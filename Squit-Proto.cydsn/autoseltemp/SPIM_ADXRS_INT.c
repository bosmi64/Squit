/*******************************************************************************
* File Name: SPIM_ADXRS_INT.c
* Version 2.21
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_ADXRS.h"

#if (SPIM_ADXRS_RXBUFFERSIZE > 4u)

    extern volatile uint16 SPIM_ADXRS_RXBUFFER[];
    extern volatile uint8 SPIM_ADXRS_rxBufferRead;
    extern volatile uint8 SPIM_ADXRS_rxBufferWrite;
    extern volatile uint8 SPIM_ADXRS_rxBufferFull;
    
#endif /* SPIM_ADXRS_RXBUFFERSIZE > 4u */

#if (SPIM_ADXRS_TXBUFFERSIZE > 4u)

    extern volatile uint16 SPIM_ADXRS_TXBUFFER[];
    extern volatile uint8 SPIM_ADXRS_txBufferRead;
    extern volatile uint8 SPIM_ADXRS_txBufferWrite;
    extern volatile uint8 SPIM_ADXRS_txBufferFull;

#endif /* SPIM_ADXRS_TXBUFFERSIZE > 4u */

volatile uint8 SPIM_ADXRS_swStatusTx = 0u;
volatile uint8 SPIM_ADXRS_swStatusRx = 0u;

/* User code required at start of ISR */
/* `#START SPIM_ADXRS_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_ADXRS_TX_ISR
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
*  SPIM_ADXRS_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_ADXRS_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to 
*  sending and FIFO Not Full.
*  SPIM_ADXRS_TXBUFFER[SPIM_ADXRS_TXBUFFERSIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_ADXRS_TX_ISR)
{     
    /* User code required at start of ISR */
    /* `#START SPIM_ADXRS_TX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_ADXRS_InternalTxInterruptEnabled) && (SPIM_ADXRS_TXBUFFERSIZE > 4u))
                         
        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_ADXRS_txBufferRead != SPIM_ADXRS_txBufferWrite)
        {
            SPIM_ADXRS_swStatusTx = SPIM_ADXRS_GET_STATUS_TX(SPIM_ADXRS_swStatusTx);
            
            if ((SPIM_ADXRS_swStatusTx & SPIM_ADXRS_STS_TX_FIFO_NOT_FULL) != 0u)
            {            
                if(SPIM_ADXRS_txBufferFull == 0u)
                {
                   SPIM_ADXRS_txBufferRead++;

                    if(SPIM_ADXRS_txBufferRead >= SPIM_ADXRS_TXBUFFERSIZE)
                    {
                        SPIM_ADXRS_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_ADXRS_txBufferFull = 0u;
                }
            
                /* Move data from the Buffer to the FIFO */
                CY_SET_REG16(SPIM_ADXRS_TXDATA_PTR,
                    SPIM_ADXRS_TXBUFFER[SPIM_ADXRS_txBufferRead]);
            }
            else
            {
                break;
            }            
        }
            
        /* Disable Interrupt on TX_fifo_not_empty if BUFFER is empty */
        if(SPIM_ADXRS_txBufferRead == SPIM_ADXRS_txBufferWrite)
        {
            SPIM_ADXRS_TX_STATUS_MASK_REG  &= ~SPIM_ADXRS_STS_TX_FIFO_NOT_FULL; 
        }                       
        
	#endif /* SPIM_ADXRS_InternalTxInterruptEnabled && (SPIM_ADXRS_TXBUFFERSIZE > 4u) */
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_ADXRS_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH
        #if(SPIM_ADXRS_PSOC3_ES2 && (SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH))
            SPIM_ADXRS_TX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */
    #endif /* SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH */    
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_RX_ISR
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
*  SPIM_ADXRS_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_ADXRS_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_ADXRS_RXBUFFER[SPIM_ADXRS_RXBUFFERSIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_ADXRS_RX_ISR)
{     
    #if((SPIM_ADXRS_InternalRxInterruptEnabled) && (SPIM_ADXRS_RXBUFFERSIZE > 4u))
        uint16 rxData = 0u; 
    #endif /* SPIM_ADXRS_InternalRxInterruptEnabled */  
    
    /* User code required at start of ISR */
    /* `#START SPIM_ADXRS_RX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_ADXRS_InternalRxInterruptEnabled) && (SPIM_ADXRS_RXBUFFERSIZE > 4u))
         
        SPIM_ADXRS_swStatusRx = SPIM_ADXRS_GET_STATUS_RX(SPIM_ADXRS_swStatusRx);          
        
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((SPIM_ADXRS_swStatusRx & SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY) == 
                                                                                SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY)
        {
            rxData = CY_GET_REG16(SPIM_ADXRS_RXDATA_PTR);
            
            /* Set next pointer. */
            SPIM_ADXRS_rxBufferWrite++;
            if(SPIM_ADXRS_rxBufferWrite >= SPIM_ADXRS_RXBUFFERSIZE)
            {
                SPIM_ADXRS_rxBufferWrite = 0u;
            }
            
            if(SPIM_ADXRS_rxBufferWrite == SPIM_ADXRS_rxBufferRead)
            {
                SPIM_ADXRS_rxBufferRead++;
                if(SPIM_ADXRS_rxBufferRead >= SPIM_ADXRS_RXBUFFERSIZE)
                {
                    SPIM_ADXRS_rxBufferRead = 0u;
                }
                SPIM_ADXRS_rxBufferFull = 1u;
            }
            
            /* Move data from the FIFO to the Buffer */
            SPIM_ADXRS_RXBUFFER[SPIM_ADXRS_rxBufferWrite] = rxData;
                
            SPIM_ADXRS_swStatusRx = SPIM_ADXRS_GET_STATUS_RX(SPIM_ADXRS_swStatusRx);
        }                    
        
	#endif /* SPIM_ADXRS_InternalRxInterruptEnabled  && (SPIM_ADXRS_RXBUFFERSIZE > 4u) */        
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_ADXRS_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH
        #if(SPIM_ADXRS_PSOC3_ES2 && (SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH))
            SPIM_ADXRS_RX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */  
    #endif /* SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH */       
}

/* [] END OF FILE */
