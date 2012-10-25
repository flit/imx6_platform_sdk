/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "sdk.h"
#include "sdk_version.h"
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
extern void gic_test(void);
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
extern int camera_test(void);
extern int wdog_test(void);
extern int camera_test(void);
extern void usb_test(void);

#ifdef CHIP_MX6DQ
extern int sata_test(void);
#endif
#if defined(BOARD_EVB) 
extern int pcie_test(void);
#endif

#if defined(CHIP_MX6SL)
extern int lcdc_test(void);
#endif

void ALL_test(void)
{
    while (1) {
        printf("Starting the tests suite...\n");
#if defined(BOARD_EVB)
        audio_test();
#endif

#ifdef BOARD_SABRE_AI
        eim_test();
#endif /* BOARD_SABRE_AI */
        epit_test();

        gpt_test();
#if !defined (CHIP_MX6SL)
        hdmi_test();
        ipu_test();
#endif
        i2c_test();

#if defined(BOARD_EVB) || defined(BOARD_SABRE_AI)
        mipi_test();
#endif /* BOARD_EVB || BOARD_SABRE_AI */

#if defined(BOARD_EVB)
        pcie_test();
#if defined(CHIP_MX6DQ)
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
#if defined(BOARD_SMART_DEVICE) && defined(BOARD_REV_B)
// 		usb_test();
#endif

        gic_test();

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

