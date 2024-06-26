/*******************************************************************************
* File Name: POT_TEST.c  
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
#include "POT_TEST.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 POT_TEST__PORT == 15 && ((POT_TEST__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: POT_TEST_Write
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
void POT_TEST_Write(uint8 value) 
{
    uint8 staticBits = (POT_TEST_DR & (uint8)(~POT_TEST_MASK));
    POT_TEST_DR = staticBits | ((uint8)(value << POT_TEST_SHIFT) & POT_TEST_MASK);
}


/*******************************************************************************
* Function Name: POT_TEST_SetDriveMode
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
void POT_TEST_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(POT_TEST_0, mode);
}


/*******************************************************************************
* Function Name: POT_TEST_Read
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
*  Macro POT_TEST_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 POT_TEST_Read(void) 
{
    return (POT_TEST_PS & POT_TEST_MASK) >> POT_TEST_SHIFT;
}


/*******************************************************************************
* Function Name: POT_TEST_ReadDataReg
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
uint8 POT_TEST_ReadDataReg(void) 
{
    return (POT_TEST_DR & POT_TEST_MASK) >> POT_TEST_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(POT_TEST_INTSTAT) 

    /*******************************************************************************
    * Function Name: POT_TEST_ClearInterrupt
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
    uint8 POT_TEST_ClearInterrupt(void) 
    {
        return (POT_TEST_INTSTAT & POT_TEST_MASK) >> POT_TEST_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
