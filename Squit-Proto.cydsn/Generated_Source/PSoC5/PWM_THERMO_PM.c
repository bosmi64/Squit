/*******************************************************************************
* File Name: PWM_THERMO_PM.c
* Version 2.40
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
#include "PWM_THERMO.h"

static PWM_THERMO_backupStruct PWM_THERMO_backup;


/*******************************************************************************
* Function Name: PWM_THERMO_SaveConfig
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
*  PWM_THERMO_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_THERMO_SaveConfig(void) 
{
    
    #if(!PWM_THERMO_UsingFixedFunction)
        #if (CY_UDB_V0)
            PWM_THERMO_backup.PWMUdb = PWM_THERMO_ReadCounter();
            PWM_THERMO_backup.PWMPeriod = PWM_THERMO_ReadPeriod();
            #if (PWM_THERMO_UseStatus)
                PWM_THERMO_backup.InterruptMaskValue = PWM_THERMO_STATUS_MASK;
            #endif /* (PWM_THERMO_UseStatus) */
            
            #if(PWM_THERMO_UseOneCompareMode)
                PWM_THERMO_backup.PWMCompareValue = PWM_THERMO_ReadCompare();
            #else
                PWM_THERMO_backup.PWMCompareValue1 = PWM_THERMO_ReadCompare1();
                PWM_THERMO_backup.PWMCompareValue2 = PWM_THERMO_ReadCompare2();
            #endif /* (PWM_THERMO_UseOneCompareMode) */
            
           #if(PWM_THERMO_DeadBandUsed)
                PWM_THERMO_backup.PWMdeadBandValue = PWM_THERMO_ReadDeadTime();
            #endif /* (PWM_THERMO_DeadBandUsed) */
          
            #if ( PWM_THERMO_KillModeMinTime)
                PWM_THERMO_backup.PWMKillCounterPeriod = PWM_THERMO_ReadKillTime();
            #endif /* ( PWM_THERMO_KillModeMinTime) */
        #endif /* (CY_UDB_V0) */
        
        #if (CY_UDB_V1)
            #if(!PWM_THERMO_PWMModeIsCenterAligned)
                PWM_THERMO_backup.PWMPeriod = PWM_THERMO_ReadPeriod();
            #endif /* (!PWM_THERMO_PWMModeIsCenterAligned) */
            PWM_THERMO_backup.PWMUdb = PWM_THERMO_ReadCounter();
            #if (PWM_THERMO_UseStatus)
                PWM_THERMO_backup.InterruptMaskValue = PWM_THERMO_STATUS_MASK;
            #endif /* (PWM_THERMO_UseStatus) */
            
            #if(PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_256_CLOCKS || \
                PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_2_4_CLOCKS)
                PWM_THERMO_backup.PWMdeadBandValue = PWM_THERMO_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_THERMO_KillModeMinTime)
                 PWM_THERMO_backup.PWMKillCounterPeriod = PWM_THERMO_ReadKillTime();
            #endif /* (PWM_THERMO_KillModeMinTime) */
        #endif /* (CY_UDB_V1) */
        
        #if(PWM_THERMO_UseControl)
            PWM_THERMO_backup.PWMControlRegister = PWM_THERMO_ReadControlRegister();
        #endif /* (PWM_THERMO_UseControl) */
    #endif  /* (!PWM_THERMO_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_THERMO_RestoreConfig
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
*  PWM_THERMO_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_THERMO_RestoreConfig(void) 
{
        #if(!PWM_THERMO_UsingFixedFunction)
            #if (CY_UDB_V0)
                /* Interrupt State Backup for Critical Region*/
                uint8 PWM_THERMO_interruptState;
                /* Enter Critical Region*/
                PWM_THERMO_interruptState = CyEnterCriticalSection();
                #if (PWM_THERMO_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    PWM_THERMO_STATUS_AUX_CTRL |= PWM_THERMO_STATUS_ACTL_INT_EN_MASK;
                    
                    PWM_THERMO_STATUS_MASK = PWM_THERMO_backup.InterruptMaskValue;
                #endif /* (PWM_THERMO_UseStatus) */
                
                #if (PWM_THERMO_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    PWM_THERMO_AUX_CONTROLDP0 |= (PWM_THERMO_AUX_CTRL_FIFO0_CLR);
                #else /* (PWM_THERMO_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    PWM_THERMO_AUX_CONTROLDP0 |= (PWM_THERMO_AUX_CTRL_FIFO0_CLR);
                    PWM_THERMO_AUX_CONTROLDP1 |= (PWM_THERMO_AUX_CTRL_FIFO0_CLR);
                #endif /* (PWM_THERMO_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(PWM_THERMO_interruptState);
                
                PWM_THERMO_WriteCounter(PWM_THERMO_backup.PWMUdb);
                PWM_THERMO_WritePeriod(PWM_THERMO_backup.PWMPeriod);
                
                #if(PWM_THERMO_UseOneCompareMode)
                    PWM_THERMO_WriteCompare(PWM_THERMO_backup.PWMCompareValue);
                #else
                    PWM_THERMO_WriteCompare1(PWM_THERMO_backup.PWMCompareValue1);
                    PWM_THERMO_WriteCompare2(PWM_THERMO_backup.PWMCompareValue2);
                #endif /* (PWM_THERMO_UseOneCompareMode) */
                
               #if(PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_256_CLOCKS || \
                   PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_2_4_CLOCKS)
                    PWM_THERMO_WriteDeadTime(PWM_THERMO_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( PWM_THERMO_KillModeMinTime)
                    PWM_THERMO_WriteKillTime(PWM_THERMO_backup.PWMKillCounterPeriod);
                #endif /* ( PWM_THERMO_KillModeMinTime) */
            #endif /* (CY_UDB_V0) */
            
            #if (CY_UDB_V1)
                #if(!PWM_THERMO_PWMModeIsCenterAligned)
                    PWM_THERMO_WritePeriod(PWM_THERMO_backup.PWMPeriod);
                #endif /* (!PWM_THERMO_PWMModeIsCenterAligned) */
                PWM_THERMO_WriteCounter(PWM_THERMO_backup.PWMUdb);
                #if (PWM_THERMO_UseStatus)
                    PWM_THERMO_STATUS_MASK = PWM_THERMO_backup.InterruptMaskValue;
                #endif /* (PWM_THERMO_UseStatus) */
                
                #if(PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_256_CLOCKS || \
                    PWM_THERMO_DeadBandMode == PWM_THERMO__B_PWM__DBM_2_4_CLOCKS)
                    PWM_THERMO_WriteDeadTime(PWM_THERMO_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(PWM_THERMO_KillModeMinTime)
                    PWM_THERMO_WriteKillTime(PWM_THERMO_backup.PWMKillCounterPeriod);
                #endif /* (PWM_THERMO_KillModeMinTime) */
            #endif /* (CY_UDB_V1) */
            
            #if(PWM_THERMO_UseControl)
                PWM_THERMO_WriteControlRegister(PWM_THERMO_backup.PWMControlRegister); 
            #endif /* (PWM_THERMO_UseControl) */
        #endif  /* (!PWM_THERMO_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_THERMO_Sleep
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
*  PWM_THERMO_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_THERMO_Sleep(void) 
{
    #if(PWM_THERMO_UseControl)
        if(PWM_THERMO_CTRL_ENABLE == (PWM_THERMO_CONTROL & PWM_THERMO_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_THERMO_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_THERMO_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_THERMO_UseControl) */

    /* Stop component */
    PWM_THERMO_Stop();
    
    /* Save registers configuration */
    PWM_THERMO_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_THERMO_Wakeup
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
*  PWM_THERMO_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_THERMO_Wakeup(void) 
{
     /* Restore registers values */
    PWM_THERMO_RestoreConfig();
    
    if(PWM_THERMO_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_THERMO_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
