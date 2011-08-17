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
    if (ims == NULL) {
        printf("Memory malloc error!!\n");
        return NULL;
    } else {
        memset(ims, 0, sizeof(ips_image_stream_t));
    }
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
    return ims;
}

void ips_delete_ims(ips_image_stream_t * ims)
{
    free(ims);
}

void ips_set_ims(ips_image_stream_t * ims, uint32_t attr, uint32_t val, ...)
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
    mem->out_ims = ims;
    ips_update_ims_attr_params(ims, OFFSETOF(ips_image_stream_t, base0), buffer->base_addr_0);
    ips_update_ims_attr_params(ims, OFFSETOF(ips_image_stream_t, base1), buffer->base_addr_1);
}

void stream_on(ips_flow_t * flow)
{
    ipu_enable_display(1);
}

int ips_flow_add_device(ips_flow_t * flow, ips_device_t * dev)
{
    ips_node_t *temp, *tail;

    if (dev == NULL)
        return false;

    if (flow->head == NULL) {
        tail = flow->head;
    } else {

        tail = flow->head;
        while (tail != NULL) {
            if (!strcmp(dev->devname, ((ips_device_t *) tail->pointer)->devname)) {
                printf("the device %s has been added into the flow already!\n", dev->devname);
                return true;
            }
            temp = tail;
            tail = tail->next;  // find the last element
        }
        tail = temp;
    }

    temp = malloc(sizeof(ips_node_t));
    temp->pointer = dev;
    temp->next = NULL;

    if (flow->head == NULL) {
        flow->head = temp;
        flow->head->prev = flow->head->next = NULL;
    } else {
        tail->next = temp;
        temp->prev = tail;
    }

    dev->parent_flow_id = flow->flow_id;
    printf("the device %s is added into the flow!!\n", dev->devname);
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

int ips_flow_set_conf_data(ips_flow_t * flow)
{
    int layeridx = 0;
    ips_device_t *dev;
    ips_node_t *temp;
    ips_hw_conf_struct_t *conf = flow->conf_data;

    /*clean the configuration data structure */
    memset(conf, 0, sizeof(ips_hw_conf_struct_t));
    layeridx = 0;
    /*the flow should contain at least a device or a supper device */
    temp = flow->head;
    while (temp != NULL) {
        dev = temp->pointer;
        temp = temp->next;
        switch (dev->devtype) {
        case IPS_DEV_MEM:
            if (((ips_pad_t *) dev->srcpadlist->pointer)->next != NULL) //the memory device is a source
            {
                ips_image_stream_t *ims =
                    (ips_image_stream_t *) ((ips_dev_memory_t *) dev->devattr)->out_ims;
                layeridx = ((ips_dev_memory_t *) dev->devattr)->layer_id;
                conf->input.layer[layeridx].colorimetry = ims->pixel_format;
                conf->input.layer[layeridx].width = ims->width;
                conf->input.layer[layeridx].height = ims->height;
                conf->input.layer[layeridx].buffer_num =
                    ((ips_dev_memory_t *) dev->devattr)->number_frame_buf;
                conf->input.layer[layeridx].buffer_addr[0] = ims->base0;
                conf->input.layer[layeridx].buffer_addr[1] = ims->base1;
                conf->input.layer[layeridx].curr_buf = 0;
                conf->input.layer[layeridx].interlaced = 0;
                conf->input.layer_num++;
                layeridx++;
            } else if (((ips_pad_t *) dev->sinkpadlist->pointer)->prev != NULL) {
                ips_image_stream_t *ims =
                    (ips_image_stream_t *) ((ips_dev_memory_t *) dev->devattr)->in_ims;

                conf->output.mem.colorimetry = ims->pixel_format;
                conf->output.mem.width = ims->width;
                conf->output.mem.height = ims->height;
                conf->output.mem.buffer_num = ((ips_dev_memory_t *) dev->devattr)->number_frame_buf;
                conf->output.mem.buffer_addr[0] = ims->base0;
                conf->output.mem.buffer_addr[1] = ims->base1;
                conf->output.mem.interlaced = 0;
                conf->flow_type = MEM_TO_DISPLAY;

            } else {
                printf("The pad of the memory %s is not linked to any other device!!\n",
                       dev->devname);
                return false;
            }

            break;
        case IPS_DEV_DISPLAY:
            {
                ips_dev_display_t *disp = (ips_dev_display_t *) dev->devattr;
                conf->output.disp.colorimetry = disp->colorimetry;
                conf->output.disp.refresh_rate = 60;
                conf->output.disp.width = disp->frame_width;
                conf->output.disp.height = disp->frame_height;
                conf->output.disp.pixel_clock = disp->disp_clock_freq;
                conf->output.disp.hsync_start_width = disp->h_active_start;
                conf->output.disp.hsync_width = disp->h_sync_width;
                conf->output.disp.hsync_end_width = disp->h_active_end;
                conf->output.disp.vsync_start_width = disp->v_active_start;
                conf->output.disp.vsync_width = disp->v_sync_width;
                conf->output.disp.vsync_end_width = disp->v_active_end;
                conf->output.disp.delay_h2v = disp->if_param_ptr->v_to_h_sync;
                conf->output.disp.interlaced = 0;
                conf->output.disp.clk_pol = disp->disp_clk_pol;
                conf->output.disp.hsync_sel = disp->if_param_ptr->hsync_pin;
                conf->output.disp.hsync_pol = disp->if_param_ptr->hsync_pol;
                conf->output.disp.vsync_sel = disp->if_param_ptr->vsync_pin;
                conf->output.disp.vsync_pol = disp->if_param_ptr->vsync_pol;
                conf->output.disp.drdy_pol = disp->if_param_ptr->enable_pol;
                conf->output.disp.data_pol = disp->if_param_ptr->data_pol;
                conf->output.disp.di = disp->if_param_ptr->hw_if;
                conf->output.disp.clk_src = disp->if_param_ptr->ext_pclk;
                conf->flow_type = MEM_TO_DISPLAY;
            }
            break;
        default:
            break;
        }
    }
    return true;
}

ips_flow_t *ips_new_flow(int flow_id, char *flow_name, ips_device_t * dev)
{
    ips_node_t *temp;

    if (ipu_hw_instance[flow_id] != 0) {
        printf("The flow %s has been occupied!!\n", flow_name);
        return NULL;
    }

    /*create an image stream */
    ips_flow_t *flow = (ips_flow_t *) malloc(sizeof(ips_flow_t));
    ips_hw_conf_struct_t *conf_data = (ips_hw_conf_struct_t *) malloc(sizeof(ips_hw_conf_struct_t));

    if (!flow || !conf_data) {
        printf("Memory malloc error!!\n");
        return NULL;
    } else {
        memset(flow, 0, sizeof(ips_flow_t));
        memset(conf_data, 0, sizeof(ips_hw_conf_struct_t));

    }
    flow->flow_id = flow_id;
    flow->flow_name = flow_name;
    flow->flow_status = IPS_FLOW_STATE_NULL;
    flow->conf_data = conf_data;
    flow->head = NULL;

    /*list all the devices included in the flow */
    temp = dev->sinkpadlist;
    while (temp != NULL) {
        ips_flow_add_device(flow, ((ips_pad_t *) temp->pointer)->parent);
        temp = temp->next;
    }
    temp = dev->sinkpadlist;
    while (temp != NULL) {
        ips_flow_add_device(flow, ((ips_pad_t *) temp->pointer)->parent);
        temp = temp->next;
    }

    ips_flow_set_conf_data(flow);
    ipu_hw_instance[flow_id] = 1;

    ips_new_flow_hw_config(1, flow->conf_data);

    return flow;
}

void ips_delete_flow(ips_flow_t * flow)
{
    ips_node_t *temp = flow->head, *temp2;
    while (temp != NULL) {
        flow->head = temp->next;
        free(temp);
        temp = flow->head;

    }
    free(flow);

}
