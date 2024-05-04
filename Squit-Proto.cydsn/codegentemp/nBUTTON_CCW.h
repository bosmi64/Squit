/*******************************************************************************
* File Name: nBUTTON_CCW.h  
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

#if !defined(CY_PINS_nBUTTON_CCW_H) /* Pins nBUTTON_CCW_H */
#define CY_PINS_nBUTTON_CCW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nBUTTON_CCW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nBUTTON_CCW__PORT == 15 && ((nBUTTON_CCW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    nBUTTON_CCW_Write(uint8 value) ;
void    nBUTTON_CCW_SetDriveMode(uint8 mode) ;
uint8   nBUTTON_CCW_ReadDataReg(void) ;
uint8   nBUTTON_CCW_Read(void) ;
uint8   nBUTTON_CCW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nBUTTON_CCW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nBUTTON_CCW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nBUTTON_CCW_DM_RES_UP          PIN_DM_RES_UP
#define nBUTTON_CCW_DM_RES_DWN         PIN_DM_RES_DWN
#define nBUTTON_CCW_DM_OD_LO           PIN_DM_OD_LO
#define nBUTTON_CCW_DM_OD_HI           PIN_DM_OD_HI
#define nBUTTON_CCW_DM_STRONG          PIN_DM_STRONG
#define nBUTTON_CCW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nBUTTON_CCW_MASK               nBUTTON_CCW__MASK
#define nBUTTON_CCW_SHIFT              nBUTTON_CCW__SHIFT
#define nBUTTON_CCW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nBUTTON_CCW_PS                     (* (reg8 *) nBUTTON_CCW__PS)
/* Data Register */
#define nBUTTON_CCW_DR                     (* (reg8 *) nBUTTON_CCW__DR)
/* Port Number */
#define nBUTTON_CCW_PRT_NUM                (* (reg8 *) nBUTTON_CCW__PRT) 
/* Connect to Analog Globals */                                                  
#define nBUTTON_CCW_AG                     (* (reg8 *) nBUTTON_CCW__AG)                       
/* Analog MUX bux enable */
#define nBUTTON_CCW_AMUX                   (* (reg8 *) nBUTTON_CCW__AMUX) 
/* Bidirectional Enable */                                                        
#define nBUTTON_CCW_BIE                    (* (reg8 *) nBUTTON_CCW__BIE)
/* Bit-mask for Aliased Register Access */
#define nBUTTON_CCW_BIT_MASK               (* (reg8 *) nBUTTON_CCW__BIT_MASK)
/* Bypass Enable */
#define nBUTTON_CCW_BYP                    (* (reg8 *) nBUTTON_CCW__BYP)
/* Port wide control signals */                                                   
#define nBUTTON_CCW_CTL                    (* (reg8 *) nBUTTON_CCW__CTL)
/* Drive Modes */
#define nBUTTON_CCW_DM0                    (* (reg8 *) nBUTTON_CCW__DM0) 
#define nBUTTON_CCW_DM1                    (* (reg8 *) nBUTTON_CCW__DM1)
#define nBUTTON_CCW_DM2                    (* (reg8 *) nBUTTON_CCW__DM2) 
/* Input Buffer Disable Override */
#define nBUTTON_CCW_INP_DIS                (* (reg8 *) nBUTTON_CCW__INP_DIS)
/* LCD Common or Segment Drive */
#define nBUTTON_CCW_LCD_COM_SEG            (* (reg8 *) nBUTTON_CCW__LCD_COM_SEG)
/* Enable Segment LCD */
#define nBUTTON_CCW_LCD_EN                 (* (reg8 *) nBUTTON_CCW__LCD_EN)
/* Slew Rate Control */
#define nBUTTON_CCW_SLW                    (* (reg8 *) nBUTTON_CCW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nBUTTON_CCW_PRTDSI__CAPS_SEL       (* (reg8 *) nBUTTON_CCW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nBUTTON_CCW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nBUTTON_CCW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nBUTTON_CCW_PRTDSI__OE_SEL0        (* (reg8 *) nBUTTON_CCW__PRTDSI__OE_SEL0) 
#define nBUTTON_CCW_PRTDSI__OE_SEL1        (* (reg8 *) nBUTTON_CCW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nBUTTON_CCW_PRTDSI__OUT_SEL0       (* (reg8 *) nBUTTON_CCW__PRTDSI__OUT_SEL0) 
#define nBUTTON_CCW_PRTDSI__OUT_SEL1       (* (reg8 *) nBUTTON_CCW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nBUTTON_CCW_PRTDSI__SYNC_OUT       (* (reg8 *) nBUTTON_CCW__PRTDSI__SYNC_OUT) 


#if defined(nBUTTON_CCW__INTSTAT)  /* Interrupt Registers */

    #define nBUTTON_CCW_INTSTAT                (* (reg8 *) nBUTTON_CCW__INTSTAT)
    #define nBUTTON_CCW_SNAP                   (* (reg8 *) nBUTTON_CCW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nBUTTON_CCW_H */


/* [] END OF FILE */
