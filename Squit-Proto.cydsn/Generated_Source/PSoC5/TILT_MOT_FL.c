/*******************************************************************************
* File Name: TILT_MOT_FL.c  
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
#include "TILT_MOT_FL.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 TILT_MOT_FL__PORT == 15 && ((TILT_MOT_FL__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: TILT_MOT_FL_Write
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
void TILT_MOT_FL_Write(uint8 value) 
{
    uint8 staticBits = (TILT_MOT_FL_DR & (uint8)(~TILT_MOT_FL_MASK));
    TILT_MOT_FL_DR = staticBits | ((uint8)(value << TILT_MOT_FL_SHIFT) & TILT_MOT_FL_MASK);
}


/*******************************************************************************
* Function Name: TILT_MOT_FL_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  TILT_MOT_FL_DM_STRONG     Strong Drive 
*  TILT_MOT_FL_DM_OD_HI      Open Drain, Drives High 
*  TILT_MOT_FL_DM_OD_LO      Open Drain, Drives Low 
*  TILT_MOT_FL_DM_RES_UP     Resistive Pull Up 
*  TILT_MOT_FL_DM_RES_DWN    Resistive Pull Down 
*  TILT_MOT_FL_DM_RES_UPDWN  Resistive Pull Up/Down 
*  TILT_MOT_FL_DM_DIG_HIZ    High Impedance Digital 
*  TILT_MOT_FL_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void TILT_MOT_FL_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(TILT_MOT_FL_0, mode);
}


/*******************************************************************************
* Function Name: TILT_MOT_FL_Read
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
*  Macro TILT_MOT_FL_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 TILT_MOT_FL_Read(void) 
{
    return (TILT_MOT_FL_PS & TILT_MOT_FL_MASK) >> TILT_MOT_FL_SHIFT;
}


/*******************************************************************************
* Function Name: TILT_MOT_FL_ReadDataReg
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
uint8 TILT_MOT_FL_ReadDataReg(void) 
{
    return (TILT_MOT_FL_DR & TILT_MOT_FL_MASK) >> TILT_MOT_FL_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(TILT_MOT_FL_INTSTAT) 

    /*******************************************************************************
    * Function Name: TILT_MOT_FL_ClearInterrupt
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
    uint8 TILT_MOT_FL_ClearInterrupt(void) 
    {
        return (TILT_MOT_FL_INTSTAT & TILT_MOT_FL_MASK) >> TILT_MOT_FL_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
