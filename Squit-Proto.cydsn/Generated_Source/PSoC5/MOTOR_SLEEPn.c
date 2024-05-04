/*******************************************************************************
* File Name: MOTOR_SLEEPn.c  
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
#include "MOTOR_SLEEPn.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MOTOR_SLEEPn__PORT == 15 && ((MOTOR_SLEEPn__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MOTOR_SLEEPn_Write
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
void MOTOR_SLEEPn_Write(uint8 value) 
{
    uint8 staticBits = (MOTOR_SLEEPn_DR & (uint8)(~MOTOR_SLEEPn_MASK));
    MOTOR_SLEEPn_DR = staticBits | ((uint8)(value << MOTOR_SLEEPn_SHIFT) & MOTOR_SLEEPn_MASK);
}


/*******************************************************************************
* Function Name: MOTOR_SLEEPn_SetDriveMode
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
void MOTOR_SLEEPn_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MOTOR_SLEEPn_0, mode);
}


/*******************************************************************************
* Function Name: MOTOR_SLEEPn_Read
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
*  Macro MOTOR_SLEEPn_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MOTOR_SLEEPn_Read(void) 
{
    return (MOTOR_SLEEPn_PS & MOTOR_SLEEPn_MASK) >> MOTOR_SLEEPn_SHIFT;
}


/*******************************************************************************
* Function Name: MOTOR_SLEEPn_ReadDataReg
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
uint8 MOTOR_SLEEPn_ReadDataReg(void) 
{
    return (MOTOR_SLEEPn_DR & MOTOR_SLEEPn_MASK) >> MOTOR_SLEEPn_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MOTOR_SLEEPn_INTSTAT) 

    /*******************************************************************************
    * Function Name: MOTOR_SLEEPn_ClearInterrupt
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
    uint8 MOTOR_SLEEPn_ClearInterrupt(void) 
    {
        return (MOTOR_SLEEPn_INTSTAT & MOTOR_SLEEPn_MASK) >> MOTOR_SLEEPn_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
