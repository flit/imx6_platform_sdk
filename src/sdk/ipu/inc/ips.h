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

#ifndef IPS_H
#define IPS_H

/*--------------------------------- macros --------------------------------------*/
enum ips_flow_state_e {
    IPS_FLOW_STATE_NULL,
    IPS_FLOW_STATE_READY,
    IPS_FLOW_STATE_PAUSED,
    IPS_FLOW_STATE_PLAYING
};

/*-------------------------------- object structs -------------------------------*/
struct ips_display_device_s {
    uint32_t bus_width;         // up to 48bit
    uint32_t disp_clk_pol;      // polarity of display clock: OFF, ON
    uint32_t disp_clock_freq;   // up to 500MHz
    uint32_t ext_hsync_en;      // synchronization with external HSYNC: OFF, ON
    uint32_t ext_vsync_en;      // syncrhonization with external VYSNC: OFF, ON
    uint32_t total_frame_height;    // shows display height(in lines). up to 0x4000
    uint32_t active_window_left_offset; // 1, Frame of left corner (in pixels) position of active window
    // 2, Display of inactive pixels is not
    // up to 0x4000
    uint32_t active_window_top_offset;  // 1, Frame of top corner (in pixels) position of active window
    // 2, Display of inactive pixels is not
    // up to 0x4000
    uint32_t total_frame_width; // shows display width(in lines). up to 0x4000  
    uint32_t h_active_end;      // Marks time period (in pixels) between last active pixel 
    // in the refresh line and new HSYNC. up to 0x4000
    uint32_t h_active_start;    // Marks time period (in pixels) between HSYNC pulse 
    // and first active pixel in the refreshed line . up to 0x4000
    uint32_t h_sync_width;      // Marks width of HSYNC pulse.
    uint32_t if_type;           // select from list: BT1120, BT656, EAI861, JPEG, Sys8080, sys68
    uint32_t *if_param_ptr;     // Pointer to interface specific parameter structure.
    uint32_t v_active_end;      // Marks time period (in refreshed lines) between last active line and
    // new VSYNC. up to 0x4000  
    uint32_t v_active_start;    // Marks time period (in refreshed lines) between VSYNC pulse and first
    // active line in the frame. up to 0x4000
    uint32_t v_sync_width;      // Marks width of VSYNC pulse. up to 0x4000 
};

typedef struct {
    uint32_t data_pol;          // Polarity of data bus: OFF, ON
    uint32_t enable_pol;        // Polarity of data enable signal (DRDY): OFF, ON
    uint32_t h_sync_pol;        // Polarity of HSYNC pulse: OFF, ON
    uint32_t v_to_h_sync;       // Offset of VSYNC to HSYNC (in pixels). up to 0x4000
    uint32_t vsync_pol;         // Polarity of VSYNC pulse: OFF, ON

} _IPS_display_if_t;

/*--------------------------------- functions -------------------------------------*/

#endif
