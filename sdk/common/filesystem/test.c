/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include <string.h>
#include <stdlib.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h>   //! \todo malinclusion

uint8_t readfile[] = "indir/fsproj.h";
uint8_t writefile[] = "outdir/fsproj.h";

#define TEST_FILE_SIZE 2048
#define DeviceNum 0

extern void print_media_fat_info(uint32_t);

int fat_test(void)
{
    int count = 0;
    int TestResult = 0;
    int32_t fin;
    uint8_t *ReadBuffer;
    uint32_t ClusterSize = 0, FileSize = 0;

    printf("FSInit				");
    if (FSInit(NULL, bufy, maxdevices, maxhandles, maxcaches) != SUCCESS) {
        TestResult = -1;
        printf("FAIL\n");
    } else {
        printf("PASS\n");
    }

    /*init the drive */
    FSDriveInit(DeviceNum);
    SetCWDHandle(DeviceNum);

    print_media_fat_info(DeviceNum);

    if ((fin = Fopen(readfile, (uint8_t *) "r")) < 0)
    {
        printf("Can't open the file: %s !\n", readfile);
        return ERROR_GENERIC;
    }

    FileSize = GetFileSize(fin);
    printf("File %s of size %d opened!\n", readfile, FileSize);

    ClusterSize = MediaTable[DeviceNum].SectorsPerCluster * MediaTable[DeviceNum].BytesPerSector;
    ReadBuffer = (uint8_t *) malloc(FileSize+1);
    printf("%X\n", ReadBuffer);
    memset(ReadBuffer,'\0',FileSize+1);

    if ((count = Fread(fin, ReadBuffer, FileSize)) < 0)
    {
        Fclose(fin);
        return ERROR_GENERIC;
    }
    else
    {
        printf("%s\n", ReadBuffer);
    }

    printf("\n*****************File Reading End********************\n");

    free(ReadBuffer);
    Fclose(fin);
    FlushCache();
    return 0;
}
