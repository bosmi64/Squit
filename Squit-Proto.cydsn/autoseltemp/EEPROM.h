/*******************************************************************************
* File Name: EEPROM.h
* Version 1.60
*
*  Description:
*   Provides the function definitions for the EEPROM API.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(__EEPROM_EEPROM_H__)
#define __EEPROM_EEPROM_H__


#include <CYFLASH.H>

#define EEPROM_EEPROM_SIZE    CYDEV_EE_SIZE

#ifndef CY_PSOC3
#error Component EEPROM_v1_60 requires cy_boot v2.30 or later
#endif /* CY_PSOC3 */


/***************************************
* Function Prototypes
***************************************/
#if (CY_PSOC3_ES3 || CY_PSOC5_ES2) 
    void EEPROM_Enable(void) ;
    void EEPROM_Start(void); 
    void EEPROM_Stop(void) ;
#endif /* (CY_PSOC3_ES3 || CY_PSOC5_ES2) */
cystatus EEPROM_EraseSector(uint8 sectorNumber) ;
cystatus EEPROM_Write(uint8 * rowData, uint8 rowNumber) ;
cystatus EEPROM_StartWrite(uint8 * rowData, uint8 rowNumber) ;
cystatus EEPROM_QueryWrite(void) ;


#endif /* __EEPROM_EEPROM_H__ */
