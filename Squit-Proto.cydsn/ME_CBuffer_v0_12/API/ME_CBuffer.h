/***************************************************************************************************
  
 CBuffer Component
 (c) 2013-2014 Movie Engineering

 Nome file : ME_cbuffer.h
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-11
 
 Descrizione :
 
   Componente software per utilizzo della libreria che implementa il buffer circolare.
   
   
***************************************************************************************************/

#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"
#include "ME_lib_cbuffer.h"


////  FUNZIONI ESPORTATE  //////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Init: Inizializza il buffer circolare, svuotandolo.
//

void `$INSTANCE_NAME`_Init(void);           // La dimensione del buffer è nei parametri



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PutByte : inserisce un byte nel buffer, se non c'è errore. Se non c'è spazio genera errore.
//

void `$INSTANCE_NAME`_PutByte(BYTE b);      



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GetByte : preleva un byte dal buffer, genera errore se il buffer è vuoto.
//

BYTE `$INSTANCE_NAME`_GetByte(void);        // Preleva un byte dal buffer



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AnyData : restituisce il numero di byte presenti e prelevabili dal buffer.
//

WORD `$INSTANCE_NAME`_AnyData(void);        // Numero di byte nel buffer



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Error : restituisce vero se c'è stato un errore di overflow o underflow nel buffer
//

BOOL `$INSTANCE_NAME`_ERROR(void);          // Errore di underflow o overflow



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Status : restituisce lo stato corrente del buffer (ok, underrun, overrun).
//

CBUFFER_STATUS `$INSTANCE_NAME`_Status(void);   // Vedi ME_lib_cbuffer.h per gli stati

