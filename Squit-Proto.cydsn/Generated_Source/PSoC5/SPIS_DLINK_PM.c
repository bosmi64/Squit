/*******************************************************************************
* File Name: SPIS_DLINK_PM.c
* Version 2.50
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

#include "SPIS_DLINK.h"

static SPIS_DLINK_BACKUP_STRUCT SPIS_DLINK_backup = {
                                        0u,
                                        SPIS_DLINK_BITCTR_INIT,
                                        #if(CY_UDB_V0)
                                            SPIS_DLINK_TX_INIT_INTERRUPTS_MASK,
                                            SPIS_DLINK_RX_INIT_INTERRUPTS_MASK
                                        #endif /* CY_UDB_V0 */
                                        };

#if (SPIS_DLINK_TXBUFFERSIZE > 4u)

    extern volatile uint8 SPIS_DLINK_txBufferRead;
    extern volatile uint8 SPIS_DLINK_txBufferWrite;

#endif /* SPIS_DLINK_TXBUFFERSIZE > 4u */

#if (SPIS_DLINK_RXBUFFERSIZE > 4u)

    extern volatile uint8 SPIS_DLINK_rxBufferRead;
    extern volatile uint8 SPIS_DLINK_rxBufferWrite;

#endif /* SPIS_DLINK_RXBUFFERSIZE > 4u */


/*******************************************************************************
* Function Name: SPIS_DLINK_SaveConfig
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
*  SPIS_DLINK_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_DLINK_SaveConfig(void) 
{
    /* Store Status Mask registers */
    #if (CY_UDB_V0)

       SPIS_DLINK_backup.saveSrTxIntMask = SPIS_DLINK_TX_STATUS_MASK_REG;
       SPIS_DLINK_backup.saveSrRxIntMask = SPIS_DLINK_RX_STATUS_MASK_REG;
       SPIS_DLINK_backup.cntrPeriod = SPIS_DLINK_COUNTER_PERIOD_REG;

    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: SPIS_DLINK_RestoreConfig
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
*  SPIS_DLINK_backup - used when non-retention registers are restored.
*
* Side Effects:
*  If this API is called without first calling SaveConfig then in the following
*  registers will be default values from Customizer:
*  SPIS_DLINK_STATUS_MASK_REG and SPIS_DLINK_COUNTER_PERIOD_REG.
*
*******************************************************************************/
void SPIS_DLINK_RestoreConfig(void) 
{
    /* Restore the data, saved by SaveConfig() function */
    #if (CY_UDB_V0)

        SPIS_DLINK_TX_STATUS_MASK_REG = SPIS_DLINK_backup.saveSrTxIntMask;
        SPIS_DLINK_RX_STATUS_MASK_REG = SPIS_DLINK_backup.saveSrRxIntMask;
        SPIS_DLINK_COUNTER_PERIOD_REG = SPIS_DLINK_backup.cntrPeriod;

    #endif /* CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: SPIS_DLINK_Sleep
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
*  SPIS_DLINK_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_DLINK_Sleep(void) 
{
    /* Save components enable state */
    if ((SPIS_DLINK_TX_STATUS_ACTL_REG & SPIS_DLINK_INT_ENABLE) == SPIS_DLINK_INT_ENABLE)
    {
        SPIS_DLINK_backup.enableState = 1u;
    }
    else /* Components block is disabled */
    {
        SPIS_DLINK_backup.enableState = 0u;
    }

    SPIS_DLINK_Stop();

    SPIS_DLINK_SaveConfig();
}


/*******************************************************************************
* Function Name: SPIS_DLINK_Wakeup
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
*  SPIS_DLINK_backup - used when non-retention registers are restored.
*  SPIS_DLINK_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_DLINK_txBufferRead - modified every function call - resets to
*  zero.
*  SPIS_DLINK_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIS_DLINK_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIS_DLINK_Wakeup(void) 
{
    SPIS_DLINK_RestoreConfig();

    #if (SPIS_DLINK_TXBUFFERSIZE > 4u)

        SPIS_DLINK_txBufferRead = 0u;
        SPIS_DLINK_txBufferWrite = 0u;

    #endif /* SPIS_DLINK_TXBUFFERSIZE > 4u */

    #if (SPIS_DLINK_RXBUFFERSIZE > 4u)

        SPIS_DLINK_rxBufferRead = 0u;
        SPIS_DLINK_rxBufferWrite = 0u;

    #endif /* SPIS_DLINK_RXBUFFERSIZE > 4u */

    SPIS_DLINK_ClearFIFO();

    /* Restore components block enable state */
    if (SPIS_DLINK_backup.enableState != 0u)
    {
         /* Components block was enabled */
         SPIS_DLINK_Enable();
    } /* Do nothing if components block was disabled */
}


/* [] END OF FILE */
