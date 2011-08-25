/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_flow.c
 * @brief IPU Software library, for flow management .
 * @group diag_ipu
 */
#include <stdarg.h>
#include <ips.h>

/*!
 * create a new ips image stream object. all the parameters will be set as default
 *
 * @return  	return the pointer to the device or NULL if creation failed.
 */
ips_ims_t *ips_new_ims(void)
{
    /*create an image stream */
    ips_ims_t *ims = (ips_ims_t *) malloc(sizeof(ips_ims_t));
    if (ims == NULL) {
        printf("Memory malloc error!!\n");
        return NULL;
    } else {
        memset(ims, 0, sizeof(ips_ims_t));
    }
    /*initialize the image stream with default settings */
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

/*!
 * delete the ips image stream object. 
 *
 * @param   	ims:      pointer to the object
 */
void ips_delete_ims(ips_ims_t * ims)
{
    free(ims);
}

/*!
 * set the parameters of an image stream object. it could include multiple field, and the last
 * parameter must be EOP
 *
 * @param   	ims:      	pointer to the image stream
 * @param 	attr:			offset of the bit fields inside the object
 * @param	val:			updated value
 */
void ips_set_ims(ips_ims_t * ims, uint32_t attr, uint32_t val, ...)
{
    va_list attr_list;

    va_start(attr_list, val);
    while (attr != EOP) {
        ips_set_attr_params(ims, attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

/*!
 * attach the ims with the specified pad.
 *
 * @param   	pad:      	pointer to the pad
 * @param 	ims:		pointer to the image stream
 */
void ips_set_pad_ims(ips_pad_t * pad, ips_ims_t * ims)
{
    ips_device_t *dev = (ips_device_t *) pad->parent;
    ips_dev_memory_t *mem = (ips_dev_memory_t *) dev->devattr;
    ips_mem_buffer_addr_t *buffer = (ips_mem_buffer_addr_t *) mem->buffer;
    mem->ims = ims;
    ips_set_attr_params(ims, OFFSETOF(ips_ims_t, base0), buffer->base_addr_0);
    ips_set_attr_params(ims, OFFSETOF(ips_ims_t, base1), buffer->base_addr_1);
}

extern void ipu_enable_display(int ipu_index);
/*!
 * set the stream to function
 *
 * @param   	flow:      	pointer to the flow
 */
void stream_on(ips_flow_t * flow)
{
    flow->flow_status = IPS_FLOW_STATE_PLAYING;
    ipu_enable_display(1);
}

/*!
 * set the configuration data for HW settings. it is named
 * IPU configuration struture, based on which all the accelerators
 * would be set accrodingly.
 *
 * @param   	flow:      	pointer to the flow
 *
 * @return 	true for success or false for failure
 */
int ips_flow_set_conf_data(ips_flow_t * flow)
{
    int layeridx = 0;
    ips_device_t *dev;
    ips_node_t *temp;
    ips_hw_conf_struct_t *conf = flow->conf_data;

    layeridx = 0;
    /*the flow should contain at least a device or a supper device */
    temp = flow->bin->devchain;
    while (temp != NULL) {
        dev = temp->pointer;
        temp = temp->next;
        switch (dev->devtype) {
        case IPS_DEV_MEM:
            if (((ips_pad_t *) dev->srcpadlist->pointer)->next != NULL) //the memory device is a source
            {
                ips_ims_t *ims = (ips_ims_t *) ((ips_dev_memory_t *) dev->devattr)->ims;
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
            } else if (((ips_pad_t *) dev->sinkpadlist->pointer)->next == NULL) {   //the memory device is a sink
                ips_ims_t *ims = (ips_ims_t *) ((ips_dev_memory_t *) dev->devattr)->ims;

                conf->output.mem.colorimetry = ims->pixel_format;
                conf->output.mem.width = ims->width;
                conf->output.mem.height = ims->height;
                conf->output.mem.buffer_num = ((ips_dev_memory_t *) dev->devattr)->number_frame_buf;
                conf->output.mem.buffer_addr[0] = ims->base0;
                conf->output.mem.buffer_addr[1] = ims->base1;
                conf->output.mem.interlaced = 0;
                conf->flow_type = MEM_TO_MEM;

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

/*!
 * create a new ips flow object over the bin specified. 
 *
 * @param	flow_id:		set the flow id 
 * @param	flow_name:	name of the flow
 * @param	bin:			the pointer to the bin, inside which the flow will run
 *
 * @return  	return the pointer to the flow or NULL if creation failed.
 */
ips_flow_t *ips_new_flow(int flow_id, char *flow_name, ips_bin_t * bin)
{

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
    flow->bin = bin;

    ips_flow_set_conf_data(flow);

    ips_new_flow_hw_config(1, flow->conf_data);

    return flow;
}

/*!
 * delete the ips flow object. 
 *
 * @param   	flow:      pointer to the flow object
 */
void ips_delete_flow(ips_flow_t * flow)
{
    ips_node_t *temp = flow->bin->devchain;
    while (temp != NULL) {
        flow->bin->devchain = temp->next;
        free(temp);
        temp = flow->bin->devchain;
    }
    free(flow);

}
