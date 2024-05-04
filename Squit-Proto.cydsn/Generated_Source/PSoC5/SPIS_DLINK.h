/*******************************************************************************
* File Name: SPIS_DLINK.h
* Version 2.50
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Slave Component.
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

#if !defined(CY_SPIS_SPIS_DLINK_H)
#define CY_SPIS_SPIS_DLINK_H

#include "cytypes.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component SPI_Slave_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SPIS_DLINK_DataWidth                  (16u)
#define SPIS_DLINK_InternalTxInterruptEnabled (0u)
#define SPIS_DLINK_InternalRxInterruptEnabled (0u)
#define SPIS_DLINK_ModeUseZero                (1u)
#define SPIS_DLINK_BidirectionalMode          (0u)
#define SPIS_DLINK_Mode                       (0u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_DLINK_DATAWIDHT                (SPIS_DLINK_DataWidth)
#define SPIS_DLINK_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _SPIS_DLINK_backupStruct
{
    uint8 enableState;
    uint8 cntrPeriod;

    #if(CY_UDB_V0) /* CY_UDB_V0 */

        uint16 saveSrTxIntMask;
        uint16 saveSrRxIntMask;

    #endif /* CY_UDB_V0 */

} SPIS_DLINK_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIS_DLINK_Init(void) ;
void  SPIS_DLINK_Enable(void) ;
void  SPIS_DLINK_Start(void) ;
void  SPIS_DLINK_Stop(void) ;
void  SPIS_DLINK_EnableTxInt(void) ;
void  SPIS_DLINK_EnableRxInt(void) ;
void  SPIS_DLINK_DisableTxInt(void) ;
void  SPIS_DLINK_DisableRxInt(void) ;
void  SPIS_DLINK_SetTxInterruptMode(uint8 intSource) ;
void  SPIS_DLINK_SetRxInterruptMode(uint8 intSource) ;
uint8 SPIS_DLINK_ReadTxStatus(void) ;
uint8 SPIS_DLINK_ReadRxStatus(void) ;
void  SPIS_DLINK_WriteTxData(uint16 txData) ;

#if(SPIS_DLINK_ModeUseZero == 1u)
    void  SPIS_DLINK_WriteTxDataZero(uint16 txDataByte) \
                                              ;
#endif /* (SPIS_DLINK_ModeUseZero == 1u) */

uint16 SPIS_DLINK_ReadRxData(void) ;
uint8 SPIS_DLINK_GetRxBufferSize(void) ;
uint8 SPIS_DLINK_GetTxBufferSize(void) ;
void  SPIS_DLINK_ClearRxBuffer(void) ;
void  SPIS_DLINK_ClearTxBuffer(void) ;

#if (SPIS_DLINK_BidirectionalMode == 1u)
    void  SPIS_DLINK_TxEnable(void) ;
    void  SPIS_DLINK_TxDisable(void) ;
#endif /* SPIS_DLINK_BidirectionalMode == 1u */

void  SPIS_DLINK_PutArray(uint16 *buffer, uint8 byteCount) ;
void  SPIS_DLINK_ClearFIFO(void) ;
void  SPIS_DLINK_Sleep(void) ;
void  SPIS_DLINK_Wakeup(void) ;
void  SPIS_DLINK_SaveConfig(void) ;
void  SPIS_DLINK_RestoreConfig(void) ;

/* Communication bootloader APIs */
#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_DLINK) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
    /* Physical layer functions */
    void    SPIS_DLINK_CyBtldrCommStart(void) CYSMALL ;
    void    SPIS_DLINK_CyBtldrCommStop(void) CYSMALL ;
    void    SPIS_DLINK_CyBtldrCommReset(void) CYSMALL ;
    cystatus SPIS_DLINK_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL 
             ;
    cystatus SPIS_DLINK_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut) CYSMALL 
             ;
    
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_DLINK)
        #define CyBtldrCommStart    SPIS_DLINK_CyBtldrCommStart
        #define CyBtldrCommStop     SPIS_DLINK_CyBtldrCommStop
        #define CyBtldrCommReset    SPIS_DLINK_CyBtldrCommReset
        #define CyBtldrCommWrite    SPIS_DLINK_CyBtldrCommWrite
        #define CyBtldrCommRead     SPIS_DLINK_CyBtldrCommRead
    #endif  /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_DLINK) */
    
    /* Byte to Byte time out for detecting end of block data from host */
    #define SPIS_DLINK_BYTE2BYTE_TIME_OUT (1u)
             
#endif /* (CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_SPIS_DLINK) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */
                                                 

CY_ISR_PROTO(SPIS_DLINK_TX_ISR);
CY_ISR_PROTO(SPIS_DLINK_RX_ISR);

/* Macros for getting software status of SPIS Statusi Register */
#define SPIS_DLINK_GET_STATUS_TX(swTxSts) (uint8)(SPIS_DLINK_TX_STATUS_REG | \
                                                       (swTxSts & SPIS_DLINK_STS_CLR_ON_RD_BYTES_MASK))
#define SPIS_DLINK_GET_STATUS_RX(swRxSts) (uint8)(SPIS_DLINK_RX_STATUS_REG | \
                                                       (swRxSts & SPIS_DLINK_STS_CLR_ON_RD_BYTES_MASK))

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_DLINK_WriteByte      (SPIS_DLINK_WriteTxData)
#define SPIS_DLINK_ReadByte       (SPIS_DLINK_ReadRxData)
#define SPIS_DLINK_WriteByteZero  (SPIS_DLINK_WriteTxDataZero)
void  SPIS_DLINK_SetInterruptMode(uint8 intSource) ;
uint8 SPIS_DLINK_ReadStatus(void) ;
void  SPIS_DLINK_EnableInt(void) ;
void  SPIS_DLINK_DisableInt(void) ;


/***************************************
*           API Constants
***************************************/

#define SPIS_DLINK_TX_ISR_NUMBER     (SPIS_DLINK_TxInternalInterrupt__INTC_NUMBER)
#define SPIS_DLINK_RX_ISR_NUMBER     (SPIS_DLINK_RxInternalInterrupt__INTC_NUMBER)
#define SPIS_DLINK_TX_ISR_PRIORITY   (SPIS_DLINK_TxInternalInterrupt__INTC_PRIOR_NUM)
#define SPIS_DLINK_RX_ISR_PRIORITY   (SPIS_DLINK_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/

#define SPIS_DLINK_INT_ON_SPI_DONE    (0u << SPIS_DLINK_STS_SPI_DONE_SHIFT)
#define SPIS_DLINK_INT_ON_TX_EMPTY    (1u << SPIS_DLINK_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIS_DLINK_INT_ON_TX_NOT_FULL (0u << SPIS_DLINK_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIS_DLINK_INT_ON_BYTE_COMP   (0u << SPIS_DLINK_STS_BYTE_COMPLETE_SHIFT)

#define SPIS_DLINK_TX_INIT_INTERRUPTS_MASK  (SPIS_DLINK_INT_ON_SPI_DONE | \
                                            SPIS_DLINK_INT_ON_TX_EMPTY | SPIS_DLINK_INT_ON_TX_NOT_FULL | \
                                            SPIS_DLINK_INT_ON_BYTE_COMP)

#define SPIS_DLINK_INT_ON_RX_EMPTY     (0u << SPIS_DLINK_STS_RX_FIFO_EMPTY_SHIFT)
#define SPIS_DLINK_INT_ON_RX_NOT_EMPTY (0u << SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIS_DLINK_INT_ON_RX_OVER      (0u << SPIS_DLINK_STS_RX_FIFO_OVERRUN_SHIFT)
#define SPIS_DLINK_INT_ON_RX_FULL      (0u << SPIS_DLINK_STS_RX_FIFO_FULL_SHIFT)

#define SPIS_DLINK_RX_INIT_INTERRUPTS_MASK (SPIS_DLINK_INT_ON_RX_EMPTY | \
                                            SPIS_DLINK_INT_ON_RX_NOT_EMPTY | SPIS_DLINK_INT_ON_RX_OVER | \
                                            SPIS_DLINK_INT_ON_RX_FULL)

#define SPIS_DLINK_BITCTR_INIT           (SPIS_DLINK_DataWidth - 1u)

#define SPIS_DLINK__MODE_00 0
#define SPIS_DLINK__MODE_01 1
#define SPIS_DLINK__MODE_10 2
#define SPIS_DLINK__MODE_11 3


#define SPIS_DLINK_TXBUFFERSIZE          (4u)
#define SPIS_DLINK_RXBUFFERSIZE          (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects
*/
#define SPIS_DLINK_INIT_INTERRUPTS_MASK  (SPIS_DLINK_INT_ON_SPI_DONE | SPIS_DLINK_INT_ON_TX_EMPTY | \
                                            SPIS_DLINK_INT_ON_TX_NOT_FULL | SPIS_DLINK_INT_ON_RX_EMPTY | \
                                            SPIS_DLINK_INT_ON_RX_NOT_EMPTY | SPIS_DLINK_INT_ON_RX_OVER | \
                                            SPIS_DLINK_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#if(CY_UDB_V0)

    #define SPIS_DLINK_TXDATA_ZERO_REG           (* (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__A0_REG)

    #define SPIS_DLINK_TXDATA_ZERO_PTR           (  (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__A0_REG)

    #define SPIS_DLINK_RXDATA_ZERO_REG           (* (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMOSI_u0__A0_REG)

    #define SPIS_DLINK_RXDATA_ZERO_PTR           (  (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMOSI_u0__A0_REG)

    #define SPIS_DLINK_TXDATA_REG                (* (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__F0_REG)

    #define SPIS_DLINK_TXDATA_PTR                (  (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__F0_REG)

    #define SPIS_DLINK_RXDATA_REG                (* (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMOSI_u0__F0_REG)

    #define SPIS_DLINK_RXDATA_PTR                (  (reg16  *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMOSI_u0__F0_REG)

    #define SPIS_DLINK_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__DP_AUX_CTL_REG)
    #define SPIS_DLINK_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u0__DP_AUX_CTL_REG)

    #if(SPIS_DLINK_DataWidth > 8u)

        #define SPIS_DLINK_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u1__DP_AUX_CTL_REG)
        #define SPIS_DLINK_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_DLINK_BSPIS_es2_SPISlave_sR16_DpMISO_u1__DP_AUX_CTL_REG)

    #endif /* SPIS_DLINK_DataWidth > 8u */

#else /* CY_UDB_V0 */
	#if(CY_PSOC3 || CY_PSOC5)
	    #define SPIS_DLINK_TXDATA_ZERO_REG          (* (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

	    #define SPIS_DLINK_TXDATA_ZERO_PTR           (  (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

	    #define SPIS_DLINK_RXDATA_ZERO_REG           (* (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

	    #define SPIS_DLINK_RXDATA_ZERO_PTR           (  (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

	    #define SPIS_DLINK_TXDATA_REG                (* (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F0_REG)

	    #define SPIS_DLINK_TXDATA_PTR                (  (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F0_REG)

	    #define SPIS_DLINK_RXDATA_REG                (* (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F1_REG)

	    #define SPIS_DLINK_RXDATA_PTR                (  (reg16  *) \
	            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F1_REG)
	#else
		#if(SPIS_DLINK_DataWidth <= 8u) /* 8bit - SPIS */
			#define SPIS_DLINK_TXDATA_ZERO_REG           (* (reg8 *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

		    #define SPIS_DLINK_TXDATA_ZERO_PTR           (  (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

		    #define SPIS_DLINK_RXDATA_ZERO_REG           (* (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

		    #define SPIS_DLINK_RXDATA_ZERO_PTR           (  (reg8 *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__A0_REG)

		    #define SPIS_DLINK_TXDATA_REG                (* (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F0_REG)

		    #define SPIS_DLINK_TXDATA_PTR                (  (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F0_REG)

		    #define SPIS_DLINK_RXDATA_REG                (* (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F1_REG)

		    #define SPIS_DLINK_RXDATA_PTR                (  (reg8  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__F1_REG)
		#else /* 16bit - SPIS */
			#define SPIS_DLINK_TXDATA_ZERO_REG           (* (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_A0_REG)

		    #define SPIS_DLINK_TXDATA_ZERO_PTR           (  (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_A0_REG)

		    #define SPIS_DLINK_RXDATA_ZERO_REG           (* (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_A0_REG)

		    #define SPIS_DLINK_RXDATA_ZERO_PTR           (  (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_A0_REG)

		    #define SPIS_DLINK_TXDATA_REG                (* (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_F0_REG)

		    #define SPIS_DLINK_TXDATA_PTR                (  (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_F0_REG)

		    #define SPIS_DLINK_RXDATA_REG                (* (reg16  *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_F1_REG)

		    #define SPIS_DLINK_RXDATA_PTR                (  (reg16 *) \
		            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__16BIT_F1_REG)
		#endif /* (SPIS_DLINK_DataWidth <= 8u) */
	#endif     /* (CY_PSOC3 || CY_PSOC5) */

    #define SPIS_DLINK_TX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__DP_AUX_CTL_REG)
    #define SPIS_DLINK_TX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__DP_AUX_CTL_REG)

    #define SPIS_DLINK_RX_AUX_CONTROL_DP0_REG       (* (reg8 *) \
            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__DP_AUX_CTL_REG)
    #define SPIS_DLINK_RX_AUX_CONTROL_DP0_PTR       (  (reg8 *) \
            SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u0__DP_AUX_CTL_REG)

    #if(SPIS_DLINK_DataWidth > 8u)

        #define SPIS_DLINK_TX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u1__DP_AUX_CTL_REG)
        #define SPIS_DLINK_TX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u1__DP_AUX_CTL_REG)

        #define SPIS_DLINK_RX_AUX_CONTROL_DP1_REG   (* (reg8 *) \
                SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u1__DP_AUX_CTL_REG)
        #define SPIS_DLINK_RX_AUX_CONTROL_DP1_PTR   (  (reg8 *) \
                SPIS_DLINK_BSPIS_es3_SPISlave_sR16_Dp_u1__DP_AUX_CTL_REG)

    #endif /* SPIS_DLINK_DataWidth > 8u */

#endif /* CY_UDB_V0 */

#define SPIS_DLINK_COUNTER_PERIOD_REG    (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)
#define SPIS_DLINK_COUNTER_PERIOD_PTR    (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_BitCounter__PERIOD_REG)

#define SPIS_DLINK_TX_STATUS_MASK_REG    (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)
#define SPIS_DLINK_TX_STATUS_MASK_PTR    (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_TxStsReg__MASK_REG)

#define SPIS_DLINK_RX_STATUS_MASK_REG    (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)
#define SPIS_DLINK_RX_STATUS_MASK_PTR    (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_RxStsReg__MASK_REG)

#define SPIS_DLINK_ONE_REG               (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)
#define SPIS_DLINK_ONE_PTR               (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_dpCounter_u0__D1_REG)

#define SPIS_DLINK_TX_STATUS_REG         (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)
#define SPIS_DLINK_TX_STATUS_PTR         (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_TxStsReg__STATUS_REG)

#define SPIS_DLINK_RX_STATUS_REG         (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)
#define SPIS_DLINK_RX_STATUS_PTR         (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_RxStsReg__STATUS_REG)

#define SPIS_DLINK_COUNTER_CONTROL_REG   (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIS_DLINK_COUNTER_CONTROL_PTR   (  (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIS_DLINK_TX_STATUS_ACTL_REG    (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIS_DLINK_TX_STATUS_ACTL_PTR    (  (reg8 *) \
        SPIS_DLINK_TX_BSPIS_es3_SPISlave_TxStsReg__STATUS_AUX_CTL_REG)

#define SPIS_DLINK_RX_STATUS_ACTL_REG    (* (reg8 *) \
        SPIS_DLINK_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIS_DLINK_RX_STATUS_ACTL_PTR    (  (reg8 *) \
        SPIS_DLINK_RX_BSPIS_es3_SPISlave_RxStsReg__STATUS_AUX_CTL_REG)

#if(SPIS_DLINK_BidirectionalMode)

    #define SPIS_DLINK_CONTROL_REG       (* (reg8 *) \
   SPIS_DLINK_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)
    #define SPIS_DLINK_CONTROL_PTR       (  (reg8 *) \
   SPIS_DLINK_BSPIS_es3_SPISlave_SyncCtl_CtrlReg__CONTROL_REG)

#endif /* SPIS_DLINK_BidirectionalMode */

/* Obsolete register names. Not to be used in new designs */
#define SPIS_DLINK_TXDATA_ZERO               (SPIS_DLINK_TXDATA_ZERO_REG)
#define SPIS_DLINK_TXDATA                    (SPIS_DLINK_TXDATA_REG)
#define SPIS_DLINK_RXDATA                    (SPIS_DLINK_RXDATA_REG)
#define SPIS_DLINK_MISO_AUX_CONTROLDP0       (SPIS_DLINK_MISO_AUX_CTRL_DP0_REG)
#define SPIS_DLINK_MOSI_AUX_CONTROLDP0       (SPIS_DLINK_MOSI_AUX_CTRL_DP0_REG)
#define SPIS_DLINK_TXBUFFERREAD              (SPIS_DLINK_txBufferRead)
#define SPIS_DLINK_TXBUFFERWRITE             (SPIS_DLINK_txBufferWrite)
#define SPIS_DLINK_RXBUFFERREAD              (SPIS_DLINK_rxBufferRead)
#define SPIS_DLINK_RXBUFFERWRITE             (SPIS_DLINK_rxBufferWrite)

#if(SPIS_DLINK_DataWidth > 8u)

    #define SPIS_DLINK_MISO_AUX_CONTROLDP1   (SPIS_DLINK_MISO_AUX_CTRL_DP1_REG)
    #define SPIS_DLINK_MOSI_AUX_CONTROLDP1   (SPIS_DLINK_MOSI_AUX_CTRL_DP0_REG)

#endif /* SPIS_DLINK_DataWidth > 8u */

#define SPIS_DLINK_COUNTER_PERIOD            (SPIS_DLINK_COUNTER_PERIOD_REG)
#define SPIS_DLINK_COUNTER_CONTROL           (SPIS_DLINK_COUNTER_CONTROL_REG)
#define SPIS_DLINK_ONE                       (SPIS_DLINK_ONE_REG)
#define SPIS_DLINK_STATUS                    (SPIS_DLINK_TX_STATUS_REG)
#define SPIS_DLINK_STATUS_MASK               (SPIS_DLINK_TX_STATUS_MASK_REG)
#define SPIS_DLINK_STATUS_ACTL               (SPIS_DLINK_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SPIS_DLINK_STS_SPI_DONE_SHIFT             (0x00u)
#define SPIS_DLINK_STS_TX_FIFO_NOT_FULL_SHIFT     (0x01u)
#define SPIS_DLINK_STS_TX_FIFO_EMPTY_SHIFT        (0x02u)
#define SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x03u)
#define SPIS_DLINK_STS_RX_FIFO_EMPTY_SHIFT        (0x04u)
#define SPIS_DLINK_STS_RX_FIFO_OVERRUN_SHIFT      (0x05u)
#define SPIS_DLINK_STS_RX_FIFO_FULL_SHIFT         (0x06u)
#define SPIS_DLINK_STS_BYTE_COMPLETE_SHIFT        (0x06u)

#define SPIS_DLINK_STS_SPI_DONE                   (0x01u << SPIS_DLINK_STS_SPI_DONE_SHIFT)
#define SPIS_DLINK_STS_TX_FIFO_EMPTY              (0x01u << SPIS_DLINK_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIS_DLINK_STS_TX_FIFO_NOT_FULL           (0x01u << SPIS_DLINK_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIS_DLINK_STS_RX_FIFO_EMPTY              (0x01u << SPIS_DLINK_STS_RX_FIFO_EMPTY_SHIFT)
#define SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY          (0x01u << SPIS_DLINK_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIS_DLINK_STS_RX_FIFO_OVERRUN            (0x01u << SPIS_DLINK_STS_RX_FIFO_OVERRUN_SHIFT)
#define SPIS_DLINK_STS_RX_FIFO_FULL               (0x01u << SPIS_DLINK_STS_RX_FIFO_FULL_SHIFT)
#define SPIS_DLINK_STS_BYTE_COMPLETE              (0x01u << SPIS_DLINK_STS_BYTE_COMPLETE_SHIFT)

#define SPIS_DLINK_STS_CLR_ON_RD_BYTES_MASK       (0x61u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIS_DLINK_INT_ENABLE                     (0x10u)
#define SPIS_DLINK_FIFO_CLR                       (0x03u)

/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIS_DLINK_CNTR_ENABLE                    (0x20u)

/* Bi-Directional mode control bit */
#define SPIS_DLINK_CTRL_TX_SIGNAL_EN              (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIS_DLINK_AUX_CTRL_FIFO0_CLR             (0x00u)
#define SPIS_DLINK_AUX_CTRL_FIFO1_CLR             (0x00u)
#define SPIS_DLINK_AUX_CTRL_FIFO0_LVL             (0x00u)
#define SPIS_DLINK_AUX_CTRL_FIFO1_LVL             (0x00u)
#define SPIS_DLINK_STATUS_ACTL_INT_EN_MASK        (0x10u)

/* Obosolete Status Register Definitions *DO NOT USE IN NEW DESIGNS* */
#define SPIS_DLINK_STS_TX_BUF_NOT_FULL_SHIFT      (0x01u)
#define SPIS_DLINK_STS_TX_BUF_FULL_SHIFT          (0x02u)
#define SPIS_DLINK_STS_RX_BUF_NOT_EMPTY_SHIFT     (0x03u)
#define SPIS_DLINK_STS_RX_BUF_EMPTY_SHIFT         (0x04u)
#define SPIS_DLINK_STS_RX_BUF_OVERRUN_SHIFT       (0x05u)

#define SPIS_DLINK_STS_TX_BUF_NOT_FULL            (0x01u << SPIS_DLINK_STS_TX_BUF_NOT_FULL_SHIFT)
#define SPIS_DLINK_STS_TX_BUF_FULL                (0x01u << SPIS_DLINK_STS_TX_BUF_FULL_SHIFT)
#define SPIS_DLINK_STS_RX_BUF_NOT_EMPTY           (0x01u << SPIS_DLINK_STS_RX_BUF_NOT_EMPTY_SHIFT)
#define SPIS_DLINK_STS_RX_BUF_EMPTY               (0x01u << SPIS_DLINK_STS_RX_BUF_EMPTY_SHIFT)
#define SPIS_DLINK_STS_RX_BUF_OVERRUN             (0x01u << SPIS_DLINK_STS_RX_BUF_OVERRUN_SHIFT)

#endif  /* CY_SPIS_SPIS_DLINK_H */


/* [] END OF FILE */
