/*******************************************************************************
* File Name: CHRUM7_ISR.c  
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
#include <CHRUM7_ISR.h>

#if !defined(CHRUM7_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START CHRUM7_ISR_intc` */

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
* Function Name: CHRUM7_ISR_Start
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
void CHRUM7_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    CHRUM7_ISR_Disable();

    /* Set the ISR to point to the CHRUM7_ISR Interrupt. */
    CHRUM7_ISR_SetVector(&CHRUM7_ISR_Interrupt);

    /* Set the priority. */
    CHRUM7_ISR_SetPriority((uint8)CHRUM7_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    CHRUM7_ISR_Enable();
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_StartEx
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
void CHRUM7_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    CHRUM7_ISR_Disable();

    /* Set the ISR to point to the CHRUM7_ISR Interrupt. */
    CHRUM7_ISR_SetVector(address);

    /* Set the priority. */
    CHRUM7_ISR_SetPriority((uint8)CHRUM7_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    CHRUM7_ISR_Enable();
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_Stop
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
void CHRUM7_ISR_Stop(void)
{
    /* Disable this interrupt. */
    CHRUM7_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    CHRUM7_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for CHRUM7_ISR.
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
CY_ISR(CHRUM7_ISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START CHRUM7_ISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling CHRUM7_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use CHRUM7_ISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void CHRUM7_ISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)CHRUM7_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_GetVector
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
cyisraddress CHRUM7_ISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)CHRUM7_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling CHRUM7_ISR_Start
*   or CHRUM7_ISR_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   CHRUM7_ISR_Start or CHRUM7_ISR_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void CHRUM7_ISR_SetPriority(uint8 priority)
{
    *CHRUM7_ISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_GetPriority
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
uint8 CHRUM7_ISR_GetPriority(void)
{
    uint8 priority;


    priority = *CHRUM7_ISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_Enable
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
void CHRUM7_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *CHRUM7_ISR_INTC_SET_EN = CHRUM7_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_GetState
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
uint8 CHRUM7_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*CHRUM7_ISR_INTC_SET_EN & (uint32)CHRUM7_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_Disable
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
void CHRUM7_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *CHRUM7_ISR_INTC_CLR_EN = CHRUM7_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_SetPending
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
void CHRUM7_ISR_SetPending(void)
{
    *CHRUM7_ISR_INTC_SET_PD = CHRUM7_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: CHRUM7_ISR_ClearPending
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
void CHRUM7_ISR_ClearPending(void)
{
    *CHRUM7_ISR_INTC_CLR_PD = CHRUM7_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
