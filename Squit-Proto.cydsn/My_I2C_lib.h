/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

//Reads a single Byte from I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint8 My_I2C_COULOMB_ReadByte(uint8 slaveAddress);


//Reads 2 Bytes from I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint16 My_I2C_COULOMB_Read2Bytes(uint8 slaveAddress);


//Reads a single Byte from slaveRegisterAddress of I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint8 My_I2C_COULOMB_ReadSlaveRegister(uint8 slaveAddress, uint8 slaveRegisterAddress);

/* [] END OF FILE */
