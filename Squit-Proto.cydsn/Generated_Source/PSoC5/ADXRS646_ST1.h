/*******************************************************************************
* File Name: ADXRS646_ST1.h  
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

#if !defined(CY_PINS_ADXRS646_ST1_H) /* Pins ADXRS646_ST1_H */
#define CY_PINS_ADXRS646_ST1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXRS646_ST1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADXRS646_ST1__PORT == 15 && ((ADXRS646_ST1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXRS646_ST1_Write(uint8 value) ;
void    ADXRS646_ST1_SetDriveMode(uint8 mode) ;
uint8   ADXRS646_ST1_ReadDataReg(void) ;
uint8   ADXRS646_ST1_Read(void) ;
uint8   ADXRS646_ST1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXRS646_ST1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXRS646_ST1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXRS646_ST1_DM_RES_UP          PIN_DM_RES_UP
#define ADXRS646_ST1_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXRS646_ST1_DM_OD_LO           PIN_DM_OD_LO
#define ADXRS646_ST1_DM_OD_HI           PIN_DM_OD_HI
#define ADXRS646_ST1_DM_STRONG          PIN_DM_STRONG
#define ADXRS646_ST1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXRS646_ST1_MASK               ADXRS646_ST1__MASK
#define ADXRS646_ST1_SHIFT              ADXRS646_ST1__SHIFT
#define ADXRS646_ST1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXRS646_ST1_PS                     (* (reg8 *) ADXRS646_ST1__PS)
/* Data Register */
#define ADXRS646_ST1_DR                     (* (reg8 *) ADXRS646_ST1__DR)
/* Port Number */
#define ADXRS646_ST1_PRT_NUM                (* (reg8 *) ADXRS646_ST1__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXRS646_ST1_AG                     (* (reg8 *) ADXRS646_ST1__AG)                       
/* Analog MUX bux enable */
#define ADXRS646_ST1_AMUX                   (* (reg8 *) ADXRS646_ST1__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXRS646_ST1_BIE                    (* (reg8 *) ADXRS646_ST1__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXRS646_ST1_BIT_MASK               (* (reg8 *) ADXRS646_ST1__BIT_MASK)
/* Bypass Enable */
#define ADXRS646_ST1_BYP                    (* (reg8 *) ADXRS646_ST1__BYP)
/* Port wide control signals */                                                   
#define ADXRS646_ST1_CTL                    (* (reg8 *) ADXRS646_ST1__CTL)
/* Drive Modes */
#define ADXRS646_ST1_DM0                    (* (reg8 *) ADXRS646_ST1__DM0) 
#define ADXRS646_ST1_DM1                    (* (reg8 *) ADXRS646_ST1__DM1)
#define ADXRS646_ST1_DM2                    (* (reg8 *) ADXRS646_ST1__DM2) 
/* Input Buffer Disable Override */
#define ADXRS646_ST1_INP_DIS                (* (reg8 *) ADXRS646_ST1__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXRS646_ST1_LCD_COM_SEG            (* (reg8 *) ADXRS646_ST1__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXRS646_ST1_LCD_EN                 (* (reg8 *) ADXRS646_ST1__LCD_EN)
/* Slew Rate Control */
#define ADXRS646_ST1_SLW                    (* (reg8 *) ADXRS646_ST1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXRS646_ST1_PRTDSI__CAPS_SEL       (* (reg8 *) ADXRS646_ST1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXRS646_ST1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXRS646_ST1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXRS646_ST1_PRTDSI__OE_SEL0        (* (reg8 *) ADXRS646_ST1__PRTDSI__OE_SEL0) 
#define ADXRS646_ST1_PRTDSI__OE_SEL1        (* (reg8 *) ADXRS646_ST1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXRS646_ST1_PRTDSI__OUT_SEL0       (* (reg8 *) ADXRS646_ST1__PRTDSI__OUT_SEL0) 
#define ADXRS646_ST1_PRTDSI__OUT_SEL1       (* (reg8 *) ADXRS646_ST1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXRS646_ST1_PRTDSI__SYNC_OUT       (* (reg8 *) ADXRS646_ST1__PRTDSI__SYNC_OUT) 


#if defined(ADXRS646_ST1__INTSTAT)  /* Interrupt Registers */

    #define ADXRS646_ST1_INTSTAT                (* (reg8 *) ADXRS646_ST1__INTSTAT)
    #define ADXRS646_ST1_SNAP                   (* (reg8 *) ADXRS646_ST1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADXRS646_ST1_H */


/* [] END OF FILE */
