/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "version.h"
#include "cortex_a9.h"
#include "mmu.h"

#ifdef ALL_TEST_ENABLE

extern void sdma_test(void);
extern void ipu_test(void);
extern void uart_test(void);
extern void gpt_test(void);
extern void epit_test(void);
extern void usdhc_test(void);
extern void hdmi_test(void);
extern void audio_test(void);
extern void i2c_test(void);
extern void gic_sgi_test(void);
extern void gic_multicore_test(void);
extern void snvs_rtc_test(void);
extern void snvs_srtc_test(void);
extern void flexcan_test(void);
extern int spi_test(void);
extern void tempmon_test(void);
extern int vpu_test(void);
extern int gpmi_test(void);
extern int mipi_test();
extern int pwm_test();
extern int eim_test();
extern int gpu_test(void);
extern int camera_test(void);
extern int wdog_test(void);
extern int camera_test(void);
extern void usb_test(void);

#if CHIP_MX6DQ
extern int sata_test(void);
extern int pcie_test(void);
#endif

//For obds test only
int        auto_run_enable;
extern int i2s_audio_test(void);
extern int run_ddr_test(void);
extern int ds90ur124_test_main(void);
extern int spi_nor_test(void);
extern int obds_snvs_srtc_test(void);
extern int enet_test_main(void);
extern int ar8031_test_main(void);
extern int KSZ9021RN_test_main(void);
extern int mmcsd_test(void);
extern int program_board_id(void);
extern int i2c_device_id_check(void);
extern int i2c_device_id_check_DA9053(void);
extern int ltc3589_i2c_device_id_check(void);
extern int i2c_device_id_check_MAX17135(void);
extern int device_id_mc13892_test(void);
extern int pf0100_i2c_device_id_check(void);
extern int ds90ur124_test_main(void);
extern int si476x_test_main(void);
extern int gps_test(void);
extern int i2c_eeprom_at24cxx_test(void);
extern int os81050_test_main(void);
extern int srtc_test(void);
extern int touch_button_test(void);
extern int touch_screen_test(void);
extern int adv7180_test_main(void);
extern int ard_mb_reset_test(void);
extern int ard_mb_expander_reset_test(void); 

void ALL_test(void)
{
    uint8_t input;

    while (1) {

        printf("Starting the tests suite...\n");
        printf("1 --- DDR Test\n");
        printf("2 --- UART Test\n");
        printf("3 --- BOARD ID\n");
        printf("4 --- SPI NOR FLASH\n");
        printf("5 --- SNVS SRTC Test\n");
        printf("6 --- I2S Audio Test\n");
        printf("7 --- Ethernet Test\n");
        printf("8 --- PMIC - Test\n");
        printf("9 --- I2C Device Check\n");
        printf("a --- MMC/SD Test\n");
        printf("b --- USB Test\n");
        printf("c --- SATA Test\n");
        printf("d --- Camera & Display\n");
        printf("e --- HDMI display Test\n");
        printf("f --- Deserializer Test \n");
        printf("g --- FM_tuner Test \n");
        printf("h --- gps Test \n");
        printf("i --- EEPROM Test \n");
        printf("j --- mlb Test\n");
        printf("k --- srtc Test \n");
        printf("l --- smbus Test\n");
        printf("m --- Touch button\n");
        printf("n --- Touch Screen\n");
        printf("o --- Video Test\n");
        printf("p --- Video Reset\n");
        printf("q --- Video MBrst\n");
        printf("r --- Weim nor Flash\n");
 
        do {
           input = getchar();
        } while (input == NONE_CHAR);

        switch (input)
        {
        case '1':
           //DDR Test
           ddr_test_enable = 1;
           ddr_density = 1024 * 1024 * 1024;
           ddr_num_of_cs = 1;
           run_ddr_test();
           break;
        case '2':
           //UART test
           uart_test(); 
           break;
        case '3':
           //Board ID test
           program_board_id_enable = 1;
           program_board_id(); 
           break;
        case '4':
           //SPI NOR FLASH
           spi_nor_test_enable = 1;
           spi_nor_flash_type = M25P32;
           spi_nor_test(); 
           break;
        case '5':
           //SNVS SRTC Test
           obds_snvs_srtc_test_enable = 1;
           obds_snvs_srtc_test();
           break;
        case '6':
            //I2S Audio 
            printf("Audio Test --- SDK, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                audio_test();
            }
            printf("Audio Test --- OBDS, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                i2s_audio_test_enable = 1;
                i2s_audio_test();
            }  
            break;
        case '7':
            enet_test_enable = 1;
            enet_test_main();
            ar8031_test_enable = 1;
            ar8031_test_main();
            KSZ9021RN_test_enable = 1;
            KSZ9021RN_test_main();
            break;
        case '8':
            printf("PMIC Test --- DA9053, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                i2c_device_id_check_DA9053_test_enable = 1;
                i2c_device_id_check_DA9053();
            }

            printf("PMIC Test --- ltc3589, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                ltc3589_i2c_device_id_test_enable = 1;
                ltc3589_i2c_device_id_check();
            }

            printf("PMIC Test --- max17135, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                i2c_device_id_check_MAX17135();
            }

           printf("PMIC Test --- mc13892, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                pmic_mc13892_test_enable = 1;
                device_id_mc13892_test();
            }

            printf("PMIC Test --- pf0100, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                pf0100_i2c_device_id_test_enable = 1;
                pf0100_i2c_device_id_check();
            }
            break;
        case '9':
            i2c_device_id_check_isl29023_test_enable = 1;
            //i2c_device_id_check_mma8450_test_enable = 1;
            i2c_device_id_check_mma8451_test_enable = 1;
            i2c_device_id_check_mag3112_test_enable = 1;
            i2c_device_id_check_mag3110_test_enable = 1;        
            i2c_device_id_check_p1003_test_enable = 1;
            i2c_device_id_check_cs42888_test_enable = 1;

            i2c_device_id_check();  
            break;
        case 'a':
            mmcsd_test_enable = 1;
            mmcsd_bus_width = 4;
            mmc_sd_base_address = USDHC4_BASE_ADDR;
            mmcsd_test(); 
            break; 
        case 'b':
 /*           printf("SDK USB Test, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                usb_test();
            }

            printf("USB Test --- EHCI, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                usbh_EHCI_test_mode_test_enable = 1;
                usbh_EHCI_test_mode_base = USBOH3_BASE_ADDR;
                EHCI_test_mode();
            }

            printf("USB Test --- USBH Enum, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                usbh_dev_enum_test_enable = 1;
                usbh_dev_enum_test_base = USBOH3_BASE_ADDR;
                usbh_dev_enum_test();
            }
 
            printf("USB Test --- USBOTG Enum, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                usbo_dev_enum_test_enable = 1;
                usbo_dev_enum_test_base = USBOH3_BASE_ADDR;
                usbo_dev_enum_test();
            }

            printf("USB Test --- USB Hub, y/n\n");
            do {
                input = getchar();
            } while (input == NONE_CHAR);
            if ((input == 'Y') || (input == 'y'))
            {
                usbh_hub251x_test_enable = 1;
                usbh_hub251x_test_base = USBOH3_BASE_ADDR;
                usbh_hub251x_test();
            }       
*/            break;
        case 'c':
            sata_test();
            break;
        case 'd':
//            camera_test();
            break;
        case 'e':
//            hdmi_test();
            break;
        case 'f':
            ds90ur124_test_enable = 1;
            ds90ur124_test_main();
            break;
        case 'g':
            si476x_test_enable = 1;
            si476x_test_main();
            break;
        case 'h':
            gps_test_enable = 1;
            gps_test();
            break;
        case 'i':
            i2c_eeprom_at24cxx_test();
            break;
        case 'j':
            mlb_os81050_test_enable = 1;
            os81050_test_main();
            break;
        case 'k':
            srtc_test_enable = 1;
            srtc_test();
            break;
        case 'l':
//            smbus_test_enable = 1;
//            smbus_test_routine();
            break;
        case 'm':
            touch_button_test_enable = 1;
            touch_button_test();
            break;
        case 'n':
            touch_screen_test_enable = 1;
            touch_screen_test();
            break;
        case 'o':
            adv7180_test_enable = 1;
            adv7180_test_main();
            break;
        case 'p':
            ard_mb_reset_test_enable = 1;
            ard_mb_reset_test();
            break;
        case 'q':
            ard_mb_expander_reset_test_enable = 1;
            ard_mb_expander_reset_test();
            break;
        case 'r':
//            weim_nor_flash_test_enable = 1;
//            weim_nor_flash_test();
            break;
        default:
           break;
        }

        printf("\n...end of the tests suite.\n");
    }
}

#endif /* ALL_TEST_ENABLE */

