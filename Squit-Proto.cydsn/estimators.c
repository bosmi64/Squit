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
#include <stdio.h>
#include <gobee.h>
#include <gobeelib.h>
#include <math.h>
#include <mover.h>
#include <estimators.h>
#include <clu.h>
#include <gml.h>

/* External Global Wars */
extern struct GOBEE_PARAMS gobee_param;

/* extern mover structure 	*/
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/


/* external events structure	*/
extern struct EVENTS events;

/* External CLU execution state machine */
extern struct CLU_STATEMACHINE clu_sm;	

/********************************************/
/* Simple Bike Jump Event Estimator			*/
/* input  : float (acc_x,y,z(t))			*/
/********************************************/
void SimpleJumpEventEstimator(float acc_x,float acc_y,float acc_z, float acc_modulo)
{	
	static uint32 local_ticks=0;
	
	if (fabsf(acc_modulo) < gobee_param.jump_g_threshold.fnum)	
	{
		events.inertial.jump = IM_JUMPING;
		local_ticks = 0;
	}
	else
	{
		if (local_ticks < 50)	/* 0,5 sec pulse stretcher */ 
		{
			local_ticks++;
		}
		else
		{		
			events.inertial.jump = NO_JUMP;	
		}			
	}
}


/********************************************************/
/* Simple Bike Horizontal Acceleration Event Estimator	*/
/* input  : float (horizontal acceleration)				*/
/********************************************************/
void SimpleHorizAccelerationEventsEstimator(float horiz_acc)
{	
	
	if (horiz_acc > gobee_param.acc_g_threshold.fnum)	
	{
		events.inertial.acceleration = BIKE_ACCELERATING;
	}
	else if (horiz_acc < -gobee_param.acc_g_threshold.fnum)
	{
		events.inertial.acceleration = BIKE_DECELERATING;	
	}
	else
	{
		events.inertial.acceleration = BIKE_NO_ACCELERATION;	
	}
}


/********************************************************/
/* Simple Bike Frame Roll Angle Events Estimator		*/
/* input  : float (bike roll angle(t))					*/
/********************************************************/
void SimpleRollAngleEventsEstimator(float angle)
{	
	float angle_abs = fabsf(angle);
	
	if (angle_abs <= NO_ROLL_ANGLE)							/* [deg] */
	{
		events.inertial.roll_angle = NO_ROLL;
	}
	else if (angle_abs <= BIKE_SIMPLE_ROLLING_ANGLE)		/* [deg] */
	{
		events.inertial.roll_angle = BIKE_SIMPLE_ROLLING;		
	}
	else if (angle_abs <= BIKE_ROLLING_ANGLE)				/* [deg] */
	{
		events.inertial.roll_angle = BIKE_ROLLING;		
	}	
	else
	{
		events.inertial.roll_angle = BIKE_TOO_MUCH_ROLL;
	}
}	

/********************************************/
/* Simple Bike Pitch Angle Events Estimator	*/
/* input  : float (bike pitch angle(t))		*/
/********************************************/
void SimpleTiltAngleEventsEstimator(float angle)
{	
	if (fabsf(angle) <= 2.86)	
	{
		events.inertial.tilt_angle = PLANE_MOTION;
	}
	else
	if (angle > 0)
	{
		if (angle > 11.31)	/* 20% climb	*/
		{
			events.inertial.tilt_angle = VERY_STEEP_DESCENT;
		}
		else
		if (angle > 5.71)	/* 10% climb */
		{
			events.inertial.tilt_angle = STEEP_DESCENT;
		}
		else
		if (angle > 2.86)	/* 5% climb */
		{
			events.inertial.tilt_angle = SIMPLE_DESCENT;
		}
	}
	else /* angle < 0 */
	{
		if (angle < -11.31)	/* 20% descent	*/
		{
			events.inertial.tilt_angle = VERY_STEEP_CLIMB;
		}
		else
		if (angle < -5.71)	/* 10% descent */
		{
			events.inertial.tilt_angle = STEEP_CLIMB;
		}
		else
		if (angle < -2.86)	/* 5% descent */
		{
			events.inertial.tilt_angle = SIMPLE_CLIMB;
		}
	}	
}

/********************************************/
/* Simple Bike Vibration Events Estimator	*/
/* input  : float (system dynamic scalar(t))*/
/********************************************/
void SimpleVibrationEventsEstimator(float sysdyn)
{	
	if (fabsf(sysdyn) >= 10.0)
	{
		events.inertial.vibration = HIGH_VIBRATION;
	}
	else 	if (fabsf(sysdyn) >= 5.0)
	{
		events.inertial.vibration = MEDIUM_VIBRATION;
	}	
	else 	if (fabsf(sysdyn) >= 0.25)
	{
		events.inertial.vibration = VIBRATION;
	}
	else
	{
		events.inertial.vibration = NO_VIBRATION;
	}	
}

/****************************************/
/* MAPPING STATE MACHINE			 	*/
/****************************************/
void MappingStateMachineExecution(void)
{
	switch (events.mapping_sm_status)
	{
		case SM_ON_ORIGIN:
			events.timecode.on_origin_ticks++;
		
			if (events.inertial.tilt_angle == VERY_STEEP_CLIMB)
			{	
				events.mapping_sm_status = SM_MOVING_TO_FACE;
				printf("\r\n@MAPSM: MOVING TO FACE!\r\n");
				if (gobee_param.director == STANLEY)
				{
					clu_sm_start(MOVING_TO_FACE_STANLEY_CLU);
				}
				else if	(gobee_param.director == JJ)
				{
					clu_sm_start(MOVING_TO_FACE_JJ_CLU);
				}
				else
				{
					clu_sm_start(MOVING_TO_FACE_GENERIC_CLU);
				}				
			}
			
			if (events.inertial.tilt_angle == VERY_STEEP_DESCENT)
			{	
				events.mapping_sm_status = SM_MOVING_TO_WHEEL;
				printf("\r\n@MAPSM: MOVING TO WHEEL!\r\n");
				if (gobee_param.director == STANLEY)
				{
					clu_sm_start(MOVING_TO_WHEEL_STANLEY_CLU);
				}
				else if	(gobee_param.director == JJ)
				{
					clu_sm_start(MOVING_TO_WHEEL_JJ_CLU);
				}
				else
				{
					clu_sm_start(MOVING_TO_WHEEL_GENERIC_CLU);
				}				
			}			
			
			if (((events.inertial.tilt_angle == PLANE_MOTION) ||
				 (events.inertial.tilt_angle == SIMPLE_CLIMB) ||
				 (events.inertial.tilt_angle == SIMPLE_DESCENT)) &&
				(events.timecode.on_origin_ticks >= 3000))
			{
				events.mapping_sm_status = SM_MOVING_PANORAMIC;
				printf("\r\n@MAPSM: MOVING PANORAMIC PAN!\r\n");
				
				if (gobee_param.director == STANLEY)
				{
					clu_sm_start(MOVING_PANORAMIC_STANLEY_CLU);
				}
				else if	(gobee_param.director == JJ)
				{
					clu_sm_start(MOVING_PANORAMIC_JJ_CLU);
				}
				else
				{
					clu_sm_start(MOVING_PANORAMIC_GENERIC_CLU);
				}
			}		
			
			if (events.inertial.jump == IM_JUMPING)
			{
				events.mapping_sm_status = SM_MOVING_JUMP;
				printf("\r\n@MAPSM: MOVING JUMP PAN!\r\n");
				clu_sm_start(MOVING_JUMP_CLU);
			}			
			break;
		case SM_MOVING_TO_FACE:
			//if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
			if (clu_sm.status == CLUSM_END)
			{
				events.mapping_sm_status = SM_ON_FACE;				
			}
			if (events.inertial.jump == IM_JUMPING)
			{
				events.mapping_sm_status = SM_MOVING_JUMP;
				printf("\r\n@MAPSM: MOVING JUMP PAN!\r\n");
				clu_sm_start(MOVING_JUMP_CLU);
			}				
			break;
		case SM_ON_FACE:
			if ((events.inertial.tilt_angle == VERY_STEEP_DESCENT) ||
				(events.inertial.tilt_angle == STEEP_DESCENT)	   ||
				(events.inertial.tilt_angle == SIMPLE_DESCENT)	   ||
				(events.inertial.tilt_angle == PLANE_MOTION))
			{
				events.mapping_sm_status = SM_MOVING_TO_ORIGIN;
				printf("\r\n@MAPSM: GOTO HOME P+T!\r\n");
				clu_sm_start(GOTO_HOME_CLU);
			}
			if (events.inertial.jump == IM_JUMPING)
			{
				events.mapping_sm_status = SM_MOVING_JUMP;
				printf("\r\n@MAPSM: MOVING JUMP PAN!\r\n");
				clu_sm_start(MOVING_JUMP_CLU);
			}			
			break;	
		case SM_MOVING_TO_ORIGIN:
			//if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
			if (clu_sm.status == CLUSM_END)
			{
				events.mapping_sm_status = SM_ON_ORIGIN;
				events.timecode.on_origin_ticks = 0;
			}
			break;
		case SM_MOVING_PANORAMIC:
			//if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
			if (clu_sm.status == CLUSM_END)
			{
				events.mapping_sm_status = SM_ON_ORIGIN;
				events.timecode.on_origin_ticks = 0;				
			}
			break;
		case SM_MOVING_JUMP:
			//if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
			if (clu_sm.status == CLUSM_END)
			{
				events.mapping_sm_status = SM_MOVING_TO_ORIGIN;
				printf("\r\n@MAPSM: GOTO HOME P+T!\r\n");
				clu_sm_start(GOTO_HOME_CLU);			
			}			
			break;	
		case SM_MOVING_TO_WHEEL:
			//if ((mover_pan.status == MOVER_ENDED) && (mover_tilt.status == MOVER_ENDED))
			if (clu_sm.status == CLUSM_END)
			{
				events.mapping_sm_status = SM_ON_WHEEL;				
			}
			break;
		case SM_ON_WHEEL:
			if ((events.inertial.tilt_angle == VERY_STEEP_CLIMB) ||
				(events.inertial.tilt_angle == STEEP_CLIMB)	     ||
				(events.inertial.tilt_angle == SIMPLE_CLIMB)	 ||
				(events.inertial.tilt_angle == PLANE_MOTION))
			{
				events.mapping_sm_status = SM_MOVING_TO_ORIGIN;
				printf("\r\n@MAPSM: GOTO HOME P+T!\r\n");
				clu_sm_start(GOTO_HOME_CLU);
			}
			break;				
		default:
			//
			break;
	}	
}

/****************************************/
/* MAPPING STATE MACHINE INITIALIZATION	*/
/****************************************/
void MappingStateMachineInit(void)
{
	events.mapping_sm_status = SM_STANDBY;
	events.timecode.on_origin_ticks = 0;	
}

/****************************************/
/* MAPPING STATE MACHINE START			*/
/****************************************/
void MappingStateMachineStart(void)
{
	events.mapping_sm_status = SM_ON_ORIGIN;
	events.timecode.on_origin_ticks = 0;	
}

///****************************************/
///* float Encoder Velocity Estimator 	*/
///* input  : int32 encoder  [step]		*/
///* returns: float velocity [step/sec]	*/
///****************************************/
//float SimplestVelocityEstimator(int32 encoder_steps)
//{
//	static float  estimated_velocity=0;
//	static int32  encoder_bef;
//	
//	encoder_bef = encoder_steps;										   /* [step]	 */	
//	estimated_velocity = (float)(encoder_steps-encoder_bef)*SAMPLING_FREQ; /* [step/sec] */
//	
//	return estimated_velocity; /* [step/sec] */
//}


///****************************************/
///* float Encoder Velocity Estimator 	*/
///* input  : int32 encoder  [step]		*/
///* returns: float velocity [step/sec]	*/
///****************************************/
//float VelocityEstimator(int32 encoder_steps)
//{
//	static float  estimated_velocity=0;
//	static int32  accumulator=0;
//	static int32  encoder_bef;
//	static uint32 counter=0;	/* rolls after 397 hours @ 3kHz control frequency */
//	
//	counter++;
//	
//	accumulator = accumulator + (encoder_steps - encoder_bef);
//	encoder_bef = encoder_steps;
//	
//	/* 3000 Hz/25 = 120 --> 1 tick every 1/120 sec] */
//	/* Ho accumulato n step in 25 ticks (1/120) di secondo quindi l'accumulatore contiene [step/ (1/120 sec)] */
//	/* Per ottenere [step/sec] moltiplico per 120 all'interno dell'if così lo fa una volta sola ogni giro	*/
//	if (counter % 25 == 0)
//	{
//		estimated_velocity = (float)accumulator*120; /* [step/sec] */
//		accumulator = 0;
//	}
//	return estimated_velocity; /* [step/sec] */
//}

///************************************************/
///* input  : master encoder  [step]				*/
///* returns: master velocity [step/sec]			*/
///************************************************/
//float VelocityEstimatorII(int32 master_encoder_steps)
//{
//	static int32 total = 0;
//	static int32 master_encoder_bef;
//
//
//    total -= buffer[index_buf] ;
//
//    buffer[index_buf] = (master_encoder_steps - master_encoder_bef) ;
//    
//    total += buffer[index_buf] ;
//
//    index_buf++ ;
//    if (index_buf >= MAX_INDEX)
//    {
//        index_buf = 0 ;
//    }
//
//    master_encoder_bef = master_encoder_steps;
//	
//	return (float)total * V_ESTIM_K ; 
//}

//void ClearVelocityEstimatorII(void)
//{
//    uint16 i ;
//
//    for (i=0; i<MAX_INDEX ; i++)
//    {
//        buffer[i] = 0 ;
//    }
//}


/* [] END OF FILE */
