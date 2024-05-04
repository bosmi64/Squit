/*******************************************************************************
* File Name: ADIS_16210_SPI.h
* Version 2.40
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_ADIS_16210_SPI_H)
#define CY_SPIM_ADIS_16210_SPI_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component SPI_Master_v2_40 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define ADIS_16210_SPI_INTERNAL_CLOCK             (0u)

#if(0u != ADIS_16210_SPI_INTERNAL_CLOCK)
    #include "ADIS_16210_SPI_IntClock.h"
#endif /* (0u != ADIS_16210_SPI_INTERNAL_CLOCK) */

#define ADIS_16210_SPI_MODE                       (4u)
#define ADIS_16210_SPI_DATA_WIDTH                 (16u)
#define ADIS_16210_SPI_MODE_USE_ZERO              (0u)
#define ADIS_16210_SPI_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define ADIS_16210_SPI_TX_BUFFER_SIZE             (4u)
#define ADIS_16210_SPI_RX_BUFFER_SIZE             (4u)
#define ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED    (0u)
#define ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED    (0u)

#define ADIS_16210_SPI_SINGLE_REG_SIZE            (8u)
#define ADIS_16210_SPI_USE_SECOND_DATAPATH        (ADIS_16210_SPI_DATA_WIDTH > ADIS_16210_SPI_SINGLE_REG_SIZE)

#define ADIS_16210_SPI_FIFO_SIZE                  (4u)
#define ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED    ((0u != ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED) && \
                                                     (ADIS_16210_SPI_TX_BUFFER_SIZE > ADIS_16210_SPI_FIFO_SIZE))

#define ADIS_16210_SPI_RX_SOFTWARE_BUF_ENABLED    ((0u != ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED) && \
                                                     (ADIS_16210_SPI_RX_BUFFER_SIZE > ADIS_16210_SPI_FIFO_SIZE))


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint8 cntrPeriod;
    #if(CY_UDB_V0)
        uint16 saveSrTxIntMask;
        uint16 saveSrRxIntMask;
    #endif /* (CY_UDB_V0) */

} ADIS_16210_SPI_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  ADIS_16210_SPI_Init(void)                           ;
void  ADIS_16210_SPI_Enable(void)                         ;
void  ADIS_16210_SPI_Start(void)                          ;
void  ADIS_16210_SPI_Stop(void)                           ;

void  ADIS_16210_SPI_EnableTxInt(void)                    ;
void  ADIS_16210_SPI_EnableRxInt(void)                    ;
void  ADIS_16210_SPI_DisableTxInt(void)                   ;
void  ADIS_16210_SPI_DisableRxInt(void)                   ;

void  ADIS_16210_SPI_Sleep(void)                          ;
void  ADIS_16210_SPI_Wakeup(void)                         ;
void  ADIS_16210_SPI_SaveConfig(void)                     ;
void  ADIS_16210_SPI_RestoreConfig(void)                  ;

void  ADIS_16210_SPI_SetTxInterruptMode(uint8 intSrc)     ;
void  ADIS_16210_SPI_SetRxInterruptMode(uint8 intSrc)     ;
uint8 ADIS_16210_SPI_ReadTxStatus(void)                   ;
uint8 ADIS_16210_SPI_ReadRxStatus(void)                   ;
void  ADIS_16210_SPI_WriteTxData(uint16 txData)  \
                                                            ;
uint16 ADIS_16210_SPI_ReadRxData(void) \
                                                            ;
uint8 ADIS_16210_SPI_GetRxBufferSize(void)                ;
uint8 ADIS_16210_SPI_GetTxBufferSize(void)                ;
void  ADIS_16210_SPI_ClearRxBuffer(void)                  ;
void  ADIS_16210_SPI_ClearTxBuffer(void)                  ;
void  ADIS_16210_SPI_ClearFIFO(void)                              ;
void  ADIS_16210_SPI_PutArray(const uint16 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != ADIS_16210_SPI_BIDIRECTIONAL_MODE)
    void  ADIS_16210_SPI_TxEnable(void)                   ;
    void  ADIS_16210_SPI_TxDisable(void)                  ;
#endif /* (0u != ADIS_16210_SPI_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(ADIS_16210_SPI_TX_ISR);
CY_ISR_PROTO(ADIS_16210_SPI_RX_ISR);


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 ADIS_16210_SPI_initVar;


/***************************************
*           API Constants
***************************************/

#define ADIS_16210_SPI_TX_ISR_NUMBER     ((uint8) (ADIS_16210_SPI_TxInternalInterrupt__INTC_NUMBER))
#define ADIS_16210_SPI_RX_ISR_NUMBER     ((uint8) (ADIS_16210_SPI_RxInternalInterrupt__INTC_NUMBER))

#define ADIS_16210_SPI_TX_ISR_PRIORITY   ((uint8) (ADIS_16210_SPI_TxInternalInterrupt__INTC_PRIOR_NUM))
#define ADIS_16210_SPI_RX_ISR_PRIORITY   ((uint8) (ADIS_16210_SPI_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define ADIS_16210_SPI_INT_ON_SPI_DONE    ((uint8) (0u   << ADIS_16210_SPI_STS_SPI_DONE_SHIFT))
#define ADIS_16210_SPI_INT_ON_TX_EMPTY    ((uint8) (0u   << ADIS_16210_SPI_STS_TX_FIFO_EMPTY_SHIFT))
#define ADIS_16210_SPI_INT_ON_TX_NOT_FULL ((uint8) (0u << \
                                                                           ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL_SHIFT))
#define ADIS_16210_SPI_INT_ON_BYTE_COMP   ((uint8) (0u  << ADIS_16210_SPI_STS_BYTE_COMPLETE_SHIFT))
#define ADIS_16210_SPI_INT_ON_SPI_IDLE    ((uint8) (0u   << ADIS_16210_SPI_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define ADIS_16210_SPI_INT_ON_TX_NOT_FULL_DEF ((ADIS_16210_SPI_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (ADIS_16210_SPI_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define ADIS_16210_SPI_TX_INIT_INTERRUPTS_MASK    (ADIS_16210_SPI_INT_ON_SPI_DONE  | \
                                                     ADIS_16210_SPI_INT_ON_TX_EMPTY  | \
                                                     ADIS_16210_SPI_INT_ON_TX_NOT_FULL_DEF | \
                                                     ADIS_16210_SPI_INT_ON_BYTE_COMP | \
                                                     ADIS_16210_SPI_INT_ON_SPI_IDLE)

#define ADIS_16210_SPI_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          ADIS_16210_SPI_STS_RX_FIFO_FULL_SHIFT))
#define ADIS_16210_SPI_INT_ON_RX_NOT_EMPTY    ((uint8) (0u << \
                                                                          ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define ADIS_16210_SPI_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          ADIS_16210_SPI_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define ADIS_16210_SPI_RX_INIT_INTERRUPTS_MASK    (ADIS_16210_SPI_INT_ON_RX_FULL      | \
                                                     ADIS_16210_SPI_INT_ON_RX_NOT_EMPTY | \
                                                     ADIS_16210_SPI_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define ADIS_16210_SPI_BITCTR_INIT            (((uint8) (ADIS_16210_SPI_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC3 || CY_PSOC5)
    #define ADIS_16210_SPI_TXDATA_REG (* (reg16 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F0_REG)
    #define ADIS_16210_SPI_TXDATA_PTR (  (reg16 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F0_REG)
    #define ADIS_16210_SPI_RXDATA_REG (* (reg16 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F1_REG)
    #define ADIS_16210_SPI_RXDATA_PTR (  (reg16 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(ADIS_16210_SPI_USE_SECOND_DATAPATH)
        #define ADIS_16210_SPI_TXDATA_REG (* (reg16 *) \
                                          ADIS_16210_SPI_BSPIM_sR16_Dp_u0__16BIT_F0_REG)
        #define ADIS_16210_SPI_TXDATA_PTR (  (reg16 *) \
                                          ADIS_16210_SPI_BSPIM_sR16_Dp_u0__16BIT_F0_REG)
        #define ADIS_16210_SPI_RXDATA_REG (* (reg16 *) \
                                          ADIS_16210_SPI_BSPIM_sR16_Dp_u0__16BIT_F1_REG)
        #define ADIS_16210_SPI_RXDATA_PTR         (  (reg16 *) \
                                          ADIS_16210_SPI_BSPIM_sR16_Dp_u0__16BIT_F1_REG)
    #else
        #define ADIS_16210_SPI_TXDATA_REG (* (reg8 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F0_REG)
        #define ADIS_16210_SPI_TXDATA_PTR (  (reg8 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F0_REG)
        #define ADIS_16210_SPI_RXDATA_REG (* (reg8 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F1_REG)
        #define ADIS_16210_SPI_RXDATA_PTR (  (reg8 *) \
                                                ADIS_16210_SPI_BSPIM_sR16_Dp_u0__F1_REG)
    #endif /* (ADIS_16210_SPI_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define ADIS_16210_SPI_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        ADIS_16210_SPI_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)
#define ADIS_16210_SPI_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        ADIS_16210_SPI_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)

#if(ADIS_16210_SPI_USE_SECOND_DATAPATH)
    #define ADIS_16210_SPI_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        ADIS_16210_SPI_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
    #define ADIS_16210_SPI_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        ADIS_16210_SPI_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
#endif /* (ADIS_16210_SPI_USE_SECOND_DATAPATH) */

#define ADIS_16210_SPI_COUNTER_PERIOD_REG     (* (reg8 *) ADIS_16210_SPI_BSPIM_BitCounter__PERIOD_REG)
#define ADIS_16210_SPI_COUNTER_PERIOD_PTR     (  (reg8 *) ADIS_16210_SPI_BSPIM_BitCounter__PERIOD_REG)
#define ADIS_16210_SPI_COUNTER_CONTROL_REG    (* (reg8 *) ADIS_16210_SPI_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define ADIS_16210_SPI_COUNTER_CONTROL_PTR    (  (reg8 *) ADIS_16210_SPI_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define ADIS_16210_SPI_TX_STATUS_REG          (* (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__STATUS_REG)
#define ADIS_16210_SPI_TX_STATUS_PTR          (  (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__STATUS_REG)
#define ADIS_16210_SPI_RX_STATUS_REG          (* (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__STATUS_REG)
#define ADIS_16210_SPI_RX_STATUS_PTR          (  (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__STATUS_REG)

#define ADIS_16210_SPI_CONTROL_REG            (* (reg8 *) \
                                      ADIS_16210_SPI_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
#define ADIS_16210_SPI_CONTROL_PTR            (  (reg8 *) \
                                      ADIS_16210_SPI_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)

#define ADIS_16210_SPI_TX_STATUS_MASK_REG     (* (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__MASK_REG)
#define ADIS_16210_SPI_TX_STATUS_MASK_PTR     (  (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__MASK_REG)
#define ADIS_16210_SPI_RX_STATUS_MASK_REG     (* (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__MASK_REG)
#define ADIS_16210_SPI_RX_STATUS_MASK_PTR     (  (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__MASK_REG)

#define ADIS_16210_SPI_TX_STATUS_ACTL_REG     (* (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define ADIS_16210_SPI_TX_STATUS_ACTL_PTR     (  (reg8 *) ADIS_16210_SPI_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define ADIS_16210_SPI_RX_STATUS_ACTL_REG     (* (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define ADIS_16210_SPI_RX_STATUS_ACTL_PTR     (  (reg8 *) ADIS_16210_SPI_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(ADIS_16210_SPI_USE_SECOND_DATAPATH)
    #define ADIS_16210_SPI_AUX_CONTROLDP1     (ADIS_16210_SPI_AUX_CONTROL_DP1_REG)
#endif /* (ADIS_16210_SPI_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define ADIS_16210_SPI_STS_SPI_DONE_SHIFT             (0x00u)
#define ADIS_16210_SPI_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define ADIS_16210_SPI_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define ADIS_16210_SPI_STS_SPI_IDLE_SHIFT             (0x04u)
#define ADIS_16210_SPI_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define ADIS_16210_SPI_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define ADIS_16210_SPI_STS_SPI_DONE           ((uint8) (0x01u << ADIS_16210_SPI_STS_SPI_DONE_SHIFT))
#define ADIS_16210_SPI_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << ADIS_16210_SPI_STS_TX_FIFO_EMPTY_SHIFT))
#define ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << ADIS_16210_SPI_STS_TX_FIFO_NOT_FULL_SHIFT))
#define ADIS_16210_SPI_STS_BYTE_COMPLETE      ((uint8) (0x01u << ADIS_16210_SPI_STS_BYTE_COMPLETE_SHIFT))
#define ADIS_16210_SPI_STS_SPI_IDLE           ((uint8) (0x01u << ADIS_16210_SPI_STS_SPI_IDLE_SHIFT))
#define ADIS_16210_SPI_STS_RX_FIFO_FULL       ((uint8) (0x01u << ADIS_16210_SPI_STS_RX_FIFO_FULL_SHIFT))
#define ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << ADIS_16210_SPI_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define ADIS_16210_SPI_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << ADIS_16210_SPI_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define ADIS_16210_SPI_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define ADIS_16210_SPI_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define ADIS_16210_SPI_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define ADIS_16210_SPI_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define ADIS_16210_SPI_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define ADIS_16210_SPI_FIFO_CLR       (ADIS_16210_SPI_TX_FIFO_CLR | ADIS_16210_SPI_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define ADIS_16210_SPI_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define ADIS_16210_SPI_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define ADIS_16210_SPI_AUX_CTRL_FIFO0_CLR         (0x01u)
#define ADIS_16210_SPI_AUX_CTRL_FIFO1_CLR         (0x02u)
#define ADIS_16210_SPI_AUX_CTRL_FIFO0_LVL         (0x04u)
#define ADIS_16210_SPI_AUX_CTRL_FIFO1_LVL         (0x08u)
#define ADIS_16210_SPI_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define ADIS_16210_SPI_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define ADIS_16210_SPI_IS_ENABLED (0u != (ADIS_16210_SPI_TX_STATUS_ACTL_REG & ADIS_16210_SPI_INT_ENABLE))

/* Retuns TX status register */
#define ADIS_16210_SPI_GET_STATUS_TX(swTxSts) ( (uint8)(ADIS_16210_SPI_TX_STATUS_REG | \
                                                          ((swTxSts) & ADIS_16210_SPI_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define ADIS_16210_SPI_GET_STATUS_RX(swRxSts) ( (uint8)(ADIS_16210_SPI_RX_STATUS_REG | \
                                                          ((swRxSts) & ADIS_16210_SPI_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
*       Obsolete definitions
***************************************/

/* Following definitions are for version compatibility.
*  They are obsolete in SPIM v2_30.
*  Please do not use it in new projects
*/

#define ADIS_16210_SPI_WriteByte   ADIS_16210_SPI_WriteTxData
#define ADIS_16210_SPI_ReadByte    ADIS_16210_SPI_ReadRxData
void  ADIS_16210_SPI_SetInterruptMode(uint8 intSrc)       ;
uint8 ADIS_16210_SPI_ReadStatus(void)                     ;
void  ADIS_16210_SPI_EnableInt(void)                      ;
void  ADIS_16210_SPI_DisableInt(void)                     ;

/* Obsolete register names. Not to be used in new designs */
#define ADIS_16210_SPI_TXDATA                 (ADIS_16210_SPI_TXDATA_REG)
#define ADIS_16210_SPI_RXDATA                 (ADIS_16210_SPI_RXDATA_REG)
#define ADIS_16210_SPI_AUX_CONTROLDP0         (ADIS_16210_SPI_AUX_CONTROL_DP0_REG)
#define ADIS_16210_SPI_TXBUFFERREAD           (ADIS_16210_SPI_txBufferRead)
#define ADIS_16210_SPI_TXBUFFERWRITE          (ADIS_16210_SPI_txBufferWrite)
#define ADIS_16210_SPI_RXBUFFERREAD           (ADIS_16210_SPI_rxBufferRead)
#define ADIS_16210_SPI_RXBUFFERWRITE          (ADIS_16210_SPI_rxBufferWrite)

#define ADIS_16210_SPI_COUNTER_PERIOD         (ADIS_16210_SPI_COUNTER_PERIOD_REG)
#define ADIS_16210_SPI_COUNTER_CONTROL        (ADIS_16210_SPI_COUNTER_CONTROL_REG)
#define ADIS_16210_SPI_STATUS                 (ADIS_16210_SPI_TX_STATUS_REG)
#define ADIS_16210_SPI_CONTROL                (ADIS_16210_SPI_CONTROL_REG)
#define ADIS_16210_SPI_STATUS_MASK            (ADIS_16210_SPI_TX_STATUS_MASK_REG)
#define ADIS_16210_SPI_STATUS_ACTL            (ADIS_16210_SPI_TX_STATUS_ACTL_REG)

#define ADIS_16210_SPI_INIT_INTERRUPTS_MASK  (ADIS_16210_SPI_INT_ON_SPI_DONE     | \
                                                ADIS_16210_SPI_INT_ON_TX_EMPTY     | \
                                                ADIS_16210_SPI_INT_ON_TX_NOT_FULL_DEF  | \
                                                ADIS_16210_SPI_INT_ON_RX_FULL      | \
                                                ADIS_16210_SPI_INT_ON_RX_NOT_EMPTY | \
                                                ADIS_16210_SPI_INT_ON_RX_OVER      | \
                                                ADIS_16210_SPI_INT_ON_BYTE_COMP)
                                                
/* Following definitions are for version Compatibility.
*  They are obsolete in SPIM v2_40.
*  Please do not use it in new projects
*/

#define ADIS_16210_SPI_DataWidth                  (ADIS_16210_SPI_DATA_WIDTH)
#define ADIS_16210_SPI_InternalClockUsed          (ADIS_16210_SPI_INTERNAL_CLOCK)
#define ADIS_16210_SPI_InternalTxInterruptEnabled (ADIS_16210_SPI_INTERNAL_TX_INT_ENABLED)
#define ADIS_16210_SPI_InternalRxInterruptEnabled (ADIS_16210_SPI_INTERNAL_RX_INT_ENABLED)
#define ADIS_16210_SPI_ModeUseZero                (ADIS_16210_SPI_MODE_USE_ZERO)
#define ADIS_16210_SPI_BidirectionalMode          (ADIS_16210_SPI_BIDIRECTIONAL_MODE)
#define ADIS_16210_SPI_Mode                       (ADIS_16210_SPI_MODE)
#define ADIS_16210_SPI_DATAWIDHT                  (ADIS_16210_SPI_DATA_WIDTH)
#define ADIS_16210_SPI_InternalInterruptEnabled   (0u)

#define ADIS_16210_SPI_TXBUFFERSIZE   (ADIS_16210_SPI_TX_BUFFER_SIZE)
#define ADIS_16210_SPI_RXBUFFERSIZE   (ADIS_16210_SPI_RX_BUFFER_SIZE)

#define ADIS_16210_SPI_TXBUFFER       ADIS_16210_SPI_txBuffer
#define ADIS_16210_SPI_RXBUFFER       ADIS_16210_SPI_rxBuffer

#endif /* (CY_SPIM_ADIS_16210_SPI_H) */


/* [] END OF FILE */
