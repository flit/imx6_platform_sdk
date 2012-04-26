/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/CheckMode.c $
 $Revision: 1 $                                       
 $Date: 7/26/03 4:25p $
 Description: CheckMode.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"

/*----------------------------------------------------------------------------
>  Function Name: uint8_t CheckMode(uint32_t HandleNumber)

   FunctionType:  Non-Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns Mode field of the given HandleNumber

   Description:   Finds the Mode field of the given HandleNumber
<
----------------------------------------------------------------------------*/
uint8_t CheckMode(uint32_t HandleNumber)
{
    return Handle[HandleNumber].Mode;
}


