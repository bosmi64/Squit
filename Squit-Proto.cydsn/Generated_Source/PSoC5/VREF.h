/*******************************************************************************
* File Name: VREF.h  
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

#if !defined(CY_PINS_VREF_H) /* Pins VREF_H */
#define CY_PINS_VREF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VREF_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VREF__PORT == 15 && ((VREF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VREF_Write(uint8 value) ;
void    VREF_SetDriveMode(uint8 mode) ;
uint8   VREF_ReadDataReg(void) ;
uint8   VREF_Read(void) ;
uint8   VREF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VREF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VREF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VREF_DM_RES_UP          PIN_DM_RES_UP
#define VREF_DM_RES_DWN         PIN_DM_RES_DWN
#define VREF_DM_OD_LO           PIN_DM_OD_LO
#define VREF_DM_OD_HI           PIN_DM_OD_HI
#define VREF_DM_STRONG          PIN_DM_STRONG
#define VREF_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VREF_MASK               VREF__MASK
#define VREF_SHIFT              VREF__SHIFT
#define VREF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VREF_PS                     (* (reg8 *) VREF__PS)
/* Data Register */
#define VREF_DR                     (* (reg8 *) VREF__DR)
/* Port Number */
#define VREF_PRT_NUM                (* (reg8 *) VREF__PRT) 
/* Connect to Analog Globals */                                                  
#define VREF_AG                     (* (reg8 *) VREF__AG)                       
/* Analog MUX bux enable */
#define VREF_AMUX                   (* (reg8 *) VREF__AMUX) 
/* Bidirectional Enable */                                                        
#define VREF_BIE                    (* (reg8 *) VREF__BIE)
/* Bit-mask for Aliased Register Access */
#define VREF_BIT_MASK               (* (reg8 *) VREF__BIT_MASK)
/* Bypass Enable */
#define VREF_BYP                    (* (reg8 *) VREF__BYP)
/* Port wide control signals */                                                   
#define VREF_CTL                    (* (reg8 *) VREF__CTL)
/* Drive Modes */
#define VREF_DM0                    (* (reg8 *) VREF__DM0) 
#define VREF_DM1                    (* (reg8 *) VREF__DM1)
#define VREF_DM2                    (* (reg8 *) VREF__DM2) 
/* Input Buffer Disable Override */
#define VREF_INP_DIS                (* (reg8 *) VREF__INP_DIS)
/* LCD Common or Segment Drive */
#define VREF_LCD_COM_SEG            (* (reg8 *) VREF__LCD_COM_SEG)
/* Enable Segment LCD */
#define VREF_LCD_EN                 (* (reg8 *) VREF__LCD_EN)
/* Slew Rate Control */
#define VREF_SLW                    (* (reg8 *) VREF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VREF_PRTDSI__CAPS_SEL       (* (reg8 *) VREF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VREF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VREF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VREF_PRTDSI__OE_SEL0        (* (reg8 *) VREF__PRTDSI__OE_SEL0) 
#define VREF_PRTDSI__OE_SEL1        (* (reg8 *) VREF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VREF_PRTDSI__OUT_SEL0       (* (reg8 *) VREF__PRTDSI__OUT_SEL0) 
#define VREF_PRTDSI__OUT_SEL1       (* (reg8 *) VREF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VREF_PRTDSI__SYNC_OUT       (* (reg8 *) VREF__PRTDSI__SYNC_OUT) 


#if defined(VREF__INTSTAT)  /* Interrupt Registers */

    #define VREF_INTSTAT                (* (reg8 *) VREF__INTSTAT)
    #define VREF_SNAP                   (* (reg8 *) VREF__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VREF_H */


/* [] END OF FILE */
