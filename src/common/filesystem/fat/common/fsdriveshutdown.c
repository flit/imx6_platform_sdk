/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/common/Fsinit.c $              
 $Revision: 4 $                                       
 $Date: 9/18/03 10:37a $      
 Description: FsDriveShutdown.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "filespec.h"
#include "os/filesystem.h"
#include "fat_internal.h"

/*----------------------------------------------------------------------------

>  Function Name:  int FSDriveShutdown(int DeviceNumber)

   FunctionType:  

   Inputs:         a) Pointer to X buffer for allocation of cache buffers
                   b) Pointer to Y buffer for allocation of handles, descriptors, etc
                   c) Max number of internal + external media supported.
                   d) Max handles supported.
                   e) Max cache buffers supported.

   Outputs:        Returns 0, if Success, else ERROR CODE

   Description:    Initialization of FileSystem.
<
--------- -------------------------------------------------------------------*/
int32_t  FSDriveShutdown(int32_t deviceNumber)
{
    int32_t i;
    

	/* Close all the active handles */

	for (i =0; i < maxhandles; i++)
	{
		if((Handleactive(i))==SUCCESS)
		{
            int32_t iDeviceNumberCheck;
            if( GetDeviceFromHandle(i, &iDeviceNumberCheck) == SUCCESS )
            {
                if( iDeviceNumberCheck == deviceNumber )
                {
					Fclose(i);
                }
            }
		}
	}

	/* Flush the drive cache */

	FSFlushDriveCache(deviceNumber);
		
	/* Clear the drive buff */
	
    FSClearDriveBuf( deviceNumber, maxhandles );

	/* Deallocate drive_specific system resource */
	/* TODOFSINITSHUTDOWN */

	/* Clear drive specific file system data structures */

	Cleardevicerecord(deviceNumber);	 

    return SUCCESS;
}

