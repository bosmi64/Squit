/*******************************************************************************
* File Name: MOT_SLEEPn.c  
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
#include "MOT_SLEEPn.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 MOT_SLEEPn__PORT == 15 && ((MOT_SLEEPn__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: MOT_SLEEPn_Write
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
void MOT_SLEEPn_Write(uint8 value) 
{
    uint8 staticBits = (MOT_SLEEPn_DR & (uint8)(~MOT_SLEEPn_MASK));
    MOT_SLEEPn_DR = staticBits | ((uint8)(value << MOT_SLEEPn_SHIFT) & MOT_SLEEPn_MASK);
}


/*******************************************************************************
* Function Name: MOT_SLEEPn_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MOT_SLEEPn_DM_STRONG     Strong Drive 
*  MOT_SLEEPn_DM_OD_HI      Open Drain, Drives High 
*  MOT_SLEEPn_DM_OD_LO      Open Drain, Drives Low 
*  MOT_SLEEPn_DM_RES_UP     Resistive Pull Up 
*  MOT_SLEEPn_DM_RES_DWN    Resistive Pull Down 
*  MOT_SLEEPn_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MOT_SLEEPn_DM_DIG_HIZ    High Impedance Digital 
*  MOT_SLEEPn_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MOT_SLEEPn_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(MOT_SLEEPn_0, mode);
}


/*******************************************************************************
* Function Name: MOT_SLEEPn_Read
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
*  Macro MOT_SLEEPn_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MOT_SLEEPn_Read(void) 
{
    return (MOT_SLEEPn_PS & MOT_SLEEPn_MASK) >> MOT_SLEEPn_SHIFT;
}


/*******************************************************************************
* Function Name: MOT_SLEEPn_ReadDataReg
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
uint8 MOT_SLEEPn_ReadDataReg(void) 
{
    return (MOT_SLEEPn_DR & MOT_SLEEPn_MASK) >> MOT_SLEEPn_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MOT_SLEEPn_INTSTAT) 

    /*******************************************************************************
    * Function Name: MOT_SLEEPn_ClearInterrupt
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
    uint8 MOT_SLEEPn_ClearInterrupt(void) 
    {
        return (MOT_SLEEPn_INTSTAT & MOT_SLEEPn_MASK) >> MOT_SLEEPn_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
