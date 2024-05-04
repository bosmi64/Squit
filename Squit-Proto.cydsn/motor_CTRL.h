/* ========================================
 *
 * Copyright Logic Brainstorm, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Logic Brainstorm.
 *
 * ========================================
*/

///* PWM Period     = 2048 (31 usec @ 66MHz clock)	*/
///* PWM Freq       = 32,2kHz							*/
///* PWM Resolution = 11 bit	 						*/
//#define MOTOR_PWM_PERIOD_MAX	2048
//#define MOTOR_PWM_PERIOD_HALF	1024

/* PWM Period     = 1024 (15,5 usec @ 66MHz clock)	*/
/* PWM Freq       = 64,4kHz							*/
/* PWM Resolution = 10 bit	 						*/
#define MOTOR_PWM_PERIOD_MAX	1024
#define MOTOR_PWM_PERIOD_HALF	512

/* limit control status defines */
#define COARSE_BETWEEN_LIMITS_OK	0
#define NEGATIVE_LIMIT_REACHED		1
#define POSITIVE_LIMIT_REACHED		2

#define LIMIT_CONTROL_DISABLED		0
#define LIMIT_CONTROL_ENABLED		1

/* Absolute sensor defines */
#define ABS_SENSOR_TRUE				0
#define ABS_SENSOR_INVERTED			1


/* GoBee Limit Control Functions */
void Axis_limit_control_init(void);
void Axis_limit_control(struct MOTOR_AXIS *paxis, struct ABSPOS_SENSOR *abs_sens);
void All_Axes_limit_control(void);


/* GoBee Motor Control Functions */
void motor_control(struct MOTOR_AXIS *paxis, mover_type *mover);
void motor_init(struct MOTOR_AXIS *paxis);
void motor_energize(struct MOTOR_AXIS *paxis);
void motor_sleep(struct MOTOR_AXIS *paxis);

/********************************************************************/
/* GALIL TRICK														*/
/********************************************************************/
void GalilTrick(struct MOTOR_AXIS *paxis);

/********************************************************************/
/* ANAPOS OR ANAVEL SHOW											*/
/* DAC_ANAOUT <-- Selected ENCODER	* Gain_ANAOUT					*/
/*			  <-- d/dt(Selected ENCODER) * Gain_ANAOUT				*/
/********************************************************************/
void AnalogShow(struct MOTOR_AXIS *paxis);

//[] END OF FILE
