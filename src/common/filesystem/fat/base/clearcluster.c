/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/ClearCluster.c $
 $Revision: 3 $                                       
 $Date: 9/13/03 12:20p $
 Description: ClearCluster.c
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
#include <drivers/media/ddi_media.h>

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t ClearCluster(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        HandleNumber

   Outputs:       Nil

   Description:   Cleares the whole Cluster
<
----------------------------------------------------------------------------*/
RtStatus_t ClearCluster(int32_t HandleNumber)
{
    int32_t Device = Handle[HandleNumber].Device,i,RetValue;
    int32_t SectorNumber = Handle[HandleNumber].CurrentSector;
    
    for(i=0; i< MediaTable[Device].SectorsPerCluster; i++)
    {
        if((RetValue = FSEraseSector(Device,SectorNumber)) <0)
			return RetValue;
        SectorNumber++;
    }
    return SUCCESS;
}




