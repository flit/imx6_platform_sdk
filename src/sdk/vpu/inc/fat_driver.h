/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * FreeDOS 32 FAT Driver                                                  
 * by Salvo Isaja                                                         
 */
#ifndef _FAT_DRIVER_H
#define _FAT_DRIVER_H

#include <stdio.h>
#include "io.h"

#define LOG_PRINTF(a)	printf a

/* Use the following defines to add features to the FAT driver */
/* TODO: The FAT driver currently doesn't work with buffers disabled! */
/* TODO: The name cache is totally broken! */
/* TODO: Sharing support can't be currently enabled */
#define FATBUFFERS              /* Uncomment this to use the buffered I/O        */
#define FATLFN                  /* Define this to use Long File Names            */
//#define FATWRITE     /* Define this to enable writing facilities      */
#define FATSHARE                /* Define this to enable sharing support         */
//#define FATNAMECACHE /* Define this to enable the opening name cache  */
#define FATREMOVABLE            /* Define this to enable removable media support */
//#define FAT_FD32DEV  /* Define this to enable FD32 devices support    */

/* 4-characters signatures to identify correct FAT driver structures */
#define FAT_VOLSIG 0x46415456   /* "FATV": FAT volume signature */
#define FAT_FILSIG 0x46415446   /* "FATF": FAT file signature   */

/* FIX ME: These should be read from CONFIG.SYS (or similar) */
#define FAT_MAX_FILES   20
#define FAT_MAX_BUFFERS 30

/* FAT Types */
typedef enum { FAT12, FAT16, FAT32 } tFatType;

/* EOC (End Of Clusterchain) check macros.                               */
/* These expressions are true (nonzero) if the value of a FAT entry is   */
/* an EOC for the FAT type. An EOC indicates the last cluster of a file. */
#define  FAT12_EOC(EntryValue)  (EntryValue >= 0x0FF8)
#define  FAT16_EOC(EntryValue)  (EntryValue >= 0xFFF8)
#define  FAT32_EOC(EntryValue)  (EntryValue >= 0x0FFFFFF8)

/* Bad cluster marks.                                                    */
/* Set a FAT entry to the FATxx_BAD value to mark the cluster as bad.    */
/*                                                                       */
/* The FAT file system specification says that to avoid confusion, no    */
/* FAT32 volume should ever be configured such that 0x0FFFFFF7 is an     */
/* allocatable cluster number. In fact an entry that would point to the  */
/* cluster 0x0FFFFFF7 would be recognised as Bad instead. Since values   */
/* greater or equal than 0x0FFFFFF8 are interpreted as EOC, I think we   */
/* can assume that the max cluster for a FAT32 volume is 0x0FFFFFF6.     */
/* That problem doesn't exist on FAT12 and FAT16 volumes, in fact:       */
/* 0x0FF7 = 4087 is greater than 4086 (max cluster for a FAT12 volume)   */
/* 0xFFF7 = 65527 is greater than 65526 (max cluster for a FAT16 volume) */
#define FAT12_BAD 0x0FF7
#define FAT16_BAD 0xFFF7
#define FAT32_BAD 0x0FFFFFF7

/* Special codes for the first byte of a directory entry */
#define FREEENT  0xE5           /* The directory entry is free             */
#define ENDOFDIR 0x00           /* This and the following entries are free */

/* FAT Return Codes                                          */
/* FIX ME: These should be removed. Use FD32 errors instead. */
#define FAT_RET_EOF -0xF7

/* Additional allowable attributes mask for lookup */
#define FAT_FANOVOLID 0x37      /* All attributes but volume label */

/* FAT32 Boot Sector and BIOS Parameter Block                         */
/* This structure is used in all driver functions, even if the volume */
/* is FAT12 or FAT16. In fact some FAT32 fields are checked anyway    */
/* like BPB_FATSz32). So we load the boot sector from the disk, we    */
/* detect the FAT type and if it's a FAT32, we fill the following     */
/* struct as is, while if the volume is FAT12/FAT16 we copy in the    */
/* right position the appropriate (common) fields.                    */

#define ATTR_READ_ONLY      0x1
#define ATTR_HIDDEN         0x2
#define ATTR_SYSTEM         0x4
#define ATTR_VOLUME_ID      0x8
#define ATTR_DIRECTORY      0x10
#define ATTR_ARCHIVE        0x20
#define ATTR_LONG_NAME      (ATTR_READ_ONLY | ATTR_HIDDEN | ATTR_SYSTEM | ATTR_VOLUME_ID)

#define FAT_BUFFER_SIZE     0x200

enum {
    FILE_READ_LOOP,             //in this mode, when reached to the end of file, curr ptr will back to the start
    FILE_READ_NORMAL,
};

typedef int fat_data_req_t(uint32_t sector, uint32_t sec_num, void *buffer, int flags);

/*DPT - Disk Partition Table*/
typedef struct {
    uint8_t boot_indicator;
    uint8_t starting_head;
    uint8_t starting_sector:6;
    uint16_t starting_cylinder:10;
    uint8_t system_id;
    uint8_t ending_head;
    uint8_t ending_sector:6;
    uint16_t ending_cylinder:10;
    uint32_t sector_offset;
    uint32_t total_sector;
} __attribute__ ((packed)) tDPT;

/*MBR - Main Boot Record*/
typedef struct {
    uint8_t boot_code[446];     //0x0~0x1BD
    tDPT dpt1;                  //the first partition
    tDPT dpt2;                  //the second partition
    tDPT dpt3;                  //the third partition
    tDPT dpt4;                  //the fourth partition
    uint16_t endcode;           //should be 0xAA55
} __attribute__ ((packed)) tMBR;
/*BIOS parameter block*/
typedef struct {
    uint8_t BS_jmpBoot[3];      //0x00~0x02
    uint8_t BS_OEMName[8];      //0x03~0x0A
    uint16_t BPB_BytsPerSec;    //0x0B~0x0C
    uint8_t BPB_SecPerClus;     //0x0D
    uint16_t BPB_ResvdSecCnt;   //0x0E~0x0F
    uint8_t BPB_NumFATs;        //0x10
    uint16_t BPB_RootEntCnt;    //0x11~0x12
    uint16_t BPB_TotSec16;      //0x13~0x14
    uint8_t BPB_Media;          //0x15
    uint16_t BPB_FATSz16;       //0x16~0x17
    uint16_t BPB_SecPerTrk;     //0x18~0x19
    uint16_t BPB_NumHeads;      //0x1A~0x1B
    uint32_t BPB_HiddSec;       //0x1C~0x1F
    uint32_t BPB_TotSec32;      //0x20~0x23
    /* Here start the FAT32 specific fields */
    uint32_t BPB_FATSz32;       //0x24~0x27
    uint16_t BPB_ExtFlags;      //0x28~0x29
    uint16_t BPB_FSVer;         //0x2A~0x2B
    uint32_t BPB_RootClus;      //0x2C~0x2F
    uint16_t BPB_FSInfo;        //0x30~0x31
    uint16_t BPB_BkBootSec;     //0x32~0x33
    uint8_t BPB_Reserved[12];   //0x34~0x3F
    /* The following fields are present also in a FAT12/FAT16 BPB,     */
    /* but at offset 36. In a FAT32 BPB they are at offset 64 instead. */
    uint8_t BS_DrvNum;          //0x40
    uint8_t BS_Reserved1;       //0x41
    uint8_t BS_BootSig;         //0x42
    uint32_t BS_VolID;          //0x43~0x46
    uint8_t BS_VolLab[11];      //0x47~0x51
    uint8_t BS_FilSysType[8];   //0x52~0x59
    /*then followed the startup code and end code 0xAA55 */
} __attribute__ ((packed)) tBpb;

/* FAT32 FSInfo Sector structure */
typedef struct {
    uint32_t LeadSig;
    uint8_t Reserved1[480];
    uint32_t StrucSig;
    uint32_t Free_Count;
    uint32_t Nxt_Free;
    uint8_t Reserved2[12];
    uint32_t TrailSig;
} __attribute__ ((packed)) tFSInfo;

/* FAT 32-byte Directory Entry structure */
typedef struct {
    char Name[11];
    uint8_t Attr;
    uint8_t NTRes;
    uint8_t CrtTimeTenth;
    uint16_t CrtTime;
    uint16_t CrtDate;
    uint16_t LstAccDate;
    uint16_t FstClusHI;
    uint16_t WrtTime;
    uint16_t WrtDate;
    uint16_t FstClusLO;
    uint32_t FileSize;
} __attribute__ ((packed)) tDirEntry;

/* FAT 32-byte Long File Name Directory Entry structure */
typedef struct {
    uint8_t Order;              /* Sequence number for slot        */
    uint16_t Name0_4[5];        /* First 5 Unicode characters      */
    uint8_t Attr;               /* Attributes, always 0x0F         */
    uint8_t Reserved;           /* Reserved, always 0x00           */
    uint8_t Checksum;           /* Checksum of 8.3 name            */
    uint16_t Name5_10[6];       /* 6 more Unicode characters       */
    uint16_t FstClus;           /* First cluster number, must be 0 */
    uint16_t Name11_12[2];      /* Last 2 Unicode characters       */
} __attribute__ ((packed)) tLfnEntry;

#ifdef FATBUFFERS
/* The buffer structure stores the status of a volume buffer */
typedef struct {
    uint32_t StartingSector;
    uint32_t LastAccess;
    uint32_t Flags;
    uint8_t *Data;
} tBuffer;
#endif

typedef struct {
    char fname[8];
    char fext[4];               //last for '\0'
    uint32_t file_size;
    uint32_t first_cluster;
    uint32_t sector;
    uint32_t bytes_read;
} __attribute__ ((packed)) tFile;

/* This structure stores all informations about a FAT volume.       */
/* It is the P structure (private data) for file system volume ops. */
typedef struct {
    /* Data referring to the hosting block device */
    uint32_t hBlkDev;           /* Handle of the block device hosting the volume   */
    fat_data_req_t *blkreq;     /* Request function of the block device driver     */

    /* Some precalculated data */
    tFatType FatType;           /* Can be FAT12, FAT16 or FAT32            */
    uint32_t DataClusters;      /* The total number of valid data clusters */
    uint32_t FirstDataSector;   /* The first sector of the data region     */
    uint32_t FirstRootSector;   /* The first sector of FAT12/FAT16 root    */
    uint32_t FirstFatTable;     /* The first file allocation table offset  */
    uint32_t FSI_Free_Count;    /* The count of free clusters              */
    uint32_t FSI_Nxt_Free;      /* The cluster number from which to start  */
    uint32_t FirstPartionOffset;    /* The offset of the first partition(in sector) */
    /* to search for free clusters, if known   */
    char *buffer;
    uint32_t buffer_pos;

    /* The BIOS Parameter Block of the volume (the long entry) */
    tBpb Bpb;
} tVolume;

/* A unique file identifier. Since FAT does not support hard links,  */
/* we can identify a file from its volume and the location of its    */
/* directory in the file's parent directory.                         */
/* This structure matches the first 24 bytes of the tFile structure. */
typedef struct {
    tVolume *V;                 /* Pointer to the volume hosting the file */
    uint32_t ParentFstClus;     /* First cluster of the parent directory  */
    uint32_t DirEntryOffset;    /* Offset of the dir entry in the parent  */
} tFileId;

/* Finddata block for the internal "readdir" function (fat_readdir) */
typedef struct {
    tDirEntry SfnEntry;
    uint32_t EntryOffset;
    int LfnEntries;
    char LongName[260];
    char ShortName[14];
} tFatFind;

/* The FAT driver format used for the 8 reserved bytes of the find data */
typedef struct {
    uint16_t EntryCount;        /* Entry count position within the directory   */
    uint32_t FirstDirCluster;   /* First cluster of the search directory       */
    uint16_t Reserved;          /* Currently not used by the FAT driver        */
} __attribute__ ((packed)) tFindRes;

/* Packs the high and low word of a tDirEntry's first cluster in a uint32_t */
#define FIRSTCLUSTER(D) (((uint32_t) D.FstClusHI << 16) + (uint32_t) D.FstClusLO)

/* Nonzero if two tFile or tFileId structs refer to the same file */
#define SAMEFILE(F1, F2) (!memcmp(F1, F2, sizeof(tFileId)))

/* Nonzero if the file is a FAT12/FAT16 root directory */
#define ISROOT(F) (!FIRSTCLUSTER(F->DirEntry) && !F->DirEntrySector && (F->V->FatType != FAT32))

int fat_mount(tVolume * V);
int fat_scan_root(tVolume * V, tFile * files, int maxFiles, int filter, const char *ext);
int fat_read_file(tVolume * V, tFile * F, char *buffer, uint32_t size, int mode);
int fat_open_file(tVolume * V, tFile * F);
#endif /* #ifndef __FD32_FAT_H */
