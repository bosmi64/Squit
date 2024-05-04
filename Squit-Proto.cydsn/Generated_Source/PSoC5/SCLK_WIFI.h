/*******************************************************************************
* File Name: SCLK_WIFI.h  
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

#if !defined(CY_PINS_SCLK_WIFI_H) /* Pins SCLK_WIFI_H */
#define CY_PINS_SCLK_WIFI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SCLK_WIFI_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SCLK_WIFI__PORT == 15 && ((SCLK_WIFI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SCLK_WIFI_Write(uint8 value) ;
void    SCLK_WIFI_SetDriveMode(uint8 mode) ;
uint8   SCLK_WIFI_ReadDataReg(void) ;
uint8   SCLK_WIFI_Read(void) ;
uint8   SCLK_WIFI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SCLK_WIFI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SCLK_WIFI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SCLK_WIFI_DM_RES_UP          PIN_DM_RES_UP
#define SCLK_WIFI_DM_RES_DWN         PIN_DM_RES_DWN
#define SCLK_WIFI_DM_OD_LO           PIN_DM_OD_LO
#define SCLK_WIFI_DM_OD_HI           PIN_DM_OD_HI
#define SCLK_WIFI_DM_STRONG          PIN_DM_STRONG
#define SCLK_WIFI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SCLK_WIFI_MASK               SCLK_WIFI__MASK
#define SCLK_WIFI_SHIFT              SCLK_WIFI__SHIFT
#define SCLK_WIFI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCLK_WIFI_PS                     (* (reg8 *) SCLK_WIFI__PS)
/* Data Register */
#define SCLK_WIFI_DR                     (* (reg8 *) SCLK_WIFI__DR)
/* Port Number */
#define SCLK_WIFI_PRT_NUM                (* (reg8 *) SCLK_WIFI__PRT) 
/* Connect to Analog Globals */                                                  
#define SCLK_WIFI_AG                     (* (reg8 *) SCLK_WIFI__AG)                       
/* Analog MUX bux enable */
#define SCLK_WIFI_AMUX                   (* (reg8 *) SCLK_WIFI__AMUX) 
/* Bidirectional Enable */                                                        
#define SCLK_WIFI_BIE                    (* (reg8 *) SCLK_WIFI__BIE)
/* Bit-mask for Aliased Register Access */
#define SCLK_WIFI_BIT_MASK               (* (reg8 *) SCLK_WIFI__BIT_MASK)
/* Bypass Enable */
#define SCLK_WIFI_BYP                    (* (reg8 *) SCLK_WIFI__BYP)
/* Port wide control signals */                                                   
#define SCLK_WIFI_CTL                    (* (reg8 *) SCLK_WIFI__CTL)
/* Drive Modes */
#define SCLK_WIFI_DM0                    (* (reg8 *) SCLK_WIFI__DM0) 
#define SCLK_WIFI_DM1                    (* (reg8 *) SCLK_WIFI__DM1)
#define SCLK_WIFI_DM2                    (* (reg8 *) SCLK_WIFI__DM2) 
/* Input Buffer Disable Override */
#define SCLK_WIFI_INP_DIS                (* (reg8 *) SCLK_WIFI__INP_DIS)
/* LCD Common or Segment Drive */
#define SCLK_WIFI_LCD_COM_SEG            (* (reg8 *) SCLK_WIFI__LCD_COM_SEG)
/* Enable Segment LCD */
#define SCLK_WIFI_LCD_EN                 (* (reg8 *) SCLK_WIFI__LCD_EN)
/* Slew Rate Control */
#define SCLK_WIFI_SLW                    (* (reg8 *) SCLK_WIFI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SCLK_WIFI_PRTDSI__CAPS_SEL       (* (reg8 *) SCLK_WIFI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SCLK_WIFI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SCLK_WIFI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SCLK_WIFI_PRTDSI__OE_SEL0        (* (reg8 *) SCLK_WIFI__PRTDSI__OE_SEL0) 
#define SCLK_WIFI_PRTDSI__OE_SEL1        (* (reg8 *) SCLK_WIFI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SCLK_WIFI_PRTDSI__OUT_SEL0       (* (reg8 *) SCLK_WIFI__PRTDSI__OUT_SEL0) 
#define SCLK_WIFI_PRTDSI__OUT_SEL1       (* (reg8 *) SCLK_WIFI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SCLK_WIFI_PRTDSI__SYNC_OUT       (* (reg8 *) SCLK_WIFI__PRTDSI__SYNC_OUT) 


#if defined(SCLK_WIFI__INTSTAT)  /* Interrupt Registers */

    #define SCLK_WIFI_INTSTAT                (* (reg8 *) SCLK_WIFI__INTSTAT)
    #define SCLK_WIFI_SNAP                   (* (reg8 *) SCLK_WIFI__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SCLK_WIFI_H */


/* [] END OF FILE */
