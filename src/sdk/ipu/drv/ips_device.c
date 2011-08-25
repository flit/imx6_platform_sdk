/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_device.c
 * @brief IPU Software library, device management. it is a high-level framework 
 * 	for ipu.
 * @group diag_ipu
 */

#include "ips.h"
#include "ipu_common.h"

/*!
 * create a new ips device object. 
 *
 * @param   	devtype:      specify the device type
 * @param 	devname:	device name
 *
 * @return  	return the pointer to the device or NULL if creation failed.
 */
ips_device_t *ips_new_device(ips_dev_type_e devtype, char *devname)
{
    ips_device_t *device = (ips_device_t *) malloc(sizeof(ips_device_t));
    if (device == NULL) {
        printf("Memory malloc error!!\n");
        return NULL;
    } else {
        memset(device, 0, sizeof(ips_device_t));
    }

    ips_pad_t *pad = NULL;
    ips_node_t *list;
    device->devtype = devtype;
    switch (devtype) {
    case IPS_DEV_DISPLAY:
        {
            ips_dev_display_t *display = (ips_dev_display_t *) malloc(sizeof(ips_dev_display_t));
            if (display == NULL) {
                printf("Memory malloc error!!\n");
                return NULL;
            } else {
                memset(display, 0, sizeof(ips_dev_display_t));
            }
            ips_dev_panel_t *panel = &disp_dev_list[0];
            int index = 0;
            while (index < num_of_panels) {
                if (!strcmp(panel->panel_name, devname)) {
                    break;
                } else {
                    panel++;
                    index++;
                }

            }
            if (index == num_of_panels) {
                printf("The display panel %s is not supported!!\n", devname);
                return false;
            }

            display->colorimetry = panel->colorimetry;
            display->active_window_left_offset = 0;
            display->active_window_top_offset = 0;
            display->disp_clk_pol = panel->clk_pol;
            display->disp_clock_freq = panel->pixel_clock;
            display->ext_hsync_en = 0;
            display->ext_vsync_en = 0;
            display->h_active_start = panel->hsync_start_width;
            display->h_active_end = panel->hsync_end_width;
            display->h_sync_width = panel->hsync_width;
            display->v_active_start = panel->vsync_start_width;
            display->v_active_end = panel->vsync_end_width;
            display->v_sync_width = panel->vsync_width;
            display->if_type = panel->panel_id;
            display->frame_width = panel->width;
            display->frame_height = panel->height;
            display->if_param_ptr = (ips_display_if_t *) malloc(sizeof(ips_display_if_t));
            display->if_param_ptr->data_pol = panel->data_pol;
            display->if_param_ptr->enable_pol = panel->drdy_pol;
            display->if_param_ptr->hsync_pol = panel->hsync_pol;
            display->if_param_ptr->vsync_pol = panel->vsync_pol;
            display->if_param_ptr->v_to_h_sync = panel->delay_h2v;
            display->if_param_ptr->hsync_pin = 1;
            display->if_param_ptr->vsync_pin = 2;
            display->if_param_ptr->hw_if = 0;
            display->if_param_ptr->ext_pclk = 1;

            /*attach the device and attribute */
            device->devname = devname;
            device->devattr = display;
            device->srcpadlist = NULL;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = list->prev = NULL;
            device->sinkpadlist = list;
            pad->padname = "interface";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            panel->panel_init();    //initialize the panel

            break;
        }
    case IPS_DEV_MEM:
        {
            ips_dev_memory_t *mem = (ips_dev_memory_t *) malloc(sizeof(ips_dev_memory_t));
            if (mem == NULL) {
                printf("Memory malloc error!!\n");
                return NULL;
            } else {
                memset(mem, 0, sizeof(ips_dev_memory_t));
            }
            mem->active_frame_buf = 0;
            mem->number_frame_buf = 1;
            ips_mem_buffer_addr_t *buffer =
                (ips_mem_buffer_addr_t *) malloc(sizeof(ips_mem_buffer_addr_t) *
                                                 mem->number_frame_buf);
            memset((void *)buffer, 0, sizeof(ips_mem_buffer_addr_t) * mem->number_frame_buf);
            buffer->base_addr_0 = CH23_EBA0;
            buffer->base_addr_1 = CH23_EBA1;
            mem->buffer = buffer;

            device->devname = devname;
            device->devattr = mem;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "output";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = list->prev = NULL;
            device->srcpadlist = list;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "input";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = list->prev = NULL;
            device->sinkpadlist = list;
        }
        break;
    case IPS_DEV_IPU:
        {
            ips_dev_ipu_t *ipu = (ips_dev_ipu_t *) malloc(sizeof(ips_dev_ipu_t));
            if (ipu == NULL) {
                printf("Memory malloc error!!\n");
                return NULL;
            } else {
                memset(ipu, 0, sizeof(ips_dev_ipu_t));
            }
            /*attach the device and attribute */
            device->devname = devname;
            device->devattr = ipu;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "dcin";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = list->prev = NULL;
            device->sinkpadlist = list;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "dpin";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = NULL;
            list->prev = device->sinkpadlist;
            device->sinkpadlist->next = list;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "di0";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = list->prev = NULL;
            device->srcpadlist = list;

            pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
            pad->padname = "di1";
            pad->parent = device;
            pad->prev = pad->next = NULL;
            list = (ips_node_t *) malloc(sizeof(ips_node_t));
            list->pointer = pad;
            list->next = NULL;
            list->prev = device->srcpadlist->prev;
            device->srcpadlist->next = list;
            break;
        }
    default:
        printf("The device type is not defined!!\n");
        return false;
    }

    return device;
}

/*!
 * delete ips device object. 
 *
 * @param   	dev:      pointer to the device
 */
void ips_delete_device(ips_device_t * dev)
{
    free(dev->devattr);
    free(dev);
}

/*!
 * update the parameters of an object. 
 *
 * @param   	obj:      		pointer to the object, it could be a devie, flow or ims
 * @param 	attr_offset:	offset of the bit fields inside the object
 * @param	val:			updated value
 */
void ips_set_attr_params(void *obj, uint32_t attr_offset, uint32_t val)
{
    mem32_write((char *)obj + attr_offset, val);
}

/*!
 * set the parameters of a device object. it could include multiple field, and the last
 * parameter must be EOP
 *
 * @param   	dev_attr:      	pointer to the device attribute
 * @param 	attr:			offset of the bit fields inside the object
 * @param	val:			updated value
 */
void ips_set_device(void *dev_attr, uint32_t attr, uint32_t val, ...)
{
    va_list attr_list;

    va_start(attr_list, val);
    while (attr != EOP) {
        ips_set_attr_params(dev_attr, attr, val);
        attr = va_arg(attr_list, uint32_t);
        val = va_arg(attr_list, uint32_t);
    }
    va_end(attr_list);
}

/*!
 * get the source pad of a device by name
 *
 * @param   	dev:      		pointer to the device
 * @param 	padname:	name of the pad
 *
 * @return	the pointer to the pad, if search succeed
 *			NULL if search failed.
 */
ips_pad_t *ips_device_get_src_pad(ips_device_t * dev, const char *padname)
{
    ips_node_t *list = dev->srcpadlist;

    while (list != NULL) {
        if (!strcmp(((ips_pad_t *) (list->pointer))->padname, padname))
            return list->pointer;
        list = list->next;

    }
    printf("No source pad named %s can be found!\n", padname);

    return NULL;
}

/*!
 * get the sink pad of a device by name
 *
 * @param   	dev:      		pointer to the device
 * @param 	padname:	name of the pad
 *
 * @return	the pointer to the pad, if search succeed
 *			NULL if search failed.
 */
ips_pad_t *ips_device_get_sink_pad(ips_device_t * dev, const char *padname)
{
    ips_node_t *list = dev->sinkpadlist;

    while (list != NULL) {
        if (!strcmp(((ips_pad_t *) (list->pointer))->padname, padname))
            return list->pointer;
        list = list->next;

    }
    printf("No sink pad named %s can be found!\n", padname);

    return false;
}

/*!
 * add a source pad of a device
 *
 * @param   	dev:      		pointer to the device
 * @param 	padname:	name of the pad
 *
 * @return	true for success and false for failure
 */
int ips_device_add_src_pad(ips_device_t * dev, char *padname)
{
    ips_node_t *tail = dev->srcpadlist, *temp;
    ips_pad_t *pad;

    pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
    pad->padname = padname;
    pad->parent = dev;
    pad->prev = pad->next = NULL;
    temp = (ips_node_t *) malloc(sizeof(ips_node_t));
    temp->pointer = (void *)pad;
    temp->next = NULL;
    if (tail == NULL) {
        tail = temp;
        temp->prev = NULL;
    } else {
        while (tail->next != NULL)
            if (!strcmp(((ips_pad_t *) (tail->pointer))->padname, padname)) {
                printf("device %s already has a pad named %s!\n", dev->devname, padname);
                free(temp);
                free(pad);
                return false;
            } else
                tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;

    return true;
}

/*!
 * add a sink pad of a device
 *
 * @param   	dev:      		pointer to the device
 * @param 	padname:	name of the pad
 *
 * @return	true for success and false for failure
 */
int ips_device_add_sink_pad(ips_device_t * dev, char *padname)
{
    ips_node_t *tail = dev->sinkpadlist, *temp;
    ips_pad_t *pad;

    pad = (ips_pad_t *) malloc(sizeof(ips_pad_t));
    pad->padname = padname;
    pad->parent = dev;
    pad->prev = pad->next = NULL;
    temp = (ips_node_t *) malloc(sizeof(ips_node_t));
    temp->pointer = (void *)pad;
    temp->next = NULL;
    if (tail == NULL) {
        tail = temp;
        temp->prev = NULL;
    } else {
        while (tail->next != NULL)
            if (!strcmp(((ips_pad_t *) (tail->pointer))->padname, padname)) {
                printf("device %s already has a pad named %s!\n", dev->devname, padname);
                free(temp);
                free(pad);
                return false;
            } else
                tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;

    return true;
}

static int ips_link_device(ips_device_t * src, char *srcpadname,
                           char *destpadname, ips_device_t * dest)
{
    int ret = true;
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

    /*step3: link the two pads */
    srcpad->next = destpad;
    destpad->prev = srcpad;

    return ret;
}

/*!
 * link several devices per pads.
 * source pad must be connected with sink pad
 *
 * @param   	dev1:      pointer to the source device
 * @param 	outpad:	name of the source pad
 * @param 	inpad:	name of the sink pad
 * @param   	dev2:      pointer to the sink device
 *
 * @return	true for success and false for failure
 */
int ips_link_device_many(ips_device_t * dev1, char *outpad, char *inpad, ips_device_t * dev2, ...)
{

    va_list dev_list;
    int ret = true;

    va_start(dev_list, dev2);
    while ((dev2 != NULL) && (dev1 != NULL)) {

        if (!ips_link_device(dev1, outpad, inpad, dev2)) {
            printf("device link error!!\n");
            ret = false;
            break;
        }
        dev1 = dev2;
        outpad = va_arg(dev_list, char *);
        if (outpad == NULL)
            break;
        inpad = va_arg(dev_list, char *);
        dev2 = va_arg(dev_list, ips_device_t *);
    }

    va_end(dev_list);

    return ret;
}

inline int is_src_pad(ips_device_t * dev, char *padname)
{
    if (ips_device_get_src_pad(dev, padname) == NULL)
        return true;
    else
        return false;
}

/*!
 * create a new bin object. bin is a collection of devices, it can be
 * regarded as a super device
 *
 * @param 	binname:	   	name of the bin
 *
 * @return  	return the pointer to the bin or NULL if creation failed.
 */
ips_bin_t *ips_new_bin(char *binname)
{
    ips_bin_t *bin = (ips_bin_t *) malloc(sizeof(ips_bin_t));
    if (bin == NULL) {
        printf("Memory malloc error!!\n");
        return NULL;
    } else {
        memset(bin, 0, sizeof(ips_device_t));
    }
    bin->binname = binname;
    bin->parent_flow = NULL;
    bin->ghost_sinkpadlist = bin->ghost_srcpadlist = NULL;
    bin->devchain = NULL;
    bin->binattr = NULL;
    return bin;
}

/*!
 * add several devices into a bin.
 *
 * @param   	bin:      	pointer to the bin
 * @param 	dev1:	device list added into the bin
 *
 * @return	true for success and false for failure
 */
int ips_bin_add_device_many(ips_bin_t * bin, ips_device_t * dev1, ...)
{
    va_list dev_list;
    ips_node_t *temp;
    int ret = true;

    if (bin->devchain == NULL)
        temp = NULL;
    else {
        temp = bin->devchain;
        while (temp->next != NULL)
            temp = temp->next;
    }

    va_start(dev_list, dev1);
    while (dev1 != NULL) {
        if (temp == NULL) {
            ips_node_t *node = (ips_node_t *) malloc(sizeof(ips_node_t));
            node->pointer = dev1;
            node->prev = node->next = NULL;
            bin->devchain = node;
            temp = node;
        } else {
            ips_node_t *node = (ips_node_t *) malloc(sizeof(ips_node_t));
            node->pointer = dev1;
            node->prev = temp;
            node->next = NULL;
            temp->next = node;
            temp = node;
        }
        dev1->parent_bin = (void *)bin;
        dev1 = va_arg(dev_list, ips_device_t *);
    }

    va_end(dev_list);

    return ret;
}
