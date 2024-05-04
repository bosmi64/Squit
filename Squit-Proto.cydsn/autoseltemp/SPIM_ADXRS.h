/*******************************************************************************
* File Name: SPIM_ADXRS.h
* Version 2.21
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_SPIM_ADXRS_H)
#define CY_SPIM_SPIM_ADXRS_H

#include "cyfitter.h"

/* PSoC3 ES2 or earlier*/
#define SPIM_ADXRS_PSOC3_ES2   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && \
                     			      (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2))
                     
/* PSoC5 ES1 or earlier */
#define SPIM_ADXRS_PSOC5_ES1   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A) && \
                     		    	  (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_5A_ES1))
	
#ifdef SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH
	#if(SPIM_ADXRS_PSOC3_ES2 && SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define SPIM_ADXRS_TX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* SPIM_ADXRS_TxInternalInterrupt__ES2_PATCH */

#ifdef SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH  
	#if(SPIM_ADXRS_PSOC3_ES2 && SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define SPIM_ADXRS_RX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* SPIM_ADXRS_RxInternalInterrupt__ES2_PATCH */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SPIM_ADXRS_DataWidth                  (16u)
#define SPIM_ADXRS_InternalClockUsed          (0u)
#define SPIM_ADXRS_InternalTxInterruptEnabled (0u)
#define SPIM_ADXRS_InternalRxInterruptEnabled (0u)
#define SPIM_ADXRS_ModeUseZero                (1u)
#define SPIM_ADXRS_BidirectionalMode          (0u)
#define SPIM_ADXRS_Mode                       (1u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_ADXRS_DATAWIDHT                (SPIM_ADXRS_DataWidth)
#define SPIM_ADXRS_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _SPIM_ADXRS_backupStruct
{
    uint8 enableState;
    uint8 cntrPeriod;
    
    #if(SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1) /* PSoC3 ES2 or earlier, PSoC5 ES1 */
    
        uint16 saveSrTxIntMask;
        uint16 saveSrRxIntMask;
        
    #endif /* End SPIM_ADXRS_PSOC3_ES2 || SPIM_ADXRS_PSOC5_ES1 */

} SPIM_ADXRS_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIM_ADXRS_Init(void) ;
void  SPIM_ADXRS_Enable(void) ;
void  SPIM_ADXRS_Start(void) ;
void  SPIM_ADXRS_Stop(void) ;
void  SPIM_ADXRS_EnableTxInt(void) ;
void  SPIM_ADXRS_EnableRxInt(void) ;
void  SPIM_ADXRS_DisableTxInt(void) ;
void  SPIM_ADXRS_DisableRxInt(void) ;
void  SPIM_ADXRS_SetTxInterruptMode(uint8 intSource) ;
void  SPIM_ADXRS_SetRxInterruptMode(uint8 intSource) ;
uint8 SPIM_ADXRS_ReadTxStatus(void) ;
uint8 SPIM_ADXRS_ReadRxStatus(void) ;
void  SPIM_ADXRS_WriteTxData(uint16 txData) ;
uint16 SPIM_ADXRS_ReadRxData(void) ;
uint8 SPIM_ADXRS_GetRxBufferSize(void) ;
uint8 SPIM_ADXRS_GetTxBufferSize(void) ;
void  SPIM_ADXRS_ClearRxBuffer(void) ;
void  SPIM_ADXRS_ClearTxBuffer(void) ;
void  SPIM_ADXRS_ClearFIFO(void) ;
void  SPIM_ADXRS_PutArray(uint16 *buffer, uint8 byteCount) ;
void  SPIM_ADXRS_Sleep(void) ;
void  SPIM_ADXRS_Wakeup(void) ;
void  SPIM_ADXRS_SaveConfig(void) ;
void  SPIM_ADXRS_RestoreConfig(void) ;

#if (SPIM_ADXRS_BidirectionalMode)

    void  SPIM_ADXRS_TxEnable(void) ;
    void  SPIM_ADXRS_TxDisable(void) ;

#endif /* SPIM_ADXRS_BidirectionalMode == 1u*/

CY_ISR_PROTO(SPIM_ADXRS_TX_ISR);
CY_ISR_PROTO(SPIM_ADXRS_RX_ISR);

/* Macros for getting software status of SPIM Statusi Register */
#define SPIM_ADXRS_GET_STATUS_TX(swTxSts) (uint8)(SPIM_ADXRS_TX_STATUS_REG | \
                                                       (swTxSts & SPIM_ADXRS_TX_STS_CLR_ON_RD_BYTES_MASK))
#define SPIM_ADXRS_GET_STATUS_RX(swRxSts) (uint8)(SPIM_ADXRS_RX_STATUS_REG | \
                                                       (swRxSts & SPIM_ADXRS_RX_STS_CLR_ON_RD_BYTES_MASK))                                                  

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_ADXRS_WriteByte (SPIM_ADXRS_WriteTxData)
#define SPIM_ADXRS_ReadByte  (SPIM_ADXRS_ReadRxData)
void  SPIM_ADXRS_SetInterruptMode(uint8 intSource) ;
uint8 SPIM_ADXRS_ReadStatus(void) ;
void  SPIM_ADXRS_EnableInt(void) ;
void  SPIM_ADXRS_DisableInt(void) ;


/***************************************
*           API Constants
***************************************/

#define SPIM_ADXRS_TX_ISR_NUMBER     (SPIM_ADXRS_TxInternalInterrupt__INTC_NUMBER)
#define SPIM_ADXRS_RX_ISR_NUMBER     (SPIM_ADXRS_RxInternalInterrupt__INTC_NUMBER)
#define SPIM_ADXRS_TX_ISR_PRIORITY   (SPIM_ADXRS_TxInternalInterrupt__INTC_PRIOR_NUM)
#define SPIM_ADXRS_RX_ISR_PRIORITY   (SPIM_ADXRS_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/
                                               
#define SPIM_ADXRS_INT_ON_SPI_DONE    (0u << SPIM_ADXRS_STS_SPI_DONE_SHIFT)
#define SPIM_ADXRS_INT_ON_TX_EMPTY    (0u << SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIM_ADXRS_INT_ON_TX_NOT_FULL (0u << SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIM_ADXRS_INT_ON_BYTE_COMP   (0u << SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT)
#define SPIM_ADXRS_INT_ON_SPI_IDLE    (0u << SPIM_ADXRS_STS_SPI_IDLE_SHIFT)

#define SPIM_ADXRS_TX_INIT_INTERRUPTS_MASK  (SPIM_ADXRS_INT_ON_SPI_DONE | \
                                            SPIM_ADXRS_INT_ON_TX_EMPTY | SPIM_ADXRS_INT_ON_TX_NOT_FULL | \
                                            SPIM_ADXRS_INT_ON_BYTE_COMP | SPIM_ADXRS_INT_ON_SPI_IDLE)
            
#define SPIM_ADXRS_INT_ON_RX_FULL      (0u << SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT)
#define SPIM_ADXRS_INT_ON_RX_NOT_EMPTY (0u << SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIM_ADXRS_INT_ON_RX_OVER      (0u << SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT)

#define SPIM_ADXRS_RX_INIT_INTERRUPTS_MASK  (SPIM_ADXRS_INT_ON_RX_FULL | \
                                            SPIM_ADXRS_INT_ON_RX_NOT_EMPTY | SPIM_ADXRS_INT_ON_RX_OVER)
                                               
#define SPIM_ADXRS_BITCTR_INIT           ( (SPIM_ADXRS_DataWidth << 1u) - 1u)

#define SPIM_ADXRS_TXBUFFERSIZE          (4u)
#define SPIM_ADXRS_RXBUFFERSIZE          (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_ADXRS_INIT_INTERRUPTS_MASK  (SPIM_ADXRS_INT_ON_SPI_DONE | SPIM_ADXRS_INT_ON_TX_EMPTY | \
                                            SPIM_ADXRS_INT_ON_TX_NOT_FULL | SPIM_ADXRS_INT_ON_RX_FULL | \
                                            SPIM_ADXRS_INT_ON_RX_NOT_EMPTY | SPIM_ADXRS_INT_ON_RX_OVER | \
                                            SPIM_ADXRS_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#define SPIM_ADXRS_TXDATA_REG         (* (reg16 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
#define SPIM_ADXRS_TXDATA_PTR         (  (reg16 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
#define SPIM_ADXRS_RXDATA_REG         (* (reg16 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)
#define SPIM_ADXRS_RXDATA_PTR         (  (reg16 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)

#define SPIM_ADXRS_AUX_CONTROL_DP0_REG (* (reg8 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)
#define SPIM_ADXRS_AUX_CONTROL_DP0_PTR (  (reg8 *) \
        SPIM_ADXRS_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)        

#if (SPIM_ADXRS_DataWidth > 8u)

    #define SPIM_ADXRS_AUX_CONTROL_DP1_REG  (* (reg8 *) \
            SPIM_ADXRS_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
    #define SPIM_ADXRS_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
            SPIM_ADXRS_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
#endif /* SPIM_ADXRS_DataWidth > 8u */

#define SPIM_ADXRS_COUNTER_PERIOD_REG  (* (reg8 *)  SPIM_ADXRS_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_ADXRS_COUNTER_PERIOD_PTR  (  (reg8 *)  SPIM_ADXRS_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_ADXRS_COUNTER_CONTROL_REG (* (reg8 *)  SPIM_ADXRS_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIM_ADXRS_COUNTER_CONTROL_PTR (  (reg8 *)  SPIM_ADXRS_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIM_ADXRS_TX_STATUS_REG       (* (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_ADXRS_TX_STATUS_PTR       (  (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_ADXRS_RX_STATUS_REG       (* (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__STATUS_REG)
#define SPIM_ADXRS_RX_STATUS_PTR       (  (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__STATUS_REG)

#define SPIM_ADXRS_CONTROL_REG         (* (reg8 *)  \
        SPIM_ADXRS_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
#define SPIM_ADXRS_CONTROL_PTR         (  (reg8 *)  \
        SPIM_ADXRS_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
        
#define SPIM_ADXRS_TX_STATUS_MASK_REG  (* (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__MASK_REG)
#define SPIM_ADXRS_TX_STATUS_MASK_PTR  (  (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__MASK_REG)
#define SPIM_ADXRS_RX_STATUS_MASK_REG  (* (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__MASK_REG)
#define SPIM_ADXRS_RX_STATUS_MASK_PTR  (  (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__MASK_REG)

#define SPIM_ADXRS_TX_STATUS_ACTL_REG  (* (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_TX_STATUS_ACTL_PTR  (  (reg8 *)  SPIM_ADXRS_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_RX_STATUS_ACTL_REG  (* (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_RX_STATUS_ACTL_PTR  (  (reg8 *)  SPIM_ADXRS_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

/* Obsolete register names. Not to be used in new designs */
#define SPIM_ADXRS_TXDATA                 (SPIM_ADXRS_TXDATA_REG)
#define SPIM_ADXRS_RXDATA                 (SPIM_ADXRS_RXDATA_REG)
#define SPIM_ADXRS_AUX_CONTROLDP0         (SPIM_ADXRS_AUX_CONTROL_DP0_REG)
#define SPIM_ADXRS_TXBUFFERREAD           (SPIM_ADXRS_txBufferRead)
#define SPIM_ADXRS_TXBUFFERWRITE          (SPIM_ADXRS_txBufferWrite)
#define SPIM_ADXRS_RXBUFFERREAD           (SPIM_ADXRS_rxBufferRead)
#define SPIM_ADXRS_RXBUFFERWRITE          (SPIM_ADXRS_rxBufferWrite)

#if(SPIM_ADXRS_DataWidth > 8u)    
    #define SPIM_ADXRS_AUX_CONTROLDP1     (SPIM_ADXRS_AUX_CONTROL_DP1_REG)    
#endif /* SPIM_ADXRS_DataWidth > 8u */
    
#define SPIM_ADXRS_COUNTER_PERIOD         (SPIM_ADXRS_COUNTER_PERIOD_REG)
#define SPIM_ADXRS_COUNTER_CONTROL        (SPIM_ADXRS_COUNTER_CONTROL_REG)
#define SPIM_ADXRS_STATUS                 (SPIM_ADXRS_TX_STATUS_REG)
#define SPIM_ADXRS_CONTROL                (SPIM_ADXRS_CONTROL_REG)
#define SPIM_ADXRS_STATUS_MASK            (SPIM_ADXRS_TX_STATUS_MASK_REG)
#define SPIM_ADXRS_STATUS_ACTL            (SPIM_ADXRS_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants 
***************************************/

/* Status Register Definitions */
#define SPIM_ADXRS_STS_SPI_DONE_SHIFT          (0x00u)
#define SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT     (0x01u)
#define SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT  (0x02u)
#define SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT     (0x03u)
#define SPIM_ADXRS_STS_SPI_IDLE_SHIFT          (0x04u)
#define SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT      (0x04u)
#define SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT (0x05u)
#define SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT   (0x06u)

#define SPIM_ADXRS_STS_SPI_DONE                (0x01u << SPIM_ADXRS_STS_SPI_DONE_SHIFT)        
#define SPIM_ADXRS_STS_TX_FIFO_EMPTY           (0x01u << SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT)    
#define SPIM_ADXRS_STS_TX_FIFO_NOT_FULL        (0x01u << SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT)    
#define SPIM_ADXRS_STS_SPI_IDLE                (0x01u << SPIM_ADXRS_STS_SPI_IDLE_SHIFT)
#define SPIM_ADXRS_STS_RX_FIFO_FULL            (0x01u << SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT)    
#define SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY       (0x01u << SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT)    
#define SPIM_ADXRS_STS_RX_FIFO_OVERRUN         (0x01u << SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT)  
#define SPIM_ADXRS_STS_BYTE_COMPLETE           (0x01u << SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT)

#define SPIM_ADXRS_TX_STS_CLR_ON_RD_BYTES_MASK (0x09u)
#define SPIM_ADXRS_RX_STS_CLR_ON_RD_BYTES_MASK (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_ADXRS_INT_ENABLE                  (0x10u)
#define SPIM_ADXRS_FIFO_CLR                    (0x03u)
                                                                 
/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_ADXRS_CNTR_ENABLE                 (0x20u)   
                                                                  
/* Bi-Directional mode control bit */
#define SPIM_ADXRS_CTRL_TX_SIGNAL_EN           (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIM_ADXRS_AUX_CTRL_FIFO0_CLR          (0x01u)
#define SPIM_ADXRS_AUX_CTRL_FIFO1_CLR          (0x02u)
#define SPIM_ADXRS_AUX_CTRL_FIFO0_LVL          (0x04u)
#define SPIM_ADXRS_AUX_CTRL_FIFO1_LVL          (0x08u)
#define SPIM_ADXRS_STATUS_ACTL_INT_EN_MASK     (0x10u)

#endif  /* CY_SPIM_SPIM_ADXRS_H */


/* [] END OF FILE */
