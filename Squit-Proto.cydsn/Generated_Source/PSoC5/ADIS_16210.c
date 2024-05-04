/***************************************************************************************************
  
 Acc ADIS16210 Component
 (c) 2013 Movie Engineering

 Nome file : ME_Inc_ADIS16210.c
    Autore : Roberto Gatti 
  Versione : 0.11 Beta
      Data : 2013-08-16
 
 Descrizione :
   Componente software per utilizzo della libreria dei componenti ADIS16210 e ADIS1626x
   Vedere:
     ME_lib_acc_ADIS16210.*  
     ME_lib_gyr_ADIS1626x.*  
     
***************************************************************************************************/

#include <stdio.h>

#include "ADIS_16210.h"
#include "ADIS_16210_SPI.h"


#define SPI_STALL_TIME_US       60
#define SPI_READ                ((WORD) ADIS_16210_SPI_ReadRxData())
#define SPI_WRITE(w)            ADIS_16210_SPI_WriteTxData(w)
#define SPI_RX_BUFFER_NOT_EMPTY (ADIS_16210_SPI_GetRxBufferSize()!=0)
#define SPI_WAIT_STALL          CyDelayUs(SPI_STALL_TIME_US)
#define SPI_WAIT_RX_BUFFER      while (!SPI_RX_BUFFER_NOT_EMPTY);

    
void ADIS_16210_Start(void)
{
    ADIS_16210_SPI_Start();
    CyDelay(160);        // Minimo per inizializzazione (startup-time)
}


WORD ADIS_16210_ReadReg(BYTE address)
{
    SPI_WAIT_STALL ; 
    SPI_WRITE(W(address , 0));
    
    SPI_WAIT_STALL ; 
    SPI_WRITE(W(address, 0));
    
    SPI_WAIT_RX_BUFFER;
    SPI_READ ;  // Butta via
    
    SPI_WAIT_RX_BUFFER;
    return SPI_READ ;
}

void ADIS_16210_WriteReg(BYTE address, WORD value)
{
    SPI_WAIT_STALL ; 
    SPI_WRITE(0x8000 | W(address, L(value)));

    SPI_WAIT_RX_BUFFER;
    SPI_READ ;  // Butta via
    
    SPI_WAIT_STALL ; 
    SPI_WRITE(0x8000 | W(address+1, H(value)));
    
    SPI_WAIT_RX_BUFFER;
    SPI_READ ;  // Butta via
}




BYTE ADIS_16210_registers[MAX_READS];
WORD ADIS_16210_data[MAX_READS];

static BYTE ADIS_16210_number_of_reads ;
static int ADIS_16210_step = 0 ;


void ADIS_16210_StartPolling(BYTE number_of_reads)
{
    ADIS_16210_number_of_reads = number_of_reads ;
    ADIS_16210_step = 0 ;
    SPI_WAIT_STALL ;       // Per concatenare le letture.
    SPI_WRITE(W(ADIS_16210_registers[0],0));
}

void ADIS_16210_StopPolling(void)
{
    SPI_WAIT_RX_BUFFER;
    SPI_READ ;
}


BOOL ADIS_16210_PollForSingle(void)
{
    static BOOL waiting = false ;           // Una volta si e una no
    BOOL result = false ;
    
    if (SPI_RX_BUFFER_NOT_EMPTY)
    {
        if (!waiting)
        {
            ADIS_16210_data[0] = SPI_READ ;

            result = true ;

        //    SPI_WAIT_STALL ;          // Per non bloccare il controllo, ma ogni due giri
            SPI_WRITE(W(ADIS_16210_registers[0],0));
        }
        
        waiting = !waiting ;
    }
     
    return result ;    
}


BOOL ADIS_16210_PollForMulti(void)
{
    static BOOL waiting = false ;           // Una volta si e una no
    BOOL result = false ;
    INT r_step = 0 ;
    
    if (SPI_RX_BUFFER_NOT_EMPTY)
    {
        if (!waiting)
        {
            r_step = ADIS_16210_step - 1 ;
            
            if (r_step < 0 ) 
            {
                r_step += ADIS_16210_number_of_reads ;
            }  
            
            ADIS_16210_data[r_step] = SPI_READ ;

            ADIS_16210_step++;

            if ( ADIS_16210_step >= ADIS_16210_number_of_reads )
            {
                result = true ;
                ADIS_16210_step = 0 ;
            }

        //    SPI_WAIT_STALL ;          // Per non bloccare il controllo, ma ogni due giri
            SPI_WRITE(W(ADIS_16210_registers[ADIS_16210_step],0));
        }
        
        waiting = !waiting ;
    }
     
    return result ;    
}


void ADIS_16210_ADIS16210_PrintDiagStat(void)
{
    ADIS16210_PrintDiagStat(ADIS_16210_ReadReg(ADIS16210_DIAG_STAT));
}

void ADIS_16210_ADIS1626x_PrintDiagStat(void)
{
    ADIS1626x_PrintDiagStat(ADIS_16210_ReadReg(ADIS1626x_DIAG_STAT));
}


/* [] END OF FILE */
