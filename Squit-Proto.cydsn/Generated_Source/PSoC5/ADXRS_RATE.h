/*******************************************************************************
* File Name: ADXRS_RATE.h  
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

#if !defined(CY_PINS_ADXRS_RATE_H) /* Pins ADXRS_RATE_H */
#define CY_PINS_ADXRS_RATE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXRS_RATE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADXRS_RATE__PORT == 15 && ((ADXRS_RATE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXRS_RATE_Write(uint8 value) ;
void    ADXRS_RATE_SetDriveMode(uint8 mode) ;
uint8   ADXRS_RATE_ReadDataReg(void) ;
uint8   ADXRS_RATE_Read(void) ;
uint8   ADXRS_RATE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXRS_RATE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXRS_RATE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXRS_RATE_DM_RES_UP          PIN_DM_RES_UP
#define ADXRS_RATE_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXRS_RATE_DM_OD_LO           PIN_DM_OD_LO
#define ADXRS_RATE_DM_OD_HI           PIN_DM_OD_HI
#define ADXRS_RATE_DM_STRONG          PIN_DM_STRONG
#define ADXRS_RATE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXRS_RATE_MASK               ADXRS_RATE__MASK
#define ADXRS_RATE_SHIFT              ADXRS_RATE__SHIFT
#define ADXRS_RATE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXRS_RATE_PS                     (* (reg8 *) ADXRS_RATE__PS)
/* Data Register */
#define ADXRS_RATE_DR                     (* (reg8 *) ADXRS_RATE__DR)
/* Port Number */
#define ADXRS_RATE_PRT_NUM                (* (reg8 *) ADXRS_RATE__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXRS_RATE_AG                     (* (reg8 *) ADXRS_RATE__AG)                       
/* Analog MUX bux enable */
#define ADXRS_RATE_AMUX                   (* (reg8 *) ADXRS_RATE__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXRS_RATE_BIE                    (* (reg8 *) ADXRS_RATE__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXRS_RATE_BIT_MASK               (* (reg8 *) ADXRS_RATE__BIT_MASK)
/* Bypass Enable */
#define ADXRS_RATE_BYP                    (* (reg8 *) ADXRS_RATE__BYP)
/* Port wide control signals */                                                   
#define ADXRS_RATE_CTL                    (* (reg8 *) ADXRS_RATE__CTL)
/* Drive Modes */
#define ADXRS_RATE_DM0                    (* (reg8 *) ADXRS_RATE__DM0) 
#define ADXRS_RATE_DM1                    (* (reg8 *) ADXRS_RATE__DM1)
#define ADXRS_RATE_DM2                    (* (reg8 *) ADXRS_RATE__DM2) 
/* Input Buffer Disable Override */
#define ADXRS_RATE_INP_DIS                (* (reg8 *) ADXRS_RATE__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXRS_RATE_LCD_COM_SEG            (* (reg8 *) ADXRS_RATE__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXRS_RATE_LCD_EN                 (* (reg8 *) ADXRS_RATE__LCD_EN)
/* Slew Rate Control */
#define ADXRS_RATE_SLW                    (* (reg8 *) ADXRS_RATE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXRS_RATE_PRTDSI__CAPS_SEL       (* (reg8 *) ADXRS_RATE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXRS_RATE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXRS_RATE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXRS_RATE_PRTDSI__OE_SEL0        (* (reg8 *) ADXRS_RATE__PRTDSI__OE_SEL0) 
#define ADXRS_RATE_PRTDSI__OE_SEL1        (* (reg8 *) ADXRS_RATE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXRS_RATE_PRTDSI__OUT_SEL0       (* (reg8 *) ADXRS_RATE__PRTDSI__OUT_SEL0) 
#define ADXRS_RATE_PRTDSI__OUT_SEL1       (* (reg8 *) ADXRS_RATE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXRS_RATE_PRTDSI__SYNC_OUT       (* (reg8 *) ADXRS_RATE__PRTDSI__SYNC_OUT) 


#if defined(ADXRS_RATE__INTSTAT)  /* Interrupt Registers */

    #define ADXRS_RATE_INTSTAT                (* (reg8 *) ADXRS_RATE__INTSTAT)
    #define ADXRS_RATE_SNAP                   (* (reg8 *) ADXRS_RATE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADXRS_RATE_H */


/* [] END OF FILE */
