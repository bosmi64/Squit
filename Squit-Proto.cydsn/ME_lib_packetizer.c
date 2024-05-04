/***************************************************************************************************
  
  Modulo "Lib Packetizer" v0.10B
  (c) 2013 Movie Engineering

  Vedi header file.
   
***************************************************************************************************/

#include "ME_common.h"
#include "ME_lib_packetizer.h"

#pragma save
#pragma optimize(5, speed)

///////////////////////////////////////////////////////////////////////////////////////////////////

void PacketBuffer_Init(PACKET_BUFFER *pb, BYTE *buffer_ptr, 
                       BYTE header_len, 
                       BYTE max_len, 
                       BYTE sop, 
                       HEADER_VALIDATOR hv,
                       PACKET_VALIDATOR pv)
{
    pb->buffer = buffer_ptr ;
    pb->idx = 0 ;
    pb->sop_idx = 0 ;
    pb->hlen = header_len ;
    pb->len = 0 ;
    pb->max_len = max_len ;
    pb->sop = sop ;
    pb->status = PACKET_WAITING ;
    pb->invalid_packets = 0 ;
    pb->header_validator = hv ;
    pb->packet_validator = pv ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void PacketBuffer_Reset(PACKET_BUFFER *pb)
{
    pb->idx = 0 ;
    pb->sop_idx = 0 ;
    pb->len = 0 ;
    pb->status = PACKET_WAITING ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////


BOOL PacketBuffer_BuildPacket(PACKET_BUFFER *pb, BYTE b)
{   
  // Se per qualunque motivo ha raggiunto il massimo del buffer interno resetta
  // (Ad esempio se non è riuscito ad individuare un'header nel flusso dati)
  
    if (pb->idx >= pb->max_len)
    {
        PacketBuffer_Reset(pb);
    }
  
  // Se alla chiamata precedente era finito un pacchetto valido allora è già
  // stato resettato il buffer e si mette in attesa di un nuovo pacchetto.
  
    if (pb->status == PACKET_OK)
    {
        pb->status = PACKET_WAITING ;
    }
    
  // La lunghezza è stata impostata (dall'header) ed è stata raggiunta, vuol dire che
  // il pacchetto ricevuto è stato considerato non valido dalla funzione di call-back
  // che valida il pacchetto, quindi  verifica se c'è in mezzo ai dati un nuovo inizio
  // di pacchetto (magari era un flusso dati fuori sync.). Se c'è trasla tutto all'inizio
  // altrimenti butta via tutto e ricomincia da zero.
  
    if ((pb->status == PACKET_ERROR) && (pb->len != 0))    
    {
        pb->status = PACKET_RESYNCING ;
        
        if (pb->sop_idx != 0)               // C'è uno start of packet in mezzo ai dati
        {
            BYTE i ;                        // Contatore per traslare il nuovo inizio all'inizio (!)
            BYTE new_sop_idx = 0 ;          // Se nel traslare c'è un altro inizio lo memorizza
            
          // Trasla tutto all'inizio
          
            for (i=0; i< (pb->len - pb->sop_idx) ; i++ )
            {
                pb->buffer[i] = pb->buffer[pb->sop_idx + i] ;
              
                if (pb->buffer[i] == pb->sop)           // Memorizza eventuale nuovo inizio
                {
                    new_sop_idx = i ;
                }
            }
            
            pb->idx = i ;                    // Il nuovo primo spazio vuoto nel buffer 
            pb->sop_idx = new_sop_idx ;      // La nuova posizione di un evenutale altro sop
        }
        else                    // Non c'è uno start of packet, ripristina tutto per nuovi dati
        {
            PacketBuffer_Reset(pb);
        }
    }


  // Verifica se il byte ricevuto è uno di quelli speciali
  
    if (b == pb->sop)           // Il byte ricevuto è start of packet
    {
        pb->status = PACKET_BUILDING ;
        
        if (pb->idx != 0)           // Se non è il primo del buffer salva l'indice per dopo 
        {
            pb->sop_idx = pb->idx ;
        }
    }
    else                        // Il byte ricevuto non è uno start of packet
    {
        if (pb->idx == 0)       // Se siamo all'inizio del pacchetto ignora i dati e ritorna
        {
            pb->status = PACKET_RESYNCING ;
            return false ;
        }
    }

  // Verificate le condizioni particolari può memorizzare normalmente ed avanzare la posizione
  // libera.
  
    pb->buffer[pb->idx] = b ;   
    pb->idx++ ;
  
  // Verifica se ha ricevuto un'header intera e se non l'aveva già processata
  
    if (    (pb->len == 0)          // Lunghezza pacchetto zero significa header non ancora ricevuta
         && (pb->header_validator != 0)         // Esiste una call-back? (per evitare inchiodamenti)
         && (pb->idx == pb->hlen ))             // Ha ricevuto sufficienti byte per un'header
    {
        pb->len = pb->header_validator(pb->buffer);         // Chiama la call-back è imposta la 
    }                                                       // lunghezza del pacchetto.
  
  // Se la lunghezza è nota verifica se è arrivato un pacchetto intero
  
    if (   (pb->idx == pb->len)                     // Se è arrivato prova a validarlo
        && (pb->packet_validator != 0) )            // Esiste una call-back? (evita inchiodamenti)
    {   
        BOOL is_valid = pb->packet_validator(pb->buffer, pb->len);  // Chiama la call-back
        
        if (is_valid)                   // Se la call-back dice che il pacchetto è buono allora
        {                               // resetta il buffer (chi usa la funzione deve usare il
            PacketBuffer_Reset(pb);     // pacchetto prima che venga chiamata di nuovo)
            pb->status = PACKET_OK ;    // (il reset mette in waiting, qui va messo in ok!)
        }
        else                            // altrimenti lo lascia come è perché potrebbe essere solo
        {                               // fuori sync e alla prossima chiamata viene traslato 
            pb->status = PACKET_ERROR ; // l'interno (se nei dati c'è uno start of packet)
            pb->invalid_packets++ ;
        }
        
        return is_valid ;               
    }
    
    return false ;                          // Altrimenti aspetta altri caratteri
}

#pragma restore

