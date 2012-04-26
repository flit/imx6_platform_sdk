///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Freescale Semiconductor. All rights reserved.
// 
// Freescale Semiconductor
// Proprietary & Confidential
// 
// This source code and the algorithms implemented therein constitute confidential
// information and may comprise trade secrets of Freescale Semiconductor or its
// associates, and any use thereof is subject to the terms and conditions of the
// Confidential Disclosure Agreement pursual to which this source code was
// originally received.
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ddi_media
//! @{
//! \file ddi_media.c
//! \brief Contains public interface for the Logical Drive Layer.
////////////////////////////////////////////////////////////////////////////////

#include "drivers/media/ddi_media.h"

inline void ddi_ldl_push_media_task(const char * taskName) {}
inline void ddi_ldl_pop_media_task(void) {}
inline unsigned ddi_ldl_get_media_task_count(void) { return 0; }
inline unsigned ddi_ldl_get_media_task_stack(const char ** tasks, unsigned maxTasks) { return 0; }

RtStatus_t FSDataDriveInit(DriveTag_t tag){return 0;}
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
