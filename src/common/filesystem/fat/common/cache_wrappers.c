///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Freescale Semiconductor. All rights reserved.
// 
// Freescale Semiconductor
// Proprietary & Confidential
// 
// This source code and the algorithms implemented therein constitute
// confidential information and may comprise trade secrets of Freescale Semiconductor.
// or its associates, and any use thereof is subject to the terms and
// conditions of the Confidential Disclosure Agreement pursual to which this
// source code was originally received.
///////////////////////////////////////////////////////////////////////////////
//! \addtogroup fs_fat
//! @{
//! \file cache_wrappers.c
//! \brief Contains wrappers for the cache read and write calls.
///////////////////////////////////////////////////////////////////////////////

#include "fat_internal.h"
#include "drivers/media/cache/media_cache.h"
#include "drivers/media/buffer_manager/media_buffer_manager.h"
#include <string.h>
#include <arm_ghs.h>

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! \brief Determines if a sector is within the first FAT.
static bool IsFATSector(uint32_t drive, uint32_t sector)
{
    uint32_t start = MediaTable[drive].RsvdSectors;
    uint32_t end = start + MediaTable[drive].FATSize;
    return (sector >= start) && (sector < end); 
}

//! \brief Returns the appropriate weight for the given sector.
static inline int GetSectorWeight(uint32_t drive, uint32_t sector)
{
    return IsFATSector(drive, sector) ? kMediaCacheWeight_High : kMediaCacheWeight_Medium;
}

//! Param block fields:
//! - \b => \i drive
//! - \b => \i sector
//! - \b => \i flags
//! - \b => \i buffer
//! - \b X \i requestSectorCount
//! - \b X \i actualSectorCount
//! - \b X \i token
//! - \b => \i writeOffset
//! - \b => \i writeByteCount
//! - \b => \i mode
RtStatus_t FSWriteSector(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType)
{
    RtStatus_t status;
    
    // Setup param block for write.
    MediaCacheParamBlock_t pb = {0};
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.buffer = sourceBuffer + sourceOffset;
    pb.writeOffset = destOffset;
    pb.writeByteCount = numBytesToWrite;
    pb.mode = writeType;
    pb.weight = GetSectorWeight(deviceNumber, sectorNumber);
    pb.flags = kMediaCacheFlag_ApplyWeight;
    
    ddi_ldl_push_media_task((const char *)__builtin_return_address(0));
    
    // Do the write.
    status = media_cache_write(&pb);
    
    ddi_ldl_pop_media_task();
    
    return status;
}

// used by Fwrite_BypassCache(), used by StorWriteObjectData()
RtStatus_t FSWriteSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType)
{
    // Setup param block for write.
    MediaCacheParamBlock_t pb = {0};
    pb.flags = kMediaCacheFlag_BypassCache | kMediaCacheFlag_ApplyWeight | kMediaCacheFlag_NoReadback | kMediaCacheFlag_SequentialWrite;
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.buffer = sourceBuffer + sourceOffset;
    pb.writeOffset = destOffset;
    pb.writeByteCount = numBytesToWrite;
    pb.mode = writeType;
    pb.weight = kMediaCacheWeight_Low;
    
    // Do the write.
    return media_cache_write(&pb);
}

// Used only in clearcluster() in the FAT filesystem. Can replace with call to writesector.
RtStatus_t FSEraseSector(int32_t deviceNumber, int32_t sectorNumber)
{
    MediaCacheParamBlock_t pb = {0};
    RtStatus_t status;
    uint8_t * buffer;

    // Acquire a buffer to hold the empty sector.
    status = media_buffer_acquire(kMediaBufferType_Sector, 0, (SECTOR_BUFFER **)&buffer);
    if (status != SUCCESS)
    {
        return status;
    }
    
    // Clear the sector buffer to all zeroes.
    memset(buffer, 0, MediaTable[deviceNumber].BytesPerSector);
    
    // Setup param block for write.
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.buffer = buffer;
    pb.writeOffset = 0;
    pb.writeByteCount = MediaTable[deviceNumber].BytesPerSector;
    pb.mode = WRITE_TYPE_RANDOM;
    pb.weight = GetSectorWeight(deviceNumber, sectorNumber);
    pb.flags = kMediaCacheFlag_ApplyWeight;
    
    // Write the empty sector.
    status = media_cache_write(&pb);
    
    // Let go of the sector buffer.
    media_buffer_release((SECTOR_BUFFER *)buffer);
    
    return status;
}

//! Param block fields:
//! - \b => \i drive
//! - \b => \i sector
//! - \b => \i flags
//! - \b <= \i buffer
//! - \b X \i requestSectorCount
//! - \b X \i actualSectorCount
//! - \b <= \i token
//! - \b X \i writeOffset
//! - \b X \i writeByteCount
//! - \b => \i mode
int32_t * FSReadSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint32_t * token)
{
    RtStatus_t status;
    MediaCacheParamBlock_t pb = {0};
    
    // Setup the param block for a read.
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.requestSectorCount = 1;
    pb.mode = writeType;
    pb.weight = GetSectorWeight(deviceNumber, sectorNumber);
    pb.flags = kMediaCacheFlag_ApplyWeight;

    ddi_ldl_push_media_task((const char *)__builtin_return_address(0));
    
    // Read the sector.
    status = media_cache_read(&pb);
    
    ddi_ldl_pop_media_task();
    
    // Give the caller the token so they can release the cache entry.
    if (status == SUCCESS && token)
    {
        *token = pb.token;
        return (int32_t *)pb.buffer;
    }
    else
    {
        // An error occurred, so return NULL.
        return NULL;
    }
}

// used by Fread_BypassCache(), used by StorReadObjectData()
int32_t * FSReadSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint8_t *pBuffer, uint32_t * token)
{
    RtStatus_t status;
    MediaCacheParamBlock_t pb = {0};
    
    // Setup the param block for a read.
    pb.flags = kMediaCacheFlag_BypassCache | kMediaCacheFlag_ApplyWeight;
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.requestSectorCount = 1;
    pb.mode = writeType;
    pb.weight = kMediaCacheWeight_Low;
    
    // Read the sector.
    status = media_cache_read(&pb);
    
    // Give the caller the token so they can release the cache entry.
    if (status == SUCCESS && token)
    {
        *token = pb.token;
        return (int32_t *)pb.buffer;
    }
    else
    {
        // An error occurred, so return NULL.
        return NULL;
    }
}

RtStatus_t FSReleaseSector(uint32_t token)
{
    return media_cache_release(token);
}

//! Param block fields:
//! - \b => \i drive
//! - \b => \i sector
//! - \b => \i flags
//! - \b X \i buffer
//! - \b X \i requestSectorCount
//! - \b X \i actualSectorCount
//! - \b X \i token
//! - \b X \i writeOffset
//! - \b X \i writeByteCount
//! - \b X \i mode
RtStatus_t FSFlushSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, int32_t ix, int32_t * writeFlag)
{
    MediaCacheParamBlock_t pb = {0};
    
    // Setup the param block for a sector flush.
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    
    // Assume we had to write.
    *writeFlag = 1;
    
    // Flush the specified sector.
    return media_cache_flush(&pb);
}

RtStatus_t FlushCache(void)
{
    MediaCacheParamBlock_t pb = {0};
    
    // Setup the param block to flush the entire cache.
    pb.flags = kMediaCacheFlag_FlushAllDrives;
    
    // Flush the specified sector.
    return media_cache_flush(&pb);
}

RtStatus_t FSFlushDriveCache(int32_t deviceNumber)
{
    MediaCacheParamBlock_t pb = {0};
    
    // Setup the param block for a drive flush.
    pb.flags = kMediaCacheFlag_FlushDrive;
    pb.drive = deviceNumber;
    
    // Flush the specified sector.
    return media_cache_flush(&pb);
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}

