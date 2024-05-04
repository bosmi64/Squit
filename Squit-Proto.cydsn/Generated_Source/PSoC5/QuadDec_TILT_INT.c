/*******************************************************************************
* File Name: QuadDec_TILT_INT.c
* Version 2.40
*
* Description:
*  This file contains the Interrupt Service Routine (ISR) for the Quadrature
*  Decoder component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDec_TILT.h"
#include "QuadDec_TILT_PVT.h"

volatile int32 QuadDec_TILT_count32SoftPart = 0;


/*******************************************************************************
* FUNCTION NAME: void QuadDec_TILT_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for Quadrature Decoder Component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  QuadDec_TILT_count32SoftPart - modified to update hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*  QuadDec_TILT_swStatus - modified with the updated values of STATUS
*  register.
*
*******************************************************************************/
CY_ISR( QuadDec_TILT_ISR )
{
   uint8 QuadDec_TILT_swStatus;

   QuadDec_TILT_swStatus = QuadDec_TILT_STATUS_REG;

    /* User code required at start of ISR */
    /* `#START QuadDec_TILT_ISR_START` */

	#include <gobee.h>
	
	/* GoBee Faults structure */
	extern struct GOBEE_FAULTS gobeeFaults;		
	
    /* `#END` */

    if (0u != (QuadDec_TILT_swStatus & QuadDec_TILT_COUNTER_OVERFLOW))
    {
        QuadDec_TILT_count32SoftPart += (int32) QuadDec_TILT_COUNTER_MAX_VALUE;
    }
    else if (0u != (QuadDec_TILT_swStatus & QuadDec_TILT_COUNTER_UNDERFLOW))
    {
        QuadDec_TILT_count32SoftPart -= (int32) QuadDec_TILT_COUNTER_INIT_VALUE;
    }
    else
    {
        /* Nothing to do here */
    }
    
    if (0u != (QuadDec_TILT_swStatus & QuadDec_TILT_COUNTER_RESET))
    {
        QuadDec_TILT_count32SoftPart = 0;
    }
    
    /* User code required at end of ISR */
    /* `#START QuadDec_TILT_ISR_END` */

    if (0u != (QuadDec_TILT_swStatus & QuadDec_TILT_INVALID_IN))
    {
        gobeeFaults.FbkEncFaults = TILT_FBKENC_INVT_FAULT;
    }
	
    /* `#END` */
}


/* [] END OF FILE */
