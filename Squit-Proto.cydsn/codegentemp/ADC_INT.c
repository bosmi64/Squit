/*******************************************************************************
* File Name: ADC_INT.c
* Version 3.10
*
* Description:
*  This file contains the code that operates during the ADC_DelSig interrupt
*  service routine.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC.h"


/*******************************************************************************
* Custom Declarations and Variables
* - add user include files, prototypes and variables between the following
*   #START and #END tags
*******************************************************************************/
/* `#START ADC_SYS_VAR`  */
#include "AMuxSeq.h"
#include <device.h>
#include <gobee.h>
#include <gobeelib.h>

uint8 iIndex=0;
uint16 Conversion=0;
extern int16 AdcValue[ADC_MUX_LENGHT];
/* `#END`  */


#if(ADC_IRQ_REMOVE == 0u)


    /*****************************************************************************
    * Function Name: ADC_ISR1
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( ADC_ISR1)
    {
        /**************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR1`  */
#if MEASURE_ADC_ISR
Control_Reg_LED_Write(0x01);
#endif
	
		ADC_StopConvert();						//The ADC is stopped after every conversion. This is to reduce the crosstalk between channels
		
		Conversion = ADC_GetResult16();			//Get the ADC result for the present channel
		
		AMuxSeq_Next();							// Connect next channel.
		
		AdcValue[iIndex] = Conversion;			// Store Conversion into the array
		
		iIndex=(iIndex+1)%ADC_MUX_LENGHT;		//Increment the channel index for the next channel
		
		ADC_StartConvert();	
	
#if MEASURE_ADC_ISR
Control_Reg_LED_Write(0x00);
#endif
        /* `#END`  */

        /* Stop the conversion if conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(ADC_CFG1_RESOLUTION > 16 && \
            ADC_CFG1_CONV_MODE == ADC_MODE_SINGLE_SAMPLE)
            ADC_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            ADC_convDone = ADC_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

    }


    /*****************************************************************************
    * Function Name: ADC_ISR2
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( ADC_ISR2)
    {
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR2`  */

        /* `#END`  */

        /* Stop the conversion conversion mode is single sample and resolution
        *  is above 16 bits.
        */
        #if(ADC_CFG2_RESOLUTION > 16 && \
            ADC_CFG2_CONVMODE == ADC_MODE_SINGLE_SAMPLE)
            ADC_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *   resolution is above 16 bits and conversion mode is single sample 
			*/
            ADC_convDone = ADC_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */

    }


    /*****************************************************************************
    * Function Name: ADC_ISR3
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( ADC_ISR3)
    {
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR3`  */

        /* `#END`  */

        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(ADC_CFG3_RESOLUTION > 16 && \
            ADC_CFG3_CONVMODE == ADC_MODE_SINGLE_SAMPLE)
            ADC_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            ADC_convDone = ADC_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */
    }


    /*****************************************************************************
    * Function Name: ADC_ISR4
    ******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    * Reentrant:
    *  No
    *
    *****************************************************************************/
    CY_ISR( ADC_ISR4)
    {
        /***************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        **************************************************************************/
        /* `#START MAIN_ADC_ISR4`  */

        /* `#END`  */

        /* Stop the conversion if conversion mode is set to single sample and
        *  resolution is above 16 bits.
        */
        #if(ADC_CFG4_RESOLUTION > 16 && \
            ADC_CFG4_CONVMODE == ADC_MODE_SINGLE_SAMPLE)
            ADC_StopConvert();
            /* Software flag for checking conversion complete or not. Will be used when
            *  resolution is above 16 bits and conversion mode is single sample 
			*/
            ADC_convDone = ADC_DEC_CONV_DONE;
        #endif /* Single sample conversion mode with resolution above 16 bits */
    }

#endif   /* End ADC_IRQ_REMOVE */


/* [] END OF FILE */
