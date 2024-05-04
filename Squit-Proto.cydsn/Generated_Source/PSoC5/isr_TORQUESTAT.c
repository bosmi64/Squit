/*******************************************************************************
* File Name: isr_TORQUESTAT.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <isr_TORQUESTAT.h>

#if !defined(isr_TORQUESTAT__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_TORQUESTAT_intc` */
#include <gobee.h>
#include <statistics.h>
#include <torquestat.h>

/* extern Feedback Encoder structure */
extern struct ENCODER pan_feedback_encoder;  	/* PAN Feedback Encoder Parameters & RT Datas	*/
extern struct ENCODER tilt_feedback_encoder; 	/* TILT Feedback Encoder Parameters & RT Datas	*/

/* extern MOTOR AXIS STRUCTURES */
extern struct MOTOR_AXIS pan_axis;				/* PAN  Motor Axis Parameters & RT Datas		*/
extern struct MOTOR_AXIS tilt_axis;				/* TILT Motor Axis Parameters & RT Datas		*/
	
/* extern axis TORQUE Estimator	*/
struct TORQUESTAT pan_torque_stat;				/* PAN  Torque Statistics Real Time Datas  	  	*/
struct TORQUESTAT tilt_torque_stat;				/* TILT Torque Statistics Real Time Datas		*/	

/* extern axis current and power STATISTICS	*/
extern struct STATISTICS pan_current_stat;		/* PAN  Current  Statistic    [A]           (Motor Torque estimating) */	
extern struct STATISTICS pan_qpower_stat;		/* PAN  quasi-power Statistic [A * rad/sec] (Motor Power estimating)  */
extern struct STATISTICS tilt_current_stat;		/* TILT Current  Statistic    [A]           (Motor Torque estimating) */
extern struct STATISTICS tilt_qpower_stat;		/* TILT quasi-power Statistic [A * rad/sec] (Motor Power estimating)  */
	
/* Local Wars */
float pan_abs_motor_velocity;		/* Pan  Motor abs(velocity(t)) calculated @ 3.125Hz sampling rate	*/
float tilt_abs_motor_velocity;		/* Tilt Motor abs(velocity(t)) calculated @ 3.125Hz sampling rate	*/
	
/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: isr_TORQUESTAT_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_TORQUESTAT_Disable();

    /* Set the ISR to point to the isr_TORQUESTAT Interrupt. */
    isr_TORQUESTAT_SetVector(&isr_TORQUESTAT_Interrupt);

    /* Set the priority. */
    isr_TORQUESTAT_SetPriority((uint8)isr_TORQUESTAT_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_TORQUESTAT_Enable();
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_TORQUESTAT_Disable();

    /* Set the ISR to point to the isr_TORQUESTAT Interrupt. */
    isr_TORQUESTAT_SetVector(address);

    /* Set the priority. */
    isr_TORQUESTAT_SetPriority((uint8)isr_TORQUESTAT_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_TORQUESTAT_Enable();
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_Stop(void)
{
    /* Disable this interrupt. */
    isr_TORQUESTAT_Disable();

    /* Set the ISR to point to the passive one. */
    isr_TORQUESTAT_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_TORQUESTAT.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(isr_TORQUESTAT_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_TORQUESTAT_Interrupt` */
	
	/********************************************************************/
	/* Calculates Pan&Tilt motor abs(velocity) (3.125Hz mean value)		*/
	/********************************************************************/	
	pan_abs_motor_velocity  = motor_abs_velocity_sampling(&pan_torque_stat,  pan_axis.mc.slave_enc.position);
	tilt_abs_motor_velocity = motor_abs_velocity_sampling(&tilt_torque_stat, tilt_axis.mc.slave_enc.position);

	/********************************************************************/
	/* Elaborate Pan&Tilt statistics of the current (i(t))				*/
	/********************************************************************/
	current_statistics_elab_step(&pan_torque_stat,  &pan_current_stat,  pan_axis.mc.current);
	current_statistics_elab_step(&tilt_torque_stat, &tilt_current_stat, tilt_axis.mc.current);
	
	/********************************************************************/	
	/* Elaborate Pan&Tilt statistics of the quasi-power [A * rad/sec]	*/
	/********************************************************************/
	qpower_statistics_elab_step(&pan_torque_stat,  &pan_qpower_stat,  pan_axis.mc.current,  pan_abs_motor_velocity);
	qpower_statistics_elab_step(&tilt_torque_stat, &tilt_qpower_stat, tilt_axis.mc.current, tilt_abs_motor_velocity);

    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_TORQUESTAT_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_TORQUESTAT_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_TORQUESTAT__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress isr_TORQUESTAT_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_TORQUESTAT__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_TORQUESTAT_Start
*   or isr_TORQUESTAT_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_TORQUESTAT_Start or isr_TORQUESTAT_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_SetPriority(uint8 priority)
{
    *isr_TORQUESTAT_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 isr_TORQUESTAT_GetPriority(void)
{
    uint8 priority;


    priority = *isr_TORQUESTAT_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_TORQUESTAT_INTC_SET_EN = isr_TORQUESTAT__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 isr_TORQUESTAT_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_TORQUESTAT_INTC_SET_EN & (uint32)isr_TORQUESTAT__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_TORQUESTAT_INTC_CLR_EN = isr_TORQUESTAT__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_SetPending(void)
{
    *isr_TORQUESTAT_INTC_SET_PD = isr_TORQUESTAT__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_TORQUESTAT_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void isr_TORQUESTAT_ClearPending(void)
{
    *isr_TORQUESTAT_INTC_CLR_PD = isr_TORQUESTAT__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
