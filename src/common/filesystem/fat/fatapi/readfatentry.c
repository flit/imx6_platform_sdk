/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/ReadFATentry.c $                                        
 $Revision: 10 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: ReadFATentry.c
 Notes:	 This file read provides FAT API to read the FAT entry of given cluster
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
>  Function Name:  int32_t ReadFATentry(int32_t Devicenum,int32_t FATsector,int32_t FATNtryoffset,int32_t clusterno)
 
   FunctionType:   Reentrant

   Inputs:         1) Device number
				   2) FATsector
				   3) FATNtryoffset
				   4) cluster no.

   Outputs:        Returns FATentry of the given cluster no.

   Description:    Determines FATentry for the given cluster no. from the FAT sector 
                   and FATentryoffset depending upon FAT type.
<
----------------------------------------------------------------------------*/
int32_t ReadFATentry(int32_t Devicenum,int32_t FATsector,int32_t FATNtryoffset,int32_t clusterno)
{
    int32_t FATntry=0;
    uint8_t *buf;
    uint32_t cacheToken = 0;

	EnterNonReentrantSection();
    /* Read the FAT Sector */ 
    
    ddi_ldl_push_media_task("ReadFATentry");

	if((buf = (uint8_t*)FSReadSector(Devicenum, FATsector,WRITE_TYPE_RANDOM, &cacheToken)) == (uint8_t*)0)
	{
        ddi_ldl_pop_media_task();
	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}
    /* if FAT type is FAT12 then take 12 bits for FAT entry */    
    if (MediaTable[Devicenum].FATType ==FAT12)
    {
        buf = ReadFAT12Entry(Devicenum,(int32_t *) &FATsector,FATNtryoffset,clusterno,buf,(int32_t *) &FATntry, &cacheToken);
        if (FATntry == 0x0FFF)
        {
	        FATntry = ERROR_OS_FILESYSTEM_EOF;
        }
    }
	/* if FAT type is FAT16 then take 16 bits (uint32_t) for FAT entry */    
    else if (MediaTable[Devicenum].FATType ==FAT16)
	{
        FATntry = FSGetWord((uint8_t *)buf,FATNtryoffset);
		if (FATntry == 0xFFFF)
        {
            FATntry = ERROR_OS_FILESYSTEM_EOF;
        }
	}
	/* if FAT type is FAT32 then take 32 bits (DWORD) for FAT entry */    
	else  if (MediaTable[Devicenum].FATType == FAT32)
	{
	    FATntry = FS_GET_LITTLEENDIAN_INT32(buf,FATNtryoffset);
        if (FATntry == 0x0FFFFFFF)
        {
	        FATntry = ERROR_OS_FILESYSTEM_EOF;
        }
	}  
    else 
	{
	    FATntry = ERROR_OS_FILESYSTEM_MEDIA_TYPE_NOT_SUPPORTED;
	}
    FSReleaseSector(cacheToken);
	LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
    return (FATntry);
}
 
