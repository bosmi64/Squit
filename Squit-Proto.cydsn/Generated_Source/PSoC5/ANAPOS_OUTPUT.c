/*******************************************************************************
* File Name: ANAPOS_OUTPUT.c  
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
#include "ANAPOS_OUTPUT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ANAPOS_OUTPUT__PORT == 15 && ((ANAPOS_OUTPUT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ANAPOS_OUTPUT_Write
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
void ANAPOS_OUTPUT_Write(uint8 value) 
{
    uint8 staticBits = (ANAPOS_OUTPUT_DR & (uint8)(~ANAPOS_OUTPUT_MASK));
    ANAPOS_OUTPUT_DR = staticBits | ((uint8)(value << ANAPOS_OUTPUT_SHIFT) & ANAPOS_OUTPUT_MASK);
}


/*******************************************************************************
* Function Name: ANAPOS_OUTPUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ANAPOS_OUTPUT_DM_STRONG     Strong Drive 
*  ANAPOS_OUTPUT_DM_OD_HI      Open Drain, Drives High 
*  ANAPOS_OUTPUT_DM_OD_LO      Open Drain, Drives Low 
*  ANAPOS_OUTPUT_DM_RES_UP     Resistive Pull Up 
*  ANAPOS_OUTPUT_DM_RES_DWN    Resistive Pull Down 
*  ANAPOS_OUTPUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ANAPOS_OUTPUT_DM_DIG_HIZ    High Impedance Digital 
*  ANAPOS_OUTPUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ANAPOS_OUTPUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ANAPOS_OUTPUT_0, mode);
}


/*******************************************************************************
* Function Name: ANAPOS_OUTPUT_Read
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
*  Macro ANAPOS_OUTPUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ANAPOS_OUTPUT_Read(void) 
{
    return (ANAPOS_OUTPUT_PS & ANAPOS_OUTPUT_MASK) >> ANAPOS_OUTPUT_SHIFT;
}


/*******************************************************************************
* Function Name: ANAPOS_OUTPUT_ReadDataReg
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
uint8 ANAPOS_OUTPUT_ReadDataReg(void) 
{
    return (ANAPOS_OUTPUT_DR & ANAPOS_OUTPUT_MASK) >> ANAPOS_OUTPUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ANAPOS_OUTPUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: ANAPOS_OUTPUT_ClearInterrupt
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
    uint8 ANAPOS_OUTPUT_ClearInterrupt(void) 
    {
        return (ANAPOS_OUTPUT_INTSTAT & ANAPOS_OUTPUT_MASK) >> ANAPOS_OUTPUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
