/***************************************************************************************************
 
  Printf Override
  (c) 2013 Movie Engineering

  Nome File: ME_printf_ovr.h
     Autore: Roberto Gatti 
   Versione: 0.10 Beta
       Data: 2013-07-01
 
 
   Descrizione:
   
     Macro per ridefinire l'uso della funzione printf standard e redirigerla sulla seriale.
 
 
   Uso:
   
     Nel main, fuori dalle funzioni, usare (se la uart si chiama CONSOLE):

      PRINTF_OVERRIDE(CONSOLE)
        
        
   Note:
   
     Se si usa il PSOC5 il compilatore GCC usa una libreria che di default ha il buffering
     di linea abilitato per le printf. 
   
     Per avere l'output sul singolo carattere in una singola printf è necessario chiamare:
   
       setvbuf(stdout, 0, _IONBF, 0);
    
     prima della prima printf in modo da disabilitare il buffering e quindi ottenere la stampa
     dei caratteri subito dopo l'esecuzione delle printf, senza aspettare che ci sia un finelinea.


   Storia:
   
     2013-11-03 : migliorati commenti
     
***************************************************************************************************/

#ifndef __PRINTF_OVR_H__
#define __PRINTF_OVR_H__


////  PSOC 3  /////////////////////////////////////////////////////////////////////////////////////

#ifdef __C51__

#define PRINTF_OVERRIDE(uart)   char putchar (char c)       \
                                { uart ## _PutChar(c);      \
                                  return c ; }
#endif  // __C51__



////  PSOC 5  /////////////////////////////////////////////////////////////////////////////////////

#ifdef __GNUC__

#include <sys/stat.h>              
#define PRINTF_OVERRIDE(uart)     int _write(int file, char *ptr, int len)      \
                                  { int todo;                                   \
                                    for (todo = 0; todo < len; todo++)          \
                                    { uart ## _PutChar(*ptr++); }               \
                                    return len; }                               \
                                                                                \
                                  int _read(int file, char *ptr, int len)       \
                                  { return 0; }                                 \
                                                                                \
                                  int _fstat(int file, struct stat *st)         \
                                  { st->st_mode = S_IFCHR;                      \
                                    return 0; }                                 \
                                                                                \
                                  int _close(int file)                          \
                                  { return -1; }                                \
                                                                                \
                                  int _isatty(int file)                         \
                                  { return 1; }                                 \
                                                                                \
                                  int _lseek(int file, int ptr, int dir)        \
                                  { return 0; }

#endif  // __GNUC__
                                                                            

        
        
#endif  // __PRINTF_OVR_H__
