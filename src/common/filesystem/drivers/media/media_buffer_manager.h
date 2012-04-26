///////////////////////////////////////////////////////////////////////////////
// Copyright (c) SigmaTel, Inc. All rights reserved.
// 
// SigmaTel, Inc.
// Proprietary & Confidential
// 
// This source code and the algorithms implemented therein constitute
// confidential information and may comprise trade secrets of SigmaTel, Inc.
// or its associates, and any use thereof is subject to the terms and
// conditions of the Confidential Disclosure Agreement pursual to which this
// source code was originally received.
///////////////////////////////////////////////////////////////////////////////
//! \defgroup media_buf_mgr Media Buffer Manager
//! \ingroup ddi_media
//! \brief Manages shared buffers for media drivers.
//!
//! \section intro Introduction
//!
//! The media buffer manager allows media drivers and related code to share a
//! set of common buffers, which is much more memory efficient than each code
//! module having its own buffers. It can work with both permanent, pre-allocated
//! buffers as well as temporary buffers it dynamically allocates itself. The
//! application can add any number of permanent buffers, thus controlling the
//! tradeoff between performance and memory. This also allows the application to
//! handle situations such as when NCNB memory cannot be allocated at runtime.
//!
//! The buffers under control of the buffer manager have several attributes.
//! The first is their type. Instead of specifying buffers by a size in
//! bytes, an enumerated list of types is used. This allows the caller to
//! pass along extra semantic information about the purpose of the buffer.
//! Currently this is only useful for programmers reviewing the code, but
//! it could potentially be put to other purposes in the future.
//!
//! The two types of buffers currently supported are:
//!     - #kMediaBufferType_Sector: A buffer at least as large as
//!          the page size of the currently attached NAND device.
//!     - #kMediaBufferType_Auxiliary: A buffer large enough to
//!         hold the auxiliary data required by the ECC8 engine.
//!
//! In addition to a type, each buffer has a set of flags. The only flags
//! that are implemented now are as follows:
//!     - #kMediaBufferFlag_NCNB: The buffer is located in non-cacheable,
//!         non-bufferable memory.
//!     - #kMediaBufferFlag_FastMemory: The buffer is within "fast"
//!         memory, usually OCRAM.
//!
//! \section usage Using the APIs
//!
//! In order for the buffer manager to be used, it must first be initialised.
//! This is done with a call to media_buffer_init(), which takes no parameters.
//! A set of buffers is pre-allocated by the manager so that it is immediately
//! usable. If you wish to add additional buffers, see the media_buffer_add() API.
//!
//! To get a buffer to use, a driver will call media_buffer_acquire(). It provides
//! information about the buffer it needs, including the type and a set of
//! desired flags. The buffer manager will make an attempt to
//! match the specifications exactly, but if that is not possible it will
//! try to find a close match amongst the available buffers already under
//! its control. Only as a last resort will it allocate memory using the
//! malloc() and specialised related functions from the DMI API (used to
//! allocate memory with special conditions such as NCNB). Wherever the buffer
//! comes from, it will always match the requested flags. However, a larger
//! buffer may be used for a small request
//!
//! These allocated buffers are called temporary buffers due to the fact that
//! they are deallocated when the caller is finished with them. Buffers added
//! with the buffer_add() API are called permanent buffers.
//!
//! The caller can use the buffer it acquired for as long as it likes, and
//! can hold any number of buffers at once. When finished, a call to
//! media_buffer_release() puts the buffer back under control of the buffer manager
//! and makes it available for other callers to use.
//!
//! If the buffer being released is a temporary buffer, it is returned to the
//! manager just like permanent buffers, but only for a short time. If the
//! buffer is still unused after this time expires, it is completely deallocated.
//! Reacquiring a temporary buffer waiting to expire will restart the process.
//! This mechanism keeps from repeatedly allocating and freeing buffers during
//! bursts of activity, while allowing efficient use of memory during idle time.
//!
//! @{
//! \file media_buffer_manager.h
//! \brief Public API to manage shared buffers for media code.
///////////////////////////////////////////////////////////////////////////////

#if !defined(_media_buffer_manager_h_)
#define _media_buffer_manager_h_

///////////////////////////////////////////////////////////////////////////////
// Includes
///////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "errordefs.h"
//#include "hw/core/vmemory.h"

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

//! \name Buffer type
//@{

//! \brief Classes of buffers supported by the media buffer manager.
//!
//! Each buffer type has an associated size that may vary depending upon
//! runtime conditions. These types are used to request buffers instead of
//! exact sizes because the type carries additional semantic content that
//! may be useful.
typedef enum _media_buffer_type {
    //! A buffer at least as large as the maximum sector size supported
    //! by the system.
    kMediaBufferType_Sector = 0,
    
    //! Buffer at least big enough to hold the auxiliary buffer required
    //! by the ECC8 engine for the largest supported NAND page size.
    kMediaBufferType_Auxiliary,
    
    //! A buffer large enough to hold a full NAND page, including metadata.
    kMediaBufferType_NANDPage,
    
    //! Number of buffer types.
    kMediaBufferType_Count
} MediaBufferType_t;

//@}

//! \name Flags
//@{

//! \brief Optional flags for use with media_buffer_acquire().
enum _media_buffer_acquire_flags
{
    kMediaBufferFlag_None = 0,          //!< No flags are set.
    kMediaBufferFlag_NCNB = (1 << 0),   //!< Buffer must be in non-cached, non-bufferable memory.
    kMediaBufferFlag_FastMemory = (1 << 1)     //!< Buffer resides in fast memory.
};

//@}

//! \name Properties
//@{

//! \brief Available properties of buffers.
//!
//! These properties can be accessed with the media_buffer_get_property() API or its templated
//! variants. Just pass one of the property selectors to the API and provide appropriate
//! storage for the result value. The documentation for each of the property selectors includes
//! the data type of the property's value.
#ifdef __UNUSED__
enum _media_buffer_properties
{
    //! \brief The buffer's size in bytes. \em [uint32_t]
    kMediaBufferProperty_Size = 'bsiz',
    
    //! \brief The original type of the buffer. \em [MediaBufferType_t]
    kMediaBufferProperty_Type = 'btyp',
    
    //! \brief The buffer's set of flags set when the buffer was added. \em [uint32_t]
    kMediaBufferProperty_Flags = 'bflg',
    
    //! \brief Whether the buffer is temporary or permanent. \em [bool]
    //! \retval true The buffer is temporary. You can get the #kMediaBufferProperty_Timeout
    //!     property to see when the buffer will expire.
    //! \retval false The buffer is permanent.
    kMediaBufferProperty_IsTemporary = 'btmp',
    
    //! \brief Whether the buffer is currently owned by a client. [bool]
    kMediaBufferProperty_IsInUse = 'binu',
    
    //! \brief Number of references to the buffer. [uint32_t]
    //!
    //! If the buffer is not currently in use, the reference count will always be zero.
    kMediaBufferProperty_ReferenceCount = 'ret#',
    
    //! \brief Timeout when the buffer will expire. \em [uint32_t]
    //!
    //! This property only applies to temporary buffers that are not currently in use. It's value
    //! is the absolute time in system ticks when the buffer will expire, assuming it is not
    //! acquired before then. If the buffer is not temporary, then the result will be -1
    //! (0xffffffff). If the buffer is temporary but currently in use by someone, the result will
    //! be zero.
    kMediaBufferProperty_Timeout = 'btmo'
};
#endif // __UNUSED__
//@}

///////////////////////////////////////////////////////////////////////////////
// Prototypes
///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

//! \brief Initialise the buffer manager.
//!
//! Aside from preparing the buffer manager's global context, this function
//! will one auxiliary buffer to start with. This initial buffer is specified
//! as non-cacheable, non-bufferable (NCNB) and has the appropriate flag set.
//! It is not specifically placed in fast memory.
//!
//! \retval SUCCESS The buffer manager was initialised without error.
//! \retval ERROR_OS_KERNEL_TX_CALLER_ERROR This function was called from an
//!     invalid execution context. It must only be called from a thread.
RtStatus_t media_buffer_init(void);

//! \brief Makes a new buffer available for use by buffer manager clients.
//!
//! Immediately after a successful return, the buffer passed into this function
//! may be returned from a call to media_buffer_acquire(). There is no way to free or 
//! remove the buffer once it is handed to the buffer manager. The presumption
//! is that the buffer remain available until the running program stops
//! execution.
//!
//! \param[in] bufferType Which size class this buffer is.
//! \param[in] bufferFlags Flags that apply to this buffer.
//! \param[in] buffer Pointer to the buffer itself. Should be word aligned.
//!
//! \retval SUCCESS The new buffer was added.
//! \retval ERROR_DDI_MEDIABUFMGR_NO_ROOM There is no room to add another buffer.
RtStatus_t media_buffer_add(MediaBufferType_t bufferType, uint32_t bufferFlags, SECTOR_BUFFER * buffer);

//! \brief Obtain a free buffer of the requested type.
//!
//! Clients call this function to get a buffer that they can use for any length
//! of time. The parameters specify the desired attributes of the buffer,
//! including its type. The buffer manager first makes an attempt to find a
//! pre-existing buffer that exactly matches the requested attributes. If that
//! fails, further attempts are made, looking for a buffer that is as close a
//! match as possible.
//!
//! Flags take precedence over size. In other words, given a choice between
//! buffer "A" that matches required flags but is larger, and
//! buffer "B" that is an exact size match but doesn't match all of the
//! flags, the buffer manager will choose buffer "A".
//!
//! In the case where no pre-existing buffers are available that match, this
//! function will allocate a temporary buffer from dynamic memory. The
//! allocated buffer will match both required and optional flags. For example,
//! if NCNB is required and fast memory is optional, a temporary buffer will be
//! allocated with both NCNB and fast memory.
//!
//! \param[in] bufferType Requested size of the buffer.
//! \param[in] requiredFlags Flags that must be set on the returned buffer.
//! \param[out] buffer On successful return, this parameter will hold the
//!     buffer's address.
//!
//! \retval SUCCESS A free buffer was returned in the \a buffer parameter.
//! \retval ERROR_DDI_MEDIABUFMGR_NO_ROOM Allocating a new temporary buffer was
//!     required in order to service the request, but there is no room to add
//!     another buffer.
//! \retval ERROR_DDI_MEDIABUFMGR_ALLOC_FAILED The buffer manager was unable to
//!     allocate a new temporary buffer for some reason.
RtStatus_t media_buffer_acquire(MediaBufferType_t bufferType, uint32_t requiredFlags, SECTOR_BUFFER ** buffer);

//! \brief Add a reference to an already acquired buffer.
//!
//! This API lets a caller add a reference to a buffer that has previously been
//! returned from media_buffer_acquire(), probably by another piece of code.
//! When the caller is done with the buffer, they can call media_buffer_release()
//! just like normal. Only when the reference count for the buffer falls to
//! zero will it actually be released.
RtStatus_t media_buffer_retain(SECTOR_BUFFER * buffer);

//! \brief Return a previously acquired buffer to the buffer manager's control.
//!
//! The reference count for the provided buffer is decremented by one. Only when
//! this count reaches zero will the buffer actually be released. The type of buffer,
//! either permanent or temporary, determines what happens when the buffer is
//! released.
//!
//! Permanent buffers that are released are made immediately available to other
//! callers, as soon as this function returns.
//!
//! Temporary buffers are not immediately deallocated. They become available
//! for other callers for a limited amount of time, currently 200 ms. If not
//! re-acquired during that time, the temporary buffer is freed for good.
//! However, if the buffer is used again before the timeout expires then the
//! process starts over again when it is next released.
//!
//! \param[in] buffer Pointer to the buffer to release. This buffer must have
//!     been previously obtained by a call to buffer_acquire().
//!
//! \retval SUCCESS The buffer is now available for other use.
//! \retval ERROR_DDI_MEDIABUFMGR_INVALID_BUFFER The buffer passed into this
//!     function was not obtained from the buffer manager, or something
//!     serious has gone wrong.
RtStatus_t media_buffer_release(SECTOR_BUFFER * buffer);

//! \brief Reads an arbitrary property of a buffer.
//!
//! \retval SUCCESS
RtStatus_t media_buffer_get_property(SECTOR_BUFFER * buffer, uint32_t whichProperty, void * value);

#ifdef __cplusplus
}

//! \brief Handy template form of media_buffer_get_property().
template <typename T>
T media_buffer_get_property(SECTOR_BUFFER * buffer, uint32_t whichProperty, RtStatus_t * status=0) __INIT_TEXT
{
    T value = 0;
    RtStatus_t localStatus = media_buffer_get_property(buffer, whichProperty, &value);
    if (status)
    {
        *status = localStatus;
    }
    return value;
}

#endif

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////

#endif // _media_buffer_manager_h_
//! @}


