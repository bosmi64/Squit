/*******************************************************************************
* File Name: PWM_MOTOR_TILT_PM.c
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
#include "PWM_MOTOR_TILT.h"

static PWM_MOTOR_TILT_backupStruct PWM_MOTOR_TILT_backup;


/*******************************************************************************
* Function Name: PWM_MOTOR_TILT_SaveConfig
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
*  PWM_MOTOR_TILT_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_MOTOR_TILT_SaveConfig(void) 
{
    
    #if(!PWM_MOTOR_TILT_UsingFixedFunction)
        #if(!PWM_MOTOR_TILT_PWMModeIsCenterAligned)
            PWM_MOTOR_TILT_backup.PWMPeriod = PWM_MOTOR_TILT_ReadPeriod();
        #endif /* (!PWM_MOTOR_TILT_PWMModeIsCenterAligned) */
        PWM_MOTOR_TILT_backup.PWMUdb = PWM_MOTOR_TILT_ReadCounter();
        #if (PWM_MOTOR_TILT_UseStatus)
            PWM_MOTOR_TILT_backup.InterruptMaskValue = PWM_MOTOR_TILT_STATUS_MASK;
        #endif /* (PWM_MOTOR_TILT_UseStatus) */
        
        #if(PWM_MOTOR_TILT_DeadBandMode == PWM_MOTOR_TILT__B_PWM__DBM_256_CLOCKS || \
            PWM_MOTOR_TILT_DeadBandMode == PWM_MOTOR_TILT__B_PWM__DBM_2_4_CLOCKS)
            PWM_MOTOR_TILT_backup.PWMdeadBandValue = PWM_MOTOR_TILT_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(PWM_MOTOR_TILT_KillModeMinTime)
             PWM_MOTOR_TILT_backup.PWMKillCounterPeriod = PWM_MOTOR_TILT_ReadKillTime();
        #endif /* (PWM_MOTOR_TILT_KillModeMinTime) */
        
        #if(PWM_MOTOR_TILT_UseControl)
            PWM_MOTOR_TILT_backup.PWMControlRegister = PWM_MOTOR_TILT_ReadControlRegister();
        #endif /* (PWM_MOTOR_TILT_UseControl) */
    #endif  /* (!PWM_MOTOR_TILT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_MOTOR_TILT_RestoreConfig
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
*  PWM_MOTOR_TILT_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_TILT_RestoreConfig(void) 
{
        #if(!PWM_MOTOR_TILT_UsingFixedFunction)
            #if(!PWM_MOTOR_TILT_PWMModeIsCenterAligned)
                PWM_MOTOR_TILT_WritePeriod(PWM_MOTOR_TILT_backup.PWMPeriod);
            #endif /* (!PWM_MOTOR_TILT_PWMModeIsCenterAligned) */
            PWM_MOTOR_TILT_WriteCounter(PWM_MOTOR_TILT_backup.PWMUdb);
            #if (PWM_MOTOR_TILT_UseStatus)
                PWM_MOTOR_TILT_STATUS_MASK = PWM_MOTOR_TILT_backup.InterruptMaskValue;
            #endif /* (PWM_MOTOR_TILT_UseStatus) */
            
            #if(PWM_MOTOR_TILT_DeadBandMode == PWM_MOTOR_TILT__B_PWM__DBM_256_CLOCKS || \
                PWM_MOTOR_TILT_DeadBandMode == PWM_MOTOR_TILT__B_PWM__DBM_2_4_CLOCKS)
                PWM_MOTOR_TILT_WriteDeadTime(PWM_MOTOR_TILT_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_MOTOR_TILT_KillModeMinTime)
                PWM_MOTOR_TILT_WriteKillTime(PWM_MOTOR_TILT_backup.PWMKillCounterPeriod);
            #endif /* (PWM_MOTOR_TILT_KillModeMinTime) */
            
            #if(PWM_MOTOR_TILT_UseControl)
                PWM_MOTOR_TILT_WriteControlRegister(PWM_MOTOR_TILT_backup.PWMControlRegister); 
            #endif /* (PWM_MOTOR_TILT_UseControl) */
        #endif  /* (!PWM_MOTOR_TILT_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_MOTOR_TILT_Sleep
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
*  PWM_MOTOR_TILT_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_TILT_Sleep(void) 
{
    #if(PWM_MOTOR_TILT_UseControl)
        if(PWM_MOTOR_TILT_CTRL_ENABLE == (PWM_MOTOR_TILT_CONTROL & PWM_MOTOR_TILT_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_MOTOR_TILT_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_MOTOR_TILT_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_MOTOR_TILT_UseControl) */

    /* Stop component */
    PWM_MOTOR_TILT_Stop();
    
    /* Save registers configuration */
    PWM_MOTOR_TILT_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_MOTOR_TILT_Wakeup
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
*  PWM_MOTOR_TILT_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_MOTOR_TILT_Wakeup(void) 
{
     /* Restore registers values */
    PWM_MOTOR_TILT_RestoreConfig();
    
    if(PWM_MOTOR_TILT_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_MOTOR_TILT_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
