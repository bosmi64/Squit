/***************************************************************************************************
  
 Packetizer Component
 (c) 2013 Movie Engineering

 Nome file : ME_packetizer.c
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-11
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_packetizer.* per i dettagli. 
   
***************************************************************************************************/

#include <stdio.h>

#include "IMU_UM6_PACKETIZER.h"

static BYTE IMU_UM6_PACKETIZER_packet_buffer_data[32] ;     // Buffer dati privato
static PACKET_BUFFER IMU_UM6_PACKETIZER_packet_buffer ;                    // Struttura dati privata
static BOOL IMU_UM6_PACKETIZER_debug = false ;

BYTE *IMU_UM6_PACKETIZER_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv)
{
    PacketBuffer_Init(&IMU_UM6_PACKETIZER_packet_buffer, 
                      &IMU_UM6_PACKETIZER_packet_buffer_data, 
                      4, 
                      32, 
                      115, 
                      hv,
                      pv);
   
    return &IMU_UM6_PACKETIZER_packet_buffer_data ;       // Restituisce il puntatore al buffer
}                                                       // dati privato in modo da poter usare 
                                                        // i dati del pacchetto !


void IMU_UM6_PACKETIZER_ResetPacket(void)
{
    PacketBuffer_Reset(&IMU_UM6_PACKETIZER_packet_buffer);
}


BOOL IMU_UM6_PACKETIZER_BuildPacket(BYTE b)
{
    BOOL result = PacketBuffer_BuildPacket(&IMU_UM6_PACKETIZER_packet_buffer, b); 
    
    if (IMU_UM6_PACKETIZER_debug)
    {
        printf("\n--> %02bX : status=%02bX, idx=%2bd, len=%2bd <--", 
               b,
               IMU_UM6_PACKETIZER_packet_buffer.status,
               IMU_UM6_PACKETIZER_packet_buffer.idx,
               IMU_UM6_PACKETIZER_packet_buffer.len);
    }

    return result ;
}


PACKET_STATUS IMU_UM6_PACKETIZER_PacketStatus(void)
{
    return IMU_UM6_PACKETIZER_packet_buffer.status ;
}



WORD IMU_UM6_PACKETIZER_InvalidPackets(void)
{
    return IMU_UM6_PACKETIZER_packet_buffer.invalid_packets ;
}

void IMU_UM6_PACKETIZER_Debug(BOOL debug)
{
    IMU_UM6_PACKETIZER_debug = debug ;
}

/* [] END OF FILE */
