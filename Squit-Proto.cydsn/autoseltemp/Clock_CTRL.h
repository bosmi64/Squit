/*******************************************************************************
* File Name: Clock_CTRL.h
* Version 1.60
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_CLOCK_Clock_CTRL_H)
#define CY_CLOCK_Clock_CTRL_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void Clock_CTRL_Start(void) ;
void Clock_CTRL_Stop(void) ;

#if(!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2) && \
	!(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5 && \
	CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_5A_ES1))
void Clock_CTRL_StopBlock(void) ;
#endif

void Clock_CTRL_StandbyPower(uint8 state) ;
void Clock_CTRL_SetDividerRegister(uint16 clkDivider, uint8 reset) ;
uint16 Clock_CTRL_GetDividerRegister(void) ;
void Clock_CTRL_SetModeRegister(uint8 modeBitMask) ;
void Clock_CTRL_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_CTRL_GetModeRegister(void) ;
void Clock_CTRL_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_CTRL_GetSourceRegister(void) ;
#if defined(Clock_CTRL__CFG3)
void Clock_CTRL_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_CTRL_GetPhaseRegister(void) ;
#endif

#define Clock_CTRL_Enable()                       Clock_CTRL_Start()
#define Clock_CTRL_Disable()                      Clock_CTRL_Stop()
#define Clock_CTRL_SetDivider(clkDivider)         Clock_CTRL_SetDividerRegister(clkDivider, 1)
#define Clock_CTRL_SetDividerValue(clkDivider)    Clock_CTRL_SetDividerRegister((clkDivider) - 1, 1)
#define Clock_CTRL_SetMode(clkMode)               Clock_CTRL_SetModeRegister(clkMode)
#define Clock_CTRL_SetSource(clkSource)           Clock_CTRL_SetSourceRegister(clkSource)
#if defined(Clock_CTRL__CFG3)
#define Clock_CTRL_SetPhase(clkPhase)             Clock_CTRL_SetPhaseRegister(clkPhase)
#define Clock_CTRL_SetPhaseValue(clkPhase)        Clock_CTRL_SetPhaseRegister((clkPhase) + 1)
#endif


/***************************************
*           API Constants
***************************************/

/* Constants SetPhase(), clkPhase parameter. Only valid for PSoC 3 ES2 and earlier. See datasheet for details. */
#if CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3 && \
   (CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES1 || \
    CYDEV_CHIP_REVISION_USED == CYDEV_CHIP_REVISION_3A_ES2)
#define CYCLK_2_5NS             0x01 /* 2.5 ns delay. */
#define CYCLK_3_5NS             0x02 /* 3.5 ns delay. */
#define CYCLK_4_5NS             0x03 /* 4.5 ns delay. */
#define CYCLK_5_5NS             0x04 /* 5.5 ns delay. */
#define CYCLK_6_5NS             0x05 /* 6.5 ns delay. */
#define CYCLK_7_5NS             0x06 /* 7.5 ns delay. */
#define CYCLK_8_5NS             0x07 /* 8.5 ns delay. */
#define CYCLK_9_5NS             0x08 /* 9.5 ns delay. */
#define CYCLK_10_5NS            0x09 /* 10.5 ns delay. */
#define CYCLK_11_5NS            0x0A /* 11.5 ns delay. */
#define CYCLK_12_5NS            0x0B /* 12.5 ns delay. */
#endif


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
#endif


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
#endif

#endif /* CY_CLOCK_Clock_CTRL_H */


/* [] END OF FILE */
