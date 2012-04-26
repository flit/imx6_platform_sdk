/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/FindnextFreecurrentcluster.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: FindnextFreecurrentcluster.c
 Notes:	 This file read provides FAT API to find the next cluster and to free the current cluster
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
>  Function Name:  int32_t FindnextFreecurrentcluster(int32_t DeviceNum,int32_t clusterno)
  
   FunctionType:   Reentrant

   Inputs:         1) Device number
                   2) cluster number

   Outputs:        Returns Next cluster no. 

   Description:    Determines Next cluster no. by first finding the FAT sector and offset
                   in that sector for the entry of the given cluster no. and frees the current cluster
<
-----------------------------------------------------------------------------*/
// sdk3.05 deleted func body.  eventually TODO Search and remove all references in dsc and mk and loc files.  TOVERIFY2
#if 0
int32_t FindnextFreecurrentcluster(int32_t DeviceNum,int32_t clusterno)
{
    int FATNtryoffset;
    int32_t FATsector,FATentry;
      
    EnterNonReentrantSection();
   
    if(DeviceNum > maxdevices ||DeviceNum < 0)
	{
        LeaveNonReentrantSection();
	    return ERROR_OS_FILESYSTEM_MAX_DEVICES_EXCEEDED;
	}
    
    ddi_ldl_push_media_task("FindnextFreecurrentcluster");
  
    /* First find sector no and offset in that sector for the entry of the 
    given cluster no. */
    if((FATsector = FATsectorno(DeviceNum,clusterno,&FATNtryoffset))<=0)
	{
        ddi_ldl_pop_media_task();
        LeaveNonReentrantSection();
	    return ERROR_OS_FILESYSTEM_NOT_VALID_SECTOR;
	}
		  
	/* Read the entry of the given cluster no. */
	FATentry = ReadFATentry(DeviceNum,FATsector,FATNtryoffset,clusterno);
   	/* write the entry in the sector no. at the offset in the sector */
   	WriteFATentry(DeviceNum,FATsector,FATNtryoffset,clusterno,FAT32FREECX);

    LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
    return (FATentry);
}
#endif




	
 
