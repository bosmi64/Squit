/*******************************************************************************
* File Name: CLK_DLINK.h
* Version 2.0
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

#if !defined(CY_CLOCK_CLK_DLINK_H)
#define CY_CLOCK_CLK_DLINK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CLK_DLINK_Start(void) ;
void CLK_DLINK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CLK_DLINK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CLK_DLINK_StandbyPower(uint8 state) ;
void CLK_DLINK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CLK_DLINK_GetDividerRegister(void) ;
void CLK_DLINK_SetModeRegister(uint8 modeBitMask) ;
void CLK_DLINK_ClearModeRegister(uint8 modeBitMask) ;
uint8 CLK_DLINK_GetModeRegister(void) ;
void CLK_DLINK_SetSourceRegister(uint8 clkSource) ;
uint8 CLK_DLINK_GetSourceRegister(void) ;
#if defined(CLK_DLINK__CFG3)
void CLK_DLINK_SetPhaseRegister(uint8 clkPhase) ;
uint8 CLK_DLINK_GetPhaseRegister(void) ;
#endif /* defined(CLK_DLINK__CFG3) */

#define CLK_DLINK_Enable()                       CLK_DLINK_Start()
#define CLK_DLINK_Disable()                      CLK_DLINK_Stop()
#define CLK_DLINK_SetDivider(clkDivider)         CLK_DLINK_SetDividerRegister(clkDivider, 1)
#define CLK_DLINK_SetDividerValue(clkDivider)    CLK_DLINK_SetDividerRegister((clkDivider) - 1, 1)
#define CLK_DLINK_SetMode(clkMode)               CLK_DLINK_SetModeRegister(clkMode)
#define CLK_DLINK_SetSource(clkSource)           CLK_DLINK_SetSourceRegister(clkSource)
#if defined(CLK_DLINK__CFG3)
#define CLK_DLINK_SetPhase(clkPhase)             CLK_DLINK_SetPhaseRegister(clkPhase)
#define CLK_DLINK_SetPhaseValue(clkPhase)        CLK_DLINK_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(CLK_DLINK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CLK_DLINK_CLKEN              (* (reg8 *) CLK_DLINK__PM_ACT_CFG)
#define CLK_DLINK_CLKEN_PTR          ((reg8 *) CLK_DLINK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CLK_DLINK_CLKSTBY            (* (reg8 *) CLK_DLINK__PM_STBY_CFG)
#define CLK_DLINK_CLKSTBY_PTR        ((reg8 *) CLK_DLINK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CLK_DLINK_DIV_LSB            (* (reg8 *) CLK_DLINK__CFG0)
#define CLK_DLINK_DIV_LSB_PTR        ((reg8 *) CLK_DLINK__CFG0)
#define CLK_DLINK_DIV_PTR            ((reg16 *) CLK_DLINK__CFG0)

/* Clock MSB divider configuration register. */
#define CLK_DLINK_DIV_MSB            (* (reg8 *) CLK_DLINK__CFG1)
#define CLK_DLINK_DIV_MSB_PTR        ((reg8 *) CLK_DLINK__CFG1)

/* Mode and source configuration register */
#define CLK_DLINK_MOD_SRC            (* (reg8 *) CLK_DLINK__CFG2)
#define CLK_DLINK_MOD_SRC_PTR        ((reg8 *) CLK_DLINK__CFG2)

#if defined(CLK_DLINK__CFG3)
/* Analog clock phase configuration register */
#define CLK_DLINK_PHASE              (* (reg8 *) CLK_DLINK__CFG3)
#define CLK_DLINK_PHASE_PTR          ((reg8 *) CLK_DLINK__CFG3)
#endif /* defined(CLK_DLINK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CLK_DLINK_CLKEN_MASK         CLK_DLINK__PM_ACT_MSK
#define CLK_DLINK_CLKSTBY_MASK       CLK_DLINK__PM_STBY_MSK

/* CFG2 field masks */
#define CLK_DLINK_SRC_SEL_MSK        CLK_DLINK__CFG2_SRC_SEL_MASK
#define CLK_DLINK_MODE_MASK          (~(CLK_DLINK_SRC_SEL_MSK))

#if defined(CLK_DLINK__CFG3)
/* CFG3 phase mask */
#define CLK_DLINK_PHASE_MASK         CLK_DLINK__CFG3_PHASE_DLY_MASK
#endif /* defined(CLK_DLINK__CFG3) */

#endif /* CY_CLOCK_CLK_DLINK_H */


/* [] END OF FILE */
