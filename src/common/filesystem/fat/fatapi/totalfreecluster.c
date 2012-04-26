/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/Totalfreecluster.c $
 $Revision: 8 $
 $Date: 9/13/03 12:21p $
 Description: Totalfreecluster.c
 Notes: This file read provides FAT API to find total free clusters
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
        File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include <string.h>                 // memcpy() or memset()
#include <os\os_dmi_api.h>
#include <drivers\sectordef.h>
#include "platform.h"
#include "BootSecOffset.h"

// Defines

// Use the stub blank version by default. Debug tool only for active error analysis.
//#define MODULE_ASSERT(a)  assert(a)
#define MODULE_ASSERT(a)

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Totalfreecluster(int32_t DeviceNum)

   FunctionType:   Reentrant

   Inputs:         1) Device number

   Outputs:        Returns total no. of free clusters

   Description:    Determines total free clusters by first checking FAT type
<
----------------------------------------------------------------------------*/
int32_t Totalfreecluster(int32_t DeviceNum)
{
    const int32_t   iSectorSize = MediaTable[DeviceNum].BytesPerSector;
    int32_t         totalfreeclusters,FATsectorNo,FATentry;
    uint8_t         *pu8LocalBuf;
    uint8_t         *buf;
    int32_t         FAToffset,clusterNum;
    RtStatus_t      rVal;
    uint32_t cacheToken;

    totalfreeclusters = 0;
    FATsectorNo = MediaTable[DeviceNum].RsvdSectors;

    if(MediaTable[DeviceNum].FATType == FAT32)
    {
        // get a buffer
        rVal = os_dmi_MemAlloc( (void**)&pu8LocalBuf, iSectorSize, true, DMI_MEM_SOURCE_FASTMEM );
        if ( rVal != SUCCESS )
        {
            SystemHalt( );
        }

        EnterNonReentrantSection();
        if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
        {
            MODULE_ASSERT(false); 
            os_dmi_MemFree( pu8LocalBuf );
            LeaveNonReentrantSection();
            return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
        }
        // copy from cached buffer to local buffer so we can free the mutex protecting the file system(cache)
        memcpy( pu8LocalBuf, buf, iSectorSize );
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();

        FAToffset = 8;
        for (clusterNum = 2 ; clusterNum <= MediaTable[DeviceNum].TotalNoofclusters  ; clusterNum++)
        {
            FATentry  = FSGetDWord((uint8_t*)pu8LocalBuf,FAToffset);
            if (FATentry == 0)
            {
                totalfreeclusters++;
                if(totalfreeclusters == 1)
                    MediaTable[DeviceNum].NextFreeCluster = clusterNum;
            }

            FAToffset = FAToffset + 4;

            /* check for boundary condition */
            if(FAToffset == MediaTable[DeviceNum].BytesPerSector)
            {
                FAToffset = 0;
                FATsectorNo++;

                EnterNonReentrantSection();
                if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t *)0)
                {
                    MODULE_ASSERT(false);
                    os_dmi_MemFree( pu8LocalBuf );
                    LeaveNonReentrantSection();
                    return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
                }
                // copy from cached buffer to local buffer so we can free the mutex protecting the file system(cache)
                memcpy( pu8LocalBuf, buf, iSectorSize );
                FSReleaseSector(cacheToken);
                LeaveNonReentrantSection();
            }
        }
        os_dmi_MemFree( pu8LocalBuf );
    }
    else
    {
        totalfreeclusters = TotalfreeclusterFAT16(DeviceNum);
        MODULE_ASSERT(totalfreeclusters >= 0); // catch error code in DEBUG builds. 
    }
    MODULE_ASSERT(totalfreeclusters >= 0); // catch error code in DEBUG builds. 
    return (totalfreeclusters);

}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t TotalfreeclusterFAT16(int32_t DeviceNum)

   FunctionType:   Reentrant

   Inputs:         1) Device number

   Outputs:        Returns total no. of free clusters

   Description:    Determines total free clusters by first checking FAT type
<
----------------------------------------------------------------------------*/
int32_t  TotalfreeclusterFAT16(int32_t DeviceNum)
{
    const int32_t   iSectorSize = MediaTable[DeviceNum].BytesPerSector;
    int32_t         totalfreeclusters;
    int32_t         FATsectorNo,FAToffset,clusterNum,FATentry,FATntryoffset;
    uint8_t         *pu8LocalBuf;
    uint8_t         *buf;
    RtStatus_t      rVal;
    uint32_t cacheToken;

    totalfreeclusters = 0;
    FATsectorNo = MediaTable[DeviceNum].RsvdSectors;
    EnterNonReentrantSection();
    if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t *)0)
    {
        MODULE_ASSERT(false);
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
    }

    if (MediaTable[DeviceNum].FATType == FAT12)
    {
        // for fat12 we can't let go of the mutex protecting the underlaying cache buffer
        // so for this case, we'll keep it the entire time.  fortunately, fat12 is only for system files.
        for (clusterNum = 2 ; clusterNum <= MediaTable[DeviceNum].TotalNoofclusters  ; clusterNum++)
        {
            FAToffset =  clusterNum + (clusterNum>>1);
            FATntryoffset = FAToffset & MediaTable[DeviceNum].SectorMask;
            if((buf = ReadFAT12Entry(DeviceNum,&FATsectorNo,FATntryoffset,clusterNum,buf,&FATentry, &cacheToken))==(uint8_t *)0)
            {
                MODULE_ASSERT(false);
                LeaveNonReentrantSection();
                return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
            }

            if (FATentry == 0)
            {
                totalfreeclusters++;
                if(totalfreeclusters == 1)
                {
                    MediaTable[DeviceNum].NextFreeCluster = clusterNum;
                }
            }

        }
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();
    }
    else if(MediaTable[DeviceNum].FATType == FAT16)
    {
        // get a buffer
        rVal = os_dmi_MemAlloc( (void**)&pu8LocalBuf, iSectorSize, true, DMI_MEM_SOURCE_FASTMEM );
        if ( rVal != SUCCESS )
        {
            SystemHalt( ); // note: powers off in release builds.
        }
        // copy from cached buffer to local buffer so we can free the mutex protecting the file system(cache)
        memcpy( pu8LocalBuf, buf, iSectorSize );
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();

        FATntryoffset = 4;
        for (clusterNum = 2 ; clusterNum <= MediaTable[DeviceNum].TotalNoofclusters  ; clusterNum++)
        {
            FATentry = FSGetWord((uint8_t*)pu8LocalBuf,FATntryoffset);
            if (FATentry == 0)
            {
                totalfreeclusters++;
                if(totalfreeclusters == 1)
                    MediaTable[DeviceNum].NextFreeCluster = clusterNum;
            }

            FATntryoffset = FATntryoffset + 2;
            /* check for boundary condition */
            if(FATntryoffset  == MediaTable[DeviceNum].BytesPerSector)
            {
                FATntryoffset = 0;
                FATsectorNo++;

                EnterNonReentrantSection();
                if((buf = (uint8_t*)FSReadSector(DeviceNum, FATsectorNo,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t *)0)
                {
                    MODULE_ASSERT(false);
                    os_dmi_MemFree( pu8LocalBuf );
                    LeaveNonReentrantSection();
                    return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
                }
                // copy from cached buffer to local buffer so we can free the mutex protecting the file system(cache)
                memcpy( pu8LocalBuf, buf, iSectorSize );
                FSReleaseSector(cacheToken);
                LeaveNonReentrantSection();
            }
        }
        os_dmi_MemFree( pu8LocalBuf );
    }

    else
    {   
        // FAT32 case
        MODULE_ASSERT(false);
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_MEDIA_TYPE_NOT_SUPPORTED;
    }


    return(totalfreeclusters);
}

