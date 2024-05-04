/*******************************************************************************
* File Name: SPIM_EASYCAMS_PM.c
* Version 2.21
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_EASYCAMS.h"

static SPIM_EASYCAMS_BACKUP_STRUCT SPIM_EASYCAMS_backup = {
                                        0u,
                                        SPIM_EASYCAMS_BITCTR_INIT,
                                        #if(SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1)
                                            SPIM_EASYCAMS_TX_INIT_INTERRUPTS_MASK,
                                            SPIM_EASYCAMS_RX_INIT_INTERRUPTS_MASK
                                        #endif /* SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1 */
                                        };

#if (SPIM_EASYCAMS_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_EASYCAMS_txBufferRead;
    extern volatile uint8 SPIM_EASYCAMS_txBufferWrite;
    
#endif /* SPIM_EASYCAMS_TXBUFFERSIZE > 4u */

#if (SPIM_EASYCAMS_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_EASYCAMS_rxBufferRead;
    extern volatile uint8 SPIM_EASYCAMS_rxBufferWrite;
    
#endif /* SPIM_EASYCAMS_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_SaveConfig
********************************************************************************
*
* Summary:
*  Saves SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
* 
* Global Variables:
*  SPIM_EASYCAMS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EASYCAMS_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if (SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1)     
    
       SPIM_EASYCAMS_backup.saveSrTxIntMask = SPIM_EASYCAMS_TX_STATUS_MASK_REG;
       SPIM_EASYCAMS_backup.saveSrRxIntMask = SPIM_EASYCAMS_RX_STATUS_MASK_REG;
       SPIM_EASYCAMS_backup.cntrPeriod = SPIM_EASYCAMS_COUNTER_PERIOD_REG;
       
    #endif /* (SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores SPIM configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_EASYCAMS_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer: 
*  SPIM_EASYCAMS_STATUS_MASK_REG and SPIM_EASYCAMS_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_EASYCAMS_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1)
    
        SPIM_EASYCAMS_TX_STATUS_MASK_REG = SPIM_EASYCAMS_backup.saveSrTxIntMask;
        SPIM_EASYCAMS_RX_STATUS_MASK_REG = SPIM_EASYCAMS_backup.saveSrRxIntMask;
        SPIM_EASYCAMS_COUNTER_PERIOD_REG = SPIM_EASYCAMS_backup.cntrPeriod;
        
    #endif /* (SPIM_EASYCAMS_PSOC3_ES2 || SPIM_EASYCAMS_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global Variables:
*  SPIM_EASYCAMS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EASYCAMS_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIM_EASYCAMS_TX_STATUS_ACTL_REG & SPIM_EASYCAMS_INT_ENABLE) == SPIM_EASYCAMS_INT_ENABLE)
    {
        SPIM_EASYCAMS_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIM_EASYCAMS_backup.enableState = 0u;
    }

    SPIM_EASYCAMS_Stop();

    SPIM_EASYCAMS_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:  
*  None.
*
* Return: 
*  None.
*
* Global Variables:
*  SPIM_EASYCAMS_backup - used when non-retention registers are restored.
*  SPIM_EASYCAMS_txBufferWrite - modified every function call - resets to 
*  zero.
*  SPIM_EASYCAMS_txBufferRead - modified every function call - resets to 
*  zero.
*  SPIM_EASYCAMS_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EASYCAMS_rxBufferRead - modified every function call - resets to
*  zero. 
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EASYCAMS_Wakeup(void) 
{        
    SPIM_EASYCAMS_RestoreConfig();
         
    #if (SPIM_EASYCAMS_TXBUFFERSIZE > 4u)
    
        SPIM_EASYCAMS_txBufferRead = 0u;
        SPIM_EASYCAMS_txBufferWrite = 0u;
        
    #endif /* SPIM_EASYCAMS_TXBUFFERSIZE > 4u */
    
    #if (SPIM_EASYCAMS_RXBUFFERSIZE > 4u)    
    
        SPIM_EASYCAMS_rxBufferRead = 0u;
        SPIM_EASYCAMS_rxBufferWrite = 0u;
        
    #endif /* SPIM_EASYCAMS_RXBUFFERSIZE > 4u */ 
    
    SPIM_EASYCAMS_ClearFIFO();
    
    /* Restore components block enable state */
    if (SPIM_EASYCAMS_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIM_EASYCAMS_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
