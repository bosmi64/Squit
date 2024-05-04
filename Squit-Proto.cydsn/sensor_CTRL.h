/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/************************************************************/
/* GoBee Real Time CONTROL SENSORS Sampling & Control 		*/
/*   Control sensors are used for Gimbal Real Time Control	*/
/*   (isr_CTRL.c  1500Hz)									*/
/************************************************************/
void Control_sensors_processing(void);

/********************************************************/
/* Bike HEADING SENSORS Sampling & Control 				*/
/*   Heading sensors are used for Events Identification	*/
/*  (isr_EVENTS_IDENTIF.c  100Hz)						*/
/********************************************************/
void Heading_sensors_processing(void);


//[] END OF FILE
