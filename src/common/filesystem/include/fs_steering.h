//! \addtogroup os_file
//! @{
// Copyright (c) 2004-2005 SigmaTel, Inc.
//
//! \file fs_steering.h
//! \brief Filesystem steering support
//! \version 1.0
//! \date June-2005
//! 
//! Prototypes, enumerations and defines for filesystem steering support.
//!                     
//! \see Implementations in fs_steering.c
//                     
                     
#ifndef _FS_STEERING_H
#define _FS_STEERING_H

#include "os/filesystem/fsapi.h"
#include "os/filesystem/resource/src/os_resource_internal.h"

// Minimum and maximum file handles for FAT file system
#define FAT_HANDLE_MIN      (0x00000000)
#define FAT_HANDLE_MAX      (0x000000FF)
// Minimum and maximum file handles for resource file system
#define RESOURCE_HANDLE_MIN (0x00000100)
#define RESOURCE_HANDLE_MAX (0x000001FF)
// Add more file system specific handle min and max values here when needed

//! Pointer to Fclose-type function
typedef RtStatus_t (*Fclose_t)( int32_t );

//! Pointer to Fread-type function
typedef int32_t (*Fread_t)( int32_t, uint8_t*, int32_t );

//! Pointer to Fwrite-type function
typedef int32_t (*Fwrite_t)( int32_t, uint8_t*, int32_t );

//! Pointer to Fseek-type function
typedef RtStatus_t (*Fseek_t)( int32_t, int32_t, int32_t );

//! Various filesystem types
typedef enum FsType
{
    FS_TYPE_FAT = 0,
    FS_TYPE_RESOURCE = 1,
    // Add more file system types here when needed
    FS_TYPE_MAX
} FsType_t;

// Function to return the filesystem type enum based on the handle
FsType_t FileSystemType( int32_t handleNumber );

// Function to redirect Fclose
RtStatus_t Fclose( int32_t handleNumber );

// Function to redirect Fread
int32_t Fread( int32_t handleNumber,
                                 uint8_t *pBuffer,
                                 int32_t numBytesToRead );
                         
// Function to redirect Fwrite
int32_t Fwrite( int32_t handleNumber,
                                  uint8_t *pBuffer,
                                  int32_t numBytesToWrite );
                                  
// Function to redirect Fseek
RtStatus_t Fseek( int32_t handleNumber,
                                    int32_t numBytesToSeek,
                                    int32_t seekPosition );

#endif // _FS_STEERING_H
//! @}

