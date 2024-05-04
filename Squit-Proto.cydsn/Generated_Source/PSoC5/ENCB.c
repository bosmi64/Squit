/*******************************************************************************
* File Name: ENCB.c  
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
#include "ENCB.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ENCB__PORT == 15 && ((ENCB__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ENCB_Write
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
void ENCB_Write(uint8 value) 
{
    uint8 staticBits = (ENCB_DR & (uint8)(~ENCB_MASK));
    ENCB_DR = staticBits | ((uint8)(value << ENCB_SHIFT) & ENCB_MASK);
}


/*******************************************************************************
* Function Name: ENCB_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ENCB_DM_STRONG     Strong Drive 
*  ENCB_DM_OD_HI      Open Drain, Drives High 
*  ENCB_DM_OD_LO      Open Drain, Drives Low 
*  ENCB_DM_RES_UP     Resistive Pull Up 
*  ENCB_DM_RES_DWN    Resistive Pull Down 
*  ENCB_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ENCB_DM_DIG_HIZ    High Impedance Digital 
*  ENCB_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ENCB_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ENCB_0, mode);
}


/*******************************************************************************
* Function Name: ENCB_Read
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
*  Macro ENCB_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ENCB_Read(void) 
{
    return (ENCB_PS & ENCB_MASK) >> ENCB_SHIFT;
}


/*******************************************************************************
* Function Name: ENCB_ReadDataReg
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
uint8 ENCB_ReadDataReg(void) 
{
    return (ENCB_DR & ENCB_MASK) >> ENCB_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ENCB_INTSTAT) 

    /*******************************************************************************
    * Function Name: ENCB_ClearInterrupt
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
    uint8 ENCB_ClearInterrupt(void) 
    {
        return (ENCB_INTSTAT & ENCB_MASK) >> ENCB_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
