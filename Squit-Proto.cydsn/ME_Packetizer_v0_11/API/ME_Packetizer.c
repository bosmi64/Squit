/***************************************************************************************************
  
  Componente Packetizer v0.11B
  (c) 2013-14 Movie Engineering

  Vedi header file.
  
***************************************************************************************************/

#include <stdio.h>

#include "`$INSTANCE_NAME`.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

static BYTE `$INSTANCE_NAME`_packet_buffer_data[`$MAX_PACKET_LENGTH`] ;  
static PACKET_BUFFER `$INSTANCE_NAME`_packet_buffer ;                    
static BOOL `$INSTANCE_NAME`_debug = false ;

////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE *`$INSTANCE_NAME`_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv)
{
    PacketBuffer_Init(&`$INSTANCE_NAME`_packet_buffer,                  // Struttura privata
                      (BYTE *) &`$INSTANCE_NAME`_packet_buffer_data,    // Array privato
                      `$HEADER_LENGTH`,                                 // Parametro componente
                      `$MAX_PACKET_LENGTH`,                             // Parametro componente
                      `$START_OF_PACKET`,                               // Parametro componente
                      hv,                                   // Funzione passata come parametro
                      pv);                                  // Funzione passata come parametro
   
    return (BYTE *) &`$INSTANCE_NAME`_packet_buffer_data ;      // Restituisce il puntatore al buffer
}                                                               // dati privato in modo da poter usare 
                                                                // i dati del pacchetto !


////////////////////////////////////////////////////////////////////////////////////////////////////

void `$INSTANCE_NAME`_SetStartOfPacket(BYTE sop)
{
    `$INSTANCE_NAME`_packet_buffer.sop = sop ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void `$INSTANCE_NAME`_Reset(void)
{
    PacketBuffer_Reset(&`$INSTANCE_NAME`_packet_buffer);
}


////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL `$INSTANCE_NAME`_BuildPacket(BYTE b)
{
    BOOL result = PacketBuffer_BuildPacket(&`$INSTANCE_NAME`_packet_buffer, b); 

  // Nel caso di debug attivato stampa un po' di info
  
    #define DEBUG_STRING "\n--> %02X : status=%02X, idx=%2d, len=%2d <--"

    if (`$INSTANCE_NAME`_debug)
    {
        printf(DEBUG_STRING,
               b,
               `$INSTANCE_NAME`_packet_buffer.status,
               `$INSTANCE_NAME`_packet_buffer.idx,
               `$INSTANCE_NAME`_packet_buffer.len);
    }

    return result ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

PACKET_STATUS `$INSTANCE_NAME`_PacketStatus(void)
{
    return `$INSTANCE_NAME`_packet_buffer.status ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

WORD `$INSTANCE_NAME`_InvalidPackets(BOOL clear)
{
    WORD val = `$INSTANCE_NAME`_packet_buffer.invalid_packets ;
 
    if (clear)
    {
        `$INSTANCE_NAME`_packet_buffer.invalid_packets = 0 ;
    }
    
    return val ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void `$INSTANCE_NAME`_Debug(BOOL debug)
{
    `$INSTANCE_NAME`_debug = debug ;
}

/* [] END OF FILE */
