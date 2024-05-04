/***************************************************************************************************
  
  I2CSW Component
  (c) 2014 Movie Engineering

  Nome file : ME_I2CSW.h
     Autore : Roberto Gatti 
   Versione : 0.13 Beta
       Data : 2014-03-28
 
 
  Descrizione :
 
    Componente che implementa un master I2C software su due pin qualsiasi.
    Ha un parametro che indica il periodo (la durata) di un singolo evento sul bus i2c (come ad 
    esempio una start condition e cose simili)
   
   
  Nota : 
  
    In coda a questo file ci sono alcuni appunti sul funzionamento del bus I2C
  
  
  Storia :
   
    2014-11-03 : Rivista documentazione.
   
***************************************************************************************************/

#ifndef _`$INSTANCE_NAME`_H_
#define _`$INSTANCE_NAME`_H_

#include "cytypes.h"
#include "cyfitter.h"

#include "ME_common.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  Parametri del componente PSOC 
//

// Il periodo del singolo evento sul bus è un parametro del componente.
extern WORD `$INSTANCE_NAME`_PERIOD ;


//// FUNZIONI ESPORTATE ///////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  InitI2C : inizializza il bus mettendo entrambe le linee alte.
// 

void `$INSTANCE_NAME`_InitI2C(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  StartI2C : manda una start sequence sul bus
//               SDA :  LLLL                  ____
//               SCL :  ..LL                    __
//

void `$INSTANCE_NAME`_StartI2C(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  RestartI2C : manda una restart sequence sul bus
//               SDA :  HHLLLL              --____
//               SCL :  .HHHLL               ---__
//

void `$INSTANCE_NAME`_RestartI2C(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  StopI2C : manda una stop sequence sul bus
//               SDA :  ..LLLLHHH           ____---
//               SCL :  LLLLHHHHH         ____-----
//

void `$INSTANCE_NAME`_StopI2C(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  SendI2C : manda un byte sul bus (MSBit prima) (x,y,z può essere H o L)
//               SDA : xxxxxx yyyyyy zzzzzz etc.
//               SCL : .HHHLL LHHHLL LHHHLL etc.
//            lettura (n)ack ( ? = legge ): 
//               SDA : HH????
//               SCL : .HHHLL
//

BOOL `$INSTANCE_NAME`_SendI2C(BYTE b);




////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//  RecvI2C : legge un byte dal bus (MSBit prima)
//              SDA : HH?? HH?? etc..
//              SCL : .HHL LHHL etc...
//            spedisce (n)ack (x può essere H o L ) :
//              SDA : xxxxx
//              SCL : .HHLL
//

BYTE `$INSTANCE_NAME`_RecvI2C(BOOL ack);




// Funzioni alias per compatibilità sorgenti fatti con componente Cypress
void `$INSTANCE_NAME`_Start(void);
BOOL `$INSTANCE_NAME`_MasterSendStart(BYTE address, BYTE read);
BOOL `$INSTANCE_NAME`_MasterSendRestart(BYTE address, BYTE read);
void `$INSTANCE_NAME`_MasterSendStop(void);
void `$INSTANCE_NAME`_MasterWriteByte(BYTE b);
BYTE `$INSTANCE_NAME`_MasterReadByte(BOOL ack);



////////////////////////////////////////////////////////////////////////////////////////////////////

/*

 APPUNTI SU I2C

 La linea SDA può cambiare stato solo quando la linea SCL è bassa.

 La start_sequence e la stop_sequence sono gli unici casi in cui la linea SDA cambia con SCL alto 
 (durante i trasferimenti SDA non deve mai cambiare se SCL è alto)

 start_sequence : SCL alto e SDA che va da alto a basso.
 stop_sequence  : SCL alto e SDA che va da basso ad alto

 Quando il master legge una sequenza di byte, deve mandare gli ack sempre tranne l'ultimo byte in 
 cui deve mandare nack.


 Per scrivere nei registri della periferica slave:

 1) Mandare una start-sequence
 2) Mandare l'indirizzo della periferica (pari)
 3) Mandare il numero del registro
 4) Mandare i dati (quelli che si aspetta)
 5) Mandare la stop-sequence


 Per leggere dai registri della periferica:
 
 1) Mnadare una start-sequence
 2) Mandare l'indirizzo della periferica (pari)
 3) Mandare il numero del registro
 4) Mandare un'altra start-sequence
 5) Mandare l'indirizzo della periferrica (dispari)
 6) Ricevere i dati (quelli che manda)
 7) Mandare la stop-sequence


 Queste sono solo indicazioni di massima, l'effettivo funzionamento dello specifico periferico 
 potrebbe (e di solito lo fa) variare (vedere datasheet specifico).


*/


#endif
