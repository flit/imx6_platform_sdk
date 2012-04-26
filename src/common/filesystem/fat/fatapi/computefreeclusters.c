/*----------------------------------------------------------------------------
 Copyright (C) 2003-2008 SigmaTel, Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/Computefreeclusters.c $                                        
 $Revision: 8 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: Computes total free cluster count. 
 Notes:	This file read provides FAT API to find total free clusters.
----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
//#include <stdio.h>
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
#include "components/telemetry/tss_logtext.h"

// Define as 0 by default or 1 to see Compute Free Clx result and error codes on tss
#define VERBOSE_CFC_LOGGING 0

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Computefreecluster(int32_t DeviceNumber)

   FunctionType:   Reentrant

   Inputs:         1) Device number

   Outputs:        SUCCESS or negative error code. Writes static media table struct. 

   Description:    Determines & sets MediaTable[DeviceNumber].TotalFreeClusters 
                   by first checking FAT type (16|32)
<
----------------------------------------------------------------------------*/
int32_t Computefreecluster(int32_t DeviceNumber)
{
    int32_t totalfreeclusters;


    if(MediaTable[DeviceNumber].DevicePresent)
    {
        if((totalfreeclusters= Totalfreecluster(DeviceNumber))<0)
        {
            #if VERBOSE_CFC_LOGGING
            tss_logtext_Print(LOGTEXT_EVENT_OS_FILESYSTEM_GROUP|LOGTEXT_VERBOSITY_3, 
                "Totfreecx(%d) er:x%x\r\n", DeviceNumber, totalfreeclusters);   
            #endif                               

            // return negative err code.
            return (int32_t)totalfreeclusters;
        }

        MediaTable[DeviceNumber].TotalFreeClusters = totalfreeclusters;         

        #if VERBOSE_CFC_LOGGING
        tss_logtext_Print(LOGTEXT_EVENT_OS_FILESYSTEM_GROUP|LOGTEXT_VERBOSITY_3, 
             "Compfreecx(%d): %d\r\n", DeviceNumber, totalfreeclusters);
        #endif
    }
    else
    {
        #if VERBOSE_CFC_LOGGING    
        tss_logtext_Print(LOGTEXT_EVENT_OS_FILESYSTEM_GROUP|LOGTEXT_VERBOSITY_3, 
                "Compfreecx: no device\r\n");// should this case return error? 
        #endif
    }

    return SUCCESS;
   
}



