/*******************************************************************************
* File Name: Control_Reg_LED.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a control register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "Control_Reg_LED.h"

#if !defined(Control_Reg_LED_ctrl_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Control_Reg_LED_Write
********************************************************************************
*
* Summary:
*  Write a byte to a control register.
*
* Parameters:  
*  control:  The value to be assigned to the control register. 
*
* Return: 
*  void 
*
* Reentrant:
*  Yes
*  
*******************************************************************************/
void Control_Reg_LED_Write(uint8 control) 
{
    Control_Reg_LED_Control = control;
}


/*******************************************************************************
* Function Name: Control_Reg_LED_Read
********************************************************************************
*
* Summary:
*  Read the current value assigned to a control register.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the control register
*
* Reentrant:
*  Yes
*  
*******************************************************************************/
uint8 Control_Reg_LED_Read(void) 
{
    return Control_Reg_LED_Control;
}

#endif /* End check for removal by optimization */
