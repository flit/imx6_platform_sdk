/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs_srtc_test.c
 * @brief Basic security RTC test of the SNVS module.
 *
 */

#include "obds.h"
#include "hardware.h"
#include "sdk.h"
#include "registers/regsocotp.h"
#include "registers/regssnvs.h"

/*!
 * The SRTC test enables the SRTC of the SNVS and check if the SRTC LP counter toggles.
 */
menu_action_t snvs_srtc_test(const menu_context_t* const context, void* const param)
{
    u32 c1, c2;
	const char* indent = menu_get_indent(context);

    PROMPT_RUN_TEST("SNVS - SRTC Test", indent);

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
    	printf("%s%s%sWARNING!! SNVS SRTC TEST MAY FAIL BECAUSE DEVICE IS IN AN INVALID\n", indent, TEXT_ATTRIB_BOLD, TEXT_COLOR_YELLOW);
    	printf(    "%sSECURITY MODE. FREESCALE DOES NOT DISTRIBUTE BOARDS IN THIS MODE.\n", indent);
    	printf(    "%sPLEASE CONTACT YOUR FREESCALE REPRESENTATIVE FOR INSTRUCTIONS TO\n", indent);
    	printf(    "%sRECONFIGURE THIS DEVICE TO A VALID SECURITY MODE.\n", indent);
        printf( "\n%sSNVS SRTC TEST SKIPPED.%s\n", indent, TEXT_ATTRIB_DEFAULT);
        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
    }
    else
    {
    	printf("%sSECURITY CONFIGURATION is OPEN.\n", indent);
    }

    // enable SNVS HP
    BW_SNVS_HPCR_RTC_EN(1); // writel(0x1, SNVS_HPCR);

    c1 = HW_SNVS_HPRTCMR_RD(); // readl(SNVS_HPCMR);
    c2 = HW_SNVS_HPRTCLR_RD(); // readl(SNVS_HPCLR);

    hal_delay_us(10000);

    if (c1 == HW_SNVS_HPRTCMR_RD() && c2 == HW_SNVS_HPRTCLR_RD()) {
        printf("%sSNVS SRTC secure counter failed to run.\n", indent);
        printf_color(TEXT_ATTRIB_BOLD, TEXT_COLOR_MAGENTA, "\n%sSNVS SRTC TEST FAILED.\n", indent);
        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;
    } else {
        printf("%sSNVS SRTC HP counter is running.\n", indent);
    }

    // enable SNVS LP
    BW_SNVS_LPCR_SRTC_ENV(1); // writel(0x1, SNVS_LPCR);

    c1 = HW_SNVS_LPSRTCMR_RD(); // readl(SNVS_LPSCMR);
    c2 = HW_SNVS_LPSRTCLR_RD(); // readl(SNVS_LPSCLR);
    hal_delay_us(10000);

    if (c1 == HW_SNVS_LPSRTCMR_RD() && c2 == HW_SNVS_LPSRTCLR_RD()) {
        printf("%sSNVS SRTC secure counter failed to run.\n", indent);
        printf_color(TEXT_ATTRIB_BOLD, TEXT_COLOR_MAGENTA, "\n%sSNVS SRTC TEST FAILED.\n", indent);
        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;
    } else {
        printf("%sSNVS SRTC LP counter is running.\n", indent);
    }

    printf_color(NULL, TEXT_COLOR_GREEN, "\n%sSNVS SRTC TEST PASSED.\n", indent);
    *(test_return_t*)param = TEST_PASSED;
    return MENU_CONTINUE;
}
