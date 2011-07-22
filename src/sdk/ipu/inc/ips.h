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
typedef enum {
    IPS_FLOW_STATE_NULL,
    IPS_FLOW_STATE_READY,
    IPS_FLOW_STATE_PAUSED,
    IPU_FLOW_STATE_PLAYING
} _IPS_FLOW_STATE_e;

/*-------------------------------- object structs -------------------------------*/
typedef struct {
    u32 bus_width;              // up to 48bit
    u32 disp_clk_pol;           // polarity of display clock: OFF, ON
    u32 disp_clock_freq;        // up to 500MHz
    u32 ext_hsync_en;           // synchronization with external HSYNC: OFF, ON
    u32 ext_vsync_en;           // syncrhonization with external VYSNC: OFF, ON
    u32 total_frame_height;     // shows display height(in lines). up to 0x4000
    u32 active_window_left_offset;  // 1, Frame of left corner (in pixels) position of active window
    // 2, Display of inactive pixels is not
    // up to 0x4000
    u32 active_window_top_offset;   // 1, Frame of top corner (in pixels) position of active window
    // 2, Display of inactive pixels is not
    // up to 0x4000
    u32 total_frame_width;      // shows display width(in lines). up to 0x4000  
    u32 h_active_end;           // Marks time period (in pixels) between last active pixel 
    // in the refresh line and new HSYNC. up to 0x4000
    u32 h_active_start;         // Marks time period (in pixels) between HSYNC pulse 
    // and first active pixel in the refreshed line . up to 0x4000
    u32 h_sync_width;           // Marks width of HSYNC pulse.
    u32 if_type;                // select from list: BT1120, BT656, EAI861, JPEG, Sys8080, sys68
    u32 *if_param_ptr;          // Pointer to interface specific parameter structure.
    u32 v_active_end;           // Marks time period (in refreshed lines) between last active line and
    // new VSYNC. up to 0x4000  
    u32 v_active_start;         // Marks time period (in refreshed lines) between VSYNC pulse and first
    // active line in the frame. up to 0x4000
    u32 v_sync_width;           // Marks width of VSYNC pulse. up to 0x4000 

} _IPS_display_obj_t;

typedef struct {
    u32 data_pol;               // Polarity of data bus: OFF, ON
    u32 enable_pol;             // Polarity of data enable signal (DRDY): OFF, ON
    u32 h_sync_pol;             // Polarity of HSYNC pulse: OFF, ON
    u32 v_to_h_sync;            // Offset of VSYNC to HSYNC (in pixels). up to 0x4000
    u32 vsync_pol;              // Polarity of VSYNC pulse: OFF, ON

} _IPS_display_if_t;

/*--------------------------------- functions -------------------------------------*/

#endif
