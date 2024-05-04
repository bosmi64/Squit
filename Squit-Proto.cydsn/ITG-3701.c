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

/* PSOC Include Files */
#include <device.h>
#include <math.h>
#include <stdio.h>

/* This PRJ Include Files */
#include <ITG-3701.h>

// Specify Gyro Sensor Parameters
uint8 Gscale = GFS_4000DPS; 	// gyro full scale
uint8 Godr   = GODR_190Hz;   	// gyro data sample rate
uint8 Gbw    = GBW_highest;     // gyro data bandwidth
float gRes;      				// scale resolutions per LSB for the sensors

int16 gyroCount[3];  			// Stores the 16-bit signed gyro output
float gx, gy, gz; 				// variables to hold latest sensor data values 
float gyroBias[3] = {0, 0, 0}; 	// Bias corrections for gyro, accelerometer, and magnetometer
float temperature;          	// Stores the ITG3701yro internal chip temperature in degrees Celsius

uint8 dummy;

uint8 ITG3701_ReadByte(uint8 slaveAddress, uint8 registerAddress)
{
	uint8 belbyte;
	uint8 error_status __attribute__ ((unused));
	
#if ITG_3701_ENABLED	
	error_status = I2C_ITG3701_MasterSendStart(slaveAddress, I2C_ITG3701_WRITE_XFER_MODE);
	
//	if (error_status == I2C_ITG3701_MSTR_NO_ERROR)
//	{
		//ACK from Slave?
		//CyDelay(1);
		I2C_ITG3701_MasterWriteByte(registerAddress);
		//ACK from Slave?
		//CyDelay(1);	
		I2C_ITG3701_MasterSendRestart(slaveAddress, I2C_ITG3701_READ_XFER_MODE);
		//ACK from Slave?
		//CyDelay(1);	
		belbyte = I2C_ITG3701_MasterReadByte(I2C_ITG3701_NAK_DATA);	
		//CyDelay(1);	
		I2C_ITG3701_MasterSendStop();
#endif		
		return belbyte;
//	}
//	else
//	{
//		return error_status;
//	}
}

void ITG3701_ReadBytes(uint8 slaveAddress, uint8 registerAddress, uint8 count, uint8 * dest)
{  
//	Wire.beginTransmission(address);   // Initialize the Tx buffer
//	Wire.write(0x80 | subAddress);     // Put slave register address in Tx buffer, include 0x80 for LSM303D multiple byte read
//	Wire.endTransmission(I2C_NOSTOP);  // Send the Tx buffer, but send a restart to keep connection alive
////	Wire.endTransmission(false);       // Send the Tx buffer, but send a restart to keep connection alive
//	uint8_t i = 0;
////        Wire.requestFrom(address, count);  // Read bytes from slave register address 
//        Wire.requestFrom(address, (size_t) count);  // Read bytes from slave register address 
//	while (Wire.available()) {
//        dest[i++] = Wire.read(); }         // Put read results in the Rx buffer

#if ITG_3701_ENABLED	
	uint8 i = 0;	
	
	I2C_ITG3701_MasterSendStart(slaveAddress, I2C_ITG3701_WRITE_XFER_MODE);
	//ACK from Slave?
	I2C_ITG3701_MasterWriteByte(registerAddress);
	//ACK from Slave?
	I2C_ITG3701_MasterSendRestart(slaveAddress, I2C_ITG3701_READ_XFER_MODE);
	//ACK from Slave?	
	while(count>2)
	{
		dest[i++] = I2C_ITG3701_MasterReadByte(I2C_ITG3701_ACK_DATA); 	//after reading from the slave, the master sends ACK
		count--;	
	}
	dest[i] = I2C_ITG3701_MasterReadByte(I2C_ITG3701_NAK_DATA);			//after last read, the master sends NAK
	I2C_ITG3701_MasterSendStop();
#endif	
}


void ITG3701_WriteByte(uint8 address, uint8 registerAddress, uint8 data_byte)
{	
//	Wire.beginTransmission(address);  // Initialize the Tx buffer
//	Wire.write(subAddress);           // Put slave register address in Tx buffer
//	Wire.write(data);                 // Put data in Tx buffer
//	Wire.endTransmission();           // Send the Tx buffer

#if ITG_3701_ENABLED	
	I2C_ITG3701_MasterSendStart(address, I2C_ITG3701_WRITE_XFER_MODE);
	//ACK from Slave?
	I2C_ITG3701_MasterWriteByte(registerAddress);
	//ACK from Slave?
	I2C_ITG3701_MasterWriteByte(data_byte);
	//ACK from Slave?	
	I2C_ITG3701_MasterSendStop();	
#endif	
}


//======================================================
//====== Set of useful function to access gyroscope data
//======================================================
void getGres()
{
	switch (Gscale)
	{
	 	// Possible gyro scales (and their register bit settings) are:
		// 500 DPS (00), 1000 DPS (01), 2000 DPS (10) and 4000 DPS  (11). 
	    case GFS_500DPS:
	          gRes = 500.0/32768.0;
	          break;
	    case GFS_1000DPS:
	          gRes = 1000.0/32768.0;
	          break;
	    case GFS_2000DPS:
	          gRes = 2000.0/32768.0;
	          break;
	    case GFS_4000DPS:
	          gRes = 4000.0/32768.0;
	          break;
  	}
}


void readGyroData(int16_t * destination)
{
  uint8_t rawData[6];  // x/y/z gyro register data stored here
  ITG3701_ReadBytes(ITG3701_ADDRESS, ITG3701_GYRO_XOUT_H, 6, &rawData[0]);  // Read the six raw data registers sequentially
																			//   into data array
  destination[0] = ((int16_t)rawData[0] << 8) | rawData[1] ;  				// Turn the MSB and LSB into a signed 16-bit value
  destination[1] = ((int16_t)rawData[2] << 8) | rawData[3] ;  
  destination[2] = ((int16_t)rawData[4] << 8) | rawData[5] ; 
}

void initITG3701(void)
{  
 // wake up device
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_1, 0x00); // Clear sleep mode bit (6), enable all sensors 
  CyDelay(100); // Wait for all registers to reset 

 // get stable time source
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_1, 0x01);  // Auto select clock source to be PLL gyroscope reference if ready else
  CyDelay(200); 
  
 // Configure Gyro and Thermometer
 // Disable FSYNC and set thermometer and gyro bandwidth to 41 and 42 Hz, respectively; 
 // minimum delay time for this setting is 5.9 ms, which means sensor fusion update rates cannot
 // be higher than 1 / 0.0059 = 170 Hz
 // DLPF_CFG = bits 2:0 = 011; this limits the sample rate to 1000 Hz for both
 // With the ITG3701, it is possible to get gyro sample rates of 32 kHz (!), 8 kHz, or 1 kHz
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_CONFIG, 0x03);  

 // Set sample rate = gyroscope output rate/(1 + SMPLRT_DIV)
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_SMPLRT_DIV, 0x04);  // Use a 200 Hz rate; a rate consistent with the filter update rate 
                                    // determined inset in CONFIG above
 
 // Set gyroscope full scale range
 // Range selects FS_SEL and AFS_SEL are 0 - 3, so 2-bit values are left-shifted into positions 4:3
  uint8_t c = ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG);
//  writeRegister(GYRO_CONFIG, c & ~0xE0); // Clear self-test bits [7:5] 
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG, c & ~0x02); // Clear Fchoice bits [1:0] 
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG, c & ~0x18); // Clear AFS bits [4:3]
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG, c | Gscale << 3); // Set full scale range for the gyro
 // writeRegister(GYRO_CONFIG, c | 0x00); // Set Fchoice for the gyro to 11 by writing its inverse to bits 1:0 of GYRO_CONFIG

 // Configure Interrupts and Bypass Enable
  // Set interrupt pin active high, push-pull, hold interrupt pin level HIGH until interrupt cleared,
  // clear on read of INT_STATUS, and enable I2C_BYPASS_EN so additional chips 
  // can join the I2C bus and all can be controlled by the Arduino as master
   ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_INT_PIN_CFG, 0x20);    
   ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_INT_ENABLE, 0x01);  // Enable data ready (bit 0) interrupt
   CyDelay(100);
}


// Function which accumulates gyro data after device initialization. It calculates the average
// of the at-rest readings and then loads the resulting offsets into gyro bias registers.
void gyrocalITG3701(float * dest1)
{  
  uint8_t data[6]; // data array to hold gyro x, y, z, data
  uint16_t ii, packet_count;
  uint16_t fifo_count __attribute__ ((unused));
  int32_t gyro_bias[3]  = {0, 0, 0};
  
 // reset device
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_1, 0x80); // Write a one to bit 7 reset bit; toggle reset device
  CyDelay(100);
   
 // get stable time source; Auto select clock source to be PLL gyroscope reference if ready 
 // else use the internal oscillator, bits 2:0 = 001
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_1, 0x01);  
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_2, 0x00);
  CyDelay(200);                                    

	// Configure device for bias calculation
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_INT_ENABLE, 0x00);   // Disable all interrupts
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_FIFO_EN, 0x00);      // Disable FIFO
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_PWR_MGMT_1, 0x00);   // Turn on internal clock source
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_USER_CTRL, 0x00);    // Disable FIFO 
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_USER_CTRL, 0x04);    // Reset FIFO 
  CyDelay(15);
  
//	// Configure ITG3701 gyro for bias calculation
//  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_CONFIG, 0x01);      // Set low-pass filter to 184 Hz
//  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_SMPLRT_DIV, 0x00);  // Set sample rate to 1 kHz
//  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_GYRO_CONFIG, 0x00); // Set gyro full-scale to 500 degrees per second, maximum sensitivity
 
  // Configure FIFO to capture accelerometer and gyro data for bias calculation
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_USER_CTRL, 0x40);   // Enable FIFO  
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_FIFO_EN, 0x70);     // Enable gyro sensors for FIFO  (max size 512 bytes in ITG3701)
  CyDelay(100); // accumulate 80 samples in 80 milliseconds = 480 bytes

  // At end of sample accumulation, turn off FIFO sensor read
  ITG3701_WriteByte(ITG3701_ADDRESS, ITG3701_FIFO_EN, 0x00);        // Disable gyro sensors for FIFO
  ITG3701_ReadBytes(ITG3701_ADDRESS, ITG3701_FIFO_COUNTH, 2, &data[0]); // read FIFO sample count
  fifo_count = (uint16_t)((uint16_t)data[0] << 8) | data[1];
//  packet_count = fifo_count/6; // How many sets of full gyro data for averaging
  packet_count = 128; // How many sets of full gyro data for averaging

  for (ii = 0; ii < packet_count; ii++)
	{
	    int16_t gyro_temp[3] = {0, 0, 0};
		//    readBytes(ITG3701_ADDRESS, ITG3701_FIFO_R_W, 6, &data[0]); // read data for averaging
	    ITG3701_ReadBytes(ITG3701_ADDRESS, ITG3701_GYRO_XOUT_H, 6, &data[0]); // read data for averaging
	    gyro_temp[0]  = (int16_t) (((int16_t)data[0] << 8) | data[1]) ;
	    gyro_temp[1]  = (int16_t) (((int16_t)data[2] << 8) | data[3]) ;
	    gyro_temp[2]  = (int16_t) (((int16_t)data[4] << 8) | data[5]) ;
	    
	    gyro_bias[0]  += (int32_t) gyro_temp[0];
	    gyro_bias[1]  += (int32_t) gyro_temp[1];
	    gyro_bias[2]  += (int32_t) gyro_temp[2];
	    CyDelay(5);
	}
	
    gyro_bias[0]  /= (int32_t) packet_count;
    gyro_bias[1]  /= (int32_t) packet_count;
    gyro_bias[2]  /= (int32_t) packet_count;
      
	// Construct the gyro biases for push to the hardware gyro bias registers, which are reset to zero upon device startup
  	data[0] = (-gyro_bias[0]  >> 8) & 0xFF;  
  	data[1] = (-gyro_bias[0])       & 0xFF; // Biases are additive, so change sign on calculated average gyro biases
  	data[2] = (-gyro_bias[1]  >> 8) & 0xFF;
  	data[3] = (-gyro_bias[1])       & 0xFF;
  	data[4] = (-gyro_bias[2]  >> 8) & 0xFF;
  	data[5] = (-gyro_bias[2])       & 0xFF;
  
	// Push gyro biases to hardware registers
	//  writeByte(ITG3701_ADDRESS, ITG3701_XG_OFFS_USRH, data[0]);
	//  writeByte(ITG3701_ADDRESS, ITG3701_XG_OFFS_USRL, data[1]);
	//  writeByte(ITG3701_ADDRESS, ITG3701_YG_OFFS_USRH, data[2]);
	//  writeByte(ITG3701_ADDRESS, ITG3701_YG_OFFS_USRL, data[3]);
	//  writeByte(ITG3701_ADDRESS, ITG3701_ZG_OFFS_USRH, data[4]);
	//  writeByte(ITG3701_ADDRESS, ITG3701_ZG_OFFS_USRL, data[5]);
  
	// Output scaled gyro biases for display in the main program
	dest1[0] = (float) gyro_bias[0]*gRes;  
	dest1[1] = (float) gyro_bias[1]*gRes;
	dest1[2] = (float) gyro_bias[2]*gRes;
}



void ITG3701_test(void)
{
	uint8 index;
	
	// Verify HW connection
	dummy = ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_WHO_AM_I);  // Read WHO_AM_I register for ITG3701 gyro
  	printf("ITG3701 gyro; I AM 0x%02X (should be 0x68)\r\n",(uint16)dummy);
	CyDelay(1);
	
	// Initialize ITG-3701 gyro
	initITG3701();

    // Calibrate gyro loading biases in bias registers
    gyrocalITG3701(gyroBias);

	// get sensor resolutions, only need to do this once (calculates gRes)
   	getGres();	
   	printf("ITG3701 gyro sensitivity is %1.4f LSB/dps\r\n", (float)1.0/(gRes));
	
	for(index=0;index<20;index++)
	{
		if (ITG3701_ReadByte(ITG3701_ADDRESS, ITG3701_INT_STATUS) & 0x01)  // check if new gyro data is ready  
		{
			readGyroData(gyroCount);  // Read the x/y/z adc values

		    // Calculate the gyro value into actual degrees per second
		    gx = (float)gyroCount[0]*gRes - gyroBias[0];  // get actual gyro value, this depends on scale being set
		    gy = (float)gyroCount[1]*gRes - gyroBias[1];  
		    gz = (float)gyroCount[2]*gRes - gyroBias[2]; 
		}
		printf("ITG3701 gx=%1.4f gy=%1.4f gz=%1.4f\r\n",(float)gx, (float)gy, (float)gz);
	}
}

///////////////////////////
//I2C PSoC Code Examples //
///////////////////////////
//	/* The I2C Slave address by default in a PSoC device is 8 */
//	#define I2C_SLAVE_ADDRESS    (8u)
//	/* Set the write buffer length to be 16 bits or 2 bytes */
//	#define WR_BUFFER_SIZE       (2u)
//
//    uint8 temp;
//    uint8 sample_segment[WR_BUFFER_SIZE];
//    uint16 sample_full;
//
//        sample_full = ADC_DelSig_GetResult16();
//        AMuxSeq_Next();
//        sample_segment[0] = sample_full >> 8u & 0x00FFu;
//        sample_segment[1] = sample_full & 0x00FFu;
//
//            /* The syntax below automatically writes a buffer of data to a slave
//             * device from start to stop.
//              */
//            temp = I2CM_MasterWriteBuf(I2C_SLAVE_ADDRESS, (uint8 *)sample_segment,
//                                        WR_BUFFER_SIZE, I2CM_MODE_COMPLETE_XFER);



/* [] END OF FILE */
