/* ========================================
 *
 * Copyright Gobee Srl, 2019
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/****************************************************/
/* ESTIMATION MODEL CONSTANTS 						*/
/****************************************************/

/* Inertial  Bike Frame Pitch (Tilt) Angle defines 	*/
#define PLANE_MOTION		0
#define SIMPLE_CLIMB		10
#define STEEP_CLIMB			11
#define VERY_STEEP_CLIMB	12
#define SIMPLE_DESCENT		20
#define STEEP_DESCENT		21
#define VERY_STEEP_DESCENT	22

/* Inertial  Bike Frame Roll (Roll) Angle defines 	*/	
#define NO_ROLL						0x00	//state label
#define BIKE_SIMPLE_ROLLING			0x10	//state label
#define BIKE_ROLLING				0x11	//state label
#define BIKE_TOO_MUCH_ROLL			0x12	//state label
#define NO_ROLL_ANGLE				5.0		//[deg]
#define BIKE_SIMPLE_ROLLING_ANGLE	8.0		//[deg]
#define BIKE_ROLLING_ANGLE			12.0	//[deg]


/* Inertial bike jump defines */
#define NO_JUMP						0		//state label
#define IM_JUMPING					10		//state label
	
/* Inertial bike vibration defines */
#define NO_VIBRATION		0
#define VIBRATION			10
#define MEDIUM_VIBRATION	11
#define HIGH_VIBRATION		12
	
/* Inertial bike acceleration defines */
#define BIKE_NO_ACCELERATION	0
#define BIKE_ACCELERATING		10
#define BIKE_DECELERATING		11

/****************************************/
/* MAPPING STATE MACHINE			 	*/
/****************************************/
void MappingStateMachineExecution(void);

/****************************************/
/* MAPPING STATE MACHINE INITIALIZATION	*/
/****************************************/
void MappingStateMachineInit(void);

/****************************************/
/* MAPPING STATE MACHINE START			*/
/****************************************/
void MappingStateMachineStart(void);

/********************************************/
/* Simple Bike Jump Event Estimator			*/
/* input  : float (acc_x,y,z(t))			*/
/********************************************/
void SimpleJumpEventEstimator(float acc_x,float acc_y,float acc_z, float acc_modulo);

/********************************************************/
/* Simple Bike Horizontal Acceleration Event Estimator	*/
/* input  : float (horizontal acceleration)				*/
/********************************************************/
void SimpleHorizAccelerationEventsEstimator(float horiz_acc);

/********************************************************/
/* Simple Bike Frame Roll Angle Events Estimator		*/
/* input  : float (bike roll angle(t))					*/
/********************************************************/
void SimpleRollAngleEventsEstimator(float angle);

/********************************************/
/* Simple Bike Pitch Angle Events Estimator	*/
/* input  : float (bike pitch angle(t))		*/
/********************************************/
void SimpleTiltAngleEventsEstimator(float angle);

/********************************************/
/* Simple Bike Vibration Events Estimator	*/
/* input  : float (system dynamic scalar(t))*/
/********************************************/
void SimpleVibrationEventsEstimator(float sysdyn);


/* [] END OF FILE */
