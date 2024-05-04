/*******************************************************************************
* File Name: ANAPOS_OUTPUT.h  
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

#if !defined(CY_PINS_ANAPOS_OUTPUT_H) /* Pins ANAPOS_OUTPUT_H */
#define CY_PINS_ANAPOS_OUTPUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ANAPOS_OUTPUT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ANAPOS_OUTPUT__PORT == 15 && ((ANAPOS_OUTPUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ANAPOS_OUTPUT_Write(uint8 value) ;
void    ANAPOS_OUTPUT_SetDriveMode(uint8 mode) ;
uint8   ANAPOS_OUTPUT_ReadDataReg(void) ;
uint8   ANAPOS_OUTPUT_Read(void) ;
uint8   ANAPOS_OUTPUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ANAPOS_OUTPUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ANAPOS_OUTPUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ANAPOS_OUTPUT_DM_RES_UP          PIN_DM_RES_UP
#define ANAPOS_OUTPUT_DM_RES_DWN         PIN_DM_RES_DWN
#define ANAPOS_OUTPUT_DM_OD_LO           PIN_DM_OD_LO
#define ANAPOS_OUTPUT_DM_OD_HI           PIN_DM_OD_HI
#define ANAPOS_OUTPUT_DM_STRONG          PIN_DM_STRONG
#define ANAPOS_OUTPUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ANAPOS_OUTPUT_MASK               ANAPOS_OUTPUT__MASK
#define ANAPOS_OUTPUT_SHIFT              ANAPOS_OUTPUT__SHIFT
#define ANAPOS_OUTPUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ANAPOS_OUTPUT_PS                     (* (reg8 *) ANAPOS_OUTPUT__PS)
/* Data Register */
#define ANAPOS_OUTPUT_DR                     (* (reg8 *) ANAPOS_OUTPUT__DR)
/* Port Number */
#define ANAPOS_OUTPUT_PRT_NUM                (* (reg8 *) ANAPOS_OUTPUT__PRT) 
/* Connect to Analog Globals */                                                  
#define ANAPOS_OUTPUT_AG                     (* (reg8 *) ANAPOS_OUTPUT__AG)                       
/* Analog MUX bux enable */
#define ANAPOS_OUTPUT_AMUX                   (* (reg8 *) ANAPOS_OUTPUT__AMUX) 
/* Bidirectional Enable */                                                        
#define ANAPOS_OUTPUT_BIE                    (* (reg8 *) ANAPOS_OUTPUT__BIE)
/* Bit-mask for Aliased Register Access */
#define ANAPOS_OUTPUT_BIT_MASK               (* (reg8 *) ANAPOS_OUTPUT__BIT_MASK)
/* Bypass Enable */
#define ANAPOS_OUTPUT_BYP                    (* (reg8 *) ANAPOS_OUTPUT__BYP)
/* Port wide control signals */                                                   
#define ANAPOS_OUTPUT_CTL                    (* (reg8 *) ANAPOS_OUTPUT__CTL)
/* Drive Modes */
#define ANAPOS_OUTPUT_DM0                    (* (reg8 *) ANAPOS_OUTPUT__DM0) 
#define ANAPOS_OUTPUT_DM1                    (* (reg8 *) ANAPOS_OUTPUT__DM1)
#define ANAPOS_OUTPUT_DM2                    (* (reg8 *) ANAPOS_OUTPUT__DM2) 
/* Input Buffer Disable Override */
#define ANAPOS_OUTPUT_INP_DIS                (* (reg8 *) ANAPOS_OUTPUT__INP_DIS)
/* LCD Common or Segment Drive */
#define ANAPOS_OUTPUT_LCD_COM_SEG            (* (reg8 *) ANAPOS_OUTPUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define ANAPOS_OUTPUT_LCD_EN                 (* (reg8 *) ANAPOS_OUTPUT__LCD_EN)
/* Slew Rate Control */
#define ANAPOS_OUTPUT_SLW                    (* (reg8 *) ANAPOS_OUTPUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ANAPOS_OUTPUT_PRTDSI__CAPS_SEL       (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ANAPOS_OUTPUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ANAPOS_OUTPUT_PRTDSI__OE_SEL0        (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__OE_SEL0) 
#define ANAPOS_OUTPUT_PRTDSI__OE_SEL1        (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ANAPOS_OUTPUT_PRTDSI__OUT_SEL0       (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__OUT_SEL0) 
#define ANAPOS_OUTPUT_PRTDSI__OUT_SEL1       (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ANAPOS_OUTPUT_PRTDSI__SYNC_OUT       (* (reg8 *) ANAPOS_OUTPUT__PRTDSI__SYNC_OUT) 


#if defined(ANAPOS_OUTPUT__INTSTAT)  /* Interrupt Registers */

    #define ANAPOS_OUTPUT_INTSTAT                (* (reg8 *) ANAPOS_OUTPUT__INTSTAT)
    #define ANAPOS_OUTPUT_SNAP                   (* (reg8 *) ANAPOS_OUTPUT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ANAPOS_OUTPUT_H */


/* [] END OF FILE */
