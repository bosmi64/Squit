/*******************************************************************************
* File Name: isr_DAS.c  
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
#include <isr_DAS.h>

#if !defined(isr_DAS__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_DAS_intc` */

#include <das.h>
	
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
* Function Name: isr_DAS_Start
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
void isr_DAS_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_DAS_Disable();

    /* Set the ISR to point to the isr_DAS Interrupt. */
    isr_DAS_SetVector(&isr_DAS_Interrupt);

    /* Set the priority. */
    isr_DAS_SetPriority((uint8)isr_DAS_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_DAS_Enable();
}


/*******************************************************************************
* Function Name: isr_DAS_StartEx
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
void isr_DAS_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_DAS_Disable();

    /* Set the ISR to point to the isr_DAS Interrupt. */
    isr_DAS_SetVector(address);

    /* Set the priority. */
    isr_DAS_SetPriority((uint8)isr_DAS_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_DAS_Enable();
}


/*******************************************************************************
* Function Name: isr_DAS_Stop
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
void isr_DAS_Stop(void)
{
    /* Disable this interrupt. */
    isr_DAS_Disable();

    /* Set the ISR to point to the passive one. */
    isr_DAS_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_DAS_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_DAS.
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
CY_ISR(isr_DAS_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_DAS_Interrupt` */
	
	/* Print DAS datas over console */
	DAS_printf();
	
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_DAS_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_DAS_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_DAS_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_DAS_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_DAS__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_DAS_GetVector
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
cyisraddress isr_DAS_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_DAS__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_DAS_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_DAS_Start
*   or isr_DAS_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_DAS_Start or isr_DAS_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_DAS_SetPriority(uint8 priority)
{
    *isr_DAS_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_DAS_GetPriority
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
uint8 isr_DAS_GetPriority(void)
{
    uint8 priority;


    priority = *isr_DAS_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_DAS_Enable
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
void isr_DAS_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_DAS_INTC_SET_EN = isr_DAS__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_DAS_GetState
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
uint8 isr_DAS_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_DAS_INTC_SET_EN & (uint32)isr_DAS__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_DAS_Disable
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
void isr_DAS_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_DAS_INTC_CLR_EN = isr_DAS__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_DAS_SetPending
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
void isr_DAS_SetPending(void)
{
    *isr_DAS_INTC_SET_PD = isr_DAS__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_DAS_ClearPending
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
void isr_DAS_ClearPending(void)
{
    *isr_DAS_INTC_CLR_PD = isr_DAS__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
