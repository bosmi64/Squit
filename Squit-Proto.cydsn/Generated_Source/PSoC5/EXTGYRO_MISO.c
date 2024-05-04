/*******************************************************************************
* File Name: EXTGYRO_MISO.c  
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
#include "EXTGYRO_MISO.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EXTGYRO_MISO__PORT == 15 && ((EXTGYRO_MISO__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EXTGYRO_MISO_Write
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
void EXTGYRO_MISO_Write(uint8 value) 
{
    uint8 staticBits = (EXTGYRO_MISO_DR & (uint8)(~EXTGYRO_MISO_MASK));
    EXTGYRO_MISO_DR = staticBits | ((uint8)(value << EXTGYRO_MISO_SHIFT) & EXTGYRO_MISO_MASK);
}


/*******************************************************************************
* Function Name: EXTGYRO_MISO_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  EXTGYRO_MISO_DM_STRONG     Strong Drive 
*  EXTGYRO_MISO_DM_OD_HI      Open Drain, Drives High 
*  EXTGYRO_MISO_DM_OD_LO      Open Drain, Drives Low 
*  EXTGYRO_MISO_DM_RES_UP     Resistive Pull Up 
*  EXTGYRO_MISO_DM_RES_DWN    Resistive Pull Down 
*  EXTGYRO_MISO_DM_RES_UPDWN  Resistive Pull Up/Down 
*  EXTGYRO_MISO_DM_DIG_HIZ    High Impedance Digital 
*  EXTGYRO_MISO_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void EXTGYRO_MISO_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EXTGYRO_MISO_0, mode);
}


/*******************************************************************************
* Function Name: EXTGYRO_MISO_Read
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
*  Macro EXTGYRO_MISO_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EXTGYRO_MISO_Read(void) 
{
    return (EXTGYRO_MISO_PS & EXTGYRO_MISO_MASK) >> EXTGYRO_MISO_SHIFT;
}


/*******************************************************************************
* Function Name: EXTGYRO_MISO_ReadDataReg
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
uint8 EXTGYRO_MISO_ReadDataReg(void) 
{
    return (EXTGYRO_MISO_DR & EXTGYRO_MISO_MASK) >> EXTGYRO_MISO_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EXTGYRO_MISO_INTSTAT) 

    /*******************************************************************************
    * Function Name: EXTGYRO_MISO_ClearInterrupt
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
    uint8 EXTGYRO_MISO_ClearInterrupt(void) 
    {
        return (EXTGYRO_MISO_INTSTAT & EXTGYRO_MISO_MASK) >> EXTGYRO_MISO_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
