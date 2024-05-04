/*******************************************************************************
* File Name: UART_IMU_INT.c
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

#include "UART_IMU.h"
#include "CyLib.h"


/***************************************
* Custom Declratations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if( (UART_IMU_RX_ENABLED || UART_IMU_HD_ENABLED) && \
     (UART_IMU_RXBUFFERSIZE > UART_IMU_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: UART_IMU_RXISR
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
    *  UART_IMU_rxBuffer - RAM buffer pointer for save received data.
    *  UART_IMU_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  UART_IMU_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  UART_IMU_rxBufferOverflow - software overflow flag. Set to one
    *     when UART_IMU_rxBufferWrite index overtakes
    *     UART_IMU_rxBufferRead index.
    *  UART_IMU_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when UART_IMU_rxBufferWrite is equal to
    *    UART_IMU_rxBufferRead
    *  UART_IMU_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  UART_IMU_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_IMU_RXISR)
    {
        uint8 readData;
        uint8 increment_pointer = 0u;
        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START UART_IMU_RXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        readData = UART_IMU_RXSTATUS_REG;

        if((readData & (UART_IMU_RX_STS_BREAK | UART_IMU_RX_STS_PAR_ERROR |
                        UART_IMU_RX_STS_STOP_ERROR | UART_IMU_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            /* `#START UART_IMU_RXISR_ERROR` */

            /* `#END` */
        }

        while((readData & UART_IMU_RX_STS_FIFO_NOTEMPTY) != 0u)
        {

            #if (UART_IMU_RXHW_ADDRESS_ENABLED)
                if(UART_IMU_rxAddressMode == (uint8)UART_IMU__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readData & UART_IMU_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readData & UART_IMU_RX_STS_ADDR_MATCH) != 0u)
                        {
                            UART_IMU_rxAddressDetected = 1u;
                        }
                        else
                        {
                            UART_IMU_rxAddressDetected = 0u;
                        }
                    }

                    readData = UART_IMU_RXDATA_REG;
                    if(UART_IMU_rxAddressDetected != 0u)
                    {   /* store only addressed data */
                        UART_IMU_rxBuffer[UART_IMU_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* without software addressing */
                {
                    UART_IMU_rxBuffer[UART_IMU_rxBufferWrite] = UART_IMU_RXDATA_REG;
                    increment_pointer = 1u;
                }
            #else  /* without addressing */
                UART_IMU_rxBuffer[UART_IMU_rxBufferWrite] = UART_IMU_RXDATA_REG;
                increment_pointer = 1u;
            #endif /* End SW_DETECT_TO_BUFFER */

            /* do not increment buffer pointer when skip not adderessed data */
            if( increment_pointer != 0u )
            {
                if(UART_IMU_rxBufferLoopDetect != 0u)
                {   /* Set Software Buffer status Overflow */
                    UART_IMU_rxBufferOverflow = 1u;
                }
                /* Set next pointer. */
                UART_IMU_rxBufferWrite++;

                /* Check pointer for a loop condition */
                if(UART_IMU_rxBufferWrite >= UART_IMU_RXBUFFERSIZE)
                {
                    UART_IMU_rxBufferWrite = 0u;
                }
                /* Detect pre-overload condition and set flag */
                if(UART_IMU_rxBufferWrite == UART_IMU_rxBufferRead)
                {
                    UART_IMU_rxBufferLoopDetect = 1u;
                    /* When Hardware Flow Control selected */
                    #if(UART_IMU_FLOW_CONTROL != 0u)
                    /* Disable RX interrupt mask, it will be enabled when user read data from the buffer using APIs */
                        UART_IMU_RXSTATUS_MASK_REG  &= (uint8)~UART_IMU_RX_STS_FIFO_NOTEMPTY;
                        CyIntClearPending(UART_IMU_RX_VECT_NUM);
                        break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                    #endif /* End UART_IMU_FLOW_CONTROL != 0 */
                }
            }

            /* Check again if there is data. */
            readData = UART_IMU_RXSTATUS_REG;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_IMU_RXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End UART_IMU_RX_ENABLED && (UART_IMU_RXBUFFERSIZE > UART_IMU_FIFO_LENGTH) */


#if(UART_IMU_TX_ENABLED && (UART_IMU_TXBUFFERSIZE > UART_IMU_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: UART_IMU_TXISR
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
    *  UART_IMU_txBuffer - RAM buffer pointer for transmit data from.
    *  UART_IMU_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmited byte.
    *  UART_IMU_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_IMU_TXISR)
    {

        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START UART_IMU_TXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        while((UART_IMU_txBufferRead != UART_IMU_txBufferWrite) &&
             ((UART_IMU_TXSTATUS_REG & UART_IMU_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer. */
            if(UART_IMU_txBufferRead >= UART_IMU_TXBUFFERSIZE)
            {
                UART_IMU_txBufferRead = 0u;
            }

            UART_IMU_TXDATA_REG = UART_IMU_txBuffer[UART_IMU_txBufferRead];

            /* Set next pointer. */
            UART_IMU_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_IMU_TXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End UART_IMU_TX_ENABLED && (UART_IMU_TXBUFFERSIZE > UART_IMU_FIFO_LENGTH) */


/* [] END OF FILE */
