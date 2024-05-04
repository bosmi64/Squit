/*******************************************************************************
* File Name: MOSI_BLE.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MOSI_BLE_H) /* Pins MOSI_BLE_H */
#define CY_PINS_MOSI_BLE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOSI_BLE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOSI_BLE__PORT == 15 && ((MOSI_BLE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MOSI_BLE_Write(uint8 value) ;
void    MOSI_BLE_SetDriveMode(uint8 mode) ;
uint8   MOSI_BLE_ReadDataReg(void) ;
uint8   MOSI_BLE_Read(void) ;
uint8   MOSI_BLE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOSI_BLE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MOSI_BLE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MOSI_BLE_DM_RES_UP          PIN_DM_RES_UP
#define MOSI_BLE_DM_RES_DWN         PIN_DM_RES_DWN
#define MOSI_BLE_DM_OD_LO           PIN_DM_OD_LO
#define MOSI_BLE_DM_OD_HI           PIN_DM_OD_HI
#define MOSI_BLE_DM_STRONG          PIN_DM_STRONG
#define MOSI_BLE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MOSI_BLE_MASK               MOSI_BLE__MASK
#define MOSI_BLE_SHIFT              MOSI_BLE__SHIFT
#define MOSI_BLE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI_BLE_PS                     (* (reg8 *) MOSI_BLE__PS)
/* Data Register */
#define MOSI_BLE_DR                     (* (reg8 *) MOSI_BLE__DR)
/* Port Number */
#define MOSI_BLE_PRT_NUM                (* (reg8 *) MOSI_BLE__PRT) 
/* Connect to Analog Globals */                                                  
#define MOSI_BLE_AG                     (* (reg8 *) MOSI_BLE__AG)                       
/* Analog MUX bux enable */
#define MOSI_BLE_AMUX                   (* (reg8 *) MOSI_BLE__AMUX) 
/* Bidirectional Enable */                                                        
#define MOSI_BLE_BIE                    (* (reg8 *) MOSI_BLE__BIE)
/* Bit-mask for Aliased Register Access */
#define MOSI_BLE_BIT_MASK               (* (reg8 *) MOSI_BLE__BIT_MASK)
/* Bypass Enable */
#define MOSI_BLE_BYP                    (* (reg8 *) MOSI_BLE__BYP)
/* Port wide control signals */                                                   
#define MOSI_BLE_CTL                    (* (reg8 *) MOSI_BLE__CTL)
/* Drive Modes */
#define MOSI_BLE_DM0                    (* (reg8 *) MOSI_BLE__DM0) 
#define MOSI_BLE_DM1                    (* (reg8 *) MOSI_BLE__DM1)
#define MOSI_BLE_DM2                    (* (reg8 *) MOSI_BLE__DM2) 
/* Input Buffer Disable Override */
#define MOSI_BLE_INP_DIS                (* (reg8 *) MOSI_BLE__INP_DIS)
/* LCD Common or Segment Drive */
#define MOSI_BLE_LCD_COM_SEG            (* (reg8 *) MOSI_BLE__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOSI_BLE_LCD_EN                 (* (reg8 *) MOSI_BLE__LCD_EN)
/* Slew Rate Control */
#define MOSI_BLE_SLW                    (* (reg8 *) MOSI_BLE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOSI_BLE_PRTDSI__CAPS_SEL       (* (reg8 *) MOSI_BLE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOSI_BLE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOSI_BLE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOSI_BLE_PRTDSI__OE_SEL0        (* (reg8 *) MOSI_BLE__PRTDSI__OE_SEL0) 
#define MOSI_BLE_PRTDSI__OE_SEL1        (* (reg8 *) MOSI_BLE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOSI_BLE_PRTDSI__OUT_SEL0       (* (reg8 *) MOSI_BLE__PRTDSI__OUT_SEL0) 
#define MOSI_BLE_PRTDSI__OUT_SEL1       (* (reg8 *) MOSI_BLE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOSI_BLE_PRTDSI__SYNC_OUT       (* (reg8 *) MOSI_BLE__PRTDSI__SYNC_OUT) 


#if defined(MOSI_BLE__INTSTAT)  /* Interrupt Registers */

    #define MOSI_BLE_INTSTAT                (* (reg8 *) MOSI_BLE__INTSTAT)
    #define MOSI_BLE_SNAP                   (* (reg8 *) MOSI_BLE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOSI_BLE_H */


/* [] END OF FILE */
