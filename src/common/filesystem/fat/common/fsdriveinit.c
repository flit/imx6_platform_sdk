/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/common/Fsinit.c $              
 $Revision: 4 $                                       
 $Date: 9/18/03 10:37a $      
 Description: FsDriveShutdown.c
 Notes: Base version num not incremented since.
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
    File Includes
----------------------------------------------------------------------------*/
#include "types.h"
#include "fstypes.h"
#include "error.h"
#include "os/filesystem/fsapi.h"
#include "platform.h"
#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "filespec.h"
#include "os/filesystem.h"
#include "fat_internal.h"
#include "drivers/media/ddi_media.h"

/*----------------------------------------------------------------------------

>  Function Name:  int FSDriveInit(int DeviceNumber)

   FunctionType:  
                   
   Inputs:         Single input param is logical data drive number.
   


   Outputs:        Returns 0, if Success, else ERROR CODE
                   Writes g_FSinitErrorCode static.
                   
                   
   Description:    Initialization of FileSystem.
<
--------- -------------------------------------------------------------------*/
int  FSDriveInit(int DeviceNumber)
{
    int RetValue;
    
    /* Clear drive buffer */

    FSClearDriveBuf( DeviceNumber, maxhandles );
     
    Cleardevicerecord(DeviceNumber);

    //if MMC then Shift g_FSinitErrorCode 2 bits left    (comment doesn't match code)
    g_FSinitErrorCode=(g_FSinitErrorCode << 1);  


    // Read sector 0 to get PBS address
    // Read PBS itself
    // Verify PBS.
    if ((RetValue= FSDataDriveInit(DeviceNumber))!=0)   // Non zero return value indicates error
    {
        // Could not find or confirm the PBS
        
        if(RetValue == INVALID_FILESYSTEM) 
        {
            g_FSinitErrorCode= (g_FSinitErrorCode|0x01);
            RetValue = ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
        }
        return RetValue;
    }       
    
    // Formerly, this code called FileSystemPresent(DeviceNumber) read
    // and confirm the PBS signature.  However,
    // At this point the PBS has been verified by FSDataDriveInit(), so there is no need to check it
    // again with FileSystemPresent(DeviceNumber)

    if ((RetValue= Readdevicerecord(DeviceNumber,BOOTSECTOR))!=0)
    {
        if(RetValue == INVALID_FILESYSTEM)
        {
            g_FSinitErrorCode= (g_FSinitErrorCode|0x01);
            RetValue = ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
        }
        return RetValue;
    }       
    
    return SUCCESS;
}

