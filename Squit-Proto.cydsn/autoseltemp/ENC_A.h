/*******************************************************************************
* File Name: ENC_A.h  
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

#if !defined(CY_PINS_ENC_A_H) /* Pins ENC_A_H */
#define CY_PINS_ENC_A_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ENC_A_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ENC_A_Write(uint8 value) ;
void    ENC_A_SetDriveMode(uint8 mode) ;
uint8   ENC_A_ReadDataReg(void) ;
uint8   ENC_A_Read(void) ;
uint8   ENC_A_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENC_A_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ENC_A_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ENC_A_DM_RES_UP          PIN_DM_RES_UP
#define ENC_A_DM_RES_DWN         PIN_DM_RES_DWN
#define ENC_A_DM_OD_LO           PIN_DM_OD_LO
#define ENC_A_DM_OD_HI           PIN_DM_OD_HI
#define ENC_A_DM_STRONG          PIN_DM_STRONG
#define ENC_A_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ENC_A_MASK               ENC_A__MASK
#define ENC_A_SHIFT              ENC_A__SHIFT
#define ENC_A_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENC_A_PS                     (* (reg8 *) ENC_A__PS)
/* Data Register */
#define ENC_A_DR                     (* (reg8 *) ENC_A__DR)
/* Port Number */
#define ENC_A_PRT_NUM                (* (reg8 *) ENC_A__PRT) 
/* Connect to Analog Globals */                                                  
#define ENC_A_AG                     (* (reg8 *) ENC_A__AG)                       
/* Analog MUX bux enable */
#define ENC_A_AMUX                   (* (reg8 *) ENC_A__AMUX) 
/* Bidirectional Enable */                                                        
#define ENC_A_BIE                    (* (reg8 *) ENC_A__BIE)
/* Bit-mask for Aliased Register Access */
#define ENC_A_BIT_MASK               (* (reg8 *) ENC_A__BIT_MASK)
/* Bypass Enable */
#define ENC_A_BYP                    (* (reg8 *) ENC_A__BYP)
/* Port wide control signals */                                                   
#define ENC_A_CTL                    (* (reg8 *) ENC_A__CTL)
/* Drive Modes */
#define ENC_A_DM0                    (* (reg8 *) ENC_A__DM0) 
#define ENC_A_DM1                    (* (reg8 *) ENC_A__DM1)
#define ENC_A_DM2                    (* (reg8 *) ENC_A__DM2) 
/* Input Buffer Disable Override */
#define ENC_A_INP_DIS                (* (reg8 *) ENC_A__INP_DIS)
/* LCD Common or Segment Drive */
#define ENC_A_LCD_COM_SEG            (* (reg8 *) ENC_A__LCD_COM_SEG)
/* Enable Segment LCD */
#define ENC_A_LCD_EN                 (* (reg8 *) ENC_A__LCD_EN)
/* Slew Rate Control */
#define ENC_A_SLW                    (* (reg8 *) ENC_A__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ENC_A_PRTDSI__CAPS_SEL       (* (reg8 *) ENC_A__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ENC_A_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ENC_A__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ENC_A_PRTDSI__OE_SEL0        (* (reg8 *) ENC_A__PRTDSI__OE_SEL0) 
#define ENC_A_PRTDSI__OE_SEL1        (* (reg8 *) ENC_A__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ENC_A_PRTDSI__OUT_SEL0       (* (reg8 *) ENC_A__PRTDSI__OUT_SEL0) 
#define ENC_A_PRTDSI__OUT_SEL1       (* (reg8 *) ENC_A__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ENC_A_PRTDSI__SYNC_OUT       (* (reg8 *) ENC_A__PRTDSI__SYNC_OUT) 


#if defined(ENC_A__INTSTAT)  /* Interrupt Registers */

    #define ENC_A_INTSTAT                (* (reg8 *) ENC_A__INTSTAT)
    #define ENC_A_SNAP                   (* (reg8 *) ENC_A__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ENC_A_H */


/* [] END OF FILE */
