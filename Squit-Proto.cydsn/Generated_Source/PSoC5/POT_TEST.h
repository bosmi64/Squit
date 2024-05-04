/*******************************************************************************
* File Name: POT_TEST.h  
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

#if !defined(CY_PINS_POT_TEST_H) /* Pins POT_TEST_H */
#define CY_PINS_POT_TEST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT_TEST_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT_TEST__PORT == 15 && ((POT_TEST__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    POT_TEST_Write(uint8 value) ;
void    POT_TEST_SetDriveMode(uint8 mode) ;
uint8   POT_TEST_ReadDataReg(void) ;
uint8   POT_TEST_Read(void) ;
uint8   POT_TEST_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POT_TEST_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define POT_TEST_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define POT_TEST_DM_RES_UP          PIN_DM_RES_UP
#define POT_TEST_DM_RES_DWN         PIN_DM_RES_DWN
#define POT_TEST_DM_OD_LO           PIN_DM_OD_LO
#define POT_TEST_DM_OD_HI           PIN_DM_OD_HI
#define POT_TEST_DM_STRONG          PIN_DM_STRONG
#define POT_TEST_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define POT_TEST_MASK               POT_TEST__MASK
#define POT_TEST_SHIFT              POT_TEST__SHIFT
#define POT_TEST_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_TEST_PS                     (* (reg8 *) POT_TEST__PS)
/* Data Register */
#define POT_TEST_DR                     (* (reg8 *) POT_TEST__DR)
/* Port Number */
#define POT_TEST_PRT_NUM                (* (reg8 *) POT_TEST__PRT) 
/* Connect to Analog Globals */                                                  
#define POT_TEST_AG                     (* (reg8 *) POT_TEST__AG)                       
/* Analog MUX bux enable */
#define POT_TEST_AMUX                   (* (reg8 *) POT_TEST__AMUX) 
/* Bidirectional Enable */                                                        
#define POT_TEST_BIE                    (* (reg8 *) POT_TEST__BIE)
/* Bit-mask for Aliased Register Access */
#define POT_TEST_BIT_MASK               (* (reg8 *) POT_TEST__BIT_MASK)
/* Bypass Enable */
#define POT_TEST_BYP                    (* (reg8 *) POT_TEST__BYP)
/* Port wide control signals */                                                   
#define POT_TEST_CTL                    (* (reg8 *) POT_TEST__CTL)
/* Drive Modes */
#define POT_TEST_DM0                    (* (reg8 *) POT_TEST__DM0) 
#define POT_TEST_DM1                    (* (reg8 *) POT_TEST__DM1)
#define POT_TEST_DM2                    (* (reg8 *) POT_TEST__DM2) 
/* Input Buffer Disable Override */
#define POT_TEST_INP_DIS                (* (reg8 *) POT_TEST__INP_DIS)
/* LCD Common or Segment Drive */
#define POT_TEST_LCD_COM_SEG            (* (reg8 *) POT_TEST__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT_TEST_LCD_EN                 (* (reg8 *) POT_TEST__LCD_EN)
/* Slew Rate Control */
#define POT_TEST_SLW                    (* (reg8 *) POT_TEST__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT_TEST_PRTDSI__CAPS_SEL       (* (reg8 *) POT_TEST__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT_TEST_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT_TEST__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT_TEST_PRTDSI__OE_SEL0        (* (reg8 *) POT_TEST__PRTDSI__OE_SEL0) 
#define POT_TEST_PRTDSI__OE_SEL1        (* (reg8 *) POT_TEST__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT_TEST_PRTDSI__OUT_SEL0       (* (reg8 *) POT_TEST__PRTDSI__OUT_SEL0) 
#define POT_TEST_PRTDSI__OUT_SEL1       (* (reg8 *) POT_TEST__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT_TEST_PRTDSI__SYNC_OUT       (* (reg8 *) POT_TEST__PRTDSI__SYNC_OUT) 


#if defined(POT_TEST__INTSTAT)  /* Interrupt Registers */

    #define POT_TEST_INTSTAT                (* (reg8 *) POT_TEST__INTSTAT)
    #define POT_TEST_SNAP                   (* (reg8 *) POT_TEST__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT_TEST_H */


/* [] END OF FILE */
