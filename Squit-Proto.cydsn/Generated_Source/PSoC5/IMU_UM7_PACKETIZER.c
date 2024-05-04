/***************************************************************************************************
  
  Componente Packetizer v0.11B
  (c) 2013-14 Movie Engineering

  Vedi header file.
  
***************************************************************************************************/

#include <stdio.h>

#include "IMU_UM7_PACKETIZER.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

static BYTE IMU_UM7_PACKETIZER_packet_buffer_data[32] ;  
static PACKET_BUFFER IMU_UM7_PACKETIZER_packet_buffer ;                    
static BOOL IMU_UM7_PACKETIZER_debug = false ;

////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE *IMU_UM7_PACKETIZER_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv)
{
    PacketBuffer_Init(&IMU_UM7_PACKETIZER_packet_buffer,                  // Struttura privata
                      (BYTE *) &IMU_UM7_PACKETIZER_packet_buffer_data,    // Array privato
                      4,                                 // Parametro componente
                      32,                             // Parametro componente
                      115,                               // Parametro componente
                      hv,                                   // Funzione passata come parametro
                      pv);                                  // Funzione passata come parametro
   
    return (BYTE *) &IMU_UM7_PACKETIZER_packet_buffer_data ;      // Restituisce il puntatore al buffer
}                                                               // dati privato in modo da poter usare 
                                                                // i dati del pacchetto !


////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM7_PACKETIZER_SetStartOfPacket(BYTE sop)
{
    IMU_UM7_PACKETIZER_packet_buffer.sop = sop ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM7_PACKETIZER_Reset(void)
{
    PacketBuffer_Reset(&IMU_UM7_PACKETIZER_packet_buffer);
}


////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IMU_UM7_PACKETIZER_BuildPacket(BYTE b)
{
    BOOL result = PacketBuffer_BuildPacket(&IMU_UM7_PACKETIZER_packet_buffer, b); 

  // Nel caso di debug attivato stampa un po' di info
  
    #define DEBUG_STRING "\n--> %02X : status=%02X, idx=%2d, len=%2d <--"

    if (IMU_UM7_PACKETIZER_debug)
    {
        printf(DEBUG_STRING,
               b,
               IMU_UM7_PACKETIZER_packet_buffer.status,
               IMU_UM7_PACKETIZER_packet_buffer.idx,
               IMU_UM7_PACKETIZER_packet_buffer.len);
    }

    return result ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

PACKET_STATUS IMU_UM7_PACKETIZER_PacketStatus(void)
{
    return IMU_UM7_PACKETIZER_packet_buffer.status ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

WORD IMU_UM7_PACKETIZER_InvalidPackets(BOOL clear)
{
    WORD val = IMU_UM7_PACKETIZER_packet_buffer.invalid_packets ;
 
    if (clear)
    {
        IMU_UM7_PACKETIZER_packet_buffer.invalid_packets = 0 ;
    }
    
    return val ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM7_PACKETIZER_Debug(BOOL debug)
{
    IMU_UM7_PACKETIZER_debug = debug ;
}

/* [] END OF FILE */
