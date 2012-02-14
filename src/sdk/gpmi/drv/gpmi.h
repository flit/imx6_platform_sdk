/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#if !defined(__gpmi_h_)
#define __gpmi_h_

/*!
 * @file gpmi.h
 * @brief The header file that contains the general definitions for NAND
 *
 * @ingroup diag_nand
 */

//! @addtogroup diag_nand
//! @{

#pragma pack(1)
//! @brief NAND timings for setting up the GPMI timing.
//!
//! This structure holds the timings for the NAND.  This data is used by
//! gpmi_set_timings() to setup the GPMI hardware registers.
typedef struct GpmiNandTimings
{
    //! @brief The data setup time (tDS), in nanoseconds.
    uint8_t tDS;

    //! @brief The data hold time (tDH), in nanoseconds.
    uint8_t tDH;

    //! @brief The address setup time (tSU), in nanoseconds.
    //!
    //! This value amalgamates the NAND parameters tCLS, tCS, and tALS.
    uint8_t tSU;

    //! @brief The data sample time, in nanoseconds.
    uint8_t dSampleTime;

    //! @brief From the NAND datasheet.
    uint8_t tREA;

    //! @brief From the NAND datasheet.
    //!
    //! This is the amount of time that the last contents of the data lines will persist
    //! after the controller drives the -RE signal true.
    //!
    //! EDO Mode: This time is from the NAND spec, and the persistence of data
    //! is determined by (tRLOH + tDH).
    //!
    //! Non-EDO Mode: This time is ignored, because the persistence of data
    //! is determined by tRHOH.
    uint8_t tRLOH;
    
    //! @brief From the NAND datasheet.
    //!
    //! This is the amount of time that the last contents of the data lines will persist after the
    //! controller drives the -RE signal false.
    //!
    //! EDO Mode: This time is ignored, because the persistence of data is determined by
    //! (tRLOH + tDH).
    //!
    //! Non-EDO Mode: This time is totally due to capacitive effects of the hardware. For reliable
    //! behavior it should be set to zero, unless there is specific knowledge of the trace
    //! capacitance and the persistence of the data values.
    uint8_t tRHOH;
} GpmiNandTimings_t;
#pragma pack()

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

//! \name Init and shutdown
//@{

////////////////////////////////////////////////////////////////////////////////
//! \brief Enable and initialize the GPMI driver.
//!
//! This function configures the GPMI block using the HW registers based upon
//! the desired chip and the number of bits. You must call this API for each
//! chip select that will be used in the application configuration.
//!
//! \param[in] bUse16BitData 0 for 8 bit, 1 for 16 bit NAND support.
//! \param[in] u32ChipNumber The zero-based \em index
//!     of the chip select to initialize.
//! \param[in] bUseAlternateChipEnables If TRUE, use the Alternate Chip Enables.
//! \param[in] bUse1_8V_Drive If TRUE, drive GPMI pins at 1.8V instead of 3.3V.
//! \param[in] bEnableInternalPullups If TRUE, will enable internal pullups.
//!
//! \return SUCCESS
//! \return ERROR_DDI_NAND_GPMI_NOT_PRESENT
//!
//! \todo Make this function truly take a number of NANDs so it only has to
//!     be called once.
//! \todo Get rid of bUseAlternateChipEnables parameter, and maybe bUse16BitData
//!     as well.
////////////////////////////////////////////////////////////////////////////////
int gpmi_init(unsigned chipSelectCount, uint32_t minDelay, uint32_t maxDelay);

////////////////////////////////////////////////////////////////////////////////
//! \brief Resets the GPMI block.
//!
//! A soft reset can take multiple clocks to complete, so do NOT gate the
//! clock when setting soft reset. The reset process will gate the clock
//! automatically. Poll until this has happened before subsequently
//! clearing soft reset and clock gate.
////////////////////////////////////////////////////////////////////////////////
void gpmi_soft_reset(void);

////////////////////////////////////////////////////////////////////////////////
//! \brief Disable the GPMI driver.
//!
//! This function gates the clock to the GPMI peripheral.
////////////////////////////////////////////////////////////////////////////////
void gpmi_disable(void);

//@}

//! \name Write enable
//@{

////////////////////////////////////////////////////////////////////////////////
//! \brief Enable writes via the Write Protect line of the NAND.
//!
//! Enable or disable writes via the /WP pin of the NAND.  This WP line is
//! shared amongst all the NANDs.
//!
//! \param[in] doEnable Enable writes (1) or Disable writes (0) (/WP pin)
////////////////////////////////////////////////////////////////////////////////
void gpmi_enable_writes(bool doEnable);

//@}

//! \name DMA Utilities
//@{

////////////////////////////////////////////////////////////////////////////////
//! \brief Start the appropriate DMA channel
//!
//! Starts a NAND DMA command on the channel associated with the chip select
//! in the \a wNANDDeviceNum parameter. Before the DMA is started, the region of memory
//! starting from \a pDmaCmd and running for \a dmaCommandLength bytes is flushed from
//! the data cache ("cleaned" in ARM parlance). However, if \a dmaCommandLength is set
//! to 0 instead of a valid length, then the data cache will not be flushed. This can
//! be useful in cases where the calling code has already flushed the entire cache.
//! The constant #kGpmiDontFlushCache is provided to help describe the length parameter
//! value.
//!
//! \param[in] pDmaCmd          Pointer to dma command structure. Must be the virtual address,
//!     as it is converted to a physical address before the DMA is started.
//! \param[in] dmaCommandLength Length in bytes of the DMA command chain pointed
//!                             to by \a pDmaCmd.
//! \param[in] u32NANDDeviceNum Which NAND should be started.
//! \param[in] u16DmaWaitMask   A bitmask used to indicate criteria for terminating the DMA.
//!                             See #GpmiDmaInfo_t::u16DmaWaitMask and #_nand_gpmi_dma_wait_mask.
//!
//! \retval SUCCESS The DMA is started.
//! \retval ERROR_DDI_NAND_GPMI_DMA_BUSY Another DMA is already running.
////////////////////////////////////////////////////////////////////////////////
int gpmi_run_dma(dma_cmd_t * theDma, unsigned chipSelect, uint16_t waitMask, uint32_t timeout);

////////////////////////////////////////////////////////////////////////////////
//! \brief Wait for DMA to complete.
//!
//! Waits for NAND DMA command chain corresponding to wNANDDeviceNum to complete.
//!
//! \param[in] u32usec Number of microseconds to wait before timing out. If
//!     zero is passed for the timeout, then this function will wait forever.
//! \param[in] u32NANDDeviceNum Which NAND should be polled.
//!
//! \retval SUCCESS DMA completed without an error.
//! \retval ERROR_DDI_NAND_GPMI_DMA_TIMEOUT DMA never completed or is still
//!     running. This value is returned explicitly from this function when
//!     the DMA semphore times out, and most DMA chains also return this
//!     error (see below for how) when the GPMI device busy timeout expires.
//!
//! \note Uses the BAR field of the last DMA command to signal                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
//!             result of the DMA chain.
////////////////////////////////////////////////////////////////////////////////
// int gpmi_wait_for_dma(uint32_t usec, uint32_t wNANDDeviceNum);

////////////////////////////////////////////////////////////////////////////////
//! \brief Returns a Boolean indicating if a DMA is currently running.
//!
//! \param u32NANDDeviceNum Specifies which DMA channel to inspect.
//! \retval true A DMA is currently running.
//! \retval false The DMA channel is free.
////////////////////////////////////////////////////////////////////////////////
bool gpmi_is_dma_active(uint32_t u32NANDDeviceNum);

//@}

//! \name Timing Control Functions
//@{

////////////////////////////////////////////////////////////////////////////////
//! \brief Fill the given timing structure with the safe timings.
//!
//! This function is used to get the timings characteristics that work with
//! every device we've ever known. These timings should be used during initialization
//! and device discovery. Once the device type is known,  timings specific to
//! that device should be set.  Remember to actually set the safe timings once
//! you get them by calling ddi_gpmi_set_timings().
//!
//! \param[out] timings The timings structure that will be set to the safe
//!     timings upon return.
////////////////////////////////////////////////////////////////////////////////
void gpmi_get_safe_timings(GpmiNandTimings_t * timings);

////////////////////////////////////////////////////////////////////////////////
//! \brief Set the flash timing for optimal NAND performance.
//!
//! Set the optimal NAND timings based upon the passed in NAND timings and the
//! current GPMI clock.
//!
//! \param[in] timings Pointer to timing table for the NAND.
//!
//! \retval SUCCESS Timings were set successfully.
//!
//! \warning This function assumes all NAND I/O is halted.
////////////////////////////////////////////////////////////////////////////////
int gpmi_set_timings(const GpmiNandTimings_t * timings);

////////////////////////////////////////////////////////////////////////////////
//! \brief Set the timeout value for wait for ready.
//!
//! The timeout value set here is used for the GPMI wait for ready mode. It
//! will have the most effect upon DMA operations.
//!
//! \param[in] busyTimeout Timeout value in microseconds.
////////////////////////////////////////////////////////////////////////////////
void gpmi_set_busy_timeout(uint32_t busyTimeout);

////////////////////////////////////////////////////////////////////////////////
//! \brief Returns the current GPMI timings values.
//!
//! \return A pointer to the current timing values used by the GPMI block.
//!     This will be the last set of timings passed to gpmi_set_timings().
////////////////////////////////////////////////////////////////////////////////
const GpmiNandTimings_t * gpmi_get_current_timings();

//@}

//! @name Common NAND operations
//!
//! These functions are used to perform the common set of NAND read and write operations. They
//! will build an appropriate DMA chain and execute it synchronously.
//@{

////////////////////////////////////////////////////////////////////////////////
//! @brief Reset the NAND.
////////////////////////////////////////////////////////////////////////////////
int nand_reset(unsigned chipSelect);

////////////////////////////////////////////////////////////////////////////////
//! @brief Read a NAND's ID.
////////////////////////////////////////////////////////////////////////////////
int nand_read_id(unsigned chipSelect, uint8_t * resultID);

////////////////////////////////////////////////////////////////////////////////
//! @brief Erase a block on a NAND.
////////////////////////////////////////////////////////////////////////////////
int nand_erase_block(unsigned chipSelect, uint32_t blockNumber);

////////////////////////////////////////////////////////////////////////////////
//! @brief Read a NAND page.
////////////////////////////////////////////////////////////////////////////////
int nand_read_page(unsigned chipSelect, uint32_t pageNumber, uint8_t * buffer, uint8_t * auxBuffer, const BchEccLayout_t * ecc);

////////////////////////////////////////////////////////////////////////////////
//! @brief Read the metadata from a NAND page.
////////////////////////////////////////////////////////////////////////////////
int nand_read_metadata(unsigned chipSelect, uint32_t pageNumber, uint8_t * buffer);

////////////////////////////////////////////////////////////////////////////////
//! @brief Write a NAND page.
////////////////////////////////////////////////////////////////////////////////
int nand_write_page(unsigned chipSelect, uint32_t pageNumber, const uint8_t * buffer, const uint8_t * auxBuffer, const BchEccLayout_t * ecc);

//@}

//! @}
#endif //__gpmi_h_
// EOF
