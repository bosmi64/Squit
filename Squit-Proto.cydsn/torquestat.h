/* ========================================
 *
 * TORQUE STATISTICS library header
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR SYSTEM CONSTANTS
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DC_FAULHABER_3272G_012CR		
#define N			125			//Gears rate				[adim]

#define eff_R		0.6			//Gears efficiency			[%]
								//  Worm         				   			= 60%
							
#define eff_M		0.85		//Motor efficiency			[%]
								//  Coreless DC Faulhaber 3272G-012CR 		= 85%

#define Km			20.8		//Motor Torque Constant 	[mNm/A]
								//  Coreless DC Faulhaber 3272G-012CR 		= 20,8 mNm/A

#define K_CV 		0.0078		//Control Voltage constant 	[V/lsb]
								//  Examples:
								//  HPA3AX = 11bit DAC, 8V = 8/1024 = 0,0078 V/lsb
							
#define K_AZ		2.0			//Driver constant			[A/V]
								//  Examples:
								//  AZ20A8 = 12A/10V = 1,2 A/V
								//  AZ40A8 = 20A/10V = 2,0 A/V

#define NOLOAD_CURR	0.191		//No Load Current
								//  Coreless DC Faulhaber 3272G-012CR 		= 0,191 A
#endif

#if DC_MAXON_DC_max16S_EB_KL_6V
#define N_pan		62.0		//Gears ratio				[adim]
#define N_tilt		172.0		//Gears ratio				[adim]

#define eff_R		0.75		//Gears efficiency			[%]
								//	Planetary Maxon GPX19 LZ 172:1 = 75%
								
#define eff_M		0.81		//Motor efficiency			[%]
								//	Coreless DC Maxon DC-max16S EB KL 6V  	= 81%

#define Km			7.19		//Motor Torque Constant 	[mNm/A]
								//  Coreless DC Maxon DC-max16S EB KL 6V	= 7,19 mNm/A

#define K_CV 		0.0			//Control Voltage constant 	[V/lsb]
								
#define K_AZ		0.0			//Driver constant			[A/V]

#define NOLOAD_CURR	0.014		//No Load Current
								//  Coreless DC Maxon DC-max16S EB KL 6V	= 0,014 A
#endif

#if DC_POLOLU
//#define N_pan		100.37		//Gears ratio				[adim]	PARAMETRO DEL PROTOTIPO
#define N_pan		50.0		//Gears ratio				[adim]	PARAMETRO DI TEST	
#define N_tilt		297.92		//Gears ratio				[adim]

#define eff_R		0.75		//Gears efficiency			[%]		PARAMETRO NON VERIFICATO
								//	
								
#define eff_M		0.81		//Motor efficiency			[%]		PARAMETRO NON VERIFICATO
								//	

#define Km			7.19		//Motor Torque Constant 	[mNm/A]	PARAMETRO NON VERIFICATO
								//  

#define K_CV 		0.0			//Control Voltage constant 	[V/lsb]	PARAMETRO NON VERIFICATO
								
#define K_AZ		0.0			//Driver constant			[A/V]	PARAMETRO NON VERIFICATO

#define NOLOAD_CURR	0.014		//No Load Current					PARAMETRO NON VERIFICATO
								//  
#endif
								

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FEEDBACK ENCODER CONSTANTS
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if DC_FAULHABER_3272G_012CR
#define MOTOR_ENCODER_RESOLUTION			20000		/* [step/2PI] US DIGITAL E2-5000-197-IE-D-D-B (5000x4=20.000 step)	*/													*/
#define PIx2_OVER_MOTENCODER_RESOLUTION		0.00031416	/* [rad/step]	(2PI/20000)											*/	
#endif

#if DC_MAXON_DC_max16S_EB_KL_6V
#define MOTOR_ENCODER_RESOLUTION			4096		/* [step/2PI] MAXON ENX10 EASY 1024IMP (1024x4=4096 step)			*/													*/
#define PIx2_OVER_MOTENCODER_RESOLUTION		0.00153398	/* [rad/step]	(2PI/4096)											*/		
#endif

#if DC_POLOLU
#define MOTOR_ENCODER_RESOLUTION			12			/* [step/2PI] #3081 Magnetic Encoder 12CPR (3x4=12 step)			*/													*/
#define PIx2_OVER_MOTENCODER_RESOLUTION		0.52359878	/* [rad/step]	(2PI/12)											*/		
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GENERAL SYSTEM CONSTANTS
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if SYSTEM_HPA3AX
#define TQS_SAMPLING_RATE	4.1666667	// [Hz]		(torquestat isr sampling rate)
#define TSAMPLE				0.24		// [sec]	(Tsample = 0.24 sec @ 4.167Hz sampling rate)
#endif

#if SYSTEM_GOBEE_DIRECTOR_PROTO
#define TQS_SAMPLING_RATE	3.125		// [Hz]		(torquestat isr sampling rate)
#define TSAMPLE				0.32		// [sec]	(Tsample = 0.32 sec @ 3.125Hz sampling rate)
#endif

#define RADSEC_TO_RPM	9.54929659		// [sec/(min*rad)] (Multiplying constant from [rad/sec] to [rpm]	


// tipo di dato TORQUESTAT	
struct TORQUESTAT
{
	double current_integral;				// Integral(abs(current(t))		[A] sampled in one Sampling Point
	float  abs_current_t;					// abs(current(t)) 				[A]
	
	struct POWERCALC
	{
		float  abs_omega_t;					// abs(omega(t))				[rad/sec]
		float  qpower_t;					// quasi-power(t)				[A * rad/sec]
	}pwcalc;		
	
	struct VELOCALC
	{
		float actual_abs_motor_velocity;	// Motor velocity(t) calculated @ 4.15Hz sampling rate	*/
		int32  enc_position_bef;			// Encoder position[t-Tsample]	[step] 	(where Tsample = 1/4.167Hz = 0.24 sec) 
	}vcalc;		
}TORQUESTAT;
	
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
void current_statistics_elab_step(struct TORQUESTAT *tstat, struct STATISTICS *current_stat,  float current);

/* Initialize Current Statistics */
void current_statistics_init(struct STATISTICS *current_stat);

/* Start Current Statistics */
void current_statistics_start(struct STATISTICS *current_stat);

/* Stop Current Statistics */
void current_statistics_stop(struct STATISTICS *current_stat);

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
void qpower_statistics_elab_step(struct TORQUESTAT *tstat, struct STATISTICS *qpower_stat, float current, float omega);
	
/* Initialize power Statistics */
void qpower_statistics_init(struct STATISTICS *qpower_stat);

/* Start quasi-power Statistics */
void qpower_statistics_start(struct STATISTICS *qpower_stat);

/* Stop quasi-power Statistics */
void qpower_statistics_stop(struct STATISTICS *qpower_stat);


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MOTOR ANGULAR VELOCITY SAMPLING (used to calc motor power)
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// return: motor abs(angular velocity) [rad/sec]
///////////////////////////////////////////////////////////////////////////////////////////////////////////
float motor_abs_velocity_sampling(struct TORQUESTAT *tstat, int32 enc_position_actual);

/* Initialize Motor abs(Angular Velocity) Sampling */
void motor_abs_velocity_sampling_init(struct TORQUESTAT *tstat);


/* No Load Current [A] 			*/
float i_noload(void);

/* Minimum Current Measured [A] */
float i_min(struct STATISTICS *current_stat);

/* Minimum Motor Torque Measured [mNm] */
float TMOT_min(struct STATISTICS *current_stat);

///* Minimum Absorbed Motor Power Estimated [mW] */
//float PMOTA_min(void);

/* Minimum Erogated Motor Power Estimated [mW] */
float PMOTE_min(struct STATISTICS *qpower_stat);

/* Minimum Output Torque Measured [mNm] */
float TOUT_min(struct STATISTICS *current_stat, float gear_ratio);

/* Maximum Current Measured [A] */
float i_max(struct STATISTICS *current_stat);

/* Maximum Motor Torque Measured [mNm] */
float TMOT_max(struct STATISTICS *current_stat);

/* Maximum Erogated Motor Power Estimated [mW] */
float PMOTE_max(struct STATISTICS *qpower_stat);

/* Maximum Output Torque Measured [mNm] */
float TOUT_max(struct STATISTICS *current_stat, float gear_ratio);

/* Mean Current Measured [A]	*/
float i_mean(struct STATISTICS *current_stat);

/* Mean Motor Torque Measured	[mNm] */
float TMOT_mean(struct STATISTICS *current_stat);

/* Mean Erogated Motor Power Estimated	[mW] */
float PMOTE_mean(struct STATISTICS *qpower_stat);

/* Mean Output Torque Measured	[mNm] */
float TOUT_mean(struct STATISTICS *current_stat, float gear_ratio);

/* Current Variance Measured [A]	*/
float i_variance(struct STATISTICS *current_stat);

/* Torque Motor Variance Measured	[mNm] */
float TMOT_variance(struct STATISTICS *current_stat);

/* Torque Output Variance Measured	[mNm] */
float TOUT_variance(struct STATISTICS *current_stat, float gear_ratio);

/* Instantaneous Absolute Current Measured [A] */
float i_t(struct TORQUESTAT *torque_stat);

/* Instantaneous angular velocity Measured [rad/sec] */
float omega_t(struct TORQUESTAT *torque_stat);

/* Instantaneous angular velocity Measured [rpm] */
float rpm_t(struct TORQUESTAT *torque_stat);

/* Instantaneous Motor Torque Measured [mNm] */
float TMOT_t(struct TORQUESTAT *torque_stat);

/* Instantaneous Erogated Motor Power Estimated [mW] */
float PMOTE_t(struct TORQUESTAT *torque_stat);

/* Instantaneous Output Torque Measured [mNm] */
float TOUT_t(struct TORQUESTAT *torque_stat, float gear_ratio);


/* Battery Energy Integral Reset */
void Battery_Energy_Integral_Reset(struct TORQUESTAT *torque_stat);

/* Battery used Energy Calculation [mAh used] */
float Battery_Energy(struct TORQUESTAT *torque_stat, struct STATISTICS *current_stat);

/* Battery Meter Calculation [% of used Energy]*/
float Battery_Energy_Meter(struct TORQUESTAT *torque_stat, struct STATISTICS *current_stat, float battery_max_capacity);

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
void CurrentMode_statistics_elab_step(float cv);

/* Initialize CurrentMode Statistics */
void CurrentMode_statistics_init(void);

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
void qpower_CurrentMode_statistics_elab_step(float cv, float omega);

/* Initialize quasi-power Statistics - cv(t) - CURRENT MODE */
void qpower_CurrentMode_statistics_init(void);

/* Stop quasi-power Statistics  - cv(t) - CURRENT MODE		*/
void qpower_CurrentMode_statistics_stop(void);
#endif


/* [] END OF FILE */
