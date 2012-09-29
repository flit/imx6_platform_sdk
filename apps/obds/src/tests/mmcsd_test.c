/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "obds.h"
#include "hardware.h"
//#include "board_id.h"

extern int SDHC_ADMA_mode;
extern int SDHC_UHSI_mode;
int card_detect_en = TRUE;

extern int mmc_sd_test(unsigned int, unsigned int);

int mmcsd_test_enable;
uint32_t mmcsd_bus_width, mmc_sd_base_address;
#if defined(CHIP_MX6SL) && defined(BOARD_EVB)
int mmcsd_test(void)
{
    int ret_val = TEST_NOTPRESENT;

	if (!mmcsd_test_enable) {
        return TEST_NOTPRESENT;
    }

    /* Always try maximum bus width */
    mmcsd_bus_width = 8;

	PROMPT_RUN_TEST("MMC/SD", NULL);

	/* USDHC2 test */
	printf("Please insert MMC/SD card into SD2\n");

	if (!is_input_char('y', NULL)) {
		printf("skip MMC SD test on SD2\n");
		ret_val = TEST_BYPASSED;
	} else {

		mmc_sd_base_address = USDHC2_BASE_ADDR;

        printf("Would you like to check the Card Detection status?");
        if(is_input_char('y', NULL)) {
            card_detect_en = 1;
        } else {
            card_detect_en = 0;
        }

		printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
		if (is_input_char('y', NULL)) {
			SDHC_UHSI_mode = 1;
		} else {
			SDHC_UHSI_mode = 0;
		}

		if (mmc_sd_test(mmcsd_bus_width, mmc_sd_base_address) == TEST_FAILED) {
			printf("    Test for MMC/SD card on SD2 FAILED.\n");
			ret_val = TEST_FAILED;
		}
	}
	/* USDHC3 test */
	printf("Please insert MMC/SD card into SD3\n");

	if (!is_input_char('y', NULL)) {
		printf("skip MMC SD test on SD3\n");
		return ret_val == TEST_FAILED ? TEST_FAILED : TEST_BYPASSED;
	}

	mmc_sd_base_address = USDHC3_BASE_ADDR;

    printf("Would you like to check the Card Detection status?\n");
    if(is_input_char('y', NULL)) {
        card_detect_en = 1;
    } else {
        card_detect_en = 0;
    }

	printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
	if (is_input_char('y', NULL)) {
		SDHC_UHSI_mode = 1;
	} else {
		SDHC_UHSI_mode = 0;
	}

	if (mmc_sd_test(mmcsd_bus_width, mmc_sd_base_address) == TEST_FAILED) {
		printf("    Test for MMC/SD card on SD3 FAILED.\n");
		ret_val = TEST_FAILED;
	}

	return ret_val == TEST_NOTPRESENT ? TEST_PASSED : ret_val;
}
#else // #if defined(MX6SL) && defined(EVB)
int mmcsd_test(void)
{
    if (!mmcsd_test_enable) {
        return TEST_NOTPRESENT;
    }

    /* Always try maximum bus width */
    mmcsd_bus_width = 8;

#if ((!defined(CHIP_MX6SL) && defined(BOARD_EVB)) || defined(BOARD_SMART_DEVICE) || defined(BOARD_SABRE_LITE) )
    if ((BOARD_TYPE_ID == BOARD_TYPE_EVB) || (BOARD_TYPE_ID == BOARD_TYPE_SABRE_LITE) || (BOARD_TYPE_ID == BOARD_TYPE_SMART_DEVICE)) {    //EVB/Sabre-Lite board, MMC/SD
        PROMPT_RUN_TEST("MMC/SD", NULL);
        printf("Please make sure to insert an MMC/SD card into SD slot #3\n");
        if (!is_input_char('y', NULL)) {
            printf("  skip MMC SD test \n");
            return TEST_BYPASSED;
        }
    } else {
        printf("Board not supported.\n");
        return TEST_BYPASSED;
    }

    mmc_sd_base_address = USDHC3_BASE_ADDR;

#elif defined(BOARD_SABRE_AI)

    PROMPT_RUN_TEST("MMC/SD", NULL);
    printf("Please insert an MMC/SD card into the SD slot on the bottom of the main board.\n");
    if (!is_input_char('y', NULL)) {
        printf("  skip MMC SD test \n");
        return TEST_BYPASSED;
    }
    mmc_sd_base_address = USDHC1_BASE_ADDR;

#else

    PROMPT_RUN_TEST("MMC/SD", NULL);
    printf("Please make sure to insert an MMC/SD card into SD slot 2 \n");
    if (!is_input_char('y', NULL)) {
        printf("  skip MMC SD test \n");
        return TEST_BYPASSED;
    }

    mmc_sd_base_address = USDHC2_BASE_ADDR;
#endif

    printf("Would you like to check the Card Detection status?");
    if(is_input_char('y', NULL)) {
        card_detect_en = 1;
    } else {
        card_detect_en = 0;
    }

#if (!defined(CHIP_MX6SL) && defined(BOARD_EVB))
    /* Test for voltage switch & reset */
    printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
    if (is_input_char('y', NULL)) {
        SDHC_UHSI_mode = 1;
    } else {
        SDHC_UHSI_mode = 0;
    }
#endif

    return mmc_sd_test(mmcsd_bus_width, mmc_sd_base_address);
}
#endif

//RUN_TEST_INTERACTIVE("MMC/SD", mmcsd_test)
