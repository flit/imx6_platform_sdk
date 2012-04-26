/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/FATsector.c $                                        
 $Revision: 5 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: FATsector.c
 Notes:	This file read provides FAT sector no and FATentry offset for the given cluster no.
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
#include "BootSecOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name: int32_t FATsectorno(int32_t DeviceNum,int32_t clusterno,int32_t *FATNtryOffsetInBytes)

   FunctionType:  Reentrant

   Inputs:        1) Device number
				  2) clusterno
				  3) pointer to a variable to receive the FAT entry offset

   Outputs:       Returns a sector-offset (in sectors) from the start of the device.
                  Also, *FATNtryOffsetInBytes is modified to be the offset of the associated FAT entry,
                  in bytes, within that sector.

   Description:   Background: Entries in the FAT refer to clusters on the device.

                  Given a cluster on the device designated by "clusterno", this 
                  function computes the sector on the device that contains
                  the FAT entry that refers to that cluster.
                  An offset to that sector from the start of the device
                  is returned, and "*FATNtryOffsetInBytes" is modified
                  to be the offset in bytes of that FAT entry in that
                  sector.
<
----------------------------------------------------------------------------*/
int32_t FATsectorno(int32_t DeviceNum,int32_t clusterno,int32_t *FATNtryOffsetInBytes)
{
	int32_t FAToffsetInBytes=0;
	 
	if (MediaTable[DeviceNum].FATType == FAT12)
    	FAToffsetInBytes = clusterno + (clusterno >> 1);

	else if (MediaTable[DeviceNum].FATType == FAT16)
		FAToffsetInBytes = clusterno << 1;

	else if (MediaTable[DeviceNum].FATType == FAT32)
		FAToffsetInBytes = clusterno << 2;

	else
	    return ERROR_OS_FILESYSTEM_MEDIA_TYPE_NOT_SUPPORTED;

	*FATNtryOffsetInBytes = FAToffsetInBytes & MediaTable[DeviceNum].SectorMask;

	return (MediaTable[DeviceNum].RsvdSectors) + (FAToffsetInBytes >> MediaTable[DeviceNum].SectorShift);

}


