/*******************************************************************************
* File Name: HOME_PAN.c  
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
#include "HOME_PAN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HOME_PAN__PORT == 15 && ((HOME_PAN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HOME_PAN_Write
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
void HOME_PAN_Write(uint8 value) 
{
    uint8 staticBits = (HOME_PAN_DR & (uint8)(~HOME_PAN_MASK));
    HOME_PAN_DR = staticBits | ((uint8)(value << HOME_PAN_SHIFT) & HOME_PAN_MASK);
}


/*******************************************************************************
* Function Name: HOME_PAN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HOME_PAN_DM_STRONG     Strong Drive 
*  HOME_PAN_DM_OD_HI      Open Drain, Drives High 
*  HOME_PAN_DM_OD_LO      Open Drain, Drives Low 
*  HOME_PAN_DM_RES_UP     Resistive Pull Up 
*  HOME_PAN_DM_RES_DWN    Resistive Pull Down 
*  HOME_PAN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HOME_PAN_DM_DIG_HIZ    High Impedance Digital 
*  HOME_PAN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HOME_PAN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HOME_PAN_0, mode);
}


/*******************************************************************************
* Function Name: HOME_PAN_Read
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
*  Macro HOME_PAN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HOME_PAN_Read(void) 
{
    return (HOME_PAN_PS & HOME_PAN_MASK) >> HOME_PAN_SHIFT;
}


/*******************************************************************************
* Function Name: HOME_PAN_ReadDataReg
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
uint8 HOME_PAN_ReadDataReg(void) 
{
    return (HOME_PAN_DR & HOME_PAN_MASK) >> HOME_PAN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HOME_PAN_INTSTAT) 

    /*******************************************************************************
    * Function Name: HOME_PAN_ClearInterrupt
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
    uint8 HOME_PAN_ClearInterrupt(void) 
    {
        return (HOME_PAN_INTSTAT & HOME_PAN_MASK) >> HOME_PAN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
