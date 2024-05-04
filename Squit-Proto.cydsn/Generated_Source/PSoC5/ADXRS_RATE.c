/*******************************************************************************
* File Name: ADXRS_RATE.c  
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
#include "ADXRS_RATE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADXRS_RATE__PORT == 15 && ((ADXRS_RATE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADXRS_RATE_Write
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
void ADXRS_RATE_Write(uint8 value) 
{
    uint8 staticBits = (ADXRS_RATE_DR & (uint8)(~ADXRS_RATE_MASK));
    ADXRS_RATE_DR = staticBits | ((uint8)(value << ADXRS_RATE_SHIFT) & ADXRS_RATE_MASK);
}


/*******************************************************************************
* Function Name: ADXRS_RATE_SetDriveMode
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
void ADXRS_RATE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADXRS_RATE_0, mode);
}


/*******************************************************************************
* Function Name: ADXRS_RATE_Read
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
*  Macro ADXRS_RATE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADXRS_RATE_Read(void) 
{
    return (ADXRS_RATE_PS & ADXRS_RATE_MASK) >> ADXRS_RATE_SHIFT;
}


/*******************************************************************************
* Function Name: ADXRS_RATE_ReadDataReg
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
uint8 ADXRS_RATE_ReadDataReg(void) 
{
    return (ADXRS_RATE_DR & ADXRS_RATE_MASK) >> ADXRS_RATE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADXRS_RATE_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADXRS_RATE_ClearInterrupt
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
    uint8 ADXRS_RATE_ClearInterrupt(void) 
    {
        return (ADXRS_RATE_INTSTAT & ADXRS_RATE_MASK) >> ADXRS_RATE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
