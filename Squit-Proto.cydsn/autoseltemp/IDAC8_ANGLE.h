/*******************************************************************************
* File Name: IDAC8_ANGLE.h  
* Version 1.80
*
*  Description:
*    This file contains the function prototypes and constants used in
*    the 8-bit Current DAC (IDAC8) User Module.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_IDAC8_IDAC8_ANGLE_H)  
#define CY_IDAC8_IDAC8_ANGLE_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct IDAC8_ANGLE_backupStruct
{
    uint8 enableState;
    uint8 data_value;
    uint8 DACCR0Reg;
}IDAC8_ANGLE_backupStruct;


/***************************************
*        Function Prototypes 
***************************************/

void    IDAC8_ANGLE_Start(void);
void    IDAC8_ANGLE_Stop(void) ;
void    IDAC8_ANGLE_SetSpeed(uint8 speed) ;
void    IDAC8_ANGLE_SetPolarity(uint8 polarity) ;
void    IDAC8_ANGLE_SetRange(uint8 iRange) ;
void    IDAC8_ANGLE_SetValue(uint8 value) ;
void    IDAC8_ANGLE_DacTrim(void) ;

/* Sleep Retention APIs */
void IDAC8_ANGLE_Init(void) ;
void IDAC8_ANGLE_Enable(void) ;
void IDAC8_ANGLE_SaveConfig(void);
void IDAC8_ANGLE_RestoreConfig(void);
void IDAC8_ANGLE_Sleep(void);
void IDAC8_ANGLE_Wakeup(void);
 
  
/***************************************
*       Paramater Initial Values
***************************************/

#define IDAC8_ANGLE_DEFAULT_RANGE     8u      /* Default DAC range */
#define IDAC8_ANGLE_DEFAULT_SPEED     ((2u ? 1u:0u)*2)  /* Default DAC speed */
#define IDAC8_ANGLE_DEFAULT_CNTL      0x00u             /* Default Control */
#define IDAC8_ANGLE_DEFAULT_STRB     0u    /* Default Strobe mode */
#define IDAC8_ANGLE_DEFAULT_DATA     128u          /* Initial DAC value */
#define IDAC8_ANGLE_DEFAULT_POLARITY 0u       /* Default Sink or Source */
#define IDAC8_ANGLE_DEFAULT_DATA_SRC 0u    /* Default Data Source */   
#define IDAC8_ANGLE_HARDWARE_ENABLE  0u /*Hardware Enable */
/***************************************
*              API Constants        
***************************************/

/* SetRange constants */

#define IDAC8_ANGLE_RANGE_32uA             (0x00u)
#define IDAC8_ANGLE_RANGE_255uA            (0x04u)
#define IDAC8_ANGLE_RANGE_2mA              (0x08u)

/* SetPolarity constants */
#define IDAC8_ANGLE_SOURCE                 (0x00u)
#define IDAC8_ANGLE_SINK                   (0x04u)
#define IDAC8_ANGLE_HARDWARE_CONTROLLED    (0x02u)
/* Power setting for SetSpeed API  */
#define IDAC8_ANGLE_LOWSPEED               (0x00u)
#define IDAC8_ANGLE_HIGHSPEED              (0x02u)


/***************************************
*              Registers        
***************************************/

#define IDAC8_ANGLE_CR0         (* (reg8 *) IDAC8_ANGLE_viDAC8__CR0 )
#define IDAC8_ANGLE_CR1         (* (reg8 *) IDAC8_ANGLE_viDAC8__CR1 )
#define IDAC8_ANGLE_Data        (* (reg8 *) IDAC8_ANGLE_viDAC8__D )
#define IDAC8_ANGLE_Data_PTR    (  (reg8 *) IDAC8_ANGLE_viDAC8__D )
#define IDAC8_ANGLE_Strobe      (* (reg8 *) IDAC8_ANGLE_viDAC8__STROBE )
#define IDAC8_ANGLE_SW0         (* (reg8 *) IDAC8_ANGLE_viDAC8__SW0 )
#define IDAC8_ANGLE_SW2         (* (reg8 *) IDAC8_ANGLE_viDAC8__SW2 )
#define IDAC8_ANGLE_SW3         (* (reg8 *) IDAC8_ANGLE_viDAC8__SW3 )
#define IDAC8_ANGLE_SW4         (* (reg8 *) IDAC8_ANGLE_viDAC8__SW4 )
#define IDAC8_ANGLE_TR          (* (reg8 *) IDAC8_ANGLE_viDAC8__TR )
#define IDAC8_ANGLE_PWRMGR      (* (reg8 *) IDAC8_ANGLE_viDAC8__PM_ACT_CFG )  /* Power manager */
#define IDAC8_ANGLE_STBY_PWRMGR (* (reg8 *) IDAC8_ANGLE_viDAC8__PM_STBY_CFG )  /* Standby Power manager */


/******************************************************************************
*              Trim    
*
* Note - VIDAC trim values are stored in the "Customer Table" area in 
* Row 1 of the Hidden Flash.  There are 8 bytes of trim data for each VIDAC 
* block.
* The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* The data set for the 4 VIDACs are arranged using a left side/right 
* side approach:
*   Left 0, Left 1, Right 0, Right 1.
* When mapped to the VIDAC0 thru VIDAC3 as:
*   VIDAC 0, VIDAC 2, VIDAC 1, VIDAC 3
******************************************************************************/

#define IDAC8_ANGLE_DAC_TRIM_BASE   IDAC8_ANGLE_viDAC8__TRIM__M1


/***************************************
*         Register Constants       
***************************************/

/* CR0 iDAC Control Register 0 definitions */  

/* Bit Field  DAC_HS_MODE                  */
#define IDAC8_ANGLE_HS_MASK        (0x02u)
#define IDAC8_ANGLE_HS_LOWPOWER    (0x00u)
#define IDAC8_ANGLE_HS_HIGHSPEED   (0x02u)

/* Bit Field  DAC_MODE                  */
#define IDAC8_ANGLE_MODE_MASK      (0x10u)
#define IDAC8_ANGLE_MODE_V         (0x00u)
#define IDAC8_ANGLE_MODE_I         (0x10u)

/* Bit Field  DAC_RANGE                  */
#define IDAC8_ANGLE_RANGE_MASK     (0x0Cu)
#define IDAC8_ANGLE_RANGE_0        (0x00u)
#define IDAC8_ANGLE_RANGE_1        (0x04u)
#define IDAC8_ANGLE_RANGE_2        (0x08u)
#define IDAC8_ANGLE_RANGE_3        (0x0Cu)

/* CR1 iDAC Control Register 1 definitions */

/* Bit Field  DAC_MX_DATA                  */
#define IDAC8_ANGLE_SRC_MASK       (0x20u)
#define IDAC8_ANGLE_SRC_REG        (0x00u)
#define IDAC8_ANGLE_SRC_UDB        (0x20u)

/* This bit enable reset from UDB array      */
#define IDAC8_ANGLE_RESET_MASK     (0x10u)
#define IDAC8_ANGLE_RESET_ENABLE   (0x10u)
#define IDAC8_ANGLE_RESET_DISABLE  (0x00u)

/* Bit Field  DAC_MX_IDIR_SRC              */
#define IDAC8_ANGLE_IDIR_SRC_MASK  (0x08u)
#define IDAC8_ANGLE_IDIR_SRC_REG   (0x00u)
#define IDAC8_ANGLE_IDIR_SRC_UDB   (0x08u)

/* Bit Field  DAC_I_DIR                  */
/* Register control of current direction      */
#define IDAC8_ANGLE_IDIR_MASK      (0x04u)   
#define IDAC8_ANGLE_IDIR_SRC       (0x00u)
#define IDAC8_ANGLE_IDIR_SINK      (0x04u)

/* Bit Field  DAC_MX_IOFF_SRC                  */
/* Selects source of IOFF control, reg or UDB  */
#define IDAC8_ANGLE_IDIR_CTL_MASK  (0x02u)
#define IDAC8_ANGLE_IDIR_CTL_REG   (0x00u)
#define IDAC8_ANGLE_IDIR_CTL_UDB   (0x02u)

/* Bit Field  DAC_MX_IOFF                   */
/* Register control of IDAC                 */
/* Only valid if IOFF CTL is set to Reg     */
#define IDAC8_ANGLE_I_OFF_MASK     (0x01u)   
#define IDAC8_ANGLE_I_OFF          (0x00u)
#define IDAC8_ANGLE_I_ON           (0x01u)

/* This bit enables data from DAC bus      */
#define IDAC8_ANGLE_DACBUS_MASK    (0x20u)
#define IDAC8_ANGLE_DACBUS_ENABLE  (0x20u)
#define IDAC8_ANGLE_DACBUS_DISABLE (0x00u)

/* DAC STROBE Strobe Control Register definitions */

/* Bit Field  DAC_MX_STROBE                  */
#define IDAC8_ANGLE_STRB_MASK      (0x08u)
#define IDAC8_ANGLE_STRB_EN        (0x08u)
#define IDAC8_ANGLE_STRB_DIS       (0x00u)

/* PM_ACT_CFG (Active Power Mode CFG Register)     */ 
#define IDAC8_ANGLE_ACT_PWR_EN   IDAC8_ANGLE_viDAC8__PM_ACT_MSK  /* Power enable mask */ 
#define IDAC8_ANGLE_STBY_PWR_EN  IDAC8_ANGLE_viDAC8__PM_STBY_MSK  /* Standby Power enable mask */ 

#endif /* CY_IDAC8_IDAC8_ANGLE_H */


/* [] END OF FILE */
