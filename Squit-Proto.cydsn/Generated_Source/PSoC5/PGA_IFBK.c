/*******************************************************************************
* File Name: PGA_IFBK.c  
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the PGA 
*  User Module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PGA_IFBK.h"

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static PGA_IFBK_BACKUP_STRUCT  PGA_IFBK_P5backup;
#endif /* (CY_ PSOC5A) */

uint8 PGA_IFBK_initVar = 0u;


/*******************************************************************************   
* Function Name: PGA_IFBK_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  PGA_IFBK_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_IFBK_Init(void) 
{
    /* Set PGA mode */
    PGA_IFBK_CR0_REG = PGA_IFBK_MODE_PGA;      
    /* Set non-inverting PGA mode and reference mode */
    PGA_IFBK_CR1_REG |= PGA_IFBK_PGA_NINV;  
    /* Set default gain and ref mode */
    PGA_IFBK_CR2_REG = PGA_IFBK_VREF_MODE;
    /* Set gain and compensation */
    PGA_IFBK_SetGain(PGA_IFBK_DEFAULT_GAIN);
    /* Set power */
    PGA_IFBK_SetPower(PGA_IFBK_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: PGA_IFBK_Enable
********************************************************************************
*
* Summary:
*  Enables the PGA block operation.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_IFBK_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(PGA_IFBK_P5backup.enableState == 1u)
        {
            PGA_IFBK_CR1_REG = PGA_IFBK_P5backup.scCR1Reg;
            PGA_IFBK_CR2_REG = PGA_IFBK_P5backup.scCR2Reg;
            PGA_IFBK_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */   

    /* Enable power to the Amp in Active mode*/
    PGA_IFBK_PM_ACT_CFG_REG |= PGA_IFBK_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative Active mode*/
    PGA_IFBK_PM_STBY_CFG_REG |= PGA_IFBK_STBY_PWR_EN;
    
    PGA_IFBK_PUMP_CR1_REG |= PGA_IFBK_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                PGA_IFBK_BSTCLK_REG &= (uint8)(~PGA_IFBK_BST_CLK_INDEX_MASK);
                PGA_IFBK_BSTCLK_REG |= PGA_IFBK_BST_CLK_EN | CyScBoostClk__INDEX;
                PGA_IFBK_SC_MISC_REG |= PGA_IFBK_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                PGA_IFBK_BSTCLK_REG &= (uint8)(~PGA_IFBK_BST_CLK_EN);
                PGA_IFBK_SC_MISC_REG &= (uint8)(~PGA_IFBK_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: PGA_IFBK_Start
********************************************************************************
*
* Summary:
*  The start function initializes the PGA with the default values and sets
*  the power to the given level. A power level of 0, is same as executing
*  the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_IFBK_Start(void) 
{

    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modification in stop() API */

    if(PGA_IFBK_initVar == 0u)
    {
        PGA_IFBK_Init();
        PGA_IFBK_initVar = 1u;
    }

    PGA_IFBK_Enable();
}


/*******************************************************************************
* Function Name: PGA_IFBK_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_IFBK_Stop(void) 
{ 
    /* Disble power to the Amp in Active mode template */
    PGA_IFBK_PM_ACT_CFG_REG &= (uint8)(~PGA_IFBK_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative Active mode template */
    PGA_IFBK_PM_STBY_CFG_REG &= (uint8)(~PGA_IFBK_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            PGA_IFBK_BSTCLK_REG &= (uint8)(~PGA_IFBK_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((PGA_IFBK_PM_ACT_CFG_REG & PGA_IFBK_PM_ACT_CFG_MASK) == 0u)
            {
                PGA_IFBK_SC_MISC_REG &= (uint8)(~PGA_IFBK_PUMP_FORCE);
                PGA_IFBK_PUMP_CR1_REG &= (uint8)(~PGA_IFBK_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        PGA_IFBK_P5backup.scCR1Reg = PGA_IFBK_CR1_REG;
        PGA_IFBK_P5backup.scCR2Reg = PGA_IFBK_CR2_REG;
        PGA_IFBK_CR1_REG = 0x00u;
        PGA_IFBK_CR2_REG = 0x00u;
        PGA_IFBK_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: PGA_IFBK_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the PGA.
*
* Parameters:
*  power: Sets power level between (0) and (3) high power
*
* Return:
*  void
*
*******************************************************************************/
void PGA_IFBK_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = PGA_IFBK_CR1_REG & (uint8)(~PGA_IFBK_DRIVE_MASK);
    tmpCR |= (power & PGA_IFBK_DRIVE_MASK);
    PGA_IFBK_CR1_REG = tmpCR;  
}


/*******************************************************************************
* Function Name: PGA_IFBK_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Gain value of PGA (See header file for gain values.)
*
* Return:
*  void 
*
*******************************************************************************/
void PGA_IFBK_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 PGA_IFBK_GainArray[9] = { 
        (PGA_IFBK_RVAL_0K   | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=1  */
        (PGA_IFBK_RVAL_40K  | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=2  */
        (PGA_IFBK_RVAL_120K | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=4  */
        (PGA_IFBK_RVAL_280K | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=8  */
        (PGA_IFBK_RVAL_600K | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=16 */
        (PGA_IFBK_RVAL_460K | PGA_IFBK_R20_40B_40K | PGA_IFBK_BIAS_LOW), /* G=24, Sets Rin as 20k */
        (PGA_IFBK_RVAL_620K | PGA_IFBK_R20_40B_20K | PGA_IFBK_BIAS_LOW), /* G=32 */
        (PGA_IFBK_RVAL_470K | PGA_IFBK_R20_40B_20K | PGA_IFBK_BIAS_LOW), /* G=48, Sets Rin as 10k */
        (PGA_IFBK_RVAL_490K | PGA_IFBK_R20_40B_20K | PGA_IFBK_BIAS_LOW)  /* G=50, Sets Rin as 10k */
    };
    
    /* Constant array for gain compenstion settings */
    const uint8 PGA_IFBK_GainComp[9] = { 
        ( PGA_IFBK_COMP_4P35PF  | (uint8)( PGA_IFBK_REDC_00 >> 2 )), /* G=1  */
        ( PGA_IFBK_COMP_4P35PF  | (uint8)( PGA_IFBK_REDC_01 >> 2 )), /* G=2  */
        ( PGA_IFBK_COMP_3P0PF   | (uint8)( PGA_IFBK_REDC_01 >> 2 )), /* G=4  */
        ( PGA_IFBK_COMP_3P0PF   | (uint8)( PGA_IFBK_REDC_01 >> 2 )), /* G=8  */
        ( PGA_IFBK_COMP_3P6PF   | (uint8)( PGA_IFBK_REDC_01 >> 2 )), /* G=16 */
        ( PGA_IFBK_COMP_3P6PF   | (uint8)( PGA_IFBK_REDC_11 >> 2 )), /* G=24 */
        ( PGA_IFBK_COMP_3P6PF   | (uint8)( PGA_IFBK_REDC_11 >> 2 )), /* G=32 */
        ( PGA_IFBK_COMP_3P6PF   | (uint8)( PGA_IFBK_REDC_00 >> 2 )), /* G=48 */
        ( PGA_IFBK_COMP_3P6PF   | (uint8)( PGA_IFBK_REDC_00 >> 2 ))  /* G=50 */
    };
    
    /* Only set new gain if it is a valid gain */
    if( gain <= PGA_IFBK_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        PGA_IFBK_CR2_REG &= (uint8)(~(PGA_IFBK_RVAL_MASK | PGA_IFBK_R20_40B_MASK | 
                                PGA_IFBK_REDC_MASK | PGA_IFBK_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        PGA_IFBK_CR2_REG |= (PGA_IFBK_GainArray[gain] |
                                ((uint8)(PGA_IFBK_GainComp[gain] << 2 ) & PGA_IFBK_REDC_MASK));

        /* Clear sc_comp  */
        PGA_IFBK_CR1_REG &= (uint8)(~PGA_IFBK_COMP_MASK);
        /* Set sc_comp  */
        PGA_IFBK_CR1_REG |= ( PGA_IFBK_GainComp[gain] | PGA_IFBK_COMP_MASK );
    }
}


/* [] END OF FILE */
