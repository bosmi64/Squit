/*******************************************************************************
* File Name: MOT_FL.h  
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

#if !defined(CY_PINS_MOT_FL_H) /* Pins MOT_FL_H */
#define CY_PINS_MOT_FL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOT_FL_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOT_FL__PORT == 15 && ((MOT_FL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MOT_FL_Write(uint8 value) ;
void    MOT_FL_SetDriveMode(uint8 mode) ;
uint8   MOT_FL_ReadDataReg(void) ;
uint8   MOT_FL_Read(void) ;
uint8   MOT_FL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOT_FL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MOT_FL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MOT_FL_DM_RES_UP          PIN_DM_RES_UP
#define MOT_FL_DM_RES_DWN         PIN_DM_RES_DWN
#define MOT_FL_DM_OD_LO           PIN_DM_OD_LO
#define MOT_FL_DM_OD_HI           PIN_DM_OD_HI
#define MOT_FL_DM_STRONG          PIN_DM_STRONG
#define MOT_FL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MOT_FL_MASK               MOT_FL__MASK
#define MOT_FL_SHIFT              MOT_FL__SHIFT
#define MOT_FL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOT_FL_PS                     (* (reg8 *) MOT_FL__PS)
/* Data Register */
#define MOT_FL_DR                     (* (reg8 *) MOT_FL__DR)
/* Port Number */
#define MOT_FL_PRT_NUM                (* (reg8 *) MOT_FL__PRT) 
/* Connect to Analog Globals */                                                  
#define MOT_FL_AG                     (* (reg8 *) MOT_FL__AG)                       
/* Analog MUX bux enable */
#define MOT_FL_AMUX                   (* (reg8 *) MOT_FL__AMUX) 
/* Bidirectional Enable */                                                        
#define MOT_FL_BIE                    (* (reg8 *) MOT_FL__BIE)
/* Bit-mask for Aliased Register Access */
#define MOT_FL_BIT_MASK               (* (reg8 *) MOT_FL__BIT_MASK)
/* Bypass Enable */
#define MOT_FL_BYP                    (* (reg8 *) MOT_FL__BYP)
/* Port wide control signals */                                                   
#define MOT_FL_CTL                    (* (reg8 *) MOT_FL__CTL)
/* Drive Modes */
#define MOT_FL_DM0                    (* (reg8 *) MOT_FL__DM0) 
#define MOT_FL_DM1                    (* (reg8 *) MOT_FL__DM1)
#define MOT_FL_DM2                    (* (reg8 *) MOT_FL__DM2) 
/* Input Buffer Disable Override */
#define MOT_FL_INP_DIS                (* (reg8 *) MOT_FL__INP_DIS)
/* LCD Common or Segment Drive */
#define MOT_FL_LCD_COM_SEG            (* (reg8 *) MOT_FL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOT_FL_LCD_EN                 (* (reg8 *) MOT_FL__LCD_EN)
/* Slew Rate Control */
#define MOT_FL_SLW                    (* (reg8 *) MOT_FL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOT_FL_PRTDSI__CAPS_SEL       (* (reg8 *) MOT_FL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOT_FL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOT_FL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOT_FL_PRTDSI__OE_SEL0        (* (reg8 *) MOT_FL__PRTDSI__OE_SEL0) 
#define MOT_FL_PRTDSI__OE_SEL1        (* (reg8 *) MOT_FL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOT_FL_PRTDSI__OUT_SEL0       (* (reg8 *) MOT_FL__PRTDSI__OUT_SEL0) 
#define MOT_FL_PRTDSI__OUT_SEL1       (* (reg8 *) MOT_FL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOT_FL_PRTDSI__SYNC_OUT       (* (reg8 *) MOT_FL__PRTDSI__SYNC_OUT) 


#if defined(MOT_FL__INTSTAT)  /* Interrupt Registers */

    #define MOT_FL_INTSTAT                (* (reg8 *) MOT_FL__INTSTAT)
    #define MOT_FL_SNAP                   (* (reg8 *) MOT_FL__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOT_FL_H */


/* [] END OF FILE */
