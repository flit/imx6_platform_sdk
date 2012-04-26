/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fclose.c $
 $Revision: 9 $
 $Date: 9/13/03 12:23p $
 Description: Fclose.c
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
#include "fat_internal.h"
#include "fs_steering.h"

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t Fclose(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns 0 on success else an Error Code if error occurs

   Description:   Closes the opened file 
<
----------------------------------------------------------------------------*/
RtStatus_t Fclose_FAT(int32_t HandleNumber)
{
    RtStatus_t RetValue;

	if((HandleNumber < 0)||(HandleNumber >=maxhandles))
    {
	    return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}
    
    if((RetValue = Handleactive(HandleNumber)) <0)
    {
        return RetValue;
	}
    
    if(Handle[HandleNumber].Mode & (WRITE_MODE|APPEND_MODE))
    {
        // If file is opened in write mode flush the sector
        if((RetValue = Fflush(HandleNumber)) < 0)
        {
            return RetValue;
        }
    }        

    RetValue = Freehandle(HandleNumber);
    
    return RetValue;
}
