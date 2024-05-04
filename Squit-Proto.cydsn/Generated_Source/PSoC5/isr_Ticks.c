/*******************************************************************************
* File Name: isr_Ticks.c  
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
#include <isr_Ticks.h>

#if !defined(isr_Ticks__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START isr_Ticks_intc` */

#include <device.h>
#include <stdio.h>
#include <gobee.h>
#include <gobeelib.h>

extern uint8 machine_state;			/* Global Machine State */

extern uint16 GyroNullPauseTicks;	/* centiseconds ticks counter for Gyroscope Autonull Procedure Delay	*/

extern struct GOBEE_PARAMS gobee_param;

extern uint8 agyro_messg;				/* analog gyro message passing console --> isr_ctrl					*/

/* extern Analog External ADXRS646 gyroscope vars) */
extern struct ANALOG_GYRO agyro;
	
/* local wars */
uint8 local_dummy=0;
	
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
* Function Name: isr_Ticks_Start
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
void isr_Ticks_Start(void)
{
    /* For all we know the interrupt is active. */
    isr_Ticks_Disable();

    /* Set the ISR to point to the isr_Ticks Interrupt. */
    isr_Ticks_SetVector(&isr_Ticks_Interrupt);

    /* Set the priority. */
    isr_Ticks_SetPriority((uint8)isr_Ticks_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_Ticks_Enable();
}


/*******************************************************************************
* Function Name: isr_Ticks_StartEx
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
void isr_Ticks_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    isr_Ticks_Disable();

    /* Set the ISR to point to the isr_Ticks Interrupt. */
    isr_Ticks_SetVector(address);

    /* Set the priority. */
    isr_Ticks_SetPriority((uint8)isr_Ticks_INTC_PRIOR_NUMBER);

    /* Enable it. */
    isr_Ticks_Enable();
}


/*******************************************************************************
* Function Name: isr_Ticks_Stop
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
void isr_Ticks_Stop(void)
{
    /* Disable this interrupt. */
    isr_Ticks_Disable();

    /* Set the ISR to point to the passive one. */
    isr_Ticks_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: isr_Ticks_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for isr_Ticks.
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
CY_ISR(isr_Ticks_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START isr_Ticks_Interrupt` */
	//=======================================================//
	//=== Auto Null Gyro Procedure Pause Ticks	[msec]    ===//
	//=======================================================//
	GyroNullPauseTicks++;


//	//=============================================================================//
//	//=== Auto Null Gyro Procedure Stop Condition							    ===//
//	//=============================================================================//	
//	if (machine_state == GOBEE_AUTOCALIBRATING) 
//	{
//		if (GyroNullPauseTicks >= 1000)	/* 10 sec @ 100Hz */
//		{
//			isr_Ticks_Stop();				// Stop (me!!!) Wait Ticks  isr (100Hz)
//
//			//ANULL: 5 Stop Mean Calculus
//			agyro_messg = AGYRO_MEAN_STOP;
//			CyDelayUs(100);				/* 100usec delay */
//			
//			//ANULL: 6 SET AGFINE Ccmmand
//			gobee_param.gyro_offset_fine.fnum = -agyro.mean_rate;
//			
//			/* Writes AGFINE on EEPROM */
//			local_dummy = WriteAllEEparams();			
//
//			//ANULL: 7 Zero Gyro Command
//			agyro.angle = 0;
//			
//			printf("\r\n[OK]\r\n");
//			
//			/* blink LED_OK green led with OPERATIVE (SLOW) repetition rate */
//			Counter_LED_WritePeriod(LED_OK_OPERATIVE);		
//			
//			/************************************/
//			/*** WARNING MACHINE STATE CHANGE ***/
//			/************************************/
//			machine_state = GOBEE_OPERATIVE;
//		}
//	}
    /* `#END` */
}


/*******************************************************************************
* Function Name: isr_Ticks_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling isr_Ticks_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use isr_Ticks_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void isr_Ticks_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_Ticks__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: isr_Ticks_GetVector
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
cyisraddress isr_Ticks_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)isr_Ticks__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: isr_Ticks_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling isr_Ticks_Start
*   or isr_Ticks_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   isr_Ticks_Start or isr_Ticks_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void isr_Ticks_SetPriority(uint8 priority)
{
    *isr_Ticks_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: isr_Ticks_GetPriority
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
uint8 isr_Ticks_GetPriority(void)
{
    uint8 priority;


    priority = *isr_Ticks_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: isr_Ticks_Enable
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
void isr_Ticks_Enable(void)
{
    /* Enable the general interrupt. */
    *isr_Ticks_INTC_SET_EN = isr_Ticks__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Ticks_GetState
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
uint8 isr_Ticks_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*isr_Ticks_INTC_SET_EN & (uint32)isr_Ticks__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: isr_Ticks_Disable
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
void isr_Ticks_Disable(void)
{
    /* Disable the general interrupt. */
    *isr_Ticks_INTC_CLR_EN = isr_Ticks__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Ticks_SetPending
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
void isr_Ticks_SetPending(void)
{
    *isr_Ticks_INTC_SET_PD = isr_Ticks__INTC_MASK;
}


/*******************************************************************************
* Function Name: isr_Ticks_ClearPending
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
void isr_Ticks_ClearPending(void)
{
    *isr_Ticks_INTC_CLR_PD = isr_Ticks__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
