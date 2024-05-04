/*******************************************************************************
* File Name: ADIS_16210_SPI_PM.c
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

#include "ADIS_16210_SPI_PVT.h"

static ADIS_16210_SPI_BACKUP_STRUCT ADIS_16210_SPI_backup =
{
    ADIS_16210_SPI_DISABLED,
    ADIS_16210_SPI_BITCTR_INIT,
    #if(CY_UDB_V0)
        ADIS_16210_SPI_TX_INIT_INTERRUPTS_MASK,
        ADIS_16210_SPI_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: ADIS_16210_SPI_SaveConfig
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
*  ADIS_16210_SPI_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADIS_16210_SPI_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       ADIS_16210_SPI_backup.cntrPeriod      = ADIS_16210_SPI_COUNTER_PERIOD_REG;
       ADIS_16210_SPI_backup.saveSrTxIntMask = ADIS_16210_SPI_TX_STATUS_MASK_REG;
       ADIS_16210_SPI_backup.saveSrRxIntMask = ADIS_16210_SPI_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_RestoreConfig
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
*  ADIS_16210_SPI_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  ADIS_16210_SPI_STATUS_MASK_REG and ADIS_16210_SPI_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void ADIS_16210_SPI_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        ADIS_16210_SPI_COUNTER_PERIOD_REG = ADIS_16210_SPI_backup.cntrPeriod;
        ADIS_16210_SPI_TX_STATUS_MASK_REG = ((uint8) ADIS_16210_SPI_backup.saveSrTxIntMask);
        ADIS_16210_SPI_RX_STATUS_MASK_REG = ((uint8) ADIS_16210_SPI_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Sleep
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
*  ADIS_16210_SPI_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADIS_16210_SPI_Sleep(void) 
{
    /* Save components enable state */
    ADIS_16210_SPI_backup.enableState = ((uint8) ADIS_16210_SPI_IS_ENABLED);

    ADIS_16210_SPI_Stop();
    ADIS_16210_SPI_SaveConfig();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Wakeup
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
*  ADIS_16210_SPI_backup - used when non-retention registers are restored.
*  ADIS_16210_SPI_txBufferWrite - modified every function call - resets to
*  zero.
*  ADIS_16210_SPI_txBufferRead - modified every function call - resets to
*  zero.
*  ADIS_16210_SPI_rxBufferWrite - modified every function call - resets to
*  zero.
*  ADIS_16210_SPI_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADIS_16210_SPI_Wakeup(void) 
{
    ADIS_16210_SPI_RestoreConfig();

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
        ADIS_16210_SPI_rxBufferFull  = 0u;
        ADIS_16210_SPI_rxBufferRead  = 0u;
        ADIS_16210_SPI_rxBufferWrite = 0u;
    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        ADIS_16210_SPI_txBufferFull  = 0u;
        ADIS_16210_SPI_txBufferRead  = 0u;
        ADIS_16210_SPI_txBufferWrite = 0u;
    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    ADIS_16210_SPI_ClearFIFO();

    /* Restore components block enable state */
    if(0u != ADIS_16210_SPI_backup.enableState)
    {
        ADIS_16210_SPI_Enable();
    }
}


/* [] END OF FILE */
