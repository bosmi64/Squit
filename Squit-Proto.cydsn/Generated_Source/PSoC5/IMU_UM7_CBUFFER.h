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

void IMU_UM7_CBUFFER_Init(void);           // La dimensione del buffer � nei parametri



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PutByte : inserisce un byte nel buffer, se non c'� errore. Se non c'� spazio genera errore.
//

void IMU_UM7_CBUFFER_PutByte(BYTE b);      



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GetByte : preleva un byte dal buffer, genera errore se il buffer � vuoto.
//

BYTE IMU_UM7_CBUFFER_GetByte(void);        // Preleva un byte dal buffer



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AnyData : restituisce il numero di byte presenti e prelevabili dal buffer.
//

WORD IMU_UM7_CBUFFER_AnyData(void);        // Numero di byte nel buffer



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Error : restituisce vero se c'� stato un errore di overflow o underflow nel buffer
//

BOOL IMU_UM7_CBUFFER_ERROR(void);          // Errore di underflow o overflow



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Status : restituisce lo stato corrente del buffer (ok, underrun, overrun).
//

CBUFFER_STATUS IMU_UM7_CBUFFER_Status(void);   // Vedi ME_lib_cbuffer.h per gli stati

