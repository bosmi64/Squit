/*******************************************************************************
* File Name: isr_BUTTON.c  
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
#include <isr_BUTTON.h>

#if !defined(isr_BUTTON__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_BUTTON_intc` */

	#include <device.h>
	#include <gobee.h>
	#include <gobeelib.h>
	#include <mover.h>
	#include <motor_CTRL.h>	
	#include <estimators.h>
	#include <gml.h>
	
	extern uint8 machine_state;		/*  Gobee Machine State */

	/* GLOBAL MOTOR AXIS STRUCTURES */
	extern struct MOTOR_AXIS pan_axis;			/* PAN Motor Axis Parameters & R TDatas		*/	
	extern struct MOTOR_AXIS tilt_axis;			/* TILT Motor Axis Parameters & R TDatas	*/		
	
	uint8 idx;
	
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
* Function Name: isr_BUTTON_Start
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
void isr_BUTTON_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_BUTTON_Disable();

    /* Set the ISR to point to the isr_BUTTON Interrupt. */
    isr_BUTTON_SetVector(&isr_BUTTON_Interrupt);

    /* Set the priority. */
    isr_BUTTON_SetPriority((uint8)isr_BUTTON_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_BUTTON_Enable();
}


/*******************************************************************************
* Function Name: isr_BUTTON_StartEx
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
void isr_BUTTON_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_BUTTON_Disable();

    /* Set the ISR to point to the isr_BUTTON Interrupt. */
    isr_BUTTON_SetVector(address);

    /* Set the priority. */
    isr_BUTTON_SetPriority((uint8)isr_BUTTON_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_BUTTON_Enable();
}


/*******************************************************************************
* Function Name: isr_BUTTON_Stop
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
void isr_BUTTON_Stop(void)
{
    /* Disable this interrupt. */
    isr_BUTTON_Disable();

    /* Set the ISR to point to the passive one. */
    isr_BUTTON_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_BUTTON_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_BUTTON.
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
CY_ISR(isr_BUTTON_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_BUTTON_Interrupt` */
	
	if (machine_state == GOBEE_ENERGIZED)
	{
		Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
		CyDelay(250);						/* 250msec sec delay	*/
		Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/

		/* Mapping State Machine Initialization & STOP */
		MappingStateMachineInit();
			
		machine_state = GOBEE_DEENERGIZED;
		motor_sleep(&pan_axis);
		motor_sleep(&tilt_axis);		
	}
	else if (machine_state == GOBEE_DEENERGIZED)
	{
 		for (idx = 0; idx < 3; idx++)
 		{			
			Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
			CyDelay(80);						/* 250msec sec delay	*/
			Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/
			CyDelay(30);						/* 125msec sec delay	*/			
		}	

		motor_init(&pan_axis);						/* Initialize Pan Axis  */
		motor_init(&tilt_axis);						/* Initialize Tilt Axis */			
		QuadDec_PAN_Start();						/* Reset PAN Feedback Encoder Counter	*/
		QuadDec_TILT_Start();						/* Reset TILT Feedback Encoder Counter	*/
			
		/* CLU state machine Init */
		clu_sm_init();
		
		/* Mapping State Machine START */
		MappingStateMachineStart();

		machine_state = GOBEE_ENERGIZED;			
		motor_energize(&pan_axis);
		motor_energize(&tilt_axis);		
	}	
	
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_BUTTON_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_BUTTON_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_BUTTON_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_BUTTON_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_BUTTON__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_BUTTON_GetVector
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
cyisraddress isr_BUTTON_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_BUTTON__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_BUTTON_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_BUTTON_Start
*   or isr_BUTTON_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_BUTTON_Start or isr_BUTTON_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_BUTTON_SetPriority(uint8 priority)
{
    *isr_BUTTON_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_BUTTON_GetPriority
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
uint8 isr_BUTTON_GetPriority(void)
{
    uint8 priority;


    priority = *isr_BUTTON_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_BUTTON_Enable
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
void isr_BUTTON_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_BUTTON_INTC_SET_EN = isr_BUTTON__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_GetState
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
uint8 isr_BUTTON_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_BUTTON_INTC_SET_EN & (uint32)isr_BUTTON__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_BUTTON_Disable
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
void isr_BUTTON_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_BUTTON_INTC_CLR_EN = isr_BUTTON__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_SetPending
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
void isr_BUTTON_SetPending(void)
{
    *isr_BUTTON_INTC_SET_PD = isr_BUTTON__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_ClearPending
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
void isr_BUTTON_ClearPending(void)
{
    *isr_BUTTON_INTC_CLR_PD = isr_BUTTON__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
