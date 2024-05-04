/*******************************************************************************
* File Name: SCLK_WIFI.c  
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
#include "SCLK_WIFI.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SCLK_WIFI__PORT == 15 && ((SCLK_WIFI__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SCLK_WIFI_Write
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
void SCLK_WIFI_Write(uint8 value) 
{
    uint8 staticBits = (SCLK_WIFI_DR & (uint8)(~SCLK_WIFI_MASK));
    SCLK_WIFI_DR = staticBits | ((uint8)(value << SCLK_WIFI_SHIFT) & SCLK_WIFI_MASK);
}


/*******************************************************************************
* Function Name: SCLK_WIFI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SCLK_WIFI_DM_STRONG     Strong Drive 
*  SCLK_WIFI_DM_OD_HI      Open Drain, Drives High 
*  SCLK_WIFI_DM_OD_LO      Open Drain, Drives Low 
*  SCLK_WIFI_DM_RES_UP     Resistive Pull Up 
*  SCLK_WIFI_DM_RES_DWN    Resistive Pull Down 
*  SCLK_WIFI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SCLK_WIFI_DM_DIG_HIZ    High Impedance Digital 
*  SCLK_WIFI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SCLK_WIFI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SCLK_WIFI_0, mode);
}


/*******************************************************************************
* Function Name: SCLK_WIFI_Read
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
*  Macro SCLK_WIFI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SCLK_WIFI_Read(void) 
{
    return (SCLK_WIFI_PS & SCLK_WIFI_MASK) >> SCLK_WIFI_SHIFT;
}


/*******************************************************************************
* Function Name: SCLK_WIFI_ReadDataReg
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
uint8 SCLK_WIFI_ReadDataReg(void) 
{
    return (SCLK_WIFI_DR & SCLK_WIFI_MASK) >> SCLK_WIFI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SCLK_WIFI_INTSTAT) 

    /*******************************************************************************
    * Function Name: SCLK_WIFI_ClearInterrupt
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
    uint8 SCLK_WIFI_ClearInterrupt(void) 
    {
        return (SCLK_WIFI_INTSTAT & SCLK_WIFI_MASK) >> SCLK_WIFI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
