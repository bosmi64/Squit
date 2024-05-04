/*******************************************************************************
* File Name: ITG_INT.h  
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

#if !defined(CY_PINS_ITG_INT_H) /* Pins ITG_INT_H */
#define CY_PINS_ITG_INT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ITG_INT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ITG_INT__PORT == 15 && ((ITG_INT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ITG_INT_Write(uint8 value) ;
void    ITG_INT_SetDriveMode(uint8 mode) ;
uint8   ITG_INT_ReadDataReg(void) ;
uint8   ITG_INT_Read(void) ;
uint8   ITG_INT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ITG_INT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ITG_INT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ITG_INT_DM_RES_UP          PIN_DM_RES_UP
#define ITG_INT_DM_RES_DWN         PIN_DM_RES_DWN
#define ITG_INT_DM_OD_LO           PIN_DM_OD_LO
#define ITG_INT_DM_OD_HI           PIN_DM_OD_HI
#define ITG_INT_DM_STRONG          PIN_DM_STRONG
#define ITG_INT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ITG_INT_MASK               ITG_INT__MASK
#define ITG_INT_SHIFT              ITG_INT__SHIFT
#define ITG_INT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ITG_INT_PS                     (* (reg8 *) ITG_INT__PS)
/* Data Register */
#define ITG_INT_DR                     (* (reg8 *) ITG_INT__DR)
/* Port Number */
#define ITG_INT_PRT_NUM                (* (reg8 *) ITG_INT__PRT) 
/* Connect to Analog Globals */                                                  
#define ITG_INT_AG                     (* (reg8 *) ITG_INT__AG)                       
/* Analog MUX bux enable */
#define ITG_INT_AMUX                   (* (reg8 *) ITG_INT__AMUX) 
/* Bidirectional Enable */                                                        
#define ITG_INT_BIE                    (* (reg8 *) ITG_INT__BIE)
/* Bit-mask for Aliased Register Access */
#define ITG_INT_BIT_MASK               (* (reg8 *) ITG_INT__BIT_MASK)
/* Bypass Enable */
#define ITG_INT_BYP                    (* (reg8 *) ITG_INT__BYP)
/* Port wide control signals */                                                   
#define ITG_INT_CTL                    (* (reg8 *) ITG_INT__CTL)
/* Drive Modes */
#define ITG_INT_DM0                    (* (reg8 *) ITG_INT__DM0) 
#define ITG_INT_DM1                    (* (reg8 *) ITG_INT__DM1)
#define ITG_INT_DM2                    (* (reg8 *) ITG_INT__DM2) 
/* Input Buffer Disable Override */
#define ITG_INT_INP_DIS                (* (reg8 *) ITG_INT__INP_DIS)
/* LCD Common or Segment Drive */
#define ITG_INT_LCD_COM_SEG            (* (reg8 *) ITG_INT__LCD_COM_SEG)
/* Enable Segment LCD */
#define ITG_INT_LCD_EN                 (* (reg8 *) ITG_INT__LCD_EN)
/* Slew Rate Control */
#define ITG_INT_SLW                    (* (reg8 *) ITG_INT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ITG_INT_PRTDSI__CAPS_SEL       (* (reg8 *) ITG_INT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ITG_INT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ITG_INT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ITG_INT_PRTDSI__OE_SEL0        (* (reg8 *) ITG_INT__PRTDSI__OE_SEL0) 
#define ITG_INT_PRTDSI__OE_SEL1        (* (reg8 *) ITG_INT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ITG_INT_PRTDSI__OUT_SEL0       (* (reg8 *) ITG_INT__PRTDSI__OUT_SEL0) 
#define ITG_INT_PRTDSI__OUT_SEL1       (* (reg8 *) ITG_INT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ITG_INT_PRTDSI__SYNC_OUT       (* (reg8 *) ITG_INT__PRTDSI__SYNC_OUT) 


#if defined(ITG_INT__INTSTAT)  /* Interrupt Registers */

    #define ITG_INT_INTSTAT                (* (reg8 *) ITG_INT__INTSTAT)
    #define ITG_INT_SNAP                   (* (reg8 *) ITG_INT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ITG_INT_H */


/* [] END OF FILE */
