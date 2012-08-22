/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "version.h"
#include "cortex_a9.h"
#include "mmu.h"

#ifdef ALL_TEST_ENABLE

extern void sdma_test(void);
extern void ipu_test(void);
extern void uart_test(void);
extern void gpt_test(void);
extern void epit_test(void);
extern void usdhc_test(void);
extern void hdmi_test(void);
extern void audio_test(void);
extern void i2c_test(void);
extern void gic_sgi_test(void);
extern void gic_multicore_test(void);
extern void snvs_rtc_test(void);
extern void snvs_srtc_test(void);
extern void flexcan_test(void);
extern int spi_test(void);
extern void tempmon_test(void);
extern int vpu_test(void);
extern int gpmi_test(void);
extern int mipi_test();
extern int pwm_test();
extern int eim_test();
extern int gpu_test(void);
extern int camera_test(void);
extern int wdog_test(void);
extern int camera_test(void);
extern void usb_test(void);

#if CHIP_MX6DQ
extern int sata_test(void);
extern int pcie_test(void);
#endif

void ALL_test(void)
{
    uint8_t gic_test_done = 0;

    while (1) {
        printf("Starting the tests suite...\n");
#if defined(BOARD_EVB)
        audio_test();
#endif

#ifdef BOARD_SABRE_AI
        eim_test();
#endif /* BOARD_SABRE_AI */
        epit_test();

#if defined(BOARD_EVB)
        gpu_test();
#endif
        gpt_test();
        hdmi_test();
        i2c_test();
        ipu_test();
#if defined(BOARD_EVB) || defined(BOARD_SABRE_AI)
        mipi_test();
#endif /* BOARD_EVB || BOARD_SABRE_AI */

#if defined(BOARD_EVB)
#if defined(CHIP_MX6DQ)
        pcie_test();
        sata_test();
#endif
        wdog_test();
#endif
#ifndef BOARD_SABRE_LITE
        pwm_test();
#endif
        sdma_test();
        snvs_rtc_test();
        snvs_srtc_test();
#if defined(BOARD_EVB) || defined(BOARD_SMART_DEVICE)
//        vpu_test();
#endif
#ifdef BOARD_EVB
        gpmi_test();
        spi_test();
#endif /* BOARD_EVB */
        tempmon_test();
        uart_test();
        usdhc_test();
#if defined(BOARD_SMART_DEVICE) && defined(BOARD_VERSION2)
// 		usb_test();
#endif
        gic_sgi_test();

        /* GIC test can only be executed once, and requires a board reset */
        if (gic_test_done == 0) {
            gic_test_done = 0xFF;
            gic_multicore_test();
        }
#ifdef BOARD_SABRE_AI
    /* need to be here */
        flexcan_test();
#endif /* BOARD_SABRE_AI */

#if defined(BOARD_SMART_DEVICE)
        camera_test();
#endif

        printf("\n...end of the tests suite.\n");
    }
}

#endif /* ALL_TEST_ENABLE */

