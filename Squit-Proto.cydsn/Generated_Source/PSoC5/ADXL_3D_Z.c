/*******************************************************************************
* File Name: ADXL_3D_Z.c  
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
#include "ADXL_3D_Z.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADXL_3D_Z__PORT == 15 && ((ADXL_3D_Z__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADXL_3D_Z_Write
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
void ADXL_3D_Z_Write(uint8 value) 
{
    uint8 staticBits = (ADXL_3D_Z_DR & (uint8)(~ADXL_3D_Z_MASK));
    ADXL_3D_Z_DR = staticBits | ((uint8)(value << ADXL_3D_Z_SHIFT) & ADXL_3D_Z_MASK);
}


/*******************************************************************************
* Function Name: ADXL_3D_Z_SetDriveMode
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
void ADXL_3D_Z_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADXL_3D_Z_0, mode);
}


/*******************************************************************************
* Function Name: ADXL_3D_Z_Read
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
*  Macro ADXL_3D_Z_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADXL_3D_Z_Read(void) 
{
    return (ADXL_3D_Z_PS & ADXL_3D_Z_MASK) >> ADXL_3D_Z_SHIFT;
}


/*******************************************************************************
* Function Name: ADXL_3D_Z_ReadDataReg
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
uint8 ADXL_3D_Z_ReadDataReg(void) 
{
    return (ADXL_3D_Z_DR & ADXL_3D_Z_MASK) >> ADXL_3D_Z_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADXL_3D_Z_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADXL_3D_Z_ClearInterrupt
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
    uint8 ADXL_3D_Z_ClearInterrupt(void) 
    {
        return (ADXL_3D_Z_INTSTAT & ADXL_3D_Z_MASK) >> ADXL_3D_Z_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
