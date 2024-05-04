/*******************************************************************************
* File Name: ITG_SDA_SDI.h  
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

#if !defined(CY_PINS_ITG_SDA_SDI_H) /* Pins ITG_SDA_SDI_H */
#define CY_PINS_ITG_SDA_SDI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ITG_SDA_SDI_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ITG_SDA_SDI__PORT == 15 && ((ITG_SDA_SDI__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ITG_SDA_SDI_Write(uint8 value) ;
void    ITG_SDA_SDI_SetDriveMode(uint8 mode) ;
uint8   ITG_SDA_SDI_ReadDataReg(void) ;
uint8   ITG_SDA_SDI_Read(void) ;
uint8   ITG_SDA_SDI_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ITG_SDA_SDI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ITG_SDA_SDI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ITG_SDA_SDI_DM_RES_UP          PIN_DM_RES_UP
#define ITG_SDA_SDI_DM_RES_DWN         PIN_DM_RES_DWN
#define ITG_SDA_SDI_DM_OD_LO           PIN_DM_OD_LO
#define ITG_SDA_SDI_DM_OD_HI           PIN_DM_OD_HI
#define ITG_SDA_SDI_DM_STRONG          PIN_DM_STRONG
#define ITG_SDA_SDI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ITG_SDA_SDI_MASK               ITG_SDA_SDI__MASK
#define ITG_SDA_SDI_SHIFT              ITG_SDA_SDI__SHIFT
#define ITG_SDA_SDI_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ITG_SDA_SDI_PS                     (* (reg8 *) ITG_SDA_SDI__PS)
/* Data Register */
#define ITG_SDA_SDI_DR                     (* (reg8 *) ITG_SDA_SDI__DR)
/* Port Number */
#define ITG_SDA_SDI_PRT_NUM                (* (reg8 *) ITG_SDA_SDI__PRT) 
/* Connect to Analog Globals */                                                  
#define ITG_SDA_SDI_AG                     (* (reg8 *) ITG_SDA_SDI__AG)                       
/* Analog MUX bux enable */
#define ITG_SDA_SDI_AMUX                   (* (reg8 *) ITG_SDA_SDI__AMUX) 
/* Bidirectional Enable */                                                        
#define ITG_SDA_SDI_BIE                    (* (reg8 *) ITG_SDA_SDI__BIE)
/* Bit-mask for Aliased Register Access */
#define ITG_SDA_SDI_BIT_MASK               (* (reg8 *) ITG_SDA_SDI__BIT_MASK)
/* Bypass Enable */
#define ITG_SDA_SDI_BYP                    (* (reg8 *) ITG_SDA_SDI__BYP)
/* Port wide control signals */                                                   
#define ITG_SDA_SDI_CTL                    (* (reg8 *) ITG_SDA_SDI__CTL)
/* Drive Modes */
#define ITG_SDA_SDI_DM0                    (* (reg8 *) ITG_SDA_SDI__DM0) 
#define ITG_SDA_SDI_DM1                    (* (reg8 *) ITG_SDA_SDI__DM1)
#define ITG_SDA_SDI_DM2                    (* (reg8 *) ITG_SDA_SDI__DM2) 
/* Input Buffer Disable Override */
#define ITG_SDA_SDI_INP_DIS                (* (reg8 *) ITG_SDA_SDI__INP_DIS)
/* LCD Common or Segment Drive */
#define ITG_SDA_SDI_LCD_COM_SEG            (* (reg8 *) ITG_SDA_SDI__LCD_COM_SEG)
/* Enable Segment LCD */
#define ITG_SDA_SDI_LCD_EN                 (* (reg8 *) ITG_SDA_SDI__LCD_EN)
/* Slew Rate Control */
#define ITG_SDA_SDI_SLW                    (* (reg8 *) ITG_SDA_SDI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ITG_SDA_SDI_PRTDSI__CAPS_SEL       (* (reg8 *) ITG_SDA_SDI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ITG_SDA_SDI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ITG_SDA_SDI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ITG_SDA_SDI_PRTDSI__OE_SEL0        (* (reg8 *) ITG_SDA_SDI__PRTDSI__OE_SEL0) 
#define ITG_SDA_SDI_PRTDSI__OE_SEL1        (* (reg8 *) ITG_SDA_SDI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ITG_SDA_SDI_PRTDSI__OUT_SEL0       (* (reg8 *) ITG_SDA_SDI__PRTDSI__OUT_SEL0) 
#define ITG_SDA_SDI_PRTDSI__OUT_SEL1       (* (reg8 *) ITG_SDA_SDI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ITG_SDA_SDI_PRTDSI__SYNC_OUT       (* (reg8 *) ITG_SDA_SDI__PRTDSI__SYNC_OUT) 


#if defined(ITG_SDA_SDI__INTSTAT)  /* Interrupt Registers */

    #define ITG_SDA_SDI_INTSTAT                (* (reg8 *) ITG_SDA_SDI__INTSTAT)
    #define ITG_SDA_SDI_SNAP                   (* (reg8 *) ITG_SDA_SDI__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ITG_SDA_SDI_H */


/* [] END OF FILE */
