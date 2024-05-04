/***************************************************************************************************
  
 CHRUM6 Component
 (c) 2013 Movie Engineering

 Nome file : ME_imu_CHRUM6.c
    Autore : Roberto Gatti 
  Versione : 0.10 Beta
      Data : 2013-06-16
 
 Descrizione :
   Componente software per utilizzo della libreria.
   Vedere ME_lib_imu_CHRUM6.* per i dettagli. 
   
***************************************************************************************************/

#include "IMU_UM6.h"
#include "IMU_UM6_UART.h"
#include "IMU_UM6_CBUFFER.h"
#include "IMU_UM6_PACKETIZER.h"
#include "IMU_UM6_ISR.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

WORD IMU_UM6_serial_errors_count = 0 ;



////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM6_InterruptServiceRoutine(void)
{   
    BYTE status ; 
    
    status = IMU_UM6_UART_RXSTATUS_REG ;

    if (status & IMU_UM6_UART_RX_STS_FIFO_NOTEMPTY)
    {
        IMU_UM6_CBUFFER_PutByte(IMU_UM6_UART_RXDATA_REG) ;
    }
    else
    {
        IMU_UM6_serial_errors_count ++ ;
    }

}



////////////////////////////////////////////////////////////////////////////////////////////////////

static BYTE *IMU_UM6_packet_buffer_ptr ;

BYTE *IMU_UM6_InitAndStart(void)
{
    IMU_UM6_CBUFFER_Init();
    IMU_UM6_packet_buffer_ptr = IMU_UM6_PACKETIZER_Init(CHRUM6_HeaderValidator, 
                                                                          CHRUM6_PacketValidator);
    
    IMU_UM6_UART_Start();
    
    CyDelay(100);

    // Default : 67 5F AD 00
    // Solo Eulero: 40 40 05 00
    // Ultimo byte rate broadcast: freq = (280/255) * rate + 20
    #define BROADCAST_RATE (((20-20)*280)/255)
    
                      
    CHRUM6_RegisterIO(CHRUM6_WRITE,         
                      CHRUM6_ADDRESS_COMM_REG, 
                      0x40400500 | BROADCAST_RATE,
                      IMU_UM6_UART_PutChar);

    CHRUM6_RegisterIO(CHRUM6_WRITE,          
                      CHRUM6_ADDRESS_MISC_CONFIG, 
                      0xE0000000,
                      IMU_UM6_UART_PutChar);

    CHRUM6_RegisterIO(CHRUM6_WRITE,                     // Il primo d� errore di checksum
                  CHRUM6_ADDRESS_GET_FW_VER,            // baco del componente hw
                  0,
                  IMU_UM6_UART_PutChar);
    
    IMU_UM6_serial_errors_count = 0 ;
    IMU_UM6_ISR_Start();

    return IMU_UM6_packet_buffer_ptr ;
}                            



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IMU_UM6_CheckForPacket(void)
{
    BOOL valid = false ;
    
    while (   (IMU_UM6_CBUFFER_AnyData()!=0)
           && (!valid) )
    {
        valid = IMU_UM6_PACKETIZER_BuildPacket(IMU_UM6_CBUFFER_GetByte());
    }
    
    return valid ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IMU_UM6_Error(void)
{
    return (   (IMU_UM6_CBUFFER_ERROR())
            || (IMU_UM6_serial_errors_count != 0));
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BYTE IMU_UM6_PacketAddress(void)
{
    return ((CHRUM6_HEADER *) IMU_UM6_packet_buffer_ptr)->address ;
}
void IMU_UM6_PrintPacket(void)
{
    CHRUM6_PrintPacket(IMU_UM6_packet_buffer_ptr);
    printf(" Inv:%2d", IMU_UM6_PACKETIZER_InvalidPackets());
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM6_ExecCommand(BYTE command)
{
    CHRUM6_RegisterIO(CHRUM6_WRITE, command, 0, IMU_UM6_UART_PutChar);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM6_RegisterIO(BOOL read, BYTE address, DWORD value)
{
    CHRUM6_RegisterIO(read, address, value, IMU_UM6_UART_PutChar);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM6_PacketToEuler(CHRUM6_EULER *euler_angles_ptr)
{
    CHRUM6_PacketToEuler(IMU_UM6_packet_buffer_ptr, 
                         euler_angles_ptr);
}



////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IMU_UM6_CheckForEulerPacket(CHRUM6_EULER *euler_angles_ptr)
{
    if (IMU_UM6_CheckForPacket())
    {
        if (IMU_UM6_PacketAddress() == CHRUM6_ADDRESS_EULER)
        {
            IMU_UM6_PacketToEuler(euler_angles_ptr);
            return true ;
        }
    }    

    return false ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////

void IMU_UM6_PrintEulerAngles(CHRUM6_EULER *euler_angles_ptr)
{
    printf("\n[ R(X):%7.2f  |  T(Y):%7.2f  |  P(Z):%7.2f ]", 
           euler_angles_ptr->phi, euler_angles_ptr->theta, euler_angles_ptr->psi);
        
    printf("  Inv: %3d", IMU_UM6_PACKETIZER_InvalidPackets());

}


/* [] END OF FILE */
