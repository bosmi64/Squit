/*******************************************************************************
* File Name: IMU_UM7_TX.h  
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

#if !defined(CY_PINS_IMU_UM7_TX_H) /* Pins IMU_UM7_TX_H */
#define CY_PINS_IMU_UM7_TX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IMU_UM7_TX_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IMU_UM7_TX__PORT == 15 && ((IMU_UM7_TX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    IMU_UM7_TX_Write(uint8 value) ;
void    IMU_UM7_TX_SetDriveMode(uint8 mode) ;
uint8   IMU_UM7_TX_ReadDataReg(void) ;
uint8   IMU_UM7_TX_Read(void) ;
uint8   IMU_UM7_TX_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IMU_UM7_TX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define IMU_UM7_TX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define IMU_UM7_TX_DM_RES_UP          PIN_DM_RES_UP
#define IMU_UM7_TX_DM_RES_DWN         PIN_DM_RES_DWN
#define IMU_UM7_TX_DM_OD_LO           PIN_DM_OD_LO
#define IMU_UM7_TX_DM_OD_HI           PIN_DM_OD_HI
#define IMU_UM7_TX_DM_STRONG          PIN_DM_STRONG
#define IMU_UM7_TX_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define IMU_UM7_TX_MASK               IMU_UM7_TX__MASK
#define IMU_UM7_TX_SHIFT              IMU_UM7_TX__SHIFT
#define IMU_UM7_TX_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IMU_UM7_TX_PS                     (* (reg8 *) IMU_UM7_TX__PS)
/* Data Register */
#define IMU_UM7_TX_DR                     (* (reg8 *) IMU_UM7_TX__DR)
/* Port Number */
#define IMU_UM7_TX_PRT_NUM                (* (reg8 *) IMU_UM7_TX__PRT) 
/* Connect to Analog Globals */                                                  
#define IMU_UM7_TX_AG                     (* (reg8 *) IMU_UM7_TX__AG)                       
/* Analog MUX bux enable */
#define IMU_UM7_TX_AMUX                   (* (reg8 *) IMU_UM7_TX__AMUX) 
/* Bidirectional Enable */                                                        
#define IMU_UM7_TX_BIE                    (* (reg8 *) IMU_UM7_TX__BIE)
/* Bit-mask for Aliased Register Access */
#define IMU_UM7_TX_BIT_MASK               (* (reg8 *) IMU_UM7_TX__BIT_MASK)
/* Bypass Enable */
#define IMU_UM7_TX_BYP                    (* (reg8 *) IMU_UM7_TX__BYP)
/* Port wide control signals */                                                   
#define IMU_UM7_TX_CTL                    (* (reg8 *) IMU_UM7_TX__CTL)
/* Drive Modes */
#define IMU_UM7_TX_DM0                    (* (reg8 *) IMU_UM7_TX__DM0) 
#define IMU_UM7_TX_DM1                    (* (reg8 *) IMU_UM7_TX__DM1)
#define IMU_UM7_TX_DM2                    (* (reg8 *) IMU_UM7_TX__DM2) 
/* Input Buffer Disable Override */
#define IMU_UM7_TX_INP_DIS                (* (reg8 *) IMU_UM7_TX__INP_DIS)
/* LCD Common or Segment Drive */
#define IMU_UM7_TX_LCD_COM_SEG            (* (reg8 *) IMU_UM7_TX__LCD_COM_SEG)
/* Enable Segment LCD */
#define IMU_UM7_TX_LCD_EN                 (* (reg8 *) IMU_UM7_TX__LCD_EN)
/* Slew Rate Control */
#define IMU_UM7_TX_SLW                    (* (reg8 *) IMU_UM7_TX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IMU_UM7_TX_PRTDSI__CAPS_SEL       (* (reg8 *) IMU_UM7_TX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IMU_UM7_TX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IMU_UM7_TX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IMU_UM7_TX_PRTDSI__OE_SEL0        (* (reg8 *) IMU_UM7_TX__PRTDSI__OE_SEL0) 
#define IMU_UM7_TX_PRTDSI__OE_SEL1        (* (reg8 *) IMU_UM7_TX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IMU_UM7_TX_PRTDSI__OUT_SEL0       (* (reg8 *) IMU_UM7_TX__PRTDSI__OUT_SEL0) 
#define IMU_UM7_TX_PRTDSI__OUT_SEL1       (* (reg8 *) IMU_UM7_TX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IMU_UM7_TX_PRTDSI__SYNC_OUT       (* (reg8 *) IMU_UM7_TX__PRTDSI__SYNC_OUT) 


#if defined(IMU_UM7_TX__INTSTAT)  /* Interrupt Registers */

    #define IMU_UM7_TX_INTSTAT                (* (reg8 *) IMU_UM7_TX__INTSTAT)
    #define IMU_UM7_TX_SNAP                   (* (reg8 *) IMU_UM7_TX__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IMU_UM7_TX_H */


/* [] END OF FILE */
