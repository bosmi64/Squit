/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <gobee.h>
#include <gobeelib.h>
#include <clu.h>

/* EXTERN CLU Array 			*/
extern clu_type clu[MAX_CLU_NUMBER];

/* EXTERN CLU Sequence Array 	*/
extern uint8 clu_sequence[MAX_CLU_SEQUENCE_STEPS];


/********************************************************************************/
/* Constant CLUs Initialization													*/
/* GML 1.0																		*/
/********************************************************************************/
/*																				*/
/* clu[0..MAX_CLU_NUMBER-1][0..MAX_CLU_STEPS-1] = "CLU_CMDSTRING_SIZE chars"	*/
/*																				*/
/* MAX_CLU_NUMBER 	   	50														*/
/* MAX_CLU_STEPS 	   	21														*/
/* CLU_CMDSTRING_SIZE 	25														*/
/********************************************************************************/
void InitAllClus(void)
{
	ClearAllClus();
	
	/*----------------------------------------------*/
	/* CLU 00 INIT									*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[0][0], "#CAMERAON");	
	sprintf(clu[0][1], "#PTRAP +90 0.3 10");
	sprintf(clu[0][2], "#TTRAP +90 0.2 10");	
	sprintf(clu[0][3], "#PATHEXEC");
	sprintf(clu[0][4], "#CAMERAOFF");	
	sprintf(clu[0][5], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 01 INIT									*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[1][0], "#TGOTOH");	
	sprintf(clu[1][1], "#CAMERAON");	
	sprintf(clu[1][2], "#PAUSE 5.5");
	sprintf(clu[1][3], "#PTRAP +180 0.2 10");	
	sprintf(clu[1][4], "#PATHEXEC");
	sprintf(clu[1][5], "#PAUSE 10");	
	sprintf(clu[1][6], "#CAMERAOFF");	
	sprintf(clu[1][7], "#CLUEND");	

	
	/*----------------------------------------------*/
	/* CLU 02 INIT									*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[2][0], "#CAMERAON");
	sprintf(clu[2][1], "#PAUSE 5");	
	sprintf(clu[2][2], "#TTRAP +180 0.2 10");	
	sprintf(clu[2][3], "#PATHEXEC");
	sprintf(clu[2][4], "#PAUSE 10");	
	sprintf(clu[2][5], "#CAMERAOFF");		
	sprintf(clu[2][6], "#CLUEND");		
	
	
	/*----------------------------------------------*/
	/* CLU 03 INIT									*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[3][0], "#CAMERAON");
	sprintf(clu[3][1], "#PAUSE 5");	
	sprintf(clu[3][2], "#TTRAP +180 0.2 10");	
	sprintf(clu[3][3], "#PTRAP +180 0.2 15");	
	sprintf(clu[3][4], "#PATHEXEC");
	sprintf(clu[3][5], "#PAUSE 10");	
	sprintf(clu[3][6], "#CAMERAOFF");	
	sprintf(clu[3][7], "#GOTOH");	
	sprintf(clu[3][8], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 04 INIT									*/
	/* GOTO WHEEL (Q21)								*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[4][0], "#CAMERAON");	
	sprintf(clu[4][1], "#PTQ 21 0.3 5");	
	sprintf(clu[4][2], "#PATHEXEC");
	sprintf(clu[4][3], "#PAUSE 10");	
	sprintf(clu[4][4], "#CAMERAOFF");	
	sprintf(clu[4][5], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 05 INIT									*/
	/* GOTO PANORAMA DX (Q41)						*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[5][0], "#CAMERAON");	
	sprintf(clu[5][1], "#PTQ 41 0.3 5");	
	sprintf(clu[5][2], "#PATHEXEC");
	sprintf(clu[5][3], "#PAUSE 10");	
	sprintf(clu[5][4], "#CAMERAOFF");	
	sprintf(clu[5][5], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 06 INIT									*/
	/* GOTO ROAD (Q31)								*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[6][0], "#CAMERAON");	
	sprintf(clu[6][1], "#PTQ 31 0.3 5");	
	sprintf(clu[6][2], "#PATHEXEC");
	sprintf(clu[6][3], "#PAUSE 10");	
	sprintf(clu[6][4], "#CAMERAOFF");	
	sprintf(clu[6][5], "#CLUEND");

	
	/*----------------------------------------------*/
	/* CLU 10 INIT									*/
	/* SM_MOVING_TO_FACE							*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[10][0], "#CAMERAON");	
	sprintf(clu[10][1], "#TTRAP +35 0.2 2");	
	sprintf(clu[10][2], "#PTRAP +180 0.2 1.5");	
	sprintf(clu[10][3], "#PATHEXEC");
	sprintf(clu[10][4], "#CAMERAOFF");	
	sprintf(clu[10][5], "#CLUEND");
	
	/*----------------------------------------------*/
	/* CLU 11 INIT									*/
	/* GOTO HOME PAN & TILT							*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[11][0], "#GOTOH");		
	sprintf(clu[11][1], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 12 INIT									*/
	/* MOVING_PANORAMIC PAN	(GENERIC STYLE)			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[12][0], "#CAMERAON");	
	sprintf(clu[12][1], "#PTRAP +120 0.2 10");	
	sprintf(clu[12][2], "#PATHEXEC");
	sprintf(clu[12][3], "#PAUSE 5");	
	sprintf(clu[12][4], "#CAMERAOFF");
	sprintf(clu[12][5], "#GOTOH");	
	sprintf(clu[12][6], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 13 INIT									*/
	/* JUMP PAN	(SLOW)								*/
	/*                 "########################\0" */
	/*----------------------------------------------*/
	sprintf(clu[13][0], "#CAMERAON");	
	sprintf(clu[13][1], "#PTRAP +720 0.2 10");
	sprintf(clu[13][2], "#PATHEXEC");
	sprintf(clu[13][3], "#PAUSE 0.1");	
	sprintf(clu[13][4], "#PTRAP -720 0.2 10");		
	sprintf(clu[13][5], "#PATHEXEC");
	sprintf(clu[13][6], "#PAUSE 3");	
	sprintf(clu[13][7], "#CAMERAOFF");	
	sprintf(clu[13][8], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 14 INIT									*/
	/* MOVING_PANORAMIC PAN	(STANLEY STYLE)			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[14][0], "#CAMERAON");	
	sprintf(clu[14][1], "#PTRAP +160 0.2 5");	
	sprintf(clu[14][2], "#PATHEXEC");
	sprintf(clu[14][3], "#PAUSE 1");	
	sprintf(clu[14][4], "#PTRAP -160 0.2 1.5");	
	sprintf(clu[14][5], "#PATHEXEC");	
	sprintf(clu[14][6], "#PAUSE 5");	
	sprintf(clu[14][7], "#CAMERAOFF");	
	sprintf(clu[14][8], "#CLUEND");	
	
	/*----------------------------------------------*/
	/* CLU 15 INIT									*/
	/* MOVING_PANORAMIC PAN	(JJ STYLE)				*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[15][0], "#CAMERAON");	
	sprintf(clu[15][1], "#PTRAP +160 0.2 1.5");	
	sprintf(clu[15][2], "#TTRAP +30 0.2 1.5");	
	sprintf(clu[15][3], "#PATHEXEC");	
	sprintf(clu[15][4], "#PTRAP -80 0.2 0.75");
	sprintf(clu[15][5], "#TTRAP -60 0.2 0.75");	
	sprintf(clu[15][6], "#PATHEXEC");	
	sprintf(clu[15][7], "#PTRAP +60 0.2 1.5");
	sprintf(clu[15][8], "#TTRAP +30 0.2 1.5");	
	sprintf(clu[15][9], "#PATHEXEC");	
	sprintf(clu[15][10], "#CAMERAOFF");
	sprintf(clu[15][11], "#GOTOH");	
	sprintf(clu[15][12], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 16 INIT									*/
	/* SM_MOVING_TO_FACE (STANLEY STYLE)			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[16][0], "#CAMERAON");		
	sprintf(clu[16][1], "#PTRAP +180 0.2 4");	
	sprintf(clu[16][2], "#PATHEXEC");
	sprintf(clu[16][3], "#TTRAP +35 0.2 4");	
	sprintf(clu[16][4], "#PATHEXEC");
	sprintf(clu[16][5], "#PAUSE 10");	
	sprintf(clu[16][6], "#CAMERAOFF");	
	sprintf(clu[16][7], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 17 INIT									*/
	/* SM_MOVING_TO_FACE (JJ STYLE)					*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[17][0], "#CAMERAON");		
	sprintf(clu[17][1], "#PTRAP +200 0.2 2.5");
	sprintf(clu[17][2], "#TTRAP +45 0.2 2.5");	
	sprintf(clu[17][3], "#PATHEXEC");
	sprintf(clu[17][4], "#PTRAP -50 0.2 0.75");
	sprintf(clu[17][5], "#TTRAP -30 0.2 0.75");	
	sprintf(clu[17][6], "#PATHEXEC");
	sprintf(clu[17][7], "#PTRAP +30 0.2 1.5");
	sprintf(clu[17][8], "#TTRAP +20 0.2 1.5");	
	sprintf(clu[17][9], "#PATHEXEC");		
	sprintf(clu[17][10], "#CAMERAOFF");	
	sprintf(clu[17][11], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 18 INIT									*/
	/* SM_MOVING_TO_WHEEL (GENERIC STYLE)			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[18][0], "#CAMERAON");		
	sprintf(clu[18][1], "#TTRAP -45 0.2 3");	
	sprintf(clu[18][2], "#PATHEXEC");
	sprintf(clu[18][3], "#PAUSE 1");			
	sprintf(clu[18][4], "#CAMERAOFF");	
	sprintf(clu[18][5], "#CLUEND");	

	
	/*----------------------------------------------*/
	/* CLU 19 INIT									*/
	/* SM_MOVING_TO_WHEEL (STANLEY STYLE)			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[19][0], "#CAMERAON");		
	sprintf(clu[19][1], "#PTRAP +360 0.2 4");	
	sprintf(clu[19][2], "#PATHEXEC");
	sprintf(clu[19][3], "#TTRAP -45 0.2 2");	
	sprintf(clu[19][4], "#PATHEXEC");			
	sprintf(clu[19][5], "#CAMERAOFF");	
	sprintf(clu[19][6], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 20 INIT									*/
	/* SM_MOVING_TO_WHEEL (JJ STYLE)				*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[20][0], "#CAMERAON");	
	sprintf(clu[20][1], "#PTRAP -90 0.2 1.0");	
	sprintf(clu[20][2], "#TTRAP -25 0.2 1.0");
	sprintf(clu[20][3], "#PATHEXEC");
	sprintf(clu[20][4], "#PTRAP +180 0.2 2");	
	sprintf(clu[20][5], "#PATHEXEC");	
	sprintf(clu[20][6], "#PTRAP -90 0.2 1");	
	sprintf(clu[20][7], "#TTRAP -20 0.2 1");
	sprintf(clu[20][8], "#PATHEXEC");	
	sprintf(clu[20][9], "#CAMERAOFF");	
	sprintf(clu[20][10], "#CLUEND");		

	
	/*----------------------------------------------*/
	/* CLU 30 INIT									*/
	/* GOTO FACE (Q11)								*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[30][0], "#CAMERAON");	
	sprintf(clu[30][1], "#PTQ 11 0.3 3");	
	sprintf(clu[30][2], "#PATHEXEC");
	sprintf(clu[30][3], "#CAMERAOFF");	
	sprintf(clu[30][4], "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 31 INIT									*/
	/* SEQ FACE(Q11) -> WHEEL(Q21) -> HAND SX(Q15)	*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[31][0],  "#CAMERAON");	
	sprintf(clu[31][1],  "#PTQ 11 0.3 1.5");	//FACE in 3 sec	
	sprintf(clu[31][2],  "#PATHEXEC");
	sprintf(clu[31][3],  "#PAUSE 5");
	sprintf(clu[31][4],  "#PTQ 21 0.3 6");		//WHEEL	in 6 sec
	sprintf(clu[31][5],  "#PATHEXEC");
	sprintf(clu[31][6],  "#PAUSE 0.5");
	sprintf(clu[31][7],  "#PTQ 15 0.3 3");		//HAND SX in 3 sec	
	sprintf(clu[31][8],  "#PATHEXEC");	
	sprintf(clu[31][9],  "#CAMERAOFF");	
	sprintf(clu[31][10], "#CLUEND");
	
	
	/*------------------------------------------------------------------------------------------*/
	/* CLU 32 INIT																				*/
	/* SEQ PANORAMA DX REAR (Q43) -> PANORAMA FRONT (Q40) -> (Q40+120°PAN) --> (Q40-120°PAN)	*/
	/*                 "########################\0" 											*/
	/*------------------------------------------------------------------------------------------*/	
	sprintf(clu[32][0],  "#CAMERAON");	
	sprintf(clu[32][1],  "#PTQ 43 0.3 1.5");
	sprintf(clu[32][2],  "#PATHEXEC");
	sprintf(clu[32][3],  "#PAUSE 5");
	sprintf(clu[32][4],  "#PTQ 40 0.3 12");
	sprintf(clu[32][5],  "#PATHEXEC");
	sprintf(clu[32][6],  "#PAUSE 0.1");
	sprintf(clu[32][7],  "#PTRAP 120 0.3 12");
	sprintf(clu[32][8],  "#PATHEXEC");
	sprintf(clu[32][9],  "#PAUSE 3");
	sprintf(clu[32][10], "#PTRAP -120 0.3 6");	
	sprintf(clu[32][11], "#PATHEXEC");	
	sprintf(clu[32][12], "#CAMERAOFF");	
	sprintf(clu[32][13], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 33 INIT									*/
	/* SEQ FACE(Q11) -> SKY(Q51)					*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[33][0],  "#CAMERAON");	
	sprintf(clu[33][1],  "#PTQ 11 0.3 1.5");	
	sprintf(clu[33][2],  "#PATHEXEC");
	sprintf(clu[33][3],  "#PAUSE 5");
	sprintf(clu[33][4],  "#PTQ 51 0.3 12");
	sprintf(clu[33][5],  "#PATHEXEC");	
	sprintf(clu[33][6],  "#CAMERAOFF");	
	sprintf(clu[33][7],  "#CLUEND");	
	
	
	/*------------------------------------------------------------------------------------------*/
	/* CLU 34 INIT																				*/
	/* SEQ PANORAMA SX REAR (Q44) -> (Q40+120°PAN) --> (Q40-120°PAN)	*/
	/*                 "########################\0" 											*/
	/*------------------------------------------------------------------------------------------*/	
	sprintf(clu[34][0],  "#CAMERAON");	
	sprintf(clu[34][1],  "#PTQ 44 0.3 1.5");
	sprintf(clu[34][2],  "#PATHEXEC");
	sprintf(clu[34][3],  "#PAUSE 5");
	sprintf(clu[34][4],  "#PTRAP -300 0.3 20");
	sprintf(clu[34][5],  "#PATHEXEC");
	sprintf(clu[34][6],  "#CAMERAOFF");	
	sprintf(clu[34][7],  "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 35 INIT									*/
	/* SEQ WHEEL(Q21) -> SKY(Q51)					*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[35][0],  "#CAMERAON");	
	sprintf(clu[35][1],  "#PTQ 21 0.3 1.5");	
	sprintf(clu[35][2],  "#PATHEXEC");
	sprintf(clu[35][3],  "#PAUSE 5");
	sprintf(clu[35][4],  "#PTQ 51 0.3 12");
	sprintf(clu[35][5],  "#PATHEXEC");	
	sprintf(clu[35][6],  "#CAMERAOFF");	
	sprintf(clu[35][7],  "#CLUEND");
	
	
	/*----------------------------------------------*/
	/* CLU 36 INIT									*/
	/* BIG ROTATION PAN	(FACE)						*/
	/*                 "########################\0" */
	/*----------------------------------------------*/
	sprintf(clu[36][0], "#CAMERAON");	
	sprintf(clu[36][1], "#PTQ 11 0.2 1.5");
	sprintf(clu[36][2], "#PATHEXEC");	
	sprintf(clu[36][3], "#PTRAP +1440 0.2 20");
	sprintf(clu[36][4], "#PATHEXEC");	
	sprintf(clu[36][5], "#CAMERAOFF");	
	sprintf(clu[36][6], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 37 INIT									*/
	/* OSCILLATION PANORAMA FRONT					*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[37][0],  "#PTQ 40 0.2 1.5");
	sprintf(clu[37][1],  "#PATHEXEC");
	sprintf(clu[37][2],  "#PAUSE 5");
	sprintf(clu[37][3],  "#PTRAP +45 0.4 0.5");
	sprintf(clu[37][4],  "#PATHEXEC");
	sprintf(clu[37][5],  "#PTRAP -90 0.4 1");
	sprintf(clu[37][6],  "#PATHEXEC");
	sprintf(clu[37][7],  "#PTRAP +90 0.4 1");
	sprintf(clu[37][8],  "#PATHEXEC");
	sprintf(clu[37][9],  "#PTRAP -90 0.4 1");
	sprintf(clu[37][10], "#PATHEXEC");	
	sprintf(clu[37][11], "#PTRAP +90 0.4 1");
	sprintf(clu[37][12], "#PATHEXEC");
	sprintf(clu[37][13], "#PTRAP -90 0.4 1");
	sprintf(clu[37][14], "#PATHEXEC");
	sprintf(clu[37][15], "#PTRAP +90 0.4 1");
	sprintf(clu[37][16], "#PATHEXEC");	
	sprintf(clu[37][17], "#PTQ 40 0.4 4");
	sprintf(clu[37][18], "#PATHEXEC");	
	sprintf(clu[37][19], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 38 INIT									*/
	/* WHERE ARE MY EYES LOOKING FOR?				*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[38][0],  "#PTQ 11 0.2 1.5");
	sprintf(clu[38][1],  "#PATHEXEC");
	sprintf(clu[38][2],  "#PAUSE 2");
	sprintf(clu[38][3],  "#PTQ 14 0.2 1.5");
	sprintf(clu[38][4],  "#PATHEXEC");	
	sprintf(clu[38][5],  "#PAUSE 1");
	sprintf(clu[38][6],  "#PTQ 11 0.2 1.5");
	sprintf(clu[38][7],  "#PATHEXEC");
	sprintf(clu[38][8],  "#PAUSE 2");	
	sprintf(clu[38][9],  "#PTQ 17 0.2 1.5");
	sprintf(clu[38][10], "#PATHEXEC");	
	sprintf(clu[38][11], "#PAUSE 1");	
	sprintf(clu[38][12], "#PTQ 11 0.2 1.5");
	sprintf(clu[38][13], "#PATHEXEC");
	sprintf(clu[38][14], "#PAUSE 1.5");
	sprintf(clu[38][15], "#PTQ 31 0.2 9");
	sprintf(clu[38][16], "#PATHEXEC");		
	sprintf(clu[38][17], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 39 INIT									*/
	/* WHERE ARE MY EYES LOOKING FOR II?			*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[39][0],  "#PTQ 11 0.2 1.5");
	sprintf(clu[39][1],  "#PATHEXEC");
	sprintf(clu[39][2],  "#PAUSE 2");
	sprintf(clu[39][3],  "#PTQ 42 0.2 1.5");
	sprintf(clu[39][4],  "#PATHEXEC");	
	sprintf(clu[39][5],  "#PAUSE 1");
	sprintf(clu[39][6],  "#PTQ 11 0.2 1.5");
	sprintf(clu[39][7],  "#PATHEXEC");
	sprintf(clu[39][8],  "#PAUSE 2");	
	sprintf(clu[39][9],  "#PTQ 41 0.2 1.5");
	sprintf(clu[39][10], "#PATHEXEC");	
	sprintf(clu[39][11], "#PAUSE 1");	
	sprintf(clu[39][12], "#PTQ 11 0.2 1.5");
	sprintf(clu[39][13], "#PATHEXEC");
	sprintf(clu[39][14], "#PAUSE 1.5");
	sprintf(clu[39][15], "#PTQ 51 0.2 9");
	sprintf(clu[39][16], "#PATHEXEC");		
	sprintf(clu[39][17], "#CLUEND");	
		
	
	/*----------------------------------------------*/
	/* CLU 40 INIT									*/
	/* BIG SPYRO 									*/
	/*                 "########################\0" */
	/*----------------------------------------------*/
	sprintf(clu[40][0], "#CAMERAON");	
	sprintf(clu[40][1], "#PTQ 13 0.2 1.5");
	sprintf(clu[40][2], "#PATHEXEC");	
	sprintf(clu[40][3], "#PTRAP +1620  0.2 28");
	sprintf(clu[40][4], "#TTRAP +120   0.2 28");	
	sprintf(clu[40][5], "#PATHEXEC");	
	sprintf(clu[40][6], "#CAMERAOFF");	
	sprintf(clu[40][7], "#CLUEND");	
	
	
	/*----------------------------------------------*/
	/* CLU 41 INIT									*/
	/* LITTLE SPYRO 								*/
	/*                 "########################\0" */
	/*----------------------------------------------*/
	sprintf(clu[41][0], "#CAMERAON");	
	sprintf(clu[41][1], "#PTQ 21 0.2 1.5");
	sprintf(clu[41][2], "#PATHEXEC");
	sprintf(clu[41][3], "#PAUSE 2");	
	sprintf(clu[41][4], "#PTRAP +360   0.2 10");
	sprintf(clu[41][5], "#TTRAP +100   0.2 10");	
	sprintf(clu[41][6], "#PATHEXEC");	
	sprintf(clu[41][7], "#CAMERAOFF");	
	sprintf(clu[41][8], "#CLUEND");		
	
	
	/*----------------------------------------------*/
	/* CLU 49 INIT									*/
	/* TEST											*/
	/*                 "########################\0" */
	/*----------------------------------------------*/	
	sprintf(clu[49][0], "#CAMERAON");	
	sprintf(clu[49][1], "#PTQ 11 0.2 2");	
	sprintf(clu[49][2], "#PATHEXEC");	
	sprintf(clu[49][3], "#PAUSE 1");
	sprintf(clu[49][4], "#PTQ 99 0.2 1");	
	sprintf(clu[49][5], "#PATHEXEC");	
	sprintf(clu[49][6], "#CAMERAOFF");	
	sprintf(clu[49][7], "#CLUEND");	
	
}


/********************************************************************************/
/* Constant CLU Sequence Initialization											*/
/********************************************************************************/
/*																				*/
/* clu_sequence[0..MAX_CLU_SEQUENCE_STEPS-1]									*/
/*																				*/
/* MAX_CLU_SEQUENCE_STEPS 	   100												*/
/********************************************************************************/
void InitCluSequence(void)
{
	clu_sequence[0]  = 11;
	clu_sequence[1]  = 30;
	clu_sequence[2]  = 4;
	clu_sequence[3]  = 5;
	clu_sequence[4]  = 41;
	clu_sequence[5]  = 11;
	clu_sequence[6]  = 6;
	clu_sequence[7]  = 11;
	clu_sequence[8]  = 31;
	clu_sequence[9]  = 11;
	clu_sequence[10] = 32;
	clu_sequence[11] = 11;
	clu_sequence[12] = 32;
	clu_sequence[13] = 11;	
	clu_sequence[14] = 35;
	clu_sequence[15] = 11;
	clu_sequence[16] = 36;
	clu_sequence[17] = 11;
	clu_sequence[18] = 32;
	clu_sequence[19] = 33;
	clu_sequence[20] = 34;
	clu_sequence[21] = 37;
	clu_sequence[22] = 37;
	clu_sequence[23] = 37;	
	clu_sequence[24] = 11;	
	clu_sequence[25] = 38;
	clu_sequence[26] = 39;
	clu_sequence[27] = 40;
	clu_sequence[28] = 40;	
	
	clu_sequence[29] = 0xFF;		//END
}

//Prints CLU number clu_number
void PrintClu(uint8 number)
{
	uint8 index;
	
	if (number < MAX_CLU_NUMBER)
	{
		for (index=0; index < MAX_CLU_STEPS ; index++)
	    {
			if (strlen(clu[number][index]) != 0)
			{
				printf("%s\r\n",clu[number][index]);
			}
	    }
		printf("\r\n");		
	}
}

//Prints CLU number at step index
void PrintCluStep(uint8 number, uint8 index)
{
	if (number < MAX_CLU_NUMBER)
	{
		if ((strlen(clu[number][index]) != 0) && (index < MAX_CLU_STEPS))
		{
			printf("%s\r\n",clu[number][index]);
		}
	}
}


//Clears all CLUs
void ClearAllClus(void)
{
	uint8 index;
	
	for (index=0; index < MAX_CLU_NUMBER ; index++)
	{
		sprintf(clu[index][0], "#CLUEND");
	}
}


//Checks Empty or not Empty Clu
uint8 isCluEmpty(uint8 clu_number)
{
	if (strcmp(clu[clu_number][0], "#CLUEND") == 0)	
		return CLU_IS_EMPTY;
	else
		return CLU_IS_NOT_EMPTY;
}



/* [] END OF FILE */
