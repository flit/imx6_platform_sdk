/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file camera_def.h
 * @brief common macro and data structre defination of camera.
 * @ingroup diag_camera
 */

#ifndef __CAMERA_DEF_H__
#define __CAMERA_DEF_H__

#include "imx_i2c.h"
#include "hardware.h"

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

typedef struct {
    uint16_t addr;
    uint16_t value;
    uint16_t is_16bits;
    uint32_t delay_ms;
    uint8_t verify;
} t_reg_param;

typedef struct {
    t_reg_param *setting;
    int32_t size;
} t_camera_mode;

typedef struct {
    int8_t sensor_name[30];
    uint32_t avdd_mv, dovdd_mv, dvdd_mv;
    int32_t i2c_dev_addr;
    t_reg_param *sensor_detection;
    int32_t sensor_detection_size;
    int32_t mode_id;
    t_camera_mode *modes;
    int32_t auto_focus_enable;
    t_reg_param *af_firmware;
    int32_t af_firmware_size;
    t_reg_param *af_trigger;
    int32_t af_trigger_size;
    t_reg_param *af_ready;
    int32_t af_ready_size;
} t_camera_profile;

enum {
    OV3640_MODE_VGA_640_480_30FPS = 0,
    OV5640_MODE_VGA_640_480_30FPS,
    OV5642_MODE_VGA_640_480_30FPS,
    MT9P111_MODE_VGA_640_480_30FPS,
    CAMERA_MODE_NUM
};

enum {
    OV3640 = 0,
    OV5640,
    OV5642,
    MT9P111,
    SENSOR_NUM
};

extern t_camera_mode camera_modes[CAMERA_MODE_NUM];
extern t_camera_profile camera_profiles[SENSOR_NUM];

extern t_reg_param ov3640_sensor_detection[];
extern t_reg_param ov5640_sensor_detection[];
extern t_reg_param ov5642_sensor_detection[];
extern t_reg_param mt9p111_sensor_detection[];
extern t_reg_param ov3640_mode_vga_640_480_30fps[];
extern t_reg_param ov5640_mode_vga_640_480_30fps[];
extern t_reg_param ov5642_mode_vga_640_480_30fps[];
extern t_reg_param ov5642_af_firmware[];
extern t_reg_param ov5642_af_trigger[];
extern t_reg_param ov5642_af_ready[];
extern t_reg_param mt9p111_mode_vga_640_480_30fps[];
extern t_reg_param mt9p111_af_firmware[];
extern t_reg_param mt9p111_af_trigger[];
extern t_reg_param mt9p111_af_ready[];

void sensor_reset(void);
int32_t sensor_standby(int32_t enable);
void sensor_clock_setting(void);
t_camera_profile *search_sensor(void);
int32_t sensor_config(t_camera_profile * sensor);
int32_t sensor_init(t_camera_profile * sensor);
int32_t sensor_af_trigger(t_camera_profile * sensor);
int32_t sensor_autofocus_init(t_camera_profile * sensor);
int32_t sensor_i2c_init(uint32_t base, uint32_t baud);

#endif
