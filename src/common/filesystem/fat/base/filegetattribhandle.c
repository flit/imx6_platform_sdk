/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/filegetattribhandle.c $
 $Revision: 7 $                                       
 $Date: 9/13/03 12:20p $
 Description: filegetattribhandle.c
 Notes:	This file read provides base api functon to get the attribute of the file.
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
#include "diroffset.h"


/*----------------------------------------------------------------------------

>  Function Name:  RtStatus_t filegetattribhandle(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)valid file handle 

   Outputs:       Returns directory attributes for a file, or ERROR Code if  Error Occurs

   Description:   Gets directory attributes (a byte) for a file. See possible attributes in fsapi.h

<
----------------------------------------------------------------------------*/
RtStatus_t filegetattribhandle(int32_t HandleNumber)
{
    RtStatus_t dirattribute;
    uint8_t *buf;
    uint32_t cacheToken;
        
    EnterNonReentrantSection();
    if((buf = (uint8_t *)FSReadSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
    {
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
    }
    dirattribute = (RtStatus_t) FSGetByte((uint8_t*)buf,(DIR_ATTRIBUTEOFFSET + Handle[HandleNumber].DirOffset));
    FSReleaseSector(cacheToken);
    LeaveNonReentrantSection();
    
    return  dirattribute;
}
