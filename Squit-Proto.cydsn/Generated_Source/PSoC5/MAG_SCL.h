/*******************************************************************************
* File Name: MAG_SCL.h  
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

#if !defined(CY_PINS_MAG_SCL_H) /* Pins MAG_SCL_H */
#define CY_PINS_MAG_SCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MAG_SCL_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MAG_SCL__PORT == 15 && ((MAG_SCL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MAG_SCL_Write(uint8 value) ;
void    MAG_SCL_SetDriveMode(uint8 mode) ;
uint8   MAG_SCL_ReadDataReg(void) ;
uint8   MAG_SCL_Read(void) ;
uint8   MAG_SCL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MAG_SCL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MAG_SCL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MAG_SCL_DM_RES_UP          PIN_DM_RES_UP
#define MAG_SCL_DM_RES_DWN         PIN_DM_RES_DWN
#define MAG_SCL_DM_OD_LO           PIN_DM_OD_LO
#define MAG_SCL_DM_OD_HI           PIN_DM_OD_HI
#define MAG_SCL_DM_STRONG          PIN_DM_STRONG
#define MAG_SCL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MAG_SCL_MASK               MAG_SCL__MASK
#define MAG_SCL_SHIFT              MAG_SCL__SHIFT
#define MAG_SCL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MAG_SCL_PS                     (* (reg8 *) MAG_SCL__PS)
/* Data Register */
#define MAG_SCL_DR                     (* (reg8 *) MAG_SCL__DR)
/* Port Number */
#define MAG_SCL_PRT_NUM                (* (reg8 *) MAG_SCL__PRT) 
/* Connect to Analog Globals */                                                  
#define MAG_SCL_AG                     (* (reg8 *) MAG_SCL__AG)                       
/* Analog MUX bux enable */
#define MAG_SCL_AMUX                   (* (reg8 *) MAG_SCL__AMUX) 
/* Bidirectional Enable */                                                        
#define MAG_SCL_BIE                    (* (reg8 *) MAG_SCL__BIE)
/* Bit-mask for Aliased Register Access */
#define MAG_SCL_BIT_MASK               (* (reg8 *) MAG_SCL__BIT_MASK)
/* Bypass Enable */
#define MAG_SCL_BYP                    (* (reg8 *) MAG_SCL__BYP)
/* Port wide control signals */                                                   
#define MAG_SCL_CTL                    (* (reg8 *) MAG_SCL__CTL)
/* Drive Modes */
#define MAG_SCL_DM0                    (* (reg8 *) MAG_SCL__DM0) 
#define MAG_SCL_DM1                    (* (reg8 *) MAG_SCL__DM1)
#define MAG_SCL_DM2                    (* (reg8 *) MAG_SCL__DM2) 
/* Input Buffer Disable Override */
#define MAG_SCL_INP_DIS                (* (reg8 *) MAG_SCL__INP_DIS)
/* LCD Common or Segment Drive */
#define MAG_SCL_LCD_COM_SEG            (* (reg8 *) MAG_SCL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MAG_SCL_LCD_EN                 (* (reg8 *) MAG_SCL__LCD_EN)
/* Slew Rate Control */
#define MAG_SCL_SLW                    (* (reg8 *) MAG_SCL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MAG_SCL_PRTDSI__CAPS_SEL       (* (reg8 *) MAG_SCL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MAG_SCL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MAG_SCL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MAG_SCL_PRTDSI__OE_SEL0        (* (reg8 *) MAG_SCL__PRTDSI__OE_SEL0) 
#define MAG_SCL_PRTDSI__OE_SEL1        (* (reg8 *) MAG_SCL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MAG_SCL_PRTDSI__OUT_SEL0       (* (reg8 *) MAG_SCL__PRTDSI__OUT_SEL0) 
#define MAG_SCL_PRTDSI__OUT_SEL1       (* (reg8 *) MAG_SCL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MAG_SCL_PRTDSI__SYNC_OUT       (* (reg8 *) MAG_SCL__PRTDSI__SYNC_OUT) 


#if defined(MAG_SCL__INTSTAT)  /* Interrupt Registers */

    #define MAG_SCL_INTSTAT                (* (reg8 *) MAG_SCL__INTSTAT)
    #define MAG_SCL_SNAP                   (* (reg8 *) MAG_SCL__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MAG_SCL_H */


/* [] END OF FILE */
