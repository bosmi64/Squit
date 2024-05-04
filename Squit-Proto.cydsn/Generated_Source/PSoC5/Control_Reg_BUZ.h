/*******************************************************************************
* File Name: Control_Reg_BUZ.h  
* Version 1.70
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

#if !defined(CY_CONTROL_REG_Control_Reg_BUZ_H) /* CY_CONTROL_REG_Control_Reg_BUZ_H */
#define CY_CONTROL_REG_Control_Reg_BUZ_H

#include "cytypes.h"


/***************************************
*         Function Prototypes 
***************************************/

void    Control_Reg_BUZ_Write(uint8 control) ;
uint8   Control_Reg_BUZ_Read(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define Control_Reg_BUZ_Control        (* (reg8 *) Control_Reg_BUZ_Sync_ctrl_reg__CONTROL_REG )
#define Control_Reg_BUZ_Control_PTR    (  (reg8 *) Control_Reg_BUZ_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_Control_Reg_BUZ_H */


/* [] END OF FILE */
