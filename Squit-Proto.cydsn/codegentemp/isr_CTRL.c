/*******************************************************************************
* File Name: isr_CTRL.c  
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
#include <isr_CTRL.h>

#if !defined(isr_CTRL__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_CTRL_intc` */

#include <device.h>
	
#include <gobee.h>
#include <sensor_CTRL.h>
#include <mover.h>
#include <motor_CTRL.h>
	
extern uint16 isr_START_check_counter;
extern uint16 isr_STOP_check_counter;
	
/* EXTERNAL Feedback Encoder */
extern struct ENCODER pan_feedback_encoder; 	/* PAN Feedback Encoder Parameters & RT Datas  */
extern struct ENCODER tilt_feedback_encoder; 	/* TILT Feedback Encoder Parameters & RT Datas */
    
/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 				/* PAN Motor Axis Parameters & RT Datas		*/
extern struct MOTOR_AXIS tilt_axis; 			/* TILT Motor Axis Parameters & RT Datas	*/
extern struct MOTOR_AXIS *Selected_ANAOUT;		/* Selected Axis for Analog Output			*/
	
/* EXTERN MOVER PAN&TILT  */
extern mover_type mover_pan;			/* mover PAN structure 		*/
extern mover_type mover_tilt;			/* mover TILT structure 	*/
    
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
* Function Name: isr_CTRL_Start
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
void isr_CTRL_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_CTRL_Disable();

    /* Set the ISR to point to the isr_CTRL Interrupt. */
    isr_CTRL_SetVector(&isr_CTRL_Interrupt);

    /* Set the priority. */
    isr_CTRL_SetPriority((uint8)isr_CTRL_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_CTRL_Enable();
}


/*******************************************************************************
* Function Name: isr_CTRL_StartEx
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
void isr_CTRL_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_CTRL_Disable();

    /* Set the ISR to point to the isr_CTRL Interrupt. */
    isr_CTRL_SetVector(address);

    /* Set the priority. */
    isr_CTRL_SetPriority((uint8)isr_CTRL_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_CTRL_Enable();
}


/*******************************************************************************
* Function Name: isr_CTRL_Stop
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
void isr_CTRL_Stop(void)
{
    /* Disable this interrupt. */
    isr_CTRL_Disable();

    /* Set the ISR to point to the passive one. */
    isr_CTRL_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_CTRL_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_CTRL.
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
CY_ISR(isr_CTRL_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_CTRL_Interrupt` */
	

#if MEASURE_CONTROL_ISR
	Control_Reg_LED_Write(0x01);
	//SET_ON(LED_OK);	/* ON LED OK - MEASUREMENT	POINT*/
#endif
	isr_START_check_counter++;	

	/************************************************************/
	/* GoBee Real Time CONTROL SENSORS Sampling & Control 		*/
	/************************************************************/
	Control_sensors_processing();
 
	/********************************/
	/* Analog SHOW			        */
	/********************************/
    AnalogShow(Selected_ANAOUT);
	
	/*************************************/	
    /* GoBee Motor Control               */
	/*************************************/	
    motor_control(&pan_axis,  &mover_pan);
    motor_control(&tilt_axis, &mover_tilt);
	
	isr_STOP_check_counter++;
#if MEASURE_CONTROL_ISR
	Control_Reg_LED_Write(0x00);
	//SET_OFF(LED_OK);	/* OFF LED OK - MEASUREMENT	POINT*/
#endif

    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_CTRL_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_CTRL_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_CTRL_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_CTRL_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_CTRL__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_CTRL_GetVector
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
cyisraddress isr_CTRL_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_CTRL__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_CTRL_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_CTRL_Start
*   or isr_CTRL_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_CTRL_Start or isr_CTRL_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_CTRL_SetPriority(uint8 priority)
{
    *isr_CTRL_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_CTRL_GetPriority
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
uint8 isr_CTRL_GetPriority(void)
{
    uint8 priority;


    priority = *isr_CTRL_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_CTRL_Enable
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
void isr_CTRL_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_CTRL_INTC_SET_EN = isr_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_CTRL_GetState
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
uint8 isr_CTRL_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_CTRL_INTC_SET_EN & (uint32)isr_CTRL__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_CTRL_Disable
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
void isr_CTRL_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_CTRL_INTC_CLR_EN = isr_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_CTRL_SetPending
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
void isr_CTRL_SetPending(void)
{
    *isr_CTRL_INTC_SET_PD = isr_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_CTRL_ClearPending
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
void isr_CTRL_ClearPending(void)
{
    *isr_CTRL_INTC_CLR_PD = isr_CTRL__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
