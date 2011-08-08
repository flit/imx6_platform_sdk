/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_flow.c
 * @brief IPU Software library, for flow management 
 */
#include <stdarg.h>
#include <ips.h>

ips_image_stream_t *ips_new_ims(int channel)
{
    /*create an image stream */
    ips_image_stream_t *ims = (ips_image_stream_t *) malloc(sizeof(ips_image_stream_t));
    int ipu_index = 1;

    /*initialize the image stream with default settings */
    ims->channel = channel;
    ims->aspect_ratio = ASPECT_RATIO_4_3;
    ims->background = 1;
    ims->compress_type = 0;
    ims->scan_interface = 0;
    ims->frame_rate = 60;
    ims->gamma_type = 0;
    ims->gamma_factor = 0;
    ims->width = 1024;
    ims->height = 768;
    ims->pixel_format = INTERLEAVED_RGB;
    ipu_idmac_config(ipu_index, ims);
    return ims;
}

void ips_delete_ims(ips_image_stream_t * ims)
{
    free(ims);
}

void ips_set_ims(void *ims, uint32_t attr, uint32_t val, ...)
{
    va_list attr_list;
    int ret = true;

    va_start(attr_list, val);
    while (attr != EOP) {
        ips_update_ims_attr_params(ims, attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

void ips_set_pad_ims(ips_pad_t * pad, ips_image_stream_t * ims)
{
    ips_device_t *dev = (ips_device_t *) pad->parent;
    ips_dev_memory_t *mem = (ips_dev_memory_t *) dev->devattr;
    ips_mem_buffer_addr_t *buffer = (ips_mem_buffer_addr_t *) mem->buffer;
    ips_update_ims_attr_params(ims, OFFSETOF(ips_image_stream_t, base0), buffer->base_addr_0);
    ips_update_ims_attr_params(ims, OFFSETOF(ips_image_stream_t, base1), buffer->base_addr_1);
}

void stream_on(void)
{
    ipu_enable_display(1);
}
