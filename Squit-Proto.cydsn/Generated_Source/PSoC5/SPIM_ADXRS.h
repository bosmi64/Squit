/*******************************************************************************
* File Name: SPIM_ADXRS.h
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

#if !defined(CY_SPIM_SPIM_ADXRS_H)
#define CY_SPIM_SPIM_ADXRS_H

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

#define SPIM_ADXRS_INTERNAL_CLOCK             (0u)

#if(0u != SPIM_ADXRS_INTERNAL_CLOCK)
    #include "SPIM_ADXRS_IntClock.h"
#endif /* (0u != SPIM_ADXRS_INTERNAL_CLOCK) */

#define SPIM_ADXRS_MODE                       (1u)
#define SPIM_ADXRS_DATA_WIDTH                 (16u)
#define SPIM_ADXRS_MODE_USE_ZERO              (1u)
#define SPIM_ADXRS_BIDIRECTIONAL_MODE         (0u)

/* Internal interrupt handling */
#define SPIM_ADXRS_TX_BUFFER_SIZE             (4u)
#define SPIM_ADXRS_RX_BUFFER_SIZE             (4u)
#define SPIM_ADXRS_INTERNAL_TX_INT_ENABLED    (0u)
#define SPIM_ADXRS_INTERNAL_RX_INT_ENABLED    (0u)

#define SPIM_ADXRS_SINGLE_REG_SIZE            (8u)
#define SPIM_ADXRS_USE_SECOND_DATAPATH        (SPIM_ADXRS_DATA_WIDTH > SPIM_ADXRS_SINGLE_REG_SIZE)

#define SPIM_ADXRS_FIFO_SIZE                  (4u)
#define SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED    ((0u != SPIM_ADXRS_INTERNAL_TX_INT_ENABLED) && \
                                                     (SPIM_ADXRS_TX_BUFFER_SIZE > SPIM_ADXRS_FIFO_SIZE))

#define SPIM_ADXRS_RX_SOFTWARE_BUF_ENABLED    ((0u != SPIM_ADXRS_INTERNAL_RX_INT_ENABLED) && \
                                                     (SPIM_ADXRS_RX_BUFFER_SIZE > SPIM_ADXRS_FIFO_SIZE))


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

} SPIM_ADXRS_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIM_ADXRS_Init(void)                           ;
void  SPIM_ADXRS_Enable(void)                         ;
void  SPIM_ADXRS_Start(void)                          ;
void  SPIM_ADXRS_Stop(void)                           ;

void  SPIM_ADXRS_EnableTxInt(void)                    ;
void  SPIM_ADXRS_EnableRxInt(void)                    ;
void  SPIM_ADXRS_DisableTxInt(void)                   ;
void  SPIM_ADXRS_DisableRxInt(void)                   ;

void  SPIM_ADXRS_Sleep(void)                          ;
void  SPIM_ADXRS_Wakeup(void)                         ;
void  SPIM_ADXRS_SaveConfig(void)                     ;
void  SPIM_ADXRS_RestoreConfig(void)                  ;

void  SPIM_ADXRS_SetTxInterruptMode(uint8 intSrc)     ;
void  SPIM_ADXRS_SetRxInterruptMode(uint8 intSrc)     ;
uint8 SPIM_ADXRS_ReadTxStatus(void)                   ;
uint8 SPIM_ADXRS_ReadRxStatus(void)                   ;
void  SPIM_ADXRS_WriteTxData(uint16 txData)  \
                                                            ;
uint16 SPIM_ADXRS_ReadRxData(void) \
                                                            ;
uint8 SPIM_ADXRS_GetRxBufferSize(void)                ;
uint8 SPIM_ADXRS_GetTxBufferSize(void)                ;
void  SPIM_ADXRS_ClearRxBuffer(void)                  ;
void  SPIM_ADXRS_ClearTxBuffer(void)                  ;
void  SPIM_ADXRS_ClearFIFO(void)                              ;
void  SPIM_ADXRS_PutArray(const uint16 buffer[], uint8 byteCount) \
                                                            ;

#if(0u != SPIM_ADXRS_BIDIRECTIONAL_MODE)
    void  SPIM_ADXRS_TxEnable(void)                   ;
    void  SPIM_ADXRS_TxDisable(void)                  ;
#endif /* (0u != SPIM_ADXRS_BIDIRECTIONAL_MODE) */

CY_ISR_PROTO(SPIM_ADXRS_TX_ISR);
CY_ISR_PROTO(SPIM_ADXRS_RX_ISR);


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 SPIM_ADXRS_initVar;


/***************************************
*           API Constants
***************************************/

#define SPIM_ADXRS_TX_ISR_NUMBER     ((uint8) (SPIM_ADXRS_TxInternalInterrupt__INTC_NUMBER))
#define SPIM_ADXRS_RX_ISR_NUMBER     ((uint8) (SPIM_ADXRS_RxInternalInterrupt__INTC_NUMBER))

#define SPIM_ADXRS_TX_ISR_PRIORITY   ((uint8) (SPIM_ADXRS_TxInternalInterrupt__INTC_PRIOR_NUM))
#define SPIM_ADXRS_RX_ISR_PRIORITY   ((uint8) (SPIM_ADXRS_RxInternalInterrupt__INTC_PRIOR_NUM))


/***************************************
*    Initial Parameter Constants
***************************************/

#define SPIM_ADXRS_INT_ON_SPI_DONE    ((uint8) (0u   << SPIM_ADXRS_STS_SPI_DONE_SHIFT))
#define SPIM_ADXRS_INT_ON_TX_EMPTY    ((uint8) (0u   << SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT))
#define SPIM_ADXRS_INT_ON_TX_NOT_FULL ((uint8) (0u << \
                                                                           SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SPIM_ADXRS_INT_ON_BYTE_COMP   ((uint8) (0u  << SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT))
#define SPIM_ADXRS_INT_ON_SPI_IDLE    ((uint8) (0u   << SPIM_ADXRS_STS_SPI_IDLE_SHIFT))

/* Disable TX_NOT_FULL if software buffer is used */
#define SPIM_ADXRS_INT_ON_TX_NOT_FULL_DEF ((SPIM_ADXRS_TX_SOFTWARE_BUF_ENABLED) ? \
                                                                        (0u) : (SPIM_ADXRS_INT_ON_TX_NOT_FULL))

/* TX interrupt mask */
#define SPIM_ADXRS_TX_INIT_INTERRUPTS_MASK    (SPIM_ADXRS_INT_ON_SPI_DONE  | \
                                                     SPIM_ADXRS_INT_ON_TX_EMPTY  | \
                                                     SPIM_ADXRS_INT_ON_TX_NOT_FULL_DEF | \
                                                     SPIM_ADXRS_INT_ON_BYTE_COMP | \
                                                     SPIM_ADXRS_INT_ON_SPI_IDLE)

#define SPIM_ADXRS_INT_ON_RX_FULL         ((uint8) (0u << \
                                                                          SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT))
#define SPIM_ADXRS_INT_ON_RX_NOT_EMPTY    ((uint8) (0u << \
                                                                          SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SPIM_ADXRS_INT_ON_RX_OVER         ((uint8) (0u << \
                                                                          SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT))

/* RX interrupt mask */
#define SPIM_ADXRS_RX_INIT_INTERRUPTS_MASK    (SPIM_ADXRS_INT_ON_RX_FULL      | \
                                                     SPIM_ADXRS_INT_ON_RX_NOT_EMPTY | \
                                                     SPIM_ADXRS_INT_ON_RX_OVER)
/* Nubmer of bits to receive/transmit */
#define SPIM_ADXRS_BITCTR_INIT            (((uint8) (SPIM_ADXRS_DATA_WIDTH << 1u)) - 1u)


/***************************************
*             Registers
***************************************/

#if(CY_PSOC3 || CY_PSOC5)
    #define SPIM_ADXRS_TXDATA_REG (* (reg16 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
    #define SPIM_ADXRS_TXDATA_PTR (  (reg16 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
    #define SPIM_ADXRS_RXDATA_REG (* (reg16 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)
    #define SPIM_ADXRS_RXDATA_PTR (  (reg16 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)
#else   /* PSOC4 */
    #if(SPIM_ADXRS_USE_SECOND_DATAPATH)
        #define SPIM_ADXRS_TXDATA_REG (* (reg16 *) \
                                          SPIM_ADXRS_BSPIM_sR16_Dp_u0__16BIT_F0_REG)
        #define SPIM_ADXRS_TXDATA_PTR (  (reg16 *) \
                                          SPIM_ADXRS_BSPIM_sR16_Dp_u0__16BIT_F0_REG)
        #define SPIM_ADXRS_RXDATA_REG (* (reg16 *) \
                                          SPIM_ADXRS_BSPIM_sR16_Dp_u0__16BIT_F1_REG)
        #define SPIM_ADXRS_RXDATA_PTR         (  (reg16 *) \
                                          SPIM_ADXRS_BSPIM_sR16_Dp_u0__16BIT_F1_REG)
    #else
        #define SPIM_ADXRS_TXDATA_REG (* (reg8 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
        #define SPIM_ADXRS_TXDATA_PTR (  (reg8 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F0_REG)
        #define SPIM_ADXRS_RXDATA_REG (* (reg8 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)
        #define SPIM_ADXRS_RXDATA_PTR (  (reg8 *) \
                                                SPIM_ADXRS_BSPIM_sR16_Dp_u0__F1_REG)
    #endif /* (SPIM_ADXRS_USE_SECOND_DATAPATH) */
#endif     /* (CY_PSOC3 || CY_PSOC5) */

#define SPIM_ADXRS_AUX_CONTROL_DP0_REG (* (reg8 *) \
                                        SPIM_ADXRS_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)
#define SPIM_ADXRS_AUX_CONTROL_DP0_PTR (  (reg8 *) \
                                        SPIM_ADXRS_BSPIM_sR16_Dp_u0__DP_AUX_CTL_REG)

#if(SPIM_ADXRS_USE_SECOND_DATAPATH)
    #define SPIM_ADXRS_AUX_CONTROL_DP1_REG  (* (reg8 *) \
                                        SPIM_ADXRS_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
    #define SPIM_ADXRS_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
                                        SPIM_ADXRS_BSPIM_sR16_Dp_u1__DP_AUX_CTL_REG)
#endif /* (SPIM_ADXRS_USE_SECOND_DATAPATH) */

#define SPIM_ADXRS_COUNTER_PERIOD_REG     (* (reg8 *) SPIM_ADXRS_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_ADXRS_COUNTER_PERIOD_PTR     (  (reg8 *) SPIM_ADXRS_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_ADXRS_COUNTER_CONTROL_REG    (* (reg8 *) SPIM_ADXRS_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIM_ADXRS_COUNTER_CONTROL_PTR    (  (reg8 *) SPIM_ADXRS_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIM_ADXRS_TX_STATUS_REG          (* (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_ADXRS_TX_STATUS_PTR          (  (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_ADXRS_RX_STATUS_REG          (* (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__STATUS_REG)
#define SPIM_ADXRS_RX_STATUS_PTR          (  (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__STATUS_REG)

#define SPIM_ADXRS_CONTROL_REG            (* (reg8 *) \
                                      SPIM_ADXRS_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
#define SPIM_ADXRS_CONTROL_PTR            (  (reg8 *) \
                                      SPIM_ADXRS_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)

#define SPIM_ADXRS_TX_STATUS_MASK_REG     (* (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__MASK_REG)
#define SPIM_ADXRS_TX_STATUS_MASK_PTR     (  (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__MASK_REG)
#define SPIM_ADXRS_RX_STATUS_MASK_REG     (* (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__MASK_REG)
#define SPIM_ADXRS_RX_STATUS_MASK_PTR     (  (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__MASK_REG)

#define SPIM_ADXRS_TX_STATUS_ACTL_REG     (* (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_TX_STATUS_ACTL_PTR     (  (reg8 *) SPIM_ADXRS_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_RX_STATUS_ACTL_REG     (* (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_ADXRS_RX_STATUS_ACTL_PTR     (  (reg8 *) SPIM_ADXRS_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

#if(SPIM_ADXRS_USE_SECOND_DATAPATH)
    #define SPIM_ADXRS_AUX_CONTROLDP1     (SPIM_ADXRS_AUX_CONTROL_DP1_REG)
#endif /* (SPIM_ADXRS_USE_SECOND_DATAPATH) */


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SPIM_ADXRS_STS_SPI_DONE_SHIFT             (0x00u)
#define SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define SPIM_ADXRS_STS_SPI_IDLE_SHIFT             (0x04u)
#define SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define SPIM_ADXRS_STS_SPI_DONE           ((uint8) (0x01u << SPIM_ADXRS_STS_SPI_DONE_SHIFT))
#define SPIM_ADXRS_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << SPIM_ADXRS_STS_TX_FIFO_EMPTY_SHIFT))
#define SPIM_ADXRS_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << SPIM_ADXRS_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SPIM_ADXRS_STS_BYTE_COMPLETE      ((uint8) (0x01u << SPIM_ADXRS_STS_BYTE_COMPLETE_SHIFT))
#define SPIM_ADXRS_STS_SPI_IDLE           ((uint8) (0x01u << SPIM_ADXRS_STS_SPI_IDLE_SHIFT))
#define SPIM_ADXRS_STS_RX_FIFO_FULL       ((uint8) (0x01u << SPIM_ADXRS_STS_RX_FIFO_FULL_SHIFT))
#define SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << SPIM_ADXRS_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SPIM_ADXRS_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << SPIM_ADXRS_STS_RX_FIFO_OVERRUN_SHIFT))

/* TX and RX masks for clear on read bits */
#define SPIM_ADXRS_TX_STS_CLR_ON_RD_BYTES_MASK    (0x09u)
#define SPIM_ADXRS_RX_STS_CLR_ON_RD_BYTES_MASK    (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_ADXRS_INT_ENABLE     (0x10u) /* Enable interrupt from statusi */
#define SPIM_ADXRS_TX_FIFO_CLR    (0x01u) /* F0 - TX FIFO */
#define SPIM_ADXRS_RX_FIFO_CLR    (0x02u) /* F1 - RX FIFO */
#define SPIM_ADXRS_FIFO_CLR       (SPIM_ADXRS_TX_FIFO_CLR | SPIM_ADXRS_RX_FIFO_CLR)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_ADXRS_CNTR_ENABLE    (0x20u) /* Enable CNT7 */

/* Bi-Directional mode control bit */
#define SPIM_ADXRS_CTRL_TX_SIGNAL_EN  (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIM_ADXRS_AUX_CTRL_FIFO0_CLR         (0x01u)
#define SPIM_ADXRS_AUX_CTRL_FIFO1_CLR         (0x02u)
#define SPIM_ADXRS_AUX_CTRL_FIFO0_LVL         (0x04u)
#define SPIM_ADXRS_AUX_CTRL_FIFO1_LVL         (0x08u)
#define SPIM_ADXRS_STATUS_ACTL_INT_EN_MASK    (0x10u)

/* Component disabled */
#define SPIM_ADXRS_DISABLED   (0u)


/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define SPIM_ADXRS_IS_ENABLED (0u != (SPIM_ADXRS_TX_STATUS_ACTL_REG & SPIM_ADXRS_INT_ENABLE))

/* Retuns TX status register */
#define SPIM_ADXRS_GET_STATUS_TX(swTxSts) ( (uint8)(SPIM_ADXRS_TX_STATUS_REG | \
                                                          ((swTxSts) & SPIM_ADXRS_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define SPIM_ADXRS_GET_STATUS_RX(swRxSts) ( (uint8)(SPIM_ADXRS_RX_STATUS_REG | \
                                                          ((swRxSts) & SPIM_ADXRS_RX_STS_CLR_ON_RD_BYTES_MASK)) )


/***************************************
*       Obsolete definitions
***************************************/

/* Following definitions are for version compatibility.
*  They are obsolete in SPIM v2_30.
*  Please do not use it in new projects
*/

#define SPIM_ADXRS_WriteByte   SPIM_ADXRS_WriteTxData
#define SPIM_ADXRS_ReadByte    SPIM_ADXRS_ReadRxData
void  SPIM_ADXRS_SetInterruptMode(uint8 intSrc)       ;
uint8 SPIM_ADXRS_ReadStatus(void)                     ;
void  SPIM_ADXRS_EnableInt(void)                      ;
void  SPIM_ADXRS_DisableInt(void)                     ;

/* Obsolete register names. Not to be used in new designs */
#define SPIM_ADXRS_TXDATA                 (SPIM_ADXRS_TXDATA_REG)
#define SPIM_ADXRS_RXDATA                 (SPIM_ADXRS_RXDATA_REG)
#define SPIM_ADXRS_AUX_CONTROLDP0         (SPIM_ADXRS_AUX_CONTROL_DP0_REG)
#define SPIM_ADXRS_TXBUFFERREAD           (SPIM_ADXRS_txBufferRead)
#define SPIM_ADXRS_TXBUFFERWRITE          (SPIM_ADXRS_txBufferWrite)
#define SPIM_ADXRS_RXBUFFERREAD           (SPIM_ADXRS_rxBufferRead)
#define SPIM_ADXRS_RXBUFFERWRITE          (SPIM_ADXRS_rxBufferWrite)

#define SPIM_ADXRS_COUNTER_PERIOD         (SPIM_ADXRS_COUNTER_PERIOD_REG)
#define SPIM_ADXRS_COUNTER_CONTROL        (SPIM_ADXRS_COUNTER_CONTROL_REG)
#define SPIM_ADXRS_STATUS                 (SPIM_ADXRS_TX_STATUS_REG)
#define SPIM_ADXRS_CONTROL                (SPIM_ADXRS_CONTROL_REG)
#define SPIM_ADXRS_STATUS_MASK            (SPIM_ADXRS_TX_STATUS_MASK_REG)
#define SPIM_ADXRS_STATUS_ACTL            (SPIM_ADXRS_TX_STATUS_ACTL_REG)

#define SPIM_ADXRS_INIT_INTERRUPTS_MASK  (SPIM_ADXRS_INT_ON_SPI_DONE     | \
                                                SPIM_ADXRS_INT_ON_TX_EMPTY     | \
                                                SPIM_ADXRS_INT_ON_TX_NOT_FULL_DEF  | \
                                                SPIM_ADXRS_INT_ON_RX_FULL      | \
                                                SPIM_ADXRS_INT_ON_RX_NOT_EMPTY | \
                                                SPIM_ADXRS_INT_ON_RX_OVER      | \
                                                SPIM_ADXRS_INT_ON_BYTE_COMP)
                                                
/* Following definitions are for version Compatibility.
*  They are obsolete in SPIM v2_40.
*  Please do not use it in new projects
*/

#define SPIM_ADXRS_DataWidth                  (SPIM_ADXRS_DATA_WIDTH)
#define SPIM_ADXRS_InternalClockUsed          (SPIM_ADXRS_INTERNAL_CLOCK)
#define SPIM_ADXRS_InternalTxInterruptEnabled (SPIM_ADXRS_INTERNAL_TX_INT_ENABLED)
#define SPIM_ADXRS_InternalRxInterruptEnabled (SPIM_ADXRS_INTERNAL_RX_INT_ENABLED)
#define SPIM_ADXRS_ModeUseZero                (SPIM_ADXRS_MODE_USE_ZERO)
#define SPIM_ADXRS_BidirectionalMode          (SPIM_ADXRS_BIDIRECTIONAL_MODE)
#define SPIM_ADXRS_Mode                       (SPIM_ADXRS_MODE)
#define SPIM_ADXRS_DATAWIDHT                  (SPIM_ADXRS_DATA_WIDTH)
#define SPIM_ADXRS_InternalInterruptEnabled   (0u)

#define SPIM_ADXRS_TXBUFFERSIZE   (SPIM_ADXRS_TX_BUFFER_SIZE)
#define SPIM_ADXRS_RXBUFFERSIZE   (SPIM_ADXRS_RX_BUFFER_SIZE)

#define SPIM_ADXRS_TXBUFFER       SPIM_ADXRS_txBuffer
#define SPIM_ADXRS_RXBUFFER       SPIM_ADXRS_rxBuffer

#endif /* (CY_SPIM_SPIM_ADXRS_H) */


/* [] END OF FILE */
