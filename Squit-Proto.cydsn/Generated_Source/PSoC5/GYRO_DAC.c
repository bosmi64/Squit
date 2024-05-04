/*******************************************************************************
* File Name: GYRO_DAC.c  
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
#include "GYRO_DAC.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 GYRO_DAC__PORT == 15 && ((GYRO_DAC__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: GYRO_DAC_Write
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
void GYRO_DAC_Write(uint8 value) 
{
    uint8 staticBits = (GYRO_DAC_DR & (uint8)(~GYRO_DAC_MASK));
    GYRO_DAC_DR = staticBits | ((uint8)(value << GYRO_DAC_SHIFT) & GYRO_DAC_MASK);
}


/*******************************************************************************
* Function Name: GYRO_DAC_SetDriveMode
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
void GYRO_DAC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(GYRO_DAC_0, mode);
}


/*******************************************************************************
* Function Name: GYRO_DAC_Read
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
*  Macro GYRO_DAC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 GYRO_DAC_Read(void) 
{
    return (GYRO_DAC_PS & GYRO_DAC_MASK) >> GYRO_DAC_SHIFT;
}


/*******************************************************************************
* Function Name: GYRO_DAC_ReadDataReg
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
uint8 GYRO_DAC_ReadDataReg(void) 
{
    return (GYRO_DAC_DR & GYRO_DAC_MASK) >> GYRO_DAC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(GYRO_DAC_INTSTAT) 

    /*******************************************************************************
    * Function Name: GYRO_DAC_ClearInterrupt
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
    uint8 GYRO_DAC_ClearInterrupt(void) 
    {
        return (GYRO_DAC_INTSTAT & GYRO_DAC_MASK) >> GYRO_DAC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
