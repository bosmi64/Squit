/*******************************************************************************
* File Name: ADXRS_MOSI.c  
* Version 1.60
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "ADXRS_MOSI.h"


/*******************************************************************************
* Function Name: ADXRS_MOSI_Write
********************************************************************************
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  void 
*  
*******************************************************************************/
void ADXRS_MOSI_Write(uint8 value) 
{
    uint8 staticBits = ADXRS_MOSI_DR & ~ADXRS_MOSI_MASK;
    ADXRS_MOSI_DR = staticBits | ((value << ADXRS_MOSI_SHIFT) & ADXRS_MOSI_MASK);
}


/*******************************************************************************
* Function Name: ADXRS_MOSI_SetDriveMode
********************************************************************************
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  void
*
*******************************************************************************/
void ADXRS_MOSI_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADXRS_MOSI_0, mode);
}


/*******************************************************************************
* Function Name: ADXRS_MOSI_Read
********************************************************************************
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ADXRS_MOSI_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADXRS_MOSI_Read(void) 
{
    return (ADXRS_MOSI_PS & ADXRS_MOSI_MASK) >> ADXRS_MOSI_SHIFT;
}


/*******************************************************************************
* Function Name: ADXRS_MOSI_ReadDataReg
********************************************************************************
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  void 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ADXRS_MOSI_ReadDataReg(void) 
{
    return (ADXRS_MOSI_DR & ADXRS_MOSI_MASK) >> ADXRS_MOSI_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADXRS_MOSI_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADXRS_MOSI_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  void 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ADXRS_MOSI_ClearInterrupt(void) 
    {
        return (ADXRS_MOSI_INTSTAT & ADXRS_MOSI_MASK) >> ADXRS_MOSI_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
