/* ========================================
 *
 * Copyright Logic brainstorm, 2015
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your logic brainstorm.
 *
 * ========================================
*/

#include <device.h>
#include <gobee.h>
#include <gobeelib.h>
#include <math.h>

/* extern Control Variables */
extern uint8 machine_state;		/* Machine State Global						*/

extern float error;				/* Sensor error(t) 	  						*/
extern float error_lowpass;		/* Sensor error(t) low pass filtered		*/
extern float alpha;				/* low pass filter alpha value				*/

extern float error_bef;			/* Sensor error(t-1)  						*/
extern float derror;			/* Sensor d/dt(error)						*/
extern float ierror;			/* Sensor Integral(error(t))				*/

extern int16 control_var;		/* cv(t) = Kp*angle(t)			  			*/
extern uint16 angle_var;		/* Angle Compensation DAC variable			*/
extern int16  angle_digi;		/* Angle Compensation SPI variable			*/

extern int16 VSenseMAX;			/* Maximum Sensor Array ADC Voltage			*/
extern int16 VSenseSUM;			/* Sum of all Sensor Array ADC Voltage		*/

extern int16 Encoder_now;		/* Driver Motor Encoder(t)					*/
extern int16 Encoder_bef;		/* Driver Motor Encoder(t-1)				*/
extern int16 DriveVelocity;		/* Driver Motor Velocity(t)					*/


/* extern Sensor ADC array */
extern int16 AdcValue[ADC_MUX_LENGHT];


/* extern Analog ADXL325 3D accelerometer vars) */
struct ANALOG_3D_ACCELEROMETER aacc;

//extern signed long system_dynamic_scalar;	/* x_acc_ADC^2 + y_acc_ADC^2 - (1g_ADC)^2	*/


/* extern IMU UM7 vars */ 
#if IMU_UM7_ENABLED
extern EULER_ANGLES euler_angles; 		/* Struttura in cui vengono messi gli angoli di Eulero misurati dallo SpacePoint */
#endif

/* extern IMU sensor vars */
extern struct IMU_SENSOR	IMU_sensor;		/* Struttura dei dati della IMU */


/* extern Analog External ADXRS646 gyroscope vars) */
extern struct ANALOG_GYRO agyro;

/* extern ADXRS453 digital gyroscope vars	*/
extern float dgyro_rate_float;		/* ADXRS453 Digital Gyro Rate (float) [deg/sec] 	*/
extern float dgyro_mean;			/* digital gyro raw mean_value(t)					*/
extern float dgyro_mean_previous;	/* digital gyro raw mean_value(t-1)					*/
extern float dgyro_mean_of;			/* digital gyro ofsetted mean_value(t)				*/
extern float dgyro_mean_previous_of;/* digital gyro ofsetted mean_value(t-1)			*/
extern uint32 dg_iteration;			/* digital gyro mean value iteration counter		*/
extern uint8 dgyro_messg;			/* digital gyro message passing console --> isr_ctrl*/

/* extern estimated control vars */
extern float angle;				/* Complementary Filter Estimated angle float [deg]	*/
extern float angle_lowpass;
extern float angle_estim;	

///* external ITG-3701 digital gyro vars */
//extern float gRes;      				// scale resolutions per LSB for the sensors
//extern int16 gyroCount[3];  			// Stores the 16-bit signed gyro output
//extern float gx, gy, gz; 				// variables to hold latest sensor data values 
//extern float gyroBias[3];			 	// Bias corrections for gyro, accelerometer, and magnetometer
//extern float temperature;          		// Stores the ITG3701yro internal chip temperature in degrees Celsius

/* extern GOBEE param structure */
extern struct GOBEE_PARAMS gobee_param;
 

/* Local vars Definition */
uint8 idx = 0;					/* all pourpose index							*/
uint8 dummy = 0;				/* Dummy Local									*/
uint8 idxMAX = 0;				/* index: Vsense(index)=VSenseMAX				*/
uint8 QuadDecEvent = 0;			/* Quadrature Encoder Status Register Shadow 	*/

float dgyro_offset_fine;


/************************************************************/
/* GoBee Real Time CONTROL SENSORS Sampling & Control 		*/
/*   Control sensors are used for Gimbal Real Time Control	*/
/*   (isr_CTRL.c  1500Hz)									*/
/************************************************************/
void Control_sensors_processing(void)
{
	/************************************************/
	/*** IMU UM7-LT build packet 					*/
	/*** deve essere chiamata almeno 15 volte per 	*/
	/************************************************/
#if IMU_UM7_ENABLED	
	IMU_UM7_CheckForEulerPacket(&euler_angles);
#endif	

	/************************************************/
	/*** IMU UM7-LT YAW elaboration 				*/
	/************************************************/
#if IMU_YAW_ELABORATION
	if (IMU_sensor.param.yaw_invertion == ANGLE_NOT_INVERTED)
	{
		IMU_sensor.bike_yaw = euler_angles.psi;	
	}
	else	//ANGLE INVERTED
	{
		IMU_sensor.bike_yaw = -euler_angles.psi;	
	}	

	/****************************************************************************/
	/* IMU_sensor.bike_yaw: Exponential error smoothing function				*/
	/* (exactly like RC first order low pass filter) 							*/
	/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
	/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
	/*																			*/
	/* tau = deltaT *(1 - gamma)/gamma											*/
	/*       deltaT = 666.7 usec @ 1500Hz										*/
	/*		 gamma  = 0.0005													*/
	/*		 --> tau = 1,33 sec (fc = 2 * 3.14 / tau = 4.71Hz)					*/
	/****************************************************************************/
	/* gamma = 1 TO BYPASS FILTER												*/
	/****************************************************************************/
	if (IMU_sensor.param.gamma.fnum == 1)
	{
		IMU_sensor.bike_yaw_lpf = IMU_sensor.bike_yaw;
	}
	else
	{
		IMU_sensor.bike_yaw_lpf = IMU_sensor.bike_yaw_lpf + (double)IMU_sensor.param.gamma.fnum * (IMU_sensor.bike_yaw - IMU_sensor.bike_yaw_lpf);
	}
#endif

#if IMU_PITCH_ELABORATION
	/************************************************/
	/*** IMU UM7-LT PITCH elaboration 				*/
	/************************************************/
	if (IMU_sensor.param.pitch_invertion == ANGLE_NOT_INVERTED)
	{
		IMU_sensor.bike_pitch = euler_angles.theta;
	}
	else	//ANGLE INVERTED
	{
		IMU_sensor.bike_pitch = -euler_angles.theta;	
	}	

	/****************************************************************************/
	/* IMU_sensor.bike_pitch: Exponential error smoothing function				*/
	/****************************************************************************/
	/* gamma = 1 TO BYPASS FILTER												*/
	/****************************************************************************/
	if (IMU_sensor.param.gamma.fnum == 1)
	{
		IMU_sensor.bike_pitch_lpf = IMU_sensor.bike_pitch;
	}
	else
	{
		IMU_sensor.bike_pitch_lpf = IMU_sensor.bike_pitch_lpf + (double)IMU_sensor.param.gamma.fnum * (IMU_sensor.bike_pitch - IMU_sensor.bike_pitch_lpf);
	}
#endif	

#if IMU_ROLL_ELABORATION
	/************************************************/
	/*** IMU UM7-LT ROLL elaboration 				*/
	/************************************************/
	if (IMU_sensor.param.roll_invertion == ANGLE_NOT_INVERTED)
	{
		IMU_sensor.bike_roll = euler_angles.phi;	
	}
	else	//ANGLE INVERTED
	{
		IMU_sensor.bike_roll = -euler_angles.phi;	
	}	

	
	/****************************************************************************/
	/* IMU_sensor.bike_pitch: Exponential error smoothing function				*/
	/****************************************************************************/
	/* gamma = 1 TO BYPASS FILTER												*/
	/****************************************************************************/
	if (IMU_sensor.param.gamma.fnum == 1)
	{
		IMU_sensor.bike_roll_lpf = IMU_sensor.bike_roll;
	}
	else
	{
		IMU_sensor.bike_roll_lpf = IMU_sensor.bike_roll_lpf + (double)IMU_sensor.param.gamma.fnum * (IMU_sensor.bike_roll - IMU_sensor.bike_roll_lpf);
	}
#endif	

	/****************************************************************************/
	/* Real Time Stabilization calculations										*/
	/****************************************************************************/
	// abs_pan_angle --> rad
	//	Function: void sincos (double x, double *sinx, double *cosx)
	//	Function: void sincosf (float x, float *sinx, float *cosx)

	// IMU_sensor.cam_gyrotilt = (IMU_sensor.bike_pitch_lpf * cos(abs_pan_angle)
	//							 + IMU_sensor.bike_roll_lpf * sin(abs_pan_angle) [deg]) * tilt_axis.vparam.resolution_step_deg [step/deg] --> [float steps]	

}        


/********************************************************/
/* Bike HEADING SENSORS Sampling & Control 				*/
/*   Heading sensors are used for Events Identification	*/
/*  (isr_EVENTS_IDENTIF.c  100Hz)						*/
/********************************************************/
void Heading_sensors_processing(void)
{
	/************************************************/
	/* ADXL325 Accelerometer Sampling and scaling	*/
	/************************************************/
	/* Sensivity = 174mV/g							*/
	/* Zero g    = 1,5V								*/
	/*												*/
	/* ADC(int16 signed)=(Vin - 2,5V)*4096/5V		*/
	/* ADC resolution = 12 bit						*/
	/* 												*/
	/*  -->       0g  = -819.2	  ADC lsb			*/
	/*	-->       1g  = -676.6592 ADC lsb			*/
	/*  --> delta(1g) = 142.5408  ADC lsb			*/
	/************************************************/
	aacc.x_axis.scale = 0.007015535;	/* 1 / [1g] = 1 / 142.5408 = 0.007015535	*/
	aacc.y_axis.scale = 0.007015535;	/* 1 / [1g] = 1 / 142.5408 = 0.007015535	*/
	aacc.z_axis.scale = 0.007015535;	/* 1 / [1g] = 1 / 142.5408 = 0.007015535	*/
	
	aacc.x_axis.ADC = AdcValue[ADXL_X] + ADC_ACC_ZERO_OFFSET ;
	aacc.y_axis.ADC = AdcValue[ADXL_Y] + ADC_ACC_ZERO_OFFSET ;
	aacc.z_axis.ADC = AdcValue[ADXL_Z] + ADC_ACC_ZERO_OFFSET ;	
	
	aacc.x_axis.acceleration = (float)(aacc.x_axis.ADC + gobee_param.x_acc_ADC_offset) * aacc.x_axis.scale; /* [g] */
	aacc.y_axis.acceleration = (float)(aacc.y_axis.ADC + gobee_param.y_acc_ADC_offset) * aacc.y_axis.scale; /* [g] */
	aacc.z_axis.acceleration = (float)(aacc.z_axis.ADC + gobee_param.z_acc_ADC_offset) * aacc.z_axis.scale; /* [g] */

	/****************************************************************************/
	/* Accelerometer Exponential error smoothing function						*/
	/* (exactly like RC first order low pass filter) 							*/
	/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
	/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
	/*																			*/
	/* tau = deltaT *(1 - beta)/beta											*/
	/*       deltaT = 666.7 usec @ 100Hz										*/
	/*		 beta  = 0.0005														*/
	/*		 --> tau = 1,33 sec (fc = 2 * 3.14 / tau = 4.71Hz)					*/
	/****************************************************************************/
	/* beta = 1 TO BYPASS FILTER												*/
	/****************************************************************************/
	if (gobee_param.beta.fnum < 1)
	{
		aacc.x_axis.acceleration_lpf = aacc.x_axis.acceleration_lpf +
									gobee_param.beta.fnum * (aacc.x_axis.acceleration - aacc.x_axis.acceleration_lpf);
		aacc.y_axis.acceleration_lpf = aacc.y_axis.acceleration_lpf +
									gobee_param.beta.fnum * (aacc.y_axis.acceleration - aacc.y_axis.acceleration_lpf);								
		aacc.z_axis.acceleration_lpf = aacc.z_axis.acceleration_lpf +
									gobee_param.beta.fnum * (aacc.z_axis.acceleration - aacc.z_axis.acceleration_lpf);									
	}
	
	/************************************************************************************/
	/* Accelerometer Modulo Calculation		 											*/
	/* 																					*/
	/*  modulo = sqrt(x_g^2 + y_g^2 + z_g^2)  [g]										*/
	/************************************************************************************/
	aacc.squared = squaref(aacc.x_axis.acceleration_lpf) +					
				   squaref(aacc.y_axis.acceleration_lpf) +		
				   squaref(aacc.z_axis.acceleration_lpf);
				
	aacc.modulo = sqrt((double)aacc.squared);		
								
	/************************************************************************************/
	/* System Dynamic Scalar Calculation	 											*/
	/* 																					*/
	/*  system dynamic_scalar = x_g^2 + y_g^2 + z_g^2 - (1_g)^2	[g^2]					*/
	/************************************************************************************/
	aacc.system_dynamic_scalar = aacc.squared - 1;
}

/* [] END OF FILE */
