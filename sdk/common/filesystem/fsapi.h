/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_fat
//! @{
//!
//  Copyright (c) 2005-2008 SigmaTel, Inc.
//!
//! \file    fsapi.h
//! \brief   Contains the FAT file system public API. Supports FAT32 and FAT16.
//!
////////////////////////////////////////////////////////////////////////////////
#ifndef _FS_API_H
#define _FS_API_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "os_filesystem_errordefs.h"
#include <stdio.h>
#include "fsproj.h"
#include "drivers/media/ddi_media.h"

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

//! \brief Holds fast file handles for files that CheckDisk() deletes.
// extern uint64_t *g_CheckDiskFastFileHandles;
// //! \brief Holds the number of fast file handles that CheckDisk() deletes.
// extern uint8_t g_CheckDiskNumFastFileHandles;
// //! \brief Holds directories that CheckDisk() deletes.
// extern uint8_t g_CheckDiskAnyDirectoriesDeleted;
// 
// 
// // We'll remember up to this many fast file handles with
// // each fast file handle being 64 bits
// //! \brief Maximum number of 64-bit fast file handles stored.
// #define CHECKDISK_MAX_FAST_FILE_HANDLES   (32)
// 
// //! \brief Large buffers are allocated by DMI instead of stack.
// #define FS_USE_MALLOC

//! \brief TBD
#define SEEK_SET           	0
//! \brief TBD
#define SEEK_CUR            1
//! \brief TBD
#define SEEK_END            2

//! \brief TBD
#define INVALID_FILESYSTEM	      (WORD)(3)

#ifndef MAX_FILENAME_LENGTH
//! \brief TBD
#define MAX_FILENAME_LENGTH 256
#endif

#if defined(__cplusplus) && !defined(WIN32)
extern "C" {
#endif // __cplusplus

// Stmp00009401 :
// Function to determine if a file handle is NOT for the FAT
// filesystem (i.e. it should be redirected)
///////////////////////////////////////////////////////////////////////////////
//! \brief Determines if a file handle should be redirected                  
//!                  
//! \fntype Function                  
//!                  
//! Determines if the specified file handle has a value that indicates
//! that it should be redirected from the standard filesystem call to
//! an alternate implementation; i.e., the handle is not for the FAT file system.
//!                  
//! \param[in]  handleNumber The file handle of interest      
//!                  
//! \retval true  The \c handleNumber needs redirection
//! \retval false This \c handleNumber does not need redirection
//!                  
//!
//! \internal
//! \see To view the function definition, see fs_steering.c.
///////////////////////////////////////////////////////////////////////////////
bool RedirectCall( int32_t handleNumber );
///////////////////////////////////////////////////////////////////////////////
//! \brief Redirects an Fclose request
//!                  
//! \fntype Function                  
//!                  
//! Redirects an Fclose request to the appropriate handler based on the
//! specified file handle.
//!                  
//! \param[in]  handleNumber Handle of the file to close
//!         
//! \return Value of the steering function or an error.
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//!
//! \internal
//! \see To view the function definition, see fs_steering.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fclose( int32_t handleNumber );
///////////////////////////////////////////////////////////////////////////////
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
//! \return Number of bytes read if the steering function was successful or an RtStatus_t error.
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//!
//! \internal
//! \see To view the function definition, see fs_steering.c.
///////////////////////////////////////////////////////////////////////////////
int32_t Fread( int32_t handleNumber,
                                 uint8_t *pBuffer,
                                 int32_t numBytesToRead );                                 
                                 
///////////////////////////////////////////////////////////////////////////////
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
//! \return Number of bytes read if the steering function was successful or an RtStatus_t error.
//! \retval ERROR_OS_FILESYSTEM_NO_STEERING_FUNCTION If there is no steering function defined for \c filehandle
//!
//! \internal
//! \see To view the function definition, see fs_steering.c.
///////////////////////////////////////////////////////////////////////////////
int32_t Fwrite( int32_t handleNumber,
                                  uint8_t *pBuffer,
                                  int32_t numBytesToWrite );
                                                                   
///////////////////////////////////////////////////////////////////////////////
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
//! \internal
//! \see To view the function definition, see fs_steering.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fseek( int32_t handleNumber,
                                    int32_t numBytesToSeek,
                                    int32_t seekPosition );


////////////////////////////////////////////////////////////////////////////////
// STDIO API
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//!
//! \brief Fopen Opens a file for subsequent access.
//!
//! \param[in] filepath Pointer to a null-terminated ASCII string that contains the name of the file to open.
//!
//! \param[in] mode Null-terminated ASCII string that specifies how the file will be accessed. It must be one of the following:
//!
//!		-	"r"		=	open for reading only
//!		-	"r+"		=	same as "r", also allows writing
//!		-	"w"		=	open for writing only, file will be created if it does 
//!						not exist, and will be overwritten if it does exist
//!		-	"w+"		=	same as "w", also allows reading
//!		-	"a"		=	open for appending to end of file, upon opening
//!						file position is set to end-of-file
//!		-	"a+"		=	same as "a", also allows reading/writing
//!
//!
//!  \param[out] handle Returns an int32_t which uniquely identifies the file while it is open, and which must be
//!  used on all subsequent file system calls to access this file If this value is negative, then an error occurred.
//!
//!
//!  Long file name considerations
//!
//!    
//!  When creating a file (opening it with either "w" or "w+" modes) the
//!  FAT file system uses the following considerations to determine whether
//!  the file name will be stored on the media with a short name only (older
//!  style) or with both a short name and a long name.
//!
//! -	The file name is parsed into 2 parts, the part before the period (filespec) and the part after (extension)
//!
//! -	If more than one period is found during parsing, a long file name is created.
//!
//! -	If the filespec is more than 11 characters long a long file name is created.
//!
//! -	If the extension is more than 3 characters long a long file name is created
//!
//! -	If the filespec or the extension contains a space character or any one of +,;=[](plus-sign,comma,semi-colon,
//!		equal-sign,open-brace,close-brace) then a long file name is created.
//!
//! -	If a long file name is not used, the filepec and extension are converted 
//!		to upper case, and the resulting short file name is created.
//!
//!
//!  \internal
//
//   All of the checking listed above actually takes place in
//   the function 'IsShortNameValid()' (which is in 'isshortnamevalid.c')
//
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fopen(uint8_t *filepath, uint8_t *mode);

///////////////////////////////////////////////////////////////////////////////
//!
//! \brief Fopenw Opens a file for subsequent access.
//!
//! \param[in] filepath Pointer to a null-terminated UNICODE string that contains the name of the file to open.
//!
//! \param[in] mode Null-terminated ASCII string that specifies how the file will be accessed. It must be one of the following:
//!
//!		-	"r"		=	open for reading only
//!		-	"r+"		=	same as "r", also allows writing
//!		-	"w"		=	open for writing only, file will be created if it does 
//!						not exist, and will be overwritten if it does exist
//!		-	"w+"		=	same as "w", also allows reading
//!		-	"a"		=	open for appending to end of file, upon opening
//!						file position is set to end-of-file
//!		-	"a+"		=	same as "a", also allows reading/writing
//!
//!
//!  \param[out] handle Returns an int32_t which uniquely identifies the file while it is open, and which must be
//!  used on all subsequent file system calls to access this file If this value is negative, then an error occurred.
//!
//!
//!  Long file name considerations
//!
//!  Since the input filepath is in UNICODE, this function ALWAYS creates a long file name
//!
//
//
//
RtStatus_t Fopenw(uint8_t *filepath, uint8_t *mode);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fclose_FAT(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fgetc(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//! \param[in] ByteToWrite TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fputc(int32_t HandleNumber, int32_t ByteToWrite);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber  TBD
//! \param[in] Buffer        TBD
//! \param[in] NumBytes      TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
uint8_t *Fgets(int32_t HandleNumber, int32_t NumBytes, uint8_t *Buffer);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber    TBD
//! \param[in] Buffer          TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
uint8_t *Fputs(int32_t HandleNumber, uint8_t *Buffer);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber    TBD
//! \param[in] Buffer          TBD
//! \param[in] NumBytesToRead TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fread_FAT(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber    TBD
//! \param[in] Buffer          TBD
//! \param[in] NumBytesToWrite TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fwrite_FAT(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToWrite);

///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
int32_t Feof(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
int32_t Ftell(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
int32_t Ferror(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber   TBD
//! \param[in] NumBytesToSeek TBD
//! \param[in] SeekPosition   TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fseek_FAT(int32_t HandleNumber, int32_t NumBytesToSeek, int32_t SeekPosition);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fflush(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to the file.
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fremove(const uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to the file.
//!
//! \return Status of the call.
//! \retval TBD
//!
//! \note This function is a standard (stdio) library function.
//!
//! \todo [PUBS] Add definition(s).
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Fremovew(uint8_t *filepath);


////////////////////////////////////////////////////////////////////////////////
// Miscellaneous File System Prototypes
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//! \brief Initializes the file system.
//!
//! \fntype Non-reentrant 
//!
//! \param[in] bufx       Pointer to X buffer for allocation of cache buffers.
//! \param[in] bufy       Pointer to Y buffer for allocation of handles, descriptors, etc.
//! \param[in] maxdevices Max number of internal + external media supported.
//! \param[in] maxhandles Max handles supported.
//! \param[in] maxcaches  Max cache buffers supported.
//!
//! \return Status of the call.
//! \retval 0 If the call was successful.
//!
//! \internal
//! \see To view the function definition, see fsinit.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t FSInit(uint8_t *bufx, uint8_t *bufy, int32_t maxdevices, int32_t maxhandles, int32_t maxcaches);

///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] DeviceNumber TBD
//!
//! \return TBD
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see fsdriveinit.c.
///////////////////////////////////////////////////////////////////////////////
int32_t FSDriveInit(int32_t DeviceNumber);
int32_t FSDriveShutdown(int32_t DeviceNumber);

///////////////////////////////////////////////////////////////////////////////
//! \brief Determines free space by reading the all records 
//!
//! \fntype Reentrant
//!
//! \return Status of the call.
//! \retval 0 If successful.
//!
//! \todo [PUBS] Is the return value and definition correct?
//!
//! \internal
//! \see To view the function definition, see fsshutdown.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t FSShutdown(void);
///////////////////////////////////////////////////////////////////////////////
//! \brief Determines total free clusters by first checking FAT type.
//!
//! \fntype Reentrant 
//!
//! \param[in] DeviceNumber Device number.
//!
//! \return Returns total number of free clusters.
//!
//! \internal
//! \see To view the function definition, see computefreecluster.c.
///////////////////////////////////////////////////////////////////////////////
int32_t Computefreecluster(int32_t DeviceNumber);

///////////////////////////////////////////////////////////////////////////////
//! \brief Gets the size of the file.
//!
//! \fntype Reentrant 
//!
//! \param[in] HandleNumber File handle.
//!
//! \return Status of the call.
//! \retval 0 If the call was successful.
//! \retval error If an error occurred.
//!
//! \internal
//! \see To view the function definition, see getfilesize.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t GetFileSize(int32_t HandleNumber);

///////////////////////////////////////////////////////////////////////////////
//! \brief Flushes only the dirty cache buffers that contain valid
//!        data to the disk, but invalidates all cache entries.
//!
//! \fntype Function 
//!
//! \return Status of the call.
//!
//! \todo [PUBS] Function definition shows RtStatus_t as return.
//!
//! \internal
//! \see To view the function definition, see flushsector.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t FlushCache(void);

///////////////////////////////////////////////////////////////////////////////
//! \brief For device "deviceNumber", flushes only the dirty cache buffers that contain valid
//!        data to the disk, and invalidates their cache entries.
//!
//! \fntype Function 
//!
//! \param[in] deviceNumber TBD
//!
//! \return TBD
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see ??.
///////////////////////////////////////////////////////////////////////////////
int32_t FSFlushDriveCache(int32_t deviceNumber); //The real code calls for RtStatus_t

///////////////////////////////////////////////////////////////////////////////
//! \brief Returns FAT type.
//!
//! \fntype Non-Reentrant
//!
//! \param[in] DeviceNum
//!
//! \return TBD
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see readdevicerecord.c.
///////////////////////////////////////////////////////////////////////////////
int32_t FSFATType(int32_t DeviceNum);
///////////////////////////////////////////////////////////////////////////////
//! \brief Returns a value that indicates whether the specified device is present.
//!
//! \fntype Non-Reentrant 
//!
//! \param[in] DeviceNum Device number of the specified device.
//!
//! \return A value that indicates whether the device is present.
//! \retval TBD If the device is present.
//! \retval TBD If the device is not present.
//!
//! \todo [PUBS] Add return values...
//!
//! \internal
//! \see To view the function definition, see readdevicerecord.c.
///////////////////////////////////////////////////////////////////////////////
int32_t FSMediaPresent(int32_t DeviceNum);

///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Non-Reentrant 
//!
//! \param[in] Device TBD
//!
//! \return free space on the logical data drive in bytes.
//! \retval TBD
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see readdevicerecord.c.
///////////////////////////////////////////////////////////////////////////////
int32_t FSFreeClusters(int32_t Device);
int64_t FSFreeSpace(int32_t Device);
int64_t FSFreeSpaceFromHandle(int32_t HandleNumber);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Non-Reentrant 
//!
//! \param[in] HandleNumber TBD
//!
//! \return TBD
//! \retval TBD
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see readdevicerecord.c.
///////////////////////////////////////////////////////////////////////////////
int32_t FSSize(int32_t DeviceNum);

////////////////////////////////////////////////////////////////////////////////
// Directory API
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//! \brief Searches for the given directoy path and if the path is found 
//!        then changes the current working directoy to the given directory path.
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to file name.
//!
//! \return Status of the call.
//! \retval SUCCESS
//! \retval Error If error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see chdir.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Chdir(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief Searches for the given directoy path for UNICODE string and if the path is found 
//!        then changes the current working directoy to the given directory path.
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to the file name.
//!
//! \return Status of the call.
//! \retval SUCCESS
//! \retval Error If error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see chdirw.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Chdirw(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Reentrant Function 
//!
//! \param[in] filepath Pointer to the file path.
//!
//! \return Status of the call.
//! \retval SUCCESS If no error occurs.
//! \retval Error   If an error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see mkdir.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Mkdir(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Reentrant Function 
//!
//! \param[in] filepath Pointer to the file path.
//!
//! \return Status of the call.
//! \retval FS_SUCCESS If call was successful.
//! \retval Error      If error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see mkdirw.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Mkdirw(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief Searches for the given directory, and if it is found, empties and 
//!        deletes the directory.
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to the file name.
//!
//! \return Status of the call.
//! \retval FS_SUCCESS If call was successful.
//! \retval Error      If error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see rmdir.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Rmdir(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief Searches for the given directory, and if it is found, empties and 
//!        deletes the directory. 
//!
//! \fntype Function 
//!
//! \param[in] filepath Pointer to the file name.
//!
//! \return Status of the call.
//! \retval FS_SUCCESS If call was successful.
//! \retval Error      If error occurs.
//!
//! \note This function considers the string to be Unicode.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see rmdirw.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t Rmdirw(uint8_t *filepath);
///////////////////////////////////////////////////////////////////////////////
//! \brief Deletes all the files and directories of the specified path.
//!
//! \fntype Reentrant Function 
//!
//! \param[in] Path Pointer to the directory path.
//!
//! \return Status of the call.
//! \retval 0     If the call was successful.
//! \retval Error If an error occurs.
//!
//! \todo [PUBS] Add definition(s) and list error codes.
//!
//! \internal
//! \see To view the function definition, see deletetree.c.
///////////////////////////////////////////////////////////////////////////////
int32_t DeleteTree(uint8_t *Path);

int32_t Frename(uint8_t *oldFilename, uint8_t *newFilename);

///////////////////////////////////////////////////////////////////////////////
//! \brief Returns the pointer to the \c gCurrentWorkingdirectory string buffer.
//!
//! \fntype Function 
//!
//! \return Pointer to current working directory buffer.
//!
//! \internal
//! \see To view the function definition, see getcwd.c.
///////////////////////////////////////////////////////////////////////////////
uint8_t *Getcwd(void);
///////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//!
//! \fntype Function 
//!
//! \param[in] DeviceNo Device number to set the cwd handle to root dir of
//!
//! \retval 0 If successful
//!
//! \todo [PUBS] Revise \c DeviceNo definition.
//!
//! \internal
//! \see To view the function definition, see setcwdhandle.c.
///////////////////////////////////////////////////////////////////////////////
int32_t  SetCWDHandle(int32_t DeviceNo);

////////////////////////////////////////////////////////////////////////////////
// Find file API
////////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_READ_ONLY      0x01
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_HIDDEN         0x02
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_SYSTEM         0x04
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_VOLUME_ID      0x08
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_DIRECTORY      0x10
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_ARCHIVE        0x20
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ATTR_LONG_NAME      (ATTR_READ_ONLY|ATTR_HIDDEN|ATTR_SYSTEM|ATTR_VOLUME_ID)
//! \brief TBD
//! \todo [PUBS] Add definition...
#define MAX_FILESNAME   13

//! \brief TBD
//! \todo [PUBS] Add definition...
typedef struct _FindData
{
    //! \brief TBD
    uint8_t attrib;
    //! \brief TBD
    int32_t FileSize;
    //! \brief TBD
    uint8_t device;
    //! \brief TBD
    uint32_t startrecord;
    //! \brief TBD
    uint8_t name[MAX_FILESNAME];
    //! \brief TBD
    int64_t Key;
}
FindData_t;

///////////////////////////////////////////////////////////////////////////////
//! \brief Provides base, file name, and extension of the file to the FindNext() function.
//!
//! \fntype Function 
//!
//! \param[in] _finddata File specification
//! \param[in] FileName  Pointer to the file name.
//!
//! \return Status of the call.
//! \retval 0 If successful.
//! \retval Error 
//!
//! \note This function should not be called from multiple tasks.
//!
//! \todo [PUBS] Add definition(s) and error codes.
//!
//! \internal
//! \see To view the function definition, see findfirst.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t FindFirstLFN(FindData_t *_finddata, uint8_t *FileName,void*);
//! \brief TBD
//! \todo [PUBS] Add definition...
RtStatus_t FindFirst(FindData_t *_finddata, uint8_t *FileName);
//! \brief TBD
//! \todo [PUBS] Add definition...
RtStatus_t FindNextLFN(int32_t HandleNumber, FindData_t *_finddata,void*);
//! \brief TBD
//! \todo [PUBS] Add definition...
RtStatus_t FindNext(int32_t HandleNumber, FindData_t *_finddata);
//! \brief TBD
//! \todo [PUBS] Add definition...
RtStatus_t FindClose(int32_t HandleNumber);

////////////////////////////////////////////////////////////////////////////////
// File attribute API
////////////////////////////////////////////////////////////////////////////////
//! \brief TBD
//! \todo [PUBS] Add definition...
typedef struct
{
    //! \brief TBD
    uint8_t Day;
    //! \brief TBD
    uint8_t Month;
    //! \brief TBD
    int16_t Year;
}
DIR_DATE;

//! \brief TBD
//! \todo [PUBS] Add definition...
typedef struct
{
    //! \brief TBD
    uint8_t Second;
    //! \brief TBD
    uint8_t Minute;
    //! \brief TBD
    uint8_t Hour;
}
DIR_TIME;

// Use for 'crt_mod_date_time_para' parameter
//! \brief TBD
//! \todo [PUBS] Add definition...
#define CREATION_DATE       1
//! \brief TBD
//! \todo [PUBS] Add definition...
#define CREATION_TIME       2
//! \brief TBD
//! \todo [PUBS] Add definition...
#define MODIFICATION_DATE   3
//! \brief TBD
//! \todo [PUBS] Add definition...
#define MODIFICATION_TIME   4

///////////////////////////////////////////////////////////////////////////////
//! \brief Finds the creation or modification date or time of 
//!                  the file referenced by the given handle number.
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber           Handle number.
//! \param[in] crt_mod_date_time_para Create-modify-date-time parameter.
//! \param[in] dirdate                Pointer to the DIR_DATE structure.
//! \param[in] dirtime                Pointer to the DIR_TIME structure.
//!
//! \return Status of the call.
//! \retval 0 If successful.
//! \retval ERROR If an error occurs.
//!
//! \todo [PUBS] Revise definition for \c crt_mod_date_time_para and add error codes.
//!
//! \internal
//! \see To view the function definition, see filegetdate.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t filegetdate(int32_t HandleNumber, int32_t crt_mod_date_time_para, DIR_DATE *dirdate, DIR_TIME *dirtime);
///////////////////////////////////////////////////////////////////////////////
//! \brief Sets the creation or modification date or time of 
//!                  the file referenced by the given handle to the specified date or time.
//!
//! \fntype Function 
//!
//! \param[in] FilePath               Pointer to the file path.
//! \param[in] crt_mod_date_time_para Create-modify-date-time parameter.
//! \param[in] dirdate                Pointer to the DIR_DATE structure.
//! \param[in] dirtime                Pointer to the DIR_TIME structure.
//!
//! \return Status of the call.
//! \retval 0 If successful.
//! \retval Error 
//!
//! \todo [PUBS] Revise definition for \c crt_mod_date_time_para and add error codes.
//!
//! \internal
//! \see To view the function definition, see filesetdate.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t filesetdate(uint8_t *FilePath, int32_t crt_mod_date_time_para, DIR_DATE *dirdate, DIR_TIME *dirtime);


// Use for 'dirattribute' parameter

//! \brief TBD
//! \todo [PUBS] Add definition...
#define READ_ONLY           0X01
//! \brief TBD
//! \todo [PUBS] Add definition...
#define HIDDEN              0X02
//! \brief TBD
//! \todo [PUBS] Add definition...
#define SYSTEM              0X04
//! \brief TBD
//! \todo [PUBS] Add definition...
#define VOLUME_ID           0X08
//! \brief TBD
//! \todo [PUBS] Add definition...
#define DIRECTORY           0X10
//! \brief TBD
//! \todo [PUBS] Add definition...
#define ARCHIVE             0X20
//! \brief TBD
//! \todo [PUBS] Add definition...
#define MAX_UNICODE_SIZE 512

///////////////////////////////////////////////////////////////////////////////
//! \brief Gets directory attributes for a file based on the file handle.
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber File Handle.
//!
//! \return Returns directory attributes for a file or an error Code if an error occurs.
//!
//! \internal
//! \see To view the function definition, see filegetattribhandle.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t filegetattribhandle(int32_t HandleNumber);

///////////////////////////////////////////////////////////////////////////////
//! \brief Gets directory attributes for a file.
//!
//! \fntype Function 
//!
//! \param[in] FilePath Pointer to the file path.
//!
//! \return Returns directory attributes for a file or an error Code if an error occurs.
//!
//! \todo [PUBS] Is the return description accurate? Looks like it returns status (RtStatus_t).
//!
//! \internal
//! \see To view the function definition, see filegetattrib.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t filegetattrib(uint8_t *FilePath);

///////////////////////////////////////////////////////////////////////////////
//! \brief Sets directory attributes for a file.
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//! \param[in] dirattribute TBD
//!
//! \return Status of the call.
//! \retval SUCCESS If call was successful.
//! \retval ERROR   If an error occurs.
//!
//! \todo [PUBS] Add definition(s) and error codes.
//!
//! \internal
//! \see To view the function definition, see filesetattrib.c.
///////////////////////////////////////////////////////////////////////////////
RtStatus_t filesetattrib(int32_t HandleNumber, int32_t dirattribute);
 
///////////////////////////////////////////////////////////////////////////////
//! \brief Provides long file name.
//!
//! \fntype Function 
//!
//! \param[in] HandleNumber TBD
//! \param[in] RecordNumber TBD
//! \param[in] LFNBuffer    Pointer to the file name buffer.
//!
//! \return Returns length of the long file name string.
//!
//! \todo [PUBS] Add definition(s).
//!
//! \internal
//! \see To view the function definition, see longfilename.c.
///////////////////////////////////////////////////////////////////////////////
int32_t ConstructLongFileName(int32_t HandleNumber, int32_t RecordNumber, int8_t *LFNBuffer);

////////////////////////////////////////////////////////////////////////////////
//! \brief      Change the basename and/or extension name in a file name to lower case
//! \fntype     Function
//!
//! Cheks bits 3 and 4 in byte 0x0C to restore the case of the file name and changes
//! name to lower case in the buffer passed by the user
//! Here is an excerpt from Wikipedia:
//! If a filename contains only lowercase letters, or is a combination of a lowercase basename 
//!with an uppercase extension, or vice-versa; and has no special characters, and fits within 
//!the 8.3 limits, a VFAT entry is not created on Windows NT and later versions such as XP. 
//!Instead, two bits in byte 0x0c of the directory entry are used to indicate that the filename 
//!should be considered as entirely or partially lowercase. Specifically, bit 4 means lowercase 
//!extension and bit 3 lowercase basename, which allows for combinations such as "example.TXT" 
//!or "HELLO.txt" but not "Mixed.txt". Few other operating systems support this. This creates a
//!backwards-compatibility problem with older Windows versions (95, 98, ME) that see all-uppercase 
//!filenames if this extension has been used, and therefore can change the name of a file 
//!when it is transported, such as on a USB flash drive.
//!
//! \param[in]  HandleNumber - File handle number
//! \param[in]  pFindData - pointer to a FindData_t which has file information including
//! record number and name of the filearray of structure to store the maximum page erasures and the
//!
//! \param[out]  pFindData->name - name change to lower case if bits 3 or 4 is set
//!
//! \retval 0     always
//!
////////////////////////////////////////////////////////////////////////////////
int32_t CheckFileNameCase(int32_t HandleNumber, FindData_t * pFindData);

//! \brief TBD
//! \todo [PUBS] Add definition...
// typedef struct
// {
//     //! \brief TBD
//     int32_t CurrentOffset;     
//     //! \brief TBD
//     int32_t BytePosInSector;
//     //! \brief TBD
//     int32_t SectorPosInCluster;
//     //! \brief TBD
//     int32_t CurrentCluster;
//     //! \brief TBD
//     int32_t CurrentSector;   
// } HandleContext_t;
// 
// ////////////////////////////////////////////////////////////////////////////////
// // Check Disk Public API
// ////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////
// //! \brief TBD
// //!
// //! \fntype Function 
// //!
// //! \param[in] drive TBD
// //!
// //! \return Status of the call.
// //! \retval SUCCESS If the call was successful.
// //! \retval ERROR   If an error occurred.
// //!
// //! \todo [PUBS] Add definition(s) and actual error codes.
// //!
// //! \internal
// //! \see To view the function definition, see chkdsk.c.
// ///////////////////////////////////////////////////////////////////////////////
// RtStatus_t CheckDisk( uint8_t drive );
// 
// //! \brief TBD
// //! \todo [PUBS] Add definition...
// #define MAXCONTEXT 8
// 
// //! \brief TBD
// //! \todo [PUBS] Add definition...
// typedef struct
// {
//     //! \brief TBD
//     int32_t  HandleNumber;
//     //! \brief TBD
//     HandleContext_t HandleContext[MAXCONTEXT];
// } StoreContext_t;
// 
// //! \brief TBD
// //! \todo [PUBS] Add definition...
// #define MAX_STORE 2


#if defined(__cplusplus) && !defined(WIN32)
} // extern "C"
#endif // __cplusplus


#endif  //_FS_API_H



///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}
