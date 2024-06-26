/*******************************************************************************
* File Name: CHRUM7_UART_INT.c
* Version 2.30
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CHRUM7_UART.h"
#include "CyLib.h"


/***************************************
* Custom Declratations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if( (CHRUM7_UART_RX_ENABLED || CHRUM7_UART_HD_ENABLED) && \
     (CHRUM7_UART_RXBUFFERSIZE > CHRUM7_UART_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: CHRUM7_UART_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  CHRUM7_UART_rxBuffer - RAM buffer pointer for save received data.
    *  CHRUM7_UART_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  CHRUM7_UART_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  CHRUM7_UART_rxBufferOverflow - software overflow flag. Set to one
    *     when CHRUM7_UART_rxBufferWrite index overtakes
    *     CHRUM7_UART_rxBufferRead index.
    *  CHRUM7_UART_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when CHRUM7_UART_rxBufferWrite is equal to
    *    CHRUM7_UART_rxBufferRead
    *  CHRUM7_UART_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  CHRUM7_UART_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(CHRUM7_UART_RXISR)
    {
        uint8 readData;
        uint8 increment_pointer = 0u;
        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START CHRUM7_UART_RXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        readData = CHRUM7_UART_RXSTATUS_REG;

        if((readData & (CHRUM7_UART_RX_STS_BREAK | CHRUM7_UART_RX_STS_PAR_ERROR |
                        CHRUM7_UART_RX_STS_STOP_ERROR | CHRUM7_UART_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            /* `#START CHRUM7_UART_RXISR_ERROR` */

            /* `#END` */
        }

        while((readData & CHRUM7_UART_RX_STS_FIFO_NOTEMPTY) != 0u)
        {

            #if (CHRUM7_UART_RXHW_ADDRESS_ENABLED)
                if(CHRUM7_UART_rxAddressMode == (uint8)CHRUM7_UART__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readData & CHRUM7_UART_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readData & CHRUM7_UART_RX_STS_ADDR_MATCH) != 0u)
                        {
                            CHRUM7_UART_rxAddressDetected = 1u;
                        }
                        else
                        {
                            CHRUM7_UART_rxAddressDetected = 0u;
                        }
                    }

                    readData = CHRUM7_UART_RXDATA_REG;
                    if(CHRUM7_UART_rxAddressDetected != 0u)
                    {   /* store only addressed data */
                        CHRUM7_UART_rxBuffer[CHRUM7_UART_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* without software addressing */
                {
                    CHRUM7_UART_rxBuffer[CHRUM7_UART_rxBufferWrite] = CHRUM7_UART_RXDATA_REG;
                    increment_pointer = 1u;
                }
            #else  /* without addressing */
                CHRUM7_UART_rxBuffer[CHRUM7_UART_rxBufferWrite] = CHRUM7_UART_RXDATA_REG;
                increment_pointer = 1u;
            #endif /* End SW_DETECT_TO_BUFFER */

            /* do not increment buffer pointer when skip not adderessed data */
            if( increment_pointer != 0u )
            {
                if(CHRUM7_UART_rxBufferLoopDetect != 0u)
                {   /* Set Software Buffer status Overflow */
                    CHRUM7_UART_rxBufferOverflow = 1u;
                }
                /* Set next pointer. */
                CHRUM7_UART_rxBufferWrite++;

                /* Check pointer for a loop condition */
                if(CHRUM7_UART_rxBufferWrite >= CHRUM7_UART_RXBUFFERSIZE)
                {
                    CHRUM7_UART_rxBufferWrite = 0u;
                }
                /* Detect pre-overload condition and set flag */
                if(CHRUM7_UART_rxBufferWrite == CHRUM7_UART_rxBufferRead)
                {
                    CHRUM7_UART_rxBufferLoopDetect = 1u;
                    /* When Hardware Flow Control selected */
                    #if(CHRUM7_UART_FLOW_CONTROL != 0u)
                    /* Disable RX interrupt mask, it will be enabled when user read data from the buffer using APIs */
                        CHRUM7_UART_RXSTATUS_MASK_REG  &= (uint8)~CHRUM7_UART_RX_STS_FIFO_NOTEMPTY;
                        CyIntClearPending(CHRUM7_UART_RX_VECT_NUM);
                        break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                    #endif /* End CHRUM7_UART_FLOW_CONTROL != 0 */
                }
            }

            /* Check again if there is data. */
            readData = CHRUM7_UART_RXSTATUS_REG;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START CHRUM7_UART_RXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End CHRUM7_UART_RX_ENABLED && (CHRUM7_UART_RXBUFFERSIZE > CHRUM7_UART_FIFO_LENGTH) */


#if(CHRUM7_UART_TX_ENABLED && (CHRUM7_UART_TXBUFFERSIZE > CHRUM7_UART_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: CHRUM7_UART_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  CHRUM7_UART_txBuffer - RAM buffer pointer for transmit data from.
    *  CHRUM7_UART_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmited byte.
    *  CHRUM7_UART_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(CHRUM7_UART_TXISR)
    {

        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START CHRUM7_UART_TXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        while((CHRUM7_UART_txBufferRead != CHRUM7_UART_txBufferWrite) &&
             ((CHRUM7_UART_TXSTATUS_REG & CHRUM7_UART_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer. */
            if(CHRUM7_UART_txBufferRead >= CHRUM7_UART_TXBUFFERSIZE)
            {
                CHRUM7_UART_txBufferRead = 0u;
            }

            CHRUM7_UART_TXDATA_REG = CHRUM7_UART_txBuffer[CHRUM7_UART_txBufferRead];

            /* Set next pointer. */
            CHRUM7_UART_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START CHRUM7_UART_TXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End CHRUM7_UART_TX_ENABLED && (CHRUM7_UART_TXBUFFERSIZE > CHRUM7_UART_FIFO_LENGTH) */


/* [] END OF FILE */
