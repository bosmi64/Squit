/*******************************************************************************
* File Name: .h
* Version 2.40
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_ADIS_16210_SPI_H)
#define CY_SPIM_PVT_ADIS_16210_SPI_H

#include "ADIS_16210_SPI.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 ADIS_16210_SPI_swStatusTx;
extern volatile uint8 ADIS_16210_SPI_swStatusRx;

#if(ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 ADIS_16210_SPI_txBuffer[ADIS_16210_SPI_TX_BUFFER_SIZE];
    extern volatile uint8 ADIS_16210_SPI_txBufferRead;
    extern volatile uint8 ADIS_16210_SPI_txBufferWrite;
    extern volatile uint8 ADIS_16210_SPI_txBufferFull;
#endif /* (ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) */

#if(ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 ADIS_16210_SPI_rxBuffer[ADIS_16210_SPI_RX_BUFFER_SIZE];
    extern volatile uint8 ADIS_16210_SPI_rxBufferRead;
    extern volatile uint8 ADIS_16210_SPI_rxBufferWrite;
    extern volatile uint8 ADIS_16210_SPI_rxBufferFull;
#endif /* (ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_ADIS_16210_SPI_H */


/* [] END OF FILE */
