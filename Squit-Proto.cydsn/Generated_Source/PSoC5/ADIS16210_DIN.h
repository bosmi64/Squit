/*******************************************************************************
* File Name: ADIS16210_DIN.h  
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

#if !defined(CY_PINS_ADIS16210_DIN_H) /* Pins ADIS16210_DIN_H */
#define CY_PINS_ADIS16210_DIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADIS16210_DIN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADIS16210_DIN__PORT == 15 && ((ADIS16210_DIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADIS16210_DIN_Write(uint8 value) ;
void    ADIS16210_DIN_SetDriveMode(uint8 mode) ;
uint8   ADIS16210_DIN_ReadDataReg(void) ;
uint8   ADIS16210_DIN_Read(void) ;
uint8   ADIS16210_DIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADIS16210_DIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADIS16210_DIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADIS16210_DIN_DM_RES_UP          PIN_DM_RES_UP
#define ADIS16210_DIN_DM_RES_DWN         PIN_DM_RES_DWN
#define ADIS16210_DIN_DM_OD_LO           PIN_DM_OD_LO
#define ADIS16210_DIN_DM_OD_HI           PIN_DM_OD_HI
#define ADIS16210_DIN_DM_STRONG          PIN_DM_STRONG
#define ADIS16210_DIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADIS16210_DIN_MASK               ADIS16210_DIN__MASK
#define ADIS16210_DIN_SHIFT              ADIS16210_DIN__SHIFT
#define ADIS16210_DIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADIS16210_DIN_PS                     (* (reg8 *) ADIS16210_DIN__PS)
/* Data Register */
#define ADIS16210_DIN_DR                     (* (reg8 *) ADIS16210_DIN__DR)
/* Port Number */
#define ADIS16210_DIN_PRT_NUM                (* (reg8 *) ADIS16210_DIN__PRT) 
/* Connect to Analog Globals */                                                  
#define ADIS16210_DIN_AG                     (* (reg8 *) ADIS16210_DIN__AG)                       
/* Analog MUX bux enable */
#define ADIS16210_DIN_AMUX                   (* (reg8 *) ADIS16210_DIN__AMUX) 
/* Bidirectional Enable */                                                        
#define ADIS16210_DIN_BIE                    (* (reg8 *) ADIS16210_DIN__BIE)
/* Bit-mask for Aliased Register Access */
#define ADIS16210_DIN_BIT_MASK               (* (reg8 *) ADIS16210_DIN__BIT_MASK)
/* Bypass Enable */
#define ADIS16210_DIN_BYP                    (* (reg8 *) ADIS16210_DIN__BYP)
/* Port wide control signals */                                                   
#define ADIS16210_DIN_CTL                    (* (reg8 *) ADIS16210_DIN__CTL)
/* Drive Modes */
#define ADIS16210_DIN_DM0                    (* (reg8 *) ADIS16210_DIN__DM0) 
#define ADIS16210_DIN_DM1                    (* (reg8 *) ADIS16210_DIN__DM1)
#define ADIS16210_DIN_DM2                    (* (reg8 *) ADIS16210_DIN__DM2) 
/* Input Buffer Disable Override */
#define ADIS16210_DIN_INP_DIS                (* (reg8 *) ADIS16210_DIN__INP_DIS)
/* LCD Common or Segment Drive */
#define ADIS16210_DIN_LCD_COM_SEG            (* (reg8 *) ADIS16210_DIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADIS16210_DIN_LCD_EN                 (* (reg8 *) ADIS16210_DIN__LCD_EN)
/* Slew Rate Control */
#define ADIS16210_DIN_SLW                    (* (reg8 *) ADIS16210_DIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADIS16210_DIN_PRTDSI__CAPS_SEL       (* (reg8 *) ADIS16210_DIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADIS16210_DIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADIS16210_DIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADIS16210_DIN_PRTDSI__OE_SEL0        (* (reg8 *) ADIS16210_DIN__PRTDSI__OE_SEL0) 
#define ADIS16210_DIN_PRTDSI__OE_SEL1        (* (reg8 *) ADIS16210_DIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADIS16210_DIN_PRTDSI__OUT_SEL0       (* (reg8 *) ADIS16210_DIN__PRTDSI__OUT_SEL0) 
#define ADIS16210_DIN_PRTDSI__OUT_SEL1       (* (reg8 *) ADIS16210_DIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADIS16210_DIN_PRTDSI__SYNC_OUT       (* (reg8 *) ADIS16210_DIN__PRTDSI__SYNC_OUT) 


#if defined(ADIS16210_DIN__INTSTAT)  /* Interrupt Registers */

    #define ADIS16210_DIN_INTSTAT                (* (reg8 *) ADIS16210_DIN__INTSTAT)
    #define ADIS16210_DIN_SNAP                   (* (reg8 *) ADIS16210_DIN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADIS16210_DIN_H */


/* [] END OF FILE */
