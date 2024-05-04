/*******************************************************************************
* File Name: BAT_FAULTn.h  
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

#if !defined(CY_PINS_BAT_FAULTn_H) /* Pins BAT_FAULTn_H */
#define CY_PINS_BAT_FAULTn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BAT_FAULTn_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BAT_FAULTn__PORT == 15 && ((BAT_FAULTn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    BAT_FAULTn_Write(uint8 value) ;
void    BAT_FAULTn_SetDriveMode(uint8 mode) ;
uint8   BAT_FAULTn_ReadDataReg(void) ;
uint8   BAT_FAULTn_Read(void) ;
uint8   BAT_FAULTn_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BAT_FAULTn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BAT_FAULTn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BAT_FAULTn_DM_RES_UP          PIN_DM_RES_UP
#define BAT_FAULTn_DM_RES_DWN         PIN_DM_RES_DWN
#define BAT_FAULTn_DM_OD_LO           PIN_DM_OD_LO
#define BAT_FAULTn_DM_OD_HI           PIN_DM_OD_HI
#define BAT_FAULTn_DM_STRONG          PIN_DM_STRONG
#define BAT_FAULTn_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BAT_FAULTn_MASK               BAT_FAULTn__MASK
#define BAT_FAULTn_SHIFT              BAT_FAULTn__SHIFT
#define BAT_FAULTn_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BAT_FAULTn_PS                     (* (reg8 *) BAT_FAULTn__PS)
/* Data Register */
#define BAT_FAULTn_DR                     (* (reg8 *) BAT_FAULTn__DR)
/* Port Number */
#define BAT_FAULTn_PRT_NUM                (* (reg8 *) BAT_FAULTn__PRT) 
/* Connect to Analog Globals */                                                  
#define BAT_FAULTn_AG                     (* (reg8 *) BAT_FAULTn__AG)                       
/* Analog MUX bux enable */
#define BAT_FAULTn_AMUX                   (* (reg8 *) BAT_FAULTn__AMUX) 
/* Bidirectional Enable */                                                        
#define BAT_FAULTn_BIE                    (* (reg8 *) BAT_FAULTn__BIE)
/* Bit-mask for Aliased Register Access */
#define BAT_FAULTn_BIT_MASK               (* (reg8 *) BAT_FAULTn__BIT_MASK)
/* Bypass Enable */
#define BAT_FAULTn_BYP                    (* (reg8 *) BAT_FAULTn__BYP)
/* Port wide control signals */                                                   
#define BAT_FAULTn_CTL                    (* (reg8 *) BAT_FAULTn__CTL)
/* Drive Modes */
#define BAT_FAULTn_DM0                    (* (reg8 *) BAT_FAULTn__DM0) 
#define BAT_FAULTn_DM1                    (* (reg8 *) BAT_FAULTn__DM1)
#define BAT_FAULTn_DM2                    (* (reg8 *) BAT_FAULTn__DM2) 
/* Input Buffer Disable Override */
#define BAT_FAULTn_INP_DIS                (* (reg8 *) BAT_FAULTn__INP_DIS)
/* LCD Common or Segment Drive */
#define BAT_FAULTn_LCD_COM_SEG            (* (reg8 *) BAT_FAULTn__LCD_COM_SEG)
/* Enable Segment LCD */
#define BAT_FAULTn_LCD_EN                 (* (reg8 *) BAT_FAULTn__LCD_EN)
/* Slew Rate Control */
#define BAT_FAULTn_SLW                    (* (reg8 *) BAT_FAULTn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BAT_FAULTn_PRTDSI__CAPS_SEL       (* (reg8 *) BAT_FAULTn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BAT_FAULTn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BAT_FAULTn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BAT_FAULTn_PRTDSI__OE_SEL0        (* (reg8 *) BAT_FAULTn__PRTDSI__OE_SEL0) 
#define BAT_FAULTn_PRTDSI__OE_SEL1        (* (reg8 *) BAT_FAULTn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BAT_FAULTn_PRTDSI__OUT_SEL0       (* (reg8 *) BAT_FAULTn__PRTDSI__OUT_SEL0) 
#define BAT_FAULTn_PRTDSI__OUT_SEL1       (* (reg8 *) BAT_FAULTn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BAT_FAULTn_PRTDSI__SYNC_OUT       (* (reg8 *) BAT_FAULTn__PRTDSI__SYNC_OUT) 


#if defined(BAT_FAULTn__INTSTAT)  /* Interrupt Registers */

    #define BAT_FAULTn_INTSTAT                (* (reg8 *) BAT_FAULTn__INTSTAT)
    #define BAT_FAULTn_SNAP                   (* (reg8 *) BAT_FAULTn__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BAT_FAULTn_H */


/* [] END OF FILE */
