/***************************************************************************************************
  
  Componente Packetizer v0.11B
  (c) 2013-14 Movie Engineering

  Vedi header file.
  
***************************************************************************************************/

#include <stdio.h>

#include "CHRUM7_PACKETIZER.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

static BYTE CHRUM7_PACKETIZER_packet_buffer_data[32] ;  
static PACKET_BUFFER CHRUM7_PACKETIZER_packet_buffer ;                    
static BOOL CHRUM7_PACKETIZER_debug = false ;

////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE *CHRUM7_PACKETIZER_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv)
{
    PacketBuffer_Init(&CHRUM7_PACKETIZER_packet_buffer,                  // Struttura privata
                      (BYTE *) &CHRUM7_PACKETIZER_packet_buffer_data,    // Array privato
                      4,                                 // Parametro componente
                      32,                             // Parametro componente
                      115,                               // Parametro componente
                      hv,                                   // Funzione passata come parametro
                      pv);                                  // Funzione passata come parametro
   
    return (BYTE *) &CHRUM7_PACKETIZER_packet_buffer_data ;      // Restituisce il puntatore al buffer
}                                                               // dati privato in modo da poter usare 
                                                                // i dati del pacchetto !


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PACKETIZER_SetStartOfPacket(BYTE sop)
{
    CHRUM7_PACKETIZER_packet_buffer.sop = sop ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PACKETIZER_Reset(void)
{
    PacketBuffer_Reset(&CHRUM7_PACKETIZER_packet_buffer);
}


////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_PACKETIZER_BuildPacket(BYTE b)
{
    BOOL result = PacketBuffer_BuildPacket(&CHRUM7_PACKETIZER_packet_buffer, b); 

  // Nel caso di debug attivato stampa un po' di info
  
    #define DEBUG_STRING "\n--> %02X : status=%02X, idx=%2d, len=%2d <--"

    if (CHRUM7_PACKETIZER_debug)
    {
        printf(DEBUG_STRING,
               b,
               CHRUM7_PACKETIZER_packet_buffer.status,
               CHRUM7_PACKETIZER_packet_buffer.idx,
               CHRUM7_PACKETIZER_packet_buffer.len);
    }

    return result ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

PACKET_STATUS CHRUM7_PACKETIZER_PacketStatus(void)
{
    return CHRUM7_PACKETIZER_packet_buffer.status ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

WORD CHRUM7_PACKETIZER_InvalidPackets(BOOL clear)
{
    WORD val = CHRUM7_PACKETIZER_packet_buffer.invalid_packets ;
 
    if (clear)
    {
        CHRUM7_PACKETIZER_packet_buffer.invalid_packets = 0 ;
    }
    
    return val ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PACKETIZER_Debug(BOOL debug)
{
    CHRUM7_PACKETIZER_debug = debug ;
}

/* [] END OF FILE */
