/*******************************************************************************
* File Name: ECSPI_CS.c  
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
#include "ECSPI_CS.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ECSPI_CS__PORT == 15 && ((ECSPI_CS__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ECSPI_CS_Write
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
void ECSPI_CS_Write(uint8 value) 
{
    uint8 staticBits = (ECSPI_CS_DR & (uint8)(~ECSPI_CS_MASK));
    ECSPI_CS_DR = staticBits | ((uint8)(value << ECSPI_CS_SHIFT) & ECSPI_CS_MASK);
}


/*******************************************************************************
* Function Name: ECSPI_CS_SetDriveMode
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
void ECSPI_CS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ECSPI_CS_0, mode);
}


/*******************************************************************************
* Function Name: ECSPI_CS_Read
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
*  Macro ECSPI_CS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ECSPI_CS_Read(void) 
{
    return (ECSPI_CS_PS & ECSPI_CS_MASK) >> ECSPI_CS_SHIFT;
}


/*******************************************************************************
* Function Name: ECSPI_CS_ReadDataReg
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
uint8 ECSPI_CS_ReadDataReg(void) 
{
    return (ECSPI_CS_DR & ECSPI_CS_MASK) >> ECSPI_CS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ECSPI_CS_INTSTAT) 

    /*******************************************************************************
    * Function Name: ECSPI_CS_ClearInterrupt
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
    uint8 ECSPI_CS_ClearInterrupt(void) 
    {
        return (ECSPI_CS_INTSTAT & ECSPI_CS_MASK) >> ECSPI_CS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
