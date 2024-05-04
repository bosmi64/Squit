/*******************************************************************************
* File Name: DUMMY.c  
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
#include "DUMMY.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 DUMMY__PORT == 15 && ((DUMMY__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: DUMMY_Write
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
void DUMMY_Write(uint8 value) 
{
    uint8 staticBits = (DUMMY_DR & (uint8)(~DUMMY_MASK));
    DUMMY_DR = staticBits | ((uint8)(value << DUMMY_SHIFT) & DUMMY_MASK);
}


/*******************************************************************************
* Function Name: DUMMY_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  DUMMY_DM_STRONG     Strong Drive 
*  DUMMY_DM_OD_HI      Open Drain, Drives High 
*  DUMMY_DM_OD_LO      Open Drain, Drives Low 
*  DUMMY_DM_RES_UP     Resistive Pull Up 
*  DUMMY_DM_RES_DWN    Resistive Pull Down 
*  DUMMY_DM_RES_UPDWN  Resistive Pull Up/Down 
*  DUMMY_DM_DIG_HIZ    High Impedance Digital 
*  DUMMY_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void DUMMY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DUMMY_0, mode);
}


/*******************************************************************************
* Function Name: DUMMY_Read
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
*  Macro DUMMY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DUMMY_Read(void) 
{
    return (DUMMY_PS & DUMMY_MASK) >> DUMMY_SHIFT;
}


/*******************************************************************************
* Function Name: DUMMY_ReadDataReg
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
uint8 DUMMY_ReadDataReg(void) 
{
    return (DUMMY_DR & DUMMY_MASK) >> DUMMY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DUMMY_INTSTAT) 

    /*******************************************************************************
    * Function Name: DUMMY_ClearInterrupt
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
    uint8 DUMMY_ClearInterrupt(void) 
    {
        return (DUMMY_INTSTAT & DUMMY_MASK) >> DUMMY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
