/***************************************************************************************************
  
  CBuffer Component v0.10B
  (c) 2013-14 Movie Engineering
 
  Vedi header file.
  
***************************************************************************************************/

#include "CHRUM7_CBUFFER.h"

// Buffer dati privato del componente (impostabile da schema) 
static BYTE CHRUM7_CBUFFER_data[128];    

// Struttura dati privata del componente
static CBUFFER CHRUM7_CBUFFER_cbuffer ;             

///////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_CBUFFER_Init(void)
{
    CBuffer_Init(&CHRUM7_CBUFFER_cbuffer, (BYTE *) &CHRUM7_CBUFFER_data, 128);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_CBUFFER_PutByte(BYTE b)
{
    CBuffer_PutByte(&CHRUM7_CBUFFER_cbuffer, b);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BYTE CHRUM7_CBUFFER_GetByte(void)
{
    return CBuffer_GetByte(&CHRUM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

WORD CHRUM7_CBUFFER_AnyData(void)
{
    return CBuffer_AnyData(&CHRUM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_CBUFFER_ERROR(void)
{
    return CBuffer_ERROR(&CHRUM7_CBUFFER_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

CBUFFER_STATUS CHRUM7_CBUFFER_Status(void)
{
    return CHRUM7_CBUFFER_cbuffer.status ;
}


