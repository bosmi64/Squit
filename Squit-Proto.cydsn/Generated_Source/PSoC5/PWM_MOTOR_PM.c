/*******************************************************************************
* File Name: PWM_MOTOR_PM.c
* Version 3.0
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "PWM_MOTOR.h"

static PWM_MOTOR_backupStruct PWM_MOTOR_backup;


/*******************************************************************************
* Function Name: PWM_MOTOR_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_MOTOR_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_MOTOR_SaveConfig(void) 
{
    
    #if(!PWM_MOTOR_UsingFixedFunction)
        #if(!PWM_MOTOR_PWMModeIsCenterAligned)
            PWM_MOTOR_backup.PWMPeriod = PWM_MOTOR_ReadPeriod();
        #endif /* (!PWM_MOTOR_PWMModeIsCenterAligned) */
        PWM_MOTOR_backup.PWMUdb = PWM_MOTOR_ReadCounter();
        #if (PWM_MOTOR_UseStatus)
            PWM_MOTOR_backup.InterruptMaskValue = PWM_MOTOR_STATUS_MASK;
        #endif /* (PWM_MOTOR_UseStatus) */
        
        #if(PWM_MOTOR_DeadBandMode == PWM_MOTOR__B_PWM__DBM_256_CLOCKS || \
            PWM_MOTOR_DeadBandMode == PWM_MOTOR__B_PWM__DBM_2_4_CLOCKS)
            PWM_MOTOR_backup.PWMdeadBandValue = PWM_MOTOR_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(PWM_MOTOR_KillModeMinTime)
             PWM_MOTOR_backup.PWMKillCounterPeriod = PWM_MOTOR_ReadKillTime();
        #endif /* (PWM_MOTOR_KillModeMinTime) */
        
        #if(PWM_MOTOR_UseControl)
            PWM_MOTOR_backup.PWMControlRegister = PWM_MOTOR_ReadControlRegister();
        #endif /* (PWM_MOTOR_UseControl) */
    #endif  /* (!PWM_MOTOR_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_MOTOR_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_MOTOR_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_RestoreConfig(void) 
{
        #if(!PWM_MOTOR_UsingFixedFunction)
            #if(!PWM_MOTOR_PWMModeIsCenterAligned)
                PWM_MOTOR_WritePeriod(PWM_MOTOR_backup.PWMPeriod);
            #endif /* (!PWM_MOTOR_PWMModeIsCenterAligned) */
            PWM_MOTOR_WriteCounter(PWM_MOTOR_backup.PWMUdb);
            #if (PWM_MOTOR_UseStatus)
                PWM_MOTOR_STATUS_MASK = PWM_MOTOR_backup.InterruptMaskValue;
            #endif /* (PWM_MOTOR_UseStatus) */
            
            #if(PWM_MOTOR_DeadBandMode == PWM_MOTOR__B_PWM__DBM_256_CLOCKS || \
                PWM_MOTOR_DeadBandMode == PWM_MOTOR__B_PWM__DBM_2_4_CLOCKS)
                PWM_MOTOR_WriteDeadTime(PWM_MOTOR_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_MOTOR_KillModeMinTime)
                PWM_MOTOR_WriteKillTime(PWM_MOTOR_backup.PWMKillCounterPeriod);
            #endif /* (PWM_MOTOR_KillModeMinTime) */
            
            #if(PWM_MOTOR_UseControl)
                PWM_MOTOR_WriteControlRegister(PWM_MOTOR_backup.PWMControlRegister); 
            #endif /* (PWM_MOTOR_UseControl) */
        #endif  /* (!PWM_MOTOR_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_MOTOR_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_MOTOR_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_Sleep(void) 
{
    #if(PWM_MOTOR_UseControl)
        if(PWM_MOTOR_CTRL_ENABLE == (PWM_MOTOR_CONTROL & PWM_MOTOR_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_MOTOR_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_MOTOR_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_MOTOR_UseControl) */

    /* Stop component */
    PWM_MOTOR_Stop();
    
    /* Save registers configuration */
    PWM_MOTOR_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_MOTOR_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_MOTOR_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_Wakeup(void) 
{
     /* Restore registers values */
    PWM_MOTOR_RestoreConfig();
    
    if(PWM_MOTOR_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_MOTOR_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
