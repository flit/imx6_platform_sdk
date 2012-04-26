/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/ReadFAT12Entry.c $                                        
 $Revision: 9 $                                       
 $Date: 9/17/03 5:02p $                                           
 Description: ReadFAT12Entry.c
 Notes:	 This file read provides FAT API to read the FAT12 entry of given cluster
-----------------------------------------------------------------------------*/

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
>  Function Name: uint8_t *ReadFAT12Entry(int32_t DeviceNum,int32_t *FATsectorNo,int32_t FATntryoffset,int32_t clusterNum,uint8_t *buf,int32_t *FATentry)
 
   FunctionType:  Reentrant

   Inputs:        1) Device number
				  2) FATsectorNo
				  3) FATntryoffset
				  4) cluster no.
                  5) pointer to buffer
                  6) pointer to FATentry 

   Outputs:       Returns FATentry of the given cluster no. 

   Description:   Determines FATentry for the given cluster no. from the FAT sector 
                  and FATentryoffset depending upon FAT type.
<
----------------------------------------------------------------------------*/
uint8_t *ReadFAT12Entry(int32_t DeviceNum,int32_t *FATsectorNo,int32_t FATntryoffset,int32_t clusterNum,uint8_t *buf,int32_t *FATentry, uint32_t * cacheToken)
{
    /* check boundary condition */
    /* if FATntryoffset is at the boundary of a sector then get low byte from the last byte
    of this sector and high byte from the first byte of next sector */
	EnterNonReentrantSection();
    
    if (FATntryoffset == (MediaTable[DeviceNum].BytesPerSector-1))
    {
        *FATentry = FSGetByte((uint8_t *)buf,FATntryoffset);
        *FATsectorNo = *FATsectorNo + 1;
        FSReleaseSector(*cacheToken);
		if((buf = (uint8_t*)FSReadSector(DeviceNum,*FATsectorNo,WRITE_TYPE_RANDOM, cacheToken)) ==(uint8_t *)0)
		{
		    LeaveNonReentrantSection();
			return (uint8_t*)0;
		}
        *FATentry +=  (FSGetByte((uint8_t*)buf,0)<<8);
    }
    else
    {
        *FATentry = FSGetWord((uint8_t*)buf,FATntryoffset);
    }
    
	LeaveNonReentrantSection();

    if (clusterNum & 0x0001)
    {
        *FATentry =(*FATentry >> 4);
    }
    else
    {
        *FATentry = (*FATentry & 0x0fff);
    }

    /* check boundary condition */
    /* if FATntryoffset is at the boundary of a sector then get the entry
    from the next sector */           
	if((FATntryoffset == (MediaTable[DeviceNum].BytesPerSector-2)) && (clusterNum & 0x0001))
    {
        *FATsectorNo = *FATsectorNo + 1;
		EnterNonReentrantSection();
        FSReleaseSector(*cacheToken);
		if((buf = (uint8_t*)FSReadSector(DeviceNum,*FATsectorNo,WRITE_TYPE_RANDOM, cacheToken)) == (uint8_t*)0)
		{
		    LeaveNonReentrantSection();
			return (uint8_t*)0;
		}
		LeaveNonReentrantSection();
    }
    return buf;
}
