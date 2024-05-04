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

#if !defined(CY_SPIM_PVT_SPIM_BLE_H)
#define CY_SPIM_PVT_SPIM_BLE_H

#include "SPIM_BLE.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_BLE_swStatusTx;
extern volatile uint8 SPIM_BLE_swStatusRx;

#if(SPIM_BLE_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_BLE_txBuffer[SPIM_BLE_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_BLE_txBufferRead;
    extern volatile uint8 SPIM_BLE_txBufferWrite;
    extern volatile uint8 SPIM_BLE_txBufferFull;
#endif /* (SPIM_BLE_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_BLE_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_BLE_rxBuffer[SPIM_BLE_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_BLE_rxBufferRead;
    extern volatile uint8 SPIM_BLE_rxBufferWrite;
    extern volatile uint8 SPIM_BLE_rxBufferFull;
#endif /* (SPIM_BLE_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_BLE_H */


/* [] END OF FILE */
