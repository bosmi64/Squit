/*******************************************************************************
* File Name: ENC_B.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_ENC_B_H) /* Pins ENC_B_H */
#define CY_PINS_ENC_B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ENC_B_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ENC_B_Write(uint8 value) ;
void    ENC_B_SetDriveMode(uint8 mode) ;
uint8   ENC_B_ReadDataReg(void) ;
uint8   ENC_B_Read(void) ;
uint8   ENC_B_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENC_B_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ENC_B_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ENC_B_DM_RES_UP          PIN_DM_RES_UP
#define ENC_B_DM_RES_DWN         PIN_DM_RES_DWN
#define ENC_B_DM_OD_LO           PIN_DM_OD_LO
#define ENC_B_DM_OD_HI           PIN_DM_OD_HI
#define ENC_B_DM_STRONG          PIN_DM_STRONG
#define ENC_B_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ENC_B_MASK               ENC_B__MASK
#define ENC_B_SHIFT              ENC_B__SHIFT
#define ENC_B_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENC_B_PS                     (* (reg8 *) ENC_B__PS)
/* Data Register */
#define ENC_B_DR                     (* (reg8 *) ENC_B__DR)
/* Port Number */
#define ENC_B_PRT_NUM                (* (reg8 *) ENC_B__PRT) 
/* Connect to Analog Globals */                                                  
#define ENC_B_AG                     (* (reg8 *) ENC_B__AG)                       
/* Analog MUX bux enable */
#define ENC_B_AMUX                   (* (reg8 *) ENC_B__AMUX) 
/* Bidirectional Enable */                                                        
#define ENC_B_BIE                    (* (reg8 *) ENC_B__BIE)
/* Bit-mask for Aliased Register Access */
#define ENC_B_BIT_MASK               (* (reg8 *) ENC_B__BIT_MASK)
/* Bypass Enable */
#define ENC_B_BYP                    (* (reg8 *) ENC_B__BYP)
/* Port wide control signals */                                                   
#define ENC_B_CTL                    (* (reg8 *) ENC_B__CTL)
/* Drive Modes */
#define ENC_B_DM0                    (* (reg8 *) ENC_B__DM0) 
#define ENC_B_DM1                    (* (reg8 *) ENC_B__DM1)
#define ENC_B_DM2                    (* (reg8 *) ENC_B__DM2) 
/* Input Buffer Disable Override */
#define ENC_B_INP_DIS                (* (reg8 *) ENC_B__INP_DIS)
/* LCD Common or Segment Drive */
#define ENC_B_LCD_COM_SEG            (* (reg8 *) ENC_B__LCD_COM_SEG)
/* Enable Segment LCD */
#define ENC_B_LCD_EN                 (* (reg8 *) ENC_B__LCD_EN)
/* Slew Rate Control */
#define ENC_B_SLW                    (* (reg8 *) ENC_B__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ENC_B_PRTDSI__CAPS_SEL       (* (reg8 *) ENC_B__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ENC_B_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ENC_B__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ENC_B_PRTDSI__OE_SEL0        (* (reg8 *) ENC_B__PRTDSI__OE_SEL0) 
#define ENC_B_PRTDSI__OE_SEL1        (* (reg8 *) ENC_B__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ENC_B_PRTDSI__OUT_SEL0       (* (reg8 *) ENC_B__PRTDSI__OUT_SEL0) 
#define ENC_B_PRTDSI__OUT_SEL1       (* (reg8 *) ENC_B__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ENC_B_PRTDSI__SYNC_OUT       (* (reg8 *) ENC_B__PRTDSI__SYNC_OUT) 


#if defined(ENC_B__INTSTAT)  /* Interrupt Registers */

    #define ENC_B_INTSTAT                (* (reg8 *) ENC_B__INTSTAT)
    #define ENC_B_SNAP                   (* (reg8 *) ENC_B__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ENC_B_H */


/* [] END OF FILE */
