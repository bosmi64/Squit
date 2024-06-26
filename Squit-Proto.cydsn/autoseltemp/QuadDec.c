/*******************************************************************************
* File Name: QuadDec.c  
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the Quadrature Decoder
*  component.
*
* Note:
*  None.
*   
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "QuadDec.h"

#if(QuadDec_COUNTER_SIZE == 32u)
    extern volatile int32 QuadDec_count32SoftPart;    
#endif /*QuadDec_COUNTER_SIZE == 32u*/

uint8 QuadDec_initVar = 0u;


/*******************************************************************************
* Function Name: QuadDec_Init
********************************************************************************
*
* Summary:   
*  Inits/Restores default QuadDec configuration provided with customizer.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
*******************************************************************************/
void QuadDec_Init(void) 
{      
    #if (QuadDec_COUNTER_SIZE == 32u)
      
        /* Disable Interrupt. */
        CyIntDisable(QuadDec_ISR_NUMBER);
        
        /* Set the ISR to point to the QuadDec_isr Interrupt. */
        CyIntSetVector(QuadDec_ISR_NUMBER, QuadDec_ISR);
        
        /* Set the priority. */
        CyIntSetPriority(QuadDec_ISR_NUMBER, QuadDec_ISR_PRIORITY);       
        
    #endif /* QuadDec_COUNTER_SIZE == 32u */    
}


/*******************************************************************************
* Function Name: QuadDec_Enable
********************************************************************************
*
* Summary:   
*  This function enable interrupts from Component and also enable Component's 
*  isr for 32-bit counter.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
*******************************************************************************/
void QuadDec_Enable(void) 
{
    uint8 enableInterrupts = 0u;
    
    QuadDec_SetInterruptMask(QuadDec_INIT_INT_MASK);
    
    enableInterrupts = CyEnterCriticalSection();
    
    /* Enable interrupts from Statusi register */
    QuadDec_SR_AUX_CONTROL |= QuadDec_INTERRUPTS_ENABLE;
    
    CyExitCriticalSection(enableInterrupts);
    
    #if (QuadDec_COUNTER_SIZE == 32u)
        /* Enable Component interrupts */
        CyIntEnable(QuadDec_ISR_NUMBER);
    #endif /* QuadDec_COUNTER_SIZE == 32u */
}


/*******************************************************************************
* Function Name: QuadDec_Start
********************************************************************************
*
* Summary:
*  Initializes UDBs and other relevant hardware. 
*  Resets counter to 0, enables or disables all relevant interrupts.
*  Starts monitoring the inputs and counting.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global variables:
*  QuadDec_initVar - used to check initial configuration, modified on 
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_Start(void)
{  
    #if (QuadDec_COUNTER_SIZE == 8u)
    
        QuadDec_Cnt8_Start();
        QuadDec_Cnt8_WriteCounter(QuadDec_COUNTER_INIT_VALUE);
        
    #else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
    
        QuadDec_Cnt16_Start();
        QuadDec_Cnt16_WriteCounter(QuadDec_COUNTER_INIT_VALUE);
        
    #endif /* QuadDec_COUNTER_SIZE == 8u */        
    
    if(QuadDec_initVar == 0u)
    {
        QuadDec_Init();
        QuadDec_initVar = 1u;
    }        

    QuadDec_Enable();
}


/*******************************************************************************
* Function Name: QuadDec_Stop
********************************************************************************
*
* Summary:
*  Turns off UDBs and other relevant hardware.
*
* Parameters:  
*  None.  
*
* Return: 
*  None.
*
*******************************************************************************/
void QuadDec_Stop(void) 
{                        
    uint8 enableInterrupts = 0u;
    
    #if (QuadDec_COUNTER_SIZE == 8u)
        QuadDec_Cnt8_Stop();
    #else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
        QuadDec_Cnt16_Stop();                                          /* counter disable */
    #endif /* (QuadDec_COUNTER_SIZE == 8u) */
    
    enableInterrupts = CyEnterCriticalSection();
    
    /* Disable interrupts interrupts from Statusi register */
    QuadDec_SR_AUX_CONTROL &= ~QuadDec_INTERRUPTS_ENABLE;
    
    CyExitCriticalSection(enableInterrupts);
    
    #if (QuadDec_COUNTER_SIZE == 32u)
        CyIntDisable(QuadDec_ISR_NUMBER);                              /* interrupt disable */
    #endif /* QuadDec_COUNTER_SIZE == 32u */
}


/*******************************************************************************
* Function Name: QuadDec_GetCounter
********************************************************************************
*
* Summary:
*  Reports the current value of the counter.
*
* Parameters:  
*  None.  
*
* Return: 
*  The counter value. Return type is signed and per 
*  the counter size setting. A positive value indicates 
*  clockwise movement (B before A).
*
* Global variables:
*  QuadDec_count32SoftPart - used to get hi 16 bit for current value 
*  of the 32-bit counter, when Counter size equal 32-bit.
*
*******************************************************************************/
int16 QuadDec_GetCounter(void) 
{
    int16 count;
    uint16 tmpCnt;   
    
    #if (QuadDec_COUNTER_SIZE == 32u)  
    
        int16 hwCount;   
        
    #endif /* QuadDec_COUNTER_SIZE == 32u */
    
    #if (QuadDec_COUNTER_SIZE == 8u)
    
        tmpCnt = QuadDec_Cnt8_ReadCounter();
        count = tmpCnt ^ 0x80u;
        
    #endif /* QuadDec_COUNTER_SIZE == 8u */
    
    #if (QuadDec_COUNTER_SIZE == 16u)
    
        tmpCnt = QuadDec_Cnt16_ReadCounter();
        count = tmpCnt ^ 0x8000u;    
        
    #endif /* QuadDec_COUNTER_SIZE == 16u */ 
    
    #if (QuadDec_COUNTER_SIZE == 32u)
    
        CyIntDisable(QuadDec_ISR_NUMBER);
        
        tmpCnt = QuadDec_Cnt16_ReadCounter();
        hwCount = tmpCnt ^ 0x8000u;
        count = QuadDec_count32SoftPart + hwCount;
        
        CyIntEnable(QuadDec_ISR_NUMBER);
        
    #endif /* QuadDec_COUNTER_SIZE == 32u */
        
    return(count);    
}


/*******************************************************************************
* Function Name: QuadDec_SetCounter
********************************************************************************
*
* Summary:
*  Sets the current value of the counter.
*
* Parameters:  
*  value:  The new value. Parameter type is signed and per the counter size  
*  setting.  
*
* Return: 
*  None.
*
* Global variables:
*  QuadDec_count32SoftPart - modified to set hi 16 bit for current 
*  value of the 32-bit counter, when Counter size equal 32-bit.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_SetCounter(int16 value)
{    
    #if ((QuadDec_COUNTER_SIZE == 8u) || (QuadDec_COUNTER_SIZE == 16u))        
        uint16 count;         
    #endif  /* (QuadDec_COUNTER_SIZE == 8u) || (QuadDec_COUNTER_SIZE == 16u) */   
    
    #if (QuadDec_COUNTER_SIZE == 8u)     
    
        count = (value ^ 0x80u);
        QuadDec_Cnt8_WriteCounter(count);
        
    #endif  /* QuadDec_COUNTER_SIZE == 8u */
    
    #if (QuadDec_COUNTER_SIZE == 16u) 
    
        count = (value ^ 0x8000u);
        QuadDec_Cnt16_WriteCounter(count);
        
    #endif  /* QuadDec_COUNTER_SIZE == 16u */
    
    #if (QuadDec_COUNTER_SIZE == 32u)
    
        CyIntDisable(QuadDec_ISR_NUMBER);
        
        QuadDec_Cnt16_WriteCounter(0x8000u);
        QuadDec_count32SoftPart = value;
        
        CyIntEnable(QuadDec_ISR_NUMBER);
        
    #endif  /* QuadDec_COUNTER_SIZE == 32u */
}


/*******************************************************************************
* Function Name: QuadDec_GetEvents
********************************************************************************
* 
* Summary:
*   Reports the current status of events.
*
* Parameters:  
*  None.  
*
* Return: 
*  The events, as bits in an unsigned 8-bit value:
*        Bit      Description
*
*        0        Counter overflow.
*        1        Counter underflow.
*        2        Counter reset due to index, if index input is used.
*        3        Invalid A, B inputs state transition.
*
*******************************************************************************/
uint8 QuadDec_GetEvents(void) 
{   
    return(QuadDec_STATUS_REG & QuadDec_INIT_INT_MASK);
}


/*******************************************************************************
* Function Name: QuadDec_SetInterruptMask
********************************************************************************
*
* Summary:
*  Enables / disables interrupts due to the events. 
*  For the 32-bit counter, the overflow, underflow and reset interrupts cannot 
*  be disabled, these bits are ignored.
*
* Parameters:  
*  mask:  Enable / disable bits in an 8-bit value,where 1 enables the interrupt. 
*
* Return: 
*  None.
*
*******************************************************************************/
void QuadDec_SetInterruptMask(uint8 mask) 
{
    #if (QuadDec_COUNTER_SIZE == 32u)
    
        /* Underflow, Overflow and Reset interrupts for 32-bit Counter are always enable */
        mask |= (QuadDec_COUNTER_OVERFLOW | QuadDec_COUNTER_UNDERFLOW |
                 QuadDec_COUNTER_RESET);
                 
    #endif /* QuadDec_COUNTER_SIZE == 32u */
    
    QuadDec_STATUS_MASK = mask;
}


/*******************************************************************************
* Function Name: QuadDec_GetInterruptMask
********************************************************************************
* 
* Summary:
*  Reports the current interrupt mask settings.
*
* Parameters:  
*  None.
*
* Return: 
*  Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*  For the 32-bit counter, the overflow, underflow and reset enable bits are 
*  always set.
*
*******************************************************************************/
uint8 QuadDec_GetInterruptMask(void) 
{
    return(QuadDec_STATUS_MASK & QuadDec_INIT_INT_MASK);
}


/* [] END OF FILE */
