/*******************************************************************************
* File Name: Status_Reg_BUTTON.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_Status_Reg_BUTTON_H) /* CY_STATUS_REG_Status_Reg_BUTTON_H */
#define CY_STATUS_REG_Status_Reg_BUTTON_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 Status_Reg_BUTTON_Read(void) ;
void Status_Reg_BUTTON_InterruptEnable(void) ;
void Status_Reg_BUTTON_InterruptDisable(void) ;
void Status_Reg_BUTTON_WriteMask(uint8 mask) ;
uint8 Status_Reg_BUTTON_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Status_Reg_BUTTON_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Status_Reg_BUTTON_INPUTS              3


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Status_Reg_BUTTON_Status             (* (reg8 *) Status_Reg_BUTTON_sts_sts_reg__STATUS_REG )
#define Status_Reg_BUTTON_Status_PTR         (  (reg8 *) Status_Reg_BUTTON_sts_sts_reg__STATUS_REG )
#define Status_Reg_BUTTON_Status_Mask        (* (reg8 *) Status_Reg_BUTTON_sts_sts_reg__MASK_REG )
#define Status_Reg_BUTTON_Status_Aux_Ctrl    (* (reg8 *) Status_Reg_BUTTON_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Status_Reg_BUTTON_H */


/* [] END OF FILE */
