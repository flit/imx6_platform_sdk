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

/*ips flow status enumeration*/
enum ips_flow_state_e {
    IPS_FLOW_STATE_NULL,
    IPS_FLOW_STATE_READY,
    IPS_FLOW_STATE_PAUSED,
    IPS_FLOW_STATE_PLAYING
};

enum ips_rotate_angle_e {
    IPS_NO_ROTATE;
    IPS_ROTATE_90;
    IPS_ROTATE_180;
    IPS_ROTATE_270;
};

/*!
 * @brief IPS devices description.
 */

/*display device structure*/
struct ips_dev_display_s {
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
};

struct ips_display_if_s {
    uint32_t data_pol;          // Polarity of data bus
    uint32_t enable_pol;        // Polarity of data enable signal (DRDY)
    uint32_t h_sync_pol;        // Polarity of HSYNC pulse
    uint32_t v_to_h_sync;       // Offset of VSYNC to HSYNC(in pixels)
    uint32_t vsync_pol;         // Polarity of VSYNC pulse
};

/*memory device structure*/
struct ips_dev_memory_s {
    uint32_t active_frame_buf;
    uint32_t number_frame_buf;
    uint32_t stride_line_addr_0;
    uint32_t stride_line_addr_1;
    uint32_t stride_line_addr_2;
    uint32_t stride_line_addr_3;
};

/*rotation device structure*/
struct ips_dev_rotate_s {
    uint32_t angle;
}
/*ipu device structure. ipu is super device combined of several devices */ struct ips_dev_memory_s {
    struct ips_dev_memory_s mem;
    struct ips_dev_rotate_s rotate;
    struct ips_dev_resize_s resize;
    struct ips_dev_display_s disp;
};
#endif
