/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#if !defined(__bch_ecc_h__)
#define __bch_ecc_h__

#include <stdint.h>
#include <stdbool.h>

//! @addtogroup bch
//! @{

//! @file bch_ecc.h
//! @brief Declarations for the BCH ECC engine driver.

//! @brief Options for the BCH Galois field size.
//!
//! The values of these enums are also the number of bits of parity data required per bit of
//! ECC correction, for each payload. For instance, when using #kGaloisField_13bit with 24-bit
//! correction, there will be 13 * 24 = 312 bit of parity data per payload.
typedef enum _bch_galois_field {
    kGaloisField_13bit = 13, //!< Galois field size of 2<super>13</super>.
    kGaloisField_14bit = 14  //!< Galois field size of 2<super>14</super>.
} bch_galois_field_t;

//! @brief The minimum and maximum BCH ECC levels.
enum _bch_levels
{
    kMinBchLevel = 2,   //!< Minimum BCH ECC level is 2 bits per payload.
    kMaxBchLevel = 40   //!< Maximum BCH ECC level is 40 bits per payload.
};

//! @brief Buffer mask values for BCH.
//!
//! The BCH engine supports two options for transferring page data. The most common option is
//! to simply read or write the entire page. But in order to support fast reading of a page's
//! metadata (auxiliary area), there is an option to read only block 0 as defined in the BCH
//! page layout (see #BchEccLayout). 
enum _bch_buffer_masks
{
    kBchBufferMask_AuxOnly = 0x100, //!< Read of only block 0. This option cannot be used for writes.
    kBchBufferMask_Page = 0x1ff     //!< Read or write the entire page.
};

/*!
 * @brief BCH page layout parameters
 *
 * This structure contains all the information required to describe an ECC configuration for
 * the BCH ECC engine.
 *
 * The size of the Galois field (2<super>13</super> or 2<super>14</super>) for block 0 and block
 * N is determined by the block0GaloisField and blockNGaloisField members. The Galois field size
 * sets the maximum number of bytes that can be protected in one ECC block. It also determines
 * how many bits per ECC level of parity data are required. For each block, the parity data will
 * be the Galois field size (13 or 14) times the ECC level number of bits. For example, if
 * blockNGaloisField is #kGaloisField_14bit and blockNLevel is 24, then each block N will require
 * 14 * 24 = 336 bits = 42 bytes of parity data.
 *
 * The fullPageSize member should be set to the total number of bytes in the NAND page, including
 * the redundant area. If this value is larger than the size computed by adding up each of the
 * blocks and their parity data, plus the metadata, then the BCH block will pad the page with
 * zero bits when writing (encoding).
 */
typedef struct BchEccLayout {
    uint16_t fullPageSize;  //!< Size in bytes of the entire NAND page.
    bch_galois_field_t block0GaloisField;   //!< Block 0 Galois field size.
    uint16_t block0Level;   //!< Block 0 ECC level (0-40).
    uint16_t block0Size;    //!< Block 0 data size. If this is 0, then block 0 contains only metadata.
    uint16_t metadataSize;  //!< Number of meta data bytes.
    bch_galois_field_t blockNGaloisField;   //!< Block N Galois field size.
    uint16_t blockNLevel;   //!< Block N ECC level (0-40).
    uint16_t blockNSize;    //!< Block N data size.
    uint16_t blockNCount;   //!< Number of ECC blocks not including block 0.
} BchEccLayout_t;

enum _ecc_correction_constants
{
    //! Maximum number of payloads supported by all ECC engines.
    kMaxPayloadCount = 16,
    
    //! Sentinel value used to indicate that an ECC payload had too many errors to correct.
    kUncorrectable = 0xffffffff,
    
    //! Sentinel value that indicates that a payload contained all ones.
    kAllOnes = 0xfffffffe
};
    
/*!
 * @brief ECC correction information.
 */
typedef struct BchEccCorrectionInfo {
    unsigned maxCorrections;        //!< Overall maximum number of corrections for all payloads and the metadata.
    unsigned payloadCount;          //!< Number of valid entries in \a payloadCorrections.
    bool isMetadataValid;           //!< True if \a metadataCorrections contains valid data.
    unsigned metadataCorrections;   //!< Number of bit errors in the metadata, or #kUncorrectable.
    unsigned payloadCorrections[kMaxPayloadCount];    //!< Number of bit errors for each payload, or #kUncorrectable.
} BchEccCorrectionInfo_t;

#if defined(__cplusplus)
exten "C" {
#endif // __cplusplus

//! \name BCH API
//@{

////////////////////////////////////////////////////////////////////////////////
//! \brief Initializes BCH driver.
//!
//! Performs BCH driver initialization.
//! 1. Removes BCH reset, ungates BCH clock, and resets BCH DMA channel.
//! 2. Initializes physical address pointers and links the DMA chain if needed.
//!
//! \pre  ppEccDmaCmds = NULL if DMA chains have not been linked
//! \post HWECC is ready to start new computation
//! \post ppEccDmaCmds and ppEccResults are initialized
//! \post DMA chains in eccDmaCmds are linked
////////////////////////////////////////////////////////////////////////////////
void bch_init();

////////////////////////////////////////////////////////////////////////////////
//! \brief Enable the BCH block.
//!
//! This function enables the BCH block.
////////////////////////////////////////////////////////////////////////////////
void bch_enable(void);

////////////////////////////////////////////////////////////////////////////////
//! \brief Disable the BCH block.
//!
//! This function disables the BCH block.
////////////////////////////////////////////////////////////////////////////////
void bch_disable(void);

////////////////////////////////////////////////////////////////////////////////
//! \brief Updates the BCH erase threshold value.
//!
//! @param threshold The new erase threshold number. This is the maximum number
//!     of bits that can be set to zero in a page for the page to be considered
//!     erased. For most SLC NANDs, this value should be set to 0.
////////////////////////////////////////////////////////////////////////////////
void bch_set_erase_threshold(unsigned threshold);

////////////////////////////////////////////////////////////////////////////////
//! \brief Sets the BCH Flash Layout registers.
//!
//! \param[in] u32NandDeviceNumber NAND device number.
//! \param[in] pEccDescriptor ECC Descriptor.
//! \param[in] bTransfer2k TRUE to transfer only 2k, otherwise transfer full page.
////////////////////////////////////////////////////////////////////////////////
void bch_set_layout(uint32_t u32NandDeviceNumber, const BchEccLayout_t * ecc);

////////////////////////////////////////////////////////////////////////////////
//! \brief Determines the highest BCH ECC level that will fit in a page.
//!
//! Given a page with a certain data and metadata size, this function will
//! compute the highest level of BCH ECC that will fit. It assumes that there
//! will be 10 bytes of user metadata not reserved for ECC parity, and that
//! the block size will always be 512 bytes.
//!
//! \param pageDataSize Number of bytes for data in the page.
//! \param pageMetadataSize Number of bytes for user metadata and ECC parity.
//! \param[out] resultEcc ECC descriptor filled in with the BCH ECC of
//!     the highest level that will fit in the page.
//! \retval SUCCESS The \a resultEcc parameter has been filled in.
//! \retval ERROR_GENERIC There is not enough room in the page for any ECC.
////////////////////////////////////////////////////////////////////////////////
int bch_calculate_best_level(uint32_t pageDataSize, uint32_t pageMetadataSize, BchEccLayout_t * resultEcc);

////////////////////////////////////////////////////////////////////////////////
//! \brief Clear the ECC Complete IRQ flag.
//!
//! This function clears the ECC Complete flag.  This should be done before each
//! transaction that uses the ECC.
////////////////////////////////////////////////////////////////////////////////
void bch_clear_complete_irq();

////////////////////////////////////////////////////////////////////////////////
//! \brief Read ECC correction results.
//!
//! The results of a BCH ECC correction operation are stored after the metadata
//! bytes in the metadata buffer. This function reads the correction results
//! and fills in the @a correctionInfo parameter appropriately.
//!
//! @param auxBuffer Pointer to the buffer containing the metadata and
//!     correction results filled in by the BCH block.
//! @param[out] correctionInfo Filled in with the results of the ECC correction
//!     operation.
////////////////////////////////////////////////////////////////////////////////
void bch_read_correction_status(const uint8_t * auxBuffer, BchEccCorrectionInfo_t * correctionInfo);

////////////////////////////////////////////////////////////////////////////////
//! \brief Determines the GPMI buffer mask value to use.
//!
//! The GPMI register HW_GPMI_ECCCTRL has a BUFFER_MASK field that is used to
//! specify what part of the NAND page is being read or written. This function
//! will return the appropriate buffer mask value to use, given the number of
//! bytes being read or written and the BCH ECC layout description.
//!
//! @retval 
////////////////////////////////////////////////////////////////////////////////
uint16_t bch_get_buffer_mask(bool isWrite, uint32_t dataSize, const BchEccLayout_t * ecc);

//@}

#if defined(__cplusplus)
}
#endif // __cplusplus

//! @}

#endif // __bch_ecc_h__
// EOF
