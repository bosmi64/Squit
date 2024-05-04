/*******************************************************************************
* File Name: WAKE_WIFI.c  
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
#include "WAKE_WIFI.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 WAKE_WIFI__PORT == 15 && ((WAKE_WIFI__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: WAKE_WIFI_Write
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
void WAKE_WIFI_Write(uint8 value) 
{
    uint8 staticBits = (WAKE_WIFI_DR & (uint8)(~WAKE_WIFI_MASK));
    WAKE_WIFI_DR = staticBits | ((uint8)(value << WAKE_WIFI_SHIFT) & WAKE_WIFI_MASK);
}


/*******************************************************************************
* Function Name: WAKE_WIFI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WAKE_WIFI_DM_STRONG     Strong Drive 
*  WAKE_WIFI_DM_OD_HI      Open Drain, Drives High 
*  WAKE_WIFI_DM_OD_LO      Open Drain, Drives Low 
*  WAKE_WIFI_DM_RES_UP     Resistive Pull Up 
*  WAKE_WIFI_DM_RES_DWN    Resistive Pull Down 
*  WAKE_WIFI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WAKE_WIFI_DM_DIG_HIZ    High Impedance Digital 
*  WAKE_WIFI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WAKE_WIFI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(WAKE_WIFI_0, mode);
}


/*******************************************************************************
* Function Name: WAKE_WIFI_Read
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
*  Macro WAKE_WIFI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WAKE_WIFI_Read(void) 
{
    return (WAKE_WIFI_PS & WAKE_WIFI_MASK) >> WAKE_WIFI_SHIFT;
}


/*******************************************************************************
* Function Name: WAKE_WIFI_ReadDataReg
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
uint8 WAKE_WIFI_ReadDataReg(void) 
{
    return (WAKE_WIFI_DR & WAKE_WIFI_MASK) >> WAKE_WIFI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WAKE_WIFI_INTSTAT) 

    /*******************************************************************************
    * Function Name: WAKE_WIFI_ClearInterrupt
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
    uint8 WAKE_WIFI_ClearInterrupt(void) 
    {
        return (WAKE_WIFI_INTSTAT & WAKE_WIFI_MASK) >> WAKE_WIFI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
