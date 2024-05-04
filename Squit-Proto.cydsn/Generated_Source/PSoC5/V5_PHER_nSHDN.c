/*******************************************************************************
* File Name: V5_PHER_nSHDN.c  
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
#include "V5_PHER_nSHDN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 V5_PHER_nSHDN__PORT == 15 && ((V5_PHER_nSHDN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: V5_PHER_nSHDN_Write
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
void V5_PHER_nSHDN_Write(uint8 value) 
{
    uint8 staticBits = (V5_PHER_nSHDN_DR & (uint8)(~V5_PHER_nSHDN_MASK));
    V5_PHER_nSHDN_DR = staticBits | ((uint8)(value << V5_PHER_nSHDN_SHIFT) & V5_PHER_nSHDN_MASK);
}


/*******************************************************************************
* Function Name: V5_PHER_nSHDN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  V5_PHER_nSHDN_DM_STRONG     Strong Drive 
*  V5_PHER_nSHDN_DM_OD_HI      Open Drain, Drives High 
*  V5_PHER_nSHDN_DM_OD_LO      Open Drain, Drives Low 
*  V5_PHER_nSHDN_DM_RES_UP     Resistive Pull Up 
*  V5_PHER_nSHDN_DM_RES_DWN    Resistive Pull Down 
*  V5_PHER_nSHDN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  V5_PHER_nSHDN_DM_DIG_HIZ    High Impedance Digital 
*  V5_PHER_nSHDN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void V5_PHER_nSHDN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(V5_PHER_nSHDN_0, mode);
}


/*******************************************************************************
* Function Name: V5_PHER_nSHDN_Read
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
*  Macro V5_PHER_nSHDN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 V5_PHER_nSHDN_Read(void) 
{
    return (V5_PHER_nSHDN_PS & V5_PHER_nSHDN_MASK) >> V5_PHER_nSHDN_SHIFT;
}


/*******************************************************************************
* Function Name: V5_PHER_nSHDN_ReadDataReg
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
uint8 V5_PHER_nSHDN_ReadDataReg(void) 
{
    return (V5_PHER_nSHDN_DR & V5_PHER_nSHDN_MASK) >> V5_PHER_nSHDN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(V5_PHER_nSHDN_INTSTAT) 

    /*******************************************************************************
    * Function Name: V5_PHER_nSHDN_ClearInterrupt
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
    uint8 V5_PHER_nSHDN_ClearInterrupt(void) 
    {
        return (V5_PHER_nSHDN_INTSTAT & V5_PHER_nSHDN_MASK) >> V5_PHER_nSHDN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
