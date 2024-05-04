/*******************************************************************************
* File Name: HOME_TILT.h  
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

#if !defined(CY_PINS_HOME_TILT_H) /* Pins HOME_TILT_H */
#define CY_PINS_HOME_TILT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HOME_TILT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HOME_TILT__PORT == 15 && ((HOME_TILT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HOME_TILT_Write(uint8 value) ;
void    HOME_TILT_SetDriveMode(uint8 mode) ;
uint8   HOME_TILT_ReadDataReg(void) ;
uint8   HOME_TILT_Read(void) ;
uint8   HOME_TILT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HOME_TILT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HOME_TILT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HOME_TILT_DM_RES_UP          PIN_DM_RES_UP
#define HOME_TILT_DM_RES_DWN         PIN_DM_RES_DWN
#define HOME_TILT_DM_OD_LO           PIN_DM_OD_LO
#define HOME_TILT_DM_OD_HI           PIN_DM_OD_HI
#define HOME_TILT_DM_STRONG          PIN_DM_STRONG
#define HOME_TILT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HOME_TILT_MASK               HOME_TILT__MASK
#define HOME_TILT_SHIFT              HOME_TILT__SHIFT
#define HOME_TILT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HOME_TILT_PS                     (* (reg8 *) HOME_TILT__PS)
/* Data Register */
#define HOME_TILT_DR                     (* (reg8 *) HOME_TILT__DR)
/* Port Number */
#define HOME_TILT_PRT_NUM                (* (reg8 *) HOME_TILT__PRT) 
/* Connect to Analog Globals */                                                  
#define HOME_TILT_AG                     (* (reg8 *) HOME_TILT__AG)                       
/* Analog MUX bux enable */
#define HOME_TILT_AMUX                   (* (reg8 *) HOME_TILT__AMUX) 
/* Bidirectional Enable */                                                        
#define HOME_TILT_BIE                    (* (reg8 *) HOME_TILT__BIE)
/* Bit-mask for Aliased Register Access */
#define HOME_TILT_BIT_MASK               (* (reg8 *) HOME_TILT__BIT_MASK)
/* Bypass Enable */
#define HOME_TILT_BYP                    (* (reg8 *) HOME_TILT__BYP)
/* Port wide control signals */                                                   
#define HOME_TILT_CTL                    (* (reg8 *) HOME_TILT__CTL)
/* Drive Modes */
#define HOME_TILT_DM0                    (* (reg8 *) HOME_TILT__DM0) 
#define HOME_TILT_DM1                    (* (reg8 *) HOME_TILT__DM1)
#define HOME_TILT_DM2                    (* (reg8 *) HOME_TILT__DM2) 
/* Input Buffer Disable Override */
#define HOME_TILT_INP_DIS                (* (reg8 *) HOME_TILT__INP_DIS)
/* LCD Common or Segment Drive */
#define HOME_TILT_LCD_COM_SEG            (* (reg8 *) HOME_TILT__LCD_COM_SEG)
/* Enable Segment LCD */
#define HOME_TILT_LCD_EN                 (* (reg8 *) HOME_TILT__LCD_EN)
/* Slew Rate Control */
#define HOME_TILT_SLW                    (* (reg8 *) HOME_TILT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HOME_TILT_PRTDSI__CAPS_SEL       (* (reg8 *) HOME_TILT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HOME_TILT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HOME_TILT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HOME_TILT_PRTDSI__OE_SEL0        (* (reg8 *) HOME_TILT__PRTDSI__OE_SEL0) 
#define HOME_TILT_PRTDSI__OE_SEL1        (* (reg8 *) HOME_TILT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HOME_TILT_PRTDSI__OUT_SEL0       (* (reg8 *) HOME_TILT__PRTDSI__OUT_SEL0) 
#define HOME_TILT_PRTDSI__OUT_SEL1       (* (reg8 *) HOME_TILT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HOME_TILT_PRTDSI__SYNC_OUT       (* (reg8 *) HOME_TILT__PRTDSI__SYNC_OUT) 


#if defined(HOME_TILT__INTSTAT)  /* Interrupt Registers */

    #define HOME_TILT_INTSTAT                (* (reg8 *) HOME_TILT__INTSTAT)
    #define HOME_TILT_SNAP                   (* (reg8 *) HOME_TILT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HOME_TILT_H */


/* [] END OF FILE */
