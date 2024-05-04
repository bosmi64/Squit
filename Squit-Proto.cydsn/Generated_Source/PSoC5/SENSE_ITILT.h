/*******************************************************************************
* File Name: SENSE_ITILT.h  
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

#if !defined(CY_PINS_SENSE_ITILT_H) /* Pins SENSE_ITILT_H */
#define CY_PINS_SENSE_ITILT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SENSE_ITILT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SENSE_ITILT__PORT == 15 && ((SENSE_ITILT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SENSE_ITILT_Write(uint8 value) ;
void    SENSE_ITILT_SetDriveMode(uint8 mode) ;
uint8   SENSE_ITILT_ReadDataReg(void) ;
uint8   SENSE_ITILT_Read(void) ;
uint8   SENSE_ITILT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SENSE_ITILT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SENSE_ITILT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SENSE_ITILT_DM_RES_UP          PIN_DM_RES_UP
#define SENSE_ITILT_DM_RES_DWN         PIN_DM_RES_DWN
#define SENSE_ITILT_DM_OD_LO           PIN_DM_OD_LO
#define SENSE_ITILT_DM_OD_HI           PIN_DM_OD_HI
#define SENSE_ITILT_DM_STRONG          PIN_DM_STRONG
#define SENSE_ITILT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SENSE_ITILT_MASK               SENSE_ITILT__MASK
#define SENSE_ITILT_SHIFT              SENSE_ITILT__SHIFT
#define SENSE_ITILT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SENSE_ITILT_PS                     (* (reg8 *) SENSE_ITILT__PS)
/* Data Register */
#define SENSE_ITILT_DR                     (* (reg8 *) SENSE_ITILT__DR)
/* Port Number */
#define SENSE_ITILT_PRT_NUM                (* (reg8 *) SENSE_ITILT__PRT) 
/* Connect to Analog Globals */                                                  
#define SENSE_ITILT_AG                     (* (reg8 *) SENSE_ITILT__AG)                       
/* Analog MUX bux enable */
#define SENSE_ITILT_AMUX                   (* (reg8 *) SENSE_ITILT__AMUX) 
/* Bidirectional Enable */                                                        
#define SENSE_ITILT_BIE                    (* (reg8 *) SENSE_ITILT__BIE)
/* Bit-mask for Aliased Register Access */
#define SENSE_ITILT_BIT_MASK               (* (reg8 *) SENSE_ITILT__BIT_MASK)
/* Bypass Enable */
#define SENSE_ITILT_BYP                    (* (reg8 *) SENSE_ITILT__BYP)
/* Port wide control signals */                                                   
#define SENSE_ITILT_CTL                    (* (reg8 *) SENSE_ITILT__CTL)
/* Drive Modes */
#define SENSE_ITILT_DM0                    (* (reg8 *) SENSE_ITILT__DM0) 
#define SENSE_ITILT_DM1                    (* (reg8 *) SENSE_ITILT__DM1)
#define SENSE_ITILT_DM2                    (* (reg8 *) SENSE_ITILT__DM2) 
/* Input Buffer Disable Override */
#define SENSE_ITILT_INP_DIS                (* (reg8 *) SENSE_ITILT__INP_DIS)
/* LCD Common or Segment Drive */
#define SENSE_ITILT_LCD_COM_SEG            (* (reg8 *) SENSE_ITILT__LCD_COM_SEG)
/* Enable Segment LCD */
#define SENSE_ITILT_LCD_EN                 (* (reg8 *) SENSE_ITILT__LCD_EN)
/* Slew Rate Control */
#define SENSE_ITILT_SLW                    (* (reg8 *) SENSE_ITILT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SENSE_ITILT_PRTDSI__CAPS_SEL       (* (reg8 *) SENSE_ITILT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SENSE_ITILT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SENSE_ITILT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SENSE_ITILT_PRTDSI__OE_SEL0        (* (reg8 *) SENSE_ITILT__PRTDSI__OE_SEL0) 
#define SENSE_ITILT_PRTDSI__OE_SEL1        (* (reg8 *) SENSE_ITILT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SENSE_ITILT_PRTDSI__OUT_SEL0       (* (reg8 *) SENSE_ITILT__PRTDSI__OUT_SEL0) 
#define SENSE_ITILT_PRTDSI__OUT_SEL1       (* (reg8 *) SENSE_ITILT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SENSE_ITILT_PRTDSI__SYNC_OUT       (* (reg8 *) SENSE_ITILT__PRTDSI__SYNC_OUT) 


#if defined(SENSE_ITILT__INTSTAT)  /* Interrupt Registers */

    #define SENSE_ITILT_INTSTAT                (* (reg8 *) SENSE_ITILT__INTSTAT)
    #define SENSE_ITILT_SNAP                   (* (reg8 *) SENSE_ITILT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SENSE_ITILT_H */


/* [] END OF FILE */
