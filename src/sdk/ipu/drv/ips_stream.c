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

ips_image_stream_t *ips_new_ims(channel)
{
    /*create an image stream */
    ips_image_stream_t *ims = (ips_image_stream_t *) malloc(sizeof(ips_image_stream_t));

    /*initialize the image stream with default settings */
    //TBD
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
        ips_update_attr_params(attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

void ips_set_pad_ims(ips_pad_t pad, ips_image_stream_t ims)
{
}
