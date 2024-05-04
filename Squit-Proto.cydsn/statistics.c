/* =============================================
 * STATISTICS Library code	     				*
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
/* Include files */
#include <device.h>
#include <math.h>
#include <statistics.h>


/* Floating point square function	*/
double square(float x)
{
    return(x*x);
}

/********************************************************************************************/
/* Statistics Initialization																*/
/********************************************************************************************/
void statistics_init(struct STATISTICS *stat)
{
	(*stat).messg = STATISTICS_STOP;	
}

/********************************************************************************************/
/* Statistics Start																			*/
/********************************************************************************************/
void statistics_start(struct STATISTICS *stat)
{
	(*stat).messg = STATISTICS_START;	
}


/********************************************************************************************/
/* Statistics Stop																			*/
/********************************************************************************************/
void statistics_stop(struct STATISTICS *stat)
{
	(*stat).messg = STATISTICS_STOP;	
}


/********************************************************************************************/
/* Value Statistics Iterative Calculus														*/
/* iteration >= 2																			*/
/* Calcola il valor medio e altre variabili statistiche del flusso di value passato			*/
/* Fonte: http://www.cs.berkeley.edu/~mhoemmen/cs194/Tutorials/variance.pdf					*/
/* vedi anche \Study\Statistica\variance(Computing the standard deviation efficiently).pdf	*/
/********************************************************************************************/
void statistics_elab_step(struct STATISTICS *stat, float value)
{
	(*stat).tick = (*stat).tick + 1;	//increment statistic tick
	
	if ((*stat).messg == STATISTICS_START)
	{
		(*stat).tick = 0;				/* tick = 0 [ms]									*/
		(*stat).mean  = value;			/* mean value(t) 									*/
		(*stat).mean_previous = value; 	/* mean value(t-1)									*/		
		(*stat).min   = value;			/* minimum value(t) 								*/
		(*stat).max   = value;			/* maximum value(t) 								*/
		(*stat).range = 0;				/* range = maximum - minimum value 					*/
		(*stat).scarto = 0;				/* scarto = value - mean(value)						*/
		(*stat).Qk	= 0;				/* Qk value for sample variance iterative calculus 	*/
		(*stat).Qk_previous = 0;		/* Qk(t-1)											*/
		
		(*stat).iteration_num = 2;		/* iteration_num = n = 2							*/
		
		(*stat).messg = STATISTICS_STARTED; /* issue STAT STARTED MESSAGE 					*/
	}
	else
		if ((*stat).messg != STATISTICS_STOP)
		{
			/* Mean calculus iterative step */
			(*stat).mean = ((*stat).mean_previous * ((*stat).iteration_num - 1) + value) / (*stat).iteration_num;
			(*stat).mean_previous = (*stat).mean;
			
//			/* Sample Variance iterative step */
//			(*stat).Qk = (*stat).Qk_previous + ((((*stat).iteration_num - 1 ) * pow(value - (*stat).mean_previous, 2)) / (*stat).iteration_num);
//			(*stat).variance = (*stat).Qk / ((*stat).iteration_num - 1);
//
//			/* scarto(t) iterative step */
//			(*stat).scarto = value - (*stat).mean;
			
			/* n = n + 1 */
			(*stat).iteration_num = (*stat).iteration_num + 1;
			
			/* Angle Range calculus */
			if (value < (*stat).min)
				(*stat).min = value;

			if (value > (*stat).max)
				(*stat).max = value;
				
			(*stat).range = (*stat).max - (*stat).min;	
		}	
}

/* [] END OF FILE */
