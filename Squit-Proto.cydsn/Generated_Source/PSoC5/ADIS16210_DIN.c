/*******************************************************************************
* File Name: ADIS16210_DIN.c  
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
#include "ADIS16210_DIN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADIS16210_DIN__PORT == 15 && ((ADIS16210_DIN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADIS16210_DIN_Write
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
void ADIS16210_DIN_Write(uint8 value) 
{
    uint8 staticBits = (ADIS16210_DIN_DR & (uint8)(~ADIS16210_DIN_MASK));
    ADIS16210_DIN_DR = staticBits | ((uint8)(value << ADIS16210_DIN_SHIFT) & ADIS16210_DIN_MASK);
}


/*******************************************************************************
* Function Name: ADIS16210_DIN_SetDriveMode
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
void ADIS16210_DIN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADIS16210_DIN_0, mode);
}


/*******************************************************************************
* Function Name: ADIS16210_DIN_Read
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
*  Macro ADIS16210_DIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADIS16210_DIN_Read(void) 
{
    return (ADIS16210_DIN_PS & ADIS16210_DIN_MASK) >> ADIS16210_DIN_SHIFT;
}


/*******************************************************************************
* Function Name: ADIS16210_DIN_ReadDataReg
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
uint8 ADIS16210_DIN_ReadDataReg(void) 
{
    return (ADIS16210_DIN_DR & ADIS16210_DIN_MASK) >> ADIS16210_DIN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADIS16210_DIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADIS16210_DIN_ClearInterrupt
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
    uint8 ADIS16210_DIN_ClearInterrupt(void) 
    {
        return (ADIS16210_DIN_INTSTAT & ADIS16210_DIN_MASK) >> ADIS16210_DIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
