/*******************************************************************************
* File Name: ASTIM_OUTPUT.h  
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

#if !defined(CY_PINS_ASTIM_OUTPUT_H) /* Pins ASTIM_OUTPUT_H */
#define CY_PINS_ASTIM_OUTPUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ASTIM_OUTPUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ASTIM_OUTPUT__PORT == 15 && ((ASTIM_OUTPUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ASTIM_OUTPUT_Write(uint8 value) ;
void    ASTIM_OUTPUT_SetDriveMode(uint8 mode) ;
uint8   ASTIM_OUTPUT_ReadDataReg(void) ;
uint8   ASTIM_OUTPUT_Read(void) ;
uint8   ASTIM_OUTPUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ASTIM_OUTPUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ASTIM_OUTPUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ASTIM_OUTPUT_DM_RES_UP          PIN_DM_RES_UP
#define ASTIM_OUTPUT_DM_RES_DWN         PIN_DM_RES_DWN
#define ASTIM_OUTPUT_DM_OD_LO           PIN_DM_OD_LO
#define ASTIM_OUTPUT_DM_OD_HI           PIN_DM_OD_HI
#define ASTIM_OUTPUT_DM_STRONG          PIN_DM_STRONG
#define ASTIM_OUTPUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ASTIM_OUTPUT_MASK               ASTIM_OUTPUT__MASK
#define ASTIM_OUTPUT_SHIFT              ASTIM_OUTPUT__SHIFT
#define ASTIM_OUTPUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ASTIM_OUTPUT_PS                     (* (reg8 *) ASTIM_OUTPUT__PS)
/* Data Register */
#define ASTIM_OUTPUT_DR                     (* (reg8 *) ASTIM_OUTPUT__DR)
/* Port Number */
#define ASTIM_OUTPUT_PRT_NUM                (* (reg8 *) ASTIM_OUTPUT__PRT) 
/* Connect to Analog Globals */                                                  
#define ASTIM_OUTPUT_AG                     (* (reg8 *) ASTIM_OUTPUT__AG)                       
/* Analog MUX bux enable */
#define ASTIM_OUTPUT_AMUX                   (* (reg8 *) ASTIM_OUTPUT__AMUX) 
/* Bidirectional Enable */                                                        
#define ASTIM_OUTPUT_BIE                    (* (reg8 *) ASTIM_OUTPUT__BIE)
/* Bit-mask for Aliased Register Access */
#define ASTIM_OUTPUT_BIT_MASK               (* (reg8 *) ASTIM_OUTPUT__BIT_MASK)
/* Bypass Enable */
#define ASTIM_OUTPUT_BYP                    (* (reg8 *) ASTIM_OUTPUT__BYP)
/* Port wide control signals */                                                   
#define ASTIM_OUTPUT_CTL                    (* (reg8 *) ASTIM_OUTPUT__CTL)
/* Drive Modes */
#define ASTIM_OUTPUT_DM0                    (* (reg8 *) ASTIM_OUTPUT__DM0) 
#define ASTIM_OUTPUT_DM1                    (* (reg8 *) ASTIM_OUTPUT__DM1)
#define ASTIM_OUTPUT_DM2                    (* (reg8 *) ASTIM_OUTPUT__DM2) 
/* Input Buffer Disable Override */
#define ASTIM_OUTPUT_INP_DIS                (* (reg8 *) ASTIM_OUTPUT__INP_DIS)
/* LCD Common or Segment Drive */
#define ASTIM_OUTPUT_LCD_COM_SEG            (* (reg8 *) ASTIM_OUTPUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define ASTIM_OUTPUT_LCD_EN                 (* (reg8 *) ASTIM_OUTPUT__LCD_EN)
/* Slew Rate Control */
#define ASTIM_OUTPUT_SLW                    (* (reg8 *) ASTIM_OUTPUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ASTIM_OUTPUT_PRTDSI__CAPS_SEL       (* (reg8 *) ASTIM_OUTPUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ASTIM_OUTPUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ASTIM_OUTPUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ASTIM_OUTPUT_PRTDSI__OE_SEL0        (* (reg8 *) ASTIM_OUTPUT__PRTDSI__OE_SEL0) 
#define ASTIM_OUTPUT_PRTDSI__OE_SEL1        (* (reg8 *) ASTIM_OUTPUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ASTIM_OUTPUT_PRTDSI__OUT_SEL0       (* (reg8 *) ASTIM_OUTPUT__PRTDSI__OUT_SEL0) 
#define ASTIM_OUTPUT_PRTDSI__OUT_SEL1       (* (reg8 *) ASTIM_OUTPUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ASTIM_OUTPUT_PRTDSI__SYNC_OUT       (* (reg8 *) ASTIM_OUTPUT__PRTDSI__SYNC_OUT) 


#if defined(ASTIM_OUTPUT__INTSTAT)  /* Interrupt Registers */

    #define ASTIM_OUTPUT_INTSTAT                (* (reg8 *) ASTIM_OUTPUT__INTSTAT)
    #define ASTIM_OUTPUT_SNAP                   (* (reg8 *) ASTIM_OUTPUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ASTIM_OUTPUT_H */


/* [] END OF FILE */
