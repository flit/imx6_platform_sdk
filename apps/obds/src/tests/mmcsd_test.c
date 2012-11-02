/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "obds.h"
#include "registers/regsusdhc.h"

extern int SDHC_ADMA_mode;
int SDHC_UHSI_mode;
int card_detect_en;

static const char * const mmcsd_test_name = "MMC/SD Test";

extern int mmc_sd_test(unsigned int bus_width, uint32_t instance);

uint32_t mmcsd_bus_width, instance;
#if defined(CHIP_MX6SL) && defined(BOARD_EVK)
menu_action_t mmcsd_test(const menu_context_t* const context, void* const param)
{
 	const char* indent = menu_get_indent(context);

    if ( prompt_run_test(mmcsd_test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }
    /* Always try maximum bus width */
    mmcsd_bus_width = 8;

	/* USDHC2 test */
	printf("Please insert MMC/SD card into SD2\n");

	if (!is_input_char('y', indent)) {
		printf("skip MMC SD test on SD2\n");
   	    print_test_skipped(mmcsd_test_name, indent);
    	
        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
	} else {

		instance = HW_USDHC2;

        printf("Would you like to check the Card Detection status?");
        if(is_input_char('y', indent)) {
            card_detect_en = 1;
        } else {
            card_detect_en = 0;
        }

		printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
		if (is_input_char('y', indent)) {
			SDHC_UHSI_mode = 1;
		} else {
			SDHC_UHSI_mode = 0;
		}

		if (mmc_sd_test(mmcsd_bus_width, instance) == TEST_FAILED) {
			printf("    Test for MMC/SD card on SD2 FAILED.\n");
            print_test_failed(mmcsd_test_name, indent);

            *(test_return_t*)param = TEST_FAILED;
            return MENU_CONTINUE;      
		}
	}
	/* USDHC3 test */
	printf("Please insert MMC/SD card into SD3\n");

	if (!is_input_char('y', indent)) {
		printf("skip MMC SD test on SD3\n");
   	    print_test_skipped(mmcsd_test_name, indent);
    	
        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
	}

	instance = HW_USDHC3;

    printf("Would you like to check the Card Detection status?\n");
    if(is_input_char('y', indent)) {
        card_detect_en = 1;
    } else {
        card_detect_en = 0;
    }

	printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
	if (is_input_char('y', indent)) {
		SDHC_UHSI_mode = 1;
	} else {
		SDHC_UHSI_mode = 0;
	}

	if (mmc_sd_test(mmcsd_bus_width, instance) == TEST_FAILED) {
		printf("    Test for MMC/SD card on SD3 FAILED.\n");
        print_test_failed(mmcsd_test_name, indent);

        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;      
	}

	return MENU_CONTINUE;
}
#else // #if defined(MX6SL) && defined(EVB)
menu_action_t mmcsd_test(const menu_context_t* const context, void* const param)
{
 	const char* indent = menu_get_indent(context);

    if ( prompt_run_test(mmcsd_test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }

    /* Always try maximum bus width */
    mmcsd_bus_width = 8;
#if ((!defined(CHIP_MX6SL) && defined(BOARD_EVB)) || defined(BOARD_SMART_DEVICE) )
    printf("Please make sure to insert an MMC/SD card into SD slot #3\n");
    printf("Please enter y or Y to confirm\n");
    if (!is_input_char('y', indent)) {
   	    print_test_skipped(mmcsd_test_name, indent);

        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
    }

    instance = HW_USDHC3;

#elif defined(BOARD_SABRE_AI)

    printf("Please insert an MMC/SD card into the SD slot on the bottom of the main board.\n");
    if (!is_input_char('y', indent)) {
        printf("  skip MMC SD test \n");
  	    print_test_skipped(mmcsd_test_name, indent);
    	
        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
    }
    instance = HW_USDHC1;

#else
    printf("Please make sure to insert an MMC/SD card into SD slot 2 \n");
    if (!is_input_char('y', indent)) {
        printf("  skip MMC SD test \n");
 	    print_test_skipped(mmcsd_test_name, indent);
    	
        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
    }

    instance = HW_USDHC2;
#endif

    printf("Would you like to check the Card Detection status? Please enter y or Y to confirm");
    if(is_input_char('y', indent)) {
        card_detect_en = 1;
    } else {
        card_detect_en = 0;
    }

#if (!defined(CHIP_MX6SL) && defined(BOARD_EVB))
    /* Test for voltage switch & reset */
    printf("U-HSI(make sure voltage switch circuit on board) mode test?\n");
    if (is_input_char('y', indent)) {
        SDHC_UHSI_mode = 1;
    } else {
        SDHC_UHSI_mode = 0;
    }
#endif

    mmc_sd_test(mmcsd_bus_width, instance);
    return MENU_CONTINUE;
}
#endif

