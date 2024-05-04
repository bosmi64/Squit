/* ==============================================
 *                                              *
 * GoBee Director GML Interpreter functions		*
 *												*
 * Copyright 2017-2019 Gobee Srl				*
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH IS THE PROPERTY OF Gobee Srl			*
 * ==============================================
*/

/* Include files */
#include <device.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gobee.h>
#include <console.h>
#include <systrings.h>
#include <gobeelib.h>
#include <mover.h>
#include <estimators.h>
#include <clu.h>
#include <gml.h>


/* External Global Wars */
extern uint8 machine_state;			/* Initial Machine State = POWERON 					*/
									/* Machine States = [POWERON | OPERATIVE | FAULT]	*/

/* External CLU execution state machine */
extern struct CLU_STATEMACHINE clu_sm;									

/* EXTERN CLU Array 	*/
extern clu_type clu[MAX_CLU_NUMBER];

/* GLOBAL MOVER PATH Array */
/* 16 paths 			   */
extern path_type path[PATH_N_MAX];		/* path array structure 	*/
extern path_type path_to_home;			/* path to home structure instatiation		*/

/* EXTERN MOVER PAN&TILT PATHs */
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/
//extern mover_type mover;				/* mover structure			*/

/* external events structure	*/
extern struct EVENTS events;

/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 			/* PAN Motor Axis Parameters & RT Datas		*/
extern struct MOTOR_AXIS tilt_axis; 		/* TILT Motor Axis Parameters & RT Datas	*/

/* EXTERNAL Absolute Position Sensor */
extern struct ABSPOS_SENSOR	pan_absolute_sensor;	/* PAN  Absolute Position Sensor Parameters & RT Datas */
extern struct ABSPOS_SENSOR	tilt_absolute_sensor;	/* TILT Absolute Position Sensor Parameters & RT Datas */

/* external Q elements (shots) ARRAY	*/
extern struct QELEMENT q[MAX_Q_MEMORIES_SAFE];

/* external [Q number --> Q memory index] table for fast indexing */
extern uint8 q_table[MAX_Q_NUMBER_SAFE];

/* GML Interpreter Module Wars */
char   CluBuffer[CLU_CMDSTRING_SIZE]="";		/* Input Buffer from CLU 	*/
struct GML_COMMANDLINE gml_cmd;


// ****************************************************************
// *** CLU STATE MACHINE EXECUTOR FUNCTION					    ***
// ****************************************************************
// *** to call inside isr_CLU_EXEC (100Hz, priority=7)			***
// ****************************************************************
void clu_sm_exec(uint8 verbose)
{
	if ((clu_sm.status == CLUSM_START) || (clu_sm.status == CLUSM_LINE_EXECUTED))
	{
		if (ReadCLUbuffer(clu_sm.clunumber, clu_sm.cluline) == CLU_IS_NOT_ENDED) // Clubuffer <-- clu line
		{
			clu_sm.status = CLUSM_LINE_EXECUTING;								 // Assert Clu State Machine = Line Executing
			
			gml_scanner(verbose);											 	 // scan CluBuffer to extract Tokens
			gml_parser(verbose);												 // parse Tokens to exec the command

			clu_sm.cluline++;													 // increments clu line
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #CLUEND\r\n");	
			}
			clu_sm.status = CLUSM_END;
		}
	}
	
	//pause ticks elapsed check
	// 1/100 sec (100Hz)
	if (clu_sm.status == CLUSM_PAUSE_EXECUTION)
	{
		clu_sm.pauseticks++;
		
		if (clu_sm.pauseticks > clu_sm.pausemax)
		{
			clu_sm.status = CLUSM_LINE_EXECUTED;
			if (verbose == VERBOSE_ON)
			{
				printf("*GML pause is ended\r\n");		
			}			
		}
	}
	
	//goto mover end check
	if ((clu_sm.status == CLUSM_PGOTO_EXECUTION) ||
	    (clu_sm.status == CLUSM_TGOTO_EXECUTION) ||
		(clu_sm.status == CLUSM_PATH_EXECUTION))
	{	
		if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
		{
			clu_sm.status = CLUSM_LINE_EXECUTED;
			if (verbose == VERBOSE_ON)
			{
				printf("*GML mover is ended\r\n");		
			}
		}
	}
}

void clu_sm_init(void)
{
	clu_sm.status = CLUSM_NOP;
}

// CLU START (LAUNCH) FUNCTION
//to call inside console or an internal process
// clu_num = clu to start
void clu_sm_start(uint8 clu_num)
{
	clu_sm.status = CLUSM_NOP;
	
	mover_pan.status  = MOVER_NOP;
	mover_tilt.status = MOVER_NOP;
	
	clu_sm.clunumber   = clu_num;
	clu_sm.cluline     = 0;
	clu_sm.pauseticks  = 0;
	clu_sm.pausemax    = 0;
	clu_sm.ptrap_num   = 0;
	clu_sm.ttrap_num   = 0;
	
	clu_sm.status = CLUSM_START;	
}


// ****************************************************************
// *** CLU LINE BUFFERIZER (pass 1 of 3)					    ***
// ****************************************************************
// *** Legge la CLU clu_number alla linea clu_step				***
// *** e popola il buffer CluBuffer 							***
// ****************************************************************
// *** restituisce CLU_IS_ENDED alla fine della CLU				***
// ****************************************************************
uint8 ReadCLUbuffer(uint8 clu_number, uint8 clu_step)
{
	//CluBuffer = clu[clu_number][clu_step];	//clu clu_number step 
	sprintf(CluBuffer, clu[clu_number][clu_step]);
	
	if (strcmp(CluBuffer, "#CLUEND") == 0)
		return CLU_IS_ENDED;
	else
		return CLU_IS_NOT_ENDED;
}	

// ************************************************************************
// *** GML SIMPLE SCANNER (pass 1 of 2)									***
// ************************************************************************
// *** Estrae quattro sottostinghe dal Clu Buffer
// *** e le associa ai token di actual_command:
// *** actual_command.action     <-- primo token
// *** actual_command.parameter1 <-- secondo token 
// *** actual_command.parameter2 <-- terzo token
// *** actual_command.parameter3 <-- quarto token
// *** restituisce:
// *** 0: SCAN_OK
// *** 1: SCANNING ERROR (tokens > 4)
// ************************************************************************

void gml_scanner(bit verbose)
{	
	char localBuffer[40];
	char* p;

	clear_gml_string(gml_cmd.action);
	clear_gml_string(gml_cmd.parameter1);	
	clear_gml_string(gml_cmd.parameter2);	
	clear_gml_string(gml_cmd.parameter3);	

	
	/* Extract 4 Tokens */
	clear_gml_string(localBuffer);
	strcpy(localBuffer, CluBuffer);
	
	p = strtok(localBuffer, " ");

	if (p != NULL)
	{
		strcpy(gml_cmd.action, p);	
		p = strtok(NULL, " ");
	}
	else
	{
		clear_string(gml_cmd.action);
	}

	if (p != NULL)
	{
		strcpy(gml_cmd.parameter1, p);	
		p = strtok(NULL, " ");
	}
	else
	{
		clear_string(gml_cmd.parameter1);
	}
	
	if (p != NULL)
	{
		strcpy(gml_cmd.parameter2, p);	
		p = strtok(NULL, " ");
	}
	else
	{
		clear_string(gml_cmd.parameter2);
	}

	if (p != NULL)
	{
		strcpy(gml_cmd.parameter3, p);	
		p = strtok(NULL, " ");
	}
	else
	{
		clear_string(gml_cmd.parameter3);
	}


	if (verbose == VERBOSE_ON)
	{
		printf("\r\n");
		printf("*buff=%s\r\n", localBuffer);
		
		printf("*tk1=");
		printf(gml_cmd.action);
		printf(" tk2=");
		printf(gml_cmd.parameter1);
		printf(" tk3=");
		printf(gml_cmd.parameter2);
		printf(" tk4=");		
		printf(gml_cmd.parameter3);
		printf("\r\n");		
	}
	else
	{
		printf("\r\n");	
		printf("\r\n");
	}
}


// ************************************************************************
// *** GML SIMPLE PARSER (pass 2 of 2)									***
// ************************************************************************
uint8 gml_parser(bit verbose)
{
	uint8 scanstat __attribute__ ((unused));
	uint8 dummy __attribute__ ((unused));
	
	int16	param1_loc __attribute__ ((unused));
	int16	param2_loc __attribute__ ((unused));
	int16	param3_loc __attribute__ ((unused));
	
	float	angle_loc;
	float	acc_loc;
	float	time_loc;
	int8	q_number;
	
	//=====================================================================//
	//=== GML COMMANDS PARSING 											===//
	//=====================================================================//
	
	/* GML NOP CMD */	
	if (strlen(gml_cmd.action) == 0)
	{
	goto exitpars;
	}
	/* END GML NOP CMD */
	
	
	/* GML CMD #CAMERAON */
	if (strcmp(gml_cmd.action, "#CAMERAON") == 0)
	{
		if (strlen(gml_cmd.parameter1) == 0)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #CAMERAON\r\n");		
			}
			
			//command execution
			Control_Reg_LED_Write(0xF7);		/* led on				*/
			Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
			CyDelay(50);						/* 50msec sec delay		*/
			Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/
			
			clu_sm.status = CLUSM_LINE_EXECUTED;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
	goto exitpars;
	}
	/* END GML CMD #CAMERAON */	

	
	/* GML CMD #CAMERAOFF */
	if (strcmp(gml_cmd.action, "#CAMERAOFF") == 0)
	{
		if (strlen(gml_cmd.parameter1) == 0)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #CAMERAOFF\r\n");		
			}
			
			//command execution
			Control_Reg_LED_Write(0xFF);		/* led off	*/
			Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
			CyDelay(25);						/* 25msec sec delay		*/
			Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/
			CyDelay(25);						/* 25msec sec delay		*/			
			Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
			CyDelay(25);						/* 25msec sec delay		*/
			Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/				

			clu_sm.status = CLUSM_LINE_EXECUTED;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
	goto exitpars;
	}
	/* END GML CMD #CAMERAOFF */		
			
	
	/* GML CMD #PAUSE */
	if (strcmp(gml_cmd.action, "#PAUSE") == 0)
	{	
		if (((time_loc = atof(gml_cmd.parameter1)) >= 0)
		&& (time_loc = atof(gml_cmd.parameter1)) <= CLU_PAUSE_MAX)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #PAUSE %1.2f[sec]\r\n", (float)time_loc);
			}	
			//command execution
			clu_sm.status     = CLUSM_NOP;
			clu_sm.pauseticks = 0;
			clu_sm.pausemax   = (uint16)(time_loc * GML_SAMPLING_RATE);
			clu_sm.status     = CLUSM_PAUSE_EXECUTION;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
		goto exitpars;	
	}	
	/* GML CMD #PAUSE */

	
	/* GML CMD #PGOTOH */
	if (strcmp(gml_cmd.action, "#PGOTOH") == 0)
	{	
		if (machine_state == GOBEE_ENERGIZED)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #PGOTOH\r\n");
			}
			
			//command execution
			clu_sm.status     = CLUSM_NOP;

			InitPanGotoHomePath();						/* initialize the Pan Goto Home Path					*/
			CalculatePanGotoHomePath();					/* Calculate the Pan Goto Home Path 					*/
			MoverStart(&mover_pan, PATH_PGOTOHOME);		/* Initialize & Start the Mover over Pan path to Home	*/
			
			mover_tilt.status = MOVER_ENDED;			/* implicit MOVER END on TILT							*/
			
			clu_sm.status     = CLUSM_PGOTO_EXECUTION;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
		goto exitpars;	
	}		
	/* END GML CMD #PGOTOH */	

	
	/* GML CMD #TGOTOH */
	if (strcmp(gml_cmd.action, "#TGOTOH") == 0)
	{	
		if (machine_state == GOBEE_ENERGIZED)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #TGOTOH\r\n");
			}
			
			//command execution
			clu_sm.status     = CLUSM_NOP;

			InitTiltGotoHomePath();						/* initialize the Tilt Goto Home Path					*/
			CalculateTiltGotoHomePath();				/* Calculate the Tilt Goto Home Path 					*/
			MoverStart(&mover_tilt, PATH_TGOTOHOME);	/* Initialize & Start the Mover over Tilt path to Home	*/
			
			mover_pan.status = MOVER_ENDED;				/* implicit MOVER END on PAN							*/
			
			clu_sm.status     = CLUSM_TGOTO_EXECUTION;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
		goto exitpars;	
	}		
	/* END GML CMD #TGOTOH */		

	
	/* GML CMD #GOTOH */
	if (strcmp(gml_cmd.action, "#GOTOH") == 0)
	{	
		if (machine_state == GOBEE_ENERGIZED)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #GOTOH\r\n");
			}
			
			//command execution
			clu_sm.status     = CLUSM_NOP;

			InitPanGotoHomePath();						/* initialize the Pan Goto Home Path					*/
			InitTiltGotoHomePath();						/* initialize the Tilt Goto Home Path					*/			
			CalculatePanGotoHomePath();					/* Calculate the  Pan Goto Home Path 					*/
			CalculateTiltGotoHomePath();				/* Calculate the  Tilt Goto Home Path 					*/			
			MoverStart(&mover_pan, PATH_PGOTOHOME);		/* Initialize & Start the Mover over Pan path to Home	*/
			MoverStart(&mover_tilt, PATH_TGOTOHOME);	/* Initialize & Start the Mover over Tilt path to Home	*/			
			
			clu_sm.status = CLUSM_PATH_EXECUTION;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
		goto exitpars;	
	}		
	/* END GML CMD #GOTOH */		
	
	
	/* GML CMD #PTRAP */
	if (strcmp(gml_cmd.action, "#PTRAP") == 0)
	{	
		angle_loc = atof(gml_cmd.parameter1);	//angle [deg]
		acc_loc   = atof(gml_cmd.parameter2);	//acc   [%]
		time_loc  = atof(gml_cmd.parameter3);	//time  [sec]
		
		if (machine_state == GOBEE_ENERGIZED)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #PTRAP %1.2f[deg]  %1.2f[%%]  %1.2f[sec]\r\n", (float)angle_loc, (float)acc_loc, (float)time_loc);
			}	
			path[PANPATH].trapezoid[clu_sm.ptrap_num].param.acc_pc.fnum = acc_loc;												/* [%]     */
			path[PANPATH].trapezoid[clu_sm.ptrap_num].param.dec_pc.fnum = acc_loc;												/* [%]     */
			path[PANPATH].trapezoid[clu_sm.ptrap_num].param.time_sec.fnum = time_loc;											/* [sec]   */
			path[PANPATH].trapezoid[clu_sm.ptrap_num].param.steps = (int32)(angle_loc * pan_axis.vparam.resolution_step_deg);	/* [steps] */
			path[PANPATH].trapezoid[clu_sm.ptrap_num].param.last_flg = NOT_LAST_TRAPEZOID;		
			
			clu_sm.ptrap_num++;		/* Increments PAN Trapezoid Number */
		}
		clu_sm.status = CLUSM_LINE_EXECUTED;
		goto exitpars;	
	}	
	/* END GML CMD #PTRAP */
	
	
	/* GML CMD #PTQ */
	if (strcmp(gml_cmd.action, "#PTQ") == 0)
	{	
		q_number  = atoi(gml_cmd.parameter1);	//Q (shot) number
		acc_loc   = atof(gml_cmd.parameter2);	//acc   [%]
		time_loc  = atof(gml_cmd.parameter3);	//time  [sec]
		
		if ((machine_state == GOBEE_ENERGIZED) && (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)) 
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #PTQ  Q%02d  %1.2f[%%]  %1.2f[sec]\r\n", (uint16)q_number, (float)acc_loc, (float)time_loc);
			}	
			
			//PAN
			path[PANPATH].trapezoid[0].param.acc_pc.fnum = acc_loc;										/* [%]     */
			path[PANPATH].trapezoid[0].param.dec_pc.fnum = acc_loc;										/* [%]     */
			path[PANPATH].trapezoid[0].param.time_sec.fnum = time_loc;									/* [sec]   */
			path[PANPATH].trapezoid[0].param.steps = (int32)(-pan_absolute_sensor.position + q[q_table[q_number]].mc.position[PAN_AXIS]); /* [steps] */
			path[PANPATH].trapezoid[0].param.last_flg = LAST_TRAPEZOID;		
			clu_sm.ptrap_num = 1;	/* Safety: PAN Trapezoid Number = 1		*/
									/* The next command should be #PATHEXEC	*/

			//TILT
			path[TILTPATH].trapezoid[0].param.acc_pc.fnum = acc_loc;										/* [%]     */
			path[TILTPATH].trapezoid[0].param.dec_pc.fnum = acc_loc;										/* [%]     */
			path[TILTPATH].trapezoid[0].param.time_sec.fnum = time_loc;									/* [sec]   */
			path[TILTPATH].trapezoid[0].param.steps = (int32)(-tilt_absolute_sensor.position + q[q_table[q_number]].mc.position[TILT_AXIS]); /* [steps] */
			path[TILTPATH].trapezoid[0].param.last_flg = LAST_TRAPEZOID;		
			clu_sm.ttrap_num = 1;	/* Safety: TILT Trapezoid Number = 1 	*/
									/* The next command should be #PATHEXEC	*/			
		}
		clu_sm.status = CLUSM_LINE_EXECUTED;
		goto exitpars;	
	}	
	/* END GML CMD #PTQ */	

	
	/* GML CMD #TTRAP */
	if (strcmp(gml_cmd.action, "#TTRAP") == 0)
	{	
		angle_loc = atof(gml_cmd.parameter1);	//angle [deg]
		acc_loc   = atof(gml_cmd.parameter2);	//acc   [%]
		time_loc  = atof(gml_cmd.parameter3);	//time  [sec]
		
		if (machine_state == GOBEE_ENERGIZED)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #TTRAP %1.2f[deg]  %1.2f[%%]  %1.2f[sec]\r\n", (float)angle_loc, (float)acc_loc, (float)time_loc);
			}	
			path[TILTPATH].trapezoid[clu_sm.ttrap_num].param.acc_pc.fnum = acc_loc;												/* [%]     */
			path[TILTPATH].trapezoid[clu_sm.ttrap_num].param.dec_pc.fnum = acc_loc;												/* [%]     */
			path[TILTPATH].trapezoid[clu_sm.ttrap_num].param.time_sec.fnum = time_loc;											/* [sec]   */
			path[TILTPATH].trapezoid[clu_sm.ttrap_num].param.steps = (int32)(angle_loc * tilt_axis.vparam.resolution_step_deg);	/* [steps] */
			path[TILTPATH].trapezoid[clu_sm.ttrap_num].param.last_flg = NOT_LAST_TRAPEZOID;		
			
			clu_sm.ttrap_num++;		/* Increments TILT Trapezoid Number */
		}
		clu_sm.status = CLUSM_LINE_EXECUTED;
		goto exitpars;	
	}	
	/* END GML CMD #TTRAP */
	

	/* GML CMD #PATHEXEC */
	if (strcmp(gml_cmd.action, "#PATHEXEC") == 0)
	{
		if (strlen(gml_cmd.parameter1) == 0)
		{
			if (verbose == VERBOSE_ON)
			{
				printf("*GML #PATHEXEC\r\n");		
			}
			
			//command execution
			//path[PANPATH].trapezoid[clu_sm.ptrap_num - 1].param.last_flg  = LAST_TRAPEZOID;
			//path[TILTPATH].trapezoid[clu_sm.ttrap_num - 1].param.last_flg = LAST_TRAPEZOID;
			
			path[PANPATH].param.Trapezoid_Number  = clu_sm.ptrap_num;	//set numero dei trapezoidi di PAN
			path[TILTPATH].param.Trapezoid_Number = clu_sm.ttrap_num;	//set numero dei trapezoidi di TILT
			
			printf("* clu_sm.ptrap_num = %2i\r\n", (uint16)clu_sm.ptrap_num);
			printf("* clu_sm.ttrap_num = %2i\r\n", (uint16)clu_sm.ttrap_num);			
			
			clu_sm.ptrap_num = 0;		//reset index for the next #PTRAP
			clu_sm.ttrap_num = 0;		//reset index for the next #TTRAP
			
			//calculates PAN path if pan trapezoids exist
			if (path[PANPATH].param.Trapezoid_Number > 0)
			{
				path[PANPATH].trapezoid[path[PANPATH].param.Trapezoid_Number - 1].param.last_flg  = LAST_TRAPEZOID;				
				CalculatePath(&path[PANPATH]);	/* Calculate PAN PATH	*/
			}

			//calculates TILT path if tilt trapezoids exist
			if (path[TILTPATH].param.Trapezoid_Number > 0)
			{
				path[TILTPATH].trapezoid[path[TILTPATH].param.Trapezoid_Number - 1].param.last_flg = LAST_TRAPEZOID;				
				CalculatePath(&path[TILTPATH]);	/* Calculate TILT PATH	*/
			}		
				
			//executes PAN PATH mover if exists, else pan mover is ended
			if (path[PANPATH].param.Trapezoid_Number > 0)
			{			
				MoverStart(&mover_pan, PANPATH);	/* Initialize & Start the PAN Mover over path		*/
			}
			else
			{
				mover_pan.status = MOVER_ENDED;
			}

			//executes TILT PATH mover if exists, else tilt mover is ended
			if (path[TILTPATH].param.Trapezoid_Number > 0)
			{			
				MoverStart(&mover_tilt, TILTPATH);	/* Initialize & Start the TILT Mover over path		*/
			}
			else
			{
				mover_tilt.status = MOVER_ENDED;
			}			
		
			clu_sm.status = CLUSM_PATH_EXECUTION;
		}
		else
		{
			if (verbose == VERBOSE_ON)
			{			
				printf ("*GML err\n");
			}
		}
	goto exitpars;
	}
	/* END GML CMD #PATHEXEC */	
	
	
//	/* GML CMD MOVEPATH */
//	if (strcmp(gml_cmd.action, "#MOVP") == 0)
//	{	
//		if (((param1_loc = atoi(gml_cmd.parameter1)) >= 0)
//		&& (param1_loc = atoi(gml_cmd.parameter1)) <= PATH_N_MAX-1)
//		{
//			if (machine_state == GOBEE_ENERGIZED)
//			{
//				if (verbose == VERBOSE_ON)
//				{
//					printf("*GML #MOVP %2i\r\n", (int16)param1_loc);
//				}
//				MoverStart((uint8)param1_loc);	/* Initialize & Start the Mover over path param1_loc	*/
//			}
//		}
//		else
//		{
//			if (verbose == VERBOSE_ON)
//			{			
//				printf ("*GML err\n");
//			}
//		}
//		goto exitpars;	
//	}	

		
//	/* GML CMD #ORIGIN */
//	if (strcmp(gml_cmd.action, "#ORIGIN") == 0)
//	{	
//		if (machine_state == GOBEE_ENERGIZED)
//		{
//			if (verbose == VERBOSE_ON)
//			{
//				printf("*GML #ORIGIN\r\n");
//			}
//			InitGotoHomePath();						/* initialize the Goto Home Path					*/
//			CalculateGotoHomePath();				/* Calculate the Goto Home Path 					*/
//			MoverStart(PATH_GOTOHOME_N);			/* Initialize & Start the Mover over path to Home	*/
//		}
//		goto exitpars;	
//	}			

exitpars:	
	//printf("\r\n");	
	return 0;	// PARS_OK//
}


void clear_gml_string(char *str)
{
	uint8 idx = 0;
	for (idx=0; idx <= sizeof(str); idx++)
	{
		*(str + idx) = '\0';
	}
}

/* [] END OF FILE */
