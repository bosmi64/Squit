/*******************************************************************************
* File Name: UM6_RX.c  
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
#include "UM6_RX.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UM6_RX__PORT == 15 && ((UM6_RX__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UM6_RX_Write
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
void UM6_RX_Write(uint8 value) 
{
    uint8 staticBits = (UM6_RX_DR & (uint8)(~UM6_RX_MASK));
    UM6_RX_DR = staticBits | ((uint8)(value << UM6_RX_SHIFT) & UM6_RX_MASK);
}


/*******************************************************************************
* Function Name: UM6_RX_SetDriveMode
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
void UM6_RX_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UM6_RX_0, mode);
}


/*******************************************************************************
* Function Name: UM6_RX_Read
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
*  Macro UM6_RX_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UM6_RX_Read(void) 
{
    return (UM6_RX_PS & UM6_RX_MASK) >> UM6_RX_SHIFT;
}


/*******************************************************************************
* Function Name: UM6_RX_ReadDataReg
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
uint8 UM6_RX_ReadDataReg(void) 
{
    return (UM6_RX_DR & UM6_RX_MASK) >> UM6_RX_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UM6_RX_INTSTAT) 

    /*******************************************************************************
    * Function Name: UM6_RX_ClearInterrupt
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
    uint8 UM6_RX_ClearInterrupt(void) 
    {
        return (UM6_RX_INTSTAT & UM6_RX_MASK) >> UM6_RX_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
