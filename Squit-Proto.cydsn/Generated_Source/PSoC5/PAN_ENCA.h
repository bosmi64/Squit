/*******************************************************************************
* File Name: PAN_ENCA.h  
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

#if !defined(CY_PINS_PAN_ENCA_H) /* Pins PAN_ENCA_H */
#define CY_PINS_PAN_ENCA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PAN_ENCA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PAN_ENCA__PORT == 15 && ((PAN_ENCA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PAN_ENCA_Write(uint8 value) ;
void    PAN_ENCA_SetDriveMode(uint8 mode) ;
uint8   PAN_ENCA_ReadDataReg(void) ;
uint8   PAN_ENCA_Read(void) ;
uint8   PAN_ENCA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PAN_ENCA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PAN_ENCA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PAN_ENCA_DM_RES_UP          PIN_DM_RES_UP
#define PAN_ENCA_DM_RES_DWN         PIN_DM_RES_DWN
#define PAN_ENCA_DM_OD_LO           PIN_DM_OD_LO
#define PAN_ENCA_DM_OD_HI           PIN_DM_OD_HI
#define PAN_ENCA_DM_STRONG          PIN_DM_STRONG
#define PAN_ENCA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PAN_ENCA_MASK               PAN_ENCA__MASK
#define PAN_ENCA_SHIFT              PAN_ENCA__SHIFT
#define PAN_ENCA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PAN_ENCA_PS                     (* (reg8 *) PAN_ENCA__PS)
/* Data Register */
#define PAN_ENCA_DR                     (* (reg8 *) PAN_ENCA__DR)
/* Port Number */
#define PAN_ENCA_PRT_NUM                (* (reg8 *) PAN_ENCA__PRT) 
/* Connect to Analog Globals */                                                  
#define PAN_ENCA_AG                     (* (reg8 *) PAN_ENCA__AG)                       
/* Analog MUX bux enable */
#define PAN_ENCA_AMUX                   (* (reg8 *) PAN_ENCA__AMUX) 
/* Bidirectional Enable */                                                        
#define PAN_ENCA_BIE                    (* (reg8 *) PAN_ENCA__BIE)
/* Bit-mask for Aliased Register Access */
#define PAN_ENCA_BIT_MASK               (* (reg8 *) PAN_ENCA__BIT_MASK)
/* Bypass Enable */
#define PAN_ENCA_BYP                    (* (reg8 *) PAN_ENCA__BYP)
/* Port wide control signals */                                                   
#define PAN_ENCA_CTL                    (* (reg8 *) PAN_ENCA__CTL)
/* Drive Modes */
#define PAN_ENCA_DM0                    (* (reg8 *) PAN_ENCA__DM0) 
#define PAN_ENCA_DM1                    (* (reg8 *) PAN_ENCA__DM1)
#define PAN_ENCA_DM2                    (* (reg8 *) PAN_ENCA__DM2) 
/* Input Buffer Disable Override */
#define PAN_ENCA_INP_DIS                (* (reg8 *) PAN_ENCA__INP_DIS)
/* LCD Common or Segment Drive */
#define PAN_ENCA_LCD_COM_SEG            (* (reg8 *) PAN_ENCA__LCD_COM_SEG)
/* Enable Segment LCD */
#define PAN_ENCA_LCD_EN                 (* (reg8 *) PAN_ENCA__LCD_EN)
/* Slew Rate Control */
#define PAN_ENCA_SLW                    (* (reg8 *) PAN_ENCA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PAN_ENCA_PRTDSI__CAPS_SEL       (* (reg8 *) PAN_ENCA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PAN_ENCA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PAN_ENCA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PAN_ENCA_PRTDSI__OE_SEL0        (* (reg8 *) PAN_ENCA__PRTDSI__OE_SEL0) 
#define PAN_ENCA_PRTDSI__OE_SEL1        (* (reg8 *) PAN_ENCA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PAN_ENCA_PRTDSI__OUT_SEL0       (* (reg8 *) PAN_ENCA__PRTDSI__OUT_SEL0) 
#define PAN_ENCA_PRTDSI__OUT_SEL1       (* (reg8 *) PAN_ENCA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PAN_ENCA_PRTDSI__SYNC_OUT       (* (reg8 *) PAN_ENCA__PRTDSI__SYNC_OUT) 


#if defined(PAN_ENCA__INTSTAT)  /* Interrupt Registers */

    #define PAN_ENCA_INTSTAT                (* (reg8 *) PAN_ENCA__INTSTAT)
    #define PAN_ENCA_SNAP                   (* (reg8 *) PAN_ENCA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PAN_ENCA_H */


/* [] END OF FILE */
