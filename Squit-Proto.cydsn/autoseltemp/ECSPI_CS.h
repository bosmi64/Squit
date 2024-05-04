/*******************************************************************************
* File Name: ECSPI_CS.h  
* Version 1.60
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PINS_ECSPI_CS_H) /* Pins ECSPI_CS_H */
#define CY_PINS_ECSPI_CS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ECSPI_CS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ECSPI_CS_Write(uint8 value) ;
void    ECSPI_CS_SetDriveMode(uint8 mode) ;
uint8   ECSPI_CS_ReadDataReg(void) ;
uint8   ECSPI_CS_Read(void) ;
uint8   ECSPI_CS_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ECSPI_CS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ECSPI_CS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ECSPI_CS_DM_RES_UP          PIN_DM_RES_UP
#define ECSPI_CS_DM_RES_DWN         PIN_DM_RES_DWN
#define ECSPI_CS_DM_OD_LO           PIN_DM_OD_LO
#define ECSPI_CS_DM_OD_HI           PIN_DM_OD_HI
#define ECSPI_CS_DM_STRONG          PIN_DM_STRONG
#define ECSPI_CS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ECSPI_CS_MASK               ECSPI_CS__MASK
#define ECSPI_CS_SHIFT              ECSPI_CS__SHIFT
#define ECSPI_CS_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ECSPI_CS_PS                     (* (reg8 *) ECSPI_CS__PS)
/* Data Register */
#define ECSPI_CS_DR                     (* (reg8 *) ECSPI_CS__DR)
/* Port Number */
#define ECSPI_CS_PRT_NUM                (* (reg8 *) ECSPI_CS__PRT) 
/* Connect to Analog Globals */                                                  
#define ECSPI_CS_AG                     (* (reg8 *) ECSPI_CS__AG)                       
/* Analog MUX bux enable */
#define ECSPI_CS_AMUX                   (* (reg8 *) ECSPI_CS__AMUX) 
/* Bidirectional Enable */                                                        
#define ECSPI_CS_BIE                    (* (reg8 *) ECSPI_CS__BIE)
/* Bit-mask for Aliased Register Access */
#define ECSPI_CS_BIT_MASK               (* (reg8 *) ECSPI_CS__BIT_MASK)
/* Bypass Enable */
#define ECSPI_CS_BYP                    (* (reg8 *) ECSPI_CS__BYP)
/* Port wide control signals */                                                   
#define ECSPI_CS_CTL                    (* (reg8 *) ECSPI_CS__CTL)
/* Drive Modes */
#define ECSPI_CS_DM0                    (* (reg8 *) ECSPI_CS__DM0) 
#define ECSPI_CS_DM1                    (* (reg8 *) ECSPI_CS__DM1)
#define ECSPI_CS_DM2                    (* (reg8 *) ECSPI_CS__DM2) 
/* Input Buffer Disable Override */
#define ECSPI_CS_INP_DIS                (* (reg8 *) ECSPI_CS__INP_DIS)
/* LCD Common or Segment Drive */
#define ECSPI_CS_LCD_COM_SEG            (* (reg8 *) ECSPI_CS__LCD_COM_SEG)
/* Enable Segment LCD */
#define ECSPI_CS_LCD_EN                 (* (reg8 *) ECSPI_CS__LCD_EN)
/* Slew Rate Control */
#define ECSPI_CS_SLW                    (* (reg8 *) ECSPI_CS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ECSPI_CS_PRTDSI__CAPS_SEL       (* (reg8 *) ECSPI_CS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ECSPI_CS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ECSPI_CS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ECSPI_CS_PRTDSI__OE_SEL0        (* (reg8 *) ECSPI_CS__PRTDSI__OE_SEL0) 
#define ECSPI_CS_PRTDSI__OE_SEL1        (* (reg8 *) ECSPI_CS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ECSPI_CS_PRTDSI__OUT_SEL0       (* (reg8 *) ECSPI_CS__PRTDSI__OUT_SEL0) 
#define ECSPI_CS_PRTDSI__OUT_SEL1       (* (reg8 *) ECSPI_CS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ECSPI_CS_PRTDSI__SYNC_OUT       (* (reg8 *) ECSPI_CS__PRTDSI__SYNC_OUT) 


#if defined(ECSPI_CS__INTSTAT)  /* Interrupt Registers */

    #define ECSPI_CS_INTSTAT                (* (reg8 *) ECSPI_CS__INTSTAT)
    #define ECSPI_CS_SNAP                   (* (reg8 *) ECSPI_CS__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ECSPI_CS_H */


/* [] END OF FILE */
