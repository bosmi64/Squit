/*******************************************************************************
* File Name: SPIM_ADXRS_PM.c
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

#include "SPIM_ADXRS.h"

static SPIM_ADXRS_BACKUP_STRUCT SPIM_ADXRS_backup = {
                                        0u,
                                        SPIM_ADXRS_BITCTR_INIT,
                                        #if(SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1)
                                            SPIM_ADXRS_TX_INIT_INTERRUPTS_MASK,
                                            SPIM_ADXRS_RX_INIT_INTERRUPTS_MASK
                                        #endif /* SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1 */
                                        };

#if (SPIM_ADXRS_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_ADXRS_txBufferRead;
    extern volatile uint8 SPIM_ADXRS_txBufferWrite;
    
#endif /* SPIM_ADXRS_TXBUFFERSIZE > 4u */

#if (SPIM_ADXRS_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIM_ADXRS_rxBufferRead;
    extern volatile uint8 SPIM_ADXRS_rxBufferWrite;
    
#endif /* SPIM_ADXRS_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: SPIM_ADXRS_SaveConfig
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
*  SPIM_ADXRS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ADXRS_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if (SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1)     
    
       SPIM_ADXRS_backup.saveSrTxIntMask = SPIM_ADXRS_TX_STATUS_MASK_REG;
       SPIM_ADXRS_backup.saveSrRxIntMask = SPIM_ADXRS_RX_STATUS_MASK_REG;
       SPIM_ADXRS_backup.cntrPeriod = SPIM_ADXRS_COUNTER_PERIOD_REG;
       
    #endif /* (SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_RestoreConfig
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
*  SPIM_ADXRS_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer: 
*  SPIM_ADXRS_STATUS_MASK_REG and SPIM_ADXRS_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_ADXRS_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1)
    
        SPIM_ADXRS_TX_STATUS_MASK_REG = SPIM_ADXRS_backup.saveSrTxIntMask;
        SPIM_ADXRS_RX_STATUS_MASK_REG = SPIM_ADXRS_backup.saveSrRxIntMask;
        SPIM_ADXRS_COUNTER_PERIOD_REG = SPIM_ADXRS_backup.cntrPeriod;
        
    #endif /* (SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_Sleep
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
*  SPIM_ADXRS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ADXRS_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIM_ADXRS_TX_STATUS_ACTL_REG & SPIM_ADXRS_INT_ENABLE) == SPIM_ADXRS_INT_ENABLE)
    {
        SPIM_ADXRS_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIM_ADXRS_backup.enableState = 0u;
    }

    SPIM_ADXRS_Stop();

    SPIM_ADXRS_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_Wakeup
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
*  SPIM_ADXRS_backup - used when non-retention registers are restored.
*  SPIM_ADXRS_txBufferWrite - modified every function call - resets to 
*  zero.
*  SPIM_ADXRS_txBufferRead - modified every function call - resets to 
*  zero.
*  SPIM_ADXRS_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_ADXRS_rxBufferRead - modified every function call - resets to
*  zero. 
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ADXRS_Wakeup(void) 
{        
    SPIM_ADXRS_RestoreConfig();
         
    #if (SPIM_ADXRS_TXBUFFERSIZE > 4u)
    
        SPIM_ADXRS_txBufferRead = 0u;
        SPIM_ADXRS_txBufferWrite = 0u;
        
    #endif /* SPIM_ADXRS_TXBUFFERSIZE > 4u */
    
    #if (SPIM_ADXRS_RXBUFFERSIZE > 4u)    
    
        SPIM_ADXRS_rxBufferRead = 0u;
        SPIM_ADXRS_rxBufferWrite = 0u;
        
    #endif /* SPIM_ADXRS_RXBUFFERSIZE > 4u */ 
    
    SPIM_ADXRS_ClearFIFO();
    
    /* Restore components block enable state */
    if (SPIM_ADXRS_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIM_ADXRS_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
