/*******************************************************************************
* File Name: SENSE_ITILT.c  
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
#include "SENSE_ITILT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SENSE_ITILT__PORT == 15 && ((SENSE_ITILT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SENSE_ITILT_Write
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
void SENSE_ITILT_Write(uint8 value) 
{
    uint8 staticBits = (SENSE_ITILT_DR & (uint8)(~SENSE_ITILT_MASK));
    SENSE_ITILT_DR = staticBits | ((uint8)(value << SENSE_ITILT_SHIFT) & SENSE_ITILT_MASK);
}


/*******************************************************************************
* Function Name: SENSE_ITILT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SENSE_ITILT_DM_STRONG     Strong Drive 
*  SENSE_ITILT_DM_OD_HI      Open Drain, Drives High 
*  SENSE_ITILT_DM_OD_LO      Open Drain, Drives Low 
*  SENSE_ITILT_DM_RES_UP     Resistive Pull Up 
*  SENSE_ITILT_DM_RES_DWN    Resistive Pull Down 
*  SENSE_ITILT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SENSE_ITILT_DM_DIG_HIZ    High Impedance Digital 
*  SENSE_ITILT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SENSE_ITILT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SENSE_ITILT_0, mode);
}


/*******************************************************************************
* Function Name: SENSE_ITILT_Read
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
*  Macro SENSE_ITILT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SENSE_ITILT_Read(void) 
{
    return (SENSE_ITILT_PS & SENSE_ITILT_MASK) >> SENSE_ITILT_SHIFT;
}


/*******************************************************************************
* Function Name: SENSE_ITILT_ReadDataReg
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
uint8 SENSE_ITILT_ReadDataReg(void) 
{
    return (SENSE_ITILT_DR & SENSE_ITILT_MASK) >> SENSE_ITILT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SENSE_ITILT_INTSTAT) 

    /*******************************************************************************
    * Function Name: SENSE_ITILT_ClearInterrupt
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
    uint8 SENSE_ITILT_ClearInterrupt(void) 
    {
        return (SENSE_ITILT_INTSTAT & SENSE_ITILT_MASK) >> SENSE_ITILT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
