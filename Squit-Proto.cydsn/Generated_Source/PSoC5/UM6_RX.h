/*******************************************************************************
* File Name: UM6_RX.h  
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

#if !defined(CY_PINS_UM6_RX_H) /* Pins UM6_RX_H */
#define CY_PINS_UM6_RX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UM6_RX_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UM6_RX__PORT == 15 && ((UM6_RX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    UM6_RX_Write(uint8 value) ;
void    UM6_RX_SetDriveMode(uint8 mode) ;
uint8   UM6_RX_ReadDataReg(void) ;
uint8   UM6_RX_Read(void) ;
uint8   UM6_RX_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define UM6_RX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define UM6_RX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define UM6_RX_DM_RES_UP          PIN_DM_RES_UP
#define UM6_RX_DM_RES_DWN         PIN_DM_RES_DWN
#define UM6_RX_DM_OD_LO           PIN_DM_OD_LO
#define UM6_RX_DM_OD_HI           PIN_DM_OD_HI
#define UM6_RX_DM_STRONG          PIN_DM_STRONG
#define UM6_RX_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define UM6_RX_MASK               UM6_RX__MASK
#define UM6_RX_SHIFT              UM6_RX__SHIFT
#define UM6_RX_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UM6_RX_PS                     (* (reg8 *) UM6_RX__PS)
/* Data Register */
#define UM6_RX_DR                     (* (reg8 *) UM6_RX__DR)
/* Port Number */
#define UM6_RX_PRT_NUM                (* (reg8 *) UM6_RX__PRT) 
/* Connect to Analog Globals */                                                  
#define UM6_RX_AG                     (* (reg8 *) UM6_RX__AG)                       
/* Analog MUX bux enable */
#define UM6_RX_AMUX                   (* (reg8 *) UM6_RX__AMUX) 
/* Bidirectional Enable */                                                        
#define UM6_RX_BIE                    (* (reg8 *) UM6_RX__BIE)
/* Bit-mask for Aliased Register Access */
#define UM6_RX_BIT_MASK               (* (reg8 *) UM6_RX__BIT_MASK)
/* Bypass Enable */
#define UM6_RX_BYP                    (* (reg8 *) UM6_RX__BYP)
/* Port wide control signals */                                                   
#define UM6_RX_CTL                    (* (reg8 *) UM6_RX__CTL)
/* Drive Modes */
#define UM6_RX_DM0                    (* (reg8 *) UM6_RX__DM0) 
#define UM6_RX_DM1                    (* (reg8 *) UM6_RX__DM1)
#define UM6_RX_DM2                    (* (reg8 *) UM6_RX__DM2) 
/* Input Buffer Disable Override */
#define UM6_RX_INP_DIS                (* (reg8 *) UM6_RX__INP_DIS)
/* LCD Common or Segment Drive */
#define UM6_RX_LCD_COM_SEG            (* (reg8 *) UM6_RX__LCD_COM_SEG)
/* Enable Segment LCD */
#define UM6_RX_LCD_EN                 (* (reg8 *) UM6_RX__LCD_EN)
/* Slew Rate Control */
#define UM6_RX_SLW                    (* (reg8 *) UM6_RX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UM6_RX_PRTDSI__CAPS_SEL       (* (reg8 *) UM6_RX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UM6_RX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UM6_RX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UM6_RX_PRTDSI__OE_SEL0        (* (reg8 *) UM6_RX__PRTDSI__OE_SEL0) 
#define UM6_RX_PRTDSI__OE_SEL1        (* (reg8 *) UM6_RX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UM6_RX_PRTDSI__OUT_SEL0       (* (reg8 *) UM6_RX__PRTDSI__OUT_SEL0) 
#define UM6_RX_PRTDSI__OUT_SEL1       (* (reg8 *) UM6_RX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UM6_RX_PRTDSI__SYNC_OUT       (* (reg8 *) UM6_RX__PRTDSI__SYNC_OUT) 


#if defined(UM6_RX__INTSTAT)  /* Interrupt Registers */

    #define UM6_RX_INTSTAT                (* (reg8 *) UM6_RX__INTSTAT)
    #define UM6_RX_SNAP                   (* (reg8 *) UM6_RX__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UM6_RX_H */


/* [] END OF FILE */
