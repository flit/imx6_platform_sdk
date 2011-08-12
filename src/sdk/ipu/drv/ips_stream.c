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

void stream_on(ips_flow_t * flow)
{
    ipu_enable_display(1);
}

int ips_flow_add_device(ips_flow_t * flow, ips_device_t * dev)
{
    ips_dev_chain_t *temp = malloc(sizeof(ips_dev_chain_t));

    if (dev == NULL)
        return false;

    temp->node = dev;
    temp->next = NULL;

    if (flow->tail == NULL) {
        flow->tail = flow->head = temp;
    } else {
        flow->tail = flow->head->next = temp;
    }

    dev->parent_flow_id = flow->flow_id;

    return true;
}

int ips_flow_add_device_many(ips_flow_t * flow, ips_device_t * dev1, ...)
{
    va_list dev_list;
    int ret = true;

    va_start(dev_list, dev1);
    while (dev1 != NULL) {
        if (!ips_flow_add_device(flow, dev1)) {
            printf("Error in adding device %s to flow %s!!\n", dev1->devname, flow->flow_name);
            ret = false;
            break;
        }
        dev1 = va_arg(dev_list, ips_device_t *);
    }
    va_end(dev_list);
    return ret;
}

void ips_flow_set_conf_data(ips_flow_t * flow)
{
    int layernum = 0;
    ips_device_t *dev;
    /*clean the configuration data structure */
    memset(flow->conf_data, 0, sizeof(ips_hw_conf_struct_t));

    /*the flow should contain at least a device or a supper device */
    dev = flow->head->node;
    while (dev != NULL) {
        switch (dev->devtype) {
        case IPS_DEV_MEM:
            break;
        case IPS_DEV_DISPLAY:
            break;
        }
    }
}

ips_flow_t *ips_new_flow(int flow_id, char *flow_name, ips_device_t * dev)
{
    if (ipu_hw_instance[flow_id] != 0) {
        printf("The flow %s has been occupied!!\n", flow_name);
        return NULL;
    }

    /*create an image stream */
    ips_flow_t *flow = (ips_flow_t *) malloc(sizeof(ips_flow_t));
    ips_hw_conf_struct_t *conf_data = (ips_hw_conf_struct_t *) malloc(sizeof(ips_hw_conf_struct_t));
    ips_dev_chain_t temp;

    flow->flow_id = flow_id;
    flow->flow_name = flow_name;
    flow->flow_status = IPS_FLOW_STATE_NULL;
    flow->conf_data = conf_data;
    ips_flow_set_conf_data(flow);
    ipu_hw_instance[flow_id] = 1;

    return flow;
}

void ips_delete_flow(ips_flow_t * flow)
{
    ips_dev_chain_t *temp = flow->head, *temp2;
    while (temp != flow->tail) {
        flow->head = temp->next;
        free(temp);
        temp = flow->head;

    }
    free(flow);

}
