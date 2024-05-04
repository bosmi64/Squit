/*******************************************************************************
* File Name: QuadDec.h  
* Version 2.0
*
* Description:
*  This file provides constants and parameter values for the Quadrature
*  Decoder component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_QUADRATURE_DECODER_QuadDec_H)
#define CY_QUADRATURE_DECODER_QuadDec_H

#include "cyfitter.h"

#define QuadDec_COUNTER_SIZE               (16u)

#if (QuadDec_COUNTER_SIZE == 8u)
    #include "QuadDec_Cnt8.h"
#else
    #include "QuadDec_Cnt16.h"
#endif /* QuadDec_COUNTER_SIZE == 8u */

#if(QuadDec_COUNTER_SIZE == 32u)

	/* Check to see if required defines such as CY_PSOC3 and CY_PSOC5 are available */
	/* They are defined starting with cy_boot v2.30 */
	#ifndef CY_PSOC3
	    #error Component QuadDec_v2_0 requires cy_boot v2.30 or later
	#endif /* CY_PSOC3 */    
                                        
    #if(CY_PSOC3_ES2 && (QuadDec_isr__ES2_PATCH))
    
        #include <intrins.h>
        #define QuadDec_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
        
    #endif /* End PSOC3_ES2 */

#endif /* QuadDec_COUNTER_SIZE == 32u */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define QuadDec_COUNTER_RESOLUTION         (1u)


/***************************************
*       Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _QuadDec_backupStruct
{
    uint8 enableState;
} QuadDec_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void    QuadDec_Init(void) ;
void    QuadDec_Start(void);
void    QuadDec_Stop(void) ;
void    QuadDec_Enable(void) ;
uint8   QuadDec_GetEvents(void) ;
void    QuadDec_SetInterruptMask(uint8 mask) ;
uint8   QuadDec_GetInterruptMask(void) ;
int16    QuadDec_GetCounter(void) ;
void    QuadDec_SetCounter(int16 value);
void    QuadDec_Sleep(void);
void    QuadDec_Wakeup(void) ;
void    QuadDec_SaveConfig(void) ;
void    QuadDec_RestoreConfig(void) ;

CY_ISR_PROTO(QuadDec_ISR);


/***************************************
*           API Constants
***************************************/

#define QuadDec_ISR_NUMBER                 (QuadDec_isr__INTC_NUMBER)
#define QuadDec_ISR_PRIORITY               (QuadDec_isr__INTC_PRIOR_NUM)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec_GLITCH_FILTERING           (1u)
#define QuadDec_INDEX_INPUT                (0u)


/***************************************
*    Initial Parameter Constants
***************************************/

#if (QuadDec_COUNTER_SIZE == 8u)    
    #define QuadDec_COUNTER_INIT_VALUE    (0x80u)
#else /* (QuadDec_COUNTER_SIZE == 16u) || (QuadDec_COUNTER_SIZE == 32u) */
    #define QuadDec_COUNTER_INIT_VALUE    (0x8000u)
#endif /* QuadDec_COUNTER_SIZE == 8u */   


/***************************************
*             Registers
***************************************/

#define QuadDec_STATUS_REG                 (* (reg8 *) QuadDec_bQuadDec_Stsreg__STATUS_REG)
#define QuadDec_STATUS_PTR                 (  (reg8 *) QuadDec_bQuadDec_Stsreg__STATUS_REG)
#define QuadDec_STATUS_MASK                (* (reg8 *) QuadDec_bQuadDec_Stsreg__MASK_REG)
#define QuadDec_STATUS_MASK_PTR            (  (reg8 *) QuadDec_bQuadDec_Stsreg__MASK_REG)
#define QuadDec_SR_AUX_CONTROL             (* (reg8 *) QuadDec_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)
#define QuadDec_SR_AUX_CONTROL_PTR         (  (reg8 *) QuadDec_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)


/***************************************
*        Register Constants
***************************************/

#define QuadDec_COUNTER_OVERFLOW_SHIFT     (0x00u)
#define QuadDec_COUNTER_UNDERFLOW_SHIFT    (0x01u)
#define QuadDec_COUNTER_RESET_SHIFT        (0x02u)
#define QuadDec_INVALID_IN_SHIFT           (0x03u)
#define QuadDec_COUNTER_OVERFLOW           (0x01u << QuadDec_COUNTER_OVERFLOW_SHIFT)
#define QuadDec_COUNTER_UNDERFLOW          (0x01u << QuadDec_COUNTER_UNDERFLOW_SHIFT)
#define QuadDec_COUNTER_RESET              (0x01u << QuadDec_COUNTER_RESET_SHIFT)
#define QuadDec_INVALID_IN                 (0x01u << QuadDec_INVALID_IN_SHIFT)

#define QuadDec_INTERRUPTS_ENABLE_SHIFT    (0x04u)
#define QuadDec_INTERRUPTS_ENABLE          (0x01u << QuadDec_INTERRUPTS_ENABLE_SHIFT)
#define QuadDec_INIT_INT_MASK              (0x0Fu)
#define QuadDec_DISABLE                    (0x00u)     

#endif /* CY_QUADRATURE_DECODER_QuadDec_H */


/* [] END OF FILE */
