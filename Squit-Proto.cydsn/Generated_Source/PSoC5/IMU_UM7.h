/***************************************************************************************************
  
  CHRUM6 Component
  (c) 2015 Movie Engineering

  Nome file : ME_imu_CHRUM7.h
     Autore : Roberto Gatti 
   Versione : 0.10 Beta
       Data : 2015-01-08
 
 
  Descrizione :
   
    Componente software per utilizzo della libreria della IMU Ch Robotics UM7.
    (IMU = Inertial Measurement Unit, Unità per Misure Inerziali)
    
    Vedere ME_lib_imu_CHRUM7.* per i dettagli. 
   
    

  Nota : 

    Diversamente dalla versione di questo componente per UM6, qui non è necessario scrivere a 
    mano la chiamata alla routine di interrupt di ricezione seriale nel codice generato.
    Viene fatto tutto automaticamente nella funzione InitAndStart.

    
   
  Storia :
    
    2015-01-16 : corretto parametro componente, aggiunta documentazione.

    2015-02-05 : aggiunta funzione di impostazione rates dei dati (parziale)
    
    2015-02-09 : aggiunta funzione di lettura registro 32 bit (pacchetto senza has_batch)
    
    2015-02-10 : razionalizzate lettura e scrittura registri (attende pacchetto ok su scrittura)
   
    2015-02-12 : aggiunte altre funzioni di impostazione registri e lettura diretta dati processati
                 aggiunta stampa di tutti i dati importanti letti in tempo reale dai registri
    
    2015-03-05 : migliorata documentazione nuove funzioni
    
    2015-03-10 : documentazione

***************************************************************************************************/

#ifndef PIPPO
#define PIPPO

#include <stdio.h>

#include "cytypes.h"
#include "cyfitter.h"


////  LIBRERIE UTILIZZATE  /////////////////////////////////////////////////////////////////////////

#include "ME_common.h"
#include "ME_geometry.h"
#include "ME_lib_imu_CHRUM7.h"
#include "ME_lib_cbuffer.h"
#include "ME_lib_packetizer.h"


////  PARAMETRI COMPONENTE PSOC  ///////////////////////////////////////////////////////////////////

// Frequenza con cui viene trasmesso il pacchetto dati dall'hardware in Hertz (0 = no spedizione)

#define IMU_UM7_BROADCAST_RATE 50

////  TIPI ESPORTATI  //////////////////////////////////////////////////////////////////////////////



////  VARIABILI ESPORTATE  //////////////////////////////////////////////////////////////////////////

// Conteggio errori hardware della porta seriale 
    
extern WORD IMU_UM7_serial_errors_count;                       



////  FUNZIONI ESPORTATE  //////////////////////////////////////////////////////////////////////////

    
    
    
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _WriteRegister : Manda un pacchetto con richiesta di scrittura di un valore in un registro ed 
//                   attende di ricevere il pacchetto di ack.
//                   Note:
//                    - la funzione è bloccante, ma il compoente è saldato e quindi a parte bachi 
//                      hardware o malfunzionamenti generali non dovrebbe creare problemi.
//                    - vengono ignorati e scartati eventuali pacchetti broadcast ricevuti nel 
//                      frattempo
    
BOOL IMU_UM7_WriteRegister(BYTE address, DWORD value);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _ReadRegister : Manda un pacchetto con richiesta di lettura di un valore da un registro ed
//                  attende il pacchetto con il valore.
//                  Note:
//                    - la funzione è bloccante, ma il compoente è saldato e quindi a parte bachi 
//                      hardware o malfunzionamenti generali non dovrebbe creare problemi.
//                    - vengono ignorati e scartati eventuali pacchetti broadcast ricevuti nel 
//                      frattempo
//

DWORD IMU_UM7_ReadRegister(BYTE address);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _InitAndStart : Inizializza e fa partire il componente.
//                  Dopo la chiamata di questa funzione bisogna iniziare a svuotare il buffer della
//                  seriale (con le funzioni CheckFor...) in modo da evitare overrun perché 
//                  l'hardware inizia a spedire i dati autonomamente e vengono raccolti nel buffer.
//                  Nel caso di errori del componente chiamare nuovamente questa funzione per 
//                  resettarlo.
//                  Restituisce un puntatore al buffer interno dove ci sono i dati grezzi del
//                  pacchetto (nel caso servisse andare a indagare pacchetti particolari)
//
//                  Nota: questa funzione si occupa automaticamente di impostare la routine di 
//                  interrupt per la ricezione seriale.
//                  

BYTE *IMU_UM7_InitAndStart(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _Stop : Sospende la ricezione dei pacchetti spegnendo l'interrupt in modo che non venga dato
//          alcun errore di overrun.
//

void IMU_UM7_Stop(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _CheckForPacket : Consuma un singolo byte dal buffer circolare del componente e inizia a 
//                    costruire un pacchetto. Si risincronizza se la comunicazione viene avviata a 
//                    metà pacchetto.
//                    Restituisce TRUE solo quando ha ricevuto completamente un pacchetto ed ha 
//                    verificato che sia valido.
//

BOOL IMU_UM7_CheckForPacket(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _Error : Restituisce TRUE se c'è stato un errore di overflow o underflow del buffer circolare
//           oppure se c'è stato un errore hardware di seriale.
//           Nel caso di errore per ripartire in modo pulito bisogna chiamare _InitAndStart.
//

BOOL IMU_UM7_Error(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _PacketAddress : Restituisce il campo 'address' del pacchetto presente nel buffer interno.
//                   NOTA: il pacchetto DEVE essere valido (lo è se l'ultima chiamata a CheckFor..
//                   ha restituito TRUE).
//

BYTE IMU_UM7_PacketAddress(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _PrintPacket : Stampa su stdout il pacchetto presente nel buffer interno in formato leggibile.
//                 Nota: gli ultimi due byte sono sempre la checksum
//

void IMU_UM7_PrintPacket(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// _ExecCommand : Esegue un comando del componente hardware (campo address >= 0xAA, vedi datasheet).
//                Nota: non si occupa di aspettare il pacchetto di ack
//                TODO: fare in modo che restituisca true o false se eseguito o errore

void IMU_UM7_ExecCommand(BYTE command);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _RegisterIO : Scrive o legge da un singolo indirizzo dei registri del componente hardware (vedi
//                datasheet).
//                Note: 
//                 - nel caso di lettura il componente spedisce indietro un pacchetto con il dato
//                 - se il parametro read è falso allora scrive value nel registro.
//

void IMU_UM7_RegisterIO(BOOL read, BYTE address, DWORD value);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _SetBAUD : Imposta un nuovo valore di velocità di comunicazione.
//             dopo questa chiamata bisogna cambiare velocità dal lato host altrimenti non si 
//             comunica.
//             Le costanti valide come parametro sono le seguenti:
//                CHRUM7_BAUD_9600
//                CHRUM7_BAUD_14400 
//                CHRUM7_BAUD_19200 
//                CHRUM7_BAUD_38400 
//                CHRUM7_BAUD_57600 
//                CHRUM7_BAUD_115200
//                CHRUM7_BAUD_128000
//                CHRUM7_BAUD_153600
//                CHRUM7_BAUD_230400
//                CHRUM7_BAUD_256000
//                CHRUM7_BAUD_460800
//                CHRUM7_BAUD_921600  




void IMU_UM7_SetBAUD(DWORD baudrate);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _SetRate : Imposta la frequenza di broadcast autonomo di un singolo gruppo di dati
//             Ogni gruppo può essere spedito a frequenza da 0 (non spedito) a 255 Hz.
//             I rate dei gruppi sono indipendenti ed impostabili con diverse chiamate.
//             La funzione InitAndStart imposta il broadcast degli angoli di eulero in base al 
//             valore del parametro del componente psoc.
//             Nota : fare attenzione che la somma dei byte spediti per ciascun gruppo ognuno alla 
//                    sua frequenza potrebbe eccedere la capacità di trasmissione del baud rate 
//                    impostato. Questo porta ad un blocco delle trasmissioni.
//
//             Le costanti da usare per i gruppi sono le seguenti
//                RATE_PROC_ACCEL
//                RATE_PROC_GYRO
//                RATE_PROC_MAG
//                RATE_QUAT
//                RATE_EULER
//                RATE_POSITION
//                RATE_VELOCITY
//                RATE_POSE
//
//             Vedere il datasheet per estrapolare i dati dai pacchetti ricevuti per ciascun gruppo.
//

void IMU_UM7_SetRate(UM7_RATE_TYPE UM7_RATE_TYPE, BYTE rate);


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _SetMisc :  imposta alcuni parametri generali
//                zerogyro : cerca di misurare il bias dei giroscopi all'accensione 
//                           (deve essere fermo durante l'accensione)
//                quaternion_mode : esegue usando i quaternioni e non gli angoli di eulero
//                use_magnetometer : usa il magnetometro durante gli aggiornamenti di stato
//

void IMU_UM7_SetMisc(BOOL zerogyro, BOOL quaternion_mode, BOOL use_magnetometer);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _SetGyroTrim : imposta il bias dei giroscopi che verrà aggiunto a quello misurato durante il 
//                 comando _ExecCommand(CHRUM7_ZERO_GYROS)
//                 NOTA: al momento della chiamata di questa funzione non viene eseguita alcuna
//                       modifica ai dati in uscita, è necessario eseguire il comando di calibrazione
//                       

void IMU_UM7_SetGyroTrim(FLOAT x, FLOAT y, FLOAT z);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _GetProcessedData : legge direttamente dai registri i dati elaborati ed aggiorna la struttura
//                      che gli viene passata con i dati freschi.
//

void IMU_UM7_GetProcessedData(UM7_PROCESSED_DATA *data);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _PrintSettings : stampa le impostazioni attualmente sul sensore
//

void IMU_UM7_PrintSettings(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _PrintData : legge e stampa tutti i dati 
//

void IMU_UM7_PrintData(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _PacketToEuler : Converte il pacchetto presente nel buffer interno in coordinate euleriane
//                   aggiornando la struttura passata per riferimento.
//                   NOTA: il pacchetto DEVE essere valido (solo se l'ultima chiamata a CheckFor..
//                   ha restituito TRUE.)
//

void IMU_UM7_PacketToEuler(EULER_ANGLES *euler_angles_ptr);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  _CheckForEulerPacket : come CheckForPacket, ma verifica che il pacchetto ricevuto contenga le 
//                         coordinate euleriane e nel caso effettua la conversione e riempie la 
//                         struttura passata per indirizzo.
//                         NOTA: tutti gli altri pacchetti ricevuti vengono processati ma IGNORATI.
//

BOOL IMU_UM7_CheckForEulerPacket(EULER_ANGLES *euler_angles_ptr);



#endif





