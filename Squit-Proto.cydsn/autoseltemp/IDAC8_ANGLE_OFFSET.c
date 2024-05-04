/*******************************************************************************
* File Name: IDAC8_ANGLE_OFFSET.c  
* Version 1.80
*
*  Description:
*    This file provides the source code to the API for the 8-bit Current 
*    DAC (IDAC8) User Module.
*
*   Note:
*     
*
*******************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "cytypes.h"
#include "IDAC8_ANGLE_OFFSET.h"   

#if (CY_PSOC5_ES1)
#include <CyLib.h>
#endif /* CY_PSOC5_ES1 */

uint8 IDAC8_ANGLE_OFFSET_initVar = 0u;


static IDAC8_ANGLE_OFFSET_backupStruct  IDAC8_ANGLE_OFFSET_backup;

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5 ES1 */
#if (CY_PSOC5_ES1)
uint8 IDAC8_ANGLE_OFFSET_restoreReg = 0u;
uint8 IDAC8_ANGLE_OFFSET_intrStatus = 0u;
#endif /* CY_PSOC5_ES1 */


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:  
*  void:  
*
* Return: 
*  (void)
*
* Theory: 
*
* Side Effects: 
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_Init(void) 
{
    IDAC8_ANGLE_OFFSET_CR0 = (IDAC8_ANGLE_OFFSET_MODE_I | IDAC8_ANGLE_OFFSET_DEFAULT_RANGE )  ;    

    /* Set default data source */
    if(IDAC8_ANGLE_OFFSET_DEFAULT_DATA_SRC != 0u )    
    {
        IDAC8_ANGLE_OFFSET_CR1 = (IDAC8_ANGLE_OFFSET_DEFAULT_CNTL | IDAC8_ANGLE_OFFSET_DACBUS_ENABLE) ;   
    }
    else
    {
        IDAC8_ANGLE_OFFSET_CR1 = (IDAC8_ANGLE_OFFSET_DEFAULT_CNTL | IDAC8_ANGLE_OFFSET_DACBUS_DISABLE) ;   
    } 
    
    /*Controls polarity from UDB Control*/
    if(IDAC8_ANGLE_OFFSET_DEFAULT_POLARITY == IDAC8_ANGLE_OFFSET_HARDWARE_CONTROLLED)
    {
         IDAC8_ANGLE_OFFSET_CR1 |= IDAC8_ANGLE_OFFSET_IDIR_SRC_UDB;
    }
    else
    {
        IDAC8_ANGLE_OFFSET_CR1 |= IDAC8_ANGLE_OFFSET_DEFAULT_POLARITY;
    }
    /*Controls Current Source from UDB Control*/
    if(IDAC8_ANGLE_OFFSET_HARDWARE_ENABLE != 0u ) 
    {
        IDAC8_ANGLE_OFFSET_CR1 |= IDAC8_ANGLE_OFFSET_IDIR_CTL_UDB;
    }
    
    /* Set default strobe mode */
    if(IDAC8_ANGLE_OFFSET_DEFAULT_STRB != 0u)
    {
        IDAC8_ANGLE_OFFSET_Strobe |= IDAC8_ANGLE_OFFSET_STRB_EN ;
    }
    
    /* Set default speed */
    IDAC8_ANGLE_OFFSET_SetSpeed(IDAC8_ANGLE_OFFSET_DEFAULT_SPEED); 
    
    /* Set proper DAC trim */
    IDAC8_ANGLE_OFFSET_DacTrim();  
    
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_Enable
********************************************************************************
* Summary:
*     Enable the IDAC8
* 
* Parameters:  
*  void:  
*
* Return: 
*  (void)
*
* Theory: 
*
* Side Effects: 
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_Enable(void) 
{
    IDAC8_ANGLE_OFFSET_PWRMGR |= IDAC8_ANGLE_OFFSET_ACT_PWR_EN;
    IDAC8_ANGLE_OFFSET_STBY_PWRMGR |= IDAC8_ANGLE_OFFSET_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5_ES1)
    if(IDAC8_ANGLE_OFFSET_restoreReg == 1u)
    {
        IDAC8_ANGLE_OFFSET_CR0 = IDAC8_ANGLE_OFFSET_backup.DACCR0Reg;

        /* Clear the flag */
        IDAC8_ANGLE_OFFSET_restoreReg = 0u;
    }
    #endif /* CY_PSOC5_ES1 */
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_Start
********************************************************************************
* Summary:
*  Set power level then turn on IDAC8.
*
* Parameters:  
*  power:   Sets power level between off (0) and (3) high power
*
* Return: 
*  (void) 
*
* Global variables:
*  IDAC8_ANGLE_OFFSET_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDAC8_ANGLE_OFFSET_initVar == 0u)  
    {     
        IDAC8_ANGLE_OFFSET_Init();
       
        IDAC8_ANGLE_OFFSET_initVar = 1;
    }  
   
    /* Enable power to DAC */
    IDAC8_ANGLE_OFFSET_Enable();

    /* Set default value */
    IDAC8_ANGLE_OFFSET_SetValue(IDAC8_ANGLE_OFFSET_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_Stop
********************************************************************************
* Summary:
*  Powers down IDAC8 to lowest power state.
*
* Parameters:  
*   (void)
*
* Return: 
*  (void)
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_Stop(void) 
{
   /* Disble power to DAC */
   IDAC8_ANGLE_OFFSET_PWRMGR &= ~IDAC8_ANGLE_OFFSET_ACT_PWR_EN;
   IDAC8_ANGLE_OFFSET_STBY_PWRMGR &= ~IDAC8_ANGLE_OFFSET_STBY_PWR_EN;
   
   #if (CY_PSOC5_ES1)
   
        /* Set the global variable  */
        IDAC8_ANGLE_OFFSET_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDAC8_ANGLE_OFFSET_backup.DACCR0Reg = IDAC8_ANGLE_OFFSET_CR0;
        IDAC8_ANGLE_OFFSET_CR0 = (IDAC8_ANGLE_OFFSET_MODE_I | IDAC8_ANGLE_OFFSET_RANGE_3 | IDAC8_ANGLE_OFFSET_HS_HIGHSPEED);
    #endif /* CY_PSOC5_ES1 */
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:  
*  power:   Sets speed value
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_SetSpeed(uint8 speed) 
{
   /* Clear power mask then write in new value */
   IDAC8_ANGLE_OFFSET_CR0 &= ~IDAC8_ANGLE_OFFSET_HS_MASK ;    
   IDAC8_ANGLE_OFFSET_CR0 |=  ( speed & IDAC8_ANGLE_OFFSET_HS_MASK) ;    
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current.
*  
* Parameters:  
*  Polarity: Sets the IDAC to Sink or Source 
*   0x00 - Source
*   0x04 - Sink
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
#if(IDAC8_ANGLE_OFFSET_DEFAULT_POLARITY != IDAC8_ANGLE_OFFSET_HARDWARE_CONTROLLED)
void IDAC8_ANGLE_OFFSET_SetPolarity(uint8 polarity) 
{
    IDAC8_ANGLE_OFFSET_CR1 &= ~IDAC8_ANGLE_OFFSET_IDIR_MASK;                /* clear polarity bit */
    IDAC8_ANGLE_OFFSET_CR1 |= (polarity & IDAC8_ANGLE_OFFSET_IDIR_MASK);    /* set new value */
    
    IDAC8_ANGLE_OFFSET_DacTrim();
}
#endif

/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:  
*  Range:  Sets on of four valid ranges.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_SetRange(uint8 range) 
{
   IDAC8_ANGLE_OFFSET_CR0 &= ~IDAC8_ANGLE_OFFSET_RANGE_MASK ;       /* Clear existing mode */
   IDAC8_ANGLE_OFFSET_CR0 |= ( range & IDAC8_ANGLE_OFFSET_RANGE_MASK );  /*  Set Range  */
   IDAC8_ANGLE_OFFSET_DacTrim();
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_SetValue(uint8 value) 
{

   #if (CY_PSOC5_ES1)
       IDAC8_ANGLE_OFFSET_intrStatus = CyEnterCriticalSection();
   #endif /* CY_PSOC5_ES1 */

   IDAC8_ANGLE_OFFSET_Data = value;         /*  Set Value  */
   
   /* PSOC3 silicons earlier to ES3 require a double write */
   #if (CY_PSOC3_ES2 ||CY_PSOC5_ES1 )
       IDAC8_ANGLE_OFFSET_Data = value;
   #endif /* CY_PSOC3_ES2 ||CY_PSOC5_ES1  */
   
   #if (CY_PSOC5_ES1)
       CyExitCriticalSection(IDAC8_ANGLE_OFFSET_intrStatus);
   #endif /* CY_PSOC5_ES1 */
}


/*******************************************************************************
* Function Name: IDAC8_ANGLE_OFFSET_DacTrim
********************************************************************************
* Summary:
*  Set the trim value for the given range.
*
* Parameters:  
*  None
*
* Return: 
*  (void) 
*
* Theory: 
*  Trim values for the IDAC blocks are stored in the "Customer Table" area in 
*  Row 1 of the Hidden Flash.  There are 8 bytes of trim data for each 
*  IDAC block.
*  The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* Side Effects:
*
*******************************************************************************/
void IDAC8_ANGLE_OFFSET_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDAC8_ANGLE_OFFSET_CR0 & IDAC8_ANGLE_OFFSET_RANGE_MASK) >> 1);
    
    if((IDAC8_ANGLE_OFFSET_IDIR_MASK & IDAC8_ANGLE_OFFSET_CR1) == IDAC8_ANGLE_OFFSET_IDIR_SINK)
    {
        mode++;
    }

    IDAC8_ANGLE_OFFSET_TR = CY_GET_XTND_REG8((uint8 *)(IDAC8_ANGLE_OFFSET_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
