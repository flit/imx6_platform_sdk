/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include "sdk.h"
#include "types.h"
#include <string.h>
#include <stdlib.h>
#include "filesystem/fsapi.h"
#include "filesystem/fat/fstypes.h"
#include "filesystem/fat/fat_internal.h"
#include "timer/epit.h"
#include "usdhc/usdhc_ifc.h"

uint8_t readfile[] = "indir/fsproj.h";
uint8_t writefile[] = "fs_test.dat";

#define TEST_FILE_SIZE (1024*1024*16)
#define DeviceNum 0

extern void print_media_fat_info(uint32_t);

hw_module_t count_timer = {
    "EPIT2 for system tick",
    2,
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    NULL,
    NULL
};

int fat_write_speed_test(void)
{
	uint8_t *WriteBuffer = NULL;
    uint32_t ClusterSize = 0, BytesWritten = 0;
    uint32_t TimeCount = 0;
	int32_t i = 0, count = 0;
	int32_t fout;
	
    printf("FSInit				");
    if (FSInit(NULL, bufy, maxdevices, maxhandles, maxcaches) != SUCCESS) {
        printf("FAIL\n");
		return ERROR_GENERIC;
    } else {
        printf("PASS\n");
    }

    /*init the drive */
    FSDriveInit(DeviceNum);
    SetCWDHandle(DeviceNum);


    print_media_fat_info(DeviceNum);

    if ((fout = Fopen(writefile, (uint8_t *) "wb+")) < 0) {
        printf("Can't open the file: %s !\n", writefile);
        return ERROR_GENERIC;
    }

    ClusterSize = MediaTable[DeviceNum].SectorsPerCluster * MediaTable[DeviceNum].BytesPerSector;
	WriteBuffer = (uint8_t *)malloc(ClusterSize);
    if (WriteBuffer == NULL) {
        printf("Allocating buffer failed!\n");
        return ERROR_GENERIC;
    }
	for(i = 0; i < ClusterSize; i++){
		*WriteBuffer = (uint8_t)i;
	}

    count_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&count_timer, CLKSRC_IPG_CLK, count_timer.freq / 1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&count_timer, FALSE);
    epit_counter_enable(&count_timer, 0xFFFFFFFF, 0);   //polling mode

    SDHC_ADMA_mode = 1;
    SDHC_INTR_mode = 0;

	while(BytesWritten < TEST_FILE_SIZE){
		if((count = Fwrite(fout, WriteBuffer, ClusterSize)) != ClusterSize){
			printf("Fwrite failed. Exit.\n");
            Fclose(fout);
            return ERROR_GENERIC;
		}	
		BytesWritten += count;
		printf(".");
	}

    TimeCount = epit_get_counter_value(&count_timer);
    epit_counter_disable(&count_timer); //polling mode

    free(WriteBuffer);
    Fclose(fout);
    FlushCache();

    printf("\n*****************File Reading End********************\n");
    TimeCount = (0xFFFFFFFF - TimeCount) / 1000;    //ms
    printf("Total data written %d, time %d ms\n", GetFileSize(fout), TimeCount);

	return 0;
}

int fat_read_speed_test(void)
{
    int count = 0;
    int TestResult = 0;
    int32_t fin;
    uint8_t *ReadBuffer;
    uint32_t ClusterSize = 0, FileSize = 0;
    int ChunkSize = 0x80000;
    uint8_t readfile[] = "indir/fslclip.264";
    int ReadSize = 0;
    uint32_t TimeCount = 0;

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

    if ((fin = Fopen(readfile, (uint8_t *) "r")) < 0) {
        printf("Can't open the file: %s !\n", readfile);
        return ERROR_GENERIC;
    }

    FileSize = GetFileSize(fin);
    printf("File %s of size %d opened!\n", readfile, FileSize);

    ClusterSize = MediaTable[DeviceNum].SectorsPerCluster * MediaTable[DeviceNum].BytesPerSector;
    ReadBuffer = (uint8_t *) malloc(ChunkSize);
    if (ReadBuffer == NULL) {
        printf("Allocating buffer failed!\n");
        return ERROR_GENERIC;
    }

    count_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&count_timer, CLKSRC_IPG_CLK, count_timer.freq / 1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&count_timer, FALSE);
    epit_counter_enable(&count_timer, 0xFFFFFFFF, 0);   //polling mode

    SDHC_ADMA_mode = 1;
    SDHC_INTR_mode = 0;
    while (1) {
        if ((count = Fread(fin, ReadBuffer, ChunkSize)) < 0) {
            Fclose(fin);
            return ERROR_GENERIC;
        }

        ReadSize += count;
        if (count < ChunkSize) {
            break;
        }
    }
    TimeCount = epit_get_counter_value(&count_timer);
    epit_counter_disable(&count_timer); //polling mode

    printf("\n*****************File Reading End********************\n");
    TimeCount = (0xFFFFFFFF - TimeCount) / 1000;    //ms
    printf("Total data read %d, time %d ms\n", ReadSize, TimeCount);

    free(ReadBuffer);
    Fclose(fin);
    FlushCache();
    return 0;
}

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

    if ((fin = Fopen(readfile, (uint8_t *) "r")) < 0) {
        printf("Can't open the file: %s !\n", readfile);
        return ERROR_GENERIC;
    }

    FileSize = GetFileSize(fin);
    printf("File %s of size %d opened!\n", readfile, FileSize);

    ClusterSize = MediaTable[DeviceNum].SectorsPerCluster * MediaTable[DeviceNum].BytesPerSector;
    ReadBuffer = (uint8_t *) malloc(FileSize + 1);
    printf("%X\n", ReadBuffer);
    memset(ReadBuffer, '\0', FileSize + 1);

    if ((count = Fread(fin, ReadBuffer, FileSize)) < 0) {
        Fclose(fin);
        return ERROR_GENERIC;
    } else {
        printf("%s\n", ReadBuffer);
    }

    printf("\n*****************File Reading End********************\n");

    free(ReadBuffer);
    Fclose(fin);
    FlushCache();
    return 0;
}
