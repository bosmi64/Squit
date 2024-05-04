/*******************************************************************************
* File Name: ADXRS_CLK.c  
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
#include "ADXRS_CLK.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADXRS_CLK__PORT == 15 && ((ADXRS_CLK__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADXRS_CLK_Write
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
void ADXRS_CLK_Write(uint8 value) 
{
    uint8 staticBits = (ADXRS_CLK_DR & (uint8)(~ADXRS_CLK_MASK));
    ADXRS_CLK_DR = staticBits | ((uint8)(value << ADXRS_CLK_SHIFT) & ADXRS_CLK_MASK);
}


/*******************************************************************************
* Function Name: ADXRS_CLK_SetDriveMode
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
void ADXRS_CLK_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADXRS_CLK_0, mode);
}


/*******************************************************************************
* Function Name: ADXRS_CLK_Read
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
*  Macro ADXRS_CLK_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADXRS_CLK_Read(void) 
{
    return (ADXRS_CLK_PS & ADXRS_CLK_MASK) >> ADXRS_CLK_SHIFT;
}


/*******************************************************************************
* Function Name: ADXRS_CLK_ReadDataReg
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
uint8 ADXRS_CLK_ReadDataReg(void) 
{
    return (ADXRS_CLK_DR & ADXRS_CLK_MASK) >> ADXRS_CLK_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADXRS_CLK_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADXRS_CLK_ClearInterrupt
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
    uint8 ADXRS_CLK_ClearInterrupt(void) 
    {
        return (ADXRS_CLK_INTSTAT & ADXRS_CLK_MASK) >> ADXRS_CLK_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
