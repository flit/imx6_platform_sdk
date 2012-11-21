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
#include "core/cortex_a9.h"
#include "core/mmu.h"

//#define FS_DEBUG
#ifdef FS_DEBUG
#define dbprintf(fmt, arg...) printf(fmt, ##arg)
#else
#define dbprintf(fmt, ...)
#endif

#define FS_CHUNK_SIZE_512B      512
#define FS_CHUNK_SIZE_1K          1024
#define FS_CHUNK_SIZE_4K          (1024*4)
#define FS_CHUNK_SIZE_32K        (1024*32)
#define FS_CHUNK_SIZE_1M        (1024*1024)
#define FS_CHUNK_SIZE_4M        (1024*1024*4)
#define FS_CHUNK_SIZE_16M        (1024*1024*16)

typedef struct fs_rw_speed_data_s {
    int WorkMode;               // PIO or ADMA
    int ChunkSize;
    int ReadSpeed;
    int WriteSpeed;
} fs_rw_speed_data_t;
char test_mode[2][8] = { "PIO", "ADMA" };
fs_rw_speed_data_t rw_test_data[] = {
    {.WorkMode = 0,.ChunkSize = FS_CHUNK_SIZE_512B,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 0,.ChunkSize = FS_CHUNK_SIZE_1K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 0,.ChunkSize = FS_CHUNK_SIZE_4K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 0,.ChunkSize = FS_CHUNK_SIZE_32K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 0,.ChunkSize = FS_CHUNK_SIZE_1M,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 1,.ChunkSize = FS_CHUNK_SIZE_512B,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 1,.ChunkSize = FS_CHUNK_SIZE_1K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 1,.ChunkSize = FS_CHUNK_SIZE_4K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 1,.ChunkSize = FS_CHUNK_SIZE_32K,.ReadSpeed = 0,.WriteSpeed = 0},
    {.WorkMode = 1,.ChunkSize = FS_CHUNK_SIZE_1M,.ReadSpeed = 0,.WriteSpeed = 0}
};

uint8_t readfile[] = "testin.dat";
uint8_t writefile[] = "testoutx.dat";
#define TEST_BUFFER_ADDR 0x28000000
#define CHUNCK_SIZE (1024*4)
#define TEST_FILE_SIZE FS_CHUNK_SIZE_16M
#define DeviceNum 0

hw_module_t count_timer = {
    "EPIT2 for system tick",
    2,
    EPIT2_BASE_ADDR,
    27000000,
    IMX_INT_EPIT2,
    NULL,
    NULL
};

extern void print_media_fat_info(uint32_t);

int fat_write_speed_test(fs_rw_speed_data_t * test_data, int i)
{
    uint8_t *WriteBuffer = NULL;
    uint32_t ClusterSize = 0, BytesWritten = 0;
    uint32_t TimeCount = 0;
    uint32_t ChunkSize = test_data->ChunkSize;
    int32_t count = 0;
    int32_t fout;

    char *buf = (char *)memchr(writefile, '.', strlen((char *)writefile));
    buf[-1] = (char)('0' + i);

    if ((fout = Fopen(writefile, (uint8_t *) "w")) < 0) {
        printf("Can't open the file: %s !\n", writefile);
        return ERROR_GENERIC;
    }

    ClusterSize = MediaTable[DeviceNum].SectorsPerCluster * MediaTable[DeviceNum].BytesPerSector;
    WriteBuffer = (uint8_t *) TEST_BUFFER_ADDR;

    count_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&count_timer, CLKSRC_IPG_CLK, count_timer.freq / 1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&count_timer, FALSE);
    epit_counter_enable(&count_timer, 0xFFFFFFFF, 0);   //polling mode

    SDHC_ADMA_mode = test_data->WorkMode;
    SDHC_INTR_mode = 0;

    while (BytesWritten < TEST_FILE_SIZE) {
        if ((count =
             Fwrite(fout, (uint8_t *) (WriteBuffer + BytesWritten), ChunkSize)) != ChunkSize) {
            printf("Fwrite failed. Exit.\n");
            Fclose(fout);
            return ERROR_GENERIC;
        }
        BytesWritten += count;
    }

    TimeCount = epit_get_counter_value(&count_timer);
    epit_counter_disable(&count_timer); //polling mode

    printf("\n*****************%d File Writing End********************\n", i);
    TimeCount = (0xFFFFFFFF - TimeCount) / 1000;    //ms
    printf("Total data written %d Bytes, time %d ms\n", BytesWritten, TimeCount);

    test_data->WriteSpeed = (BytesWritten / 1024 * 1000) / TimeCount;

    Fclose(fout);

    return 0;
}

int fat_read_speed_test(fs_rw_speed_data_t * test_data, int i)
{
    int count = 0;
    int32_t fin;
    uint8_t *ReadBuffer;
    uint32_t FileSize = 0;
    int ChunkSize = test_data->ChunkSize;
    int ReadSize = 0;
    uint32_t TimeCount = 0;

    if ((fin = Fopen(readfile, (uint8_t *) "r")) < 0) {
        printf("Can't open the file: %s !\n", readfile);
        return ERROR_GENERIC;
    }

    FileSize = GetFileSize(fin);
    dbprintf("File %s of size %d opened!\n", readfile, FileSize);

    ReadBuffer = (uint8_t *) TEST_BUFFER_ADDR;

    count_timer.freq = get_main_clock(IPG_CLK);
    epit_init(&count_timer, CLKSRC_IPG_CLK, count_timer.freq / 1000000,
              SET_AND_FORGET, 10000, WAIT_MODE_EN | STOP_MODE_EN);
    epit_setup_interrupt(&count_timer, FALSE);
    epit_counter_enable(&count_timer, 0xFFFFFFFF, 0);   //polling mode

    SDHC_ADMA_mode = test_data->WorkMode;
    SDHC_INTR_mode = 0;
    while (ReadSize < TEST_FILE_SIZE) {
        if ((count = Fread(fin, (uint8_t *) (ReadBuffer + ReadSize), ChunkSize)) < 0) {
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

    printf("\n*****************%d File Reading End********************\n", i);
    TimeCount = (0xFFFFFFFF - TimeCount) / 1000;    //ms
    printf("Total data read %d Bytes, time %d ms\n", ReadSize, TimeCount);
    test_data->ReadSpeed = (ReadSize / 1024 * 1000) / TimeCount;

    Fclose(fin);
    return 0;
}

void dump_test_results(void)
{
    int i = sizeof(rw_test_data) / sizeof(rw_test_data[0]);
    printf("_______________________________________________________________________\n");
    printf("R/W Size\tTest Mode\tPer Access Size\t\tRead Speed\tWrite Speed\n");
    while (--i >= 0) {
        printf("%4dMB\t\t%s\t\t%8dB\t %8dKB\t %8dKB\n", TEST_FILE_SIZE / 1024 / 1024,
               test_mode[rw_test_data[i].WorkMode], rw_test_data[i].ChunkSize,
               rw_test_data[i].ReadSpeed, rw_test_data[i].WriteSpeed);
    }
    printf("_______________________________________________________________________\n");
}

int fat_test(void)
{
    int TestResult = 0;
    int i = sizeof(rw_test_data) / sizeof(rw_test_data[0]);

    /* configure cache */
    arm_icache_enable();
    arm_dcache_invalidate();
    mmu_disable();
    arm_dcache_disable();
    
    dbprintf("FSInit				");
    if (FSInit(NULL, bufy, maxdevices, maxhandles, maxcaches) != SUCCESS) {
        TestResult = -1;
        dbprintf("FAIL\n");
    } else {
        dbprintf("PASS\n");
    }

    /*init the drive */
    FSDriveInit(DeviceNum);
    SetCWDHandle(DeviceNum);

#ifdef FS_DEBUG
    print_media_fat_info(DeviceNum);
#endif

    while (--i >= 0) {
        /*read input file to TEST BUFFER */
        fat_read_speed_test(&rw_test_data[i], i);

        /*Dump the test buffer to SD card */
        fat_write_speed_test(&rw_test_data[i], i);
    }

    dump_test_results();

    return 0;
}
