/* ==============================================
 *                                              *
 * GyroSens Console Interface header file	    *
 *												*
 * Copyright 2012-2013 Logic brainstorm         *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICHx IS THE PROPERTY OF Logic brainstorm	*
 * ==============================================
*/

// Descrizione: raccolta di funzioni di gestione della Console

// tipo di dato command
struct command
	{
		char action[15];
		char parameter[15];
		char number1[10];
		char number2[5];
	};
	

// ReadInputBuffer													//
// Legge l'UART USB in ingresso e popola il buffer					//
// userInputBuffer sino alla ricezione i un carattere di fine linea	//
// Ritorna codici:													//
// 0 = READ_OK				--> ok									//
// 1 = READ_TIMEOUT 		--> timeout (SW)						//
// 2 = READ_BUFF_OVERFLOW 	--> Buffer Overflow						//
uint8 ReadInputBuffer(bit echo, bit timeout);

// Board PIN Define
#define BOARD_PIN			"147583"

// echo parameter define
#define ECHO_ON				1
#define ECHO_OFF			0

// timeout parameter define
#define TIMEOUT_ON			1
#define TIMEOUT_OFF			0

// exit codes defines
#define READ_OK 				0
#define READ_TIMEOUT 			1
#define READ_BUFF_OVERFLOW		2


//TIMEOUT define (internal)
#define TIMEOUT_TICKS		50000	//SW ticks (time depends from computation


// Buffer Scanner
uint8 scanner(bit verbose);


// verbose parameter define
#define VERBOSE_ON			1
#define VERBOSE_OFF			0


// Token Parser
// command =
//			[action
//			|action parameter
//			|action parameter number1
//			|action parameter number1 number2
//			].
//
// action    = ("?"|"DISABLE"|"ENABLE"|"GOTO"|"SET"|"SHOW"|"STOP"|"V").
//
// parameter = ("ALL|"CANADD"|"COMMANDS"|"CURRENT"|"CURRENTS"|"FC"|"HOME"|"MOTOR"|
//				"RELPOSITIONS"|"RP"|"SPEED"|"STATUS"|"TARGET"|"UNICODE"|
//				"VERSION"|"VCC").
//
// number1	 = ([1-8]|[0-10000 step]|[0.0mm 20.0mm]|[0-100 step/s]|[0 - 10.0 mm/s]|
//			    0-2400 [mA])
//
// number2   = future expansion token
uint8 parser();


// Verify Button Pressed
uint8 AnyButtonPressed(void);
#define NO_PRESSED 0
#define PRESSED    1

/* Verify [Y/N] choice */
uint8 ButtonYNChoice(bit echo);
#define _YES				1
#define _NO					0

// internal functions
void clear_string(char *str);


// Checks status of local USB insertion //
uint8 USB_Check(void);
#define USB_NOT_INSERTED 0
#define USB_INSERTED	 1

/* Get Anapos Offset value to zero Oscilloscope									*/
/*   returns: (int32)anapos_offset  correct value to zero oscilloscope output	*/
int32 GetAnaposOffsetZero(void);


//[] END OF FILE
