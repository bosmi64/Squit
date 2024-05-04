/*******************************************************************************
* File Name: CC_nALCC.h  
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

#if !defined(CY_PINS_CC_nALCC_H) /* Pins CC_nALCC_H */
#define CY_PINS_CC_nALCC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CC_nALCC_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CC_nALCC__PORT == 15 && ((CC_nALCC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CC_nALCC_Write(uint8 value) ;
void    CC_nALCC_SetDriveMode(uint8 mode) ;
uint8   CC_nALCC_ReadDataReg(void) ;
uint8   CC_nALCC_Read(void) ;
uint8   CC_nALCC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CC_nALCC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CC_nALCC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CC_nALCC_DM_RES_UP          PIN_DM_RES_UP
#define CC_nALCC_DM_RES_DWN         PIN_DM_RES_DWN
#define CC_nALCC_DM_OD_LO           PIN_DM_OD_LO
#define CC_nALCC_DM_OD_HI           PIN_DM_OD_HI
#define CC_nALCC_DM_STRONG          PIN_DM_STRONG
#define CC_nALCC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CC_nALCC_MASK               CC_nALCC__MASK
#define CC_nALCC_SHIFT              CC_nALCC__SHIFT
#define CC_nALCC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CC_nALCC_PS                     (* (reg8 *) CC_nALCC__PS)
/* Data Register */
#define CC_nALCC_DR                     (* (reg8 *) CC_nALCC__DR)
/* Port Number */
#define CC_nALCC_PRT_NUM                (* (reg8 *) CC_nALCC__PRT) 
/* Connect to Analog Globals */                                                  
#define CC_nALCC_AG                     (* (reg8 *) CC_nALCC__AG)                       
/* Analog MUX bux enable */
#define CC_nALCC_AMUX                   (* (reg8 *) CC_nALCC__AMUX) 
/* Bidirectional Enable */                                                        
#define CC_nALCC_BIE                    (* (reg8 *) CC_nALCC__BIE)
/* Bit-mask for Aliased Register Access */
#define CC_nALCC_BIT_MASK               (* (reg8 *) CC_nALCC__BIT_MASK)
/* Bypass Enable */
#define CC_nALCC_BYP                    (* (reg8 *) CC_nALCC__BYP)
/* Port wide control signals */                                                   
#define CC_nALCC_CTL                    (* (reg8 *) CC_nALCC__CTL)
/* Drive Modes */
#define CC_nALCC_DM0                    (* (reg8 *) CC_nALCC__DM0) 
#define CC_nALCC_DM1                    (* (reg8 *) CC_nALCC__DM1)
#define CC_nALCC_DM2                    (* (reg8 *) CC_nALCC__DM2) 
/* Input Buffer Disable Override */
#define CC_nALCC_INP_DIS                (* (reg8 *) CC_nALCC__INP_DIS)
/* LCD Common or Segment Drive */
#define CC_nALCC_LCD_COM_SEG            (* (reg8 *) CC_nALCC__LCD_COM_SEG)
/* Enable Segment LCD */
#define CC_nALCC_LCD_EN                 (* (reg8 *) CC_nALCC__LCD_EN)
/* Slew Rate Control */
#define CC_nALCC_SLW                    (* (reg8 *) CC_nALCC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CC_nALCC_PRTDSI__CAPS_SEL       (* (reg8 *) CC_nALCC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CC_nALCC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CC_nALCC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CC_nALCC_PRTDSI__OE_SEL0        (* (reg8 *) CC_nALCC__PRTDSI__OE_SEL0) 
#define CC_nALCC_PRTDSI__OE_SEL1        (* (reg8 *) CC_nALCC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CC_nALCC_PRTDSI__OUT_SEL0       (* (reg8 *) CC_nALCC__PRTDSI__OUT_SEL0) 
#define CC_nALCC_PRTDSI__OUT_SEL1       (* (reg8 *) CC_nALCC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CC_nALCC_PRTDSI__SYNC_OUT       (* (reg8 *) CC_nALCC__PRTDSI__SYNC_OUT) 


#if defined(CC_nALCC__INTSTAT)  /* Interrupt Registers */

    #define CC_nALCC_INTSTAT                (* (reg8 *) CC_nALCC__INTSTAT)
    #define CC_nALCC_SNAP                   (* (reg8 *) CC_nALCC__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CC_nALCC_H */


/* [] END OF FILE */
