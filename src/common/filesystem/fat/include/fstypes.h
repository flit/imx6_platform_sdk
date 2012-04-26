////////////////////////////////////////////////////////////////////////////////
// Copyright(C) SigmaTel, Inc. 2000-2003
//
// Filename: fs_types.h
// Description: Standard data types
////////////////////////////////////////////////////////////////////////////////
#ifndef _FS_TYPES_H
#define _FS_TYPES_H

#include "types.h"
#include "drivers/media/sectordef.h"

#if 0
#define ENABLE_WRITE_FAT2
#endif

// Override these from the project file if needed
#ifndef NUMDEVICES
    #define NUMDEVICES      3
#endif

// Set default number of handles.
#ifndef NUMHANDLES
    #define NUMHANDLES      32
#endif

// Set default number of cached sectors.
#ifndef NUMCACHES
    #define NUMCACHES       32
#endif

#ifndef DRIVELETTERS
#define DRIVELETTERS    "acd"
#endif


#define BPB_AND_FSI_SIGNATURE_OFFSET_512B_SECTOR  (512-2)
#define BPB_AND_FSI_SIGNATURE_OFFSET_1K_SECTOR (1024-2)
#define BPB_AND_FSI_SIGNATURE_OFFSET_2K_SECTOR (2048-2)
#define BPB_AND_FSI_SIGNATURE_OFFSET_4K_SECTOR (4096-2)

#define BOOTSECTOR      0
#define SECONDARY_BOOT_SECTOR   6

//! Signature in last two bytes of the boot sector that identify it as such.
#define BOOT_SECTOR_SIGNATURE (0xaa55)

#define CREATE_MODE  32  // change

typedef enum
{
    NOT_WRITE_MODE = 0,
    READ_MODE = 1,
    WRITE_MODE = 2,
    APPEND_MODE = 4,
    RPLUS = (APPEND_MODE | READ_MODE),
    WPLUS = (APPEND_MODE | WRITE_MODE),
    APLUS = (APPEND_MODE | WRITE_MODE | READ_MODE),
    SEQ_WRITE_MODE = 8,
    DIRECTORY_MODE = 16
} FileSystemModeTypes_t;

typedef enum
{
	FAT_TYPE_INVALID = 0,
    FAT12 = 1,
    FAT16 = 2,
    FAT32 = 3,
} FAT_Types_t;

typedef struct
{
    int32_t CurrentOffset;
    int32_t CurrentCluster;
}HANDLECONTEXT;


#define FAT12EOF            0x0FFF
#define FAT16EOF            0xFFFF
#define FAT32EOF            0x0FFFFFFF

#define FAT12FREECX         0x000
#define FAT16FREECX         0x0000
#define FAT32FREECX         0x00000000

//! Supported character encoding formats for the filesystem.
enum _fs_character_encoding
{
    kDBCSEncoding = 1,
    kUTF16Encoding = 2
};

#define CWD_HANDLE          0
#define DIRECTORY_HANDLE    1
#define FIRST_VALID_HANDLE  2
#define END_OF_DIR_PATH     3

#define SHORTNAMERES_CH     6
#define LONGNAMERES_CH      9
#define MAXFILENAME_CH      260

#define VOLUME_TYPE          0
#define DIR_TYPE             1
#define FILE_TYPE            2

#define UCS2s               0
#define UCS3s               1

#define     FAT32FSIFREECOUNTSIZE	4

#endif  //FS_TYPES_H
