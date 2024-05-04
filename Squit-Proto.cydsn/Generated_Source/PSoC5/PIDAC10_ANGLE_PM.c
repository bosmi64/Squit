/*******************************************************************************
* File Name: PIDAC10_ANGLE_PM.c  
* Version 1.2
*
*  Description:
*     This file provides the power management source code to API for the
*     Parallel Current DAC (PIDAC) Component.  
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
#include "PIDAC10_ANGLE.h"

static PIDAC10_ANGLE_backupStruct PIDAC10_ANGLE_backup;


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void PIDAC10_ANGLE_SaveConfig(void)
{
	PIDAC10_ANGLE_backup.MSB_data_value = PIDAC10_ANGLE_MSB_Data;   
	PIDAC10_ANGLE_backup.LSB_data_value = PIDAC10_ANGLE_LSB_Data;  
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_RestoreConfig
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
*******************************************************************************/
void PIDAC10_ANGLE_RestoreConfig(void)
{
    PIDAC10_ANGLE_MSB_Data = PIDAC10_ANGLE_backup.MSB_data_value;   
	PIDAC10_ANGLE_LSB_Data = PIDAC10_ANGLE_backup.LSB_data_value;  
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  PIDAC10_ANGLE_backup.enableState:  Is modified depending on the enable state
*  of the block before entering sleep mode.
*
*******************************************************************************/
void PIDAC10_ANGLE_Sleep(void)
{
    if(PIDAC10_ANGLE_MSB_ACT_PWR_EN == (PIDAC10_ANGLE_MSB_PWRMGR & PIDAC10_ANGLE_MSB_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        PIDAC10_ANGLE_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        PIDAC10_ANGLE_backup.enableState = 0u;
    }
    
    PIDAC10_ANGLE_Stop();
    PIDAC10_ANGLE_SaveConfig();
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Wakeup
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
*  PIDAC10_ANGLE_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PIDAC10_ANGLE_Wakeup(void)
{
    PIDAC10_ANGLE_RestoreConfig();
    
    if(PIDAC10_ANGLE_backup.enableState == 1u)
    {
        /* Enable PIDAC's operation */
        PIDAC10_ANGLE_Enable();
		
		/* Set the data register */
		PIDAC10_ANGLE_RestoreConfig();
    } /* Do nothing if PIDAC was disabled before */  
	
}


/* [] END OF FILE */

