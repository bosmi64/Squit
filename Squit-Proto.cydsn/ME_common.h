/***************************************************************************************************
  
  "Common Defines"
  (c) 2013-2014 Movie Engineering

  Nome file : ME_common.h
     Autore : Roberto Gatti 
   Versione : 0.10 Beta
       Data : 2013-04-08
 
 
  Descrizione:
  
    Definizioni comuni all'implementazione di tutti i moduli della libreria.
  
    
  Note:
  
    Le definizioni dei tipi base rendono il codice indipendente dalla piattaforma su cui
    viene compilata.
      BYTE : 8 bit senza segno
     SMALL : 8 bit con segno
      WORD : 16 bit senza segno
       INT : 16 bit con segno
     DWORD : 32 bit senza segno
      LONG : 32 bit con segno
     FLOAT : 32 bit virgola mobile
    DOUBLE : 64 bit virgola mobile


  Storia:
  
    2014-02-14 : razionalizzazione e miglioramento commenti
    
    2015-02-27 : aggiunta inclusione di "ME_printf_ovr.h"

***************************************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

#include "ME_printf_ovr.h"    
    
////  PRAGMA DEL COMPILATORE  //////////////////////////////////////////////////////////////////////

#pragma GCC diagnostic ignored "-Wpointer-sign"


////  TIPI DI DATI BASE  ///////////////////////////////////////////////////////////////////////////

typedef unsigned char    CHAR ;
typedef unsigned char    BYTE ;
typedef unsigned short   WORD ;
typedef unsigned long    DWORD ;
typedef signed   char    SMALL ;
typedef signed   short   INT ;
typedef signed   long    LONG ;
typedef          float   FLOAT ;
typedef          double  DOUBLE ;

typedef enum BOOL 
        {
            false = 0,
            true = !false 
        } BOOL ;



////  TIPI PER MANIPOLAZIONE SOTTOBIT  /////////////////////////////////////////////////////////////

// Nota:  Le union vanno adattate in base all'endian-ess del sistema e all'ordine di valutazione.

typedef union BITS16
    {
        INT signed16 ;
        WORD unsigned16 ;
        struct bytes
        { BYTE lo;
          BYTE hi;  } bytes; 
    } BITS16 ;

typedef union BITS32
    { LONG  signed32 ;
      DWORD unsigned32 ;
      FLOAT ieee32 ;
      struct words
      { BITS16 lo;
        BITS16 hi;  } words; 
    } BITS32;


////  COSTANTI  ////////////////////////////////////////////////////////////////////////////////////

// Caratteri speciali
#define CRLF   "\r\n"
#define CR     '\r'
#define LF     '\n'
#define ESCAPE 0x1b
#define CLEAR  "\033[2J"
#define HOME   "\033[0;0f"
#define NORMAL "\033[m"    
#define REVERSE "\033[7m"    

// Bit singolo da usare se variabile
#define BIT(n)   (1 << (n))

// Bit singoli costanti
#define BIT00   0x0001
#define BIT01   0x0002
#define BIT02   0x0004
#define BIT03   0x0008
#define BIT04   0x0010
#define BIT05   0x0020
#define BIT06   0x0040
#define BIT07   0x0080
#define BIT08   0x0100
#define BIT09   0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000



////  MACRO DI UTILITA' GENERALE ///////////////////////////////////////////////////////////////////


//
// Impostazione bit singoli con maschera
//

#define SET_BITS(var,mask) ((var) | (mask)) 
#define CLR_BITS(var,mask) ((var) & (~mask)) 
#define TGL_BITS(var,mask) ((var) ^ (mask)) 


//
// Conversione rapida da 16 a 8 bit e viceversa
//

#define W(H,L) ((WORD) ( ( (WORD) (H) ) << 8 ) | ((WORD) (L)) )

#define H(W) ( (BYTE) (W>>8) )
#define L(W) ( (BYTE) (W) )

//
// Altre matematiche
//

// Valore assoluto semplice
#define ABS(x) ( (x) >= 0 ? (x) : (-x))

// Rotazione di un byte di un bit a destra
#define ROR(a,n) ((a >> n) | (a << (8-n)))


// Macro comoda per stampare byte in valore binario.
//  NOTA: il byte che si passa alla macro DEVE essere una variabile, non può essere un'espressione
//
//  Utilizzo: 
//    printf("Questo è il valore binario: " BITPATTERN, BITS(b) );

#define BITPATTERN "%d%d%d%d%d%d%d%d"
#define BITS(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 


//
// Macro utili per l'uso dell'i2c (sono il bit 0 dell'indirizzo i2c, vedi specs)
//

#define I2C_WRITE 0
#define I2C_READ 1
#define I2C_ACK true
#define I2C_NAK false

        
        
#endif  // __COMMON_H__
