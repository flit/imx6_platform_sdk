/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sensor_capture.c
 * @brief camera sensor capture and display test.
 * @ingroup diag_camera
 */

#include <stdio.h>
#include "ipu/inc/ipu_common.h"
#include "camera_def.h"
#include "iomux_config.h"
#include "registers/regsipu.h"

/*!
 * camera sensor display and capture test.
 *
 * @return error information
 */
int32_t sensor_capture(void)
{
    int32_t ipu_index = 1, read_value = 1;
    ips_dev_panel_t *panel;
    t_camera_profile *sensor;
    uint8_t revchar;

    /*step 1: enable panel */
    panel = search_panel("HannStar XGA LVDS");
    panel->panel_init(&ipu_index);

    /*step 2: setup IPU: from csi to display */
    ipu1_iomux_config();
    ipu_sw_reset(ipu_index, 1000);
    ipu_capture_setup(ipu_index, CSI_PARALLEL, 640, 480, 640, 480, panel);

    /*step 3: setup sensor */
    sensor = search_sensor();
    if (sensor == NULL)
        return FALSE;
    sensor_config(sensor);

    /*step 4: enable ipu display channel */
    ipu_enable_display(ipu_index);

    /*test 1: capture image from sensor */
    printf("Do you see the captured image (y or n)?\n");
    do {
        revchar = getchar();
    } while (revchar == (uint8_t) 0xFF);
    if (!(revchar == 'Y' || revchar == 'y'))
        return FALSE;

    /*test 2: sensor auto focus */
    if (sensor->auto_focus_enable) {
        printf("Do you want to test auto focus function? [y/n]\n");
        if (is_input_char('y')) {
            sensor_autofocus_init(sensor);
            while (is_input_char('y')) {
                sensor_af_trigger(sensor);
                printf("Do you see the viewfiner in the middle of camera?[y/n]\n");
                if (!is_input_char('y')) {
                    return TEST_FAILED;
                }
                printf("Trigger more? [y/n]\n");
            }
        }
    }

    /*test 3: sensor standby */
    printf("Do you want to test standby mode? [y/n]\n");
    while (is_input_char('y')) {
        sensor_standby(read_value);
        if (read_value == 1) {
            printf("Do you see the still camera image? [y/n]\n");
            if (!is_input_char('y')) {
                return TEST_FAILED;
            }
        }
        read_value = 1 - read_value;
        printf("Trigger more? [y/n]\n");
    }

    return TEST_PASSED;
}
