/*******************************************************************************
* File Name: QuadDec_PAN_Cnt16_PM.c  
* Version 2.40
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "QuadDec_PAN_Cnt16.h"

static QuadDec_PAN_Cnt16_backupStruct QuadDec_PAN_Cnt16_backup;


/*******************************************************************************
* Function Name: QuadDec_PAN_Cnt16_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDec_PAN_Cnt16_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void QuadDec_PAN_Cnt16_SaveConfig(void) 
{
    #if (!QuadDec_PAN_Cnt16_UsingFixedFunction)

        QuadDec_PAN_Cnt16_backup.CounterUdb = QuadDec_PAN_Cnt16_ReadCounter();

        #if (CY_UDB_V0)
            QuadDec_PAN_Cnt16_backup.CounterPeriod = QuadDec_PAN_Cnt16_ReadPeriod();
            QuadDec_PAN_Cnt16_backup.CompareValue = QuadDec_PAN_Cnt16_ReadCompare();
            QuadDec_PAN_Cnt16_backup.InterruptMaskValue = QuadDec_PAN_Cnt16_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!QuadDec_PAN_Cnt16_ControlRegRemoved)
            QuadDec_PAN_Cnt16_backup.CounterControlRegister = QuadDec_PAN_Cnt16_ReadControlRegister();
        #endif /* (!QuadDec_PAN_Cnt16_ControlRegRemoved) */

    #endif /* (!QuadDec_PAN_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDec_PAN_Cnt16_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDec_PAN_Cnt16_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDec_PAN_Cnt16_RestoreConfig(void) 
{      
    #if (!QuadDec_PAN_Cnt16_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 QuadDec_PAN_Cnt16_interruptState;
        #endif  /* (CY_UDB_V0) */

       QuadDec_PAN_Cnt16_WriteCounter(QuadDec_PAN_Cnt16_backup.CounterUdb);

        #if (CY_UDB_V0)
            QuadDec_PAN_Cnt16_WritePeriod(QuadDec_PAN_Cnt16_backup.CounterPeriod);
            QuadDec_PAN_Cnt16_WriteCompare(QuadDec_PAN_Cnt16_backup.CompareValue);

            QuadDec_PAN_Cnt16_interruptState = CyEnterCriticalSection();
            QuadDec_PAN_Cnt16_STATUS_AUX_CTRL |= QuadDec_PAN_Cnt16_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(QuadDec_PAN_Cnt16_interruptState);

            QuadDec_PAN_Cnt16_STATUS_MASK = QuadDec_PAN_Cnt16_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!QuadDec_PAN_Cnt16_ControlRegRemoved)
            QuadDec_PAN_Cnt16_WriteControlRegister(QuadDec_PAN_Cnt16_backup.CounterControlRegister);
        #endif /* (!QuadDec_PAN_Cnt16_ControlRegRemoved) */

    #endif /* (!QuadDec_PAN_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QuadDec_PAN_Cnt16_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDec_PAN_Cnt16_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void QuadDec_PAN_Cnt16_Sleep(void) 
{
    #if(!QuadDec_PAN_Cnt16_ControlRegRemoved)
        /* Save Counter's enable state */
        if(QuadDec_PAN_Cnt16_CTRL_ENABLE == (QuadDec_PAN_Cnt16_CONTROL & QuadDec_PAN_Cnt16_CTRL_ENABLE))
        {
            /* Counter is enabled */
            QuadDec_PAN_Cnt16_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            QuadDec_PAN_Cnt16_backup.CounterEnableState = 0u;
        }
    #else
        QuadDec_PAN_Cnt16_backup.CounterEnableState = 1u;
        if(QuadDec_PAN_Cnt16_backup.CounterEnableState != 0u)
        {
            QuadDec_PAN_Cnt16_backup.CounterEnableState = 0u;
        }
    #endif /* (!QuadDec_PAN_Cnt16_ControlRegRemoved) */
    
    QuadDec_PAN_Cnt16_Stop();
    QuadDec_PAN_Cnt16_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_PAN_Cnt16_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  QuadDec_PAN_Cnt16_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void QuadDec_PAN_Cnt16_Wakeup(void) 
{
    QuadDec_PAN_Cnt16_RestoreConfig();
    #if(!QuadDec_PAN_Cnt16_ControlRegRemoved)
        if(QuadDec_PAN_Cnt16_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            QuadDec_PAN_Cnt16_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!QuadDec_PAN_Cnt16_ControlRegRemoved) */
    
}


/* [] END OF FILE */
