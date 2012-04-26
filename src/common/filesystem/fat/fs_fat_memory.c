////////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_file
//! @{
//!
//  Copyright (c) 2005-2007 SigmaTel, Inc.
//!
//! \file    fs_fat_memory.c
//! \brief   FAT file system module data definition.
//!
//! This file defines the global data objects used by the FAT file system.
//! It is included in the FAT library. If you need to override the default
//! definitions, add this file and your custom definitions to your 'Program'
//! project. For example, to change the number of devices to 4, add the
//! following lines to your project.
//!
//! \code
//! os\filesystem\fat\fs_fat_memory.c
//!    -DNUMDEVICES=4
//! \endcode
//!
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "include/fstypes.h"
#include "hw/core/vmemory.h"
#include "include/fat_internal.h"
#include "include/filespec.h"
#include "drivers/sectordef.h"


////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

// Include filesystem memory only if the number of filesystem devices is non-zero.
#if (NUMDEVICES > 0)

const int maxcaches  = NUMCACHES;
const int maxdevices = NUMDEVICES;
const int maxhandles = NUMHANDLES;
const uint8_t DriveLetter[] = DRIVELETTERS;

//! All other global, custom configurable data is in Y memory.
//! Two handles are reserved by the file system, so the number of handles must be more than 2
uint8_t bufy[ NUMDEVICES*sizeof(FileSystemMediaTable_t) +
              NUMHANDLES*sizeof(HandleTable_t) +
              NUMHANDLES*sizeof(FileSpecs_t) ] __attribute__ ((aligned(4)));

#endif //#if (NUMDEVICES > 0)


// eof fs_fat_memory.c
//! @}
