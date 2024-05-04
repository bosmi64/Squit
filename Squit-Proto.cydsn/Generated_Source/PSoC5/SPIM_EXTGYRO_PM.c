/*******************************************************************************
* File Name: SPIM_EXTGYRO_PM.c
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

#include "SPIM_EXTGYRO_PVT.h"

static SPIM_EXTGYRO_BACKUP_STRUCT SPIM_EXTGYRO_backup =
{
    SPIM_EXTGYRO_DISABLED,
    SPIM_EXTGYRO_BITCTR_INIT,
    #if(CY_UDB_V0)
        SPIM_EXTGYRO_TX_INIT_INTERRUPTS_MASK,
        SPIM_EXTGYRO_RX_INIT_INTERRUPTS_MASK
    #endif /* CY_UDB_V0 */
};


/*******************************************************************************
* Function Name: SPIM_EXTGYRO_SaveConfig
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
*  SPIM_EXTGYRO_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EXTGYRO_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if(CY_UDB_V0)
       SPIM_EXTGYRO_backup.cntrPeriod      = SPIM_EXTGYRO_COUNTER_PERIOD_REG;
       SPIM_EXTGYRO_backup.saveSrTxIntMask = SPIM_EXTGYRO_TX_STATUS_MASK_REG;
       SPIM_EXTGYRO_backup.saveSrRxIntMask = SPIM_EXTGYRO_RX_STATUS_MASK_REG;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_EXTGYRO_RestoreConfig
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
*  SPIM_EXTGYRO_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIM_EXTGYRO_STATUS_MASK_REG and SPIM_EXTGYRO_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIM_EXTGYRO_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if(CY_UDB_V0)
        SPIM_EXTGYRO_COUNTER_PERIOD_REG = SPIM_EXTGYRO_backup.cntrPeriod;
        SPIM_EXTGYRO_TX_STATUS_MASK_REG = ((uint8) SPIM_EXTGYRO_backup.saveSrTxIntMask);
        SPIM_EXTGYRO_RX_STATUS_MASK_REG = ((uint8) SPIM_EXTGYRO_backup.saveSrRxIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SPIM_EXTGYRO_Sleep
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
*  SPIM_EXTGYRO_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EXTGYRO_Sleep(void) 
{
    /* Save components enable state */
    SPIM_EXTGYRO_backup.enableState = ((uint8) SPIM_EXTGYRO_IS_ENABLED);

    SPIM_EXTGYRO_Stop();
    SPIM_EXTGYRO_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIM_EXTGYRO_Wakeup
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
*  SPIM_EXTGYRO_backup - used when non-retention registers are restored.
*  SPIM_EXTGYRO_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EXTGYRO_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_EXTGYRO_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_EXTGYRO_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_EXTGYRO_Wakeup(void) 
{
    SPIM_EXTGYRO_RestoreConfig();

    #if(SPIM_EXTGYRO_RX_SOFTWARE_BUF_ENABLED)
        SPIM_EXTGYRO_rxBufferFull  = 0u;
        SPIM_EXTGYRO_rxBufferRead  = 0u;
        SPIM_EXTGYRO_rxBufferWrite = 0u;
    #endif /* (SPIM_EXTGYRO_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_EXTGYRO_TX_SOFTWARE_BUF_ENABLED)
        SPIM_EXTGYRO_txBufferFull  = 0u;
        SPIM_EXTGYRO_txBufferRead  = 0u;
        SPIM_EXTGYRO_txBufferWrite = 0u;
    #endif /* (SPIM_EXTGYRO_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_EXTGYRO_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_EXTGYRO_backup.enableState)
    {
        SPIM_EXTGYRO_Enable();
    }
}


/* [] END OF FILE */
