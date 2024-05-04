/*******************************************************************************
* File Name: THERMO_EN.c  
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
#include "THERMO_EN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 THERMO_EN__PORT == 15 && ((THERMO_EN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: THERMO_EN_Write
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
void THERMO_EN_Write(uint8 value) 
{
    uint8 staticBits = (THERMO_EN_DR & (uint8)(~THERMO_EN_MASK));
    THERMO_EN_DR = staticBits | ((uint8)(value << THERMO_EN_SHIFT) & THERMO_EN_MASK);
}


/*******************************************************************************
* Function Name: THERMO_EN_SetDriveMode
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
void THERMO_EN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(THERMO_EN_0, mode);
}


/*******************************************************************************
* Function Name: THERMO_EN_Read
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
*  Macro THERMO_EN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 THERMO_EN_Read(void) 
{
    return (THERMO_EN_PS & THERMO_EN_MASK) >> THERMO_EN_SHIFT;
}


/*******************************************************************************
* Function Name: THERMO_EN_ReadDataReg
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
uint8 THERMO_EN_ReadDataReg(void) 
{
    return (THERMO_EN_DR & THERMO_EN_MASK) >> THERMO_EN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(THERMO_EN_INTSTAT) 

    /*******************************************************************************
    * Function Name: THERMO_EN_ClearInterrupt
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
    uint8 THERMO_EN_ClearInterrupt(void) 
    {
        return (THERMO_EN_INTSTAT & THERMO_EN_MASK) >> THERMO_EN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
