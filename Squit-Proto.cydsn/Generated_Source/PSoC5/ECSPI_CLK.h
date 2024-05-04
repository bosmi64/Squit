/*******************************************************************************
* File Name: ECSPI_CLK.h  
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

#if !defined(CY_PINS_ECSPI_CLK_H) /* Pins ECSPI_CLK_H */
#define CY_PINS_ECSPI_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ECSPI_CLK_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ECSPI_CLK__PORT == 15 && ((ECSPI_CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ECSPI_CLK_Write(uint8 value) ;
void    ECSPI_CLK_SetDriveMode(uint8 mode) ;
uint8   ECSPI_CLK_ReadDataReg(void) ;
uint8   ECSPI_CLK_Read(void) ;
uint8   ECSPI_CLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ECSPI_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ECSPI_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ECSPI_CLK_DM_RES_UP          PIN_DM_RES_UP
#define ECSPI_CLK_DM_RES_DWN         PIN_DM_RES_DWN
#define ECSPI_CLK_DM_OD_LO           PIN_DM_OD_LO
#define ECSPI_CLK_DM_OD_HI           PIN_DM_OD_HI
#define ECSPI_CLK_DM_STRONG          PIN_DM_STRONG
#define ECSPI_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ECSPI_CLK_MASK               ECSPI_CLK__MASK
#define ECSPI_CLK_SHIFT              ECSPI_CLK__SHIFT
#define ECSPI_CLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ECSPI_CLK_PS                     (* (reg8 *) ECSPI_CLK__PS)
/* Data Register */
#define ECSPI_CLK_DR                     (* (reg8 *) ECSPI_CLK__DR)
/* Port Number */
#define ECSPI_CLK_PRT_NUM                (* (reg8 *) ECSPI_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define ECSPI_CLK_AG                     (* (reg8 *) ECSPI_CLK__AG)                       
/* Analog MUX bux enable */
#define ECSPI_CLK_AMUX                   (* (reg8 *) ECSPI_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define ECSPI_CLK_BIE                    (* (reg8 *) ECSPI_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define ECSPI_CLK_BIT_MASK               (* (reg8 *) ECSPI_CLK__BIT_MASK)
/* Bypass Enable */
#define ECSPI_CLK_BYP                    (* (reg8 *) ECSPI_CLK__BYP)
/* Port wide control signals */                                                   
#define ECSPI_CLK_CTL                    (* (reg8 *) ECSPI_CLK__CTL)
/* Drive Modes */
#define ECSPI_CLK_DM0                    (* (reg8 *) ECSPI_CLK__DM0) 
#define ECSPI_CLK_DM1                    (* (reg8 *) ECSPI_CLK__DM1)
#define ECSPI_CLK_DM2                    (* (reg8 *) ECSPI_CLK__DM2) 
/* Input Buffer Disable Override */
#define ECSPI_CLK_INP_DIS                (* (reg8 *) ECSPI_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define ECSPI_CLK_LCD_COM_SEG            (* (reg8 *) ECSPI_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define ECSPI_CLK_LCD_EN                 (* (reg8 *) ECSPI_CLK__LCD_EN)
/* Slew Rate Control */
#define ECSPI_CLK_SLW                    (* (reg8 *) ECSPI_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ECSPI_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) ECSPI_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ECSPI_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ECSPI_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ECSPI_CLK_PRTDSI__OE_SEL0        (* (reg8 *) ECSPI_CLK__PRTDSI__OE_SEL0) 
#define ECSPI_CLK_PRTDSI__OE_SEL1        (* (reg8 *) ECSPI_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ECSPI_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) ECSPI_CLK__PRTDSI__OUT_SEL0) 
#define ECSPI_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) ECSPI_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ECSPI_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) ECSPI_CLK__PRTDSI__SYNC_OUT) 


#if defined(ECSPI_CLK__INTSTAT)  /* Interrupt Registers */

    #define ECSPI_CLK_INTSTAT                (* (reg8 *) ECSPI_CLK__INTSTAT)
    #define ECSPI_CLK_SNAP                   (* (reg8 *) ECSPI_CLK__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ECSPI_CLK_H */


/* [] END OF FILE */
