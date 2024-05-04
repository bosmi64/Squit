/***************************************************************************************************
  
  Modulo "Lib Imu CHRUM7"
  (c) 2015 Movie Engineering

  Nome file : ME_lib_imu_CHRUM7.h
     Autore : Roberto Gatti 
   Versione : 0.11 Beta
       Data : 2015-01-12
 
 
  Descrizione :
  
    Implementa le funzioni di utilizzo del sensore IMU CHR-UM7.

    Il sensore comunica via seriale con un protocollo proprietario basato su scambio di pacchetti
    binari in lettura scrittura.
    
    Vengono fornite le funzioni di call-back da usare con la libreria "packetizer" in modo da
    poter trattare con pacchetti già "ben formati". (La libreria packetizer si occupa di estrapolare
    i pacchetti corretti dal flusso di dati seriali e risincronizzarsi automaticamente usando le
    funzioni di call back fornitegli).

    La libreria fornisce i meccanismi per utilizzare il componente, ma sono state sviluppate solo
    le parti utili al progetto in corso. In pratica è stata implementata solo l'impostazione del
    rateo di spedizione dei pacchetti contenenti gli angoli di eulero e la ricezione di essi.

    Questa libreria nasce dalle ceneri di quella per l'UM6 che è fuori produzione.
    

    
  Storia :
    
    2015-01-13 : Aggiornate le define dei registri
    
    2015-01-17 : Aggiunta documentazione.
    
    2015-02-12 : Aggiunti tipi per raccolta dati giroscopio, accelerometro, magnetometro.
                 Aggiunta enum per identificare i rate delle spedizioni automatiche dei dati

                
***************************************************************************************************/


#ifndef __LIB_IMU_CHRUM7_H__
#define __LIB_IMU_CHRUM7_H__

#include "ME_common.h"
#include "ME_geometry.h"


////  COSTANTI  ////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Indirizzi dei registri e dei comandi del sensore
//

#define CHRUM7_CREG_COM_SETTINGS        0x00
#define CHRUM7_CREG_COM_RATES1          0x01
#define CHRUM7_CREG_COM_RATES2          0x02
#define CHRUM7_CREG_COM_RATES3          0x03
#define CHRUM7_CREG_COM_RATES4          0x04
#define CHRUM7_CREG_COM_RATES5          0x05
#define CHRUM7_CREG_COM_RATES6          0x06
#define CHRUM7_CREG_COM_RATES7          0x07
#define CHRUM7_CREG_MISC_SETTINGS       0x08
#define CHRUM7_CREG_HOME_NORTH          0x09
#define CHRUM7_CREG_HOME_EAST           0x0A
#define CHRUM7_CREG_HOME_UP             0x0B
#define CHRUM7_CREG_GYRO_TRIM_X         0x0C
#define CHRUM7_CREG_GYRO_TRIM_Y         0x0D 
#define CHRUM7_CREG_GYRO_TRIM_Z         0x0E 
#define CHRUM7_CREG_MAG_CAL1_1          0x0F 
#define CHRUM7_CREG_MAG_CAL1_2          0x10 
#define CHRUM7_CREG_MAG_CAL1_3          0x11 
#define CHRUM7_CREG_MAG_CAL2_1          0x12 
#define CHRUM7_CREG_MAG_CAL2_2          0x13 
#define CHRUM7_CREG_MAG_CAL2_3          0x14 
#define CHRUM7_CREG_MAG_CAL3_1          0x15 
#define CHRUM7_CREG_MAG_CAL3_2          0x16 
#define CHRUM7_CREG_MAG_CAL3_3          0x17 
#define CHRUM7_CREG_MAG_BIAS_X          0x18 
#define CHRUM7_CREG_MAG_BIAS_Y          0x19 
#define CHRUM7_CREG_MAG_BIAS_Z          0x1A 
#define CHRUM7_DREG_HEALTH              0x55 
#define CHRUM7_DREG_GYRO_RAW_XY         0x56 
#define CHRUM7_DREG_GYRO_RAW_Z          0x57 
#define CHRUM7_DREG_GYRO_TIME           0x58 
#define CHRUM7_DREG_ACCEL_RAW_XY        0x59 
#define CHRUM7_DREG_ACCEL_RAW_Z         0x5A 
#define CHRUM7_DREG_ACCEL_TIME          0x5B 
#define CHRUM7_DREG_MAG_RAW_XY          0x5C 
#define CHRUM7_DREG_MAG_RAW_Z           0x5D 
#define CHRUM7_DREG_MAG_RAW_TIME        0x5E 
#define CHRUM7_DREG_TEMPERATURE         0x5F 
#define CHRUM7_DREG_TEMPERATURE_TIME    0x60 
#define CHRUM7_DREG_GYRO_PROC_X         0x61 
#define CHRUM7_DREG_GYRO_PROC_Y         0x62 
#define CHRUM7_DREG_GYRO_PROC_Z         0x63 
#define CHRUM7_DREG_GYRO_PROC_TIME      0x64 
#define CHRUM7_DREG_ACCEL_PROC_X        0x65 
#define CHRUM7_DREG_ACCEL_PROC_Y        0x66 
#define CHRUM7_DREG_ACCEL_PROC_Z        0x67 
#define CHRUM7_DREG_ACCEL_PROC_TIME     0x68 
#define CHRUM7_DREG_MAG_PROC_X          0x69 
#define CHRUM7_DREG_MAG_PROC_Y          0x6A 
#define CHRUM7_DREG_MAG_PROC_Z          0x6B 
#define CHRUM7_DREG_MAG_PROC_TIME       0x6C 
#define CHRUM7_DREG_QUAT_AB             0x6D 
#define CHRUM7_DREG_QUAT_CD             0x6E 
#define CHRUM7_DREG_QUAT_TIME           0x6F 
#define CHRUM7_DREG_EULER_PHI_THETA     0x70 
#define CHRUM7_DREG_EULER_PSI           0x71 
#define CHRUM7_DREG_EULER_PHI_THETA_DOT 0x72 
#define CHRUM7_DREG_EULER_PSI_DOT       0x73 
#define CHRUM7_DREG_EULER_TIME          0x74 
#define CHRUM7_DREG_POSITION_NORTH      0x75 
#define CHRUM7_DREG_POSITION_EAST       0x76 
#define CHRUM7_DREG_POSITION_UP         0x77 
#define CHRUM7_DREG_POSITION_TIME       0x78 
#define CHRUM7_DREG_VELOCITY_NORTH      0x79 
#define CHRUM7_DREG_VELOCITY_EAST       0x7A 
#define CHRUM7_DREG_VELOCITY_UP         0x7B 
#define CHRUM7_DREG_VELOCITY_TIME       0x7C 
#define CHRUM7_DREG_GPS_LATITUDE        0x7D 
#define CHRUM7_DREG_GPS_LONGITUDE       0x7E 
#define CHRUM7_DREG_GPS_ALTITUDE        0x7F 
#define CHRUM7_DREG_GPS_COURSE          0x80 
#define CHRUM7_DREG_GPS_SPEED           0x81 
#define CHRUM7_DREG_GPS_TIME            0x82 
#define CHRUM7_DREG_GPS_SAT_1_2         0x83 
#define CHRUM7_DREG_GPS_SAT_3_4         0x84 
#define CHRUM7_DREG_GPS_SAT_5_6         0x85 
#define CHRUM7_DREG_GPS_SAT_7_8         0x86 
#define CHRUM7_DREG_GPS_SAT_9_10        0x87 
#define CHRUM7_DREG_GPS_SAT_11_12       0x88 
#define CHRUM7_GET_FW_REVISION          0xAA 
#define CHRUM7_FLASH_COMMIT             0xAB 
#define CHRUM7_RESET_TO_FACTORY         0xAC 
#define CHRUM7_ZERO_GYROS               0xAD 
#define CHRUM7_SET_HOME_POSITION        0xAE 
#define CHRUM7_RESERVED0                0xAF 
#define CHRUM7_SET_MAG_REFERENCE        0xB0 
#define CHRUM7_RESERVED1                0xB1 
#define CHRUM7_RESERVED2                0xB2 
#define CHRUM7_RESET_EKF                0xB3 
  

// Valori validi per impostazione del baud rate
    
#define CHRUM7_BAUD_9600        0x0000
#define CHRUM7_BAUD_14400       0x1000
#define CHRUM7_BAUD_19200       0x2000
#define CHRUM7_BAUD_38400       0x3000
#define CHRUM7_BAUD_57600       0x4000
#define CHRUM7_BAUD_115200      0x5000
#define CHRUM7_BAUD_128000      0x6000
#define CHRUM7_BAUD_153600      0x7000
#define CHRUM7_BAUD_230400      0x8000
#define CHRUM7_BAUD_256000      0x9000
#define CHRUM7_BAUD_460800      0xA000
#define CHRUM7_BAUD_921600      0xB000

    

    
    
// Costanti usate nel parametro della funzione RegisterIO per indicare scrittura o lettura
    
#define CHRUM7_READ  true
#define CHRUM7_WRITE false



////  TIPI  ////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Header dei pacchetti spediti dal sensore
//

typedef struct CHRUM7_HEADER
{
    BYTE id[3];                         // è SEMPRE "snp", quindi il carattere sop è 's'
    struct PACKET_TYPE                  // Un byte, messo a zero se address è un comando.
    {
        BYTE command_failed : 1 ;       // Usato nel pacchetto di risposta a un comando
        BYTE hidden : 1 ;               // Uso interno
        BYTE batch_len : 4 ;            // Indica il numero di DWORD (non di byte) nel pacchetto
        BYTE is_batch : 1 ;             // Se è zero c'è solo una DWORD se has_data è true
        BYTE has_data : 1 ;             // Indica che ci sono dati (falso, se si legge dal sensore)
    } packet_type ;
    BYTE address ;                      // Indirizzo del registro o del comando
} CHRUM7_HEADER ;





// Tipi di data rate impostabili per spedizioni autonome di dati

typedef enum UM7_RATE_TYPE 
        {
            RATE_PROC_ACCEL,
            RATE_PROC_GYRO,
            RATE_PROC_MAG,
            RATE_QUAT,
            RATE_EULER,
            RATE_POSITION,
            RATE_VELOCITY,
            RATE_POSE
        } UM7_RATE_TYPE ;

        
// Tipo di funzione per scrivere su seriale 
typedef void (*PUTCHAR_FUNCTION_PTR)(BYTE b) ;

// Tipo per valori a virgola mobile sui tre assi
typedef struct UM7_VECTOR
        {
            FLOAT x,y,z ;
        } UM7_VECTOR ;


typedef struct UM7_PROCESSED_DATA
        {
            UM7_VECTOR gyroscope, 
                       accelerometer, 
                       magnetometer ;
        } UM7_PROCESSED_DATA ;

////  FUNZIONI  ////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PacketToEuler : converte un pacchetto valido nelle coordinate euleriane già in gradi
//

void CHRUM7_PacketToEuler(BYTE *p, EULER_ANGLES *e);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RegisterIO : scrive o legge una singola DWORD su un registro interno del sensore
//               oppure richiede di eseguire un comando (è come leggere, ma da address 0xAA in su)
//               (ha bisogno di una funzione di call-back per scrivere, di solito è la funzione
//               del sotto-componente xxx_UART_PutChar)
//

void CHRUM7_RegisterIO(BOOL read, BYTE address, DWORD value, void (putchar_function)(BYTE b));



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PrintPacket : stampa il pacchetto valido in formato leggibile
//                (gli ultimi due byte sono sempre la checksum)
//

void CHRUM7_PrintPacket(BYTE *p);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Funzioni di call-back ad uso del sotto-componente Packetizer. 
//
//  NOTA: per l'utilizzo vedere il componente e la libreria "Packetizer"
//

BYTE CHRUM7_HeaderValidator(BYTE *packet);
BOOL CHRUM7_PacketValidator(BYTE *packet, BYTE length);

#endif // __LIB_IMU_CHRUM7_H__
