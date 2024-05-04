/*******************************************************************************
* File Name: CC_SDA.c  
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
#include "CC_SDA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CC_SDA__PORT == 15 && ((CC_SDA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CC_SDA_Write
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
void CC_SDA_Write(uint8 value) 
{
    uint8 staticBits = (CC_SDA_DR & (uint8)(~CC_SDA_MASK));
    CC_SDA_DR = staticBits | ((uint8)(value << CC_SDA_SHIFT) & CC_SDA_MASK);
}


/*******************************************************************************
* Function Name: CC_SDA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CC_SDA_DM_STRONG     Strong Drive 
*  CC_SDA_DM_OD_HI      Open Drain, Drives High 
*  CC_SDA_DM_OD_LO      Open Drain, Drives Low 
*  CC_SDA_DM_RES_UP     Resistive Pull Up 
*  CC_SDA_DM_RES_DWN    Resistive Pull Down 
*  CC_SDA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CC_SDA_DM_DIG_HIZ    High Impedance Digital 
*  CC_SDA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CC_SDA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CC_SDA_0, mode);
}


/*******************************************************************************
* Function Name: CC_SDA_Read
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
*  Macro CC_SDA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CC_SDA_Read(void) 
{
    return (CC_SDA_PS & CC_SDA_MASK) >> CC_SDA_SHIFT;
}


/*******************************************************************************
* Function Name: CC_SDA_ReadDataReg
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
uint8 CC_SDA_ReadDataReg(void) 
{
    return (CC_SDA_DR & CC_SDA_MASK) >> CC_SDA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CC_SDA_INTSTAT) 

    /*******************************************************************************
    * Function Name: CC_SDA_ClearInterrupt
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
    uint8 CC_SDA_ClearInterrupt(void) 
    {
        return (CC_SDA_INTSTAT & CC_SDA_MASK) >> CC_SDA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
