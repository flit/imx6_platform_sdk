/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef DEVICETABLE_H
#define DEVICETABLE_H

#include <types.h>
#include "fstypes.h"

//! \brief Structure to hold parameters from the BPB
//!
//! Media that contains a filesystem contains a BIOS Parameter Block (BPB).
//! This structure captures parameters from that BPB, and other values
//! that are computed based on the BPB.
typedef struct
{
     /* *******************************************************************
            BPB variables
        ******************************************************************* */
    
                                        // BPB-mandated    Microsoft
                                        // size            Name
                                        // -------         ------
    int32_t  BytesPerSector;            // 2               BPB_BytsPerSec    
    uint8_t  SectorsPerCluster;         // 1               BPB_SecPerClus
    uint16_t RsvdSectors;               // 2               BPB_RsvdSecCnt
    uint8_t  NoOfFATs;                  // 1               BPB_NumFATs
    int32_t  MaxRootDirEntries;         // 2               BPB_RootEntCnt   =0 for FAT32.  Nom. =512 for FAT16.
    int32_t  TotalSectors;              // 2 (FAT16)       BPB_TotSec16
                                        // or 4 (FAT32)    BPB_TotSec32
    int32_t  FATSize;                   // 2 (FAT16)       BPB_FATSz16    size units: sectors
                                        // or 4 (FAT32)    BPB_FATSz32
    int32_t  RootdirCluster;            // 4               BPB_RootClus
    //int32_t  FSInfoSector;  
    //int32_t  BkBootSector;  

     /* *******************************************************************
            Derived variables
        ******************************************************************* */

    int32_t  NextFreeCluster;
    int32_t  TotalFreeClusters;
    uint16_t RootDirSectors;            // Qty of sectors needed to hold the root directory.
    int32_t  FIRSTDataSector;    
    uint8_t  FATType;    
    int32_t  TotalNoofclusters;    
    int32_t  ClusterMask;    
    int32_t  ClusterShift;    
    int32_t  SectorShift;               // Index of the MSB of the value in BytesPerSector.
    int32_t  SectorMask;                // Mask of all bits up to SectorShift.
    uint8_t  DevicePresent;    
    int32_t  FirRootdirsec;    
    int32_t  FSInfoSector;
} FileSystemMediaTable_t;

#endif /* #ifndef DEVICETABLE_H */

