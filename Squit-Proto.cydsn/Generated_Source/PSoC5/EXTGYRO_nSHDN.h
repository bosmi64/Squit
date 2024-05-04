/*******************************************************************************
* File Name: EXTGYRO_nSHDN.h  
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

#if !defined(CY_PINS_EXTGYRO_nSHDN_H) /* Pins EXTGYRO_nSHDN_H */
#define CY_PINS_EXTGYRO_nSHDN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EXTGYRO_nSHDN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EXTGYRO_nSHDN__PORT == 15 && ((EXTGYRO_nSHDN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EXTGYRO_nSHDN_Write(uint8 value) ;
void    EXTGYRO_nSHDN_SetDriveMode(uint8 mode) ;
uint8   EXTGYRO_nSHDN_ReadDataReg(void) ;
uint8   EXTGYRO_nSHDN_Read(void) ;
uint8   EXTGYRO_nSHDN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EXTGYRO_nSHDN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EXTGYRO_nSHDN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EXTGYRO_nSHDN_DM_RES_UP          PIN_DM_RES_UP
#define EXTGYRO_nSHDN_DM_RES_DWN         PIN_DM_RES_DWN
#define EXTGYRO_nSHDN_DM_OD_LO           PIN_DM_OD_LO
#define EXTGYRO_nSHDN_DM_OD_HI           PIN_DM_OD_HI
#define EXTGYRO_nSHDN_DM_STRONG          PIN_DM_STRONG
#define EXTGYRO_nSHDN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EXTGYRO_nSHDN_MASK               EXTGYRO_nSHDN__MASK
#define EXTGYRO_nSHDN_SHIFT              EXTGYRO_nSHDN__SHIFT
#define EXTGYRO_nSHDN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EXTGYRO_nSHDN_PS                     (* (reg8 *) EXTGYRO_nSHDN__PS)
/* Data Register */
#define EXTGYRO_nSHDN_DR                     (* (reg8 *) EXTGYRO_nSHDN__DR)
/* Port Number */
#define EXTGYRO_nSHDN_PRT_NUM                (* (reg8 *) EXTGYRO_nSHDN__PRT) 
/* Connect to Analog Globals */                                                  
#define EXTGYRO_nSHDN_AG                     (* (reg8 *) EXTGYRO_nSHDN__AG)                       
/* Analog MUX bux enable */
#define EXTGYRO_nSHDN_AMUX                   (* (reg8 *) EXTGYRO_nSHDN__AMUX) 
/* Bidirectional Enable */                                                        
#define EXTGYRO_nSHDN_BIE                    (* (reg8 *) EXTGYRO_nSHDN__BIE)
/* Bit-mask for Aliased Register Access */
#define EXTGYRO_nSHDN_BIT_MASK               (* (reg8 *) EXTGYRO_nSHDN__BIT_MASK)
/* Bypass Enable */
#define EXTGYRO_nSHDN_BYP                    (* (reg8 *) EXTGYRO_nSHDN__BYP)
/* Port wide control signals */                                                   
#define EXTGYRO_nSHDN_CTL                    (* (reg8 *) EXTGYRO_nSHDN__CTL)
/* Drive Modes */
#define EXTGYRO_nSHDN_DM0                    (* (reg8 *) EXTGYRO_nSHDN__DM0) 
#define EXTGYRO_nSHDN_DM1                    (* (reg8 *) EXTGYRO_nSHDN__DM1)
#define EXTGYRO_nSHDN_DM2                    (* (reg8 *) EXTGYRO_nSHDN__DM2) 
/* Input Buffer Disable Override */
#define EXTGYRO_nSHDN_INP_DIS                (* (reg8 *) EXTGYRO_nSHDN__INP_DIS)
/* LCD Common or Segment Drive */
#define EXTGYRO_nSHDN_LCD_COM_SEG            (* (reg8 *) EXTGYRO_nSHDN__LCD_COM_SEG)
/* Enable Segment LCD */
#define EXTGYRO_nSHDN_LCD_EN                 (* (reg8 *) EXTGYRO_nSHDN__LCD_EN)
/* Slew Rate Control */
#define EXTGYRO_nSHDN_SLW                    (* (reg8 *) EXTGYRO_nSHDN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EXTGYRO_nSHDN_PRTDSI__CAPS_SEL       (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EXTGYRO_nSHDN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EXTGYRO_nSHDN_PRTDSI__OE_SEL0        (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__OE_SEL0) 
#define EXTGYRO_nSHDN_PRTDSI__OE_SEL1        (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EXTGYRO_nSHDN_PRTDSI__OUT_SEL0       (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__OUT_SEL0) 
#define EXTGYRO_nSHDN_PRTDSI__OUT_SEL1       (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EXTGYRO_nSHDN_PRTDSI__SYNC_OUT       (* (reg8 *) EXTGYRO_nSHDN__PRTDSI__SYNC_OUT) 


#if defined(EXTGYRO_nSHDN__INTSTAT)  /* Interrupt Registers */

    #define EXTGYRO_nSHDN_INTSTAT                (* (reg8 *) EXTGYRO_nSHDN__INTSTAT)
    #define EXTGYRO_nSHDN_SNAP                   (* (reg8 *) EXTGYRO_nSHDN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EXTGYRO_nSHDN_H */


/* [] END OF FILE */
