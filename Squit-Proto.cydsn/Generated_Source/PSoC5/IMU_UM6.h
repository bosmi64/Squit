/***************************************************************************************************
  
 CHRUM6 Component
 (c) 2013 Movie Engineering

 Nome file : ME_imu_CHRUM6.h
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-16
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_imu_CHRUM6.* per i dettagli. 
   
***************************************************************************************************/

#include <stdio.h>

#include "cytypes.h"
#include "cyfitter.h"

// Librerie di funzioni comuni a pi� componenti o istanze.

#include "ME_common.h"
#include "ME_lib_imu_CHRUM6.h"
#include "ME_lib_packetizer.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  serial_errors_count : conteggio errori di porta seriale (errori hardware)
//                        (esportata ad uso di altri moduli)

extern WORD IMU_UM6_serial_errors_count;                       


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  InterruptServiceRoutine : raccoglie i byte in arrivo dalla porta seriale e li mette nel buffer
//                            circolare (sotto-componente).
//                            Questa funzione va inserita nel sottocomponente _ISR dopo che � stato
//                            generato il sorgente la prima volta (inserire sia il prototipo di 
//                            funzione che la chiamata vera e propria negli appositi spazi del 
//                            codice generato).
//

void IMU_UM6_InterruptServiceRoutine(void);          // da mettere nella ISR del componente



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  InitAndStart : inizializza e fa partire il componente.
//                 Dopo la chiamata di questa funzione bisogna iniziare a svuotare il buffer della
//                 seriale (con le funzioni CheckFor...) in modo da evitare overrun.
//                 Nel caso di errori del componente chiamare nuovamente questa funzione per 
//                 resettarlo.
//                 Restituisce un puntatore al buffer interno dove ci sono i dati grezzi del
//                 pacchetto (nel caso servisse andare a indagare pacchetti particolari)
//

BYTE *IMU_UM6_InitAndStart(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CheckForPacket : consuma un singolo byte dal buffer circolare del componente e inizia a 
//                   costruire un pacchetto. Si risincronizza se la comunicazione viene avviata a 
//                   met� pacchetto.
//                   Restituisce TRUE solo quando ha ricevuto completamente un pacchetto ed ha 
//                   verificato che sia valido.
//

BOOL IMU_UM6_CheckForPacket(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Error : restituisce TRUE se c'� stato un errore di overflow o underflow del buffer circolare
//          oppure se c'� stato un errore hardware di seriale.
//

BOOL IMU_UM6_Error(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PacketAddress : restituisce il campo 'address' del pacchetto presente nel buffer interno.
//                  NOTA: il pacchetto DEVE essere valido (solo se l'ultima chiamata a CheckFor..
//                  ha restituito TRUE.
//

BYTE IMU_UM6_PacketAddress(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PrintPacket : stampa su stdout il pacchetto presente nel buffer interno in formato leggibile.
//                Nota: gli ultimi due byte sono sempre la checksum
//

void IMU_UM6_PrintPacket(void);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ExecCommand : esegue un comando del componente hardware (campo address >= 0xAA, vedi datasheet).
//

void IMU_UM6_ExecCommand(BYTE command);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RegisterIO : scrive o legge da un singolo indirizzo dei registri del componente hardware (vedi
//               datasheet).
//               Nota: nel caso di lettura il componente spedisce indietro un pacchetto con il dato.
//               Nota: se il parametro read � falso allora scrive value nel registro.

void IMU_UM6_RegisterIO(BOOL read, BYTE address, DWORD value);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PacketToEuler : converte il pacchetto presente nel buffer interno in coordinate euleriane
//                  aggiornando la struttura passata per riferimento.
//                  NOTA: il pacchetto DEVE essere valido (solo se l'ultima chiamata a CheckFor..
//                  ha restituito TRUE.
//

void IMU_UM6_PacketToEuler(CHRUM6_EULER *euler_angles_ptr);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CheckForEulerPacket : come CheckForPacket, ma verifica che il pacchetto ricevuto contenga le 
//                        coordinate euleriane e nel caso effettua la conversione e riempie la 
//                        struttura passata per indirizzo.
//                        NOTA: tutti gli altri pacchetti ricevuti vengono processati ma IGNORATI.
//

BOOL IMU_UM6_CheckForEulerPacket(CHRUM6_EULER *euler_angles_ptr);



////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PrintEulerAngles : stampa in formato leggibile i valori degli angoli euleriani della struttura
//                     passata per indirizzo.
//

void IMU_UM6_PrintEulerAngles(CHRUM6_EULER *euler_angles_ptr);


//[] END OF FILE
