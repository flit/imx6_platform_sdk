/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/SearchfreeRecord.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: Searchfreerecord.c
 Notes:	This file read provides utility function to find free record in root directory
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
//#include <stdio.h>
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
#include "DirOffset.h" 

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Searchfreerecord(int32_t DeviceNum,int32_t sectorNum)

   FunctionType:   Reentrant

   Inputs:         1) Device number
                   2) Sector number

   Outputs:        Returns index no. of free record in root directory if there is a space for new 
                   directory record else an error NOSPACEINROOTDIRECTORY

   Description:    Determines space in root directory by determining the first character 
                   of directory record for 0x00 or 0xE5
<
----------------------------------------------------------------------------*/
int32_t Searchfreerecord(int32_t DeviceNum,int32_t sectorNum)
{
    int32_t Dirrecordoffset, Firstbyteofrecord, direntryindex;
    uint8_t *buf;
    uint32_t cacheToken;

	EnterNonReentrantSection();
	if((buf = (uint8_t*)FSReadSector(DeviceNum,sectorNum,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
	{
	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}
    Dirrecordoffset = 0;
 
    for (direntryindex = 0 ; direntryindex < DIR_RECORD_PERSECTOR; direntryindex++)
    {
        Firstbyteofrecord = FSGetByte((uint8_t *)buf,Dirrecordoffset);
        /* if first byte of the record is 0x00 or 0xE5 then this record
        is free or deleted */
        if (Firstbyteofrecord == 0 || Firstbyteofrecord == 0xE5)
        {
            FSReleaseSector(cacheToken);
	        LeaveNonReentrantSection();
            return (Dirrecordoffset);
		}
            
        Dirrecordoffset = Dirrecordoffset + 32;
    }
    FSReleaseSector(cacheToken);
    LeaveNonReentrantSection();
    return (ERROR_OS_FILESYSTEM_SECTOR_FULL_OF_RECORD);
}

