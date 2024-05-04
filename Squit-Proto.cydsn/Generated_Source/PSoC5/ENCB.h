/*******************************************************************************
* File Name: ENCB.h  
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

#if !defined(CY_PINS_ENCB_H) /* Pins ENCB_H */
#define CY_PINS_ENCB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ENCB_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ENCB__PORT == 15 && ((ENCB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ENCB_Write(uint8 value) ;
void    ENCB_SetDriveMode(uint8 mode) ;
uint8   ENCB_ReadDataReg(void) ;
uint8   ENCB_Read(void) ;
uint8   ENCB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENCB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ENCB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ENCB_DM_RES_UP          PIN_DM_RES_UP
#define ENCB_DM_RES_DWN         PIN_DM_RES_DWN
#define ENCB_DM_OD_LO           PIN_DM_OD_LO
#define ENCB_DM_OD_HI           PIN_DM_OD_HI
#define ENCB_DM_STRONG          PIN_DM_STRONG
#define ENCB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ENCB_MASK               ENCB__MASK
#define ENCB_SHIFT              ENCB__SHIFT
#define ENCB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENCB_PS                     (* (reg8 *) ENCB__PS)
/* Data Register */
#define ENCB_DR                     (* (reg8 *) ENCB__DR)
/* Port Number */
#define ENCB_PRT_NUM                (* (reg8 *) ENCB__PRT) 
/* Connect to Analog Globals */                                                  
#define ENCB_AG                     (* (reg8 *) ENCB__AG)                       
/* Analog MUX bux enable */
#define ENCB_AMUX                   (* (reg8 *) ENCB__AMUX) 
/* Bidirectional Enable */                                                        
#define ENCB_BIE                    (* (reg8 *) ENCB__BIE)
/* Bit-mask for Aliased Register Access */
#define ENCB_BIT_MASK               (* (reg8 *) ENCB__BIT_MASK)
/* Bypass Enable */
#define ENCB_BYP                    (* (reg8 *) ENCB__BYP)
/* Port wide control signals */                                                   
#define ENCB_CTL                    (* (reg8 *) ENCB__CTL)
/* Drive Modes */
#define ENCB_DM0                    (* (reg8 *) ENCB__DM0) 
#define ENCB_DM1                    (* (reg8 *) ENCB__DM1)
#define ENCB_DM2                    (* (reg8 *) ENCB__DM2) 
/* Input Buffer Disable Override */
#define ENCB_INP_DIS                (* (reg8 *) ENCB__INP_DIS)
/* LCD Common or Segment Drive */
#define ENCB_LCD_COM_SEG            (* (reg8 *) ENCB__LCD_COM_SEG)
/* Enable Segment LCD */
#define ENCB_LCD_EN                 (* (reg8 *) ENCB__LCD_EN)
/* Slew Rate Control */
#define ENCB_SLW                    (* (reg8 *) ENCB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ENCB_PRTDSI__CAPS_SEL       (* (reg8 *) ENCB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ENCB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ENCB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ENCB_PRTDSI__OE_SEL0        (* (reg8 *) ENCB__PRTDSI__OE_SEL0) 
#define ENCB_PRTDSI__OE_SEL1        (* (reg8 *) ENCB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ENCB_PRTDSI__OUT_SEL0       (* (reg8 *) ENCB__PRTDSI__OUT_SEL0) 
#define ENCB_PRTDSI__OUT_SEL1       (* (reg8 *) ENCB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ENCB_PRTDSI__SYNC_OUT       (* (reg8 *) ENCB__PRTDSI__SYNC_OUT) 


#if defined(ENCB__INTSTAT)  /* Interrupt Registers */

    #define ENCB_INTSTAT                (* (reg8 *) ENCB__INTSTAT)
    #define ENCB_SNAP                   (* (reg8 *) ENCB__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ENCB_H */


/* [] END OF FILE */
