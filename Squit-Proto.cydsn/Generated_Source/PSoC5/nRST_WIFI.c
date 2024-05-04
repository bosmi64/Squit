/*******************************************************************************
* File Name: nRST_WIFI.c  
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
#include "nRST_WIFI.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 nRST_WIFI__PORT == 15 && ((nRST_WIFI__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: nRST_WIFI_Write
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
void nRST_WIFI_Write(uint8 value) 
{
    uint8 staticBits = (nRST_WIFI_DR & (uint8)(~nRST_WIFI_MASK));
    nRST_WIFI_DR = staticBits | ((uint8)(value << nRST_WIFI_SHIFT) & nRST_WIFI_MASK);
}


/*******************************************************************************
* Function Name: nRST_WIFI_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  nRST_WIFI_DM_STRONG     Strong Drive 
*  nRST_WIFI_DM_OD_HI      Open Drain, Drives High 
*  nRST_WIFI_DM_OD_LO      Open Drain, Drives Low 
*  nRST_WIFI_DM_RES_UP     Resistive Pull Up 
*  nRST_WIFI_DM_RES_DWN    Resistive Pull Down 
*  nRST_WIFI_DM_RES_UPDWN  Resistive Pull Up/Down 
*  nRST_WIFI_DM_DIG_HIZ    High Impedance Digital 
*  nRST_WIFI_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void nRST_WIFI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(nRST_WIFI_0, mode);
}


/*******************************************************************************
* Function Name: nRST_WIFI_Read
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
*  Macro nRST_WIFI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 nRST_WIFI_Read(void) 
{
    return (nRST_WIFI_PS & nRST_WIFI_MASK) >> nRST_WIFI_SHIFT;
}


/*******************************************************************************
* Function Name: nRST_WIFI_ReadDataReg
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
uint8 nRST_WIFI_ReadDataReg(void) 
{
    return (nRST_WIFI_DR & nRST_WIFI_MASK) >> nRST_WIFI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(nRST_WIFI_INTSTAT) 

    /*******************************************************************************
    * Function Name: nRST_WIFI_ClearInterrupt
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
    uint8 nRST_WIFI_ClearInterrupt(void) 
    {
        return (nRST_WIFI_INTSTAT & nRST_WIFI_MASK) >> nRST_WIFI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
