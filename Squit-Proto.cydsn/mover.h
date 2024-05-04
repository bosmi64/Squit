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

/* MOVER CONSTANTS */
#define TRAPEZOID_MAX	7		/* 6+1 (safety) Trapezoid Maximum	in one Path */

// PATH 0 --> PAN  PATH
// PATH 1 --> TILT PATH
// PATH 2 --> PAN  PATH TO HOME
// PATH 3 --> TILT PATH TO HOME
// PATH 4 --> PAN  PATH TO Qxx
// PATH 5 --> TILT PATH TO Qxx
// PATH 6 --> safety
#define PATH_N_MAX		7		/* 6+1 (safety) Paths (movements) Maximum 		*/
#define	PATH_PGOTOHOME	2		/* Path 2 is special for PAN GOTO HOME			*/
#define	PATH_TGOTOHOME	3		/* Path 3 is special for TILT GOTO HOME			*/
#define	PATH_PGOTOQ		4		/* Path 4 is special for TILT GOTO Q (SHOT)		*/
#define	PATH_TGOTOQ		5		/* Path 5 is special for TILT GOTO Q (SHOT)		*/

#define MOVER_FREQ		1500	/* [Hz] Mover Sampling Frequency				*/


////////////////////////////////////
//Q SET elements (SHOT) constants //
////////////////////////////////////

// Q memories (where Q elements are stored)
#define Q_MEMORY_NUMBER_MIN		0		/* Q elements MEMORY minimum number							*/
#define Q_MEMORY_NUMBER_MAX 	32		/* Q elements MEMORY maximum number							*/
#define MAX_Q_MEMORIES_SAFE 	33		/* maximum number of Q elements Memories + 1 safety			*/

// Q numbers (11=face, 21=wheel, 32=road, ...)
#define Q_NUMBER_UNUSED			0		/* The Q element is not used								*/
#define Q_NUMBER_MIN			1		/* minimum Q element (SHOT) number							*/
#define Q_NUMBER_MAX			99		/* maximum Q element (SHOT) number							*/
#define MAX_Q_NUMBER_SAFE		100		/* maximum number of q_table[] elements + 1 safety			*/

// Axis used in the Q shot
#define QMAXAXES		 		3		/* Q (SHOT) maximum axes + 1 safety 						*/
										/* 0=PAN, 1=TILT											*/
										/* (roll, zoom and focus future expansion)					*/

//q_table constant
#define Q_MEMORY_NOT_ALLOCATED	255		/* The Q element is not allocated into q_table				*/
										/* (Q_MEMORY_NOT_ALLOCATED should be > MAX_Q_NUMBERS)		*/

//q modes
#define QMODE_DEFAULT			0		/* Q position = default										*/
#define QMODE_ADJUST			1		/* Q position = default	+ adjust							*/
						

// tipo di dato TRAPEZOID
struct TRAPEZOID
	{			
		/* EEPROM (NonVolatile) Parameters	*/
		struct TPARA
		{		
			floatEE acc_pc;			/* Acceleration percentage of total Trapezoid Time [%]	*/
		
			floatEE dec_pc;			/* Deceleration percentage of total Trapezoid Time [%]	*/
			
			floatEE time_sec;		/* Total Trapezoid Time	[sec]							*/
			
			int32	steps;			/* Total Trapezoid Steps [encoder step]					*/
		
			uint8   last_flg;		/* 0 --> this is not the last trapezoid					*/
									/* 1 --> this is the last trapezoid						*/
		}param;
		
		/* Trapezoid Mover Datas	*/
		struct MVDATAS 
		{
    		double acc_ticks;		/* Acceleration Time					 	[double ticks] Relative	*/
    		double dec_ticks;		/* Deceleration Time					 	[double ticks] Relative	*/
			double vconst_ticks;	/* Constant Velocity Time					[double ticks] Relative	*/

			int32 acc_end_tpoint;	/* Ticks Point of the Acceleration End	 	[ticks] 	  Absolute	*/
			int32 dec_start_tpoint;	/* Ticks Point of the Deceleration Start 	[ticks] 	  Absolute	*/
			int32 dec_end_tpoint;	/* Ticks Point of the Deceleration End   	[ticks] 	  Absolute	*/	
			
			int32 ticks_initial;	/* Initial Ticks Point of the trapezoid   	[ticks] 	  Absolute	*/
			int32 ticks_final;		/* Final   Ticks Point of the trapezoid   	[ticks] 	  Absolute	*/			
			
			double v_const;			/* Constant velocity of Trapezoidal Travel 	[double step/ticks]		*/
			double v_initial;		/* Initial velocity of Trapezoidal Travel   [double step/ticks]		*/			
			double v_final;			/* Final velocity of Trapezoidal Travel    	[double step/ticks]		*/	
			
			float acc_slope;		/* Acceleration slope						[step/ticks^2]			*/
			float dec_slope;		/* Deceleration slope						[step/ticks^2]			*/			
			
		}mover;
	};	

	
// tipo di dato PATH
typedef struct
	{
		/* EEPROM (NonVolatile) Parameters	*/
		struct PPARA
		{				
			uint8 Trapezoid_Number;		/* Number of Trapezoid used in current Path	1-4 		*/
		}param;	
		
		struct TRAPEZOID trapezoid[TRAPEZOID_MAX];	/* Trapezoid Array for this Path			*/
		
		int32 ticks;					/* ticks over the Path									*/
		int32 path_ticks_MAX;			/* Maximum number of ticks over this path				*/	
		
		int32 delta_position;			/* Calculated Delta position							*/
	}path_type;

	
// tipo di dato MOVER	
typedef struct
	{
		uint8  status;				/* 1 == ON							*/
		uint8  trapezoid_index;		/* mover trapezoid index var 		*/
		uint32 ticks;				/* mover ticks		  				*/
		double remainder_double;	/* mover remainder [double steps]	*/
		int32  steps;				/* mover steps		   [steps]		*/
		double steps_to_move_double;/* mover steps  [double steps]		*/
		int32 steps_to_move;		/* steps to move [steps] 		 	*/
		int32  steps_integral;		/* mover steps integral [steps]		*/ 
		uint8  path_to_move;		/* mover path to move number		*/
		
	}mover_type;
	
	
// tipo di dato QELEMENT (SHOTS)	
struct QELEMENT
	{	
		uint8  number;							/* Q element (shot) number									*/
												/* 00=UNUSED, 11=VISO, 13=GAMBE, 14=MANO DX, ...			*/
		
		uint8  mode;							/* 0=default, 1=default+adjust								*/
		
		/* EEPROM (NonVolatile) Parameters	*/
		struct QPARA
		{				
			floatEE position_default[QMAXAXES];	/* Shot Default Absolute Position Parameter [float steps]	*/
												/* 0 = PAN, 1=TILT, 2=ROLL (3=ZOOM, 4=FOCUS)				*/
			int16 position_adjust[QMAXAXES];	/* Shot Adjust  Absolute Position Parameter [steps]			*/
												/* 0 = PAN, 1=TILT, 2=ROLL (3=ZOOM, 4=FOCUS)				*/			
		}param;	
		
		/* Real Time Motion Control vars */
		struct QMC
		{				
			float position[QMAXAXES];			/* Shot Absolute Position Real Time value [float steps]		*/
												/* 0 = PAN, 1=TILT, 2=ROLL (3=ZOOM, 4=FOCUS)				*/			
		}mc;			
	};	

/* MOVER DEFINES */
#define MOVER_OFF		0
#define MOVER_NOP		0
#define MOVER_STARTED	1
#define MOVER_ENDED		2

	
/* LAST TRAPEZOID DEFINES */
#define NOT_LAST_TRAPEZOID	0	/* This is not the last trapezoid	*/
#define LAST_TRAPEZOID		1	/* This is the last trapezoid		*/


/****************************************/
/* Trapezoid Calculation 				*/
/****************************************/
void CalculateTrapezoid(struct TRAPEZOID *pt);

/****************************************/
/* Single Path Calculation		 		*/
/****************************************/
void CalculatePath(path_type *pp);


/****************************************/
/* Goto Home Paths Calculation		 	*/
/****************************************/
void CalculatePanGotoHomePath(void);
void CalculateTiltGotoHomePath(void);

/****************************************/
/* Goto Home Paths Initialization		*/
/****************************************/
void InitPanGotoHomePath(void);
void InitTiltGotoHomePath(void);

/****************************************/
/* Goto Q Paths Calculation				*/
/****************************************/
void CalculatePanGotoQPath(void);
void CalculateTiltGotoQPath(void);

/****************************************/
/* Goto Q (Shot) Paths Initialization	*/
/****************************************/
void InitPanGotoQPath(int8 q_number, float time_sec);
void InitTiltGotoQPath(int8 q_number, float time_sec);

/************************************************************************/
/* Q elements (Shot) Initialization										*/
/* ("fast indexing" table q_number --> memory_number initialization)	*/
/************************************************************************/
void InitQFastIdxTable(void);

/************************************************************************/
/* Q elements															*/
/* Clear "fast indexing" table											*/
/************************************************************************/
void ClearQFastIdxTable(void);

/************************************************************************/
/* Q elements															*/
/* Initialize All Q positions											*/
/* 		mode=QMODE_DEFAULT	-->	position = default						*/
/* 		mode=QMODE_ADJUST	-->	position = default+adjust				*/	
/************************************************************************/
void InitQAllPositions(void);				//all
void InitQPosition(uint8 memory_number);	//single

/****************************************/
/* Move Rendering Initialization		*/
/****************************************/
void MoverInit(mover_type *mover);

/****************************************/
/* Move Rendering Path n Start			*/
/****************************************/
void MoverStart(mover_type *mover, uint8 path_n);

/****************************************/
/* Move Rendering Calculation		 	*/
/****************************************/
int32 MoverGeneratedSteps(mover_type *mover, path_type *pp, uint32 ticks);

/************************************************************************/
/* Q elements															*/
/* Initialize qmemory standard address table							*/
/************************************************************************/
void InitQmemoryStandardAllocationTable(void);


/* [] END OF FILE */
