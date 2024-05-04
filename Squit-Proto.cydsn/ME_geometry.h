/***************************************************************************************************
  
  Modulo "Geometry"
  (c) 2013-2015 Movie Engineering

  Nome file : ME_geometry.h
     Autore : Roberto Gatti 
   Versione : 0.20 Beta
       Data : 2013-06-24
 
 
  Descrizione :
  
    Funzioni di calcolo geometrico/fisico.


  Storia :   
  
    2013-11-03 : modifica commenti
    2014-02-13 : aggiunte e commenti
    2014-07-29 : aggiunto tipo di dati e funzioni per ANGULAR
    2014-10-29 : migliorata documentazione
    2015-01-28 : aggiornato copyright
    
***************************************************************************************************/

#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "ME_common.h"

////  COSTANTI  ////////////////////////////////////////////////////////////////////////////////////

// PiGreco Mezzi
#define       PI_2 1.57079632679489661923

// Da radianti a gradi
#define RAD_TO_DEG 57.295779513082325
 

////  TIPI  ////////////////////////////////////////////////////////////////////////////////////////

// Struttura per angoli multigiro a partire da dati -180 +180
    
// Rappresenta un angolo in gradi anche superiori a 360 o inferiori a -360 a partire dalla 
// ricezione di un valore tra -180 e +180. In pratica viene tenuto il valore precedente misurato
// tra -180 e +180 e viene calcolata la variazione con il valore attuale e la variazione usata
// per incrementare o decrementare il valore finale senza limiti.
// NOTA: viene usata per avere il valore di giri a partire da dati giroscopici (?)

typedef struct ANGULAR
        {
           DOUBLE value ;       // Valore dell'angolo in gradi (anche maggiori e multipli di 360)
            FLOAT old_raw ;     // Vecchio valore grezzo di incremento
            FLOAT offset ;      // Semplice offset di azzeramento sul valore "value" quando si 
                                // legge con la funzione angular_get
        } ANGULAR ;


// Angoli di eulero per rotazioni
        
typedef struct EULER_ANGLES
        {
            FLOAT phi ;
            FLOAT theta ;
            FLOAT psi ;
        } EULER_ANGLES ;        
   
        
// Quaternioni per rotazioni 
        
typedef struct QUATERNION
        {
            FLOAT w,x,y,z ;
        } QUATERNION ;


// Accelerazioni lineari
        
typedef struct ACCELERATION
        {
            FLOAT x, y, z ;
        } ACCELERATION ;

        
        
        
////  FUNZIONI  ////////////////////////////////////////////////////////////////////////////////////
        
        
////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  offset_heading : funzione di offset ed eliminazione della discontinuità negli angoli per sensori
//                   che restituiscono 0..3599 
//                   La posizione passata come offset è il punto di zero.
//                   Il punto assoluto di discontinuità 3599 a 0 viene evitato e i valori restituiti
//                   sono tra -1799 e 1799.

INT offset_heading(WORD raw, WORD offset);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  euler_rad_to_deg : converte una struttura di angoli di eulero considerati in radianti nell'
//                     equivalmente in gradi, sovrascrive i dati.
//

void euler_rad_to_deg(EULER_ANGLES *e);
 

 
////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  quaternion_multiply : moltiplicazione tra quaternioni
//

void quaternion_multiply(QUATERNION *q3, QUATERNION q1, QUATERNION q2);
 
 
 
////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  quaternion_to_euler : da quaternioni ad angoli di eulero
//

void quaternion_to_euler(QUATERNION q, EULER_ANGLES *e);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  print_euler_angles : stampa la tripletta di angoli
//

void print_euler_angles(EULER_ANGLES *e);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  print_quaternion : stampa il quaternione 
//

void print_quaternion(QUATERNION q);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  print_acceleration_vector : stampa i valori di accelerazione
//

void print_acceleration_vector(ACCELERATION *a);

        
////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  angular_init : inizializza un tipo di dati anglular con angolo multigiro e offset
//

void angular_init(ANGULAR *a, DOUBLE val, FLOAT ofs);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  angular_set_offset : imposta un offset diverso a un dato angular
//

DOUBLE angular_set_offset(ANGULAR *a, FLOAT ofs);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  angular_get : converte un dato angular in angolo multigiro con offset già sommato
//

DOUBLE angular_get(ANGULAR *a);



////////////////////////////////////////////////////////////////////////////////////////////////////        
//
//  angular_add : aggiunge un angolo espresso in -180..+180 ad un angolo multigiro evitando le 
//                discontinuità
//

DOUBLE angular_add(ANGULAR *a, FLOAT raw);
        

        

#endif // __GEOMETRY_H__