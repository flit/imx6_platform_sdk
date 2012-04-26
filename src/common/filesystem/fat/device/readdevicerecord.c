/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/device/Readdevicerecord.c $                                        
 $Revision: 11 $                                       
 $Date: 9/18/03 2:41p $                                           
 Description: Readdevicerecord.c
 Notes: This file read provides initialization of Media table
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
    File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include "os/filesystem/fsapi.h" // includes "os/filesystem.h"
#include <string.h>
#include "platform.h"
#include "BootSecOffset.h" 

#include "drivers/media/ddi_media.h" 
// g_bFrameworkExternalDriveOrFsInit true means FsDriveInit done for frameworks 
// that handle FS. For another framework config with app handling FS, true 
// means the external drive is present and initialized. 

#include "../include/diroffset.h"

/*----------------------------------------------------------------------------
    Extern Declarations
----------------------------------------------------------------------------*/
extern int32_t Totalfreecluster(int32_t DeviceNum);


/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t Readdevicerecord(int32_t DeviceNum)
 
   FunctionType:  Reentrant

   Inputs:        1)Device number

   Outputs:       SUCCESS else an error

   Description:   Initializes Media Table by reading the Boot sector.
                  If the content of the boot sector cannot be read or
                  verified, then this function just errors out without
                  touching the Media Table.
<
----------------------------------------------------------------------------*/
RtStatus_t Readdevicerecord(int32_t DeviceNum,int32_t SectorNum)
{ 
    int64_t     DataSec;
    int         *buf;
    int         shift,temp;
    uint32_t    cacheToken;
    uint16_t    fsInfoSector;
    RtStatus_t  rtStatus;

    if((DeviceNum < 0) || (DeviceNum >=maxdevices))
    {
        return ERROR_OS_FILESYSTEM_DEVICE_NOT_SUPPORTED;
    }

    EnterNonReentrantSection();
 
    /* Read the BootSector */ 
    if((buf = FSReadSector(DeviceNum, SectorNum,WRITE_TYPE_RANDOM, &cacheToken))==(int32_t *)0)
    {
        LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
    }

    // Confirm that this is really the boot sector.
    rtStatus = FileSystemBootSectorVerify( (uint8_t *) buf );
    if ( SUCCESS != rtStatus )
    {
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();
        return (RtStatus_t)INVALID_FILESYSTEM;
    }
      
    MediaTable[ DeviceNum].DevicePresent=1;
    MediaTable[ DeviceNum].BytesPerSector     = FSGetWord((uint8_t *)buf,BYTESPERSECTOROFFSET);
    MediaTable[ DeviceNum].SectorsPerCluster  = FSGetByte((uint8_t  *)buf,SECPERCLUSTEROFFSET);
    MediaTable[ DeviceNum].RsvdSectors       =  FSGetWord((uint8_t  *)buf,RSVDSECOFFSET);
    MediaTable[ DeviceNum].NoOfFATs           = FSGetByte((uint8_t  *)buf,NOFATSOFFSET);

    // Make the fat type invalid before we can confirm
    MediaTable[DeviceNum].FATType           = FAT_TYPE_INVALID;

    if (MediaTable[ DeviceNum].NoOfFATs == 0)
    {
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();    
        return (RtStatus_t)INVALID_FILESYSTEM;
    }

    MediaTable[ DeviceNum].MaxRootDirEntries =  FSGetWord((uint8_t  *)buf,ROOTDIRENTRYOFFSET);
    MediaTable[ DeviceNum].TotalSectors      =  FSGetWord((uint8_t  *)buf,TOTSECTOROFFSET);
    /* if total sectors are zero then this is FAT32 and find total sectors 
    from total big sector offset */ 
    if (MediaTable[ DeviceNum].TotalSectors == 0)
        MediaTable[ DeviceNum].TotalSectors  =  FSGetDWord((uint8_t  *)buf,TOTBIGSECOFFSET);
    
    if (MediaTable[ DeviceNum].TotalSectors == 0)
    {
        FSReleaseSector(cacheToken);
        LeaveNonReentrantSection();
        return (RtStatus_t)INVALID_FILESYSTEM; 
    }    

    MediaTable[ DeviceNum].FATSize           =  FSGetWord((uint8_t  *)buf,FATSIZEOFFSET);
    /* if FAT size is zero then this is FAT32 and find FAT size 
    from FAT32 size offset */ 

    MediaTable[ DeviceNum].RootdirCluster = 0;

    if (MediaTable[ DeviceNum].FATSize == 0)
    {
        MediaTable[ DeviceNum].FATSize           =  FSGetDWord((uint8_t  *)buf,FAT32SIZEOFFSET);
        MediaTable[ DeviceNum].RootdirCluster    =  FSGetDWord((uint8_t  *)buf,FAT32ROOTCLUSOFFSET);
    }
    
    // Read FSInfo sector while we still own the buffer.
    fsInfoSector = FSGetWord((uint8_t *)buf, FAT32FSINFOOFFSET);

    FSReleaseSector(cacheToken);
    LeaveNonReentrantSection();

    if (MediaTable[ DeviceNum].FATSize == 0)
    {
        return (RtStatus_t)INVALID_FILESYSTEM;
    }    

    temp = MediaTable[ DeviceNum].BytesPerSector*MediaTable[ DeviceNum].SectorsPerCluster;
    MediaTable[ DeviceNum].ClusterMask = temp - 1;
    shift = 0;
    while (temp >>= 1)
    {
        shift++;
    }
    MediaTable[ DeviceNum].ClusterShift = shift;
 
    temp = MediaTable[ DeviceNum].BytesPerSector;    
    shift = 0;
    while (temp >>= 1)
    {
        shift++;
    }
    MediaTable[ DeviceNum].SectorShift = shift;

    MediaTable[ DeviceNum].SectorMask = MediaTable[ DeviceNum].BytesPerSector - 1;

    // Expected values:
    //  MaxRootDirEntries   = 512 (FAT16) or 0 (FAT32)
    //  SectorShift         = Used to divide by the quantity of bytes in a sector. {512 (FAT16), 2k, or 4k}
    //  RootDirSectors      = 0 or 1.
    //
    MediaTable[ DeviceNum].RootDirSectors = (MediaTable[ DeviceNum].MaxRootDirEntries * DIRRECORDSIZE) >> MediaTable[ DeviceNum].SectorShift;
 
    /* First data sector after reserved sectors, primary and secondary FAT table and 
    Root directory sectors */
    MediaTable[ DeviceNum].FIRSTDataSector = MediaTable[ DeviceNum].RsvdSectors + (MediaTable[ DeviceNum].NoOfFATs * MediaTable[DeviceNum].FATSize) + MediaTable[DeviceNum].RootDirSectors;
  
    /* To determine FATtype find total no of clusters on the volume */
    DataSec = MediaTable[ DeviceNum].TotalSectors - (MediaTable[ DeviceNum].RsvdSectors + 
                                                  (MediaTable[ DeviceNum].NoOfFATs*MediaTable[ DeviceNum].FATSize)
                                                  + MediaTable[ DeviceNum].RootDirSectors);

    temp = MediaTable[ DeviceNum].SectorsPerCluster;
    shift =0;
    while (temp >>= 1)
    {
        shift++;
    }
    MediaTable[ DeviceNum].TotalNoofclusters    =( DataSec >> shift);

    /* if total data clusters are less than 4085, File system is FAT12 type */
    if (MediaTable[ DeviceNum].TotalNoofclusters < 4085)
    {
        MediaTable[ DeviceNum].FATType = FAT12; 
    }
    /* if total data clusters are less than 65525, File system is FAT16 type */
    else if (MediaTable[ DeviceNum].TotalNoofclusters < 65525 )
    {
        MediaTable[ DeviceNum].FATType = FAT16;       
    }
    else
    {   /* total data clusters are more than 65525, so File system is FAT32 type */
        MediaTable[ DeviceNum].FATType = FAT32; 
    }

    if (MediaTable[DeviceNum].FATType == FAT32)
    {
        DataSec = MediaTable[DeviceNum].RootdirCluster;
        MediaTable[DeviceNum].FirRootdirsec = ((DataSec - 2) * MediaTable[DeviceNum].SectorsPerCluster) + MediaTable[ DeviceNum].FIRSTDataSector;
        MediaTable[DeviceNum].FSInfoSector = fsInfoSector;

        /* Add a fix here for the Win98 support */
        EnterNonReentrantSection();
 
        /* Write undertermined FSinfo size into the FAT, so that we can force the Win98 
           to compute for free cluster count. This operation should not affect Win2000, WinXP */
        DataSec = 0xFFFFFFFFFFFF;       /* To save some memory let's reuse this variable */

        /* Write FAT32FSIFREECOUNT with 0xffffffff to make it become unknown size for FAT32. 
           Ignore the return code for FSWriteSector because this is not a crucial operation, 
           if it fails we are still OK */

        if( FSWriteSector(DeviceNum,MediaTable[DeviceNum].FSInfoSector,FAT32FSIFREECOUNTOFFSET,
                        (uint8_t*)&DataSec,0,FAT32FSIFREECOUNTSIZE,WRITE_TYPE_RANDOM) != 0)
        { ;  /* (DebugBuildAssert(0); */ 
        }        
        LeaveNonReentrantSection();
    }/* end FAT32 case. */
    /* if FAT Type is FAT12 or FAT16 then root directory starts after reserved sector 
       and primary and secondary FAT table */
    else if( (MediaTable[DeviceNum].FATType == FAT12) ||  (MediaTable[DeviceNum].FATType == FAT16) )
    {
        MediaTable[DeviceNum].FirRootdirsec = MediaTable[DeviceNum].RsvdSectors +  (MediaTable[DeviceNum].NoOfFATs * MediaTable[DeviceNum].FATSize);
    }
       
    return SUCCESS;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t FSSize(int32_t DeviceNum, int32_t TYPE)

   FunctionType:  Non-Reentrant

   Inputs:        1) Device number
                  2) Type

   Outputs:       File size
<
----------------------------------------------------------------------------*/
int32_t FSSize(int32_t DeviceNum, int32_t TYPE)
{
    int64_t fsize = (int64_t)MediaTable[ DeviceNum].TotalNoofclusters*(int64_t)MediaTable[ DeviceNum].SectorsPerCluster*(int64_t)MediaTable[ DeviceNum].BytesPerSector;
    fsize = fsize >> 20;
    return fsize;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t FSFreeClusters(int32_t Device)

   FunctionType:  Non-Reentrant

   Inputs:        1) Device number
                   
   Outputs:       TotalFreeClusters
<
//----------------------------------------------------------------------------*/
int32_t FSFreeClusters(int32_t Device)
{
    return MediaTable[Device].TotalFreeClusters;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t BytesPerCluster(int32_t Device)

   FunctionType:  Non-Reentrant

   Inputs:        1) Device number
                   
   Outputs:       BytesPerCluster
<
//----------------------------------------------------------------------------*/
int32_t BytesPerCluster(int32_t Device)
{
    return (1 << MediaTable[Device].ClusterShift);
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t FSClusterShift(int32_t Device)

   FunctionType:  Non-Reentrant

   Inputs:        1) Device number
                   
   Outputs:       ClusterShift
<
//----------------------------------------------------------------------------*/
int32_t FSClusterShift(int32_t Device)
{
    return (MediaTable[Device].ClusterShift);
}

/*----------------------------------------------------------------------------
>  Function Name: int64_t FSFreeSpace(int32_t Device)

   FunctionType:  Non-Reentrant

   Inputs:        1) Device number
                   
   Outputs:       int64_t FSFreeSpace in bytes or a negative error code.
<
----------------------------------------------------------------------------*/
int64_t FSFreeSpace(int32_t Device)
{
    //!todo Search for better ways to check for Drive's health here. Relates to SDK-1864.
    // Don't just return 0 when FSDriveInit and Computefreecluster() haven't succeeded yet.
    //      .DevicePresent is only set to non-zero by Readdevicerecord().
    // I don't think checking .DevicePresent is a reliable approach though.
    return (int64_t)( ((uint64_t) MediaTable[Device].TotalFreeClusters) << MediaTable[Device].ClusterShift);
}

/*----------------------------------------------------------------------------
>  Function Name: int64_t FSFreeSpaceFromHandle(int32_t HandleNumber)

   FunctionType:  Non-Reentrant

   Inputs:        1) Handle number

   Outputs:       FSFreeSpace or 0 for invalid handle
<
----------------------------------------------------------------------------*/
int64_t FSFreeSpaceFromHandle(int32_t HandleNumber)
{
    if (SUCCESS == Handleactive(HandleNumber))
        return FSFreeSpace(Handle[HandleNumber].Device);
    else
        return 0;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t FSMediaPresent(int32_t DeviceNum)  

   FunctionType:  Non-Reentrant

   Inputs:        1) DeviceNum 
                   
   Outputs:       returns device is present or not
<
----------------------------------------------------------------------------*/
int32_t FSMediaPresent(int32_t DeviceNum)
{
    return MediaTable[DeviceNum].DevicePresent;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t FSFATType (int32_t DeviceNum)
 
   FunctionType:  Non-Reentrant

   Inputs:        1) DeviceNum 

   Outputs:       Returns FAT type.
<
----------------------------------------------------------------------------*/
int32_t FSFATType (int32_t DeviceNum)
{
    return MediaTable[DeviceNum].FATType;
}

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t Cleardevicerecord(int32_t DeviceNum)
 
   FunctionType:  Reentrant

   Inputs:        1)Device number

   Outputs:       SUCCESS else an error

   Description:   Clear the device Media Table
<
----------------------------------------------------------------------------*/
RtStatus_t Cleardevicerecord(int32_t DeviceNum)
{ 
 
    if((DeviceNum < 0) || (DeviceNum >=maxdevices))
        return ERROR_OS_FILESYSTEM_DEVICE_NOT_SUPPORTED;
  
    memset((void *)&MediaTable[DeviceNum],0,sizeof(FileSystemMediaTable_t));

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
//!
//!     \brief       Detect the present of an MMC/SD card and validate its FAT/FS status.
//!
//!     Cancel 
//!
//!     \fntype      non-reentrant function
//!
//!     \retval      MEDIA_MMC_VALID if FSFATType() detects a valid FAT on the card,
//!               or MEDIA_MMC_INVALID if present and removable drive init but FS FAT type invalid,
//!               or MEDIA_MMC_NOT_PRESENT if g_bFrameworkExternalDriveOrFsInit is false.
//!
//      Note:        g_bFrameworkExternalDriveOrFsInit is read to check if an external 
//                   media is present with drive init and maybe FS init and 
//                   to check if its FAT type is ready to be used.
//                   Note: Will only return success case of MEDIA_MMC_VALID after the app 
//                         has init the external drive's FS.
////////////////////////////////////////////////////////////////////////////////
media_mmc_status_t ExternalMMCMediaPresent(void)
{
    media_mmc_status_t Status = MEDIA_MMC_NOT_PRESENT;

    // Note: In some apps that don't enable the sdk os media framework to init the FS, 
    //   g_bFrameworkExternalDriveOrFsInit true just means that media & drive are init.
    // We'd prefer a check of the FsDriveInit & computefreeclusters status. 
    if( g_bFrameworkExternalDriveOrFsInit ) 
    {   
        // External Drive was init. 
        // Did FsInit and FsDriveInit run and succeed?
        if (FSFATType(DATA_DRIVE_ID_EXTERNAL) != FAT_TYPE_INVALID)
        {
            Status = MEDIA_MMC_VALID;
        }
        else
        {   // Drive is init and removable media is present but FS is invalid.
            Status = MEDIA_MMC_INVALID;
        }
    }

    return(Status);
}







