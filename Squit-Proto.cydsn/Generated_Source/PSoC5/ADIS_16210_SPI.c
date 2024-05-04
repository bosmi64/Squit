/*******************************************************************************
* File Name: ADIS_16210_SPI.c
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

#include "ADIS_16210_SPI_PVT.h"

#if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
    volatile uint16 ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_TX_BUFFER_SIZE] = {0u};
    volatile uint8 ADIS_16210_SPI_txBufferFull;
    volatile uint8 ADIS_16210_SPI_txBufferRead;
    volatile uint8 ADIS_16210_SPI_txBufferWrite;
#endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

#if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
    volatile uint16 ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_RX_BUFFER_SIZE] = {0u};
    volatile uint8 ADIS_16210_SPI_rxBufferFull;
    volatile uint8 ADIS_16210_SPI_rxBufferRead;
    volatile uint8 ADIS_16210_SPI_rxBufferWrite;
#endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

uint8 ADIS_16210_SPI_initVar = 0u;

volatile uint8 ADIS_16210_SPI_swStatusTx;
volatile uint8 ADIS_16210_SPI_swStatusRx;


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Init
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
void ADIS_16210_SPI_Init(void) 
{
    /* Initialize the Bit counter */
    ADIS_16210_SPI_COUNTER_PERIOD_REG = ADIS_16210_SPI_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (ADIS_16210_SPI_TX_ISR_NUMBER);
        CyIntSetPriority     (ADIS_16210_SPI_TX_ISR_NUMBER,  ADIS_16210_SPI_TX_ISR_PRIORITY);
        (void) CyIntSetVector(ADIS_16210_SPI_TX_ISR_NUMBER, &ADIS_16210_SPI_TX_ISR);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (ADIS_16210_SPI_RX_ISR_NUMBER);
        CyIntSetPriority     (ADIS_16210_SPI_RX_ISR_NUMBER,  ADIS_16210_SPI_RX_ISR_PRIORITY);
        (void) CyIntSetVector(ADIS_16210_SPI_RX_ISR_NUMBER, &ADIS_16210_SPI_RX_ISR);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    ADIS_16210_SPI_ClearFIFO();

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
        ADIS_16210_SPI_rxBufferFull  = 0u;
        ADIS_16210_SPI_rxBufferRead  = 0u;
        ADIS_16210_SPI_rxBufferWrite = 0u;
    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        ADIS_16210_SPI_txBufferFull  = 0u;
        ADIS_16210_SPI_txBufferRead  = 0u;
        ADIS_16210_SPI_txBufferWrite = 0u;
    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    (void) ADIS_16210_SPI_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) ADIS_16210_SPI_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    ADIS_16210_SPI_TX_STATUS_MASK_REG = ADIS_16210_SPI_TX_INIT_INTERRUPTS_MASK;
    ADIS_16210_SPI_RX_STATUS_MASK_REG = ADIS_16210_SPI_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Enable
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
void ADIS_16210_SPI_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    ADIS_16210_SPI_COUNTER_CONTROL_REG |= ADIS_16210_SPI_CNTR_ENABLE;
    ADIS_16210_SPI_TX_STATUS_ACTL_REG  |= ADIS_16210_SPI_INT_ENABLE;
    ADIS_16210_SPI_RX_STATUS_ACTL_REG  |= ADIS_16210_SPI_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != ADIS_16210_SPI_INTERNAL_CLOCK)
        ADIS_16210_SPI_IntClock_Enable();
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_CLOCK) */

    ADIS_16210_SPI_EnableTxInt();
    ADIS_16210_SPI_EnableRxInt();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Start
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
*  ADIS_16210_SPI_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADIS_16210_SPI_Start(void) 
{
    if(0u == ADIS_16210_SPI_initVar)
    {
        ADIS_16210_SPI_Init();
        ADIS_16210_SPI_initVar = 1u;
    }

    ADIS_16210_SPI_Enable();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_Stop
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
void ADIS_16210_SPI_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    ADIS_16210_SPI_TX_STATUS_ACTL_REG &= ((uint8) ~ADIS_16210_SPI_INT_ENABLE);
    ADIS_16210_SPI_RX_STATUS_ACTL_REG &= ((uint8) ~ADIS_16210_SPI_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != ADIS_16210_SPI_INTERNAL_CLOCK)
        ADIS_16210_SPI_IntClock_Disable();
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_CLOCK) */

    ADIS_16210_SPI_DisableTxInt();
    ADIS_16210_SPI_DisableRxInt();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_EnableTxInt
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
void ADIS_16210_SPI_EnableTxInt(void) 
{
    #if(0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(ADIS_16210_SPI_TX_ISR_NUMBER);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_EnableRxInt
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
void ADIS_16210_SPI_EnableRxInt(void) 
{
    #if(0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(ADIS_16210_SPI_RX_ISR_NUMBER);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_DisableTxInt
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
void ADIS_16210_SPI_DisableTxInt(void) 
{
    #if(0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(ADIS_16210_SPI_TX_ISR_NUMBER);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_DisableRxInt
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
void ADIS_16210_SPI_DisableRxInt(void) 
{
    #if(0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(ADIS_16210_SPI_RX_ISR_NUMBER);
    #endif /* (0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_SetTxInterruptMode
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
void ADIS_16210_SPI_SetTxInterruptMode(uint8 intSrc) 
{
    ADIS_16210_SPI_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_SetRxInterruptMode
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
void ADIS_16210_SPI_SetRxInterruptMode(uint8 intSrc) 
{
    ADIS_16210_SPI_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ReadTxStatus
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
*  ADIS_16210_SPI_swStatusTx - used to store in software status register,
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
uint8 ADIS_16210_SPI_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableTxInt();

        tmpStatus = ADIS_16210_SPI_GET_STATUS_TX(ADIS_16210_SPI_swStatusTx);
        ADIS_16210_SPI_swStatusTx = 0u;

        ADIS_16210_SPI_EnableTxInt();

    #else

        tmpStatus = ADIS_16210_SPI_TX_STATUS_REG;

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ReadRxStatus
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
*  ADIS_16210_SPI_swStatusRx - used to store in software Rx status register,
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
uint8 ADIS_16210_SPI_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableRxInt();

        tmpStatus = ADIS_16210_SPI_GET_STATUS_RX(ADIS_16210_SPI_swStatusRx);
        ADIS_16210_SPI_swStatusRx = 0u;

        ADIS_16210_SPI_EnableRxInt();

    #else

        tmpStatus = ADIS_16210_SPI_RX_STATUS_REG;

    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_WriteTxData
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
*  ADIS_16210_SPI_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  ADIS_16210_SPI_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_TX_BUFFER_SIZE] - used to store
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
void ADIS_16210_SPI_WriteTxData(uint16 txData) 
{
    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = ADIS_16210_SPI_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (ADIS_16210_SPI_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == ADIS_16210_SPI_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableTxInt();

        tempStatus = ADIS_16210_SPI_GET_STATUS_TX(ADIS_16210_SPI_swStatusTx);
        ADIS_16210_SPI_swStatusTx = tempStatus;


        if((ADIS_16210_SPI_txBufferRead == ADIS_16210_SPI_txBufferWrite) &&
           (0u != (ADIS_16210_SPI_swStatusTx & ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL)))
        {
            /* Add directly to the TX FIFO */
            CY_SET_REG16(ADIS_16210_SPI_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            ADIS_16210_SPI_txBufferWrite++;
            if(ADIS_16210_SPI_txBufferWrite >= ADIS_16210_SPI_TX_BUFFER_SIZE)
            {
                ADIS_16210_SPI_txBufferWrite = 0u;
            }

            if(ADIS_16210_SPI_txBufferWrite == ADIS_16210_SPI_txBufferRead)
            {
                ADIS_16210_SPI_txBufferRead++;
                if(ADIS_16210_SPI_txBufferRead >= ADIS_16210_SPI_TX_BUFFER_SIZE)
                {
                    ADIS_16210_SPI_txBufferRead = 0u;
                }
                ADIS_16210_SPI_txBufferFull = 1u;
            }

            ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_txBufferWrite] = txData;

            ADIS_16210_SPI_TX_STATUS_MASK_REG |= ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL;
        }

        ADIS_16210_SPI_EnableTxInt();

    #else

        while(0u == (ADIS_16210_SPI_TX_STATUS_REG & ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL))
        {
            ; /* Wait for room in FIFO */
        }

        /* Put byte in TX FIFO */
        CY_SET_REG16(ADIS_16210_SPI_TXDATA_PTR, txData);

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ReadRxData
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
*  ADIS_16210_SPI_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  ADIS_16210_SPI_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_RX_BUFFER_SIZE] - used to store
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
uint16 ADIS_16210_SPI_ReadRxData(void) 
{
    uint16 rxData;

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableRxInt();

        if(ADIS_16210_SPI_rxBufferRead != ADIS_16210_SPI_rxBufferWrite)
        {
            if(0u == ADIS_16210_SPI_rxBufferFull)
            {
                ADIS_16210_SPI_rxBufferRead++;
                if(ADIS_16210_SPI_rxBufferRead >= ADIS_16210_SPI_RX_BUFFER_SIZE)
                {
                    ADIS_16210_SPI_rxBufferRead = 0u;
                }
            }
            else
            {
                ADIS_16210_SPI_rxBufferFull = 0u;
            }
        }

        rxData = ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_rxBufferRead];

        ADIS_16210_SPI_EnableRxInt();

    #else

        rxData = CY_GET_REG16(ADIS_16210_SPI_RXDATA_PTR);

    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_GetRxBufferSize
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
*  ADIS_16210_SPI_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  ADIS_16210_SPI_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 ADIS_16210_SPI_GetRxBufferSize(void) 
{
    uint8 size;

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableRxInt();

        if(ADIS_16210_SPI_rxBufferRead == ADIS_16210_SPI_rxBufferWrite)
        {
            size = 0u;
        }
        else if(ADIS_16210_SPI_rxBufferRead < ADIS_16210_SPI_rxBufferWrite)
        {
            size = (ADIS_16210_SPI_rxBufferWrite - ADIS_16210_SPI_rxBufferRead);
        }
        else
        {
            size = (ADIS_16210_SPI_RX_BUFFER_SIZE - ADIS_16210_SPI_rxBufferRead) + ADIS_16210_SPI_rxBufferWrite;
        }

        ADIS_16210_SPI_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (ADIS_16210_SPI_RX_STATUS_REG & ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_GetTxBufferSize
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
*  ADIS_16210_SPI_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  ADIS_16210_SPI_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  ADIS_16210_SPI_GetTxBufferSize(void) 
{
    uint8 size;

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableTxInt();

        if(ADIS_16210_SPI_txBufferRead == ADIS_16210_SPI_txBufferWrite)
        {
            size = 0u;
        }
        else if(ADIS_16210_SPI_txBufferRead < ADIS_16210_SPI_txBufferWrite)
        {
            size = (ADIS_16210_SPI_txBufferWrite - ADIS_16210_SPI_txBufferRead);
        }
        else
        {
            size = (ADIS_16210_SPI_TX_BUFFER_SIZE - ADIS_16210_SPI_txBufferRead) + ADIS_16210_SPI_txBufferWrite;
        }

        ADIS_16210_SPI_EnableTxInt();

    #else

        size = ADIS_16210_SPI_TX_STATUS_REG;

        if(0u != (size & ADIS_16210_SPI_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = ADIS_16210_SPI_FIFO_SIZE;
        }

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ClearRxBuffer
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
*  ADIS_16210_SPI_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  ADIS_16210_SPI_rxBufferRead - used for the account of the bytes which
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
void ADIS_16210_SPI_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(ADIS_16210_SPI_RX_STATUS_REG & ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(ADIS_16210_SPI_RXDATA_PTR);
    }

    #if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableRxInt();

        ADIS_16210_SPI_rxBufferFull  = 0u;
        ADIS_16210_SPI_rxBufferRead  = 0u;
        ADIS_16210_SPI_rxBufferWrite = 0u;

        ADIS_16210_SPI_EnableRxInt();
    #endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ClearTxBuffer
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
*  ADIS_16210_SPI_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  ADIS_16210_SPI_txBufferRead - used for the account of the bytes which
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
void ADIS_16210_SPI_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    ADIS_16210_SPI_AUX_CONTROL_DP0_REG |= ((uint8)  ADIS_16210_SPI_TX_FIFO_CLR);
    ADIS_16210_SPI_AUX_CONTROL_DP0_REG &= ((uint8) ~ADIS_16210_SPI_TX_FIFO_CLR);

    #if(ADIS_16210_SPI_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        ADIS_16210_SPI_AUX_CONTROL_DP1_REG |= ((uint8)  ADIS_16210_SPI_TX_FIFO_CLR);
        ADIS_16210_SPI_AUX_CONTROL_DP1_REG &= ((uint8) ~ADIS_16210_SPI_TX_FIFO_CLR);
    #endif /* (ADIS_16210_SPI_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        ADIS_16210_SPI_DisableTxInt();

        ADIS_16210_SPI_txBufferFull  = 0u;
        ADIS_16210_SPI_txBufferRead  = 0u;
        ADIS_16210_SPI_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        ADIS_16210_SPI_TX_STATUS_MASK_REG &= ((uint8) ~ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL);

        ADIS_16210_SPI_EnableTxInt();
    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != ADIS_16210_SPI_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: ADIS_16210_SPI_TxEnable
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
    void ADIS_16210_SPI_TxEnable(void) 
    {
        ADIS_16210_SPI_CONTROL_REG |= ADIS_16210_SPI_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: ADIS_16210_SPI_TxDisable
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
    void ADIS_16210_SPI_TxDisable(void) 
    {
        ADIS_16210_SPI_CONTROL_REG &= ((uint8) ~ADIS_16210_SPI_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != ADIS_16210_SPI_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: ADIS_16210_SPI_PutArray
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
void ADIS_16210_SPI_PutArray(const uint16 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        ADIS_16210_SPI_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ClearFIFO
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
void ADIS_16210_SPI_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(ADIS_16210_SPI_RX_STATUS_REG & ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(ADIS_16210_SPI_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    ADIS_16210_SPI_AUX_CONTROL_DP0_REG |= ((uint8)  ADIS_16210_SPI_TX_FIFO_CLR);
    ADIS_16210_SPI_AUX_CONTROL_DP0_REG &= ((uint8) ~ADIS_16210_SPI_TX_FIFO_CLR);

    #if(ADIS_16210_SPI_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        ADIS_16210_SPI_AUX_CONTROL_DP1_REG |= ((uint8)  ADIS_16210_SPI_TX_FIFO_CLR);
        ADIS_16210_SPI_AUX_CONTROL_DP1_REG &= ((uint8) ~ADIS_16210_SPI_TX_FIFO_CLR);
    #endif /* (ADIS_16210_SPI_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: ADIS_16210_SPI_EnableInt
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
void ADIS_16210_SPI_EnableInt(void) 
{
    ADIS_16210_SPI_EnableRxInt();
    ADIS_16210_SPI_EnableTxInt();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_DisableInt
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
void ADIS_16210_SPI_DisableInt(void) 
{
    ADIS_16210_SPI_DisableTxInt();
    ADIS_16210_SPI_DisableRxInt();
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_SetInterruptMode
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
void ADIS_16210_SPI_SetInterruptMode(uint8 intSrc) 
{
    ADIS_16210_SPI_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~ADIS_16210_SPI_STS_SPI_IDLE));
    ADIS_16210_SPI_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: ADIS_16210_SPI_ReadStatus
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
*  ADIS_16210_SPI_swStatus - used to store in software status register,
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
uint8 ADIS_16210_SPI_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED || ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)

        ADIS_16210_SPI_DisableInt();

        tmpStatus  = ADIS_16210_SPI_GET_STATUS_RX(ADIS_16210_SPI_swStatusRx);
        tmpStatus |= ADIS_16210_SPI_GET_STATUS_TX(ADIS_16210_SPI_swStatusTx);
        tmpStatus &= ((uint8) ~ADIS_16210_SPI_STS_SPI_IDLE);

        ADIS_16210_SPI_swStatusTx = 0u;
        ADIS_16210_SPI_swStatusRx = 0u;

        ADIS_16210_SPI_EnableInt();

    #else

        tmpStatus  = ADIS_16210_SPI_RX_STATUS_REG;
        tmpStatus |= ADIS_16210_SPI_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~ADIS_16210_SPI_STS_SPI_IDLE);

    #endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED || ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
