/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/GetFileSize.c $
 $Revision: 12 $                                       
 $Date: 9/18/03 7:10p $
 Description: GetFileSize.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
//#include "dirrecord.h"

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t GetFileSize(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns 0 or ERROR Code if  Error Occurs

   Description:   Gets the size of the File

<
----------------------------------------------------------------------------*/
RtStatus_t GetFileSize(int32_t HandleNumber)
{   
    RtStatus_t RetValue;

    EnterNonReentrantSection();
 
    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
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
    return Handle[HandleNumber].FileSize;
}
