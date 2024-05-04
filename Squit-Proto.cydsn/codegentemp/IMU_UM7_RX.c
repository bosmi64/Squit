/*******************************************************************************
* File Name: IMU_UM7_RX.c  
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
#include "IMU_UM7_RX.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 IMU_UM7_RX__PORT == 15 && ((IMU_UM7_RX__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: IMU_UM7_RX_Write
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
void IMU_UM7_RX_Write(uint8 value) 
{
    uint8 staticBits = (IMU_UM7_RX_DR & (uint8)(~IMU_UM7_RX_MASK));
    IMU_UM7_RX_DR = staticBits | ((uint8)(value << IMU_UM7_RX_SHIFT) & IMU_UM7_RX_MASK);
}


/*******************************************************************************
* Function Name: IMU_UM7_RX_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  IMU_UM7_RX_DM_STRONG     Strong Drive 
*  IMU_UM7_RX_DM_OD_HI      Open Drain, Drives High 
*  IMU_UM7_RX_DM_OD_LO      Open Drain, Drives Low 
*  IMU_UM7_RX_DM_RES_UP     Resistive Pull Up 
*  IMU_UM7_RX_DM_RES_DWN    Resistive Pull Down 
*  IMU_UM7_RX_DM_RES_UPDWN  Resistive Pull Up/Down 
*  IMU_UM7_RX_DM_DIG_HIZ    High Impedance Digital 
*  IMU_UM7_RX_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void IMU_UM7_RX_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(IMU_UM7_RX_0, mode);
}


/*******************************************************************************
* Function Name: IMU_UM7_RX_Read
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
*  Macro IMU_UM7_RX_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IMU_UM7_RX_Read(void) 
{
    return (IMU_UM7_RX_PS & IMU_UM7_RX_MASK) >> IMU_UM7_RX_SHIFT;
}


/*******************************************************************************
* Function Name: IMU_UM7_RX_ReadDataReg
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
uint8 IMU_UM7_RX_ReadDataReg(void) 
{
    return (IMU_UM7_RX_DR & IMU_UM7_RX_MASK) >> IMU_UM7_RX_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IMU_UM7_RX_INTSTAT) 

    /*******************************************************************************
    * Function Name: IMU_UM7_RX_ClearInterrupt
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
    uint8 IMU_UM7_RX_ClearInterrupt(void) 
    {
        return (IMU_UM7_RX_INTSTAT & IMU_UM7_RX_MASK) >> IMU_UM7_RX_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
