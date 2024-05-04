/***************************************************************************************************
  
  CHRUM6 Component (v. 0.10 Beta)
  (c) 2015 Movie Engineering

  Vedi header file.
   
***************************************************************************************************/


////  LIBRERIE ESTERNE  ////////////////////////////////////////////////////////////////////////////

#include "CHRUM7.h"
#include "CHRUM7_UART.h"
#include "CHRUM7_CBUFFER.h"
#include "CHRUM7_PACKETIZER.h"
#include "CHRUM7_ISR.h"



////  VARIABILI  ///////////////////////////////////////////////////////////////////////////////////

// Numero di errori hardware di seriale (rari)

WORD CHRUM7_serial_errors_count = 0 ;


// Puntatore a funzione di scrittura su seriale del componente

static PUTCHAR_FUNCTION_PTR putcharf = &CHRUM7_UART_PutChar ;


// Puntatore al buffer interno in cui il componente PACKETIZER costruisce il pacchetto ricevuto 
// (è utile per verificare i valori interni grezzi)

static BYTE *CHRUM7_packet_buffer_ptr ;



////  FUNZIONI  ////////////////////////////////////////////////////////////////////////////////////

static void ReceiveISR(void)
{   
    BYTE status ; 
    
    status = CHRUM7_UART_RXSTATUS_REG ;

    if (status & CHRUM7_UART_RX_STS_FIFO_NOTEMPTY)
    {
        CHRUM7_CBUFFER_PutByte(CHRUM7_UART_RXDATA_REG) ;
    }
    else
    {
        CHRUM7_serial_errors_count ++ ;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_WriteRegister(BYTE address, DWORD value)
{
    BOOL received = false ;

    CHRUM7_RegisterIO(CHRUM7_WRITE, address, value, putcharf);
    
    while (!received)       // TODO: aggiungere timeout
    {
        if (CHRUM7_CheckForPacket())
        {
            if (CHRUM7_PacketAddress() == address)
            {
                received = true ;
            }
        }  
    }    
    
    return true ;    
}

////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD CHRUM7_ReadRegister(BYTE address)
{
    BOOL received = false ;
    BYTE *p = CHRUM7_packet_buffer_ptr ;
    BITS32 b32 ;
    
    CHRUM7_RegisterIO(CHRUM7_READ, address, 0, putcharf);

    while (!received)       // TODO: aggiungere timeout
    {
        if (CHRUM7_CheckForPacket())
        {
            if (CHRUM7_PacketAddress() == address)
            {
                received = true ;
            }
        }  
    }    

    b32.words.hi.bytes.hi = p[5] ;
    b32.words.hi.bytes.lo = p[6] ;
    b32.words.lo.bytes.hi = p[7] ;
    b32.words.lo.bytes.lo = p[8] ;
    
  //  printf(CRLF"GETREG: %02X  %02X  %02X  %02X",  p[5], p[6], p[7], p[8]);
    
    return b32.unsigned32 ;

}      

////////////////////////////////////////////////////////////////////////////////////////////////////


BYTE *CHRUM7_InitAndStart(void)
{
    CHRUM7_CBUFFER_Init();
    CHRUM7_packet_buffer_ptr = CHRUM7_PACKETIZER_Init(CHRUM7_HeaderValidator, 
                                                                          CHRUM7_PacketValidator);
    CHRUM7_serial_errors_count = 0 ;
   
    CHRUM7_UART_Start();
    CHRUM7_ISR_StartEx(&ReceiveISR);    

    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES1, 0x00000000);
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES2, 0x00000000);    
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES3, 0x00000000);
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES4, 0x00000000);
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES5, 
                                   0x00000000 | ( ((DWORD) CHRUM7_BROADCAST_RATE) << 16) );
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES6, 0x00000000);
 
    return CHRUM7_packet_buffer_ptr ;
}                            



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_Stop(void)
{
    CHRUM7_UART_Stop();
    CHRUM7_ISR_Stop();
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_CheckForPacket(void)
{
    BOOL valid = false ;
    
    while (   (CHRUM7_CBUFFER_AnyData()!=0)
           && (!valid) )
    {
        valid = CHRUM7_PACKETIZER_BuildPacket(CHRUM7_CBUFFER_GetByte());
    }
    
    return valid ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_Error(void)
{
    return (   (CHRUM7_CBUFFER_ERROR())
            || (CHRUM7_serial_errors_count != 0));
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE CHRUM7_PacketAddress(void)
{
    return ((CHRUM7_HEADER *) CHRUM7_packet_buffer_ptr)->address ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PrintPacket(void)
{
    CHRUM7_PrintPacket(CHRUM7_packet_buffer_ptr);
    printf(" Inv:%2d", CHRUM7_PACKETIZER_InvalidPackets(false));
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_ExecCommand(BYTE command)
{
    CHRUM7_RegisterIO(CHRUM7_WRITE, command, 0, putcharf);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_RegisterIO(BOOL read, BYTE address, DWORD value)
{
    CHRUM7_RegisterIO(read, address, value, putcharf);
}




////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_SetBAUD(DWORD baudrate)
{
    CHRUM7_WriteRegister(CHRUM7_CREG_COM_SETTINGS, baudrate);
}



////////////////////////////////////////////////////////////////////////////////////////////////////


void CHRUM7_SetRate(UM7_RATE_TYPE UM7_RATE_TYPE, BYTE rate)
{
    BITS32 b32 ;       // Valore registro letto
    
    
    switch(UM7_RATE_TYPE)
    {
        case RATE_PROC_ACCEL : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES3);
            b32.words.hi.bytes.hi = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES3, b32.unsigned32);  
            break ;
        
        case RATE_PROC_GYRO  : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES3);
            b32.words.hi.bytes.lo = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES3, b32.unsigned32);  
            break ;

        case RATE_PROC_MAG   : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES3);
            b32.words.lo.bytes.hi = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES3, b32.unsigned32);  
            break ;

            
        case RATE_QUAT       : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES5);
            b32.words.hi.bytes.hi = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES5, b32.unsigned32);  
            break ;

        case RATE_EULER      : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES5);
            b32.words.hi.bytes.lo = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES5, b32.unsigned32);  
            break ;

        case RATE_POSITION   : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES5);
            b32.words.lo.bytes.hi = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES5, b32.unsigned32);  
            break ;

        case RATE_VELOCITY   : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES5);
            b32.words.lo.bytes.lo = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES5, b32.unsigned32);  
            break ;

        case RATE_POSE       : 
            b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES6);
            b32.words.hi.bytes.hi = rate ;
            CHRUM7_WriteRegister(CHRUM7_CREG_COM_RATES6, b32.unsigned32);  
            break ;

    };
}


////////////////////////////////////////////////////////////////////////////////////////////////////


void CHRUM7_SetMisc(BOOL zerogyro, BOOL quaternion_mode, BOOL use_magnetometer)
{
    CHRUM7_WriteRegister(CHRUM7_CREG_MISC_SETTINGS, 
                                   (zerogyro ? BIT02 : 0 ) |
                                   (quaternion_mode ? BIT01 : 0 ) |
                                   (use_magnetometer ? BIT00 : 0 ));
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_SetGyroTrim(FLOAT x, FLOAT y, FLOAT z)
{
    BITS32 b32 ;
    
    b32.ieee32 = x ;
    CHRUM7_WriteRegister(CHRUM7_CREG_GYRO_TRIM_X, b32.unsigned32); 
    b32.ieee32 = y ;
    CHRUM7_WriteRegister(CHRUM7_CREG_GYRO_TRIM_Y, b32.unsigned32); 
    b32.ieee32 = z ;
    CHRUM7_WriteRegister(CHRUM7_CREG_GYRO_TRIM_Z, b32.unsigned32); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void CHRUM7_GetProcessedData(UM7_PROCESSED_DATA *um7_data)
{
    BITS32 b32 ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_GYRO_PROC_X);     
    um7_data->gyroscope.x = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_GYRO_PROC_Y);     
    um7_data->gyroscope.y = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_GYRO_PROC_Z);     
    um7_data->gyroscope.z = b32.ieee32 ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_ACCEL_PROC_X);     
    um7_data->accelerometer.x = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_ACCEL_PROC_Y);     
    um7_data->accelerometer.y = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_ACCEL_PROC_Z);     
    um7_data->accelerometer.z = b32.ieee32 ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_MAG_PROC_X);     
    um7_data->magnetometer.x = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_MAG_PROC_Y);     
    um7_data->magnetometer.y = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_MAG_PROC_Z);     
    um7_data->magnetometer.z = b32.ieee32 ;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

static void print_vector (UM7_VECTOR *v)
{
    printf(CRLF"  X = %8.3f", v->x);
    printf(CRLF"  Y = %8.3f", v->y);
    printf(CRLF"  Z = %8.3f", v->z);
}


void CHRUM7_PrintSettings(void)
{
    BITS32 b32 ;
    UM7_VECTOR v ;
    
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_GET_FW_REVISION);
    printf(CRLF"%s %c%c%c%c", "Firmware Version = ",  b32.words.hi.bytes.hi, 
                                                      b32.words.hi.bytes.lo,
                                                      b32.words.lo.bytes.hi,
                                                      b32.words.lo.bytes.lo ) ;
    
    printf(CRLF"Broadcast Rates in Hz:");
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES3);
    printf(CRLF"%s%3d Hz", "  Proc. Acceleration = ", b32.words.hi.bytes.hi) ;
    printf(CRLF"%s%3d Hz", "  Proc. Gyroscope    = ", b32.words.hi.bytes.lo) ;
    printf(CRLF"%s%3d Hz", "  Proc. Magnetometer = ", b32.words.lo.bytes.hi) ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES5);
    printf(CRLF"%s%3d Hz", "  Quaternion         = ", b32.words.hi.bytes.hi) ;
    printf(CRLF"%s%3d Hz", "  Euler Angles       = ", b32.words.hi.bytes.lo) ;
    printf(CRLF"%s%3d Hz", "  Position           = ", b32.words.lo.bytes.hi) ;
    printf(CRLF"%s%3d Hz", "  Velocity           = ", b32.words.lo.bytes.lo) ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_COM_RATES6);
    printf(CRLF"%s%3d Hz", "  PosE               = ", b32.words.hi.bytes.hi) ;

    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_MISC_SETTINGS);
    printf(CRLF"Misc Settings:");
    printf(CRLF"  ZeroGyro         = %s", (b32.unsigned32 & BIT02) != 0 ? "ON" : "OFF");
    printf(CRLF"  Quaternion Mode  = %s", (b32.unsigned32 & BIT01) != 0 ? "ON" : "OFF");
    printf(CRLF"  Magnetometer Use = %s", (b32.unsigned32 & BIT00) != 0 ? "ON" : "OFF");
    
    printf(CRLF"Gyro Trims:");
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_GYRO_TRIM_X);
    v.x = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_GYRO_TRIM_Y);
    v.y = b32.ieee32 ;
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_CREG_GYRO_TRIM_Z);
    v.z = b32.ieee32 ;
    print_vector(&v);
    
}    



////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PrintData(void)
{    
    BITS32 b32 ;
    UM7_VECTOR v ;
    UM7_PROCESSED_DATA um7_data ;

    CHRUM7_GetProcessedData(&um7_data);

    printf(CRLF"Processed Data:");
    printf(CRLF"Gyroscope:");
    print_vector(&um7_data.gyroscope);
    printf(CRLF"Accelerometer:");
    print_vector(&um7_data.accelerometer);
    printf(CRLF"Magnetometer:");
    print_vector(&um7_data.magnetometer);
      
    
    printf(CRLF"Euler Angles:");
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_EULER_PHI_THETA);
    printf(CRLF"  Phi   = %8.3f", b32.words.hi.signed16 / 91.02222);
    printf(CRLF"  Theta = %8.3f", b32.words.lo.signed16 / 91.02222);
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_EULER_PSI);
    printf(CRLF"  Psi   = %8.3f", b32.words.hi.signed16 / 91.02222);
    
    printf(CRLF"Euler Angles DOT:");
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_EULER_PHI_THETA_DOT);
    printf(CRLF"  Phi rate   = %8.3f", b32.words.hi.signed16 / 16.0);
    printf(CRLF"  Theta rate = %8.3f", b32.words.lo.signed16 / 16.0);
    b32.unsigned32 = CHRUM7_ReadRegister(CHRUM7_DREG_EULER_PSI_DOT);
    printf(CRLF"  Psi rate   = %8.3f", b32.words.hi.signed16 / 16.0);
    
}


////////////////////////////////////////////////////////////////////////////////////////////////////

void CHRUM7_PacketToEuler(EULER_ANGLES *euler_angles_ptr)
{
    CHRUM7_PacketToEuler(CHRUM7_packet_buffer_ptr, 
                         euler_angles_ptr);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CHRUM7_CheckForEulerPacket(EULER_ANGLES *euler_angles_ptr)
{
    if (CHRUM7_CheckForPacket())
    {
        if (CHRUM7_PacketAddress() == CHRUM7_DREG_EULER_PHI_THETA)
        {
            CHRUM7_PacketToEuler(euler_angles_ptr);
            return true ;
        }
    }    

    return false ;
}

