/*******************************************************************************
* File Name: SPIM_ADXRS.c
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

#include "SPIM_ADXRS_PVT.h"

#if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPIM_ADXRS_txBuffer[SPIM_ADXRS_TX_BUFFER_SIZE] = {0u};
    volatile uint8 SPIM_ADXRS_txBufferFull;
    volatile uint8 SPIM_ADXRS_txBufferRead;
    volatile uint8 SPIM_ADXRS_txBufferWrite;
#endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPIM_ADXRS_rxBuffer[SPIM_ADXRS_RX_BUFFER_SIZE] = {0u};
    volatile uint8 SPIM_ADXRS_rxBufferFull;
    volatile uint8 SPIM_ADXRS_rxBufferRead;
    volatile uint8 SPIM_ADXRS_rxBufferWrite;
#endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

uint8 SPIM_ADXRS_initVar = 0u;

volatile uint8 SPIM_ADXRS_swStatusTx;
volatile uint8 SPIM_ADXRS_swStatusRx;


/*******************************************************************************
* Function Name: SPIM_ADXRS_Init
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
void SPIM_ADXRS_Init(void) 
{
    /* Initialize the Bit counter */
    SPIM_ADXRS_COUNTER_PERIOD_REG = SPIM_ADXRS_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (SPIM_ADXRS_TX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_ADXRS_TX_ISR_NUMBER,  SPIM_ADXRS_TX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_ADXRS_TX_ISR_NUMBER, &SPIM_ADXRS_TX_ISR);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (SPIM_ADXRS_RX_ISR_NUMBER);
        CyIntSetPriority     (SPIM_ADXRS_RX_ISR_NUMBER,  SPIM_ADXRS_RX_ISR_PRIORITY);
        (void) CyIntSetVector(SPIM_ADXRS_RX_ISR_NUMBER, &SPIM_ADXRS_RX_ISR);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    SPIM_ADXRS_ClearFIFO();

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
        SPIM_ADXRS_rxBufferFull  = 0u;
        SPIM_ADXRS_rxBufferRead  = 0u;
        SPIM_ADXRS_rxBufferWrite = 0u;
    #endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
        SPIM_ADXRS_txBufferFull  = 0u;
        SPIM_ADXRS_txBufferRead  = 0u;
        SPIM_ADXRS_txBufferWrite = 0u;
    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

    (void) SPIM_ADXRS_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) SPIM_ADXRS_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    SPIM_ADXRS_TX_STATUS_MASK_REG = SPIM_ADXRS_TX_INIT_INTERRUPTS_MASK;
    SPIM_ADXRS_RX_STATUS_MASK_REG = SPIM_ADXRS_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_Enable
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
void SPIM_ADXRS_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_ADXRS_COUNTER_CONTROL_REG |= SPIM_ADXRS_CNTR_ENABLE;
    SPIM_ADXRS_TX_STATUS_ACTL_REG  |= SPIM_ADXRS_INT_ENABLE;
    SPIM_ADXRS_RX_STATUS_ACTL_REG  |= SPIM_ADXRS_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_ADXRS_INTERNAL_CLOCK)
        SPIM_ADXRS_IntClock_Enable();
    #endif /* (0u != SPIM_ADXRS_INTERNAL_CLOCK) */

    SPIM_ADXRS_EnableTxInt();
    SPIM_ADXRS_EnableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_Start
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
*  SPIM_ADXRS_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_ADXRS_Start(void) 
{
    if(0u == SPIM_ADXRS_initVar)
    {
        SPIM_ADXRS_Init();
        SPIM_ADXRS_initVar = 1u;
    }

    SPIM_ADXRS_Enable();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_Stop
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
void SPIM_ADXRS_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPIM_ADXRS_TX_STATUS_ACTL_REG &= ((uint8) ~SPIM_ADXRS_INT_ENABLE);
    SPIM_ADXRS_RX_STATUS_ACTL_REG &= ((uint8) ~SPIM_ADXRS_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPIM_ADXRS_INTERNAL_CLOCK)
        SPIM_ADXRS_IntClock_Disable();
    #endif /* (0u != SPIM_ADXRS_INTERNAL_CLOCK) */

    SPIM_ADXRS_DisableTxInt();
    SPIM_ADXRS_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_EnableTxInt
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
void SPIM_ADXRS_EnableTxInt(void) 
{
    #if(0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(SPIM_ADXRS_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_EnableRxInt
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
void SPIM_ADXRS_EnableRxInt(void) 
{
    #if(0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(SPIM_ADXRS_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_DisableTxInt
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
void SPIM_ADXRS_DisableTxInt(void) 
{
    #if(0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(SPIM_ADXRS_TX_ISR_NUMBER);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_DisableRxInt
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
void SPIM_ADXRS_DisableRxInt(void) 
{
    #if(0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(SPIM_ADXRS_RX_ISR_NUMBER);
    #endif /* (0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_SetTxInterruptMode
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
void SPIM_ADXRS_SetTxInterruptMode(uint8 intSrc) 
{
    SPIM_ADXRS_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_SetRxInterruptMode
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
void SPIM_ADXRS_SetRxInterruptMode(uint8 intSrc) 
{
    SPIM_ADXRS_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ReadTxStatus
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
*  SPIM_ADXRS_swStatusTx - used to store in software status register,
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
uint8 SPIM_ADXRS_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ADXRS_DisableTxInt();

        tmpStatus = SPIM_ADXRS_GET_STATUS_TX(SPIM_ADXRS_swStatusTx);
        SPIM_ADXRS_swStatusTx = 0u;

        SPIM_ADXRS_EnableTxInt();

    #else

        tmpStatus = SPIM_ADXRS_TX_STATUS_REG;

    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ReadRxStatus
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
*  SPIM_ADXRS_swStatusRx - used to store in software Rx status register,
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
uint8 SPIM_ADXRS_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_ADXRS_DisableRxInt();

        tmpStatus = SPIM_ADXRS_GET_STATUS_RX(SPIM_ADXRS_swStatusRx);
        SPIM_ADXRS_swStatusRx = 0u;

        SPIM_ADXRS_EnableRxInt();

    #else

        tmpStatus = SPIM_ADXRS_RX_STATUS_REG;

    #endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_WriteTxData
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
*  SPIM_ADXRS_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPIM_ADXRS_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPIM_ADXRS_txBuffer[SPIM_ADXRS_TX_BUFFER_SIZE] - used to store
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
void SPIM_ADXRS_WriteTxData(uint16 txData) 
{
    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = SPIM_ADXRS_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (SPIM_ADXRS_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == SPIM_ADXRS_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        SPIM_ADXRS_DisableTxInt();

        tempStatus = SPIM_ADXRS_GET_STATUS_TX(SPIM_ADXRS_swStatusTx);
        SPIM_ADXRS_swStatusTx = tempStatus;


        if((SPIM_ADXRS_txBufferRead == SPIM_ADXRS_txBufferWrite) &&
           (0u != (SPIM_ADXRS_swStatusTx & SPIM_ADXRS_STS_TX_FIFO_NOT_FULL)))
        {
            /* Add directly to the TX FIFO */
            CY_SET_REG16(SPIM_ADXRS_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            SPIM_ADXRS_txBufferWrite++;
            if(SPIM_ADXRS_txBufferWrite >= SPIM_ADXRS_TX_BUFFER_SIZE)
            {
                SPIM_ADXRS_txBufferWrite = 0u;
            }

            if(SPIM_ADXRS_txBufferWrite == SPIM_ADXRS_txBufferRead)
            {
                SPIM_ADXRS_txBufferRead++;
                if(SPIM_ADXRS_txBufferRead >= SPIM_ADXRS_TX_BUFFER_SIZE)
                {
                    SPIM_ADXRS_txBufferRead = 0u;
                }
                SPIM_ADXRS_txBufferFull = 1u;
            }

            SPIM_ADXRS_txBuffer[SPIM_ADXRS_txBufferWrite] = txData;

            SPIM_ADXRS_TX_STATUS_MASK_REG |= SPIM_ADXRS_STS_TX_FIFO_NOT_FULL;
        }

        SPIM_ADXRS_EnableTxInt();

    #else

        while(0u == (SPIM_ADXRS_TX_STATUS_REG & SPIM_ADXRS_STS_TX_FIFO_NOT_FULL))
        {
            ; /* Wait for room in FIFO */
        }

        /* Put byte in TX FIFO */
        CY_SET_REG16(SPIM_ADXRS_TXDATA_PTR, txData);

    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ReadRxData
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
*  SPIM_ADXRS_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_ADXRS_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPIM_ADXRS_rxBuffer[SPIM_ADXRS_RX_BUFFER_SIZE] - used to store
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
uint16 SPIM_ADXRS_ReadRxData(void) 
{
    uint16 rxData;

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_ADXRS_DisableRxInt();

        if(SPIM_ADXRS_rxBufferRead != SPIM_ADXRS_rxBufferWrite)
        {
            if(0u == SPIM_ADXRS_rxBufferFull)
            {
                SPIM_ADXRS_rxBufferRead++;
                if(SPIM_ADXRS_rxBufferRead >= SPIM_ADXRS_RX_BUFFER_SIZE)
                {
                    SPIM_ADXRS_rxBufferRead = 0u;
                }
            }
            else
            {
                SPIM_ADXRS_rxBufferFull = 0u;
            }
        }

        rxData = SPIM_ADXRS_rxBuffer[SPIM_ADXRS_rxBufferRead];

        SPIM_ADXRS_EnableRxInt();

    #else

        rxData = CY_GET_REG16(SPIM_ADXRS_RXDATA_PTR);

    #endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_GetRxBufferSize
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
*  SPIM_ADXRS_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPIM_ADXRS_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 SPIM_ADXRS_GetRxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPIM_ADXRS_DisableRxInt();

        if(SPIM_ADXRS_rxBufferRead == SPIM_ADXRS_rxBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_ADXRS_rxBufferRead < SPIM_ADXRS_rxBufferWrite)
        {
            size = (SPIM_ADXRS_rxBufferWrite - SPIM_ADXRS_rxBufferRead);
        }
        else
        {
            size = (SPIM_ADXRS_RX_BUFFER_SIZE - SPIM_ADXRS_rxBufferRead) + SPIM_ADXRS_rxBufferWrite;
        }

        SPIM_ADXRS_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (SPIM_ADXRS_RX_STATUS_REG & SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_GetTxBufferSize
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
*  SPIM_ADXRS_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPIM_ADXRS_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPIM_ADXRS_GetTxBufferSize(void) 
{
    uint8 size;

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ADXRS_DisableTxInt();

        if(SPIM_ADXRS_txBufferRead == SPIM_ADXRS_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPIM_ADXRS_txBufferRead < SPIM_ADXRS_txBufferWrite)
        {
            size = (SPIM_ADXRS_txBufferWrite - SPIM_ADXRS_txBufferRead);
        }
        else
        {
            size = (SPIM_ADXRS_TX_BUFFER_SIZE - SPIM_ADXRS_txBufferRead) + SPIM_ADXRS_txBufferWrite;
        }

        SPIM_ADXRS_EnableTxInt();

    #else

        size = SPIM_ADXRS_TX_STATUS_REG;

        if(0u != (size & SPIM_ADXRS_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & SPIM_ADXRS_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = SPIM_ADXRS_FIFO_SIZE;
        }

    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ClearRxBuffer
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
*  SPIM_ADXRS_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPIM_ADXRS_rxBufferRead - used for the account of the bytes which
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
void SPIM_ADXRS_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_ADXRS_RX_STATUS_REG & SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPIM_ADXRS_RXDATA_PTR);
    }

    #if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPIM_ADXRS_DisableRxInt();

        SPIM_ADXRS_rxBufferFull  = 0u;
        SPIM_ADXRS_rxBufferRead  = 0u;
        SPIM_ADXRS_rxBufferWrite = 0u;

        SPIM_ADXRS_EnableRxInt();
    #endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ClearTxBuffer
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
*  SPIM_ADXRS_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPIM_ADXRS_txBufferRead - used for the account of the bytes which
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
void SPIM_ADXRS_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_ADXRS_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_ADXRS_TX_FIFO_CLR);
    SPIM_ADXRS_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_ADXRS_TX_FIFO_CLR);

    #if(SPIM_ADXRS_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_ADXRS_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_ADXRS_TX_FIFO_CLR);
        SPIM_ADXRS_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_ADXRS_TX_FIFO_CLR);
    #endif /* (SPIM_ADXRS_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPIM_ADXRS_DisableTxInt();

        SPIM_ADXRS_txBufferFull  = 0u;
        SPIM_ADXRS_txBufferRead  = 0u;
        SPIM_ADXRS_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        SPIM_ADXRS_TX_STATUS_MASK_REG &= ((uint8) ~SPIM_ADXRS_STS_TX_FIFO_NOT_FULL);

        SPIM_ADXRS_EnableTxInt();
    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != SPIM_ADXRS_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: SPIM_ADXRS_TxEnable
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
    void SPIM_ADXRS_TxEnable(void) 
    {
        SPIM_ADXRS_CONTROL_REG |= SPIM_ADXRS_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPIM_ADXRS_TxDisable
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
    void SPIM_ADXRS_TxDisable(void) 
    {
        SPIM_ADXRS_CONTROL_REG &= ((uint8) ~SPIM_ADXRS_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != SPIM_ADXRS_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: SPIM_ADXRS_PutArray
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
void SPIM_ADXRS_PutArray(const uint16 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        SPIM_ADXRS_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ClearFIFO
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
void SPIM_ADXRS_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(SPIM_ADXRS_RX_STATUS_REG & SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPIM_ADXRS_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPIM_ADXRS_AUX_CONTROL_DP0_REG |= ((uint8)  SPIM_ADXRS_TX_FIFO_CLR);
    SPIM_ADXRS_AUX_CONTROL_DP0_REG &= ((uint8) ~SPIM_ADXRS_TX_FIFO_CLR);

    #if(SPIM_ADXRS_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPIM_ADXRS_AUX_CONTROL_DP1_REG |= ((uint8)  SPIM_ADXRS_TX_FIFO_CLR);
        SPIM_ADXRS_AUX_CONTROL_DP1_REG &= ((uint8) ~SPIM_ADXRS_TX_FIFO_CLR);
    #endif /* (SPIM_ADXRS_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: SPIM_ADXRS_EnableInt
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
void SPIM_ADXRS_EnableInt(void) 
{
    SPIM_ADXRS_EnableRxInt();
    SPIM_ADXRS_EnableTxInt();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_DisableInt
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
void SPIM_ADXRS_DisableInt(void) 
{
    SPIM_ADXRS_DisableTxInt();
    SPIM_ADXRS_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_SetInterruptMode
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
void SPIM_ADXRS_SetInterruptMode(uint8 intSrc) 
{
    SPIM_ADXRS_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~SPIM_ADXRS_STS_SPI_IDLE));
    SPIM_ADXRS_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: SPIM_ADXRS_ReadStatus
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
*  SPIM_ADXRS_swStatus - used to store in software status register,
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
uint8 SPIM_ADXRS_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED || SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)

        SPIM_ADXRS_DisableInt();

        tmpStatus  = SPIM_ADXRS_GET_STATUS_RX(SPIM_ADXRS_swStatusRx);
        tmpStatus |= SPIM_ADXRS_GET_STATUS_TX(SPIM_ADXRS_swStatusTx);
        tmpStatus &= ((uint8) ~SPIM_ADXRS_STS_SPI_IDLE);

        SPIM_ADXRS_swStatusTx = 0u;
        SPIM_ADXRS_swStatusRx = 0u;

        SPIM_ADXRS_EnableInt();

    #else

        tmpStatus  = SPIM_ADXRS_RX_STATUS_REG;
        tmpStatus |= SPIM_ADXRS_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~SPIM_ADXRS_STS_SPI_IDLE);

    #endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED || SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
