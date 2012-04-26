/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/handle/Handleres.c $ 
 $Revision: 18 $                                       
 $Date: 9/27/03 5:32p $
 Description: Handleres.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"

/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Handleactive(int32_t HandleNumber)

   FunctionType:   Reentrant

   Inputs:         1) Handle number

   Outputs:        Returns 0 if Handle is active else an ERROR CODE

   Description:    Checks the handle active field of the given handle number.
<
----------------------------------------------------------------------------*/
RtStatus_t Handleactive(int32_t HandleNumber)
{ 
    // Check whether the passed handle number is within range
    if((HandleNumber <0) || (HandleNumber >=maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if(HandleNumber == 0)
        return  ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if(Handle == NULL )
        return  ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;
    
    if(Handle[HandleNumber].HandleActive == 1)
        return SUCCESS;

    else
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;
}
