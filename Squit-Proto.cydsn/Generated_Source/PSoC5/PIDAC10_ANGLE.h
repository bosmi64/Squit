/*******************************************************************************
* File Name: PIDAC10_ANGLE.h  
* Version 1.2
*
*  Description:
*    This file contains the function prototypes and constants used in
*    the 10/11-bit Current DAC (PIDAC) User Module.
*
*   Note:
*     
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include "cytypes.h"
#include "cyfitter.h"

#if !defined(CY_PIDAC_PIDAC10_ANGLE_H)  
#define CY_PIDAC_PIDAC10_ANGLE_H


/***************************************
* Conditional Compilation Parameters
***************************************/

/* PSoC3 ES2 or early */
#define PIDAC10_ANGLE_PSOC3_ES2  ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A)    && \
                                    (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2))
/* PSoC5 ES1 or early */
#define PIDAC10_ANGLE_PSOC5_ES1  ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A)    && \
                                    (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_5A_ES1))
/* PSoC3 ES3 or later */
#define PIDAC10_ANGLE_PSOC3_ES3  ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A)    && \
                                    (CYDEV_CHIP_REVISION_USED > CYDEV_CHIP_REVISION_3A_ES2))
/* PSoC5 ES2 or later */
#define PIDAC10_ANGLE_PSOC5_ES2  ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A)    && \

									
/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct PIDAC10_ANGLE_backupStruct
{
    uint8 enableState;   
	uint8 MSB_data_value;
	uint8 LSB_data_value;
}PIDAC10_ANGLE_backupStruct;


/***************************************
*        Function Prototypes 
***************************************/

void    PIDAC10_ANGLE_Start(void);
void    PIDAC10_ANGLE_Stop(void);
void    PIDAC10_ANGLE_SetSpeed(uint8 speed);
void    PIDAC10_ANGLE_SetPolarity(uint8 polarity);
void    PIDAC10_ANGLE_SetRange(uint8 iRange);
void    PIDAC10_ANGLE_SetValue(uint16 value);

void    PIDAC10_ANGLE_DacTrim(void);

/* Sleep Retention APIs */
void PIDAC10_ANGLE_Init(void);
void PIDAC10_ANGLE_Enable(void);
void PIDAC10_ANGLE_SaveConfig(void);
void PIDAC10_ANGLE_RestoreConfig(void);
void PIDAC10_ANGLE_Sleep(void);
void PIDAC10_ANGLE_Wakeup(void);

/***************************************
*       Initialization Values
***************************************/


#define PIDAC10_ANGLE_DEFAULT_RANGE      1      /* Default DAC range */
#define PIDAC10_ANGLE_DEFAULT_SPEED      ((0 ? 1:0)*2)  /* Default DAC speed */
#define PIDAC10_ANGLE_DEFAULT_CNTL       0x00u             /* Default Control */
#define PIDAC10_ANGLE_DEFAULT_STRB       0    /* Default Strobe mode */
#define PIDAC10_ANGLE_DEFAULT_DATA       100  /* Initial DAC value */
#define PIDAC10_ANGLE_DEFAULT_POLARITY   0       /* Default Sink or Source */
#define PIDAC10_ANGLE_RESOLUTION         10 /* DAC Resolution */

#define PIDAC10_ANGLE_MSB_RSHIFT         (10-8)  /* MSB right shift */
#define PIDAC10_ANGLE_LSB_LSHIFT         (11-10)  /* LSB left shift */
#define PIDAC10_ANGLE_LSB_MASK           ((1<<(10-8))-1) /* Used to mask of the LSbs */


/***************************************
*              Constants        
***************************************/

/* SetRange constants */

#define PIDAC10_ANGLE_RANGE_255uA    0x00u
#define PIDAC10_ANGLE_RANGE_2mA      0x01u

/* SetPolarity constants */
#define PIDAC10_ANGLE_SOURCE         0x00u
#define PIDAC10_ANGLE_SINK           0x04u

/* Power setting for SetSpeed API  */
#define PIDAC10_ANGLE_LOWSPEED       0x00u
#define PIDAC10_ANGLE_HIGHSPEED      0x02u

/* CR0 iDac Control Register 0 definitions */  

/* Bit Field  DAC_HS_MODE                  */
#define PIDAC10_ANGLE_HS_MASK        0x02u
#define PIDAC10_ANGLE_HS_LOWPOWER    0x00u
#define PIDAC10_ANGLE_HS_HIGHSPEED   0x02u

/* Bit Field  DAC_MODE                  */
#define PIDAC10_ANGLE_MODE_MASK      0x10u
#define PIDAC10_ANGLE_MODE_V         0x00u
#define PIDAC10_ANGLE_MODE_I         0x10u

/* Bit Field  DAC_RANGE                  */
#define PIDAC10_ANGLE_DAC_RANGE_MASK     0x0Cu
#define PIDAC10_ANGLE_DAC_RANGE_32uA     0x00u
#define PIDAC10_ANGLE_DAC_RANGE_255uA    0x04u
#define PIDAC10_ANGLE_DAC_RANGE_2040uA   0x08u

/* CR1 iDac Control Register 1 definitions */

/* Bit Field  DAC_MX_DATA                  */
#define PIDAC10_ANGLE_SRC_MASK       0x20u
#define PIDAC10_ANGLE_SRC_REG        0x00u
#define PIDAC10_ANGLE_SRC_UDB        0x20u

/* This bit enable reset from UDB array      */
#define PIDAC10_ANGLE_RESET_MASK     0x10u
#define PIDAC10_ANGLE_RESET_ENABLE   0x10u
#define PIDAC10_ANGLE_RESET_DISABLE  0x00u

/* Bit Field  DAC_MX_IDIR_SRC              */
#define PIDAC10_ANGLE_IDIR_SRC_MASK  0x08u
#define PIDAC10_ANGLE_IDIR_SRC_REG   0x00u
#define PIDAC10_ANGLE_IDIR_SRC_UDB   0x08u

/* Bit Field  DAC_I_DIR                  */
/* Register control of current direction      */
#define PIDAC10_ANGLE_IDIR_MASK      0x04u   
#define PIDAC10_ANGLE_IDIR_SRC       0x04u
#define PIDAC10_ANGLE_IDIR_SINK      0x00u

/* Bit Field  DAC_MX_IOFF_SRC                  */
/* Selects source of IOFF control, reg or UDB  */
#define PIDAC10_ANGLE_IDIR_CTL_MASK  0x02u
#define PIDAC10_ANGLE_IDIR_CTL_REG   0x00u
#define PIDAC10_ANGLE_IDIR_CTL_UDB   0x02u

/* Bit Field  DAC_MX_IOFF                   */
/* Register control of IDAC                 */
/* Only valid if IOFF CTL is set to Reg     */
#define PIDAC10_ANGLE_I_OFF_MASK     0x01u   
#define PIDAC10_ANGLE_I_OFF          0x00u
#define PIDAC10_ANGLE_I_ON           0x01u

/* This bit enables data from DAC bus      */
#define PIDAC10_ANGLE_DACBUS_MASK     0x20u
#define PIDAC10_ANGLE_DACBUS_ENABLE   0x20u
#define PIDAC10_ANGLE_DACBUS_DISABLE  0x00u

/* DAC STROBE Strobe Control Register definitions */


/* Bit Field  DAC_MX_STROBE                  */
#define PIDAC10_ANGLE_STRB_MASK      0x08u
#define PIDAC10_ANGLE_STRB_EN        0x08u
#define PIDAC10_ANGLE_STRB_DIS       0x00u

/* PM_ACT_CFG (Active Power Mode CFG Register)     */ 
#define PIDAC10_ANGLE_MSB_ACT_PWR_EN   PIDAC10_ANGLE_viDAC8_MSB__PM_ACT_MSK /* Power enable mask */ 
#define PIDAC10_ANGLE_LSB_ACT_PWR_EN   PIDAC10_ANGLE_viDAC8_LSB__PM_ACT_MSK /* Power enable mask */ 

/***************************************
*              Registers        
***************************************/

#define PIDAC10_ANGLE_MSB_CR0    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__CR0 )
#define PIDAC10_ANGLE_MSB_CR1    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__CR1 )
#define PIDAC10_ANGLE_MSB_Data   (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__D )
#define PIDAC10_ANGLE_MSB_Strobe (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__STROBE )
#define PIDAC10_ANGLE_MSB_SW0    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__SW0 )
#define PIDAC10_ANGLE_MSB_SW2    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__SW2 )
#define PIDAC10_ANGLE_MSB_SW3    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__SW3 )
#define PIDAC10_ANGLE_MSB_SW4    (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__SW4 )
#define PIDAC10_ANGLE_MSB_TR     (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__TR )
#define PIDAC10_ANGLE_MSB_PWRMGR (* (reg8 *) PIDAC10_ANGLE_viDAC8_MSB__PM_ACT_CFG )  /* Power manager */

#define PIDAC10_ANGLE_LSB_CR0    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__CR0 )
#define PIDAC10_ANGLE_LSB_CR1    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__CR1 )
#define PIDAC10_ANGLE_LSB_Data   (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__D )
#define PIDAC10_ANGLE_LSB_Strobe (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__STROBE )
#define PIDAC10_ANGLE_LSB_SW0    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__SW0 )
#define PIDAC10_ANGLE_LSB_SW2    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__SW2 )
#define PIDAC10_ANGLE_LSB_SW3    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__SW3 )
#define PIDAC10_ANGLE_LSB_SW4    (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__SW4 )
#define PIDAC10_ANGLE_LSB_TR     (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__TR )
#define PIDAC10_ANGLE_LSB_PWRMGR (* (reg8 *) PIDAC10_ANGLE_viDAC8_LSB__PM_ACT_CFG )  /* Power manager */


/***************************************
*              Trim        
***************************************/
#define PIDAC10_ANGLE_TRIM_M1_RNG0_SRC_OFFSET   0x00u
#define PIDAC10_ANGLE_TRIM_M2_RNG0_SINK_OFFSET  0x01u
#define PIDAC10_ANGLE_TRIM_M3_RNG1_SRC_OFFSET   0x02u
#define PIDAC10_ANGLE_TRIM_M4_RNG1_SINK_OFFSET  0x03u
#define PIDAC10_ANGLE_TRIM_M5_RNG2_SRC_OFFSET   0x04u
#define PIDAC10_ANGLE_TRIM_M6_RNG2_SINK_OFFSET  0x05u


#define PIDAC10_ANGLE_TRIM_M7_4V_RNG_OFFSET  0x07u

/* MSB Trim */
#define PIDAC10_ANGLE_MSB_DAC_POS  (PIDAC10_ANGLE_viDAC8_MSB__D - CYDEV_ANAIF_WRK_DAC0_BASE)

#if(PIDAC10_ANGLE_MSB_DAC_POS == 0)
#define PIDAC10_ANGLE_MSB_DAC_TRIM_BASE  0x0C011Cu
#endif

#if(PIDAC10_ANGLE_MSB_DAC_POS == 1)
#define PIDAC10_ANGLE_MSB_DAC_TRIM_BASE  0x0C012Cu
#endif

#if(PIDAC10_ANGLE_MSB_DAC_POS == 2)
#define PIDAC10_ANGLE_MSB_DAC_TRIM_BASE  0x0C0124u
#endif

#if(PIDAC10_ANGLE_MSB_DAC_POS == 3)
#define PIDAC10_ANGLE_MSB_DAC_TRIM_BASE  0x0C0134u
#endif

/* LSB Trim */
#define PIDAC10_ANGLE_LSB_DAC_POS  (PIDAC10_ANGLE_viDAC8_LSB__D - CYDEV_ANAIF_WRK_DAC0_BASE)

#if(PIDAC10_ANGLE_LSB_DAC_POS == 0)
#define PIDAC10_ANGLE_LSB_DAC_TRIM_BASE  0x0C011Cu
#endif

#if(PIDAC10_ANGLE_LSB_DAC_POS == 1)
#define PIDAC10_ANGLE_LSB_DAC_TRIM_BASE  0x0C012Cu
#endif

#if(PIDAC10_ANGLE_LSB_DAC_POS == 2)
#define PIDAC10_ANGLE_LSB_DAC_TRIM_BASE  0x0C0124u
#endif

#if(PIDAC10_ANGLE_LSB_DAC_POS == 3)
#define PIDAC10_ANGLE_LSB_DAC_TRIM_BASE  0x0C0134u
#endif

#endif /* CY_IDAC8_PIDAC10_ANGLE_H  */
/*  [] END OF FILE  */
