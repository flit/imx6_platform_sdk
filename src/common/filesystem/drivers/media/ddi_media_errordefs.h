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
//! \file ddi_media_errordefs.h
//! \brief Error definitions for all media components.
////////////////////////////////////////////////////////////////////////////////
#ifndef _DDI_MEDIA_ERRORDEFS_H
#define _DDI_MEDIA_ERRORDEFS_H

#include "drivers/ddi_errordefs.h"

//! \addtogroup ddi_media
//! @{

    //! \name Logical drive layer errors
    //!
    //! Errors returned from the logical drive layer for all media types.
    //@{
        //! \brief Generic LDL error.  [0xf0208000]
        #define ERROR_DDI_LDL_GENERAL                                    (ERROR_DDI_LDL_GROUP)

        //! \brief [0xf0208001]
        #define ERROR_DDI_LDL_LDRIVE_INVALID_DRIVE_NUMBER                (ERROR_DDI_LDL_GROUP + 1)

        //! \brief [0xf0208002]
        #define ERROR_DDI_LDL_LDRIVE_NOT_INITIALIZED                     (ERROR_DDI_LDL_GROUP + 2)

        //! \brief General hardware failure. [0xf0008003]
        #define ERROR_DDI_LDL_LDRIVE_HARDWARE_FAILURE                    (ERROR_DDI_LDL_GROUP + 3)

        //! \brief [0xf0208004]
        #define ERROR_DDI_LDL_LDRIVE_INVALID_DRIVE_TYPE                  (ERROR_DDI_LDL_GROUP + 4)

        //! \brief [0xf0208005]
        #define ERROR_DDI_LDL_LDRIVE_INVALID_INFO_TYPE                   (ERROR_DDI_LDL_GROUP + 5)

        //! \brief [0xf0208006]
        #define ERROR_DDI_LDL_LDRIVE_SECTOR_OUT_OF_BOUNDS                (ERROR_DDI_LDL_GROUP + 6)

        //! \brief [0xf0208007]
        #define ERROR_DDI_LDL_LDRIVE_WRITE_PROTECTED                     (ERROR_DDI_LDL_GROUP + 7)

        //! \brief [0xf020800b]
        #define ERROR_DDI_LDL_LDRIVE_WRITE_ABORT                         (ERROR_DDI_LDL_GROUP + 11)

        //! \brief [0xf020800c]
        #define ERROR_DDI_LDL_LDRIVE_MEDIA_NOT_ALLOCATED                 (ERROR_DDI_LDL_GROUP + 12)

        //! \brief [0xf020800d]
        #define ERROR_DDI_LDL_LDRIVE_LOW_LEVEL_MEDIA_FORMAT_REQUIRED     (ERROR_DDI_LDL_GROUP + 13)

        //! \brief General hardware failure. [0xf0008010]
        #define ERROR_DDI_LDL_LMEDIA_HARDWARE_FAILURE                    (ERROR_DDI_LDL_GROUP + 16)

        //! \brief [0xf0208011]
        #define ERROR_DDI_LDL_LMEDIA_INVALID_MEDIA_NUMBER                (ERROR_DDI_LDL_GROUP + 17)

        //! \brief [0xf0208012]
        #define ERROR_DDI_LDL_LMEDIA_MEDIA_NOT_INITIALIZED               (ERROR_DDI_LDL_GROUP + 18)

        //! \brief [0xf0208013]
        #define ERROR_DDI_LDL_LMEDIA_MEDIA_NOT_DISCOVERED                (ERROR_DDI_LDL_GROUP + 19)

        //! \brief [0xf0208014]
        #define ERROR_DDI_LDL_LMEDIA_INVALID_MEDIA_INFO_TYPE             (ERROR_DDI_LDL_GROUP + 20)

        //! \brief [0xf0208015]
        #define ERROR_DDI_LDL_LMEDIA_ALLOCATION_TOO_LARGE                (ERROR_DDI_LDL_GROUP + 21)

        //! \brief [0xf0208016]
        #define ERROR_DDI_LDL_LMEDIA_MEDIA_NOT_ERASED                    (ERROR_DDI_LDL_GROUP + 22)

        //! \brief [0xf0208017]
        #define ERROR_DDI_LDL_LMEDIA_MEDIA_ERASED                        (ERROR_DDI_LDL_GROUP + 23)

        //! \brief [0xf0208018]
        #define ERROR_DDI_LDL_LMEDIA_MEDIA_ALLOCATE_BOUNDS_EXCEEDED      (ERROR_DDI_LDL_GROUP + 24)

        //! \brief Indicates that the corrupted drive is not recoverable. [0xf000801b]
        #define ERROR_DDI_LDL_LDRIVE_DRIVE_NOT_RECOVERABLE               (ERROR_DDI_LDL_GROUP + 27)

        //! \brief Cannot set the sector size to the given value. [0xf000801c]
        #define ERROR_DDI_LDL_LDRIVE_INVALID_SECTOR_SIZE                 (ERROR_DDI_LDL_GROUP + 28)

        //! \brief Cannot do something because the drive is already initialized. [0xf000801d]
        #define ERROR_DDI_LDL_LDRIVE_ALREADY_INITIALIZED                 (ERROR_DDI_LDL_GROUP + 29)

        //! \brief There is no drive with the given tag value. [0xf000801e]
        #define ERROR_DDI_LDL_LDRIVE_INVALID_DRIVE_TAG                   (ERROR_DDI_LDL_GROUP + 30)
        
        //! \brief An LDL iterator has no more items to return. [0xf000801f]
        #define ERROR_DDI_LDL_ITERATOR_DONE                              (ERROR_DDI_LDL_GROUP + 31)
        
        //! \brief An LDL API is unimplemented by the underlying media driver. [0xf0008020]
        #define ERROR_DDI_LDL_UNIMPLEMENTED                              (ERROR_DDI_LDL_GROUP + 32)

        //! \brief A file system format is required on the drive. [0xf0008021]
        #define ERROR_DDI_LDL_LDRIVE_FS_FORMAT_REQUIRED                  (ERROR_DDI_LDL_GROUP + 33)
    //@}

//! @}

//! \addtogroup media_buf_mgr
//! @{

    //! \name Media buffer manager errors
    //!
    //! Errors that the media buffer manager will return from its APIs.
    //@{
        //! General error. Not used. [0xf021f000]
        #define ERROR_DDI_MEDIABUFMGR_GENERAL                            (ERROR_DDI_MEDIABUFMGR_GROUP)

        //! There is no room to add another buffer to the buffer manager. [0xf021f001]
        #define ERROR_DDI_MEDIABUFMGR_NO_ROOM                            (ERROR_DDI_MEDIABUFMGR_GROUP + 1)

        //! The buffer passed into buffer_release() was not obtained from the buffer manager. [0xf021f002]
        #define ERROR_DDI_MEDIABUFMGR_INVALID_BUFFER                     (ERROR_DDI_MEDIABUFMGR_GROUP + 2)

        //! The buffer manager was unable to allocate a new temporary buffer for some reason. [0xf021f003]
        #define ERROR_DDI_MEDIABUFMGR_ALLOC_FAILED                       (ERROR_DDI_MEDIABUFMGR_GROUP + 3)

        //! Attempt to read an unknown or invalid property. [0xf021f004]
        #define ERROR_DDI_MEDIABUFMGR_INVALID_PROPERTY                   (ERROR_DDI_MEDIABUFMGR_GROUP + 4)
    //@}

//! @}

//! \addtogroup media_cache
//! @{

    //! \name Media cache errors
    //!
    //@{
        //! General error, not used. [0xf021e000]
        #define ERROR_DDI_MEDIA_CACHE_GENERAL                            (ERROR_DDI_MEDIA_CACHE_GROUP)

        //! The buffer passed to media_cache_init() is not useable for some reason. [0xf021e001]
        #define ERROR_DDI_MEDIA_CACHE_INVALID_BUFFER                     (ERROR_DDI_MEDIA_CACHE_GROUP + 1)

        //! Timed out while waiting for exclusive access to a cache entry. [0xf021e002]
        #define ERROR_DDI_MEDIA_CACHE_TIMEOUT                            (ERROR_DDI_MEDIA_CACHE_GROUP + 2)

        //! The address given for the storage media (either origin or range) is incorrect. [0xf021e003]
        #define ERROR_DDI_MEDIA_CACHE_INVALID_MEDIA_ADDRESS              (ERROR_DDI_MEDIA_CACHE_GROUP + 3)
    //@}
//! @}

//! \addtogroup ddi_lba_nand
//! @{

    //! \name LBA-NAND errors
    //!
    //! Internal errors returned from the LBA-NAND driver.
    //@{
        //! \brief Generic LDL error.  [0xf0230000]
        #define ERROR_DDI_LBA_NAND_GENERAL                               (ERROR_DDI_LBA_NAND_GROUP)

        //! \brief Unknown device type code. [0xf0230001]
        #define ERROR_DDI_LBA_NAND_UNKNOWN_DEVICE_TYPE                   (ERROR_DDI_LBA_NAND_GROUP + 1)

        //! \brief Requested VFP size is too large. [0xf0230002]
        #define ERROR_DDI_LBA_NAND_VFP_SIZE_TOO_LARGE                    (ERROR_DDI_LBA_NAND_GROUP + 2)

        //! \brief Partition mode was not set as expected. [0xf0230003]
        #define ERROR_DDI_LBA_NAND_MODE_NOT_SET                          (ERROR_DDI_LBA_NAND_GROUP + 3)

        //! \brief Sector address is out of range. [0xf0230004]
        #define ERROR_DDI_LBA_NAND_ADDRESS_OUT_OF_RANGE                  (ERROR_DDI_LBA_NAND_GROUP + 4)

        //! \brief All spare blocks have been used. [0xf0230005]
        #define ERROR_DDI_LBA_NAND_SPARE_BLOCKS_EXHAUSTED                (ERROR_DDI_LBA_NAND_GROUP + 5)

        //! \brief Unknown VFP capacity model type was returned from the device. [0xf0230006]
        #define ERROR_DDI_LBA_NAND_UNKNOWN_VFP_CAPACITY_MODEL_TYPE       (ERROR_DDI_LBA_NAND_GROUP + 6)

        //! \brief VFP was allocated neither by normal nor EX commands. [0xf0230007]
        #define ERROR_DDI_LBA_NAND_VFP_SIZE_PARADOX                      (ERROR_DDI_LBA_NAND_GROUP + 7)

        //! \brief An attempted write command failed. [0xf0230008]
        #define ERROR_DDI_LBA_NAND_WRITE_FAILED                          (ERROR_DDI_LBA_NAND_GROUP + 8)

        //! \brief The VFP was not set to the expected size. [0xf0230009]
        #define ERROR_DDI_LBA_NAND_SET_VFP_SIZE_FAILED                   (ERROR_DDI_LBA_NAND_GROUP + 9)
    //@}

//! @}

//! \addtogroup ddi_media_nand_hal_gpmi
//! @{

    //! \name GPMI driver errors
    //!
    //! Internal errors returned from the NAND GPMI driver.
    //@{
        //! \brief Generic GPMI error. [0xf0231000]
        #define ERROR_DDI_NAND_GPMI_GENERAL                              (ERROR_DDI_NAND_GPMI_GROUP)

        //! \brief A DMA is already running. [0xf0231001]
        #define ERROR_DDI_NAND_GPMI_DMA_BUSY                             (ERROR_DDI_NAND_GPMI_GROUP + 1)

        //! \brief The DMA timed out. [0xf0231002]
        #define ERROR_DDI_NAND_GPMI_DMA_TIMEOUT                          (ERROR_DDI_NAND_GPMI_GROUP + 2)

        //! \brief The GPMI peripheral is not present. [0xf0231003]
        #define ERROR_DDI_NAND_GPMI_NOT_PRESENT                          (ERROR_DDI_NAND_GPMI_GROUP + 3)

        //! \brief An attempted write DMA sequence failed. [0xf0231004]
        #define ERROR_DDI_NAND_GPMI_WRITE_FAILED                         (ERROR_DDI_NAND_GPMI_GROUP + 4)

        //! \brief The ECC8 peripheral is not present. [0xf0231005]
        #define ERROR_DDI_NAND_GPMI_ECC8_NOT_PRESENT                     (ERROR_DDI_NAND_GPMI_GROUP + 5)
    //@}

//! @}

//! \addtogroup ddi_nand
//! @{

    //! \name NAND driver errors
    //!
    //! Errors returned from the NAND driver through direct calls to it. Note that
    //! many of these errors are no longer reported and are here for historical
    //! information only. Also note that the NAND driver will return LDL errors from
    //! its functions that implement the logical drive and logical media interfaces.
    //@{
        //! \brief Unused general error. [0xf0220000]
        #define ERROR_DDI_NAND_GROUP_GENERAL                             (ERROR_DDI_NAND_GROUP)
        
        //! \brief [0xf0220001]
        #define ERROR_DDI_NAND_LMEDIA_NO_REGIONS_IN_MEDIA                (ERROR_DDI_NAND_GROUP + 1)
        
        //! \brief [0xf0220002]
        #define ERROR_DDI_NAND_LMEDIA_DRIVES_MAX_OUT                     (ERROR_DDI_NAND_GROUP + 2)

        //! \brief [0xf0220003]
        #define ERROR_DDI_NAND_LMEDIA_MEDIA_WRITE_PROTECTED              (ERROR_DDI_NAND_GROUP + 3)

        //! \brief [0xf0220004]
        #define ERROR_DDI_NAND_LMEDIA_BAD_BLOCKS_MAX_OUT                 (ERROR_DDI_NAND_GROUP + 4)

        //! \brief [0xf0220005]
        #define ERROR_DDI_NAND_LMEDIA_NOT_ALLOCATED                      (ERROR_DDI_NAND_GROUP + 5)
        
        //! \brief Config block was not found on media. [0xf0220006]
        #define ERROR_DDI_NAND_CONFIG_BLOCK_NOT_FOUND                    (ERROR_DDI_NAND_GROUP + 6)

        //! \brief [0xf022000f]
        #define ERROR_DDI_NAND_DATA_DRIVE_CANT_RECYCLE_USECTOR_MAP       (ERROR_DDI_NAND_GROUP + 15)
        
        //! \brief The LBA in a page's metadata has an unexpected value. [0xf0220010]
        //!
        //! The LBA values in all the pages of a block must match, or this error will be returned.
        #define ERROR_DDI_NAND_DATA_DRIVE_UBLOCK_LBAS_INCONSISTENT       (ERROR_DDI_NAND_GROUP + 16)
        
        //! \brief The LSI in a page's metadata is out of range. [0xf0220011]
        //!
        //! The page is corrupted, or the wrong page was read.
        #define ERROR_DDI_NAND_DATA_DRIVE_UBLOCK_HSECTORIDX_OUT_OF_RANGE (ERROR_DDI_NAND_GROUP + 17)
        
        //! \brief There are no available NSSMs. [0xf0220012]
        //!
        //! Usually caused by previous errors that didn't put the NSSM back into the LRU. Once
        //! enough of these errors pile up, there are no longer any NSSMs in the LRU.
        #define ERROR_DDI_NAND_DATA_DRIVE_CANT_RECYCLE_UBLOCK            (ERROR_DDI_NAND_GROUP + 18)
        
        //! \brief [0xf0220013]
        #define ERROR_DDI_NAND_DATA_DRIVE_BBTABLE_FULL                   (ERROR_DDI_NAND_GROUP + 19)

        //! \brief [0xf0220021]
        #define ERROR_DDI_NAND_DATA_DRIVE_CANT_ALLOCATE_USECTORS_MAPS    (ERROR_DDI_NAND_GROUP + 33)

        //! \brief [0xf022003b]
        #define ERROR_DDI_NAND_DATA_DRIVE_INVALID_LOGICAL_SECTOR         (ERROR_DDI_NAND_GROUP + 59)
        
        //! \brief Not all chip enables are the same NAND type. [0xf0220040]
        #define ERROR_DDI_NAND_HAL_NANDTYPE_MISMATCH                     (ERROR_DDI_NAND_GROUP + 64)
        
        //! \brief This NAND is not supported by the HAL. [0xf0220041]
        #define ERROR_DDI_NAND_HAL_LOOKUP_ID_FAILED                      (ERROR_DDI_NAND_GROUP + 65)
        
        //! \brief The write or erase operation failed. [0xf0220047]
        #define ERROR_DDI_NAND_HAL_WRITE_FAILED                          (ERROR_DDI_NAND_GROUP + 71)

        //! The following three error codes are, and must remain, in ascending numerical order of severity.
        
        //! \brief Data had bit errors, but ECC was able to correct them. [0xf0220051]
        #define ERROR_DDI_NAND_HAL_ECC_FIXED                             (ERROR_DDI_NAND_GROUP + 81)
        
        //! \brief ECC was able to correct all bit errors, but the number of errors was above a threshold. [0xf0220052]
        #define ERROR_DDI_NAND_HAL_ECC_FIXED_REWRITE_SECTOR              (ERROR_DDI_NAND_GROUP + 82)
        
        //! \brief Data had more bit errors than ECC could correct. [0xf0220053]
        #define ERROR_DDI_NAND_HAL_ECC_FIX_FAILED                        (ERROR_DDI_NAND_GROUP + 83)
        
        //! \brief DMA timed out. [0xf0220057]
        #define ERROR_DDI_NAND_DMA_TIMEOUT                               (ERROR_DDI_NAND_GROUP + 87)
        
        //! \brief Block erase command failed. [0xf0220058]
        #define ERROR_DDI_NAND_ERASE_FAILED                              (ERROR_DDI_NAND_GROUP + 88)
        
        //! \brief Reset command failed. [0xf0220059]
        #define ERROR_DDI_NAND_RESET_FAILED                              (ERROR_DDI_NAND_GROUP + 89)
        
        //! Returned when marking a bad block failed. [0xf022005a]
        #define ERROR_DDI_NAND_PROGRAM_FAILED                            (ERROR_DDI_NAND_GROUP + 90)

        //! \brief [0xf022005f]
        #define ERROR_DDI_NAND_D_BAD_BLOCK_TABLE_BLOCK_NOT_FOUND         (ERROR_DDI_NAND_GROUP + 95)

        //! \brief [0xf0220060]
        #define ERROR_DDI_NAND_CANT_ALLOCATE_DBBT_BLOCK                  (ERROR_DDI_NAND_GROUP + 96)

        //! \brief [0xf0220061]
        #define ERROR_DDI_NAND_MEDIA_FINDING_NEXT_VALID_BLOCK            (ERROR_DDI_NAND_GROUP + 97)
        
        //! \brief Failed to place a boot block in its search area. [0xf0220062]
        //!
        //! This usually means that all blocks within a boot block's search area are bad.
        #define ERROR_DDI_NAND_MEDIA_CANT_ALLOCATE_BCB_BLOCK             (ERROR_DDI_NAND_GROUP + 98)
        
        //! \brief [0xf0220063]
        #define ERROR_DDI_NAND_DRIVER_NO_BCB                             (ERROR_DDI_NAND_GROUP + 99)
        
        //! \brief [0xf0220064]
        #define ERROR_DDI_NAND_BCB_SEARCH_FAILED                         (ERROR_DDI_NAND_GROUP + 100)

        //! \brief [0xf0220065]
        #define ERROR_DDI_NAND_INVALID_BOOT_IMAGE_FORMAT                 (ERROR_DDI_NAND_GROUP + 101)

        //! \brief [0xf0220066]
        #define ERROR_DDI_NAND_NO_MATCHING_SECTION                       (ERROR_DDI_NAND_GROUP + 102)

        //! Mapper is not initialized yet. [0xf0220067]
        #define ERROR_DDI_NAND_MAPPER_UNITIALIZED                        (ERROR_DDI_NAND_GROUP + 103)
        
        //! \brief [0xf0220068]
        #define ERROR_DDI_NAND_MAPPER_INVALID_PHYADDR                    (ERROR_DDI_NAND_GROUP + 104)

        //! \brief [0xf022006a]
        #define ERROR_DDI_NAND_MAPPER_GET_BLOCK_FAILED                   (ERROR_DDI_NAND_GROUP + 106)

        //! \brief [0xf022006b]
        #define ERROR_DDR_NAND_MAPPER_PHYMAP_MAPFULL                     (ERROR_DDI_NAND_GROUP + 107)

        //! \brief [0xf022006d]
        #define ERROR_DDI_NAND_MAPPER_FIND_LBAMAP_BLOCK_FAILED           (ERROR_DDI_NAND_GROUP + 109)

        //! Lba is out of range. [0xf022006e]
        #define ERROR_DDI_NAND_MAPPER_LBA_OUTOFBOUND                     (ERROR_DDI_NAND_GROUP + 110)

        //! Logical page address is out of range.  [0xf022006f]
        #define ERROR_DDI_NAND_MAPPER_PAGE_OUTOFBOUND                    (ERROR_DDI_NAND_GROUP + 111)

        //! \brief [0xf0220071]
        #define ERROR_DDI_NAND_MAPPER_LBA_CORRUPTED                      (ERROR_DDI_NAND_GROUP + 113)

        //! \brief [0xf0220072]
        #define ERROR_DDI_NAND_MAPPER_ZONE_MAP_CACHE_INIT_FAILED         (ERROR_DDI_NAND_GROUP + 114)

        //! \brief [0xf0220073]
        #define ERROR_DDI_NAND_MAPPER_ZONE_MAP_INSUFFICIENT_NUM_FREE_BLOCKS (ERROR_DDI_NAND_GROUP + 115)

        //! \brief [0xf0220076]
        #define ERROR_DDI_NAND_DATA_DRIVE_SECTOR_OUT_OF_BOUNDS           (ERROR_DDI_NAND_GROUP + 118)

        //! Failed to find the correct status. [0xf0220077]
        #define ERROR_DDI_NAND_HAL_CHECK_STATUS_FAILED                   (ERROR_DDI_NAND_GROUP + 119)

        //! Cannot initiate another firmware refresh because one is already in progress. [0xf0220078]
        #define ERROR_DDI_NAND_FIRMWARE_REFRESH_BUSY                     (ERROR_DDI_NAND_GROUP + 120)

        //! The version of the config block found on the NAND does not match the one expected by the firmware. [0xf0220079]
        #define ERROR_DDI_NAND_CONFIG_BLOCK_VERSION_MISMATCH             (ERROR_DDI_NAND_GROUP + 121)

        //! Error codes from decoding software ecc encoded NCB block. [0xf022007a]
        #define ERROR_DDI_NAND_DRIVER_NCB_TRIPLE_RED_CHK_FAILED          (ERROR_DDI_NAND_GROUP + 122)
        
        //! \brief [0xf022007b]
        #define ERROR_DDI_NAND_DRIVER_NCB_SYNDROME_TABLE_MISMATCH        (ERROR_DDI_NAND_GROUP + 123)

        //! \brief [0xf022007c]
        #define ERROR_DDI_NAND_DRIVER_NCB_HAMMING_DOUBLE_ERROR           (ERROR_DDI_NAND_GROUP + 124)

        //! The ONFI parameter page is corrupted. [0xf022007e]
        #define ERROR_DDI_NAND_HAL_INVALID_ONFI_PARAM_PAGE               (ERROR_DDI_NAND_GROUP + 126)

        //! The ONFI parameter page is corrupted. [0xf022007f]
        #define ERROR_DDI_NAND_HAL_INVALID_PARAMETER                     (ERROR_DDI_NAND_GROUP + 127)
    //@}

//! \addtogroup ddi_mmc
//! @{

    //! \name MMC driver errors
    //!
    //! Internal errors returned from the DDI_MMC driver.
    //! Note that a client may also see error codes passed up from the SSP_MMCSD and HW_SSP drivers.
    //@{
        #define ERROR_DDI_MMC_GENERAL                                    (ERROR_DDI_MMC_GROUP)

        #define ERROR_DDI_MMC_MEDIA_DEVICE_NOT_INSERTED                  (ERROR_DDI_MMC_GROUP + 1)

        #define ERROR_DDI_MMC_MEDIA_RESET_FAILED                         (ERROR_DDI_MMC_GROUP + 2)

        #define ERROR_DDI_MMC_MEDIA_APP_COMMAND_FAILED                   (ERROR_DDI_MMC_GROUP + 3)

        #define ERROR_DDI_MMC_MEDIA_INIT_FAILED                          (ERROR_DDI_MMC_GROUP + 4)

        #define ERROR_DDI_MMC_MEDIA_SEND_OP_TIMEOUT                      (ERROR_DDI_MMC_GROUP + 5)

        #define ERROR_DDI_MMC_MEDIA_READ_OCR_FAILED                      (ERROR_DDI_MMC_GROUP + 6)

        #define ERROR_DDI_MMC_MEDIA_UNSUPPORTED_OCR_VOLTAGES             (ERROR_DDI_MMC_GROUP + 7)

        #define ERROR_DDI_MMC_MEDIA_READ_CSD_FAILED                      (ERROR_DDI_MMC_GROUP + 8)

        #define ERROR_DDI_MMC_MEDIA_INVALID_CSD_VERSION                  (ERROR_DDI_MMC_GROUP + 9)

        #define ERROR_DDI_MMC_MEDIA_READ_CID_FAILED                      (ERROR_DDI_MMC_GROUP + 10)

        #define ERROR_DDI_MMC_MEDIA_INVALID_CID                          (ERROR_DDI_MMC_GROUP + 11)

        #define ERROR_DDI_MMC_MEDIA_SPEC_VERSION_NOT_SUPPORTED           (ERROR_DDI_MMC_GROUP + 12)

        #define ERROR_DDI_MMC_MEDIA_NOT_FORMATTED                        (ERROR_DDI_MMC_GROUP + 13)

        #define ERROR_DDI_MMC_MEDIA_NOT_ENUMERATED                       (ERROR_DDI_MMC_GROUP + 14)

        #define ERROR_DDI_MMC_MEDIA_ERASE_FAILED                         (ERROR_DDI_MMC_GROUP + 15)

        #define ERROR_DDI_MMC_READ_SECTOR_FAIL                           (ERROR_DDI_MMC_GROUP + 16)

        //! \brief [0xf0221011] Partition table signature mismatch.
        #define ERROR_DDI_MMC_CONFIG_BLOCK_NOT_FOUND                     (ERROR_DDI_MMC_GROUP + 17)

        #define ERROR_DDI_MMC_DATA_DRIVE_WRITE_SECTOR_FAIL               (ERROR_DDI_MMC_GROUP + 18)

        #define ERROR_DDI_MMC_DATA_DRIVE_SEQUENTIAL_END_FAIL             (ERROR_DDI_MMC_GROUP + 19)

        #define ERROR_DDI_MMC_DATA_DRIVE_INVALID_SECTOR                  (ERROR_DDI_MMC_GROUP + 20)

        #define ERROR_DDI_MMC_DATA_DRIVE_READ_SECTOR_FAIL                (ERROR_DDI_MMC_GROUP + 21)

        #define ERROR_DDI_MMC_DATA_DRIVE_SEQUENTIAL_FIRST_FAIL           (ERROR_DDI_MMC_GROUP + 22)

        #define ERROR_DDI_MMC_DATA_DRIVE_SEQUENTIAL_NEXT_FAIL            (ERROR_DDI_MMC_GROUP + 23)

        #define ERROR_DDI_MMC_DATA_DRIVE_WRITE_PROTECTED                 (ERROR_DDI_MMC_GROUP + 24)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_WRITE_SECTOR_FAIL             (ERROR_DDI_MMC_GROUP + 25)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_SEQUENTIAL_END_FAIL           (ERROR_DDI_MMC_GROUP + 26)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_INVALID_SECTOR                (ERROR_DDI_MMC_GROUP + 27)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_READ_SECTOR_FAIL              (ERROR_DDI_MMC_GROUP + 28)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_SEQUENTIAL_FIRST_FAIL         (ERROR_DDI_MMC_GROUP + 29)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_SEQUENTIAL_NEXT_FAIL          (ERROR_DDI_MMC_GROUP + 30)

        #define ERROR_DDI_MMC_SYSTEM_DRIVE_WRITE_PROTECTED               (ERROR_DDI_MMC_GROUP + 31)

        #define ERROR_DDI_MMC_LMEDIA_NO_REGIONS_IN_MEDIA                 (ERROR_DDI_MMC_GROUP + 32)

        #define ERROR_DDI_MMC_LMEDIA_DRIVES_MAX_OUT                      (ERROR_DDI_MMC_GROUP + 33)
    //@}

//! @}

#endif//_DDI_MEDIA_ERRORDEFS_H 



