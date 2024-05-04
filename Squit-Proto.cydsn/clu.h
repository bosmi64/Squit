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

//CLUs definitions
#define MAX_CLU_NUMBER 	   		50		//maximum number of CLUs 		  (0..49)
#define MAX_CLU_STEPS 	   		21		//maximum steps in a single CLU   (0..20)
#define CLU_CMDSTRING_SIZE 		25		//maximum CLU command string size (24 chars + \0)
#define MAX_CLU_SEQUENCE_STEPS	100		//CLU sequence array maximum lenght

// tipo di dato clu
typedef char clu_type[MAX_CLU_STEPS][CLU_CMDSTRING_SIZE];


// tipo di dato CLU_STATEMACHINE
struct CLU_STATEMACHINE
	{
		uint8 status;		//actual state of the SM
		uint8 clunumber;	//number of the clu is playing
		uint8 cluline;		//line of the clu is playing
		uint16 pauseticks;	//pause ticks [csec]
		uint16 pausemax;	//pause ticks maximum
		uint8  ptrap_num;	//number of PAN  trapezoid
		uint8  ttrap_num;	//number of TILT trapezoid
	};

	
//CLU Constants
#define MOVING_TO_FACE_GENERIC_CLU		10
#define GOTO_HOME_CLU					11
#define MOVING_PANORAMIC_GENERIC_CLU	12
#define MOVING_JUMP_CLU					13	
#define MOVING_PANORAMIC_STANLEY_CLU	14
#define MOVING_PANORAMIC_JJ_CLU			15
#define MOVING_TO_FACE_STANLEY_CLU		16
#define MOVING_TO_FACE_JJ_CLU			17	
#define MOVING_TO_WHEEL_GENERIC_CLU		18
#define MOVING_TO_WHEEL_STANLEY_CLU		19
#define MOVING_TO_WHEEL_JJ_CLU			20	

	
/****************************************/
/* Constant CLUs Initialization			*/
/****************************************/
void InitAllClus(void);

/****************************************/
/* Constant CLU Sequence Initialization	*/
/****************************************/
void InitCluSequence(void);

//Prints CLU number clu_number
void PrintClu(uint8 clu_number);

//Prints CLU number clu_number at step index
void PrintCluStep(uint8 clu_number, uint8 index);

//Clears all CLUs
void ClearAllClus(void);

//Checks Empty or not Empty Clu
uint8 isCluEmpty(uint8 clu_number);

#define CLU_IS_NOT_EMPTY	0
#define	CLU_IS_EMPTY		1

/* [] END OF FILE */
