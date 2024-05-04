/***************************************************************************************************
  
  CBuffer Component v0.10B
  (c) 2013-14 Movie Engineering
 
  Vedi header file.
  
***************************************************************************************************/

#include "`$INSTANCE_NAME`.h"

// Buffer dati privato del componente (impostabile da schema) 
static BYTE `$INSTANCE_NAME`_data[`$CBUFFER_SIZE`];    

// Struttura dati privata del componente
static CBUFFER `$INSTANCE_NAME`_cbuffer ;             

///////////////////////////////////////////////////////////////////////////////////////////////////

void `$INSTANCE_NAME`_Init(void)
{
    CBuffer_Init(&`$INSTANCE_NAME`_cbuffer, (BYTE *) &`$INSTANCE_NAME`_data, `$CBUFFER_SIZE`);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void `$INSTANCE_NAME`_PutByte(BYTE b)
{
    CBuffer_PutByte(&`$INSTANCE_NAME`_cbuffer, b);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BYTE `$INSTANCE_NAME`_GetByte(void)
{
    return CBuffer_GetByte(&`$INSTANCE_NAME`_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

WORD `$INSTANCE_NAME`_AnyData(void)
{
    return CBuffer_AnyData(&`$INSTANCE_NAME`_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

BOOL `$INSTANCE_NAME`_ERROR(void)
{
    return CBuffer_ERROR(&`$INSTANCE_NAME`_cbuffer);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

CBUFFER_STATUS `$INSTANCE_NAME`_Status(void)
{
    return `$INSTANCE_NAME`_cbuffer.status ;
}


