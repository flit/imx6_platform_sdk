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
    u32 active_window_left_offset;  // 

} _IPS_display_obj_t;

/*--------------------------------- functions -------------------------------------*/
#endif
