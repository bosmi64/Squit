/*******************************************************************************
* File Name: UART_4D_LCD.c
* Version 2.30
*
* Description:
*  This file provides all API functionality of the UART component
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_4D_LCD.h"
#include "CyLib.h"
#if(UART_4D_LCD_INTERNAL_CLOCK_USED)
    #include "UART_4D_LCD_IntClock.h"
#endif /* End UART_4D_LCD_INTERNAL_CLOCK_USED */


/***************************************
* Global data allocation
***************************************/

uint8 UART_4D_LCD_initVar = 0u;
#if( UART_4D_LCD_TX_ENABLED && (UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
    volatile uint8 UART_4D_LCD_txBuffer[UART_4D_LCD_TXBUFFERSIZE];
    volatile uint8 UART_4D_LCD_txBufferRead = 0u;
    uint8 UART_4D_LCD_txBufferWrite = 0u;
#endif /* End UART_4D_LCD_TX_ENABLED */
#if( ( UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED ) && \
     (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH) )
    volatile uint8 UART_4D_LCD_rxBuffer[UART_4D_LCD_RXBUFFERSIZE];
    volatile uint8 UART_4D_LCD_rxBufferRead = 0u;
    volatile uint8 UART_4D_LCD_rxBufferWrite = 0u;
    volatile uint8 UART_4D_LCD_rxBufferLoopDetect = 0u;
    volatile uint8 UART_4D_LCD_rxBufferOverflow = 0u;
    #if (UART_4D_LCD_RXHW_ADDRESS_ENABLED)
        volatile uint8 UART_4D_LCD_rxAddressMode = UART_4D_LCD_RXADDRESSMODE;
        volatile uint8 UART_4D_LCD_rxAddressDetected = 0u;
    #endif /* End EnableHWAddress */
#endif /* End UART_4D_LCD_RX_ENABLED */


/*******************************************************************************
* Function Name: UART_4D_LCD_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the UART component.
*  Enable the clock input to enable operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The UART_4D_LCD_intiVar variable is used to indicate initial
*  configuration of this component. The variable is initialized to zero (0u)
*  and set to one (1u) the first time UART_Start() is called. This allows for
*  component initialization without re-initialization in all subsequent calls
*  to the UART_4D_LCD_Start() routine.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void UART_4D_LCD_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(UART_4D_LCD_initVar == 0u)
    {
        UART_4D_LCD_Init();
        UART_4D_LCD_initVar = 1u;
    }
    UART_4D_LCD_Enable();
}


/*******************************************************************************
* Function Name: UART_4D_LCD_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  UART_4D_LCD_Start().
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void UART_4D_LCD_Init(void) 
{
    #if(UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED)

        #if(UART_4D_LCD_RX_INTERRUPT_ENABLED && (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            /* Set the RX Interrupt. */
            (void)CyIntSetVector(UART_4D_LCD_RX_VECT_NUM, &UART_4D_LCD_RXISR);
            CyIntSetPriority(UART_4D_LCD_RX_VECT_NUM, UART_4D_LCD_RX_PRIOR_NUM);
        #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */

        #if (UART_4D_LCD_RXHW_ADDRESS_ENABLED)
            UART_4D_LCD_SetRxAddressMode(UART_4D_LCD_RXAddressMode);
            UART_4D_LCD_SetRxAddress1(UART_4D_LCD_RXHWADDRESS1);
            UART_4D_LCD_SetRxAddress2(UART_4D_LCD_RXHWADDRESS2);
        #endif /* End UART_4D_LCD_RXHW_ADDRESS_ENABLED */

        /* Init Count7 period */
        UART_4D_LCD_RXBITCTR_PERIOD_REG = UART_4D_LCD_RXBITCTR_INIT;
        /* Configure the Initial RX interrupt mask */
        UART_4D_LCD_RXSTATUS_MASK_REG  = UART_4D_LCD_INIT_RX_INTERRUPTS_MASK;
    #endif /* End UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED*/

    #if(UART_4D_LCD_TX_ENABLED)
        #if(UART_4D_LCD_TX_INTERRUPT_ENABLED && (UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            /* Set the TX Interrupt. */
            (void)CyIntSetVector(UART_4D_LCD_TX_VECT_NUM, &UART_4D_LCD_TXISR);
            CyIntSetPriority(UART_4D_LCD_TX_VECT_NUM, UART_4D_LCD_TX_PRIOR_NUM);
        #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

        /* Write Counter Value for TX Bit Clk Generator*/
        #if(UART_4D_LCD_TXCLKGEN_DP)
            UART_4D_LCD_TXBITCLKGEN_CTR_REG = UART_4D_LCD_BIT_CENTER;
            UART_4D_LCD_TXBITCLKTX_COMPLETE_REG = (UART_4D_LCD_NUMBER_OF_DATA_BITS +
                        UART_4D_LCD_NUMBER_OF_START_BIT) * UART_4D_LCD_OVER_SAMPLE_COUNT;
        #else
            UART_4D_LCD_TXBITCTR_PERIOD_REG = ((UART_4D_LCD_NUMBER_OF_DATA_BITS +
                        UART_4D_LCD_NUMBER_OF_START_BIT) * UART_4D_LCD_OVER_SAMPLE_8) - 1u;
        #endif /* End UART_4D_LCD_TXCLKGEN_DP */

        /* Configure the Initial TX interrupt mask */
        #if(UART_4D_LCD_TX_INTERRUPT_ENABLED && (UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            UART_4D_LCD_TXSTATUS_MASK_REG = UART_4D_LCD_TX_STS_FIFO_EMPTY;
        #else
            UART_4D_LCD_TXSTATUS_MASK_REG = UART_4D_LCD_INIT_TX_INTERRUPTS_MASK;
        #endif /*End UART_4D_LCD_TX_INTERRUPT_ENABLED*/

    #endif /* End UART_4D_LCD_TX_ENABLED */

    #if(UART_4D_LCD_PARITY_TYPE_SW)  /* Write Parity to Control Register */
        UART_4D_LCD_WriteControlRegister( \
            (UART_4D_LCD_ReadControlRegister() & (uint8)~UART_4D_LCD_CTRL_PARITY_TYPE_MASK) | \
            (uint8)(UART_4D_LCD_PARITY_TYPE << UART_4D_LCD_CTRL_PARITY_TYPE0_SHIFT) );
    #endif /* End UART_4D_LCD_PARITY_TYPE_SW */
}


/*******************************************************************************
* Function Name: UART_4D_LCD_Enable
********************************************************************************
*
* Summary:
*  Enables the UART block operation
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  UART_4D_LCD_rxAddressDetected - set to initial state (0).
*
*******************************************************************************/
void UART_4D_LCD_Enable(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    #if(UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED)
        /*RX Counter (Count7) Enable */
        UART_4D_LCD_RXBITCTR_CONTROL_REG |= UART_4D_LCD_CNTR_ENABLE;
        /* Enable the RX Interrupt. */
        UART_4D_LCD_RXSTATUS_ACTL_REG  |= UART_4D_LCD_INT_ENABLE;
        #if(UART_4D_LCD_RX_INTERRUPT_ENABLED && (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            CyIntEnable(UART_4D_LCD_RX_VECT_NUM);
            #if (UART_4D_LCD_RXHW_ADDRESS_ENABLED)
                UART_4D_LCD_rxAddressDetected = 0u;
            #endif /* End UART_4D_LCD_RXHW_ADDRESS_ENABLED */
        #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */
    #endif /* End UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED*/

    #if(UART_4D_LCD_TX_ENABLED)
        /*TX Counter (DP/Count7) Enable */
        #if(!UART_4D_LCD_TXCLKGEN_DP)
            UART_4D_LCD_TXBITCTR_CONTROL_REG |= UART_4D_LCD_CNTR_ENABLE;
        #endif /* End UART_4D_LCD_TXCLKGEN_DP */
        /* Enable the TX Interrupt. */
        UART_4D_LCD_TXSTATUS_ACTL_REG |= UART_4D_LCD_INT_ENABLE;
        #if(UART_4D_LCD_TX_INTERRUPT_ENABLED && (UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            CyIntEnable(UART_4D_LCD_TX_VECT_NUM);
        #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED*/
     #endif /* End UART_4D_LCD_TX_ENABLED */

    #if(UART_4D_LCD_INTERNAL_CLOCK_USED)
        /* Enable the clock. */
        UART_4D_LCD_IntClock_Start();
    #endif /* End UART_4D_LCD_INTERNAL_CLOCK_USED */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UART_4D_LCD_Stop
********************************************************************************
*
* Summary:
*  Disable the UART component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void UART_4D_LCD_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Write Bit Counter Disable */
    #if(UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED)
        UART_4D_LCD_RXBITCTR_CONTROL_REG &= (uint8)~UART_4D_LCD_CNTR_ENABLE;
    #endif /* End UART_4D_LCD_RX_ENABLED */

    #if(UART_4D_LCD_TX_ENABLED)
        #if(!UART_4D_LCD_TXCLKGEN_DP)
            UART_4D_LCD_TXBITCTR_CONTROL_REG &= (uint8)~UART_4D_LCD_CNTR_ENABLE;
        #endif /* End UART_4D_LCD_TXCLKGEN_DP */
    #endif /* UART_4D_LCD_TX_ENABLED */

    #if(UART_4D_LCD_INTERNAL_CLOCK_USED)
        /* Disable the clock. */
        UART_4D_LCD_IntClock_Stop();
    #endif /* End UART_4D_LCD_INTERNAL_CLOCK_USED */

    /* Disable internal interrupt component */
    #if(UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED)
        UART_4D_LCD_RXSTATUS_ACTL_REG  &= (uint8)~UART_4D_LCD_INT_ENABLE;
        #if(UART_4D_LCD_RX_INTERRUPT_ENABLED && (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            UART_4D_LCD_DisableRxInt();
        #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */
    #endif /* End UART_4D_LCD_RX_ENABLED */

    #if(UART_4D_LCD_TX_ENABLED)
        UART_4D_LCD_TXSTATUS_ACTL_REG &= (uint8)~UART_4D_LCD_INT_ENABLE;
        #if(UART_4D_LCD_TX_INTERRUPT_ENABLED && (UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            UART_4D_LCD_DisableTxInt();
        #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */
    #endif /* End UART_4D_LCD_TX_ENABLED */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: UART_4D_LCD_ReadControlRegister
********************************************************************************
*
* Summary:
*  Read the current state of the control register
*
* Parameters:
*  None.
*
* Return:
*  Current state of the control register.
*
*******************************************************************************/
uint8 UART_4D_LCD_ReadControlRegister(void) 
{
    #if( UART_4D_LCD_CONTROL_REG_REMOVED )
        return(0u);
    #else
        return(UART_4D_LCD_CONTROL_REG);
    #endif /* End UART_4D_LCD_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: UART_4D_LCD_WriteControlRegister
********************************************************************************
*
* Summary:
*  Writes an 8-bit value into the control register
*
* Parameters:
*  control:  control register value
*
* Return:
*  None.
*
*******************************************************************************/
void  UART_4D_LCD_WriteControlRegister(uint8 control) 
{
    #if( UART_4D_LCD_CONTROL_REG_REMOVED )
        if(control != 0u) { }      /* release compiler warning */
    #else
       UART_4D_LCD_CONTROL_REG = control;
    #endif /* End UART_4D_LCD_CONTROL_REG_REMOVED */
}


#if(UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED)

    #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)

        /*******************************************************************************
        * Function Name: UART_4D_LCD_EnableRxInt
        ********************************************************************************
        *
        * Summary:
        *  Enable RX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Enable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void UART_4D_LCD_EnableRxInt(void) 
        {
            CyIntEnable(UART_4D_LCD_RX_VECT_NUM);
        }


        /*******************************************************************************
        * Function Name: UART_4D_LCD_DisableRxInt
        ********************************************************************************
        *
        * Summary:
        *  Disable RX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Disable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void UART_4D_LCD_DisableRxInt(void) 
        {
            CyIntDisable(UART_4D_LCD_RX_VECT_NUM);
        }

    #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetRxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configure which status bits trigger an interrupt event
    *
    * Parameters:
    *  IntSrc:  An or'd combination of the desired status bit masks (defined in
    *           the header file)
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void UART_4D_LCD_SetRxInterruptMode(uint8 intSrc) 
    {
        UART_4D_LCD_RXSTATUS_MASK_REG  = intSrc;
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_ReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Returns data in RX Data register without checking status register to
    *  determine if data is valid
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Received data from RX register
    *
    * Global Variables:
    *  UART_4D_LCD_rxBuffer - RAM buffer pointer for save received data.
    *  UART_4D_LCD_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  UART_4D_LCD_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  UART_4D_LCD_rxBufferLoopDetect - creared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_ReadRxData(void) 
    {
        uint8 rxData;

        #if(UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)
            uint8 loc_rxBufferRead;
            uint8 loc_rxBufferWrite;
            /* Protect variables that could change on interrupt. */
            /* Disable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableRxInt();
            #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */
            loc_rxBufferRead = UART_4D_LCD_rxBufferRead;
            loc_rxBufferWrite = UART_4D_LCD_rxBufferWrite;

            if( (UART_4D_LCD_rxBufferLoopDetect != 0u) || (loc_rxBufferRead != loc_rxBufferWrite) )
            {
                rxData = UART_4D_LCD_rxBuffer[loc_rxBufferRead];
                loc_rxBufferRead++;

                if(loc_rxBufferRead >= UART_4D_LCD_RXBUFFERSIZE)
                {
                    loc_rxBufferRead = 0u;
                }
                /* Update the real pointer */
                UART_4D_LCD_rxBufferRead = loc_rxBufferRead;

                if(UART_4D_LCD_rxBufferLoopDetect != 0u )
                {
                    UART_4D_LCD_rxBufferLoopDetect = 0u;
                    #if( (UART_4D_LCD_RX_INTERRUPT_ENABLED) && (UART_4D_LCD_FLOW_CONTROL != 0u) && \
                         (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH) )
                        /* When Hardware Flow Control selected - return RX mask */
                        #if( UART_4D_LCD_HD_ENABLED )
                            if((UART_4D_LCD_CONTROL_REG & UART_4D_LCD_CTRL_HD_SEND) == 0u)
                            {   /* In Half duplex mode return RX mask only in RX
                                *  configuration set, otherwise
                                *  mask will be returned in LoadRxConfig() API.
                                */
                                UART_4D_LCD_RXSTATUS_MASK_REG  |= UART_4D_LCD_RX_STS_FIFO_NOTEMPTY;
                            }
                        #else
                            UART_4D_LCD_RXSTATUS_MASK_REG  |= UART_4D_LCD_RX_STS_FIFO_NOTEMPTY;
                        #endif /* end UART_4D_LCD_HD_ENABLED */
                    #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED and Hardware flow control*/
                }
            }
            else
            {   /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit*/
                rxData = UART_4D_LCD_RXDATA_REG;
            }

            /* Enable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableRxInt();
            #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */

        #else /* UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

            /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit*/
            rxData = UART_4D_LCD_RXDATA_REG;

        #endif /* UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_ReadRxStatus
    ********************************************************************************
    *
    * Summary:
    *  Read the current state of the status register
    *  And detect software buffer overflow.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Current state of the status register.
    *
    * Global Variables:
    *  UART_4D_LCD_rxBufferOverflow - used to indicate overload condition.
    *   It set to one in RX interrupt when there isn?t free space in
    *   UART_4D_LCD_rxBufferRead to write new data. This condition returned
    *   and cleared to zero by this API as an
    *   UART_4D_LCD_RX_STS_SOFT_BUFF_OVER bit along with RX Status register
    *   bits.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_ReadRxStatus(void) 
    {
        uint8 status;

        status = UART_4D_LCD_RXSTATUS_REG & UART_4D_LCD_RX_HW_MASK;

        #if(UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)
            if( UART_4D_LCD_rxBufferOverflow != 0u )
            {
                status |= UART_4D_LCD_RX_STS_SOFT_BUFF_OVER;
                UART_4D_LCD_rxBufferOverflow = 0u;
            }
        #endif /* UART_4D_LCD_RXBUFFERSIZE */

        return(status);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_GetChar
    ********************************************************************************
    *
    * Summary:
    *  Reads UART RX buffer immediately, if data is not available or an error
    *  condition exists, zero is returned; otherwise, character is read and
    *  returned.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Character read from UART RX buffer. ASCII characters from 1 to 255 are valid.
    *  A returned zero signifies an error condition or no data available.
    *
    * Global Variables:
    *  UART_4D_LCD_rxBuffer - RAM buffer pointer for save received data.
    *  UART_4D_LCD_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  UART_4D_LCD_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  UART_4D_LCD_rxBufferLoopDetect - creared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_GetChar(void) 
    {
        uint8 rxData = 0u;
        uint8 rxStatus;

        #if(UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)
            uint8 loc_rxBufferRead;
            uint8 loc_rxBufferWrite;
            /* Protect variables that could change on interrupt. */
            /* Disable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableRxInt();
            #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */
            loc_rxBufferRead = UART_4D_LCD_rxBufferRead;
            loc_rxBufferWrite = UART_4D_LCD_rxBufferWrite;

            if( (UART_4D_LCD_rxBufferLoopDetect != 0u) || (loc_rxBufferRead != loc_rxBufferWrite) )
            {
                rxData = UART_4D_LCD_rxBuffer[loc_rxBufferRead];
                loc_rxBufferRead++;
                if(loc_rxBufferRead >= UART_4D_LCD_RXBUFFERSIZE)
                {
                    loc_rxBufferRead = 0u;
                }
                /* Update the real pointer */
                UART_4D_LCD_rxBufferRead = loc_rxBufferRead;

                if(UART_4D_LCD_rxBufferLoopDetect > 0u )
                {
                    UART_4D_LCD_rxBufferLoopDetect = 0u;
                    #if( (UART_4D_LCD_RX_INTERRUPT_ENABLED) && (UART_4D_LCD_FLOW_CONTROL != 0u) )
                        /* When Hardware Flow Control selected - return RX mask */
                        #if( UART_4D_LCD_HD_ENABLED )
                            if((UART_4D_LCD_CONTROL_REG & UART_4D_LCD_CTRL_HD_SEND) == 0u)
                            {   /* In Half duplex mode return RX mask only if
                                *  RX configuration set, otherwise
                                *  mask will be returned in LoadRxConfig() API.
                                */
                                UART_4D_LCD_RXSTATUS_MASK_REG  |= UART_4D_LCD_RX_STS_FIFO_NOTEMPTY;
                            }
                        #else
                            UART_4D_LCD_RXSTATUS_MASK_REG  |= UART_4D_LCD_RX_STS_FIFO_NOTEMPTY;
                        #endif /* end UART_4D_LCD_HD_ENABLED */
                    #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED and Hardware flow control*/
                }

            }
            else
            {   rxStatus = UART_4D_LCD_RXSTATUS_REG;
                if((rxStatus & UART_4D_LCD_RX_STS_FIFO_NOTEMPTY) != 0u)
                {   /* Read received data from FIFO*/
                    rxData = UART_4D_LCD_RXDATA_REG;
                    /*Check status on error*/
                    if((rxStatus & (UART_4D_LCD_RX_STS_BREAK | UART_4D_LCD_RX_STS_PAR_ERROR |
                                   UART_4D_LCD_RX_STS_STOP_ERROR | UART_4D_LCD_RX_STS_OVERRUN)) != 0u)
                    {
                        rxData = 0u;
                    }
                }
            }

            /* Enable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableRxInt();
            #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */

        #else /* UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

            rxStatus =UART_4D_LCD_RXSTATUS_REG;
            if((rxStatus & UART_4D_LCD_RX_STS_FIFO_NOTEMPTY) != 0u)
            {   /* Read received data from FIFO*/
                rxData = UART_4D_LCD_RXDATA_REG;
                /*Check status on error*/
                if((rxStatus & (UART_4D_LCD_RX_STS_BREAK | UART_4D_LCD_RX_STS_PAR_ERROR |
                               UART_4D_LCD_RX_STS_STOP_ERROR | UART_4D_LCD_RX_STS_OVERRUN)) != 0u)
                {
                    rxData = 0u;
                }
            }
        #endif /* UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_GetByte
    ********************************************************************************
    *
    * Summary:
    *  Grab the next available byte of data from the recieve FIFO
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  MSB contains Status Register and LSB contains UART RX data
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 UART_4D_LCD_GetByte(void) 
    {
        return ( ((uint16)UART_4D_LCD_ReadRxStatus() << 8u) | UART_4D_LCD_ReadRxData() );
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_GetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Determine the amount of bytes left in the RX buffer and return the count in
    *  bytes
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  uint8: Integer count of the number of bytes left
    *  in the RX buffer
    *
    * Global Variables:
    *  UART_4D_LCD_rxBufferWrite - used to calculate left bytes.
    *  UART_4D_LCD_rxBufferRead - used to calculate left bytes.
    *  UART_4D_LCD_rxBufferLoopDetect - checked to decide left bytes amount.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the RX Buffer is.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_GetRxBufferSize(void)
                                                            
    {
        uint8 size;

        #if(UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)

            /* Disable Rx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableRxInt();
            #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */

            if(UART_4D_LCD_rxBufferRead == UART_4D_LCD_rxBufferWrite)
            {
                if(UART_4D_LCD_rxBufferLoopDetect > 0u)
                {
                    size = UART_4D_LCD_RXBUFFERSIZE;
                }
                else
                {
                    size = 0u;
                }
            }
            else if(UART_4D_LCD_rxBufferRead < UART_4D_LCD_rxBufferWrite)
            {
                size = (UART_4D_LCD_rxBufferWrite - UART_4D_LCD_rxBufferRead);
            }
            else
            {
                size = (UART_4D_LCD_RXBUFFERSIZE - UART_4D_LCD_rxBufferRead) + UART_4D_LCD_rxBufferWrite;
            }

            /* Enable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableRxInt();
            #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */

        #else /* UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

            /* We can only know if there is data in the fifo. */
            size = ((UART_4D_LCD_RXSTATUS_REG & UART_4D_LCD_RX_STS_FIFO_NOTEMPTY) != 0u) ? 1u : 0u;

        #endif /* End UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

        return(size);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_ClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the RX RAM buffer by setting the read and write pointers both to zero.
    *  Clears hardware RX FIFO.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_rxBufferWrite - cleared to zero.
    *  UART_4D_LCD_rxBufferRead - cleared to zero.
    *  UART_4D_LCD_rxBufferLoopDetect - cleared to zero.
    *  UART_4D_LCD_rxBufferOverflow - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may
    *  have remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM or FIFO buffer will be lost.
    *******************************************************************************/
    void UART_4D_LCD_ClearRxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* clear the HW FIFO */
        /* Enter critical section */
        enableInterrupts = CyEnterCriticalSection();
        UART_4D_LCD_RXDATA_AUX_CTL_REG |=  UART_4D_LCD_RX_FIFO_CLR;
        UART_4D_LCD_RXDATA_AUX_CTL_REG &= (uint8)~UART_4D_LCD_RX_FIFO_CLR;
        /* Exit critical section */
        CyExitCriticalSection(enableInterrupts);

        #if(UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)
            /* Disable Rx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableRxInt();
            #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */

            UART_4D_LCD_rxBufferRead = 0u;
            UART_4D_LCD_rxBufferWrite = 0u;
            UART_4D_LCD_rxBufferLoopDetect = 0u;
            UART_4D_LCD_rxBufferOverflow = 0u;

            /* Enable Rx interrupt. */
            #if(UART_4D_LCD_RX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableRxInt();
            #endif /* End UART_4D_LCD_RX_INTERRUPT_ENABLED */
        #endif /* End UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetRxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Set the receive addressing mode
    *
    * Parameters:
    *  addressMode: Enumerated value indicating the mode of RX addressing
    *  UART_4D_LCD__B_UART__AM_SW_BYTE_BYTE -  Software Byte-by-Byte address
    *                                               detection
    *  UART_4D_LCD__B_UART__AM_SW_DETECT_TO_BUFFER - Software Detect to Buffer
    *                                               address detection
    *  UART_4D_LCD__B_UART__AM_HW_BYTE_BY_BYTE - Hardware Byte-by-Byte address
    *                                               detection
    *  UART_4D_LCD__B_UART__AM_HW_DETECT_TO_BUFFER - Hardware Detect to Buffer
    *                                               address detection
    *  UART_4D_LCD__B_UART__AM_NONE - No address detection
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_rxAddressMode - the parameter stored in this variable for
    *   the farther usage in RX ISR.
    *  UART_4D_LCD_rxAddressDetected - set to initial state (0).
    *
    *******************************************************************************/
    void UART_4D_LCD_SetRxAddressMode(uint8 addressMode)
                                                        
    {
        #if(UART_4D_LCD_RXHW_ADDRESS_ENABLED)
            #if(UART_4D_LCD_CONTROL_REG_REMOVED)
                if(addressMode != 0u) { }     /* release compiler warning */
            #else /* UART_4D_LCD_CONTROL_REG_REMOVED */
                uint8 tmpCtrl;
                tmpCtrl = UART_4D_LCD_CONTROL_REG & (uint8)~UART_4D_LCD_CTRL_RXADDR_MODE_MASK;
                tmpCtrl |= (uint8)(addressMode << UART_4D_LCD_CTRL_RXADDR_MODE0_SHIFT);
                UART_4D_LCD_CONTROL_REG = tmpCtrl;
                #if(UART_4D_LCD_RX_INTERRUPT_ENABLED && \
                   (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH) )
                    UART_4D_LCD_rxAddressMode = addressMode;
                    UART_4D_LCD_rxAddressDetected = 0u;
                #endif /* End UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH*/
            #endif /* End UART_4D_LCD_CONTROL_REG_REMOVED */
        #else /* UART_4D_LCD_RXHW_ADDRESS_ENABLED */
            if(addressMode != 0u) { }     /* release compiler warning */
        #endif /* End UART_4D_LCD_RXHW_ADDRESS_ENABLED */
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetRxAddress1
    ********************************************************************************
    *
    * Summary:
    *  Set the first hardware address compare value
    *
    * Parameters:
    *  address
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void UART_4D_LCD_SetRxAddress1(uint8 address) 

    {
        UART_4D_LCD_RXADDRESS1_REG = address;
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetRxAddress2
    ********************************************************************************
    *
    * Summary:
    *  Set the second hardware address compare value
    *
    * Parameters:
    *  address
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void UART_4D_LCD_SetRxAddress2(uint8 address) 
    {
        UART_4D_LCD_RXADDRESS2_REG = address;
    }

#endif  /* UART_4D_LCD_RX_ENABLED || UART_4D_LCD_HD_ENABLED*/


#if( (UART_4D_LCD_TX_ENABLED) || (UART_4D_LCD_HD_ENABLED) )

    #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)

        /*******************************************************************************
        * Function Name: UART_4D_LCD_EnableTxInt
        ********************************************************************************
        *
        * Summary:
        *  Enable TX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Enable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void UART_4D_LCD_EnableTxInt(void) 
        {
            CyIntEnable(UART_4D_LCD_TX_VECT_NUM);
        }


        /*******************************************************************************
        * Function Name: UART_4D_LCD_DisableTxInt
        ********************************************************************************
        *
        * Summary:
        *  Disable TX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Disable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void UART_4D_LCD_DisableTxInt(void) 
        {
            CyIntDisable(UART_4D_LCD_TX_VECT_NUM);
        }

    #endif /* UART_4D_LCD_TX_INTERRUPT_ENABLED */


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetTxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configure which status bits trigger an interrupt event
    *
    * Parameters:
    *  intSrc: An or'd combination of the desired status bit masks (defined in
    *          the header file)
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void UART_4D_LCD_SetTxInterruptMode(uint8 intSrc) 
    {
        UART_4D_LCD_TXSTATUS_MASK_REG = intSrc;
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_WriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Write a byte of data to the Transmit FIFO or TX buffer to be sent when the
    *  bus is available. WriteTxData sends a byte without checking for buffer room
    *  or status. It is up to the user to separately check status.
    *
    * Parameters:
    *  TXDataByte: byte of data to place in the transmit FIFO
    *
    * Return:
    * void
    *
    * Global Variables:
    *  UART_4D_LCD_txBuffer - RAM buffer pointer for save data for transmission
    *  UART_4D_LCD_txBufferWrite - cyclic index for write to txBuffer,
    *    incremented after each byte saved to buffer.
    *  UART_4D_LCD_txBufferRead - cyclic index for read from txBuffer,
    *    checked to identify the condition to write to FIFO directly or to TX buffer
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *    initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void UART_4D_LCD_WriteTxData(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(UART_4D_LCD_initVar != 0u)
        {
            #if(UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)

                /* Disable Tx interrupt. */
                /* Protect variables that could change on interrupt. */
                #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                    UART_4D_LCD_DisableTxInt();
                #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

                if( (UART_4D_LCD_txBufferRead == UART_4D_LCD_txBufferWrite) &&
                    ((UART_4D_LCD_TXSTATUS_REG & UART_4D_LCD_TX_STS_FIFO_FULL) == 0u) )
                {
                    /* Add directly to the FIFO. */
                    UART_4D_LCD_TXDATA_REG = txDataByte;
                }
                else
                {
                    if(UART_4D_LCD_txBufferWrite >= UART_4D_LCD_TXBUFFERSIZE)
                    {
                        UART_4D_LCD_txBufferWrite = 0u;
                    }

                    UART_4D_LCD_txBuffer[UART_4D_LCD_txBufferWrite] = txDataByte;

                    /* Add to the software buffer. */
                    UART_4D_LCD_txBufferWrite++;

                }

                /* Enable Tx interrupt. */
                #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                    UART_4D_LCD_EnableTxInt();
                #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

            #else /* UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

                /* Add directly to the FIFO. */
                UART_4D_LCD_TXDATA_REG = txDataByte;

            #endif /* End UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */
        }
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_ReadTxStatus
    ********************************************************************************
    *
    * Summary:
    *  Read the status register for the component
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Contents of the status register
    *
    * Theory:
    *  This function reads the status register which is clear on read. It is up to
    *  the user to handle all bits in this return value accordingly, even if the bit
    *  was not enabled as an interrupt source the event happened and must be handled
    *  accordingly.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_ReadTxStatus(void) 
    {
        return(UART_4D_LCD_TXSTATUS_REG);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_PutChar
    ********************************************************************************
    *
    * Summary:
    *  Wait to send byte until TX register or buffer has room.
    *
    * Parameters:
    *  txDataByte: The 8-bit data value to send across the UART.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_txBuffer - RAM buffer pointer for save data for transmission
    *  UART_4D_LCD_txBufferWrite - cyclic index for write to txBuffer,
    *     checked to identify free space in txBuffer and incremented after each byte
    *     saved to buffer.
    *  UART_4D_LCD_txBufferRead - cyclic index for read from txBuffer,
    *     checked to identify free space in txBuffer.
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer
    *
    *******************************************************************************/
    void UART_4D_LCD_PutChar(uint8 txDataByte) 
    {
            #if(UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)
                /* The temporary output pointer is used since it takes two instructions
                *  to increment with a wrap, and we can't risk doing that with the real
                *  pointer and getting an interrupt in between instructions.
                */
                uint8 loc_txBufferWrite;
                uint8 loc_txBufferRead;

                do{
                    /* Block if software buffer is full, so we don't overwrite. */
                    #if ((UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_MAX_BYTE_VALUE) && (CY_PSOC3))
                        /* Disable TX interrupt to protect variables that could change on interrupt */
                        CyIntDisable(UART_4D_LCD_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                    loc_txBufferWrite = UART_4D_LCD_txBufferWrite;
                    loc_txBufferRead = UART_4D_LCD_txBufferRead;
                    #if ((UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_MAX_BYTE_VALUE) && (CY_PSOC3))
                        /* Enable interrupt to continue transmission */
                        CyIntEnable(UART_4D_LCD_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                }while( (loc_txBufferWrite < loc_txBufferRead) ? (loc_txBufferWrite == (loc_txBufferRead - 1u)) :
                                        ((loc_txBufferWrite - loc_txBufferRead) ==
                                        (uint8)(UART_4D_LCD_TXBUFFERSIZE - 1u)) );

                if( (loc_txBufferRead == loc_txBufferWrite) &&
                    ((UART_4D_LCD_TXSTATUS_REG & UART_4D_LCD_TX_STS_FIFO_FULL) == 0u) )
                {
                    /* Add directly to the FIFO. */
                    UART_4D_LCD_TXDATA_REG = txDataByte;
                }
                else
                {
                    if(loc_txBufferWrite >= UART_4D_LCD_TXBUFFERSIZE)
                    {
                        loc_txBufferWrite = 0u;
                    }
                    /* Add to the software buffer. */
                    UART_4D_LCD_txBuffer[loc_txBufferWrite] = txDataByte;
                    loc_txBufferWrite++;

                    /* Finally, update the real output pointer */
                    #if ((UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_MAX_BYTE_VALUE) && (CY_PSOC3))
                        CyIntDisable(UART_4D_LCD_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                    UART_4D_LCD_txBufferWrite = loc_txBufferWrite;
                    #if ((UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_MAX_BYTE_VALUE) && (CY_PSOC3))
                        CyIntEnable(UART_4D_LCD_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                }

            #else /* UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

                while((UART_4D_LCD_TXSTATUS_REG & UART_4D_LCD_TX_STS_FIFO_FULL) != 0u)
                {
                    ; /* Wait for room in the FIFO. */
                }

                /* Add directly to the FIFO. */
                UART_4D_LCD_TXDATA_REG = txDataByte;

            #endif /* End UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_PutString
    ********************************************************************************
    *
    * Summary:
    *  Write a Sequence of bytes on the Transmit line. Data comes from RAM or ROM.
    *
    * Parameters:
    *  string: char pointer to character string of Data to Send.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  This function will block if there is not enough memory to place the whole
    *  string, it will block until the entire string has been written to the
    *  transmit buffer.
    *
    *******************************************************************************/
    void UART_4D_LCD_PutString(const char8 string[]) 
    {
        uint16 buf_index = 0u;
        /* If not Initialized then skip this function*/
        if(UART_4D_LCD_initVar != 0u)
        {
            /* This is a blocking function, it will not exit until all data is sent*/
            while(string[buf_index] != (char8)0)
            {
                UART_4D_LCD_PutChar((uint8)string[buf_index]);
                buf_index++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_PutArray
    ********************************************************************************
    *
    * Summary:
    *  Write a Sequence of bytes on the Transmit line. Data comes from RAM or ROM.
    *
    * Parameters:
    *  string: Address of the memory array residing in RAM or ROM.
    *  byteCount: Number of Bytes to be transmitted.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void UART_4D_LCD_PutArray(const uint8 string[], uint8 byteCount)
                                                                    
    {
        uint8 buf_index = 0u;
        /* If not Initialized then skip this function*/
        if(UART_4D_LCD_initVar != 0u)
        {
            do
            {
                UART_4D_LCD_PutChar(string[buf_index]);
                buf_index++;
            }while(buf_index < byteCount);
        }
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_PutCRLF
    ********************************************************************************
    *
    * Summary:
    *  Write a character and then carriage return and line feed.
    *
    * Parameters:
    *  txDataByte: uint8 Character to send.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void UART_4D_LCD_PutCRLF(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(UART_4D_LCD_initVar != 0u)
        {
            UART_4D_LCD_PutChar(txDataByte);
            UART_4D_LCD_PutChar(0x0Du);
            UART_4D_LCD_PutChar(0x0Au);
        }
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_GetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Determine the amount of space left in the TX buffer and return the count in
    *  bytes
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Integer count of the number of bytes left in the TX buffer
    *
    * Global Variables:
    *  UART_4D_LCD_txBufferWrite - used to calculate left space.
    *  UART_4D_LCD_txBufferRead - used to calculate left space.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the TX Buffer is.
    *
    *******************************************************************************/
    uint8 UART_4D_LCD_GetTxBufferSize(void)
                                                            
    {
        uint8 size;

        #if(UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)

            /* Disable Tx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableTxInt();
            #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

            if(UART_4D_LCD_txBufferRead == UART_4D_LCD_txBufferWrite)
            {
                size = 0u;
            }
            else if(UART_4D_LCD_txBufferRead < UART_4D_LCD_txBufferWrite)
            {
                size = (UART_4D_LCD_txBufferWrite - UART_4D_LCD_txBufferRead);
            }
            else
            {
                size = (UART_4D_LCD_TXBUFFERSIZE - UART_4D_LCD_txBufferRead) + UART_4D_LCD_txBufferWrite;
            }

            /* Enable Tx interrupt. */
            #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableTxInt();
            #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

        #else /* UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

            size = UART_4D_LCD_TXSTATUS_REG;

            /* Is the fifo is full. */
            if((size & UART_4D_LCD_TX_STS_FIFO_FULL) != 0u)
            {
                size = UART_4D_LCD_FIFO_LENGTH;
            }
            else if((size & UART_4D_LCD_TX_STS_FIFO_EMPTY) != 0u)
            {
                size = 0u;
            }
            else
            {
                /* We only know there is data in the fifo. */
                size = 1u;
            }

        #endif /* End UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */

        return(size);
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_ClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the TX RAM buffer by setting the read and write pointers both to zero.
    *  Clears the hardware TX FIFO.  Any data present in the FIFO will not be sent.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_txBufferWrite - cleared to zero.
    *  UART_4D_LCD_txBufferRead - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may have
    *  remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM buffer will be lost when overwritten.
    *
    *******************************************************************************/
    void UART_4D_LCD_ClearTxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* Enter critical section */
        enableInterrupts = CyEnterCriticalSection();
        /* clear the HW FIFO */
        UART_4D_LCD_TXDATA_AUX_CTL_REG |=  UART_4D_LCD_TX_FIFO_CLR;
        UART_4D_LCD_TXDATA_AUX_CTL_REG &= (uint8)~UART_4D_LCD_TX_FIFO_CLR;
        /* Exit critical section */
        CyExitCriticalSection(enableInterrupts);

        #if(UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH)

            /* Disable Tx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                UART_4D_LCD_DisableTxInt();
            #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

            UART_4D_LCD_txBufferRead = 0u;
            UART_4D_LCD_txBufferWrite = 0u;

            /* Enable Tx interrupt. */
            #if(UART_4D_LCD_TX_INTERRUPT_ENABLED)
                UART_4D_LCD_EnableTxInt();
            #endif /* End UART_4D_LCD_TX_INTERRUPT_ENABLED */

        #endif /* End UART_4D_LCD_TXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH */
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SendBreak
    ********************************************************************************
    *
    * Summary:
    *  Write a Break command to the UART
    *
    * Parameters:
    *  uint8 retMode:  Wait mode,
    *   0 - Initialize registers for Break, sends the Break signal and return
    *       imediately.
    *   1 - Wait until Break sending is complete, reinitialize registers to normal
    *       transmission mode then return.
    *   2 - Reinitialize registers to normal transmission mode then return.
    *   3 - both steps: 0 and 1
    *       init registers for Break, send Break signal
    *       wait until Break sending is complete, reinit registers to normal
    *       transmission mode then return.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_4D_LCD_initVar - checked to identify that the component has been
    *     initialized.
    *  tx_period - static variable, used for keeping TX period configuration.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  SendBreak function initializes registers to send 13-bit break signal. It is
    *  important to return the registers configuration to normal for continue 8-bit
    *  operation.
    *  Trere are 3 variants for this API usage:
    *  1) SendBreak(3) - function will send the Break signal and take care on the
    *     configuration returning. Funcition will block CPU untill transmition
    *     complete.
    *  2) User may want to use bloking time if UART configured to the low speed
    *     operation
    *     Emample for this case:
    *     SendBreak(0);     - init Break signal transmition
    *         Add your code here to use CPU time
    *     SendBreak(1);     - complete Break operation
    *  3) Same to 2) but user may want to init and use the interrupt for complete
    *     break operation.
    *     Example for this case:
    *     Init TX interrupt whith "TX - On TX Complete" parameter
    *     SendBreak(0);     - init Break signal transmition
    *         Add your code here to use CPU time
    *     When interrupt appear with UART_TX_STS_COMPLETE status:
    *     SendBreak(2);     - complete Break operation
    *
    * Side Effects:
    *   Uses static variable to keep registers configuration.
    *
    *******************************************************************************/
    void UART_4D_LCD_SendBreak(uint8 retMode) 
    {

        /* If not Initialized then skip this function*/
        if(UART_4D_LCD_initVar != 0u)
        {
            /*Set the Counter to 13-bits and transmit a 00 byte*/
            /*When that is done then reset the counter value back*/
            uint8 tmpStat;

            #if(UART_4D_LCD_HD_ENABLED) /* Half Duplex mode*/

                if( (retMode == UART_4D_LCD_SEND_BREAK) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT ) )
                {
                    /* CTRL_HD_SEND_BREAK - sends break bits in HD mode*/
                    UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() |
                                                          UART_4D_LCD_CTRL_HD_SEND_BREAK);
                    /* Send zeros*/
                    UART_4D_LCD_TXDATA_REG = 0u;

                    do /*wait until transmit starts*/
                    {
                        tmpStat = UART_4D_LCD_TXSTATUS_REG;
                    }while((tmpStat & UART_4D_LCD_TX_STS_FIFO_EMPTY) != 0u);
                }

                if( (retMode == UART_4D_LCD_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT) )
                {
                    do /*wait until transmit complete*/
                    {
                        tmpStat = UART_4D_LCD_TXSTATUS_REG;
                    }while(((uint8)~tmpStat & UART_4D_LCD_TX_STS_COMPLETE) != 0u);
                }

                if( (retMode == UART_4D_LCD_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == UART_4D_LCD_REINIT) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT) )
                {
                    UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() &
                                                  (uint8)~UART_4D_LCD_CTRL_HD_SEND_BREAK);
                }

            #else /* UART_4D_LCD_HD_ENABLED Full Duplex mode */

                static uint8 tx_period;

                if( (retMode == UART_4D_LCD_SEND_BREAK) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT) )
                {
                    /* CTRL_HD_SEND_BREAK - skip to send parity bit at Break signal in Full Duplex mode*/
                    #if( (UART_4D_LCD_PARITY_TYPE != UART_4D_LCD__B_UART__NONE_REVB) || \
                                        (UART_4D_LCD_PARITY_TYPE_SW != 0u) )
                        UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() |
                                                              UART_4D_LCD_CTRL_HD_SEND_BREAK);
                    #endif /* End UART_4D_LCD_PARITY_TYPE != UART_4D_LCD__B_UART__NONE_REVB  */

                    #if(UART_4D_LCD_TXCLKGEN_DP)
                        tx_period = UART_4D_LCD_TXBITCLKTX_COMPLETE_REG;
                        UART_4D_LCD_TXBITCLKTX_COMPLETE_REG = UART_4D_LCD_TXBITCTR_BREAKBITS;
                    #else
                        tx_period = UART_4D_LCD_TXBITCTR_PERIOD_REG;
                        UART_4D_LCD_TXBITCTR_PERIOD_REG = UART_4D_LCD_TXBITCTR_BREAKBITS8X;
                    #endif /* End UART_4D_LCD_TXCLKGEN_DP */

                    /* Send zeros*/
                    UART_4D_LCD_TXDATA_REG = 0u;

                    do /* wait until transmit starts */
                    {
                        tmpStat = UART_4D_LCD_TXSTATUS_REG;
                    }while((tmpStat & UART_4D_LCD_TX_STS_FIFO_EMPTY) != 0u);
                }

                if( (retMode == UART_4D_LCD_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT) )
                {
                    do /*wait until transmit complete*/
                    {
                        tmpStat = UART_4D_LCD_TXSTATUS_REG;
                    }while(((uint8)~tmpStat & UART_4D_LCD_TX_STS_COMPLETE) != 0u);
                }

                if( (retMode == UART_4D_LCD_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == UART_4D_LCD_REINIT) ||
                    (retMode == UART_4D_LCD_SEND_WAIT_REINIT) )
                {

                    #if(UART_4D_LCD_TXCLKGEN_DP)
                        UART_4D_LCD_TXBITCLKTX_COMPLETE_REG = tx_period;
                    #else
                        UART_4D_LCD_TXBITCTR_PERIOD_REG = tx_period;
                    #endif /* End UART_4D_LCD_TXCLKGEN_DP */

                    #if( (UART_4D_LCD_PARITY_TYPE != UART_4D_LCD__B_UART__NONE_REVB) || \
                         (UART_4D_LCD_PARITY_TYPE_SW != 0u) )
                        UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() &
                                                      (uint8)~UART_4D_LCD_CTRL_HD_SEND_BREAK);
                    #endif /* End UART_4D_LCD_PARITY_TYPE != NONE */
                }
            #endif    /* End UART_4D_LCD_HD_ENABLED */
        }
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_SetTxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Set the transmit addressing mode
    *
    * Parameters:
    *  addressMode: 0 -> Space
    *               1 -> Mark
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void UART_4D_LCD_SetTxAddressMode(uint8 addressMode) 
    {
        /* Mark/Space sending enable*/
        if(addressMode != 0u)
        {
            #if( UART_4D_LCD_CONTROL_REG_REMOVED == 0u )
                UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() |
                                                      UART_4D_LCD_CTRL_MARK);
            #endif /* End UART_4D_LCD_CONTROL_REG_REMOVED == 0u */
        }
        else
        {
            #if( UART_4D_LCD_CONTROL_REG_REMOVED == 0u )
                UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() &
                                                    (uint8)~UART_4D_LCD_CTRL_MARK);
            #endif /* End UART_4D_LCD_CONTROL_REG_REMOVED == 0u */
        }
    }

#endif  /* EndUART_4D_LCD_TX_ENABLED */

#if(UART_4D_LCD_HD_ENABLED)


    /*******************************************************************************
    * Function Name: UART_4D_LCD_LoadTxConfig
    ********************************************************************************
    *
    * Summary:
    *  Unloads the Rx configuration if required and loads the
    *  Tx configuration. It is the users responsibility to ensure that any
    *  transaction is complete and it is safe to unload the Tx
    *  configuration.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Valid only for half duplex UART.
    *
    * Side Effects:
    *  Disable RX interrupt mask, when software buffer has been used.
    *
    *******************************************************************************/
    void UART_4D_LCD_LoadTxConfig(void) 
    {
        #if((UART_4D_LCD_RX_INTERRUPT_ENABLED) && (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            /* Disable RX interrupts before set TX configuration */
            UART_4D_LCD_SetRxInterruptMode(0u);
        #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */

        UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() | UART_4D_LCD_CTRL_HD_SEND);
        UART_4D_LCD_RXBITCTR_PERIOD_REG = UART_4D_LCD_HD_TXBITCTR_INIT;
        #if(CY_UDB_V0) /* Manually clear status register when mode has been changed */
            /* Clear status register */
            CY_GET_REG8(UART_4D_LCD_RXSTATUS_PTR);
        #endif /* CY_UDB_V0 */
    }


    /*******************************************************************************
    * Function Name: UART_4D_LCD_LoadRxConfig
    ********************************************************************************
    *
    * Summary:
    *  Unloads the Tx configuration if required and loads the
    *  Rx configuration. It is the users responsibility to ensure that any
    *  transaction is complete and it is safe to unload the Rx
    *  configuration.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Valid only for half duplex UART
    *
    * Side Effects:
    *  Set RX interrupt mask based on customizer settings, when software buffer
    *  has been used.
    *
    *******************************************************************************/
    void UART_4D_LCD_LoadRxConfig(void) 
    {
        UART_4D_LCD_WriteControlRegister(UART_4D_LCD_ReadControlRegister() &
                                                (uint8)~UART_4D_LCD_CTRL_HD_SEND);
        UART_4D_LCD_RXBITCTR_PERIOD_REG = UART_4D_LCD_HD_RXBITCTR_INIT;
        #if(CY_UDB_V0) /* Manually clear status register when mode has been changed */
            /* Clear status register */
            CY_GET_REG8(UART_4D_LCD_RXSTATUS_PTR);
        #endif /* CY_UDB_V0 */

        #if((UART_4D_LCD_RX_INTERRUPT_ENABLED) && (UART_4D_LCD_RXBUFFERSIZE > UART_4D_LCD_FIFO_LENGTH))
            /* Enable RX interrupt after set RX configuration */
            UART_4D_LCD_SetRxInterruptMode(UART_4D_LCD_INIT_RX_INTERRUPTS_MASK);
        #endif /* UART_4D_LCD_RX_INTERRUPT_ENABLED */
    }

#endif  /* UART_4D_LCD_HD_ENABLED */


/* [] END OF FILE */
