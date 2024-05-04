/*******************************************************************************
* File Name: isr_IMU_UM7.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_IMU_UM7_H)
#define CY_ISR_isr_IMU_UM7_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_IMU_UM7_Start(void);
void isr_IMU_UM7_StartEx(cyisraddress address);
void isr_IMU_UM7_Stop(void);

CY_ISR_PROTO(isr_IMU_UM7_Interrupt);

void isr_IMU_UM7_SetVector(cyisraddress address);
cyisraddress isr_IMU_UM7_GetVector(void);

void isr_IMU_UM7_SetPriority(uint8 priority);
uint8 isr_IMU_UM7_GetPriority(void);

void isr_IMU_UM7_Enable(void);
uint8 isr_IMU_UM7_GetState(void);
void isr_IMU_UM7_Disable(void);

void isr_IMU_UM7_SetPending(void);
void isr_IMU_UM7_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_IMU_UM7 ISR. */
#define isr_IMU_UM7_INTC_VECTOR            ((reg32 *) isr_IMU_UM7__INTC_VECT)

/* Address of the isr_IMU_UM7 ISR priority. */
#define isr_IMU_UM7_INTC_PRIOR             ((reg8 *) isr_IMU_UM7__INTC_PRIOR_REG)

/* Priority of the isr_IMU_UM7 interrupt. */
#define isr_IMU_UM7_INTC_PRIOR_NUMBER      isr_IMU_UM7__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_IMU_UM7 interrupt. */
#define isr_IMU_UM7_INTC_SET_EN            ((reg32 *) isr_IMU_UM7__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_IMU_UM7 interrupt. */
#define isr_IMU_UM7_INTC_CLR_EN            ((reg32 *) isr_IMU_UM7__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_IMU_UM7 interrupt state to pending. */
#define isr_IMU_UM7_INTC_SET_PD            ((reg32 *) isr_IMU_UM7__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_IMU_UM7 interrupt. */
#define isr_IMU_UM7_INTC_CLR_PD            ((reg32 *) isr_IMU_UM7__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_IMU_UM7_H */


/* [] END OF FILE */
