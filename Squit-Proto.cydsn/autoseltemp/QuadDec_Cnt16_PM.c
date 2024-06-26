/*******************************************************************************
* File Name: QuadDec_Cnt16_PM.c  
* Version 2.0
*
*  Description:
*     This file provides the power management source code to API for the
*     Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "QuadDec_Cnt16.h"

static QuadDec_Cnt16_backupStruct QuadDec_Cnt16_backup;

/*******************************************************************************
* Function Name: QuadDec_Cnt16_SaveConfig
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
*  QuadDec_Cnt16_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
* Reentrant:
*    No
*
*******************************************************************************/
void QuadDec_Cnt16_SaveConfig(void)
{
    #if (!QuadDec_Cnt16_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for PSoC3 ES2 and PSoC5 ES1*/
        #if (QuadDec_Cnt16_PSOC3_ES2 || QuadDec_Cnt16_PSOC5_ES1)
            QuadDec_Cnt16_backup.CounterUdb = QuadDec_Cnt16_ReadCounter();
            QuadDec_Cnt16_backup.CounterPeriod = QuadDec_Cnt16_ReadPeriod();
            QuadDec_Cnt16_backup.CompareValue = QuadDec_Cnt16_ReadCompare();
            QuadDec_Cnt16_backup.InterruptMaskValue = QuadDec_Cnt16_STATUS_MASK;
        #endif
		
		#if (QuadDec_Cnt16_PSOC3_ES3 || QuadDec_Cnt16_PSOC5_ES2)
			QuadDec_Cnt16_backup.CounterUdb = QuadDec_Cnt16_ReadCounter();
			QuadDec_Cnt16_backup.InterruptMaskValue = QuadDec_Cnt16_STATUS_MASK;
		#endif
		
        #if(!QuadDec_Cnt16_ControlRegRemoved)
            QuadDec_Cnt16_backup.CounterControlRegister = QuadDec_Cnt16_ReadControlRegister();
		#endif
    #endif
}

/*******************************************************************************
* Function Name: QuadDec_Cnt16_RestoreConfig
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
*  QuadDec_Cnt16_backup:  Variables of this global structure are used to restore 
*  the values of non retention registers on wakeup from sleep mode.
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void QuadDec_Cnt16_RestoreConfig(void) 
{      
    #if (!QuadDec_Cnt16_UsingFixedFunction)     
        /* Restore the UDB non-rentention registers for PSoC3 ES2 and PSoC5 ES1*/
        #if (QuadDec_Cnt16_PSOC3_ES2 || QuadDec_Cnt16_PSOC5_ES1)
            QuadDec_Cnt16_WriteCounter(QuadDec_Cnt16_backup.CounterUdb);
            QuadDec_Cnt16_WritePeriod(QuadDec_Cnt16_backup.CounterPeriod);
            QuadDec_Cnt16_WriteCompare(QuadDec_Cnt16_backup.CompareValue);
            QuadDec_Cnt16_STATUS_MASK = QuadDec_Cnt16_backup.InterruptMaskValue;
        #endif
		
		#if (QuadDec_Cnt16_PSOC3_ES3 || QuadDec_Cnt16_PSOC5_ES2)
			QuadDec_Cnt16_WriteCounter(QuadDec_Cnt16_backup.CounterUdb);
			QuadDec_Cnt16_STATUS_MASK = QuadDec_Cnt16_backup.InterruptMaskValue;
		#endif
		
		
        #if(!QuadDec_Cnt16_ControlRegRemoved)
            QuadDec_Cnt16_WriteControlRegister(QuadDec_Cnt16_backup.CounterControlRegister);
        #endif
    #endif
}


/*******************************************************************************
* Function Name: QuadDec_Cnt16_Sleep
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
*  QuadDec_Cnt16_backup.enableState:  Is modified depending on the enable state
*  of the block before entering sleep mode.
*
* Reentrant:
*  No
*
*******************************************************************************/
void QuadDec_Cnt16_Sleep(void)
{
    #if(!QuadDec_Cnt16_ControlRegRemoved)
        /* Save Counter's enable state */
        if(QuadDec_Cnt16_CTRL_ENABLE == (QuadDec_Cnt16_CONTROL & QuadDec_Cnt16_CTRL_ENABLE))
        {
            /* Counter is enabled */
            QuadDec_Cnt16_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            QuadDec_Cnt16_backup.CounterEnableState = 0u;
        }
    #endif
    QuadDec_Cnt16_Stop();
    QuadDec_Cnt16_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_Cnt16_Wakeup
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
*  QuadDec_Cnt16_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
* Reentrant:
*  Yes
*
*******************************************************************************/
void QuadDec_Cnt16_Wakeup(void) 
{
    QuadDec_Cnt16_RestoreConfig();
    #if(!QuadDec_Cnt16_ControlRegRemoved)
        if(QuadDec_Cnt16_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            QuadDec_Cnt16_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif
    
}


/* [] END OF FILE */
