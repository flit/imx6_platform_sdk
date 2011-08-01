/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_device.c
 * @brief IPU Software library, device management 
 */

/*!
 * create a new ips device.
 * @param  dev: device type
 */
#include "ips.h"

ips_device_t *ips_new_device(ips_dev_type_e devtype)
{
    ips_device_t *device = (ips_device_t *) malloc(sizeof(ips_device_t));
    device->devtype = devtype;
    switch (devtype) {
    case IPS_DEV_DISPLAY:
        {
            ips_dev_display_t *display = (ips_dev_display_t *) malloc(sizeof(ips_dev_display_t));
            /*create an instance of display */
            display->bus_width = 32;
            display->disp_clk_pol = HIGH_POLARITY;
            display->disp_clock_freq = 65000000;    // set 65M as default

            /*attach the device and attribute */
            device->devname = "display";
            device->devattr = display;
            break;
        }

    default:
        printf("The device type is not defined!!\n");
        return false;
    }

    return device;
}

void ips_delete_device(ips_device_t * dev)
{
    free(dev->devattr);
    free(dev);
}

inline void ips_update_attr_params(void *dev, uint32_t attr_offset, uint32_t val)
{
    mem32_write((char *)(dev + attr_offset), val);
}

void ips_set_device(void *dev_attr, uint32_t attr, uint32_t val, ...)
{
    va_list attr_list;
    int ret = true;

    va_start(attr_list, val);
    while (attr != EOP) {
        ips_update_attr_params(dev_attr, attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

ips_pad_t *ips_device_get_src_pad(ips_device_t * dev, const char *padname)
{
}

ips_pad_t *ips_device_get_sink_pad(ips_device_t * dev, const char *padname)
{
}

int ips_link_device_pads(ips_device_t * src, const char *srcpadname, ips_device_t * dest,
                         const char *destpadname)
{
    /*pseudo code */
    ips_pad_t *srcpad, *destpad;

    /*step1: check the validity of input, and get the pad attribute.
       first, one device may have several sinks or sources
       second, check the pad parameters match or not */
    srcpad = ips_device_get_src_pad(src, srcpadname);
    if (!srcpad) {
        printf("No pad named %s found in device %s\n", srcpadname, src->devname);
        return false;
    }

    destpad = ips_device_get_sink_pad(dest, destpadname);
    if (!destpad) {
        printf("No pad named %s found in device %s\n", destpadname, dest->devname);
        return false;
    }

    /*step2: check if the pad attributes match */
    /*TBD - add by Ray */

    /*step3: link the two pads */
    srcpad->next = destpad;
    destpad->prev = srcpad;

    return true;
}

int ips_link_device(ips_device_t * dev1, ips_device_t * dev2)
{
    /*like the pads of the two devices, dev1.src <==> dev2.sink */
    return ips_link_device_pads(dev1, NULL, dev2, NULL);
}
int ips_link_device_many(ips_device_t * dev1, ips_device_t * dev2, ...)
{
    va_list dev_list;
    int ret = true;

    va_start(dev_list, dev2);
    while ((dev2 != NULL) && (dev1 != NULL)) {
        if (!ips_link_device(dev1, dev2)) {
            printf("device link error!!\n");
            ret = false;
            break;
        }
        dev1 = dev2;
        dev2 = va_arg(dev_list, ips_device_t *);
    }
    va_end(dev_list);
    return ret;
}
