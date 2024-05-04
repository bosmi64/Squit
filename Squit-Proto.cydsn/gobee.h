/* ==============================================
 *                                              *
 * GoBee header file        			        *
 *												*
 * Copyright 2015 Logic brainstorm              *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH IS THE PROPERTY OF Logic brainstorm	*
 * ==============================================
*/

// Description: system main structures definition
//				- Preprocessor Defines
//				- Gyro Sensor product BOARD specific constants
//				- GOBEE_PARAMS data type
//				- GYRO_FAULTS data type


/********************************************/
/* TARGET SYSTEM		 					*/
/********************************************/
#define SYSTEM_GOBEE_DIRECTOR_PROTO		1

/********************************************/
/* TARGET MOTOR		 						*/
/********************************************/
#define DC_MAXON_DC_max16S_EB_KL_6V		1
//#define DC_POLOLU							1		//test only
	
/* ARCHITECTURE	*/
#define PSOC5LP_ARCH	1	/* Select Chip CY8C5868AXI-LP035 	*/

/* PSOC5 ARCHITECTURE TYPES OVERRIDES */
#if PSOC5LP_ARCH
#define bit uint8
#endif


/* PREPROCESSOR SENSORS SELECTION */
#define ITG_3701_ENABLED	0	/* If defined (1) ITG-3701 is Enabled				*/
								/* Actually ITG-3701 is DISABLED (0)				*/

#define IMU_UM7_ENABLED		0	/* If defined (1) IMU-UM7 is Enabled				*/
								/* Actually IMU-UM7 is ENABLED (1)					*/

#define IMU_YAW_ELABORATION   0	/* If defined (1) YAW IMU elaboration is Enabled	*/
								/* Actually YAW IMU elaboration is DISABLED (0)		*/
#define IMU_PITCH_ELABORATION 0	/* If defined (1) PITCH IMU elaboration is Enabled	*/
								/* Actually PITCH IMU elaboration is ENABLED (1)	*/
#define IMU_ROLL_ELABORATION  0	/* If defined (1) ROLL IMU elaboration is Enabled	*/
								/* Actually ROLL IMU elaboration is ENABLED (1)		*/

/* Control Sampling Frequency & DELTA T */
#define SAMPLING_FREQ			1500			/* isr_CTRL Frequency			  [Hz]	*/
#define DeltaT_const			0.000666667		/* DeltaT_const = 1/isr_CTRL freq [sec] */
												/* isr_CTRL freq = 1500Hz		  		*/

/* Heading Sensors Sampling Frequency & DELTA T	*/
#define HEADING_SAMPLING_FREQ	100				/* isr_EVENTS_IDENTIF Frequency	[Hz]	*/
#define H_DeltaT_const			0.01			/* H_DeltaT_const = 0.01 [sec] 			*/


#if DC_MAXON_DC_max16S_EB_KL_6V
#define VJOYSTICK_SPEED			1				/* Virtual Joystick Speed Increment 	*/
												/* 1 = 1500 [step/sec]					*/
#endif

#if DC_POLOLU
#define VJOYSTICK_SPEED			1				/* Virtual Joystick Speed Increment 	*/
												/* 1 = 1500 [step/sec]					*/	
#endif

/* MECHA CONSTANTS */
#if DC_MAXON_DC_max16S_EB_KL_6V
#define PAN_ENCODER_RESOLUTION_X4	4096		/* [step/2PI] MAXON ENX10 EASY 1024IMP (1024x4=4096 step) */
#define TILT_ENCODER_RESOLUTION_X4	4096		/* [step/2PI] MAXON ENX10 EASY 1024IMP (1024x4=4096 step) */

#define PAN_GEAR_RATIO				62.0		/* MAXON GPX19 LZ  62:1 Planetary Gearhead				  */
#define TILT_GEAR_RATIO				172.0		/* MAXON GPX19 LZ 172:1 Planetary Gearhead				  */
#endif

#if DC_POLOLU
#define PAN_ENCODER_RESOLUTION_X4	12			/* Pololu #3081 Magnetic Encoder 12CPR		*/
#define TILT_ENCODER_RESOLUTION_X4	12			/* Pololu #3081 Magnetic Encoder 12CPR		*/

//#define PAN_GEAR_RATIO				100.37		/* Pololu #2204 100:1 Micro Metal Gearmotor	Low Power	VALORE ORIGINALE SUL PROTOTIPO	*/
#define PAN_GEAR_RATIO				50.0		/* Pololu 50:1 Micro Metal Gearmotor Low Power				*/	
#define TILT_GEAR_RATIO				297.92		/* Pololu #2385 298:1 Micro Metal Gearmotor	Medium Power	*/
#endif

/* ELEC CONSTANTS */
//--------------------------------------------------------------------------------------------------------------------
// Rsense = 0,135[Ohm]; Analog Gain = 25,9; --> V[ADC] = 0,135[Ohm] * 1,48 [A] * 25,9 = 5,17[V] (about ADC FULL SCALE)
//    	[A @ 5V] = 1,48[A] * 5[V]/5,17[V] = 1,431 [A] @ 5V
// --> AMPERE_OVER_ADC_CONST = 1,431[A]/4096 = 0.00034936523
// --> AMPERE_OVER_ADC_CONST = 1,431[A]/2048 = 0.00069873047
// --> I[A] = AMPERE_OVER_ADC_CONST * (ADC_Count + 2048) 
//
//--------------------------------------------------------------------------------------------------------------------
// Rsense = 0,39[Ohm]; Analog Gain = 25,9; --> V[ADC] = 0,39[Ohm] * 0,5 [A] * 25,9 = 5,05[V] (about ADC FULL SCALE)
//    	[A @ 5V] = 0,5[A] * 5[V]/5,05[V] = 0,495 [A] @ 5V
// --> AMPERE_OVER_ADC_CONST = 0,495[A]/4096 = 0.00012084961
// --> AMPERE_OVER_ADC_CONST = 0,495[A]/2048 = 0.00024169923
// --> I[A] = AMPERE_OVER_ADC_CONST * (ADC_Count + 2048) 
//
//--------------------------------------------------------------------------------------------------------------------
#define RSENSE						0.135			/* [Ohm] Current Sensing Resistor 					*/
#define IMAX						1.48			/* [A] Maximum Current = 0.2/Rsense					*/
#define ANALOG_CURRENT_GAIN			25.9			/* [V/V] Analog Current Gain Amplifier path			*/
////#define AMPERE_OVER_ADC_CONST		0.00012084961	/* [A/ADC counts]								*/
//#define AMPERE_OVER_ADC_CONST		0.00024169923	/* [A/ADC counts]									*/
#define AMPERE_OVER_ADC_CONST 		0.00069873047	/* [A/ADC counts]									*/

													/* INDUCTOR	FOR DC_MAXON_DC_max16S_EB_KL_6V			*/
													/* 330uH 1A Mouser:994-RFC0810B-334KE				*/


/* PREPROCESSOR DEFINES 	*/
#define MEASURE_CONTROL_ISR 	0	/* If defined LED_OK GPIO output is used to measure			*/
									/*    the execution time of the isr_CTRL					*/

#define MEASURE_LIMIT_CTRL_ISR	0	/* If defined LED_OK GPIO output is used to measure			*/
									/*    the execution time of the isr_LIMIT_CTRL				*/

#define MEASURE_ADC_ISR 		0	/* If defined LED_OK GPIO output is used to measure 		*/
									/*    the execution time of the ADC_INT						*/

#define MEASURE_IMU_ISR 		0	/* If defined LED_OK GPIO output is used to measure 		*/
									/*    the execution time of the IMU_INT						*/
#define MEASURE_MYTEST			1	/* If defined LED_OK GPIO output is used to measure 		*/
									/*    the execution time of the MY_TEST CONSOLE LOOP		*/

#define PAN_PSEUDOABS			0	/* If defined PAN axis is pseudo-absolute:					*/
									/*   - uses quadrature encoder to get absolute position		*/
									/*   - Resets absolute position @ poweron					*/
									/*   - Don't resets Quadec PAN during DEENERGIZE			*/

/* MACHINE MODE DEFINES */
#define REMOTECONTROL_MODE		0	/* Gobee Remote Control Mode (starts deenergized)								*/
#define DIRECTOR_MODE			1	/* Gobee Director Mode (starts energized + mapping state machine activated)		*/

/* MACHINE STATES */
#define GOBEE_POWERON			0	/* Power On  Machine State: GoBee is Starting and Control values changes slowly	*/
#define GOBEE_OPERATIVE			1	/* Operative Machine State: GoBee Control is Operative							*/
#define GOBEE_TEST				2	/* Test Machine State: Gobee Control is Test Mode								*/
#define GOBEE_FAULT				3	/* FAULT     Machine State: GoBee Control is Fault!								*/
#define GOBEE_AUTOCALIBRATING	4	/* AUTOCALIBRATING  Machine State: Gyrosens Auto Calibrating from HW command	*/
#define GOBEE_ENERGIZED			5
#define GOBEE_DEENERGIZED		6


/***************************************/
/* Gyrosens Sensor Output Types		   */
/***************************************/
#define DIGITAL_LINK	0x00
#define ANALOG_LINK		0x01


/*****************************/
/* Axes defines				 */
/*****************************/
#define PAN_AXIS		0x00
#define TILT_AXIS		0x01
#define ROLL_AXIS		0x02
#define ZOOM_AXIS		0x03
#define FOCUS_AXIS		0x04	


/***************************************/
/* Gyrosens Tilt Estimation Types	   */
/***************************************/
#define TILT_ESTIM_APPROX			0x00		/* TILT Estimation with sin(x)=x approssimation						*/
#define TILT_ESTIM_LIMITED			0x01		/* TILT Estimation with sin(x)=x approssimation limited	+-25°		*/
#define TILT_ESTIM_LASTGOODT		0x02		/* TILT Estimation with tilt(t*): t*=last t when sqrt(ax^2+ay^2)=g	*/
#define TILT_ESTIM_ZERO				0x03		/* TILT Estimation zero (accelerometer estimated_angle=0 fixed) 	*/
#define TILT_ADIS_Y_THETA_ANGLE		0x04		/* TILT Estimation with ADIS16210 Y=TILT (theta) angle CALIBRATED	*/


/* ANALOG GYRO MESSAGES CONSOLE --> ISR_CTRL */
#define AGYRO_MEAN_NOP		0		/* ANALOG GYRO: Mean Value Calculus NO OPERATION		*/
#define AGYRO_MEAN_START	1		/* ANALOG GYRO: START Real Time Mean Value Calculus 	*/
#define AGYRO_MEAN_STARTED  2		/* ANALOG GYRO: Real Time Mean Value Calculus STARTED	*/
#define AGYRO_MEAN_STOP		3		/* ANALOG GYRO: Mean Value Calculus STOP				*/


/* DIGITAL GYRO MESSAGES CONSOLE --> ISR_CTRL */
#define DGYRO_MEAN_NOP		0		/* DIGITAL GYRO: Mean Value Calculus NO OPERATION		*/
#define DGYRO_MEAN_START	1		/* DIGITAL GYRO: START Real Time Mean Value Calculus 	*/
#define DGYRO_MEAN_STARTED  2		/* DIGITAL GYRO: Real Time Mean Value Calculus STARTED	*/
#define DGYRO_MEAN_STOP		3		/* DIGITAL GYRO: Mean Value Calculus STOP				*/


/* PRODUCT SPECIFICS CONSTANTS 	*/
#define ADC_MUX_LENGHT  		9	  	/* Maximum ADC inputs					 			*/
#define ADC_RESOLUTION			12		/* ADC is setted to 12 bits							*/
#define ADC_MAX_COUNTS          4095    /* ADC MAXIMUM counts                               */
#define ADC_MAX_POS				2047	/* ADC MAXIMUM positive number						*/
#define ADC_ACC_ZERO_OFFSET		819		/* ADC ZERO Offset from 2.5V to 1.5V (Acceler.)		*/
#define ADC_ASTIM_ZERO_OFFSET	410		/* ADC ZERO Offset from 0V to 4V (Astim)			*/
#define ADC_CURR_ZERO_OFFSET	2048	/* ADC ZERO Offset from 0V to 5V (current)			*/
#define MAX_STARS				48		/* Hystogram Visualization MAXIMUM star lenght 		*/


/* ADC ANALOG INPUTS defines */
#define SENSE_IPAN  		0
#define SENSE_ITILT	        1
#define SENSE_VCC   		2
#define ADXL_X				3
#define ADXL_Y				4
#define ADXL_Z				5
#define HOME_PAN_ABSV		6
#define HOME_TILT_ABSV		7
#define CTRL_IN_ASTIM		8

/* STATUS REG MOTORS defines */
#define SR_PAN_MOT_FL	1
#define SR_TILT_MOT_FL	2
#define SR_HOME_PAN		4
#define SR_HOME_TILT	8

/* CONTROL LOOP	PROFILE DEFINES	*/								
#define ASTIM_CALC_INLOOP		1	/* If defined ASTIM Calc is done in Motor Control Loop		*/	

/* AUTOSTIM TYPES 			*/
#define	NO_ASTIM				0	/* AUTOSTIM NONE											*/
#define SINE_ASTIM				1	/* SINE ASTIM ON											*/
#define TRIANGLE_ASTIM			2	/* TRIANGLE ASTIM ON										*/
#define SQUARE_ASTIM			3	/* SQUARE ASTIM ON											*/
#define ASTIM_DISABLED			0	/* AUTOSTIM ISABLED											*/
#define ASTIM_ENABLED			1	/* AUTOSTIM ENABLED											*/

/* AUTOSTIM ZEROCROSS FLAG 	*/
#define ASTIM_ZC_SYNC_TODO 		0	/* AUTOSTIMOLUS ZERO CROSSING SYNC TO DO					*/
#define ASTIM_ZC_SYNC_OK		5	/* AUTOSTIMOLUS ZERO CROSSING SYNC DONE						*/

/* ANAOUT COLORS 			*/
#define GYRO_RATE				0	/* analog gyro(t) rate						 				*/
#define SLAVE_ENC_POS			1	/* encoder slave position(t)								*/
#define SLAVE_ENC_VEL			2	/* encoder slave velocity(t)								*/
#define ASTIM_IN				3	/* astim(t)									 				*/
#define CTRL_ERROR				4	/* e(t) 									 				*/
#define CTRL_DERROR				5	/* de(t)/dt									 				*/
#define CTRL_IERROR				6	/* integral(e(t))							 				*/
#define CTRL_AZIERROR			7	/* Ki * integral(e(t)) (gyro OFF)			 				*/
#define CTRL_CV					8	/* cv(t)									 				*/


#define PWON_MAX_STEPS  300				/* Power ON Maximum Steps to slow down control_var	*/
										/* @150Hz control interrupt gives 2 seconds of		*/
										/* slow control										*/
										
#define LED_OK_FAST			10			/* LED_OK blinking period for POWERON state	  (200/10  * 0.5 = 10Hz @ 200Hz clock	*/
#define LED_OK_SLOW			100			/* LED_OK blinking period for OPERATIVE state (200/100 * 0.5 =  1Hz @ 200Hz clock  */
#define LED_OK_CALIBRATING	5			/* LED_OK blinking period for CALIBRATING state (100/5  * 0.5 = 10Hz @ 100Hz clock	*/
#define LED_OK_OPERATIVE	50			/* LED_OK blinking period for OPERATIVE state   (100/50 * 0.5 =  1Hz @ 100Hz clock  */


/* Pushbutton defines */
#define PUSH_ON			0x01
#define PUSH_CW			0x02
#define PUSH_CCW		0x04

/* Buzzer defines */
#define BUZZER_ON		0x01
#define BUZZER_OFF		0x00

// RTNBC FUNCTION TABLE
#define RTNBC_FUNCTION_OFF			0
#define RTNBC_FUNCTION_ON			1


/* ASTIM WAVES */
#define WaveDAC8_WAVE_SINE_LENGTH   	3333   /* Length for sine wave 		*/
#define WaveDAC8_WAVE_TRIANGLE_LENGTH   3333   /* Length for triangle wave 	*/
#define WaveDAC8_WAVE_SQUARE_LENGTH     3333   /* Length for square wave 	*/


// tipo di dato floatEE
// (serve per facilitare la lettura/scrittura di un float su EEPROM)
typedef union
	{
		char8 fbyte[sizeof(float)];		/* byte view (sizeof(float) = 4 */
		float fnum;						/* float view					*/
	} floatEE;
	
	
// tipo di dato uint16a
// (serve per poter leggere un uint16 come due bytes)
typedef union
	{
		uint8 byte[2];					/* byte view					*/
		uint16 word;					/* word view					*/
	} uint16a;

	
//// tipo di dato VPARAMS (volatile)	
//struct GOBEE_VPARAMS
//	{	
//		//uint8 DAS_PrintfOverConsole; 	/* Data Acquisition System Printf over console	*/
//										/*  0 --> Disabled								*/
//										/*  1 --> Enabled								*/							
//	} gobee_vparam;
	
// tipo di dato GOBEE_PARAMS
struct GOBEE_PARAMS
	{
		uint8 mode;					/* Machine Mode (default=0)						*/
									/*		0 --> REMOTE CONTROL MODE				*/
									/*		1 --> DIRECTOR       MODE				*/
		
		uint8 director;				/* Director Number (from Akira to JJ)			*/

		floatEE beta;				/* Analog Accelerometer Low Pass Filter			*/
									/* beta coefficient								*/
									/* tau = deltaT * (1 - beta)/beta				*/
				
		int16 x_acc_ADC_offset;		/* ANALOG ACCELEROMETER X AXIS ADC Offset		*/
		int16 y_acc_ADC_offset;		/* ANALOG ACCELEROMETER Y AXIS ADC Offset		*/
		int16 z_acc_ADC_offset;		/* ANALOG ACCELEROMETER Z AXIS ADC Offset		*/
		
				
		/* EVENTS IDENTIFICATION PARAMS */
		floatEE	jump_g_threshold;		/* bike jump event identification threshold [g]				*/
		floatEE acc_g_threshold;		/* bike acceleration event identification threshold [g]		*/
	};


// tipo di dato GOBEE_FAULTS
struct GOBEE_FAULTS
	{
		uint16  general;				/* General Faults Flags (0=NO FAULTS) 				*/
		uint8   FbkEncFaults;			/* Feedback Encoders transition Faults				*/
			
		uint8 pan_FE_FAULT_prescaler;	/* Antiglitch prescaler for PAN Feedback FAULT		*/ 
		uint8 tilt_FE_FAULT_prescaler;	/* Antiglitch prescaler for TILT Feedback FAULT		*/ 				
	};
	
/* GENERAL FAULT FLAGS */
#define GEN_NOFAULTS		 0x0000	/* General NO FAULTS							*/
#define GEN_LOWVCC_FAULT	 0x0001	/* Input voltage <= 6.5V   	      				*/
#define GEN_FBKENC_FAULT	 0x0002	/* Feedback Encoders Invalid Transition   	    */
#define GEN_INTERNAL_FAULT	 0x0004	/* General Internal Fault Flag					*/	
#define GEN_PAN_FAULT  		 0x0008	/* PAN GENERAL FAULT							*/
#define GEN_TILT_FAULT  	 0x0010	/* TILT GENERAL FAULT							*/	
#define GEN_ROLL_FAULT	  	 0x0020	/* ROLL GENERAL FAULT							*/
#define GEN_LORA_FAULT	  	 0x0040	/* LORA WIRELESS CONNECTION GENERAL FAULT		*/
#define GEN_IMU_FAULT	  	 0x0080	/* IMU SENSOR GENERAL FAULT						*/	
	
/* Encoder Invalid Transition Fault Flags */
#define PAN_FBKENC_INVT_FAULT	0x01	/* PAN Feedback Encoder Invalid Transition	*/
#define TILT_FBKENC_INVT_FAULT	0x02	/* TILT Feedback Encoder Invalid Transition	*/	
#define ROLL_FBKENC_INVT_FAULT	0x04	/* ROLL Feedback Encoder Invalid Transition	*/			

	
// tipo di dato ANALOG_GYRO
struct ANALOG_GYRO
	{
		/* ADXRS646 analog external gyroscope vars */
		int16 ADC_offset;					/* analog gyroscope ADC offset						*/
		int16 ADC;							/* analog gyroscope ADC value signed				*/
		float scale;						/* gyro scale from ADC to [deg/sec]					*/
		float rate;							/* analog gyroscope float rate      [deg/sec]		*/
		float rate_lowpass;					/* LPF(analog gyro) float rate	    [deg/sec]		*/
		float mean_rate;					/* analog gyro rate mean(t)		    [deg/sec]		*/
		float mean_rate_previous;			/* analog gyro ratìe mean(t-1)	    [deg/sec]		*/
		float angle;						/* analog gyro estimated angle(t)   [deg]			*/
	};

	
// tipo di dato ANALOG_3D_ACCELEROMETER
struct ANALOG_3D_ACCELEROMETER
	{
		/* ADXL325 analog 3D gyroscope vars */
		struct X_AXIS
		{
			int16 ADC;				/* analog accelerometer ADC raw signed		*/			
			float scale;			/* scale from ADC lsb to [g]				*/
			float acceleration;		/* acceleration float value [g]				*/
			float acceleration_lpf;	/* LPF(acceleration) float value [g]		*/
		}x_axis;
		
		struct Y_AXIS
		{
			int16 ADC;				/* analog accelerometer ADC raw signed		*/
			float scale;			/* scale from ADC lsb to [g]				*/
			float acceleration;		/* acceleration float value [g]				*/	
			float acceleration_lpf;	/* LPF(acceleration) float value [g]		*/
		}y_axis;
		
		struct Z_AXIS
		{
			int16 ADC;				/* analog accelerometer ADC raw signed		*/		
			float scale;			/* scale from ADC lsb to [g]				*/
			float acceleration;		/* acceleration float value [g]				*/	
			float acceleration_lpf;	/* LPF(acceleration) float value [g]		*/

		}z_axis;

		float squared;					/* x_g^2 + y_gC^2 + z_g^2			*/
		float modulo;					/* sqrt(x_g^2 + y_gC^2 + z_g^2)		*/
		float system_dynamic_scalar;	/* x_g^2 + y_gC^2 + z_g^2 - (1_g)^2	*/
	};

	
// tipo di dato ENCODER
struct ENCODER
	{
		int32	position;			/* Encoder Position(t) 		[step]		*/
		float   velocity;			/* Encoder Velocity(t)		[step/sec]	*/
		float	angle;				/* Encoder angle(t) 		[deg]		*/
		float	angular_velocity;	/* Encoder Angular Velocity [deg/sec]	*/	
		
		struct ENC_PARAMETER
		{
			int32	resolution;		/* Encoder Resolution	[x4step/360deg]	*/
									/* Es.									*/
									/* IEH2-4096 = 4096 step/2PI			*/
									/* ---> resolution = 16384 				*/
		}param;
	};
	
	
// tipo di dato ABSOLUTE POSITION SENSOR
struct ABSPOS_SENSOR
	{
		//vars
		int16	raw;						/* raw position ADC value 12bit								*/
											/*   raw = + adc_value	if not inverted						*/
											/*   raw = - adc_value	if inverted		 					*/
		float	position;					/* Encoder Position(t) 		[float step]					*/
		float   velocity;					/* Encoder Velocity(t)		[step/sec]						*/
		float	angle;						/* Encoder angle(t) 		[deg]							*/
		float	angle_rad;					/* Encoder angle(t) 		[rad]							*/		
		float	angular_velocity;			/* Encoder Angular Velocity [deg/sec]						*/	
		
		//calibration  
		int32   slave_encoder_step_p0;		/* Slave Encoder Point Zero	[step]							*/
		int32   raw_adc_p0;					/* Absolute Sensor Position Point Zero raw adc [lsb]		*/
		float	sample_d1;					/* Absolute Sensor Sampled Difference 1 [float step]		*/
		float	sample_d2;					/* Absolute Sensor Sampled Difference 2 [float lsb]			*/	
		float   ratio_tmp;					/* Encoder/Absolute Position temporary value 				*/

		//params
		struct ABPOS_SENS_PARAMETER
		{
			uint8	raw_invertion;			/* if 1 raw_pos is inverted copy of raw_adc					*/
			int16	raw_home;				/* raw home (zero)    position ADC value 12bit				*/
			int16	raw_limit_max;			/* raw limit maximum  position ADC value 12 bit				*/
			int16	raw_limit_min;			/* raw limit minimum  position ADC value 12 bit				*/
			int16	raw_limit_hysteresis;	/* raw limit hysteresis										*/
			floatEE step_over_abs_ratio;	/* Encoder/Absolute Position [step/ADC counts]				*/
		}param;
	};	
	
// tipo di dato IMU HEADING SENSOR
struct IMU_SENSOR
	{
		/* Vehicle Frame (bike frame) EULER ANGLES	(BIKE HEADING ESTIMATION)	*/
		float bike_yaw ;				/* YAW   IMU angle			[deg]		*/
	    float bike_pitch ;				/* PITCH IMU angle			[deg]		*/
        float bike_roll ;				/* ROLL  IMU angle			[deg]		*/		
		float bike_yaw_lpf ;			/* LPF(YAW   IMU angle)		[deg]		*/
	    float bike_pitch_lpf ;			/* LPF(PITCH IMU angle)		[deg]		*/
        float bike_roll_lpf ;			/* LPF(ROLL  IMU angle)		[deg]		*/

		/* Camera Frame EULER ANGLES (Real Time CAMERA STABILIZATION)				*/
		float cam_gyropan;				/* camera Pan/Yaw    position [float_steps]	*/
		float cam_gyrotilt;				/* camera Tilt/Pitch position [float_stps]	*/
		float cam_gyroroll;				/* camera Roll/Roll  position [float_stps]	*/
		
		//params
		struct IMU_SENS_PARAMETER
		{
			uint8	yaw_invertion;		/* yaw   angle invertion (1 = inverted)	*/
			uint8	pitch_invertion;	/* pitch angle invertion (1 = inverted)	*/			
			uint8	roll_invertion;		/* roll  angle invertion (1 = inverted)	*/
			
			uint8	pitch_roll_exchange;/* pitch angle exchanged with roll 		*/
	
			floatEE gamma;				/* IMU Euler Angles Low Pass Filter		*/
										/* gamma coefficient					*/
										/* tau = deltaT * (1 - gamma)/gamma		*/
		}param;		
	};

	
// tipo di dato MOTOR AXIS
struct MOTOR_AXIS
	{
		/* Axis Volatile Parameters				*/	
		struct VPARAMS
		{	
		uint8 astim_enable;				/* Autostimolous Enable Volatile (DEFAULT=0)	*/	
										/* 		0 --> OFF								*/
										/*		1 --> ON								*/			
			
		uint8 astim_type;				/* Autostimolous Type Volatile (DEFAULT=0)		*/
										/* 		0 --> NONE								*/
										/*		1 --> SINE								*/
										/*		2 --> TRIANGLE							*/	
										/*		3 --> SQUARE							*/	
			
		float resolution_step_deg;		/* R = Resolution of the MOTOR Axis	[step/deg]	*/
		float resolution_rad_step;		/* R = Resolution of the MOTOR Axis	[rad/step]	*/
			
		} vparam;
		
		/* Axis EEPROM (NonVolatile) Parameters	*/
		struct PARAMS
			{		
			floatEE resolution;			/* R = Resolution of the MOTOR Axis	[step/giro]		*/
										/* Es.												*/
										/* N = 22  (rapporto di riduzione)					*/
										/* E = 16384 (risoluzione encoder di feedback x4)	*/
										/* R = N*E = 22 * 8192 = 360.448 [step/giro]		*/
																			
			uint8 polarity;				/* Output DACs volatage Polarity (default=0)	*/
										/*		0 --> Output DAC true					*/
										/*		1 --> Output DAC inverted				*/						
																	
			floatEE Kpf;				/* Kp float										*/

			floatEE Kdf;				/* Kd float										*/		
			
			floatEE Kif;				/* Ki float										*/	
			
			floatEE Ksif;				/* Ksi float (integral Saturation) 				*/
										/*												*/
										/*  Maximum Integral Action = Ki * Ksi			*/

			floatEE Kopf;				/* K Open Loop Float (ASTIM)					*/
				
			floatEE Gain_ANAOUT;		/* ANALOG OUTPUT (VDAC8_ANAPOS) GAIN			*/	
				
			uint8 color;				/* ANALOG OUTPUT (VDAC8_ANAPOS) Selected Value  */
										/*		0 --> BACKSLASH							*/
										/*		1 --> SLAVE(FEEDBACK)					*/
				
			uint8 limit_control;		/* Coarse Limit Control Functions				*/
										/*		0 --> LIMIT CONTROL DISABLED			*/
										/*		1 --> LIMIT CONTROL ENABLED				*/
				
			floatEE	limit_deceleration_factor;	/* master and joy Deceleration Factor	*/
				
			} param;


		/* Motor Control Real Time Datas	*/
		struct MCDATAS 
			{			
			int32 master_enc_position;		/* Axis master_encoder(t)	[step]					*/
			int32 master_enc_sample_delta;	/* master_enc_sample(t) - master_enc_sample(t-1)	*/
			//int32 master_enc_sample;		/* master_enc_sample(t) sampled [steps]				*/
			//int32 master_enc_sample_bef;	/* master_enc_sample(t-1) [steps]					*/
			//float master_enc_steps_lowpass; /* Axis LPF(master_encoder(t)) [float steps]		*/			
				
			int32 master_joy_position;		/* Axis master_joystick(t) [steps]					*/
			int32 master_joy_sample_delta;	/* master_joy_sample(t) - master_joy_sample(t-1)	*/					
			//int32 master_joy_sample;		/* master_joy_sample(t) sampled [steps]				*/
			//int32 master_joy_sample_bef;	/* master_joy_sample(t-1) [steps]					*/				
			//float master_joy_value_lowpass; /* Axis LPF(master_joystick_value(t)) [steps/sec]	*/	
				
			struct ENCODER slave_enc;		/* Axis slave Encoder								*/

			float error;				/* Axis error(t) = master_encoder(t) - slave_encoder(t)	*/
			float error_bef;			/* Axis error(t-1)  									*/
			float ierror;				/* Axis integral(error(t))								*/
			float derror;				/* Axis d/dt(error)										*/
			float derivative_lowpass;	/* LPF(Kd*(e(t)-e(t-1)))								*/
			float deadband_factor;		/* e(t) deadband factor									*/					

			float ctrl_var;				/* Axis motor control var(t) 							*/
			int16 pwm_var;				/* Motor PWM Output Variable(t) = f(cv(t))				*/
			int16 pwm_test_var;			/* Motor PWM Output Variable(t) = f(cv(t)) TEST MODE	*/
				
			float current;				/* motor i(t)											*/	
				
			float Float_ASTIM;			/* Float Autostimolus Input Value						*/
			uint8 astim_ZCsync;			/* Autostimulus Zero Crossing Sync						*/				
			} mc;
			
		/* Motor Axis Limit Control		*/
		struct LIMITCONTROL
			{	
				uint8 status;						/* Axis Limit Control Status; 0 = NO LIMITS REACHED				*/
				float master_limit_delta;			/* Master(t) - LPF(master(t)) when Limits Reached [float steps] */
				float deceleration_factor;			/* Axis Deceleration Factor after Limit Reached					*/				
			} lc;			
	};

// tipo di dato EVENT
struct EVENTS
	{
		uint8  mapping_sm_status;	/* MAPPING State Machine Status					*/
		
		struct TIMECODE
		{
			uint32	dsec;			/* Virtual Timecode [1/10 sec]					*/
			uint32	sec;			/* Virtual Timecode [sec]						*/
			uint32  on_origin_ticks;	/* On Origin 100Hz ticks					*/ 
		}timecode;
		
		struct INERTIAL
		{
			uint8	tilt_angle;		/* Tilt Angle Event	[DESCENT, CLIMB, etc...]	*/
			uint8	roll_angle;		/* Roll Angle Event	[DESCENT, CLIMB, etc...]	*/			
			uint8	jump;			/* Jump Event [yes/no]							*/
			uint8   acceleration;	/* Acceleration/Deceleration Event [yes/no]		*/
			uint8	vibration;		/* Vibration Event [HIGH_VIBRATION,..]			*/
		}inertial;
		
	};
	
/* MAPPING State Machine States		*/	
#define SM_ON_ORIGIN			0
#define SM_MOVING_TO_FACE		1
#define SM_ON_FACE				2
#define SM_MOVING_TO_ORIGIN		3
#define SM_MOVING_PANORAMIC		4
#define SM_MOVING_JUMP			5	
#define SM_MOVING_TO_WHEEL		6
#define SM_ON_WHEEL				7
	
#define SM_STANDBY				99 
	
	
/* Eulero Angles defines */
#define	ANGLE_NOT_INVERTED		0
#define ANGLE_INVERTED			1
	
/* Bike angles defines */
#define ANGLES_NOT_EXCHANGED	0	/* bike pitch and roll euler angles are not exchanged */	
#define ANGLES_EXCHANGED		1	/* bike pitch and roll euler angles are     exchanged */	

	
/* DIRECTORS DEFINES	*/	
#define	STANLEY				0	/* Kubrick	 	*/
#define ALFRED				1	/* Hitchcock 	*/
#define DE_PALMA			2	/* Brian		*/
#define CHARLIE				3	/* Chaplin		*/
#define LINCH				4	/* David		*/
#define COPPOLA				5	/* Francis Ford	*/
#define MARTIN				6	/* Scorsese		*/
#define QUENTIN				7	/* Tarantino	*/
#define RIDLEY				8	/* Scott		*/
#define SERGIO				9	/* Leone		*/
#define STEVEN				10  /* Spielberg 	*/
#define TIM					11	/* Burton		*/
#define WES					12	/* Craven		*/
#define FEDERICO			13	/* Fellini		*/
#define JOHN				14	/* Ford			*/
#define CRISTOPHER			15	/* Nolan		*/
#define GUILLERMO			16  /* Del Toro		*/
#define GEORGE				17	/* Lucas		*/
#define JJ					18	/* Abrams		*/

	
//[] END OF FILE
