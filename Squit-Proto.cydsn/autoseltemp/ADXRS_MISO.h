/*******************************************************************************
* File Name: ADXRS_MISO.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_ADXRS_MISO_H) /* Pins ADXRS_MISO_H */
#define CY_PINS_ADXRS_MISO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXRS_MISO_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXRS_MISO_Write(uint8 value) ;
void    ADXRS_MISO_SetDriveMode(uint8 mode) ;
uint8   ADXRS_MISO_ReadDataReg(void) ;
uint8   ADXRS_MISO_Read(void) ;
uint8   ADXRS_MISO_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXRS_MISO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXRS_MISO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXRS_MISO_DM_RES_UP          PIN_DM_RES_UP
#define ADXRS_MISO_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXRS_MISO_DM_OD_LO           PIN_DM_OD_LO
#define ADXRS_MISO_DM_OD_HI           PIN_DM_OD_HI
#define ADXRS_MISO_DM_STRONG          PIN_DM_STRONG
#define ADXRS_MISO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXRS_MISO_MASK               ADXRS_MISO__MASK
#define ADXRS_MISO_SHIFT              ADXRS_MISO__SHIFT
#define ADXRS_MISO_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXRS_MISO_PS                     (* (reg8 *) ADXRS_MISO__PS)
/* Data Register */
#define ADXRS_MISO_DR                     (* (reg8 *) ADXRS_MISO__DR)
/* Port Number */
#define ADXRS_MISO_PRT_NUM                (* (reg8 *) ADXRS_MISO__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXRS_MISO_AG                     (* (reg8 *) ADXRS_MISO__AG)                       
/* Analog MUX bux enable */
#define ADXRS_MISO_AMUX                   (* (reg8 *) ADXRS_MISO__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXRS_MISO_BIE                    (* (reg8 *) ADXRS_MISO__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXRS_MISO_BIT_MASK               (* (reg8 *) ADXRS_MISO__BIT_MASK)
/* Bypass Enable */
#define ADXRS_MISO_BYP                    (* (reg8 *) ADXRS_MISO__BYP)
/* Port wide control signals */                                                   
#define ADXRS_MISO_CTL                    (* (reg8 *) ADXRS_MISO__CTL)
/* Drive Modes */
#define ADXRS_MISO_DM0                    (* (reg8 *) ADXRS_MISO__DM0) 
#define ADXRS_MISO_DM1                    (* (reg8 *) ADXRS_MISO__DM1)
#define ADXRS_MISO_DM2                    (* (reg8 *) ADXRS_MISO__DM2) 
/* Input Buffer Disable Override */
#define ADXRS_MISO_INP_DIS                (* (reg8 *) ADXRS_MISO__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXRS_MISO_LCD_COM_SEG            (* (reg8 *) ADXRS_MISO__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXRS_MISO_LCD_EN                 (* (reg8 *) ADXRS_MISO__LCD_EN)
/* Slew Rate Control */
#define ADXRS_MISO_SLW                    (* (reg8 *) ADXRS_MISO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXRS_MISO_PRTDSI__CAPS_SEL       (* (reg8 *) ADXRS_MISO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXRS_MISO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXRS_MISO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXRS_MISO_PRTDSI__OE_SEL0        (* (reg8 *) ADXRS_MISO__PRTDSI__OE_SEL0) 
#define ADXRS_MISO_PRTDSI__OE_SEL1        (* (reg8 *) ADXRS_MISO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXRS_MISO_PRTDSI__OUT_SEL0       (* (reg8 *) ADXRS_MISO__PRTDSI__OUT_SEL0) 
#define ADXRS_MISO_PRTDSI__OUT_SEL1       (* (reg8 *) ADXRS_MISO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXRS_MISO_PRTDSI__SYNC_OUT       (* (reg8 *) ADXRS_MISO__PRTDSI__SYNC_OUT) 


#if defined(ADXRS_MISO__INTSTAT)  /* Interrupt Registers */

    #define ADXRS_MISO_INTSTAT                (* (reg8 *) ADXRS_MISO__INTSTAT)
    #define ADXRS_MISO_SNAP                   (* (reg8 *) ADXRS_MISO__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ADXRS_MISO_H */


/* [] END OF FILE */
