/*******************************************************************************
* File Name: BAT_CHRGn.c  
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
#include "BAT_CHRGn.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BAT_CHRGn__PORT == 15 && ((BAT_CHRGn__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BAT_CHRGn_Write
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
void BAT_CHRGn_Write(uint8 value) 
{
    uint8 staticBits = (BAT_CHRGn_DR & (uint8)(~BAT_CHRGn_MASK));
    BAT_CHRGn_DR = staticBits | ((uint8)(value << BAT_CHRGn_SHIFT) & BAT_CHRGn_MASK);
}


/*******************************************************************************
* Function Name: BAT_CHRGn_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BAT_CHRGn_DM_STRONG     Strong Drive 
*  BAT_CHRGn_DM_OD_HI      Open Drain, Drives High 
*  BAT_CHRGn_DM_OD_LO      Open Drain, Drives Low 
*  BAT_CHRGn_DM_RES_UP     Resistive Pull Up 
*  BAT_CHRGn_DM_RES_DWN    Resistive Pull Down 
*  BAT_CHRGn_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BAT_CHRGn_DM_DIG_HIZ    High Impedance Digital 
*  BAT_CHRGn_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BAT_CHRGn_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BAT_CHRGn_0, mode);
}


/*******************************************************************************
* Function Name: BAT_CHRGn_Read
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
*  Macro BAT_CHRGn_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BAT_CHRGn_Read(void) 
{
    return (BAT_CHRGn_PS & BAT_CHRGn_MASK) >> BAT_CHRGn_SHIFT;
}


/*******************************************************************************
* Function Name: BAT_CHRGn_ReadDataReg
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
uint8 BAT_CHRGn_ReadDataReg(void) 
{
    return (BAT_CHRGn_DR & BAT_CHRGn_MASK) >> BAT_CHRGn_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BAT_CHRGn_INTSTAT) 

    /*******************************************************************************
    * Function Name: BAT_CHRGn_ClearInterrupt
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
    uint8 BAT_CHRGn_ClearInterrupt(void) 
    {
        return (BAT_CHRGn_INTSTAT & BAT_CHRGn_MASK) >> BAT_CHRGn_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
