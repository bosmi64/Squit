/*******************************************************************************
* File Name: ECSPI_MOSI.h  
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

#if !defined(CY_PINS_ECSPI_MOSI_H) /* Pins ECSPI_MOSI_H */
#define CY_PINS_ECSPI_MOSI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ECSPI_MOSI_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ECSPI_MOSI_Write(uint8 value) ;
void    ECSPI_MOSI_SetDriveMode(uint8 mode) ;
uint8   ECSPI_MOSI_ReadDataReg(void) ;
uint8   ECSPI_MOSI_Read(void) ;
uint8   ECSPI_MOSI_ClearInterrupt(void) ;

/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ECSPI_MOSI_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ECSPI_MOSI_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ECSPI_MOSI_DM_RES_UP          PIN_DM_RES_UP
#define ECSPI_MOSI_DM_RES_DWN         PIN_DM_RES_DWN
#define ECSPI_MOSI_DM_OD_LO           PIN_DM_OD_LO
#define ECSPI_MOSI_DM_OD_HI           PIN_DM_OD_HI
#define ECSPI_MOSI_DM_STRONG          PIN_DM_STRONG
#define ECSPI_MOSI_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ECSPI_MOSI_MASK               ECSPI_MOSI__MASK
#define ECSPI_MOSI_SHIFT              ECSPI_MOSI__SHIFT
#define ECSPI_MOSI_WIDTH              1u

/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ECSPI_MOSI_PS                     (* (reg8 *) ECSPI_MOSI__PS)
/* Data Register */
#define ECSPI_MOSI_DR                     (* (reg8 *) ECSPI_MOSI__DR)
/* Port Number */
#define ECSPI_MOSI_PRT_NUM                (* (reg8 *) ECSPI_MOSI__PRT) 
/* Connect to Analog Globals */                                                  
#define ECSPI_MOSI_AG                     (* (reg8 *) ECSPI_MOSI__AG)                       
/* Analog MUX bux enable */
#define ECSPI_MOSI_AMUX                   (* (reg8 *) ECSPI_MOSI__AMUX) 
/* Bidirectional Enable */                                                        
#define ECSPI_MOSI_BIE                    (* (reg8 *) ECSPI_MOSI__BIE)
/* Bit-mask for Aliased Register Access */
#define ECSPI_MOSI_BIT_MASK               (* (reg8 *) ECSPI_MOSI__BIT_MASK)
/* Bypass Enable */
#define ECSPI_MOSI_BYP                    (* (reg8 *) ECSPI_MOSI__BYP)
/* Port wide control signals */                                                   
#define ECSPI_MOSI_CTL                    (* (reg8 *) ECSPI_MOSI__CTL)
/* Drive Modes */
#define ECSPI_MOSI_DM0                    (* (reg8 *) ECSPI_MOSI__DM0) 
#define ECSPI_MOSI_DM1                    (* (reg8 *) ECSPI_MOSI__DM1)
#define ECSPI_MOSI_DM2                    (* (reg8 *) ECSPI_MOSI__DM2) 
/* Input Buffer Disable Override */
#define ECSPI_MOSI_INP_DIS                (* (reg8 *) ECSPI_MOSI__INP_DIS)
/* LCD Common or Segment Drive */
#define ECSPI_MOSI_LCD_COM_SEG            (* (reg8 *) ECSPI_MOSI__LCD_COM_SEG)
/* Enable Segment LCD */
#define ECSPI_MOSI_LCD_EN                 (* (reg8 *) ECSPI_MOSI__LCD_EN)
/* Slew Rate Control */
#define ECSPI_MOSI_SLW                    (* (reg8 *) ECSPI_MOSI__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ECSPI_MOSI_PRTDSI__CAPS_SEL       (* (reg8 *) ECSPI_MOSI__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ECSPI_MOSI_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ECSPI_MOSI__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ECSPI_MOSI_PRTDSI__OE_SEL0        (* (reg8 *) ECSPI_MOSI__PRTDSI__OE_SEL0) 
#define ECSPI_MOSI_PRTDSI__OE_SEL1        (* (reg8 *) ECSPI_MOSI__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ECSPI_MOSI_PRTDSI__OUT_SEL0       (* (reg8 *) ECSPI_MOSI__PRTDSI__OUT_SEL0) 
#define ECSPI_MOSI_PRTDSI__OUT_SEL1       (* (reg8 *) ECSPI_MOSI__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ECSPI_MOSI_PRTDSI__SYNC_OUT       (* (reg8 *) ECSPI_MOSI__PRTDSI__SYNC_OUT) 


#if defined(ECSPI_MOSI__INTSTAT)  /* Interrupt Registers */

    #define ECSPI_MOSI_INTSTAT                (* (reg8 *) ECSPI_MOSI__INTSTAT)
    #define ECSPI_MOSI_SNAP                   (* (reg8 *) ECSPI_MOSI__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ECSPI_MOSI_H */


/* [] END OF FILE */
