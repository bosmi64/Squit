/*******************************************************************************
* File Name: nBUTTON_PUSH.h  
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

#if !defined(CY_PINS_nBUTTON_PUSH_H) /* Pins nBUTTON_PUSH_H */
#define CY_PINS_nBUTTON_PUSH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nBUTTON_PUSH_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nBUTTON_PUSH__PORT == 15 && ((nBUTTON_PUSH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    nBUTTON_PUSH_Write(uint8 value) ;
void    nBUTTON_PUSH_SetDriveMode(uint8 mode) ;
uint8   nBUTTON_PUSH_ReadDataReg(void) ;
uint8   nBUTTON_PUSH_Read(void) ;
uint8   nBUTTON_PUSH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nBUTTON_PUSH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nBUTTON_PUSH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nBUTTON_PUSH_DM_RES_UP          PIN_DM_RES_UP
#define nBUTTON_PUSH_DM_RES_DWN         PIN_DM_RES_DWN
#define nBUTTON_PUSH_DM_OD_LO           PIN_DM_OD_LO
#define nBUTTON_PUSH_DM_OD_HI           PIN_DM_OD_HI
#define nBUTTON_PUSH_DM_STRONG          PIN_DM_STRONG
#define nBUTTON_PUSH_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nBUTTON_PUSH_MASK               nBUTTON_PUSH__MASK
#define nBUTTON_PUSH_SHIFT              nBUTTON_PUSH__SHIFT
#define nBUTTON_PUSH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nBUTTON_PUSH_PS                     (* (reg8 *) nBUTTON_PUSH__PS)
/* Data Register */
#define nBUTTON_PUSH_DR                     (* (reg8 *) nBUTTON_PUSH__DR)
/* Port Number */
#define nBUTTON_PUSH_PRT_NUM                (* (reg8 *) nBUTTON_PUSH__PRT) 
/* Connect to Analog Globals */                                                  
#define nBUTTON_PUSH_AG                     (* (reg8 *) nBUTTON_PUSH__AG)                       
/* Analog MUX bux enable */
#define nBUTTON_PUSH_AMUX                   (* (reg8 *) nBUTTON_PUSH__AMUX) 
/* Bidirectional Enable */                                                        
#define nBUTTON_PUSH_BIE                    (* (reg8 *) nBUTTON_PUSH__BIE)
/* Bit-mask for Aliased Register Access */
#define nBUTTON_PUSH_BIT_MASK               (* (reg8 *) nBUTTON_PUSH__BIT_MASK)
/* Bypass Enable */
#define nBUTTON_PUSH_BYP                    (* (reg8 *) nBUTTON_PUSH__BYP)
/* Port wide control signals */                                                   
#define nBUTTON_PUSH_CTL                    (* (reg8 *) nBUTTON_PUSH__CTL)
/* Drive Modes */
#define nBUTTON_PUSH_DM0                    (* (reg8 *) nBUTTON_PUSH__DM0) 
#define nBUTTON_PUSH_DM1                    (* (reg8 *) nBUTTON_PUSH__DM1)
#define nBUTTON_PUSH_DM2                    (* (reg8 *) nBUTTON_PUSH__DM2) 
/* Input Buffer Disable Override */
#define nBUTTON_PUSH_INP_DIS                (* (reg8 *) nBUTTON_PUSH__INP_DIS)
/* LCD Common or Segment Drive */
#define nBUTTON_PUSH_LCD_COM_SEG            (* (reg8 *) nBUTTON_PUSH__LCD_COM_SEG)
/* Enable Segment LCD */
#define nBUTTON_PUSH_LCD_EN                 (* (reg8 *) nBUTTON_PUSH__LCD_EN)
/* Slew Rate Control */
#define nBUTTON_PUSH_SLW                    (* (reg8 *) nBUTTON_PUSH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nBUTTON_PUSH_PRTDSI__CAPS_SEL       (* (reg8 *) nBUTTON_PUSH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nBUTTON_PUSH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nBUTTON_PUSH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nBUTTON_PUSH_PRTDSI__OE_SEL0        (* (reg8 *) nBUTTON_PUSH__PRTDSI__OE_SEL0) 
#define nBUTTON_PUSH_PRTDSI__OE_SEL1        (* (reg8 *) nBUTTON_PUSH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nBUTTON_PUSH_PRTDSI__OUT_SEL0       (* (reg8 *) nBUTTON_PUSH__PRTDSI__OUT_SEL0) 
#define nBUTTON_PUSH_PRTDSI__OUT_SEL1       (* (reg8 *) nBUTTON_PUSH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nBUTTON_PUSH_PRTDSI__SYNC_OUT       (* (reg8 *) nBUTTON_PUSH__PRTDSI__SYNC_OUT) 


#if defined(nBUTTON_PUSH__INTSTAT)  /* Interrupt Registers */

    #define nBUTTON_PUSH_INTSTAT                (* (reg8 *) nBUTTON_PUSH__INTSTAT)
    #define nBUTTON_PUSH_SNAP                   (* (reg8 *) nBUTTON_PUSH__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nBUTTON_PUSH_H */


/* [] END OF FILE */
