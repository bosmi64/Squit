
/*******************************************************************************
* File Name: PIDAC10_ANGLE.c  
* Version 1.2
*
*  Description:
*    This file provides the source code to the API for the parallel Current DAC 
*    (PIDAC) Component.
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
#include "PIDAC10_ANGLE.h"   

uint8 PIDAC10_ANGLE_initVar = 0;

/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Start
********************************************************************************
* Summary:  Initialize and power up both DACs
*
* Parameters:  
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_Start(void) 
{
   /* Hardware initiazation only needs to occure the first time */
   if ( PIDAC10_ANGLE_initVar == 0)  
   {     
       PIDAC10_ANGLE_initVar = 1;
	   PIDAC10_ANGLE_Init();   
	}
	
	/* Enable power to DAC */
    PIDAC10_ANGLE_Enable();
   
    /* Set default value */
    PIDAC10_ANGLE_SetValue(PIDAC10_ANGLE_DEFAULT_DATA);
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Enable
********************************************************************************
* Summary:  
*   Power up both DACs
*
* Parameters:  
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_Enable(void) 
{
  
       /* Enable power to DAC */
   PIDAC10_ANGLE_MSB_PWRMGR |= PIDAC10_ANGLE_MSB_ACT_PWR_EN;
   PIDAC10_ANGLE_LSB_PWRMGR |= PIDAC10_ANGLE_LSB_ACT_PWR_EN;

}

/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Init
********************************************************************************
* Summary:
*  Initialize mode, range, and polarity.
*
* Parameters: 
* ( void )
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_Init(void) 
{
   /* Setup block modes */
   PIDAC10_ANGLE_MSB_CR0 = PIDAC10_ANGLE_MODE_I;
   PIDAC10_ANGLE_LSB_CR0 = PIDAC10_ANGLE_MODE_I;
   
   PIDAC10_ANGLE_SetRange(PIDAC10_ANGLE_DEFAULT_RANGE);

   PIDAC10_ANGLE_MSB_CR1 = (PIDAC10_ANGLE_DEFAULT_CNTL | PIDAC10_ANGLE_DACBUS_DISABLE | PIDAC10_ANGLE_DEFAULT_POLARITY) ;   
   PIDAC10_ANGLE_LSB_CR1 = (PIDAC10_ANGLE_DEFAULT_CNTL | PIDAC10_ANGLE_DACBUS_DISABLE | PIDAC10_ANGLE_DEFAULT_POLARITY) ;   

    /* Set default strobe mode */
   if(PIDAC10_ANGLE_DEFAULT_STRB != 0)
   {
       PIDAC10_ANGLE_MSB_Strobe |= PIDAC10_ANGLE_STRB_EN ;
       PIDAC10_ANGLE_LSB_Strobe |= PIDAC10_ANGLE_STRB_EN ;
   }

   /* Set default speed */
   PIDAC10_ANGLE_SetSpeed(PIDAC10_ANGLE_DEFAULT_SPEED); 

   /* Set proper DAC trim */
   PIDAC10_ANGLE_DacTrim();
  
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_Stop
********************************************************************************
* Summary:
*  Powers down PIDAC to lowest power state.
*
* Parameters:  
*   (void)
*
* Return: 
*  (void)
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_Stop(void)
{
   /* Disble power to DAC */
   PIDAC10_ANGLE_MSB_PWRMGR &= ~PIDAC10_ANGLE_MSB_ACT_PWR_EN;
   PIDAC10_ANGLE_LSB_PWRMGR &= ~PIDAC10_ANGLE_LSB_ACT_PWR_EN;
}

/*******************************************************************************
* Function Name: PIDAC10_ANGLE_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:  
*  power:   Sets speed value
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_SetSpeed(uint8 speed) 
{
   /* Clear power mask then write in new value */
   PIDAC10_ANGLE_MSB_CR0 &= ~PIDAC10_ANGLE_HS_MASK ;    
   PIDAC10_ANGLE_MSB_CR0 |=  ( speed & PIDAC10_ANGLE_HS_MASK) ;    

   PIDAC10_ANGLE_LSB_CR0 &= ~PIDAC10_ANGLE_HS_MASK ;    
   PIDAC10_ANGLE_LSB_CR0 |=  ( speed & PIDAC10_ANGLE_HS_MASK) ;    
}

/*******************************************************************************
* Function Name: PIDAC10_ANGLE_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current
*
* Parameters:  
*  Polarity: Sets the IDAC to Sink or Source
*             0 = sink, 1 = source
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_SetPolarity(uint8 polarity)
{
   
   PIDAC10_ANGLE_MSB_CR1 &= ~PIDAC10_ANGLE_IDIR_MASK ;   
   PIDAC10_ANGLE_LSB_CR1 &= ~PIDAC10_ANGLE_IDIR_MASK ;   
   if(polarity == 0)     /* Sink Current */
   {
      PIDAC10_ANGLE_MSB_CR1 &= ~PIDAC10_ANGLE_IDIR_SINK ;   
      PIDAC10_ANGLE_LSB_CR1 &= ~PIDAC10_ANGLE_IDIR_SINK ;   
   }
   else               /* Source Current */
   {
      PIDAC10_ANGLE_MSB_CR1 |= PIDAC10_ANGLE_IDIR_SRC ;   
      PIDAC10_ANGLE_LSB_CR1 |= PIDAC10_ANGLE_IDIR_SRC ;   
   }
   PIDAC10_ANGLE_DacTrim();
}

/*******************************************************************************
* Function Name: PIDAC10_ANGLE_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:  
*  Range:  Sets on of four valid ranges.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_SetRange(uint8 range)
{
   if(range == PIDAC10_ANGLE_RANGE_255uA)  /* 255uA Range */
   {
      PIDAC10_ANGLE_MSB_CR0 &= ~PIDAC10_ANGLE_DAC_RANGE_MASK ;            /* Clear MSB existing mode */
      PIDAC10_ANGLE_MSB_CR0 |= PIDAC10_ANGLE_DAC_RANGE_255uA;             /* Set MSB Range to 255uA  */
	  
	  PIDAC10_ANGLE_LSB_CR0 &= ~PIDAC10_ANGLE_DAC_RANGE_MASK ;            /* Clear MSB existing mode */
      PIDAC10_ANGLE_LSB_CR0 |= PIDAC10_ANGLE_DAC_RANGE_32uA;              /* Set MSB Range to 32uA  */
   }
   else                                       /* 2mA Range */
   {
      PIDAC10_ANGLE_MSB_CR0 &= ~PIDAC10_ANGLE_DAC_RANGE_MASK ;            /* Clear MSB existing mode */
      PIDAC10_ANGLE_MSB_CR0 |= PIDAC10_ANGLE_DAC_RANGE_2040uA;            /* Set MSB Range to 2040uA  */
	  
	  PIDAC10_ANGLE_LSB_CR0 &= ~PIDAC10_ANGLE_DAC_RANGE_MASK ;            /* Clear MSB existing mode */
      PIDAC10_ANGLE_LSB_CR0 |= PIDAC10_ANGLE_DAC_RANGE_255uA;             /* Set MSB Range to 255uA  */
   }
	PIDAC10_ANGLE_DacTrim();
}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 2047.
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_SetValue(uint16 value)
{
   uint8 msb;
   uint8 lsb;

    msb = (uint8)(value >> PIDAC10_ANGLE_MSB_RSHIFT);
	lsb = (uint8) ((value & PIDAC10_ANGLE_LSB_MASK)<< PIDAC10_ANGLE_LSB_LSHIFT);
	

    PIDAC10_ANGLE_MSB_Data = msb;             /*  Set MSB Value  */
    PIDAC10_ANGLE_LSB_Data = lsb;             /*  Set LSB Value  */
    
    #if (PIDAC10_ANGLE_PSOC3_ES2 || PIDAC10_ANGLE_PSOC5_ES1)
	    PIDAC10_ANGLE_MSB_Data = msb;         /*  Set MSB Value  */
     	PIDAC10_ANGLE_LSB_Data = lsb;         /*  Set LSB Value  */
    #endif 

}


/*******************************************************************************
* Function Name: PIDAC10_ANGLE_DacTrim
********************************************************************************
* Summary:
*  Set the trim value for the given range.
*
* Parameters:  
*  value:  Sets DAC value between 0 and 2^bits - 1
*
* Return: 
*  (void) 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void PIDAC10_ANGLE_DacTrim(void)
{
 	uint8 mode;
	
   /* Trim MSB */
	mode = ((PIDAC10_ANGLE_MSB_CR0 & PIDAC10_ANGLE_DAC_RANGE_MASK) >> 1);
	if((PIDAC10_ANGLE_IDIR_MASK & PIDAC10_ANGLE_MSB_CR1) == PIDAC10_ANGLE_IDIR_SINK)
	{
		mode++;
	}
	PIDAC10_ANGLE_MSB_TR = CY_GET_XTND_REG8((uint8 *)(PIDAC10_ANGLE_MSB_DAC_TRIM_BASE + mode));

   /* Trim LSB */
	mode = ((PIDAC10_ANGLE_LSB_CR0 & PIDAC10_ANGLE_DAC_RANGE_MASK) >> 1);
	if((PIDAC10_ANGLE_IDIR_MASK & PIDAC10_ANGLE_LSB_CR1) == PIDAC10_ANGLE_IDIR_SINK)
	{
		mode++;
	}
	PIDAC10_ANGLE_LSB_TR = CY_GET_XTND_REG8((uint8 *)(PIDAC10_ANGLE_LSB_DAC_TRIM_BASE + mode));
}

/* [] END OF FILE */


