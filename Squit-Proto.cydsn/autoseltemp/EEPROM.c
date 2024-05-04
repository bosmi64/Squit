/*******************************************************************************
* File Name: EEPROM.c
* Version 1.60
*
* Description:
*  Provides an API for the EEPROM component.
*
********************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include <Cydevice_trm.h>
#include <EEPROM.H>
#include "CYFLASH.H"


#if (CY_PSOC3_ES3 || CY_PSOC5_ES2)
/*******************************************************************************
* Function Name: EEPROM_Enable
********************************************************************************
* Summary: 
*  Enable the EEPROM.
*
* Parameters:  
*  void
*
* Return:
* void
*
* Reentrant
*  Yes
*
*******************************************************************************/
void EEPROM_Enable(void) 
{
    CyEEPROM_Start();
}


/*******************************************************************************
* Function Name: EEPROM_Start       
********************************************************************************
* Summary:
*  Starts EEPROM
*
* Parameters:
*  void.
*
* Return:
*  void
* 
* Reentrant
*  Yes
*
*******************************************************************************/
void EEPROM_Start(void) 
{
    /* Enable the EEPROM */
    EEPROM_Enable();
}


/*******************************************************************************
* Function Name: EEPROM_Stop
********************************************************************************
*
* Summary:
*  Stops and powers down EEPROM.
*   
* Parameters:
*  void
* 
* Return:
*  void  
* 
* Reentrant
*  Yes
*
*******************************************************************************/
void EEPROM_Stop (void) 
{
    /* Disable EEPROM */
    CyEEPROM_Stop();
}
#endif /* (CY_PSOC3_ES3 || CY_PSOC5_ES2) */


/*******************************************************************************
* Function Name: EEPROM_EraseSector
********************************************************************************
* 
* Summary:
*  Erases a sector of memory. This function blocks until the operation is 
*  complete.
*
* Parameters:
*  sectorNumber. Sector number to erase.
*
* Return:
*  CYRET_SUCCESS if the operation was successful.
*  CYRET_BAD_PARAM if the parameters were invalid.
*  CYRET_LOCKED if the spc is being used.
*  CYRET_UNKNOWN if there was an SPC error.
*
* Reentrant
*  Yes
*
*******************************************************************************/
cystatus EEPROM_EraseSector(uint8 sectorNumber) 
{
    cystatus status;
    
    uint8* rowData;
    uint8 testdata0[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    rowData = testdata0;

    /* Make sure SPC is powered. */
    CySpcActivePower(1);

    if(sectorNumber < (uint8)(EEPROM_EEPROM_SIZE / (CYDEV_EEPROM_ROW_SIZE * 64)))
    {
        /* See if we can get the SPC. */
        if(CySpcLock() == CYRET_SUCCESS)
        {
            /* Plan for failure. */
            status = CYRET_UNKNOWN;

            #if (CY_PSOC5_ES1)

            /* Create the command to load the row latch. */
            if(CySpcCreateCmdLoadRow(FIRST_EE_ARRAYID) == CYRET_SUCCESS)
            {
                /* Write the command. */
                if(CySpcWriteCommand(rowData, CYDEV_EEPROM_ROW_SIZE) == CYRET_STARTED)
                {
                    /* Spin until completion. */
                    while(!(*SPC_STATUS & SPC_SPC_IDLE))
                    {
                        /* CyDelay(1); */
                    }

                    /* See if we were successful. */
                    if(CySpcReadStatus == CYRET_SUCCESS)
                    {
                        status = CYRET_SUCCESS;
                    }
                }
            }

            /* Create the command to erase a sector. */
            if(status == CYRET_SUCCESS && CySpcCreateCmdEraseSector(FIRST_EE_ARRAYID, sectorNumber) == CYRET_SUCCESS)
            
            #else

            if(CySpcCreateCmdEraseSector(FIRST_EE_ARRAYID, sectorNumber) == CYRET_SUCCESS)

            #endif /* (CY_PSOC5_ES1) */

            {
                /* Write the command. */
                if(CySpcWriteCommand(0, 0) == CYRET_STARTED)
                {
                    /* Spin until completion. */
                    while(!(*SPC_STATUS & SPC_SPC_IDLE))
                    {
                        CyDelay(1);
                    }

                    /* See if we were successful. */
                    if(CySpcReadStatus == CYRET_SUCCESS)
                    {
                        status = CYRET_SUCCESS;
                    }
                }
            }


            /* Unlock the SPC so someone else can use it. */
            CySpcUnlock();
        }
        else
        {
            status = CYRET_LOCKED;
        }
    }
    else
    {
        status = CYRET_BAD_PARAM;
    }

    return status;
}


/*******************************************************************************
* Function Name: EEPROM_Write
********************************************************************************
* 
* Summary:
*  Writes a line, CYDEV_EEPROM_ROW_SIZE of data to the EEPROM. This is
*  a blocking call. It will not return until the function succeeds or fails.
*
* Parameters:
*  rowData. Address of the row of data to write to the EEPROM.
*
*  rowNumber. EEPROM row number to program.
*
* Return:
*  CYRET_SUCCESS if the operation was successful.
*  CYRET_BAD_PARAM if the parameters were invalid.
*  CYRET_LOCKED if the spc is being used.
*  CYRET_UNKNOWN if there was an SPC error.
*
* Reentrant
*  Yes
*
*******************************************************************************/
cystatus EEPROM_Write(uint8 * rowData, uint8 rowNumber) 
{
    cystatus status;

    /* Make sure SPC is powerd. */
    CySpcActivePower(1);

    if(rowNumber < (uint8)(EEPROM_EEPROM_SIZE / CYDEV_EEPROM_ROW_SIZE))
    {
        /* Get the die temp. */
        status = CySetTemp();

        /* See if we can get the SPC. */
        if(status == CYRET_SUCCESS && CySpcLock() == CYRET_SUCCESS)
        {
            status = CYRET_UNKNOWN;

            /* Create the command to load the row latch. */
            if(CySpcCreateCmdLoadRow(FIRST_EE_ARRAYID) == CYRET_SUCCESS)
            {
                /* Write the command. */
                if(CySpcWriteCommand(rowData, CYDEV_EEPROM_ROW_SIZE) == CYRET_STARTED)
                {
                    /* Spin until completion. */
                    while(!(*SPC_STATUS & SPC_SPC_IDLE))
                    {
                        /* CyDelay(1); */
                    }

                    /* See if we were successful. */
                    if(CySpcReadStatus == CYRET_SUCCESS)
                    {
                        status = CYRET_SUCCESS;
                    }
                }
            }

            /* Create the command to erase and program the row. */
            if(status == CYRET_SUCCESS && 
                CySpcCreateCmdWriteRow(FIRST_EE_ARRAYID, rowNumber, dieTemperature[0], 
                dieTemperature[1]) == CYRET_SUCCESS)
            {   
                status = CYRET_UNKNOWN;

                /* Write the command. */
                if(CySpcWriteCommand(0, 0) == CYRET_STARTED)
                {
                    /* Spin until completion. */
                    while(!(*SPC_STATUS & SPC_SPC_IDLE))
                    {
                         CyDelayUs(1); 
                    }

                    /* See if we were successful. */
                    if(CySpcReadStatus == CYRET_SUCCESS)
                    {
                        status = CYRET_SUCCESS;
                    }
                }
            }
            else
            {
                status = CYRET_UNKNOWN; 
            }
            /* Unlock the SPC so someone else can use it. */
            CySpcUnlock();
        }
        else
        {
            status = CYRET_LOCKED;
        }
    }
    else
    {
        status = CYRET_BAD_PARAM;
    }

    return status;
}


/*******************************************************************************
* Function Name: EEPROM_StartWrite
********************************************************************************
* 
* Summary:
*  Starts the SPC write function. This function does not block, it returns
*  once the command has begun the SPC write function. Once this function has
*  been called the SPC will be locked until EEPROM_QueryWrite()
*  returns CYRET_SUCCESS. If the caller wants to abandon the write he can call
*  CySpcUnlock() to unlock the SPC.
*  
*
* Parameters:
*  rowData. address of buffer containing a row of data to write to the EEPROM.
*
*  rowNumber. EEPROM row number to program.
*
* Return:
*  CYRET_STARTED if the spc command to write was successfuly started.
*  CYRET_BAD_PARAM if the parameters were invalid.
*  CYRET_LOCKED if the spc is being used.
*  CYRET_UNKNOWN if there was an SPC error.
*
* Reentrant
*  Yes
*
*******************************************************************************/
cystatus EEPROM_StartWrite(uint8 * rowData, uint8 rowNumber) 
{
    cystatus status;

    if(rowNumber < (uint8)(EEPROM_EEPROM_SIZE / CYDEV_EEPROM_ROW_SIZE))
    {
        /* Get the die temp. */
        status = CySetTemp();

        /* See if we can get the SPC. */
        if(status == CYRET_SUCCESS && CySpcLock() == CYRET_SUCCESS)
        {
            status = CYRET_UNKNOWN;

            /* Create the command to load the row latch. */
            if(CySpcCreateCmdLoadRow(FIRST_EE_ARRAYID) == CYRET_SUCCESS)
            {
                /* Write the command. */
                if(CySpcWriteCommand(rowData, CYDEV_EEPROM_ROW_SIZE) == CYRET_STARTED)
                {
                    /* Spin until completion. */
                    while(!(*SPC_STATUS & SPC_SPC_IDLE))
                    {
                        CyDelay(1);
                    }

                    /* See if we were successful. */
                    if(CySpcReadStatus == CYRET_SUCCESS)
                    {
                        status = CYRET_SUCCESS;
                    }
                }
            }

            /* Create the command to erase and program the row. */
            if(status == CYRET_SUCCESS && 
                CySpcCreateCmdWriteRow(FIRST_EE_ARRAYID, rowNumber, dieTemperature[0],
                dieTemperature[1]) == CYRET_SUCCESS)
            {
                status = CYRET_UNKNOWN;

                /* Write the command. */
                if(CySpcWriteCommand(0, 0) == CYRET_STARTED)
                {
                    status = CYRET_STARTED;
                }
            }
            else
            {
                status = CYRET_UNKNOWN; 
            }
        }
        else
        {
            status = CYRET_LOCKED;
        }
    }
    else
    {
        status = CYRET_BAD_PARAM;
    }

    return status;
}


/*******************************************************************************
* Function Name: EEPROM_QueryWrite
********************************************************************************
* 
* Summary:
*  Checks the state of a write to EEPROM. This function must be called until
*  the return value is not CYRET_STARTED. 
*
* Parameters:
*  void
*
* Return:
*  CYRET_STARTED if the spc command is still processing.
*  CYRET_SUCCESS if the operation was successful.
*  CYRET_UNKNOWN if there was an SPC error.
*
* Reentrant
*  Yes
*
*******************************************************************************/
cystatus EEPROM_QueryWrite(void) 
{
    cystatus status;

    /* Spin until completion. */
    if(*SPC_STATUS & SPC_SPC_IDLE)
    {
        /* See if we were successful. */
        if(CySpcReadStatus == CYRET_SUCCESS)
        {
            status = CYRET_SUCCESS;
        }
        else
        {
            status = CYRET_UNKNOWN;
        }
        
        /* Unlock the SPC so someone else can use it. */
        CySpcUnlock();
    }
    else
    {
        status = CYRET_STARTED;
    }

    return status;
}

