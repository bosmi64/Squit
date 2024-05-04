/*******************************************************************************
* File Name: ITG_SCL_SCLK.c  
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
#include "ITG_SCL_SCLK.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ITG_SCL_SCLK__PORT == 15 && ((ITG_SCL_SCLK__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ITG_SCL_SCLK_Write
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
void ITG_SCL_SCLK_Write(uint8 value) 
{
    uint8 staticBits = (ITG_SCL_SCLK_DR & (uint8)(~ITG_SCL_SCLK_MASK));
    ITG_SCL_SCLK_DR = staticBits | ((uint8)(value << ITG_SCL_SCLK_SHIFT) & ITG_SCL_SCLK_MASK);
}


/*******************************************************************************
* Function Name: ITG_SCL_SCLK_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ITG_SCL_SCLK_DM_STRONG     Strong Drive 
*  ITG_SCL_SCLK_DM_OD_HI      Open Drain, Drives High 
*  ITG_SCL_SCLK_DM_OD_LO      Open Drain, Drives Low 
*  ITG_SCL_SCLK_DM_RES_UP     Resistive Pull Up 
*  ITG_SCL_SCLK_DM_RES_DWN    Resistive Pull Down 
*  ITG_SCL_SCLK_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ITG_SCL_SCLK_DM_DIG_HIZ    High Impedance Digital 
*  ITG_SCL_SCLK_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ITG_SCL_SCLK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ITG_SCL_SCLK_0, mode);
}


/*******************************************************************************
* Function Name: ITG_SCL_SCLK_Read
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
*  Macro ITG_SCL_SCLK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ITG_SCL_SCLK_Read(void) 
{
    return (ITG_SCL_SCLK_PS & ITG_SCL_SCLK_MASK) >> ITG_SCL_SCLK_SHIFT;
}


/*******************************************************************************
* Function Name: ITG_SCL_SCLK_ReadDataReg
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
uint8 ITG_SCL_SCLK_ReadDataReg(void) 
{
    return (ITG_SCL_SCLK_DR & ITG_SCL_SCLK_MASK) >> ITG_SCL_SCLK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ITG_SCL_SCLK_INTSTAT) 

    /*******************************************************************************
    * Function Name: ITG_SCL_SCLK_ClearInterrupt
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
    uint8 ITG_SCL_SCLK_ClearInterrupt(void) 
    {
        return (ITG_SCL_SCLK_INTSTAT & ITG_SCL_SCLK_MASK) >> ITG_SCL_SCLK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
