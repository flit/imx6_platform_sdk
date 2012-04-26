/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/Firstrootdirsector.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: Firstrootdirsector.c
 Notes:	This file read provides First Root directory sector
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  int32_t Firstrootdirsector(int32_t DeviceNum)

   FunctionType:   Reentrant

   Inputs:         1) Device number
				  
   Outputs:        Returns First Root directory sector 

   Description:    Determines First Root directory sector depending upon
                   the FAT type
----------------------------------------------------------------------------*/
// TODO TOVERIFY2   func body rm by sdk3.05.  search for and remove all refs in loc mk dsc


									
