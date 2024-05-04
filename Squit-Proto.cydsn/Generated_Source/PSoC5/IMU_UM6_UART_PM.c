/*******************************************************************************
* File Name: IMU_UM6_UART_PM.c
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

#include "IMU_UM6_UART.h"


/***************************************
* Local data allocation
***************************************/

static IMU_UM6_UART_BACKUP_STRUCT  IMU_UM6_UART_backup =
{
    /* enableState - disabled */
    0u,
};



/*******************************************************************************
* Function Name: IMU_UM6_UART_SaveConfig
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
*  IMU_UM6_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void IMU_UM6_UART_SaveConfig(void)
{
    #if (CY_UDB_V0)

        #if(IMU_UM6_UART_CONTROL_REG_REMOVED == 0u)
            IMU_UM6_UART_backup.cr = IMU_UM6_UART_CONTROL_REG;
        #endif /* End IMU_UM6_UART_CONTROL_REG_REMOVED */

        #if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
            IMU_UM6_UART_backup.rx_period = IMU_UM6_UART_RXBITCTR_PERIOD_REG;
            IMU_UM6_UART_backup.rx_mask = IMU_UM6_UART_RXSTATUS_MASK_REG;
            #if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
                IMU_UM6_UART_backup.rx_addr1 = IMU_UM6_UART_RXADDRESS1_REG;
                IMU_UM6_UART_backup.rx_addr2 = IMU_UM6_UART_RXADDRESS2_REG;
            #endif /* End IMU_UM6_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End IMU_UM6_UART_RX_ENABLED | IMU_UM6_UART_HD_ENABLED*/

        #if(IMU_UM6_UART_TX_ENABLED)
            #if(IMU_UM6_UART_TXCLKGEN_DP)
                IMU_UM6_UART_backup.tx_clk_ctr = IMU_UM6_UART_TXBITCLKGEN_CTR_REG;
                IMU_UM6_UART_backup.tx_clk_compl = IMU_UM6_UART_TXBITCLKTX_COMPLETE_REG;
            #else
                IMU_UM6_UART_backup.tx_period = IMU_UM6_UART_TXBITCTR_PERIOD_REG;
            #endif /*End IMU_UM6_UART_TXCLKGEN_DP */
            IMU_UM6_UART_backup.tx_mask = IMU_UM6_UART_TXSTATUS_MASK_REG;
        #endif /*End IMU_UM6_UART_TX_ENABLED */


    #else /* CY_UDB_V1 */

        #if(IMU_UM6_UART_CONTROL_REG_REMOVED == 0u)
            IMU_UM6_UART_backup.cr = IMU_UM6_UART_CONTROL_REG;
        #endif /* End IMU_UM6_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: IMU_UM6_UART_RestoreConfig
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
*  IMU_UM6_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void IMU_UM6_UART_RestoreConfig(void)
{

    #if (CY_UDB_V0)

        #if(IMU_UM6_UART_CONTROL_REG_REMOVED == 0u)
            IMU_UM6_UART_CONTROL_REG = IMU_UM6_UART_backup.cr;
        #endif /* End IMU_UM6_UART_CONTROL_REG_REMOVED */

        #if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
            IMU_UM6_UART_RXBITCTR_PERIOD_REG = IMU_UM6_UART_backup.rx_period;
            IMU_UM6_UART_RXSTATUS_MASK_REG = IMU_UM6_UART_backup.rx_mask;
            #if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
                IMU_UM6_UART_RXADDRESS1_REG = IMU_UM6_UART_backup.rx_addr1;
                IMU_UM6_UART_RXADDRESS2_REG = IMU_UM6_UART_backup.rx_addr2;
            #endif /* End IMU_UM6_UART_RXHW_ADDRESS_ENABLED */
        #endif  /* End (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */

        #if(IMU_UM6_UART_TX_ENABLED)
            #if(IMU_UM6_UART_TXCLKGEN_DP)
                IMU_UM6_UART_TXBITCLKGEN_CTR_REG = IMU_UM6_UART_backup.tx_clk_ctr;
                IMU_UM6_UART_TXBITCLKTX_COMPLETE_REG = IMU_UM6_UART_backup.tx_clk_compl;
            #else
                IMU_UM6_UART_TXBITCTR_PERIOD_REG = IMU_UM6_UART_backup.tx_period;
            #endif /*End IMU_UM6_UART_TXCLKGEN_DP */
            IMU_UM6_UART_TXSTATUS_MASK_REG = IMU_UM6_UART_backup.tx_mask;
        #endif /*End IMU_UM6_UART_TX_ENABLED */

    #else /* CY_UDB_V1 */

        #if(IMU_UM6_UART_CONTROL_REG_REMOVED == 0u)
            IMU_UM6_UART_CONTROL_REG = IMU_UM6_UART_backup.cr;
        #endif /* End IMU_UM6_UART_CONTROL_REG_REMOVED */

    #endif  /* End CY_UDB_V0 */
}


/*******************************************************************************
* Function Name: IMU_UM6_UART_Sleep
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
*  IMU_UM6_UART_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void IMU_UM6_UART_Sleep(void)
{

    #if(IMU_UM6_UART_RX_ENABLED || IMU_UM6_UART_HD_ENABLED)
        if((IMU_UM6_UART_RXSTATUS_ACTL_REG  & IMU_UM6_UART_INT_ENABLE) != 0u)
        {
            IMU_UM6_UART_backup.enableState = 1u;
        }
        else
        {
            IMU_UM6_UART_backup.enableState = 0u;
        }
    #else
        if((IMU_UM6_UART_TXSTATUS_ACTL_REG  & IMU_UM6_UART_INT_ENABLE) !=0u)
        {
            IMU_UM6_UART_backup.enableState = 1u;
        }
        else
        {
            IMU_UM6_UART_backup.enableState = 0u;
        }
    #endif /* End IMU_UM6_UART_RX_ENABLED || IMU_UM6_UART_HD_ENABLED*/

    IMU_UM6_UART_Stop();
    IMU_UM6_UART_SaveConfig();
}


/*******************************************************************************
* Function Name: IMU_UM6_UART_Wakeup
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
*  IMU_UM6_UART_backup - used when non-retention registers are restored.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void IMU_UM6_UART_Wakeup(void)
{
    IMU_UM6_UART_RestoreConfig();
    #if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
        IMU_UM6_UART_ClearRxBuffer();
    #endif /* End (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */
    #if(IMU_UM6_UART_TX_ENABLED || IMU_UM6_UART_HD_ENABLED)
        IMU_UM6_UART_ClearTxBuffer();
    #endif /* End IMU_UM6_UART_TX_ENABLED || IMU_UM6_UART_HD_ENABLED */

    if(IMU_UM6_UART_backup.enableState != 0u)
    {
        IMU_UM6_UART_Enable();
    }
}


/* [] END OF FILE */
