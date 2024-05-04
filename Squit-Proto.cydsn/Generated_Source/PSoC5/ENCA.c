/*******************************************************************************
* File Name: ENCA.c  
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
#include "ENCA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ENCA__PORT == 15 && ((ENCA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ENCA_Write
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
void ENCA_Write(uint8 value) 
{
    uint8 staticBits = (ENCA_DR & (uint8)(~ENCA_MASK));
    ENCA_DR = staticBits | ((uint8)(value << ENCA_SHIFT) & ENCA_MASK);
}


/*******************************************************************************
* Function Name: ENCA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ENCA_DM_STRONG     Strong Drive 
*  ENCA_DM_OD_HI      Open Drain, Drives High 
*  ENCA_DM_OD_LO      Open Drain, Drives Low 
*  ENCA_DM_RES_UP     Resistive Pull Up 
*  ENCA_DM_RES_DWN    Resistive Pull Down 
*  ENCA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ENCA_DM_DIG_HIZ    High Impedance Digital 
*  ENCA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ENCA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ENCA_0, mode);
}


/*******************************************************************************
* Function Name: ENCA_Read
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
*  Macro ENCA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ENCA_Read(void) 
{
    return (ENCA_PS & ENCA_MASK) >> ENCA_SHIFT;
}


/*******************************************************************************
* Function Name: ENCA_ReadDataReg
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
uint8 ENCA_ReadDataReg(void) 
{
    return (ENCA_DR & ENCA_MASK) >> ENCA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ENCA_INTSTAT) 

    /*******************************************************************************
    * Function Name: ENCA_ClearInterrupt
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
    uint8 ENCA_ClearInterrupt(void) 
    {
        return (ENCA_INTSTAT & ENCA_MASK) >> ENCA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
