/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips.h
 * @brief IPU Software library macros, structures and functions 
 */

#ifndef _IPS_H_
#define _IPS_H_

#include <stdarg.h>
#include "hardware.h"
#include "functions.h"

#define EOP (0xFFFFFFFF)
#define HIGH_POLARITY 1
#define LOW_POLARITY 0

/*ips flow status enumeration*/
typedef enum {
    IPS_FLOW_STATE_NULL,
    IPS_FLOW_STATE_READY,
    IPS_FLOW_STATE_PAUSED,
    IPS_FLOW_STATE_PLAYING
} ips_flow_state_e;

typedef enum {
    IPS_NO_ROTATE,
    IPS_ROTATE_90,
    IPS_ROTATE_180,
    IPS_ROTATE_270,
} ips_rotate_angle_e;

typedef enum {
    IPS_DEV_SENSOR,
    IPS_DEV_DISPLAY,
    IPS_DEV_MEM,
    IPS_DEV_VPU,
    IPS_DEV_IPU,
    IPS_DEV_COMBINER,
    IPS_DEV_DEINTERLACE,
    IPS_DEV_RESIZE,
    IPS_DEV_ROTATE,
    IPS_DEV_CROPPER,
    IPS_DEV_FLIP,
    IPS_DEV_SCROLL,
    IPS_DEV_FR_CONVERTER,
    IPS_DEV_FORMAT_CONVERTER,
    IPS_DEV_GAMMA,
    IPS_DEV_UNGAMMA,
    IPS_DEV_GAMUT_MAPPING,
    IPS_DEV_COMPANDER,
    IPS_DEV_GAIN_ADJ,
    IPS_DEV_BRIGHTNESS,
    IPS_DEV_SHARPENING,
    IPS_DEV_DENOISE,
    IPS_DEV_SPLITTER,
    IPS_DEV_MERGE,
    IPS_DEV_COMPRESSOR,
} ips_dev_type_e;

typedef enum {
    Y,
    U,
    V,
    R,
    G,
    B,
    A,
    D,
    X,
} ips_comp_type_e;

typedef struct {
    ips_comp_type_e type;
    uint32_t pixel_index;
    uint32_t start;
    uint32_t end;
} ips_comp_slice_t;

typedef struct {
    uint32_t odd_slice_num;
    uint32_t even_slice_num;
    ips_comp_slice_t *odd;
    ips_comp_slice_t *even;
} ips_macro_pixel_t;

enum {
    ASPECT_RATIO_16_9,
    ASPECT_RATIO_4_3,
    ASPECT_RATIO_16_10,
    ASPECT_RATIO_OTHER,
};

enum {
    NON_INTERLEAVED_YUV444 = 0x0,
    NON_INTERLEAVED_YUV422 = 0x1,
    NON_INTERLEAVED_YUV420 = 0x2,
    PARTIAL_INTERLEAVED_YUV422 = 0x3,
    PARTIAL_INTERLEAVED_YUV420 = 0x4,
    INTERLEAVED_LUT = 0x5,
    INTERLEAVED_GENERIC = 0x6,
    INTERLEAVED_RGB = 0x7,
    INTERLEAVED_Y1U1Y2V1 = 0x8,
    INTERLEAVED_Y2U1Y1V1 = 0x9,
    INTERLEAVED_U1Y1V1Y2 = 0xA,
    INTERLEAVED_U1Y2V1Y1 = 0xB,
};

typedef struct {
    uint32_t channel;
    uint32_t aspect_ratio;
    uint32_t background;
    uint32_t compress_type;
    uint32_t scan_interface;
    uint32_t frame_rate;
    uint32_t gamma_factor;
    uint32_t gamma_type;
    uint32_t width;
    uint32_t height;
    ips_macro_pixel_t macro_pixel0;
    ips_macro_pixel_t macro_pixel1;
    ips_macro_pixel_t macro_pixel2;
    ips_macro_pixel_t macro_pixel3;
    uint32_t pixel_format;
} ips_image_stream_t;

typedef struct {
    void *data_pointer;
    struct ips_pad_s *next;
    struct ips_pad_s *prev;
} ips_pad_t;

typedef struct {
    void *data_pointer;
} ips_flow_t;

/*display device structure*/
typedef struct {
    uint32_t bus_width;
    uint32_t disp_clk_pol;
    uint32_t disp_clock_freq;
    uint32_t ext_hsync_en;
    uint32_t ext_vsync_en;
    uint32_t total_frame_height;
    uint32_t active_window_left_offset;
    uint32_t active_window_top_offset;
    uint32_t total_frame_width;
    uint32_t h_active_end;
    uint32_t h_active_start;
    uint32_t h_sync_width;
    uint32_t if_type;
    uint32_t *if_param_ptr;     // point to the display interfaces definition
    uint32_t v_active_end;
    uint32_t v_active_start;
    uint32_t v_sync_width;
} ips_dev_display_t;

struct ips_display_if_s {
    uint32_t data_pol;          // Polarity of data bus
    uint32_t enable_pol;        // Polarity of data enable signal (DRDY)
    uint32_t h_sync_pol;        // Polarity of HSYNC pulse
    uint32_t v_to_h_sync;       // Offset of VSYNC to HSYNC(in pixels)
    uint32_t vsync_pol;         // Polarity of VSYNC pulse
};

/*memory device structure*/
typedef struct {
    uint32_t base_addr_0;       //base address of component 0
    uint32_t base_addr_1;
    uint32_t base_addr_2;
    uint32_t base_addr_3;
} ips_mem_buffer_addr_t;

typedef struct {
    uint32_t active_frame_buf;
    uint32_t number_frame_buf;
    uint32_t stride_line_addr_0;
    uint32_t stride_line_addr_1;
    uint32_t stride_line_addr_2;
    uint32_t stride_line_addr_3;
    ips_mem_buffer_addr_t *buffer;
    ips_image_stream_t *(*create_ims) (int);
} ips_dev_memory_t;

/*rotation device structure*/
typedef struct {
    uint32_t angle;
} ips_dev_rotate_t;

typedef enum {
    RGB2YUV,
    YUV2RGB,
    RGB2YUVHR,
    YUV2RGBHR,
    OTHER,
} ips_csc_type_e;

/*format converter structure*/
typedef struct {
    uint32_t **conv_matrix;
    uint32_t fmt_conversion;
} ips_dev_fmt_convert_t;

/*gamma device*/
typedef struct {
    uint32_t gamma_factor;
    uint32_t gamma_type;
} ips_dev_gamma_t;

/*ipu device structure. ipu is super device combined of several devices */
typedef struct {
    ips_dev_memory_t mem;
    ips_dev_rotate_t rotate;
    ips_dev_display_t disp;
} ips_dev_ipu_t;

typedef struct {
    char *devname;
    ips_dev_type_e devtype;
    uint32_t numsrcpads;
    ips_pad_t *srcpads;
    uint32_t numsinkpads;
    ips_pad_t *sinkpads;
    void *devattr;              //point to the structure of one specified device
} ips_device_t;

#define OFFSETOF(type, member) ((size_t)&((type *)0)->member)

#endif
