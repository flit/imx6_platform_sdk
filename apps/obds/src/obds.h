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
// Definitions
////////////////////////////////////////////////////////////////////////////////

extern int auto_run_enable;

test_return_t prompt_run_test(const char * const test_name, const char* const indent);
void print_test_passed(const char* const test_name, const char* const indent);
void print_test_skipped(const char* const test_name, const char* const indent);
void print_test_failed(const char* const test_name, const char* const indent);
void print_test_not_implemented(const char* const test_name, const char* const indent);

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

// TODO Replasce this with function prompt_run_test
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
#define MAX_TESTS              200

typedef enum _select_tests
{
	SEL_CPU_BOARD_ONLY_TESTS,
	SEL_MAIN_BOARD_ONLY_TESTS,
	SEL_CPU_AND_MAIN_BOARD_TESTS,
	SEL_MENU_TESTS

} select_tests_t;

// OBDS tests
menu_action_t program_board_id(const menu_context_t* const context, void* const param);
menu_action_t program_mac_address(const menu_context_t* const context, void* const param);
menu_action_t ddr_test(const menu_context_t* const context, void* const param);
menu_action_t android_buttons_test(const menu_context_t* const context, void* const param);
menu_action_t touch_button_test(const menu_context_t* context, void* param);
menu_action_t touch_screen_test(const menu_context_t* context, void* param);
menu_action_t ar8031_test_main(const menu_context_t* const context, void* const param);
menu_action_t KSZ9021RN_test_main(const menu_context_t* const context, void* const param);
menu_action_t i2c_device_id_check(const menu_context_t* const context, void* const param); 
menu_action_t pmic_test(const menu_context_t* const context, void* const param);

menu_action_t snvs_srtc_test(const menu_context_t* const context, void* const param);
menu_action_t enet_test_main(const menu_context_t* const context, void* const param);
menu_action_t flexcan_test(const menu_context_t* const context, void* const param);
menu_action_t i2s_audio_test(const menu_context_t* const context, void* const param);
menu_action_t uart_test(const menu_context_t* const context, void* const param);
menu_action_t spi_nor_test(const menu_context_t* const context, void* const param);
menu_action_t mmcsd_test(const menu_context_t* const context, void* const param);
menu_action_t pf0100_i2c_device_id_check(const menu_context_t* const context, void* const param);

//
// PRIVATE
//
extern menuitem_t main_menuitems[];

void report_test_results(void);
menu_action_t run_all_tests(const menu_context_t* const context, void* const param);
void select_tests(menuitem_t* const menuitems, const select_tests_t select_tests);

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
extern int ipu_display_test_enable;
extern int si476x_test_enable;
//extern int KSZ9021RN_test_enable;
extern int camera_flashtest_ebable;
extern int esai_test_enable;

//Add variables from obds
extern uint32_t usbh_EHCI_test_mode_base;
extern uint32_t usbh_dev_enum_test_base;
extern uint32_t usbo_dev_enum_test_base;
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
