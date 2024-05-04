/*******************************************************************************
* File Name: UART_IMU.h
* Version 2.30
*
* Description:
*  Contains the function prototypes and constants available to the UART
*  user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_UART_UART_IMU_H)
#define CY_UART_UART_IMU_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

#define UART_IMU_RX_ENABLED                     (1u)
#define UART_IMU_TX_ENABLED                     (1u)
#define UART_IMU_HD_ENABLED                     (0u)
#define UART_IMU_RX_INTERRUPT_ENABLED           (1u)
#define UART_IMU_TX_INTERRUPT_ENABLED           (0u)
#define UART_IMU_INTERNAL_CLOCK_USED            (1u)
#define UART_IMU_RXHW_ADDRESS_ENABLED           (0u)
#define UART_IMU_OVER_SAMPLE_COUNT              (8u)
#define UART_IMU_PARITY_TYPE                    (0u)
#define UART_IMU_PARITY_TYPE_SW                 (0u)
#define UART_IMU_BREAK_DETECT                   (0u)
#define UART_IMU_BREAK_BITS_TX                  (13u)
#define UART_IMU_BREAK_BITS_RX                  (13u)
#define UART_IMU_TXCLKGEN_DP                    (1u)
#define UART_IMU_USE23POLLING                   (0u)
#define UART_IMU_FLOW_CONTROL                   (0u)
#define UART_IMU_CLK_FREQ                       (0u)
#define UART_IMU_TXBUFFERSIZE                   (4u)
#define UART_IMU_RXBUFFERSIZE                   (255u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#ifdef UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_IMU_CONTROL_REG_REMOVED            (0u)
#else
    #define UART_IMU_CONTROL_REG_REMOVED            (1u)
#endif /* End UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct UART_IMU_backupStruct_
{
    uint8 enableState;

    #if(UART_IMU_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End UART_IMU_CONTROL_REG_REMOVED */
    #if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )
        uint8 rx_period;
        #if (CY_UDB_V0)
            uint8 rx_mask;
            #if (UART_IMU_RXHW_ADDRESS_ENABLED)
                uint8 rx_addr1;
                uint8 rx_addr2;
            #endif /* End UART_IMU_RXHW_ADDRESS_ENABLED */
        #endif /* End CY_UDB_V0 */
    #endif  /* End (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED)*/

    #if(UART_IMU_TX_ENABLED)
        #if(UART_IMU_TXCLKGEN_DP)
            uint8 tx_clk_ctr;
            #if (CY_UDB_V0)
                uint8 tx_clk_compl;
            #endif  /* End CY_UDB_V0 */
        #else
            uint8 tx_period;
        #endif /*End UART_IMU_TXCLKGEN_DP */
        #if (CY_UDB_V0)
            uint8 tx_mask;
        #endif  /* End CY_UDB_V0 */
    #endif /*End UART_IMU_TX_ENABLED */
} UART_IMU_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void UART_IMU_Start(void) ;
void UART_IMU_Stop(void) ;
uint8 UART_IMU_ReadControlRegister(void) ;
void UART_IMU_WriteControlRegister(uint8 control) ;

void UART_IMU_Init(void) ;
void UART_IMU_Enable(void) ;
void UART_IMU_SaveConfig(void) ;
void UART_IMU_RestoreConfig(void) ;
void UART_IMU_Sleep(void) ;
void UART_IMU_Wakeup(void) ;

/* Only if RX is enabled */
#if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )

    #if(UART_IMU_RX_INTERRUPT_ENABLED)
        void  UART_IMU_EnableRxInt(void) ;
        void  UART_IMU_DisableRxInt(void) ;
        CY_ISR_PROTO(UART_IMU_RXISR);
    #endif /* UART_IMU_RX_INTERRUPT_ENABLED */

    void UART_IMU_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void UART_IMU_SetRxAddress1(uint8 address) ;
    void UART_IMU_SetRxAddress2(uint8 address) ;

    void  UART_IMU_SetRxInterruptMode(uint8 intSrc) ;
    uint8 UART_IMU_ReadRxData(void) ;
    uint8 UART_IMU_ReadRxStatus(void) ;
    uint8 UART_IMU_GetChar(void) ;
    uint16 UART_IMU_GetByte(void) ;
    uint8 UART_IMU_GetRxBufferSize(void)
                                                            ;
    void UART_IMU_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define UART_IMU_GetRxInterruptSource   UART_IMU_ReadRxStatus

#endif /* End (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) */

/* Only if TX is enabled */
#if(UART_IMU_TX_ENABLED || UART_IMU_HD_ENABLED)

    #if(UART_IMU_TX_INTERRUPT_ENABLED)
        void UART_IMU_EnableTxInt(void) ;
        void UART_IMU_DisableTxInt(void) ;
        CY_ISR_PROTO(UART_IMU_TXISR);
    #endif /* UART_IMU_TX_INTERRUPT_ENABLED */

    void UART_IMU_SetTxInterruptMode(uint8 intSrc) ;
    void UART_IMU_WriteTxData(uint8 txDataByte) ;
    uint8 UART_IMU_ReadTxStatus(void) ;
    void UART_IMU_PutChar(uint8 txDataByte) ;
    void UART_IMU_PutString(const char8 string[]) ;
    void UART_IMU_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void UART_IMU_PutCRLF(uint8 txDataByte) ;
    void UART_IMU_ClearTxBuffer(void) ;
    void UART_IMU_SetTxAddressMode(uint8 addressMode) ;
    void UART_IMU_SendBreak(uint8 retMode) ;
    uint8 UART_IMU_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define UART_IMU_PutStringConst         UART_IMU_PutString
    #define UART_IMU_PutArrayConst          UART_IMU_PutArray
    #define UART_IMU_GetTxInterruptSource   UART_IMU_ReadTxStatus

#endif /* End UART_IMU_TX_ENABLED || UART_IMU_HD_ENABLED */

#if(UART_IMU_HD_ENABLED)
    void UART_IMU_LoadRxConfig(void) ;
    void UART_IMU_LoadTxConfig(void) ;
#endif /* End UART_IMU_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_IMU) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    UART_IMU_CyBtldrCommStart(void) CYSMALL ;
    void    UART_IMU_CyBtldrCommStop(void) CYSMALL ;
    void    UART_IMU_CyBtldrCommReset(void) CYSMALL ;
    cystatus UART_IMU_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus UART_IMU_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_IMU)
        #define CyBtldrCommStart    UART_IMU_CyBtldrCommStart
        #define CyBtldrCommStop     UART_IMU_CyBtldrCommStop
        #define CyBtldrCommReset    UART_IMU_CyBtldrCommReset
        #define CyBtldrCommWrite    UART_IMU_CyBtldrCommWrite
        #define CyBtldrCommRead     UART_IMU_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_IMU) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define UART_IMU_BYTE2BYTE_TIME_OUT (25u)

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define UART_IMU_SET_SPACE                              (0x00u)
#define UART_IMU_SET_MARK                               (0x01u)

/* Status Register definitions */
#if( (UART_IMU_TX_ENABLED) || (UART_IMU_HD_ENABLED) )
    #if(UART_IMU_TX_INTERRUPT_ENABLED)
        #define UART_IMU_TX_VECT_NUM            (uint8)UART_IMU_TXInternalInterrupt__INTC_NUMBER
        #define UART_IMU_TX_PRIOR_NUM           (uint8)UART_IMU_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_IMU_TX_INTERRUPT_ENABLED */
    #if(UART_IMU_TX_ENABLED)
        #define UART_IMU_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define UART_IMU_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define UART_IMU_TX_STS_FIFO_FULL_SHIFT         (0x02u)
        #define UART_IMU_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* UART_IMU_TX_ENABLED */
    #if(UART_IMU_HD_ENABLED)
        #define UART_IMU_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define UART_IMU_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define UART_IMU_TX_STS_FIFO_FULL_SHIFT         (0x05u)  /*needs MD=0*/
        #define UART_IMU_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* UART_IMU_HD_ENABLED */
    #define UART_IMU_TX_STS_COMPLETE            (uint8)(0x01u << UART_IMU_TX_STS_COMPLETE_SHIFT)
    #define UART_IMU_TX_STS_FIFO_EMPTY          (uint8)(0x01u << UART_IMU_TX_STS_FIFO_EMPTY_SHIFT)
    #define UART_IMU_TX_STS_FIFO_FULL           (uint8)(0x01u << UART_IMU_TX_STS_FIFO_FULL_SHIFT)
    #define UART_IMU_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << UART_IMU_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (UART_IMU_TX_ENABLED) || (UART_IMU_HD_ENABLED)*/

#if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )
    #if(UART_IMU_RX_INTERRUPT_ENABLED)
        #define UART_IMU_RX_VECT_NUM            (uint8)UART_IMU_RXInternalInterrupt__INTC_NUMBER
        #define UART_IMU_RX_PRIOR_NUM           (uint8)UART_IMU_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* UART_IMU_RX_INTERRUPT_ENABLED */
    #define UART_IMU_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define UART_IMU_RX_STS_BREAK_SHIFT             (0x01u)
    #define UART_IMU_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define UART_IMU_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define UART_IMU_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define UART_IMU_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define UART_IMU_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define UART_IMU_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define UART_IMU_RX_STS_MRKSPC           (uint8)(0x01u << UART_IMU_RX_STS_MRKSPC_SHIFT)
    #define UART_IMU_RX_STS_BREAK            (uint8)(0x01u << UART_IMU_RX_STS_BREAK_SHIFT)
    #define UART_IMU_RX_STS_PAR_ERROR        (uint8)(0x01u << UART_IMU_RX_STS_PAR_ERROR_SHIFT)
    #define UART_IMU_RX_STS_STOP_ERROR       (uint8)(0x01u << UART_IMU_RX_STS_STOP_ERROR_SHIFT)
    #define UART_IMU_RX_STS_OVERRUN          (uint8)(0x01u << UART_IMU_RX_STS_OVERRUN_SHIFT)
    #define UART_IMU_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << UART_IMU_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define UART_IMU_RX_STS_ADDR_MATCH       (uint8)(0x01u << UART_IMU_RX_STS_ADDR_MATCH_SHIFT)
    #define UART_IMU_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << UART_IMU_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define UART_IMU_RX_HW_MASK                     (0x7Fu)
#endif /* End (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) */

/* Control Register definitions */
#define UART_IMU_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define UART_IMU_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define UART_IMU_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define UART_IMU_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define UART_IMU_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define UART_IMU_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define UART_IMU_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define UART_IMU_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define UART_IMU_CTRL_HD_SEND               (uint8)(0x01u << UART_IMU_CTRL_HD_SEND_SHIFT)
#define UART_IMU_CTRL_HD_SEND_BREAK         (uint8)(0x01u << UART_IMU_CTRL_HD_SEND_BREAK_SHIFT)
#define UART_IMU_CTRL_MARK                  (uint8)(0x01u << UART_IMU_CTRL_MARK_SHIFT)
#define UART_IMU_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << UART_IMU_CTRL_PARITY_TYPE0_SHIFT)
#define UART_IMU_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << UART_IMU_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define UART_IMU_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define UART_IMU_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define UART_IMU_SEND_BREAK                         (0x00u)
#define UART_IMU_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define UART_IMU_REINIT                             (0x02u)
#define UART_IMU_SEND_WAIT_REINIT                   (0x03u)

#define UART_IMU_OVER_SAMPLE_8                      (8u)
#define UART_IMU_OVER_SAMPLE_16                     (16u)

#define UART_IMU_BIT_CENTER                         (UART_IMU_OVER_SAMPLE_COUNT - 1u)

#define UART_IMU_FIFO_LENGTH                        (4u)
#define UART_IMU_NUMBER_OF_START_BIT                (1u)
#define UART_IMU_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation*/
#define UART_IMU_TXBITCTR_BREAKBITS8X   ((UART_IMU_BREAK_BITS_TX * UART_IMU_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation*/
#define UART_IMU_TXBITCTR_BREAKBITS ((UART_IMU_BREAK_BITS_TX * UART_IMU_OVER_SAMPLE_COUNT) - 1u)

#define UART_IMU_HALF_BIT_COUNT   \
                            (((UART_IMU_OVER_SAMPLE_COUNT / 2u) + (UART_IMU_USE23POLLING * 1u)) - 2u)
#if (UART_IMU_OVER_SAMPLE_COUNT == UART_IMU_OVER_SAMPLE_8)
    #define UART_IMU_HD_TXBITCTR_INIT   (((UART_IMU_BREAK_BITS_TX + \
                            UART_IMU_NUMBER_OF_START_BIT) * UART_IMU_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define UART_IMU_RXBITCTR_INIT  ((((UART_IMU_BREAK_BITS_RX + UART_IMU_NUMBER_OF_START_BIT) \
                            * UART_IMU_OVER_SAMPLE_COUNT) + UART_IMU_HALF_BIT_COUNT) - 1u)


#else /* UART_IMU_OVER_SAMPLE_COUNT == UART_IMU_OVER_SAMPLE_16 */
    #define UART_IMU_HD_TXBITCTR_INIT   ((8u * UART_IMU_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount=16 */
    #define UART_IMU_RXBITCTR_INIT      (((7u * UART_IMU_OVER_SAMPLE_COUNT) - 1u) + \
                                                      UART_IMU_HALF_BIT_COUNT)
#endif /* End UART_IMU_OVER_SAMPLE_COUNT */
#define UART_IMU_HD_RXBITCTR_INIT                   UART_IMU_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 UART_IMU_initVar;
#if( UART_IMU_TX_ENABLED && (UART_IMU_TXBUFFERSIZE > UART_IMU_FIFO_LENGTH))
    extern volatile uint8 UART_IMU_txBuffer[UART_IMU_TXBUFFERSIZE];
    extern volatile uint8 UART_IMU_txBufferRead;
    extern uint8 UART_IMU_txBufferWrite;
#endif /* End UART_IMU_TX_ENABLED */
#if( ( UART_IMU_RX_ENABLED || UART_IMU_HD_ENABLED ) && \
     (UART_IMU_RXBUFFERSIZE > UART_IMU_FIFO_LENGTH) )
    extern volatile uint8 UART_IMU_rxBuffer[UART_IMU_RXBUFFERSIZE];
    extern volatile uint8 UART_IMU_rxBufferRead;
    extern volatile uint8 UART_IMU_rxBufferWrite;
    extern volatile uint8 UART_IMU_rxBufferLoopDetect;
    extern volatile uint8 UART_IMU_rxBufferOverflow;
    #if (UART_IMU_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_IMU_rxAddressMode;
        extern volatile uint8 UART_IMU_rxAddressDetected;
    #endif /* End EnableHWAddress */
#endif /* End UART_IMU_RX_ENABLED */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define UART_IMU__B_UART__AM_SW_BYTE_BYTE 1
#define UART_IMU__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define UART_IMU__B_UART__AM_HW_BYTE_BY_BYTE 3
#define UART_IMU__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define UART_IMU__B_UART__AM_NONE 0

#define UART_IMU__B_UART__NONE_REVB 0
#define UART_IMU__B_UART__EVEN_REVB 1
#define UART_IMU__B_UART__ODD_REVB 2
#define UART_IMU__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define UART_IMU_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define UART_IMU_NUMBER_OF_STOP_BITS    (1u)

#if (UART_IMU_RXHW_ADDRESS_ENABLED)
    #define UART_IMU_RXADDRESSMODE      (0u)
    #define UART_IMU_RXHWADDRESS1       (0u)
    #define UART_IMU_RXHWADDRESS2       (0u)
    /* Backward compatible define */
    #define UART_IMU_RXAddressMode      UART_IMU_RXADDRESSMODE
#endif /* End EnableHWAddress */

#define UART_IMU_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << UART_IMU_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_BREAK_SHIFT) \
                                        | (0 << UART_IMU_RX_STS_OVERRUN_SHIFT))

#define UART_IMU_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << UART_IMU_TX_STS_COMPLETE_SHIFT) \
                                        | (1 << UART_IMU_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << UART_IMU_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << UART_IMU_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_IMU_CONTROL_REG \
                            (* (reg8 *) UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define UART_IMU_CONTROL_PTR \
                            (  (reg8 *) UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_IMU_TX_ENABLED)
    #define UART_IMU_TXDATA_REG          (* (reg8 *) UART_IMU_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_IMU_TXDATA_PTR          (  (reg8 *) UART_IMU_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_IMU_TXDATA_AUX_CTL_REG  (* (reg8 *) UART_IMU_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_IMU_TXDATA_AUX_CTL_PTR  (  (reg8 *) UART_IMU_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_IMU_TXSTATUS_REG        (* (reg8 *) UART_IMU_BUART_sTX_TxSts__STATUS_REG)
    #define UART_IMU_TXSTATUS_PTR        (  (reg8 *) UART_IMU_BUART_sTX_TxSts__STATUS_REG)
    #define UART_IMU_TXSTATUS_MASK_REG   (* (reg8 *) UART_IMU_BUART_sTX_TxSts__MASK_REG)
    #define UART_IMU_TXSTATUS_MASK_PTR   (  (reg8 *) UART_IMU_BUART_sTX_TxSts__MASK_REG)
    #define UART_IMU_TXSTATUS_ACTL_REG   (* (reg8 *) UART_IMU_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define UART_IMU_TXSTATUS_ACTL_PTR   (  (reg8 *) UART_IMU_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(UART_IMU_TXCLKGEN_DP)
        #define UART_IMU_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_IMU_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_IMU_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define UART_IMU_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define UART_IMU_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_IMU_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_IMU_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_IMU_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_IMU_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define UART_IMU_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) UART_IMU_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* UART_IMU_TXCLKGEN_DP */

#endif /* End UART_IMU_TX_ENABLED */

#if(UART_IMU_HD_ENABLED)

    #define UART_IMU_TXDATA_REG             (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_IMU_TXDATA_PTR             (  (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_IMU_TXDATA_AUX_CTL_REG     (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define UART_IMU_TXDATA_AUX_CTL_PTR     (  (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_IMU_TXSTATUS_REG           (* (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_REG )
    #define UART_IMU_TXSTATUS_PTR           (  (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_REG )
    #define UART_IMU_TXSTATUS_MASK_REG      (* (reg8 *) UART_IMU_BUART_sRX_RxSts__MASK_REG )
    #define UART_IMU_TXSTATUS_MASK_PTR      (  (reg8 *) UART_IMU_BUART_sRX_RxSts__MASK_REG )
    #define UART_IMU_TXSTATUS_ACTL_REG      (* (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_IMU_TXSTATUS_ACTL_PTR      (  (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End UART_IMU_HD_ENABLED */

#if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )
    #define UART_IMU_RXDATA_REG             (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_IMU_RXDATA_PTR             (  (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_IMU_RXADDRESS1_REG         (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_IMU_RXADDRESS1_PTR         (  (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_IMU_RXADDRESS2_REG         (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_IMU_RXADDRESS2_PTR         (  (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_IMU_RXDATA_AUX_CTL_REG     (* (reg8 *) UART_IMU_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_IMU_RXBITCTR_PERIOD_REG    (* (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_IMU_RXBITCTR_PERIOD_PTR    (  (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_IMU_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_IMU_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_IMU_RXBITCTR_COUNTER_REG   (* (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__COUNT_REG )
    #define UART_IMU_RXBITCTR_COUNTER_PTR   (  (reg8 *) UART_IMU_BUART_sRX_RxBitCounter__COUNT_REG )

    #define UART_IMU_RXSTATUS_REG           (* (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_REG )
    #define UART_IMU_RXSTATUS_PTR           (  (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_REG )
    #define UART_IMU_RXSTATUS_MASK_REG      (* (reg8 *) UART_IMU_BUART_sRX_RxSts__MASK_REG )
    #define UART_IMU_RXSTATUS_MASK_PTR      (  (reg8 *) UART_IMU_BUART_sRX_RxSts__MASK_REG )
    #define UART_IMU_RXSTATUS_ACTL_REG      (* (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_IMU_RXSTATUS_ACTL_PTR      (  (reg8 *) UART_IMU_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) */

#if(UART_IMU_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define UART_IMU_INTCLOCK_CLKEN_REG     (* (reg8 *) UART_IMU_IntClock__PM_ACT_CFG)
    #define UART_IMU_INTCLOCK_CLKEN_PTR     (  (reg8 *) UART_IMU_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define UART_IMU_INTCLOCK_CLKEN_MASK    UART_IMU_IntClock__PM_ACT_MSK
#endif /* End UART_IMU_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(UART_IMU_TX_ENABLED)
    #define UART_IMU_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End UART_IMU_TX_ENABLED */

#if(UART_IMU_HD_ENABLED)
    #define UART_IMU_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End UART_IMU_HD_ENABLED */

#if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )
    #define UART_IMU_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) */


/***************************************
* Renamed global variables or defines
* for backward compatible
***************************************/

#define UART_IMU_initvar                    UART_IMU_initVar

#define UART_IMU_RX_Enabled                 UART_IMU_RX_ENABLED
#define UART_IMU_TX_Enabled                 UART_IMU_TX_ENABLED
#define UART_IMU_HD_Enabled                 UART_IMU_HD_ENABLED
#define UART_IMU_RX_IntInterruptEnabled     UART_IMU_RX_INTERRUPT_ENABLED
#define UART_IMU_TX_IntInterruptEnabled     UART_IMU_TX_INTERRUPT_ENABLED
#define UART_IMU_InternalClockUsed          UART_IMU_INTERNAL_CLOCK_USED
#define UART_IMU_RXHW_Address_Enabled       UART_IMU_RXHW_ADDRESS_ENABLED
#define UART_IMU_OverSampleCount            UART_IMU_OVER_SAMPLE_COUNT
#define UART_IMU_ParityType                 UART_IMU_PARITY_TYPE

#if( UART_IMU_TX_ENABLED && (UART_IMU_TXBUFFERSIZE > UART_IMU_FIFO_LENGTH))
    #define UART_IMU_TXBUFFER               UART_IMU_txBuffer
    #define UART_IMU_TXBUFFERREAD           UART_IMU_txBufferRead
    #define UART_IMU_TXBUFFERWRITE          UART_IMU_txBufferWrite
#endif /* End UART_IMU_TX_ENABLED */
#if( ( UART_IMU_RX_ENABLED || UART_IMU_HD_ENABLED ) && \
     (UART_IMU_RXBUFFERSIZE > UART_IMU_FIFO_LENGTH) )
    #define UART_IMU_RXBUFFER               UART_IMU_rxBuffer
    #define UART_IMU_RXBUFFERREAD           UART_IMU_rxBufferRead
    #define UART_IMU_RXBUFFERWRITE          UART_IMU_rxBufferWrite
    #define UART_IMU_RXBUFFERLOOPDETECT     UART_IMU_rxBufferLoopDetect
    #define UART_IMU_RXBUFFER_OVERFLOW      UART_IMU_rxBufferOverflow
#endif /* End UART_IMU_RX_ENABLED */

#ifdef UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_IMU_CONTROL                UART_IMU_CONTROL_REG
#endif /* End UART_IMU_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_IMU_TX_ENABLED)
    #define UART_IMU_TXDATA                 UART_IMU_TXDATA_REG
    #define UART_IMU_TXSTATUS               UART_IMU_TXSTATUS_REG
    #define UART_IMU_TXSTATUS_MASK          UART_IMU_TXSTATUS_MASK_REG
    #define UART_IMU_TXSTATUS_ACTL          UART_IMU_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(UART_IMU_TXCLKGEN_DP)
        #define UART_IMU_TXBITCLKGEN_CTR        UART_IMU_TXBITCLKGEN_CTR_REG
        #define UART_IMU_TXBITCLKTX_COMPLETE    UART_IMU_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define UART_IMU_TXBITCTR_PERIOD        UART_IMU_TXBITCTR_PERIOD_REG
        #define UART_IMU_TXBITCTR_CONTROL       UART_IMU_TXBITCTR_CONTROL_REG
        #define UART_IMU_TXBITCTR_COUNTER       UART_IMU_TXBITCTR_COUNTER_REG
    #endif /* UART_IMU_TXCLKGEN_DP */
#endif /* End UART_IMU_TX_ENABLED */

#if(UART_IMU_HD_ENABLED)
    #define UART_IMU_TXDATA                 UART_IMU_TXDATA_REG
    #define UART_IMU_TXSTATUS               UART_IMU_TXSTATUS_REG
    #define UART_IMU_TXSTATUS_MASK          UART_IMU_TXSTATUS_MASK_REG
    #define UART_IMU_TXSTATUS_ACTL          UART_IMU_TXSTATUS_ACTL_REG
#endif /* End UART_IMU_HD_ENABLED */

#if( (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) )
    #define UART_IMU_RXDATA                 UART_IMU_RXDATA_REG
    #define UART_IMU_RXADDRESS1             UART_IMU_RXADDRESS1_REG
    #define UART_IMU_RXADDRESS2             UART_IMU_RXADDRESS2_REG
    #define UART_IMU_RXBITCTR_PERIOD        UART_IMU_RXBITCTR_PERIOD_REG
    #define UART_IMU_RXBITCTR_CONTROL       UART_IMU_RXBITCTR_CONTROL_REG
    #define UART_IMU_RXBITCTR_COUNTER       UART_IMU_RXBITCTR_COUNTER_REG
    #define UART_IMU_RXSTATUS               UART_IMU_RXSTATUS_REG
    #define UART_IMU_RXSTATUS_MASK          UART_IMU_RXSTATUS_MASK_REG
    #define UART_IMU_RXSTATUS_ACTL          UART_IMU_RXSTATUS_ACTL_REG
#endif /* End  (UART_IMU_RX_ENABLED) || (UART_IMU_HD_ENABLED) */

#if(UART_IMU_INTERNAL_CLOCK_USED)
    #define UART_IMU_INTCLOCK_CLKEN         UART_IMU_INTCLOCK_CLKEN_REG
#endif /* End UART_IMU_INTERNAL_CLOCK_USED */

#define UART_IMU_WAIT_FOR_COMLETE_REINIT    UART_IMU_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_UART_IMU_H */


/* [] END OF FILE */
