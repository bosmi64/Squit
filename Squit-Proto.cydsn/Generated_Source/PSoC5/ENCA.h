/*******************************************************************************
* File Name: ENCA.h  
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

#if !defined(CY_PINS_ENCA_H) /* Pins ENCA_H */
#define CY_PINS_ENCA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ENCA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ENCA__PORT == 15 && ((ENCA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ENCA_Write(uint8 value) ;
void    ENCA_SetDriveMode(uint8 mode) ;
uint8   ENCA_ReadDataReg(void) ;
uint8   ENCA_Read(void) ;
uint8   ENCA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENCA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ENCA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ENCA_DM_RES_UP          PIN_DM_RES_UP
#define ENCA_DM_RES_DWN         PIN_DM_RES_DWN
#define ENCA_DM_OD_LO           PIN_DM_OD_LO
#define ENCA_DM_OD_HI           PIN_DM_OD_HI
#define ENCA_DM_STRONG          PIN_DM_STRONG
#define ENCA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ENCA_MASK               ENCA__MASK
#define ENCA_SHIFT              ENCA__SHIFT
#define ENCA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENCA_PS                     (* (reg8 *) ENCA__PS)
/* Data Register */
#define ENCA_DR                     (* (reg8 *) ENCA__DR)
/* Port Number */
#define ENCA_PRT_NUM                (* (reg8 *) ENCA__PRT) 
/* Connect to Analog Globals */                                                  
#define ENCA_AG                     (* (reg8 *) ENCA__AG)                       
/* Analog MUX bux enable */
#define ENCA_AMUX                   (* (reg8 *) ENCA__AMUX) 
/* Bidirectional Enable */                                                        
#define ENCA_BIE                    (* (reg8 *) ENCA__BIE)
/* Bit-mask for Aliased Register Access */
#define ENCA_BIT_MASK               (* (reg8 *) ENCA__BIT_MASK)
/* Bypass Enable */
#define ENCA_BYP                    (* (reg8 *) ENCA__BYP)
/* Port wide control signals */                                                   
#define ENCA_CTL                    (* (reg8 *) ENCA__CTL)
/* Drive Modes */
#define ENCA_DM0                    (* (reg8 *) ENCA__DM0) 
#define ENCA_DM1                    (* (reg8 *) ENCA__DM1)
#define ENCA_DM2                    (* (reg8 *) ENCA__DM2) 
/* Input Buffer Disable Override */
#define ENCA_INP_DIS                (* (reg8 *) ENCA__INP_DIS)
/* LCD Common or Segment Drive */
#define ENCA_LCD_COM_SEG            (* (reg8 *) ENCA__LCD_COM_SEG)
/* Enable Segment LCD */
#define ENCA_LCD_EN                 (* (reg8 *) ENCA__LCD_EN)
/* Slew Rate Control */
#define ENCA_SLW                    (* (reg8 *) ENCA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ENCA_PRTDSI__CAPS_SEL       (* (reg8 *) ENCA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ENCA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ENCA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ENCA_PRTDSI__OE_SEL0        (* (reg8 *) ENCA__PRTDSI__OE_SEL0) 
#define ENCA_PRTDSI__OE_SEL1        (* (reg8 *) ENCA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ENCA_PRTDSI__OUT_SEL0       (* (reg8 *) ENCA__PRTDSI__OUT_SEL0) 
#define ENCA_PRTDSI__OUT_SEL1       (* (reg8 *) ENCA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ENCA_PRTDSI__SYNC_OUT       (* (reg8 *) ENCA__PRTDSI__SYNC_OUT) 


#if defined(ENCA__INTSTAT)  /* Interrupt Registers */

    #define ENCA_INTSTAT                (* (reg8 *) ENCA__INTSTAT)
    #define ENCA_SNAP                   (* (reg8 *) ENCA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ENCA_H */


/* [] END OF FILE */
