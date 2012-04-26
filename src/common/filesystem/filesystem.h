///////////////////////////////////////////////////////////////////////////////
//! \addtogroup os_file
//! @{
//
// Copyright (c) 2004-2005 SigmaTel, Inc.
//
//! \file filesystem.h
//! \brief Contains header data for the OS file system API.
//! \todo [PUBS] Add definitions for TBDs in this file.
///////////////////////////////////////////////////////////////////////////////

#ifndef _FILESYSTEM_H
#define _FILESYSTEM_H

#include "drivers/media/ddi_media.h"

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

//! \brief TBD
typedef struct {
    //! \brief TBD
    //!
    //! This value is limited to 2-bytes for compatibility with older host drivers.
    uint32_t dwTotalSizeInMegaBytes;
    //! \brief TBD
    uint64_t dwTotalNumberOfSectors;
    //! \brief TBD
    uint64_t dwTotalNumberOfBytes;
    //! \brief TBD
    uint32_t wSectorSizeInBytes;
} MEDIA_SIZE;


/*!
 * \brief Association between drive letter and drive tag.
 */
typedef struct {
    char letter;    //!< Drive letter.
    DriveTag_t tag; //!< Drive tag.
} FileSystemDriveAssociation_t;

//! \brief Table of associations between drive letter and drive tag.
//!
//! The table is terminated with an entry that has 0 for both letter and tag.
extern const FileSystemDriveAssociation_t g_fsDriveAssociations[];


// Private data needed by fsapi.h: true here for external data drive means drive 
// is init and for frameworks that handle the FS, it means the drive's FS is init also.
//extern bool g_bFrameworkExternalDriveOrFsInit;

//------------------------------------------------------------------------------
// It's preferred to instead use public macro API IsExternalDriveFsReady().
// TODOFSINITSHUTDOWN: 
// This does not really belong to DDI LDL or FS, but the function uses FS utilities.
typedef enum MEDIA_MMC_STATUS
{   MEDIA_MMC_NOT_PRESENT = 0,
    MEDIA_MMC_INVALID,      // MMC is present but does not have a valid FS (or drive's FS is not init)
    MEDIA_MMC_VALID,        // MMC is present and has a valid FS
    MEDIA_MMC_EJECTED
} media_mmc_status_t;

#if (!defined(WIN32) && defined(MMC))
// This util checks drive's FS status. Suggest instead using fsapi.h's IsExternalDriveFsReady() macro.
extern media_mmc_status_t ExternalMMCMediaPresent(void);
#endif
//------------------------------------------------------------------------------



#endif // _FILESYSTEM_H

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}

