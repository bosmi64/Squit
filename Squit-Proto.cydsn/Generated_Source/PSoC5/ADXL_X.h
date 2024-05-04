/*******************************************************************************
* File Name: ADXL_X.h  
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

#if !defined(CY_PINS_ADXL_X_H) /* Pins ADXL_X_H */
#define CY_PINS_ADXL_X_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXL_X_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADXL_X__PORT == 15 && ((ADXL_X__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXL_X_Write(uint8 value) ;
void    ADXL_X_SetDriveMode(uint8 mode) ;
uint8   ADXL_X_ReadDataReg(void) ;
uint8   ADXL_X_Read(void) ;
uint8   ADXL_X_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXL_X_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXL_X_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXL_X_DM_RES_UP          PIN_DM_RES_UP
#define ADXL_X_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXL_X_DM_OD_LO           PIN_DM_OD_LO
#define ADXL_X_DM_OD_HI           PIN_DM_OD_HI
#define ADXL_X_DM_STRONG          PIN_DM_STRONG
#define ADXL_X_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXL_X_MASK               ADXL_X__MASK
#define ADXL_X_SHIFT              ADXL_X__SHIFT
#define ADXL_X_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXL_X_PS                     (* (reg8 *) ADXL_X__PS)
/* Data Register */
#define ADXL_X_DR                     (* (reg8 *) ADXL_X__DR)
/* Port Number */
#define ADXL_X_PRT_NUM                (* (reg8 *) ADXL_X__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXL_X_AG                     (* (reg8 *) ADXL_X__AG)                       
/* Analog MUX bux enable */
#define ADXL_X_AMUX                   (* (reg8 *) ADXL_X__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXL_X_BIE                    (* (reg8 *) ADXL_X__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXL_X_BIT_MASK               (* (reg8 *) ADXL_X__BIT_MASK)
/* Bypass Enable */
#define ADXL_X_BYP                    (* (reg8 *) ADXL_X__BYP)
/* Port wide control signals */                                                   
#define ADXL_X_CTL                    (* (reg8 *) ADXL_X__CTL)
/* Drive Modes */
#define ADXL_X_DM0                    (* (reg8 *) ADXL_X__DM0) 
#define ADXL_X_DM1                    (* (reg8 *) ADXL_X__DM1)
#define ADXL_X_DM2                    (* (reg8 *) ADXL_X__DM2) 
/* Input Buffer Disable Override */
#define ADXL_X_INP_DIS                (* (reg8 *) ADXL_X__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXL_X_LCD_COM_SEG            (* (reg8 *) ADXL_X__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXL_X_LCD_EN                 (* (reg8 *) ADXL_X__LCD_EN)
/* Slew Rate Control */
#define ADXL_X_SLW                    (* (reg8 *) ADXL_X__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXL_X_PRTDSI__CAPS_SEL       (* (reg8 *) ADXL_X__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXL_X_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXL_X__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXL_X_PRTDSI__OE_SEL0        (* (reg8 *) ADXL_X__PRTDSI__OE_SEL0) 
#define ADXL_X_PRTDSI__OE_SEL1        (* (reg8 *) ADXL_X__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXL_X_PRTDSI__OUT_SEL0       (* (reg8 *) ADXL_X__PRTDSI__OUT_SEL0) 
#define ADXL_X_PRTDSI__OUT_SEL1       (* (reg8 *) ADXL_X__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXL_X_PRTDSI__SYNC_OUT       (* (reg8 *) ADXL_X__PRTDSI__SYNC_OUT) 


#if defined(ADXL_X__INTSTAT)  /* Interrupt Registers */

    #define ADXL_X_INTSTAT                (* (reg8 *) ADXL_X__INTSTAT)
    #define ADXL_X_SNAP                   (* (reg8 *) ADXL_X__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADXL_X_H */


/* [] END OF FILE */
