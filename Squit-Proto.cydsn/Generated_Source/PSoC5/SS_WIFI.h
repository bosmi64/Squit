/*******************************************************************************
* File Name: SS_WIFI.h  
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

#if !defined(CY_PINS_SS_WIFI_H) /* Pins SS_WIFI_H */
#define CY_PINS_SS_WIFI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SS_WIFI_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SS_WIFI__PORT == 15 && ((SS_WIFI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SS_WIFI_Write(uint8 value) ;
void    SS_WIFI_SetDriveMode(uint8 mode) ;
uint8   SS_WIFI_ReadDataReg(void) ;
uint8   SS_WIFI_Read(void) ;
uint8   SS_WIFI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SS_WIFI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SS_WIFI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SS_WIFI_DM_RES_UP          PIN_DM_RES_UP
#define SS_WIFI_DM_RES_DWN         PIN_DM_RES_DWN
#define SS_WIFI_DM_OD_LO           PIN_DM_OD_LO
#define SS_WIFI_DM_OD_HI           PIN_DM_OD_HI
#define SS_WIFI_DM_STRONG          PIN_DM_STRONG
#define SS_WIFI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SS_WIFI_MASK               SS_WIFI__MASK
#define SS_WIFI_SHIFT              SS_WIFI__SHIFT
#define SS_WIFI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS_WIFI_PS                     (* (reg8 *) SS_WIFI__PS)
/* Data Register */
#define SS_WIFI_DR                     (* (reg8 *) SS_WIFI__DR)
/* Port Number */
#define SS_WIFI_PRT_NUM                (* (reg8 *) SS_WIFI__PRT) 
/* Connect to Analog Globals */                                                  
#define SS_WIFI_AG                     (* (reg8 *) SS_WIFI__AG)                       
/* Analog MUX bux enable */
#define SS_WIFI_AMUX                   (* (reg8 *) SS_WIFI__AMUX) 
/* Bidirectional Enable */                                                        
#define SS_WIFI_BIE                    (* (reg8 *) SS_WIFI__BIE)
/* Bit-mask for Aliased Register Access */
#define SS_WIFI_BIT_MASK               (* (reg8 *) SS_WIFI__BIT_MASK)
/* Bypass Enable */
#define SS_WIFI_BYP                    (* (reg8 *) SS_WIFI__BYP)
/* Port wide control signals */                                                   
#define SS_WIFI_CTL                    (* (reg8 *) SS_WIFI__CTL)
/* Drive Modes */
#define SS_WIFI_DM0                    (* (reg8 *) SS_WIFI__DM0) 
#define SS_WIFI_DM1                    (* (reg8 *) SS_WIFI__DM1)
#define SS_WIFI_DM2                    (* (reg8 *) SS_WIFI__DM2) 
/* Input Buffer Disable Override */
#define SS_WIFI_INP_DIS                (* (reg8 *) SS_WIFI__INP_DIS)
/* LCD Common or Segment Drive */
#define SS_WIFI_LCD_COM_SEG            (* (reg8 *) SS_WIFI__LCD_COM_SEG)
/* Enable Segment LCD */
#define SS_WIFI_LCD_EN                 (* (reg8 *) SS_WIFI__LCD_EN)
/* Slew Rate Control */
#define SS_WIFI_SLW                    (* (reg8 *) SS_WIFI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SS_WIFI_PRTDSI__CAPS_SEL       (* (reg8 *) SS_WIFI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SS_WIFI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SS_WIFI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SS_WIFI_PRTDSI__OE_SEL0        (* (reg8 *) SS_WIFI__PRTDSI__OE_SEL0) 
#define SS_WIFI_PRTDSI__OE_SEL1        (* (reg8 *) SS_WIFI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SS_WIFI_PRTDSI__OUT_SEL0       (* (reg8 *) SS_WIFI__PRTDSI__OUT_SEL0) 
#define SS_WIFI_PRTDSI__OUT_SEL1       (* (reg8 *) SS_WIFI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SS_WIFI_PRTDSI__SYNC_OUT       (* (reg8 *) SS_WIFI__PRTDSI__SYNC_OUT) 


#if defined(SS_WIFI__INTSTAT)  /* Interrupt Registers */

    #define SS_WIFI_INTSTAT                (* (reg8 *) SS_WIFI__INTSTAT)
    #define SS_WIFI_SNAP                   (* (reg8 *) SS_WIFI__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SS_WIFI_H */


/* [] END OF FILE */
