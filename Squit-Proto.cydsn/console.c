/* ==============================================
 *                                              *
 * GoBee Director Console Interface functions	*
 *												*
 * Copyright 2017 Gobee Srl		         		*
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
#include <math.h>

#include <gobee.h>
#include <console.h>
#include <systrings.h>
#include <gobeelib.h>
#include <ITG-3701.h>
#include <IMU_UM7.h>
#include <XTR-8LR100.h>
#include <mover.h>
#include <motor_CTRL.h>
#include <pid_lib.h>
#include <My_I2C_lib.h>
#include <estimators.h>
#include <clu.h>
#include <gml.h>
#include <statistics.h>
#include <torquestat.h>


/* External Global Wars */
extern struct GOBEE_PARAMS gobee_param;
extern int16 AdcValue[ADC_MUX_LENGHT];

extern uint8 machine_state;			/* Initial Machine State = POWERON 					*/
									/* Machine States = [POWERON | OPERATIVE | FAULT]	*/

/* GoBee Faults structure */
extern struct GOBEE_FAULTS gobeeFaults;	

/* External CLU execution state machine */
extern struct CLU_STATEMACHINE clu_sm;		

/* extern Control Variables */
extern float fsampling;			/* fsampling [kHz]							*/


/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 					/* PAN  Motor Axis Parameters & RT Datas			   */
extern struct MOTOR_AXIS tilt_axis; 				/* TILT Motor Axis Parameters & RT Datas			   */
extern struct MOTOR_AXIS *Selected_ANAOUT;			/* Selected Axis for Analog Output					   */

/* EXTERNAL Absolute Position Sensor */
extern struct ABSPOS_SENSOR	pan_absolute_sensor;	/* PAN  Absolute Position Sensor Parameters & RT Datas */
extern struct ABSPOS_SENSOR	tilt_absolute_sensor;	/* TILT Absolute Position Sensor Parameters & RT Datas */

/* extern axis absolute sensor STATISTICS	*/
extern struct STATISTICS pan_absolute_sensor_stat;	/* PAN  Absolute Position Sensor Statistics Datas  	   */
extern struct STATISTICS tilt_absolute_sensor_stat;	/* TILT Absolute Position Sensor Statistics Datas  	   */

/* extern axis current and power STATISTICS	*/
extern struct STATISTICS pan_current_stat;			/* PAN  Current  Statistic    [A]           (Motor Torque estimating) */
extern struct STATISTICS pan_qpower_stat;			/* PAN  quasi-power Statistic [A * rad/sec] (Motor Power estimating)  */
extern struct STATISTICS tilt_current_stat;			/* TILT Current  Statistic    [A]           (Motor Torque estimating) */
extern struct STATISTICS tilt_qpower_stat;			/* TILT quasi-power Statistic [A * rad/sec] (Motor Power estimating)  */

/* extern axis TORQUE Estimator	*/
extern struct TORQUESTAT pan_torque_stat;			/* PAN  Torque Statistics Real Time Datas	*/
extern struct TORQUESTAT tilt_torque_stat;			/* TILT Torque Statistics Real Time Datas	*/

/* EXTERN MOVER PATH Array */
extern path_type path[PATH_N_MAX];		/* path array structure 	*/
extern path_type path_to_home;			/* path to home structure instatiation		*/

/* EXTERN MOVER PAN&TILT PATHs */
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/

/* external Q elements (shots) ARRAY	*/
extern struct QELEMENT q[MAX_Q_MEMORIES_SAFE];

/* external [Q number --> Q memory index] table for fast indexing */
extern uint8 q_table[MAX_Q_NUMBER_SAFE];
extern uint8 qmemory_standard_address[MAX_Q_NUMBER_SAFE]; 

/* EXTERN CLU Sequence Array 	*/
extern uint8 clu_sequence[MAX_CLU_SEQUENCE_STEPS];

/* external events structure	*/
extern struct EVENTS events;

/* extern IMU UM7 vars */ 
#if IMU_UM7_ENABLED
extern EULER_ANGLES euler_angles; 		/* Struttura in cui vengono messi gli angoli di Eulero misurati dallo SpacePoint */
#endif

/* extern IMU sensor vars */
extern struct IMU_SENSOR	IMU_sensor;		/* Struttura dei dati della IMU */

/* external ITG-3701 digital gyro vars */
extern float gRes;      				// scale resolutions per LSB for the sensors
extern int16 gyroCount[3];  			// Stores the 16-bit signed gyro output
extern float gx, gy, gz; 				// variables to hold latest sensor data values 
extern float gyroBias[3];			 	// Bias corrections for gyro, accelerometer, and magnetometer
extern float temperature;          		// Stores the ITG3701yro internal chip temperature in degrees Celsius

/* extern accelerometer and gyroscopes and estimated Variables */
extern int16 gyro_ADC_offset;			/* analog gyroscope ADC offset				*/

//extern float angle_estim_analog_gyro;	/* estimated angle [deg] from ADXRS646     (analog gyro) 			*/
//extern float angle_estim_digital_gyro;	/* estimated angle [deg] from ADXRS453     (digital gyro)			*/
//extern float angle_estim_acc;			/* estimated angle [deg] from ADXL203      (analog accelerometer) 	*/
//extern float angle_estim_acc_lowpass;	/* Low Pass Filtered estimated angle [deg] (analog accelerometer)	*/

extern signed long system_dynamic_scalar;	/* x_acc_ADC^2 + y_acc_ADC^2 - (1g_ADC)^2						*/

//extern float gyro;					/* analog gyroscope float value						*/
//extern float gyro_offset_fine;		/* fine Gyro offset									*/
//extern float int_gyro;				/* estimated angle [deg] from ADXRS646				*/
//extern float angle;					/* Complementary Filter Estimated angle float [deg]	*/
extern float angle_lowpass;
extern float agyro_mean;			/* analog gyro mean_value(t)						*/
extern float agyro_mean_previous;	/* analog gyro mean_value(t-1)						*/
extern uint32 iteration;			/* mean value iteration counter						*/
extern uint8 agyro_messg;			/* analog gyro message passing console --> isr_ctrl	*/
extern uint16 GyroNullPauseTicks;	/* centiseconds ticks counter for Gyroscope Autonull Procedure Delay	*/

/* extern Analog ADXL325 3D accelerometer vars) */
extern struct ANALOG_3D_ACCELEROMETER aacc;

/* GLOBAL Analog External ADXRS646 gyroscope vars) */
extern struct ANALOG_GYRO agyro;

//extern Digital Gyroscope Vars
extern unsigned long int dgyro_spi32;	/* ADXRS453 Digital Gyro 32 bit SPI Response			*/
extern float dgyro_rate_float;			/* ADXRS453 Digital Gyro Rate (float) [deg/sec] 		*/
extern float dgyro_mean;				/* digital gyro mean_value(t)							*/
extern float dgyro_mean_of;				/* digital gyro ofsetted mean_value(t)					*/
extern uint8 dgyro_messg;				/* digital gyro message passing console --> isr_ctrl	*/

/* extern anapos vars */
extern float anapos;					/* Analog Position Output(t) 				*/
extern int32 anapos_offset;				/* Analog Position Output Offset			*/

/* EXTERNAL CONTROL CHECK VARS */
extern uint16 isr_START_check_counter;
extern uint16 isr_STOP_check_counter;

/* EXTERNAL EEPROM Buffers */
extern char8 EEreadBuffer[18];
extern char8 EEwriteBuffer[18];

extern struct  GOBEE_FAULTS nemo_Faults;			/* Faults Flags Structure */


/* ASTIM WAVES (3Hz - 3333 samples/sec */
extern const uint8 CYCODE WaveDAC8_wave_sine[WaveDAC8_WAVE_SINE_LENGTH];
extern const uint8 CYCODE WaveDAC8_wave_triangle[WaveDAC8_WAVE_TRIANGLE_LENGTH];
extern const uint8 CYCODE WaveDAC8_wave_square[WaveDAC8_WAVE_SQUARE_LENGTH];

/* Console Module Wars */
char   userInputBuffer[40]="";		/* User Input Buffer from USB UART 	*/
struct command actual_cmd;
uint8  USB_Check_prev;				/* USB Check(t-1) 					*/
char   slegenda[15]="";				/* hystogram legenda string 		*/

//////////////////////////////////////////////////////////////////////////
// Show Status of the Mapping State Machine Auxiliary Functions
//////////////////////////////////////////////////////////////////////////
void ShowStatusMappingSM(uint8 status)
{
	switch (status)
	{
		case SM_ON_ORIGIN:
			printf("(SM_ON_ORIGIN)");
		break;	
		case SM_MOVING_TO_FACE:
			printf("(SM_MOVING_TO_FACE)");
		break;		
		case SM_ON_FACE:
			printf("(SM_ON_FACE)");
		break;
		case SM_MOVING_TO_ORIGIN:
			printf("(SM_MOVING_TO_ORIGIN)");
		break;
		case SM_MOVING_PANORAMIC:
			printf("(SM_MOVING_PANORAMIC)");
		break;
		case SM_MOVING_JUMP:
			printf("(SM_MOVING_JUMP)");
		break;
		case SM_MOVING_TO_WHEEL:
			printf("(SM_MOVING_TO_WHEEL)");
		break;			
		case SM_ON_WHEEL:
			printf("(SM_ON_WHEEL)");
		break;			
		case SM_STANDBY:
			printf("(SM_STANDBY)");
		break;			
		default:
			printf("(*err)");
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
// Show Status of the CLU Machine Auxiliary Functions
//////////////////////////////////////////////////////////////////////////
void ShowCLUSM(uint8 status)
{
	switch (status)
	{
		case CLUSM_NOP:
			printf("(CLUSM_NOP)");
		break;	
		case CLUSM_START:
			printf("(CLUSM_START)");
		break;
		case CLUSM_LINE_EXECUTING:
			printf("(CLUSM_LINE_EXECUTING)");
		break;
		case CLUSM_PAUSE_EXECUTION:
			printf("(CLUSM_PAUSE_EXECUTION)");
		break;		
		case CLUSM_PGOTO_EXECUTION:
			printf("(CLUSM_PGOTO_EXECUTION)");
		break;	
		case CLUSM_TGOTO_EXECUTION:
			printf("(CLUSM_TGOTO_EXECUTION)");
		break;
		case CLUSM_PATH_EXECUTION:
			printf("(CLUSM_PATH_EXECUTION)");
		break;		
		case CLUSM_LINE_EXECUTED:
			printf("(CLUSM_LINE_EXECUTED)");
		break;		
		case CLUSM_STOP:
			printf("(CLUSM_STOP)");
		break;	
		case CLUSM_END:
			printf("(CLUSM_END)");
		break;			
		default:
			printf("(*err)");
		break;
	}
}


//////////////////////////////////////////////////////////////////////////
// Show Parameters Auxiliary Functions
//////////////////////////////////////////////////////////////////////////
void ShowParamsDirector(void)
{	
	switch (gobee_param.director)
	{
		case STANLEY:
			printf("Stanley Kubrick");
			break;	
		case ALFRED:
			printf("Alfred Hitchcock");
			break;
		case DE_PALMA:
			printf("Brian De Palma");
			break;	
		case CHARLIE:
			printf("Charlie Chaplin");
			break;	
		case LINCH:
			printf("David Linch");
			break;
		case COPPOLA:
			printf("Francis Ford Coppola");
			break;
		case MARTIN:
			printf("Martin Scorsese");
			break;	
		case QUENTIN:
			printf("Quentin Tarantino");
			break;
		case RIDLEY:
			printf("Ridley Scott");
			break;
		case SERGIO:
			printf("Sergio Leone");
			break;
		case STEVEN:
			printf("Steven Spielberg");
			break;
		case TIM:
			printf("Tim Burton");
			break;
		case WES:
			printf("Wes Craven");
			break;
		case FEDERICO:
			printf("Federico Fellini");
			break;
		case CRISTOPHER:
			printf("Christopher Nolan");
			break;
		case GUILLERMO:
			printf("Gullermo Del Toro");
			break;	
		case GEORGE:
			printf("George Lucas");
			break;	
		case JJ:
			printf("J.J. Abrams");
			break;			
		default:
			printf("You");
			break;
	}		
}


void ShowParamsMode(void)
{	switch (gobee_param.mode)
	{
		case REMOTECONTROL_MODE:
			printf("Remote Control");
			break;	
		case DIRECTOR_MODE:
			printf("Director AI");
			break;
		default:
			printf("* mode err!");
			break;
	}		
	printf("\r\n");
}


void ShowParamsAstim(struct MOTOR_AXIS *paxis)
{
	if ((*paxis).vparam.astim_type == NO_ASTIM)
	{
		printf(" (0:off)");
	}
	else if ((*paxis).vparam.astim_type == SINE_ASTIM)
	{
		printf(" (1:sine)");
	}				
	else if ((*paxis).vparam.astim_type == TRIANGLE_ASTIM)
	{
		printf(" (2:triangle)");
	}
	else if ((*paxis).vparam.astim_type == SQUARE_ASTIM)
	{
		printf(" (3:square)");
	}					
	else
	{
		printf(" (!internal error)");
	}				
	printf("\r\n");
}

void ShowParamsGainAnaout(struct MOTOR_AXIS *paxis)
{	
	printf("%4f ",(float)((*paxis).param.Gain_ANAOUT.fnum));
	/********************************************************************************/
	/* Again (I/O_EQV) = DAC_Resolution/ADC_Resolution * VMAX_ADC/VMAX_DAC * 1/Kopf	*/
	/* Again (I/O_EQV) =            255/4096           *       5V/4V       * 1/Kopf	*/
	/* Again (I/O_EQV) = 0.077819824 / Kopf											*/
	/********************************************************************************/
	/* 1V Output --> [step] * AGAIN = 255/4 --> [step] = 255/4 * 1/AGAIN			*/
	/********************************************************************************/
	printf("  1V=%4.1f [step]",(float)(63.75/((*paxis).param.Gain_ANAOUT.fnum)));
	printf("  (I/O_EQV=f(Kopf)=%1.6f\r\n",(float)(0.077819824/(*paxis).param.Kopf.fnum));
}

void ShowParamsAnaoutSelectedAxis(struct MOTOR_AXIS *paxis)
{
	if (paxis == &pan_axis)
	{
		printf("PAN (volatile)");
	}
	else if (paxis == &tilt_axis)
	{
		printf("TILT (default at poweron)");
	}
//	else if (paxis == &roll_axis)
//	{
//		printf("ROLL (volatile)");
//	}
	else
	{
		printf("INTERNAL FIRMWARE ERROR!");
	}	

}

void ShowParamsKiPan(void)
{
	printf("%1.6f (Tau=%1.6f [msec])",
		   (float)(pan_axis.param.Kif.fnum),(float)convKiTi(pan_axis.param.Kpf.fnum, pan_axis.param.Kif.fnum, fsampling));		   
}

void ShowParamsKiTilt(void)
{
	printf("%1.6f (Tau=%1.6f [msec])",
		   (float)(tilt_axis.param.Kif.fnum),(float)convKiTi(tilt_axis.param.Kpf.fnum, tilt_axis.param.Kif.fnum, fsampling));		   
}

void ShowParamsColor(struct MOTOR_AXIS *paxis)
{	
	printf("%1u:",(uint16)((*paxis).param.color));
	
	if ((*paxis).param.color == GYRO_RATE)
	{
		printf("GYRO RATE");
	}
	else if ((*paxis).param.color == SLAVE_ENC_POS)
	{
		printf("SLAVE ENCODER POSITION");
	}
	else if ((*paxis).param.color == SLAVE_ENC_VEL)
	{
		printf("SLAVE ENCODER VELOCITY");
	}	
	else if ((*paxis).param.color == ASTIM_IN)
	{
		printf("ASTIM INPUT");
	}	
	else if ((*paxis).param.color == CTRL_ERROR)
	{
		printf("error(t)");
	}	
	else if ((*paxis).param.color == CTRL_DERROR)
	{
		printf("d(error(t))/dt");
	}
	else if ((*paxis).param.color == CTRL_IERROR)
	{
		printf("integral(error(t)*dt)");
	}
	else if ((*paxis).param.color == CTRL_AZIERROR)
	{
		printf("integral(error(t)*dt)");
	}
	else if ((*paxis).param.color == CTRL_AZIERROR)
	{
		printf("Ki * integral(e(t)) (fixed 4Vpp Output at PWM MAX)");
	}		
	else if ((*paxis).param.color == CTRL_CV)
	{
		printf("cv(t) (fixed 4Vpp Output at PWM MAX)");
	}
	else
	{
		printf("INTERNAL FW ERROR!   ");
	}	
}

void ShowLimits(struct MOTOR_AXIS *paxis)
{
	if ((*paxis).lc.status == COARSE_BETWEEN_LIMITS_OK)
	{
		printf("(BETWEEN)  ");
	}
	else if ((*paxis).lc.status == POSITIVE_LIMIT_REACHED)
	{
		printf("(POS    )  ");
	}
	else if ((*paxis).lc.status == NEGATIVE_LIMIT_REACHED)
	{
		printf("(NEG    )  ");
	}
	else
	{
		printf("(INT ERR) ");
	}	
}

// ****************************************************************
// *** BUFFERIZER (pass 1 of 3)								    ***
// ****************************************************************
// *** Legge l'UART USB e popola il buffer userInputBuffer      ***
// ****************************************************************

uint8 ReadUSBbuffer(bit echo, bit timeout)
{
	uint8 index = 0;
	uint16 ticks = 0;
	char charin;
	
	clear_string(userInputBuffer);
	
	while ((index < sizeof(userInputBuffer)-1)
			&& ((charin=UART_USB_GetChar()) != '\r')
			&& (ticks < TIMEOUT_TICKS) 
			&& (USB_Check() == USB_INSERTED))
	{
		if ((charin != 0) && (charin != '\n'))
		{
			userInputBuffer[index] = tolower((int)charin);
			index++;
			if (echo == 1)
			{
				printf("%c", charin);
			}
			ticks = 0;
		}
		else
		{
			if (timeout == 1)
			{
				ticks++;
			}
		}
	}
	userInputBuffer[index] = '\0';
	
	if (index >= sizeof(userInputBuffer)-1)
	{
		return READ_BUFF_OVERFLOW;
	}
	else
	{
		if (ticks >= TIMEOUT_TICKS)
		{
			return READ_TIMEOUT;
		}
		else
		{
			return READ_OK;
		}
	}
}	

// ************************************************************************
// *** SCANNERIZER (pass 2 of 3)									    ***
// ************************************************************************
// *** Estrae quattro sottostinghe dallo Standard Input (USB)
// *** e le associa ai token di actual_command:
// *** actual_command.action    <-- primo token
// *** actual_command.parameter <-- secondo token 
// *** actual_command.number1   <-- terzo token
// *** actual_command.number2   <-- quarto token
// *** restituisce:
// *** 0: SCAN_OK
// *** 1: SCANNING ERROR (tokens > 4)
// ************************************************************************

uint8 scanner2(bit verbose)
{
	uint8 rdstat=0;
	uint8 uidx=0, uidy=0;	
	char localBuffer[40];
	char* p;

	clear_string(actual_cmd.action);
	clear_string(actual_cmd.parameter);	
	clear_string(actual_cmd.number1);	
	clear_string(actual_cmd.number2);	

	/* Reads from USB buffer (standard input) */
	rdstat=ReadUSBbuffer(ECHO_ON, TIMEOUT_OFF);
	
	/* Extract 4 Tokens */
	if (rdstat == READ_OK)
	{
		clear_string(localBuffer);
		//strcpy(localBuffer, userInputBuffer);

		/*** strcopy with BACKSPACE control	***/
		uidx = 0;												// reset user  buffer pointer
		uidy = 0;									 			// reset local buffer pointer
		while ((uidx<40) && (userInputBuffer[uidx] != '\0'))	// while there is string to copy
		{
			while ((uidx<40) && (userInputBuffer[uidx] == 8))	// 	while there is ASCII BACKSPACE   = 8 (\b, ^H)
			{
				uidx = uidx + 1;								//		points to the next char

				if (uidy>0)										//		if there are characters to cancel
				{												//
					uidy = uidy - 1;							//			cancel the previous copied characters
				}												//		
			}
			localBuffer[uidy] = userInputBuffer[uidx];			//	copy one character from user to local buffer
			uidx++;												//	increments user  buffer pointer
			uidy++;												//	increments local buffer pointer
		}
		localBuffer[uidy] = '\0';								//terminate the local buffer string
		/*** strcopy with BACKSPACE control END ***/
		
		p = strtok(localBuffer, " ");

		if (p != NULL)
		{
			strcpy(actual_cmd.action, p);	
			p = strtok(NULL, " ");
		}
		else
		{
			clear_string(actual_cmd.action);
		}

		if (p != NULL)
		{
			strcpy(actual_cmd.parameter, p);	
			p = strtok(NULL, " ");
		}
		else
		{
			clear_string(actual_cmd.parameter);
		}
		
		if (p != NULL)
		{
			strcpy(actual_cmd.number1, p);	
			p = strtok(NULL, " ");
		}
		else
		{
			clear_string(actual_cmd.number1);
		}

		if (p != NULL)
		{
			strcpy(actual_cmd.number2, p);	
			p = strtok(NULL, " ");
		}
		else
		{
			clear_string(actual_cmd.number2);
		}
	
	}

	if (verbose == VERBOSE_ON)
	{
		printf("\r\n");
		printf("buff=");
		//prints user input buffer until string termination
		uidx=0;
		while ((uidx<40) && (userInputBuffer[uidx] != '\0'))
		{
			if (userInputBuffer[uidx] == 8)			// ASCII BACKSPACE   = 8 (\b, ^H)
			{
				printf("[b]");
			}
			else if (userInputBuffer[uidx] == 127)	// ASCII DELETE7CANC = 127 (^?)
			{
				printf("[d]");
			}			
			else
			{
				printf ("%c", userInputBuffer[uidx]);
			}
			uidx++;
		}
//		printf(userInputBuffer);
		
		printf(" tk1=");
		printf(actual_cmd.action);
		printf(" tk2=");
		printf(actual_cmd.parameter);
		printf(" tk3=");
		printf(actual_cmd.number1);
		printf(" tk4=");		
		printf(actual_cmd.number2);
		printf("\r\n");		
	}
	else
	{
		printf("\r\n");	
		printf("\r\n");
	}
	
	return 0;	//SCAN_OK//	
}




// ************************************************************************
// *** PARSERIZER (pass 3 of 3)										    ***
// ************************************************************************
uint8 parser()
{
	uint8 scanstat __attribute__ ((unused));
	
	uint8 director;			/* Director local								*/
	uint8 mode_loc;			/* Machine mode local							*/
	float beta=0;			/* beta local									*/	
	float gamma=0;			/* gamma local									*/
	uint8 polarity=0;		/* Motor Polarity local							*/
	uint8 invertion=0;		/* IMU Invertion local							*/
	uint8 exchange=0;		/* IMU Exchange local							*/
	int16 offset=0;			/* generic int16 Offset							*/
	
	float Kp;				/* Kp local										*/
	float Kd;				/* Kd local										*/	
	float Ki;				/* Ki local										*/
	float Ksi;				/* Ksi local									*/	
	uint8 limit_control;	/* Limit Control local							*/
	uint8 raw_invertion;	/* raw invertion local							*/
	uint16 raw_limit_hyst; 	/* raw limit hysteresis local 					*/
	float step_abs_ratio;	/* encoder step/absolute sensor ratio local		*/
	float Kopf;				/* Kopf local									*/	
	float anaout_gain;		/* Analog Output Gain local						*/
	uint8 color;			/* color local									*/
	uint8 astim_type=0;		/* astim type loc								*/
	uint8 astim_enable=0;	/* astim enable loc 							*/
	uint8 path_n=0;			/* path number local							*/
	uint8 clu_number=0;		/* clu number local								*/
	uint8 clu_pause=0;		/* clu pause local								*/	
	uint16 memory_number=0;	/* memory number local							*/
	uint8 q_number=0;		/* q number local								*/	
	float time_loc=0;		/* time float local								*/
	float jump_g_th=0;		/* jump G threshold local						*/
	float acc_g_th=0;		/* acceleration G threshold local				*/
	

	uint8 dummy __attribute__ ((unused));
	uint8 idx=0;
	uint8 get_key=0;

	
	/* Scanner */
	scanstat = scanner2(VERBOSE_OFF);

	
	//=====================================================================//
	//=== COMMANDS PARSING 												===//
	//=====================================================================//

	/* CMD 'BOOT' */	
	if (strcmp(actual_cmd.action, "boot") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf("\r\nAre you sure to start Bootload [Y/N]?");		
			if (ButtonYNChoice(ECHO_OFF) == _YES)
			{
				printf("\r\n!!!Wait for Bootloading (power off to stop bootloading process)\r\n");
				CyDelay(100);
				/* This API will pass the program control to the Bootloader portion of the flash.
			   	It will also cause the Bootloader to wait indefinitely for the host to start communication */
				//Bootloadable_Load();
			}
			else
			{
				printf("\r\nBootloading aborted!");
			}
		}
		else
		{
			printf(STR_ERROR1);
		}
	goto exitpars;
	}
	/* END CMD BOOT */

	
	/* CMD ANAPOS +20 */
	if (strcmp(actual_cmd.action, "pp") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf ("*ANAPOS ZERO +20!\r\n");
			anapos_offset = anapos_offset + 20;
			CyDelay(100);
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END ANAPOS +20 */


	/* CMD ANAPOS +100 */
	if (strcmp(actual_cmd.action, "ppp") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf ("*ANAPOS ZERO +100!\r\n");
			anapos_offset = anapos_offset + 100;
			CyDelay(100);
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END ANAPOS +100 */


	/* CMD ANAPOS -20 */
	if (strcmp(actual_cmd.action, "mm") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf ("*ANAPOS ZERO -20!\r\n");
			anapos_offset = anapos_offset - 20;
			CyDelay(100);
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END ANAPOS -20 */


	/* CMD ANAPOS -100 */
	if (strcmp(actual_cmd.action, "mmm") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf ("*ANAPOS ZERO -100!\r\n");
			anapos_offset = anapos_offset - 100;
			CyDelay(100);
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END ANAPOS -100 */	
	
	
	/* CMD TEST BUZZER */
	if (strcmp(actual_cmd.action, "tbuz") == 0)
	{
		printf("Buzzer testing!\r\n");
 		for (idx = 0; idx < 3; idx++)
 		{			
			Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
			CyDelay(250);						/* 250msec sec delay	*/
			Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/
			CyDelay(125);						/* 125msec sec delay	*/			
		}
	
		goto exitpars;
	}
	/* END CMD TEST BUZZER */	
	
	
	/* HIDDEN CMD TEST LORA */	
	if (strcmp(actual_cmd.action, "tlora") == 0)
	{
		printf("Test LoRa started!\r\n");
			
		sendLoRaATcmd(CMD_AT);					/* Send AT Command */
		
		CyDelay(500);							/* delay waiting XTR-8LR100 chars */
						
		sendLoRaATcmd(CMD_AT_SHOWVERSION);		/* Send SHOW VERSION Command */
		
		CyDelay(500);							/* delay waiting XTR-8LR100 chars */
		
		goto exitpars;
	}
	/* END HIDDEN CMD TEST LORA */ 	
	
	
//	/* HIDDEN CMD TEST LORA 2 (PINS) */	
//	if (strcmp(actual_cmd.action, "tlora2") == 0)
//	{
//		printf("Test LoRa 2 (pins) started!\r\n");
//			
//		while (AnyButtonPressed() == NO_PRESSED)
//		{	
//			printf("RESET=L\r\n");
//			Control_Reg_LORA_RESET_Write(0x00);		/* SET_A = L 		*/						
//			CyDelay(100);						/* 0.5 sec delay 	*/
//			printf("RESET=H\r\n");
//			Control_Reg_LORA_RESET_Write(0xFF);		/* SET_A = L 		*/						
//			CyDelay(100);						/* 0.5 sec delay 	*/			
//		}
//		
//		Control_Reg_LORA_Write(0xFF);		/* SET_A = H */
//		Control_Reg_LORA_RESET_Write(0xFF);	/* RESET = H */
//		
//		goto exitpars;
//	}
//	/* END HIDDEN CMD TEST LORA 2 (PINS) */ 	
	
	
	/* CMD MYTEST */
	if (strcmp(actual_cmd.action, "mytest") == 0)
	{
		printf("My test!\r\n");
		while (AnyButtonPressed() == NO_PRESSED)
		{
#if MEASURE_MYTEST
	Control_Reg_LED_Write(0x01);
#endif					
			InitPanGotoQPath(11, 0.2);				/* initialize the Pan Goto Q Path					*/
			InitTiltGotoQPath(11, 0.2);				/* initialize the Tilt Goto Q Path					*/			
			CalculatePanGotoQPath();				/* Calculate the  Pan Goto Q Path 					*/
			CalculateTiltGotoQPath();				/* Calculate the  Tilt Goto Q Path 					*/						
#if MEASURE_MYTEST
	Control_Reg_LED_Write(0x00);
#endif					
			CyDelayUs(500);
		}
				
		goto exitpars;
	}
	/* END CMD MYTEST */
	
	
#if ITG_3701_ENABLED	
	/* CMD TEST INVENSENSE ITG3701 */
	if ((strcmp(actual_cmd.action, "titg3701") == 0) ||
	   (strcmp(actual_cmd.action, "t3701") == 0))
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf("Invensense ITG-3701 testing!\r\n");
			ITG3701_test();
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END CMD TEST INVENSENSE ITG3701 */	
#endif

	
	/* CMD STOP MAPPING STATE MACHINE */
	if ((strcmp(actual_cmd.action, "stopmapsm") == 0) ||
	   (strcmp(actual_cmd.action, "stopsm") == 0))
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf("MAPPING STATE MACHINE Stopped!\r\n");
			
			/* Mapping State Machine Initialization */
			MappingStateMachineInit();
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END CMD STOP MAPPING STATE MACHINE */

	
	/* CMD DEENERGIZE */
	if ((strcmp(actual_cmd.action, "deenergize") == 0) ||
	   (strcmp(actual_cmd.action, "deen") == 0))
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf("Motors DEENERGIZED & Driver Sleeped!\r\n");
			machine_state = GOBEE_DEENERGIZED;
			
			/* Mapping State Machine Initialization & STOP */
			MappingStateMachineInit();
			
			/* CLU State Machine STOP */
			clu_sm.status = CLUSM_END;
			
			/* Movers STOP */
			mover_pan.status = MOVER_ENDED;
			mover_pan.steps_to_move = 0;
			mover_tilt.status = MOVER_ENDED;
			mover_tilt.steps_to_move = 0;			
			
			/* Sleep the Machine*/
			motor_sleep(&pan_axis);
			motor_sleep(&tilt_axis);				
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END CMD DEENERGIZE */	

	
	/* CMD ENERGIZE */
	if ((strcmp(actual_cmd.action, "energize") == 0) ||
	   (strcmp(actual_cmd.action, "en") == 0))
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf("Motors ENERGIZED!\r\n");
//			printf("CLU state machine init!\r\n");
//			printf("Mapping state machine start!\r\n");			
			
			motor_init(&pan_axis);						/* Initialize Pan Axis  */
			motor_init(&tilt_axis);						/* Initialize Tilt Axis */			
			
#if PAN_PSEUDOABS
#else
			QuadDec_PAN_Start();						/* Reset PAN Feedback Encoder Counter	*/
			QuadDec_TILT_Start();						/* Reset TILT Feedback Encoder Counter	*/
#endif

//			/* CLU state machine Init */
//			clu_sm_init();
//
//			/* Mapping State Machine START */
//			MappingStateMachineStart();
			
			CyDelay(100);
			machine_state = GOBEE_ENERGIZED;			
			motor_energize(&pan_axis);
			motor_energize(&tilt_axis);			
		}
		else
		{
			printf ("*err\n");
		}
	goto exitpars;
	}
	/* END CMD ENERGIZE */	

	
	/* CMD VIRTUAL PAN JOYSTICK */
	if ((strcmp(actual_cmd.action, "vjoyp") == 0) ||
		(strcmp(actual_cmd.action, "vjp") == 0))
	{
		float pan_joy_delta = 0;
		
		get_key = 0;						//clear internal loop getted char
		while (get_key == 0)						
		{	
			printf("PAN: enc(t)=%+ld [step]", (int32)pan_axis.mc.slave_enc.position);
			printf("   abs_pos(t)=%+ld [step] ", (int32)pan_absolute_sensor.position);	
			ShowLimits(&pan_axis);
			printf("   vjoy(t)=%4.0f [step/sec]", (float)pan_joy_delta * SAMPLING_FREQ);
			printf(" (%4.3f [deg/sec])", (float)(pan_joy_delta * SAMPLING_FREQ) / pan_axis.param.resolution.fnum);			
			printf("\r\n");
			
			/* internal one-key getchar */
			get_key = UART_USB_GetChar();	/* get the char */
			
			if 	((get_key == 'a') || (get_key == 'A'))
			{	
				pan_joy_delta = pan_joy_delta + VJOYSTICK_SPEED;
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 'd') || (get_key == 'D'))
			{	
				pan_joy_delta = pan_joy_delta - VJOYSTICK_SPEED;
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 's') || (get_key == 'S'))
			{	
				pan_joy_delta  = 0;
				get_key = 0; //stay in while loop
			}
			
			pan_axis.mc.master_joy_sample_delta = (int32)pan_joy_delta;	//Make Pan Virtual Joystick
		}

		pan_axis.mc.master_joy_sample_delta = 0;							//stop Pan Virtual Joystick
	
		goto exitpars;
	}
	/* END CMD VIRTUAL PAN JOYSTICK */

	
	/* CMD VIRTUAL TILT JOYSTICK */
	if ((strcmp(actual_cmd.action, "vjoyt") == 0) ||
		(strcmp(actual_cmd.action, "vjt") == 0))
	{
		float tilt_joy_delta = 0;
		
		get_key = 0;						//clear internal loop getted char
		while (get_key == 0)						
		{	
			printf("TILT: enc(t)=%+ld [step]", (int32)tilt_axis.mc.slave_enc.position);
			printf("   abs_pos(t)=%+ld [step] ", (int32)tilt_absolute_sensor.position);	
			ShowLimits(&tilt_axis);
			printf("   vjoy(t)=%4.0f [step/sec]", (float)tilt_joy_delta * SAMPLING_FREQ);
			printf(" (%4.3f [deg/sec])", (float)(tilt_joy_delta * SAMPLING_FREQ * 360) / tilt_axis.param.resolution.fnum);			
			printf("\r\n");
			
			/* internal one-key getchar */
			get_key = UART_USB_GetChar();	/* get the char */
			
			if 	((get_key == 'w') || (get_key == 'W'))
			{	
				tilt_joy_delta = tilt_joy_delta + VJOYSTICK_SPEED;
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 'z') || (get_key == 'Z'))
			{	
				tilt_joy_delta = tilt_joy_delta - VJOYSTICK_SPEED;
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 's') || (get_key == 'S'))
			{	
				tilt_joy_delta  = 0;
				get_key = 0; //stay in while loop
			}
			
			tilt_axis.mc.master_joy_sample_delta = (int32)tilt_joy_delta;	//Make Tilt Virtual Joystick
		}

		tilt_axis.mc.master_joy_sample_delta = 0;							//stop Tilt Virtual Joystick
	
		goto exitpars;
	}
	/* END CMD VIRTUAL TILT JOYSTICK */
	
	
	/* CMD VIRTUAL PAN + TILT JOYSTICK */
	if ((strcmp(actual_cmd.action, "vjoy") == 0) ||
		(strcmp(actual_cmd.action, "vj") == 0))
	{
		float pan_joy_delta = 0;		
		float tilt_joy_delta = 0;
		
		get_key = 0;						//clear internal loop getted char
		while (get_key == 0)						
		{						
			printf("PAN: ");
			ShowLimits(&pan_axis);
			printf("vjoy(t)=%4.0f [step/sec]", (float)pan_joy_delta * SAMPLING_FREQ);
			printf(" (%5.4f [A])", (float)pan_axis.mc.current);	
			
			printf("    TILT: ");
			ShowLimits(&tilt_axis);
			printf("vjoy(t)=%4.0f [step/sec]", (float)tilt_joy_delta * SAMPLING_FREQ);
			printf(" (%5.4f [A])", (float)tilt_axis.mc.current);			
			printf("\r\n");
			
			/* internal one-key getchar */
			get_key = UART_USB_GetChar();	/* get the char */
			
			if 	((get_key == 'a') || (get_key == 'A'))
			{	
				//risoluzione encoder = 4096 step/giro
				//1330rpm/V  (a vuoto) --> 9310rpm su 7V --> 155 giri/sec * 4096 step/giro --> 635562 step/sec / 1500 --> 423 joysteps/sec
				//però sembrano troppi quindi metto 30 (30*1500=45000)
				if (pan_joy_delta < 100)
				{
					pan_joy_delta = pan_joy_delta + VJOYSTICK_SPEED;
				}
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 'd') || (get_key == 'D'))
			{	
				if (pan_joy_delta > -100)
				{
					pan_joy_delta = pan_joy_delta - VJOYSTICK_SPEED;
				}
				get_key = 0; //stay in while loop
			}			
			else if 	((get_key == 'w') || (get_key == 'W'))
			{	
				if (tilt_joy_delta < 100)
				{				
					tilt_joy_delta = tilt_joy_delta + VJOYSTICK_SPEED;
				}
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 'z') || (get_key == 'Z'))
			{	
				if (tilt_joy_delta > -100)
				{					
					tilt_joy_delta = tilt_joy_delta - VJOYSTICK_SPEED;
				}
				get_key = 0; //stay in while loop
			}
			else if 	((get_key == 's') || (get_key == 'S'))
			{	
				pan_joy_delta   = 0;
				tilt_joy_delta  = 0;
				get_key = 0; //stay in while loop
			}
			
			pan_axis.mc.master_joy_sample_delta  = (int32)pan_joy_delta;	//Make Pan  Virtual Joystick			
			tilt_axis.mc.master_joy_sample_delta = (int32)tilt_joy_delta;	//Make Tilt Virtual Joystick
		}
		
		pan_axis.mc.master_joy_sample_delta  = 0;							//stop Pan  Virtual Joystick
		tilt_axis.mc.master_joy_sample_delta = 0;							//stop Tilt Virtual Joystick
	
		goto exitpars;
	}
	/* END CMD VIRTUAL PAN+TILT JOYSTICK */	

	
	/* NOP CMD */	
	if (strlen(actual_cmd.action) == 0)
	{
	goto exitpars;
	}
	/* END NOP CMD */

	
	/* CMD 'VERSION' (alias V) */	
	if (((strcmp(actual_cmd.action, "v") == 0)
		|| (strcmp(actual_cmd.action, "version") == 0)))
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf(STR_FW_VERS);
			printf(STR_COPY);
			printf(STR_AUTHOR1);
			printf(STR_AUTHOR2);
			printf(STR_AUTHOR3);
			printf(STR_AUTHOR4);			
		}
		else
		{
			printf(STR_ERROR1);
		}
	goto exitpars;
	}
	/* END CMD VERSION */ 


	/* CMD 'PROMPT' */	
	if (strcmp(actual_cmd.action, "prompt") == 0)
	{
		if (strlen(actual_cmd.parameter) == 0)
		{
			printf(STR_PROMPT0);
			printf(STR_PROMPT1);
			printf(STR_PROMPT2);
			printf(STR_PROMPT3);
			printf(STR_PROMPT4);			
		}
		else
		{
			printf(STR_ERROR1);
		}
	goto exitpars;
	}
	/* END CMD PROMPT */ 

		
	
		/* CMD 'HELP' (alias ?) */
		if ((strcmp(actual_cmd.action, "?") == 0)
			||(strcmp(actual_cmd.action, "h") == 0)
			||(strcmp(actual_cmd.action, "help") == 0))
		{
			if (strlen(actual_cmd.parameter) == 0)
			{
				// HELP "standard" command list
				printf(STR_HELP_PRES1);
				printf(STR_HELP_PRES4);
				printf(STR_HELP_SHOW1);
				printf(STR_HELP_SETT1);
				printf(STR_HELP_PROM1);
				printf(STR_HELP_BOOT1);				
				printf(STR_HELP_VERS1);
				printf(STR_HELP_HELP0);				
				printf(STR_HELP_HELP1);						
				printf(STR_HELP_PRES2);
				printf("\r\n");		
				
				/* Motor Control Command List */
				printf(STR_HELP_PRES5);
				printf(STR_HELP_PRES6);
				printf(STR_HELP_ENERG);
				printf(STR_HELP_DEENE);				
				printf("\r\n");	

				/* Mover Command List		 */
				printf(STR_HELP_MOV01);
				printf(STR_HELP_MOV02);
				printf(STR_HELP_MOV03);
				printf(STR_HELP_MOV04);
				printf(STR_HELP_MOV05);				
				printf("\r\n");					
				
				/* System Test Command List  */
				printf(STR_HELP_PRES7);
				printf(STR_HELP_PRES8);	
				printf(STR_HELP_TBUZZ);	
				printf(STR_HELP_TLORA);
#if ITG_3701_ENABLED				
				printf(STR_HELP_TINV);
#endif
				printf(STR_HELP_STSM);
				printf(STR_HELP_DMAP);
				printf(STR_HELP_DMAT);
				printf(STR_HELP_DMPT);				
				printf("\r\n");	
				
				/* Mean Values & Statistics Measurments Command List */
				printf(STR_HELP_PRES9);
				printf(STR_HELP_PRESA);
				printf(STR_HELP_AGSTA);
				printf(STR_HELP_AGSTO);				
				printf("\r\n");				
				
//				/* DAS Command List */
//				printf(STR_HELP_DAS01);
//				printf(STR_HELP_DAS02);
//				printf(STR_HELP_DAS03);				
//				printf(STR_HELP_DAS04);
//				printf(STR_HELP_DAS05);
//				printf(STR_HELP_DAS06);
//				printf(STR_HELP_DAS07);
//				printf(STR_HELP_DAS08);
//				printf(STR_HELP_DAS09);
//				printf(STR_HELP_DAS0A);				
			}
			else
			{
				// SET command details
				if (strcmp(actual_cmd.parameter, "set") == 0)
				{
					printf(STR_HELP_SETT1);
					printf(STR_HELP_SYNTX);			
					printf(STR_HELP_SETT2);
					printf(STR_HELP_SETT2T);					
					printf(STR_HELP_SETT3);
					printf(STR_HELP_SETT3T);					
					printf(STR_HELP_SETT4);
					printf(STR_HELP_SETT4T);					
					printf(STR_HELP_SETT5);
					printf(STR_HELP_SETT5T);					
					printf(STR_HELP_SETT6);
					printf(STR_HELP_SETT6T);
					printf(STR_HELP_SETT6U);
					printf(STR_HELP_SETT6V);					
					printf(STR_HELP_SET61);
					printf(STR_HELP_SET62);
					printf(STR_HELP_SET63);
					printf(STR_HELP_SET64);
					printf(STR_HELP_SET65);
					printf(STR_HELP_SET66);	
					printf(STR_HELP_SET67);
					printf(STR_HELP_SET68);
					printf(STR_HELP_SET69);
					printf(STR_HELP_SET70);					
					printf(STR_HELP_SET71);
					printf(STR_HELP_SET72);
					printf(STR_HELP_SET73);					
					
					printf(STR_HELP_SET80);
					printf(STR_HELP_SET81);	
					printf(STR_HELP_SET82);
					printf(STR_HELP_SET83);
					printf(STR_HELP_SET84);
					printf(STR_HELP_SET85);
					printf(STR_HELP_SET86);
					printf(STR_HELP_SET87);					
					printf(STR_HELP_SET88);
					printf(STR_HELP_SET89);		
					
					printf(STR_HELP_SETTC);					
					printf(STR_HELP_SETC1);	
					printf(STR_HELP_SETC2);	
					printf(STR_HELP_SETC3);	
					printf(STR_HELP_SETC4);	
					printf(STR_HELP_SETC5);	
					
					printf(STR_HELP_SETTF);
					printf(STR_HELP_SETTG);
					printf(STR_HELP_SETTH);
					printf(STR_HELP_SETTI);
					printf(STR_HELP_SETI1);					
					printf(STR_HELP_SETTJ);
					printf(STR_HELP_SETTK);
					
					printf("\r\n");		
					printf(STR_HELP_polar); 
					printf(STR_HELP_kpval);
					printf(STR_HELP_kdval);
					printf(STR_HELP_kival);					
					printf(STR_HELP_ksivl);
					printf(STR_HELP_dbval);					
					printf(STR_HELP_kofvl);	
					printf(STR_HELP_again);
					printf(STR_HELP_astyp);					
					printf(STR_HELP_color);
					printf(STR_HELP_colo1);
					printf(STR_HELP_axis);					
					printf(STR_HELP_avalu);					
					printf(STR_HELP_onoff);
					printf(STR_HELP_mode);
					printf(STR_HELP_qn);
					printf(STR_HELP_qm);
					printf(STR_HELP_dir);					
					printf(STR_HELP_dir1);
					printf(STR_HELP_dir2);					
					
					goto exitpars;
				}
	
	
				// HELP SHOW command details
				if (strcmp(actual_cmd.parameter, "show") == 0)
				{
					printf(STR_HELP_SHOW1);
					printf(STR_HELP_SYNTX);
					printf(STR_HELP_SHOW2);
					printf(STR_HELP_SHO21);					
					printf(STR_HELP_SHOW3);					
					printf(STR_HELP_SHOW4);
					//printf(STR_HELP_SHOW5);						
					printf(STR_HELP_SHOW6);
#if IMU_UM7_ENABLED
					printf(STR_HELP_SHW70);					
					printf(STR_HELP_SHW71);					
					printf(STR_HELP_SHW72);
#endif					
					printf(STR_HELP_SHW73);

					printf(STR_HELP_SHOW8);
					printf(STR_HELP_SHOW9);
					printf(STR_HELP_SHW90);					
					printf(STR_HELP_SHW91);
					printf(STR_HELP_SHW92);
					printf(STR_HELP_SHW93);
					printf(STR_HELP_SHW94);
					printf(STR_HELP_SHW95);
					printf(STR_HELP_SHW96);					
					printf(STR_HELP_SHOWA);
					printf(STR_HELP_SHWA1);
					printf(STR_HELP_SHWA2);	
					printf(STR_HELP_SHWA3);
					printf(STR_HELP_SHWA4);	
					printf(STR_HELP_SHWA5);	
					printf(STR_HELP_SHWA6);						
					printf(STR_HELP_SHWA7);						
					printf(STR_HELP_SHOWB);
					printf(STR_HELP_SHOWC);
					printf(STR_HELP_SHOWD);	
					printf(STR_HELP_SHOWE);
					printf(STR_HELP_SHOWF);	
					printf(STR_HELP_SHOF1);
					printf(STR_HELP_SHOF2);
					printf(STR_HELP_SHOF3);					
					printf(STR_HELP_SHOWG);
					printf(STR_HELP_SHOWH);					
					printf(STR_HELP_SHOWZ);
					goto exitpars;
				}
	
				
				// HELP GOTOQ command details
				if (strcmp(actual_cmd.parameter, "q") == 0)
				{					
					//Qtable
					printf(STR_QTAB0);
					printf(STR_QTAB1);
					printf(STR_Q000);
					printf(STR_Q011);					
					printf(STR_Q013);					
					printf(STR_Q014);			
					printf(STR_Q015);					
					printf(STR_Q016);					
					printf(STR_Q017);
					printf(STR_Q021);
					printf(STR_Q031);
					printf(STR_Q033);
					printf(STR_Q034);
					printf(STR_Q040);					
					printf(STR_Q041);					
					printf(STR_Q042);
					printf(STR_Q043);
					printf(STR_Q044);					
					printf(STR_Q051);
					printf(STR_Q052);
					printf(STR_Q053);					
					
					goto exitpars;
				}			
				
				
				// HELP TESTDAC command details
				if (strcmp(actual_cmd.parameter, "testdac") == 0)
				{
					printf(STR_HELP_TDAC1);
					printf(STR_HELP_SYNTX);
					printf(STR_HELP_TDAC2);
					goto exitpars;
				}			


				// HELP PROMPT command details
				if (strcmp(actual_cmd.parameter, "prompt") == 0)
				{
					printf(STR_HELP_PROM1);
					printf(STR_HELP_SYNTX);
					printf(STR_HELP_PROM2);
					goto exitpars;
				}			
				
				
				// HELP VERSION command details
				if ((strcmp(actual_cmd.parameter, "version") == 0)
				||(strcmp(actual_cmd.parameter, "v") == 0))
				{
					printf(STR_HELP_VERS1);
					printf(STR_HELP_SYNTX);
					printf(STR_HELP_VERS2);
					printf(STR_HELP_VERS3);				
					goto exitpars;
				}
				printf(STR_ERROR3);	/* Bad Parameter(s) */
				goto exitpars;
			}
		goto exitpars;		
		}
		/* END CMD HELP */
	
	
		/* CMD SHOW */
		if ((strcmp(actual_cmd.action, "show") == 0) ||
		   (strcmp(actual_cmd.action, "s") == 0))
		{
			// SHOW CONTROL
			if ((strcmp(actual_cmd.parameter, "control") == 0)	
			|| (strcmp(actual_cmd.parameter, "ctrl") == 0) 
			|| (strlen(actual_cmd.parameter) == 0))
			{
				printf("\x1B[2J");			/* Erase Screen (ESC=\x1B) 	*/
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("\x1B[H");		/* Cursor Home (ESC=\x1B)	*/
					printf("---------------------------------\r\n");
					printf("--- GoBee Director RT CONTROL ---\r\n");
					printf("---------------------------------\r\n");
					printf("\r\n");
									
//					printf("agyro rate=%1.4f", (float)agyro.rate);
//					printf_spc(7);
//					printf("  lpf(rate)=%1.4f [deg/s]", (float)agyro.rate_lowpass);
//					printf_spc(7);
//					printf("  angle=%1.4f [deg]", (float)agyro.angle);
//					printf_spc(7);							
//					printf("\r\n");	
//					printf("\r\n");	

//					printf("fbk enc rate=%1.4f [deg/s]", (float)pan_feedback_encoder.angular_velocity);
//					printf_spc(7);
//					printf("  angle=%1.4f [deg]", (float)pan_feedback_encoder.angle);	

					printf("axis_res(P)=%+1.3f [step/2PI]", (float)pan_axis.param.resolution.fnum);
					printf_spc(1);					
					printf("axis_res(T)=%+1.3f [step/2PI]", (float)tilt_axis.param.resolution.fnum);
					printf("\r\n");							
					
					printf("angle(P)=%+1.4f [deg]", (float)pan_axis.mc.slave_enc.position * 360/pan_axis.param.resolution.fnum);
					printf_spc(13);					
					printf("angle(T)=%+1.4f [deg]", (float)tilt_axis.mc.slave_enc.position * 360/tilt_axis.param.resolution.fnum);
					printf("\r\n");						
					printf("\r\n");		
					
					printf("fbk(P)=%+1.4f [step]", (float)pan_axis.mc.slave_enc.position);
					printf_spc(14);					
					printf("fbk(T)=%+1.4f [step]", (float)tilt_axis.mc.slave_enc.position);
					printf("\r\n");						

					printf("mast_enc(P)=%+1.4f [step]", (float)pan_axis.mc.master_enc_position);
					printf_spc(9);					
					printf("mast_enc(T)=%+1.4f [step]", (float)tilt_axis.mc.master_enc_position);
					printf("\r\n");
					
					printf("mast_joy(P)=%+1.4f [step]", (float)pan_axis.mc.master_joy_position);
					printf_spc(9);					
					printf("mast_joy(T)=%+1.4f [step]", (float)tilt_axis.mc.master_joy_position);					
					
					printf("\r\n");
					printf("\r\n");
					
					printf("err(P)=%+1.4f", (float)pan_axis.mc.error);
					printf_spc(21);					
					printf("err(T)=%+1.4f", (float)tilt_axis.mc.error);
					printf("\r\n");	
					
					printf("derr(P)=%+1.4f", (float)pan_axis.mc.derror);
					printf_spc(20);
					printf("derr(T)=%+1.4f", (float)tilt_axis.mc.derror);
					printf("\r\n");	

					printf("ierr(P)=%+1.4f", (float)pan_axis.mc.ierror);
					printf_spc(20);
					printf("ierr(T)=%+1.4f", (float)tilt_axis.mc.ierror);
					printf("\r\n");	
					
					printf("cv(P)=%+1.4f", (float)pan_axis.mc.ctrl_var);
					printf_spc(22);
					printf("cv(T)=%+1.4f", (float)tilt_axis.mc.ctrl_var);
					printf("\r\n");	
					
					printf("pwm_var(P)= %4i", (uint16)pan_axis.mc.pwm_var);
					printf_spc(19);
					printf("pwm_var(T)= %4i", (uint16)tilt_axis.mc.pwm_var);
					printf("\r\n");					

					strcpy(slegenda,"PAN  TORQUE:"); 
					print_hystogram_border(50, &slegenda[0]);    
					print_abs_linear_hystogram((int16)pan_axis.mc.ctrl_var, MOTOR_PWM_PERIOD_HALF, 50, &slegenda[0]);
//					print_hystogram_border(50, &slegenda[0]);					
//					printf("\r\n");
					
					strcpy(slegenda,"TILT TORQUE:"); 
					print_abs_linear_hystogram((int16)tilt_axis.mc.ctrl_var, MOTOR_PWM_PERIOD_HALF, 50, &slegenda[0]);
					print_hystogram_border(50, &slegenda[0]); 		
					
					printf("\r\n");
					printf("MACHINE\r\n");
					printf("-------\r\n");					
					printf("Power Status =");
					if (machine_state == GOBEE_DEENERGIZED)
					{
						printf(" Global DEENERGIZED\r\n");	/* Motor Control Power Global Deenergized */				
					}		
					else if (machine_state == GOBEE_ENERGIZED)
					{
						printf(" Global ENERGIZED!\r\n");	/* Motor Control Power Global Energized */		
					}			
					else
					{
						printf(" DANGER!!! INTERNAL FIRMWARE FAULT\r\n");	/* Firmware Fault */		
					}	
					printf("ctrl isr counters START=%5i STOP=%5i  \r\n", (uint16)isr_START_check_counter,(uint16)isr_STOP_check_counter);
	
					printf("\r\n");						
					CyDelay(50);
				}
				printf("\r\n");	
				goto exitpars;	
			}
			// SHOW CONTROL END
			
			
			// SHOW ANALOG INPUTS
			if ((strcmp(actual_cmd.parameter, "analogs") == 0)	
			|| (strcmp(actual_cmd.parameter, "ana") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{			
					printf("I_P=%5d",     (int16)AdcValue[SENSE_IPAN]);
					printf(" I_T=%5d", (int16)AdcValue[SENSE_ITILT]);					
					printf(" Vcc=%5d",    (int16)AdcValue[SENSE_VCC]);
					printf(" Ax=%5d",     (int16)AdcValue[ADXL_X]);
					printf(" Ay=%5d",     (int16)AdcValue[ADXL_Y]);
					printf(" Az=%5d",     (int16)AdcValue[ADXL_Z]);
					printf(" ABS_P=%5d",     (int16)AdcValue[HOME_PAN_ABSV]);
					printf(" ABS_T=%5d",     (int16)AdcValue[HOME_TILT_ABSV]);
					printf(" astim=%5d",     (int16)AdcValue[CTRL_IN_ASTIM]);
					
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// END SHOW ANALOG INPUTS

			
			// SHOW VCC
			if (strcmp(actual_cmd.parameter, "vcc") == 0)	
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					// ADC_Count = VCC[V] * 5k/55k * (1+100/1000) * ADC_MAX_UNSGN/5  (14 bit resolution)
					// VCC[V] = ADC_Count * 50/ADC_MAX_UNSGN
					printf("VCC = %3.1f [V]\r\n", (float)AdcValue[SENSE_VCC]*5.0/ADC_MAX_COUNTS);
					CyDelay(100);
				}
				goto exitpars;	
			}
			// END SHOW VCC
			
			// SHOW CURRENT
			if ((strcmp(actual_cmd.parameter, "current") == 0) ||
				(strcmp(actual_cmd.parameter, "i") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{					
					printf("i(t)_PAN = %5.4f [A]  i(t)_TILT = %5.4f [A]",
							(float)pan_axis.mc.current,
							(float)tilt_axis.mc.current);
					
					printf("     Drive Status=%2u ", (int16)Status_Reg_MOTORS_Read());
					if ((Status_Reg_MOTORS_Read() & SR_PAN_MOT_FL) == 0)
					{
						printf("(i(t)_PAN PEAK!) ");	
					}
					else
					{
						printf("(i(t)_PAN OK!)  ");						
					}
					
					if ((Status_Reg_MOTORS_Read() & SR_TILT_MOT_FL) == 0)
					{
						printf("(i(t)_TILT PEAK!)");	
					}
					else
					{
						printf("(i(t)_TILT OK!)");						
					}	
					CyDelay(100);
					printf("\r\n");
				}
				goto exitpars;	
			}
			// END SHOW CURRENT

			
			// SHOW PAN MOTOR TORQUE STATISTICS
			if ((strcmp(actual_cmd.parameter, "pmtorque") == 0) ||
				(strcmp(actual_cmd.parameter, "pmt") == 0))
			{
				isr_TORQUESTAT_Start();								/* start torque statistics isr	 			*/
				
				current_statistics_start(&pan_current_stat);		/* start Pan current  statistics			*/
				Battery_Energy_Integral_Reset(&pan_torque_stat);	/* Battery Energy Integral Reset 			*/
				
				printf("\r\nAxis=Pan\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("i_t=%3.3f[A] (nl=%3.3f[A])  TMOT_t=%3.2f[mNm]  i_max=%3.2f[A]  TMOT_max=%3.2f[mNm]  i_med=%3.2f[A]  TMOT_med=%3.2f[mNm]\r\n",
							(float)i_t(&pan_torque_stat),
							(float)i_noload(),
							(float)TMOT_t(&pan_torque_stat),							
							(float)i_max(&pan_current_stat),
							(float)TMOT_max(&pan_current_stat),
							(float)i_mean(&pan_current_stat),
							(float)TMOT_mean(&pan_current_stat));
					
					CyDelay(30);
				}
				current_statistics_stop(&pan_current_stat);		/* stop Pan current  statistics			*/
				isr_TORQUESTAT_Stop();							/* stop torque statistics isr			*/
				
				printf("\r\nBattery Capacity Used=%3.2f [mAh]  Percentage(1000mAh)=%3.2f [%%]\r\n",
					(float)Battery_Energy(&pan_torque_stat, &pan_current_stat),
					(float)Battery_Energy_Meter(&pan_torque_stat, &pan_current_stat, 1000));
				
				goto exitpars;	
			}
			// END SHOW PAN MOTOR TORQUE STATISTICS
			
			
			// SHOW TILT MOTOR TORQUE STATISTICS
			if ((strcmp(actual_cmd.parameter, "tmtorque") == 0) ||
				(strcmp(actual_cmd.parameter, "tmt") == 0))
			{
				isr_TORQUESTAT_Start();								/* start torque statistics isr	 			*/
				
				current_statistics_start(&tilt_current_stat);		/* start Tilt current  statistics			*/
				Battery_Energy_Integral_Reset(&tilt_torque_stat);	/* Battery Energy Integral Reset 			*/
				
				printf("\r\nAxis=Tilt\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("i_t=%3.3f[A] (nl=%3.3f[A])  TMOT_t=%3.2f[mNm]  i_max=%3.2f[A]  TMOT_max=%3.2f[mNm]  i_med=%3.2f[A]  TMOT_med=%3.2f[mNm]\r\n",
							(float)i_t(&tilt_torque_stat),
							(float)i_noload(),							
							(float)TMOT_t(&tilt_torque_stat),							
							(float)i_max(&tilt_current_stat),
							(float)TMOT_max(&tilt_current_stat),
							(float)i_mean(&tilt_current_stat),
							(float)TMOT_mean(&tilt_current_stat));
					
					CyDelay(30);
				}
				current_statistics_stop(&tilt_current_stat);	/* stop Tilt current  statistics			*/				
				isr_TORQUESTAT_Stop();							/* stop torque statistics isr				*/
				
				printf("\r\nBattery Capacity Used=%3.2f [mAh]  Percentage(1000mAh)=%3.2f [%%]\r\n",
					(float)Battery_Energy(&tilt_torque_stat, &tilt_current_stat),
					(float)Battery_Energy_Meter(&tilt_torque_stat, &tilt_current_stat, 1000));
				
				goto exitpars;	
			}
			// END SHOW TILT MOTOR TORQUE STATISTICS
			
			
			// SHOW PAN OUTPUT TORQUE STATISTICS
			if ((strcmp(actual_cmd.parameter, "potorque") == 0) ||
				(strcmp(actual_cmd.parameter, "pot") == 0))
			{
				isr_TORQUESTAT_Start();								/* start torque statistics isr	 			*/
				
				current_statistics_start(&pan_current_stat);		/* start Pan current  statistics			*/
				Battery_Energy_Integral_Reset(&pan_torque_stat);	/* Battery Energy Integral Reset 			*/
				
				printf("\r\nAxis=Pan\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("i_t=%3.3f[A] (nl=%3.3f[A])  TOUT_t=%3.2f[mNm]  i_max=%3.2f[A]  TOUT_max=%3.2f[mNm]  i_med=%3.2f[A]  TOUT_med=%3.2f[mNm]\r\n",
							(float)i_t(&pan_torque_stat),
							(float)i_noload(),
							(float)TOUT_t(&pan_torque_stat, N_pan),							
							(float)i_max(&pan_current_stat),
							(float)TOUT_max(&pan_current_stat, N_pan),
							(float)i_mean(&pan_current_stat),
							(float)TOUT_mean(&pan_current_stat, N_pan));
					
					CyDelay(30);
				}
				current_statistics_stop(&pan_current_stat);			/* stop Pan current  statistics			*/				
				isr_TORQUESTAT_Stop();								/* stop torque statistics isr			*/
				
				printf("\r\nBattery Capacity Used=%3.2f [mAh]  Percentage(1000mAh)=%3.2f [%%]\r\n",
					(float)Battery_Energy(&pan_torque_stat, &pan_current_stat),
					(float)Battery_Energy_Meter(&pan_torque_stat, &pan_current_stat, 1000));
				
				goto exitpars;	
			}
			// END SHOW PAN OUTPUT TORQUE STATISTICS
			
			
			// SHOW TILT OUTPUT TORQUE STATISTICS
			if ((strcmp(actual_cmd.parameter, "totorque") == 0) ||
				(strcmp(actual_cmd.parameter, "tot") == 0))
			{
				isr_TORQUESTAT_Start();							/* start torque statistics isr	 			*/
				
				current_statistics_start(&tilt_current_stat);	/* start Tilt current  statistics			*/
				Battery_Energy_Integral_Reset(&tilt_torque_stat);	/* Battery Energy Integral Reset 			*/
				
				printf("\r\nAxis=Tilt\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("i_t=%3.3f[A] (nl=%3.3f[A])  TOUT_t=%3.2f[mNm]  i_max=%3.2f[A]  TOUT_max=%3.2f[mNm]  i_med=%3.2f[A]  TOUT_med=%3.2f[mNm]\r\n",
							(float)i_t(&tilt_torque_stat),
							(float)i_noload(),							
							(float)TOUT_t(&tilt_torque_stat, N_tilt),							
							(float)i_max(&tilt_current_stat),
							(float)TOUT_max(&tilt_current_stat, N_tilt),
							(float)i_mean(&tilt_current_stat),
							(float)TOUT_mean(&tilt_current_stat, N_tilt));					
					
					CyDelay(30);
				}
				current_statistics_stop(&tilt_current_stat);	/* stop Tilt current  statistics			*/				
				isr_TORQUESTAT_Stop();							/* stop torque statistics isr				*/
				
				printf("\r\nBattery Capacity Used=%3.2f [mAh]  Percentage(1000mAh)=%3.2f [%%]\r\n",
					(float)Battery_Energy(&tilt_torque_stat, &tilt_current_stat),
					(float)Battery_Energy_Meter(&tilt_torque_stat, &tilt_current_stat, 1000));
				
				goto exitpars;	
			}
			// END SHOW TILT OUTPUT TORQUE STATISTICS			
	

			// SHOW PAN MOTOR EROGATED POWER STATISTICS
			if ((strcmp(actual_cmd.parameter, "pmpower") == 0) ||
				(strcmp(actual_cmd.parameter, "pmp") == 0))
			{
				isr_TORQUESTAT_Start();									/* start torque statistics isr	 						*/
	
				motor_abs_velocity_sampling_init(&pan_torque_stat);		/* initialize Pan Motor abs(Angular Velocity) Sampling 	*/
				qpower_statistics_start(&pan_qpower_stat);				/* start quasi-power Statistics							*/
				
				printf("\r\nAxis=Pan\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					//simultaneous sampling
					float my_torque = TMOT_t(&pan_torque_stat);
					float my_omega  = omega_t(&pan_torque_stat);
					float my_rpm    = rpm_t(&pan_torque_stat);
					float my_pm_t   = PMOTE_t(&pan_torque_stat);
					float my_pm_max = PMOTE_max(&pan_qpower_stat);
					float my_pm_med = PMOTE_mean(&pan_qpower_stat);
					
					printf("T(t)=%3.1f[mNm]  v(t)=%3.1f[rad/sec](%3.1f[rpm])  p(t)=%3.1f[mW]  pmax=%3.1f[mW]  pmed=%3.1f[mW]\r\n",
							(float)my_torque,
							(float)my_omega,
							(float)my_rpm,							
							(float)my_pm_t,
							(float)my_pm_max,
							(float)my_pm_med);
					
					CyDelay(30);
				}
				qpower_statistics_stop(&pan_qpower_stat);				/* stop quasi-power Statistics	   						*/				
				isr_TORQUESTAT_Stop();									/* stop torque statistics isr							*/
								
				goto exitpars;	
			}
			// END SHOW PAN MOTOR EROGATED POWER STATISTICS			
		
			
			// SHOW TILT MOTOR EROGATED POWER STATISTICS
			if ((strcmp(actual_cmd.parameter, "tmpower") == 0) ||
				(strcmp(actual_cmd.parameter, "tmp") == 0))
			{
				isr_TORQUESTAT_Start();									/* start torque statistics isr	 						*/
	
				motor_abs_velocity_sampling_init(&tilt_torque_stat);	/* Initialize Tilt Motor abs(Angular Velocity) Sampling */
				qpower_statistics_start(&tilt_qpower_stat);				/* initialize quasi-power Statistics					*/
				
				printf("\r\nAxis=Tilt\r\n\r\n");
				CyDelay(500);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					//simultaneous sampling
					float my_torque = TMOT_t(&tilt_torque_stat);
					float my_omega  = omega_t(&tilt_torque_stat);
					float my_rpm    = rpm_t(&tilt_torque_stat);
					float my_pm_t   = PMOTE_t(&tilt_torque_stat);
					float my_pm_max = PMOTE_max(&tilt_qpower_stat);
					float my_pm_med = PMOTE_mean(&tilt_qpower_stat);
					
					printf("T(t)=%3.1f[mNm]  v(t)=%3.1f[rad/sec](%3.1f[rpm])  p(t)=%3.1f[mW]  pmax=%3.1f[mW]  pmed=%3.1f[mW]\r\n",
							(float)my_torque,
							(float)my_omega,
							(float)my_rpm,							
							(float)my_pm_t,
							(float)my_pm_max,
							(float)my_pm_med);
					
					CyDelay(30);
				}
				qpower_statistics_stop(&tilt_qpower_stat);	/* stops quasi-power Statistics							*/				
				isr_TORQUESTAT_Stop();						/* stop torque statistics isr							*/
				
				goto exitpars;	
			}
			// END SHOW TILT MOTOR EROGATED POWER STATISTICS				
			
			
			// SHOW PAN ABSOLUTE SENSOR STATS
			if ((strcmp(actual_cmd.parameter, "pabsstats") == 0)	
			|| (strcmp(actual_cmd.parameter, "pabs") == 0))
			{			
				printf("PAN Absolute Sensor:");					
				printf(" mean=%+1.1f [raw]", (float) pan_absolute_sensor_stat.mean);
				printf(" max=%+1.1f [raw]", (float) pan_absolute_sensor_stat.max);
				printf(" min=%+1.1f [raw]", (float) pan_absolute_sensor_stat.min);					
				printf(" range=%+1.1f [raw]", (float) pan_absolute_sensor_stat.range);						
					
				printf("\r\n");	

				goto exitpars;	
			}
			// SHOW PAN ABSOLUTE SENSOR STATS END	
			
			
			// SHOW TILT ABSOLUTE SENSOR STATS
			if ((strcmp(actual_cmd.parameter, "tabsstats") == 0)	
			|| (strcmp(actual_cmd.parameter, "tabs") == 0))
			{			
				printf("TILT Absolute Sensor:");					
				printf(" mean=%+1.1f [raw]", (float) tilt_absolute_sensor_stat.mean);
				printf(" max=%+1.1f [raw]", (float) tilt_absolute_sensor_stat.max);
				printf(" min=%+1.1f [raw]", (float) tilt_absolute_sensor_stat.min);					
				printf(" range=%+1.1f [raw]", (float) tilt_absolute_sensor_stat.range);						
					
				printf("\r\n");	

				goto exitpars;	
			}
			// SHOW TILT ABSOLUTE SENSOR STATS END	

			
			// SHOW ASTIM
			if (strcmp(actual_cmd.parameter, "astim") == 0)	
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{					
					printf("ASTIM(ADC_INPUT) =%+5d [lsb]", (int16)AdcValue[CTRL_IN_ASTIM]);					
					printf("   ASTIM(P)=%+5.1f [step]", (float)pan_axis.mc.Float_ASTIM);
					printf("   ASTIM(T)=%+5.1f [step]\r\n", (float)tilt_axis.mc.Float_ASTIM);
					CyDelay(10);
				}
				goto exitpars;	
			}
			// END SHOW astim			
			
			
#if ITG_3701_ENABLED			
			// SHOW ITG-3701 DIGITAL GYRO
			if ((strcmp(actual_cmd.parameter, "itg3701") == 0)	
			|| (strcmp(actual_cmd.parameter, "3701") == 0))
			{
				// Verify HW connection
				dummy = ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_WHO_AM_I);  // Read WHO_AM_I register for ITG3701 gyro
			  	printf("ITG3701 gyro; I AM 0x%02X (should be 0x68)\r\n",(uint16)dummy);
				CyDelay(1);
				
//				// Initialize ITG-3701 gyro
//				initITG3701();

//			    // Calibrate gyro loading biases in bias registers
//			    gyrocalITG3701(gyroBias);

//				// get sensor resolutions, only need to do this once (calculates gRes)
//			   	getGres();	
			   	printf("ITG3701 gyro sensitivity is %1.4f LSB/dps\r\n", (float)1.0/(gRes));	
				
				// verify and print sensor resolution HW register
				dummy = ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG); // Read ITG3701_GYRO_CONFIG register for ITG3701
				printf("ITG3701_GYRO_CONFIG = 0x%02X\r\n\r\n",(uint16)dummy);
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					if (ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_INT_STATUS) & 0x01)  // check if new gyro data is ready  
					{
						readGyroData(gyroCount);  // Read the x/y/z adc values

					    // Calculate the gyro value into actual degrees per second
					    gx = (float)gyroCount[0]*gRes - gyroBias[0];  // get actual gyro value, this depends on scale being set
					    gy = (float)gyroCount[1]*gRes - gyroBias[1];  
					    gz = (float)gyroCount[2]*gRes - gyroBias[2]; 
					}
					printf("gx=%1.4f gy=%1.4f gz=%1.4f\r\n",(float)gx, (float)gy, (float)gz);
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW ITG-3701 DIGITAL GYRO END			
#endif

#if IMU_UM7_ENABLED
			// SHOW IMU CHR-UM7-LT CH ROBOTICS (rgatti code)
			if ((strcmp(actual_cmd.parameter, "imuum7") == 0)	
			|| (strcmp(actual_cmd.parameter, "imu") == 0))
			{
				//IMU_UM7_PACKETIZER_Debug(true);
				while (AnyButtonPressed() == NO_PRESSED)
				{	
					print_euler_angles(&euler_angles);
					
//					if(IMU_UM7_Error())
//					{
						printf(" Serial errors=%d", IMU_UM7_serial_errors_count);
//					}
					
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW IMU CHR-UM7-LT CH ROBOTICS (rgatti code) END
			
			// SHOW IMU CHR-UM7-LT SETTINGS (rgatti code)
			if ((strcmp(actual_cmd.parameter, "imuset") == 0)	
			|| (strcmp(actual_cmd.parameter, "imusettings") == 0))
			{	
//				isr_CTRL_Stop();				/* Stop Control ISR						 	 	 */
//				CyDelay(10);	
				
				IMU_UM7_Stop();					/* Stop CH ROBOTICS UM7-LT IMU (rgatti code) 	 */				
				IMU_UM7_UART_ClearRxBuffer();	/* Clear IMU-UM7 Psoc HW Component RX Buffer	 */				
				IMU_UM7_InitAndStart();			/* Re-Start CH ROBOTICS UM7-LT IMU (rgatti code) */	
				CyDelay(10);					
				IMU_UM7_PrintSettings();
				
				printf("\r\nERRORS:");
				printf("\r\n  Serial errors=%d", IMU_UM7_serial_errors_count);
				
				printf("\r\n");	
				CyDelay(50);
			
				IMU_UM7_Stop();					/* Stop CH ROBOTICS UM7-LT IMU (rgatti code) 	*/
				IMU_UM7_UART_ClearRxBuffer();	/* Clear IMU-UM7 Psoc HW Component RX Buffer	*/				
				IMU_UM7_InitAndStart();			/* Re-Start CH ROBOTICS UM7-LT IMU (rgatti code)*/
				
//				CyDelay(10);				
//				isr_CTRL_Start();				/* Re-Start Control ISR				 	 	 	*/
					
				goto exitpars;	
			}
			// SHOW IMU CHR-UM7-LT SETTINGS (rgatti code) END	
			
			
			// SHOW IMU CHR-UM7-LT SERIAL ERRORS (rgatti code)
			if ((strcmp(actual_cmd.parameter, "imuerr") == 0)	
			|| (strcmp(actual_cmd.parameter, "imuerrors") == 0))
			{	
				while (AnyButtonPressed() == NO_PRESSED)
				{					
					printf("\r\nIMU UM7-LT Serial errors=%d", IMU_UM7_serial_errors_count);
					CyDelay(50);
				}
				printf("\r\n");	

				goto exitpars;	
			}
			// SHOW IMU CHR-UM7-LT SERIAL ERRORS (rgatti code) END				
#endif			

			// SHOW BIKE EULER ANGLES
			if ((strcmp(actual_cmd.parameter, "bikeangles") == 0)	
			|| (strcmp(actual_cmd.parameter, "bike") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{	
   					 printf("BIKE EULER LPF ANGLES: YAW(pan):%6.3f | PITCH(tilt):%6.3f | ROLL(roll):%6.3f |\r\n",
							(float)IMU_sensor.bike_yaw_lpf,
							(float)IMU_sensor.bike_pitch_lpf,
							(float)IMU_sensor.bike_roll_lpf);
					CyDelay(50);
				}
				goto exitpars;	
			}
			// BIKE EULER ANGLES END			

			
			// SHOW ANALOG 3D ACCELEROMETER
			if ((strcmp(actual_cmd.parameter, "analogacc") == 0)	
			|| (strcmp(actual_cmd.parameter, "aacc") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("x=%+1.4f[g] (%5i)", (float) aacc.x_axis.acceleration_lpf, (int16)aacc.x_axis.ADC);
					printf(" y=%+1.4f[g] (%5i)", (float) aacc.y_axis.acceleration_lpf, (int16)aacc.y_axis.ADC);					
					printf(" z=%+1.4f[g] (%5i)", (float) aacc.z_axis.acceleration_lpf, (int16)aacc.z_axis.ADC);
					printf(" modulo=%+1.4f[g]", (float) aacc.modulo);					
					printf(" sdyn=%+1.4f[g^2]", (float) aacc.system_dynamic_scalar);

					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW ANALOG 3D ACCELEROMETER END

			
			// SHOW ESTIMATED EVENTS
			if ((strcmp(actual_cmd.parameter, "events") == 0)	
			|| (strcmp(actual_cmd.parameter, "event") == 0)
			|| (strcmp(actual_cmd.parameter, "mapsm") == 0))			
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("Events");
					printf(" on_origin_ticks=%ld", (uint32)events.timecode.on_origin_ticks);					
					printf(" angle_tilt=%2i", (uint16)events.inertial.tilt_angle);
					printf(" vibration=%2i", (uint16)events.inertial.vibration);	
					printf(" jump=%2i", (uint16)events.inertial.jump);						
					printf(" sm=%3i ", (uint16)events.mapping_sm_status);
					ShowStatusMappingSM(events.mapping_sm_status);
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW ESTIMATED EVENTS END			

			
			// SHOW CLU STATE MACHINE
			if (strcmp(actual_cmd.parameter, "clusm") == 0)
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("CLU SM: ");					
					printf(" number=%3i", (uint16)clu_sm.clunumber);
					printf(" line=%3i", (uint16)clu_sm.cluline);
					printf(" pauseticks=%3i", (uint16)clu_sm.pauseticks);					
					printf(" status=%3i ", (uint16)clu_sm.status);	
					ShowCLUSM(clu_sm.status);					
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW CLU STATE MACHINE END
			
			
			// SHOW BUTTONS
			if ((strcmp(actual_cmd.parameter, "buttons") == 0)	
			|| (strcmp(actual_cmd.parameter, "but") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("BUTTONS = %3i", (uint16)Status_Reg_BUTTON_Read());
					if (Status_Reg_BUTTON_Read() == PUSH_ON)
					{
						printf(" (ON)");
					}
					else
					if (Status_Reg_BUTTON_Read() == PUSH_CW)					
					{
						printf(" (CW)");
					}
					else
					if (Status_Reg_BUTTON_Read() == PUSH_CCW)					
					{
						printf(" (CCW)");
					}	
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW BUTTONS END


			// SHOW SYSDYN (SYSTEM DYNAMIC ACCELERATION SCALAR)
			if ((strcmp(actual_cmd.parameter, "sysdyn") == 0)	
			|| (strcmp(actual_cmd.parameter, "sdyn") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("System Dynamic Scalar=%1.8f  [xacc_ADC^2+yacc_ADC^2-(1g_ADC)^2]", (float)aacc.system_dynamic_scalar);				
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// END SHOW SYSDYN (SYSTEM DYNAMIC ACCELERATION SCALAR)

			
			// SHOW RELATIVE AND ABSOLUTE POSITION
			if ((strcmp(actual_cmd.parameter, "position") == 0)	
			|| (strcmp(actual_cmd.parameter, "pos") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("PAN: enc(t)=%+ld [step]", (int32)pan_axis.mc.slave_enc.position);
					printf(" abs_pos(t)=%+ld [step]", (int32)pan_absolute_sensor.position);
					printf(" (%+3.2f [rad])", (float)pan_absolute_sensor.angle_rad);
					printf("    TILT: enc(t)=%+ld [step]", (int32)tilt_axis.mc.slave_enc.position);
					printf(" abs_pos(t)=%+ld [step]", (int32)tilt_absolute_sensor.position);					
					printf(" (%+3.2f [rad])", (float)tilt_absolute_sensor.angle_rad);
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// END SHOW RELATIVE AND ABSOLUTE POSITION

			
			// SHOW ENCODERS FEEDBACK
			if ((strcmp(actual_cmd.parameter, "encfbk") == 0)	
			|| (strcmp(actual_cmd.parameter, "encf") == 0))
			{
				printf(STR_SHOWENCFA);			//DANGER PROMPT
				printf(STR_SHOWENCFB);			//
			
				if (ButtonYNChoice(ECHO_ON) == _YES)
				{
					isr_CTRL_Stop();				/* Stop Control ISR					*/

					PWM_MOTOR_PAN_WriteCompare(MOTOR_PWM_PERIOD_HALF);
					PWM_MOTOR_TILT_WriteCompare(MOTOR_PWM_PERIOD_HALF);
					
					while (AnyButtonPressed() == NO_PRESSED)
					{
						printf("PAN_FBK=%8ld", (int32)QuadDec_PAN_GetCounter());
						printf("  TILT_FBK=%8ld\r\n", (int32)QuadDec_TILT_GetCounter());
						//printf("  ROLL_FBK=%8ld \r\n", (int32)QuadDec_ROLL_GetCounter());							

						if (AnyButtonPressed() == PRESSED)
							goto exit_showencf;
					}
exit_showencf:					
					isr_CTRL_Start();				/* RESTART Control ISR				*/	
				}	
				
				goto exitpars;	
			}
			// SHOW ENCODERS FEEDBACK END			
			
			
			// SHOW MOTOR STATUS
			if ((strcmp(actual_cmd.parameter, "motorstatus") == 0)	
			|| (strcmp(actual_cmd.parameter, "mot") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
					printf("Motor Status=%2u ", (int16)Status_Reg_MOTORS_Read());
					if ((Status_Reg_MOTORS_Read() & SR_PAN_MOT_FL) == 0)
					{
						printf("PAN CURRENT PEAK!) ");	
					}
					else
					{
						printf("(PAN CURRENT OK!)  ");						
					}
					
					if ((Status_Reg_MOTORS_Read() & SR_TILT_MOT_FL) == 0)
					{
						printf("(TILT CURRENT PEAK!)");	
					}
					else
					{
						printf("(TILT CURRENT OK!)");						
					}					
					
					printf("\r\n");	
					CyDelay(50);
				}
				goto exitpars;	
			}
			// END SHOW MOTOR STATUS			

			
//			// SHOW HOME SENSORS
//			if ((strcmp(actual_cmd.parameter, "homesens") == 0)	
//			|| (strcmp(actual_cmd.parameter, "hsens") == 0))
//			{
//				while (AnyButtonPressed() == NO_PRESSED)
//				{
//					//2 --> home pan (HOME_PAN = 4)
//					//3 --> home tilt (HOME_TILT = 8)
//					printf("R=%0x2; ", (int16)Status_Reg_MOTORS_Read());
//					if ((Status_Reg_MOTORS_Read() & SR_HOME_PAN) == SR_HOME_PAN)
//					{
//						printf("HOME PAN=H; ");	
//					}
//					else
//					{
//						printf("HOME PAN=L; ");						
//					}
//
//					if ((Status_Reg_MOTORS_Read() & SR_HOME_TILT) == SR_HOME_TILT)
//					{
//						printf("HOME TILT=H");	
//					}
//					else
//					{
//						printf("HOME TILT=L");						
//					}
//					
//					printf("\r\n");	
//					CyDelay(50);
//				}
//				goto exitpars;	
//			}
//			// END SHOW MOTOR STATUS			
			
			
			// SHOW Q (SHOT) N
			if ((strcmp(actual_cmd.parameter, "q") == 0)	
			|| (strcmp(actual_cmd.parameter, "shot") == 0))
			{
				if (strcmp(actual_cmd.number1, "all") == 0)
				{
					int8 memory_num;
					for(memory_num=Q_MEMORY_NUMBER_MIN; memory_num <= Q_MEMORY_NUMBER_MAX; memory_num++)
					{
						if (q[memory_num].number == Q_NUMBER_UNUSED)
						{
							printf("QMemory%02d NOT ALLOCATED!\r\n",(uint16)memory_num);
						}
						else
						{
							printf("QMemory%02d allocated to Q%02d\r\n",(uint16)memory_num, (uint16)q[memory_num].number);
						}
					}
				}
				else if (((q_number = atoi(actual_cmd.number1)) >= Q_NUMBER_MIN)
				&& (q_number = atoi(actual_cmd.number1)) <= Q_NUMBER_MAX)
				{	
					if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)
					{
						//PAN 
						printf("Q%02d PAN  ABS position=%+8ld [step]  default_param=%+8ld [step]  adjust_param=%+8ld [step]\r\n",
							(uint16)q_number,
							(int32)q[q_table[q_number]].mc.position[PAN_AXIS],							
							(int32)q[q_table[q_number]].param.position_default[PAN_AXIS].fnum,
							(int32)q[q_table[q_number]].param.position_adjust[PAN_AXIS]);
						
						//TILT
						printf("Q%02d TILT ABS position=%+8ld [step]  default_param=%+8ld [step]  adjust_param=%+8ld [step]\r\n",
							(uint16)q_number,
							(int32)q[q_table[q_number]].mc.position[TILT_AXIS],            							
							(int32)q[q_table[q_number]].param.position_default[TILT_AXIS].fnum,
							(int32)q[q_table[q_number]].param.position_adjust[TILT_AXIS]);	
						
						//Memory number
						printf("\r\n(Q%02d is allocated in Q memory number %02d)\r\n", (uint16)q_number, (int16)q_table[q_number]);
					}
					else
					{
						printf("\r\nQ%02d is not allocated!\r\n", (uint16)q_number);
					}
				}
				else
				{
					printf(STR_ERROR5);				/* ERROR5: Number not allowed */
				}
				goto exitpars;	
			}
			// END SHOW Q (SHOT) N
			
			
//			// SHOW PATH N
//			if ((strcmp(actual_cmd.parameter, "path") == 0)	
//			|| (strcmp(actual_cmd.parameter, "pa") == 0))
//			{
//				if (((path_n = atoi(actual_cmd.number1)) >= 0)
//				&& (path_n = atoi(actual_cmd.number1)) <= 64)
//				{
//					for (idx=0; idx<path[path_n].param.Trapezoid_Number; idx++)
//					{
//						printf(" Trapezoid num =%3i\r\n", (int16)idx);	
//						printf(" Acc           =%+1.2f [%%]\r\n", (float)path[path_n].trapezoid[idx].param.acc_pc.fnum * 100);
//						printf(" Dec           =%+1.2f [%%]\r\n", (float)path[path_n].trapezoid[idx].param.dec_pc.fnum * 100);
//						printf(" Time          =%+1.2f [sec]\r\n", (float)path[path_n].trapezoid[idx].param.time_sec.fnum);
//						printf(" Steps         =%+1.2f [step]\r\n", (float)path[path_n].trapezoid[idx].param.steps);
//						printf(" Last_flg      =%3i [1=last]\r\n", (int16)path[path_n].trapezoid[idx].param.last_flg);
//						printf("----------------------------\r\n");
//						printf(" Ticks Initial =%+ld [ticks]\r\n", (int32)path[path_n].trapezoid[idx].mover.ticks_initial);
//						printf(" Acc EndPoint  =%+ld [ticks]\r\n", (int32)path[path_n].trapezoid[idx].mover.acc_end_tpoint);	
//						printf(" Dec StartPoint=%+ld [ticks]\r\n", (int32)path[path_n].trapezoid[idx].mover.dec_start_tpoint);
//						printf(" Dec EndPoint  =%+ld [ticks]\r\n", (int32)path[path_n].trapezoid[idx].mover.dec_end_tpoint);							
//						printf(" Ticks Final   =%+ld [ticks]\r\n", (int32)path[path_n].trapezoid[idx].mover.ticks_final);						
//						printf(" Acc Ticks     =%+1.2f [float ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.acc_ticks);
//						printf(" Vconst Ticks  =%+1.2f [float ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.vconst_ticks);
//						printf(" Dec Ticks     =%+1.2f [float ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.dec_ticks);						
//						printf(" V initial     =%+1.8f [step/ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.v_initial);						
//						printf(" Acc slope     =%+1.8f [step/ticks^2]\r\n", (float)path[path_n].trapezoid[idx].mover.acc_slope);
//						printf(" V constant    =%+1.8f [step/ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.v_const);						
//						printf(" Dec slope     =%+1.8f [step/ticks^2]\r\n", (float)path[path_n].trapezoid[idx].mover.dec_slope);
//						printf(" V final       =%+1.8f [step/ticks]\r\n", (float)path[path_n].trapezoid[idx].mover.v_final);						
//						printf("\r\n");						
//					}				
//				}
//				else
//				{
//					printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//				}
//				goto exitpars;	
//			}
//			// END SHOW PATH N				

			
//			// SHOW MOVER N
//			if ((strcmp(actual_cmd.parameter, "mover") == 0)	
//			|| (strcmp(actual_cmd.parameter, "mov") == 0))
//			{	
//				if (((path_n = atoi(actual_cmd.number1)) >= 0)
//				&& (path_n = atoi(actual_cmd.number1)) <= 64)
//				{				
//					int32 steps_loc;
//					int32 steps_integral_loc=0;
//					
//					MoverInit();	/* Initialize the Mover */
//					
//					while ((mover.ticks <= path[path_n].path_ticks_MAX) &&
//						  (AnyButtonPressed() == NO_PRESSED))
//					{
//						steps_loc = MoverGeneratedSteps(&path[path_n], mover.ticks);
//						steps_integral_loc = steps_integral_loc + steps_loc;
//						
//						printf("Ticks=%+ld [ticks]", (int32)mover.ticks);
//						printf("  Steps=%+ld [step]", (int32)steps_loc);	
//						printf("  Int(Steps)=%+ld [step]", (int32)steps_integral_loc);
//						printf("  Mover_status=%2i", (int16)mover.status);							
//						printf("\r\n");
//						
//						mover.ticks++;
//					}
//				}
//				else
//				{
//					printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//				}					
//				goto exitpars;	
//			}
//			// END SHOW MOVER N			

			
			// SHOW MOVERS
			if (strcmp(actual_cmd.parameter, "movers") == 0)
			{	
				if (strlen(actual_cmd.number1) == 0)
				{			
					while (AnyButtonPressed() == NO_PRESSED)
					{
						printf("Movers Ticks=%+ld, %+ld [ticks]", (int32)mover_pan.ticks, (int32)mover_tilt.ticks);
//						printf("  Steps=%+ld [step]", (int32)steps_loc);	
//						printf("  Int(Steps)=%+ld [step]", (int32)steps_integral_loc);
						printf("  status=%2i, %2i", (int16)mover_pan.status, (int16)mover_tilt.status);							
						printf("\r\n");
						CyDelay(50);						
					}
				}
				else
				{
					printf(STR_ERROR5);				/* ERROR5: Number not allowed */
				}					
				goto exitpars;	
			}
			// END SHOW MOVERS		
			
			// SHOW CLU N
			if (strcmp(actual_cmd.parameter, "clu") == 0)
			{	
				if (((clu_number = atoi(actual_cmd.number1)) >= 0)
				&& (clu_number = atoi(actual_cmd.number1)) < MAX_CLU_NUMBER)
				{				
					PrintClu(clu_number);
				}
				else
				{
					printf(STR_ERROR5);				/* ERROR5: Number not allowed */
				}					
				goto exitpars;	
			}
			// END SHOW CLU N			
			
			
			// SHOW PAN LIMITS
			if ((strcmp(actual_cmd.parameter, "panlimits") == 0)	
			|| (strcmp(actual_cmd.parameter, "plim") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
			        printf("PAN LIMIT=%2u ", (uint16)pan_axis.lc.status);					
					ShowLimits(&pan_axis);
					printf("\r\n");
					
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW PAN LIMITS END			

			
			// SHOW TILT LIMITS
			if ((strcmp(actual_cmd.parameter, "tiltlimits") == 0)	
			|| (strcmp(actual_cmd.parameter, "tlim") == 0))
			{
				while (AnyButtonPressed() == NO_PRESSED)
				{
			        printf("TILT LIMIT=%2u ", (uint16)tilt_axis.lc.status);
					ShowLimits(&tilt_axis);		
					printf("\r\n");
					
					CyDelay(50);
				}
				goto exitpars;	
			}
			// SHOW TILT LIMITS END					
			
			
			// SHOW ABS RATIO PAN
			if ((strcmp(actual_cmd.parameter, "ratioabsp") == 0)	
			|| (strcmp(actual_cmd.parameter, "ratiop") == 0))
			{
				printf(STR_SHOWENCFA);			//DANGER PROMPT
				printf(STR_SHOWENCFC);			//
			
				if (ButtonYNChoice(ECHO_ON) == _YES)
				{
					isr_CTRL_Stop();					/* Stop Control ISR			*/	
					motor_init(&pan_axis);				/* Initialize Pan Axis  	*/
					motor_init(&tilt_axis);				/* Initialize Tilt Axis 	*/
					
					pan_absolute_sensor.ratio_tmp = 0;	//clear temporary ratio value
					get_key = 0;						//clear internal loop getted char
					
					while (get_key == 0)						
					{						
						printf("PAN: ABS_SENSOR=%5i[lsb]", (int16)AdcValue[HOME_PAN_ABSV]);
						printf(" ENC=%9li[step]", (int32)QuadDec_PAN_GetCounter());	
						printf(" RATIO=%1.4f[step/lsb]",(float)pan_absolute_sensor.ratio_tmp);
						printf("\r\n");
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();						
					
						/* internal one-key reset & sample */
						get_key = UART_USB_GetChar();	/* get the char */
						if 	((get_key == 'r') || (get_key == 'R'))
						{	
							pan_absolute_sensor.slave_encoder_step_p0 = (int32)QuadDec_PAN_GetCounter();/* Encoder Point Zero Sampling        [step] */
							pan_absolute_sensor.raw_adc_p0            = (int32)AdcValue[HOME_PAN_ABSV];	/* ABS Sensor ADC Point Zero Sampling [lsb]  */
						
							printf("\r\n*!point 0 sampling\r\n\r\n");	
							get_key = 0; //stay in while loop
						}
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();							
						
						/* internal one-key pot ratio calc */
						if 	((get_key == 's') || (get_key == 'S'))
						{							
							pan_absolute_sensor.sample_d1 = (float)((int32)QuadDec_PAN_GetCounter() - pan_absolute_sensor.slave_encoder_step_p0);//[float step]			
							pan_absolute_sensor.sample_d2 = (float)((int32)AdcValue[HOME_PAN_ABSV]  - pan_absolute_sensor.raw_adc_p0);			 //[float lsb]
							pan_absolute_sensor.ratio_tmp = fabs(pan_absolute_sensor.sample_d1 / pan_absolute_sensor.sample_d2);	 			 //[float step/lsb]
						
							printf("\r\n*!enc over abs ratio sampled\r\n\r\n");	
							get_key = 0; //stay in while loop
						}
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();	
						
						/* internal one-key pot ratio eeprom save */
						if 	((get_key == 'e') || (get_key == 'E'))
						{	
							/* update global parameters */
							pan_absolute_sensor.param.step_over_abs_ratio.fnum = pan_absolute_sensor.ratio_tmp;
							
							goto PsavetoEE;
						}						
					}
				}				
				
				isr_CTRL_Start();				/* RESTART Control ISR				*/					
		
				goto exitpars;	
PsavetoEE:
				isr_CTRL_Start();				/* RESTART Control ISR				*/	
				
				/* Update EEPROM */
				dummy = WriteAllEEparams();
										
				printf("\r\n*!Absolute Sensor ratio PAN eeprom saved\r\n\r\n");	
				goto exitpars;				
			}		
			// END SHOW ABS RATIO PAN				
			
			
			// SHOW ABS RATIO TILT
			if ((strcmp(actual_cmd.parameter, "ratioabst") == 0)	
			|| (strcmp(actual_cmd.parameter, "ratiot") == 0))
			{
				printf(STR_SHOWENCFA);			//DANGER PROMPT
				printf(STR_SHOWENCFC);			//
			
				if (ButtonYNChoice(ECHO_ON) == _YES)
				{
					isr_CTRL_Stop();					/* Stop Control ISR			*/	
					motor_init(&pan_axis);				/* Initialize Pan Axis  	*/
					motor_init(&tilt_axis);				/* Initialize Tilt Axis 	*/
					
					tilt_absolute_sensor.ratio_tmp = 0;	//clear temporary ratio value
					get_key = 0;						//clear internal loop getted char
					
					while (get_key == 0)						
					{						
						printf("TILT: ABS_SENSOR=%5i[lsb]", (int16)AdcValue[HOME_TILT_ABSV]);
						printf(" ENC=%9li[step]", (int32)QuadDec_TILT_GetCounter());	
						printf(" RATIO=%1.4f[step/lsb]",(float)tilt_absolute_sensor.ratio_tmp);
						printf("\r\n");
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();						
					
						/* internal one-key reset & sample */
						get_key = UART_USB_GetChar();	/* get the char */
						if 	((get_key == 'r') || (get_key == 'R'))
						{	
							tilt_absolute_sensor.slave_encoder_step_p0 = (int32)QuadDec_TILT_GetCounter();	/* Encoder Point Zero Sampling        [step] */
							tilt_absolute_sensor.raw_adc_p0            = (int32)AdcValue[HOME_TILT_ABSV];	/* ABS Sensor ADC Point Zero Sampling [lsb]  */
						
							printf("\r\n*!point 0 sampling\r\n\r\n");	
							get_key = 0; //stay in while loop
						}
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();							
						
						/* internal one-key pot ratio calc */
						if 	((get_key == 's') || (get_key == 'S'))
						{							
							tilt_absolute_sensor.sample_d1 = (float)((int32)QuadDec_TILT_GetCounter() - tilt_absolute_sensor.slave_encoder_step_p0);//[float step]			
							tilt_absolute_sensor.sample_d2 = (float)((int32)AdcValue[HOME_TILT_ABSV]  - tilt_absolute_sensor.raw_adc_p0);			//[float lsb]
							tilt_absolute_sensor.ratio_tmp = fabs(tilt_absolute_sensor.sample_d1 / tilt_absolute_sensor.sample_d2);	 				//[float step/lsb]
						
							printf("\r\n*!enc over abs ratio sampled\r\n\r\n");	
							get_key = 0; //stay in while loop
						}
						
//						/******************************************************/
//						/*** WDT CLEAR	(32–48msec max)						***/
//						/******************************************************/
//						CyWdtClear();	
						
						/* internal one-key pot ratio eeprom save */
						if 	((get_key == 'e') || (get_key == 'E'))
						{	
							/* update global parameters */
							tilt_absolute_sensor.param.step_over_abs_ratio.fnum = tilt_absolute_sensor.ratio_tmp;
							
							goto TsavetoEE;
						}						
					}
				}				
				
				isr_CTRL_Start();				/* RESTART Control ISR				*/					
		
				goto exitpars;	
TsavetoEE:
				isr_CTRL_Start();				/* RESTART Control ISR				*/	
				
				/* Update EEPROM */
				dummy = WriteAllEEparams();
										
				printf("\r\n*!Absolute Sensor ratio TILT eeprom saved\r\n\r\n");	
				goto exitpars;				
			}		
			// END SHOW ABS RATIO TILT	
			
			
			// SHOW FAULTS
			if ((strcmp(actual_cmd.parameter, "faults") == 0)	
			|| (strcmp(actual_cmd.parameter, "fault") == 0))	
			{
				if (gobeeFaults.general == GEN_NOFAULTS)
				{
					printf(STR_FULT0);   /* NONE: ALL OK! */
				}
				else
				{
//					if ((sysFaults.general & GEN_FUSE_FAULT) == GEN_FUSE_FAULT)
//					{
//						printf(STR_FULT1);   /* @FAULT: FUSE OPEN! */
//					}
//					else
//					{
//						if ((sysFaults.general & GEN_LOWVCC_FAULT) == GEN_LOWVCC_FAULT)
//						{
//							printf(STR_FULT2);   /* @FAULT: LOW VCC! (VCC<11V) */
//						}
//					}
					
					if ((gobeeFaults.general & GEN_PAN_FAULT) == GEN_PAN_FAULT)
					{
						printf(STR_FULTP);   		/* @FAULT#01: GENERAL PAN FAULT */
						if ((gobeeFaults.general & GEN_FBKENC_FAULT) == GEN_FBKENC_FAULT)
						{
							printf(STR_FULTI);	 	/* @FAULT#10: FEEDBACK ENCODER INVALID TRANSITIONS!*/
						}							
					}		
					
					if ((gobeeFaults.general & GEN_TILT_FAULT) == GEN_TILT_FAULT)
					{
						printf(STR_FULTT);   		/* @FAULT#02: GENERAL TILT FAULT */
						if ((gobeeFaults.general & GEN_FBKENC_FAULT) == GEN_FBKENC_FAULT)
						{
							printf(STR_FULTI);	 	/* @FAULT#10: FEEDBACK ENCODER INVALID TRANSITIONS!*/
						}							
					}					
				}
				goto exitpars;
			}
			
			
			// SHOW PARAMS
			if (((strcmp(actual_cmd.parameter, "params") == 0))
			|| (strcmp(actual_cmd.parameter, "p") == 0))
			{
				printf("GoBee DIRECTOR\r\n");
				printf("==============\r\n");
				printf("Gobee Mode                   =%2u: ", gobee_param.mode);
				ShowParamsMode();				
				printf("Gobee Selected Director      =%2u: ", gobee_param.director);
				ShowParamsDirector();			
				printf("\r\n");		
				printf("\r\n");					
				
				printf("GoBee PARAMETER LIST\r\n");
				printf("====================\r\n");
					
				//axis main params
				printf("Pan  Axis Resolution         = ");
				printf("%8.1f [step/2PI]",(float)(pan_axis.param.resolution.fnum));
				printf("\r\n");
				
				printf("Tilt Axis Resolution         = ");
				printf("%8.1f [step/2PI]",(float)(tilt_axis.param.resolution.fnum));
				printf("\r\n");	
				printf("\r\n");
				
				
				printf("Motor Control\r\n");
				printf("=============\r\n");		
				
				//pan motor main params
				printf("Pan  Motor Polarity          = ");
				printf("%1u (0=true, 1=invert)",(int16)(pan_axis.param.polarity));
				printf("\r\n");

				printf("Pan  Motor Kp                = ");
				printf("%8f",(float)(pan_axis.param.Kpf.fnum));
				printf("\r\n");

				printf("Pan  Motor Kd                = ");
				printf("%8f",(float)(pan_axis.param.Kdf.fnum));
				printf("\r\n");

				printf("Pan  Motor Ki                = ");
				ShowParamsKiPan();
				printf("\r\n");
				
				printf("Pan  Motor Ksi               = ");
				printf("%8f (max AZI=%8f)",(float)(pan_axis.param.Ksif.fnum),
										   (float)(pan_axis.param.Ksif.fnum * pan_axis.param.Kif.fnum));
				printf("\r\n");	
				
				printf("Pan Limit Control            = ");
				printf("%1u (0=disabled, 1=enabled)",(int16)(pan_axis.param.limit_control));
				printf("\r\n");				
				
	
				//tilt motor main params	
				printf("Tilt Motor Polarity          = ");
				printf("%1u (0=true, 1=invert)",(int16)(tilt_axis.param.polarity));
				printf("\r\n");

				printf("Tilt Motor Kp                = ");
				printf("%8f",(float)(tilt_axis.param.Kpf.fnum));
				printf("\r\n");

				printf("Tilt Motor Kd                = ");
				printf("%8f",(float)(tilt_axis.param.Kdf.fnum));
				printf("\r\n");

				printf("Tilt Motor Ki                = ");
				ShowParamsKiTilt();
				printf("\r\n");
				
				printf("Tilt Motor Ksi               = ");
				printf("%8f (max AZI=%8f)",(float)(tilt_axis.param.Ksif.fnum),
										   (float)(tilt_axis.param.Ksif.fnum * tilt_axis.param.Kif.fnum));
				printf("\r\n");		
				
				printf("Tilt Limit Control           = ");
				printf("%1u (0=disabled, 1=enabled)",(int16)(tilt_axis.param.limit_control));
				printf("\r\n");						
				printf("\r\n");					
				
				printf("Absolute Sensors\r\n");
				printf("================\r\n");			

				//pan absolute sensor main params
				printf("Pan  Absolute sensor HOME    = ");
				printf("%6i [ADC raw]    (invertion=%1d)",(int16)(pan_absolute_sensor.param.raw_home), (int16)pan_absolute_sensor.param.raw_invertion);
				printf("\r\n");
				
				printf("Pan  Absolute sensor LimitMAX= ");
				printf("%6i [ADC raw]",(int16)(pan_absolute_sensor.param.raw_limit_max));
				printf("\r\n");
				
				printf("Pan  Absolute sensor Limitmin= ");
				printf("%6i [ADC raw]",(int16)(pan_absolute_sensor.param.raw_limit_min));
				printf("\r\n");				

				printf("Pan  Absolute sensor Hyster. = ");
				printf("%6i [ADC raw]",(int16)(pan_absolute_sensor.param.raw_limit_hysteresis));
				printf("\r\n");	
				
				printf("Pan  Absolute sensor Ratio   = ");
				printf("%3.3f [step/lsb]",(float)(pan_absolute_sensor.param.step_over_abs_ratio.fnum));
				printf("\r\n");					
				

				//tilt absolute sensor main params
				printf("Tilt Absolute sensor HOME    = ");
				printf("%6i [ADC raw]    (invertion=%1d)",(int16)(tilt_absolute_sensor.param.raw_home), (int16)tilt_absolute_sensor.param.raw_invertion);
				printf("\r\n");	
				
				printf("Tilt Absolute sensor LimitMAX= ");
				printf("%6i [ADC raw]",(int16)(tilt_absolute_sensor.param.raw_limit_max));
				printf("\r\n");
				
				printf("Tilt Absolute sensor Limitmin= ");
				printf("%6i [ADC raw]",(int16)(tilt_absolute_sensor.param.raw_limit_min));
				printf("\r\n");				

				printf("Tilt Absolute sensor Hyster. = ");
				printf("%6i [ADC raw]",(int16)(tilt_absolute_sensor.param.raw_limit_hysteresis));
				printf("\r\n");
				
				printf("Tilt Absolute sensor Ratio   = ");
				printf("%3.3f [step/lsb]",(float)(tilt_absolute_sensor.param.step_over_abs_ratio.fnum));	
				printf("\r\n");					
				printf("\r\n");	
				
				
				printf("Motor Tuning\r\n");
				printf("============\r\n");					
				printf("Pan  Motor Kopf              = ");
				printf("%8f",(float)(pan_axis.param.Kopf.fnum));
				printf("   AstimEN=%1u ",(int16)(pan_axis.vparam.astim_enable));
				ShowParamsAstim(&pan_axis);
				
				printf("Pan  Anaout GAIN             = ");
				ShowParamsGainAnaout(&pan_axis);			
				
				printf("Pan  AnaOut Signal (color)   = ");
				ShowParamsColor(&pan_axis);						
				printf("\r\n");				

				printf("Tilt Motor Kopf              = ");
				printf("%8f",(float)(tilt_axis.param.Kopf.fnum));
				printf("   AstimEN=%1u ",(int16)(tilt_axis.vparam.astim_enable));
				ShowParamsAstim(&pan_axis);
				
				printf("Tilt Anaout GAIN             = ");
				ShowParamsGainAnaout(&tilt_axis);			
				
				printf("Tilt AnaOut Signal (color)   = ");
				ShowParamsColor(&tilt_axis);						
				printf("\r\n");				
				
				printf("Anaout Selected Axis         = ");
				ShowParamsAnaoutSelectedAxis(Selected_ANAOUT);	
				printf("\r\n");
				printf("\r\n");				

				printf("Accelerometer (100Hz)\r\n");
				printf("=====================\r\n");					
				printf("beta  (accelerometer LPF)    = ");
				printf("%8f (tau=%1.4f [msec])",(float)(gobee_param.beta.fnum), (float)LPFtau(gobee_param.beta.fnum, H_DeltaT_const));
				printf(" (fc=%1.4f [Hz])\r\n", (float)LPFfreq(gobee_param.beta.fnum, H_DeltaT_const));				

				printf("Analog Accel. X ADC Offset   = ");
				printf("%4d [lsb]",(int16)(gobee_param.x_acc_ADC_offset));
				printf("\r\n");	
				
				printf("Analog Accel. Y ADC Offset   = ");
				printf("%4d [lsb]",(int16)(gobee_param.y_acc_ADC_offset));
				printf("\r\n");
				
				printf("Analog Accel. Z ADC Offset   = ");
				printf("%4d [lsb]",(int16)(gobee_param.z_acc_ADC_offset));
				printf("\r\n");				
				printf("\r\n");	
				
				printf("Bike Frame IMU (1.5kHz)\r\n");
				printf("=======================\r\n");					
				printf("gamma  (IMU LPF)             = ");
				printf("%8f (tau=%1.4f [msec])",(float)(IMU_sensor.param.gamma.fnum), (float)LPFtau(IMU_sensor.param.gamma.fnum, DeltaT_const));
				printf(" (fc=%1.4f [Hz])\r\n", (float)LPFfreq(IMU_sensor.param.gamma.fnum, DeltaT_const));
				
				printf("IMU Yaw angle invertion      = ");
				printf("%1u (0=true, 1=invert)",(int16)(IMU_sensor.param.yaw_invertion));
				printf("\r\n");
				
				printf("IMU Pitch angle invertion    = ");
				printf("%1u (0=true, 1=invert)",(int16)(IMU_sensor.param.pitch_invertion));
				printf("\r\n");
				
				printf("IMU Roll angle invertion     = ");
				printf("%1u (0=true, 1=invert)",(int16)(IMU_sensor.param.roll_invertion));
				printf("\r\n");
				
				printf("IMU Pith and Roll exchange   = ");
				printf("%1u (0=true, 1=exchanged)",(int16)(IMU_sensor.param.pitch_roll_exchange));
				printf("\r\n");				
				printf("\r\n");					
				
				printf("Events Parameters\r\n");
				printf("=================\r\n");				
				
				printf("Jump G Threshold             = ");
				printf("%8f [g]\r\n",(float)(gobee_param.jump_g_threshold.fnum));				

				printf("Acceleration G Threshold     = ");
				printf("%8f [g]\r\n",(float)(gobee_param.acc_g_threshold.fnum));				
				printf("\r\n");
				
				goto exitpars;
			}
		goto exitpars;	
		}
		
		
//		/* CMD MOVEPATH */
//		if ((strcmp(actual_cmd.action, "movepath") == 0) ||
//		   (strcmp(actual_cmd.action, "movep") == 0))
//		{	
//			if (((path_n = atoi(actual_cmd.parameter)) >= 0)
//			&& (path_n = atoi(actual_cmd.parameter)) <= PATH_N_MAX-1)
//			{
//				if (machine_state == GOBEE_ENERGIZED)
//				{
//					printf("Path %2i Mover START!\r\n", (int16)path_n);				
//					MoverStart(path_n);	/* Initialize & Start the Mover over path n		*/
//					
//					while (AnyButtonPressed() == NO_PRESSED)
//					{
//						//print . every 1 sec
//						if (mover.ticks % MOVER_FREQ)
//						printf(".");
//						
//						if (mover.status == MOVER_ENDED)
//						{
//							printf("\r\nPath %2i Mover END!\r\n", (int16)path_n);						
//							goto exitpars;
//						}
//					}
//				}
//				else
//				{
//					printf("Mover Not Started: energize the Gobee before!\r\n");	
//				}
//			}
//			else
//			{
//				printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//			}
//			goto exitpars;	
//		}	

		
		/* CMD CLUEXEC */
		if (strcmp(actual_cmd.action, "cluexec") == 0)
		{	
			if (((clu_number = atoi(actual_cmd.parameter)) >= 0)
			&& (clu_number = atoi(actual_cmd.parameter)) <= MAX_CLU_NUMBER)
			{
				if (machine_state == GOBEE_ENERGIZED)
				{
					if (isCluEmpty(clu_number) == CLU_IS_NOT_EMPTY)
					{
						printf("CLU %2i START!\r\n", (int16)clu_number);
						clu_sm_start((uint8)clu_number);
						
						while (AnyButtonPressed() == NO_PRESSED)
						{					
							if (clu_sm.status == CLUSM_END)
							{
								printf("\r\nCLU %2i END!\r\n", (int16)clu_number);						
								goto exitpars;
							}
						}
					}
					else
					{
						printf("CLU not started: selected CLU is empty!\r\n");	
					}
				}
				else
				{
					printf("CLU not started: energize the Gobee before!\r\n");	
				}
			}
			else
			{
				printf(STR_ERROR5);				/* ERROR5: Number not allowed */
			}
			goto exitpars;	
		}
		/* END CMD CLUEXEC*/
		
		
		/* CMD CLUSEQUENCE */
		if (strcmp(actual_cmd.action, "cluseq") == 0)
		{	
			if (((clu_pause = atoi(actual_cmd.parameter)) >= 0)
			&& (clu_pause = atoi(actual_cmd.parameter)) <= 30000)
			{
				if (machine_state == GOBEE_ENERGIZED)
				{				
					InitCluSequence();
					
					uint8 clu_step = 0;
					while (clu_sequence[clu_step] != 0xFF)
					{
						printf("CLU %2i START!\r\n", (int16)clu_sequence[clu_step]);
						clu_sm_start((uint8)clu_sequence[clu_step]);

						while (clu_sm.status != CLUSM_END)
						{
							if (AnyButtonPressed() == PRESSED)
							{
								printf("\r\nUser Abort!\r\n");
								
								goto exitpars;	
							}	
						}
						printf("\r\nCLU %2i END!\r\n", (int16)clu_sequence[clu_step]);
						CyDelay(clu_pause);
						clu_step++;
					}
					printf("\r\nCLU SEQUENCE END!\r\n");
					goto exitpars;
				}
				else
				{
					printf("CLUSEQ not started: energize the Gobee before!\r\n");	
				}				
			}
			else
			{
				printf(STR_ERROR5);				/* ERROR5: Number not allowed */
			}
			goto exitpars;	
		}
		/* END CMD CLUSEQUENCE*/		
		
		
		/* CMD GOTOHOME */
		if ((strcmp(actual_cmd.action, "gotohome") == 0) ||
		   (strcmp(actual_cmd.action, "gotoh") == 0))
		{	
			if (machine_state == GOBEE_ENERGIZED)
			{
				printf("Goto Home Mover START!\r\n");	
				InitPanGotoHomePath();						/* initialize the Pan Goto Home Path					*/
				InitTiltGotoHomePath();						/* initialize the Tilt Goto Home Path					*/			
				CalculatePanGotoHomePath();					/* Calculate the  Pan Goto Home Path 					*/
				CalculateTiltGotoHomePath();				/* Calculate the  Tilt Goto Home Path 					*/			
				MoverStart(&mover_pan, PATH_PGOTOHOME);		/* Initialize & Start the Mover over Pan path to Home	*/
				MoverStart(&mover_tilt, PATH_TGOTOHOME);	/* Initialize & Start the Mover over Tilt path to Home	*/		
				
				while (AnyButtonPressed() == NO_PRESSED)
				{
					//print . every 1 sec
					if ((mover_pan.ticks % MOVER_FREQ) == 0)
					printf(".");
					
					if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
					{
						printf("\r\nGoto Home Mover END!\r\n");						
						goto exitpars;
					}
				}
			}
			else
			{
				printf("Goto Home Mover Not Started: energize the Gobee before!\r\n");	
			}
			goto exitpars;	
		}
		/* CMD GOTOHOME END */
		
		
		/* CMD GOTOQ */
		if ((strcmp(actual_cmd.action, "gotoq") == 0) ||
		    (strcmp(actual_cmd.action, "g") == 0))
		
		{	
			if (((q_number = atoi(actual_cmd.parameter)) >= Q_NUMBER_MIN)
			&& (q_number = atoi(actual_cmd.parameter)) <= Q_NUMBER_MAX)
			{	
				if (((time_loc = atof(actual_cmd.number1)) >= 0)
				&& (time_loc = atof(actual_cmd.number1)) <= 30)		//[sec]
				{
					if (machine_state == GOBEE_ENERGIZED)
					{
						if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)		//is Q allocated on any memory?
						{
							if (time_loc == 0)
							{
								time_loc = 2;	//default 2 sec	
							}
							
							printf("Goto Q Mover START!\r\n");	
							InitPanGotoQPath(q_number, time_loc);	/* initialize the Pan Goto Q Path					*/
							InitTiltGotoQPath(q_number, time_loc);	/* initialize the Tilt Goto Q Path					*/			
							CalculatePanGotoQPath();				/* Calculate the  Pan Goto Q Path 					*/
							CalculateTiltGotoQPath();				/* Calculate the  Tilt Goto Q Path 					*/			
							MoverStart(&mover_pan, PATH_PGOTOQ);	/* Initialize & Start the Mover over Pan path to Q	*/
							MoverStart(&mover_tilt, PATH_TGOTOQ);	/* Initialize & Start the Mover over Tilt path to Q	*/		
							
							while (AnyButtonPressed() == NO_PRESSED)
							{
								//print . every 1 sec
								if ((mover_pan.ticks % MOVER_FREQ) == 0)
								printf(".");
								
								if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
								{
									printf("\r\nGoto Q Mover END!\r\n");						
									goto exitpars;
								}
							}
						}
						else
						{
							printf("Goto Q Mover Not Started: QMemory %02d NOT ALLOCATED!\r\n",(uint16)q_number);
						}						
					}
					else
					{
						printf("Goto Q Mover Not Started: energize the Gobee before!\r\n");	
					}
				}
			}
			else
			{
				printf("Goto Q Mover Not Started: Q maximum is 99!\r\n");	
			}
			goto exitpars;	
		}
		/* CMD GOTOQ END */

		
//		/* CMD CIAK */
//		if (strcmp(actual_cmd.action, "ciak") == 0)
//		{	
//			if (machine_state == GOBEE_ENERGIZED)
//			{
//				int8 ciak_num = 2;	/* ciak path iterations */
//				
//				printf("CIAK Mover START!\r\n");	
//				MoverStart(5);				/* Initialize & Start the Mover over path 5	*/
//				
//				while (AnyButtonPressed() == NO_PRESSED)
//				{
//					//print . every 1 sec
//					if (mover.ticks % MOVER_FREQ)
//					printf(".");
//					
//					if (mover.status == MOVER_ENDED)
//					{
//						ciak_num--;
//						if (ciak_num>0)
//						{
//							MoverStart(5);				/* Redo CIAK */
//						}
//						else
//						{
//						printf("\r\nCIAK Mover END!\r\n");						
//						goto exitpars;
//						}
//					}
//				}
//			}
//			else
//			{
//				printf("CIAK Mover Not Started: energize the Gobee before!\r\n");	
//			}
//			goto exitpars;	
//		}					
		
		
		/* CMD SET*/
		if (strcmp(actual_cmd.action, "set") == 0)
		{
			if (strlen(actual_cmd.parameter) == 0)
			{
				printf(STR_ERROR2);		/* ERROR2: more parameters needed! */
			}
			else
			{
				// SET DIRECTOR
				if ((strcmp(actual_cmd.parameter, "director") == 0) ||
					(strcmp(actual_cmd.parameter, "dir") == 0))
				{	
					if (((director = atoi(actual_cmd.number1)) >= STANLEY)
					&& (director = atoi(actual_cmd.number1)) <= JJ)
					{
						gobee_param.director = director;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SEDR, (uint16)director);   /* REM: director setted to...*/
						ShowParamsDirector();
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET DIRECTOR
				
				
				// SET MACHINE MODE
				if (strcmp(actual_cmd.parameter, "mode") == 0)
				{	
					if (((mode_loc = atoi(actual_cmd.number1)) >= REMOTECONTROL_MODE)
					&& (mode_loc = atoi(actual_cmd.number1)) <= DIRECTOR_MODE)
					{
						gobee_param.mode = mode_loc;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SMOD, (uint16)mode_loc);   /* REM: machine mode setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET MACHINE MODE
				
				
				// SET PAN MOTOR POLARITY
				if ((strcmp(actual_cmd.parameter, "polarityp") == 0) ||
					(strcmp(actual_cmd.parameter, "polp") == 0))
				{	
					if (((polarity = atoi(actual_cmd.number1)) >= 0)
					&& (polarity = atoi(actual_cmd.number1)) <= 1)
					{
						pan_axis.param.polarity = polarity;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SETP, (uint16)polarity);   /* REM: pan axis polarity setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END PAN MOTOR POLARITY

				
				// SET TILT MOTOR POLARITY
				if ((strcmp(actual_cmd.parameter, "polarityt") == 0) ||
					(strcmp(actual_cmd.parameter, "polt") == 0))
				{	
					if (((polarity = atoi(actual_cmd.number1)) >= 0)
					&& (polarity = atoi(actual_cmd.number1)) <= 1)
					{
						tilt_axis.param.polarity = polarity;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SETPT, (uint16)polarity);   /* REM: tilt axis polarity setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END TILT MOTOR POLARITY
				

				// SET PAN MOTOR LIMIT CONTROL
				if ((strcmp(actual_cmd.parameter, "limitcp") == 0) ||
					(strcmp(actual_cmd.parameter, "lcp") == 0))
				{	
					if (((limit_control = atoi(actual_cmd.number1)) >= LIMIT_CONTROL_DISABLED)
					&& (limit_control = atoi(actual_cmd.number1)) <= LIMIT_CONTROL_ENABLED)
					{
						pan_axis.param.limit_control = limit_control;
						
						/* Writes parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STLP, (uint16)limit_control);   /* REM: pan axis limit control setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END PAN MOTOR LIMIT CONTROL		
				
				
				// SET ABSOLUTE SENSOR PAN INVERTION
				if ((strcmp(actual_cmd.parameter, "invabsp") == 0) ||
					(strcmp(actual_cmd.parameter, "invp") == 0))
				{	
					if (((raw_invertion = atoi(actual_cmd.number1)) >= ABS_SENSOR_TRUE)
					&& (raw_invertion = atoi(actual_cmd.number1)) <= ABS_SENSOR_INVERTED)
					{
						pan_absolute_sensor.param.raw_invertion = raw_invertion;
						
						/* Writes parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SIVP, (uint16)raw_invertion);   /* REM: pan axis absoluter sensor invertion setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END ABSOLUTE SENSOR PAN INVERTION				
				
				
				//SET ABSOLUTE SENSOR PAN ZERO (HOME)
				if ((strcmp(actual_cmd.parameter, "zeroabsp") == 0) ||
					(strcmp(actual_cmd.parameter, "zp") == 0))
				{	
					printf("* Warning! Put PAN Axis to zero (HOME) position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						pan_absolute_sensor.param.raw_home = 0; 		/* reset absolute pan sensor zero raw 			*/

						//start Pan Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&pan_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Pan Absolute Sensor Statistics
						printf("* Statistics stop!\r\n");						
						statistics_stop(&pan_absolute_sensor_stat);
								
	
						/* Update Global Parameter			*/
						pan_absolute_sensor.param.raw_home = (int16)pan_absolute_sensor_stat.mean;
						printf(STR_REM_PASZ, (int16)pan_absolute_sensor.param.raw_home); 	/* REM: Absolute Sensor Zero... setted to...*/								
					}
					else
					{
						printf("\r\n* Pan Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR PAN ZERO (HOME)
			
				
				//SET ABSOLUTE SENSOR PAN LIMIT MIN
				if ((strcmp(actual_cmd.parameter, "limitminp") == 0) ||
					(strcmp(actual_cmd.parameter, "lminp") == 0))
				{	
					printf("* Warning! Put PAN Axis to limit MIN position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						pan_absolute_sensor.param.raw_limit_min = 0; 		/* reset absolute pan sensor limit min raw 	*/

						//start Pan Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&pan_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Pan Absolute Sensor Statistics
						statistics_stop(&pan_absolute_sensor_stat);
						printf("* Statistics stop!\r\n");								
	
						/* Update Global Parameter			*/
						pan_absolute_sensor.param.raw_limit_min = (int16)pan_absolute_sensor_stat.mean;																
						printf(STR_REM_PMIN, (int16)pan_absolute_sensor.param.raw_limit_min); 	/* REM: Absolute Sensor Limit... setted to...*/								
					}
					else
					{
						printf("\r\n* Pan Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR PAN LIMIT MIN
				
				
				//SET ABSOLUTE SENSOR PAN LIMIT MAX
				if ((strcmp(actual_cmd.parameter, "limitmaxp") == 0) ||
					(strcmp(actual_cmd.parameter, "lmaxp") == 0))
				{	
					printf("* Warning! Put PAN Axis to limit MAX position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						pan_absolute_sensor.param.raw_limit_max = 0; 		/* reset absolute pan sensor limit max raw 	*/

						//start Pan Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&pan_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Pan Absolute Sensor Statistics
						statistics_stop(&pan_absolute_sensor_stat);
						printf("* Statistics stop!\r\n");								
	
						/* Update Global Parameter			*/
						pan_absolute_sensor.param.raw_limit_max = (int16)pan_absolute_sensor_stat.mean;
						printf(STR_REM_PMAX, (int16)pan_absolute_sensor.param.raw_limit_max); 	/* REM: Absolute Sensor Limit... setted to...*/								
					}
					else
					{
						printf("\r\n* Pan Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR PAN LIMIT MAX)
				
				
				// SET ABSOLUTE SENSOR PAN LIMIT HYSTERESIS
				if ((strcmp(actual_cmd.parameter, "limithystp") == 0) ||
					(strcmp(actual_cmd.parameter, "lhystp") == 0))
				{	
					if (((raw_limit_hyst = atoi(actual_cmd.number1)) >= -100)
					&& (raw_limit_hyst = atoi(actual_cmd.number1)) <= 100)
					{
						pan_absolute_sensor.param.raw_limit_hysteresis = raw_limit_hyst;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PLHY, (uint16)raw_limit_hyst);   /* REM: pan axis absolute sensor limit hysteresis setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END ABSOLUTE SENSOR PAN LIMIT HYSTERESIS		
				
				
				// SET PAN ENCODER OVER ABSOLUTE SENSOR RATIO
				if ((strcmp(actual_cmd.parameter, "ratioabsp") == 0) ||
					(strcmp(actual_cmd.parameter, "ratiop") == 0))
				{	
					if (((step_abs_ratio = atof(actual_cmd.number1)) >= -10000)
					&& (step_abs_ratio = atof(actual_cmd.number1)) <= 10000)
					{
						pan_absolute_sensor.param.step_over_abs_ratio.fnum = step_abs_ratio;
						
						/* Writes Parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PEAR, (float)step_abs_ratio);   /* REM: pan encoder over absolute sensor ratio setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END PAN ENCODER OVER ABSOLUTE SENSOR RATIO	
				
				
				// SET TILT MOTOR LIMIT CONTROL
				if ((strcmp(actual_cmd.parameter, "limitct") == 0) ||
					(strcmp(actual_cmd.parameter, "lct") == 0))
				{	
					if (((limit_control = atoi(actual_cmd.number1)) >= LIMIT_CONTROL_DISABLED)
					&& (limit_control = atoi(actual_cmd.number1)) <= LIMIT_CONTROL_ENABLED)
					{
						tilt_axis.param.limit_control = limit_control;
						
						/* Writes parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STLT, (uint16)limit_control);   /* REM: tilt axis limit control setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END TILT MOTOR LIMIT CONTROL	
				
				
				// SET ABSOLUTE SENSOR TILT INVERTION
				if ((strcmp(actual_cmd.parameter, "invabst") == 0) ||
					(strcmp(actual_cmd.parameter, "invt") == 0))
				{	
					if (((raw_invertion = atoi(actual_cmd.number1)) >= ABS_SENSOR_TRUE)
					&& (raw_invertion = atoi(actual_cmd.number1)) <= ABS_SENSOR_INVERTED)
					{
						tilt_absolute_sensor.param.raw_invertion = raw_invertion;
						
						/* Writes parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SIVT, (uint16)raw_invertion);   /* REM: tilt axis absoluter sensor invertion setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END ABSOLUTE SENSOR TILT INVERTION				
				
				
				//SET ABSOLUTE SENSOR TILT ZERO (HOME)
				if ((strcmp(actual_cmd.parameter, "zeroabst") == 0) ||
					(strcmp(actual_cmd.parameter, "zt") == 0))
				{	
					printf("* Warning! Put TILT Axis to zero (HOME) position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						tilt_absolute_sensor.param.raw_home = 0; 		/* reset absolute tilt sensor zero raw 			*/

						//start Tilt Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&tilt_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Tilt Absolute Sensor Statistics
						statistics_stop(&tilt_absolute_sensor_stat);
						printf("* Statistics stop!\r\n");								
	
						/* Update Global Parameter			*/
						tilt_absolute_sensor.param.raw_home = (int16)tilt_absolute_sensor_stat.mean;
						printf(STR_REM_TASZ, (int16)tilt_absolute_sensor.param.raw_home); 	/* REM: Absolute Sensor Zero... setted to...*/								
					}
					else
					{
						printf("\r\n* Tilt Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR TILT ZERO (HOME)				
				
				
				//SET ABSOLUTE SENSOR TILT LIMIT MIN
				if ((strcmp(actual_cmd.parameter, "limitmint") == 0) ||
					(strcmp(actual_cmd.parameter, "lmint") == 0))
				{	
					printf("* Warning! Put TILT Axis to limit MIN position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						tilt_absolute_sensor.param.raw_limit_min = 0; 		/* reset absolute tilt sensor limit min raw 	*/

						//start Tilt Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&tilt_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Tilt Absolute Sensor Statistics
						statistics_stop(&tilt_absolute_sensor_stat);
						printf("* Statistics stop!\r\n");								
	
						/* Update Global Parameter			*/
						tilt_absolute_sensor.param.raw_limit_min = (int16)tilt_absolute_sensor_stat.mean;																
						printf(STR_REM_TMIN, (int16)tilt_absolute_sensor.param.raw_limit_min); 	/* REM: Absolute Sensor Limit... setted to...*/								
					}
					else
					{
						printf("\r\n* Tilt Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR TILT LIMIT MIN
				
				
				//SET ABSOLUTE SENSOR TILT LIMIT MAX
				if ((strcmp(actual_cmd.parameter, "limitmaxt") == 0) ||
					(strcmp(actual_cmd.parameter, "lmaxt") == 0))
				{	
					printf("* Warning! Put TILT Axis to limit MAX position and press y!");
					
					if (ButtonYNChoice(ECHO_ON) == _YES)
					{						
						tilt_absolute_sensor.param.raw_limit_max = 0; 		/* reset absolute tilt sensor limit max raw 	*/

						//start Tilt Absolute Sensor Statistics
						printf("\r\n* Statistics start!\r\n");							
						statistics_start(&tilt_absolute_sensor_stat);
						
						//Delay
						CyDelay(1000);
						
						//stop Tilt Absolute Sensor Statistics
						statistics_stop(&tilt_absolute_sensor_stat);
						printf("* Statistics stop!\r\n");								
	
						/* Update Global Parameter			*/
						tilt_absolute_sensor.param.raw_limit_max = (int16)tilt_absolute_sensor_stat.mean;
						printf(STR_REM_TMAX, (int16)tilt_absolute_sensor.param.raw_limit_max); 	/* REM: Absolute Sensor Limit... setted to...*/								
					}
					else
					{
						printf("\r\n* Tilt Absolute Sensor position not sampled!\r\n");								
					}
						
					/* Update EEPROM */
					dummy = WriteAllEEparams();

					goto exitpars;
				}	
				//END SET ABSOLUTE SENSOR TILT LIMIT MAX)

				
				// SET ABSOLUTE SENSOR TILT LIMIT HYSTERESIS
				if ((strcmp(actual_cmd.parameter, "limithystt") == 0) ||
					(strcmp(actual_cmd.parameter, "lhystt") == 0))
				{	
					if (((raw_limit_hyst = atoi(actual_cmd.number1)) >= -100)
					&& (raw_limit_hyst = atoi(actual_cmd.number1)) <= 100)
					{
						tilt_absolute_sensor.param.raw_limit_hysteresis = raw_limit_hyst;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TLHY, (uint16)raw_limit_hyst);   /* REM: tilt axis absolute sensor limit hysteresis setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END ABSOLUTE SENSOR TILT LIMIT HYSTERESIS		
			
				
				// SET TILT ENCODER OVER ABSOLUTE SENSOR RATIO
				if ((strcmp(actual_cmd.parameter, "ratioabst") == 0) ||
					(strcmp(actual_cmd.parameter, "ratiot") == 0))
				{	
					if (((step_abs_ratio = atof(actual_cmd.number1)) >= -10000)
					&& (step_abs_ratio = atof(actual_cmd.number1)) <= 10000)
					{
						tilt_absolute_sensor.param.step_over_abs_ratio.fnum = step_abs_ratio;
						
						/* Writes Parameter on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TEAR, (float)step_abs_ratio);   /* REM: tilt encoder over absolute sensor ratio setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END TILT ENCODER OVER ABSOLUTE SENSOR RATIO					
								
				
				// SET INVERTION YAW (IMU)
				if ((strcmp(actual_cmd.parameter, "imuinvyaw") == 0) ||
					(strcmp(actual_cmd.parameter, "imuy") == 0))
				{	
					if (((invertion = atoi(actual_cmd.number1)) >= 0)
					&& (invertion = atoi(actual_cmd.number1)) <= 1)
					{
						IMU_sensor.param.yaw_invertion = invertion;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SINY, (uint16)IMU_sensor.param.yaw_invertion);   /* REM: Invertion Yaw setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET INVERTION YAW (IMU)	
				
				
				// SET INVERTION PITCH (IMU)
				if ((strcmp(actual_cmd.parameter, "imuinvpitch") == 0) ||
					(strcmp(actual_cmd.parameter, "imup") == 0))
				{	
					if (((invertion = atoi(actual_cmd.number1)) >= 0)
					&& (invertion = atoi(actual_cmd.number1)) <= 1)
					{
						IMU_sensor.param.pitch_invertion = invertion;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SINP, (uint16)IMU_sensor.param.pitch_invertion);   /* REM: Invertion Pitch setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET INVERTION PITCH (IMU)	
				
				
				// SET INVERTION ROLL (IMU)
				if ((strcmp(actual_cmd.parameter, "imuinvroll") == 0) ||
					(strcmp(actual_cmd.parameter, "imur") == 0))
				{	
					if (((invertion = atoi(actual_cmd.number1)) >= 0)
					&& (invertion = atoi(actual_cmd.number1)) <= 1)
					{
						IMU_sensor.param.roll_invertion = invertion;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SINR, (uint16)IMU_sensor.param.roll_invertion);   /* REM: Invertion Roll setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET INVERTION ROLL (IMU)	
				
				
				// SET PITCH ROLL EXCHANGE (IMU)
				if ((strcmp(actual_cmd.parameter, "prexchange") == 0) ||
					(strcmp(actual_cmd.parameter, "prex") == 0))
				{	
					if (((exchange = atoi(actual_cmd.number1)) >= 0)
					&& (exchange = atoi(actual_cmd.number1)) <= 1)
					{
						IMU_sensor.param.pitch_roll_exchange = exchange;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SPRX, (uint16)IMU_sensor.param.pitch_roll_exchange);   /* REM: Invertion Roll setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PITCH ROLL EXCHANGE (IMU)					
				
				
				//SET Q ELEMENT (SHOT)
				if ((strcmp(actual_cmd.parameter, "q") == 0) ||
					(strcmp(actual_cmd.parameter, "shot") == 0))
				{	
					if ((strcmp(actual_cmd.number2, "clear") == 0) ||
					    (strcmp(actual_cmd.number2, "c") == 0))
					   
					{					
						if (((q_number = atoi(actual_cmd.number1)) >= Q_NUMBER_MIN)
						&& (q_number = atoi(actual_cmd.number1)) <= Q_NUMBER_MAX)
						{	
							/* Update Global Parameter and RT data	*/
							//if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)
							if (q[q_table[q_number]].number != Q_NUMBER_UNUSED)
							{						
								printf("\r\n* Q%02d element (shot) Cleared!\r\n", (uint16)q[q_table[q_number]].number);
								
								q[q_table[q_number]].number		= Q_NUMBER_UNUSED;
								
								/* Update EEPROM */
								if (WriteQEEparams(q_table[q_number]) != CYRET_SUCCESS)
								{
									printf(STR_ERROR7);				/* ERROR7: EEPROM row out of bounds! */								
								}
							}
							else
							{
								printf("\r\n* Nothing to clear: Q element is not allocated!\r\n");	
							}
						}
					}
					else if (((memory_number = atoi(actual_cmd.number2)) >= Q_MEMORY_NUMBER_MIN)
						    && (memory_number = atoi(actual_cmd.number2)) < Q_MEMORY_NUMBER_MAX)
					{					
						if (((q_number = atoi(actual_cmd.number1)) >= Q_NUMBER_MIN)
						&& (q_number = atoi(actual_cmd.number1)) <= Q_NUMBER_MAX)
						{							
							printf("* Warning! Put All Axes to desired position and press y!");
							
							if (ButtonYNChoice(ECHO_ON) == _YES)
							{														
								if (strlen(actual_cmd.number2) != 0)
								{	
									//user defined memory number
									q_table[q_number] 			= memory_number;				  		/* save for fast indexing 	*/
								}
								else
								{
									//table standard memory number
									q_table[q_number] 			= qmemory_standard_address[q_number];	/* save for fast indexing 	*/
								}
								
								/* Update Global Parameters and RT data	*/
								q[q_table[q_number]].number									= (uint8)(q_number);
								q[q_table[q_number]].mc.position[PAN_AXIS]             		= pan_absolute_sensor.position;								
								q[q_table[q_number]].param.position_default[PAN_AXIS].fnum  = pan_absolute_sensor.position;

								q[q_table[q_number]].mc.position[TILT_AXIS]            		= tilt_absolute_sensor.position;								
								q[q_table[q_number]].param.position_default[TILT_AXIS].fnum = tilt_absolute_sensor.position;								
								
								printf("\r\n* Q%02d element (shot) ABS position setted to: pan=%+ld [step]   tilt=%+ld [step] and saved to Memory%2d\r\n",
									(uint16)q_number,
									(int32)pan_absolute_sensor.position,
									(int32)tilt_absolute_sensor.position,
									(int16)q_table[q_number]);	
							}
							else
							{
								printf("\r\n* Q element (shot) position not sampled!\r\n");								
							}
								
							/* Update EEPROM */
							if (WriteQEEparams(q_table[q_number]) != CYRET_SUCCESS)
							{
								printf(STR_ERROR7);				/* ERROR7: EEPROM row out of bounds! */								
							}
						}
						else
						{
							printf(STR_ERROR5);				/* ERROR5: Number not allowed */					
						}						
					}
//					else if (strcmp(actual_cmd.number2, "c") == 0)
//					//else if ((memory_number = atoi(actual_cmd.number2)) == Q_MEMORY_CLEAR_FLAG)
//					{					
//						if (((q_number = atoi(actual_cmd.number1)) >= Q_NUMBER_MIN)
//						&& (q_number = atoi(actual_cmd.number1)) <= Q_NUMBER_MAX)
//						{	
//							/* Update Global Parameter and RT data	*/
//							if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)
//							{						
//								printf("\r\n* Q%02d element (shot) Cleared!\r\n", (uint16)q[q_table[q_number]].number);
//								
//								q[q_table[q_number]].number		= Q_NUMBER_UNUSED;
//								
//								/* Update EEPROM */
//								if (WriteQEEparams(q_table[q_number]) != CYRET_SUCCESS)
//								{
//									printf(STR_ERROR7);				/* ERROR7: EEPROM row out of bounds! */								
//								}
//							}
//							else
//							{
//								printf("\r\n* Nothing to clear: Q element is not allocated!\r\n");	
//							}
//							
//						}
//					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */					
					}
					goto exitpars;
				}	
				//END SET SET Q ELEMENT (SHOT)
				
				
				// SET PAN MOTOR Kp
				if (strcmp(actual_cmd.parameter, "kpp") == 0)
				{	
					if (((Kp = atof(actual_cmd.number1)) >= 0)
					&& (Kp = atof(actual_cmd.number1)) <= 100)
					{
						pan_axis.param.Kpf.fnum = Kp;
						
						/* Writes Kp on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PMKP, (float)pan_axis.param.Kpf.fnum);   /* REM: Pan Motor Kp setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Kp

				
				// SET TILT MOTOR Kp
				if (strcmp(actual_cmd.parameter, "kpt") == 0)
				{	
					if (((Kp = atof(actual_cmd.number1)) >= 0)
					&& (Kp = atof(actual_cmd.number1)) <= 100)
					{
						tilt_axis.param.Kpf.fnum = Kp;
						
						/* Writes Kp on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TMKP, (float)tilt_axis.param.Kpf.fnum);   /* REM: Tilt Motor Kp setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Kp				
				
				
				// SET PAN MOTOR Kd
				if (strcmp(actual_cmd.parameter, "kdp") == 0)
				{	
					if (((Kd = atof(actual_cmd.number1)) >= 0)
					&& (Kd = atof(actual_cmd.number1)) <= 1000)
					{
						pan_axis.param.Kdf.fnum = Kd;
						
						/* Writes Kp on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PMKD, (float)pan_axis.param.Kdf.fnum);   /* REM: Pan Motor Kd setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Kd

				
				// SET TILT MOTOR Kd
				if (strcmp(actual_cmd.parameter, "kdt") == 0)
				{	
					if (((Kd = atof(actual_cmd.number1)) >= 0)
					&& (Kd = atof(actual_cmd.number1)) <= 1000)
					{
						tilt_axis.param.Kdf.fnum = Kd;
						
						/* Writes Kp on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TMKD, (float)tilt_axis.param.Kdf.fnum);   /* REM: Tilt Motor Kd setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Kd				
				
				
				// SET PAN MOTOR Ki
				if (strcmp(actual_cmd.parameter, "kip") == 0)
				{	
					if (((Ki = atof(actual_cmd.number1)) >= 0)
					&& (Ki = atof(actual_cmd.number1)) <= 100)
					{
						pan_axis.param.Kif.fnum = Ki;
						
						/* Writes Ki on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PMKI, (float)pan_axis.param.Kif.fnum);   /* REM: Pan Motor Ki setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Ki

				
				// SET TILT MOTOR Ki
				if (strcmp(actual_cmd.parameter, "kit") == 0)
				{	
					if (((Ki = atof(actual_cmd.number1)) >= 0)
					&& (Ki = atof(actual_cmd.number1)) <= 100)
					{
						tilt_axis.param.Kif.fnum = Ki;
						
						/* Writes Ki on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TMKI, (float)tilt_axis.param.Kif.fnum);   /* REM: Tilt Motor Ki setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Ki				
				
				
				// SET PAN MOTOR Ksi
				if (strcmp(actual_cmd.parameter, "ksip") == 0)
				{	
					if (((Ksi = atof(actual_cmd.number1)) >= 0)
					&& (Ksi = atof(actual_cmd.number1)) <= 1000000)
					{
						pan_axis.param.Ksif.fnum = Ksi;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PMKS, (float)pan_axis.param.Ksif.fnum);   /* REM: Pan Motor Ksi setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Ksi

				
				// SET TILT MOTOR Ksi
				if (strcmp(actual_cmd.parameter, "ksit") == 0)
				{	
					if (((Ksi = atof(actual_cmd.number1)) >= 0)
					&& (Ksi = atof(actual_cmd.number1)) <= 1000000)
					{
						tilt_axis.param.Ksif.fnum = Ksi;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TMKS, (float)tilt_axis.param.Ksif.fnum);   /* REM: Tilt Motor Ksi setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Ksi				
				
				
				// SET A[NAOUT]AXIS
				if ((strcmp(actual_cmd.parameter, "anaoutaxis") == 0) ||
					(strcmp(actual_cmd.parameter, "aaxis") == 0))
				{			
					if ((strcmp(actual_cmd.number1, "pan") == 0) || (strcmp(actual_cmd.number1, "tilt") == 0))
					{							
						if (strcmp(actual_cmd.number1, "pan") == 0)
						{								
							/* Update Global Volatile Parameter			*/
							Selected_ANAOUT=&pan_axis;
							printf(STR_REM_ANAXP);   /* REM: Anaout Axis setted to PAN*/
							
							CyDelay(100);
							printf ("* ANAPOS ZERO!\r\n");
							/* anapos_offset <-- correct value to zero oscilloscope output */
							anapos_offset = GetAnaposOffsetZero();							
						}
						
						if (strcmp(actual_cmd.number1, "tilt") == 0)
						{
							/* Update Global Volatile Parameter			*/
							Selected_ANAOUT=&tilt_axis;
							printf(STR_REM_ANAXT);   /* REM: Anaout Axis setted to TILT*/
							
							CyDelay(100);
							printf ("* ANAPOS ZERO!\r\n");
							/* anapos_offset <-- correct value to zero oscilloscope output */
							anapos_offset = GetAnaposOffsetZero();	
						}
					
						/* Update EEPROM */
						dummy = WriteAllEEparams();
					}
					else
					{
						printf(STR_ERROR6);			/* ERROR6: Axis may be [pan,tilt,roll,all] */
					}
					goto exitpars;
				}	
				//END SET A[NAOUT]AXIS							
				
				
				// SET PAN MOTOR COLOR
				if (strcmp(actual_cmd.parameter, "colorp") == 0)
				{	
					if (((color = atoi(actual_cmd.number1)) >= GYRO_RATE)
					&& (color = atoi(actual_cmd.number1)) <= CTRL_CV)
					{
						pan_axis.param.color = color;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SCOL);   /* REM: pan axis color setted to...*/
						ShowParamsColor(&pan_axis);
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END PAN MOTOR COLOR
				
				
				// SET TILT MOTOR COLOR
				if (strcmp(actual_cmd.parameter, "colort") == 0)
				{	
					if (((color = atoi(actual_cmd.number1)) >= GYRO_RATE)
					&& (color = atoi(actual_cmd.number1)) <= CTRL_CV)
					{
						tilt_axis.param.color = color;
						
						/* Writes Burst Period on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SCOLT);   /* REM: tilt axis color setted to...*/
						ShowParamsColor(&tilt_axis);						
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR COLOR				
				
				
				// SET PAN MOTOR Kopf
				if (strcmp(actual_cmd.parameter, "kopfp") == 0)
				{	
					if (((Kopf = atof(actual_cmd.number1)) >= 0)
					&& (Kopf = atof(actual_cmd.number1)) <= 10)
					{
						pan_axis.param.Kopf.fnum = Kopf;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PKOF, (float)pan_axis.param.Kopf.fnum);   /* REM: Pan Motor Kopf setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Kopf		
				
				
				// SET TILT MOTOR Kopf
				if (strcmp(actual_cmd.parameter, "kopft") == 0)
				{	
					if (((Kopf = atof(actual_cmd.number1)) >= 0)
					&& (Kopf = atof(actual_cmd.number1)) <= 10)
					{
						tilt_axis.param.Kopf.fnum = Kopf;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TKOF, (float)tilt_axis.param.Kopf.fnum);   /* REM: Tilt Motor Kopf setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Kopf 					

				
				// SET PAN MOTOR Again
				if (strcmp(actual_cmd.parameter, "againp") == 0)
				{	
					if (((anaout_gain = atof(actual_cmd.number1)) >= -1000)
					&& (anaout_gain = atof(actual_cmd.number1)) <= 1000)
					{
						pan_axis.param.Gain_ANAOUT.fnum = anaout_gain;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_PAGA, (float)pan_axis.param.Gain_ANAOUT.fnum);   /* REM: Pan Motor Anaout Gain setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET PAN MOTOR Again	
				
				
				// SET TILT MOTOR Again
				if (strcmp(actual_cmd.parameter, "againt") == 0)
				{	
					if (((anaout_gain = atof(actual_cmd.number1)) >= -1000)
					&& (anaout_gain = atof(actual_cmd.number1)) <= 1000)
					{
						tilt_axis.param.Gain_ANAOUT.fnum = anaout_gain;
						
						/* Writes Ksi on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_TAGA, (float)tilt_axis.param.Gain_ANAOUT.fnum);   /* REM: Tilt Motor Anaout Gain setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET TILT MOTOR Again				
				
				
//				// SET KPLOWPASS
//				if ((strcmp(actual_cmd.parameter, "kplowpass") == 0) ||
//					(strcmp(actual_cmd.parameter, "kpl") == 0))
//				{	
//					if (((kplowpass = atoi(actual_cmd.number1)) >= 0)
//					&& (kplowpass = atoi(actual_cmd.number1)) <= 1)
//					{
//						gobee_param.kplowpass = kplowpass;
//						
//						/* Writes Kp Low Pass flag on EEPROM */
//						dummy = WriteAllEEparams();
//						printf(STR_REM_SEKL, (uint16)kplowpass);   /* REM: kp Low Pass setted to...*/					
//					}
//					else
//					{
//						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//					}
//					goto exitpars;
//				}	
//				// END SET KP LOWPASS


				// SET ACC X AXIS ADC OFFSET
				if ((strcmp(actual_cmd.parameter, "aacxoffset") == 0) ||
					(strcmp(actual_cmd.parameter, "aacxof") == 0))
				{	
					if (((offset = atoi(actual_cmd.number1)) >= -150)
					&& (offset = atoi(actual_cmd.number1)) <= 150)
					{
						gobee_param.x_acc_ADC_offset = (int16)offset;
						
						/* Writes STEER DAC OFFSET on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SEAX, (int16)offset);   /* REM: ACC AXIS X ADC offset setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET ACC X AXIS ADC OFFSET


				// SET ACC Y AXIS ADC OFFSET
				if ((strcmp(actual_cmd.parameter, "aacyoffset") == 0) ||
					(strcmp(actual_cmd.parameter, "aacyof") == 0))
				{	
					if (((offset = atoi(actual_cmd.number1)) >= -150)
					&& (offset = atoi(actual_cmd.number1)) <= 150)
					{
						gobee_param.y_acc_ADC_offset = (int16)offset;
						
						/* Writes STEER DAC OFFSET on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SEAY, (int16)offset);   /* REM: ACC AXIS Y ADC offset setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET ACC Y AXIS ADC OFFSET

				
				// SET ACC Z AXIS ADC OFFSET
				if ((strcmp(actual_cmd.parameter, "aaczoffset") == 0) ||
					(strcmp(actual_cmd.parameter, "aaczof") == 0))
				{	
					if (((offset = atoi(actual_cmd.number1)) >= -150)
					&& (offset = atoi(actual_cmd.number1)) <= 150)
					{
						gobee_param.z_acc_ADC_offset = (int16)offset;
						
						/* Writes STEER DAC OFFSET on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_SEAZ, (int16)offset);   /* REM: ACC AXIS Z ADC offset setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET ACC Z AXIS ADC OFFSET				
		
				
//				// SET Digital Gyro Offset FINE
//				if (strcmp(actual_cmd.parameter, "dgfine") == 0)
//				{	
//					if (((offset_fine = atof(actual_cmd.number1)) >= -10)
//					&& (offset_fine = atof(actual_cmd.number1)) <= +10)
//					{
//						gobee_param.dgyro_offset_fine.fnum = offset_fine;
//						
//						/* Writes Ki on EEPROM */
//						dummy = WriteAllEEparams();
//						printf(STR_REM_STDF, (float)offset_fine);   /* REM: Digital Gyro Offset Fine...*/					
//					}
//					else
//					{
//						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//					}
//					goto exitpars;
//				}	
//				// END SET Digital Gyro Offset FINE


//				// SET Analog Gyro Offset FINE
//				if (strcmp(actual_cmd.parameter, "agfine") == 0)
//				{	
//					if (((offset_fine = atof(actual_cmd.number1)) >= -10)
//					&& (offset_fine = atof(actual_cmd.number1)) <= +10)
//					{
//						gobee_param.gyro_offset_fine.fnum = offset_fine;
//						
//						/* Writes Ki on EEPROM */
//						dummy = WriteAllEEparams();
//						printf(STR_REM_STOF, (float)offset_fine);   /* REM: Analog Gyro Offset Fine...*/					
//					}
//					else
//					{
//						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//					}
//					goto exitpars;
//				}	
//				// END SET Analog Gyro Offset FINE


//				// SET Analog Gyro Scale Offset FINE
//				if (strcmp(actual_cmd.parameter, "agsfine") == 0)
//				{	
//					if (((offset_fine = atof(actual_cmd.number1)) >= -0.1)
//					&& (offset_fine = atof(actual_cmd.number1)) <= +0.1)
//					{
//						gobee_param.gyro_scale_offset_fine.fnum = offset_fine;
//						
//						/* Writes Ki on EEPROM */
//						dummy = WriteAllEEparams();
//						printf(STR_REM_STSF, (float)offset_fine);   /* REM: Analog Gyro Scale Offset Fine...*/					
//					}
//					else
//					{
//						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//					}
//					goto exitpars;
//				}	
//				// END SET Analog Gyro Scale Offset FINE



//			// SET alpha
//				if (strcmp(actual_cmd.parameter, "alpha") == 0)
//				{	
//					if (((alpha = atof(actual_cmd.number1)) >= 0)
//					&& (alpha = atof(actual_cmd.number1)) <= 1)
//					{
//						gobee_param.alpha.fnum = alpha;
//						
//						/* Writes alpha on EEPROM */
//						dummy = WriteAllEEparams();
//						printf(STR_REM_STAL, (float)gobee_param.alpha.fnum);   /* REM: alpha setted to...*/					
//					}
//					else
//					{
//						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
//					}
//					goto exitpars;
//				}	
//				// END SET alpha
				
				
			// SET beta
				if (strcmp(actual_cmd.parameter, "beta") == 0)
				{	
					if (((beta = atof(actual_cmd.number1)) >= 0)
					&& (beta = atof(actual_cmd.number1)) <= 1)
					{
						gobee_param.beta.fnum = beta;
						
						/* Writes alpha on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STBT, (float)gobee_param.beta.fnum);   /* REM: beta setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET beta				

				
				// SET gamma (IMU LPF)
				if (strcmp(actual_cmd.parameter, "gamma") == 0)
				{	
					if (((gamma = atof(actual_cmd.number1)) >= 0)
					&& (gamma = atof(actual_cmd.number1)) <= 1)
					{
						IMU_sensor.param.gamma.fnum = gamma;
						
						/* Writes alpha on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STGM, (float)IMU_sensor.param.gamma.fnum);   /* REM: gamma setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET gamma (IMU LPF)

				
				// SET Jump G Threshold
				if (strcmp(actual_cmd.parameter, "jumpth") == 0)
				{	
					if (((jump_g_th = atof(actual_cmd.number1)) >= 0)
					&& (jump_g_th = atof(actual_cmd.number1)) <= 10)
					{
						gobee_param.jump_g_threshold.fnum = jump_g_th;
						
						/* Writes alpha on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STJG, (float)gobee_param.jump_g_threshold.fnum);   /* REM: jump g thr setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET Jump G Threshold		
				
				
				// SET Acceleration G Threshold
				if (strcmp(actual_cmd.parameter, "accth") == 0)
				{	
					if (((acc_g_th = atof(actual_cmd.number1)) >= 0)
					&& (acc_g_th = atof(actual_cmd.number1)) <= 10)
					{
						gobee_param.acc_g_threshold.fnum = acc_g_th;
						
						/* Writes alpha on EEPROM */
						dummy = WriteAllEEparams();
						printf(STR_REM_STAG, (float)gobee_param.acc_g_threshold.fnum);   /* REM: acc g thr setted to...*/					
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				// END SET Acceleration G Threshold					
				
				
				// SET ASTIM TYPE
				if ((strcmp(actual_cmd.parameter, "astype") == 0) ||
				   (strcmp(actual_cmd.parameter, "astimtype") == 0)) 
				{	
					if (((astim_type = atoi(actual_cmd.number1)) >= NO_ASTIM)
					&& (astim_type = atoi(actual_cmd.number1)) <= SQUARE_ASTIM)
					{		
//						if (astim_type != NO_ASTIM)
//						{
//							printf(STR_ASTIMA);				/* DANGER!!! PROMPT					*/
//							printf(STR_ASTIMB);				//
//							
//							if (ButtonYNChoice(ECHO_ON) == _NO)
//							{
//								goto exitpars;
//							}
//							printf("\r\n");
							
							/* Update Global Volatile Parameter		*/
							pan_axis.vparam.astim_type  = astim_type;
							tilt_axis.vparam.astim_type = astim_type;						
							
							printf(STR_REM_ASTP, (uint16)astim_type);   /* REM: PAN  Astim Type Configured to...*/
							printf(STR_REM_ASTT, (uint16)astim_type);   /* REM: TILT Astim Type Configured to...*/							
							
							WaveDAC8_Start();					//Starts WaveDAC8	
							PGA_ASTIM_Start();					//Starts PGA_ASTIM
							
							if (astim_type == SINE_ASTIM)
							{
								WaveDAC8_Stop();					//Stops WaveDAC8	
								Control_Reg_WS_Write(0);			//Selects wave 0
								WaveDAC8_Start();					//Starts WaveDAC8
								printf("Sine Wave Astim Started!\r\n");							
							}
							else if (astim_type == TRIANGLE_ASTIM)
							{
								WaveDAC8_Stop();					//Stops WaveDAC8	
								Control_Reg_WS_Write(1);			//Selects wave 1																	
								WaveDAC8_Wave2Setup(WaveDAC8_wave_triangle, WaveDAC8_WAVE_TRIANGLE_LENGTH);	//SELECTS TRIANGLE
								WaveDAC8_Start();					//Starts WaveDAC8
								printf("Triangle Wave Astim Started!\r\n");								
							}
							else if (astim_type == SQUARE_ASTIM)
							{
								WaveDAC8_Stop();					//Stops 						
								Control_Reg_WS_Write(1);			//Selects wave 1	
								WaveDAC8_Wave2Setup(WaveDAC8_wave_square, WaveDAC8_WAVE_SQUARE_LENGTH);	//SELECTS SQUARE
								WaveDAC8_Start();					//Starts WaveDAC8
								printf("Square Wave Astim Started!\r\n");								
							}						
							else if (astim_type == NO_ASTIM)
							{
								WaveDAC8_Stop();					//Stops WaveDAC8
								PGA_ASTIM_Stop();					//Stops PGA_ASTIM
								printf("Wave Astim Stopped!\r\n");							
							}	
	//						/* Autozero anapos offset when change Astim types				*/
	//						/* anapos_offset <-- correct value to zero oscilloscope output 	*/
	//						anapos_offset = GetAnaposOffsetZero();									
//						}
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				//END SET ASTIM TYPE
				
				
				// SET ASTIM PAN ENABLE
				if (strcmp(actual_cmd.parameter, "astimp") == 0) 
				{	
					if (((astim_enable = atoi(actual_cmd.number1)) >= ASTIM_DISABLED)
					&& (astim_enable = atoi(actual_cmd.number1)) <= ASTIM_ENABLED)
					{		
						if (astim_enable == ASTIM_ENABLED)
						{
							printf(STR_ASTIMA);				/* DANGER!!! PROMPT					*/
							printf(STR_ASTIMB);				//
							
							if (ButtonYNChoice(ECHO_ON) == _NO)
							{
								goto exitpars;
							}
							printf("\r\n");	
	//						/* Autozero anapos offset when change Astim types				*/
	//						/* anapos_offset <-- correct value to zero oscilloscope output 	*/
	//						anapos_offset = GetAnaposOffsetZero();									
						}
						/* Update Global Volatile Parameter		*/
						pan_axis.vparam.astim_enable  = astim_enable;
						
						printf(STR_REM_ASEP, (uint16)astim_enable);   /* REM: PAN  Astim Type Configured to...*/
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				//END SET ASTIM PAN ENABLE				
				
				
				// SET ASTIM TILT ENABLE
				if (strcmp(actual_cmd.parameter, "astimt") == 0) 
				{	
					if (((astim_enable = atoi(actual_cmd.number1)) >= ASTIM_DISABLED)
					&& (astim_enable = atoi(actual_cmd.number1)) <= ASTIM_ENABLED)
					{		
						if (astim_enable == ASTIM_ENABLED)
						{
							printf(STR_ASTIMA);				/* DANGER!!! PROMPT					*/
							printf(STR_ASTIMB);				//
							
							if (ButtonYNChoice(ECHO_ON) == _NO)
							{
								goto exitpars;
							}
							printf("\r\n");
	//						/* Autozero anapos offset when change Astim types				*/
	//						/* anapos_offset <-- correct value to zero oscilloscope output 	*/
	//						anapos_offset = GetAnaposOffsetZero();									
						}
							/* Update Global Volatile Parameter		*/
							tilt_axis.vparam.astim_enable  = astim_enable;
							
							printf(STR_REM_ASET, (uint16)astim_enable);   /* REM: TILT  Astim Type Configured to...*/
					}
					else
					{
						printf(STR_ERROR5);				/* ERROR5: Number not allowed */
					}
					goto exitpars;
				}	
				//END SET ASTIM TILT ENABLE					
				
				
//				// SET DEFAULT machine parameters
//				if ((strcmp(actual_cmd.parameter, "default") == 0)
//				|| (strcmp(actual_cmd.parameter, "defaults") == 0))
//				{	
//					if ((strlen(actual_cmd.number1)) == 0)
//					{
//						printf("Are you sure [Y/N]?");
//						
//						if (ButtonYNChoice(ECHO_ON) == _YES)
//						{
//							cys_param.nodeid = 1;					/* Default CAN/RS485 nodeid = 1 				*/
//							cys_param.maxmotors = 8;				/* Default max motor number = 8 				*/
//							cys_param.maxcurrent = 64; 				/* Default Medium Current 						*/
//							cys_param.speed = VSTOP;				/* Default All Motor Stop 						*/
//							cys_param.moveTimeoutms = 20000;		/* Default 20secs of moving before FAULT 		*/
//							cys_param.currTimeoutms = 500;			/* Default 500msec before Current Fault     	*/
//							cys_param.faultcurrent = 600;			/* Default faulcurrent=600*2,014362[mA]=1200[mA]*/	
//				
//							strcpy(cys_param.unicode, "12345678");	/* Deafult Unicode = "12345678"					*/									
//							
//							for (idx=0;idx<=7;idx++)
//							{
//								cys_param.targets1[idx] = DEFAULT_TARGET_STEPS;	/* Target Steps Scene 1 Default */
//								cys_param.targets2[idx] = DEFAULT_TARGET_STEPS;	/* Target Steps Scene 2 Default */
//								cys_param.targets3[idx] = DEFAULT_TARGET_STEPS;	/* Target Steps Scene 3 Default */
//								cys_param.targets4[idx] = DEFAULT_TARGET_STEPS;	/* Target Steps Scene 4 Default */
//							}
//	
//							/* Writes MAXCURRENT on DACS */
//							VDAC_IREF_12_SetValue(cys_param.maxcurrent);
//							VDAC_IREF_34_SetValue(cys_param.maxcurrent);
//							VDAC_IREF_56_SetValue(cys_param.maxcurrent);
//							VDAC_IREF_78_SetValue(cys_param.maxcurrent);	
//	
//							/* Writes DEFAULT parameters on EEPROM */
//							dummy = WriteAllEEparams();						
//							
//							printf(STR_REM_DEFL);   /* REM: *All machine parameters setted to factory DEFAULT! */
//						}
//						else
//						{
//							printf(STR_REM_NODF);   /* REM: Machine parameters UNCHANGED! */
//						}
//					}
//					else
//					{
//						printf(STR_ERROR1);		/* ERROR1: Too much parameters! */
//					}
//					goto exitpars;
//				}					
//				
//				printf(STR_ERROR3);				/* ERROR3: Bad parameters */
//				// altri casi di set
//
			}
		goto exitpars;	
		}	
	printf(STR_ERROR4);

	
exitpars:	
	//printf("\r\n");	
	return 0;	// PARS_OK//
}


/* Verify Any CHAR pressed */
uint8 AnyButtonPressed(void)
{	
	// case USB standard input
	if (UART_USB_GetChar() == 0)
	{
		return NO_PRESSED;
	}
	else
	{
		return PRESSED;
	}
}



/* Verify [Y/N] choice */
uint8 ButtonYNChoice(bit echo)
{	
	char charin;
	
//	if (std_input == USB_STD_INPUT)
//	{
		// case USB standard input
		while ((charin = UART_USB_GetChar()) == 0)
		{
		//wait for char
		}
//	}
//	else
//	{
//		// case BT standard input
//		while ((charin = UART_BT_GetChar()) == 0)
//		{
//		//wait for char
//		}
//	}
	
	if (echo == 1)
	{
		printf("%c", charin);
	}
	
	if (tolower((int)charin) == 'y')
	{
		return _YES;
	}
	else
	{
		return _NO;
	}

}


void clear_string(char *str)
{
	uint8 idx = 0;
	for (idx=0; idx <= sizeof(str); idx++)
	{
		*(str + idx) = '\0';
	}
}


uint8 USB_Check(void)
{	
	return USB_INSERTED;	/* There is not the phisical signal on the board */

}


/* Get Anapos Offset value to zero Oscilloscope									*/
/*   returns: (int32)anapos_offset  correct value to zero oscilloscope output	*/
int32 GetAnaposOffsetZero(void)
{	
	/* CONTROL integral(t) CASE		*/
	if ((*Selected_ANAOUT).param.color == CTRL_IERROR)
	{
		anapos_offset = (*Selected_ANAOUT).mc.ierror;
	}
	/* CONTROL integral_action(t) CASE	*/
	else if ((*Selected_ANAOUT).param.color == CTRL_AZIERROR)
	{
		anapos_offset = (*Selected_ANAOUT).param.Kif.fnum * (*Selected_ANAOUT).mc.ierror;
	}	
	/* SLAVE CASE */
	else if ((*Selected_ANAOUT).param.color == SLAVE_ENC_POS)
	{
		if (Selected_ANAOUT == &pan_axis)
		{
			anapos_offset = QuadDec_PAN_GetCounter();
		}
		else if (Selected_ANAOUT == &tilt_axis)
		{
			anapos_offset = QuadDec_TILT_GetCounter();
		}	
//		else if (Selected_ANAOUT == &roll_axis)
//		{
//			anapos_offset = QuadDec_ROLL_GetCounter();
//		}	
		else
		{
			anapos_offset = 0;
		}				
	}
	/* ASTIM CASE */
	else if (((*Selected_ANAOUT).param.color == ASTIM_IN) || 
			((*Selected_ANAOUT).param.color == CTRL_ERROR) ||
			((*Selected_ANAOUT).param.color == CTRL_DERROR) ||
			((*Selected_ANAOUT).param.color == GYRO_RATE))
	{
			anapos_offset = 0;
	}
	
	return anapos_offset;
}


/* [] END OF FILE */
