/*******************************************************************************
* File Name: isr_FAULT_CTRL.c  
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
#include <isr_FAULT_CTRL.h>

#if !defined(isr_FAULT_CTRL__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_FAULT_CTRL_intc` */

#include <gobee.h>
#include <mover.h>
#include <motor_CTRL.h>
	
/* External Motor Axis 		 */
extern struct MOTOR_AXIS pan_axis; 			/* PAN  Motor Axis Parameters & RT Datas	*/
extern struct MOTOR_AXIS tilt_axis; 		/* TILT Motor Axis Parameters & RT Datas	*/
	
/* GoBee Faults structure */
extern struct GOBEE_FAULTS gobeeFaults;	
	
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
* Function Name: isr_FAULT_CTRL_Start
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
void isr_FAULT_CTRL_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_FAULT_CTRL_Disable();

    /* Set the ISR to point to the isr_FAULT_CTRL Interrupt. */
    isr_FAULT_CTRL_SetVector(&isr_FAULT_CTRL_Interrupt);

    /* Set the priority. */
    isr_FAULT_CTRL_SetPriority((uint8)isr_FAULT_CTRL_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_FAULT_CTRL_Enable();
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_StartEx
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
void isr_FAULT_CTRL_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_FAULT_CTRL_Disable();

    /* Set the ISR to point to the isr_FAULT_CTRL Interrupt. */
    isr_FAULT_CTRL_SetVector(address);

    /* Set the priority. */
    isr_FAULT_CTRL_SetPriority((uint8)isr_FAULT_CTRL_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_FAULT_CTRL_Enable();
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_Stop
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
void isr_FAULT_CTRL_Stop(void)
{
    /* Disable this interrupt. */
    isr_FAULT_CTRL_Disable();

    /* Set the ISR to point to the passive one. */
    isr_FAULT_CTRL_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_FAULT_CTRL.
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
CY_ISR(isr_FAULT_CTRL_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_FAULT_CTRL_Interrupt` */

	//PAN FBK Encoder FAULT processing
	if (gobeeFaults.FbkEncFaults & PAN_FBKENC_INVT_FAULT)			// PAN FBK Encoder Invalid Transition
	{
		gobeeFaults.pan_FE_FAULT_prescaler++;
		
		if (gobeeFaults.pan_FE_FAULT_prescaler >= 5)
		{
			motor_sleep(&pan_axis);
			gobeeFaults.general = gobeeFaults.general | GEN_PAN_FAULT | GEN_FBKENC_FAULT;		
		}
	}
	else
	{
		gobeeFaults.pan_FE_FAULT_prescaler = 0;
	}
	
	//TILT FBK Encoder FAULT processing
	if (gobeeFaults.FbkEncFaults & TILT_FBKENC_INVT_FAULT)			// TILT FBK Encoder Invalid Transition
	{
		gobeeFaults.tilt_FE_FAULT_prescaler++;
		
		if (gobeeFaults.tilt_FE_FAULT_prescaler >= 5)
		{		
			motor_sleep(&tilt_axis);	
			gobeeFaults.general = gobeeFaults.general | GEN_TILT_FAULT | GEN_FBKENC_FAULT;			
		}
	}	
	else
	{
		gobeeFaults.tilt_FE_FAULT_prescaler = 0;
	}	
	
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_FAULT_CTRL_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_FAULT_CTRL_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_FAULT_CTRL_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_FAULT_CTRL__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_GetVector
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
cyisraddress isr_FAULT_CTRL_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_FAULT_CTRL__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_FAULT_CTRL_Start
*   or isr_FAULT_CTRL_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_FAULT_CTRL_Start or isr_FAULT_CTRL_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_FAULT_CTRL_SetPriority(uint8 priority)
{
    *isr_FAULT_CTRL_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_GetPriority
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
uint8 isr_FAULT_CTRL_GetPriority(void)
{
    uint8 priority;


    priority = *isr_FAULT_CTRL_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_Enable
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
void isr_FAULT_CTRL_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_FAULT_CTRL_INTC_SET_EN = isr_FAULT_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_GetState
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
uint8 isr_FAULT_CTRL_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_FAULT_CTRL_INTC_SET_EN & (uint32)isr_FAULT_CTRL__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_Disable
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
void isr_FAULT_CTRL_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_FAULT_CTRL_INTC_CLR_EN = isr_FAULT_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_SetPending
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
void isr_FAULT_CTRL_SetPending(void)
{
    *isr_FAULT_CTRL_INTC_SET_PD = isr_FAULT_CTRL__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_FAULT_CTRL_ClearPending
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
void isr_FAULT_CTRL_ClearPending(void)
{
    *isr_FAULT_CTRL_INTC_CLR_PD = isr_FAULT_CTRL__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
