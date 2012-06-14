/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <types.h>
#include <stdio.h>
#include <string.h>
#include "drivers/media/media_cache.h"
#include "../../../../sdk/usdhc/inc/usdhc_ifc.h"

extern uint32_t g_usdhc_base_addr;
extern uint8_t read_buf[];

#define BYTES_PER_SECTOR 512
#define CACHE_SIZE 1024*BYTES_PER_SECTOR
uint8_t g_cache_buf[CACHE_SIZE];
uint32_t g_start_sector = 0xFFFFFFFF;

uint8_t g_fat_sector_cache_buf[512];
uint8_t g_fat_loc = 0;

RtStatus_t media_cache_read(MediaCacheParamBlock_t * pb)
{
    int status, result, rq_sector, sector_offset;

    rq_sector = pb->sector * BYTES_PER_SECTOR;

    if(rq_sector == 0xD600)
    {
        if(g_fat_loc == 0)
        {
            status = card_data_read(g_usdhc_base_addr, (int *)g_fat_sector_cache_buf,
                            pb->requestSectorCount * 512, pb->sector*512);
            if (status == 1) {
                return -1;
            }
            g_fat_loc = 1;
        }
        pb->buffer = g_fat_sector_cache_buf;
    }
    else if((g_start_sector == 0xFFFFFFFF) || (rq_sector > (g_start_sector + CACHE_SIZE)) || (rq_sector < g_start_sector))
    {
        status = card_data_read(g_usdhc_base_addr, (int *)g_cache_buf, CACHE_SIZE, rq_sector);
        printf("l %X o %X\n",CACHE_SIZE,pb->sector*512);

        if (status == FAIL) {
            printf("%d: SD/MMC data read failed.\n", __LINE__);
            return -1;
        }

        g_start_sector = rq_sector;
        pb->buffer = g_cache_buf;

        /* Wait for transfer complete */
        if (SDHC_INTR_mode == 0) {
            do {
                card_xfer_result(g_usdhc_base_addr, &result);
            } while (result == 0);
        
            if (result == 2) {
                printf("%d: Error status caught.\n", __LINE__);
                return -1;
            }
        }
    }
    else
    {
        sector_offset = rq_sector - g_start_sector;
        pb->buffer = g_cache_buf + sector_offset;
    }

	return 0;
}


RtStatus_t media_cache_write(MediaCacheParamBlock_t * pb)
{
#if 0
    MediaCacheParamBlock_t pb = {0};
    pb.drive = deviceNumber;
    pb.sector = sectorNumber;
    pb.buffer = sourceBuffer + sourceOffset;
    pb.writeOffset = destOffset;
    pb.writeByteCount = numBytesToWrite;
    pb.mode = writeType;
    pb.weight = GetSectorWeight(deviceNumber, sectorNumber);
    pb.flags = kMediaCacheFlag_ApplyWeight;
		card_data_write(g_usdhc_base_addr, (int *)pb->buffer, pb->requestSectorCount * 512,
                       pb->sector*512);
#endif

	return 0;
}

RtStatus_t media_cache_init(uint8_t * cacheBuffer, uint32_t cacheBufferLength){return 0;}
RtStatus_t media_cache_shutdown(void){return 0;}
RtStatus_t media_cache_pinned_write(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_flush(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_release(uint32_t token){return 0;}
RtStatus_t media_cache_resume(void){return 0;}
RtStatus_t media_cache_increase(int32_t cacheNumIncreased){return 0;}
RtStatus_t media_cache_DiscardDrive (int32_t iDrive){return 0;}


