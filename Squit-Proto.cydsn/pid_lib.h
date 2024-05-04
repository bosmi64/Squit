/* ==============================================
 * PID Library functions			            *
 *												*
 * Copyright 2012-2013 Logic brainstorm         *
 * Author : Graziano G. Ravizza                 *
 * All Rights Reserved							*
 * UNPUBLISHED, LICENSED SOFTWARE.				*
 *												*
 * CONFIDENTIAL AND PROPRIETARY INFORMATION		*
 * WHICH IS THE PROPERTY OF your company.		*
 *												*
 * ==============================================
*/

/* CONTROL TYPES */
#define OPENLOOP_CONTROL		0
#define STD_FSPID				1
#define STD_FSPD				2
#define FIXEDKD_FSPD			3
#define LPFKD_FSPD				4
#define LPFKD_DUALLOOP_FSPD		5


/* vars interface functions */
float pid_derror_read(void);
float pid_ierror_read(void);


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
float fpSpid_k(float error, float Kp, float Kd, float Ki, uint16 Ksi, uint16 cvS);

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
float fpSpid_k2(struct MOTOR_AXIS *paxis, uint16 cvS);

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
float fpSpd_k(float error, float Kp, float Kd, uint16 cvS);


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
float fpSpd_kdfix(float error, float Kp, float Kd, uint16 cvS);


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
/* 	  cv(t) = SAT_cvS(Kp * e(t) + LPF(Kd * (e(t) - e(t-1), alpha))) 					*/
/****************************************************************************************/
float fpSpd_kdlpf(float error, float Kp, float Kd, float alpha, uint16 cvS);


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
float fp2LSpd_kdlpf(float error_intloop, float error_extloop, float Kp, float Kd, float alpha, uint16 cvS);


/****************************************************************************************/
/* Convert Time Constant Td into Derivative Gain Kd										*/
/* 	Input: 				float Td --> Derivative Time Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Kd = (Kp * Td)/TS = Kp[] * Td[msec] * fsampling[kHz]								*/
/****************************************************************************************/
float convTdKd(float Kp, float Td, float fsampling);


/****************************************************************************************/
/* Convert Derivative Gain Kd into Time Constant Td										*/
/* 	Input: 				float Kd --> Derivative Gain Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Td = (Kd * TS)/Kp = Kd[] / (Kp[] * fsampling[kHz])								*/
/****************************************************************************************/
float convKdTd(float Kp, float Kd, float fsampling);


/****************************************************************************************/
/* Convert Derivative Gain Kd into frequency(Time Constant Td)							*/
/* 	Input: 				float Kd --> Derivative Gain Constant							*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  f(Td) = 1/(2*PI*Td) [Hz]															*/
/****************************************************************************************/
float convKdfd(float Kp, float Kd, float fsampling);


/****************************************************************************************/
/* Convert Time Constant Ti into Integral Gain Ki										*/
/* 	Input: 				float Ti --> Integral Time Constant								*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Ki = (Kp * TS)/ Ti = Kp[] / (fsampling[kHz]) * Ti[msec])							*/
/****************************************************************************************/
float convTiKi(float Kp, float Ti, float fsampling);


/****************************************************************************************/
/* Convert Integral Gain Ki into Time Constant Ti 										*/
/* 	Input: 				float Ki --> Integral Gain Constant								*/
/* 	Input Parameters: 	float Kp --> Proportional Gain 	 								*/
/*						float fsampling [kHz] --> Control Sampling Frequency			*/
/*																						*/
/* CALCULUS -->																			*/
/* 	  Ti = (Kp * TS)/ Ki = Kp[] / (fsampling[kHz]) * Ki[msec])							*/
/****************************************************************************************/
float convKiTi(float Kp, float Ki, float fsampling);

/****************************************************************************************/
/* Clears all PIDs(t) real time datas:             										*/
/* 	e(t)t: 				                                   								*/
/* 	e(t-1)Parameters: 	                                 								*/
/*	integral(e(t)), d/dt(e(t), etc...	                     							*/
/****************************************************************************************/
void PIDs_DataClear(struct MOTOR_AXIS *paxis);


//[] END OF FILE
