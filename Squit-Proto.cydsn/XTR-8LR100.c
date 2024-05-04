/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* PSOC Include Files */
#include <device.h>
#include <gobee.h>

/* This PRJ Include Files */
#include <XTR-8LR100.h>

/* local wars */
uint8 UART_LORA_charin;						/* Received character from UART WIFI */
uint8 UART_LORA_RxStatus;						/* WIFI UART Rx STATUS 				 */
//uint8 idx=0;
//char  xtrstring[20];

/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/* XTR-8LR100 command strings definitions 																										*/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/

//======================================//
// AT									//
//======================================//
const char CMD_AT[ ] 
	= "++++";					// simple AT


//======================================//
// Versione dell'XTR-8LR100				//
//======================================//
const char CMD_AT_SHOWVERSION[]
	= "ATS0";	// show version information


/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/* XTR-8LR100 access functions definitions 																									*/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
void sendLoRaATcmd(const char *cmd)
{
	uint8 idx;
	
	//send string until end
	for (idx=0;idx<strlen(cmd);idx++)
	{
		if (cmd[idx] == '\0')
			break;
		
		//UART_LORA_PutChar((uint8)cmd[idx]);	//UART_LORA <-- string character
		CyDelay(1);
	}
	
	//send CR+LF
	//UART_LORA_PutChar(0x0D);		//cr
	CyDelay(1);
	//UART_LORA_PutChar(0x0A);		//nl	
	CyDelay(1);
	
	//result=WaitLoRa_OK(timeout);
	
	//return result
	//   OK
	//   FAIL
	//   ERROR
	//   LORA MODULE NOT CONNECTED
}

/* isr di ricezione caratteri dall'UART LORA*/
void UART_LORA_RX_isr_process(void)
{
	/* Check for UART LORA RX communication errors			*/
	//UART_LORA_RxStatus = UART_LORA_ReadRxStatus();

#if SYS_FAULTS_LOG_ENABLE
	if (UART_LORA_RxStatus & (UART_LORA_RX_STS_PAR_ERROR |
				  			  UART_LORA_RX_STS_STOP_ERROR |
							  UART_LORA_RX_STS_OVERRUN |
							  UART_LORA_RX_STS_SOFT_BUFF_OVER))
	{
		sysFaults.general = sysFaults.general | GEN_UART_LORA_FAULT;
		sysFaults.UART_LORA_RxStatusOnError = UART_LORA_RxStatus;		/* SAVE STATUS ON ERROR	*/
		
		// FAULT LOG ONE SHOT CONTROL (fault asserted/trigger branch)
		if (sysFaults.FaultLogOneShotTrigger[GEN_UART_LORA_FAULT_LOG] == ONESHOT_TRIGGER_ENABLED)
		{
			sysFaults.FaultLogCounter[GEN_UART_LORA_FAULT_LOG]++;
			sysFaults.FaultLogOneShotTrigger[GEN_UART_LORA_FAULT_LOG] = ONESHOT_TRIGGER_DISABLED;
		}		
		
		// FAULT LOG ONE SHOT CONTROL (fault asserted/trigger branch) - parity error UART_LORA		
		if (sysFaults.UART_LORA_RxStatusOnError & UART_LORA_RX_STS_PAR_ERROR)
		{
			if (sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_ParityError_LOG] == ONESHOT_TRIGGER_ENABLED)
			{
				sysFaults.FaultLogCounter[UART_LORA_FAULT_ParityError_LOG]++;
				sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_ParityError_LOG] = ONESHOT_TRIGGER_DISABLED;
			}			
		}
		
		// FAULT LOG ONE SHOT CONTROL (fault asserted/trigger branch) - buffer overrun UART_LORA		
		if (sysFaults.UART_LORA_RxStatusOnError & UART_LORA_RX_STS_OVERRUN)
		{
			if (sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_BufferOverrunError_LOG] == ONESHOT_TRIGGER_ENABLED)
			{
				sysFaults.FaultLogCounter[UART_LORA_FAULT_BufferOverrunError_LOG]++;
				sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_BufferOverrunError_LOG] = ONESHOT_TRIGGER_DISABLED;
			}			
		}

		// FAULT LOG ONE SHOT CONTROL (fault asserted/trigger branch) - framing error UART_LORA		
		if (sysFaults.UART_LORA_RxStatusOnError & UART_LORA_RX_STS_STOP_ERROR)
		{
			if (sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_FramingError_LOG] == ONESHOT_TRIGGER_ENABLED)
			{
				sysFaults.FaultLogCounter[UART_LORA_FAULT_FramingError_LOG]++;
				sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_FramingError_LOG] = ONESHOT_TRIGGER_DISABLED;
			}			
		}	
		
		// FAULT LOG ONE SHOT CONTROL (fault asserted/trigger branch) - FIFO buffer overrun UART_LORA		
		if (sysFaults.UART_LORA_RxStatusOnError & UART_LORA_RX_STS_SOFT_BUFF_OVER)
		{
			if (sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_FIFOBufferOverrunError_LOG] == ONESHOT_TRIGGER_ENABLED)
			{
				sysFaults.FaultLogCounter[UART_LORA_FAULT_FIFOBufferOverrunError_LOG]++;
				sysFaults.FaultLogOneShotTrigger[UART_LORA_FAULT_FIFOBufferOverrunError_LOG] = ONESHOT_TRIGGER_DISABLED;
			}			
		}				
	}
//	else
//	{
	//	sysFaults.general = sysFaults.general & ~(GEN_UART_LORA_FAULT);	
//	}
#endif	//SYS_FAULTS_LOG_ENABLE

//	do 
//	{
//		UART_LORA_RxStatus = UART_LORA_ReadRxStatus();
//		UART_LORA_charin = UART_LORA_GetChar();
//	
//		/* gateway UART LORA --> UART USB			*/
//		if (UART_LORA_charin != 0)
//		{
//			UART_USB_PutChar(UART_LORA_charin);				//send feedback through console
//		}
//	}
//	while (UART_LORA_GetRxBufferSize() > 0);
}	

/* [] END OF FILE */
