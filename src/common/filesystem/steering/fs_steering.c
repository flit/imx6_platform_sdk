//! \addtogroup os_file
//! @{
// Copyright (c) 2004-2005 SigmaTel, Inc.
//
//! \file fs_steering.c
//! \brief Filesystem steering support
//! \version 1.0
//! \date June-2005
//! 
//! Implementation of functions which support filesystem steering.
//! The SDK assigns file handles of different values depending on the type
//! of filesystem being used.  The steering mechanism looks at the value
//! of the file handle and redirects the call to the appropriate handler.
//! The handlers for each handle type are defined in an array of function
//! pointers (one array for each filesystem call to be redirected.)
//!
//! Currently, the following functions can be steered:
//!   Fclose, Fread, Fwrite, Fseek
//! Their associated steering calls are:
//!   RedirectFclose, RedirectFread, RedirectFwrite, RedirectFseek
//!
//! Steering function may be called directly.  Because there is existing
//! code which calls the non-steered versions (Fclose, Fread, etc,) the
//! non-steered functions' implementations have been modified to call
//! the steering functions if the file handle warrants.
//! 
//! \see Declarations in fs_steering.h
//! \see Fclose, Fread, Fwrite, Fseek

#include "fs_steering.h"
#include "arm_ghs.h"

// Array of fuction pointers for the redirection of Fclose.  There should
// be one entry in the array for each FsType_t enum value and a NULL entry
// to terminate the array.
Fclose_t const pRedirectFclose[FS_TYPE_MAX+1] = {
    Fclose_FAT,         // For FAT handles
    os_resource_Close,   // For resource handles
    // Future       // Add more file system redirection functions here when needed
    NULL            // For steering of invalid handles
};

// Array of fuction pointers for the redirection of Fwrite.  There should
// be one entry in the array for each FsType_t enum value and a NULL entry
// to terminate the array.
Fwrite_t const pRedirectFwrite[FS_TYPE_MAX+1] = {
    Fwrite_FAT,         // For FAT handles
    NULL,           // Fwrite not supported for resources
    // Future       // Add more file system redirection functions here when needed
    NULL            // For steering of invalid handles
};

// Array of fuction pointers for the redirection of Fseek.  There should
// be one entry in the array for each FsType_t enum value and a NULL entry
// to terminate the array.
Fseek_t const pRedirectFseek[FS_TYPE_MAX+1] = {
    Fseek_FAT,          // For FAT handles
    os_resource_Seek,    // For resource handles
    // Future       // Add more file system redirection functions here when needed
    NULL            // For steering of invalid handles
};

//                  
//! \brief Redirects an Fclose request
//!                  
//! \fntype Function                  
//!                  
//! Redirects an Fclose request to the appropriate handler based on the
//! specified file handle.
//!                  
//! \param[in]  handleNumber Handle of the file to close
//!                  
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//! \retval The return value of the steering function
//                  
RtStatus_t Fclose( int32_t handleNumber )
{
    RtStatus_t result = ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION;
    FsType_t type;
    Fclose_t function;

    // Determine filesystem type
    type = FileSystemType( handleNumber );
    // Get steering function
    function = pRedirectFclose[type];

    // Is steering function defined for this type
    if( function != NULL )
    {
        // Call steering function
        result = function( handleNumber );
    }

    return result;
}

//                  
//! \brief Redirects an Fwrite request
//!                  
//! \fntype Function                  
//!                  
//! Redirects an Fwrite request to the appropriate handler based on the
//! specified file handle.
//!                  
//! \param[in]  handleNumber   Handle of the file to write to
//! \param[in]  pBuffer        Buffer holding the data to be written
//! \param[in]  numBytesToWrite Number of bytes to write to the file
//!                  
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//! \retval RtStatus_t If the steering function encountered an error
//! \retval Number of bytes written if the steering function was successful
//!                  
//                  
int32_t Fwrite( int32_t handleNumber, uint8_t *pBuffer, int32_t numBytesToWrite )
{
    int32_t result = ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION;
    FsType_t type;
    Fwrite_t function;

    ddi_ldl_push_media_task((const char *)__builtin_return_address(0));
    ddi_ldl_push_media_task("Fwrite");

    // Determine filesystem type
    type = FileSystemType( handleNumber );
    // Get steering function
    function = pRedirectFwrite[type];

    // Is steering function defined for this type
    if( function != NULL )
    {
        // Call steering function
        result = function( handleNumber, pBuffer, numBytesToWrite );
    }
    
    ddi_ldl_pop_media_task();
    ddi_ldl_pop_media_task();

    return result;
}

//                  
//! \brief Redirects an Fseek request
//!                  
//! \fntype Function                  
//!                  
//! Redirects an Fseek request to the appropriate handler based on the
//! specified file handle.
//!                  
//! \param[in]  handleNumber   Handle of the file to seek
//! \param[in]  numBytesToSeek Relative number of bytes to seek
//! \param[in]  seekPosition   Value indicating where to seek from
//!                  
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//! \retval RtStatus_t The return value of the steering function
//                  
RtStatus_t Fseek( int32_t handleNumber, int32_t numBytesToSeek, int32_t seekPosition )
{
    RtStatus_t result = ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION;
    FsType_t type;
    Fseek_t function;

    // Determine filesystem type
    type = FileSystemType( handleNumber );
    // Get steering function
    function = pRedirectFseek[type];

    // Is steering function defined for this type
    if( function != NULL )
    {
        // Call steering function
        result = function( handleNumber, numBytesToSeek, seekPosition );
    }

    return result;
}

//! @}

