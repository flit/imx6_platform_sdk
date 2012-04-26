//! \addtogroup os_file
//! @{
// Copyright (c) 2004-2005 SigmaTel, Inc.
//
//! \file fs_steering_read.c
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

// Array of fuction pointers for the redirection of Fread.  There should
// be one entry in the array for each FsType_t enum value and a NULL entry
// to terminate the array.
Fread_t const pRedirectFread[FS_TYPE_MAX+1] = {
    Fread_FAT,          // For FAT handles
    os_resource_Read,    // For resource handles
    // Future       // Add more file system redirection functions here when needed
    NULL            // For steering of invalid handles
};

//                  
//! \brief Redirects an Fread request
//!                  
//! \fntype Function                  
//!                  
//! Redirects an Fread request to the appropriate handler based on the
//! specified file handle.
//!                  
//! \param[in]  handleNumber   Handle of the file to read from
//! \param[out] pBuffer        Buffer in which the data to be read is placed
//! \param[in]  numBytesToRead Number of bytes to read from the file
//!                  
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//! \retval RtStatus_t If the steering function encountered an error
//! \retval Number of bytes read if the steering function was successful
//!                  
//                  
int32_t Fread( int32_t handleNumber, uint8_t *pBuffer, int32_t numBytesToRead )
{
    int32_t result = ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION;
    FsType_t type;
    Fread_t function;
    
    ddi_ldl_push_media_task((const char *)__builtin_return_address(0));
    ddi_ldl_push_media_task("Fread");

    // Determine filesystem type
    type = FileSystemType( handleNumber );
    // Get steering function
    function = pRedirectFread[type];

    // Is steering function defined for this type
    if( function != NULL )
    {
        // Call steering function
        result = function( handleNumber, pBuffer, numBytesToRead );
    }
    
    ddi_ldl_pop_media_task();
    ddi_ldl_pop_media_task();

    return result;
}

//! @}

