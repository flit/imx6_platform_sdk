/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "drivers/media/media_cache.h"

RtStatus_t media_cache_init(uint8_t * cacheBuffer, uint32_t cacheBufferLength){return 0;}
RtStatus_t media_cache_shutdown(void){return 0;}
RtStatus_t media_cache_read(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_write(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_pinned_write(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_flush(MediaCacheParamBlock_t * pb){return 0;}
RtStatus_t media_cache_release(uint32_t token){return 0;}
RtStatus_t media_cache_resume(void){return 0;}
RtStatus_t media_cache_increase(int32_t cacheNumIncreased){return 0;}
RtStatus_t media_cache_DiscardDrive (int32_t iDrive){return 0;}


