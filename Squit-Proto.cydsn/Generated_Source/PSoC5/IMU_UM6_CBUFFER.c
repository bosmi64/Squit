/***************************************************************************************************
  
 CBuffer Component
 (c) 2013 Movie Engineering

 Nome file : ME_cbuffer.c
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-11
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_cbuffer.* per i dettagli. 
   
***************************************************************************************************/

#include "IMU_UM6_CBUFFER.h"

static BYTE IMU_UM6_CBUFFER_data[1024];       // Buffer dati privato del componente
static CBUFFER IMU_UM6_CBUFFER_cbuffer ;              // Struttura dati privata del componente


void IMU_UM6_CBUFFER_Init(void)
{
    CBuffer_SetUp(&IMU_UM6_CBUFFER_cbuffer, &IMU_UM6_CBUFFER_data, 1024);
}

void IMU_UM6_CBUFFER_PutByte(BYTE b)
{
    CBuffer_Put(&IMU_UM6_CBUFFER_cbuffer, b);
}

BYTE IMU_UM6_CBUFFER_GetByte(void)
{
    return CBuffer_Get(&IMU_UM6_CBUFFER_cbuffer);
}

WORD IMU_UM6_CBUFFER_AnyData(void)
{
    return CBuffer_AnyData(&IMU_UM6_CBUFFER_cbuffer);
}

BOOL IMU_UM6_CBUFFER_ERROR(void)
{
    return CBuffer_ERROR(&IMU_UM6_CBUFFER_cbuffer);
}

CBUFFER_STATUS IMU_UM6_CBUFFER_Status(void)
{
    return IMU_UM6_CBUFFER_cbuffer.status ;
}


/* [] END OF FILE */
