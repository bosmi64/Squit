/*******************************************************************************
* File Name: ADXL_X.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ADXL_X.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADXL_X__PORT == 15 && ((ADXL_X__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADXL_X_Write
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
void ADXL_X_Write(uint8 value) 
{
    uint8 staticBits = (ADXL_X_DR & (uint8)(~ADXL_X_MASK));
    ADXL_X_DR = staticBits | ((uint8)(value << ADXL_X_SHIFT) & ADXL_X_MASK);
}


/*******************************************************************************
* Function Name: ADXL_X_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ADXL_X_DM_STRONG     Strong Drive 
*  ADXL_X_DM_OD_HI      Open Drain, Drives High 
*  ADXL_X_DM_OD_LO      Open Drain, Drives Low 
*  ADXL_X_DM_RES_UP     Resistive Pull Up 
*  ADXL_X_DM_RES_DWN    Resistive Pull Down 
*  ADXL_X_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ADXL_X_DM_DIG_HIZ    High Impedance Digital 
*  ADXL_X_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ADXL_X_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADXL_X_0, mode);
}


/*******************************************************************************
* Function Name: ADXL_X_Read
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
*  Macro ADXL_X_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADXL_X_Read(void) 
{
    return (ADXL_X_PS & ADXL_X_MASK) >> ADXL_X_SHIFT;
}


/*******************************************************************************
* Function Name: ADXL_X_ReadDataReg
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
uint8 ADXL_X_ReadDataReg(void) 
{
    return (ADXL_X_DR & ADXL_X_MASK) >> ADXL_X_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADXL_X_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADXL_X_ClearInterrupt
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
    uint8 ADXL_X_ClearInterrupt(void) 
    {
        return (ADXL_X_INTSTAT & ADXL_X_MASK) >> ADXL_X_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
