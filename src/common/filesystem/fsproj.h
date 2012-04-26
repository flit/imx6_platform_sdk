////////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_file
//! @{
//!
//  Copyright (c) 2005 SigmaTel, Inc.
//!
//! \file fsproj.h
//! \brief TBD
//! \todo [PUBS] Add definition.
////////////////////////////////////////////////////////////////////////////////

#ifndef _FS_PROJ_H
#define _FS_PROJ_H

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

//! \brief Maximum number of drives supported by the file system. 
//! 
//! Typically, \c maxdevices is 2.
extern const int maxdevices;

//! \brief Maximum number of handles available in the file system.
//! 
//! The number of handles available to the user is maxhandles - 2. 
//! Two handles are reserved by the file system for internal use only. 
//! The number of handles decides the number of files, which can 
//! simultaneously be open. Typically, \c maxhandles is 16.
extern const int maxhandles;

//! \brief Total number of cache buffers. 
//! 
//! Increasing the number of cache buffers improves the performance of 
//! the file system when several threads are accessing the file system. 
//! Typically, \c maxcaches is 8.
extern const int maxcaches;

//! \brief Assigns a drive letter to a drive.
//! 
//! For example, in the following sample code, \n
//!
//! \c A is assigned to drive 0,\n
//! \c B is assigned to drive 1, and \n
//! \c C is assigned to drive 2.
//! \code
//! int DriveLetter[] = {'A','B','C'};
//! \endcode
extern const uint8_t DriveLetter[];

// The cache buffers are allocated in the X buffer.
//extern BYTE bufx[NUMCACHES*CACHEBUFSIZE];
#ifndef _WIN32
#pragma alignvar(32)
#endif
//! \brief X memory buffer.
extern uint8_t bufx[];

#ifndef _WIN32
#pragma alignvar(4)
#endif
//! \brief Y memory buffer.
extern uint8_t bufy[];

#endif  //_FS_PROJ_H
///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}
