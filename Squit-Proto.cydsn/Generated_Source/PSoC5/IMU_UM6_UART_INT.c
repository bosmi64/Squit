/*******************************************************************************
* File Name: IMU_UM6_UART_INT.c
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

#include "IMU_UM6_UART.h"
#include "CyLib.h"


/***************************************
* Custom Declratations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if( (IMU_UM6_UART_RX_ENABLED || IMU_UM6_UART_HD_ENABLED) && \
     (IMU_UM6_UART_RXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: IMU_UM6_UART_RXISR
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
    *  IMU_UM6_UART_rxBuffer - RAM buffer pointer for save received data.
    *  IMU_UM6_UART_rxBufferWrite - cyclic index for write to rxBuffer,
    *     increments after each byte saved to buffer.
    *  IMU_UM6_UART_rxBufferRead - cyclic index for read from rxBuffer,
    *     checked to detect overflow condition.
    *  IMU_UM6_UART_rxBufferOverflow - software overflow flag. Set to one
    *     when IMU_UM6_UART_rxBufferWrite index overtakes
    *     IMU_UM6_UART_rxBufferRead index.
    *  IMU_UM6_UART_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when IMU_UM6_UART_rxBufferWrite is equal to
    *    IMU_UM6_UART_rxBufferRead
    *  IMU_UM6_UART_rxAddressMode - this variable contains the Address mode,
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  IMU_UM6_UART_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(IMU_UM6_UART_RXISR)
    {
        uint8 readData;
        uint8 increment_pointer = 0u;
        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START IMU_UM6_UART_RXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        readData = IMU_UM6_UART_RXSTATUS_REG;

        if((readData & (IMU_UM6_UART_RX_STS_BREAK | IMU_UM6_UART_RX_STS_PAR_ERROR |
                        IMU_UM6_UART_RX_STS_STOP_ERROR | IMU_UM6_UART_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            /* `#START IMU_UM6_UART_RXISR_ERROR` */

            /* `#END` */
        }

        while((readData & IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY) != 0u)
        {

            #if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
                if(IMU_UM6_UART_rxAddressMode == (uint8)IMU_UM6_UART__B_UART__AM_SW_DETECT_TO_BUFFER)
                {
                    if((readData & IMU_UM6_UART_RX_STS_MRKSPC) != 0u)
                    {
                        if ((readData & IMU_UM6_UART_RX_STS_ADDR_MATCH) != 0u)
                        {
                            IMU_UM6_UART_rxAddressDetected = 1u;
                        }
                        else
                        {
                            IMU_UM6_UART_rxAddressDetected = 0u;
                        }
                    }

                    readData = IMU_UM6_UART_RXDATA_REG;
                    if(IMU_UM6_UART_rxAddressDetected != 0u)
                    {   /* store only addressed data */
                        IMU_UM6_UART_rxBuffer[IMU_UM6_UART_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* without software addressing */
                {
                    IMU_UM6_UART_rxBuffer[IMU_UM6_UART_rxBufferWrite] = IMU_UM6_UART_RXDATA_REG;
                    increment_pointer = 1u;
                }
            #else  /* without addressing */
                IMU_UM6_UART_rxBuffer[IMU_UM6_UART_rxBufferWrite] = IMU_UM6_UART_RXDATA_REG;
                increment_pointer = 1u;
            #endif /* End SW_DETECT_TO_BUFFER */

            /* do not increment buffer pointer when skip not adderessed data */
            if( increment_pointer != 0u )
            {
                if(IMU_UM6_UART_rxBufferLoopDetect != 0u)
                {   /* Set Software Buffer status Overflow */
                    IMU_UM6_UART_rxBufferOverflow = 1u;
                }
                /* Set next pointer. */
                IMU_UM6_UART_rxBufferWrite++;

                /* Check pointer for a loop condition */
                if(IMU_UM6_UART_rxBufferWrite >= IMU_UM6_UART_RXBUFFERSIZE)
                {
                    IMU_UM6_UART_rxBufferWrite = 0u;
                }
                /* Detect pre-overload condition and set flag */
                if(IMU_UM6_UART_rxBufferWrite == IMU_UM6_UART_rxBufferRead)
                {
                    IMU_UM6_UART_rxBufferLoopDetect = 1u;
                    /* When Hardware Flow Control selected */
                    #if(IMU_UM6_UART_FLOW_CONTROL != 0u)
                    /* Disable RX interrupt mask, it will be enabled when user read data from the buffer using APIs */
                        IMU_UM6_UART_RXSTATUS_MASK_REG  &= (uint8)~IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY;
                        CyIntClearPending(IMU_UM6_UART_RX_VECT_NUM);
                        break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                    #endif /* End IMU_UM6_UART_FLOW_CONTROL != 0 */
                }
            }

            /* Check again if there is data. */
            readData = IMU_UM6_UART_RXSTATUS_REG;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START IMU_UM6_UART_RXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End IMU_UM6_UART_RX_ENABLED && (IMU_UM6_UART_RXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH) */


#if(IMU_UM6_UART_TX_ENABLED && (IMU_UM6_UART_TXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH))


    /*******************************************************************************
    * Function Name: IMU_UM6_UART_TXISR
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
    *  IMU_UM6_UART_txBuffer - RAM buffer pointer for transmit data from.
    *  IMU_UM6_UART_txBufferRead - cyclic index for read and transmit data
    *     from txBuffer, increments after each transmited byte.
    *  IMU_UM6_UART_rxBufferWrite - cyclic index for write to txBuffer,
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(IMU_UM6_UART_TXISR)
    {

        #if(CY_PSOC3)
            uint8 int_en;
        #endif /* CY_PSOC3 */

        /* User code required at start of ISR */
        /* `#START IMU_UM6_UART_TXISR_START` */

        /* `#END` */

        #if(CY_PSOC3)   /* Make sure nested interrupt is enabled */
            int_en = EA;
            CyGlobalIntEnable;
        #endif /* CY_PSOC3 */

        while((IMU_UM6_UART_txBufferRead != IMU_UM6_UART_txBufferWrite) &&
             ((IMU_UM6_UART_TXSTATUS_REG & IMU_UM6_UART_TX_STS_FIFO_FULL) == 0u))
        {
            /* Check pointer. */
            if(IMU_UM6_UART_txBufferRead >= IMU_UM6_UART_TXBUFFERSIZE)
            {
                IMU_UM6_UART_txBufferRead = 0u;
            }

            IMU_UM6_UART_TXDATA_REG = IMU_UM6_UART_txBuffer[IMU_UM6_UART_txBufferRead];

            /* Set next pointer. */
            IMU_UM6_UART_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START IMU_UM6_UART_TXISR_END` */

        /* `#END` */

        #if(CY_PSOC3)
            EA = int_en;
        #endif /* CY_PSOC3 */

    }

#endif /* End IMU_UM6_UART_TX_ENABLED && (IMU_UM6_UART_TXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH) */


/* [] END OF FILE */
