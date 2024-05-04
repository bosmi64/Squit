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
#include <estimators.h>
#include <mover.h>

/* EXTERN MOVER PATH Array */
extern path_type path[PATH_N_MAX];

/* EXTERN MOVER PAN&TILT  */
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/

/* EXTERNAL Feedback Encoders */
extern struct ENCODER pan_feedback_encoder;  /* PAN Feedback Encoder Parameters & RT Datas  */
extern struct ENCODER tilt_feedback_encoder; /* TILT Feedback Encoder Parameters & RT Datas */

/* EXTERNAL Absolute Position Sensor */
extern struct ABSPOS_SENSOR	pan_absolute_sensor;	/* PAN  Absolute Position Sensor Parameters & RT Datas */
extern struct ABSPOS_SENSOR	tilt_absolute_sensor;	/* TILT Absolute Position Sensor Parameters & RT Datas */

/* External Motor Axes 		  */
extern struct MOTOR_AXIS pan_axis; 			/* PAN Motor Axis Parameters & RT Datas		*/
extern struct MOTOR_AXIS tilt_axis; 		/* TILT Motor Axis Parameters & RT Datas	*/

/* external Q elements (shots) ARRAY	*/
extern struct QELEMENT q[MAX_Q_MEMORIES_SAFE];

/* external [Q number --> Q memory index] table for fast indexing */
extern uint8 q_table[MAX_Q_NUMBER_SAFE];
extern uint8 qmemory_standard_address[MAX_Q_NUMBER_SAFE]; 


/* Mover local defines */
//


/****************************************/
/* Trapezoid Calculation 				*/
/****************************************/
void CalculateTrapezoid(struct TRAPEZOID *pt)
{

	// Calculates acceleration ticks
	(*pt).mover.acc_ticks = (*pt).param.acc_pc.fnum * (*pt).param.time_sec.fnum * (float)MOVER_FREQ;	/* [float ctrl ticks]	*/
	
	// Calculates deceleration ticks
	// if this is not the last trapezoid, deceleration ticks are zero
	if ((*pt).param.last_flg == LAST_TRAPEZOID)
	{
		(*pt).mover.dec_ticks = (*pt).param.dec_pc.fnum * (*pt).param.time_sec.fnum * (float)MOVER_FREQ;	/* [float ctrl ticks]	*/		
	}
	else
	{
		(*pt).mover.dec_ticks = 0;																		/* [float ctrl ticks]	*/
	}

	// Calculates Constant Velocity Time ticks
    (*pt).mover.vconst_ticks  = (*pt).param.time_sec.fnum * (float)MOVER_FREQ
							  - (*pt).mover.acc_ticks
							  - (*pt).mover.dec_ticks;											/* [float ctrl ticks]	*/
	  
  	// Calculates the Constant Velocity of the Trapezoid Travel	
    (*pt).mover.v_const = (2 * (float)(*pt).param.steps - (*pt).mover.acc_ticks * (*pt).mover.v_initial)/
					  ((*pt).mover.acc_ticks + (*pt).mover.dec_ticks + 2 * (*pt).mover.vconst_ticks);	/* [float step/ticks] */

  
	// Calculates final velocity
	// if this is the last trapezoid, final velocity is zero
	if ((*pt).param.last_flg == LAST_TRAPEZOID)
	{
		(*pt).mover.v_final = 0;																/* [float step/ticks] */
	}
	else
	{
		(*pt).mover.v_final = (*pt).mover.v_const;												/* [float step/ticks] */
	}

  	// Acceleration Slope Calculation	
	(*pt).mover.acc_slope = ((*pt).mover.v_const - (*pt).mover.v_initial) / (*pt).mover.acc_ticks;  /* [float step/ticks^2] */
	
	// Deceleration Slope Calculation
	if ((*pt).param.last_flg == LAST_TRAPEZOID)
	{
		(*pt).mover.dec_slope = -(*pt).mover.v_const / (*pt).mover.dec_ticks;  						/* [float step/ticks^2] */
	}
	else
	{
		(*pt).mover.dec_slope = 0;
	}
	
	// Calculates the Ticks Point of acceleration ending
	(*pt).mover.acc_end_tpoint   =  (*pt).mover.ticks_initial +
									(int32)((*pt).mover.acc_ticks);									/* [ctrl ticks] */
	
	// Calculates the Ticks Point of deceleration starting	
	(*pt).mover.dec_start_tpoint =  (*pt).mover.ticks_initial +
									(int32)((*pt).mover.acc_ticks + (*pt).mover.vconst_ticks); 		/* [ctrl ticks] */  
	
	// Calculates the Ticks Point of deceleration ending	
	(*pt).mover.dec_end_tpoint =  (*pt).mover.ticks_initial +
								  (int32)((*pt).mover.acc_ticks    +
								  (*pt).mover.vconst_ticks +
								  (*pt).mover.dec_ticks);							 				/* [ctrl ticks] */  
	
	(*pt).mover.ticks_final = (*pt).mover.dec_end_tpoint;											/* [ctrl ticks] */
	
}

/****************************************/
/* Move Rendering Initialization		*/
/****************************************/
void MoverInit(mover_type *mover)
{
	(*mover).status = MOVER_OFF;
	(*mover).trapezoid_index = 0;
	(*mover).ticks = 0;
	(*mover).remainder_double = 0;
}

/****************************************/
/* Move Rendering Path n Start			*/
/****************************************/
void MoverStart(mover_type *mover, uint8 path_n)
{
	(*mover).path_to_move = path_n;
	(*mover).trapezoid_index = 0;
	(*mover).ticks = 0;
	(*mover).remainder_double = 0;	
	(*mover).status = MOVER_STARTED;
}


/****************************************/
/* Move Rendering Calculation		 	*/
/****************************************/
int32 MoverGeneratedSteps(mover_type *mover, path_type *pp, uint32 ticks)
{
	//static double steps_to_move_double;	/* [double steps] */
	//int32 steps_to_move;				/* [steps] 		 */
	
	// Acceleration Rendering
	if (ticks <= (*pp).trapezoid[(*mover).trapezoid_index].mover.acc_end_tpoint)
	{
		(*mover).steps_to_move_double = (*mover).steps_to_move_double + (*pp).trapezoid[(*mover).trapezoid_index].mover.acc_slope;
	}
	else
	// Constant Velocity Rendering
	if (ticks < (*pp).trapezoid[(*mover).trapezoid_index].mover.dec_start_tpoint)
	{
		(*mover).steps_to_move_double = (*pp).trapezoid[(*mover).trapezoid_index].mover.v_const;
	}
	else
	// Deceleration Rendering
	{
		(*mover).steps_to_move_double = (*mover).steps_to_move_double + (*pp).trapezoid[(*mover).trapezoid_index].mover.dec_slope;
	}	
	
	//alla fine della decelerazione, se, incrementa il numero del trapezio
	if (ticks >= (*pp).trapezoid[(*mover).trapezoid_index].mover.dec_end_tpoint)
	{
		(*mover).trapezoid_index++;
	}	
	
	//Integer Steps Rendering
	(*mover).steps_to_move = (int32)(*mover).steps_to_move_double;
	
	// Remainder Calculation
	(*mover).remainder_double = (*mover).remainder_double + ((*mover).steps_to_move_double - (double)(*mover).steps_to_move);	/* Remainder Integration */
	
	if ((*mover).remainder_double >= +1.0)
	{
		(*mover).remainder_double = (*mover).remainder_double - 1.0;
		(*mover).steps_to_move = (*mover).steps_to_move + 1;
	}
	
	if ((*mover).remainder_double <= -1.0)
	{
		(*mover).remainder_double = (*mover).remainder_double + 1.0;
		(*mover).steps_to_move = (*mover).steps_to_move - 1;
	}	
	
	// Check mover end
	if (ticks >= (*pp).path_ticks_MAX)
	{
		(*mover).status = MOVER_ENDED;
		(*mover).steps_to_move = 0;
	}
			
	// Return the steps to Move in this tick [steps]
	return (*mover).steps_to_move;
}

/****************************************/
/* Single Path Calculation		 		*/
/****************************************/
void CalculatePath(path_type *pp)
{
	uint8 idx;

	//ticks initial first trapezoid <-- 0
	(*pp).trapezoid[0].mover.ticks_initial = 0;
	
	//vinitial first Trapezoid <-- 0
	(*pp).trapezoid[0].mover.v_initial = 0;
	
	//vfinal last Trapezoid <-- 0
	(*pp).trapezoid[(*pp).param.Trapezoid_Number-1].mover.v_final = 0;	
	
	//Calculate path Trapezoids
	for (idx=0; idx<=(*pp).param.Trapezoid_Number; idx++)
	{
		//calcola il trapezoide(idx)
		CalculateTrapezoid(&((*pp).trapezoid[idx]));
		
		//viniziale del trapezoide idx+1 = vfinale del trapezoide idx
		(*pp).trapezoid[idx+1].mover.v_initial =  (*pp).trapezoid[idx].mover.v_final;
		
		//tick iniziale del trapezoide idx+1 = tick del trapezoide idx
		(*pp).trapezoid[idx+1].mover.ticks_initial =  (*pp).trapezoid[idx].mover.ticks_final;		
	}
	
	(*pp).path_ticks_MAX = (*pp).trapezoid[idx-1].mover.ticks_final;
}




/****************************************/
/* Pan Goto Home Path Calculation		*/
/****************************************/
void CalculatePanGotoHomePath(void)
{
	CalculatePath(&path[PATH_PGOTOHOME]);
}

/****************************************/
/* Tilt Goto Home Path Calculation		*/
/****************************************/
void CalculateTiltGotoHomePath(void)
{
	CalculatePath(&path[PATH_TGOTOHOME]);
}

/****************************************/
/* Pan Goto Q Path Calculation			*/
/****************************************/
void CalculatePanGotoQPath(void)
{
	CalculatePath(&path[PATH_PGOTOQ]);
}

/****************************************/
/* Tilt Goto Q Path Calculation			*/
/****************************************/
void CalculateTiltGotoQPath(void)
{
	CalculatePath(&path[PATH_TGOTOQ]);
}




///****************************************/
///* Constant Paths Initialization		*/
///****************************************/
//void InitAllPathsWithConstMovements(void)
//{
//	//path[0]: simple trapezoid
//	// Relative +90 [deg] CW MOVEMENT
//	// in 1 sec
//	// with soft acceleration & deceleration
//	path[0].param.Trapezoid_Number = 1;
//	
//	path[0].trapezoid[0].param.acc_pc.fnum = 0.3;	/* 30% */
//	path[0].trapezoid[0].param.dec_pc.fnum = 0.3;	/* 30% */
//	path[0].trapezoid[0].param.time_sec.fnum = 1;	/* [sec] */
//	path[0].trapezoid[0].param.steps = 90 * pan_axis.param.resolution.fnum / 360;	
//	path[0].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
//
//	
//	//path[1]: simple trapezoid
//	// Relative -90 [deg] CCW MOVEMENT
//	// in 2.5 sec
//	// with soft acceleration & deceleration
//	path[1].param.Trapezoid_Number = 1;
//	
//	path[1].trapezoid[0].param.acc_pc.fnum = 0.3;	/* 20% */
//	path[1].trapezoid[0].param.dec_pc.fnum = 0.3;	/* 20% */
//	path[1].trapezoid[0].param.time_sec.fnum = 2.5;	/* [sec] */
//	path[1].trapezoid[0].param.steps = -90 * pan_axis.param.resolution.fnum / 360;	
//	path[1].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
//
//
//	//path[2]: simple trapezoid
//	// Relative +180 [deg] CW MOVEMENT
//	// in 3 sec
//	// with soft acceleration & deceleration
//	path[2].param.Trapezoid_Number = 1;
//	
//	path[2].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
//	path[2].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[2].trapezoid[0].param.time_sec.fnum = 3;	/* [sec] */
//	path[2].trapezoid[0].param.steps = 180 * pan_axis.param.resolution.fnum / 360;	
//	path[2].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
//
//	
//	//path[3]: simple trapezoid
//	// Relative -180 [deg] CCW MOVEMENT
//	// in 20 sec
//	// with soft acceleration & deceleration
//	path[3].param.Trapezoid_Number = 1;
//	
//	path[3].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
//	path[3].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[3].trapezoid[0].param.time_sec.fnum = 20;	/* [sec] */
//	path[3].trapezoid[0].param.steps = -180 * pan_axis.param.resolution.fnum / 360;	
//	path[3].trapezoid[0].param.last_flg = LAST_TRAPEZOID;	
//	
//	
//	//path[4]: double trapezoid
//	// from origin to +90 [deg] very fast in 3 sec
//	// then from +90 [deg] to +180 [deg] slow in 10 sec
//	// with soft acceleration & deceleration
//	path[4].param.Trapezoid_Number = 2;
//	
//	path[4].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
//	path[4].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[4].trapezoid[0].param.time_sec.fnum = 3;	/* [sec] */
//	path[4].trapezoid[0].param.steps = 90 * pan_axis.param.resolution.fnum / 360;	
//	path[4].trapezoid[0].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[4].trapezoid[1].param.acc_pc.fnum = 0.1;	/* 10% */
//	path[4].trapezoid[1].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[4].trapezoid[1].param.time_sec.fnum = 10;	/* [sec] */
//	path[4].trapezoid[1].param.steps = 90 * pan_axis.param.resolution.fnum / 360;	
//	path[4].trapezoid[1].param.last_flg = LAST_TRAPEZOID;
//	
//	
//	//path[5]: Ciak movement
//	// quad trapezoid
//	// from origin to -15 
//	// then from -15 [deg] to +15 [deg]
//	// then from +15 [deg] to -15 [deg]
//	// then from -15 [deg] to origin (fast)
//	path[5].param.Trapezoid_Number = 4;
//	
//	path[5].trapezoid[0].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[0].param.dec_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[0].param.time_sec.fnum = 0.15;	/* [sec] */
//	path[5].trapezoid[0].param.steps = -15 * pan_axis.param.resolution.fnum / 360;	
//	path[5].trapezoid[0].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[5].trapezoid[1].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[1].param.dec_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[1].param.time_sec.fnum = 0.1;	/* [sec] */
//	path[5].trapezoid[1].param.steps = 30 * pan_axis.param.resolution.fnum / 360;	
//	path[5].trapezoid[1].param.last_flg = NOT_LAST_TRAPEZOID;
//	
//	path[5].trapezoid[2].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[2].param.dec_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[2].param.time_sec.fnum = 0.1;	/* [sec] */
//	path[5].trapezoid[2].param.steps = -30 * pan_axis.param.resolution.fnum / 360;	
//	path[5].trapezoid[2].param.last_flg = NOT_LAST_TRAPEZOID;
//	
//	path[5].trapezoid[3].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[3].param.dec_pc.fnum = 0.05;	/* 5% */
//	path[5].trapezoid[3].param.time_sec.fnum = 0.1;	/* [sec] */
//	path[5].trapezoid[3].param.steps = 15 * pan_axis.param.resolution.fnum / 360;	
//	path[5].trapezoid[3].param.last_flg = LAST_TRAPEZOID;	
//
//	
//	//path[6]: SLOW PANORAMIC from SX to DX
//	// double trapezoid
//	// from origin to -90 [deg] very fast in 2 sec
//	// then from +90 [deg] to +180 [deg] slow in 20 sec
//	// with soft acceleration & deceleration
//	path[6].param.Trapezoid_Number = 2;
//	
//	path[6].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
//	path[6].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[6].trapezoid[0].param.time_sec.fnum = 2;	/* [sec] */
//	path[6].trapezoid[0].param.steps = -90 * pan_axis.param.resolution.fnum / 360;	
//	path[6].trapezoid[0].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[6].trapezoid[1].param.acc_pc.fnum = 0.1;	/* 10% */
//	path[6].trapezoid[1].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[6].trapezoid[1].param.time_sec.fnum = 20;	/* [sec] */
//	path[6].trapezoid[1].param.steps = 180 * pan_axis.param.resolution.fnum / 360;	
//	path[6].trapezoid[1].param.last_flg = LAST_TRAPEZOID;
//	
//	
//	//path[7]: SLOW PANORAMIC from SX to DX
//	// double trapezoid
//	// from origin to -90 [deg] very fast in 2.5 sec
//	// then from -90 [deg] to +90 [deg] slow in 20 sec
//	// Then from +90 [deg] to -90 [deg] slow in 20 sec
//	// Then from -90 [deg] to Origin very fast in 2.5 sec	
//	// with soft acceleration & deceleration
//	path[7].param.Trapezoid_Number = 4;
//	
//	path[7].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
//	path[7].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[7].trapezoid[0].param.time_sec.fnum = 2.5;	/* [sec] */
//	path[7].trapezoid[0].param.steps = (int32)(-90 * pan_axis.param.resolution.fnum / 360);	
//	path[7].trapezoid[0].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[7].trapezoid[1].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[7].trapezoid[1].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[7].trapezoid[1].param.time_sec.fnum = 20;	/* [sec] */
//	path[7].trapezoid[1].param.steps = (int32)(180 * pan_axis.param.resolution.fnum / 360);	
//	path[7].trapezoid[1].param.last_flg = NOT_LAST_TRAPEZOID;
//	
//	path[7].trapezoid[2].param.acc_pc.fnum = 0.05;	/* 5% */
//	path[7].trapezoid[2].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[7].trapezoid[2].param.time_sec.fnum = 20;	/* [sec] */
//	path[7].trapezoid[2].param.steps = (int32)(-180 * pan_axis.param.resolution.fnum / 360);	
//	path[7].trapezoid[2].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[7].trapezoid[3].param.acc_pc.fnum = 0.1;	/* 10% */
//	path[7].trapezoid[3].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[7].trapezoid[3].param.time_sec.fnum = 2.5;	/* [sec] */
//	path[7].trapezoid[3].param.steps = (int32) (90 * pan_axis.param.resolution.fnum / 360);	
//	path[7].trapezoid[3].param.last_flg = LAST_TRAPEZOID;
//	
//	
//	//path[8]: JUMP (double trapezoid)
//	// from origin to +1440 [deg] very fast in 2.5 sec
//	// then from +1440 [deg] to origin fast in 2.5 sec
//	// with soft acceleration & deceleration
//	path[8].param.Trapezoid_Number = 2;
//	
//	path[8].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 10% */
//	path[8].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[8].trapezoid[0].param.time_sec.fnum = 2.5;	/* [sec] */
//	path[8].trapezoid[0].param.steps = (int32)(4 * pan_axis.param.resolution.fnum);	/* 4 giri */
//	path[8].trapezoid[0].param.last_flg = NOT_LAST_TRAPEZOID;	
//	
//	path[8].trapezoid[1].param.acc_pc.fnum = 0.2;	/* 10% */
//	path[8].trapezoid[1].param.dec_pc.fnum = 0.2;	/* 20% */
//	path[8].trapezoid[1].param.time_sec.fnum = 2.5;	/* [sec] */
//	path[8].trapezoid[1].param.steps = (int32)(-4 * pan_axis.param.resolution.fnum);	/* 4 giri */
//	path[8].trapezoid[1].param.last_flg = LAST_TRAPEZOID;	
//}

/****************************************/
/* PAN Goto Home Path Initialization	*/
/****************************************/
void InitPanGotoHomePath(void)
{
	//path[PATH_PGOTOHOME]: simple trapezoid
	// with soft acceleration & deceleration
	path[PATH_PGOTOHOME].param.Trapezoid_Number = 1;
	
	path[PATH_PGOTOHOME].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
	path[PATH_PGOTOHOME].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
	path[PATH_PGOTOHOME].trapezoid[0].param.time_sec.fnum = 2.0;	/* [sec] */
	
	path[PATH_PGOTOHOME].trapezoid[0].param.steps = (int32)(-pan_absolute_sensor.position);	
	path[PATH_PGOTOHOME].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
}


/****************************************/
/* TILT Goto Home Path Initialization	*/
/****************************************/
void InitTiltGotoHomePath(void)
{
	//path[PATH_TGOTOHOME]: simple trapezoid
	// with soft acceleration & deceleration
	path[PATH_TGOTOHOME].param.Trapezoid_Number = 1;
	
	path[PATH_TGOTOHOME].trapezoid[0].param.acc_pc.fnum = 0.2;	/* 20% */
	path[PATH_TGOTOHOME].trapezoid[0].param.dec_pc.fnum = 0.2;	/* 20% */
	path[PATH_TGOTOHOME].trapezoid[0].param.time_sec.fnum = 2.0;	/* [sec] */
	
	path[PATH_TGOTOHOME].trapezoid[0].param.steps =(int32)(-tilt_absolute_sensor.position);	
	path[PATH_TGOTOHOME].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
}


/********************************************/
/* PAN Goto Q (Shot) Path Initialization	*/
/********************************************/
void InitPanGotoQPath(int8 q_number, float time_sec)
{
	if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)		//is Q allocated on any memory?
	{
		//path[PATH_PGOTOQ]: simple trapezoid
		// with soft acceleration & deceleration
		path[PATH_PGOTOQ].param.Trapezoid_Number = 1;
		
		path[PATH_PGOTOQ].trapezoid[0].param.acc_pc.fnum = 0.2;			/* 20% */
		path[PATH_PGOTOQ].trapezoid[0].param.dec_pc.fnum = 0.2;			/* 20% */
		path[PATH_PGOTOQ].trapezoid[0].param.time_sec.fnum = time_sec;	/* [sec] */
		
		path[PATH_PGOTOQ].trapezoid[0].param.steps = (int32)(-pan_absolute_sensor.position + q[q_table[q_number]].mc.position[PAN_AXIS]); /* [steps] */
		path[PATH_PGOTOQ].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
	}
	else
	{
		//path[PATH_PGOTOQ]: ***warning*** zero trapezoid
		// (Q memory is not allocated)
		path[PATH_PGOTOQ].param.Trapezoid_Number = 1;
		
		path[PATH_PGOTOQ].trapezoid[0].param.acc_pc.fnum = 0.2;			/* 20% */
		path[PATH_PGOTOQ].trapezoid[0].param.dec_pc.fnum = 0.2;			/* 20% */
		path[PATH_PGOTOQ].trapezoid[0].param.time_sec.fnum = 0.1;		/* [sec] */
		
		path[PATH_PGOTOQ].trapezoid[0].param.steps = 0; 				/* [steps] */
		path[PATH_PGOTOQ].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
	}	
	
}

/********************************************/
/* TILT Goto Q (Shot) Path Initialization	*/
/********************************************/
void InitTiltGotoQPath(int8 q_number, float time_sec)
{
	if (q_table[q_number] != Q_MEMORY_NOT_ALLOCATED)		//is Q allocated on any memory?
	{	
		//path[PATH_TGOTOQ]: simple trapezoid
		// with soft acceleration & deceleration
		path[PATH_TGOTOQ].param.Trapezoid_Number = 1;
		
		path[PATH_TGOTOQ].trapezoid[0].param.acc_pc.fnum = 0.2;			/* 20% */
		path[PATH_TGOTOQ].trapezoid[0].param.dec_pc.fnum = 0.2;			/* 20% */
		path[PATH_TGOTOQ].trapezoid[0].param.time_sec.fnum = time_sec;	/* [sec] */
		
		path[PATH_TGOTOQ].trapezoid[0].param.steps = (int32)(-tilt_absolute_sensor.position + q[q_table[q_number]].mc.position[TILT_AXIS]); /* [steps] */
		path[PATH_TGOTOQ].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
	}
	else
	{	
		//path[PATH_TGOTOQ]: ***warning*** zero trapezoid
		// (Q memory is not allocated)
		path[PATH_TGOTOQ].param.Trapezoid_Number = 1;
		
		path[PATH_TGOTOQ].trapezoid[0].param.acc_pc.fnum = 0.2;				/* 20% */
		path[PATH_TGOTOQ].trapezoid[0].param.dec_pc.fnum = 0.2;				/* 20% */
		path[PATH_TGOTOQ].trapezoid[0].param.time_sec.fnum = 0.1;			/* [sec] */
		
		path[PATH_TGOTOQ].trapezoid[0].param.steps = 0; 					/* [steps] */
		path[PATH_TGOTOQ].trapezoid[0].param.last_flg = LAST_TRAPEZOID;
	}	
	
}

/************************************************************************/
/* Q elements															*/
/* "fast indexing" table q_number --> memory_number initialization		*/
/************************************************************************/
void InitQFastIdxTable(void)
{
	uint8 memory_number;
	
	//resetta la tabella
	ClearQFastIdxTable();
	
	//ricostruisci la tabella "fast indexing" q_number --> memory_number	
	for(memory_number=Q_MEMORY_NUMBER_MIN; memory_number <= Q_MEMORY_NUMBER_MAX; memory_number++)	
	{
		if (q[memory_number].number != Q_NUMBER_UNUSED)
		{
			q_table[q[memory_number].number] = memory_number;
		}
	}		
}

/************************************************************************/
/* Q elements															*/
/* Clear "fast indexing" table											*/
/************************************************************************/
void ClearQFastIdxTable(void)
{
	uint8 q_number;
	
	//resetta la tabella
	for(q_number=Q_NUMBER_MIN; q_number <= Q_NUMBER_MAX; q_number++)
	{
		q_table[q_number] = Q_MEMORY_NOT_ALLOCATED;
	}	
}

/************************************************************************/
/* Q elements															*/
/* Initialize All Q positions											*/
/* 		mode=QMODE_DEFAULT	-->	position = default						*/
/* 		mode=QMODE_ADJUST	-->	position = default+adjust				*/	
/************************************************************************/
void InitQAllPositions(void)
{
	uint8 memory_number;
	
	for(memory_number=Q_MEMORY_NUMBER_MIN; memory_number <= Q_MEMORY_NUMBER_MAX; memory_number++)	
	{
		InitQPosition(memory_number);
	}
}

void InitQPosition(uint8 memory_number)
{
	if (memory_number <= Q_MEMORY_NUMBER_MAX)
	{
		if (q[memory_number].number != 0)
		{
			//copy default parameter into real time position
			q[memory_number].mc.position[PAN_AXIS]  = q[memory_number].param.position_default[PAN_AXIS].fnum;	/* [float steps] */
			q[memory_number].mc.position[TILT_AXIS] = q[memory_number].param.position_default[TILT_AXIS].fnum;	/* [float steps] */	
			
			//if (mode=adjust) make adjusting
			if (q[memory_number].mode == QMODE_ADJUST)
			{
				q[memory_number].mc.position[PAN_AXIS] = q[memory_number].mc.position[PAN_AXIS] 
														+ (float)q[memory_number].param.position_adjust[PAN_AXIS];	
				q[memory_number].mc.position[TILT_AXIS] = q[memory_number].mc.position[TILT_AXIS] 
														+ (float)q[memory_number].param.position_adjust[TILT_AXIS];															
			}
		}
	}
}


/************************************************************************/
/* Q elements															*/
/* Initialize qmemory standard address table							*/
/************************************************************************/
void InitQmemoryStandardAllocationTable(void)
{
	qmemory_standard_address[0]  = 0;			//origin
	qmemory_standard_address[11] = 1;			//face
	qmemory_standard_address[13] = 2;			//legs
	qmemory_standard_address[14] = 3;			//hand dx	
	qmemory_standard_address[15] = 4;			//hand sx	
	qmemory_standard_address[16] = 5;			//pedal dx	
	qmemory_standard_address[17] = 6;			//pedal sx	
	qmemory_standard_address[21] = 7;			//wheel	
	qmemory_standard_address[31] = 8;			//road		
	qmemory_standard_address[33] = 9;			//road side dx	
	qmemory_standard_address[34] = 10;			//road side sx
	qmemory_standard_address[40] = 11;			//panorama front	
	qmemory_standard_address[41] = 12;			//panorama dx
	qmemory_standard_address[42] = 13;			//panorama sx	
	qmemory_standard_address[43] = 14;			//panorama dx rear	
	qmemory_standard_address[44] = 15;			//panorama sx rear	
	qmemory_standard_address[51] = 16;			//sky	
	qmemory_standard_address[52] = 17;			//sky dx	
	qmemory_standard_address[53] = 18;			//sky sx		
}

/* [] END OF FILE */
