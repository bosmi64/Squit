/***************************************************************************************************
  
 Packetizer Component
 (c) 2013 Movie Engineering

 Nome file : ME_packetizer.h
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-11
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_packetizer.* per i dettagli. 
   
***************************************************************************************************/

#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"
#include "ME_lib_packetizer.h"

/* Esempi di validatori:
BYTE HeaderValidator(BYTE *packet);
BOOL PacketValidator(BYTE *packet, BYTE length);
*/

BYTE *IMU_UM6_PACKETIZER_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv);  // Richiede le due call-back
void IMU_UM6_PACKETIZER_ResetPacket(void);                                
BOOL IMU_UM6_PACKETIZER_BuildPacket(BYTE b);                         // Chiamare ad ogni byte ricevuto
PACKET_STATUS IMU_UM6_PACKETIZER_PacketStatus(void);
WORD IMU_UM6_PACKETIZER_InvalidPackets(void);
void IMU_UM6_PACKETIZER_Debug(BOOL debug);


//[] END OF FILE
