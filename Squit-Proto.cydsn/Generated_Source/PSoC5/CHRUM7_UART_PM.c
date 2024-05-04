/*******************************************************************************
* File Name: CHRUM7_UART_PM.c
* Version 2.30
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CHRUM7_UART.h"


/***************************************
* Local data allocation
***************************************/

static CHRUM7_UART_BACKUP_STRUCT  CHRUM7_UART_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: CHRUM7_UART_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  CHRUM7_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CHRUM7_UART_SaveConfig(void)
{
    #if (CY_UDB_V0)

        #if(CHRUM7_UART_CONTROL_REG_REMOVED == 0u)
            CHRUM7_UART_backup.cr = CHRUM7_UART_CONTROL_REG;
        #endif /* End CHRUM7_UART_CONTROL_REG_REMOVED */

        #if( (CHRUM7_UART_RX_ENABLED) || (CHRUM7_UART_HD_ENABLED) )
            CHRUM7_UART_backup.rx_period = CHRUM7_UART_RXBITCTR_PERIOD_REG;
            CHRUM7_UART_backup.rx_mask = CHRUM7_UART_RXSTATUS_MASK_REG;
            #if (CHRUM7_UART_RXHW_ADDRESS_ENABLED)
                CHRUM7_UART_backup.rx_addr1 = CHRUM7_UART_RXADDRESS1_REG;
                CHRUM7_UART_backup.rx_addr2 = CHRUM7_UART_RXADDRESS2_REG;
            #endif /* End CHRUM7_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End CHRUM7_UART_RX_ENABLED | CHRUM7_UART_HD_ENABLED*/

        #if(CHRUM7_UART_TX_ENABLED)
            #if(CHRUM7_UART_TXCLKGEN_DP)
                CHRUM7_UART_backup.tx_clk_ctr = CHRUM7_UART_TXBITCLKGEN_CTR_REG;
                CHRUM7_UART_backup.tx_clk_compl = CHRUM7_UART_TXBITCLKTX_COMPLETE_REG;
            #else
                CHRUM7_UART_backup.tx_period = CHRUM7_UART_TXBITCTR_PERIOD_REG;
            #endif /*End CHRUM7_UART_TXCLKGEN_DP */
            CHRUM7_UART_backup.tx_mask = CHRUM7_UART_TXSTATUS_MASK_REG;
        #endif /*End CHRUM7_UART_TX_ENABLED */


    #else /* CY_UDB_V1 */

        #if(CHRUM7_UART_CONTROL_REG_REMOVED == 0u)
            CHRUM7_UART_backup.cr = CHRUM7_UART_CONTROL_REG;
        #endif /* End CHRUM7_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: CHRUM7_UART_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  CHRUM7_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CHRUM7_UART_RestoreConfig(void)
{

    #if (CY_UDB_V0)

        #if(CHRUM7_UART_CONTROL_REG_REMOVED == 0u)
            CHRUM7_UART_CONTROL_REG = CHRUM7_UART_backup.cr;
        #endif /* End CHRUM7_UART_CONTROL_REG_REMOVED */

        #if( (CHRUM7_UART_RX_ENABLED) || (CHRUM7_UART_HD_ENABLED) )
            CHRUM7_UART_RXBITCTR_PERIOD_REG = CHRUM7_UART_backup.rx_period;
            CHRUM7_UART_RXSTATUS_MASK_REG = CHRUM7_UART_backup.rx_mask;
            #if (CHRUM7_UART_RXHW_ADDRESS_ENABLED)
                CHRUM7_UART_RXADDRESS1_REG = CHRUM7_UART_backup.rx_addr1;
                CHRUM7_UART_RXADDRESS2_REG = CHRUM7_UART_backup.rx_addr2;
            #endif /* End CHRUM7_UART_RXHW_ADDRESS_ENABLED */
        #endif  /* End (CHRUM7_UART_RX_ENABLED) || (CHRUM7_UART_HD_ENABLED) */

        #if(CHRUM7_UART_TX_ENABLED)
            #if(CHRUM7_UART_TXCLKGEN_DP)
                CHRUM7_UART_TXBITCLKGEN_CTR_REG = CHRUM7_UART_backup.tx_clk_ctr;
                CHRUM7_UART_TXBITCLKTX_COMPLETE_REG = CHRUM7_UART_backup.tx_clk_compl;
            #else
                CHRUM7_UART_TXBITCTR_PERIOD_REG = CHRUM7_UART_backup.tx_period;
            #endif /*End CHRUM7_UART_TXCLKGEN_DP */
            CHRUM7_UART_TXSTATUS_MASK_REG = CHRUM7_UART_backup.tx_mask;
        #endif /*End CHRUM7_UART_TX_ENABLED */

    #else /* CY_UDB_V1 */

        #if(CHRUM7_UART_CONTROL_REG_REMOVED == 0u)
            CHRUM7_UART_CONTROL_REG = CHRUM7_UART_backup.cr;
        #endif /* End CHRUM7_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: CHRUM7_UART_Sleep
********************************************************************************
*
* Summary:
*  Stops and saves the user configuration. Should be called
*  just prior to entering sleep.
*
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  CHRUM7_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CHRUM7_UART_Sleep(void)
{

    #if(CHRUM7_UART_RX_ENABLED || CHRUM7_UART_HD_ENABLED)
        if((CHRUM7_UART_RXSTATUS_ACTL_REG  & CHRUM7_UART_INT_ENABLE) != 0u)
        {
            CHRUM7_UART_backup.enableState = 1u;
        }
        else
        {
            CHRUM7_UART_backup.enableState = 0u;
        }
    #else
        if((CHRUM7_UART_TXSTATUS_ACTL_REG  & CHRUM7_UART_INT_ENABLE) !=0u)
        {
            CHRUM7_UART_backup.enableState = 1u;
        }
        else
        {
            CHRUM7_UART_backup.enableState = 0u;
        }
    #endif /* End CHRUM7_UART_RX_ENABLED || CHRUM7_UART_HD_ENABLED*/

    CHRUM7_UART_Stop();
    CHRUM7_UART_SaveConfig();
}


/*******************************************************************************
* Function Name: CHRUM7_UART_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  CHRUM7_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void CHRUM7_UART_Wakeup(void)
{
    CHRUM7_UART_RestoreConfig();
    #if( (CHRUM7_UART_RX_ENABLED) || (CHRUM7_UART_HD_ENABLED) )
        CHRUM7_UART_ClearRxBuffer();
    #endif /* End (CHRUM7_UART_RX_ENABLED) || (CHRUM7_UART_HD_ENABLED) */
    #if(CHRUM7_UART_TX_ENABLED || CHRUM7_UART_HD_ENABLED)
        CHRUM7_UART_ClearTxBuffer();
    #endif /* End CHRUM7_UART_TX_ENABLED || CHRUM7_UART_HD_ENABLED */

    if(CHRUM7_UART_backup.enableState != 0u)
    {
        CHRUM7_UART_Enable();
    }
}


/* [] END OF FILE */
