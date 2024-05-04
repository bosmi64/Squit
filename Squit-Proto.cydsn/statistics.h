/* =============================================
 * STATISTICS Library header      				*
 * V.2.3										*
 * 12/10/2018									*
 *												*
 * Copyright 2010-2018 Logic brainstorm         *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH IS THE PROPERTY OF Logic brainstorm	*
 * =============================================
*/

/* STAT MESSAGES CONSTANTS */
#define STATISTICS_NOP		0
#define STATISTICS_START	1
#define STATISTICS_STOP		2
#define STATISTICS_STARTED	3


// tipo di dato STATISTICS
struct STATISTICS
	{
		uint8 messg;			/* Internal Message (start, stop, ect.)				*/
		
		float mean;				/* mean value(t) 									*/
		float mean_previous; 	/* mean value(t-1)									*/		
		float min;				/* minimum value(t) 								*/
		float max;				/* maximum value(t) 								*/	
		float range;			/* range = maximum - minimum value 					*/
		float scarto;			/* scarto = value - mean(value)						*/		
		float Qk;				/* Qk value for sample variance iterative calculus 	*/
		float Qk_previous;		/* Qk(t-1)											*/
		float variance;			/* Variance(t)										*/
		
		uint32 iteration_num;	/* iteration_num = n								*/
		
		uint32 tick;			/* statistic tick									*/
	};

/********************************************************************************************/
/* Statistics Initialization																*/
/********************************************************************************************/
void statistics_init(struct STATISTICS *stat);

/********************************************************************************************/
/* Statistics Start																			*/
/********************************************************************************************/
void statistics_start(struct STATISTICS *stat);

/********************************************************************************************/
/* Statistics Stop																			*/
/********************************************************************************************/
void statistics_stop(struct STATISTICS *stat);

/********************************************************************************************/
/* Value Statistics Iterative Calculus														*/
/* 																							*/
/* iteration >= 2																			*/
/* Calcola il valor medio e altre variabili statistiche del flusso di value passato			*/
/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
/********************************************************************************************/
void statistics_elab_step(struct STATISTICS *stat, float value);


/* [] END OF FILE */
