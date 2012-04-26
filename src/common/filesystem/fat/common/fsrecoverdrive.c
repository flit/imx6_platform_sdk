/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat/common/FsRecoverdrive.c $                                        
 $Revision: 11 $                                       
 $Date: 9/18/03 2:41p $                                           
 Description: FsRecoverDrive.c
 Notes: This file read provides initialization of Media table
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
    File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include "os/filesystem/fsapi.h" // includes "os/filesystem.h"
#include <string.h>
#include "platform.h"
#include "BootSecOffset.h" 

#include "drivers/media/ddi_media.h" 
#include "../include/diroffset.h"
#include "fstypes.h"


/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t FsFat32RecoverPBS(int32_t DeviceNum)
 
   FunctionType:  Reentrant

   Inputs:        1)Device number

   Outputs:       SUCCESS else an error

   Description:   Recovers PBS one by reading PBS two.
                  Also initializes the Media table for the given DriveNumber.
<
----------------------------------------------------------------------------*/
RtStatus_t FsFat32RecoverPBS(int32_t DriveNumber)
{
    RtStatus_t  RetVal;
    int32_t     *buf;
    uint32_t    cacheToken=0;

    
    RetVal = FileSystemPresent(DriveNumber);

    if( SUCCESS == RetVal )
    {
        // We ought not to be here.
        // There seems to be no problem with PBS One.
        // Do nothing.
        return SUCCESS;
    }    

    // If we got HERE, PBS One was missing or could not be read.

    //Read PBS two and fill-in media table
    RetVal = Readdevicerecord(DriveNumber,SECONDARY_BOOT_SECTOR);

    if( RetVal==SUCCESS )
    {
        // PBS One is missing, but PBS Two is intact.
        // We will restore PBS One from PBS Two.

        EnterNonReentrantSection(); 

        // Read PBS two
        if((buf = FSReadSector(DriveNumber, SECONDARY_BOOT_SECTOR,WRITE_TYPE_RANDOM, &cacheToken))==(int32_t *)0) 
        { 
            //Secondary record is not readable. Full format is the only option.
            // This would be really unexpected, since Readdevicerecord() also
            // read the same sector moments ago.
            RetVal = ERROR_OS_FILESYSTEM_READSECTOR_FAIL; 
        }
        else
        {
            // We have PBS two.
            // Write PBS two to PBS One.
            RetVal = FSWriteSector(DriveNumber,BOOTSECTOR,0,(uint8_t*)buf,0,MediaTable[DriveNumber].BytesPerSector,WRITE_TYPE_RANDOM);

            // NOTE: If RetVal is not SUCCESS, PBS Is not writable. Full Format?
        } 

        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection(); 

    }

    return RetVal;
        
}
