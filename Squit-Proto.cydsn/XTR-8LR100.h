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

/* preprocessor defines */
#define SYS_FAULTS_LOG_ENABLE	0	/* If defined the FAULT LOG code is compiled 					*/
									/*    actually the FAULT LOG code is not compiled (0)			*/

#define LORA_CMDS_VERBOSE		0	/* If defined the high level LoRa commands are verbose 			*/
									/*    actually the high level LoRa commands are not verbose (0)	*/	

/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/* XTR-8LR100 command strings definitions 																										*/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/

//======================================//
// AT									//
//======================================//
extern const char CMD_AT[];

//======================================//
// Versione dell'XTR-8LR100				//
//======================================//
extern const char CMD_AT_SHOWVERSION[];


/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
/* XTR-8LR100 access functions definitions 																									*/
/********************************************************************************************************************************************/
/********************************************************************************************************************************************/
void sendLoRaATcmd(const char *cmd);

/* isr di ricezione caratteri dall'UART LORA*/
void UART_LORA_RX_isr_process(void);


/* [] END OF FILE */