/*******************************************************************************
* File Name: MISO_WIFI.c  
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
#include "MISO_WIFI.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MISO_WIFI__PORT == 15 && ((MISO_WIFI__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MISO_WIFI_Write
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
void MISO_WIFI_Write(uint8 value) 
{
    uint8 staticBits = (MISO_WIFI_DR & (uint8)(~MISO_WIFI_MASK));
    MISO_WIFI_DR = staticBits | ((uint8)(value << MISO_WIFI_SHIFT) & MISO_WIFI_MASK);
}


/*******************************************************************************
* Function Name: MISO_WIFI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MISO_WIFI_DM_STRONG     Strong Drive 
*  MISO_WIFI_DM_OD_HI      Open Drain, Drives High 
*  MISO_WIFI_DM_OD_LO      Open Drain, Drives Low 
*  MISO_WIFI_DM_RES_UP     Resistive Pull Up 
*  MISO_WIFI_DM_RES_DWN    Resistive Pull Down 
*  MISO_WIFI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MISO_WIFI_DM_DIG_HIZ    High Impedance Digital 
*  MISO_WIFI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MISO_WIFI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MISO_WIFI_0, mode);
}


/*******************************************************************************
* Function Name: MISO_WIFI_Read
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
*  Macro MISO_WIFI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MISO_WIFI_Read(void) 
{
    return (MISO_WIFI_PS & MISO_WIFI_MASK) >> MISO_WIFI_SHIFT;
}


/*******************************************************************************
* Function Name: MISO_WIFI_ReadDataReg
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
uint8 MISO_WIFI_ReadDataReg(void) 
{
    return (MISO_WIFI_DR & MISO_WIFI_MASK) >> MISO_WIFI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MISO_WIFI_INTSTAT) 

    /*******************************************************************************
    * Function Name: MISO_WIFI_ClearInterrupt
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
    uint8 MISO_WIFI_ClearInterrupt(void) 
    {
        return (MISO_WIFI_INTSTAT & MISO_WIFI_MASK) >> MISO_WIFI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
