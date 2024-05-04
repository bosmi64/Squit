/*******************************************************************************
* File Name: V5_PHER_nSHDN.h  
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

#if !defined(CY_PINS_V5_PHER_nSHDN_H) /* Pins V5_PHER_nSHDN_H */
#define CY_PINS_V5_PHER_nSHDN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "V5_PHER_nSHDN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 V5_PHER_nSHDN__PORT == 15 && ((V5_PHER_nSHDN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    V5_PHER_nSHDN_Write(uint8 value) ;
void    V5_PHER_nSHDN_SetDriveMode(uint8 mode) ;
uint8   V5_PHER_nSHDN_ReadDataReg(void) ;
uint8   V5_PHER_nSHDN_Read(void) ;
uint8   V5_PHER_nSHDN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define V5_PHER_nSHDN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define V5_PHER_nSHDN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define V5_PHER_nSHDN_DM_RES_UP          PIN_DM_RES_UP
#define V5_PHER_nSHDN_DM_RES_DWN         PIN_DM_RES_DWN
#define V5_PHER_nSHDN_DM_OD_LO           PIN_DM_OD_LO
#define V5_PHER_nSHDN_DM_OD_HI           PIN_DM_OD_HI
#define V5_PHER_nSHDN_DM_STRONG          PIN_DM_STRONG
#define V5_PHER_nSHDN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define V5_PHER_nSHDN_MASK               V5_PHER_nSHDN__MASK
#define V5_PHER_nSHDN_SHIFT              V5_PHER_nSHDN__SHIFT
#define V5_PHER_nSHDN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define V5_PHER_nSHDN_PS                     (* (reg8 *) V5_PHER_nSHDN__PS)
/* Data Register */
#define V5_PHER_nSHDN_DR                     (* (reg8 *) V5_PHER_nSHDN__DR)
/* Port Number */
#define V5_PHER_nSHDN_PRT_NUM                (* (reg8 *) V5_PHER_nSHDN__PRT) 
/* Connect to Analog Globals */                                                  
#define V5_PHER_nSHDN_AG                     (* (reg8 *) V5_PHER_nSHDN__AG)                       
/* Analog MUX bux enable */
#define V5_PHER_nSHDN_AMUX                   (* (reg8 *) V5_PHER_nSHDN__AMUX) 
/* Bidirectional Enable */                                                        
#define V5_PHER_nSHDN_BIE                    (* (reg8 *) V5_PHER_nSHDN__BIE)
/* Bit-mask for Aliased Register Access */
#define V5_PHER_nSHDN_BIT_MASK               (* (reg8 *) V5_PHER_nSHDN__BIT_MASK)
/* Bypass Enable */
#define V5_PHER_nSHDN_BYP                    (* (reg8 *) V5_PHER_nSHDN__BYP)
/* Port wide control signals */                                                   
#define V5_PHER_nSHDN_CTL                    (* (reg8 *) V5_PHER_nSHDN__CTL)
/* Drive Modes */
#define V5_PHER_nSHDN_DM0                    (* (reg8 *) V5_PHER_nSHDN__DM0) 
#define V5_PHER_nSHDN_DM1                    (* (reg8 *) V5_PHER_nSHDN__DM1)
#define V5_PHER_nSHDN_DM2                    (* (reg8 *) V5_PHER_nSHDN__DM2) 
/* Input Buffer Disable Override */
#define V5_PHER_nSHDN_INP_DIS                (* (reg8 *) V5_PHER_nSHDN__INP_DIS)
/* LCD Common or Segment Drive */
#define V5_PHER_nSHDN_LCD_COM_SEG            (* (reg8 *) V5_PHER_nSHDN__LCD_COM_SEG)
/* Enable Segment LCD */
#define V5_PHER_nSHDN_LCD_EN                 (* (reg8 *) V5_PHER_nSHDN__LCD_EN)
/* Slew Rate Control */
#define V5_PHER_nSHDN_SLW                    (* (reg8 *) V5_PHER_nSHDN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define V5_PHER_nSHDN_PRTDSI__CAPS_SEL       (* (reg8 *) V5_PHER_nSHDN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define V5_PHER_nSHDN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) V5_PHER_nSHDN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define V5_PHER_nSHDN_PRTDSI__OE_SEL0        (* (reg8 *) V5_PHER_nSHDN__PRTDSI__OE_SEL0) 
#define V5_PHER_nSHDN_PRTDSI__OE_SEL1        (* (reg8 *) V5_PHER_nSHDN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define V5_PHER_nSHDN_PRTDSI__OUT_SEL0       (* (reg8 *) V5_PHER_nSHDN__PRTDSI__OUT_SEL0) 
#define V5_PHER_nSHDN_PRTDSI__OUT_SEL1       (* (reg8 *) V5_PHER_nSHDN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define V5_PHER_nSHDN_PRTDSI__SYNC_OUT       (* (reg8 *) V5_PHER_nSHDN__PRTDSI__SYNC_OUT) 


#if defined(V5_PHER_nSHDN__INTSTAT)  /* Interrupt Registers */

    #define V5_PHER_nSHDN_INTSTAT                (* (reg8 *) V5_PHER_nSHDN__INTSTAT)
    #define V5_PHER_nSHDN_SNAP                   (* (reg8 *) V5_PHER_nSHDN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_V5_PHER_nSHDN_H */


/* [] END OF FILE */
