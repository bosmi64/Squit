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

/* Include files */
#include <device.h>
#include <stdio.h>
#include <gobee.h>


//Reads a single Byte from I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint8 My_I2C_COULOMB_ReadByte(uint8 slaveAddress)
{
	uint8 result;
	uint8 status __attribute__ ((unused));

	status = I2C_COULOMB_MasterReadBuf(slaveAddress, &result, sizeof(uint8), I2C_COULOMB_MODE_COMPLETE_XFER);
	//status = I2C_COULOMB_MasterReadBuf(slaveAddress, &result, sizeof(uint8),I2C_COULOMB_MODE_REPEAT_START);	
	// error handling

	return result;
}

//Reads 2 Bytes from I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint16 My_I2C_COULOMB_Read2Bytes(uint8 slaveAddress)
{
	uint16a result;
	uint8 status __attribute__ ((unused));

	status = I2C_COULOMB_MasterReadBuf(slaveAddress, &result.byte[0], sizeof(uint16), I2C_COULOMB_MODE_COMPLETE_XFER);
	// error handling

return result.word;
}



//Reads a single Byte from slaveRegisterAddress of I2C device at address slaveAddress
//  slaveAddress = Right-justified 7-bit slave address (valid range 0 to 127)
//  This function performs complete transfer for Start to Stop
//  Non Blocking
uint8 My_I2C_COULOMB_ReadSlaveRegister(uint8 slaveAddress, uint8 slaveRegisterAddress)
{
	uint8 result;
	uint8 status __attribute__ ((unused));

	status = I2C_COULOMB_MasterWriteBuf(slaveAddress, &slaveRegisterAddress, sizeof(uint8), I2C_COULOMB_MODE_NO_STOP);
	// error handling

	status = I2C_COULOMB_MasterReadBuf(slaveAddress, &result, sizeof(uint8), I2C_COULOMB_MODE_REPEAT_START | I2C_COULOMB_MODE_COMPLETE_XFER);
	// error handling

	return result;
}

/* [] END OF FILE */
