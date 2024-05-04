/***************************************************************************************************
  
  Modulo "Lib CBuffer" v0.12B
  (c) 2013-2015 Movie Engineering

  Vedi header file.
 
***************************************************************************************************/

#include "ME_common.h"
#include "ME_lib_cbuffer.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

void CBuffer_Init(CBUFFER *cbuffer, BYTE *buffer_data_ptr,  WORD size)
{
    cbuffer->data_ptr = buffer_data_ptr ;       // Posizione del buffer in memoria
    cbuffer->size = size ,                      // Numero di byte usati ad iniziare da buffer_data_ptr
    cbuffer->top = 0 ;                          // La condizione di buffer vuoto iniziale è zero 
    cbuffer->bottom = 0 ;                       // in entrambi i puntatori
    cbuffer->status = CBUFFER_NOERROR ;         // Nessun errore all'inizio!
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void CBuffer_PutByte(CBUFFER *cbuffer, BYTE b)
{
    if (cbuffer->status != CBUFFER_NOERROR)     // Se c'è errore non modificare nulla
    {
        return ;
    }
    
    cbuffer->data_ptr[cbuffer->top] = b ;       // L'indice top punta sempre al primo spazio
    cbuffer->top++ ;                            // vuoto disponibile.

    if (cbuffer->top == cbuffer->size)          // Se dopo l'inserimento non c'è uno spazio vuoto
    {                                           // successivo, allora riporta all'inizio
      cbuffer->top = 0 ;
    }

    if (cbuffer->top == cbuffer->bottom)        // L'indice bottom punta sempre al primo byte  
    {                                           // utilizzabile, se top lo raggiunge vuol dire che 
        cbuffer->status = CBUFFER_OVERRUN ;     // il buffer è pieno!
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE CBuffer_GetByte(CBUFFER *cbuffer)
{
    BYTE b ;

    if (cbuffer->status != CBUFFER_NOERROR)         // Se c'è errore non modificare nulla
    {
        return 0;
    }
    
    if (cbuffer->bottom == cbuffer->top)            // Se l'indice bottom ha raggiunto il top
    {                                               // al giro prima significa che nel frattempo
        cbuffer->status = CBUFFER_UNDERRUN ;        // top non è avanzato quindi il buffer è vuoto!
        return 0 ;                                  // Non c'è niente da prelevalre: underrun.
    }

    b = cbuffer->data_ptr[cbuffer->bottom];                  
    cbuffer->bottom++ ; 

    if (cbuffer->bottom == cbuffer->size)           // Se siamo alla fine del buffer riparti dall'
    {                                               // inizio.
        cbuffer->bottom = 0 ;                       // Nota: la verifica di underrun viene fatta 
    }                                               // alla prossima richiesta perché un inserimento
                                                    // potrebbe sopraggiungere prima e far avanzare
    return b ;                                      // top.
}

////////////////////////////////////////////////////////////////////////////////////////////////////

WORD CBuffer_AnyData(CBUFFER *cbuffer)
{
    register WORD top = cbuffer->top ;              // Salva gli indici in locale per rendere più 
    register WORD bot = cbuffer->bottom ;           // efficiente il calcolo dopo.
    
    if (cbuffer->status != CBUFFER_NOERROR)         // Se c'è errore non ci sono dati disponibili
    {
        return 0 ;
    }
    
    return ( top >= bot ? 
            (top - bot) :                           // Caso semplice: sottoinsieme dell'array 
            ( cbuffer->size - (bot - top) ) ) ;     // Caso complicato: dati divisi in due sottoins.
}

