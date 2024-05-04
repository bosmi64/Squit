/*******************************************************************************
* File Name: ADXRS_CS.h  
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

#if !defined(CY_PINS_ADXRS_CS_H) /* Pins ADXRS_CS_H */
#define CY_PINS_ADXRS_CS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXRS_CS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADXRS_CS__PORT == 15 && ((ADXRS_CS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXRS_CS_Write(uint8 value) ;
void    ADXRS_CS_SetDriveMode(uint8 mode) ;
uint8   ADXRS_CS_ReadDataReg(void) ;
uint8   ADXRS_CS_Read(void) ;
uint8   ADXRS_CS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXRS_CS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXRS_CS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXRS_CS_DM_RES_UP          PIN_DM_RES_UP
#define ADXRS_CS_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXRS_CS_DM_OD_LO           PIN_DM_OD_LO
#define ADXRS_CS_DM_OD_HI           PIN_DM_OD_HI
#define ADXRS_CS_DM_STRONG          PIN_DM_STRONG
#define ADXRS_CS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXRS_CS_MASK               ADXRS_CS__MASK
#define ADXRS_CS_SHIFT              ADXRS_CS__SHIFT
#define ADXRS_CS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXRS_CS_PS                     (* (reg8 *) ADXRS_CS__PS)
/* Data Register */
#define ADXRS_CS_DR                     (* (reg8 *) ADXRS_CS__DR)
/* Port Number */
#define ADXRS_CS_PRT_NUM                (* (reg8 *) ADXRS_CS__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXRS_CS_AG                     (* (reg8 *) ADXRS_CS__AG)                       
/* Analog MUX bux enable */
#define ADXRS_CS_AMUX                   (* (reg8 *) ADXRS_CS__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXRS_CS_BIE                    (* (reg8 *) ADXRS_CS__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXRS_CS_BIT_MASK               (* (reg8 *) ADXRS_CS__BIT_MASK)
/* Bypass Enable */
#define ADXRS_CS_BYP                    (* (reg8 *) ADXRS_CS__BYP)
/* Port wide control signals */                                                   
#define ADXRS_CS_CTL                    (* (reg8 *) ADXRS_CS__CTL)
/* Drive Modes */
#define ADXRS_CS_DM0                    (* (reg8 *) ADXRS_CS__DM0) 
#define ADXRS_CS_DM1                    (* (reg8 *) ADXRS_CS__DM1)
#define ADXRS_CS_DM2                    (* (reg8 *) ADXRS_CS__DM2) 
/* Input Buffer Disable Override */
#define ADXRS_CS_INP_DIS                (* (reg8 *) ADXRS_CS__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXRS_CS_LCD_COM_SEG            (* (reg8 *) ADXRS_CS__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXRS_CS_LCD_EN                 (* (reg8 *) ADXRS_CS__LCD_EN)
/* Slew Rate Control */
#define ADXRS_CS_SLW                    (* (reg8 *) ADXRS_CS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXRS_CS_PRTDSI__CAPS_SEL       (* (reg8 *) ADXRS_CS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXRS_CS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXRS_CS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXRS_CS_PRTDSI__OE_SEL0        (* (reg8 *) ADXRS_CS__PRTDSI__OE_SEL0) 
#define ADXRS_CS_PRTDSI__OE_SEL1        (* (reg8 *) ADXRS_CS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXRS_CS_PRTDSI__OUT_SEL0       (* (reg8 *) ADXRS_CS__PRTDSI__OUT_SEL0) 
#define ADXRS_CS_PRTDSI__OUT_SEL1       (* (reg8 *) ADXRS_CS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXRS_CS_PRTDSI__SYNC_OUT       (* (reg8 *) ADXRS_CS__PRTDSI__SYNC_OUT) 


#if defined(ADXRS_CS__INTSTAT)  /* Interrupt Registers */

    #define ADXRS_CS_INTSTAT                (* (reg8 *) ADXRS_CS__INTSTAT)
    #define ADXRS_CS_SNAP                   (* (reg8 *) ADXRS_CS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADXRS_CS_H */


/* [] END OF FILE */
