/*******************************************************************************
* File Name: nBUTTON_CCW.c  
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
#include "nBUTTON_CCW.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 nBUTTON_CCW__PORT == 15 && ((nBUTTON_CCW__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: nBUTTON_CCW_Write
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
void nBUTTON_CCW_Write(uint8 value) 
{
    uint8 staticBits = (nBUTTON_CCW_DR & (uint8)(~nBUTTON_CCW_MASK));
    nBUTTON_CCW_DR = staticBits | ((uint8)(value << nBUTTON_CCW_SHIFT) & nBUTTON_CCW_MASK);
}


/*******************************************************************************
* Function Name: nBUTTON_CCW_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  nBUTTON_CCW_DM_STRONG     Strong Drive 
*  nBUTTON_CCW_DM_OD_HI      Open Drain, Drives High 
*  nBUTTON_CCW_DM_OD_LO      Open Drain, Drives Low 
*  nBUTTON_CCW_DM_RES_UP     Resistive Pull Up 
*  nBUTTON_CCW_DM_RES_DWN    Resistive Pull Down 
*  nBUTTON_CCW_DM_RES_UPDWN  Resistive Pull Up/Down 
*  nBUTTON_CCW_DM_DIG_HIZ    High Impedance Digital 
*  nBUTTON_CCW_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void nBUTTON_CCW_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(nBUTTON_CCW_0, mode);
}


/*******************************************************************************
* Function Name: nBUTTON_CCW_Read
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
*  Macro nBUTTON_CCW_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 nBUTTON_CCW_Read(void) 
{
    return (nBUTTON_CCW_PS & nBUTTON_CCW_MASK) >> nBUTTON_CCW_SHIFT;
}


/*******************************************************************************
* Function Name: nBUTTON_CCW_ReadDataReg
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
uint8 nBUTTON_CCW_ReadDataReg(void) 
{
    return (nBUTTON_CCW_DR & nBUTTON_CCW_MASK) >> nBUTTON_CCW_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(nBUTTON_CCW_INTSTAT) 

    /*******************************************************************************
    * Function Name: nBUTTON_CCW_ClearInterrupt
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
    uint8 nBUTTON_CCW_ClearInterrupt(void) 
    {
        return (nBUTTON_CCW_INTSTAT & nBUTTON_CCW_MASK) >> nBUTTON_CCW_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
