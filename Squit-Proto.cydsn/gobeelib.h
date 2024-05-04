/* ==============================================
 *                                              *
 * GyroSens Library header file                 *
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

// Descrizione: raccolta di funzioni di utilità varia.
//              Sono suddivise nei seguenti gruppi:
//			    - Byte Access
//              - Matematiche
//				- Led Control
//              - Standard Output
//				- Accesso EEPROM


// ****************************
// *** Funzioni Byte Access ***
// ****************************

// Byte Access for Read Only Operations
#define LOWBYTE(v)   ((unsigned char) (v))
#define HIGHBYTE(v)  ((unsigned char) (((unsigned int) (v)) >> 8))


// Byte Access for Read/Write Operations
#define BYTELOW(v)   (*(((char8 *) (&v) + 1)))
#define BYTEHIGH(v)  (*((char8 *) (&v)))


// ****************************
// *** Funzioni Matematiche ***
// ****************************

/* Compensation Filter: Tau calculus										*/
/*																			*/
/* 0 <= alpha <= 1															*/
/* --> Tau is expressed in msec												*/
uint16 CFtau(float alpha);


/* Low Pass Filter: Tau calculus											*/
/*																			*/
/* 0 <= beta <= 1															*/
/* deltaT_sec [sec]															*/
/* REM: Tau is returned in msec												*/
float LPFtau(float beta, float deltaT_sec);


/* Exponential error smoothing function: Freq calculus						*/
/* (exactly like RC first order low pass filter) 							*/
/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
/*																			*/
/* REM: freq is expressed in Hz												*/
float LPFfreq(float alpha, float deltaT_sec);


/* Floating point square function	*/
float squaref(float x);


/* Floating point signum         */
/* returns +1.0 if fvalue >= 0.0 */
/* returns -1.0 if fvalue <  0.0 */
float fsgn(float fvalue);


/* Integer signum                */
/* returns +1 if ivalue >= 0     */
/* returns -1 if ivalue <  0     */
int   isgn(int ivalue);


// *************************************************************
// *** Funzioni "grafiche"	di console						 ***
// *************************************************************

// Cancella la console (CLS) e rimette il cursore a Home
void clshome_console(void);

// stampa un numero spaces_number di spazi
void printf_spc(int spaces_number);

// stampa un istogramma della variabile value rispetto ad un valore massimo max_value
// che corrisponderà a max_stars asterischi
// L'istogramma stampato è funzione lineare di abs(value)
// legenda è il puntatore ad una stringa che viene stampata prima del bargraph
void print_abs_linear_hystogram(int16 value, uint16 max_value, uint8 max_stars, char *legenda);

// stampa il bordo superiore o inferiore dell'istogramma lungo max_stars asterischi e con legenda
void print_hystogram_border(uint8 max_stars, char *legenda);

// stampa scherzo
void print_joke(void);

// ********************************
// *** Funzioni Standard Output ***
// ********************************

#if PSOC3_ARCH
/* Keil putchar override function */
/* To use Keil's IO functions such as printf,                 */
/* the program must override Keil's built-in putchar function.*/ 
/* This function overrides over USB/ANYBUS UART				  */
char putchar(char c);
#endif


// ******************************************
// *** Funzioni di interfaccia con EEPROM ***
// ******************************************

// Reads 1 byte from EEPROM			  	 	//
// 0 <= EEPROMAddress <= 2047 (2kbyte)   	//
uint8 EEPROM_ReadByte(uint16 EEPROMAddress);

// Writes 16byte buffer (1 row) starting from EEPROM RowAddress 	// 
// sourceData <-- pointer to 16 bytes array to write				//
// 0 <= RowAddress <= 127											//
uint8 EEPROM_WriteBuffer(uint8 RowAddress, uint8* sourceData);

// Reads All CYSENS Parameters from EEPROM and populate cys_param structure //
void ReadAllEEparams(void);

// Writes ALL CYSENS Parameters (cys_param structure) to EEPROM 	//
// returns:															//
// 			CYRET_SUCCESS											//
uint8 WriteAllEEparams(void);

/********************************************************************/
/* Writes Q Parameters (QELEMENT structure) to EEPROM				*/
/* returns:															*/
/* 			CYRET_SUCCESS											*/
/*			CYRET_BAD_PARAM (memory_number >= MAX_Q_MEMORIES)		*/
/********************************************************************/
uint8 WriteQEEparams(int8 memory_number);

/********************************************************************/
/* Read All Q Parameters (QELEMENT structure array) from EEPROM		*/
/********************************************************************/
void ReadAllQEEparams(void);


// *************************************************************
// *** Funzioni di abilitazione e disabilitazione (sleep) HW ***
// *************************************************************

void EnableSleepedHW(void);

void SleepHW(void);

//[] END OF FILE
