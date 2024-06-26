/*******************************************************************************
* File Name: MOTOR_FL.c  
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
#include "MOTOR_FL.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MOTOR_FL__PORT == 15 && ((MOTOR_FL__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MOTOR_FL_Write
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
void MOTOR_FL_Write(uint8 value) 
{
    uint8 staticBits = (MOTOR_FL_DR & (uint8)(~MOTOR_FL_MASK));
    MOTOR_FL_DR = staticBits | ((uint8)(value << MOTOR_FL_SHIFT) & MOTOR_FL_MASK);
}


/*******************************************************************************
* Function Name: MOTOR_FL_SetDriveMode
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
void MOTOR_FL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MOTOR_FL_0, mode);
}


/*******************************************************************************
* Function Name: MOTOR_FL_Read
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
*  Macro MOTOR_FL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MOTOR_FL_Read(void) 
{
    return (MOTOR_FL_PS & MOTOR_FL_MASK) >> MOTOR_FL_SHIFT;
}


/*******************************************************************************
* Function Name: MOTOR_FL_ReadDataReg
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
uint8 MOTOR_FL_ReadDataReg(void) 
{
    return (MOTOR_FL_DR & MOTOR_FL_MASK) >> MOTOR_FL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MOTOR_FL_INTSTAT) 

    /*******************************************************************************
    * Function Name: MOTOR_FL_ClearInterrupt
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
    uint8 MOTOR_FL_ClearInterrupt(void) 
    {
        return (MOTOR_FL_INTSTAT & MOTOR_FL_MASK) >> MOTOR_FL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
