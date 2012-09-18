/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__OBDS_H__)
#define __OBDS_H__

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//list of tests from obds
extern int android_buttons_test_enable;
extern int touch_button_test_enable;
extern int eeprom_test_enable;
extern int ddr_test_enable;
extern int i2c_device_id_check_p1003_test_enable;
extern int i2c_device_id_check_mma8451_test_enable;
extern int i2c_device_id_check_mag3110_test_enable;
extern int i2c_device_id_check_mag3112_test_enable;
extern int i2c_device_id_check_isl29023_test_enable;
extern int i2c_device_id_check_cs42888_test_enable;
extern int touch_screen_test_enable;
extern int adv7180_test_enable;
extern int ard_mb_reset_test_enable;
extern int ard_mb_expander_reset_test_enable;
extern int ds90ur124_test_enable;
extern int mlb_os81050_test_enable;
extern int weim_nor_flash_test_enable;
extern int pf0100_i2c_device_id_test_enable;
extern int usbh_EHCI_test_mode_test_enable;
extern int usbh_dev_enum_test_enable;
extern int usbo_dev_enum_test_enable;
extern int usbh_hub251x_test_enable;
extern int spi_nor_test_enable;
extern int smbus_test_enable;
extern int i2c_device_id_check_DA9053_test_enable;
extern int ltc3589_i2c_device_id_test_enable;
extern int pmic_mc13892_test_enable;
extern int mmcsd_test_enable;
extern int sdio_test_enable;
extern int gps_test_enable;
extern int ipu_display_test_enable;
extern int si476x_test_enable;
extern int obds_snvs_srtc_test_enable;
extern int enet_test_enable;
extern int ar8031_test_enable;
extern int KSZ9021RN_test_enable;
extern int camera_flashtest_ebable;
extern int i2s_audio_test_enable;
extern int esai_test_enable;
extern int program_board_id_enable;
extern int spi_nor_test_enable;
extern int obds_snvs_srtc_test_enable;
extern int srtc_test_enable;
extern int program_board_id_enable;

//Add variables from obds
extern uint32_t usbh_EHCI_test_mode_base;
extern uint32_t usbh_dev_enum_test_base;
extern uint32_t usbo_dev_enum_test_base;
extern uint32_t usbh_hub251x_test_base;
extern uint32_t mmcsd_bus_width;
extern uint32_t mmc_sd_base_address;
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

typedef unsigned int (*pmic_mc13892_reg_t) (unsigned int reg, unsigned int val, unsigned int write);

#define PROMPT_RUN_TEST(name)           \
    do {                                \
        printf("\n---- Running < %s > test\n", name);       \
        if (!auto_run_enable) {                             \
            if (!is_input_char('y'))                        \
                return TEST_BYPASSED;                       \
        }                                                   \
    } while (0)

extern int auto_run_enable;

#endif // __OBDS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
