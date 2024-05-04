/*******************************************************************************
* File Name: UART_4D_OLED_PM.c
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

#include "UART_4D_OLED.h"


/***************************************
* Local data allocation
***************************************/

static UART_4D_OLED_BACKUP_STRUCT  UART_4D_OLED_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: UART_4D_OLED_SaveConfig
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
*  UART_4D_OLED_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_4D_OLED_SaveConfig(void)
{
    #if (CY_UDB_V0)

        #if(UART_4D_OLED_CONTROL_REG_REMOVED == 0u)
            UART_4D_OLED_backup.cr = UART_4D_OLED_CONTROL_REG;
        #endif /* End UART_4D_OLED_CONTROL_REG_REMOVED */

        #if( (UART_4D_OLED_RX_ENABLED) || (UART_4D_OLED_HD_ENABLED) )
            UART_4D_OLED_backup.rx_period = UART_4D_OLED_RXBITCTR_PERIOD_REG;
            UART_4D_OLED_backup.rx_mask = UART_4D_OLED_RXSTATUS_MASK_REG;
            #if (UART_4D_OLED_RXHW_ADDRESS_ENABLED)
                UART_4D_OLED_backup.rx_addr1 = UART_4D_OLED_RXADDRESS1_REG;
                UART_4D_OLED_backup.rx_addr2 = UART_4D_OLED_RXADDRESS2_REG;
            #endif /* End UART_4D_OLED_RXHW_ADDRESS_ENABLED */
        #endif /* End UART_4D_OLED_RX_ENABLED | UART_4D_OLED_HD_ENABLED*/

        #if(UART_4D_OLED_TX_ENABLED)
            #if(UART_4D_OLED_TXCLKGEN_DP)
                UART_4D_OLED_backup.tx_clk_ctr = UART_4D_OLED_TXBITCLKGEN_CTR_REG;
                UART_4D_OLED_backup.tx_clk_compl = UART_4D_OLED_TXBITCLKTX_COMPLETE_REG;
            #else
                UART_4D_OLED_backup.tx_period = UART_4D_OLED_TXBITCTR_PERIOD_REG;
            #endif /*End UART_4D_OLED_TXCLKGEN_DP */
            UART_4D_OLED_backup.tx_mask = UART_4D_OLED_TXSTATUS_MASK_REG;
        #endif /*End UART_4D_OLED_TX_ENABLED */


    #else /* CY_UDB_V1 */

        #if(UART_4D_OLED_CONTROL_REG_REMOVED == 0u)
            UART_4D_OLED_backup.cr = UART_4D_OLED_CONTROL_REG;
        #endif /* End UART_4D_OLED_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: UART_4D_OLED_RestoreConfig
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
*  UART_4D_OLED_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_4D_OLED_RestoreConfig(void)
{

    #if (CY_UDB_V0)

        #if(UART_4D_OLED_CONTROL_REG_REMOVED == 0u)
            UART_4D_OLED_CONTROL_REG = UART_4D_OLED_backup.cr;
        #endif /* End UART_4D_OLED_CONTROL_REG_REMOVED */

        #if( (UART_4D_OLED_RX_ENABLED) || (UART_4D_OLED_HD_ENABLED) )
            UART_4D_OLED_RXBITCTR_PERIOD_REG = UART_4D_OLED_backup.rx_period;
            UART_4D_OLED_RXSTATUS_MASK_REG = UART_4D_OLED_backup.rx_mask;
            #if (UART_4D_OLED_RXHW_ADDRESS_ENABLED)
                UART_4D_OLED_RXADDRESS1_REG = UART_4D_OLED_backup.rx_addr1;
                UART_4D_OLED_RXADDRESS2_REG = UART_4D_OLED_backup.rx_addr2;
            #endif /* End UART_4D_OLED_RXHW_ADDRESS_ENABLED */
        #endif  /* End (UART_4D_OLED_RX_ENABLED) || (UART_4D_OLED_HD_ENABLED) */

        #if(UART_4D_OLED_TX_ENABLED)
            #if(UART_4D_OLED_TXCLKGEN_DP)
                UART_4D_OLED_TXBITCLKGEN_CTR_REG = UART_4D_OLED_backup.tx_clk_ctr;
                UART_4D_OLED_TXBITCLKTX_COMPLETE_REG = UART_4D_OLED_backup.tx_clk_compl;
            #else
                UART_4D_OLED_TXBITCTR_PERIOD_REG = UART_4D_OLED_backup.tx_period;
            #endif /*End UART_4D_OLED_TXCLKGEN_DP */
            UART_4D_OLED_TXSTATUS_MASK_REG = UART_4D_OLED_backup.tx_mask;
        #endif /*End UART_4D_OLED_TX_ENABLED */

    #else /* CY_UDB_V1 */

        #if(UART_4D_OLED_CONTROL_REG_REMOVED == 0u)
            UART_4D_OLED_CONTROL_REG = UART_4D_OLED_backup.cr;
        #endif /* End UART_4D_OLED_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: UART_4D_OLED_Sleep
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
*  UART_4D_OLED_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_4D_OLED_Sleep(void)
{

    #if(UART_4D_OLED_RX_ENABLED || UART_4D_OLED_HD_ENABLED)
        if((UART_4D_OLED_RXSTATUS_ACTL_REG  & UART_4D_OLED_INT_ENABLE) != 0u)
        {
            UART_4D_OLED_backup.enableState = 1u;
        }
        else
        {
            UART_4D_OLED_backup.enableState = 0u;
        }
    #else
        if((UART_4D_OLED_TXSTATUS_ACTL_REG  & UART_4D_OLED_INT_ENABLE) !=0u)
        {
            UART_4D_OLED_backup.enableState = 1u;
        }
        else
        {
            UART_4D_OLED_backup.enableState = 0u;
        }
    #endif /* End UART_4D_OLED_RX_ENABLED || UART_4D_OLED_HD_ENABLED*/

    UART_4D_OLED_Stop();
    UART_4D_OLED_SaveConfig();
}


/*******************************************************************************
* Function Name: UART_4D_OLED_Wakeup
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
*  UART_4D_OLED_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_4D_OLED_Wakeup(void)
{
    UART_4D_OLED_RestoreConfig();
    #if( (UART_4D_OLED_RX_ENABLED) || (UART_4D_OLED_HD_ENABLED) )
        UART_4D_OLED_ClearRxBuffer();
    #endif /* End (UART_4D_OLED_RX_ENABLED) || (UART_4D_OLED_HD_ENABLED) */
    #if(UART_4D_OLED_TX_ENABLED || UART_4D_OLED_HD_ENABLED)
        UART_4D_OLED_ClearTxBuffer();
    #endif /* End UART_4D_OLED_TX_ENABLED || UART_4D_OLED_HD_ENABLED */

    if(UART_4D_OLED_backup.enableState != 0u)
    {
        UART_4D_OLED_Enable();
    }
}


/* [] END OF FILE */
