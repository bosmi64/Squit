/*******************************************************************************
* File Name: ADIS_16210_SPI_INT.c
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

#include "ADIS_16210_SPI_PVT.h"

/* User code required at start of ISR */
/* `#START ADIS_16210_SPI_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: ADIS_16210_SPI_TX_ISR
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
*  ADIS_16210_SPI_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  ADIS_16210_SPI_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(ADIS_16210_SPI_TX_ISR)
{
    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START ADIS_16210_SPI_TX_ISR_START` */

    /* `#END` */

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(ADIS_16210_SPI_txBufferRead != ADIS_16210_SPI_txBufferWrite)
        {
            tmpStatus = ADIS_16210_SPI_GET_STATUS_TX(ADIS_16210_SPI_swStatusTx);
            ADIS_16210_SPI_swStatusTx = tmpStatus;

            if(0u != (ADIS_16210_SPI_swStatusTx & ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == ADIS_16210_SPI_txBufferFull)
                {
                   ADIS_16210_SPI_txBufferRead++;

                    if(ADIS_16210_SPI_txBufferRead >= ADIS_16210_SPI_TX_BUFFER_SIZE)
                    {
                        ADIS_16210_SPI_txBufferRead = 0u;
                    }
                }
                else
                {
                    ADIS_16210_SPI_txBufferFull = 0u;
                }

                /* Move data from the Buffer to the FIFO */
                CY_SET_REG16(ADIS_16210_SPI_TXDATA_PTR,
                    ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(ADIS_16210_SPI_txBufferRead == ADIS_16210_SPI_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            ADIS_16210_SPI_TX_STATUS_MASK_REG &= ((uint8) ~ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START ADIS_16210_SPI_TX_ISR_END` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_RX_ISR
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
*  ADIS_16210_SPI_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  ADIS_16210_SPI_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(ADIS_16210_SPI_RX_ISR)
{
    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint16 rxData;
    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at start of ISR */
    /* `#START ADIS_16210_SPI_RX_ISR_START` */

    /* `#END` */

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = ADIS_16210_SPI_GET_STATUS_RX(ADIS_16210_SPI_swStatusRx);
        ADIS_16210_SPI_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (ADIS_16210_SPI_swStatusRx & ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG16(ADIS_16210_SPI_RXDATA_PTR);

            /* Set next pointer. */
            ADIS_16210_SPI_rxBufferWrite++;
            if(ADIS_16210_SPI_rxBufferWrite >= ADIS_16210_SPI_RX_BUFFER_SIZE)
            {
                ADIS_16210_SPI_rxBufferWrite = 0u;
            }

            if(ADIS_16210_SPI_rxBufferWrite == ADIS_16210_SPI_rxBufferRead)
            {
                ADIS_16210_SPI_rxBufferRead++;
                if(ADIS_16210_SPI_rxBufferRead >= ADIS_16210_SPI_RX_BUFFER_SIZE)
                {
                    ADIS_16210_SPI_rxBufferRead = 0u;
                }

                ADIS_16210_SPI_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_rxBufferWrite] = rxData;

            tmpStatus = ADIS_16210_SPI_GET_STATUS_RX(ADIS_16210_SPI_swStatusRx);
            ADIS_16210_SPI_swStatusRx = tmpStatus;
        }

    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START ADIS_16210_SPI_RX_ISR_END` */

    /* `#END` */
}

/* [] END OF FILE */
