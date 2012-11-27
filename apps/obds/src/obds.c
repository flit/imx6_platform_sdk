/*
 * Copyright (c) 2009-2012, Freescale Semiconductor, Inc.
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
#include "sdk.h"
#include "board_id/board_id.h"
#include "obds.h"
#include "obds_utils.h"
#include "platform_init.h"
#include "text_color.h"
#include "sdk_version.h"
#include "print_clock_info.h"
#include "print_version.h"


int total_tests = 0;
int auto_run_enable = 1; // global flag to indicate auto-run feature enabled or not
menuitem_t main_menuitems[MAX_TESTS];
obds_test_t obds_tests[MAX_TESTS];

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
    // Create the test list (menuitems) for the board.
    //
    memset(obds_tests, 0, MAX_TESTS * sizeof(obds_test_t));
    select_tests(main_menuitems, SelectTests_Menu);

    //
    // Initialize the test results list.
    //
    memset(obds_tests, 0, MAX_TESTS * sizeof(obds_test_t));
    int mi = 0, ti = 0;
    for(mi=0; main_menuitems[mi].type != MenuItem_Null; ++mi)
    {
        if (main_menuitems[mi].func_ptr != (menu_function_t)run_test)
            continue;

        obds_tests[ti].key = main_menuitems[mi].key;
        obds_tests[ti].description = main_menuitems[mi].description;
        obds_tests[ti].test_function = (obds_test_function_t)main_menuitems[mi].func_param;
        obds_tests[ti].result_node = (test_result_node_t*)malloc(sizeof(test_result_node_t));
        obds_tests[ti].result_node->result = TEST_NOT_STARTED;
        obds_tests[ti].result_node->next = NULL;
        ++ti;
    }

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
    const menu_t main_menu = {
            .header = main_menu_desc,
            .menuitems = main_menuitems,
            .footer = "Enter test number followed by the enter key, 'm' for menu, or 'q' to exit."
    };

    //
    // Show the main menu
    //
    menu_present(&main_menu);

    //
    // Report the results of the tests.
    //
    report_test_results();


    free_test_results();
    _sys_exit(0);

    return 0;
}

void free_test_results(void)
{
    for (int i=0; obds_tests[i].key == NULL; ++i)
    {
    test_result_node_t* result = obds_tests[i].result_node;
        while(result)
        {
            test_result_node_t* temp = result;
            result = temp->next;
            free(temp);
        }
    }
}


int printf_hook(const char *format, ...)
{
     int n = 0;
     va_list args;
     va_start(args, format);

     char param_format[8192];
     char obds_format[8192] = {'\0'};
     char token_buffer[8192] = {'\0'};
     const char* indent = menu_get_indent();
     strcpy(param_format, format);


     if ( format[0] == '\n' || format[0] == '\r')
         sprintf(obds_format, "%s\n", indent);

     const char separators[]   = "\r\n";

     char *token;
     token = strtok(param_format, separators);
     while( token != NULL )
    {
       sprintf(token_buffer, "%s%s\n", indent, token);
       strcat(obds_format, token_buffer);

       token = strtok( NULL, separators);
    }

     /* If needed, put your change to arguments in here,
      * char *argv = NULL;
      * argv = va_arg(args, char *);
      * argv …
      */

     n = vprintf("inside obds_printf\n", args);

     n = vprintf(format, args);
     va_end(args);
     return n;
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

//! @brief Action function to call the test function passed in as a parameter.
menu_action_t run_test(void* param)
{
    test_return_t testResult = TEST_NOT_STARTED;

    const char* const indent = menu_get_indent();
    obds_test_function_t testFunction = (obds_test_function_t)param;

    int i = 0;
    while (obds_tests[i].test_function != testFunction) ++i;
    test_result_node_t* result_node = obds_tests[i].result_node;

    if ( prompt_run_test(obds_tests[i].description, indent) != TEST_CONTINUE )
        testResult = TEST_BYPASSED;
    else
        testResult = testFunction();

    while (result_node->next != NULL)
        result_node = result_node->next;
    result_node->result = testResult;
    result_node->next = (test_result_node_t*) malloc(sizeof(test_result_node_t));
    result_node->next->result = TEST_NOT_STARTED;
    result_node->next->next = NULL;

    switch(testResult)
    {
        case TEST_BYPASSED:
            print_test_skipped(obds_tests[i].description, indent);
            break;
        case TEST_FAILED:
            print_test_failed(obds_tests[i].description, indent);
            break;
        case TEST_PASSED:
            print_test_passed(obds_tests[i].description, indent);
            break;
        case TEST_NOT_IMPLEMENTED:
            print_test_not_implemented(obds_tests[i].description, indent);
            break;
        case TEST_NOT_PRESENT:
        case TEST_CONTINUE:
        case TEST_NOT_STARTED:
            break;
    }

    return MenuAction_Continue;
}

//
// Report the results of the tests.
// NOTE: Only the last test result for a given test is reflected
//       in the summary if a test was run more than once from the menu.
//
void report_test_results(void)
{
    int passed = 0, failed = 0, not_implemented = 0, skipped = 0, not_run = 0, not_present = 0, unknown = 0;
    int i;

    printf("\n----------------- TEST RESULTS -----------------\n");
    for (i = 0; obds_tests[i].key != NULL; i++)
    {
        test_result_node_t* test_result = obds_tests[i].result_node;
        int test_pass = 1;
        while ( test_result != NULL && test_pass > 1 )
        {
            if (test_result->result == TEST_NOT_PRESENT)
            {
                ++not_present;
            }
            else if (test_result->result == TEST_PASSED)
            {
                printf_color(NULL/*g_TextAttributeBold*/, g_TextColorGreen, "\t<%s> pass %d PASSED\n", obds_tests[i].description, test_pass);
                ++passed;
            }
            else if (test_result->result == TEST_FAILED)
            {
                printf_color(g_TextAttributeBold, g_TextColorRed, "\t<%s> pass %d FAILED\n", obds_tests[i].description, test_pass);
                ++failed;
            }
            else if (test_result->result == TEST_NOT_IMPLEMENTED)
            {
                printf_color(g_TextAttributeBold, g_TextColorRed, "\t<%s> is NOT IMPLEMENTED\n", obds_tests[i].description);
                ++not_implemented;
            }
            else if (test_result->result == TEST_BYPASSED)
            {
                printf_color(NULL/*g_TextAttributeBold*/, g_TextColorYellow, "\t<%s> SKIPPED\n", obds_tests[i].description);
                ++skipped;
            }
            else if (test_result->result == TEST_NOT_STARTED)
            {
                printf_color(g_TextAttributeDim, g_TextColorGray, "\t<%s> NOT RUN\n", obds_tests[i].description);
                ++not_run;
            }
            else
            {
                ++unknown;
            }

            test_result = test_result->next;
            ++test_pass;
        }
    }

    printf("\n=================== SUMMARY ====================\n");
    printf("PASSED:          \t%d\n", passed);
    printf("FAILED:          \t%d\n", failed);
    printf("NOT IMPLEMENTED: \t%d\n", not_implemented);
    printf("SKIPPED:         \t%d\n", skipped);
    printf("NOT RUN:         \t%d\n", not_run);
    printf("TOTAL:           \t%d\n", MAX_TESTS - not_present - unknown);
    printf("=================================================\n");
}

menu_action_t run_all_tests(void* const param)
{
    select_tests_t tests = SelectTests_CpuAndMainBoard;
    const char* indent = menu_get_indent();

    if (BOARD_TYPE == BOARD_TYPE_SABRE_AI || BOARD_TYPE == BOARD_TYPE_EVB)
    {
        printf("%sDo you wish to run the CPU-ONLY set of tests?\n", indent);
        if (is_input_char('y', indent)) {
            printf("%s  Run CPU-ONLY tests.\n\n", indent);
            tests = SelectTests_CpuBoardOnly;
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
        if ( main_menuitems[test_idx].func_ptr &&
             strcmp(main_menuitems[test_idx].key, "m") != 0 &&
             strcmp(main_menuitems[test_idx].key, "q") != 0 )
        {
            // This calls run_test() which handles all the prompting and return results.
            main_menuitems[test_idx].func_ptr(main_menuitems[test_idx].func_param);
        }
    }

    return MenuAction_Exit;
}

void select_tests(menuitem_t menuitems[], const select_tests_t select_tests)
{
    memset(menuitems, 0, sizeof(menuitem_t) * MAX_TESTS);
    menuitems[0].type = MenuItem_Null;

    menu_append_menuitems(menuitems, MAX_TESTS, MenuList_All_Tests);

#if defined(BOARD_SABRE_AI)

    int display = 0;

    if ( select_tests != SelectTests_MainBoardOnly )
    {
        menu_append_menuitems(menuitems, MAX_TESTS, CPU_Tests);
        ipu_display_panel[display++] = DISP_DEV_TFTLCD;
        ipu_display_panel[display++] = DISP_DEV_LVDS;
        ipu_display_panel[display++] = DISP_DEV_HDMI;
    }
    if ( select_tests != SelectTests_CpuBoardOnly )
    {
        menu_append_menuitems(menuitems, MAX_TESTS, MainBoard_Tests);
        if ( select_tests == SelectTests_MainBoardOnly )
            ipu_display_panel[display++] = DISP_DEV_LVDS;
    }

    ipu_display_panel[display++] = DISP_DEV_NULL;

#endif // defined(BOARD_SABRE_AI)

    menu_append_menuitems(menuitems, MAX_TESTS, Menu_Commands);
}

const menuitem_t MenuList_All_Tests[] =
{
    MENU_MAKE_MENUITEM("00", "RUN ALL TESTS", run_all_tests, NULL),
    MENU_MAKE_MENUITEM_END()
};

const menuitem_t Menu_Commands[] =
{
    MENU_MAKE_MENUITEM_GROUP("Menu functions"),
    MENU_MAKE_MENUITEM_SHOW(),
    MENU_MAKE_MENUITEM_EXIT(),
    MENU_MAKE_MENUITEM_END()
};

#if defined (CHIP_MX6DQ) || defined(CHIP_MX6SDL)
#if defined(BOARD_SABRE_AI)

    const menuitem_t CPU_Tests[] =
    {
        MENU_MAKE_MENUITEM_GROUP("CPU Board Tests"),
        MENU_MAKE_MENUITEM("01", g_program_board_id_test_name, run_test, program_board_id),
        MENU_MAKE_MENUITEM("02", g_program_mac_address_test_name, run_test, program_mac_address),
        MENU_MAKE_MENUITEM("03", g_ddr_test_name, run_test, ddr_test),
        MENU_MAKE_MENUITEM("04", g_snvs_srtc_test_name, run_test, snvs_srtc_test),
#if defined(BOARD_REV_A)
        // use micrel ethernet for rev A board
        MENU_MAKE_MENUITEM("05", g_KSZ9021RN_test_name, run_test, KSZ9021RN_test_main),
#else
        // use Atheros ethernet for all other revs (rev B)
        MENU_MAKE_MENUITEM("05", g_ar8031_test_name, run_test, ar8031_test_main),
#endif
        MENU_MAKE_MENUITEM("06", g_eim_NOR_flash_test_name, run_test, eim_nor_flash_test),
        MENU_MAKE_MENUITEM("07", g_max7310_i2c_device_id_test_name, run_test, max7310_i2c_device_id_check),
        MENU_MAKE_MENUITEM("08", g_hs_tsc_p1003_i2c_device_id_test_name, run_test, i2c_device_id_check_p1003),
        MENU_MAKE_MENUITEM("09", g_pmic_pf0100_i2c_device_id_test_name, run_test, pf0100_i2c_device_id_check),
        MENU_MAKE_MENUITEM("10", g_spi_nor_test_name, run_test, spi_nor_test),
        MENU_MAKE_MENUITEM("11", g_usb_otg_dev_enum_test_name, run_test, usbo_dev_enum_test),
#if defined(CHIP_MX6DQ)
        MENU_MAKE_MENUITEM("25", g_sata_test_name, run_test, sata_test),
#endif
        MENU_MAKE_MENUITEM_END()
    };


    const menuitem_t MainBoard_Tests[] =
    {
        MENU_MAKE_MENUITEM_GROUP("Main Board Tests"),
//        MENU_MAKE_MENUITEM("09", "I2S Audio Test", run_test, i2s_audio_test),
//        MENU_MAKE_MENUITEM("12", uart_test_name, run_test, uart_test),
//        MENU_MAKE_MENUITEM("14", "MMC/SD Test", run_test, mmcsd_test),
//c        MENU_MAKE_MENUITEM("10", "ANDROID BUTTONS Test", run_test, android_buttons_test),
//c        MENU_MAKE_MENUITEM("11", flexcan_test_name, run_test, flexcan_test),
//      MENU_MAKE_MENUITEM("12", "RGMII AR8031 G-Ethernet Test", run_test, ar8031_test_main),
//      MENU_MAKE_MENUITEM("13", "RGMII AR8031 G-Ethernet Test", run_test, ar8031_test_main),
//      can_test_enable = 1;
//      ard_mb_reset_test_enable = 1;
//      ard_mb_expander_reset_test_enable = 1;
        MENU_MAKE_MENUITEM_END()
    };

#elif defined(BOARD_SMART_DEVICE)
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
#elif defined(BOARD_EVB)
#if defined(CHIP_MX6DQ)
//    sata_test_enable = 1;
#endif
#endif
#elif defined(CHIP_MX6SL)
#if defined(BOARD_EVK)
    const menuitem_t CPU_Tests[] =
    {
        MENU_MAKE_MENUITEM_GROUP("CPU Board Tests"),
        MENU_MAKE_MENUITEM("01", g_program_board_id_test_name, run_test, program_board_id),
        MENU_MAKE_MENUITEM("02", g_program_mac_address_test_name, run_test, program_mac_address),
        MENU_MAKE_MENUITEM("03", g_ddr_test_name, run_test, ddr_test),
        MENU_MAKE_MENUITEM("04", g_snvs_srtc_test_name, run_test, snvs_srtc_test),
//        MENU_MAKE_MENUITEM("05", "Ethernet Test", run_test, enet_test_main),
        MENU_MAKE_MENUITEM_END()
    };


    const menuitem_t MainBoard_Tests[] =
    {
        MENU_MAKE_MENUITEM_GROUP("Main Board Tests"),
        MENU_MAKE_MENUITEM_END()
    };
#endif
#endif


#if 0
    if ( select_tests != SEL_MAIN_BOARD_ONLY_TESTS )
    {
        //common tests for all chips and boards
        menu_make_menuitem_group(&menuitems[menu_idx++], "CPU Board Tests");
        menu_make_menuitem(&menuitems[menu_idx], "01", "BOARD ID Test", program_board_id, &test_results[menu_idx]);menu_idx++;
        menu_make_menuitem(&menuitems[menu_idx], "02", "MAC Address Test", program_mac_address, &test_results[menu_idx]);menu_idx++;
//      menu_make_menuitem(&menuitems[menu_idx], "04", "SNVS - SRTC Test", snvs_srtc_test, &test_results[menu_idx]);menu_idx++;

    // use Atheros ethernet for all other revs (rev B)
//  menu_make_menuitem(&menuitems[menu_idx], "05", "Ethernet Test", enet_test_main, &test_results[menu_idx]);menu_idx++;    
//  menu_make_menuitem(&menuitems[menu_idx], "08", "I2C Device ID Test", i2c_device_id_check, &test_results[menu_idx]);menu_idx++;      
//  menu_make_menuitem(&menuitems[menu_idx], "09", "I2S Audio Test", i2s_audio_test, &test_results[menu_idx]);menu_idx++;
//  menu_make_menuitem(&menuitems[menu_idx], "12", "UART Test", uart_test, &test_results[menu_idx]);menu_idx++;
//  menu_make_menuitem(&menuitems[menu_idx], "13", "SPI NOR FLASH Test", spi_nor_test, &test_results[menu_idx]);menu_idx++; 
//  menu_make_menuitem(&menuitems[menu_idx], "14", "MMC/SD Test", mmcsd_test, &test_results[menu_idx]);menu_idx++;      
//  menu_make_menuitem(&menuitems[menu_idx], "15", "PMIC - PF0100 Test", pf0100_i2c_device_id_check, &test_results[menu_idx]);menu_idx++;   
//      menu_make_menuitem(&menuitems[menu_idx], "11", "FLEXCAN1/2 LOOPBACK Test", flexcan_test, &test_results[menu_idx]);menu_idx++;
    }

    if ( select_tests != SEL_CPU_BOARD_ONLY_TESTS )
    {
        menu_make_menuitem_group(&menuitems[menu_idx++], "Main Board Tests");
#if defined(CHIP_MX6DQ)
#if defined(BOARD_EVB)

#elif defined(BOARD_SABRE_AI)

#if defined(BOARD_REV_A)        // use micrel ethernet for rev A board
    menu_make_menuitem(&menuitems[menu_idx], "05", "RGMII KSZ9021RN G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
#else // use Atheros ethernet for all other revs (rev B)
    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
#endif
    menu_make_menuitem(&menuitems[menu_idx], "06", "ANDROID BUTTONS Test", android_buttons_test, &test_results[menu_idx]);menu_idx++;
#elif defined(BOARD_SMART_DEVICE)
    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
    menu_make_menuitem(&menuitems[menu_idx], "06", "TOUCH BUTTONS Test", touch_button_test, &test_results[menu_idx]);menu_idx++;
#endif // defined(BOARD)
    menu_make_menuitem(&menuitems[menu_idx], "07", "PMIC Test", pmic_test, &test_results[menu_idx]);menu_idx++;
    menu_make_menuitem(&menuitems[menu_idx], "08", "I2C DEVICE_ID Test", i2c_device_id_check, &test_results[menu_idx]);menu_idx++;  
#endif //chip_mx6dq
        
#if defined(CHIP_MX6SDL)    
#if defined(BOARD_EVB)
    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
#elif defined(BOARD_SABRE_AI)
#if defined(BOARD_REV_A)        // use micrel ethernet for rev A board
    menu_make_menuitem(&menuitems[menu_idx], "05", "RGMII KSZ9021RN G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
#else // use Atheros ethernet for all other revs (rev B)
    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
#endif
    menu_make_menuitem(&menuitems[menu_idx], "06", "ANDROID BUTTONS Test", android_buttons_test, &test_results[menu_idx]);menu_idx++;   
#elif defined(BOARD_SMART_DEVICE)
    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++;
    menu_make_menuitem(&menuitems[menu_idx], "06", "TOUCH BUTTONS Test", touch_button_test, &test_results[menu_idx]);menu_idx++;
#endif // defined(BOARD)
    menu_make_menuitem(&menuitems[menu_idx], "07", "PMIC Test", pmic_test, &test_results[menu_idx]);menu_idx++;
    menu_make_menuitem(&menuitems[menu_idx], "08", "I2C DEVICE_ID Test", i2c_device_id_check, &test_results[menu_idx]);menu_idx++;
#endif //chip_mx6sdl


#if defined(CHIP_MX6SL)
    // Tests for mx6sl evk.
    menu_make_menuitem(&menuitems[menu_idx], "03", "DDR Test", ddr_test, &test_results[menu_idx]);menu_idx++;
//    menu_make_menuitem(&menuitems[menu_idx], "04", "RGMII AR8031 G-Ethernet Test", ar8031_test_main, &test_results[menu_idx]);menu_idx++; 
    menu_make_menuitem(&menuitems[menu_idx], "07", "PMIC Test", pmic_test, &test_results[menu_idx]);menu_idx++;
    menu_make_menuitem(&menuitems[menu_idx], "08", "I2C DEVICE_ID Test", i2c_device_id_check, &test_results[menu_idx]);menu_idx++;
#endif //end chip
    }
#endif //0

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
	            i2c_device_id_check_mag3110_test_enable = 1;    // eCompass - on sabre_ai main board rev. C
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
	            i2c_device_id_check_mag3112_test_enable = 1;    // eCompass - on sabre_ai main board rev. C
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

    ipu_display_panel[display++] = DISP_DEV_NULL;
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

//              ipu_display_panel[display++] = DISP_DEV_TFTLCD;
                ipu_display_panel[display++] = DISP_DEV_LVDS;
//              ipu_display_panel[display++] = DISP_DEV_HDMI;
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
//      weim_nor_flash_test_enable = 1;

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
