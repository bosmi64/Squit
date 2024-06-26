/*******************************************************************************
* File Name: isr_CTRL.h
* Version 1.50
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(__isr_CTRL_INTC_H__)
#define __isr_CTRL_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define isr_CTRL_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void isr_CTRL_Start(void);
void isr_CTRL_StartEx(cyisraddress address);
void isr_CTRL_Stop(void) ;

CY_ISR_PROTO(isr_CTRL_Interrupt);

void isr_CTRL_SetVector(cyisraddress address) ;
cyisraddress isr_CTRL_GetVector(void) ;

void isr_CTRL_SetPriority(uint8 priority) ;
uint8 isr_CTRL_GetPriority(void) ;

void isr_CTRL_Enable(void) ;
uint8 isr_CTRL_GetState(void) ;
void isr_CTRL_Disable(void) ;

void isr_CTRL_SetPending(void) ;
void isr_CTRL_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_CTRL ISR. */
#define isr_CTRL_INTC_VECTOR            ((reg16 *) isr_CTRL__INTC_VECT)

/* Address of the isr_CTRL ISR priority. */
#define isr_CTRL_INTC_PRIOR             ((reg8 *) isr_CTRL__INTC_PRIOR_REG)

/* Priority of the isr_CTRL interrupt. */
#define isr_CTRL_INTC_PRIOR_NUMBER      isr_CTRL__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_CTRL interrupt. */
#define isr_CTRL_INTC_SET_EN            ((reg8 *) isr_CTRL__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_CTRL interrupt. */
#define isr_CTRL_INTC_CLR_EN            ((reg8 *) isr_CTRL__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_CTRL interrupt state to pending. */
#define isr_CTRL_INTC_SET_PD            ((reg8 *) isr_CTRL__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_CTRL interrupt. */
#define isr_CTRL_INTC_CLR_PD            ((reg8 *) isr_CTRL__INTC_CLR_PD_REG)



/* __isr_CTRL_INTC_H__ */
#endif
