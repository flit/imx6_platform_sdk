/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "fat_driver.h"
#include <stdio.h>
#include <string.h>

uint32_t fat_first_sector_of_cluster(uint32_t N, tVolume * V)
{
    if ((N < 2) || (N > V->DataClusters + 1))
        return 0;
    return ((N - 2) * V->Bpb.BPB_SecPerClus) + V->FirstDataSector;
}

static uint32_t root_dir_sectors(tBpb * Bpb)
{
    return ((Bpb->BPB_RootEntCnt * 32) + (Bpb->BPB_BytsPerSec - 1)) / Bpb->BPB_BytsPerSec;
}

static uint32_t first_data_sector(tBpb * Bpb)
{
    uint32_t FATSz;

    if (Bpb->BPB_FATSz16 != 0)
        FATSz = Bpb->BPB_FATSz16;
    else
        FATSz = Bpb->BPB_FATSz32;
    return Bpb->BPB_ResvdSecCnt + (Bpb->BPB_NumFATs * FATSz) + root_dir_sectors(Bpb);
}

static uint32_t data_clusters(tBpb * Bpb)
{
    uint32_t FATSz, TotSec;

    /* For a FAT12/FAT16 volume, BPB_FATSz16 must be non-zero, so we don't */
    /* have to bother to pass a tFat1216_Bpb structure instead.            */
    /* The BPB_FATSz32, only present in a FAT32 BPB, will be used only if  */
    /* if the BPB_FATSz16 is zero, i.e. if the volume is FAT32.            */
    if (Bpb->BPB_FATSz16 != 0)
        FATSz = Bpb->BPB_FATSz16;
    else
        FATSz = Bpb->BPB_FATSz32;   //sector occupied by fat table
    if (Bpb->BPB_TotSec16 != 0)
        TotSec = Bpb->BPB_TotSec16; //total sectors
    else
        TotSec = Bpb->BPB_TotSec32;
    return (TotSec - (Bpb->BPB_ResvdSecCnt + (Bpb->BPB_NumFATs * FATSz)
                      + root_dir_sectors(Bpb))) / Bpb->BPB_SecPerClus;
}

static tFatType determine_fat_type(tBpb * Bpb)
{
    uint32_t CountOfClusters = data_clusters(Bpb);

    if (CountOfClusters < 4085)
        return FAT12;
    else if (CountOfClusters < 65525)
        return FAT16;
    else
        return FAT32;
}

static int check_bpb(char *SecBuf)
{
    uint32_t TotSec;
    tBpb *Bpb = (tBpb *) SecBuf;

    /* Check for the 0xAA55 signature at offset 510 of the boot sector */
    if (*((uint16_t *) & SecBuf[510]) != 0xAA55) {
        printf("Boot sector signature 0xAA55 not found\n");
        return -1;
    }

    /* Check volume size. If both TotSec32 and TotSec16 are nonzero,
     * only the latter is considered valid. */
    TotSec = Bpb->BPB_TotSec16;
    if (!TotSec) {
        TotSec = Bpb->BPB_TotSec32;
        if (!TotSec) {
            printf("Both BPB_TotSec16 and BPB_TotSec32 are zero\n");
            return -1;
        }
    }

    /* BPB_BytsPerSec can be 512, 1024, 2048 or 4096 */
    switch (Bpb->BPB_BytsPerSec) {
        /*case 512: case 1024: case 2048: case 4096: break; */
    case 512:
        break;                  /* this very limited code will only support 512 bytes */
    default:
        printf("Invalid BPB_BytsPerSec: %u\n", Bpb->BPB_BytsPerSec);
        return -1;
    }

    /* BPB_SecPerCluster can be 1, 2, 4, 8, 16, 32, 64, 128 */
    switch (Bpb->BPB_SecPerClus) {
    case 1:
    case 2:
    case 4:
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
        break;
    default:
        printf("Invalid BPB_SecPerClus: %u\n", Bpb->BPB_SecPerClus);
        return -1;
    }

    /* BPB_Media can be 0xF0, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF */
    if ((Bpb->BPB_Media != 0xF0) && (Bpb->BPB_Media < 0xF8)) {
        printf("Invalid BPB_Media: %u\n", Bpb->BPB_Media);
        return -1;
    }

    return 0;
}

static uint32_t get_relative_sector(char *buffer)
{
    return (uint32_t) ((uint32_t *) (buffer + 0x1c6));
}

static int read_bpb(tVolume * V, tBpb * Bpb, tFatType * FatType)
{
    int Res;
    tMBR mbr;

    /*read the MBR */
    if ((Res = V->blkreq(0, FAT_BUFFER_SIZE, V->buffer, 0)) < 0) {
        return -1;
    }

    memcpy((char *)&mbr, V->buffer, sizeof(tMBR));
    if (mbr.endcode != 0xAA55) {
        printf("MBR reading failed!!\n");
        return -1;
    }

    /*get the base of the first partition */
    V->FirstPartionOffset = mbr.dpt1.sector_offset;

    /*read the BPB */
    if ((Res =
         V->blkreq(V->FirstPartionOffset * FAT_BUFFER_SIZE, FAT_BUFFER_SIZE, V->buffer, 0)) < 0) {
        return -1;
    }

    /* Check if the BPB is valid */
    if ((Res = check_bpb(V->buffer)) < 0) {
        return Res;
    }

    /* Initialize the volume's BPB, using also the FSInfo if FAT32 */
    *FatType = determine_fat_type((tBpb *) V->buffer);

    if (*FatType != FAT32) {
        printf("Not FAT32!\n");
        return -1;
    }

    memcpy(Bpb, V->buffer, sizeof(tBpb));
    /* Check the FAT32 version */
    if (Bpb->BPB_FSVer > 0x0000) {
        printf("Unknown FAT32 version in BPB_FSVer: %04X\n", Bpb->BPB_FSVer);
        return -1;
    }

    return 0;
}

int fat_mount(tVolume * V)
{
    int Res;
    tFSInfo *FSInfo;

    V->buffer_pos = 0;

    /* Read the boot sector and initialize the BPB */
    Res = read_bpb(V, &V->Bpb, &V->FatType);
    if (Res < 0)
        return -1;

    V->DataClusters = data_clusters(&V->Bpb);
    V->FirstDataSector = first_data_sector(&V->Bpb) + V->FirstPartionOffset;
    V->FirstFatTable = V->Bpb.BPB_ResvdSecCnt + V->FirstPartionOffset;
    if ((Res =
         V->blkreq((V->Bpb.BPB_FSInfo + V->FirstPartionOffset) * V->Bpb.BPB_BytsPerSec,
                   V->Bpb.BPB_BytsPerSec, V->buffer, 0)) < 0) {
        return -1;
    }
    FSInfo = (tFSInfo *) V->buffer;

    /* Check FAT32 FSInfo signatures */
    if (FSInfo->LeadSig != 0x41615252)
        return -1;
    if (FSInfo->StrucSig != 0x61417272)
        return -1;
    if (FSInfo->TrailSig != 0xAA550000)
        return -1;
    /* Assign FSInfo parameters to FAT volume fields */
    V->FSI_Free_Count = FSInfo->Free_Count;
    V->FSI_Nxt_Free = FSInfo->Nxt_Free;

    return 0;
}

inline void split_filename(char *filename, char *name, char *ext)
{
    int name_len = 0, string_len = 0;
    int i = 0;

    string_len = strlen((const char *)filename);

    while ((i < string_len) && (filename[i++] != '.')) {
        name_len++;
    }

    memcpy(name, filename, name_len);
    memcpy(ext, &filename[name_len + 1], string_len - name_len - 1);
}

inline int compare_filename(char *filename, char *name, char *ext)
{
    char fname[8], fext[3];
    int i = 0;

    memset(fname, 0x20, 8);
    memset(fext, 0x20, 3);
    split_filename(filename, fname, fext);

    while (i < 8) {
        if (fname[i] != name[i])
            return 0;           //file name does not match
        i++;
    }

    i = 0;
    while (i < 3) {
        if (ext[i] != ext[i])
            return 0;           //file extension does not match
        i++;
    }

    return 1;
}

/* if file found return 1 else return 0 */
int fat_get_file(tVolume * V, tFile * file, char *filename)
{
    tDirEntry *dirEntry;
    int secCnt, curCluster, FATSecNum;

    secCnt = 1;
    curCluster = V->Bpb.BPB_RootClus;

    V->blkreq(V->FirstDataSector * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
    dirEntry = (tDirEntry *) V->buffer;

    while (dirEntry->Name[0] != 0) {
        if ((dirEntry->Name[0] != 0xE5) && (dirEntry->Attr != ATTR_LONG_NAME)
            && (!(dirEntry->Attr & ATTR_DIRECTORY))) {
            if (compare_filename(filename, &(dirEntry->Name[0]), &(dirEntry->Name[8]))) {
                file->file_size = dirEntry->FileSize;
                file->first_cluster =
                    ((uint32_t) dirEntry->FstClusHI << 16) | (uint32_t) dirEntry->FstClusLO;
                file->sector = fat_first_sector_of_cluster(file->first_cluster, V);
                file->bytes_read = 0;
                split_filename(filename, file->fname, file->fext);
                file->fext[3] = '\0';
                return 1;
            }
        }

        ++dirEntry;
        if (((uint16_t *) dirEntry - (uint16_t *) (V->buffer)) >= FAT_BUFFER_SIZE) {
            if (secCnt == V->Bpb.BPB_SecPerClus) {
                FATSecNum = V->Bpb.BPB_ResvdSecCnt + (curCluster * 4 / V->Bpb.BPB_BytsPerSec);
                V->blkreq(FATSecNum * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
                curCluster =
                    *(unsigned int *)(V->buffer + ((curCluster * 4) % V->Bpb.BPB_BytsPerSec));
                secCnt = 0x0;
            }

            V->blkreq((fat_first_sector_of_cluster(curCluster, V) +
                       secCnt++) * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
            dirEntry = (tDirEntry *) V->buffer;
        }
    }

    return 0;
}

int fat_scan_root(tVolume * V, tFile * files, int maxFiles, int filter, const char *ext)
{
    tDirEntry *dirEntry;
    int fileCnt, secCnt, curCluster, FATSecNum, i;
    int fileNameLen = 0;

    fileCnt = 0;
    secCnt = 1;
    curCluster = V->Bpb.BPB_RootClus;

    V->blkreq(V->FirstDataSector * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
    dirEntry = (tDirEntry *) V->buffer;

    while (dirEntry->Name[0] != 0) {
        if ((dirEntry->Name[0] != 0xE5) && (dirEntry->Attr != ATTR_LONG_NAME)) {
            if ((!(dirEntry->Attr & ATTR_DIRECTORY)) &&
                (filter && (dirEntry->Name[8] == ext[0]) && (dirEntry->Name[9] == ext[1])
                 && (dirEntry->Name[10] == ext[2]))) {
                files[fileCnt].file_size = dirEntry->FileSize;
                files[fileCnt].first_cluster =
                    ((uint32_t) dirEntry->FstClusHI << 16) | (uint32_t) dirEntry->FstClusLO;
                files[fileCnt].sector =
                    fat_first_sector_of_cluster(files[fileCnt].first_cluster, V);
                files[fileCnt].bytes_read = 0;
                fileNameLen = 0;
                for (i = 0; i < 8; i++) {
                    files[fileCnt].fname[i] = 0x20; //clean the name
                    if (dirEntry->Name[i] != 0x20)  //get rid of space
                        fileNameLen++;
                }
                for (i = 0; i < fileNameLen; i++)
                    files[fileCnt].fname[7 - fileNameLen + i] = dirEntry->Name[i];
                files[fileCnt].fname[7] = '.';
                for (i = 0; i < 3; i++)
                    files[fileCnt].fext[i] = dirEntry->Name[i + 8];
                files[fileCnt].fext[3] = '\0';
                if (++fileCnt == maxFiles)
                    fileCnt = 0;
            }
        }

        ++dirEntry;
        if (((uint16_t *) dirEntry - (uint16_t *) (V->buffer)) >= FAT_BUFFER_SIZE) {
            if (secCnt == V->Bpb.BPB_SecPerClus) {
                FATSecNum = V->Bpb.BPB_ResvdSecCnt + (curCluster * 4 / V->Bpb.BPB_BytsPerSec);
                V->blkreq(FATSecNum * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
                curCluster =
                    *(unsigned int *)(V->buffer + ((curCluster * 4) % V->Bpb.BPB_BytsPerSec));
                secCnt = 0x0;
            }

            V->blkreq((fat_first_sector_of_cluster(curCluster, V) +
                       secCnt++) * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
            dirEntry = (tDirEntry *) V->buffer;
        }
    }

    return fileCnt;
}

int fat_scan_root_for_directories(tVolume * V, tFile * files, int maxFiles, int filter,
                                  const char *ext)
{
    tDirEntry *dirEntry;
    int fileCnt, secCnt, curCluster, FATSecNum, i;
    int fileNameLen = 0;

    fileCnt = 0;
    secCnt = 1;
    curCluster = V->Bpb.BPB_RootClus;

    V->blkreq(V->FirstDataSector * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
    dirEntry = (tDirEntry *) V->buffer;

    while (dirEntry->Name[0] != 0) {
        if (dirEntry->Attr == ATTR_DIRECTORY) {
            files[fileCnt].file_size = dirEntry->FileSize;
            files[fileCnt].first_cluster =
                ((uint32_t) dirEntry->FstClusHI << 16) | (uint32_t) dirEntry->FstClusLO;
            files[fileCnt].sector = fat_first_sector_of_cluster(files[fileCnt].first_cluster, V);
            files[fileCnt].bytes_read = 0;
            fileNameLen = 0;
            for (i = 0; i < 8; i++) {
                files[fileCnt].fname[i] = 0x20; //clean the name
                if (dirEntry->Name[i] != 0x20)  //get rid of space
                    fileNameLen++;
            }
            for (i = 0; i < fileNameLen; i++)
                files[fileCnt].fname[7 - fileNameLen + i] = dirEntry->Name[i];
            files[fileCnt].fname[7] = '.';
            for (i = 0; i < 3; i++)
                files[fileCnt].fext[i] = dirEntry->Name[i + 8];
            files[fileCnt].fext[3] = '\0';
            if (++fileCnt == maxFiles)
                fileCnt = 0;
        }

        ++dirEntry;
        if (((uint16_t *) dirEntry - (uint16_t *) V->buffer) >= FAT_BUFFER_SIZE) {
            if (secCnt == V->Bpb.BPB_SecPerClus) {
                FATSecNum = V->Bpb.BPB_ResvdSecCnt + (curCluster * 4 / V->Bpb.BPB_BytsPerSec);
                V->blkreq(FATSecNum * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
                curCluster =
                    *(unsigned int *)(V->buffer + ((curCluster * 4) % V->Bpb.BPB_BytsPerSec));
                secCnt = 0x0;
            }

            V->blkreq((fat_first_sector_of_cluster(curCluster, V) +
                       secCnt++) * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
            dirEntry = (tDirEntry *) V->buffer;
        }
    }

    return fileCnt;
}

int fat_scan_dir(tVolume * V, uint32_t dirFirstCluster, tFile * files, int maxFiles, int filter,
                 const char *ext)
{
    tDirEntry *dirEntry;
    int fileCnt, secCnt, curCluster, FATSecNum, i;

    fileCnt = 0;
    secCnt = 1;
    curCluster = dirFirstCluster;

    V->blkreq(fat_first_sector_of_cluster(dirFirstCluster, V) * V->Bpb.BPB_BytsPerSec,
              V->Bpb.BPB_BytsPerSec, V->buffer, 0);
    dirEntry = (tDirEntry *) V->buffer;

    while (dirEntry->Name[0] != 0) {

        if ((dirEntry->Name[0] != 0xE5) && (dirEntry->Attr != ATTR_LONG_NAME)) {
            if ((!(dirEntry->Attr & ATTR_DIRECTORY)) &&
                (filter && (dirEntry->Name[8] == ext[0]) && (dirEntry->Name[9] == ext[1])
                 && (dirEntry->Name[10] == ext[2]))) {
                files[fileCnt].file_size = dirEntry->FileSize;
                files[fileCnt].first_cluster =
                    ((uint32_t) dirEntry->FstClusHI << 16) | (uint32_t) dirEntry->FstClusLO;
                files[fileCnt].sector =
                    fat_first_sector_of_cluster(files[fileCnt].first_cluster, V);
                files[fileCnt].bytes_read = 0;
                for (i = 0; i < 8; i++)
                    files[fileCnt].fname[i] = dirEntry->Name[i];
                for (i = 0; i < 3; i++)
                    files[fileCnt].fext[i] = dirEntry->Name[i + 8];
                if (++fileCnt == maxFiles)
                    fileCnt = 0;
            }
        }

        ++dirEntry;
        if (((uint16_t *) dirEntry - (uint16_t *) V->buffer) >= FAT_BUFFER_SIZE) {
            if (secCnt == V->Bpb.BPB_SecPerClus) {
                FATSecNum = V->Bpb.BPB_ResvdSecCnt + (curCluster * 4 / V->Bpb.BPB_BytsPerSec);
                V->blkreq(FATSecNum * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
                curCluster =
                    *(unsigned int *)(V->buffer + ((curCluster * 4) % V->Bpb.BPB_BytsPerSec));
                secCnt = 0x0;
            }

            V->blkreq((fat_first_sector_of_cluster(curCluster, V) +
                       secCnt++) * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
            dirEntry = (tDirEntry *) V->buffer;
        }
    }

    return fileCnt;
}

int fat_open_file(tVolume * V, tFile * F)
{
    F->sector = fat_first_sector_of_cluster(F->first_cluster, V);
    F->bytes_read = 0;
    V->buffer_pos = 0;
    return 0;
}

inline uint32_t get_cluster_index(tVolume * V, uint32_t curSector)
{
    uint32_t curCluster;

    curCluster = (curSector - V->FirstFatTable) / V->Bpb.BPB_SecPerClus + 2;

    return curCluster;
}

inline uint32_t get_sector_offset_in_cluster(tVolume * V, uint32_t curSector)
{
    uint32_t index = 0;

    index =
        curSector - ((get_cluster_index(V, curSector) - 2) * V->Bpb.BPB_SecPerClus +
                     V->FirstDataSector);

    return index;
}

inline uint32_t get_next_cluster(tVolume * V, uint32_t curCluster)
{
    uint32_t nextCluster;
    if ((curCluster < 2) || (curCluster > V->DataClusters + 1))
        return 0;

    nextCluster = readl(curCluster * 4 + V->FirstFatTable);

    return nextCluster;
}

inline uint32_t get_next_sector(tVolume * V, uint32_t curSector)
{
    uint32_t nextSector, curCluster;

    if (get_sector_offset_in_cluster(V, curSector) != V->Bpb.BPB_SecPerClus - 1)
        return (curSector + 1);
    else                        //reach to end of a cluster
    {
        curCluster = get_cluster_index(V, curSector);
        nextSector =
            (get_next_cluster(V, curCluster) - 2) * V->Bpb.BPB_SecPerClus + V->FirstDataSector;
        return nextSector;
    }

    return 0;
}

/* Read data from a fat32 file. size is given in bytes. Function returns number of bytes readget the offset inside the buffer*/
/* Read file based on the fat partition descrption table, the sector could be not sequential in physical, we need to set the ADMA script to indicate the offset of each cluster */
int fat_read_file(tVolume * V, tFile * F, char *buffer, uint32_t size)
{
    uint32_t left_bytes, read_size, pos;

    left_bytes = 0;

    if (size > (F->file_size - F->bytes_read))
        size = F->file_size - F->bytes_read;

    pos = 0;
    read_size = size;
    if (V->buffer_pos != 0) {
        /*get the offset inside the buffer */
        pos = V->Bpb.BPB_BytsPerSec - V->buffer_pos;

        if (size < pos) {
            memcpy(buffer, V->buffer + V->buffer_pos, size);
            V->buffer_pos += size;
            F->bytes_read += size;
            return size;
        }

        memcpy(buffer, V->buffer + V->buffer_pos, pos);
        V->buffer_pos = 0;
        read_size -= pos;
    }

    if (read_size % V->Bpb.BPB_BytsPerSec) {
        left_bytes = read_size % V->Bpb.BPB_BytsPerSec;
        read_size -= left_bytes;
    }

    if (read_size > 0) {
        /*Note by Ray:suppose all the clusters are consequential in physical address. or else we have to read the SD card in cluster unit, and add mutex in sd_read to avoid data corruption */
        V->blkreq(F->sector * V->Bpb.BPB_BytsPerSec, read_size, buffer + pos, 0);
        F->sector += (read_size / V->Bpb.BPB_BytsPerSec);
    }

    if (left_bytes) {
        /*Note by Ray:A potential bug here. if there is unaligned data read, we have to wait untill the last read finished. */
        V->blkreq(F->sector * V->Bpb.BPB_BytsPerSec, V->Bpb.BPB_BytsPerSec, V->buffer, 0);
        ++(F->sector);
        memcpy(buffer + read_size + pos, V->buffer, left_bytes);
        V->buffer_pos = left_bytes;
    }

    F->bytes_read += size;

    if (F->bytes_read == F->file_size) {
        F->sector = fat_first_sector_of_cluster(F->first_cluster, V);
        F->bytes_read = 0;
        V->buffer_pos = 0;
    }

    return size;
}

/* Read data from a fat32 file. size is given in bytes. Function returns number of bytes read */
/* Doesn't wait for callback read function to return. Size must be a multiple of BPB_BytesPerSec (usualy 512 bytes) */
int fat_read_file_fast(tVolume * V, tFile * F, char *buffer, uint32_t size)
{
    uint32_t left_bytes, read_size;

    left_bytes = 0;

    if (size > (F->file_size - F->bytes_read))
        size =
            (((F->file_size - F->bytes_read) +
              (V->Bpb.BPB_BytsPerSec - 1)) / V->Bpb.BPB_BytsPerSec) * V->Bpb.BPB_BytsPerSec;

    read_size = size;

    V->blkreq(F->sector * V->Bpb.BPB_BytsPerSec, read_size, buffer, 1);
    F->sector += (read_size / V->Bpb.BPB_BytsPerSec);

    F->bytes_read += size;

    if (F->bytes_read >= F->file_size) {
        F->sector = fat_first_sector_of_cluster(F->first_cluster, V);
        F->bytes_read = 0;
        V->buffer_pos = 0;
    }

    return size;

}
