/*******************************************************************************
* File Name: Clock_CTRL.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_CTRL_H)
#define CY_CLOCK_Clock_CTRL_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_CTRL_Start(void) ;
void Clock_CTRL_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_CTRL_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_CTRL_StandbyPower(uint8 state) ;
void Clock_CTRL_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_CTRL_GetDividerRegister(void) ;
void Clock_CTRL_SetModeRegister(uint8 modeBitMask) ;
void Clock_CTRL_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_CTRL_GetModeRegister(void) ;
void Clock_CTRL_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_CTRL_GetSourceRegister(void) ;
#if defined(Clock_CTRL__CFG3)
void Clock_CTRL_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_CTRL_GetPhaseRegister(void) ;
#endif /* defined(Clock_CTRL__CFG3) */

#define Clock_CTRL_Enable()                       Clock_CTRL_Start()
#define Clock_CTRL_Disable()                      Clock_CTRL_Stop()
#define Clock_CTRL_SetDivider(clkDivider)         Clock_CTRL_SetDividerRegister(clkDivider, 1u)
#define Clock_CTRL_SetDividerValue(clkDivider)    Clock_CTRL_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock_CTRL_SetMode(clkMode)               Clock_CTRL_SetModeRegister(clkMode)
#define Clock_CTRL_SetSource(clkSource)           Clock_CTRL_SetSourceRegister(clkSource)
#if defined(Clock_CTRL__CFG3)
#define Clock_CTRL_SetPhase(clkPhase)             Clock_CTRL_SetPhaseRegister(clkPhase)
#define Clock_CTRL_SetPhaseValue(clkPhase)        Clock_CTRL_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock_CTRL__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_CTRL_CLKEN              (* (reg8 *) Clock_CTRL__PM_ACT_CFG)
#define Clock_CTRL_CLKEN_PTR          ((reg8 *) Clock_CTRL__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_CTRL_CLKSTBY            (* (reg8 *) Clock_CTRL__PM_STBY_CFG)
#define Clock_CTRL_CLKSTBY_PTR        ((reg8 *) Clock_CTRL__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_CTRL_DIV_LSB            (* (reg8 *) Clock_CTRL__CFG0)
#define Clock_CTRL_DIV_LSB_PTR        ((reg8 *) Clock_CTRL__CFG0)
#define Clock_CTRL_DIV_PTR            ((reg16 *) Clock_CTRL__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_CTRL_DIV_MSB            (* (reg8 *) Clock_CTRL__CFG1)
#define Clock_CTRL_DIV_MSB_PTR        ((reg8 *) Clock_CTRL__CFG1)

/* Mode and source configuration register */
#define Clock_CTRL_MOD_SRC            (* (reg8 *) Clock_CTRL__CFG2)
#define Clock_CTRL_MOD_SRC_PTR        ((reg8 *) Clock_CTRL__CFG2)

#if defined(Clock_CTRL__CFG3)
/* Analog clock phase configuration register */
#define Clock_CTRL_PHASE              (* (reg8 *) Clock_CTRL__CFG3)
#define Clock_CTRL_PHASE_PTR          ((reg8 *) Clock_CTRL__CFG3)
#endif /* defined(Clock_CTRL__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_CTRL_CLKEN_MASK         Clock_CTRL__PM_ACT_MSK
#define Clock_CTRL_CLKSTBY_MASK       Clock_CTRL__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_CTRL_SRC_SEL_MSK        Clock_CTRL__CFG2_SRC_SEL_MASK
#define Clock_CTRL_MODE_MASK          (~(Clock_CTRL_SRC_SEL_MSK))

#if defined(Clock_CTRL__CFG3)
/* CFG3 phase mask */
#define Clock_CTRL_PHASE_MASK         Clock_CTRL__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_CTRL__CFG3) */

#endif /* CY_CLOCK_Clock_CTRL_H */


/* [] END OF FILE */
