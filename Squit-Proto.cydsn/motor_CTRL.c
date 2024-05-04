/* ========================================
 *
 * Copyright Logic brainstorm, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <device.h>
#include <gobee.h>
#include <gobeelib.h>
#include <math.h>
#include <statistics.h>
#include <estimators.h>
#include <pid_lib.h>
#include <mover.h>
#include <motor_CTRL.h>

/* External Gobee Machine State */
extern uint8 machine_state;			/* Initial Machine State = POWERON 					*/
									/* Machine States = [POWERON | OPERATIVE | FAULT]	*/

extern uint8 machine_state_backup;	/* machine state backup var for test mode			*/


/* External GoBee Parameters */
extern struct GOBEE_PARAMS gobee_param;

/* EXTERNAL Absolute Position Sensor */
extern struct ABSPOS_SENSOR	pan_absolute_sensor;	/* PAN  Absolute Position Sensor Parameters & RT Datas */
extern struct ABSPOS_SENSOR	tilt_absolute_sensor;	/* TILT Absolute Position Sensor Parameters & RT Datas */

/* extern axis absolute sensor STATISTICS	*/
extern struct STATISTICS pan_absolute_sensor_stat;	/* PAN  Absolute Position Sensor Statistics Datas  	   */
extern struct STATISTICS tilt_absolute_sensor_stat;	/* TILT Absolute Position Sensor Statistics Datas  	   */

/* EXTERNAL Motor Axis */
extern struct MOTOR_AXIS pan_axis; 			/* PAN Motor Axis Parameters & RT Datas	    */
extern struct MOTOR_AXIS tilt_axis; 		/* TILT Motor Axis Parameters & RT Datas	*/

/* EXTERN MOVER PAN&TILT  */
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/

/* EXTERN MOVER PATH Array */
extern path_type path[PATH_N_MAX];		/* path array structure 	*/

extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/

/* extern Sensor ADC array */
extern int16 AdcValue[ADC_MUX_LENGHT];

/* extern anapos vars */
extern float anapos;					/* Analog Position Output(t) 				*/
extern int32 anapos_offset;				/* Analog Position Output Offset			*/


/********************************************************************/
/* ANAPOS OR ANAVEL SHOW											*/
/* DAC_ANAOUT <-- Selected ENCODER	* Gain_ANAOUT					*/
/*			  <-- d/dt(Selected ENCODER) * Gain_ANAOUT				*/
/********************************************************************/
void AnalogShow(struct MOTOR_AXIS *paxis)
{
	/* ANAPOS Selection based on *paxis (pan, tilt or roll?) and color (backslash or slave?)	*/

	if ((*paxis).param.color == SLAVE_ENC_POS)
	{
		anapos = (*paxis).param.Gain_ANAOUT.fnum*(float)((*paxis).mc.slave_enc.position - anapos_offset);
	}
	else if ((*paxis).param.color == SLAVE_ENC_VEL)
	{
		anapos = (*paxis).param.Gain_ANAOUT.fnum*(float)((*paxis).mc.slave_enc.velocity - anapos_offset);
	}	
	else if ((*paxis).param.color == ASTIM_IN)
	{
		//anapos = pan_axis.param.Gain_ANAOUT.fnum*(pan_axis.mc.Float_ASTIM - (float)anapos_offset);
		anapos = (*paxis).param.Gain_ANAOUT.fnum*pan_axis.mc.Float_ASTIM;
		
	}
	else if ((*paxis).param.color == CTRL_ERROR)
	{
		anapos = (*paxis).param.Gain_ANAOUT.fnum*((*paxis).mc.error - (float)anapos_offset);	
	}
	else if ((*paxis).param.color == CTRL_DERROR)
	{
		anapos = (*paxis).param.Gain_ANAOUT.fnum*((*paxis).mc.derror - (float)anapos_offset);	
	}
	else if ((*paxis).param.color == CTRL_IERROR)
	{
		anapos = (*paxis).param.Gain_ANAOUT.fnum*((*paxis).mc.ierror - (float)anapos_offset);	
	}
	else if ((*paxis).param.color == CTRL_CV)
	{
		anapos = (*paxis).mc.ctrl_var * 128/MOTOR_PWM_PERIOD_HALF;	//fixed 4Vpp Output at PWM MAX	
	}	
	else if ((*paxis).param.color == CTRL_AZIERROR)
	{
		anapos = (*paxis).param.Kif.fnum * (*paxis).mc.ierror * 128/MOTOR_PWM_PERIOD_HALF;	//fixed 4Vpp Output at PWM MAX		
	}		

	else
	{
		anapos = 0;	/* Internal Firmware Error */
	}
			
		/* anapos 8 bit saturation */
		if (anapos>127)
		{
			anapos = 127;
		}
		if (anapos < -127)
		{
			anapos = -127;
		}
		
		VDAC8_ANAPOS_SetValue((uint8)(anapos+128));		/* Anapos DAC Refresh <-- position(t)		*/	
}


/****************************/
/* Axis Limit Control CODE  */
/****************************/
void Axis_limit_control_init(void)
{
	pan_axis.lc.status  = COARSE_BETWEEN_LIMITS_OK;	/* PAN  COARSE BETWEEN LIMITS	*/
	tilt_axis.lc.status = COARSE_BETWEEN_LIMITS_OK;	/* TILT COARSE BETWEEN LIMITS	*/
}

void Axis_limit_control(struct MOTOR_AXIS *paxis, struct ABSPOS_SENSOR *abs_sens)
{
	/* absolute limits check & Hysteresys Logic */
	if ((*paxis).param.limit_control == LIMIT_CONTROL_ENABLED)
	{
		if ((*abs_sens).raw >= ((*abs_sens).param.raw_limit_max + (*abs_sens).param.raw_limit_hysteresis))
		{
			(*paxis).lc.status = POSITIVE_LIMIT_REACHED;		/* ASSERT POSITIVE LIMIT!!! 	*/
		}
		else
		if ((*abs_sens).raw <= ((*abs_sens).param.raw_limit_min - (*abs_sens).param.raw_limit_hysteresis))	
		{
			(*paxis).lc.status = NEGATIVE_LIMIT_REACHED;		/* ASSERT NEGATIVE LIMIT!!! 	*/			
		}

		if (((*paxis).lc.status == POSITIVE_LIMIT_REACHED) &&
		   ((*abs_sens).raw <= ((*abs_sens).param.raw_limit_max - (*abs_sens).param.raw_limit_hysteresis)))
		{
			(*paxis).lc.status = COARSE_BETWEEN_LIMITS_OK;		/* ASSERT COARSE BETWEEN LIMITS */
		}

		if (((*paxis).lc.status == NEGATIVE_LIMIT_REACHED) &&
		   ((*abs_sens).raw >= ((*abs_sens).param.raw_limit_min - (*abs_sens).param.raw_limit_hysteresis)))
		{
			(*paxis).lc.status = COARSE_BETWEEN_LIMITS_OK;		/* ASSERT COARSE BETWEEN LIMITS */
		}		
	}
	else
	{
		(*paxis).lc.status = COARSE_BETWEEN_LIMITS_OK;			/* UNLIMITED CASE: ASSERT COARSE BETWEEN LIMITS */		
	}
}

void All_Axes_limit_control(void)
{
	Axis_limit_control(&pan_axis, &pan_absolute_sensor);	/* pan_axis.lc.status  <-- LIMIT STATUS	(positive, negative, coarse between limits) */
	Axis_limit_control(&tilt_axis, &tilt_absolute_sensor);	/* tilt_axis.lc.status <-- LIMIT STATUS	(positive, negative, coarse between limits) */
}

/************************************************/
/*** AXIS MOTOR CONTROL CODE       			  ***/
/************************************************/
/* *paxis = [&pan_axis, &tilt_axis]				*/
/* *mover = [&mover_pan, &mover_tilt]			*/
/************************************************/
void motor_control(struct MOTOR_AXIS *paxis, mover_type *mover)
{
	/****************************************************************/
	/* Current(t), SlaveEncoder(t) & Absolute_Sensor(t) Sampling	*/
	/****************************************************************/
	if (paxis == &pan_axis)
	{
		// Rsense = 0,39[Ohm]; Analog Gain = 25,9; --> V[ADC] = 0,39[Ohm] * 0,5 [A] * 25,9 = 5,05[V] (about ADC FULL SCALE)
		pan_axis.mc.current = (float)(AdcValue[SENSE_IPAN] + ADC_CURR_ZERO_OFFSET) * AMPERE_OVER_ADC_CONST;		/* [A] */
		
		/* PAN Feedback Encoder PositionSampling						*/	
		(*paxis).mc.slave_enc.position = QuadDec_PAN_GetCounter();												/* Incremental Position(t) [step] 	*/
		
		/* PAN Analog Absolute Position Sensor ADC Sampling (12bit) 	*/		
		pan_absolute_sensor.raw = AdcValue[HOME_PAN_ABSV];														/* [ADC lsb] */
		
		/*  PAN Analog Absolute Position Sensor raw invertion 			*/
		if (pan_absolute_sensor.param.raw_invertion == ABS_SENSOR_INVERTED)
		{
			pan_absolute_sensor.raw = -pan_absolute_sensor.raw;													/* [ADC lsb] */
		}	
				
		/********************************************************************************************/
		/* Pan Absolute Position Sensor Statistics Iterative Calculus								*/
		/* iteration >= 2																			*/
		/* Calcola il valor medio e altre variabili statistiche										*/
		/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
		/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
		/********************************************************************************************/
		statistics_elab_step(&pan_absolute_sensor_stat,  (float)pan_absolute_sensor.raw);

#if PAN_PSEUDOABS
		/* PAN Pseudo-Absolute Position Steps Calculation 	*/	
		if (pan_axis.mc.slave_enc.position >= 0)
		{
			pan_absolute_sensor.position = 	(float)((int32)pan_axis.mc.slave_enc.position % (int32)pan_axis.param.resolution.fnum);
		}
		else
		{
			pan_absolute_sensor.position = 	pan_axis.param.resolution.fnum - 
											(float)((int32)-pan_axis.mc.slave_enc.position % (int32)pan_axis.param.resolution.fnum);
		}		
#else		
		/* PAN Absolute Position Steps Calculation 			*/		
		pan_absolute_sensor.position = (float)(pan_absolute_sensor.raw - pan_absolute_sensor.param.raw_home)   	/* Absolute Position(t) [float step] */
									 * pan_absolute_sensor.param.step_over_abs_ratio.fnum;					   	/* referred to HOME position 		 */
#endif
		
		pan_absolute_sensor.angle_rad = (float)pan_absolute_sensor.position * pan_axis.vparam.resolution_rad_step; 	/* Absolute Position(t) [rad] 	 */
	}	
    else if (paxis == &tilt_axis)
    {
		// Rsense = 0,39[Ohm]; Analog Gain = 25,9; --> V[ADC] = 0,39[Ohm] * 0,5 [A] * 25,9 = 5,05[V] (about ADC FULL SCALE)
		tilt_axis.mc.current = (float)(AdcValue[SENSE_ITILT] + ADC_CURR_ZERO_OFFSET) * AMPERE_OVER_ADC_CONST;	/* [A] */
		
 		/* TILT Feedback Encoder PositionSampling						 */	
		(*paxis).mc.slave_enc.position = QuadDec_TILT_GetCounter();												/* Incremental Position(t) [step] 	*/
		
		/* TILT Analog Absolute Position SensorRaw Data Sampling (12bit) */		
		tilt_absolute_sensor.raw = AdcValue[HOME_TILT_ABSV];													/* [ADC lsb] */

		/*  TILT Analog Absolute Position Sensor raw invertion 			 */
		if (tilt_absolute_sensor.param.raw_invertion == ABS_SENSOR_INVERTED)
		{
			tilt_absolute_sensor.raw = -tilt_absolute_sensor.raw;												/* [ADC lsb] */
		}

		/********************************************************************************************/
		/* Tilt Absolute Position Sensor Statistics Iterative Calculus								*/
		/* iteration >= 2																			*/
		/* Calcola il valor medio e altre variabili statistiche										*/
		/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
		/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
		/********************************************************************************************/
		statistics_elab_step(&tilt_absolute_sensor_stat, (float)tilt_absolute_sensor.raw);
		
		/* TILT Absolute Position Steps Calculation 					 */		
		tilt_absolute_sensor.position = (float)(tilt_absolute_sensor.raw - tilt_absolute_sensor.param.raw_home) /* Absolute Position(t) [float step] */
									 * tilt_absolute_sensor.param.step_over_abs_ratio.fnum;						/* referred to HOME position 		 */
    }
	
	/****************************************************************************/
	/* MASTER Encoder: Delta Mover Input										*/
	/****************************************************************************/
	if ((*mover).status == MOVER_STARTED)
	{	
		/* Mover Generated Steps 	*/
		(*mover).steps = MoverGeneratedSteps(mover, &path[(*mover).path_to_move], (*mover).ticks);		/* [int32 steps] */
		(*paxis).mc.master_enc_sample_delta = (*mover).steps;											/* [int32 steps] */
		
		(*mover).ticks++;																				/* Mover ticks Increment	*/
	}  


	/********************************/
	/* CONDITIONAL DELTA LIMITING	*/
	/********************************/
	if ((*paxis).lc.status == COARSE_BETWEEN_LIMITS_OK)
	{		
		(*paxis).lc.deceleration_factor = 1; /* reset Limit deceleration factor */		
	}
	else
	{
		(*paxis).lc.master_limit_delta = (float)(*paxis).mc.master_enc_sample_delta +
										 (float)(*paxis).mc.master_joy_sample_delta;  /* [float delta steps] */
									
		/*  Re-enter into limits allowed al full speed */
		if ((((*paxis).lc.status == POSITIVE_LIMIT_REACHED) && ((*paxis).lc.master_limit_delta < 0)) ||
			(((*paxis).lc.status == NEGATIVE_LIMIT_REACHED) && ((*paxis).lc.master_limit_delta > 0)))
		{		
			(*paxis).lc.deceleration_factor = 1; /* reset Limit deceleration factor */				
		}
		else	/* fixed deceleration to zero speed */
		{
			/* 0.97^250 = 0.05% --> speed limiting to 0.05% after 0.1 sec */			
			(*paxis).lc.deceleration_factor = (*paxis).lc.deceleration_factor * (*paxis).param.limit_deceleration_factor.fnum;

			(*paxis).mc.master_enc_sample_delta = (int32)((float)(*paxis).mc.master_enc_sample_delta * (*paxis).lc.deceleration_factor); /* [int32 steps] */	
			
			(*paxis).mc.master_joy_sample_delta = (int32)((float)(*paxis).mc.master_joy_sample_delta * (*paxis).lc.deceleration_factor); /* [int32 steps] */	
		}		
	}	
	

	//////////////////////////////////////////////
	// MASTER ENCODER & JOYSTICK INTEGRATION	//
	//////////////////////////////////////////////
	(*paxis).mc.master_enc_position = (*paxis).mc.master_enc_position + (*paxis).mc.master_enc_sample_delta;
	(*paxis).mc.master_joy_position = (*paxis).mc.master_joy_position + (*paxis).mc.master_joy_sample_delta;

	
	/****************************************************************************/
	/* If DEENERGIZE by Software (OR Hardware)									*/
	/* then GALIL TRICK!!!														*/
	/****************************************************************************/
	if (machine_state == GOBEE_DEENERGIZED)
	{
		GalilTrick(paxis);
	}	
	
	
	/****************************************************************************/
	/* e(t) Calculus										   					*/
	/****************************************************************************/
	(*paxis).mc.error = (float)((*paxis).mc.master_enc_position + (*paxis).mc.master_joy_position - (*paxis).mc.slave_enc.position);
		

	/************************************************************************/
	/* d/dt(error)  Calculus												*/
	/*   d/dt(error) = error(t) - error(t-1)       							*/
	/************************************************************************/	
	(*paxis).mc.derror = (*paxis).mc.error - (*paxis).mc.error_bef;
	(*paxis).mc.error_bef = (*paxis).mc.error;	
	
	
#if ASTIM_CALC_INLOOP
	/********************************************************************************************/
	/* WARNING!!!: AUTOSTIM VELOCITY (CONTROLLER INPUT)   										*/
	/********************************************************************************************/
	/*																							*/
	/*							          -----------------------	  -------    				*/
	/*   (0..4V)  CTRL_IN [V] --> (+) --> |* 4096[lsb]*4[V]/5[V]| --> |*Kopf| --> Float_ASTIM	*/
	/*							   ^       ----------------------	  -------					*/
	/*							   |															*/
	/* 							  410 (offset)													*/
	/* 																							*/
	/* 	 Float_ASTIM(t) --->(+)---> e(t)														*/
	/*					     ^																	*/
	/*					     |																	*/
	/*				         |------ -(gyro feedback(t))										*/
	/*																							*/
	/*   (Float_ASTIM)peak = Vinpp[V] * 410[lsb/V] * Kopf										*/
	/*																							*/
	/********************************************************************************************/	
	(*paxis).mc.Float_ASTIM = ((float)(AdcValue[CTRL_IN_ASTIM]) + ADC_ASTIM_ZERO_OFFSET) * (*paxis).param.Kopf.fnum;

	/* Sgancio Zero Cross dall'autostimolo */
	if ((*paxis).vparam.astim_enable == ASTIM_DISABLED)									//ASTIM IS DISABLED
	{
		if ((*paxis).mc.astim_ZCsync == ASTIM_ZC_SYNC_OK)
		{
			if (((*paxis).mc.Float_ASTIM >= 50) || ((*paxis).mc.Float_ASTIM <= -50))
			{
				(*paxis).mc.error = (*paxis).mc.error + (*paxis).mc.Float_ASTIM;		/* Position Stimulus Input */
			}
			else
			{
				(*paxis).mc.astim_ZCsync = ASTIM_ZC_SYNC_TODO;
			}
		}
	}
	else																				//ASTIM is enabled
	{
		/* Aggancio Zero Cross all'autostimolo (sine e tria) */
		if (((*paxis).vparam.astim_type == SINE_ASTIM) || ((*paxis).vparam.astim_type == TRIANGLE_ASTIM))
		{
			if ((((*paxis).mc.Float_ASTIM > 0) && ((*paxis).mc.Float_ASTIM <= 10)) || ((*paxis).mc.astim_ZCsync == ASTIM_ZC_SYNC_OK))
			{
				(*paxis).mc.error = (*paxis).mc.error + (*paxis).mc.Float_ASTIM;		/* Position Stimulus Input 			*/
				(*paxis).mc.astim_ZCsync = ASTIM_ZC_SYNC_OK;
			}
		}

		/* Aggancio immediato all'autostimolo (square) */		
		if ((*paxis).vparam.astim_type == SQUARE_ASTIM)
		{
			(*paxis).mc.error = (*paxis).mc.error + (*paxis).mc.Float_ASTIM;			/* Position Stimulus Input 				*/			
		}
	}
#endif	

	/****************************************************************************/
	/* PID Calculus										   						*/
	/* 	  cv(t) =   PID(e(t)) + Autostimulus									*/
	/****************************************************************************/
	/* cv(t) = SAT_cvS(Kp * e(t) + Kd * (e(t) - e(t-1)) + Ki * Ksi_Saturated(integral(e(t))) 	*/
	/* 11 bit saturation --> cvS=MOTOR_PWM_PERIOD_HALF											*/	
	(*paxis).mc.ctrl_var = fpSpid_k2(paxis, MOTOR_PWM_PERIOD_HALF);
	
	
	/****************************************************************************/
	/* CONTROL VAR PWM refreshing: BASED ON POLARITY							*/
	/****************************************************************************/
	if ((*paxis).param.polarity == 0)
	{
		(*paxis).mc.pwm_var = (uint16)((*paxis).mc.ctrl_var + MOTOR_PWM_PERIOD_HALF);			
	}
	else
	{			
		(*paxis).mc.pwm_var = (uint16)(MOTOR_PWM_PERIOD_HALF - (*paxis).mc.ctrl_var);
	}
	
	
	/****************************************************************************/
	/* PWM MOTOR Output (11.5bit)												*/
	/****************************************************************************/
	if (paxis == &pan_axis)
	{
		PWM_MOTOR_PAN_WriteCompare((int16)pan_axis.mc.pwm_var);
	}
    else if (paxis == &tilt_axis)
	{
		PWM_MOTOR_TILT_WriteCompare((int16)tilt_axis.mc.pwm_var);
	}
	else		/* Firmware Internal Error */
	{
		PWM_MOTOR_PAN_WriteCompare(MOTOR_PWM_PERIOD_HALF);
		PWM_MOTOR_TILT_WriteCompare(MOTOR_PWM_PERIOD_HALF);
	}			
}
	

/********************************************************************/
/* GALIL TRICK														*/
/********************************************************************/
void GalilTrick(struct MOTOR_AXIS *paxis)

{    /*------------------------------*/
	/* Clear all PID(t) RT Datas    */
    /*------------------------------*/
	/* e(t) = 0, LPF(e(t)) = 0	    */
	/* e(t-1) = 0		   		    */
	/* integral(e(t)) = 0  		    */
	/* d/dt(e(t)), LPF(d/dt(e(t)))	*/
    /*------------------------------*/
	PIDs_DataClear(paxis);
	
	if (paxis == &pan_axis)
	{
		/* Azzera anche e(t+1) caricando nel registro di feedback slave(t)...                               */
        /*--------------------------------------------------------------------------------------------------*/            
        /* slave(t) = master(t) - Gyro(t) + GYRO_MASTER_OFFSET(t)                                           */
        /* e(t+1) = master(t+1) - slave(t) - Gyro(t) + GYRO_MASTER_OFFSET(t) = 0                            */
//		QuadDec_PAN_SetCounter((int32)(pan_axis.mc.master_enc_steps_lowpass
//                                   - pan_axis.gyrodata.Gyro_FLOAT_lowpass
//                                   + pan_axis.gyrodata.GyroMOffset_FLOAT_lowpass)); //[steps]	
#if PAN_PSEUDOABS
#else
		QuadDec_PAN_SetCounter(          (int32)(pan_axis.mc.master_enc_position + pan_axis.mc.master_joy_position));
		pan_axis.mc.slave_enc.position = (int32)(pan_axis.mc.master_enc_position + pan_axis.mc.master_joy_position);
#endif		
	}
	else if (paxis == &tilt_axis)
	{
		/* Azzera anche e(t+1) caricando nel registro di feedback slave(t)...                               */
        /*--------------------------------------------------------------------------------------------------*/            
        /* slave(t) = master(t) - Gyro(t) + GYRO_MASTER_OFFSET(t)                                           */
        /* e(t+1) = master(t+1) - slave(t) - Gyro(t) + GYRO_MASTER_OFFSET(t) = 0                            */
//		QuadDec_TILT_SetCounter((int32)(tilt_axis.mc.master_enc_steps_lowpass
//                                   - tilt_axis.gyrodata.Gyro_FLOAT_lowpass
//                                   + tilt_axis.gyrodata.GyroMOffset_FLOAT_lowpass)); //[steps]	
		QuadDec_TILT_SetCounter(          (int32)(tilt_axis.mc.master_enc_position + tilt_axis.mc.master_joy_position));
		tilt_axis.mc.slave_enc.position = (int32)(tilt_axis.mc.master_enc_position + tilt_axis.mc.master_joy_position);	
		
	}	
}

//////////////////////////////////////
//motors initialization function	//
//////////////////////////////////////
void motor_init(struct MOTOR_AXIS *paxis)
{
    /*------------------------------*/
	/* Clear all PID(t) RT Datas    */
    /*------------------------------*/
	/* e(t) = 0, LPF(e(t)) = 0	    */
	/* e(t-1) = 0		   		    */
	/* integral(e(t)) = 0  		    */
	/* d/dt(e(t)), LPF(d/dt(e(t)))	*/
    /*------------------------------*/
	PIDs_DataClear(paxis);
	
	//clears master integrated positions
	(*paxis).mc.master_enc_position = 0;
	(*paxis).mc.master_joy_position = 0;
	
	//clears feedback encoders
	if (paxis == &pan_axis)
	{
		QuadDec_PAN_SetCounter(0);
	}
	else if (paxis == &tilt_axis)
	{
		QuadDec_TILT_SetCounter(0);
	}
//	else if (paxis == &roll_axis)
//	{
//		QuadDec_ROLL_SetCounter(0);
//	}	
}

void motor_energize(struct MOTOR_AXIS *paxis)
{
	if ((paxis == &pan_axis) || (paxis == &tilt_axis))
	{
		Control_Reg_MOTOR_Write(0x01);
	}
}


void motor_sleep(struct MOTOR_AXIS *paxis)
{
	if ((paxis == &pan_axis) || (paxis == &tilt_axis))
	{
		Control_Reg_MOTOR_Write(0x00);
	}
}

/* [] END OF FILE */
