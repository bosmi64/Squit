/*******************************************************************************
* File Name: ENC_A.c  
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
#include "ENC_A.h"


/*******************************************************************************
* Function Name: ENC_A_Write
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
void ENC_A_Write(uint8 value) 
{
    uint8 staticBits = ENC_A_DR & ~ENC_A_MASK;
    ENC_A_DR = staticBits | ((value << ENC_A_SHIFT) & ENC_A_MASK);
}


/*******************************************************************************
* Function Name: ENC_A_SetDriveMode
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
void ENC_A_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ENC_A_0, mode);
}


/*******************************************************************************
* Function Name: ENC_A_Read
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
*  Macro ENC_A_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ENC_A_Read(void) 
{
    return (ENC_A_PS & ENC_A_MASK) >> ENC_A_SHIFT;
}


/*******************************************************************************
* Function Name: ENC_A_ReadDataReg
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
uint8 ENC_A_ReadDataReg(void) 
{
    return (ENC_A_DR & ENC_A_MASK) >> ENC_A_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ENC_A_INTSTAT) 

    /*******************************************************************************
    * Function Name: ENC_A_ClearInterrupt
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
    uint8 ENC_A_ClearInterrupt(void) 
    {
        return (ENC_A_INTSTAT & ENC_A_MASK) >> ENC_A_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */ 
