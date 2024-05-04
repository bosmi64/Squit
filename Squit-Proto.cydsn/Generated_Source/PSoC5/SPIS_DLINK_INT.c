/*******************************************************************************
* File Name: SPIS_DLINK_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Slave
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

#include "SPIS_DLINK.h"

#if (SPIS_DLINK_RXBUFFERSIZE > 4u)

    extern volatile uint16 SPIS_DLINK_RXBUFFER[];
    extern volatile uint8 SPIS_DLINK_rxBufferRead;
    extern volatile uint8 SPIS_DLINK_rxBufferWrite;
    extern volatile uint8 SPIS_DLINK_rxBufferFull;

#endif /* SPIS_DLINK_RXBUFFERSIZE > 4u */

#if (SPIS_DLINK_TXBUFFERSIZE > 4u)

    extern volatile uint16 SPIS_DLINK_TXBUFFER[];
    extern volatile uint8 SPIS_DLINK_txBufferRead;
    extern volatile uint8 SPIS_DLINK_txBufferWrite;
    extern volatile uint8 SPIS_DLINK_txBufferFull;

#endif /* SPIS_DLINK_TXBUFFERSIZE > 4u */

volatile uint8 SPIS_DLINK_swStatusTx = 0u;
volatile uint8 SPIS_DLINK_swStatusRx = 0u;

/* User code required at start of ISR */
/* `#START SPIS_DLINK_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIS_DLINK_TX_ISR
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_DLINK_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIS_DLINK_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPIS_DLINK_TXBUFFER[SPIS_DLINK_TXBUFFERSIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIS_DLINK_TX_ISR)
{
    /* User code required at start of ISR */
    /* `#START SPIS_DLINK_ISR_TX_START` */

    /* `#END` */

    #if((SPIS_DLINK_InternalTxInterruptEnabled) && (SPIS_DLINK_TXBUFFERSIZE > 4u))
        /* Component interrupt service code */

        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIS_DLINK_txBufferRead != SPIS_DLINK_txBufferWrite)
        {
            SPIS_DLINK_swStatusTx = SPIS_DLINK_GET_STATUS_TX(SPIS_DLINK_swStatusTx);

            if ((SPIS_DLINK_swStatusTx & SPIS_DLINK_STS_TX_FIFO_NOT_FULL) != 0u)
            {
                if(SPIS_DLINK_txBufferFull == 0u)
                {
                   SPIS_DLINK_txBufferRead++;

                    if(SPIS_DLINK_txBufferRead >= SPIS_DLINK_TXBUFFERSIZE)
                    {
                        SPIS_DLINK_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIS_DLINK_txBufferFull = 0u;
                }

                /* Move data from the Buffer to the FIFO */
                CY_SET_REG16(SPIS_DLINK_TXDATA_PTR,
                    SPIS_DLINK_TXBUFFER[SPIS_DLINK_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        /* If Buffer is empty then disable TX FIFO status interrupt until there is data in the buffer */
        if(SPIS_DLINK_txBufferRead == SPIS_DLINK_txBufferWrite)
        {
            SPIS_DLINK_TX_STATUS_MASK_REG &= ~SPIS_DLINK_STS_TX_FIFO_NOT_FULL;
        }

    #endif /* SPIS_DLINK_InternalTxInterruptEnabled && (SPIS_DLINK_TXBUFFERSIZE > 4u) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIS_DLINK_ISR_TX_END` */

    /* `#END` */

   }


/*******************************************************************************
* Function Name: SPIS_DLINK_RX_ISR
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Slave.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIS_DLINK_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIS_DLINK_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIS_DLINK_RXBUFFER[SPIS_DLINK_RXBUFFERSIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIS_DLINK_RX_ISR)
{
    #if((SPIS_DLINK_InternalRxInterruptEnabled) && (SPIS_DLINK_RXBUFFERSIZE > 4u))
        uint16 rxData = 0u; 
    #endif /* SPIS_DLINK_InternalRxInterruptEnabled */
    
    /* User code required at start of ISR */
    /* `#START SPIS_DLINK_RX_ISR_START` */

    /* `#END` */

    #if((SPIS_DLINK_InternalRxInterruptEnabled) && (SPIS_DLINK_RXBUFFERSIZE > 4u))
        SPIS_DLINK_swStatusRx = SPIS_DLINK_GET_STATUS_RX(SPIS_DLINK_swStatusRx);

        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */        
        while((SPIS_DLINK_swStatusRx & SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY) ==
                                                                                SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY)
        {
            rxData = CY_GET_REG16(SPIS_DLINK_RXDATA_PTR);
            
            /* Set next pointer. */
            SPIS_DLINK_rxBufferWrite++;
            if(SPIS_DLINK_rxBufferWrite >= SPIS_DLINK_RXBUFFERSIZE)
            {
                SPIS_DLINK_rxBufferWrite = 0u;
            }

            if(SPIS_DLINK_rxBufferWrite == SPIS_DLINK_rxBufferRead)
            {
                SPIS_DLINK_rxBufferRead++;
                if(SPIS_DLINK_rxBufferRead >= SPIS_DLINK_RXBUFFERSIZE)
                {
                    SPIS_DLINK_rxBufferRead = 0u;
                }
                SPIS_DLINK_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPIS_DLINK_RXBUFFER[SPIS_DLINK_rxBufferWrite] = rxData;
                
            SPIS_DLINK_swStatusRx = SPIS_DLINK_GET_STATUS_RX(SPIS_DLINK_swStatusRx);
        }
    #endif /* SPIS_DLINK_InternalRxInterruptEnabled  && (SPIS_DLINK_RXBUFFERSIZE > 4u) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPIS_DLINK_RX_ISR_END` */

    /* `#END` */
    
}

/* [] END OF FILE */
