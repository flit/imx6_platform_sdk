/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_init Base OBDS files
 */

/*!
 * @file  main.c
 * @brief main() function
 *
 * @ingroup diag_init
 */

//#include <stdio.h>
#include "hardware.h"
#include "board_id/board_id.h"
#include "obds.h"
#include "obds_utils.h"
#include "platform_init.h"
#include "text_color.h"
#include "version.h"
#include "print_clock_info.h"

int total_tests = 0;
int auto_run_enable = 1; // global flag to indicate auto-run feature enabled or not
menuitem_t main_menuitems[MAX_TESTS];
test_return_t test_results[MAX_TESTS];

/*!
 * main function that decides which tests to run and prompts the user before
 * running test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
    auto_run_enable = 1;

    platform_init();
    printf(g_TextAttributeDefault); // reset terminal colors to default
    print_version();

    show_freq();
    show_ddr_config();
    show_boot_switch_info();

    //
    // Initialize the test results and create the
    // test list (menuitems) for the board.
    //
    memset(test_results, TEST_NOT_PRESENT, MAX_TESTS * sizeof(int));
    select_tests(&main_menuitems[0], SEL_MENU_TESTS);

    //
    // Create the main menu header
    //
    char chip_str[64];
    char chip_rev_str[64];
    char board_str[64];
    char board_rev_str[64];

    fsl_board_id_t fsl_board_id = get_board_id();

    chip_name(chip_str, fsl_board_id.B.CHIP_TYPE_ID, false);
    chip_revision(chip_rev_str, fsl_board_id.B.CHIP_REV_MAJOR, fsl_board_id.B.CHIP_REV_MINOR);
    board_name(board_str, BOARD_TYPE);
    board_revision(board_rev_str, BOARD_REVISION);

    char main_menu_desc[1024];
	sprintf(main_menu_desc, "This is an interactive test menu for %s %s %s %s.",
			chip_str, chip_rev_str, board_str, board_rev_str);

	//
	// Create the main menu
	//
	menu_t main_menu;
	menu_make_menu(&main_menu, main_menu_desc, main_menuitems,
			"Enter test number followed by the enter key, 'm' for menu, or 'q' to exit.");

	//
	// Show the main menu
	//
	menu_present(&main_menu);

	//
	// Report the results of the tests.
	//
    report_test_results();

    _sys_exit(0);

    return 0;
}

test_return_t prompt_run_test(const char * const test_name, const char* const indent)
{
    printf_color(g_TextAttributeBold, NULL, "\n%s---- Running < %s >\n", indent, test_name);
    if (!auto_run_enable)
    {
        if (!is_input_char('y', indent))
        {
        	print_test_skipped(test_name, indent);
            return TEST_BYPASSED;
        }
    }
    else
        printf("\n");

    return TEST_CONTINUE;
}

void print_test_passed(const char* const test_name, const char* const indent)
{
	 printf_color(NULL, g_TextColorGreen, "\n%s%s PASSED.\n", indent, test_name);
}

void print_test_skipped(const char* const test_name, const char* const indent)
{
	 printf_color(NULL, g_TextColorYellow, "\n%s%s SKIPPED.\n", indent, test_name);
}

void print_test_failed(const char* const test_name, const char* const indent)
{
	 printf_color(g_TextAttributeBold, g_TextColorRed, "\n%s%s FAILED.\n", indent, test_name);
}

void print_test_not_implemented(const char* const test_name, const char* const indent)
{
	 printf_color(g_TextAttributeBold, g_TextColorRed, "\n%s%s is NOT IMPLEMENTED.\n", indent, test_name);
}

//
// PRIVATE
//

//
// Report the results of the tests.
// NOTE: Only the last test result for a given test is reflected
//       in the summary if a test was run more than once from the menu.
//
void report_test_results(void)
{
    int passed = 0, failed = 0, not_implemented = 0, skipped = 0, not_present = 0, unknown = 0;
    int i;

    printf("\n----------------- TEST RESULTS -----------------\n");
    for (i = 0; i < MAX_TESTS; i++)
    {
        if (test_results[i] == TEST_NOT_PRESENT)
        {
        	++not_present;
        }
    	else if (test_results[i] == TEST_PASSED)
        {
            printf_color(g_TextAttributeBold, g_TextColorGreen, "\t<%s> PASSED\n", main_menuitems[i].description);
            ++passed;
        }
        else if (test_results[i] == TEST_FAILED)
        {
            printf_color(g_TextAttributeBold, g_TextColorRed, "\t<%s> FAILED\n", main_menuitems[i].description);
            ++failed;
        }
        else if (test_results[i] == TEST_NOT_IMPLEMENTED)
        {
            printf_color(g_TextAttributeBold, g_TextColorRed, "\t<%s> is NOT IMPLEMENTED\n", main_menuitems[i].description);
            ++not_implemented;
        }
        else if (test_results[i] == TEST_BYPASSED)
        {
            printf_color(g_TextAttributeBold, g_TextColorYellow, "\t<%s> SKIPPED\n", main_menuitems[i].description);
            ++skipped;
        }
        else
        {
            ++unknown;
        }
    }

    printf("\n=================== SUMMARY ====================\n");
    printf("PASSED:          \t%d\n", passed);
    printf("FAILED:          \t%d\n", failed);
    printf("NOT IMPLEMENTED: \t%d\n", not_implemented);
    printf("SKIPPED:         \t%d\n", skipped);
    printf("TOTAL:           \t%d\n", MAX_TESTS - not_present - unknown);
    printf("=================================================\n");
}

menu_action_t run_all_tests(const menu_context_t* const context, void* const param)
{
	select_tests_t tests = SEL_CPU_AND_MAIN_BOARD_TESTS;
	const char* indent = menu_get_indent(context);

    if (BOARD_TYPE == BOARD_TYPE_SABRE_AI || BOARD_TYPE == BOARD_TYPE_EVB)
    {
        printf("%sDo you wish to run the CPU-ONLY set of tests?\n", indent);
        if (is_input_char('y', indent)) {
            printf("%s  Run CPU-ONLY tests.\n\n", indent);
        	tests = SEL_CPU_BOARD_ONLY_TESTS;
        }
    }
    select_tests(main_menuitems, tests);

    printf("%sEnable auto-run feature?\n", indent);
    if (is_input_char('y', indent)) {
        printf("%s  Auto-run enabled.\n\n", indent);
        auto_run_enable = 1;
    } else {
    	auto_run_enable = 0;
    }

    // run through the tests starting at 1 since run_all_tests() is at 0.
    int test_idx;
    for (test_idx = 1; test_idx < MAX_TESTS; test_idx++)
    {
    	if ( main_menuitems[test_idx].func &&
    		 strcmp(main_menuitems[test_idx].key, "m") != 0 &&
    		 strcmp(main_menuitems[test_idx].key, "q") != 0	)

    		main_menuitems[test_idx].func(context, main_menuitems[test_idx].param);
    }

    return MENU_EXIT;
}

void select_tests(menuitem_t* const menuitems, const select_tests_t select_tests)
{
	int menu_idx = 0;
	memset(menuitems, 0, sizeof(menuitem_t) * MAX_TESTS);

	menu_make_menuitem(&menuitems[menu_idx], "00", "RUN ALL TESTS", run_all_tests, NULL);menu_idx++;

#if defined (CHIP_MX6DQ) || defined(CHIP_MX6SDL)
#if defined(BOARD_TYPE_SABRE_AI)
	if ( select_tests != SEL_MAIN_BOARD_ONLY_TESTS )
	{
		menu_make_menuitem_group(&menuitems[menu_idx++], "CPU Board Tests");
		menu_make_menuitem(&menuitems[menu_idx], "01", "BOARD ID Test", program_board_id, &test_results[menu_idx]);menu_idx++;
		menu_make_menuitem(&menuitems[menu_idx], "02", "MAC Address Test", program_mac_address, &test_results[menu_idx]);menu_idx++;
		menu_make_menuitem(&menuitems[menu_idx], "03", "DDR Test", ddr_test, &test_results[menu_idx]);menu_idx++;
		menu_make_menuitem(&menuitems[menu_idx], "04", "SNVS - SRTC Test", snvs_srtc_test, &test_results[menu_idx]);menu_idx++;
#if defined(BOARD_REV_A)
	// use micrel ethernet for rev A board
	// KSZ9021RN_test_enable = 1;
#else
    // use Atheros ethernet for all other revs (rev B)
	menu_make_menuitem(&menuitems[menu_idx], "05", "Ethernet Test", enet_test_main, &test_results[menu_idx]);menu_idx++;    
	menu_make_menuitem(&menuitems[menu_idx], "06", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
	menu_make_menuitem(&menuitems[menu_idx], "07", "RGMII AR8031 G-Ethernet Test", KSZ9021RN_test_main, &test_results[menu_idx]);menu_idx++;
	menu_make_menuitem(&menuitems[menu_idx], "08", "I2C Device ID Test", i2c_device_id_check, &test_results[menu_idx]);menu_idx++;		
	menu_make_menuitem(&menuitems[menu_idx], "09", "I2S Audio Test", i2s_audio_test, &test_results[menu_idx]);menu_idx++;
	menu_make_menuitem(&menuitems[menu_idx], "12", "UART Test", uart_test, &test_results[menu_idx]);menu_idx++;
	menu_make_menuitem(&menuitems[menu_idx], "13", "SPI NOR FLASH Test", spi_nor_test, &test_results[menu_idx]);menu_idx++;	
	menu_make_menuitem(&menuitems[menu_idx], "14", "MMC/SD Test", mmcsd_test, &test_results[menu_idx]);menu_idx++;		
	menu_make_menuitem(&menuitems[menu_idx], "15", "PMIC - PF0100 Test", pf0100_i2c_device_id_check, &test_results[menu_idx]);menu_idx++;	
#endif
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
//    etm_test_enable = 1;
	}

	if ( select_tests != SEL_CPU_BOARD_ONLY_TESTS )
	{
		menu_make_menuitem_group(&menuitems[menu_idx++], "Main Board Tests");
		menu_make_menuitem(&menuitems[menu_idx], "10", "ANDROID BUTTONS Test", android_buttons_test, &test_results[menu_idx]);menu_idx++;
		menu_make_menuitem(&menuitems[menu_idx], "11", "FLEXCAN1/2 LOOPBACK Test", flexcan_test, &test_results[menu_idx]);menu_idx++;
//		menu_make_menuitem(&menuitems[menu_idx], "12", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
//		menu_make_menuitem(&menuitems[menu_idx], "13", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
//		can_test_enable = 1;
//		ard_mb_reset_test_enable = 1;
//		ard_mb_expander_reset_test_enable = 1;
	}

#elif defined(BOARD_TYPE_SMART_DEVICE)
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
#elif defined(BOARD_TYPE_SABRE_LITE)
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
#elif defined(BOARD_TYPE_EVB)
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
#endif
#elif defined(CHIP_MX6SL)
#if defined (BOARD_EVB)
#elif defined(BOARD_EVK)
#endif
#endif

	menu_make_menuitem_group(&menuitems[menu_idx++], "Menu functions");
	menu_make_menuitem_showmenu(&menuitems[menu_idx++]);
	menu_make_menuitem_exitmenu(&menuitems[menu_idx++]);
	menu_make_menuitem_end(&menuitems[menu_idx]);
}




#if 0
#if defined(CHIP_MX6DQ)
void select_tests(SELECT_TESTS tests)
{
    int display = 0;

    etm_test_enable = 1;

    ipu_display_test_enable = 1;

    if (BOARD_TYPE == BOARD_TYPE_SABRE_AI) {
        // these tests apply to SABRE AI CPU Board

        //ds90ur124_test_enable = 0;

        weim_nor_flash_test_enable = 1;

        sata_test_enable = 1;
        nand_test_enable = 0;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        max7310_i2c_device_id_test_enable = 1;  // Port expander ID tests

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;

        usbo_dev_enum_test_base = USBOH3_USB_BASE_ADDR;
        usbo_dev_enum_test_enable = 1;

        // include further testing of the SABRE AI MAIN board if selected
        switch (tests)
        {
			case SEL_CPU_ONLY_TESTS:

	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

				break;

			case SEL_CPU_PLUS_BOARD_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

	            ipu_display_panel[display++] = DISP_DEV_LVDS;

	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;      //J30 on the main board
	            usbh_dev_enum_test_enable = 1;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_cs42888_test_enable = 1;    // codec
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mag3112_test_enable = 0;    // eCompass - no pop on sabre_ai
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

	            mmcsd_test_enable = 1;
	            mmcsd_bus_width = 8;
	            mmc_sd_base_address = USDHC3_BASE_ADDR;

	            sata_test_enable = 0;   // only test in CPU_ONLY mode per Babin 5/9/12

	            break;

			case SEL_MENU_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;      //J30 on the main board
	            usbh_dev_enum_test_enable = 1;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_cs42888_test_enable = 1;    // codec
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mag3112_test_enable = 0;    // eCompass - no pop on sabre_ai
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

	            android_buttons_test_enable = 1;
	            can_test_enable = 1;
	            ard_mb_reset_test_enable = 1;
	            ard_mb_expander_reset_test_enable = 1;

	            mmcsd_test_enable = 1;
	            mmcsd_bus_width = 8;
	            mmc_sd_base_address = USDHC3_BASE_ADDR;

	            sata_test_enable = 1;

	            break;

			default:
				printf("ERROR: Unsupported test configuration.\n");
				break;
        }

    }  // if (BOARD_TYPE == BOARD_TYPE_SABRE_AI)

    if (BOARD_TYPE == BOARD_TYPE_SMART_DEVICE) {
        ar8031_test_enable = 1; // Atheros ethernet

        pf0100_i2c_device_id_test_enable = 1;

        sata_test_enable = 1;

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;

        camera_test_enable = 1;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;
        weim_nor_flash_test_enable = 0;

        usbo_dev_enum_test_base = USBOH3_USB_BASE_ADDR;
        usbo_dev_enum_test_enable = 1;

        i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
        i2c_device_id_check_mag3112_test_enable = 1;    // eCompass
        i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer
        // barometer is listed as DNP in schematic

        /* eMMC test */
        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC4_BASE_ADDR;

        i2s_audio_test_enable = 1;
        // epd_test_enable = 1;
        // touch_button_test_enable = 1;

    }                           // if (BOARD_TYPE == BOARD_TYPE_SMART_DEVICE)

    if (BOARD_TYPE == BOARD_TYPE_SABRE_LITE) {
        KSZ9021RN_test_enable = 1;  // micrel ethernet

        sata_test_enable = 1;

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        // spi_nor_test_enable = 1;
        // spi_nor_flash_type = M25P32;

        //usbh_dev_enum_test_base = USBH1_BASE_ADDR;
        //usbh_dev_enum_test_enable = 1;  // will return HUB info
        usbh_hub251x_test_base = USBH1_BASE_ADDR;
        usbh_hub251x_test_enable = 1;   // will return device info connected to hub

        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC3_BASE_ADDR;

        i2s_audio_test_enable = 1;  // sabre-lite audio out of sgtl5000

    }                           // if (BOARD_TYPE == BOARD_TYPE_SABRE_LITE)

    if (BOARD_TYPE == BOARD_TYPE_EVB) {
        // these tests apply to EVB CPU board

        //ds90ur124_test_enable = 0;
        //si476x_test_enable = 0;
        //weim_nor_flash_test_enable = 1;

        ar8031_test_enable = 1; // Atheros ethernet

        sata_test_enable = 1;

        nand_test_enable = 1;

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;
        ipu_display_panel[display++] = DISP_DEV_MIPI;

        max7310_i2c_device_id_test_enable = 1;

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;

        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC3_BASE_ADDR;

        eeprom_test_enable = 1;

        switch (tests)
        {
			case SEL_CPU_ONLY_TESTS:
	            //adv7180_test_enable = 0;
	            esai_test_enable = 0;
	            usbh_EHCI_test_mode_test_enable = 0;
				break;
			case SEL_CPU_PLUS_BOARD_TESTS:
		        // include further testing of the EVB MAIN board if selected
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			case SEL_MENU_TESTS:
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			default:
				printf("ERROR: Unsupported test configuration.\n");
				break;
        }

    } // if (BOARD_TYPE == BOARD_TYPE_EVB)

}
#elif defined(CHIP_MX6SDL)
void select_tests(SELECT_TESTS tests)
{
    int display = 0;

    program_mac_address_enable = 1;
    ipu_display_test_enable = 1;

    if (BOARD_TYPE == BOARD_TYPE_SABRE_AI) {
        // these tests apply to SABRE AI CPU Board

        //ds90ur124_test_enable = 0;
#if defined(BOARD_REV_A)        // use micrel ethernet for rev A board
        KSZ9021RN_test_enable = 1;
#else // use Atheros ethernet for all other revs (rev B)
        ar8031_test_enable = 1; // ethernet
#endif

        weim_nor_flash_test_enable = 1;

        nand_test_enable = 0;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        max7310_i2c_device_id_test_enable = 1;  // Port expander ID tests

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;

        usbo_dev_enum_test_base = USBOH3_USB_BASE_ADDR;
        usbo_dev_enum_test_enable = 1;

        // include further testing of the SABRE AI MAIN board if selected
        switch (tests)
        {
			case SEL_CPU_ONLY_TESTS:

	            adv7180_test_enable = 0;    // VIDEO INPUT
	            esai_test_enable = 0;       // AUDIO

	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 0;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;      //J30 on the main board
	            usbh_dev_enum_test_enable = 0;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_cs42888_test_enable = 0;    // codec
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mag3112_test_enable = 0;    // eCompass - no pop on sabre_ai
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

	            android_buttons_test_enable = 0;
	            can_test_enable = 0;
	            ard_mb_reset_test_enable = 0;
	            ard_mb_expander_reset_test_enable = 0;

	            mmcsd_test_enable = 0;
	            mmcsd_bus_width = 8;
	            mmc_sd_base_address = USDHC3_BASE_ADDR;

				break;

			case SEL_CPU_PLUS_BOARD_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

//	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
//	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 0;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;      //J30 on the main board
	            usbh_dev_enum_test_enable = 1;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_cs42888_test_enable = 1;    // codec
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mag3112_test_enable = 0;    // eCompass - no pop on sabre_ai
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

	            android_buttons_test_enable = 1;
	            can_test_enable = 1;
	            ard_mb_reset_test_enable = 1;
	            ard_mb_expander_reset_test_enable = 1;

	            mmcsd_test_enable = 1;
	            mmcsd_bus_width = 8;
	            mmc_sd_base_address = USDHC3_BASE_ADDR;

	            break;

			case SEL_MENU_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;      //J30 on the main board
	            usbh_dev_enum_test_enable = 1;

	            pf0100_i2c_device_id_test_enable = 1;           // PMIC PF0100 ID test
	            i2c_device_id_check_cs42888_test_enable = 1;    // codec
	            i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
	            i2c_device_id_check_mag3112_test_enable = 0;    // eCompass - no pop on sabre_ai
	            i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer

	            android_buttons_test_enable = 1;
	            can_test_enable = 1;
	            ard_mb_reset_test_enable = 1;
	            ard_mb_expander_reset_test_enable = 1;

	            mmcsd_test_enable = 1;
	            mmcsd_bus_width = 8;
	            mmc_sd_base_address = USDHC3_BASE_ADDR;

	            break;

			default:
				printf("ERROR: Unsupported test configuration.\n");
				break;
        }

    }  // if (BOARD_TYPE == BOARD_TYPE_SABRE_AI)

    if (BOARD_TYPE == BOARD_TYPE_SMART_DEVICE) {
        ar8031_test_enable = 1; // Atheros ethernet

        pf0100_i2c_device_id_test_enable = 1;

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;

        camera_test_enable = 1;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;
        weim_nor_flash_test_enable = 0;

        usbo_dev_enum_test_base = USBOH3_USB_BASE_ADDR;
        usbo_dev_enum_test_enable = 1;

        i2c_device_id_check_isl29023_test_enable = 1;   // light sensor
        i2c_device_id_check_mag3112_test_enable = 1;    // eCompass
        i2c_device_id_check_mma8451_test_enable = 1;    // accelerometer
        // barometer is listed as DNP in schematic

        /* eMMC test */
        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC4_BASE_ADDR;

        i2s_audio_test_enable = 1;
        epd_test_enable = 1;
        // touch_button_test_enable = 1;

    }                           // if (BOARD_TYPE == BOARD_TYPE_SMART_DEVICE)

    if (BOARD_TYPE == BOARD_TYPE_SABRE_LITE) {
        KSZ9021RN_test_enable = 1;  // micrel ethernet

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        // spi_nor_test_enable = 1;
        // spi_nor_flash_type = M25P32;

        //usbh_dev_enum_test_base = USBH1_BASE_ADDR;
        //usbh_dev_enum_test_enable = 1;  // will return HUB info
        usbh_hub251x_test_base = USBH1_BASE_ADDR;
        usbh_hub251x_test_enable = 1;   // will return device info connected to hub

        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC3_BASE_ADDR;

        i2s_audio_test_enable = 1;  // sabre-lite audio out of sgtl5000

    }                           // if (BOARD_TYPE == BOARD_TYPE_SABRE_LITE)

    if (BOARD_TYPE == BOARD_TYPE_EVB) {
        // these tests apply to EVB CPU board

        //ds90ur124_test_enable = 0;
        //si476x_test_enable = 0;
        //weim_nor_flash_test_enable = 1;

        ar8031_test_enable = 1; // Atheros ethernet

        nand_test_enable = 1;

        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;
        ipu_display_panel[display++] = DISP_DEV_MIPI;

        max7310_i2c_device_id_test_enable = 1;

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;

        mmcsd_test_enable = 1;
        mmcsd_bus_width = 8;
        mmc_sd_base_address = USDHC3_BASE_ADDR;

        eeprom_test_enable = 1;

        switch (tests)
        {
			case SEL_CPU_ONLY_TESTS:
	            //adv7180_test_enable = 0;
	            esai_test_enable = 0;
	            usbh_EHCI_test_mode_test_enable = 0;
				break;
			case SEL_CPU_PLUS_BOARD_TESTS:
		        // include further testing of the EVB MAIN board if selected
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			case SEL_MENU_TESTS:
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			default:
				printf("ERROR: Unsupported test configuration.\n");
				break;
        }

    } // if (BOARD_TYPE == BOARD_TYPE_EVB)

}
#elif defined(CHIP_MX6SL)
void select_tests(SELECT_TESTS tests)
{
    mmcsd_test_enable = 1;
    program_mac_address_enable = 1;

    if (BOARD_TYPE == BOARD_TYPE_EVB) {

		pf0100_i2c_device_id_test_enable = 1;         // pmic i2c dev id
		epd_test_enable = 1;
		lcd_test_enable = 1;
		camera_test_enable = 1;
		fec_test_enable = 1;
		i2s_audio_test_enable = 1;
		keypad_test_enable = 1;
		usbh_EHCI_test_mode_base = USBOH3_USB_BASE_ADDR;
		usbh_EHCI_test_mode_test_enable = 0;          // for debug
		usbh_dev_enum_test_base = USBH1_BASE_ADDR;
		usbh_dev_enum_test_enable = 1;                //J10 on CPU board
		usbo_dev_enum_test_base = USBOH3_USB_BASE_ADDR;
		usbo_dev_enum_test_enable = 1;                // J9 on CPU board
//		weim_nor_flash_test_enable = 1;

		spi_nor_test_enable = 1;
		spi_nor_flash_type = M25P32;

        switch (tests)
        {
			case SEL_CPU_ONLY_TESTS:

				epd_test_enable = 0;
				keypad_test_enable = 0;

				break;

			case SEL_CPU_PLUS_BOARD_TESTS:
				break;

			case SEL_MENU_TESTS:
				break;

			default:
				printf("ERROR: Unsupported test configuration.\n");
				break;
        }

    } // if (BOARD_TYPE == BOARD_TYPE_EVB)

}
#endif
#endif //0
