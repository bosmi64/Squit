/*******************************************************************************
* File Name: ANGLE_DAC.h  
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

#if !defined(CY_PINS_ANGLE_DAC_H) /* Pins ANGLE_DAC_H */
#define CY_PINS_ANGLE_DAC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ANGLE_DAC_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ANGLE_DAC__PORT == 15 && ((ANGLE_DAC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ANGLE_DAC_Write(uint8 value) ;
void    ANGLE_DAC_SetDriveMode(uint8 mode) ;
uint8   ANGLE_DAC_ReadDataReg(void) ;
uint8   ANGLE_DAC_Read(void) ;
uint8   ANGLE_DAC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ANGLE_DAC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ANGLE_DAC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ANGLE_DAC_DM_RES_UP          PIN_DM_RES_UP
#define ANGLE_DAC_DM_RES_DWN         PIN_DM_RES_DWN
#define ANGLE_DAC_DM_OD_LO           PIN_DM_OD_LO
#define ANGLE_DAC_DM_OD_HI           PIN_DM_OD_HI
#define ANGLE_DAC_DM_STRONG          PIN_DM_STRONG
#define ANGLE_DAC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ANGLE_DAC_MASK               ANGLE_DAC__MASK
#define ANGLE_DAC_SHIFT              ANGLE_DAC__SHIFT
#define ANGLE_DAC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ANGLE_DAC_PS                     (* (reg8 *) ANGLE_DAC__PS)
/* Data Register */
#define ANGLE_DAC_DR                     (* (reg8 *) ANGLE_DAC__DR)
/* Port Number */
#define ANGLE_DAC_PRT_NUM                (* (reg8 *) ANGLE_DAC__PRT) 
/* Connect to Analog Globals */                                                  
#define ANGLE_DAC_AG                     (* (reg8 *) ANGLE_DAC__AG)                       
/* Analog MUX bux enable */
#define ANGLE_DAC_AMUX                   (* (reg8 *) ANGLE_DAC__AMUX) 
/* Bidirectional Enable */                                                        
#define ANGLE_DAC_BIE                    (* (reg8 *) ANGLE_DAC__BIE)
/* Bit-mask for Aliased Register Access */
#define ANGLE_DAC_BIT_MASK               (* (reg8 *) ANGLE_DAC__BIT_MASK)
/* Bypass Enable */
#define ANGLE_DAC_BYP                    (* (reg8 *) ANGLE_DAC__BYP)
/* Port wide control signals */                                                   
#define ANGLE_DAC_CTL                    (* (reg8 *) ANGLE_DAC__CTL)
/* Drive Modes */
#define ANGLE_DAC_DM0                    (* (reg8 *) ANGLE_DAC__DM0) 
#define ANGLE_DAC_DM1                    (* (reg8 *) ANGLE_DAC__DM1)
#define ANGLE_DAC_DM2                    (* (reg8 *) ANGLE_DAC__DM2) 
/* Input Buffer Disable Override */
#define ANGLE_DAC_INP_DIS                (* (reg8 *) ANGLE_DAC__INP_DIS)
/* LCD Common or Segment Drive */
#define ANGLE_DAC_LCD_COM_SEG            (* (reg8 *) ANGLE_DAC__LCD_COM_SEG)
/* Enable Segment LCD */
#define ANGLE_DAC_LCD_EN                 (* (reg8 *) ANGLE_DAC__LCD_EN)
/* Slew Rate Control */
#define ANGLE_DAC_SLW                    (* (reg8 *) ANGLE_DAC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ANGLE_DAC_PRTDSI__CAPS_SEL       (* (reg8 *) ANGLE_DAC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ANGLE_DAC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ANGLE_DAC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ANGLE_DAC_PRTDSI__OE_SEL0        (* (reg8 *) ANGLE_DAC__PRTDSI__OE_SEL0) 
#define ANGLE_DAC_PRTDSI__OE_SEL1        (* (reg8 *) ANGLE_DAC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ANGLE_DAC_PRTDSI__OUT_SEL0       (* (reg8 *) ANGLE_DAC__PRTDSI__OUT_SEL0) 
#define ANGLE_DAC_PRTDSI__OUT_SEL1       (* (reg8 *) ANGLE_DAC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ANGLE_DAC_PRTDSI__SYNC_OUT       (* (reg8 *) ANGLE_DAC__PRTDSI__SYNC_OUT) 


#if defined(ANGLE_DAC__INTSTAT)  /* Interrupt Registers */

    #define ANGLE_DAC_INTSTAT                (* (reg8 *) ANGLE_DAC__INTSTAT)
    #define ANGLE_DAC_SNAP                   (* (reg8 *) ANGLE_DAC__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ANGLE_DAC_H */


/* [] END OF FILE */
