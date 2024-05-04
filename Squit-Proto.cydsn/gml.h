/* ==============================================
 *                                              *
 * Gobee Director GML Interpreter header file	*
 *												*
 * Copyright 2017 Gobee Srl						*
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICHx IS THE PROPERTY OF Logic brainstorm	*
 * ==============================================
*/

// Descrizione: raccolta di funzioni di gestione dell'interprete GML


// tipo di dato GML_COMMANDLINE
struct GML_COMMANDLINE
	{
		char action[15];
		char parameter1[10];
		char parameter2[10];
		char parameter3[10];
	};
	
// ****************************************************************
// *** CLU EXECUTOR FUNCTION								    ***
// ****************************************************************
// *** to call inside isr										***
// ****************************************************************
void clu_sm_exec(uint8 verbose);

// CLU state machine initialization
void clu_sm_init(void);

// CLU START (LAUNCH) FUNCTION
//to call inside console or an internal process
// clu_num = clu to start
void clu_sm_start(uint8 clu_num);


// ****************************************************************
// *** Legge la CLU clu_number alla linea clu_step				***
// *** e popola il buffer CluBuffer 							***
// ****************************************************************
// *** restituisce CLU_IS_ENDED alla fine della CLU				***
// ****************************************************************
uint8 ReadCLUbuffer(uint8 clu_number, uint8 clu_step);

// Buffer Scanner
void gml_scanner(uint8 verbose);

// GML Token Parser
uint8 gml_parser(uint8 verbose);

// GML Implementation consts
#define GML_SAMPLING_RATE		100		// [Hz]
#define PANPATH					0		// PAN  path number
#define TILTPATH				1		// TILT path number

// exit codes defines
#define READ_OK 				0
#define READ_BUFF_OVERFLOW		2

// verbose parameter define
#define VERBOSE_ON			1
#define VERBOSE_OFF			0

// clu line buffer status defines
#define CLU_IS_NOT_ENDED	0
#define CLU_IS_ENDED		1

// clu state machines defines
#define CLUSM_NOP				0
#define CLUSM_START				1
#define CLUSM_LINE_EXECUTING	2
#define CLUSM_PAUSE_EXECUTION	3		//execution of clu PAUSE command
#define CLUSM_PGOTO_EXECUTION	4		//execution of clu PAN GOTO command
#define CLUSM_TGOTO_EXECUTION	5		//execution of clu TILT GOTO command
#define CLUSM_PATH_EXECUTION	6		//execution of clu PAN+TILT PATH Mover
#define CLUSM_LINE_EXECUTED		10
#define CLUSM_STOP				11
#define CLUSM_END				12

// clu constants
#define CLU_PAUSE_MAX			60		// [sec]

// internal functions
void clear_gml_string(char *str);

//[] END OF FILE
