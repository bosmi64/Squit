/*******************************************************************************
* File Name: BUZ.c  
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
#include "BUZ.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BUZ__PORT == 15 && ((BUZ__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BUZ_Write
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
void BUZ_Write(uint8 value) 
{
    uint8 staticBits = (BUZ_DR & (uint8)(~BUZ_MASK));
    BUZ_DR = staticBits | ((uint8)(value << BUZ_SHIFT) & BUZ_MASK);
}


/*******************************************************************************
* Function Name: BUZ_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BUZ_DM_STRONG     Strong Drive 
*  BUZ_DM_OD_HI      Open Drain, Drives High 
*  BUZ_DM_OD_LO      Open Drain, Drives Low 
*  BUZ_DM_RES_UP     Resistive Pull Up 
*  BUZ_DM_RES_DWN    Resistive Pull Down 
*  BUZ_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BUZ_DM_DIG_HIZ    High Impedance Digital 
*  BUZ_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BUZ_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BUZ_0, mode);
}


/*******************************************************************************
* Function Name: BUZ_Read
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
*  Macro BUZ_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BUZ_Read(void) 
{
    return (BUZ_PS & BUZ_MASK) >> BUZ_SHIFT;
}


/*******************************************************************************
* Function Name: BUZ_ReadDataReg
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
uint8 BUZ_ReadDataReg(void) 
{
    return (BUZ_DR & BUZ_MASK) >> BUZ_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BUZ_INTSTAT) 

    /*******************************************************************************
    * Function Name: BUZ_ClearInterrupt
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
    uint8 BUZ_ClearInterrupt(void) 
    {
        return (BUZ_INTSTAT & BUZ_MASK) >> BUZ_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
