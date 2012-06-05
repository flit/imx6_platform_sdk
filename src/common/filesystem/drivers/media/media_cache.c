/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include <types.h>
#include <stdio.h>
#include "drivers/media/media_cache.h"
#include "../../../../sdk/usdhc/inc/usdhc_ifc.h"

extern uint32_t g_usdhc_base_addr;
extern uint8_t read_buf[];

RtStatus_t media_cache_init(uint8_t * cacheBuffer, uint32_t cacheBufferLength){return 0;}
RtStatus_t media_cache_shutdown(void){return 0;}
RtStatus_t media_cache_read(MediaCacheParamBlock_t * pb)
{
    int status, result;
        
    status = card_data_read(g_usdhc_base_addr, (int *)read_buf, pb->requestSectorCount*512,
                       pb->sector*512);
    printf("d %X l %X o %X\n",read_buf,pb->requestSectorCount*512,pb->sector*512);

    if (status == FAIL) {
        printf("%d: SD/MMC data read failed.\n", __LINE__);
        return -1;
    }
    pb->buffer = read_buf;

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
RtStatus_t media_cache_pinned_write(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_flush(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_release(uint32_t token){return 0;}
RtStatus_t media_cache_resume(void){return 0;}
RtStatus_t media_cache_increase(int32_t cacheNumIncreased){return 0;}
RtStatus_t media_cache_DiscardDrive (int32_t iDrive){return 0;}


