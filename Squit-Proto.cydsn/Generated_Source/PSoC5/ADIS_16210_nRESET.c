/*******************************************************************************
* File Name: ADIS_16210_nRESET.c  
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
#include "ADIS_16210_nRESET.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ADIS_16210_nRESET__PORT == 15 && ((ADIS_16210_nRESET__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ADIS_16210_nRESET_Write
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
void ADIS_16210_nRESET_Write(uint8 value) 
{
    uint8 staticBits = (ADIS_16210_nRESET_DR & (uint8)(~ADIS_16210_nRESET_MASK));
    ADIS_16210_nRESET_DR = staticBits | ((uint8)(value << ADIS_16210_nRESET_SHIFT) & ADIS_16210_nRESET_MASK);
}


/*******************************************************************************
* Function Name: ADIS_16210_nRESET_SetDriveMode
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
void ADIS_16210_nRESET_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ADIS_16210_nRESET_0, mode);
}


/*******************************************************************************
* Function Name: ADIS_16210_nRESET_Read
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
*  Macro ADIS_16210_nRESET_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ADIS_16210_nRESET_Read(void) 
{
    return (ADIS_16210_nRESET_PS & ADIS_16210_nRESET_MASK) >> ADIS_16210_nRESET_SHIFT;
}


/*******************************************************************************
* Function Name: ADIS_16210_nRESET_ReadDataReg
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
uint8 ADIS_16210_nRESET_ReadDataReg(void) 
{
    return (ADIS_16210_nRESET_DR & ADIS_16210_nRESET_MASK) >> ADIS_16210_nRESET_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ADIS_16210_nRESET_INTSTAT) 

    /*******************************************************************************
    * Function Name: ADIS_16210_nRESET_ClearInterrupt
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
    uint8 ADIS_16210_nRESET_ClearInterrupt(void) 
    {
        return (ADIS_16210_nRESET_INTSTAT & ADIS_16210_nRESET_MASK) >> ADIS_16210_nRESET_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
