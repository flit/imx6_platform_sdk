/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/FirstfreeAndallocate.c $                                        
 $Revision: 20 $                                       
 $Date: 9/18/03 7:43p $                                           
 Description: FirstfreeAndallocate.c
 Notes:	This file read provides FAT API to find free cluster and allocate cluster
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/filesystem/fsapi.h>
#include "platform.h"
#include "BootSecOffset.h" 
#include <os/filesystem/filesystem.h>
#include <drivers\ddi_media.h>

/*----------------------------------------------------------------------------
>  Function Name:  REENTRANT int32_t FirstfreeAndallocate(int32_t DeviceNum)

   FunctionType:   Reentrant

   Inputs:         1) Device number

   Outputs:        Returns Cluster no. of free cluster 

   Description:    Determines free cluster by checking FAT entry in FAT table
<
----------------------------------------------------------------------------*/
REENTRANT int32_t FirstfreeAndallocate(int32_t DeviceNum)
{
    int32_t FATentry,FATntryoffset,FAToffset;
    int32_t clusterNum,FATsectorNo ; 
    uint8_t *buf;
    uint32_t cacheToken = 0;
 
	if(DeviceNum >= maxdevices || DeviceNum < 0)
    {
	    return ERROR_OS_FILESYSTEM_MAX_DEVICES_EXCEEDED;
    }
    
    ddi_ldl_push_media_task("FirstfreeAndallocate");
  
    if((FATsectorNo = FATsectorno(DeviceNum,(MediaTable[ DeviceNum].NextFreeCluster+1),&FATntryoffset)) <0)
    {
        ddi_ldl_pop_media_task();
        return 	FATsectorNo;
    }

    if((clusterNum =  MediaTable[DeviceNum].NextFreeCluster)<0)
    {
        ddi_ldl_pop_media_task();
        return ERROR_OS_FILESYSTEM_INVALID_CLUSTER_NO;
    }

   	if (MediaTable[DeviceNum].TotalFreeClusters == 0)
    {
        ddi_ldl_pop_media_task();
    	   return (ERROR_OS_FILESYSTEM_NO_FREE_CLUSTER);
    }

    EnterNonReentrantSection();
    if((buf = ((uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken)))==(uint8_t*)0)
	{
        ddi_ldl_pop_media_task();
	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}

    if (MediaTable[DeviceNum].FATType == FAT12)
    {	
        do 
        {
            clusterNum++;
            if (clusterNum > MediaTable[DeviceNum].TotalNoofclusters)
			{
			   	clusterNum = 2;
				FATsectorNo = MediaTable[ DeviceNum].RsvdSectors;
                
                // Release previous sector before reading the next.
                FSReleaseSector(cacheToken);
                
	            if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken))==(uint8_t*)0)
				{
                    ddi_ldl_pop_media_task();
				    LeaveNonReentrantSection();	        
					return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
				}
			}
	
			FAToffset = clusterNum + (clusterNum >> 1);
		  	FATntryoffset = FAToffset & MediaTable[ DeviceNum].SectorMask;
            buf = ReadFAT12Entry(DeviceNum, (int32_t *)&FATsectorNo,FATntryoffset,clusterNum,buf,&FATentry, &cacheToken);
    	   		    
		} while(FATentry != 0); 	

        if (FATntryoffset == (MediaTable[DeviceNum].BytesPerSector-1))
        {
            FATsectorNo--;
        }
  
        // Have to release the cache entry from reading before we can write into it.
        FSReleaseSector(cacheToken);
        
		WriteFATentry(DeviceNum,FATsectorNo,FATntryoffset,clusterNum,FAT12EOF);
    }
    else if (MediaTable[DeviceNum].FATType == FAT16)
    {
        FATntryoffset = FATntryoffset - 2;
	    do  
	    {
            clusterNum++;
			if (clusterNum > MediaTable[DeviceNum].TotalNoofclusters )
			{
			    clusterNum = 2;
				FATntryoffset = 4;
				FATsectorNo = MediaTable[DeviceNum].RsvdSectors;
                
                // Release previous sector before reading the next.
                FSReleaseSector(cacheToken);
                
	            if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken))==(uint8_t*)0)
				{
                    ddi_ldl_pop_media_task();
				    LeaveNonReentrantSection();
	   				return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
				}
			}
            else 
            {
                FATntryoffset = FATntryoffset + 2;
            }
            
            if (FATntryoffset == MediaTable[DeviceNum].BytesPerSector)
            {
                FATntryoffset = 0;
			    FATsectorNo++;
                
                // Release previous sector.
                FSReleaseSector(cacheToken);
                
	            if ((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken)) ==(uint8_t*)0)
				{
                    ddi_ldl_pop_media_task();
				    LeaveNonReentrantSection();
    				    return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
				}
            }    
            FATentry = FSGetWord((uint8_t*)buf,FATntryoffset);
		    
        } while(FATentry != 0);
        
        // Have to release the cache entry from reading before we can write into it.
        FSReleaseSector(cacheToken);
        
        WriteFATentry(DeviceNum,FATsectorNo,FATntryoffset,clusterNum,FAT32EOF);
    }
    else if(MediaTable[DeviceNum].FATType == FAT32)
    {
	    buf = FirstfreeAndallocateFAT32(DeviceNum, FATsectorNo, FATntryoffset, buf, &clusterNum, cacheToken);
    }

    MediaTable[ DeviceNum].NextFreeCluster = clusterNum;
    MediaTable[ DeviceNum].TotalFreeClusters--;

    LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
    return (MediaTable[ DeviceNum].NextFreeCluster);

}
/*----------------------------------------------------------------------------
>  Function Name:  REENTRANT uint8_t *FirstfreeAndallocateFAT32(int32_t DeviceNum ,int32_t FATsectorNo,int32_t FAToffset,uint8_t *buf, int32_t *FATval)

   FunctionType:   Reentrant

   Inputs:         1)Device number
                   2)FATsectorNo
                   3)FAToffset
                   4)pointer to buffer
                   5)pointer to FATvalue

   Outputs:        Returns cluster no. of free cluster 

   Description:    Determines free cluster depending upon the entry in FAT Table
<
----------------------------------------------------------------------------*/
uint8_t *FirstfreeAndallocateFAT32(int32_t DeviceNum ,int32_t FATsectorNo,int32_t FAToffset,uint8_t *buf, int32_t *FATval, uint32_t cacheToken)
{
    int32_t clusterNum, FATentry;
    
    clusterNum = MediaTable[ DeviceNum].NextFreeCluster;
    FAToffset = FAToffset - 4;
	do
	{
        clusterNum++;
 		if (clusterNum > MediaTable[DeviceNum].TotalNoofclusters)
	    {
	        clusterNum = 2;
		    FAToffset = 8;  
		    FATsectorNo = MediaTable[ DeviceNum].RsvdSectors;
            
            FSReleaseSector(cacheToken);
            
            if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken))==(uint8_t*)0)
		    {
			    return (uint8_t*)0;
		    }
		}
		else
        {
            FAToffset = FAToffset + 4;
        }
            
        if(FAToffset == MediaTable[DeviceNum].BytesPerSector)
        {
            FAToffset = 0;
            FATsectorNo++;
            
            FSReleaseSector(cacheToken);
            
            if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,0, &cacheToken))==(uint8_t*)0)
			{
				return (uint8_t*)0;
			}
        }
        FATentry = FSGetDWord((uint8_t*)buf,FAToffset);
    } while(FATentry != 0);
    
    // Have to release the cache entry from reading before we can write into it.
    FSReleaseSector(cacheToken);
    
    WriteFATentry(DeviceNum,FATsectorNo,FAToffset,clusterNum,FAT32EOF);
    
    *FATval = clusterNum; 
    return buf;
}

//------------------------------------------------------------------------------
/**
// @}
**/
//---eof------------------------------------------------------------------------





