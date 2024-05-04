/***************************************************************************************************
  
  Modulo "Lib Imu CHRUM7" v0.10B
  (c) 2015 Movie Engineering

  Vedi header file.

***************************************************************************************************/

#include <stdio.h>
#include "ME_common.h"
#include "ME_lib_imu_CHRUM7.h"


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PrintPacket(BYTE *p)
{
    CHRUM7_HEADER *hp = (CHRUM7_HEADER *) p ;           // Converte il puntatore generico all'header
    
    BYTE i, len ;                                       // Lunghezza in DWORD (32bit)

  // Se "is_batch" è zero allora la lunghezza del pacchetto è 1 (cioè un 32bit che sono 4 byte) 
  // altrimenti la lunghezza in dwords è in "batch_len" (esempio: 5 vuol dire 20 bytes)

    len = hp->packet_type.has_data & !hp->packet_type.is_batch ? 
          1 : hp->packet_type.batch_len ; 


  // Stampa della parte header

    printf(CRLF"%02X ",hp->address);
    printf(hp->packet_type.has_data ? "HAS_DATA " : "NO_DATA  ");
    printf(hp->packet_type.is_batch ? "IS_BATCH " : "NO_BATCH ");
    printf("Len:%02d ", 4*hp->packet_type.batch_len );
    printf("%c", hp->packet_type.hidden ? 'H' : ' ' );
    printf(hp->packet_type.command_failed ? "   " : "OK ");

  // Stampa tutto il pacchetto in esadecimale ascii

    printf(" [");         
    for(i=0; i < sizeof(CHRUM7_HEADER)+4*len + 2 ; i++)   // Stampa anche la checksum (ultimi 2)
    {
        printf(" %02X",p[i]);
    }

    printf(" ] ");
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PacketToEuler(BYTE *p, EULER_ANGLES *e)
{
  // Per i fattori di conversione vedi datasheet del componente hardware)
  
    e->phi   = 0.0109863 * (INT) W(p[5], p[6]);   
    e->theta = 0.0109863 * (INT) W(p[7], p[8]);
    e->psi   = 0.0109863 * (INT) W(p[9], p[10]);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_RegisterIO(BOOL read, BYTE address, DWORD value, void (putchar_function)(BYTE b) )
{
    CHRUM7_HEADER h ;
    WORD checksum = 0 ;
    BYTE i, *p ;
    BOOL command = (address >= 0xAA) ;      // Stesso campo per indirizzo o comando (!)
    BOOL write = !(command || read) ;       // Scrittura solo se non è comando e non è lettura
    
  // Inizializza l'header (i pacchetti spediti e ricevuti hanno la stessa struttura)
  
    h.id[0]='s';
    h.id[1]='n';
    h.id[2]='p';
    
    h.packet_type.has_data       = write ;            // 1 = scrive, se 0 = legge/esegue 
    h.packet_type.batch_len      = (write ? 1 : 0) ;  // Lettura o comando non hanno batch
    h.packet_type.is_batch       = write ;            // Una sola DWORD cioè un solo registro
    h.packet_type.hidden         = 0 ;
    h.packet_type.command_failed = 0 ;      
    h.address                    = address ;
    
  
  // Spedisce i dati al componente (usando la funzione putchar di call-back)
 
  // ...prima l'header
 
    p = (BYTE *) &h  ;                      // Puntatore di comodo per mandare i byte 
    for (i=0; i<sizeof(h); i++)             
    {
        putchar_function(*(p+i));           // (usa la funzione di call-back)
        checksum += *(p+i) ;
    }

  // ...poi il resto del pacchetto 
  
    p = (BYTE *) &value  ;                  // Puntatore di comodo per mandare i byte 
    if (write)                              // (i 4 byte del dato solo se write e non comando.)
    {
        for (i=4; i>0; i--)         
        {   
            putchar_function(*(p+i-1));
            checksum += *(p+i-1) ;
        }
    }
    
  // ...infine la checksum complessiva
  
    putchar_function(H(checksum));          
    putchar_function(L(checksum));
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE CHRUM7_HeaderValidator(BYTE *packet)
{
    CHRUM7_HEADER *hdr = (CHRUM7_HEADER *) packet ;     // Converte il puntatore generico all'header
    BYTE length = 0 ;

    if (   (packet[0]=='s')                  // I pacchetti iniziano tutti con questi tre caratteri
        && (packet[1]=='n')
        && (packet[2]=='p'))
    {    
        if (hdr->packet_type.has_data)      // Se ha dei dati calcola la lunghezza
        {
            if (hdr->packet_type.is_batch)
                length = 7 + 4 * hdr->packet_type.batch_len ;
            else
                length = 11 ;
        }
        else                                // Se non ha dati allora la lunghezza è fissa.
        {
            length = 7 ;        
        }
    }
    else                                    // Se non è una header valida la lunghezza è nulla.
    {
        length = 0 ;
    }
    
    return length ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_PacketValidator(BYTE *packet, BYTE length)
{
    WORD checksum = 0 ;                         // L'unica verifica di integrità del pacchetto è 
    WORD i ;                                    // la checksum.
    BOOL ok ;
    
//    printf(CRLF"[ PKT (%d): ",length);        // Usato per debug estremi
   
    for( i = 0 ; i < length-2 ; i++ )           
    {
        checksum += packet[i] ;       
//        printf("%02X.",packet[i]);            // Usato per debug estremi
    }
    
//    printf("%02X.%02X",packet[length-2], packet[length-1]);   // Usato per debug estremi
//    printf(" Calc: %04X ]", checksum);

    ok = (checksum == W(packet[length-2], packet[length-1]) ); 

//    if (!ok)                                                  // Usato per debug estremi
//        printf(" * ");

    return ok ;
}


