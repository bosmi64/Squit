/*******************************************************************************
* File Name: MOTOR_FL.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MOTOR_FL_H) /* Pins MOTOR_FL_H */
#define CY_PINS_MOTOR_FL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOTOR_FL_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOTOR_FL__PORT == 15 && ((MOTOR_FL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MOTOR_FL_Write(uint8 value) ;
void    MOTOR_FL_SetDriveMode(uint8 mode) ;
uint8   MOTOR_FL_ReadDataReg(void) ;
uint8   MOTOR_FL_Read(void) ;
uint8   MOTOR_FL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOTOR_FL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MOTOR_FL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MOTOR_FL_DM_RES_UP          PIN_DM_RES_UP
#define MOTOR_FL_DM_RES_DWN         PIN_DM_RES_DWN
#define MOTOR_FL_DM_OD_LO           PIN_DM_OD_LO
#define MOTOR_FL_DM_OD_HI           PIN_DM_OD_HI
#define MOTOR_FL_DM_STRONG          PIN_DM_STRONG
#define MOTOR_FL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MOTOR_FL_MASK               MOTOR_FL__MASK
#define MOTOR_FL_SHIFT              MOTOR_FL__SHIFT
#define MOTOR_FL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOTOR_FL_PS                     (* (reg8 *) MOTOR_FL__PS)
/* Data Register */
#define MOTOR_FL_DR                     (* (reg8 *) MOTOR_FL__DR)
/* Port Number */
#define MOTOR_FL_PRT_NUM                (* (reg8 *) MOTOR_FL__PRT) 
/* Connect to Analog Globals */                                                  
#define MOTOR_FL_AG                     (* (reg8 *) MOTOR_FL__AG)                       
/* Analog MUX bux enable */
#define MOTOR_FL_AMUX                   (* (reg8 *) MOTOR_FL__AMUX) 
/* Bidirectional Enable */                                                        
#define MOTOR_FL_BIE                    (* (reg8 *) MOTOR_FL__BIE)
/* Bit-mask for Aliased Register Access */
#define MOTOR_FL_BIT_MASK               (* (reg8 *) MOTOR_FL__BIT_MASK)
/* Bypass Enable */
#define MOTOR_FL_BYP                    (* (reg8 *) MOTOR_FL__BYP)
/* Port wide control signals */                                                   
#define MOTOR_FL_CTL                    (* (reg8 *) MOTOR_FL__CTL)
/* Drive Modes */
#define MOTOR_FL_DM0                    (* (reg8 *) MOTOR_FL__DM0) 
#define MOTOR_FL_DM1                    (* (reg8 *) MOTOR_FL__DM1)
#define MOTOR_FL_DM2                    (* (reg8 *) MOTOR_FL__DM2) 
/* Input Buffer Disable Override */
#define MOTOR_FL_INP_DIS                (* (reg8 *) MOTOR_FL__INP_DIS)
/* LCD Common or Segment Drive */
#define MOTOR_FL_LCD_COM_SEG            (* (reg8 *) MOTOR_FL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOTOR_FL_LCD_EN                 (* (reg8 *) MOTOR_FL__LCD_EN)
/* Slew Rate Control */
#define MOTOR_FL_SLW                    (* (reg8 *) MOTOR_FL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOTOR_FL_PRTDSI__CAPS_SEL       (* (reg8 *) MOTOR_FL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOTOR_FL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOTOR_FL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOTOR_FL_PRTDSI__OE_SEL0        (* (reg8 *) MOTOR_FL__PRTDSI__OE_SEL0) 
#define MOTOR_FL_PRTDSI__OE_SEL1        (* (reg8 *) MOTOR_FL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOTOR_FL_PRTDSI__OUT_SEL0       (* (reg8 *) MOTOR_FL__PRTDSI__OUT_SEL0) 
#define MOTOR_FL_PRTDSI__OUT_SEL1       (* (reg8 *) MOTOR_FL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOTOR_FL_PRTDSI__SYNC_OUT       (* (reg8 *) MOTOR_FL__PRTDSI__SYNC_OUT) 


#if defined(MOTOR_FL__INTSTAT)  /* Interrupt Registers */

    #define MOTOR_FL_INTSTAT                (* (reg8 *) MOTOR_FL__INTSTAT)
    #define MOTOR_FL_SNAP                   (* (reg8 *) MOTOR_FL__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOTOR_FL_H */


/* [] END OF FILE */
