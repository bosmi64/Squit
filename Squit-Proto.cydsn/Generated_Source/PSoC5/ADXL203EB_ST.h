/*******************************************************************************
* File Name: ADXL203EB_ST.h  
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

#if !defined(CY_PINS_ADXL203EB_ST_H) /* Pins ADXL203EB_ST_H */
#define CY_PINS_ADXL203EB_ST_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADXL203EB_ST_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADXL203EB_ST__PORT == 15 && ((ADXL203EB_ST__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ADXL203EB_ST_Write(uint8 value) ;
void    ADXL203EB_ST_SetDriveMode(uint8 mode) ;
uint8   ADXL203EB_ST_ReadDataReg(void) ;
uint8   ADXL203EB_ST_Read(void) ;
uint8   ADXL203EB_ST_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADXL203EB_ST_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ADXL203EB_ST_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ADXL203EB_ST_DM_RES_UP          PIN_DM_RES_UP
#define ADXL203EB_ST_DM_RES_DWN         PIN_DM_RES_DWN
#define ADXL203EB_ST_DM_OD_LO           PIN_DM_OD_LO
#define ADXL203EB_ST_DM_OD_HI           PIN_DM_OD_HI
#define ADXL203EB_ST_DM_STRONG          PIN_DM_STRONG
#define ADXL203EB_ST_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ADXL203EB_ST_MASK               ADXL203EB_ST__MASK
#define ADXL203EB_ST_SHIFT              ADXL203EB_ST__SHIFT
#define ADXL203EB_ST_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADXL203EB_ST_PS                     (* (reg8 *) ADXL203EB_ST__PS)
/* Data Register */
#define ADXL203EB_ST_DR                     (* (reg8 *) ADXL203EB_ST__DR)
/* Port Number */
#define ADXL203EB_ST_PRT_NUM                (* (reg8 *) ADXL203EB_ST__PRT) 
/* Connect to Analog Globals */                                                  
#define ADXL203EB_ST_AG                     (* (reg8 *) ADXL203EB_ST__AG)                       
/* Analog MUX bux enable */
#define ADXL203EB_ST_AMUX                   (* (reg8 *) ADXL203EB_ST__AMUX) 
/* Bidirectional Enable */                                                        
#define ADXL203EB_ST_BIE                    (* (reg8 *) ADXL203EB_ST__BIE)
/* Bit-mask for Aliased Register Access */
#define ADXL203EB_ST_BIT_MASK               (* (reg8 *) ADXL203EB_ST__BIT_MASK)
/* Bypass Enable */
#define ADXL203EB_ST_BYP                    (* (reg8 *) ADXL203EB_ST__BYP)
/* Port wide control signals */                                                   
#define ADXL203EB_ST_CTL                    (* (reg8 *) ADXL203EB_ST__CTL)
/* Drive Modes */
#define ADXL203EB_ST_DM0                    (* (reg8 *) ADXL203EB_ST__DM0) 
#define ADXL203EB_ST_DM1                    (* (reg8 *) ADXL203EB_ST__DM1)
#define ADXL203EB_ST_DM2                    (* (reg8 *) ADXL203EB_ST__DM2) 
/* Input Buffer Disable Override */
#define ADXL203EB_ST_INP_DIS                (* (reg8 *) ADXL203EB_ST__INP_DIS)
/* LCD Common or Segment Drive */
#define ADXL203EB_ST_LCD_COM_SEG            (* (reg8 *) ADXL203EB_ST__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADXL203EB_ST_LCD_EN                 (* (reg8 *) ADXL203EB_ST__LCD_EN)
/* Slew Rate Control */
#define ADXL203EB_ST_SLW                    (* (reg8 *) ADXL203EB_ST__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADXL203EB_ST_PRTDSI__CAPS_SEL       (* (reg8 *) ADXL203EB_ST__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADXL203EB_ST_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADXL203EB_ST__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADXL203EB_ST_PRTDSI__OE_SEL0        (* (reg8 *) ADXL203EB_ST__PRTDSI__OE_SEL0) 
#define ADXL203EB_ST_PRTDSI__OE_SEL1        (* (reg8 *) ADXL203EB_ST__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADXL203EB_ST_PRTDSI__OUT_SEL0       (* (reg8 *) ADXL203EB_ST__PRTDSI__OUT_SEL0) 
#define ADXL203EB_ST_PRTDSI__OUT_SEL1       (* (reg8 *) ADXL203EB_ST__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADXL203EB_ST_PRTDSI__SYNC_OUT       (* (reg8 *) ADXL203EB_ST__PRTDSI__SYNC_OUT) 


#if defined(ADXL203EB_ST__INTSTAT)  /* Interrupt Registers */

    #define ADXL203EB_ST_INTSTAT                (* (reg8 *) ADXL203EB_ST__INTSTAT)
    #define ADXL203EB_ST_SNAP                   (* (reg8 *) ADXL203EB_ST__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADXL203EB_ST_H */


/* [] END OF FILE */
