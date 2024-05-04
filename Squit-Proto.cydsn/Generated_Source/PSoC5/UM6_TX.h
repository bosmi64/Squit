/*******************************************************************************
* File Name: UM6_TX.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_UM6_TX_H) /* Pins UM6_TX_H */
#define CY_PINS_UM6_TX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UM6_TX_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UM6_TX__PORT == 15 && ((UM6_TX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UM6_TX_Write(uint8 value) ;
void    UM6_TX_SetDriveMode(uint8 mode) ;
uint8   UM6_TX_ReadDataReg(void) ;
uint8   UM6_TX_Read(void) ;
uint8   UM6_TX_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UM6_TX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UM6_TX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UM6_TX_DM_RES_UP          PIN_DM_RES_UP
#define UM6_TX_DM_RES_DWN         PIN_DM_RES_DWN
#define UM6_TX_DM_OD_LO           PIN_DM_OD_LO
#define UM6_TX_DM_OD_HI           PIN_DM_OD_HI
#define UM6_TX_DM_STRONG          PIN_DM_STRONG
#define UM6_TX_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UM6_TX_MASK               UM6_TX__MASK
#define UM6_TX_SHIFT              UM6_TX__SHIFT
#define UM6_TX_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UM6_TX_PS                     (* (reg8 *) UM6_TX__PS)
/* Data Register */
#define UM6_TX_DR                     (* (reg8 *) UM6_TX__DR)
/* Port Number */
#define UM6_TX_PRT_NUM                (* (reg8 *) UM6_TX__PRT) 
/* Connect to Analog Globals */                                                  
#define UM6_TX_AG                     (* (reg8 *) UM6_TX__AG)                       
/* Analog MUX bux enable */
#define UM6_TX_AMUX                   (* (reg8 *) UM6_TX__AMUX) 
/* Bidirectional Enable */                                                        
#define UM6_TX_BIE                    (* (reg8 *) UM6_TX__BIE)
/* Bit-mask for Aliased Register Access */
#define UM6_TX_BIT_MASK               (* (reg8 *) UM6_TX__BIT_MASK)
/* Bypass Enable */
#define UM6_TX_BYP                    (* (reg8 *) UM6_TX__BYP)
/* Port wide control signals */                                                   
#define UM6_TX_CTL                    (* (reg8 *) UM6_TX__CTL)
/* Drive Modes */
#define UM6_TX_DM0                    (* (reg8 *) UM6_TX__DM0) 
#define UM6_TX_DM1                    (* (reg8 *) UM6_TX__DM1)
#define UM6_TX_DM2                    (* (reg8 *) UM6_TX__DM2) 
/* Input Buffer Disable Override */
#define UM6_TX_INP_DIS                (* (reg8 *) UM6_TX__INP_DIS)
/* LCD Common or Segment Drive */
#define UM6_TX_LCD_COM_SEG            (* (reg8 *) UM6_TX__LCD_COM_SEG)
/* Enable Segment LCD */
#define UM6_TX_LCD_EN                 (* (reg8 *) UM6_TX__LCD_EN)
/* Slew Rate Control */
#define UM6_TX_SLW                    (* (reg8 *) UM6_TX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UM6_TX_PRTDSI__CAPS_SEL       (* (reg8 *) UM6_TX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UM6_TX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UM6_TX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UM6_TX_PRTDSI__OE_SEL0        (* (reg8 *) UM6_TX__PRTDSI__OE_SEL0) 
#define UM6_TX_PRTDSI__OE_SEL1        (* (reg8 *) UM6_TX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UM6_TX_PRTDSI__OUT_SEL0       (* (reg8 *) UM6_TX__PRTDSI__OUT_SEL0) 
#define UM6_TX_PRTDSI__OUT_SEL1       (* (reg8 *) UM6_TX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UM6_TX_PRTDSI__SYNC_OUT       (* (reg8 *) UM6_TX__PRTDSI__SYNC_OUT) 


#if defined(UM6_TX__INTSTAT)  /* Interrupt Registers */

    #define UM6_TX_INTSTAT                (* (reg8 *) UM6_TX__INTSTAT)
    #define UM6_TX_SNAP                   (* (reg8 *) UM6_TX__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UM6_TX_H */


/* [] END OF FILE */
