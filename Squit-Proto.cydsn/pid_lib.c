/* ==============================================
 *                                              *
 * PID Library functions			            *
 *												*
 * Copyright 2012-2015 Logic brainstorm         *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH  IS THE PROPERTY OF Logic brainstorm	*
 * ==============================================
*/

/* Include files */
#include <device.h>
#include <math.h>
#include <gobee.h>
#include <pid_lib.h>

/* Internal Wars */
float static derror;		/* PID d/dt(error)						*/
float static ierror;		/* PID Integral(error(t))				*/

/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 			/* PAN Motor Axis Parameters & RT Datas	*/


/* vars interface functions */
float pid_derror_read(void)
{
	return derror;
}

float pid_ierror_read(void)
{
	return ierror;
}

// ****************************
// *** FLOATING POINT PIDs ***
// ****************************

/****************************************************************************************/
/* Float Positional Saturated PID with K constants I (flat variables passing)			*/
/* 	Input: 				float e(t) --> positional error(t)								*/
/* 	Input Parameters: 	float Kp, Kd, Ki	 											*/
/*																						*/
/*						uint16 Ksi -->	Integral Action Saturation						*/
/*						-Ksi <= (Integral(e(t)) * Ki) <= + Ksi							*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Global vars:		float derror --> e(t)-e(t-1)									*/
/*						float ierror --> sum(e(k)) 0<=k<=t								*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e(t) + Kd * (e(t) - e(t-1)) + SAT_Ksi(ki * Integral(e(t)))) 	*/
/****************************************************************************************/
float fpSpid_k(float error, float Kp, float Kd, float Ki, uint16 Ksi, uint16 cvS)
{
	static float error_bef;			/* error(t-1) buffer 					*/
	static float control_var=0;		/* cv(t)								*/
	
	
	/***************************/
	/* d/dt(error) calculation */
	/***************************/
	derror = error - error_bef;
	error_bef = error;
	
	/********************************************************/
	/* Rectangular Integration Approximation 				*/
	/* and saturation (float)								*/
	/********************************************************/
	
	/* Integral(e(t)) Accumulation 		*/
	ierror = ierror + error;			

	/* Integral(e(t) Saturation			*/
	if (ierror >= (float)Ksi)
	{
		ierror = (float)Ksi;
	}
	if (ierror <= -(float)Ksi)
	{
		ierror = -(float)Ksi;
	}
	
	/************************************************************************/
	/* CONTROL VARIABLE CALCULUS 											*/
	/* 	  cv(t) =   Kp * e(t) + Kd * (e(t) - e(t-1)) + ki * Integral(e(t))	*/
	/************************************************************************/
	control_var	 = Kp * error
						 + Kd * derror
						 + Ki * ierror;


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}

/****************************************************************************************/
/* Float Positional Saturated PID with K constants II (structured variables passing)	*/
/* 	Input: 				float e(t) --> positional error(t)								*/
/* 	Input Parameters: 	struct MOTOR_AXIS *paxis										*/
/*																						*/
/*						uint16 Ksi -->	Integral Action Saturation						*/
/*						-Ksi <= (Integral(e(t)) * Ki) <= + Ksi,g						*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Static Local vars:	float derror --> e(t)-e(t-1)									*/
/*						float ierror --> sum(e(k)) 0<=k<=t								*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e(t) + Kd * (e(t) - e(t-1)) + SAT_Ksi(ki * Integral(e(t)))) 	*/
/****************************************************************************************/
float fpSpid_k2(struct MOTOR_AXIS *paxis, uint16 cvS)
{
	static float control_var=0;		/* cv(t)				*/
	
	/********************************************************/
	/* Rectangular Integration Approximation 				*/
	/* and saturation (float)								*/
	/********************************************************/
	
	/* Integral(e(t)) Accumulation 		*/
	(*paxis).mc.ierror = (*paxis).mc.ierror + (*paxis).mc.error;			

	/* Integral(e(t) Saturation					*/
	if ((*paxis).mc.ierror >= (*paxis).param.Ksif.fnum)
	{
		(*paxis).mc.ierror = (*paxis).param.Ksif.fnum;
	}
	if ((*paxis).mc.ierror <= -(*paxis).param.Ksif.fnum)
	{
		(*paxis).mc.ierror = -(*paxis).param.Ksif.fnum;
	}
	
	
	/************************************************************************/
	/* CONTROL VARIABLE CALCULUS 											*/
	/* 	  cv(t) =   Kp * e(t) + Kd * (e(t) - e(t-1)) + ki * Integral(e(t))	*/
	/************************************************************************/
	control_var	 = (*paxis).param.Kpf.fnum 		   * (*paxis).mc.error
						 + (*paxis).param.Kdf.fnum * (*paxis).mc.derror
						 + (*paxis).param.Kif.fnum * (*paxis).mc.ierror;


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}


/****************************************************************************************/
/* Float Positional Saturated PD with K constants										*/
/* 	Input: 				float e(t) --> positional error(t)								*/
/* 	Input Parameters: 	float Kp, Kd		 											*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Global vars:		float derror --> e(t)-e(t-1)									*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e(t) + Kd * (e(t) - e(t-1))) 								*/
/****************************************************************************************/

float fpSpd_k(float error, float Kp, float Kd, uint16 cvS)
{
	static float error_bef;			/* error(t-1) buffer 					*/
	static float control_var=0;		/* cv(t)								*/
	
	
	/***************************/
	/* d/dt(error) calculation */
	/***************************/
	derror = error - error_bef;
	error_bef = error;
	
	
	/************************************************************************/
	/* CONTROL VARIABLE CALCULUS 											*/
	/* 	  cv(t) =   Kp * e(t) + Kd * (e(t) - e(t-1))						*/
	/************************************************************************/
	control_var	 = Kp * error
						 + Kd * derror;


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}



/****************************************************************************************/
/* Float Positional Saturated PD with K constants and FIXED Kd Action					*/
/* 	Input: 				float e(t) --> positional error(t)								*/
/* 	Input Parameters: 	float Kp, Kd		 											*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Global vars:		float derror --> e(t)-e(t-1)									*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e(t) + Kd *  ...)			 								*/
/* 	  							  		(+1) if (e(t) - e(t-1))>0 						*/
/* 	  							  		(-1) if (e(t) - e(t-1))<0 						*/
/* 	  							  		(0)  if (e(t) - e(t-1))=0 						*/
/****************************************************************************************/

float fpSpd_kdfix(float error, float Kp, float Kd, uint16 cvS)
{
	static float error_bef;			/* error(t-1) buffer 					*/
	static float control_var=0;		/* cv(t)								*/
	
	
	/***************************/
	/* d/dt(error) calculation */
	/***************************/
	derror = error - error_bef;
	error_bef = error;
	
	
	/************************************************************************/
	/* CONTROL VARIABLE CALCULUS 											*/
	/* 	  cv(t) =   Kp * e(t) + Kd * (e(t) - e(t-1))						*/
	/************************************************************************/
	control_var	 = Kp * error;
	
	if (derror >= 1)
	{
		control_var = control_var + Kd;
	}
	
	if (derror <= -1)
	{
		control_var = control_var - Kd;
	}


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}


/****************************************************************************************/
/* Float Positional Saturated PD with K constants and Derivative Pole alpha				*/
/* 	Input: 				float e(t) --> positional error(t)								*/
/* 	Input Parameters: 	float Kp, Kd, alpha		 										*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Global vars:		float derror --> e(t)-e(t-1)									*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e(t) + LPF(Kd * (e(t) - e(t-1), N))) 						*/
/****************************************************************************************/

float fpSpd_kdlpf(float error, float Kp, float Kd, float alpha, uint16 cvS)
{
	static float error_bef;			/* error(t-1) buffer 					*/
	static float control_var=0;		/* cv(t)								*/
	static float derivative_lowpass=0;/* LPF(Kd*(e(t)-e(t-1)))				*/	
	
	/***************************/
	/* d/dt(error) calculation */
	/***************************/
	derror = error - error_bef;
	error_bef = error;
	
	/****************************************************************************/
	/* derivative action + High frequency pole Kd/(Kp*N)						*/
	/*																			*/
	/* derivative action = Kd*s/(1+KD/((kp*N)*s))								*/
	/*																			*/
	/* "d_pid.pdf" pg.2 --> realizzazione causale dei controllori PID			*/
	/****************************************************************************/
	/* Based on Exponential error smoothing function							*/
	/* (exactly like RC first order low pass filter) 							*/
	/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
	/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
	/*																			*/
	/* tau = deltaT *(1 - alpha)/alpha											*/
	/*       deltaT = 500 usec @ 2kHzHz											*/
	/*		 alpha  = 0.05														*/
	/*		 --> tau = 127	 msec --> f=1/(2*PI*tau)= 105Hz						*/
	/****************************************************************************/

	derivative_lowpass = derivative_lowpass + alpha * (Kd * derror - derivative_lowpass);

	
	/************************************************************************/
	/* CONTROL VARIABLE CALCULUS 											*/
	/* 	  cv(t) =   Kp * e(t) + LPF(Kd * (e(t) - e(t-1)))					*/
	/************************************************************************/
	control_var	 = Kp * error
						 + derivative_lowpass;


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}

/****************************************************************************************/
/* Float Positional DUAL LOOP Saturated PD with K constants and Derivative Pole alpha	*/
/*																						*/
/* 	Inputs: 			float e_extloop(t) --> positional error(t) on external loop =	*/
/*											   master_encoder(t) - backslash_encoder(t) */
/*						float e_intloop(t) --> positional error(t) on internal loop	=	*/
/*											   master_encoder(t) - feedback_encoder(t)	*/
/* 	Input Parameters: 	float Kp, Kd, alpha		 										*/
/*																						*/
/*	Input Parameters:	uint16 cv_S --> Control Variable Saturation						*/
/*						-cvS <= cv(t) <= + cvS											*/
/*																						*/
/* 	Output:				float cv(t)  --> control variable								*/
/*  Global vars:		float derror --> e_intloop(t)-e_intloop(t-1)					*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  cv(t) = SAT_cvS(Kp * e_extloop(t) + LPF(Kd * (e_intloop(t) - e_intloop(t-1), N))) */
/****************************************************************************************/

float fp2LSpd_kdlpf(float error_intloop, float error_extloop, float Kp, float Kd, float alpha, uint16 cvS)
{
	static float error_intloop_bef;		/* error_intloop(t-1) buffer 				*/
	static float control_var=0;			/* cv(t)									*/
	static float derivative_lowpass=0;	/* LPF(Kd*(e_intloop(t)-e_intloop(t-1)))	*/	
	
	/***********************************/
	/* d/dt(error_intloop) calculation */
	/***********************************/
	derror = error_intloop - error_intloop_bef;
	error_intloop_bef = error_intloop;
	
	/****************************************************************************/
	/* derivative action + High frequency pole Kd/(Kp*N)						*/
	/*																			*/
	/* derivative action = Kd*s/(1+KD/((kp*N)*s))								*/
	/*																			*/
	/* "d_pid.pdf" pg.2 --> realizzazione causale dei controllori PID			*/
	/****************************************************************************/
	/* Based on Exponential error smoothing function							*/
	/* (exactly like RC first order low pass filter) 							*/
	/* http://en.wikipedia.org/wiki/Low-pass_filter#Discrete-time_realization	*/
	/* http://en.wikipedia.org/wiki/Exponential_smoothing						*/
	/*																			*/
	/* tau = deltaT *(1 - alpha)/alpha											*/
	/*       deltaT = 500 usec @ 2kHzHz											*/
	/*		 alpha  = 0.05														*/
	/*		 --> tau = 127	 msec --> f=1/(2*PI*tau)= 105Hz						*/
	/****************************************************************************/

	derivative_lowpass = derivative_lowpass + alpha * (Kd * derror - derivative_lowpass);

	
	/********************************************************************************/
	/* CONTROL VARIABLE CALCULUS 													*/
	/* 	  cv(t) =   Kp * e_extloop(t) + LPF(Kd * (e_intloop(t) - e_intloop(t-1)))	*/
	/********************************************************************************/
	control_var	 = Kp * error_extloop
						 + derivative_lowpass;


	/****************************************/
	/* cv(t) = cv(t) saturated to |cvS| 	*/
	/****************************************/
	
	if (control_var >= (float)cvS)
	{
		control_var = (float)cvS;
	}

	if (control_var <= -(float)cvS)
	{
		control_var = -(float)cvS;
	}

	return control_var;
}





/****************************************************************************************/
/* Convert Time Constant Td into Derivative Gain Kd										*/
/* 	Input: 				float Td --> Derivative Time Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Kd = (Kp * Td)/TS = Kp[] * Td[msec] * fsampling[kHz]								*/
/****************************************************************************************/

float convTdKd(float Kp, float Td, float fsampling)
{
	return (Kp * Td * fsampling);
}

/****************************************************************************************/
/* Convert Derivative Gain Kd into Time Constant Td										*/
/* 	Input: 				float Kd --> Derivative Gain Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Td = (Kd * TS)/Kp = Kd[] / (Kp[] * fsampling[kHz])								*/
/****************************************************************************************/

float convKdTd(float Kp, float Kd, float fsampling)
{
	return (Kd / (Kp * fsampling));
}


/****************************************************************************************/
/* Convert Derivative Gain Kd into frequency(Time Constant Td)							*/
/* 	Input: 				float Kd --> Derivative Gain Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  f(Td) = 1/(2*PI*Td) [Hz]															*/
/****************************************************************************************/

float convKdfd(float Kp, float Kd, float fsampling)
{

	return (1000/(6.2832 * Kd / (Kp * fsampling)));
}


/****************************************************************************************/
/* Convert Time Constant Ti into Integral Gain Ki										*/
/* 	Input: 				float Ti --> Integral Time Constant								*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Ki = (Kp * TS)/ Ti = Kp[] / (fsampling[kHz]) * Ti[msec])							*/
/****************************************************************************************/

float convTiKi(float Kp, float Ti, float fsampling)
{
	return (Kp / (fsampling * Ti));
}


/****************************************************************************************/
/* Convert Integral Gain Ki into Time Constant Ti 										*/
/* 	Input: 				float Ki --> Integral Gain Constant								*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Ti = (Kp * TS)/ Ki = Kp[] / (fsampling[kHz]) * Ki[msec])							*/
/****************************************************************************************/

float convKiTi(float Kp, float Ki, float fsampling)
{
	return (Kp / (fsampling * Ki));
}

/****************************************************************************************/
/* Clears all PIDs(t) real time datas:             										*/
/* 	e(t)t: 				                                   								*/
/* 	e(t-1)Parameters: 	                                 								*/
/*	integral(e(t)), d/dt(e(t), etc...	                     							*/
/****************************************************************************************/
void PIDs_DataClear(struct MOTOR_AXIS *paxis)
{		
	(*paxis).mc.error = 0;
	(*paxis).mc.error_bef = 0;
	(*paxis).mc.ierror = 0;
	(*paxis).mc.derror = 0;
	(*paxis).mc.derivative_lowpass = 0;
}



/* [] END OF FILE */
