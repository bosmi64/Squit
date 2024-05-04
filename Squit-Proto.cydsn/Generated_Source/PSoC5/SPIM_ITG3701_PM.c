/*******************************************************************************
* File Name: SPIM_ITG3701_PM.c
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

#include "SPIM_ITG3701_PVT.h"

static SPIM_ITG3701_BACKUP_STRUCT SPIM_ITG3701_backup =
{
    SPIM_ITG3701_DISABLED,
    SPIM_ITG3701_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPIM_ITG3701_TX_INIT_INTERRUPTS_MASK,
        SPIM_ITG3701_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: SPIM_ITG3701_SaveConfig
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
*  SPIM_ITG3701_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       SPIM_ITG3701_backup.cntrPeriod      = SPIM_ITG3701_COUNTER_PERIOD_REG;
       SPIM_ITG3701_backup.saveSrTxIntMask = SPIM_ITG3701_TX_STATUS_MASK_REG;
       SPIM_ITG3701_backup.saveSrRxIntMask = SPIM_ITG3701_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_RestoreConfig
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
*  SPIM_ITG3701_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIM_ITG3701_STATUS_MASK_REG and SPIM_ITG3701_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_ITG3701_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        SPIM_ITG3701_COUNTER_PERIOD_REG = SPIM_ITG3701_backup.cntrPeriod;
        SPIM_ITG3701_TX_STATUS_MASK_REG = ((uint8) SPIM_ITG3701_backup.saveSrTxIntMask);
        SPIM_ITG3701_RX_STATUS_MASK_REG = ((uint8) SPIM_ITG3701_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_Sleep
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
*  SPIM_ITG3701_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_Sleep(void) 
{
    /* Save components enable state */
    SPIM_ITG3701_backup.enableState = ((uint8) SPIM_ITG3701_IS_ENABLED);

    SPIM_ITG3701_Stop();
    SPIM_ITG3701_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_Wakeup
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
*  SPIM_ITG3701_backup - used when non-retention registers are restored.
*  SPIM_ITG3701_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_ITG3701_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_ITG3701_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_ITG3701_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_Wakeup(void) 
{
    SPIM_ITG3701_RestoreConfig();

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
        SPIM_ITG3701_rxBufferFull  = 0u;
        SPIM_ITG3701_rxBufferRead  = 0u;
        SPIM_ITG3701_rxBufferWrite = 0u;
    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        SPIM_ITG3701_txBufferFull  = 0u;
        SPIM_ITG3701_txBufferRead  = 0u;
        SPIM_ITG3701_txBufferWrite = 0u;
    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_ITG3701_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_ITG3701_backup.enableState)
    {
        SPIM_ITG3701_Enable();
    }
}


/* [] END OF FILE */
