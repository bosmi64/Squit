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

#if !defined(CY_SPIM_PVT_SPIM_ITG3701_H)
#define CY_SPIM_PVT_SPIM_ITG3701_H

#include "SPIM_ITG3701.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_ITG3701_swStatusTx;
extern volatile uint8 SPIM_ITG3701_swStatusRx;

#if(SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 SPIM_ITG3701_txBuffer[SPIM_ITG3701_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_ITG3701_txBufferRead;
    extern volatile uint8 SPIM_ITG3701_txBufferWrite;
    extern volatile uint8 SPIM_ITG3701_txBufferFull;
#endif /* (SPIM_ITG3701_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint16 SPIM_ITG3701_rxBuffer[SPIM_ITG3701_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_ITG3701_rxBufferRead;
    extern volatile uint8 SPIM_ITG3701_rxBufferWrite;
    extern volatile uint8 SPIM_ITG3701_rxBufferFull;
#endif /* (SPIM_ITG3701_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_ITG3701_H */


/* [] END OF FILE */
