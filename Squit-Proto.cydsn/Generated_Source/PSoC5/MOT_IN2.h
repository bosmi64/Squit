/*******************************************************************************
* File Name: MOT_IN2.h  
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

#if !defined(CY_PINS_MOT_IN2_H) /* Pins MOT_IN2_H */
#define CY_PINS_MOT_IN2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOT_IN2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOT_IN2__PORT == 15 && ((MOT_IN2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MOT_IN2_Write(uint8 value) ;
void    MOT_IN2_SetDriveMode(uint8 mode) ;
uint8   MOT_IN2_ReadDataReg(void) ;
uint8   MOT_IN2_Read(void) ;
uint8   MOT_IN2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOT_IN2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MOT_IN2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MOT_IN2_DM_RES_UP          PIN_DM_RES_UP
#define MOT_IN2_DM_RES_DWN         PIN_DM_RES_DWN
#define MOT_IN2_DM_OD_LO           PIN_DM_OD_LO
#define MOT_IN2_DM_OD_HI           PIN_DM_OD_HI
#define MOT_IN2_DM_STRONG          PIN_DM_STRONG
#define MOT_IN2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MOT_IN2_MASK               MOT_IN2__MASK
#define MOT_IN2_SHIFT              MOT_IN2__SHIFT
#define MOT_IN2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOT_IN2_PS                     (* (reg8 *) MOT_IN2__PS)
/* Data Register */
#define MOT_IN2_DR                     (* (reg8 *) MOT_IN2__DR)
/* Port Number */
#define MOT_IN2_PRT_NUM                (* (reg8 *) MOT_IN2__PRT) 
/* Connect to Analog Globals */                                                  
#define MOT_IN2_AG                     (* (reg8 *) MOT_IN2__AG)                       
/* Analog MUX bux enable */
#define MOT_IN2_AMUX                   (* (reg8 *) MOT_IN2__AMUX) 
/* Bidirectional Enable */                                                        
#define MOT_IN2_BIE                    (* (reg8 *) MOT_IN2__BIE)
/* Bit-mask for Aliased Register Access */
#define MOT_IN2_BIT_MASK               (* (reg8 *) MOT_IN2__BIT_MASK)
/* Bypass Enable */
#define MOT_IN2_BYP                    (* (reg8 *) MOT_IN2__BYP)
/* Port wide control signals */                                                   
#define MOT_IN2_CTL                    (* (reg8 *) MOT_IN2__CTL)
/* Drive Modes */
#define MOT_IN2_DM0                    (* (reg8 *) MOT_IN2__DM0) 
#define MOT_IN2_DM1                    (* (reg8 *) MOT_IN2__DM1)
#define MOT_IN2_DM2                    (* (reg8 *) MOT_IN2__DM2) 
/* Input Buffer Disable Override */
#define MOT_IN2_INP_DIS                (* (reg8 *) MOT_IN2__INP_DIS)
/* LCD Common or Segment Drive */
#define MOT_IN2_LCD_COM_SEG            (* (reg8 *) MOT_IN2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOT_IN2_LCD_EN                 (* (reg8 *) MOT_IN2__LCD_EN)
/* Slew Rate Control */
#define MOT_IN2_SLW                    (* (reg8 *) MOT_IN2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOT_IN2_PRTDSI__CAPS_SEL       (* (reg8 *) MOT_IN2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOT_IN2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOT_IN2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOT_IN2_PRTDSI__OE_SEL0        (* (reg8 *) MOT_IN2__PRTDSI__OE_SEL0) 
#define MOT_IN2_PRTDSI__OE_SEL1        (* (reg8 *) MOT_IN2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOT_IN2_PRTDSI__OUT_SEL0       (* (reg8 *) MOT_IN2__PRTDSI__OUT_SEL0) 
#define MOT_IN2_PRTDSI__OUT_SEL1       (* (reg8 *) MOT_IN2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOT_IN2_PRTDSI__SYNC_OUT       (* (reg8 *) MOT_IN2__PRTDSI__SYNC_OUT) 


#if defined(MOT_IN2__INTSTAT)  /* Interrupt Registers */

    #define MOT_IN2_INTSTAT                (* (reg8 *) MOT_IN2__INTSTAT)
    #define MOT_IN2_SNAP                   (* (reg8 *) MOT_IN2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOT_IN2_H */


/* [] END OF FILE */
