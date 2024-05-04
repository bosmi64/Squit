/*******************************************************************************
* File Name: LED_WIFI_OK.c  
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
#include "LED_WIFI_OK.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LED_WIFI_OK__PORT == 15 && ((LED_WIFI_OK__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LED_WIFI_OK_Write
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
void LED_WIFI_OK_Write(uint8 value) 
{
    uint8 staticBits = (LED_WIFI_OK_DR & (uint8)(~LED_WIFI_OK_MASK));
    LED_WIFI_OK_DR = staticBits | ((uint8)(value << LED_WIFI_OK_SHIFT) & LED_WIFI_OK_MASK);
}


/*******************************************************************************
* Function Name: LED_WIFI_OK_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LED_WIFI_OK_DM_STRONG     Strong Drive 
*  LED_WIFI_OK_DM_OD_HI      Open Drain, Drives High 
*  LED_WIFI_OK_DM_OD_LO      Open Drain, Drives Low 
*  LED_WIFI_OK_DM_RES_UP     Resistive Pull Up 
*  LED_WIFI_OK_DM_RES_DWN    Resistive Pull Down 
*  LED_WIFI_OK_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LED_WIFI_OK_DM_DIG_HIZ    High Impedance Digital 
*  LED_WIFI_OK_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LED_WIFI_OK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LED_WIFI_OK_0, mode);
}


/*******************************************************************************
* Function Name: LED_WIFI_OK_Read
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
*  Macro LED_WIFI_OK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LED_WIFI_OK_Read(void) 
{
    return (LED_WIFI_OK_PS & LED_WIFI_OK_MASK) >> LED_WIFI_OK_SHIFT;
}


/*******************************************************************************
* Function Name: LED_WIFI_OK_ReadDataReg
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
uint8 LED_WIFI_OK_ReadDataReg(void) 
{
    return (LED_WIFI_OK_DR & LED_WIFI_OK_MASK) >> LED_WIFI_OK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LED_WIFI_OK_INTSTAT) 

    /*******************************************************************************
    * Function Name: LED_WIFI_OK_ClearInterrupt
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
    uint8 LED_WIFI_OK_ClearInterrupt(void) 
    {
        return (LED_WIFI_OK_INTSTAT & LED_WIFI_OK_MASK) >> LED_WIFI_OK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
