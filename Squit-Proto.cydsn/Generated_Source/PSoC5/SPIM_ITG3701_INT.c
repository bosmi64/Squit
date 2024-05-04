/*******************************************************************************
* File Name: SPIM_ITG3701_INT.c
* Version 2.40
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_ITG3701_PVT.h"

/* User code required at start of ISR */
/* `#START SPIM_ITG3701_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_ITG3701_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_ITG3701_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPIM_ITG3701_txBuffer[SPIM_ITG3701_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_ITG3701_TX_ISR)
{
    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START SPIM_ITG3701_TX_ISR_START` */

    /* `#END` */

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_ITG3701_txBufferRead != SPIM_ITG3701_txBufferWrite)
        {
            tmpStatus = SPIM_ITG3701_GET_STATUS_TX(SPIM_ITG3701_swStatusTx);
            SPIM_ITG3701_swStatusTx = tmpStatus;

            if(0u != (SPIM_ITG3701_swStatusTx & SPIM_ITG3701_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPIM_ITG3701_txBufferFull)
                {
                   SPIM_ITG3701_txBufferRead++;

                    if(SPIM_ITG3701_txBufferRead >= SPIM_ITG3701_TX_BUFFER_SIZE)
                    {
                        SPIM_ITG3701_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_ITG3701_txBufferFull = 0u;
                }

                /* Move data from the Buffer to the FIFO */
                CY_SET_REG16(SPIM_ITG3701_TXDATA_PTR,
                    SPIM_ITG3701_txBuffer[SPIM_ITG3701_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPIM_ITG3701_txBufferRead == SPIM_ITG3701_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPIM_ITG3701_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_ITG3701_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_ITG3701_TX_ISR_END` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_ITG3701_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_ITG3701_rxBuffer[SPIM_ITG3701_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_ITG3701_RX_ISR)
{
    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint16 rxData;
    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START SPIM_ITG3701_RX_ISR_START` */

    /* `#END` */

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPIM_ITG3701_GET_STATUS_RX(SPIM_ITG3701_swStatusRx);
        SPIM_ITG3701_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPIM_ITG3701_swStatusRx & SPIM_ITG3701_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG16(SPIM_ITG3701_RXDATA_PTR);

            /* Set next pointer. */
            SPIM_ITG3701_rxBufferWrite++;
            if(SPIM_ITG3701_rxBufferWrite >= SPIM_ITG3701_RX_BUFFER_SIZE)
            {
                SPIM_ITG3701_rxBufferWrite = 0u;
            }

            if(SPIM_ITG3701_rxBufferWrite == SPIM_ITG3701_rxBufferRead)
            {
                SPIM_ITG3701_rxBufferRead++;
                if(SPIM_ITG3701_rxBufferRead >= SPIM_ITG3701_RX_BUFFER_SIZE)
                {
                    SPIM_ITG3701_rxBufferRead = 0u;
                }

                SPIM_ITG3701_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPIM_ITG3701_rxBuffer[SPIM_ITG3701_rxBufferWrite] = rxData;

            tmpStatus = SPIM_ITG3701_GET_STATUS_RX(SPIM_ITG3701_swStatusRx);
            SPIM_ITG3701_swStatusRx = tmpStatus;
        }

    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_ITG3701_RX_ISR_END` */

    /* `#END` */
}

/* [] END OF FILE */
