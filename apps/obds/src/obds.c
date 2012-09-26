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

#include <stdio.h>
#include "hardware.h"
#include "menu.h"
#include "obds.h"
#include "obds_utils.h"
#include "platform_init.h"
#include "text_color.h"
#include "version.h"


//struct hw_module {
//    char *name;
//    u32 base;
//    u32 freq;
//};

void record_test_result(char *name, int result);

//typedef unsigned int (*pmic_mc13892_reg_t) (unsigned int reg, unsigned int val, unsigned int write);
//
//// ocotp.c
//int fuse_blow_row(int bank, int row, unsigned int value);
//unsigned int sense_fuse(int bank, int row);
//int reload_otp_shadow_registers();
//
//void hal_delay_us(u32 usecs);
//u32 get_freq(u32 module_base);
//char receive_char(void);
//int is_input_char(u8 c);
//int get_menu_item(char *menu_table[]);
//void _sys_exit(int return_code);
//extern int program_mac_address_enable;
//int set_mac(void);
//int gpio_set_direction(int port, int pin, int dir);
//int gpio_get_level(int port, int pin);
//int gpio_set_level(int port, int pin, unsigned int attr);

typedef enum {
	SEL_CPU_ONLY_TESTS,
	SEL_CPU_PLUS_BOARD_TESTS,
	SEL_MENU_TESTS
} SELECT_TESTS;

void select_tests(SELECT_TESTS tests);

// define RUN_TEST_COMMON(name, func)
//	static void add_obds_##func (void)
//	{
//		obds_test_t test_func = (obds_test_t) func;
//		add_test(name, test_func);
//	}
//    static int obds_##func (void)
//    {
//        obds_test_t test_func = (obds_test_t) func;
//        record_test_result(name, test_func());
//        return 0;
//    }
//#define TEST_PASSED     0
//#define TEST_FAILED     -1
//#define TEST_BYPASSED   2
//#define TEST_NOTPRESENT 3


#define RUN_TEST(name, func)            \
    static obds_test_t __obds_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch"))) = func;              \
    static char  __obds_name_##func[MAX_TEST_NAME_LEN] __attribute__ ((used)) __attribute__ ((section(".test_launch"))) = name; \
	static int  __obds_result_##func __attribute__ ((used)) __attribute__ ((section(".test_launch"))) = TEST_NOTPRESENT;

#define RUN_TEST_EARLY(name, func)      \
    static obds_test_t __obds_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_early"))) = func;        \
    static char __obds_name_##func[MAX_TEST_NAME_LEN] __attribute__ ((used)) __attribute__ ((section(".test_launch_early"))) = name;  \
    static int __obds_result_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_early"))) = TEST_NOTPRESENT;

#define RUN_TEST_LATE(name, func)       \
    static obds_test_t __obds_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_late"))) = func;        \
    static char __obds_name_##func[MAX_TEST_NAME_LEN] __attribute__ ((used)) __attribute__ ((section(".test_launch_late"))) = name; \
    static int __obds_result_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_late"))) = TEST_NOTPRESENT;

#define RUN_TEST_INTERACTIVE(name, func)        RUN_TEST_LATE(name, func)

#define PROMPT_RUN_TEST(name)           \
    do {                                \
        printf("\n---- Running < %s > test\n", name);       \
        if (!auto_run_enable) {                             \
            if (!is_input_char('y'))                        \
                return TEST_BYPASSED;                       \
        }                                                   \
    } while (0)


int total_tests = 0;
test_module_t* obds_test_modules[MAX_TEST_NR];

int auto_run_enable = 1; // global flag to indicate auto-run feature enabled or not

extern test_module_t __test_launch_early_start[], __test_launch_early_end[];
extern test_module_t __test_launch_start[], __test_launch_end[];
extern test_module_t __test_launch_late_start[], __test_launch_late_end[];

static int run_all_tests(void)
{
	SELECT_TESTS tests = SEL_CPU_PLUS_BOARD_TESTS;

    if (BOARD_TYPE == BOARD_TYPE_SABRE_AI || BOARD_TYPE == BOARD_TYPE_EVB) {
        printf("\nDo you wish to run the CPU only set of tests (y/n) \n");
        if (is_input_char('y')) {
        	tests = SEL_CPU_ONLY_TESTS;
        }
    }
    //select_tests(tests);
    snvs_srtc_test();

    printf("\nEnable auto-run feature?\n");
    if (is_input_char('y')) {
        printf("  Auto-run enabled.\n");
        auto_run_enable = 1;
    } else {
    	auto_run_enable = 0;
    }

    // run through the tests starting at 1 since run_tests() is at 0.
    int idx = 1;
    for ( idx=1; idx < total_tests; ++idx ) {
    	obds_test_modules[idx]->result = (*obds_test_modules[idx]->func_ptr)();
    }

    return TEST_PASSED;
}

RUN_TEST_EARLY("ALL TESTS", run_all_tests)

void build_test_array()
{
	test_module_t *test;

	// start all normal tests at 1. Reserve 0 for run_tests().
	total_tests = 1;

    for (test = __test_launch_early_start; test < __test_launch_early_end; test++)
    {
    	if ( test->func_ptr == run_all_tests )
    		obds_test_modules[0] = test;
    	else
    		obds_test_modules[total_tests++] = test;
    }
    for (test = __test_launch_start; test < __test_launch_end; test++)
    	obds_test_modules[total_tests++] = test;
    for (test = __test_launch_late_start; test < __test_launch_late_end; test++)
    	obds_test_modules[total_tests++] = test;
}

static void report_test_results(void)
{
    int passed = 0, failed = 0, skipped = 0, unavail = 0, unknown = 0;
    int i;

    printf("\n----------------- TEST RESULTS -----------------\n");
    for (i = 0; i < total_tests; i++) {
        if (obds_test_modules[i]->result == TEST_PASSED) {
            printf_color(PASS_COLOR, "\t<%s> PASSED\n", obds_test_modules[i]->name);
            passed++;
        } else if (obds_test_modules[i]->result == TEST_FAILED) {
            printf_color(ERROR_COLOR, "\t<%s> FAILED\n", obds_test_modules[i]->name);
            failed++;
        } else if (obds_test_modules[i]->result == TEST_BYPASSED) {
            printf_color(ATTENTION_COLOR, "\t<%s> SKIPPED\n", obds_test_modules[i]->name);
            skipped++;
        } else if (obds_test_modules[i]->result == TEST_NOTPRESENT) {
            //printf_color(ATTENTION_COLOR, "\t<%s> NOT PRESENT\n", obds_test_modules[i]->name);
            unavail++;
        } else {
            //printf_color(ERROR_COLOR, "\t<%s> UNKNOWN\n", obds_test_modules[i]->name);
            unknown++;
        }
    }

    textcolor(RESET, BLACK, WHITE);
    printf("\n=================== SUMMARY ====================%s\n", "");
    if (passed)
        printf("PASSED:     \t%d\n", passed);
    if (failed)
        printf("FAILED:     \t%d\n", failed);
    if (skipped)
        printf("SKIPPED:    \t%d\n", skipped);

    printf("TOTAL:      \t%d\n", total_tests - unavail - unknown);
    printf("=================================================%s\n", "");
}

/*!
 * main function that decides which tests to run and prompts the user before
 * running test.
 * @return      should never return because ARM is at WFI (low power mode in the end)
 */
int main(void)
{
    auto_run_enable = 1;

    platform_init();
    print_version();

    show_freq();
    show_ddr_config();
    show_boot_switch_info();

    build_test_array();

    // select_tests(SEL_MENU_TESTS);
    snvs_srtc_test();


    menu();

    report_test_results();

    _sys_exit(0);

    return 0;
}

#if 0
#if defined(CHIP_MX6DQ)
void select_tests(SELECT_TESTS tests)
{
    int display = 0;

    program_board_id_enable = 1;
    program_mac_address_enable = 1;

    etm_test_enable = 1;

    ddr_test_enable = 1;

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

        sata_test_enable = 1;
        nand_test_enable = 0;

        i2c_device_id_check_p1003_test_enable = 1;  // lvds display touch firmware ID test

        max7310_i2c_device_id_test_enable = 1;  // Port expander ID tests

        spi_nor_test_enable = 1;
        spi_nor_flash_type = M25P32;

        usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
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

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

	            sata_test_enable = 1;

				break;

			case SEL_CPU_PLUS_BOARD_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

//	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
//	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

	            sata_test_enable = 0;   // only test in CPU_ONLY mode per Babin 5/9/12

	            break;

			case SEL_MENU_TESTS:

				adv7180_test_enable = 1;    // VIDEO INPUT
	            esai_test_enable = 1;       // AUDIO

	            ipu_display_panel[display++] = DISP_DEV_TFTLCD;
	            ipu_display_panel[display++] = DISP_DEV_LVDS;
	            ipu_display_panel[display++] = DISP_DEV_HDMI;
//              ipu_display_panel[display++] = DISP_DEV_MIPI;

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

        usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
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
	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			case SEL_MENU_TESTS:
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

    program_board_id_enable = 1;
    program_mac_address_enable = 1;
    ddr_test_enable = 1;
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

        usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
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

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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

        usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
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
	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
	            usbh_EHCI_test_mode_test_enable = 1;
	            usbh_dev_enum_test_base = USBH1_BASE_ADDR;
	            usbh_dev_enum_test_enable = 1;
	            /* card slot #2 */
				break;
			case SEL_MENU_TESTS:
	            //adv7180_test_enable = 1;
	            esai_test_enable = 1;
	            usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
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
    program_board_id_enable = 1;
    program_mac_address_enable = 1;
    ddr_test_enable = 1;

    if (BOARD_TYPE == BOARD_TYPE_EVB) {

		pf0100_i2c_device_id_test_enable = 1;         // pmic i2c dev id
		epd_test_enable = 1;
		lcd_test_enable = 1;
		camera_test_enable = 1;
		fec_test_enable = 1;
		i2s_audio_test_enable = 1;
		keypad_test_enable = 1;
		usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
		usbh_EHCI_test_mode_test_enable = 0;          // for debug
		usbh_dev_enum_test_base = USBH1_BASE_ADDR;
		usbh_dev_enum_test_enable = 1;                //J10 on CPU board
		usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
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
