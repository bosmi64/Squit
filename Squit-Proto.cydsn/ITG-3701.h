/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Logic brainstorm.
 *
 * ========================================
*/

/* ITG3701 initialization */
void initITG3701(void);

/* ITG-3701 test function	*/
void ITG3701_test(void);


/********************************************************************/
/* based on															*/
/* ITG3701_LSM303D_MS5637_t3 Basic Example Code						*/
/*  by: Kris Winer													*/
/*  date: November 1, 2014											*/
/*  license: Beerware - Use this code however you'd like. If you 	*/
/*  find it useful you can buy me a beer some time.					*/
/********************************************************************/

//////////////////////////////
// ITG3701 Gyro I2C ADDRESS //
//////////////////////////////
//#define ITG3701_ADDRESS   0x69 // Address of gyro when ADO = 1
#define ITG3701_ADDRESS   0x68 // Address of gyro when ADO = 0


// See also ITG3701 Register Map and Descriptions
// http://www.invensense.com/mems/gyro/documents/RM-000001-ITG-3701-RM.pdf
//
////////////////////////////
// ITG3701 Gyro Registers //
////////////////////////////
#define ITG3701_XG_OFFS_TC_H     0x04
#define ITG3701_XG_OFFS_TC_L     0x05
#define ITG3701_YG_OFFS_TC_H     0x07
#define ITG3701_YG_OFFS_TC_L     0x08
#define ITG3701_ZG_OFFS_TC_H     0x0A
#define ITG3701_ZG_OFFS_TC_L     0x0B
#define ITG3701_XG_OFFS_USRH     0x13  // User-defined trim values for gyroscope
#define ITG3701_XG_OFFS_USRL     0x14
#define ITG3701_YG_OFFS_USRH     0x15
#define ITG3701_YG_OFFS_USRL     0x16
#define ITG3701_ZG_OFFS_USRH     0x17
#define ITG3701_ZG_OFFS_USRL     0x18
#define ITG3701_SMPLRT_DIV       0x19
#define ITG3701_CONFIG           0x1A
#define ITG3701_GYRO_CONFIG      0x1B
#define ITG3701_FIFO_EN          0x23
#define ITG3701_INT_PIN_CFG      0x37
#define ITG3701_INT_ENABLE       0x38
#define ITG3701_INT_STATUS       0x3A
#define ITG3701_TEMP_OUT_H       0x41
#define ITG3701_TEMP_OUT_L       0x42
#define ITG3701_GYRO_XOUT_H      0x43
#define ITG3701_GYRO_XOUT_L      0x44
#define ITG3701_GYRO_YOUT_H      0x45
#define ITG3701_GYRO_YOUT_L      0x46
#define ITG3701_GYRO_ZOUT_H      0x47
#define ITG3701_GYRO_ZOUT_L      0x48
#define ITG3701_USER_CTRL        0x6A  
#define ITG3701_PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define ITG3701_PWR_MGMT_2       0x6C
#define ITG3701_FIFO_COUNTH      0x72
#define ITG3701_FIFO_COUNTL      0x73
#define ITG3701_FIFO_R_W         0x74
#define ITG3701_WHO_AM_I         0x75 // Should return 0x68


enum Aodr {  // set of allowable gyro sample rates
  AODR_PowerDown = 0,
  AODR_3_125Hz,
  AODR_6_25Hz,
  AODR_12_5Hz,
  AODR_25Hz,
  AODR_50Hz,
  AODR_100Hz,
  AODR_200Hz,
  AODR_400Hz,
  AODR_800Hz,
  AODR_1600Hz
};

enum Gscale {
  GFS_500DPS = 0,
  GFS_1000DPS,
  GFS_2000DPS,
  GFS_4000DPS
};

enum Godr {  // set of allowable gyro sample rates
  GODR_95Hz = 0,
  GODR_190Hz,
  GODR_380Hz,
  GODR_760Hz
};

enum Gbw {   // set of allowable gyro data bandwidths
  GBW_low = 0,  // 12.5 Hz at Godr = 95 Hz, 12.5 Hz at Godr = 190 Hz,  30 Hz at Godr = 760 Hz
  GBW_med,      // 25 Hz   at Godr = 95 Hz, 25 Hz   at Godr = 190 Hz,  35 Hz at Godr = 760 Hz
  GBW_high,     // 25 Hz   at Godr = 95 Hz, 50 Hz   at Godr = 190 Hz,  50 Hz at Godr = 760 Hz
  GBW_highest   // 25 Hz   at Godr = 95 Hz, 70 Hz   at Godr = 190 Hz, 100 Hz at Godr = 760 Hz
};


/* ITG-3701 I2C interface functions */
uint8 ITG3701_ReadByte(uint8 slaveAddress, uint8 registerAddress);
void ITG3701_ReadBytes(uint8 slaveAddress, uint8 registerAddress, uint8 count, uint8 * dest);

/* ITG-3701 read raw data function	*/
void readGyroData(int16_t * destination);

/* get ITG-3701 resolutions (calculates gRes) */
void getGres();

// Function which accumulates gyro data after device initialization. It calculates the average
// of the at-rest readings and then loads the resulting offsets into gyro bias registers.
void gyrocalITG3701(float * dest1);


/* [] END OF FILE */
