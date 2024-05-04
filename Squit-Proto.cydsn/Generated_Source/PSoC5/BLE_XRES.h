/*******************************************************************************
* File Name: BLE_XRES.h  
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

#if !defined(CY_PINS_BLE_XRES_H) /* Pins BLE_XRES_H */
#define CY_PINS_BLE_XRES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BLE_XRES_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BLE_XRES__PORT == 15 && ((BLE_XRES__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    BLE_XRES_Write(uint8 value) ;
void    BLE_XRES_SetDriveMode(uint8 mode) ;
uint8   BLE_XRES_ReadDataReg(void) ;
uint8   BLE_XRES_Read(void) ;
uint8   BLE_XRES_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BLE_XRES_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BLE_XRES_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BLE_XRES_DM_RES_UP          PIN_DM_RES_UP
#define BLE_XRES_DM_RES_DWN         PIN_DM_RES_DWN
#define BLE_XRES_DM_OD_LO           PIN_DM_OD_LO
#define BLE_XRES_DM_OD_HI           PIN_DM_OD_HI
#define BLE_XRES_DM_STRONG          PIN_DM_STRONG
#define BLE_XRES_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BLE_XRES_MASK               BLE_XRES__MASK
#define BLE_XRES_SHIFT              BLE_XRES__SHIFT
#define BLE_XRES_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLE_XRES_PS                     (* (reg8 *) BLE_XRES__PS)
/* Data Register */
#define BLE_XRES_DR                     (* (reg8 *) BLE_XRES__DR)
/* Port Number */
#define BLE_XRES_PRT_NUM                (* (reg8 *) BLE_XRES__PRT) 
/* Connect to Analog Globals */                                                  
#define BLE_XRES_AG                     (* (reg8 *) BLE_XRES__AG)                       
/* Analog MUX bux enable */
#define BLE_XRES_AMUX                   (* (reg8 *) BLE_XRES__AMUX) 
/* Bidirectional Enable */                                                        
#define BLE_XRES_BIE                    (* (reg8 *) BLE_XRES__BIE)
/* Bit-mask for Aliased Register Access */
#define BLE_XRES_BIT_MASK               (* (reg8 *) BLE_XRES__BIT_MASK)
/* Bypass Enable */
#define BLE_XRES_BYP                    (* (reg8 *) BLE_XRES__BYP)
/* Port wide control signals */                                                   
#define BLE_XRES_CTL                    (* (reg8 *) BLE_XRES__CTL)
/* Drive Modes */
#define BLE_XRES_DM0                    (* (reg8 *) BLE_XRES__DM0) 
#define BLE_XRES_DM1                    (* (reg8 *) BLE_XRES__DM1)
#define BLE_XRES_DM2                    (* (reg8 *) BLE_XRES__DM2) 
/* Input Buffer Disable Override */
#define BLE_XRES_INP_DIS                (* (reg8 *) BLE_XRES__INP_DIS)
/* LCD Common or Segment Drive */
#define BLE_XRES_LCD_COM_SEG            (* (reg8 *) BLE_XRES__LCD_COM_SEG)
/* Enable Segment LCD */
#define BLE_XRES_LCD_EN                 (* (reg8 *) BLE_XRES__LCD_EN)
/* Slew Rate Control */
#define BLE_XRES_SLW                    (* (reg8 *) BLE_XRES__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BLE_XRES_PRTDSI__CAPS_SEL       (* (reg8 *) BLE_XRES__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BLE_XRES_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BLE_XRES__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BLE_XRES_PRTDSI__OE_SEL0        (* (reg8 *) BLE_XRES__PRTDSI__OE_SEL0) 
#define BLE_XRES_PRTDSI__OE_SEL1        (* (reg8 *) BLE_XRES__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BLE_XRES_PRTDSI__OUT_SEL0       (* (reg8 *) BLE_XRES__PRTDSI__OUT_SEL0) 
#define BLE_XRES_PRTDSI__OUT_SEL1       (* (reg8 *) BLE_XRES__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BLE_XRES_PRTDSI__SYNC_OUT       (* (reg8 *) BLE_XRES__PRTDSI__SYNC_OUT) 


#if defined(BLE_XRES__INTSTAT)  /* Interrupt Registers */

    #define BLE_XRES_INTSTAT                (* (reg8 *) BLE_XRES__INTSTAT)
    #define BLE_XRES_SNAP                   (* (reg8 *) BLE_XRES__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BLE_XRES_H */


/* [] END OF FILE */
