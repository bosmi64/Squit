/***************************************************************************************************
  
  Componente Packetizer 
  (c) 2013-14 Movie Engineering

  Nome file : ME_packetizer.h
     Autore : Roberto Gatti 
   Versione : 0.11 Beta
       Data : 2013-06-11
 
 
  Descrizione :
 
    Componente software per utilizzo della libreria ME_lib_packetizer.* 
    (vedere il modulo di libreria per i dettagli) 

    Esempi di prototipi di funzioni per validatori:
    
        BYTE ExampleHeaderValidator(BYTE *packet);
        BOOL ExamplePacketValidator(BYTE *packet, BYTE length);
   
   
  Storia :  
    
    2013-11-12 : aggiunta funzione cambio start of packet
    2014-02-16 : migliorati commenti e documentazione (pdf)
  
***************************************************************************************************/

#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"
#include "ME_lib_packetizer.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Init : inizializza il componente impostando le funzioni di validazione.
//
//         NOTA: questa funzione resituisce un puntatore all'array di byte in cui viene costruito
//               il pacchetto ricevuto. E' necessario quindi salvarlo per poter accedere ai dati
//               quando la funzione BuildPacket restituisce true.
//

BYTE *CHRUM7_PACKETIZER_Init(HEADER_VALIDATOR hv, PACKET_VALIDATOR pv);  // Richiede le due call-back



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Reset : ripristina il componente e i contatori interni.
//

void CHRUM7_PACKETIZER_Reset(void);                                



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  BuildPacket : funzione di costruzione e analisi del pacchetto. Viene chiamata ad ogni byte 
//                ricevuto (in modo che sia non bloccante) e si occupa di tutto il processo di 
//                individuazione dell'inizio e fine pacchetto e controllo checksum quando ha
//                ricevuto il numero di byte necessario. Riallinea automaticamente in caso di
//                perdita di sincronizzazione nella ricezione (mezzi pacchetti e simili).
//                Restituisce true solo quando un pacchetto è riconosciuto come valido e lo si
//                può leggere all'indirizzo puntato dal puntatore restituito dalla funzione Init.
//

BOOL CHRUM7_PACKETIZER_BuildPacket(BYTE b);                        



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  SetStartOfPacket : imposta il carattere di inizio pacchetto nel caso fosse necessario 
//                     modificarlo a runtime.
//

void CHRUM7_PACKETIZER_SetStartOfPacket(BYTE sop);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PacketStatus : stato attuale della macchina a stati interna del componente.
//                 (vedi libreria per i valori).
// 

PACKET_STATUS CHRUM7_PACKETIZER_PacketStatus(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  InvalidPackets : conteggio di pacchetti che hanno dato errore nella funzione di validazione.
//                   se viene passato true il conteggio viene azzerato.
//

WORD CHRUM7_PACKETIZER_InvalidPackets(BOOL clear);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Debug : Attiva/Disattiv la stampa a video i byte ricevuti e varie informazioni interne 
//

void CHRUM7_PACKETIZER_Debug(BOOL debug);


