/***************************************************************************************************
  
  Modulo "Lib Packetizer"
  (c) 2013 Movie Engineering

  Nome file : ME_lib_packetizer.h
     Autore : Roberto Gatti 
   Versione : 0.10 Beta
       Data : 2013-06-11
 
 
  Descrizione :
  
    Estrae un pacchetto dati da un flusso di byte in arrivo.

    Alla libreria bisogna fornire due funzioni di call-back per validare l'header del pacchetto
    (byte di inizio, eventuali lunghezze, indirizzi, codici, ecc.) e il pacchetto stesso (ad es.
    calcolare le checksum, crc, ecc.)
    
    I dati in arrivo possono essere anche fuori sync, una volta impostato il carattere di inizio
    pacchetto la libreria pensa a risincronizzarsi perdendo meno byte e pacchetti possibile.
    La funzione che costruisce il pacchetto riceve un byte alla volta e restituisce un valore true
    alla chiamata contenente l'ultimo byte di un pacchetto valido.
    
    Questo componente ha i seguenti limiti:
    
     - L'header dei pacchetti in arrivo deve essere di lunghezza fissa (anche 1 solo byte, sop)
 
     - L'inizio dei pacchetti è segnalato da un singolo byte (ma si può sempre validare il tutto
       nella funzione di validazione del pacchetto intero o dell'header)
     
     - I pacchetti possono essere di lunghezza variabile, ma questa lunghezza deve essere presente
       nell'header (oppure estrapolata dal tipo di pacchetto, il tipo deve essere nell'header)


 Storia:
 
   2014-01-30 : miglioramento documentazione
   2015-01-28 : miglioramento documentazione, aggiunte parentesi in un if.

   
***************************************************************************************************/

#ifndef __LIB_PACKETIZER_H__
#define __LIB_PACKETIZER_H__

#include "ME_common.h"


//  TIPI  //////////////////////////////////////////////////////////////////////////////////////////

//  Tipi funzione per passare alla libreria le funzioni di call-back per validare l'header
//  e calcolare la lunghezza del pacchetto (sia nel caso fissa che variabile) e la validità
//  di un pacchetto dati ricevuto (numero di byte ricevuti uguale alla lunghezza calcolata con
//  l'altra funzione.

typedef BYTE (*HEADER_VALIDATOR) (BYTE *);
typedef BOOL (*PACKET_VALIDATOR) (BYTE *, BYTE length);


// Codici di stato del componente 

typedef enum PACKET_STATUS
{
    PACKET_WAITING    = 0x01,           // Stanno arrivando byte ma non è ancora arrivato un sop
    PACKET_RESYNCING  = 0x02,           // La validazione ha dato KO e c'è uno sop nei dati ricevuti
    PACKET_BUILDING   = 0x03,           // E' arrivato uno sop e sta accodando i byte in arrivo
    PACKET_OK         = 0x00,           // La funzione di validazione ha dato ok.
    PACKET_ERROR      = 0xFF            // C'è stato un errore da qualche parte.
} PACKET_STATUS ;



//  Struttura dati del buffer intelligente.
//
//  Nota: il buffer esterno deve essere sufficientemente grande da contenere il pacchetto più
//        grande ricevibile (in caso di lunghezze variabili).
//
//  Nota: il buffer tiene conto di un eventuale carattere di start of packet (sop) frammisto ai 
//        dati per poter recuperare prima possibile senza perdere troppi pacchetti in caso 
//        di mancanza di sync.
//
//  Nota: si considera la lunghezza dell'header dei pacchetti come fissa, anche in caso di 
//        pacchetti a lunghezza variabile, e si considera che nell'header siano presenti 
//        informazioni sufficienti a ricavare la lunghezza del pacchetto attuale.
//

typedef struct PACKET_BUFFER
{
    BYTE *buffer ;          // Puntatore ad uno spazio di memoria dove memorizzare i dati ricevuti
    BYTE idx,               // Primo spazio libero nel buffer
         sop_idx ;          // Se != 0 indice del prossimo sop all'interno del buffer     
    BYTE hlen ;             // Lunghezza header
    BYTE len,               // Lunghezza pacchetto (== max_len se non cambiato da validator)
         max_len ;          // Lunghezza massima possibile del pacchetto (e del buffer).
    BYTE sop ;              // Byte di start of packet
    PACKET_STATUS status ;  // Stato del packetizer
    WORD invalid_packets ;  // Numero di pacchetti non validi (funzione validazione falsa)
    HEADER_VALIDATOR header_validator ;  // Funzione call-back che convalida header e lunghezza
    PACKET_VALIDATOR packet_validator ;  // Funzione call-back che convalida un pacchetto intero
} PACKET_BUFFER ;




//  FUNZIONI  //////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Init : inizializza il buffer intelligente
//

void PacketBuffer_Init(PACKET_BUFFER *pb,       // Buffer strutturato con i dati dell'algoritmo
                       BYTE *buffer_ptr,        // Buffer di spazio ram vero e proprio
                       BYTE header_len,         // Lunghezza dell'header dei pacchetti (fissa)
                       BYTE max_len,            // Massima lunghezza pacchetti
                       BYTE sop,                // Byte di Start Of Packet
                       HEADER_VALIDATOR hv,     // Funzione di convalida header e calcolo lunghezza
                       PACKET_VALIDATOR pv);    // Funzione di convalida pacchetto intero

////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Reset : Ripristina i contatori interni perdendo eventuali dati non utilizzati.
//          Viene chiamata internamente in caso di overflow e in caso di pacchetto valido.
//   

void PacketBuffer_Reset(PACKET_BUFFER *rb);



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  BuildPacket : Riceve un byte alla volta:
//                - se non è già iniziato un pacchetto lo ignora
//                - se è il carattere di inizio pacchetto lo memorizza in cima al buffer
//                - se è già iniziato il pacchetto lo accoda e riempie il buffer ad ogni chiamata
//                - se è già iniziato e riceve un altro carattere di inizio memorizza la posizione
//
//                Una volta raggiunta la lunghezza dell'header, chiama la funzione di call-back 
//                per calcolare e memorizzare la lunghezza del pacchetto in arrivo
//
//                Una volta raggiunta la lunghezza del pacchetto chiama la funzione di call-back 
//                per validare l'intero pacchetto ricevuto
//
//                Restituisce TRUE solo quando ha ricevuto l'ultimo byte di un pacchetto valido.
//

BOOL PacketBuffer_BuildPacket(PACKET_BUFFER *rb, BYTE b);


#endif // __LIB_PACKETIZER_H__

