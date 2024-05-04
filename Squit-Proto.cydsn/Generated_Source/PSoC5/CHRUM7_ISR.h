/*******************************************************************************
* File Name: CHRUM7_ISR.h
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
#if !defined(CY_ISR_CHRUM7_ISR_H)
#define CY_ISR_CHRUM7_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void CHRUM7_ISR_Start(void);
void CHRUM7_ISR_StartEx(cyisraddress address);
void CHRUM7_ISR_Stop(void);

CY_ISR_PROTO(CHRUM7_ISR_Interrupt);

void CHRUM7_ISR_SetVector(cyisraddress address);
cyisraddress CHRUM7_ISR_GetVector(void);

void CHRUM7_ISR_SetPriority(uint8 priority);
uint8 CHRUM7_ISR_GetPriority(void);

void CHRUM7_ISR_Enable(void);
uint8 CHRUM7_ISR_GetState(void);
void CHRUM7_ISR_Disable(void);

void CHRUM7_ISR_SetPending(void);
void CHRUM7_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the CHRUM7_ISR ISR. */
#define CHRUM7_ISR_INTC_VECTOR            ((reg32 *) CHRUM7_ISR__INTC_VECT)

/* Address of the CHRUM7_ISR ISR priority. */
#define CHRUM7_ISR_INTC_PRIOR             ((reg8 *) CHRUM7_ISR__INTC_PRIOR_REG)

/* Priority of the CHRUM7_ISR interrupt. */
#define CHRUM7_ISR_INTC_PRIOR_NUMBER      CHRUM7_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable CHRUM7_ISR interrupt. */
#define CHRUM7_ISR_INTC_SET_EN            ((reg32 *) CHRUM7_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the CHRUM7_ISR interrupt. */
#define CHRUM7_ISR_INTC_CLR_EN            ((reg32 *) CHRUM7_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the CHRUM7_ISR interrupt state to pending. */
#define CHRUM7_ISR_INTC_SET_PD            ((reg32 *) CHRUM7_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the CHRUM7_ISR interrupt. */
#define CHRUM7_ISR_INTC_CLR_PD            ((reg32 *) CHRUM7_ISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_CHRUM7_ISR_H */


/* [] END OF FILE */
