/*******************************************************************************
* File Name: EXTGYRO_VRATE.h  
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

#if !defined(CY_PINS_EXTGYRO_VRATE_H) /* Pins EXTGYRO_VRATE_H */
#define CY_PINS_EXTGYRO_VRATE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EXTGYRO_VRATE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EXTGYRO_VRATE__PORT == 15 && ((EXTGYRO_VRATE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EXTGYRO_VRATE_Write(uint8 value) ;
void    EXTGYRO_VRATE_SetDriveMode(uint8 mode) ;
uint8   EXTGYRO_VRATE_ReadDataReg(void) ;
uint8   EXTGYRO_VRATE_Read(void) ;
uint8   EXTGYRO_VRATE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EXTGYRO_VRATE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EXTGYRO_VRATE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EXTGYRO_VRATE_DM_RES_UP          PIN_DM_RES_UP
#define EXTGYRO_VRATE_DM_RES_DWN         PIN_DM_RES_DWN
#define EXTGYRO_VRATE_DM_OD_LO           PIN_DM_OD_LO
#define EXTGYRO_VRATE_DM_OD_HI           PIN_DM_OD_HI
#define EXTGYRO_VRATE_DM_STRONG          PIN_DM_STRONG
#define EXTGYRO_VRATE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EXTGYRO_VRATE_MASK               EXTGYRO_VRATE__MASK
#define EXTGYRO_VRATE_SHIFT              EXTGYRO_VRATE__SHIFT
#define EXTGYRO_VRATE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EXTGYRO_VRATE_PS                     (* (reg8 *) EXTGYRO_VRATE__PS)
/* Data Register */
#define EXTGYRO_VRATE_DR                     (* (reg8 *) EXTGYRO_VRATE__DR)
/* Port Number */
#define EXTGYRO_VRATE_PRT_NUM                (* (reg8 *) EXTGYRO_VRATE__PRT) 
/* Connect to Analog Globals */                                                  
#define EXTGYRO_VRATE_AG                     (* (reg8 *) EXTGYRO_VRATE__AG)                       
/* Analog MUX bux enable */
#define EXTGYRO_VRATE_AMUX                   (* (reg8 *) EXTGYRO_VRATE__AMUX) 
/* Bidirectional Enable */                                                        
#define EXTGYRO_VRATE_BIE                    (* (reg8 *) EXTGYRO_VRATE__BIE)
/* Bit-mask for Aliased Register Access */
#define EXTGYRO_VRATE_BIT_MASK               (* (reg8 *) EXTGYRO_VRATE__BIT_MASK)
/* Bypass Enable */
#define EXTGYRO_VRATE_BYP                    (* (reg8 *) EXTGYRO_VRATE__BYP)
/* Port wide control signals */                                                   
#define EXTGYRO_VRATE_CTL                    (* (reg8 *) EXTGYRO_VRATE__CTL)
/* Drive Modes */
#define EXTGYRO_VRATE_DM0                    (* (reg8 *) EXTGYRO_VRATE__DM0) 
#define EXTGYRO_VRATE_DM1                    (* (reg8 *) EXTGYRO_VRATE__DM1)
#define EXTGYRO_VRATE_DM2                    (* (reg8 *) EXTGYRO_VRATE__DM2) 
/* Input Buffer Disable Override */
#define EXTGYRO_VRATE_INP_DIS                (* (reg8 *) EXTGYRO_VRATE__INP_DIS)
/* LCD Common or Segment Drive */
#define EXTGYRO_VRATE_LCD_COM_SEG            (* (reg8 *) EXTGYRO_VRATE__LCD_COM_SEG)
/* Enable Segment LCD */
#define EXTGYRO_VRATE_LCD_EN                 (* (reg8 *) EXTGYRO_VRATE__LCD_EN)
/* Slew Rate Control */
#define EXTGYRO_VRATE_SLW                    (* (reg8 *) EXTGYRO_VRATE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EXTGYRO_VRATE_PRTDSI__CAPS_SEL       (* (reg8 *) EXTGYRO_VRATE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EXTGYRO_VRATE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EXTGYRO_VRATE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EXTGYRO_VRATE_PRTDSI__OE_SEL0        (* (reg8 *) EXTGYRO_VRATE__PRTDSI__OE_SEL0) 
#define EXTGYRO_VRATE_PRTDSI__OE_SEL1        (* (reg8 *) EXTGYRO_VRATE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EXTGYRO_VRATE_PRTDSI__OUT_SEL0       (* (reg8 *) EXTGYRO_VRATE__PRTDSI__OUT_SEL0) 
#define EXTGYRO_VRATE_PRTDSI__OUT_SEL1       (* (reg8 *) EXTGYRO_VRATE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EXTGYRO_VRATE_PRTDSI__SYNC_OUT       (* (reg8 *) EXTGYRO_VRATE__PRTDSI__SYNC_OUT) 


#if defined(EXTGYRO_VRATE__INTSTAT)  /* Interrupt Registers */

    #define EXTGYRO_VRATE_INTSTAT                (* (reg8 *) EXTGYRO_VRATE__INTSTAT)
    #define EXTGYRO_VRATE_SNAP                   (* (reg8 *) EXTGYRO_VRATE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EXTGYRO_VRATE_H */


/* [] END OF FILE */
