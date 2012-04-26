/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Ftell.c $
 $Revision: 7 $                                       
 $Date: 9/13/03 12:22p $
 Description: Ftell.c
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

/*----------------------------------------------------------------------------
>  Function Name: int32_t Ftell(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1) Handle Number

   Outputs:       Returns current offset or an Error

   Description:   Finds the current file position
<
----------------------------------------------------------------------------*/
int32_t Ftell(int32_t HandleNumber)
{
    RtStatus_t RetValue;    // Don't init to save memory.
	
	EnterNonReentrantSection();
    
    // Check whether the passed handle number is within range
    if((HandleNumber < 0)||(HandleNumber >=maxhandles))
	{
	    LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}

	if((RetValue = Handleactive(HandleNumber)) <0)
    {
	    LeaveNonReentrantSection();
		return RetValue;
	}
    LeaveNonReentrantSection();
    return Handle[HandleNumber].CurrentOffset;
}
