/*******************************************************************************
* File Name: QuadDec_PAN_INT.c
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

#include "QuadDec_PAN.h"
#include "QuadDec_PAN_PVT.h"

volatile int32 QuadDec_PAN_count32SoftPart = 0;


/*******************************************************************************
* FUNCTION NAME: void QuadDec_PAN_ISR
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
*  QuadDec_PAN_count32SoftPart - modified to update hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*  QuadDec_PAN_swStatus - modified with the updated values of STATUS
*  register.
*
*******************************************************************************/
CY_ISR( QuadDec_PAN_ISR )
{
   uint8 QuadDec_PAN_swStatus;

   QuadDec_PAN_swStatus = QuadDec_PAN_STATUS_REG;

    /* User code required at start of ISR */
    /* `#START QuadDec_PAN_ISR_START` */
	
	#include <gobee.h>
	
	/* GoBee Faults structure */
	extern struct GOBEE_FAULTS gobeeFaults;		

    /* `#END` */

    if (0u != (QuadDec_PAN_swStatus & QuadDec_PAN_COUNTER_OVERFLOW))
    {
        QuadDec_PAN_count32SoftPart += (int32) QuadDec_PAN_COUNTER_MAX_VALUE;
    }
    else if (0u != (QuadDec_PAN_swStatus & QuadDec_PAN_COUNTER_UNDERFLOW))
    {
        QuadDec_PAN_count32SoftPart -= (int32) QuadDec_PAN_COUNTER_INIT_VALUE;
    }
    else
    {
        /* Nothing to do here */
    }
    
    if (0u != (QuadDec_PAN_swStatus & QuadDec_PAN_COUNTER_RESET))
    {
        QuadDec_PAN_count32SoftPart = 0;
    }
    
    /* User code required at end of ISR */
    /* `#START QuadDec_PAN_ISR_END` */

    if (0u != (QuadDec_PAN_swStatus & QuadDec_PAN_INVALID_IN))
    {
        gobeeFaults.FbkEncFaults = PAN_FBKENC_INVT_FAULT;
    }
	
    /* `#END` */
}


/* [] END OF FILE */
