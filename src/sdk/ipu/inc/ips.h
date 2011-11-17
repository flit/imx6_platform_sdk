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

#define EOP (0xFFFFFFFF)
#define HIGH_POLARITY 1
#define LOW_POLARITY 0
#define OFFSETOF(type, member) ((size_t)&((type *)0)->member)
#define MAX_BUFF_NUM 4
#define MAX_LAYER_NUM 4

enum {
    SINK_COMP,
    SOURCE_COMP,
    INTERMEDIATE_COMP
};

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
    IPS_DEV_SUPER_DEVICE,
} ips_dev_type_e;

typedef enum {
    Y,                          // Luma component
    U,                          // Chroma component
    V,                          // Chroma component
    R,                          // Red component
    G,                          // Green component
    B,                          // Blue component
    A,                          // Alpha component
    D,                          // Dummy data
    X,                          // Others
} ips_comp_type_e;

typedef enum {
    ASPECT_RATIO_16_9,
    ASPECT_RATIO_4_3,
    ASPECT_RATIO_16_10,
    ASPECT_RATIO_OTHER,
} ips_aspect_ratio_e;

typedef enum {
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
} ips_dma_colorimetry_e;

typedef enum {
    DCMAP_RGB565,
    DCMAP_RGB666,
    DCMAP_RGB666H,
    DCMAP_RGB666L,
    DCMAP_RGB888,
    DCMAP_GBR888,
    DCMAP_BRG888,
    DCMAP_YUV888,
    DCMAP_UVY888,
    DCMAP_VYU888,
    DCMAP_RGBA8888,
    DCMAP_YUVA8888,
} ips_dcmap_colorimetry_e;

enum {
    IPU1_DP_DISP0,              //ipu1, display interface 0 through dp 
    IPU1_DC_DISP0,
    IPU1_DP_DISP1,
    IPU1_DC_DISP1,

    IPU2_DP_DISP0,              //ipu1, display interface 0 through dp background
    IPU2_DC_DISP0,
    IPU2_DP_DISP1,
    IPU2_DC_DISP1,
};

enum disp_dev_flag {
    EPSON_VGA,
    CLAA_WVGA,
    SEIKO_WVGA_7INCH,
    SEIKO_WVGA_4_3INCH,
    AUO_XGA_LVDS,
    HannStar_XGA_LVDS,
    CHIMEI_HD1080_LVDS,
    VGAOUT_XGA,
    DVI_SVGA,
    DVI_XGA,
    DVI_SXGA,
    TV_NTSC,
    TV_PAL,
    TV_720P60,
    TV_1080P30,
    TV_1080P25,
    TV_1080P24,
    TV_1080I60,
    HDMI_480P60,
    HDMI_720P60,
    HDMI_1080P24,
    HDMI_1080P25,
    HDMI_1080P30,
    HDMI_1080P60,
};

typedef enum {
    RGB2YUV,
    YUV2RGB,
    RGB2YUVHR,
    YUV2RGBHR,
    OTHER,
} ips_csc_type_e;

typedef enum {
    MEM_TO_MEM,
    MEM_TO_DISPLAY,
    CSI_TO_MEM,
    CSI_TO_DISPLAY,
} ips_flow_type_e;

typedef struct ips_node {
    void *pointer;
    struct ips_node *prev;
    struct ips_node *next;
} ips_node_t;

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

typedef struct {
    uint32_t channel;           //obselete
    uint32_t aspect_ratio;
    uint32_t background;        //obselete
    uint32_t compress_type;
    uint32_t scan_interface;
    uint32_t frame_rate;
    uint32_t gamma_factor;
    uint32_t gamma_type;
    uint32_t width;
    uint32_t height;
    uint32_t hoffset;
    uint32_t voffset;
    ips_macro_pixel_t macro_pixel0;
    ips_macro_pixel_t macro_pixel1;
    ips_macro_pixel_t macro_pixel2;
    ips_macro_pixel_t macro_pixel3;
    uint32_t base0;             //obselete
    uint32_t base1;             //obselete
    uint32_t pixel_format;
} ips_ims_t;

typedef struct ips_pad_s {
    void *capacity;
    char *padname;
    void *parent;               // pad is an interface of device 
    struct ips_pad_s *next;
    struct ips_pad_s *prev;
} ips_pad_t;

typedef struct {
    uint32_t data_pol;          // Polarity of data bus
    uint32_t enable_pol;        // Polarity of data enable signal (DRDY)
    uint32_t hsync_pol;         // Polarity of HSYNC pulse
    uint32_t v_to_h_sync;       // Offset of VSYNC to HSYNC(in pixels)
    uint32_t vsync_pol;         // Polarity of VSYNC pulse
    uint32_t hw_if;             //to which display interface
    uint32_t hsync_pin;
    uint32_t vsync_pin;
    uint32_t drdy_pin;
    uint32_t ext_pclk;
} ips_display_if_t;

/*display device structure*/
typedef struct {
    uint32_t colorimetry;
    uint32_t disp_clk_pol;
    uint32_t disp_clock_freq;
    uint32_t ext_hsync_en;
    uint32_t ext_vsync_en;
    uint32_t frame_height;
    uint32_t active_window_left_offset;
    uint32_t active_window_top_offset;
    uint32_t frame_width;
    uint32_t h_active_end;
    uint32_t h_active_start;
    uint32_t h_sync_width;
    uint32_t if_type;
    ips_display_if_t *if_param_ptr; // point to the display interfaces definition
    uint32_t v_active_end;
    uint32_t v_active_start;
    uint32_t v_sync_width;
} ips_dev_display_t;

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
    uint32_t layer_id;
    struct {
        uint32_t source;        //RAW or SUBFLOW
        void *subflow_conf;
    } data_source;
    ips_ims_t *ims;
    ips_mem_buffer_addr_t *buffer;
} ips_dev_memory_t;

/*rotation device structure*/
typedef struct {
    uint32_t angle;
} ips_dev_rotate_t;

typedef struct {
    char panel_name[32];
    uint32_t panel_id;
    uint32_t colorimetry;
    uint32_t refresh_rate;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_clock;
    uint32_t hsync_start_width;
    uint32_t hsync_width;
    uint32_t hsync_end_width;
    uint32_t vsync_start_width;
    uint32_t vsync_width;
    uint32_t vsync_end_width;
    uint32_t delay_h2v;
    uint32_t interlaced;
    uint32_t clk_sel;
    uint32_t clk_pol;
    uint32_t hsync_pol;
    uint32_t vsync_pol;
    uint32_t drdy_pol;
    uint32_t data_pol;
    int (*panel_init) (void);
    int (*panel_deinit) (void);
} ips_dev_panel_t;

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
    char *devname;              //device name
    void *parent_bin;           // the device would be added into a flow
    ips_dev_type_e devtype;     // device type
    ips_node_t *srcpadlist;     //a list to maintain the pad members
    ips_node_t *sinkpadlist;    //a list to maintain the pad members
    void *devattr;              //point to the structure of one specified device
    uint32_t devflag;
} ips_device_t;

typedef struct {
    char *binname;
    void *parent_flow;
    ips_node_t *ghost_srcpadlist;
    ips_node_t *ghost_sinkpadlist;
    ips_node_t *devchain;
    void *binattr;
} ips_bin_t;

struct ips_hw_conf_mem_layer {
    uint32_t colorimetry;
    uint32_t width;
    uint32_t height;
    uint32_t buffer_num;
    uint32_t buffer_addr[MAX_BUFF_NUM];
    uint32_t curr_buf;
    uint32_t interlaced;
};

/*now only consider the dual layer*/
struct ips_hw_conf_input {
    uint32_t layer_num;
    struct ips_hw_conf_mem_layer layer[MAX_LAYER_NUM];
//  struct ips_dev_sensor_t csi;
};

typedef struct {
    uint32_t colorimetry;
    uint32_t refresh_rate;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_clock;
    uint32_t hsync_start_width;
    uint32_t hsync_width;
    uint32_t hsync_end_width;
    uint32_t vsync_start_width;
    uint32_t vsync_width;
    uint32_t vsync_end_width;
    uint32_t delay_h2v;
    uint32_t interlaced;
    uint32_t clk_pol;
    uint32_t clk_src;
    uint32_t hsync_sel;
    uint32_t hsync_pol;
    uint32_t vsync_sel;
    uint32_t vsync_pol;
    uint32_t drdy_pol;
    uint32_t data_pol;
    uint32_t extern_vsync;
    uint32_t di;
} ips_output_disp_t;

typedef struct ips_hw_conf_output {
    ips_output_disp_t disp;
    struct ips_hw_conf_mem_layer mem;
} ips_hw_conf_output_t;

typedef struct {
    uint32_t flow_type;
    struct ips_hw_conf_input input;
    struct ips_hw_conf_output output;
} ips_hw_conf_struct_t;

typedef struct {
    char *flow_name;
    uint32_t flow_id;
    uint32_t flow_status;
    ips_bin_t *bin;
    ips_hw_conf_struct_t *conf_data;
} ips_flow_t;

extern ips_dev_panel_t disp_dev_list[];
extern uint32_t num_of_panels;

ips_device_t *ips_new_device(ips_dev_type_e devtype, char *devname);
void ips_delete_device(ips_device_t * dev);
void ips_set_attr_params(void *obj, uint32_t attr_offset, uint32_t val);
void ips_set_device(void *dev_attr, uint32_t attr, uint32_t val, ...);
ips_pad_t *ips_device_get_src_pad(ips_device_t * dev, const char *padname);
ips_pad_t *ips_device_get_sink_pad(ips_device_t * dev, const char *padname);
int ips_link_device_many(ips_device_t * dev1, char *outpad, char *inpad, ips_device_t * dev2, ...);
ips_bin_t *ips_new_bin(char *binname);
int ips_bin_add_device_many(ips_bin_t * bin, ips_device_t * dev1, ...);
ips_ims_t *ips_new_ims(void);
void ips_delete_ims(ips_ims_t * ims);
void ips_set_ims(ips_ims_t * ims, uint32_t attr, uint32_t val, ...);
void ips_set_pad_ims(ips_pad_t * pad, ips_ims_t * ims);
void stream_on(ips_flow_t * flow);
int ips_flow_set_conf_data(ips_flow_t * flow);
ips_flow_t *ips_new_flow(int flow_id, char *flow_name, ips_bin_t * bin);
void ips_delete_flow(ips_flow_t * flow);
int ips_device_add_src_pad(ips_device_t * dev, char *padname);
int ips_device_add_sink_pad(ips_device_t * dev, char *padname);
void ips_new_flow_hw_config(int ipu_index, ips_hw_conf_struct_t * conf);

#endif
