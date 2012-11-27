/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
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
#if !defined(__OBDS_H__)
#define __OBDS_H__

#include <stdint.h>
#include "sdk.h"
#include "audio/audio.h"
#include "menu.h"
#include "text_color.h"
#include "obds_hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Forward type declarations
////////////////////////////////////////////////////////////////////////////////
typedef struct _test_result_node test_result_node_t;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Flag indicating tests should run with minimal user interaction.
extern int auto_run_enable;

/*!
 * @brief OBDS Test function definition. Called in response to a menuitem being selected by the user.
 *
 * @return  The result of the test.
 */
typedef test_return_t (*obds_test_function_t) (void);

test_return_t prompt_run_test(const char * const test_name, const char* const indent);
void print_test_passed(const char* const test_name, const char* const indent);
void print_test_skipped(const char* const test_name, const char* const indent);
void print_test_failed(const char* const test_name, const char* const indent);
void print_test_not_implemented(const char* const test_name, const char* const indent);
void free_test_results(void);

//#define OBDS_DEBUG
#ifdef OBDS_DEBUG
#define printf1    printf
#else
#define printf1(fmt,args...)
#endif
//#define OBDS_DEBUG2
#ifdef OBDS_DEBUG2
#define printf2    printf
#else
#define printf2(fmt,args...)
#endif

// TODO Replace this with function prompt_run_test
#define PROMPT_RUN_TEST(name, indent)                       \
    do {                                                    \
        printf("\n%s---- Running < %s >\n", indent, name);  \
        if (!auto_run_enable) {                             \
            if (!is_input_char('y', indent))                \
                return TEST_BYPASSED;                       \
        }                                                   \
        else                                                \
            printf("\n");                                   \
    } while (0)

/*!
 * maximum number of tests currently supported
 */
#define MAX_TESTS              50

typedef enum _select_tests
{
    SelectTests_CpuBoardOnly,
    SelectTests_MainBoardOnly,
    SelectTests_CpuAndMainBoard,
    SelectTests_Menu

} select_tests_t;

//! @brief OBDS Test container to hold description and results for each test.
typedef struct _obds_test
{
    //! @brief The key associated with the test.
    const char* key;

    //! @brief The description the test.
    const char* description;

    //! @brief The test function pointer.
    obds_test_function_t test_function;

    //! @brief A pointer to the linked list of test results.
    test_result_node_t* result_node;

} obds_test_t;

//! @brief OBDS Test result linked list node for recording tests results for multiple iterations of the same test.
typedef struct _test_result_node
{
    test_return_t result;
    test_result_node_t * next;
} test_result_node_t;

/*!
 * @brief Menu Execution function definition. Abstraction layer between menu and test.
 *
 *        Calls the OBDS test function and stores the result in the global result vector.
 *
 * @param   param OBDS test function to call.
 * @return  How to proceed with menu processing.
 */
menu_action_t run_test(void*  param);

// OBDS Test Groups
extern const menuitem_t MenuList_All_Tests[];
extern const menuitem_t CPU_Tests[];
extern const menuitem_t MainBoard_Tests[];
extern const menuitem_t Menu_Commands[];

// OBDS tests
extern const char g_program_board_id_test_name[];
test_return_t program_board_id(void);
extern const char g_program_mac_address_test_name[];
test_return_t program_mac_address(void);
extern const char g_ddr_test_name[];
test_return_t ddr_test(void);
extern const char g_snvs_srtc_test_name[];
test_return_t snvs_srtc_test(void);
extern const char g_KSZ9021RN_test_name[];
test_return_t KSZ9021RN_test_main(void);
extern const char g_ar8031_test_name[];
test_return_t ar8031_test_main(void);
extern const char g_eim_NOR_flash_test_name[];
test_return_t eim_nor_flash_test(void);
extern const char g_max7310_i2c_device_id_test_name[];
test_return_t max7310_i2c_device_id_check(void);
extern const char g_hs_tsc_p1003_i2c_device_id_test_name[];
test_return_t i2c_device_id_check_p1003(void);
extern const char g_pmic_pf0100_i2c_device_id_test_name[];
test_return_t pf0100_i2c_device_id_check(void);
extern const char g_spi_nor_test_name[];
test_return_t spi_nor_test(void);
extern const char g_usb_otg_dev_enum_test_name[];
test_return_t usbo_dev_enum_test(void);
extern const char g_sata_test_name[];
test_return_t sata_test(void);
extern const char g_ipu_display_tests_name[];
test_return_t ipu_display_test_main(void);

test_return_t android_buttons_test(void);
extern const char g_touch_buttons_test_name[];
test_return_t touch_button_test(void);
test_return_t touch_screen_test(void);
test_return_t i2c_device_id_check(void);
test_return_t pmic_test(void);

test_return_t enet_test_main(void);
extern const char * const flexcan_test_name[];
test_return_t flexcan_test(void);
test_return_t i2s_audio_test(void);
extern const char * const uart_test_name[];
test_return_t uart_test(void);
test_return_t mmcsd_test(void);
extern const char g_usb_host1_dev_enum_test_name[];
extern const char g_usb_EHCI_test_modes_name[];

//
// PRIVATE
//
extern menuitem_t main_menuitems[];

void report_test_results(void);
menu_action_t run_all_tests(void* const param);
void select_tests(menuitem_t* menuitems, const select_tests_t select_tests);

//list of tests from obds
extern int eeprom_test_enable;
extern int adv7180_test_enable;
extern int ard_mb_reset_test_enable;
extern int ard_mb_expander_reset_test_enable;
extern int ds90ur124_test_enable;
extern int mlb_os81050_test_enable;
extern int weim_nor_flash_test_enable;
extern int usbh_EHCI_test_mode_test_enable;
extern int usbh_dev_enum_test_enable;
extern int usbo_dev_enum_test_enable;
extern int usbh_hub251x_test_enable;
extern int smbus_test_enable;

extern int sdio_test_enable;
extern int gps_test_enable;
extern int si476x_test_enable;
extern int camera_flashtest_ebable;
extern int esai_test_enable;

//Add variables from obds
extern uint32_t usbh_EHCI_test_mode_base;
extern uint32_t usbh_dev_enum_test_base;
extern uint32_t usbh_hub251x_test_base;
extern uint32_t sdio_bus_width;
extern uint32_t sdio_base_address;

extern audio_pcm_t pcm_record;
extern audio_pcm_t pcm_music;
extern audio_card_t snd_card_ssi;
extern audio_card_t snd_card_ssi_sgtl5000;
extern audio_card_t snd_card_ssi_wm8958;
extern audio_card_t snd_card_ssi_wm8962;

//Provide macros for test enter and exit outputs
#define TEST_ENTER(name) printf("Running test: %s\n", name)
#define TEST_EXIT(name) do {printf("..Test: %s\n", name); } while(0) 



#endif // __OBDS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
