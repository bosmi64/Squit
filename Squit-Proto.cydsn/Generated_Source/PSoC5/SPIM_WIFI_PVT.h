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

#if !defined(CY_SPIM_PVT_SPIM_WIFI_H)
#define CY_SPIM_PVT_SPIM_WIFI_H

#include "SPIM_WIFI.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_WIFI_swStatusTx;
extern volatile uint8 SPIM_WIFI_swStatusRx;

#if(SPIM_WIFI_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_WIFI_txBuffer[SPIM_WIFI_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_WIFI_txBufferRead;
    extern volatile uint8 SPIM_WIFI_txBufferWrite;
    extern volatile uint8 SPIM_WIFI_txBufferFull;
#endif /* (SPIM_WIFI_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_WIFI_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_WIFI_rxBuffer[SPIM_WIFI_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_WIFI_rxBufferRead;
    extern volatile uint8 SPIM_WIFI_rxBufferWrite;
    extern volatile uint8 SPIM_WIFI_rxBufferFull;
#endif /* (SPIM_WIFI_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_WIFI_H */


/* [] END OF FILE */
