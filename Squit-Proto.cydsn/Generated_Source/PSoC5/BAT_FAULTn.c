/*******************************************************************************
* File Name: BAT_FAULTn.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BAT_FAULTn.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BAT_FAULTn__PORT == 15 && ((BAT_FAULTn__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BAT_FAULTn_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void BAT_FAULTn_Write(uint8 value) 
{
    uint8 staticBits = (BAT_FAULTn_DR & (uint8)(~BAT_FAULTn_MASK));
    BAT_FAULTn_DR = staticBits | ((uint8)(value << BAT_FAULTn_SHIFT) & BAT_FAULTn_MASK);
}


/*******************************************************************************
* Function Name: BAT_FAULTn_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BAT_FAULTn_DM_STRONG     Strong Drive 
*  BAT_FAULTn_DM_OD_HI      Open Drain, Drives High 
*  BAT_FAULTn_DM_OD_LO      Open Drain, Drives Low 
*  BAT_FAULTn_DM_RES_UP     Resistive Pull Up 
*  BAT_FAULTn_DM_RES_DWN    Resistive Pull Down 
*  BAT_FAULTn_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BAT_FAULTn_DM_DIG_HIZ    High Impedance Digital 
*  BAT_FAULTn_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BAT_FAULTn_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BAT_FAULTn_0, mode);
}


/*******************************************************************************
* Function Name: BAT_FAULTn_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro BAT_FAULTn_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BAT_FAULTn_Read(void) 
{
    return (BAT_FAULTn_PS & BAT_FAULTn_MASK) >> BAT_FAULTn_SHIFT;
}


/*******************************************************************************
* Function Name: BAT_FAULTn_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 BAT_FAULTn_ReadDataReg(void) 
{
    return (BAT_FAULTn_DR & BAT_FAULTn_MASK) >> BAT_FAULTn_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BAT_FAULTn_INTSTAT) 

    /*******************************************************************************
    * Function Name: BAT_FAULTn_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 BAT_FAULTn_ClearInterrupt(void) 
    {
        return (BAT_FAULTn_INTSTAT & BAT_FAULTn_MASK) >> BAT_FAULTn_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
