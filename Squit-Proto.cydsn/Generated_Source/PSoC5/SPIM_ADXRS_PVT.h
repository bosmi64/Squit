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

#if !defined(CY_SPIM_PVT_SPIM_ADXRS_H)
#define CY_SPIM_PVT_SPIM_ADXRS_H

#include "SPIM_ADXRS.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_ADXRS_swStatusTx;
extern volatile uint8 SPIM_ADXRS_swStatusRx;

#if(SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 SPIM_ADXRS_txBuffer[SPIM_ADXRS_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_ADXRS_txBufferRead;
    extern volatile uint8 SPIM_ADXRS_txBufferWrite;
    extern volatile uint8 SPIM_ADXRS_txBufferFull;
#endif /* (SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 SPIM_ADXRS_rxBuffer[SPIM_ADXRS_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_ADXRS_rxBufferRead;
    extern volatile uint8 SPIM_ADXRS_rxBufferWrite;
    extern volatile uint8 SPIM_ADXRS_rxBufferFull;
#endif /* (SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_ADXRS_H */


/* [] END OF FILE */
