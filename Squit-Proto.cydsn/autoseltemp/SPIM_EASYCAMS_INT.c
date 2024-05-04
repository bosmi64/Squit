/*******************************************************************************
* File Name: SPIM_EASYCAMS_INT.c
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

#include "SPIM_EASYCAMS.h"

#if (SPIM_EASYCAMS_RXBUFFERSIZE > 4u)

    extern volatile uint16 SPIM_EASYCAMS_RXBUFFER[];
    extern volatile uint8 SPIM_EASYCAMS_rxBufferRead;
    extern volatile uint8 SPIM_EASYCAMS_rxBufferWrite;
    extern volatile uint8 SPIM_EASYCAMS_rxBufferFull;
    
#endif /* SPIM_EASYCAMS_RXBUFFERSIZE > 4u */

#if (SPIM_EASYCAMS_TXBUFFERSIZE > 4u)

    extern volatile uint16 SPIM_EASYCAMS_TXBUFFER[];
    extern volatile uint8 SPIM_EASYCAMS_txBufferRead;
    extern volatile uint8 SPIM_EASYCAMS_txBufferWrite;
    extern volatile uint8 SPIM_EASYCAMS_txBufferFull;

#endif /* SPIM_EASYCAMS_TXBUFFERSIZE > 4u */

volatile uint8 SPIM_EASYCAMS_swStatusTx = 0u;
volatile uint8 SPIM_EASYCAMS_swStatusRx = 0u;

/* User code required at start of ISR */
/* `#START SPIM_EASYCAMS_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_TX_ISR
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
*  SPIM_EASYCAMS_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_EASYCAMS_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to 
*  sending and FIFO Not Full.
*  SPIM_EASYCAMS_TXBUFFER[SPIM_EASYCAMS_TXBUFFERSIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_EASYCAMS_TX_ISR)
{     
    /* User code required at start of ISR */
    /* `#START SPIM_EASYCAMS_TX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_EASYCAMS_InternalTxInterruptEnabled) && (SPIM_EASYCAMS_TXBUFFERSIZE > 4u))
                         
        /* See if TX data buffer is not empty and there is space in TX FIFO */
        while(SPIM_EASYCAMS_txBufferRead != SPIM_EASYCAMS_txBufferWrite)
        {
            SPIM_EASYCAMS_swStatusTx = SPIM_EASYCAMS_GET_STATUS_TX(SPIM_EASYCAMS_swStatusTx);
            
            if ((SPIM_EASYCAMS_swStatusTx & SPIM_EASYCAMS_STS_TX_FIFO_NOT_FULL) != 0u)
            {            
                if(SPIM_EASYCAMS_txBufferFull == 0u)
                {
                   SPIM_EASYCAMS_txBufferRead++;

                    if(SPIM_EASYCAMS_txBufferRead >= SPIM_EASYCAMS_TXBUFFERSIZE)
                    {
                        SPIM_EASYCAMS_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPIM_EASYCAMS_txBufferFull = 0u;
                }
            
                /* Move data from the Buffer to the FIFO */
                CY_SET_REG16(SPIM_EASYCAMS_TXDATA_PTR,
                    SPIM_EASYCAMS_TXBUFFER[SPIM_EASYCAMS_txBufferRead]);
            }
            else
            {
                break;
            }            
        }
            
        /* Disable Interrupt on TX_fifo_not_empty if BUFFER is empty */
        if(SPIM_EASYCAMS_txBufferRead == SPIM_EASYCAMS_txBufferWrite)
        {
            SPIM_EASYCAMS_TX_STATUS_MASK_REG  &= ~SPIM_EASYCAMS_STS_TX_FIFO_NOT_FULL; 
        }                       
        
	#endif /* SPIM_EASYCAMS_InternalTxInterruptEnabled && (SPIM_EASYCAMS_TXBUFFERSIZE > 4u) */
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_EASYCAMS_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_EASYCAMS_TxInternalInterrupt__ES2_PATCH
        #if(SPIM_EASYCAMS_PSOC3_ES2 && (SPIM_EASYCAMS_TxInternalInterrupt__ES2_PATCH))
            SPIM_EASYCAMS_TX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */
    #endif /* SPIM_EASYCAMS_TxInternalInterrupt__ES2_PATCH */    
}


/*******************************************************************************
* Function Name: SPIM_EASYCAMS_RX_ISR
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
*  SPIM_EASYCAMS_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPIM_EASYCAMS_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPIM_EASYCAMS_RXBUFFER[SPIM_EASYCAMS_RXBUFFERSIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPIM_EASYCAMS_RX_ISR)
{     
    #if((SPIM_EASYCAMS_InternalRxInterruptEnabled) && (SPIM_EASYCAMS_RXBUFFERSIZE > 4u))
        uint16 rxData = 0u; 
    #endif /* SPIM_EASYCAMS_InternalRxInterruptEnabled */  
    
    /* User code required at start of ISR */
    /* `#START SPIM_EASYCAMS_RX_ISR_START` */

    /* `#END` */
    
    #if((SPIM_EASYCAMS_InternalRxInterruptEnabled) && (SPIM_EASYCAMS_RXBUFFERSIZE > 4u))
         
        SPIM_EASYCAMS_swStatusRx = SPIM_EASYCAMS_GET_STATUS_RX(SPIM_EASYCAMS_swStatusRx);          
        
        /* See if RX data FIFO has some data and if it can be moved to the RX Buffer */
        while((SPIM_EASYCAMS_swStatusRx & SPIM_EASYCAMS_STS_RX_FIFO_NOT_EMPTY) == 
                                                                                SPIM_EASYCAMS_STS_RX_FIFO_NOT_EMPTY)
        {
            rxData = CY_GET_REG16(SPIM_EASYCAMS_RXDATA_PTR);
            
            /* Set next pointer. */
            SPIM_EASYCAMS_rxBufferWrite++;
            if(SPIM_EASYCAMS_rxBufferWrite >= SPIM_EASYCAMS_RXBUFFERSIZE)
            {
                SPIM_EASYCAMS_rxBufferWrite = 0u;
            }
            
            if(SPIM_EASYCAMS_rxBufferWrite == SPIM_EASYCAMS_rxBufferRead)
            {
                SPIM_EASYCAMS_rxBufferRead++;
                if(SPIM_EASYCAMS_rxBufferRead >= SPIM_EASYCAMS_RXBUFFERSIZE)
                {
                    SPIM_EASYCAMS_rxBufferRead = 0u;
                }
                SPIM_EASYCAMS_rxBufferFull = 1u;
            }
            
            /* Move data from the FIFO to the Buffer */
            SPIM_EASYCAMS_RXBUFFER[SPIM_EASYCAMS_rxBufferWrite] = rxData;
                
            SPIM_EASYCAMS_swStatusRx = SPIM_EASYCAMS_GET_STATUS_RX(SPIM_EASYCAMS_swStatusRx);
        }                    
        
	#endif /* SPIM_EASYCAMS_InternalRxInterruptEnabled  && (SPIM_EASYCAMS_RXBUFFERSIZE > 4u) */        
    
    /* User code required at end of ISR (Optional) */
    /* `#START SPIM_EASYCAMS_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPIM_EASYCAMS_RxInternalInterrupt__ES2_PATCH
        #if(SPIM_EASYCAMS_PSOC3_ES2 && (SPIM_EASYCAMS_RxInternalInterrupt__ES2_PATCH))
            SPIM_EASYCAMS_RX_ISR_PATCH();
        #endif /* End PSOC3_ES2 */  
    #endif /* SPIM_EASYCAMS_RxInternalInterrupt__ES2_PATCH */       
}

/* [] END OF FILE */
