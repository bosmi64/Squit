/*******************************************************************************
* File Name: Counter_LED_PM.c  
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

#include "Counter_LED.h"

static Counter_LED_backupStruct Counter_LED_backup;


/*******************************************************************************
* Function Name: Counter_LED_SaveConfig
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
*  Counter_LED_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_LED_SaveConfig(void) 
{
    #if (!Counter_LED_UsingFixedFunction)

        Counter_LED_backup.CounterUdb = Counter_LED_ReadCounter();

        #if (CY_UDB_V0)
            Counter_LED_backup.CounterPeriod = Counter_LED_ReadPeriod();
            Counter_LED_backup.CompareValue = Counter_LED_ReadCompare();
            Counter_LED_backup.InterruptMaskValue = Counter_LED_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!Counter_LED_ControlRegRemoved)
            Counter_LED_backup.CounterControlRegister = Counter_LED_ReadControlRegister();
        #endif /* (!Counter_LED_ControlRegRemoved) */

    #endif /* (!Counter_LED_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_LED_RestoreConfig
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
*  Counter_LED_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_LED_RestoreConfig(void) 
{      
    #if (!Counter_LED_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 Counter_LED_interruptState;
        #endif  /* (CY_UDB_V0) */

       Counter_LED_WriteCounter(Counter_LED_backup.CounterUdb);

        #if (CY_UDB_V0)
            Counter_LED_WritePeriod(Counter_LED_backup.CounterPeriod);
            Counter_LED_WriteCompare(Counter_LED_backup.CompareValue);

            Counter_LED_interruptState = CyEnterCriticalSection();
            Counter_LED_STATUS_AUX_CTRL |= Counter_LED_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(Counter_LED_interruptState);

            Counter_LED_STATUS_MASK = Counter_LED_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!Counter_LED_ControlRegRemoved)
            Counter_LED_WriteControlRegister(Counter_LED_backup.CounterControlRegister);
        #endif /* (!Counter_LED_ControlRegRemoved) */

    #endif /* (!Counter_LED_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_LED_Sleep
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
*  Counter_LED_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_LED_Sleep(void) 
{
    #if(!Counter_LED_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_LED_CTRL_ENABLE == (Counter_LED_CONTROL & Counter_LED_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_LED_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_LED_backup.CounterEnableState = 0u;
        }
    #else
        Counter_LED_backup.CounterEnableState = 1u;
        if(Counter_LED_backup.CounterEnableState != 0u)
        {
            Counter_LED_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_LED_ControlRegRemoved) */
    
    Counter_LED_Stop();
    Counter_LED_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_LED_Wakeup
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
*  Counter_LED_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_LED_Wakeup(void) 
{
    Counter_LED_RestoreConfig();
    #if(!Counter_LED_ControlRegRemoved)
        if(Counter_LED_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_LED_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_LED_ControlRegRemoved) */
    
}


/* [] END OF FILE */
