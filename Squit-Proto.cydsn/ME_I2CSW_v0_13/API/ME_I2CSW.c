/***************************************************************************************************
  
  I2CSW Component v0.13 Beta
  (c) 2014 Movie Engineering

  Vedi header file.
     
***************************************************************************************************/

#include "`$INSTANCE_NAME`.h"
#include "`$INSTANCE_NAME`_CTRL.h"
#include "`$INSTANCE_NAME`_STAT.h"

// Il PERIOD è il tempo totale di un singolo evento I2C (start, stop, bit, ecc...)
// PERIOD =  5 per 400 kBps
// PERIOD = 20 per 100 kBps

WORD `$INSTANCE_NAME`_PERIOD =`$PERIOD` ;


// Ritardo di un quarto di evento
#define `$INSTANCE_NAME`_Q_DELAY CyDelayUs(`$INSTANCE_NAME`_PERIOD/4);

// Ritardo di mezzo evento
#define `$INSTANCE_NAME`_H_DELAY CyDelayUs(`$INSTANCE_NAME`_PERIOD/2);

// Latch per il componente "CONTROL" di uscita per poter cambiare un solo bit alla volta.
static WORD `$INSTANCE_NAME`_ctrl_latch = 0 ;

// Definizione dei bit corrispondenti alle linee I2C per il componente "CONTROL" di uscita
#define `$INSTANCE_NAME`_SDA_PIN 0x01
#define `$INSTANCE_NAME`_SCL_PIN 0x02

// Defines di comodo per impostare le linee e leggerle (utile per tenere il sorgente indipendente)
#define `$INSTANCE_NAME`_SCL_HIGH    { `$INSTANCE_NAME`_SetPin(`$INSTANCE_NAME`_SCL_PIN); }
#define `$INSTANCE_NAME`_SCL_LOW     { `$INSTANCE_NAME`_ClrPin(`$INSTANCE_NAME`_SCL_PIN); }
#define `$INSTANCE_NAME`_SDA_HIGH    { `$INSTANCE_NAME`_SetPin(`$INSTANCE_NAME`_SDA_PIN); }
#define `$INSTANCE_NAME`_SDA_LOW     { `$INSTANCE_NAME`_ClrPin(`$INSTANCE_NAME`_SDA_PIN); }
#define `$INSTANCE_NAME`_SDA_TEST    ( (`$INSTANCE_NAME`_STAT_Read() & `$INSTANCE_NAME`_SDA_PIN) != 0  )

// Funzione per impostare una linea memorizzando nel latch
static void `$INSTANCE_NAME`_SetPin(BYTE pin)
{
    `$INSTANCE_NAME`_ctrl_latch |= pin ;
    `$INSTANCE_NAME`_CTRL_Write(`$INSTANCE_NAME`_ctrl_latch);
}

// Funzione per azzerare una linea memorizzando nel latch
static void `$INSTANCE_NAME`_ClrPin(BYTE pin)
{
    `$INSTANCE_NAME`_ctrl_latch &= (~pin);
    `$INSTANCE_NAME`_CTRL_Write(`$INSTANCE_NAME`_ctrl_latch);
}


// INIZIALIZZAZIONE

void `$INSTANCE_NAME`_InitI2C(void)
{
    `$INSTANCE_NAME`_SCL_HIGH;
    `$INSTANCE_NAME`_SDA_HIGH;
    `$INSTANCE_NAME`_H_DELAY;
}



// START SEQUENCE

void `$INSTANCE_NAME`_StartI2C(void)
{
    `$INSTANCE_NAME`_SDA_LOW;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SCL_LOW;
    `$INSTANCE_NAME`_H_DELAY;
}


// RESTART SEQUENCE

void `$INSTANCE_NAME`_RestartI2C(void)
{
    `$INSTANCE_NAME`_SDA_HIGH;
    `$INSTANCE_NAME`_Q_DELAY;
    `$INSTANCE_NAME`_SCL_HIGH;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_StartI2C();
}



// STOP SEQUENCE

void `$INSTANCE_NAME`_StopI2C(void)
{
    `$INSTANCE_NAME`_SCL_LOW;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SDA_LOW;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SCL_HIGH;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SDA_HIGH;            
    `$INSTANCE_NAME`_Q_DELAY;
}


// SEND SEQUENCE

BOOL `$INSTANCE_NAME`_SendI2C(BYTE b)
{
    WORD counter  ;           // Conta i bit in uscita (word per ottimizzare)
    BOOL ack ;                // (N)ACK in ricezione 


  // Spedisce un bit ogni clock basso
  
    for (counter = 0 ; counter < 8; counter ++)
    {
        if ( (b & 0b10000000) != 0)            /* MSBit prima */
        {
            `$INSTANCE_NAME`_SDA_HIGH;
        }
        else
        {
            `$INSTANCE_NAME`_SDA_LOW;
        }

        `$INSTANCE_NAME`_Q_DELAY;
        `$INSTANCE_NAME`_SCL_HIGH;
        `$INSTANCE_NAME`_H_DELAY;
        `$INSTANCE_NAME`_SCL_LOW;
        b <<= 1 ;
        `$INSTANCE_NAME`_H_DELAY;
    }

  
  // Legge il N(ACK) 
  
    `$INSTANCE_NAME`_SDA_HIGH;
    `$INSTANCE_NAME`_Q_DELAY;
    `$INSTANCE_NAME`_SCL_HIGH;
    if (`$INSTANCE_NAME`_SDA_TEST)
       { ack = false ; }
    else
       { ack = true ; }
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SCL_LOW;
    `$INSTANCE_NAME`_H_DELAY;

    return ack ;
}



// RECEIVE SEQUENCE

BYTE `$INSTANCE_NAME`_RecvI2C(BOOL ack)
{
    WORD counter  ;                 // Conta i bit in ingresso (word per ottimizzare)
    BYTE b = 0 ;                    // Memorizza i bit

    `$INSTANCE_NAME`_SDA_HIGH ;


  // Riceve gli 8 bit
  
    for (counter = 0 ; counter < 8 ; counter++)
    {
        `$INSTANCE_NAME`_Q_DELAY;
        `$INSTANCE_NAME`_SCL_HIGH;
        `$INSTANCE_NAME`_Q_DELAY;
        b <<= 1 ;
        if (`$INSTANCE_NAME`_SDA_TEST)
            { b |= 1 ; }
        `$INSTANCE_NAME`_Q_DELAY;
        `$INSTANCE_NAME`_SCL_LOW;
        `$INSTANCE_NAME`_Q_DELAY;
    }

  // Spedisce il N(ACK)

    if ( ack )
    {
        `$INSTANCE_NAME`_SDA_LOW ;
    }
    else
    {
        `$INSTANCE_NAME`_SDA_HIGH ;
    }

    `$INSTANCE_NAME`_Q_DELAY;
    `$INSTANCE_NAME`_SCL_HIGH;
    `$INSTANCE_NAME`_H_DELAY;
    `$INSTANCE_NAME`_SCL_LOW;
    `$INSTANCE_NAME`_H_DELAY;

    return b ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

// Funzioni per compatibilità con componente Cypress (il componente cypress sw e hw è bacato)

void `$INSTANCE_NAME`_Start(void)
{
    `$INSTANCE_NAME`_InitI2C();
}

BOOL `$INSTANCE_NAME`_MasterSendStart(BYTE address, BYTE read)
{
    `$INSTANCE_NAME`_StartI2C();
    return `$INSTANCE_NAME`_SendI2C( ( address << 1 ) | (read & 0x01));
}

BOOL `$INSTANCE_NAME`_MasterSendRestart(BYTE address, BYTE read)
{
    `$INSTANCE_NAME`_RestartI2C();
    return `$INSTANCE_NAME`_SendI2C( ( address << 1 ) | (read & 0x01));
}


void `$INSTANCE_NAME`_MasterSendStop(void)
{
    `$INSTANCE_NAME`_StopI2C();
}


void `$INSTANCE_NAME`_MasterWriteByte(BYTE b)
{
    `$INSTANCE_NAME`_SendI2C(b);
}

BYTE `$INSTANCE_NAME`_MasterReadByte(BOOL ack)
{
    return `$INSTANCE_NAME`_RecvI2C(ack);
}
