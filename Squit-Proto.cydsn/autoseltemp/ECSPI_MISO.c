/*******************************************************************************
* File Name: ECSPI_MISO.c  
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
#include "ECSPI_MISO.h"


/*******************************************************************************
* Function Name: ECSPI_MISO_Write
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
void ECSPI_MISO_Write(uint8 value) 
{
    uint8 staticBits = ECSPI_MISO_DR & ~ECSPI_MISO_MASK;
    ECSPI_MISO_DR = staticBits | ((value << ECSPI_MISO_SHIFT) & ECSPI_MISO_MASK);
}


/*******************************************************************************
* Function Name: ECSPI_MISO_SetDriveMode
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
void ECSPI_MISO_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ECSPI_MISO_0, mode);
}


/*******************************************************************************
* Function Name: ECSPI_MISO_Read
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
*  Macro ECSPI_MISO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ECSPI_MISO_Read(void) 
{
    return (ECSPI_MISO_PS & ECSPI_MISO_MASK) >> ECSPI_MISO_SHIFT;
}


/*******************************************************************************
* Function Name: ECSPI_MISO_ReadDataReg
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
uint8 ECSPI_MISO_ReadDataReg(void) 
{
    return (ECSPI_MISO_DR & ECSPI_MISO_MASK) >> ECSPI_MISO_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ECSPI_MISO_INTSTAT) 

    /*******************************************************************************
    * Function Name: ECSPI_MISO_ClearInterrupt
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
    uint8 ECSPI_MISO_ClearInterrupt(void) 
    {
        return (ECSPI_MISO_INTSTAT & ECSPI_MISO_MASK) >> ECSPI_MISO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
