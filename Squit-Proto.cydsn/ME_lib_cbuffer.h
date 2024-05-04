/***************************************************************************************************
  
  Modulo "Lib CBuffer"
  (c) 2013-2015 Movie Engineering

  Nome file : ME_lib_cbuffer.h
     Autore : Roberto Gatti 
   Versione : 0.12 Beta
       Data : 2013-06-20
  
  
  Descrizione :
  
    Implementa un buffer FIFO circolare in cui si mettono e prendono byte senza doversi preoccupare
    dei contatori di fine e inizio buffer.
    Vengono generati errori di overflow e underflow se si preleva da un buffer vuoto o inserisce in 
    uno pieno.
    L'array dove vengono memorizzati i dati è esterno alla struttura e bisogna allocarlo e indicarlo 
    alla funzione di inizializzazione, assieme alla sua lunghezza.
    
    Internamente è implementato con due puntatori di top e bottom, quando si inserisce viene 
    incrementato top e quando si preleva viene incrementato bottom. Entrambi i puntatori ciclano
    a zero una volta raggiunta la fine dell'array.
    Top indica sempre la prima posizione vuota, Bottom indica sempre la posizione del byte inserito
    da più tempo.
    
     Caso semplice:                          Caso complicato:                
      +------------+                          +------------+                 
      |            | <--- 0                   |   byte 2   | <--- 0        
      |            |                          |   byte 3   |                
      +------------+                          +------------+                 
      |   byte 0   | <--- BOTTOM              |            | <--- TOP      
      |   byte 1   |                          |            |                 
      +------------+                          +------------+                 
      |            | <--- TOP                 |   byte 0   | <--- BOTTOM   
      |            |                          |   byte 1   |                 
      +------------+ <--- Size                +------------+ <--- Size        
 
 
 
  Storia :
  
    2013-06-20 : ottimizzata put perché se usata negli interrupt era troppo lenta.
    2013-08-14 : migliorati commenti e documentazione, rinominate alcune funzioni
    2013-11-03 : tolte defines per ottimizzazioni compilatore C51 (obsolete)
    2015-01-27 : ripuliti alcuni commenti, aggiunte parentesi negli if singoli.
    
***************************************************************************************************/

#ifndef __LIB_CBUFFER_H__
#define __LIB_CBUFFER_H__

#include "ME_common.h"


////  TIPI  ////////////////////////////////////////////////////////////////////////////////////////

// Possibili codici di errore.
typedef enum CBUFFER_STATUS
{
    CBUFFER_NOERROR  = 0x00,     // Nessun errore
    CBUFFER_OVERRUN  = 0xFF,     // Si è tentato di scrivere in un buffer pieno
    CBUFFER_UNDERRUN = 0xEE      // Si è tentato di leggere da un buffer vuoto
} CBUFFER_STATUS ;


// Struttura dati del buffer circolare
typedef struct CBUFFER
{
    BYTE *data_ptr ;            // Puntatore ai dati veri e propri
    WORD top, bottom, size ;    // Cima e fondo correnti, grandezza massima del buffer
    CBUFFER_STATUS status ;     // Stato di errore
} CBUFFER ;


////  FUNZIONI  ////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Init : usata sia per inizializzare che per resettare.
//         - azzera il buffer
//         - mette a no error lo status
//

void CBuffer_Init(CBUFFER *cbuffer, BYTE *buffer_data_ptr, WORD size);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PutByte : inserisce un byte nel buffer
//             - lo status viene messo a overrun se non c'è spazio
//

void CBuffer_PutByte(CBUFFER *cbuffer, BYTE b);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GetByte : preleva un byte dal buffer
//

BYTE CBuffer_GetByte(CBUFFER *cbuffer);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AnyData : restituisce zero se il buffer è vuoto altrimenti il numero di byte presenti
//

WORD CBuffer_AnyData(CBUFFER *cbuffer);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ERROR : vera se c'è stato un qualche errore
//

#define CBuffer_ERROR(cb) ((cb)->status != CBUFFER_NOERROR)


#endif // __LIB_CBUFFER_H__

