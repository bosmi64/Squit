/*******************************************************************************
* File Name: BUT_DRIVE.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BUT_DRIVE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BUT_DRIVE__PORT == 15 && ((BUT_DRIVE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BUT_DRIVE_Write
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
void BUT_DRIVE_Write(uint8 value) 
{
    uint8 staticBits = (BUT_DRIVE_DR & (uint8)(~BUT_DRIVE_MASK));
    BUT_DRIVE_DR = staticBits | ((uint8)(value << BUT_DRIVE_SHIFT) & BUT_DRIVE_MASK);
}


/*******************************************************************************
* Function Name: BUT_DRIVE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void BUT_DRIVE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BUT_DRIVE_0, mode);
}


/*******************************************************************************
* Function Name: BUT_DRIVE_Read
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
*  Macro BUT_DRIVE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BUT_DRIVE_Read(void) 
{
    return (BUT_DRIVE_PS & BUT_DRIVE_MASK) >> BUT_DRIVE_SHIFT;
}


/*******************************************************************************
* Function Name: BUT_DRIVE_ReadDataReg
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
uint8 BUT_DRIVE_ReadDataReg(void) 
{
    return (BUT_DRIVE_DR & BUT_DRIVE_MASK) >> BUT_DRIVE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BUT_DRIVE_INTSTAT) 

    /*******************************************************************************
    * Function Name: BUT_DRIVE_ClearInterrupt
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
    uint8 BUT_DRIVE_ClearInterrupt(void) 
    {
        return (BUT_DRIVE_INTSTAT & BUT_DRIVE_MASK) >> BUT_DRIVE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
