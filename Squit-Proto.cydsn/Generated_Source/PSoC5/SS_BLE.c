/*******************************************************************************
* File Name: SS_BLE.c  
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
#include "SS_BLE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SS_BLE__PORT == 15 && ((SS_BLE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SS_BLE_Write
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
void SS_BLE_Write(uint8 value) 
{
    uint8 staticBits = (SS_BLE_DR & (uint8)(~SS_BLE_MASK));
    SS_BLE_DR = staticBits | ((uint8)(value << SS_BLE_SHIFT) & SS_BLE_MASK);
}


/*******************************************************************************
* Function Name: SS_BLE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SS_BLE_DM_STRONG     Strong Drive 
*  SS_BLE_DM_OD_HI      Open Drain, Drives High 
*  SS_BLE_DM_OD_LO      Open Drain, Drives Low 
*  SS_BLE_DM_RES_UP     Resistive Pull Up 
*  SS_BLE_DM_RES_DWN    Resistive Pull Down 
*  SS_BLE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SS_BLE_DM_DIG_HIZ    High Impedance Digital 
*  SS_BLE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SS_BLE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SS_BLE_0, mode);
}


/*******************************************************************************
* Function Name: SS_BLE_Read
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
*  Macro SS_BLE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SS_BLE_Read(void) 
{
    return (SS_BLE_PS & SS_BLE_MASK) >> SS_BLE_SHIFT;
}


/*******************************************************************************
* Function Name: SS_BLE_ReadDataReg
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
uint8 SS_BLE_ReadDataReg(void) 
{
    return (SS_BLE_DR & SS_BLE_MASK) >> SS_BLE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SS_BLE_INTSTAT) 

    /*******************************************************************************
    * Function Name: SS_BLE_ClearInterrupt
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
    uint8 SS_BLE_ClearInterrupt(void) 
    {
        return (SS_BLE_INTSTAT & SS_BLE_MASK) >> SS_BLE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
