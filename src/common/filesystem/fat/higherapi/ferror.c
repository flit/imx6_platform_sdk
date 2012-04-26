////////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_file
//! @{
//!
//  Copyright (c) 2006 SigmaTel, Inc.
//!
//! \file    ferror.c
//! \brief   Returns error code for handle that is input.
//!
//!
////////////////////////////////////////////////////////////////////////////////

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
>  Function Name:  RtStatus_t Ferror(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1) Handle Number

   Outputs:       Returns Error code for handle

   Description:   Finds the error code in the handle table
<
----------------------------------------------------------------------------*/
int32_t Ferror(int32_t HandleNumber)
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
    return Handle[HandleNumber].ErrorCode;
}
