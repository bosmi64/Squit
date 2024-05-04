/*******************************************************************************
* File Name: HOME_PAN.h  
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

#if !defined(CY_PINS_HOME_PAN_H) /* Pins HOME_PAN_H */
#define CY_PINS_HOME_PAN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HOME_PAN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HOME_PAN__PORT == 15 && ((HOME_PAN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HOME_PAN_Write(uint8 value) ;
void    HOME_PAN_SetDriveMode(uint8 mode) ;
uint8   HOME_PAN_ReadDataReg(void) ;
uint8   HOME_PAN_Read(void) ;
uint8   HOME_PAN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HOME_PAN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HOME_PAN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HOME_PAN_DM_RES_UP          PIN_DM_RES_UP
#define HOME_PAN_DM_RES_DWN         PIN_DM_RES_DWN
#define HOME_PAN_DM_OD_LO           PIN_DM_OD_LO
#define HOME_PAN_DM_OD_HI           PIN_DM_OD_HI
#define HOME_PAN_DM_STRONG          PIN_DM_STRONG
#define HOME_PAN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HOME_PAN_MASK               HOME_PAN__MASK
#define HOME_PAN_SHIFT              HOME_PAN__SHIFT
#define HOME_PAN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HOME_PAN_PS                     (* (reg8 *) HOME_PAN__PS)
/* Data Register */
#define HOME_PAN_DR                     (* (reg8 *) HOME_PAN__DR)
/* Port Number */
#define HOME_PAN_PRT_NUM                (* (reg8 *) HOME_PAN__PRT) 
/* Connect to Analog Globals */                                                  
#define HOME_PAN_AG                     (* (reg8 *) HOME_PAN__AG)                       
/* Analog MUX bux enable */
#define HOME_PAN_AMUX                   (* (reg8 *) HOME_PAN__AMUX) 
/* Bidirectional Enable */                                                        
#define HOME_PAN_BIE                    (* (reg8 *) HOME_PAN__BIE)
/* Bit-mask for Aliased Register Access */
#define HOME_PAN_BIT_MASK               (* (reg8 *) HOME_PAN__BIT_MASK)
/* Bypass Enable */
#define HOME_PAN_BYP                    (* (reg8 *) HOME_PAN__BYP)
/* Port wide control signals */                                                   
#define HOME_PAN_CTL                    (* (reg8 *) HOME_PAN__CTL)
/* Drive Modes */
#define HOME_PAN_DM0                    (* (reg8 *) HOME_PAN__DM0) 
#define HOME_PAN_DM1                    (* (reg8 *) HOME_PAN__DM1)
#define HOME_PAN_DM2                    (* (reg8 *) HOME_PAN__DM2) 
/* Input Buffer Disable Override */
#define HOME_PAN_INP_DIS                (* (reg8 *) HOME_PAN__INP_DIS)
/* LCD Common or Segment Drive */
#define HOME_PAN_LCD_COM_SEG            (* (reg8 *) HOME_PAN__LCD_COM_SEG)
/* Enable Segment LCD */
#define HOME_PAN_LCD_EN                 (* (reg8 *) HOME_PAN__LCD_EN)
/* Slew Rate Control */
#define HOME_PAN_SLW                    (* (reg8 *) HOME_PAN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HOME_PAN_PRTDSI__CAPS_SEL       (* (reg8 *) HOME_PAN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HOME_PAN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HOME_PAN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HOME_PAN_PRTDSI__OE_SEL0        (* (reg8 *) HOME_PAN__PRTDSI__OE_SEL0) 
#define HOME_PAN_PRTDSI__OE_SEL1        (* (reg8 *) HOME_PAN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HOME_PAN_PRTDSI__OUT_SEL0       (* (reg8 *) HOME_PAN__PRTDSI__OUT_SEL0) 
#define HOME_PAN_PRTDSI__OUT_SEL1       (* (reg8 *) HOME_PAN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HOME_PAN_PRTDSI__SYNC_OUT       (* (reg8 *) HOME_PAN__PRTDSI__SYNC_OUT) 


#if defined(HOME_PAN__INTSTAT)  /* Interrupt Registers */

    #define HOME_PAN_INTSTAT                (* (reg8 *) HOME_PAN__INTSTAT)
    #define HOME_PAN_SNAP                   (* (reg8 *) HOME_PAN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HOME_PAN_H */


/* [] END OF FILE */
