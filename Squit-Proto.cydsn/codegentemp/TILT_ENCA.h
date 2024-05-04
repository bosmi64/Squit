/*******************************************************************************
* File Name: TILT_ENCA.h  
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

#if !defined(CY_PINS_TILT_ENCA_H) /* Pins TILT_ENCA_H */
#define CY_PINS_TILT_ENCA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TILT_ENCA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TILT_ENCA__PORT == 15 && ((TILT_ENCA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TILT_ENCA_Write(uint8 value) ;
void    TILT_ENCA_SetDriveMode(uint8 mode) ;
uint8   TILT_ENCA_ReadDataReg(void) ;
uint8   TILT_ENCA_Read(void) ;
uint8   TILT_ENCA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TILT_ENCA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TILT_ENCA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TILT_ENCA_DM_RES_UP          PIN_DM_RES_UP
#define TILT_ENCA_DM_RES_DWN         PIN_DM_RES_DWN
#define TILT_ENCA_DM_OD_LO           PIN_DM_OD_LO
#define TILT_ENCA_DM_OD_HI           PIN_DM_OD_HI
#define TILT_ENCA_DM_STRONG          PIN_DM_STRONG
#define TILT_ENCA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TILT_ENCA_MASK               TILT_ENCA__MASK
#define TILT_ENCA_SHIFT              TILT_ENCA__SHIFT
#define TILT_ENCA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TILT_ENCA_PS                     (* (reg8 *) TILT_ENCA__PS)
/* Data Register */
#define TILT_ENCA_DR                     (* (reg8 *) TILT_ENCA__DR)
/* Port Number */
#define TILT_ENCA_PRT_NUM                (* (reg8 *) TILT_ENCA__PRT) 
/* Connect to Analog Globals */                                                  
#define TILT_ENCA_AG                     (* (reg8 *) TILT_ENCA__AG)                       
/* Analog MUX bux enable */
#define TILT_ENCA_AMUX                   (* (reg8 *) TILT_ENCA__AMUX) 
/* Bidirectional Enable */                                                        
#define TILT_ENCA_BIE                    (* (reg8 *) TILT_ENCA__BIE)
/* Bit-mask for Aliased Register Access */
#define TILT_ENCA_BIT_MASK               (* (reg8 *) TILT_ENCA__BIT_MASK)
/* Bypass Enable */
#define TILT_ENCA_BYP                    (* (reg8 *) TILT_ENCA__BYP)
/* Port wide control signals */                                                   
#define TILT_ENCA_CTL                    (* (reg8 *) TILT_ENCA__CTL)
/* Drive Modes */
#define TILT_ENCA_DM0                    (* (reg8 *) TILT_ENCA__DM0) 
#define TILT_ENCA_DM1                    (* (reg8 *) TILT_ENCA__DM1)
#define TILT_ENCA_DM2                    (* (reg8 *) TILT_ENCA__DM2) 
/* Input Buffer Disable Override */
#define TILT_ENCA_INP_DIS                (* (reg8 *) TILT_ENCA__INP_DIS)
/* LCD Common or Segment Drive */
#define TILT_ENCA_LCD_COM_SEG            (* (reg8 *) TILT_ENCA__LCD_COM_SEG)
/* Enable Segment LCD */
#define TILT_ENCA_LCD_EN                 (* (reg8 *) TILT_ENCA__LCD_EN)
/* Slew Rate Control */
#define TILT_ENCA_SLW                    (* (reg8 *) TILT_ENCA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TILT_ENCA_PRTDSI__CAPS_SEL       (* (reg8 *) TILT_ENCA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TILT_ENCA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TILT_ENCA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TILT_ENCA_PRTDSI__OE_SEL0        (* (reg8 *) TILT_ENCA__PRTDSI__OE_SEL0) 
#define TILT_ENCA_PRTDSI__OE_SEL1        (* (reg8 *) TILT_ENCA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TILT_ENCA_PRTDSI__OUT_SEL0       (* (reg8 *) TILT_ENCA__PRTDSI__OUT_SEL0) 
#define TILT_ENCA_PRTDSI__OUT_SEL1       (* (reg8 *) TILT_ENCA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TILT_ENCA_PRTDSI__SYNC_OUT       (* (reg8 *) TILT_ENCA__PRTDSI__SYNC_OUT) 


#if defined(TILT_ENCA__INTSTAT)  /* Interrupt Registers */

    #define TILT_ENCA_INTSTAT                (* (reg8 *) TILT_ENCA__INTSTAT)
    #define TILT_ENCA_SNAP                   (* (reg8 *) TILT_ENCA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TILT_ENCA_H */


/* [] END OF FILE */
