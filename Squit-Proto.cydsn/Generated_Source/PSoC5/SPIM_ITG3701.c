/*******************************************************************************
* File Name: SPIM_ITG3701.c
* Version 2.40
*
* Description:
*  This file provides all API functionality of the SPI Master component.
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

#if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPIM_ITG3701_txBuffer[SPIM_ITG3701_TX_BUFFER_SIZE] = {0u};
    volatile uint8 SPIM_ITG3701_txBufferFull;
    volatile uint8 SPIM_ITG3701_txBufferRead;
    volatile uint8 SPIM_ITG3701_txBufferWrite;
#endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPIM_ITG3701_rxBuffer[SPIM_ITG3701_RX_BUFFER_SIZE] = {0u};
    volatile uint8 SPIM_ITG3701_rxBufferFull;
    volatile uint8 SPIM_ITG3701_rxBufferRead;
    volatile uint8 SPIM_ITG3701_rxBufferWrite;
#endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

uint8 SPIM_ITG3701_initVar = 0u;

volatile uint8 SPIM_ITG3701_swStatusTx;
volatile uint8 SPIM_ITG3701_swStatusRx;


/*******************************************************************************
* Function Name: SPIM_ITG3701_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_Init(void) 
{
    /* Initialize the Bit counter */
    SPIM_ITG3701_COUNTER_PERIOD_REG = SPIM_ITG3701_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (SPIM_ITG3701_TX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_ITG3701_TX_ISR_NUMBER,  SPIM_ITG3701_TX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_ITG3701_TX_ISR_NUMBER, &SPIM_ITG3701_TX_ISR);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (SPIM_ITG3701_RX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_ITG3701_RX_ISR_NUMBER,  SPIM_ITG3701_RX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_ITG3701_RX_ISR_NUMBER, &SPIM_ITG3701_RX_ISR);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    SPIM_ITG3701_ClearFIFO();

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
        SPIM_ITG3701_rxBufferFull  = 0u;
        SPIM_ITG3701_rxBufferRead  = 0u;
        SPIM_ITG3701_rxBufferWrite = 0u;
    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        SPIM_ITG3701_txBufferFull  = 0u;
        SPIM_ITG3701_txBufferRead  = 0u;
        SPIM_ITG3701_txBufferWrite = 0u;
    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    (void) SPIM_ITG3701_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) SPIM_ITG3701_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    SPIM_ITG3701_TX_STATUS_MASK_REG = SPIM_ITG3701_TX_INIT_INTERRUPTS_MASK;
    SPIM_ITG3701_RX_STATUS_MASK_REG = SPIM_ITG3701_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_ITG3701_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_ITG3701_COUNTER_CONTROL_REG |= SPIM_ITG3701_CNTR_ENABLE;
    SPIM_ITG3701_TX_STATUS_ACTL_REG  |= SPIM_ITG3701_INT_ENABLE;
    SPIM_ITG3701_RX_STATUS_ACTL_REG  |= SPIM_ITG3701_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_ITG3701_INTERNAL_CLOCK)
        SPIM_ITG3701_IntClock_Enable();
    #endif /* (0u != SPIM_ITG3701_INTERNAL_CLOCK) */

    SPIM_ITG3701_EnableTxInt();
    SPIM_ITG3701_EnableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_Start(void) 
{
    if(0u == SPIM_ITG3701_initVar)
    {
        SPIM_ITG3701_Init();
        SPIM_ITG3701_initVar = 1u;
    }

    SPIM_ITG3701_Enable();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void SPIM_ITG3701_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_ITG3701_TX_STATUS_ACTL_REG &= ((uint8) ~SPIM_ITG3701_INT_ENABLE);
    SPIM_ITG3701_RX_STATUS_ACTL_REG &= ((uint8) ~SPIM_ITG3701_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_ITG3701_INTERNAL_CLOCK)
        SPIM_ITG3701_IntClock_Disable();
    #endif /* (0u != SPIM_ITG3701_INTERNAL_CLOCK) */

    SPIM_ITG3701_DisableTxInt();
    SPIM_ITG3701_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_EnableTxInt(void) 
{
    #if(0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(SPIM_ITG3701_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_EnableRxInt(void) 
{
    #if(0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(SPIM_ITG3701_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_DisableTxInt(void) 
{
    #if(0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(SPIM_ITG3701_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_DisableRxInt(void) 
{
    #if(0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(SPIM_ITG3701_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_ITG3701_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_ITG3701_SetTxInterruptMode(uint8 intSrc) 
{
    SPIM_ITG3701_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_ITG3701_SetRxInterruptMode(uint8 intSrc) 
{
    SPIM_ITG3701_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  SPIM_ITG3701_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_ITG3701_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ITG3701_DisableTxInt();

        tmpStatus = SPIM_ITG3701_GET_STATUS_TX(SPIM_ITG3701_swStatusTx);
        SPIM_ITG3701_swStatusTx = 0u;

        SPIM_ITG3701_EnableTxInt();

    #else

        tmpStatus = SPIM_ITG3701_TX_STATUS_REG;

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  SPIM_ITG3701_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_ITG3701_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_ITG3701_DisableRxInt();

        tmpStatus = SPIM_ITG3701_GET_STATUS_RX(SPIM_ITG3701_swStatusRx);
        SPIM_ITG3701_swStatusRx = 0u;

        SPIM_ITG3701_EnableRxInt();

    #else

        tmpStatus = SPIM_ITG3701_RX_STATUS_REG;

    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPIM_ITG3701_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPIM_ITG3701_txBuffer[SPIM_ITG3701_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_WriteTxData(uint16 txData) 
{
    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = SPIM_ITG3701_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (SPIM_ITG3701_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == SPIM_ITG3701_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        SPIM_ITG3701_DisableTxInt();

        tempStatus = SPIM_ITG3701_GET_STATUS_TX(SPIM_ITG3701_swStatusTx);
        SPIM_ITG3701_swStatusTx = tempStatus;


        if((SPIM_ITG3701_txBufferRead == SPIM_ITG3701_txBufferWrite) &&
           (0u != (SPIM_ITG3701_swStatusTx & SPIM_ITG3701_STS_TX_FIFO_NOT_FULL)))
        {
            /* Add directly to the TX FIFO */
            CY_SET_REG16(SPIM_ITG3701_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            SPIM_ITG3701_txBufferWrite++;
            if(SPIM_ITG3701_txBufferWrite >= SPIM_ITG3701_TX_BUFFER_SIZE)
            {
                SPIM_ITG3701_txBufferWrite = 0u;
            }

            if(SPIM_ITG3701_txBufferWrite == SPIM_ITG3701_txBufferRead)
            {
                SPIM_ITG3701_txBufferRead++;
                if(SPIM_ITG3701_txBufferRead >= SPIM_ITG3701_TX_BUFFER_SIZE)
                {
                    SPIM_ITG3701_txBufferRead = 0u;
                }
                SPIM_ITG3701_txBufferFull = 1u;
            }

            SPIM_ITG3701_txBuffer[SPIM_ITG3701_txBufferWrite] = txData;

            SPIM_ITG3701_TX_STATUS_MASK_REG |= SPIM_ITG3701_STS_TX_FIFO_NOT_FULL;
        }

        SPIM_ITG3701_EnableTxInt();

    #else

        while(0u == (SPIM_ITG3701_TX_STATUS_REG & SPIM_ITG3701_STS_TX_FIFO_NOT_FULL))
        {
            ; /* Wait for room in FIFO */
        }

        /* Put byte in TX FIFO */
        CY_SET_REG16(SPIM_ITG3701_TXDATA_PTR, txData);

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  SPIM_ITG3701_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_ITG3701_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPIM_ITG3701_rxBuffer[SPIM_ITG3701_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint16 SPIM_ITG3701_ReadRxData(void) 
{
    uint16 rxData;

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_ITG3701_DisableRxInt();

        if(SPIM_ITG3701_rxBufferRead != SPIM_ITG3701_rxBufferWrite)
        {
            if(0u == SPIM_ITG3701_rxBufferFull)
            {
                SPIM_ITG3701_rxBufferRead++;
                if(SPIM_ITG3701_rxBufferRead >= SPIM_ITG3701_RX_BUFFER_SIZE)
                {
                    SPIM_ITG3701_rxBufferRead = 0u;
                }
            }
            else
            {
                SPIM_ITG3701_rxBufferFull = 0u;
            }
        }

        rxData = SPIM_ITG3701_rxBuffer[SPIM_ITG3701_rxBufferRead];

        SPIM_ITG3701_EnableRxInt();

    #else

        rxData = CY_GET_REG16(SPIM_ITG3701_RXDATA_PTR);

    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  SPIM_ITG3701_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_ITG3701_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 SPIM_ITG3701_GetRxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_ITG3701_DisableRxInt();

        if(SPIM_ITG3701_rxBufferRead == SPIM_ITG3701_rxBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_ITG3701_rxBufferRead < SPIM_ITG3701_rxBufferWrite)
        {
            size = (SPIM_ITG3701_rxBufferWrite - SPIM_ITG3701_rxBufferRead);
        }
        else
        {
            size = (SPIM_ITG3701_RX_BUFFER_SIZE - SPIM_ITG3701_rxBufferRead) + SPIM_ITG3701_rxBufferWrite;
        }

        SPIM_ITG3701_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (SPIM_ITG3701_RX_STATUS_REG & SPIM_ITG3701_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  SPIM_ITG3701_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_ITG3701_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPIM_ITG3701_GetTxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ITG3701_DisableTxInt();

        if(SPIM_ITG3701_txBufferRead == SPIM_ITG3701_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_ITG3701_txBufferRead < SPIM_ITG3701_txBufferWrite)
        {
            size = (SPIM_ITG3701_txBufferWrite - SPIM_ITG3701_txBufferRead);
        }
        else
        {
            size = (SPIM_ITG3701_TX_BUFFER_SIZE - SPIM_ITG3701_txBufferRead) + SPIM_ITG3701_txBufferWrite;
        }

        SPIM_ITG3701_EnableTxInt();

    #else

        size = SPIM_ITG3701_TX_STATUS_REG;

        if(0u != (size & SPIM_ITG3701_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & SPIM_ITG3701_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = SPIM_ITG3701_FIFO_SIZE;
        }

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPIM_ITG3701_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_ITG3701_RX_STATUS_REG & SPIM_ITG3701_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPIM_ITG3701_RXDATA_PTR);
    }

    #if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_ITG3701_DisableRxInt();

        SPIM_ITG3701_rxBufferFull  = 0u;
        SPIM_ITG3701_rxBufferRead  = 0u;
        SPIM_ITG3701_rxBufferWrite = 0u;

        SPIM_ITG3701_EnableRxInt();
    #endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPIM_ITG3701_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPIM_ITG3701_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_ITG3701_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_ITG3701_TX_FIFO_CLR);
    SPIM_ITG3701_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_ITG3701_TX_FIFO_CLR);

    #if(SPIM_ITG3701_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_ITG3701_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_ITG3701_TX_FIFO_CLR);
        SPIM_ITG3701_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_ITG3701_TX_FIFO_CLR);
    #endif /* (SPIM_ITG3701_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ITG3701_DisableTxInt();

        SPIM_ITG3701_txBufferFull  = 0u;
        SPIM_ITG3701_txBufferRead  = 0u;
        SPIM_ITG3701_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        SPIM_ITG3701_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_ITG3701_STS_TX_FIFO_NOT_FULL);

        SPIM_ITG3701_EnableTxInt();
    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != SPIM_ITG3701_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: SPIM_ITG3701_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIM_ITG3701_TxEnable(void) 
    {
        SPIM_ITG3701_CONTROL_REG |= SPIM_ITG3701_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPIM_ITG3701_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPIM_ITG3701_TxDisable(void) 
    {
        SPIM_ITG3701_CONTROL_REG &= ((uint8) ~SPIM_ITG3701_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != SPIM_ITG3701_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: SPIM_ITG3701_PutArray
********************************************************************************
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ITG3701_PutArray(const uint16 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        SPIM_ITG3701_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void SPIM_ITG3701_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_ITG3701_RX_STATUS_REG & SPIM_ITG3701_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPIM_ITG3701_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_ITG3701_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_ITG3701_TX_FIFO_CLR);
    SPIM_ITG3701_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_ITG3701_TX_FIFO_CLR);

    #if(SPIM_ITG3701_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_ITG3701_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_ITG3701_TX_FIFO_CLR);
        SPIM_ITG3701_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_ITG3701_TX_FIFO_CLR);
    #endif /* (SPIM_ITG3701_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: SPIM_ITG3701_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_EnableInt(void) 
{
    SPIM_ITG3701_EnableRxInt();
    SPIM_ITG3701_EnableTxInt();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPIM_ITG3701_DisableInt(void) 
{
    SPIM_ITG3701_DisableTxInt();
    SPIM_ITG3701_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPIM_ITG3701_SetInterruptMode(uint8 intSrc) 
{
    SPIM_ITG3701_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~SPIM_ITG3701_STS_SPI_IDLE));
    SPIM_ITG3701_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ITG3701_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  SPIM_ITG3701_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPIM_ITG3701_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED || SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)

        SPIM_ITG3701_DisableInt();

        tmpStatus  = SPIM_ITG3701_GET_STATUS_RX(SPIM_ITG3701_swStatusRx);
        tmpStatus |= SPIM_ITG3701_GET_STATUS_TX(SPIM_ITG3701_swStatusTx);
        tmpStatus &= ((uint8) ~SPIM_ITG3701_STS_SPI_IDLE);

        SPIM_ITG3701_swStatusTx = 0u;
        SPIM_ITG3701_swStatusRx = 0u;

        SPIM_ITG3701_EnableInt();

    #else

        tmpStatus  = SPIM_ITG3701_RX_STATUS_REG;
        tmpStatus |= SPIM_ITG3701_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~SPIM_ITG3701_STS_SPI_IDLE);

    #endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED || SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
