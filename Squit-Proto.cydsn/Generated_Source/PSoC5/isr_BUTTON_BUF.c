/*******************************************************************************
* File Name: isr_BUTTON_BUF.c  
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
#include <isr_BUTTON_BUF.h>

#if !defined(isr_BUTTON_BUF__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_BUTTON_BUF_intc` */
	
	#include <device.h>
	#include <gobee.h>
	#include <gobeelib.h>
	#include <das.h>
	#include <stdio.h>
	
	/* external global wars */
	extern struct DAS_VALUES das;				/* DAS- Digital Acquisition System struct 	 */	
	
	uint8 idxxx=0;

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
* Function Name: isr_BUTTON_BUF_Start
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
void isr_BUTTON_BUF_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_BUTTON_BUF_Disable();

    /* Set the ISR to point to the isr_BUTTON_BUF Interrupt. */
    isr_BUTTON_BUF_SetVector(&isr_BUTTON_BUF_Interrupt);

    /* Set the priority. */
    isr_BUTTON_BUF_SetPriority((uint8)isr_BUTTON_BUF_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_BUTTON_BUF_Enable();
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_StartEx
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
void isr_BUTTON_BUF_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_BUTTON_BUF_Disable();

    /* Set the ISR to point to the isr_BUTTON_BUF Interrupt. */
    isr_BUTTON_BUF_SetVector(address);

    /* Set the priority. */
    isr_BUTTON_BUF_SetPriority((uint8)isr_BUTTON_BUF_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_BUTTON_BUF_Enable();
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_Stop
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
void isr_BUTTON_BUF_Stop(void)
{
    /* Disable this interrupt. */
    isr_BUTTON_BUF_Disable();

    /* Set the ISR to point to the passive one. */
    isr_BUTTON_BUF_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_BUTTON_BUF.
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
CY_ISR(isr_BUTTON_BUF_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_BUTTON_BUF_Interrupt` */
	printf("*BUT --> Inertial Vars Buffering!\r\n");
	
	for (idxxx = 0; idxxx < 8; idxxx++)
	{			
		Control_Reg_BUZ_Write(BUZZER_ON);	/* buzzer on			*/
		CyDelay(25);						/* 40msec sec delay	*/
		Control_Reg_BUZ_Write(BUZZER_OFF);	/* buzzer off			*/
		CyDelay(25);						/* 40msec sec delay	*/			
	}	
	
	DASbufferingInit();			/* DAS Buffering Init  */
	DASbufferingStart();		/* DAS Buffering Start */
			
	das.control = DAS_BUFFERING_GOBEE_IVs_ENABLED;	
	
	isr_DAS_Start();				/* Start DAS ISR	*/
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_BUTTON_BUF_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_BUTTON_BUF_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_BUTTON_BUF_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_BUTTON_BUF__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_GetVector
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
cyisraddress isr_BUTTON_BUF_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_BUTTON_BUF__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_BUTTON_BUF_Start
*   or isr_BUTTON_BUF_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_BUTTON_BUF_Start or isr_BUTTON_BUF_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_BUTTON_BUF_SetPriority(uint8 priority)
{
    *isr_BUTTON_BUF_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_GetPriority
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
uint8 isr_BUTTON_BUF_GetPriority(void)
{
    uint8 priority;


    priority = *isr_BUTTON_BUF_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_Enable
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
void isr_BUTTON_BUF_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_BUTTON_BUF_INTC_SET_EN = isr_BUTTON_BUF__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_GetState
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
uint8 isr_BUTTON_BUF_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_BUTTON_BUF_INTC_SET_EN & (uint32)isr_BUTTON_BUF__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_Disable
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
void isr_BUTTON_BUF_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_BUTTON_BUF_INTC_CLR_EN = isr_BUTTON_BUF__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_SetPending
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
void isr_BUTTON_BUF_SetPending(void)
{
    *isr_BUTTON_BUF_INTC_SET_PD = isr_BUTTON_BUF__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_BUTTON_BUF_ClearPending
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
void isr_BUTTON_BUF_ClearPending(void)
{
    *isr_BUTTON_BUF_INTC_CLR_PD = isr_BUTTON_BUF__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
