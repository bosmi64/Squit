/*******************************************************************************
* File Name: QuadDec_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
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

#include "QuadDec.h"

static QuadDec_BACKUP_STRUCT QuadDec_backup = {0u};


/*******************************************************************************
* Function Name: QuadDec_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_SaveConfig(void) 
{
    #if (QuadDec_COUNTER_SIZE == 8u)
        QuadDec_Cnt8_SaveConfig();
    #else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
        QuadDec_Cnt16_SaveConfig();                                          
    #endif /* (QuadDec_COUNTER_SIZE == 8u) */
}


/*******************************************************************************
* Function Name: QuadDec_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_RestoreConfig(void) 
{
    #if (QuadDec_COUNTER_SIZE == 8u)
        QuadDec_Cnt8_RestoreConfig();
    #else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
        QuadDec_Cnt16_RestoreConfig();                                          
    #endif /* (QuadDec_COUNTER_SIZE == 8u) */
}


/*******************************************************************************
* Function Name: QuadDec_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:  
*  None.  
*
* Return: 
*  None.
*
* Global Variables:
*  QuadDec_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_Sleep(void)
{   
    if((QuadDec_SR_AUX_CONTROL & QuadDec_INTERRUPTS_ENABLE) == QuadDec_INTERRUPTS_ENABLE)
    {
        QuadDec_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QuadDec_backup.enableState = 0u;
    }
    
    QuadDec_Stop();
    
    QuadDec_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_Wakeup
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global Variables:
*  QuadDec_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QuadDec_Wakeup(void) 
{             
    QuadDec_RestoreConfig();
    
    if(QuadDec_backup.enableState != 0u)
    {       
        #if (QuadDec_COUNTER_SIZE == 8u)
            QuadDec_Cnt8_Enable();
        #else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
            QuadDec_Cnt16_Enable();                                          
        #endif /* (QuadDec_COUNTER_SIZE == 8u) */
        
        /* Enable component's operation */
        QuadDec_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

