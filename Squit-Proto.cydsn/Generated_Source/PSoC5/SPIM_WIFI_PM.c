/*******************************************************************************
* File Name: SPIM_WIFI_PM.c
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

#include "SPIM_WIFI_PVT.h"

static SPIM_WIFI_BACKUP_STRUCT SPIM_WIFI_backup =
{
    SPIM_WIFI_DISABLED,
    SPIM_WIFI_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPIM_WIFI_TX_INIT_INTERRUPTS_MASK,
        SPIM_WIFI_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: SPIM_WIFI_SaveConfig
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
*  SPIM_WIFI_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_WIFI_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       SPIM_WIFI_backup.cntrPeriod      = SPIM_WIFI_COUNTER_PERIOD_REG;
       SPIM_WIFI_backup.saveSrTxIntMask = SPIM_WIFI_TX_STATUS_MASK_REG;
       SPIM_WIFI_backup.saveSrRxIntMask = SPIM_WIFI_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_WIFI_RestoreConfig
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
*  SPIM_WIFI_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIM_WIFI_STATUS_MASK_REG and SPIM_WIFI_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_WIFI_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        SPIM_WIFI_COUNTER_PERIOD_REG = SPIM_WIFI_backup.cntrPeriod;
        SPIM_WIFI_TX_STATUS_MASK_REG = ((uint8) SPIM_WIFI_backup.saveSrTxIntMask);
        SPIM_WIFI_RX_STATUS_MASK_REG = ((uint8) SPIM_WIFI_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_WIFI_Sleep
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
*  SPIM_WIFI_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_WIFI_Sleep(void) 
{
    /* Save components enable state */
    SPIM_WIFI_backup.enableState = ((uint8) SPIM_WIFI_IS_ENABLED);

    SPIM_WIFI_Stop();
    SPIM_WIFI_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_WIFI_Wakeup
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
*  SPIM_WIFI_backup - used when non-retention registers are restored.
*  SPIM_WIFI_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_WIFI_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_WIFI_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_WIFI_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_WIFI_Wakeup(void) 
{
    SPIM_WIFI_RestoreConfig();

    #if(SPIM_WIFI_RX_SOFTWARE_BUF_ENABLED)
        SPIM_WIFI_rxBufferFull  = 0u;
        SPIM_WIFI_rxBufferRead  = 0u;
        SPIM_WIFI_rxBufferWrite = 0u;
    #endif /* (SPIM_WIFI_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_WIFI_TX_SOFTWARE_BUF_ENABLED)
        SPIM_WIFI_txBufferFull  = 0u;
        SPIM_WIFI_txBufferRead  = 0u;
        SPIM_WIFI_txBufferWrite = 0u;
    #endif /* (SPIM_WIFI_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_WIFI_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_WIFI_backup.enableState)
    {
        SPIM_WIFI_Enable();
    }
}


/* [] END OF FILE */
