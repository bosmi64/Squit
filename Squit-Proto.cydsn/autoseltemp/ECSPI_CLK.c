/*******************************************************************************
* File Name: ECSPI_CLK.c  
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
#include "ECSPI_CLK.h"


/*******************************************************************************
* Function Name: ECSPI_CLK_Write
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
void ECSPI_CLK_Write(uint8 value) 
{
    uint8 staticBits = ECSPI_CLK_DR & ~ECSPI_CLK_MASK;
    ECSPI_CLK_DR = staticBits | ((value << ECSPI_CLK_SHIFT) & ECSPI_CLK_MASK);
}


/*******************************************************************************
* Function Name: ECSPI_CLK_SetDriveMode
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
void ECSPI_CLK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ECSPI_CLK_0, mode);
}


/*******************************************************************************
* Function Name: ECSPI_CLK_Read
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
*  Macro ECSPI_CLK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ECSPI_CLK_Read(void) 
{
    return (ECSPI_CLK_PS & ECSPI_CLK_MASK) >> ECSPI_CLK_SHIFT;
}


/*******************************************************************************
* Function Name: ECSPI_CLK_ReadDataReg
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
uint8 ECSPI_CLK_ReadDataReg(void) 
{
    return (ECSPI_CLK_DR & ECSPI_CLK_MASK) >> ECSPI_CLK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ECSPI_CLK_INTSTAT) 

    /*******************************************************************************
    * Function Name: ECSPI_CLK_ClearInterrupt
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
    uint8 ECSPI_CLK_ClearInterrupt(void) 
    {
        return (ECSPI_CLK_INTSTAT & ECSPI_CLK_MASK) >> ECSPI_CLK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
