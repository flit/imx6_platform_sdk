//! \addtogroup os_file
//! @{
// Copyright (c) 2004-2007 SigmaTel, Inc.
//
//! \file fs_steering_utility.c
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

//                  
//! \brief Determines the FsType_t of a file handle
//!                  
//! \fntype Function                  
//!                  
//! Determines the FsType_t of the specified file handle and returns
//! it to the caller.
//!                  
//! \param[in]  handleNumber The file handle of interest      
//!                  
//! \retval FS_TYPE_FAT      If \c handleNumber is for the default filesystem
//! \retval FS_TYPE_RESOURCE If \c handleNumber is for the resource filesystem
//! \retval FS_TYPE_MAX      If \c handleNumber is of an unknown value
//!                  
//                  
FsType_t FileSystemType( int32_t handleNumber )
{
    // Is the handle within the range for FAT
    if( handleNumber >= FAT_HANDLE_MIN &&
        handleNumber <= FAT_HANDLE_MAX )
    {
        // Type is FAT
        return FS_TYPE_FAT;
    }
    // Is the handle within the range for resources
    else if( handleNumber >= RESOURCE_HANDLE_MIN &&
             handleNumber <= RESOURCE_HANDLE_MAX )
    {
        // Type is resource
        return FS_TYPE_RESOURCE;
    }
    // Indicate an error if we get here
    else
    {
        // Error
        return FS_TYPE_MAX;
    }
}

//! @}

