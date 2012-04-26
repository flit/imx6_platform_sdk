/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/Findnextcluster.c $                                        
 $Revision: 6 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: Findnextcluster.c
 Notes:	 This file read provides FAT API to find the next cluster
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
>  Function Name:  int32_t Findnextcluster(int32_t DeviceNum,int32_t clusterno)
  
   FunctionType:   Reentrant

   Inputs:         1) Device number
                   2) Cluster number

   Outputs:        Returns Next cluster no.

   Description:    Determines Next cluster no. by first finding the FAT sector and offset
                   in that sector for the entry of the given cluster no. 
<
----------------------------------------------------------------------------*/
int32_t Findnextcluster(int32_t DeviceNum,int32_t clusterno)
{
    int FATNtryoffset;
    int32_t FATsector,FATentry;
       
    ddi_ldl_push_media_task("Findnextcluster");
    FATsector = FATsectorno(DeviceNum,clusterno,&FATNtryoffset);
	if(FATsector <= 0)
    {
        ddi_ldl_pop_media_task();
	    return ERROR_OS_FILESYSTEM_NOT_VALID_SECTOR;
    }
	FATentry = ReadFATentry(DeviceNum,FATsector,FATNtryoffset,clusterno);
    ddi_ldl_pop_media_task();
    return (FATentry);
}




	
 
