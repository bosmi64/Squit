/***************************************************************************************************
  
  Modulo "Geometry" (v0.20B)
  (c) 2013-2015 Movie Engineering

  Vedi header file.
   
***************************************************************************************************/
#include <stdio.h>
#include <math.h>

#include "ME_common.h"
#include "ME_geometry.h"

////////////////////////////////////////////////////////////////////////////////////////////////////


INT offset_heading(WORD raw, WORD offset)
{
    INT heading ;

    heading = raw - offset ;                                  // Tiene in considerazione l'offset

    if ( ( offset <= 1800 ) && ( raw >= offset+1800 ) )       // Offset piccolo zona da correggere 
    {
        heading = raw - offset - 3600 ;
    }
    else if ( ( offset >= 1800 ) && ( raw <= offset-1800 ) )  // Offset grande zona da correggere
    {
        heading = raw - offset + 3600 ;
    }

    return heading ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void euler_rad_to_deg(EULER_ANGLES *e)
{
    e->phi   *= RAD_TO_DEG ;          // Sufficiente la costante di proporzionalità
    e->theta *= RAD_TO_DEG ;
    e->psi   *= RAD_TO_DEG ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

#define SINGULARITY_THRESHOLD 0.49999

// Originle funzionante 
//
//void quaternion_to_euler(QUATERNION q, EULER_ANGLES *e)
//{
//    FLOAT test = q.x * q.y + q.z * q.w ;
//    FLOAT sqx, sqy, sqz ;
//    
//    if (test > SINGULARITY_THRESHOLD)
//    {
//        e->phi = 2 * atan2(q.x, q.w) ;
//        e->theta = PI_2 ;
//        e->psi = 0 ;
//        return ;
//    }
//    
//    if (test < -SINGULARITY_THRESHOLD)
//    {
//        e->phi = -2 * atan2(q.x, q.w) ;
//        e->theta = -PI_2 ;
//        e->psi = 0 ;
//        return ;
//    }
//
//    sqx = q.x * q.x ;
//    sqy = q.y * q.y ;
//    sqz = q.z * q.z ;
//    
//    e->phi = atan2(2*q.y*q.w - 2*q.x*q.z , 1 - 2*sqy - 2*sqz);
//	e->theta = asin(2*test);
//	e->psi = atan2(2*q.x*q.w-2*q.y*q.z , 1 - 2*sqx - 2*sqz);
//    
//}
 
void quaternion_to_euler(QUATERNION q, EULER_ANGLES *e)
{
    register FLOAT test = q.x * q.y + q.z * q.w ;
    register FLOAT sqx, sqy, sqz ;
    
    if (test > SINGULARITY_THRESHOLD)
    {
        e->phi = 2 * atan2(q.x, q.w) ;
        e->theta = PI_2 ;
        e->psi = 0 ;
        return ;
    }
    
    if (test < -SINGULARITY_THRESHOLD)
    {
        e->phi = -2 * atan2(q.x, q.w) ;
        e->theta = -PI_2 ;
        e->psi = 0 ;
        return ;
    }

    sqx = q.x * q.x ;
    sqy = q.y * q.y ;
    sqz = q.z * q.z ;
    
    e->phi = atan2(2 * ( q.y*q.w + q.x*q.z ) , 1 - 2 * ( sqy + sqz ) );
	e->theta = asin(2*test);
	e->psi = atan2( 2 * ( q.x*q.w + q.y*q.z ) , 1 - 2 * ( sqx + sqz ) );
    
} 

////////////////////////////////////////////////////////////////////////////////////////////////////

void quaternion_multiply(QUATERNION *q3, QUATERNION q1, QUATERNION q2)
{
    q3->w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z ;
    q3->x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y ;
    q3->y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x ;
    q3->z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
 
void print_quaternion(QUATERNION q)
{
    printf("[X:%6.3f|Y:%6.3f|Z:%6.3f|W:%6.3f]", q.x, q.y, q.z, q.w);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void print_euler_angles(EULER_ANGLES *e)
{
    printf("PSI(pan):%6.3f | THETA(tilt):%6.3f | PHI(roll):%6.3f | ", e->psi, e->theta, e->phi);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void print_acceleration_vector(ACCELERATION *a)
{
    printf("[x:%6.2f|y:%6.2f|z:%6.2f]", a->x, a->y, a->z);
}



////  FUNZIONI PER TIPI ANGULAR  ///////////////////////////////////////////////////////////////////

void angular_init(ANGULAR *a, DOUBLE val, FLOAT ofs)
{
    a->old_raw = 0 ;
    a->value = val ;
    a->offset = ofs ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

DOUBLE angular_add(ANGULAR *a, FLOAT raw)
{
    FLOAT delta = raw - a->old_raw ;            // La variazione è tra dati -180..+180
 
    if (ABS(delta)>= 180.0)                     // Caso particolare per variazioni grandi
    {
      if (delta<0)                              // Corregge la variazione tenendo conto dei 
        delta = 360.0 + delta ;                 // ribaltamenti
      else
        delta = delta - 360.0 ;     
    }

    a->value += delta ;                         // Aggiorna il valore finale
    a->old_raw = raw ;                          // Memorizza il valore attuale in ingresso
    
    return a->value + a->offset ;               // Può essere comodo avere il valore finale 
}

////////////////////////////////////////////////////////////////////////////////////////////////////


DOUBLE angular_get(ANGULAR *a)
{    
    return a->value + a->offset ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

DOUBLE angular_set_offset(ANGULAR *a, FLOAT ofs)
{   
    a->offset = ofs ;
    return a->value + a->offset ;
}











