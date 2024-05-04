/* ==============================================
 *                                              *
 * Gobee Director Utility Library functions	    *
 *												*
 * Copyright 2012-2013 Logic brainstorm         *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH  IS THE PROPERTY OF Logic brainstorm	*
 * ==============================================
*/

/* Include files */
#include <device.h>
#include <stdio.h>
#include <gobee.h>
#include <gobeelib.h>
#include <console.h>
#include <systrings.h>
#include <mover.h>

/* External Global Wars */
extern uint8 ledmask;
extern uint8 signalmask;
extern uint8 sleep_status;
extern uint8 std_input;				/* Standard Communication Input  */
extern uint8 std_output;			/* Standard Communication Output */

extern struct GOBEE_PARAMS gobee_param;

/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 			/* PAN  Motor Axis Parameters & RT Datas	*/
extern struct MOTOR_AXIS tilt_axis; 		/* TILT Motor Axis Parameters & RT Datas	*/

/* External Absolute Position Sensor */
extern struct ABSPOS_SENSOR	pan_absolute_sensor;	/* PAN  Absolute Position Sensor Parameters & RT Datas */
extern struct ABSPOS_SENSOR	tilt_absolute_sensor;	/* TILT Absolute Position Sensor Parameters & RT Datas */

/* extern IMU sensor vars */
extern struct IMU_SENSOR	IMU_sensor;		/* Struttura dei dati della IMU */

/* external Q elements (shots) ARRAY	*/
extern struct QELEMENT q[MAX_Q_MEMORIES_SAFE];

/* external [Q number --> Q memory index] table for fast indexing */
extern uint8 q_table[MAX_Q_NUMBER_SAFE];


extern uint8 EEreadBuffer[18];
extern uint8 EEwriteBuffer[18];


// ****************************
// *** Funzioni Matematiche ***
// ****************************

/* Compensation Filter: Tau calculus										*/
/*																			*/
/* 0 <= alpha <= 1															*/
/* REM: Tau is expressed in msec											*/
uint16 CFtau(float alpha)
{
	float deltaT;
	
	deltaT = DeltaT_const;
	deltaT = deltaT * 1000;
	return (uint16)(deltaT * alpha / (1-alpha));
}


/* Low Pass Filter: Tau calculus											*/
/*																			*/
/* 0 <= beta <= 1															*/
/* deltaT_sec [sec]															*/
/* REM: Tau is returned in msec												*/
float LPFtau(float beta, float deltaT_sec)
{
	float deltaT = deltaT_sec;
	
	deltaT = deltaT * 1000;
	return (deltaT * (1-beta) / beta);
}

/* Exponential error smoothing function: Freq calculus						*/
/* (exactly like RC first order low pass filter) 							*/
/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
/*																			*/
/* REM: freq is expressed in Hz												*/
float LPFfreq(float alpha, float deltaT_sec)
{
	float freq;
	
	freq = 1000/(6.2831 * LPFtau(alpha, deltaT_sec));
	return (freq);
}


/* Floating point square function	*/
float squaref(float x)
{
    return(x*x);
}


/* Floating point signum         */
/* returns +1.0 if fvalue >= 0.0 */
/* returns -1.0 if fvalue <  0.0 */
//float fsgn(float fvalue)
//{
//if (fvalue >= 0.0) return +1.0;
//if (fvalue <  0.0) return -1.0;
//}


/* Integer signum                */
/* returns +1 if ivalue >= 0     */
/* returns -1 if ivalue < 0      */
//int   isgn(int ivalue)
//{
//if (ivalue >= 0) return +1;
//if (ivalue <  0) return -1;
//}


// *********************************************************
// *** Funzioni salvataggio parametri macchina in EEPROM ***
// *********************************************************

// Writes ALL CYSENS Parameters (cys_param structure) to EEPROM 	//
// returns:															//
// 			CYRET_SUCCESS											//
uint8 WriteAllEEparams(void)
{
	uint8 idx;
	uint8 dummy __attribute__ ((unused));
	// Aggiungere controllo con codice di uscita!

	// Clears EEPROM Write Buffer
	for (idx=0; idx<=16; idx++)
	{
		EEwriteBuffer[idx]=0;
	}
	
	// Writes main parameters on EEPROM Row 0 - [EEPROM Add=0..15]
	EEwriteBuffer[0] = 0;
	EEwriteBuffer[1] = pan_axis.param.polarity;
	EEwriteBuffer[2] = gobee_param.x_acc_ADC_offset;	
	EEwriteBuffer[3] = gobee_param.y_acc_ADC_offset;
	EEwriteBuffer[4] = gobee_param.y_acc_ADC_offset;	
	EEwriteBuffer[5] = gobee_param.director;
	EEwriteBuffer[6] = 0;	
	
	EEwriteBuffer[7]  = gobee_param.jump_g_threshold.fbyte[0];		//
	EEwriteBuffer[8]  = gobee_param.jump_g_threshold.fbyte[1];		//
	EEwriteBuffer[9]  = gobee_param.jump_g_threshold.fbyte[2];		//
	EEwriteBuffer[10] = gobee_param.jump_g_threshold.fbyte[3];		//float number saving
	
	EEwriteBuffer[11] = tilt_axis.param.polarity;	
	EEwriteBuffer[12] = gobee_param.mode;	
	EEwriteBuffer[13] = 0;
	EEwriteBuffer[14] = 0;
	EEwriteBuffer[15] = 0;
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 0);	

	
	// Writes main parameters on EEPROM Row 1 - [EEPROM Add=16..31]	
	EEwriteBuffer[0] = IMU_sensor.param.yaw_invertion;
	EEwriteBuffer[1] = IMU_sensor.param.pitch_invertion;
	EEwriteBuffer[2] = IMU_sensor.param.roll_invertion;
	EEwriteBuffer[3] = IMU_sensor.param.pitch_roll_exchange;
	
	EEwriteBuffer[4] = gobee_param.acc_g_threshold.fbyte[0];		//
	EEwriteBuffer[5] = gobee_param.acc_g_threshold.fbyte[1];		//
	EEwriteBuffer[6] = gobee_param.acc_g_threshold.fbyte[2];		//
	EEwriteBuffer[7] = gobee_param.acc_g_threshold.fbyte[3];		//float number saving

	EEwriteBuffer[8]  = IMU_sensor.param.gamma.fbyte[0];	//
	EEwriteBuffer[9]  = IMU_sensor.param.gamma.fbyte[1];	//
	EEwriteBuffer[10] = IMU_sensor.param.gamma.fbyte[2];	//
	EEwriteBuffer[11] = IMU_sensor.param.gamma.fbyte[3];	//float number saving	

	EEwriteBuffer[12] = gobee_param.beta.fbyte[0];	//
	EEwriteBuffer[13] = gobee_param.beta.fbyte[1];	//
	EEwriteBuffer[14] = gobee_param.beta.fbyte[2];	//
	EEwriteBuffer[15] = gobee_param.beta.fbyte[3];	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 1);

	
	// Writes parameters on EEPROM Row 2 - [EEPROM Add=32..47]
	EEwriteBuffer[0] = 0;		//
	EEwriteBuffer[1] = 0;		//
	EEwriteBuffer[2] = 0;		//
	EEwriteBuffer[3] = 0;		//float number saving

	EEwriteBuffer[4] = 0;	//
	EEwriteBuffer[5] = 0;	//
	EEwriteBuffer[6] = 0;	//
	EEwriteBuffer[7] = 0;	//float number saving

	EEwriteBuffer[8] = 0;	//
	EEwriteBuffer[9] = 0;	//
	EEwriteBuffer[10] = 0;	//
	EEwriteBuffer[11] = 0;	//float number saving
	
	EEwriteBuffer[12] = 0;	//
	EEwriteBuffer[13] = 0;	//
	EEwriteBuffer[14] = 0;	//
	EEwriteBuffer[15] = 0;	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 2);	

	
	// Writes parameters on EEPROM Row 3 - [EEPROM Add=48..63]
	EEwriteBuffer[0] = pan_axis.param.Kpf.fbyte[0];		//
	EEwriteBuffer[1] = pan_axis.param.Kpf.fbyte[1];		//
	EEwriteBuffer[2] = pan_axis.param.Kpf.fbyte[2];		//
	EEwriteBuffer[3] = pan_axis.param.Kpf.fbyte[3];		//float number saving

	EEwriteBuffer[4] = pan_axis.param.Kdf.fbyte[0];		//
	EEwriteBuffer[5] = pan_axis.param.Kdf.fbyte[1];		//
	EEwriteBuffer[6] = pan_axis.param.Kdf.fbyte[2];		//
	EEwriteBuffer[7] = pan_axis.param.Kdf.fbyte[3];		//float number saving

	EEwriteBuffer[8]  = pan_axis.param.Kif.fbyte[0];	//
	EEwriteBuffer[9]  = pan_axis.param.Kif.fbyte[1];	//
	EEwriteBuffer[10] = pan_axis.param.Kif.fbyte[2];	//
	EEwriteBuffer[11] = pan_axis.param.Kif.fbyte[3];	//float number saving
	
	EEwriteBuffer[12] = pan_axis.param.Ksif.fbyte[0];	//
	EEwriteBuffer[13] = pan_axis.param.Ksif.fbyte[1];	//
	EEwriteBuffer[14] = pan_axis.param.Ksif.fbyte[2];	//
	EEwriteBuffer[15] = pan_axis.param.Ksif.fbyte[3];	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 3);

	
	// Writes parameters on EEPROM Row 4 - [EEPROM Add=64..79]
	EEwriteBuffer[0] = pan_axis.param.Kopf.fbyte[0];		//
	EEwriteBuffer[1] = pan_axis.param.Kopf.fbyte[1];		//
	EEwriteBuffer[2] = pan_axis.param.Kopf.fbyte[2];		//
	EEwriteBuffer[3] = pan_axis.param.Kopf.fbyte[3];		//float number saving

	EEwriteBuffer[4] = pan_axis.param.Gain_ANAOUT.fbyte[0];		//
	EEwriteBuffer[5] = pan_axis.param.Gain_ANAOUT.fbyte[1];		//
	EEwriteBuffer[6] = pan_axis.param.Gain_ANAOUT.fbyte[2];		//
	EEwriteBuffer[7] = pan_axis.param.Gain_ANAOUT.fbyte[3];		//float number saving	

	EEwriteBuffer[8] = pan_axis.param.color;
	EEwriteBuffer[9] = 0;
	EEwriteBuffer[10] = 0;
	EEwriteBuffer[11] = 0;
	
	EEwriteBuffer[12] = 0;	//
	EEwriteBuffer[13] = 0;	//
	EEwriteBuffer[14] = 0;	//
	EEwriteBuffer[15] = 0;	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 4);	
	
	
	// Writes main parameters on EEPROM Row 5 - [EEPROM Add=80..95]
	EEwriteBuffer[0] = tilt_axis.param.Kpf.fbyte[0];		//
	EEwriteBuffer[1] = tilt_axis.param.Kpf.fbyte[1];		//
	EEwriteBuffer[2] = tilt_axis.param.Kpf.fbyte[2];		//
	EEwriteBuffer[3] = tilt_axis.param.Kpf.fbyte[3];		//float number saving

	EEwriteBuffer[4] = tilt_axis.param.Kdf.fbyte[0];		//
	EEwriteBuffer[5] = tilt_axis.param.Kdf.fbyte[1];		//
	EEwriteBuffer[6] = tilt_axis.param.Kdf.fbyte[2];		//
	EEwriteBuffer[7] = tilt_axis.param.Kdf.fbyte[3];		//float number saving

	EEwriteBuffer[8]  = tilt_axis.param.Kif.fbyte[0];	//
	EEwriteBuffer[9]  = tilt_axis.param.Kif.fbyte[1];	//
	EEwriteBuffer[10] = tilt_axis.param.Kif.fbyte[2];	//
	EEwriteBuffer[11] = tilt_axis.param.Kif.fbyte[3];	//float number saving
	
	EEwriteBuffer[12] = tilt_axis.param.Ksif.fbyte[0];	//
	EEwriteBuffer[13] = tilt_axis.param.Ksif.fbyte[1];	//
	EEwriteBuffer[14] = tilt_axis.param.Ksif.fbyte[2];	//
	EEwriteBuffer[15] = tilt_axis.param.Ksif.fbyte[3];	//float number saving		
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 5);	
	

	// Writes parameters on EEPROM Row 6 - [EEPROM Add=96..111]
	EEwriteBuffer[0] = tilt_axis.param.Kopf.fbyte[0];		//
	EEwriteBuffer[1] = tilt_axis.param.Kopf.fbyte[1];		//
	EEwriteBuffer[2] = tilt_axis.param.Kopf.fbyte[2];		//
	EEwriteBuffer[3] = tilt_axis.param.Kopf.fbyte[3];		//float number saving

	EEwriteBuffer[4] = tilt_axis.param.Gain_ANAOUT.fbyte[0];		//
	EEwriteBuffer[5] = tilt_axis.param.Gain_ANAOUT.fbyte[1];		//
	EEwriteBuffer[6] = tilt_axis.param.Gain_ANAOUT.fbyte[2];		//
	EEwriteBuffer[7] = tilt_axis.param.Gain_ANAOUT.fbyte[3];		//float number saving	

	EEwriteBuffer[8] = tilt_axis.param.color;
	EEwriteBuffer[9] = 0;
	EEwriteBuffer[10] = 0;
	EEwriteBuffer[11] = 0;
	
	EEwriteBuffer[12] = 0;	//
	EEwriteBuffer[13] = 0;	//
	EEwriteBuffer[14] = 0;	//
	EEwriteBuffer[15] = 0;	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 6);
	
	
	// Writes main parameters on EEPROM Row 7 - [EEPROM Add=112..127]
	EEwriteBuffer[0]  = pan_absolute_sensor.param.raw_invertion;
	EEwriteBuffer[1]  = pan_axis.param.limit_control;
	
	EEwriteBuffer[2]  = BYTEHIGH(pan_absolute_sensor.param.raw_home);	
	EEwriteBuffer[3]  = BYTELOW(pan_absolute_sensor.param.raw_home);

	EEwriteBuffer[4]  = BYTEHIGH(pan_absolute_sensor.param.raw_limit_max);	
	EEwriteBuffer[5]  = BYTELOW(pan_absolute_sensor.param.raw_limit_max);	
	
	EEwriteBuffer[6]  = BYTEHIGH(pan_absolute_sensor.param.raw_limit_min);	
	EEwriteBuffer[7]  = BYTELOW(pan_absolute_sensor.param.raw_limit_min);
	
	EEwriteBuffer[8]  = BYTEHIGH(pan_absolute_sensor.param.raw_limit_hysteresis);	
	EEwriteBuffer[9]  = BYTELOW(pan_absolute_sensor.param.raw_limit_hysteresis);
	
	EEwriteBuffer[10] = 0;	
	EEwriteBuffer[11] = 0;
	
	EEwriteBuffer[12] = pan_absolute_sensor.param.step_over_abs_ratio.fbyte[0];	//
	EEwriteBuffer[13] = pan_absolute_sensor.param.step_over_abs_ratio.fbyte[1];	//
	EEwriteBuffer[14] = pan_absolute_sensor.param.step_over_abs_ratio.fbyte[2];	//
	EEwriteBuffer[15] = pan_absolute_sensor.param.step_over_abs_ratio.fbyte[3];	//float number saving	
	
	dummy = EEPROM_Write(&EEwriteBuffer[0], 7);
	
	
	// Writes main parameters on EEPROM Row 8 - [EEPROM Add=128..143]
	EEwriteBuffer[0]  = tilt_absolute_sensor.param.raw_invertion;
	EEwriteBuffer[1]  = tilt_axis.param.limit_control;
	
	EEwriteBuffer[2]  = BYTEHIGH(tilt_absolute_sensor.param.raw_home);	
	EEwriteBuffer[3]  = BYTELOW(tilt_absolute_sensor.param.raw_home);

	EEwriteBuffer[4]  = BYTEHIGH(tilt_absolute_sensor.param.raw_limit_max);	
	EEwriteBuffer[5]  = BYTELOW(tilt_absolute_sensor.param.raw_limit_max);	
	
	EEwriteBuffer[6]  = BYTEHIGH(tilt_absolute_sensor.param.raw_limit_min);	
	EEwriteBuffer[7]  = BYTELOW(tilt_absolute_sensor.param.raw_limit_min);
	
	EEwriteBuffer[8]  = BYTEHIGH(tilt_absolute_sensor.param.raw_limit_hysteresis);	
	EEwriteBuffer[9]  = BYTELOW(tilt_absolute_sensor.param.raw_limit_hysteresis);
	
	EEwriteBuffer[10] = 0;	
	EEwriteBuffer[11] = 0;
	
	EEwriteBuffer[12] = tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[0];	//
	EEwriteBuffer[13] = tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[1];	//
	EEwriteBuffer[14] = tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[2];	//
	EEwriteBuffer[15] = tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[3];	//float number saving	
		
	dummy = EEPROM_Write(&EEwriteBuffer[0], 8);		
	
	//rows 32 to 52 reserved for Q parameters
	
	return(CYRET_SUCCESS);
}


/********************************************************************/
/* Writes Q Parameters (QELEMENT structure) to EEPROM				*/
/* returns:															*/
/* 			CYRET_SUCCESS											*/
/*			CYRET_BAD_PARAM (memory_number >= MAX_Q_MEMORIES)		*/
/********************************************************************/
uint8 WriteQEEparams(int8 memory_number)
{
	uint8 idx;
	uint8 dummy __attribute__ ((unused));

	// Clears EEPROM Write Buffer
	for (idx=0; idx<=16; idx++)
	{
		EEwriteBuffer[idx]=0;
	}
	
	if (memory_number <= Q_MEMORY_NUMBER_MAX)		//20 rows max (from row 32 to row 52)
	{
		// Writes Q parameters on EEPROM Row 32 + memory_number  [EEPROM Add=512..832]
		EEwriteBuffer[0] = q[memory_number].param.position_default[PAN_AXIS].fbyte[0];	//
		EEwriteBuffer[1] = q[memory_number].param.position_default[PAN_AXIS].fbyte[1];	//
		EEwriteBuffer[2] = q[memory_number].param.position_default[PAN_AXIS].fbyte[2];	//
		EEwriteBuffer[3] = q[memory_number].param.position_default[PAN_AXIS].fbyte[3];	//float number saving	
		
		EEwriteBuffer[4] = q[memory_number].param.position_default[TILT_AXIS].fbyte[0];	//
		EEwriteBuffer[5] = q[memory_number].param.position_default[TILT_AXIS].fbyte[1];	//
		EEwriteBuffer[6] = q[memory_number].param.position_default[TILT_AXIS].fbyte[2];	//
		EEwriteBuffer[7] = q[memory_number].param.position_default[TILT_AXIS].fbyte[3];	//float number saving	
		
		EEwriteBuffer[8]  = BYTEHIGH(q[memory_number].param.position_adjust[PAN_AXIS]);	
		EEwriteBuffer[9]  = BYTELOW(q[memory_number].param.position_adjust[PAN_AXIS]);

		EEwriteBuffer[10] = BYTEHIGH(q[memory_number].param.position_adjust[TILT_AXIS]);	
		EEwriteBuffer[11] = BYTELOW(q[memory_number].param.position_adjust[TILT_AXIS]);
		
		EEwriteBuffer[12] = q[memory_number].number;
		EEwriteBuffer[13] = q[memory_number].mode;
		
		EEwriteBuffer[14] = 0;
		EEwriteBuffer[15] = 0;		
			
		dummy = EEPROM_Write(&EEwriteBuffer[0], 32 + memory_number);		
		
		return(CYRET_SUCCESS);
	}
	else
	{
		return(CYRET_BAD_PARAM);
	}
}


void ReadAllEEparams(void)
{
	uint8 idx;
	
	// Clear EEPROM Read Buffer
	for (idx=0; idx<=16; idx++)
	{
		EEreadBuffer[idx]=0;
	}
	
	// Reads main parameters from EEPROM Row 0 - [EEPROM Add=0..15]
	//0
	pan_axis.param.polarity 		= EEPROM_ReadByte(1);	
	gobee_param.x_acc_ADC_offset 	= EEPROM_ReadByte(2);
	gobee_param.y_acc_ADC_offset  	= EEPROM_ReadByte(3);
	gobee_param.z_acc_ADC_offset  	= EEPROM_ReadByte(4);
	gobee_param.director      		= EEPROM_ReadByte(5);
	//6
	
	gobee_param.jump_g_threshold.fbyte[0] = EEPROM_ReadByte(7);		//
	gobee_param.jump_g_threshold.fbyte[1] = EEPROM_ReadByte(8);		//
	gobee_param.jump_g_threshold.fbyte[2] = EEPROM_ReadByte(9);		//
	gobee_param.jump_g_threshold.fbyte[3] = EEPROM_ReadByte(10);	//float number loading
	
	tilt_axis.param.polarity 		= EEPROM_ReadByte(11);		
	gobee_param.mode 				= EEPROM_ReadByte(12);		
	
	
	// Reads main parameters from EEPROM Row 1 - [EEPROM Add=16..31]
	
	IMU_sensor.param.yaw_invertion 		 = EEPROM_ReadByte(16);
	IMU_sensor.param.pitch_invertion 	 = EEPROM_ReadByte(17);
	IMU_sensor.param.roll_invertion 	 = EEPROM_ReadByte(18);
	IMU_sensor.param.pitch_roll_exchange = EEPROM_ReadByte(19);
	
	gobee_param.acc_g_threshold.fbyte[0] = EEPROM_ReadByte(20);		//
	gobee_param.acc_g_threshold.fbyte[1] = EEPROM_ReadByte(21);		//
	gobee_param.acc_g_threshold.fbyte[2] = EEPROM_ReadByte(22);		//
	gobee_param.acc_g_threshold.fbyte[3] = EEPROM_ReadByte(23);		//float number loading
	
	IMU_sensor.param.gamma.fbyte[0] = EEPROM_ReadByte(24);	//
	IMU_sensor.param.gamma.fbyte[1] = EEPROM_ReadByte(25);	//
	IMU_sensor.param.gamma.fbyte[2] = EEPROM_ReadByte(26);	//
	IMU_sensor.param.gamma.fbyte[3] = EEPROM_ReadByte(27);	//float number loading	
	
	gobee_param.beta.fbyte[0] = EEPROM_ReadByte(28);	//
	gobee_param.beta.fbyte[1] = EEPROM_ReadByte(29);	//
	gobee_param.beta.fbyte[2] = EEPROM_ReadByte(30);	//
	gobee_param.beta.fbyte[3] = EEPROM_ReadByte(31);	//float number loading
	
	
	// Reads Parameters from EEPROM Row 2 - [EEPROM Add=32-47]
	//NONE

	
	// Reads Parameters from EEPROM Row 3 - [EEPROM Add=48-63]
	pan_axis.param.Kpf.fbyte[0] = EEPROM_ReadByte(48);	//
	pan_axis.param.Kpf.fbyte[1] = EEPROM_ReadByte(49);	//
	pan_axis.param.Kpf.fbyte[2] = EEPROM_ReadByte(50);	//
	pan_axis.param.Kpf.fbyte[3] = EEPROM_ReadByte(51);	//float number loading		

	pan_axis.param.Kdf.fbyte[0] = EEPROM_ReadByte(52);	//
	pan_axis.param.Kdf.fbyte[1] = EEPROM_ReadByte(53);	//
	pan_axis.param.Kdf.fbyte[2] = EEPROM_ReadByte(54);	//
	pan_axis.param.Kdf.fbyte[3] = EEPROM_ReadByte(55);	//float number loading	

	pan_axis.param.Kif.fbyte[0] = EEPROM_ReadByte(56);	//
	pan_axis.param.Kif.fbyte[1] = EEPROM_ReadByte(57);	//
	pan_axis.param.Kif.fbyte[2] = EEPROM_ReadByte(58);	//
	pan_axis.param.Kif.fbyte[3] = EEPROM_ReadByte(59);	//float number loading	

	pan_axis.param.Ksif.fbyte[0] = EEPROM_ReadByte(60);	//
	pan_axis.param.Ksif.fbyte[1] = EEPROM_ReadByte(61);	//
	pan_axis.param.Ksif.fbyte[2] = EEPROM_ReadByte(62);	//
	pan_axis.param.Ksif.fbyte[3] = EEPROM_ReadByte(63);	//float number loading	
	
	
	// Reads Parameters from EEPROM Row 4 - [EEPROM Add=64-79]
	pan_axis.param.Kopf.fbyte[0] = EEPROM_ReadByte(64);	//
	pan_axis.param.Kopf.fbyte[1] = EEPROM_ReadByte(65);	//
	pan_axis.param.Kopf.fbyte[2] = EEPROM_ReadByte(66);	//
	pan_axis.param.Kopf.fbyte[3] = EEPROM_ReadByte(67);	//float number loading	
	
	pan_axis.param.Gain_ANAOUT.fbyte[0] = EEPROM_ReadByte(68);	//
	pan_axis.param.Gain_ANAOUT.fbyte[1] = EEPROM_ReadByte(69);	//
	pan_axis.param.Gain_ANAOUT.fbyte[2] = EEPROM_ReadByte(70);	//
	pan_axis.param.Gain_ANAOUT.fbyte[3] = EEPROM_ReadByte(71);	//float number loading	
	
	pan_axis.param.color = EEPROM_ReadByte(72);	

	
	// Reads Parameters from EEPROM Row 5 - [EEPROM Add=80-95]
	tilt_axis.param.Kpf.fbyte[0] = EEPROM_ReadByte(80);	//
	tilt_axis.param.Kpf.fbyte[1] = EEPROM_ReadByte(81);	//
	tilt_axis.param.Kpf.fbyte[2] = EEPROM_ReadByte(82);	//
	tilt_axis.param.Kpf.fbyte[3] = EEPROM_ReadByte(83);	//float number loading		

	tilt_axis.param.Kdf.fbyte[0] = EEPROM_ReadByte(84);	//
	tilt_axis.param.Kdf.fbyte[1] = EEPROM_ReadByte(85);	//
	tilt_axis.param.Kdf.fbyte[2] = EEPROM_ReadByte(86);	//
	tilt_axis.param.Kdf.fbyte[3] = EEPROM_ReadByte(87);	//float number loading	

	tilt_axis.param.Kif.fbyte[0] = EEPROM_ReadByte(88);	//
	tilt_axis.param.Kif.fbyte[1] = EEPROM_ReadByte(89);	//
	tilt_axis.param.Kif.fbyte[2] = EEPROM_ReadByte(90);	//
	tilt_axis.param.Kif.fbyte[3] = EEPROM_ReadByte(91);	//float number loading	

	tilt_axis.param.Ksif.fbyte[0] = EEPROM_ReadByte(92);	//
	tilt_axis.param.Ksif.fbyte[1] = EEPROM_ReadByte(93);	//
	tilt_axis.param.Ksif.fbyte[2] = EEPROM_ReadByte(94);	//
	tilt_axis.param.Ksif.fbyte[3] = EEPROM_ReadByte(95);	//float number loading	
	
	
	// Reads Parameters from EEPROM Row 6 - [EEPROM Add=96-111]
	tilt_axis.param.Kopf.fbyte[0] = EEPROM_ReadByte(96);	//
	tilt_axis.param.Kopf.fbyte[1] = EEPROM_ReadByte(97);	//
	tilt_axis.param.Kopf.fbyte[2] = EEPROM_ReadByte(98);	//
	tilt_axis.param.Kopf.fbyte[3] = EEPROM_ReadByte(99);	//float number loading	
	
	tilt_axis.param.Gain_ANAOUT.fbyte[0] = EEPROM_ReadByte(100);	//
	tilt_axis.param.Gain_ANAOUT.fbyte[1] = EEPROM_ReadByte(101);	//
	tilt_axis.param.Gain_ANAOUT.fbyte[2] = EEPROM_ReadByte(102);	//
	tilt_axis.param.Gain_ANAOUT.fbyte[3] = EEPROM_ReadByte(103);	//float number loading	
	
	tilt_axis.param.color = EEPROM_ReadByte(104);	

	
	// Reads main parameters from EEPROM Row 7 - [EEPROM Add=112-127]
	pan_absolute_sensor.param.raw_invertion = EEPROM_ReadByte(112);
	pan_axis.param.limit_control = EEPROM_ReadByte(113);
	
	BYTEHIGH(pan_absolute_sensor.param.raw_home) = EEPROM_ReadByte(114);	
	BYTELOW(pan_absolute_sensor.param.raw_home)  = EEPROM_ReadByte(115);

	BYTEHIGH(pan_absolute_sensor.param.raw_limit_max) = EEPROM_ReadByte(116);	
	BYTELOW(pan_absolute_sensor.param.raw_limit_max)  = EEPROM_ReadByte(117);	
	
	BYTEHIGH(pan_absolute_sensor.param.raw_limit_min) = EEPROM_ReadByte(118);	
	BYTELOW(pan_absolute_sensor.param.raw_limit_min)  = EEPROM_ReadByte(119);
	
	BYTEHIGH(pan_absolute_sensor.param.raw_limit_hysteresis) = EEPROM_ReadByte(120);	
	BYTELOW(pan_absolute_sensor.param.raw_limit_hysteresis)  = EEPROM_ReadByte(121);
	
	//122
	//123
	
	pan_absolute_sensor.param.step_over_abs_ratio.fbyte[0] = EEPROM_ReadByte(124);	//
	pan_absolute_sensor.param.step_over_abs_ratio.fbyte[1] = EEPROM_ReadByte(125);	//
	pan_absolute_sensor.param.step_over_abs_ratio.fbyte[2] = EEPROM_ReadByte(126);	//
	pan_absolute_sensor.param.step_over_abs_ratio.fbyte[3] = EEPROM_ReadByte(127);	//float number saving	
	
	
	// Reads main parameters from EEPROM Row 8 - [EEPROM Add=128-143]
	tilt_absolute_sensor.param.raw_invertion = EEPROM_ReadByte(128);
	tilt_axis.param.limit_control = EEPROM_ReadByte(129);
	
	BYTEHIGH(tilt_absolute_sensor.param.raw_home) = EEPROM_ReadByte(130);	
	BYTELOW(tilt_absolute_sensor.param.raw_home)  = EEPROM_ReadByte(131);

	BYTEHIGH(tilt_absolute_sensor.param.raw_limit_max) = EEPROM_ReadByte(132);	
	BYTELOW(tilt_absolute_sensor.param.raw_limit_max)  = EEPROM_ReadByte(133);	
	
	BYTEHIGH(tilt_absolute_sensor.param.raw_limit_min) = EEPROM_ReadByte(134);	
	BYTELOW(tilt_absolute_sensor.param.raw_limit_min)  = EEPROM_ReadByte(135);
	
	BYTEHIGH(tilt_absolute_sensor.param.raw_limit_hysteresis) = EEPROM_ReadByte(136);	
	BYTELOW(tilt_absolute_sensor.param.raw_limit_hysteresis)  = EEPROM_ReadByte(137);
	
	//138
	//139
	
	tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[0] = EEPROM_ReadByte(140);	//
	tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[1] = EEPROM_ReadByte(141);	//
	tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[2] = EEPROM_ReadByte(142);	//
	tilt_absolute_sensor.param.step_over_abs_ratio.fbyte[3] = EEPROM_ReadByte(143);	//float number saving	
		
	
	//return(CYRET_SUCCESS);
}


/********************************************************************/
/* Read All Q Parameters (QELEMENT structure array) from EEPROM		*/
/********************************************************************/
void ReadAllQEEparams(void)
{
	int16 memory_number;
	
	uint8 dummy __attribute__ ((unused));

	for(memory_number=Q_MEMORY_NUMBER_MIN; memory_number <= Q_MEMORY_NUMBER_MAX; memory_number++)		//20 rows max (from row 32 to row 52)
	{
		// Reads Q parameters from EEPROM Row 32 + memory_number  [EEPROM Add=512..832]
		q[memory_number].param.position_default[PAN_AXIS].fbyte[0] 	= EEPROM_ReadByte(512 + memory_number * 16);	//
		q[memory_number].param.position_default[PAN_AXIS].fbyte[1] 	= EEPROM_ReadByte(513 + memory_number * 16);	//
		q[memory_number].param.position_default[PAN_AXIS].fbyte[2] 	= EEPROM_ReadByte(514 + memory_number * 16);	//
		q[memory_number].param.position_default[PAN_AXIS].fbyte[3] 	= EEPROM_ReadByte(515 + memory_number * 16);	//float number loading	
		
		q[memory_number].param.position_default[TILT_AXIS].fbyte[0] = EEPROM_ReadByte(516 + memory_number * 16);	//
		q[memory_number].param.position_default[TILT_AXIS].fbyte[1] = EEPROM_ReadByte(517 + memory_number * 16);	//
		q[memory_number].param.position_default[TILT_AXIS].fbyte[2] = EEPROM_ReadByte(518 + memory_number * 16);	//
		q[memory_number].param.position_default[TILT_AXIS].fbyte[3] = EEPROM_ReadByte(519 + memory_number * 16);	//float number loading	
		
		BYTEHIGH(q[memory_number].param.position_adjust[PAN_AXIS])  = EEPROM_ReadByte(520 + memory_number * 16);	
		BYTELOW(q[memory_number].param.position_adjust[PAN_AXIS]) 	= EEPROM_ReadByte(521 + memory_number * 16);

		BYTEHIGH(q[memory_number].param.position_adjust[TILT_AXIS]) = EEPROM_ReadByte(522 + memory_number * 16);	
		BYTELOW(q[memory_number].param.position_adjust[TILT_AXIS]) 	= EEPROM_ReadByte(523 + memory_number * 16);
		
		q[memory_number].number 									= EEPROM_ReadByte(524 + memory_number * 16);
		q[memory_number].mode 										= EEPROM_ReadByte(525 + memory_number * 16);		
	}
	//return(CYRET_SUCCESS);
}


// **********************************************
// *** Funzioni accesso EEPROM  basso livello ***
// **********************************************
  
  // Reads 1 byte from EEPROM			   //
  // 0 <= EEPROMAddress <= 2047 (2kbyte)   //
  //									   //
  // CYDEV_EE_BASE <-- EEPROM base pointer //
  // CYDEV_EE_SIZE <-- EEPROM Size 		   //
  uint8 EEPROM_ReadByte(uint16 EEPROMAddress)
  {
  	uint8 EEPROMData;
	
  	EEPROMData= CY_GET_REG8(CYDEV_EE_BASE + EEPROMAddress);
  	return(EEPROMData);
  }
  
  // Writes 16byte buffer (1 row) starting from EEPROM RowAddress 	// 
  // sourceData <-- pointer to 16 bytes array to write				//
  // 0 <= RowAddress <= 127											//
  uint8 EEPROM_WriteBuffer(uint8 RowAddress, uint8* sourceData)
  {
  	uint8 EEPStatus;
	
  	EEPStatus = EEPROM_Write(sourceData, RowAddress);
	return EEPStatus;
  }


// *************************************************************
// *** Funzioni "grafiche"	di console						 ***
// *************************************************************

void clshome_console(void)
{
	printf("\x1B[2J");			/* Erase Screen (ESC=\x1B) 	*/
	printf("\x1B[H");			/* Cursor Home (ESC=\x1B)	*/
}

void printf_spc(int space_num)
{
	int idx;
	for(idx=0;idx<=space_num;idx++)
	{
		printf(" ");			/* Print space_num Spaces on the console 	*/
	}	
}

// stampa un istogramma della variabile value rispetto ad un valore massimo max_value
// che corrisponderà a max_stars asterischi
// L'istogramma stampato è funzione lineare di abs(value)
// legenda è il puntatore ad una stringa che viene stampata prima del bargraph
void print_abs_linear_hystogram(int16 value, uint16 max_value, uint8 max_stars, char *string)
{
	uint8 idx, star_num;
	
	printf("|");
	printf(string);
	
	if (value >= 0)
	{
		star_num = (uint8) (value * (uint16)max_stars / max_value);
	}
	else
	{
		star_num = -(uint8) (value * (uint16)max_stars / max_value);
	}
	
	for (idx = 1; idx <= max_stars; idx++)
	{
		if (idx <= star_num)
		{
			printf ("*");
		}
		else
		{
			printf (" ");
		}	
	}	
	printf("|\r\n");	
}

// stampa il bordo superiore o inferiore dell'istogramma lungo max_stars asterischi e con legenda
void print_hystogram_border(uint8 max_stars, char *legenda)
{
	uint8 idx;
	for (idx = 1; idx <= max_stars+2+strlen(legenda); idx++)
		{
			printf("-");		
		}
	printf("\r\n");
}

// stampa scherzo
void print_joke(void)
{
	printf("\r\n");
	printf(STR_JOKE0);
	printf(STR_JOKE1);
	printf(STR_JOKE2);
	printf(STR_JOKE3);
	printf(STR_JOKE4);
	printf(STR_JOKE5);
	printf(STR_JOKE6);
	printf(STR_JOKE7);
	printf(STR_JOKE8);
	printf(STR_JOKE9);	
	printf(STR_JOKEA);
	printf(STR_JOKEB);
	printf(STR_JOKEC);	
	printf(STR_JOKED);	
	printf("\r\n");
}

// ***********************************
// *** Funzioni di Standard Output ***
// ***********************************

#if PSOC5LP_ARCH
/* To use Keil's IO functions such as printf,                 */
/* the program must override Keil's built-in putchar function.*/ 
/* This function overrides over USB UART					  */
// Provides IO Functions required to use printf with a UART.
// UART instance name is assumed to be UART


int _write(int file, char *ptr, int len) {
    int todo;

    for (todo = 0; todo < len; todo++) {
        UART_USB_PutChar(*ptr++);
    }
    return len;
}

int _read(int file, char *ptr, int len) {
    return 0;
}

#include <sys/stat.h>
int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
	return 0;
}

int _close(int file) {
    return -1;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}
#endif


// *************************************************************
// *** Funzioni di abilitazione e disabilitazione (sleep) HW ***
// *************************************************************

//void EnableSleepedHW(void)
//{
//	sleep_status = NOT_SLEEPING;
//	
//	//ADC_Start();					/* Enable ADC */
//	//ADC_IRQ_Enable();				/* Enable ADC Interrupts */
//	
//	isr_T1_Start();	
//	Clock_ticks_Enable();			/* Enable 1kHz Clock for system ticks ISR */
//
//	//isr_MC_Start();
//	//Clock_MC_Enable();				/* 2kHz Clock for MC ISR */
//}

//void SleepHW(void)
//{
//	sleep_status = SLEEPING;
//	
//	//ADC_Stop();						/* Disable ADC */
//	//ADC_IRQ_Disable();				/* Disable ADC Interrupts */
//	
//	isr_T1_Stop();	
//	Clock_ticks_Disable();			/* Disable 1kHz Clock for system ticks ISR */
//
//	//isr_MC_Stop();
//	//Clock_MC_Disable();				/* 2kHz Clock for MC ISR */
//	
//	SET_OFF(ALL_LEDS);				/* Shutoff Leds */
//	
//	//CyPmSleep();
//}

/* [] END OF FILE */
