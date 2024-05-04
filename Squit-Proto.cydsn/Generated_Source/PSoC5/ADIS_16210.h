/***************************************************************************************************
  
 Inc ADIS162xx Component
 (c) 2013 Movie Engineering

 Nome file : ME_Inc_ADIS162xx.h
    Autore : Roberto Gatti 
  Versione : 0.11 Beta
      Data : 2013-07-13
 
 Descrizione :
   Componente software per utilizzo della libreria.
   
***************************************************************************************************/


#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"
#include "ME_geometry.h"
#include "ME_lib_acc_ADIS16210.h"
#include "ME_lib_gyr_ADIS1626x.h"


#define MAX_READS 6
extern BYTE ADIS_16210_registers[MAX_READS];
extern WORD ADIS_16210_data[MAX_READS];





void ADIS_16210_Start(void);

WORD ADIS_16210_ReadReg(BYTE address);
void ADIS_16210_WriteReg(BYTE address, WORD value);

void ADIS_16210_StartPolling(BYTE number_of_reads);
void ADIS_16210_StopPolling(void);

BOOL ADIS_16210_PollForMulti(void);
BOOL ADIS_16210_PollForSingle(void);

void ADIS_16210_ADIS16210_PrintDiagStat(void);
void ADIS_16210_ADIS1626x_PrintDiagStat(void);


//[] END OF FILE
