/*******************************************************************************
* File Name: SPIM_ADXRS_PM.c
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

#include "SPIM_ADXRS_PVT.h"

static SPIM_ADXRS_BACKUP_STRUCT SPIM_ADXRS_backup =
{
    SPIM_ADXRS_DISABLED,
    SPIM_ADXRS_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPIM_ADXRS_TX_INIT_INTERRUPTS_MASK,
        SPIM_ADXRS_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


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
    #if(CY_UDB_V0)
       SPIM_ADXRS_backup.cntrPeriod      = SPIM_ADXRS_COUNTER_PERIOD_REG;
       SPIM_ADXRS_backup.saveSrTxIntMask = SPIM_ADXRS_TX_STATUS_MASK_REG;
       SPIM_ADXRS_backup.saveSrRxIntMask = SPIM_ADXRS_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
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
    #if(CY_UDB_V0)
        SPIM_ADXRS_COUNTER_PERIOD_REG = SPIM_ADXRS_backup.cntrPeriod;
        SPIM_ADXRS_TX_STATUS_MASK_REG = ((uint8) SPIM_ADXRS_backup.saveSrTxIntMask);
        SPIM_ADXRS_RX_STATUS_MASK_REG = ((uint8) SPIM_ADXRS_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
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
    SPIM_ADXRS_backup.enableState = ((uint8) SPIM_ADXRS_IS_ENABLED);

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

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
        SPIM_ADXRS_rxBufferFull  = 0u;
        SPIM_ADXRS_rxBufferRead  = 0u;
        SPIM_ADXRS_rxBufferWrite = 0u;
    #endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
        SPIM_ADXRS_txBufferFull  = 0u;
        SPIM_ADXRS_txBufferRead  = 0u;
        SPIM_ADXRS_txBufferWrite = 0u;
    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_ADXRS_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_ADXRS_backup.enableState)
    {
        SPIM_ADXRS_Enable();
    }
}


/* [] END OF FILE */
