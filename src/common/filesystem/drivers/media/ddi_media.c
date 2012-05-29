/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ddi_media
//! @{
//! \file ddi_media.c
//! \brief Contains public interface for the Logical Drive Layer.
////////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "errordefs.h"
#include <string.h>
#include "filesystem/fsapi.h"
#include "drivers/media/media_cache.h"
#include "drivers/media/ddi_media.h"
#include "usdhc/inc/usdhc_ifc.h"

extern uint32_t usdhc_base_addr;

inline void ddi_ldl_push_media_task(const char * taskName) {}
inline void ddi_ldl_pop_media_task(void) {}
inline unsigned ddi_ldl_get_media_task_count(void) { return 0; }
inline unsigned ddi_ldl_get_media_task_stack(const char ** tasks, unsigned maxTasks) { return 0; }

/* start sector */
uint32_t g_u32MbrStartSector = 0;

////////////////////////////////////////////////////////////////////////////////
//! \brief Verify if the supplied sector contains valid fields of a
//!        Partition Boot Sector. Internal function.
//! \param[in] pSectorBuffer - Sector Data (presumably of a Partition Boot Sector)
//!
//! \retval SUCCESS
//! \retval ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND 
//! \internal
////////////////////////////////////////////////////////////////////////////////
RtStatus_t VerifyPBS(uint8_t* pSectorData)
{
    uint32_t u8SecValue = 1;
    uint8_t u8SecPerClus = pSectorData[0x0d];
    uint32_t i;

    // Verify that the Sectors Per Cluster field is a power of 2 value
    for (i = 0; i < 8; i++)
    {
        if (u8SecPerClus == u8SecValue)
        {
            break;
        }
        u8SecValue <<= 1;
    }

    if ((u8SecValue == 256) || ((pSectorData[0] != 0xEB) && (pSectorData[0] != 0xE9)))
    {
	     return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    // Verify the Boot Sector signature field (should be 0xAA55)
    if (((pSectorData[0x1fe] == 0x55) && (pSectorData[0x1ff] == 0xAA)) ||
        ((pSectorData[0x7fe] == 0x55) && (pSectorData[0x7ff] == 0xAA)))
    {
        return SUCCESS;
    }

    return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
}

RtStatus_t FSDataDriveInit(DriveTag_t tag)
{
    uint32_t u32PbsTotalSectors;
    uint32_t ProbablePBSFlag = 0;
    uint8_t* pSectorData;
    RtStatus_t retval;
    uint32_t pbsOffset;
    MediaCacheParamBlock_t pb = {0};

	/*Note by Ray: in this function, intialize the uSDHC controller*/
    retval = card_init(usdhc_base_addr, 8);
    /*now enable the INTERRUPT mode of usdhc */
    SDHC_INTR_mode = 0;
    SDHC_ADMA_mode = 0;
	
    if (retval == 1) {
        return 1;
    }
    
    // First read sector 0
    pb.flags = kMediaCacheFlag_NoPartitionOffset;
    pb.sector = 0;
    pb.requestSectorCount = 1;
    pb.mode = WRITE_TYPE_RANDOM;
    retval = media_cache_read(&pb);
    pSectorData = pb.buffer;
    if (retval != SUCCESS || pSectorData == 0)
    {
        return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    // First, extract the assumed start sector. We don't want to set the g_u32MbrStartSector
    // global yet, because ReadSector() uses MediaRead(), which offsets based on that global's
    // value. Thus, we'd get a double offset when trying to read the PBS.
    pbsOffset = pSectorData[0x1c6] + (pSectorData[0x1c7] << 8) + (pSectorData[0x1c8] << 16) + (pSectorData[0x1c9] << 24);

    // Now read what may be the first sector of the first partition
    pb.sector = pbsOffset;
    retval = media_cache_read(&pb);
    pSectorData = pb.buffer;
    if (retval != SUCCESS || pSectorData == 0)
    {
        // The read failed, hence we might not have this sector as MBR, assume PBS
        ProbablePBSFlag = 1;
    }
    else
    {
        if ((retval = VerifyPBS(pSectorData)) != SUCCESS)
        {
            // The verification failed, so assume PBS
            ProbablePBSFlag = 1;
        }
    }
    
    // Ok, so Sector 0 might be a PBS, verify that this is indeed the case.
    if (ProbablePBSFlag == 1)
    {
        pbsOffset = 0;

        pb.sector = pbsOffset;
        retval = media_cache_read(&pb);
        pSectorData = pb.buffer;
        if (retval != SUCCESS || pSectorData == 0)
        {
            // Not necessary to media_cache_release() here, because the read failed.

            retval = ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
            return retval;
        }
        
        if ((retval = VerifyPBS(pSectorData)) != SUCCESS)
        {
            return retval;
        }
    }
    else
    {
        /* it usually ends here */
        g_u32MbrStartSector = pbsOffset;
    }

    // Get Total Sectors from PBS (first look at small 2-byte count field at 0x13&0x14)
    u32PbsTotalSectors = pSectorData[0x13] + (pSectorData[0x14] << 8);

    if (u32PbsTotalSectors == 0)
    {
        // Total Sectors is in the large 4-byte count field beginning at 0x20
        u32PbsTotalSectors = pSectorData[0x20] + (pSectorData[0x21] << 8) + (pSectorData[0x22] << 16) + (pSectorData[0x23] << 24);
    }

    if (u32PbsTotalSectors == 0)
    {
        return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    return SUCCESS;
}

unsigned MediaGetCount(void){return 0;}
RtStatus_t MediaGetInfoSize(unsigned mediaNumber, uint32_t selector, uint32_t * propertySize){return 0;}
RtStatus_t MediaSetInfo(unsigned mediaNumber, uint32_t selector, const void * value){return 0;}
uint32_t MediaGetMaximumSectorSize(void){return 0;}
RtStatus_t MediaInit(uint32_t u32LogMediaNumber){return 0;}
RtStatus_t MediaAllocate(uint32_t u32LogMediaNumber, MediaAllocationTable_t * pMediaTable){return 0;}
RtStatus_t MediaDiscoverAllocation(uint32_t u32LogMediaNumber){return 0;}
RtStatus_t MediaGetMediaTable(uint32_t u32LogMediaNumber, MediaAllocationTable_t ** pMediaTable){return 0;}
RtStatus_t MediaFreeMediaTable(uint32_t mediaNumber, MediaAllocationTable_t * table){return 0;}
RtStatus_t MediaGetInfo(uint32_t u32LogMediaNumber, uint32_t Type, void * pInfo){return 0;}
RtStatus_t MediaErase(uint32_t u32LogMediaNumber, uint32_t u32MagicNumber, uint8_t u8NoEraseHidden){return 0;}
RtStatus_t MediaShutdown(uint32_t u32LogMediaNumber){return 0;}
RtStatus_t MediaFlushDrives(uint32_t u32LogMediaNumber){return 0;}
RtStatus_t MediaSetBootDrive(uint32_t u32LogMediaNumber, DriveTag_t u32DriveTag){return 0;}
unsigned DriveGetCount(void){return 0;}
RtStatus_t DriveCreateIterator(DriveIterator_t * iter){return 0;}
RtStatus_t DriveIteratorNext(DriveIterator_t iter, DriveTag_t * tag){return 0;}
void DriveIteratorDispose(DriveIterator_t iter){}
DriveState_t DriveGetState(DriveTag_t tag){return 0;}
RtStatus_t DriveInitAll(void){return 0;}
RtStatus_t DriveGetInfoSize(DriveTag_t tag, uint32_t selector, uint32_t * propertySize){return 0;}
RtStatus_t DriveInit(DriveTag_t tag){return 0;}
RtStatus_t DriveGetInfo(DriveTag_t tag, uint32_t Type, void * pInfo){return 0;}
RtStatus_t DriveSetInfo(DriveTag_t tag, uint32_t Type, const void * pInfo){return 0;}
RtStatus_t DriveReadSector(DriveTag_t tag, uint32_t u32SectorNumber, SECTOR_BUFFER * pSectorData){return 0;}
RtStatus_t DriveReadSectorForVMI(DriveTag_t tag, uint32_t u32SectorNumber, SECTOR_BUFFER * pSectorData){return 0;}
RtStatus_t DriveWriteSector(DriveTag_t tag, uint32_t u32SectorNumber, const SECTOR_BUFFER * pSectorData){return 0;}
RtStatus_t DriveOpenMultisectorTransaction(DriveTag_t tag, uint32_t startSector, uint32_t sectorCount, bool isRead){return 0;}
RtStatus_t DriveCommitMultisectorTransaction(DriveTag_t tag){return 0;}
RtStatus_t DriveErase(DriveTag_t tag, uint32_t u32MagicNumber){return 0;}
RtStatus_t DriveRepair(DriveTag_t tag, uint32_t u32MagicNumber){return 0;}
RtStatus_t DriveFlush(DriveTag_t tag){return 0;}
RtStatus_t DriveShutdown(DriveTag_t tag){return 0;}
