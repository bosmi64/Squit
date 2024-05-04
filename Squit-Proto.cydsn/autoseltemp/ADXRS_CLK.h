/*******************************************************************************
* File Name: ADXRS_CLK.h  
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

#if !defined(CY_PINS_ADXRS_CLK_H) /* Pins ADXRS_CLK_H */
#define CY_PINS_ADXRS_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXRS_CLK_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXRS_CLK_Write(uint8 value) ;
void    ADXRS_CLK_SetDriveMode(uint8 mode) ;
uint8   ADXRS_CLK_ReadDataReg(void) ;
uint8   ADXRS_CLK_Read(void) ;
uint8   ADXRS_CLK_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXRS_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXRS_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXRS_CLK_DM_RES_UP          PIN_DM_RES_UP
#define ADXRS_CLK_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXRS_CLK_DM_OD_LO           PIN_DM_OD_LO
#define ADXRS_CLK_DM_OD_HI           PIN_DM_OD_HI
#define ADXRS_CLK_DM_STRONG          PIN_DM_STRONG
#define ADXRS_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXRS_CLK_MASK               ADXRS_CLK__MASK
#define ADXRS_CLK_SHIFT              ADXRS_CLK__SHIFT
#define ADXRS_CLK_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXRS_CLK_PS                     (* (reg8 *) ADXRS_CLK__PS)
/* Data Register */
#define ADXRS_CLK_DR                     (* (reg8 *) ADXRS_CLK__DR)
/* Port Number */
#define ADXRS_CLK_PRT_NUM                (* (reg8 *) ADXRS_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXRS_CLK_AG                     (* (reg8 *) ADXRS_CLK__AG)                       
/* Analog MUX bux enable */
#define ADXRS_CLK_AMUX                   (* (reg8 *) ADXRS_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXRS_CLK_BIE                    (* (reg8 *) ADXRS_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXRS_CLK_BIT_MASK               (* (reg8 *) ADXRS_CLK__BIT_MASK)
/* Bypass Enable */
#define ADXRS_CLK_BYP                    (* (reg8 *) ADXRS_CLK__BYP)
/* Port wide control signals */                                                   
#define ADXRS_CLK_CTL                    (* (reg8 *) ADXRS_CLK__CTL)
/* Drive Modes */
#define ADXRS_CLK_DM0                    (* (reg8 *) ADXRS_CLK__DM0) 
#define ADXRS_CLK_DM1                    (* (reg8 *) ADXRS_CLK__DM1)
#define ADXRS_CLK_DM2                    (* (reg8 *) ADXRS_CLK__DM2) 
/* Input Buffer Disable Override */
#define ADXRS_CLK_INP_DIS                (* (reg8 *) ADXRS_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXRS_CLK_LCD_COM_SEG            (* (reg8 *) ADXRS_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXRS_CLK_LCD_EN                 (* (reg8 *) ADXRS_CLK__LCD_EN)
/* Slew Rate Control */
#define ADXRS_CLK_SLW                    (* (reg8 *) ADXRS_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXRS_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) ADXRS_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXRS_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXRS_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXRS_CLK_PRTDSI__OE_SEL0        (* (reg8 *) ADXRS_CLK__PRTDSI__OE_SEL0) 
#define ADXRS_CLK_PRTDSI__OE_SEL1        (* (reg8 *) ADXRS_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXRS_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) ADXRS_CLK__PRTDSI__OUT_SEL0) 
#define ADXRS_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) ADXRS_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXRS_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) ADXRS_CLK__PRTDSI__SYNC_OUT) 


#if defined(ADXRS_CLK__INTSTAT)  /* Interrupt Registers */

    #define ADXRS_CLK_INTSTAT                (* (reg8 *) ADXRS_CLK__INTSTAT)
    #define ADXRS_CLK_SNAP                   (* (reg8 *) ADXRS_CLK__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ADXRS_CLK_H */


/* [] END OF FILE */
