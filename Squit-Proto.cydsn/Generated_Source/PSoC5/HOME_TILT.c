/*******************************************************************************
* File Name: HOME_TILT.c  
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
#include "HOME_TILT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 HOME_TILT__PORT == 15 && ((HOME_TILT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: HOME_TILT_Write
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
void HOME_TILT_Write(uint8 value) 
{
    uint8 staticBits = (HOME_TILT_DR & (uint8)(~HOME_TILT_MASK));
    HOME_TILT_DR = staticBits | ((uint8)(value << HOME_TILT_SHIFT) & HOME_TILT_MASK);
}


/*******************************************************************************
* Function Name: HOME_TILT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HOME_TILT_DM_STRONG     Strong Drive 
*  HOME_TILT_DM_OD_HI      Open Drain, Drives High 
*  HOME_TILT_DM_OD_LO      Open Drain, Drives Low 
*  HOME_TILT_DM_RES_UP     Resistive Pull Up 
*  HOME_TILT_DM_RES_DWN    Resistive Pull Down 
*  HOME_TILT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HOME_TILT_DM_DIG_HIZ    High Impedance Digital 
*  HOME_TILT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HOME_TILT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HOME_TILT_0, mode);
}


/*******************************************************************************
* Function Name: HOME_TILT_Read
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
*  Macro HOME_TILT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HOME_TILT_Read(void) 
{
    return (HOME_TILT_PS & HOME_TILT_MASK) >> HOME_TILT_SHIFT;
}


/*******************************************************************************
* Function Name: HOME_TILT_ReadDataReg
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
uint8 HOME_TILT_ReadDataReg(void) 
{
    return (HOME_TILT_DR & HOME_TILT_MASK) >> HOME_TILT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HOME_TILT_INTSTAT) 

    /*******************************************************************************
    * Function Name: HOME_TILT_ClearInterrupt
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
    uint8 HOME_TILT_ClearInterrupt(void) 
    {
        return (HOME_TILT_INTSTAT & HOME_TILT_MASK) >> HOME_TILT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
