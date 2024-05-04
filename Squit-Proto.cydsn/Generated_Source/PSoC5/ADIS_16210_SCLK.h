/*******************************************************************************
* File Name: ADIS_16210_SCLK.h  
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

#if !defined(CY_PINS_ADIS_16210_SCLK_H) /* Pins ADIS_16210_SCLK_H */
#define CY_PINS_ADIS_16210_SCLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADIS_16210_SCLK_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADIS_16210_SCLK__PORT == 15 && ((ADIS_16210_SCLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADIS_16210_SCLK_Write(uint8 value) ;
void    ADIS_16210_SCLK_SetDriveMode(uint8 mode) ;
uint8   ADIS_16210_SCLK_ReadDataReg(void) ;
uint8   ADIS_16210_SCLK_Read(void) ;
uint8   ADIS_16210_SCLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADIS_16210_SCLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADIS_16210_SCLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADIS_16210_SCLK_DM_RES_UP          PIN_DM_RES_UP
#define ADIS_16210_SCLK_DM_RES_DWN         PIN_DM_RES_DWN
#define ADIS_16210_SCLK_DM_OD_LO           PIN_DM_OD_LO
#define ADIS_16210_SCLK_DM_OD_HI           PIN_DM_OD_HI
#define ADIS_16210_SCLK_DM_STRONG          PIN_DM_STRONG
#define ADIS_16210_SCLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADIS_16210_SCLK_MASK               ADIS_16210_SCLK__MASK
#define ADIS_16210_SCLK_SHIFT              ADIS_16210_SCLK__SHIFT
#define ADIS_16210_SCLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADIS_16210_SCLK_PS                     (* (reg8 *) ADIS_16210_SCLK__PS)
/* Data Register */
#define ADIS_16210_SCLK_DR                     (* (reg8 *) ADIS_16210_SCLK__DR)
/* Port Number */
#define ADIS_16210_SCLK_PRT_NUM                (* (reg8 *) ADIS_16210_SCLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ADIS_16210_SCLK_AG                     (* (reg8 *) ADIS_16210_SCLK__AG)                       
/* Analog MUX bux enable */
#define ADIS_16210_SCLK_AMUX                   (* (reg8 *) ADIS_16210_SCLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ADIS_16210_SCLK_BIE                    (* (reg8 *) ADIS_16210_SCLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ADIS_16210_SCLK_BIT_MASK               (* (reg8 *) ADIS_16210_SCLK__BIT_MASK)
/* Bypass Enable */
#define ADIS_16210_SCLK_BYP                    (* (reg8 *) ADIS_16210_SCLK__BYP)
/* Port wide control signals */                                                   
#define ADIS_16210_SCLK_CTL                    (* (reg8 *) ADIS_16210_SCLK__CTL)
/* Drive Modes */
#define ADIS_16210_SCLK_DM0                    (* (reg8 *) ADIS_16210_SCLK__DM0) 
#define ADIS_16210_SCLK_DM1                    (* (reg8 *) ADIS_16210_SCLK__DM1)
#define ADIS_16210_SCLK_DM2                    (* (reg8 *) ADIS_16210_SCLK__DM2) 
/* Input Buffer Disable Override */
#define ADIS_16210_SCLK_INP_DIS                (* (reg8 *) ADIS_16210_SCLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ADIS_16210_SCLK_LCD_COM_SEG            (* (reg8 *) ADIS_16210_SCLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADIS_16210_SCLK_LCD_EN                 (* (reg8 *) ADIS_16210_SCLK__LCD_EN)
/* Slew Rate Control */
#define ADIS_16210_SCLK_SLW                    (* (reg8 *) ADIS_16210_SCLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADIS_16210_SCLK_PRTDSI__CAPS_SEL       (* (reg8 *) ADIS_16210_SCLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADIS_16210_SCLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADIS_16210_SCLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADIS_16210_SCLK_PRTDSI__OE_SEL0        (* (reg8 *) ADIS_16210_SCLK__PRTDSI__OE_SEL0) 
#define ADIS_16210_SCLK_PRTDSI__OE_SEL1        (* (reg8 *) ADIS_16210_SCLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADIS_16210_SCLK_PRTDSI__OUT_SEL0       (* (reg8 *) ADIS_16210_SCLK__PRTDSI__OUT_SEL0) 
#define ADIS_16210_SCLK_PRTDSI__OUT_SEL1       (* (reg8 *) ADIS_16210_SCLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADIS_16210_SCLK_PRTDSI__SYNC_OUT       (* (reg8 *) ADIS_16210_SCLK__PRTDSI__SYNC_OUT) 


#if defined(ADIS_16210_SCLK__INTSTAT)  /* Interrupt Registers */

    #define ADIS_16210_SCLK_INTSTAT                (* (reg8 *) ADIS_16210_SCLK__INTSTAT)
    #define ADIS_16210_SCLK_SNAP                   (* (reg8 *) ADIS_16210_SCLK__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADIS_16210_SCLK_H */


/* [] END OF FILE */
