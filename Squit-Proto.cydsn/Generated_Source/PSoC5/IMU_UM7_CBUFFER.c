/***************************************************************************************************
  
  CBuffer Component v0.10B
  (c) 2013-14 Movie Engineering
 
  Vedi header file.
  
***************************************************************************************************/

#include "IMU_UM7_CBUFFER.h"

// Buffer dati privato del componente (impostabile da schema) 
static BYTE IMU_UM7_CBUFFER_data[128];    

// Struttura dati privata del componente
static CBUFFER IMU_UM7_CBUFFER_cbuffer ;             

///////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM7_CBUFFER_Init(void)
{
    CBuffer_Init(&IMU_UM7_CBUFFER_cbuffer, (BYTE *) &IMU_UM7_CBUFFER_data, 128);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM7_CBUFFER_PutByte(BYTE b)
{
    CBuffer_PutByte(&IMU_UM7_CBUFFER_cbuffer, b);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BYTE IMU_UM7_CBUFFER_GetByte(void)
{
    return CBuffer_GetByte(&IMU_UM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

WORD IMU_UM7_CBUFFER_AnyData(void)
{
    return CBuffer_AnyData(&IMU_UM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IMU_UM7_CBUFFER_ERROR(void)
{
    return CBuffer_ERROR(&IMU_UM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

CBUFFER_STATUS IMU_UM7_CBUFFER_Status(void)
{
    return IMU_UM7_CBUFFER_cbuffer.status ;
}


