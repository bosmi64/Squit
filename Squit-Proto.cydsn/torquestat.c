/* ========================================
 *
 * TORQUE STATISTICS library functions
 * Vers.2.1
 * 22/10/2018
 *
  *   Funzioni per misura e statistica delle:
 *		coppie
 *		correnti assorbite
 *		potenza assorbita ed erogata
 *		energia utilizzata
 *
 *    Versione con puntatori per stima
 *    contemporanea di pan e tilt
 *
 * Copyright Logic brainstorm, 2018
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Logic brainstorm.
 *
 * ========================================
*/
/* Include files */
#include <device.h>
#include <gobee.h>
#include <math.h>
#include <statistics.h>
#include <torquestat.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR CURRENT STATISTICS ELABORATION STEP
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se i(t) misurabile -->
// 		Output Torque(t) = i(t) * Km * eff_M * N * eff_R	[mNm]
// 		i(t)   = istantaneous current 						[A]
//		Km     = Torque constant 							[mNm/A]
//		eff_M  = Motor efficiency							[%]
//		N      = Gears rate									[adim]
//		eff_R  = Gears efficiency							[%]
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void current_statistics_elab_step(struct TORQUESTAT *tstat, struct STATISTICS *current_stat,  float current)
{
	current = fabsf(current);											//make the absolute value   [A]
	
	(*tstat).abs_current_t = current;									//save abs(current(t))
	
	(*tstat).current_integral = (*tstat).current_integral + current;	//integrate the current 	[A]
	
	/********************************************************************************************/
	/* Value Statistics Iterative Calculus						 								*/
	/* 																							*/
	/* iteration >= 2																			*/
	/* Calcola il valor medio e altre variabili statistiche del flusso di value passato			*/
	/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
	/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
	/********************************************************************************************/
	statistics_elab_step(current_stat, current);
}

/* Initialize Current Statistics */
void current_statistics_init(struct STATISTICS *current_stat)
{
	statistics_init(current_stat);	//Statistics-only initialization
}

/* Start Current Statistics */
void current_statistics_start(struct STATISTICS *current_stat)
{
	statistics_start(current_stat);	//Statistics-only initialization
}

/* Stop Current Statistics */
void current_statistics_stop(struct STATISTICS *current_stat)
{
	statistics_stop(current_stat);	//Statistics-only stop
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR POWER STATISTICS ELABORATION STEP
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se i(t) misurabile -->
// 		Output Power(t) = omega(t) * i(t) * Km * eff_M		[mW]
//		omega(t) = instantaneous angular velocity			[rad/sec]
// 		i(t)   = istantaneous current 						[A]
//		Km     = Torque constant 							[mNm/A]
//		eff_M  = Motor efficiency							[%]
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void qpower_statistics_elab_step(struct TORQUESTAT *tstat, struct STATISTICS *qpower_stat, float current, float omega)
{	
	current = fabsf(current);						//make the absolute value   [A]

	(*tstat).pwcalc.abs_omega_t = omega;
	
	(*tstat).pwcalc.qpower_t    = current * omega;		//quasi-power(t) = current(t) [A] * velocity(t) [rad/sec]
	
	/********************************************************************************************/
	/* Value Statistics Iterative Calculus						 								*/
	/* 																							*/
	/* iteration >= 2																			*/
	/* Calcola il valor medio e altre variabili statistiche del flusso di value passato			*/
	/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
	/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
	/********************************************************************************************/
	statistics_elab_step(qpower_stat, (*tstat).pwcalc.qpower_t);
}

/* Initialize quasi-power Statistics */
void qpower_statistics_init(struct STATISTICS *qpower_stat)
{
	statistics_init(qpower_stat);	//Statistics-only initialization
}

/* Start quasi-power Statistics */
void qpower_statistics_start(struct STATISTICS *qpower_stat)
{
	statistics_start(qpower_stat);	//Statistics-only initialization
}

/* Stop quasi-power Statistics */
void qpower_statistics_stop(struct STATISTICS *qpower_stat)
{
	statistics_stop(qpower_stat);	//Statistics-only stop
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR ANGULAR VELOCITY SAMPLING (used to calc motor power)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// return: absolute value of motor angular velocity [rad/sec]
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float motor_abs_velocity_sampling(struct TORQUESTAT *tstat, int32 enc_position_actual)
{
	float  motor_abs_velocity;			// Motor angular velocity		[rad/sec]
	
	//calc abs(motor velocity) [rad/sec] = (position[t] - position[t-Tsample])/Tsample * 2PI/Encoder_Resolution =
	//						        	 = (position[t] - position[t-Tsample]) * TQS_SAMPLING_RATE * 2PI/Encoder_Resolution
	//	Tsample = 0.24 sec (@ 4.167Hz sampling rate)
	
	if (enc_position_actual >= (*tstat).vcalc.enc_position_bef)
	{
		/* abs(motor velocity) */
		motor_abs_velocity = (float)(enc_position_actual - (*tstat).vcalc.enc_position_bef) * TQS_SAMPLING_RATE;
		motor_abs_velocity = motor_abs_velocity * PIx2_OVER_MOTENCODER_RESOLUTION;					//[rad/sec]
	}
	else
	{
		/* abs(motor velocity) */		
		motor_abs_velocity = (float)((*tstat).vcalc.enc_position_bef - enc_position_actual) * TQS_SAMPLING_RATE;
		motor_abs_velocity = motor_abs_velocity * PIx2_OVER_MOTENCODER_RESOLUTION;					//[rad/sec]		
	}
	
	//save encoder position[t-Tsample]
	(*tstat).vcalc.enc_position_bef = enc_position_actual;
	
	return motor_abs_velocity;	//[rad/sec] absolute value of angular velocity
}

/* Initialize Motor abs(Angular Velocity) Sampling */
void motor_abs_velocity_sampling_init(struct TORQUESTAT *tstat)
{
	(*tstat).vcalc.enc_position_bef = 0;				//encoder[0] <-- 0 [step]
}


/* No Load Current [A] 			*/
float i_noload(void)
{
	return NOLOAD_CURR;
}

/* Minimum Current Measured [A] */
float i_min(struct STATISTICS *current_stat)
{
	return (*current_stat).min;	
}

/* Minimum Motor Torque Measured [mNm] */
float TMOT_min(struct STATISTICS *current_stat)
{
	return fabsf((*current_stat).min - NOLOAD_CURR) * Km * eff_M;	//No load current does not contribute to Motor Torque
}

/* Minimum Erogated Motor Power Estimated [mW] */
float PMOTE_min(struct STATISTICS *qpower_stat)
{
	return (*qpower_stat).min * Km * eff_M;		//[mW] potenza elettrica minima erogata dal motore
}

/* Minimum Output Torque Measured [mNm] */
float TOUT_min(struct STATISTICS *current_stat, float gear_ratio)
{
	return TMOT_min(current_stat) * gear_ratio * eff_R;
}

/* Maximum Current Measured [A] */
float i_max(struct STATISTICS *current_stat)
{
	return (*current_stat).max;	
}

/* Maximum Motor Torque Measured [mNm] */
float TMOT_max(struct STATISTICS *current_stat)
{
	return fabsf((*current_stat).max - NOLOAD_CURR) * Km * eff_M;		//No load current does not contribute to Motor Torque
}

/* Maximum Erogated Motor Power Estimated [mW] */
float PMOTE_max(struct STATISTICS *qpower_stat)
{
	return (*qpower_stat).max * Km * eff_M;		//[mW] potenza elettrica massima erogata dal motore
}

/* Maximum Output Torque Measured [mNm] */
float TOUT_max(struct STATISTICS *current_stat, float gear_ratio)
{
	return TMOT_max(current_stat) * gear_ratio * eff_R;
}

/* Mean Current Measured [A]	*/
float i_mean(struct STATISTICS *current_stat)
{
	return (*current_stat).mean;		
}

/* Mean Motor Torque Measured	[mNm] */
float TMOT_mean(struct STATISTICS *current_stat)
{
	return fabsf((*current_stat).mean - NOLOAD_CURR) * Km * eff_M ;		//No load current does not contribute to Motor Torque	
}

/* Mean Erogated Motor Power Estimated	[mW] */
float PMOTE_mean(struct STATISTICS *qpower_stat)
{
	return (*qpower_stat).mean * Km * eff_M;		//[mW] potenza elettrica media erogata dal motore
}

/* Mean Output Torque Measured	[mNm] */
float TOUT_mean(struct STATISTICS *current_stat, float gear_ratio)
{
	return TMOT_mean(current_stat) * gear_ratio * eff_R;	
}

/* Current Variance Measured [A]	*/
float i_variance(struct STATISTICS *current_stat)
{
	return (*current_stat).variance;		
}

/* Torque Motor Variance Measured	[mNm] */
float TMOT_variance(struct STATISTICS *current_stat)
{
	return (*current_stat).variance * Km * eff_M;		
}

/* Torque Output Variance Measured	[mNm] */
float TOUT_variance(struct STATISTICS *current_stat, float gear_ratio)
{
	return TMOT_variance(current_stat) * gear_ratio * eff_R;		
}

/* Instantaneous Absolute Current Measured [A] */
float i_t(struct TORQUESTAT *torque_stat)
{
	return (*torque_stat).abs_current_t;	//abs(i(t))	
}

/* Instantaneous angular velocity Measured [rad/sec] */
float omega_t(struct TORQUESTAT *torque_stat)
{
	return (*torque_stat).pwcalc.abs_omega_t;			//abs(omega(t))	
}

/* Instantaneous angular velocity Measured [rpm] */
float rpm_t(struct TORQUESTAT *torque_stat)
{
	return omega_t(torque_stat) * RADSEC_TO_RPM;		//abs(rpm(t))	
}

/* Instantaneous Motor Torque Measured [mNm] */
float TMOT_t(struct TORQUESTAT *torque_stat)
{
	return fabsf((*torque_stat).abs_current_t - NOLOAD_CURR) * Km * eff_M;		//No load current does not contribute to Motor Torque
}

/* Instantaneous Erogated Motor Power Estimated [mW] */
float PMOTE_t(struct TORQUESTAT *torque_stat)
{
	return (*torque_stat).pwcalc.qpower_t * Km * eff_M;				//[mW] potenza elettrica istantanea erogata dal motore
}

/* Instantaneous Output Torque Measured [mNm] */
float TOUT_t(struct TORQUESTAT *torque_stat, float gear_ratio)
{
	return TMOT_t(torque_stat) * gear_ratio * eff_R;
}


/* Battery Energy Integral Reset */
void Battery_Energy_Integral_Reset(struct TORQUESTAT *torque_stat)
{
	(*torque_stat).current_integral = 0;			// [A] sampled in one Sampling Point
}

/* Battery used Energy Calculation [mAh used]*/
float Battery_Energy(struct TORQUESTAT *torque_stat, struct STATISTICS *current_stat)
{
	//current_stat.tick  [ticks]		--> number of ticks elapsed during statistics	[ticks]
	//current_integral   [A]			--> sum of every current of every sample		[A]
	//CSSR				 [ticks/sec]	--> Current Statistics Sampling Rate 			[Hz]
	//hours elapsed = (ticks/CSSR)/3600 --> Hours elapsed during statistics				[h]
	return	(float)((double)((*torque_stat).current_integral) * 1000 / ((*current_stat).tick * 60));	//	[mAh used]
}

/* Battery Meter Calculation [% of used Energy]*/
float Battery_Energy_Meter(struct TORQUESTAT *torque_stat, struct STATISTICS *current_stat, float battery_max_capacity)
{
	//battery capacity [mAh]
	return	Battery_Energy(torque_stat, current_stat) / battery_max_capacity * 100;	//	[% of used Energy]
}


#if SYSTEM_HPA3AX
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CURRENT MODE - cv(t) - STATISTICS
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se Controllo di Coppia con comando in tensione -->
//		Torque(t) = cv(t) * K_CV * K_AZ * Km * eff_M * N * eff_R			[mNm]
//		cv(t) = valore digitale di controllo 							 	[lsb]
//		K_CV  = costante di conversione cv --> Tensione di comando 		 	[V/lsb]
//		K_AZ  = costante di conversione Tensione di comando --> Corrente 	[A/V]
//		Km     = Torque constant 											[mNm/A]
//		eff_M  = Motor efficiency											[%]
//		N      = Gears rate													[adim]
//		eff_R  = Gears efficiency											[%]
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CurrentMode_statistics_elab_step(float cv)
{
	float current = fabsf (cv) * K_CV * K_AZ;			//make the absolute value   [A]
	current_statistics_elab_step(current);				//calculates statistics of current(torque)
}

/* Initialize CurrentMode Statistics */
void CurrentMode_statistics_init(void)
{
	current_statistics_init();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR POWER STATISTICS ELABORATION STEP - cv(t) (CURRENT MODE)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Se Controllo di Coppia con comando in tensione -->
// 		Output Power(t) = omega(t) * cv(t) * K_CV * K_AZ * Km * eff_M		[mW]
//		cv(t) = valore digitale di controllo 							 	[lsb]
//		K_CV  = costante di conversione cv --> Tensione di comando 		 	[V/lsb]
//		K_AZ  = costante di conversione Tensione di comando --> Corrente 	[A/V]
//		Km     = Torque constant 											[mNm/A]
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void qpower_CurrentMode_statistics_elab_step(float cv, float omega)
{
	float current = fabsf (cv) * K_CV * K_AZ;		//make the absolute value   [A]
	
	abs_omega_t = omega;
	
	qpower_t = current * omega;						//quasi-power(t) = current(t) * velocity(t) [A * rad/sec]
	
	/********************************************************************************************/
	/* Value Statistics Iterative Calculus						 								*/
	/* 																							*/
	/* iteration >= 2																			*/
	/* Calcola il valor medio e altre variabili statistiche del flusso di value passato			*/
	/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
	/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
	/********************************************************************************************/
	statistics_elab_step(&qpower_stat, qpower_t);
}

/* Initialize quasi-power Statistics - cv(t) - CURRENT MODE */
void qpower_CurrentMode_statistics_init(void)
{
	statistics_init(&qpower_stat);	//Statistics-only initialization
}

/* Stop quasi-power Statistics  - cv(t) - CURRENT MODE		*/
void qpower_CurrentMode_statistics_stop(void)
{
	statistics_stop(&qpower_stat);	//Statistics-only stop
}
#endif

/* [] END OF FILE */
