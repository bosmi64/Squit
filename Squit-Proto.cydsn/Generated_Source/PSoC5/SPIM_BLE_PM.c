/*******************************************************************************
* File Name: SPIM_BLE_PM.c
* Version 2.40
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_BLE_PVT.h"

static SPIM_BLE_BACKUP_STRUCT SPIM_BLE_backup =
{
    SPIM_BLE_DISABLED,
    SPIM_BLE_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPIM_BLE_TX_INIT_INTERRUPTS_MASK,
        SPIM_BLE_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: SPIM_BLE_SaveConfig
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
*  SPIM_BLE_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_BLE_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       SPIM_BLE_backup.cntrPeriod      = SPIM_BLE_COUNTER_PERIOD_REG;
       SPIM_BLE_backup.saveSrTxIntMask = SPIM_BLE_TX_STATUS_MASK_REG;
       SPIM_BLE_backup.saveSrRxIntMask = SPIM_BLE_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_BLE_RestoreConfig
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
*  SPIM_BLE_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIM_BLE_STATUS_MASK_REG and SPIM_BLE_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_BLE_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        SPIM_BLE_COUNTER_PERIOD_REG = SPIM_BLE_backup.cntrPeriod;
        SPIM_BLE_TX_STATUS_MASK_REG = ((uint8) SPIM_BLE_backup.saveSrTxIntMask);
        SPIM_BLE_RX_STATUS_MASK_REG = ((uint8) SPIM_BLE_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_BLE_Sleep
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
*  SPIM_BLE_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_BLE_Sleep(void) 
{
    /* Save components enable state */
    SPIM_BLE_backup.enableState = ((uint8) SPIM_BLE_IS_ENABLED);

    SPIM_BLE_Stop();
    SPIM_BLE_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_BLE_Wakeup
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
*  SPIM_BLE_backup - used when non-retention registers are restored.
*  SPIM_BLE_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_BLE_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_BLE_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_BLE_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_BLE_Wakeup(void) 
{
    SPIM_BLE_RestoreConfig();

    #if(SPIM_BLE_RX_SOFTWARE_BUF_ENABLED)
        SPIM_BLE_rxBufferFull  = 0u;
        SPIM_BLE_rxBufferRead  = 0u;
        SPIM_BLE_rxBufferWrite = 0u;
    #endif /* (SPIM_BLE_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_BLE_TX_SOFTWARE_BUF_ENABLED)
        SPIM_BLE_txBufferFull  = 0u;
        SPIM_BLE_txBufferRead  = 0u;
        SPIM_BLE_txBufferWrite = 0u;
    #endif /* (SPIM_BLE_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_BLE_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_BLE_backup.enableState)
    {
        SPIM_BLE_Enable();
    }
}


/* [] END OF FILE */
