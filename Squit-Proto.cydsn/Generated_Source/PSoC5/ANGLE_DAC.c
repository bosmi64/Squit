/*******************************************************************************
* File Name: ANGLE_DAC.c  
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
#include "ANGLE_DAC.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ANGLE_DAC__PORT == 15 && ((ANGLE_DAC__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ANGLE_DAC_Write
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
void ANGLE_DAC_Write(uint8 value) 
{
    uint8 staticBits = (ANGLE_DAC_DR & (uint8)(~ANGLE_DAC_MASK));
    ANGLE_DAC_DR = staticBits | ((uint8)(value << ANGLE_DAC_SHIFT) & ANGLE_DAC_MASK);
}


/*******************************************************************************
* Function Name: ANGLE_DAC_SetDriveMode
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
void ANGLE_DAC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ANGLE_DAC_0, mode);
}


/*******************************************************************************
* Function Name: ANGLE_DAC_Read
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
*  Macro ANGLE_DAC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ANGLE_DAC_Read(void) 
{
    return (ANGLE_DAC_PS & ANGLE_DAC_MASK) >> ANGLE_DAC_SHIFT;
}


/*******************************************************************************
* Function Name: ANGLE_DAC_ReadDataReg
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
uint8 ANGLE_DAC_ReadDataReg(void) 
{
    return (ANGLE_DAC_DR & ANGLE_DAC_MASK) >> ANGLE_DAC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ANGLE_DAC_INTSTAT) 

    /*******************************************************************************
    * Function Name: ANGLE_DAC_ClearInterrupt
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
    uint8 ANGLE_DAC_ClearInterrupt(void) 
    {
        return (ANGLE_DAC_INTSTAT & ANGLE_DAC_MASK) >> ANGLE_DAC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
