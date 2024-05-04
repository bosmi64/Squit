/*******************************************************************************
* File Name: Control_Reg_BUZ.c  
* Version 1.70
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Control_Reg_BUZ.h"

#if !defined(Control_Reg_BUZ_Sync_ctrl_reg__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
* Function Name: Control_Reg_BUZ_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void Control_Reg_BUZ_Write(uint8 control) 
{
    Control_Reg_BUZ_Control = control;
}


/*******************************************************************************
* Function Name: Control_Reg_BUZ_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 Control_Reg_BUZ_Read(void) 
{
    return Control_Reg_BUZ_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */