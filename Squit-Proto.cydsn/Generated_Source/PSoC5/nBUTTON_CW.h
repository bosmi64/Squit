/*******************************************************************************
* File Name: nBUTTON_CW.h  
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

#if !defined(CY_PINS_nBUTTON_CW_H) /* Pins nBUTTON_CW_H */
#define CY_PINS_nBUTTON_CW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nBUTTON_CW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nBUTTON_CW__PORT == 15 && ((nBUTTON_CW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    nBUTTON_CW_Write(uint8 value) ;
void    nBUTTON_CW_SetDriveMode(uint8 mode) ;
uint8   nBUTTON_CW_ReadDataReg(void) ;
uint8   nBUTTON_CW_Read(void) ;
uint8   nBUTTON_CW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define nBUTTON_CW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define nBUTTON_CW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define nBUTTON_CW_DM_RES_UP          PIN_DM_RES_UP
#define nBUTTON_CW_DM_RES_DWN         PIN_DM_RES_DWN
#define nBUTTON_CW_DM_OD_LO           PIN_DM_OD_LO
#define nBUTTON_CW_DM_OD_HI           PIN_DM_OD_HI
#define nBUTTON_CW_DM_STRONG          PIN_DM_STRONG
#define nBUTTON_CW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define nBUTTON_CW_MASK               nBUTTON_CW__MASK
#define nBUTTON_CW_SHIFT              nBUTTON_CW__SHIFT
#define nBUTTON_CW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nBUTTON_CW_PS                     (* (reg8 *) nBUTTON_CW__PS)
/* Data Register */
#define nBUTTON_CW_DR                     (* (reg8 *) nBUTTON_CW__DR)
/* Port Number */
#define nBUTTON_CW_PRT_NUM                (* (reg8 *) nBUTTON_CW__PRT) 
/* Connect to Analog Globals */                                                  
#define nBUTTON_CW_AG                     (* (reg8 *) nBUTTON_CW__AG)                       
/* Analog MUX bux enable */
#define nBUTTON_CW_AMUX                   (* (reg8 *) nBUTTON_CW__AMUX) 
/* Bidirectional Enable */                                                        
#define nBUTTON_CW_BIE                    (* (reg8 *) nBUTTON_CW__BIE)
/* Bit-mask for Aliased Register Access */
#define nBUTTON_CW_BIT_MASK               (* (reg8 *) nBUTTON_CW__BIT_MASK)
/* Bypass Enable */
#define nBUTTON_CW_BYP                    (* (reg8 *) nBUTTON_CW__BYP)
/* Port wide control signals */                                                   
#define nBUTTON_CW_CTL                    (* (reg8 *) nBUTTON_CW__CTL)
/* Drive Modes */
#define nBUTTON_CW_DM0                    (* (reg8 *) nBUTTON_CW__DM0) 
#define nBUTTON_CW_DM1                    (* (reg8 *) nBUTTON_CW__DM1)
#define nBUTTON_CW_DM2                    (* (reg8 *) nBUTTON_CW__DM2) 
/* Input Buffer Disable Override */
#define nBUTTON_CW_INP_DIS                (* (reg8 *) nBUTTON_CW__INP_DIS)
/* LCD Common or Segment Drive */
#define nBUTTON_CW_LCD_COM_SEG            (* (reg8 *) nBUTTON_CW__LCD_COM_SEG)
/* Enable Segment LCD */
#define nBUTTON_CW_LCD_EN                 (* (reg8 *) nBUTTON_CW__LCD_EN)
/* Slew Rate Control */
#define nBUTTON_CW_SLW                    (* (reg8 *) nBUTTON_CW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nBUTTON_CW_PRTDSI__CAPS_SEL       (* (reg8 *) nBUTTON_CW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nBUTTON_CW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nBUTTON_CW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nBUTTON_CW_PRTDSI__OE_SEL0        (* (reg8 *) nBUTTON_CW__PRTDSI__OE_SEL0) 
#define nBUTTON_CW_PRTDSI__OE_SEL1        (* (reg8 *) nBUTTON_CW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nBUTTON_CW_PRTDSI__OUT_SEL0       (* (reg8 *) nBUTTON_CW__PRTDSI__OUT_SEL0) 
#define nBUTTON_CW_PRTDSI__OUT_SEL1       (* (reg8 *) nBUTTON_CW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nBUTTON_CW_PRTDSI__SYNC_OUT       (* (reg8 *) nBUTTON_CW__PRTDSI__SYNC_OUT) 


#if defined(nBUTTON_CW__INTSTAT)  /* Interrupt Registers */

    #define nBUTTON_CW_INTSTAT                (* (reg8 *) nBUTTON_CW__INTSTAT)
    #define nBUTTON_CW_SNAP                   (* (reg8 *) nBUTTON_CW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nBUTTON_CW_H */


/* [] END OF FILE */
