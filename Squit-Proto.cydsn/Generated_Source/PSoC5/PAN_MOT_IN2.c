/*******************************************************************************
* File Name: PAN_MOT_IN2.c  
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
#include "PAN_MOT_IN2.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PAN_MOT_IN2__PORT == 15 && ((PAN_MOT_IN2__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PAN_MOT_IN2_Write
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
void PAN_MOT_IN2_Write(uint8 value) 
{
    uint8 staticBits = (PAN_MOT_IN2_DR & (uint8)(~PAN_MOT_IN2_MASK));
    PAN_MOT_IN2_DR = staticBits | ((uint8)(value << PAN_MOT_IN2_SHIFT) & PAN_MOT_IN2_MASK);
}


/*******************************************************************************
* Function Name: PAN_MOT_IN2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PAN_MOT_IN2_DM_STRONG     Strong Drive 
*  PAN_MOT_IN2_DM_OD_HI      Open Drain, Drives High 
*  PAN_MOT_IN2_DM_OD_LO      Open Drain, Drives Low 
*  PAN_MOT_IN2_DM_RES_UP     Resistive Pull Up 
*  PAN_MOT_IN2_DM_RES_DWN    Resistive Pull Down 
*  PAN_MOT_IN2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PAN_MOT_IN2_DM_DIG_HIZ    High Impedance Digital 
*  PAN_MOT_IN2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PAN_MOT_IN2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PAN_MOT_IN2_0, mode);
}


/*******************************************************************************
* Function Name: PAN_MOT_IN2_Read
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
*  Macro PAN_MOT_IN2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PAN_MOT_IN2_Read(void) 
{
    return (PAN_MOT_IN2_PS & PAN_MOT_IN2_MASK) >> PAN_MOT_IN2_SHIFT;
}


/*******************************************************************************
* Function Name: PAN_MOT_IN2_ReadDataReg
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
uint8 PAN_MOT_IN2_ReadDataReg(void) 
{
    return (PAN_MOT_IN2_DR & PAN_MOT_IN2_MASK) >> PAN_MOT_IN2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PAN_MOT_IN2_INTSTAT) 

    /*******************************************************************************
    * Function Name: PAN_MOT_IN2_ClearInterrupt
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
    uint8 PAN_MOT_IN2_ClearInterrupt(void) 
    {
        return (PAN_MOT_IN2_INTSTAT & PAN_MOT_IN2_MASK) >> PAN_MOT_IN2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
