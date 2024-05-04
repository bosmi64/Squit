/*******************************************************************************
* File Name: IMU_UM6_UART.h
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


#if !defined(CY_UART_IMU_UM6_UART_H)
#define CY_UART_IMU_UM6_UART_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

#define IMU_UM6_UART_RX_ENABLED                     (1u)
#define IMU_UM6_UART_TX_ENABLED                     (1u)
#define IMU_UM6_UART_HD_ENABLED                     (0u)
#define IMU_UM6_UART_RX_INTERRUPT_ENABLED           (0u)
#define IMU_UM6_UART_TX_INTERRUPT_ENABLED           (0u)
#define IMU_UM6_UART_INTERNAL_CLOCK_USED            (1u)
#define IMU_UM6_UART_RXHW_ADDRESS_ENABLED           (0u)
#define IMU_UM6_UART_OVER_SAMPLE_COUNT              (8u)
#define IMU_UM6_UART_PARITY_TYPE                    (0u)
#define IMU_UM6_UART_PARITY_TYPE_SW                 (0u)
#define IMU_UM6_UART_BREAK_DETECT                   (0u)
#define IMU_UM6_UART_BREAK_BITS_TX                  (13u)
#define IMU_UM6_UART_BREAK_BITS_RX                  (13u)
#define IMU_UM6_UART_TXCLKGEN_DP                    (1u)
#define IMU_UM6_UART_USE23POLLING                   (1u)
#define IMU_UM6_UART_FLOW_CONTROL                   (0u)
#define IMU_UM6_UART_CLK_FREQ                       (0u)
#define IMU_UM6_UART_TXBUFFERSIZE                   (4u)
#define IMU_UM6_UART_RXBUFFERSIZE                   (4u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component UART_v2_30 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#ifdef IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define IMU_UM6_UART_CONTROL_REG_REMOVED            (0u)
#else
    #define IMU_UM6_UART_CONTROL_REG_REMOVED            (1u)
#endif /* End IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct IMU_UM6_UART_backupStruct_
{
    uint8 enableState;

    #if(IMU_UM6_UART_CONTROL_REG_REMOVED == 0u)
        uint8 cr;
    #endif /* End IMU_UM6_UART_CONTROL_REG_REMOVED */
    #if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
        uint8 rx_period;
        #if (CY_UDB_V0)
            uint8 rx_mask;
            #if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
                uint8 rx_addr1;
                uint8 rx_addr2;
            #endif /* End IMU_UM6_UART_RXHW_ADDRESS_ENABLED */
        #endif /* End CY_UDB_V0 */
    #endif  /* End (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED)*/

    #if(IMU_UM6_UART_TX_ENABLED)
        #if(IMU_UM6_UART_TXCLKGEN_DP)
            uint8 tx_clk_ctr;
            #if (CY_UDB_V0)
                uint8 tx_clk_compl;
            #endif  /* End CY_UDB_V0 */
        #else
            uint8 tx_period;
        #endif /*End IMU_UM6_UART_TXCLKGEN_DP */
        #if (CY_UDB_V0)
            uint8 tx_mask;
        #endif  /* End CY_UDB_V0 */
    #endif /*End IMU_UM6_UART_TX_ENABLED */
} IMU_UM6_UART_BACKUP_STRUCT;


/***************************************
*       Function Prototypes
***************************************/

void IMU_UM6_UART_Start(void) ;
void IMU_UM6_UART_Stop(void) ;
uint8 IMU_UM6_UART_ReadControlRegister(void) ;
void IMU_UM6_UART_WriteControlRegister(uint8 control) ;

void IMU_UM6_UART_Init(void) ;
void IMU_UM6_UART_Enable(void) ;
void IMU_UM6_UART_SaveConfig(void) ;
void IMU_UM6_UART_RestoreConfig(void) ;
void IMU_UM6_UART_Sleep(void) ;
void IMU_UM6_UART_Wakeup(void) ;

/* Only if RX is enabled */
#if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )

    #if(IMU_UM6_UART_RX_INTERRUPT_ENABLED)
        void  IMU_UM6_UART_EnableRxInt(void) ;
        void  IMU_UM6_UART_DisableRxInt(void) ;
        CY_ISR_PROTO(IMU_UM6_UART_RXISR);
    #endif /* IMU_UM6_UART_RX_INTERRUPT_ENABLED */

    void IMU_UM6_UART_SetRxAddressMode(uint8 addressMode)
                                                           ;
    void IMU_UM6_UART_SetRxAddress1(uint8 address) ;
    void IMU_UM6_UART_SetRxAddress2(uint8 address) ;

    void  IMU_UM6_UART_SetRxInterruptMode(uint8 intSrc) ;
    uint8 IMU_UM6_UART_ReadRxData(void) ;
    uint8 IMU_UM6_UART_ReadRxStatus(void) ;
    uint8 IMU_UM6_UART_GetChar(void) ;
    uint16 IMU_UM6_UART_GetByte(void) ;
    uint8 IMU_UM6_UART_GetRxBufferSize(void)
                                                            ;
    void IMU_UM6_UART_ClearRxBuffer(void) ;

    /* Obsolete functions, defines for backward compatible */
    #define IMU_UM6_UART_GetRxInterruptSource   IMU_UM6_UART_ReadRxStatus

#endif /* End (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */

/* Only if TX is enabled */
#if(IMU_UM6_UART_TX_ENABLED || IMU_UM6_UART_HD_ENABLED)

    #if(IMU_UM6_UART_TX_INTERRUPT_ENABLED)
        void IMU_UM6_UART_EnableTxInt(void) ;
        void IMU_UM6_UART_DisableTxInt(void) ;
        CY_ISR_PROTO(IMU_UM6_UART_TXISR);
    #endif /* IMU_UM6_UART_TX_INTERRUPT_ENABLED */

    void IMU_UM6_UART_SetTxInterruptMode(uint8 intSrc) ;
    void IMU_UM6_UART_WriteTxData(uint8 txDataByte) ;
    uint8 IMU_UM6_UART_ReadTxStatus(void) ;
    void IMU_UM6_UART_PutChar(uint8 txDataByte) ;
    void IMU_UM6_UART_PutString(const char8 string[]) ;
    void IMU_UM6_UART_PutArray(const uint8 string[], uint8 byteCount)
                                                            ;
    void IMU_UM6_UART_PutCRLF(uint8 txDataByte) ;
    void IMU_UM6_UART_ClearTxBuffer(void) ;
    void IMU_UM6_UART_SetTxAddressMode(uint8 addressMode) ;
    void IMU_UM6_UART_SendBreak(uint8 retMode) ;
    uint8 IMU_UM6_UART_GetTxBufferSize(void)
                                                            ;
    /* Obsolete functions, defines for backward compatible */
    #define IMU_UM6_UART_PutStringConst         IMU_UM6_UART_PutString
    #define IMU_UM6_UART_PutArrayConst          IMU_UM6_UART_PutArray
    #define IMU_UM6_UART_GetTxInterruptSource   IMU_UM6_UART_ReadTxStatus

#endif /* End IMU_UM6_UART_TX_ENABLED || IMU_UM6_UART_HD_ENABLED */

#if(IMU_UM6_UART_HD_ENABLED)
    void IMU_UM6_UART_LoadRxConfig(void) ;
    void IMU_UM6_UART_LoadTxConfig(void) ;
#endif /* End IMU_UM6_UART_HD_ENABLED */


/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_IMU_UM6_UART) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    IMU_UM6_UART_CyBtldrCommStart(void) CYSMALL ;
    void    IMU_UM6_UART_CyBtldrCommStop(void) CYSMALL ;
    void    IMU_UM6_UART_CyBtldrCommReset(void) CYSMALL ;
    cystatus IMU_UM6_UART_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;
    cystatus IMU_UM6_UART_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL
             ;

    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_IMU_UM6_UART)
        #define CyBtldrCommStart    IMU_UM6_UART_CyBtldrCommStart
        #define CyBtldrCommStop     IMU_UM6_UART_CyBtldrCommStop
        #define CyBtldrCommReset    IMU_UM6_UART_CyBtldrCommReset
        #define CyBtldrCommWrite    IMU_UM6_UART_CyBtldrCommWrite
        #define CyBtldrCommRead     IMU_UM6_UART_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_IMU_UM6_UART) */

    /* Byte to Byte time out for detecting end of block data from host */
    #define IMU_UM6_UART_BYTE2BYTE_TIME_OUT (25u)

#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/
/* Parameters for SetTxAddressMode API*/
#define IMU_UM6_UART_SET_SPACE                              (0x00u)
#define IMU_UM6_UART_SET_MARK                               (0x01u)

/* Status Register definitions */
#if( (IMU_UM6_UART_TX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
    #if(IMU_UM6_UART_TX_INTERRUPT_ENABLED)
        #define IMU_UM6_UART_TX_VECT_NUM            (uint8)IMU_UM6_UART_TXInternalInterrupt__INTC_NUMBER
        #define IMU_UM6_UART_TX_PRIOR_NUM           (uint8)IMU_UM6_UART_TXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* IMU_UM6_UART_TX_INTERRUPT_ENABLED */
    #if(IMU_UM6_UART_TX_ENABLED)
        #define IMU_UM6_UART_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define IMU_UM6_UART_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define IMU_UM6_UART_TX_STS_FIFO_FULL_SHIFT         (0x02u)
        #define IMU_UM6_UART_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* IMU_UM6_UART_TX_ENABLED */
    #if(IMU_UM6_UART_HD_ENABLED)
        #define IMU_UM6_UART_TX_STS_COMPLETE_SHIFT          (0x00u)
        #define IMU_UM6_UART_TX_STS_FIFO_EMPTY_SHIFT        (0x01u)
        #define IMU_UM6_UART_TX_STS_FIFO_FULL_SHIFT         (0x05u)  /*needs MD=0*/
        #define IMU_UM6_UART_TX_STS_FIFO_NOT_FULL_SHIFT     (0x03u)
    #endif /* IMU_UM6_UART_HD_ENABLED */
    #define IMU_UM6_UART_TX_STS_COMPLETE            (uint8)(0x01u << IMU_UM6_UART_TX_STS_COMPLETE_SHIFT)
    #define IMU_UM6_UART_TX_STS_FIFO_EMPTY          (uint8)(0x01u << IMU_UM6_UART_TX_STS_FIFO_EMPTY_SHIFT)
    #define IMU_UM6_UART_TX_STS_FIFO_FULL           (uint8)(0x01u << IMU_UM6_UART_TX_STS_FIFO_FULL_SHIFT)
    #define IMU_UM6_UART_TX_STS_FIFO_NOT_FULL       (uint8)(0x01u << IMU_UM6_UART_TX_STS_FIFO_NOT_FULL_SHIFT)
#endif /* End (IMU_UM6_UART_TX_ENABLED) || (IMU_UM6_UART_HD_ENABLED)*/

#if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
    #if(IMU_UM6_UART_RX_INTERRUPT_ENABLED)
        #define IMU_UM6_UART_RX_VECT_NUM            (uint8)IMU_UM6_UART_RXInternalInterrupt__INTC_NUMBER
        #define IMU_UM6_UART_RX_PRIOR_NUM           (uint8)IMU_UM6_UART_RXInternalInterrupt__INTC_PRIOR_NUM
    #endif /* IMU_UM6_UART_RX_INTERRUPT_ENABLED */
    #define IMU_UM6_UART_RX_STS_MRKSPC_SHIFT            (0x00u)
    #define IMU_UM6_UART_RX_STS_BREAK_SHIFT             (0x01u)
    #define IMU_UM6_UART_RX_STS_PAR_ERROR_SHIFT         (0x02u)
    #define IMU_UM6_UART_RX_STS_STOP_ERROR_SHIFT        (0x03u)
    #define IMU_UM6_UART_RX_STS_OVERRUN_SHIFT           (0x04u)
    #define IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY_SHIFT     (0x05u)
    #define IMU_UM6_UART_RX_STS_ADDR_MATCH_SHIFT        (0x06u)
    #define IMU_UM6_UART_RX_STS_SOFT_BUFF_OVER_SHIFT    (0x07u)

    #define IMU_UM6_UART_RX_STS_MRKSPC           (uint8)(0x01u << IMU_UM6_UART_RX_STS_MRKSPC_SHIFT)
    #define IMU_UM6_UART_RX_STS_BREAK            (uint8)(0x01u << IMU_UM6_UART_RX_STS_BREAK_SHIFT)
    #define IMU_UM6_UART_RX_STS_PAR_ERROR        (uint8)(0x01u << IMU_UM6_UART_RX_STS_PAR_ERROR_SHIFT)
    #define IMU_UM6_UART_RX_STS_STOP_ERROR       (uint8)(0x01u << IMU_UM6_UART_RX_STS_STOP_ERROR_SHIFT)
    #define IMU_UM6_UART_RX_STS_OVERRUN          (uint8)(0x01u << IMU_UM6_UART_RX_STS_OVERRUN_SHIFT)
    #define IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY    (uint8)(0x01u << IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY_SHIFT)
    #define IMU_UM6_UART_RX_STS_ADDR_MATCH       (uint8)(0x01u << IMU_UM6_UART_RX_STS_ADDR_MATCH_SHIFT)
    #define IMU_UM6_UART_RX_STS_SOFT_BUFF_OVER   (uint8)(0x01u << IMU_UM6_UART_RX_STS_SOFT_BUFF_OVER_SHIFT)
    #define IMU_UM6_UART_RX_HW_MASK                     (0x7Fu)
#endif /* End (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */

/* Control Register definitions */
#define IMU_UM6_UART_CTRL_HD_SEND_SHIFT                 (0x00u) /* 1 enable TX part in Half Duplex mode */
#define IMU_UM6_UART_CTRL_HD_SEND_BREAK_SHIFT           (0x01u) /* 1 send BREAK signal in Half Duplez mode */
#define IMU_UM6_UART_CTRL_MARK_SHIFT                    (0x02u) /* 1 sets mark, 0 sets space */
#define IMU_UM6_UART_CTRL_PARITY_TYPE0_SHIFT            (0x03u) /* Defines the type of parity implemented */
#define IMU_UM6_UART_CTRL_PARITY_TYPE1_SHIFT            (0x04u) /* Defines the type of parity implemented */
#define IMU_UM6_UART_CTRL_RXADDR_MODE0_SHIFT            (0x05u)
#define IMU_UM6_UART_CTRL_RXADDR_MODE1_SHIFT            (0x06u)
#define IMU_UM6_UART_CTRL_RXADDR_MODE2_SHIFT            (0x07u)

#define IMU_UM6_UART_CTRL_HD_SEND               (uint8)(0x01u << IMU_UM6_UART_CTRL_HD_SEND_SHIFT)
#define IMU_UM6_UART_CTRL_HD_SEND_BREAK         (uint8)(0x01u << IMU_UM6_UART_CTRL_HD_SEND_BREAK_SHIFT)
#define IMU_UM6_UART_CTRL_MARK                  (uint8)(0x01u << IMU_UM6_UART_CTRL_MARK_SHIFT)
#define IMU_UM6_UART_CTRL_PARITY_TYPE_MASK      (uint8)(0x03u << IMU_UM6_UART_CTRL_PARITY_TYPE0_SHIFT)
#define IMU_UM6_UART_CTRL_RXADDR_MODE_MASK      (uint8)(0x07u << IMU_UM6_UART_CTRL_RXADDR_MODE0_SHIFT)

/* StatusI Register Interrupt Enable Control Bits. As defined by the Register map for the AUX Control Register */
#define IMU_UM6_UART_INT_ENABLE                         (0x10u)

/* Bit Counter (7-bit) Control Register Bit Definitions. As defined by the Register map for the AUX Control Register */
#define IMU_UM6_UART_CNTR_ENABLE                        (0x20u)

/*   Constants for SendBreak() "retMode" parameter  */
#define IMU_UM6_UART_SEND_BREAK                         (0x00u)
#define IMU_UM6_UART_WAIT_FOR_COMPLETE_REINIT           (0x01u)
#define IMU_UM6_UART_REINIT                             (0x02u)
#define IMU_UM6_UART_SEND_WAIT_REINIT                   (0x03u)

#define IMU_UM6_UART_OVER_SAMPLE_8                      (8u)
#define IMU_UM6_UART_OVER_SAMPLE_16                     (16u)

#define IMU_UM6_UART_BIT_CENTER                         (IMU_UM6_UART_OVER_SAMPLE_COUNT - 1u)

#define IMU_UM6_UART_FIFO_LENGTH                        (4u)
#define IMU_UM6_UART_NUMBER_OF_START_BIT                (1u)
#define IMU_UM6_UART_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation*/
#define IMU_UM6_UART_TXBITCTR_BREAKBITS8X   ((IMU_UM6_UART_BREAK_BITS_TX * IMU_UM6_UART_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation*/
#define IMU_UM6_UART_TXBITCTR_BREAKBITS ((IMU_UM6_UART_BREAK_BITS_TX * IMU_UM6_UART_OVER_SAMPLE_COUNT) - 1u)

#define IMU_UM6_UART_HALF_BIT_COUNT   \
                            (((IMU_UM6_UART_OVER_SAMPLE_COUNT / 2u) + (IMU_UM6_UART_USE23POLLING * 1u)) - 2u)
#if (IMU_UM6_UART_OVER_SAMPLE_COUNT == IMU_UM6_UART_OVER_SAMPLE_8)
    #define IMU_UM6_UART_HD_TXBITCTR_INIT   (((IMU_UM6_UART_BREAK_BITS_TX + \
                            IMU_UM6_UART_NUMBER_OF_START_BIT) * IMU_UM6_UART_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define IMU_UM6_UART_RXBITCTR_INIT  ((((IMU_UM6_UART_BREAK_BITS_RX + IMU_UM6_UART_NUMBER_OF_START_BIT) \
                            * IMU_UM6_UART_OVER_SAMPLE_COUNT) + IMU_UM6_UART_HALF_BIT_COUNT) - 1u)


#else /* IMU_UM6_UART_OVER_SAMPLE_COUNT == IMU_UM6_UART_OVER_SAMPLE_16 */
    #define IMU_UM6_UART_HD_TXBITCTR_INIT   ((8u * IMU_UM6_UART_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount=16 */
    #define IMU_UM6_UART_RXBITCTR_INIT      (((7u * IMU_UM6_UART_OVER_SAMPLE_COUNT) - 1u) + \
                                                      IMU_UM6_UART_HALF_BIT_COUNT)
#endif /* End IMU_UM6_UART_OVER_SAMPLE_COUNT */
#define IMU_UM6_UART_HD_RXBITCTR_INIT                   IMU_UM6_UART_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 IMU_UM6_UART_initVar;
#if( IMU_UM6_UART_TX_ENABLED && (IMU_UM6_UART_TXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH))
    extern volatile uint8 IMU_UM6_UART_txBuffer[IMU_UM6_UART_TXBUFFERSIZE];
    extern volatile uint8 IMU_UM6_UART_txBufferRead;
    extern uint8 IMU_UM6_UART_txBufferWrite;
#endif /* End IMU_UM6_UART_TX_ENABLED */
#if( ( IMU_UM6_UART_RX_ENABLED || IMU_UM6_UART_HD_ENABLED ) && \
     (IMU_UM6_UART_RXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH) )
    extern volatile uint8 IMU_UM6_UART_rxBuffer[IMU_UM6_UART_RXBUFFERSIZE];
    extern volatile uint8 IMU_UM6_UART_rxBufferRead;
    extern volatile uint8 IMU_UM6_UART_rxBufferWrite;
    extern volatile uint8 IMU_UM6_UART_rxBufferLoopDetect;
    extern volatile uint8 IMU_UM6_UART_rxBufferOverflow;
    #if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 IMU_UM6_UART_rxAddressMode;
        extern volatile uint8 IMU_UM6_UART_rxAddressDetected;
    #endif /* End EnableHWAddress */
#endif /* End IMU_UM6_UART_RX_ENABLED */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define IMU_UM6_UART__B_UART__AM_SW_BYTE_BYTE 1
#define IMU_UM6_UART__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define IMU_UM6_UART__B_UART__AM_HW_BYTE_BY_BYTE 3
#define IMU_UM6_UART__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define IMU_UM6_UART__B_UART__AM_NONE 0

#define IMU_UM6_UART__B_UART__NONE_REVB 0
#define IMU_UM6_UART__B_UART__EVEN_REVB 1
#define IMU_UM6_UART__B_UART__ODD_REVB 2
#define IMU_UM6_UART__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define IMU_UM6_UART_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define IMU_UM6_UART_NUMBER_OF_STOP_BITS    (1u)

#if (IMU_UM6_UART_RXHW_ADDRESS_ENABLED)
    #define IMU_UM6_UART_RXADDRESSMODE      (0u)
    #define IMU_UM6_UART_RXHWADDRESS1       (0u)
    #define IMU_UM6_UART_RXHWADDRESS2       (0u)
    /* Backward compatible define */
    #define IMU_UM6_UART_RXAddressMode      IMU_UM6_UART_RXADDRESSMODE
#endif /* End EnableHWAddress */

#define IMU_UM6_UART_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << IMU_UM6_UART_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << IMU_UM6_UART_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (1 << IMU_UM6_UART_RX_STS_PAR_ERROR_SHIFT) \
                                        | (1 << IMU_UM6_UART_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << IMU_UM6_UART_RX_STS_BREAK_SHIFT) \
                                        | (1 << IMU_UM6_UART_RX_STS_OVERRUN_SHIFT))

#define IMU_UM6_UART_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << IMU_UM6_UART_TX_STS_COMPLETE_SHIFT) \
                                        | (0 << IMU_UM6_UART_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << IMU_UM6_UART_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << IMU_UM6_UART_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define IMU_UM6_UART_CONTROL_REG \
                            (* (reg8 *) IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define IMU_UM6_UART_CONTROL_PTR \
                            (  (reg8 *) IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(IMU_UM6_UART_TX_ENABLED)
    #define IMU_UM6_UART_TXDATA_REG          (* (reg8 *) IMU_UM6_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define IMU_UM6_UART_TXDATA_PTR          (  (reg8 *) IMU_UM6_UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define IMU_UM6_UART_TXDATA_AUX_CTL_REG  (* (reg8 *) IMU_UM6_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define IMU_UM6_UART_TXDATA_AUX_CTL_PTR  (  (reg8 *) IMU_UM6_UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define IMU_UM6_UART_TXSTATUS_REG        (* (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__STATUS_REG)
    #define IMU_UM6_UART_TXSTATUS_PTR        (  (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__STATUS_REG)
    #define IMU_UM6_UART_TXSTATUS_MASK_REG   (* (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__MASK_REG)
    #define IMU_UM6_UART_TXSTATUS_MASK_PTR   (  (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__MASK_REG)
    #define IMU_UM6_UART_TXSTATUS_ACTL_REG   (* (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define IMU_UM6_UART_TXSTATUS_ACTL_PTR   (  (reg8 *) IMU_UM6_UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(IMU_UM6_UART_TXCLKGEN_DP)
        #define IMU_UM6_UART_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define IMU_UM6_UART_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define IMU_UM6_UART_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define IMU_UM6_UART_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define IMU_UM6_UART_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define IMU_UM6_UART_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define IMU_UM6_UART_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define IMU_UM6_UART_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define IMU_UM6_UART_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define IMU_UM6_UART_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* IMU_UM6_UART_TXCLKGEN_DP */

#endif /* End IMU_UM6_UART_TX_ENABLED */

#if(IMU_UM6_UART_HD_ENABLED)

    #define IMU_UM6_UART_TXDATA_REG             (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define IMU_UM6_UART_TXDATA_PTR             (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define IMU_UM6_UART_TXDATA_AUX_CTL_REG     (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define IMU_UM6_UART_TXDATA_AUX_CTL_PTR     (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define IMU_UM6_UART_TXSTATUS_REG           (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_REG )
    #define IMU_UM6_UART_TXSTATUS_PTR           (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_REG )
    #define IMU_UM6_UART_TXSTATUS_MASK_REG      (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__MASK_REG )
    #define IMU_UM6_UART_TXSTATUS_MASK_PTR      (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__MASK_REG )
    #define IMU_UM6_UART_TXSTATUS_ACTL_REG      (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define IMU_UM6_UART_TXSTATUS_ACTL_PTR      (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End IMU_UM6_UART_HD_ENABLED */

#if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
    #define IMU_UM6_UART_RXDATA_REG             (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define IMU_UM6_UART_RXDATA_PTR             (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define IMU_UM6_UART_RXADDRESS1_REG         (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define IMU_UM6_UART_RXADDRESS1_PTR         (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define IMU_UM6_UART_RXADDRESS2_REG         (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define IMU_UM6_UART_RXADDRESS2_PTR         (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define IMU_UM6_UART_RXDATA_AUX_CTL_REG     (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define IMU_UM6_UART_RXBITCTR_PERIOD_REG    (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define IMU_UM6_UART_RXBITCTR_PERIOD_PTR    (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define IMU_UM6_UART_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define IMU_UM6_UART_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define IMU_UM6_UART_RXBITCTR_COUNTER_REG   (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__COUNT_REG )
    #define IMU_UM6_UART_RXBITCTR_COUNTER_PTR   (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxBitCounter__COUNT_REG )

    #define IMU_UM6_UART_RXSTATUS_REG           (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_REG )
    #define IMU_UM6_UART_RXSTATUS_PTR           (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_REG )
    #define IMU_UM6_UART_RXSTATUS_MASK_REG      (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__MASK_REG )
    #define IMU_UM6_UART_RXSTATUS_MASK_PTR      (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__MASK_REG )
    #define IMU_UM6_UART_RXSTATUS_ACTL_REG      (* (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define IMU_UM6_UART_RXSTATUS_ACTL_PTR      (  (reg8 *) IMU_UM6_UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */

#if(IMU_UM6_UART_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define IMU_UM6_UART_INTCLOCK_CLKEN_REG     (* (reg8 *) IMU_UM6_UART_IntClock__PM_ACT_CFG)
    #define IMU_UM6_UART_INTCLOCK_CLKEN_PTR     (  (reg8 *) IMU_UM6_UART_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define IMU_UM6_UART_INTCLOCK_CLKEN_MASK    IMU_UM6_UART_IntClock__PM_ACT_MSK
#endif /* End IMU_UM6_UART_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(IMU_UM6_UART_TX_ENABLED)
    #define IMU_UM6_UART_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End IMU_UM6_UART_TX_ENABLED */

#if(IMU_UM6_UART_HD_ENABLED)
    #define IMU_UM6_UART_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End IMU_UM6_UART_HD_ENABLED */

#if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
    #define IMU_UM6_UART_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */


/***************************************
* Renamed global variables or defines
* for backward compatible
***************************************/

#define IMU_UM6_UART_initvar                    IMU_UM6_UART_initVar

#define IMU_UM6_UART_RX_Enabled                 IMU_UM6_UART_RX_ENABLED
#define IMU_UM6_UART_TX_Enabled                 IMU_UM6_UART_TX_ENABLED
#define IMU_UM6_UART_HD_Enabled                 IMU_UM6_UART_HD_ENABLED
#define IMU_UM6_UART_RX_IntInterruptEnabled     IMU_UM6_UART_RX_INTERRUPT_ENABLED
#define IMU_UM6_UART_TX_IntInterruptEnabled     IMU_UM6_UART_TX_INTERRUPT_ENABLED
#define IMU_UM6_UART_InternalClockUsed          IMU_UM6_UART_INTERNAL_CLOCK_USED
#define IMU_UM6_UART_RXHW_Address_Enabled       IMU_UM6_UART_RXHW_ADDRESS_ENABLED
#define IMU_UM6_UART_OverSampleCount            IMU_UM6_UART_OVER_SAMPLE_COUNT
#define IMU_UM6_UART_ParityType                 IMU_UM6_UART_PARITY_TYPE

#if( IMU_UM6_UART_TX_ENABLED && (IMU_UM6_UART_TXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH))
    #define IMU_UM6_UART_TXBUFFER               IMU_UM6_UART_txBuffer
    #define IMU_UM6_UART_TXBUFFERREAD           IMU_UM6_UART_txBufferRead
    #define IMU_UM6_UART_TXBUFFERWRITE          IMU_UM6_UART_txBufferWrite
#endif /* End IMU_UM6_UART_TX_ENABLED */
#if( ( IMU_UM6_UART_RX_ENABLED || IMU_UM6_UART_HD_ENABLED ) && \
     (IMU_UM6_UART_RXBUFFERSIZE > IMU_UM6_UART_FIFO_LENGTH) )
    #define IMU_UM6_UART_RXBUFFER               IMU_UM6_UART_rxBuffer
    #define IMU_UM6_UART_RXBUFFERREAD           IMU_UM6_UART_rxBufferRead
    #define IMU_UM6_UART_RXBUFFERWRITE          IMU_UM6_UART_rxBufferWrite
    #define IMU_UM6_UART_RXBUFFERLOOPDETECT     IMU_UM6_UART_rxBufferLoopDetect
    #define IMU_UM6_UART_RXBUFFER_OVERFLOW      IMU_UM6_UART_rxBufferOverflow
#endif /* End IMU_UM6_UART_RX_ENABLED */

#ifdef IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define IMU_UM6_UART_CONTROL                IMU_UM6_UART_CONTROL_REG
#endif /* End IMU_UM6_UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(IMU_UM6_UART_TX_ENABLED)
    #define IMU_UM6_UART_TXDATA                 IMU_UM6_UART_TXDATA_REG
    #define IMU_UM6_UART_TXSTATUS               IMU_UM6_UART_TXSTATUS_REG
    #define IMU_UM6_UART_TXSTATUS_MASK          IMU_UM6_UART_TXSTATUS_MASK_REG
    #define IMU_UM6_UART_TXSTATUS_ACTL          IMU_UM6_UART_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(IMU_UM6_UART_TXCLKGEN_DP)
        #define IMU_UM6_UART_TXBITCLKGEN_CTR        IMU_UM6_UART_TXBITCLKGEN_CTR_REG
        #define IMU_UM6_UART_TXBITCLKTX_COMPLETE    IMU_UM6_UART_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define IMU_UM6_UART_TXBITCTR_PERIOD        IMU_UM6_UART_TXBITCTR_PERIOD_REG
        #define IMU_UM6_UART_TXBITCTR_CONTROL       IMU_UM6_UART_TXBITCTR_CONTROL_REG
        #define IMU_UM6_UART_TXBITCTR_COUNTER       IMU_UM6_UART_TXBITCTR_COUNTER_REG
    #endif /* IMU_UM6_UART_TXCLKGEN_DP */
#endif /* End IMU_UM6_UART_TX_ENABLED */

#if(IMU_UM6_UART_HD_ENABLED)
    #define IMU_UM6_UART_TXDATA                 IMU_UM6_UART_TXDATA_REG
    #define IMU_UM6_UART_TXSTATUS               IMU_UM6_UART_TXSTATUS_REG
    #define IMU_UM6_UART_TXSTATUS_MASK          IMU_UM6_UART_TXSTATUS_MASK_REG
    #define IMU_UM6_UART_TXSTATUS_ACTL          IMU_UM6_UART_TXSTATUS_ACTL_REG
#endif /* End IMU_UM6_UART_HD_ENABLED */

#if( (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) )
    #define IMU_UM6_UART_RXDATA                 IMU_UM6_UART_RXDATA_REG
    #define IMU_UM6_UART_RXADDRESS1             IMU_UM6_UART_RXADDRESS1_REG
    #define IMU_UM6_UART_RXADDRESS2             IMU_UM6_UART_RXADDRESS2_REG
    #define IMU_UM6_UART_RXBITCTR_PERIOD        IMU_UM6_UART_RXBITCTR_PERIOD_REG
    #define IMU_UM6_UART_RXBITCTR_CONTROL       IMU_UM6_UART_RXBITCTR_CONTROL_REG
    #define IMU_UM6_UART_RXBITCTR_COUNTER       IMU_UM6_UART_RXBITCTR_COUNTER_REG
    #define IMU_UM6_UART_RXSTATUS               IMU_UM6_UART_RXSTATUS_REG
    #define IMU_UM6_UART_RXSTATUS_MASK          IMU_UM6_UART_RXSTATUS_MASK_REG
    #define IMU_UM6_UART_RXSTATUS_ACTL          IMU_UM6_UART_RXSTATUS_ACTL_REG
#endif /* End  (IMU_UM6_UART_RX_ENABLED) || (IMU_UM6_UART_HD_ENABLED) */

#if(IMU_UM6_UART_INTERNAL_CLOCK_USED)
    #define IMU_UM6_UART_INTCLOCK_CLKEN         IMU_UM6_UART_INTCLOCK_CLKEN_REG
#endif /* End IMU_UM6_UART_INTERNAL_CLOCK_USED */

#define IMU_UM6_UART_WAIT_FOR_COMLETE_REINIT    IMU_UM6_UART_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_IMU_UM6_UART_H */


/* [] END OF FILE */
