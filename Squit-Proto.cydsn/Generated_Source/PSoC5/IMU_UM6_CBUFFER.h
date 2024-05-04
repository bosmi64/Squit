/***************************************************************************************************
  
 CBuffer Component
 (c) 2013 Movie Engineering

 Nome file : ME_cbuffer.h
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-11
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_cbuffer.* per i dettagli. 
   
***************************************************************************************************/

#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"
#include "ME_lib_cbuffer.h"

void IMU_UM6_CBUFFER_Init(void);           // La dimensione del buffer � nei parametri
void IMU_UM6_CBUFFER_PutByte(BYTE b);      // Memorizza un byte nel buffer
BYTE IMU_UM6_CBUFFER_GetByte(void);        // Preleva un byte dal buffer
WORD IMU_UM6_CBUFFER_AnyData(void);        // Numero di byte nel buffer
BOOL IMU_UM6_CBUFFER_ERROR(void);          // Errore di underflow o overflow

CBUFFER_STATUS IMU_UM6_CBUFFER_Status(void);   // Vedi ME_lib_cbuffer.h per gli stati

//[] END OF FILE
