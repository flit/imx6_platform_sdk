/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file srtc_test.c
 * @brief Basic security RTC test of the SNVS module.
 *
 */

#include "obds.h"
#include "hardware.h"
//#include "sdk.h"

#include "registers/regsocotp.h"
#include "registers/regssnvs.h"

// These defines are used to solve some compilations issue with src/drivers/timer/imx_timer/srtc.c
//#define SNVS_LPSCMR    SRTC_LPSCMR
//#define SNVS_LPSCLR    SRTC_LPSCLR
//#define SNVS_LPCR      SRTC_LPCR
//#define SNVS_HPCMR     SRTC_HPCMR
//#define SNVS_HPCLR     SRTC_HPCLR
//#define SNVS_HPCR      SRTC_HPCR

/*!
 * The SRTC test enables the SRTC of the SNVS and check if the SRTC LP counter toggles.
 */
int snvs_srtc_test_enable;
int snvs_srtc_test(void)
{
    u32 c1, c2;

    PROMPT_RUN_TEST("SNVS - SRTC");

    // Check to see if Secure Clock can run
    // SEC_CONFIG[0] ( 0x440[7:0] bit 1 )
	//
	//    Combined with SEC_CONFIG[1], provide FAB/Open/Close security states:
	//    00 - FAB (Open)
	//    01 - Open - allows any code to be flashed and executed, even if it has no valid signature.
	//    1x -  Closed (Security On)
    unsigned int reg;
    reg = HW_OCOTP_CFG3_RD(); // readl(OCOTP_BASE_ADDR + 0x440);
    if ( (reg & 0x2) == 0 )
    {
    	printf("\n\tWARNING!! SNVS SRTC TEST MAY FAIL BECAUSE DEVICE IS IN AN INVALID\n");
    	printf(  "\tSECURITY MODE. FREESCALE DOES NOT DISTRIBUTE BOARDS IN THIS MODE.\n");
    	printf(  "\tPLEASE CONTACT YOUR FREESCALE REPRESENTATIVE FOR INSTRUCTIONS TO\n");
    	printf(  "\tRECONFIGURE THIS DEVICE TO A VALID SECURITY MODE.\n");
        printf("\n\tSNVS SRTC TEST SKIPPED \n");
        return TEST_BYPASSED;
    }
    else
    {
    	printf("\n\tSECURITY CONFIGURATION is OPEN.\n");
    }

    // enable SNVS HP
    BW_SNVS_HPCR_RTC_EN(1); // writel(0x1, SNVS_HPCR);

    c1 = HW_SNVS_HPRTCMR_RD(); // readl(SNVS_HPCMR);
    c2 = HW_SNVS_HPRTCLR_RD(); // readl(SNVS_HPCLR);

    hal_delay_us(10000);

    if (c1 == HW_SNVS_HPRTCMR_RD() && c2 == HW_SNVS_HPRTCLR_RD()) {
        printf("\n\tSNVS SRTC secure counter failed to run.\n");
        printf("\n\tSNVS SRTC TEST FAILED \n");
        return TEST_FAILED;
    } else {
        printf("\tSNVS SRTC HP counter is running.\n");
    }

    // enable SNVS LP
    BW_SNVS_LPCR_SRTC_ENV(1); // writel(0x1, SNVS_LPCR);

    c1 = HW_SNVS_LPSRTCMR_RD(); // readl(SNVS_LPSCMR);
    c2 = HW_SNVS_LPSRTCLR_RD(); // readl(SNVS_LPSCLR);
    hal_delay_us(10000);

    if (c1 == HW_SNVS_LPSRTCMR_RD() && c2 == HW_SNVS_LPSRTCLR_RD()) {
        printf("\n\tSNVS SRTC secure counter failed to run.\n");
        printf("\tSNVS SRTC TEST FAILED \n");
        return TEST_FAILED;
    } else {
        printf("\tSNVS SRTC LP counter is running.\n");
    }

    printf("\n\tSNVS SRTC TEST PASSED \n");
    return TEST_PASSED;
}

//RUN_TEST("SNVS - SRTC", snvs_srtc_test)
