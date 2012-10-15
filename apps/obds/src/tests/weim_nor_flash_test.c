/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_weim_nor Driver and test for a NOR flash connected on the WEIM.
 */

/*!
 * @file weim_nor_flash.c
 * @brief Driver for a NOR flash connected to the i.MX WEIM.
 *
 * @ingroup diag_weim_nor
 */

#include "obds.h"

/*!
 * Add the following defines to support a new NOR:
 * Only one NOR should be defined here, other must be commented !!!!!!!
 * e.g.
 * #define nor_flash_auto_manu_id my_new_nor_here_auto_manu_id
 * #define nor_flash_auto_dev_id my_new_nor_here_auto_dev_id
 */
#define nor_flash_auto_manu_id m29w256gl_auto_manu_id
#define nor_flash_auto_dev_id m29w256gl_auto_dev_id

int nor_flash_auto_manu_id(void);
int nor_flash_auto_dev_id(void);

int weim_nor_flash_test_enable;

// Set up the chip select registers for the weim "parallel" nor flash
void weim_nor_flash_cs_setup(void)
{
   //DSIZ=010 (map 16-bit to D[31:16], csen=1
   // writel(0x00020001, WEIM_BASE_ADDR + 0x000);
   writel(0x00620081, WEIM_BASE_ADDR + 0x0000);

   // CS0 Read Config reg1
   // RWCS=11, OEA=2, OEN=1
   //writel(0x0B002100, WEIM_BASE_ADDR + 0x008);
   writel(0x1C022000, WEIM_BASE_ADDR + 0x0008);

   // CS0 Write Config Reg 1
   // WWCS=11, WEA=2, WEN=1
   //writel(0x0B000440, WEIM_BASE_ADDR + 0x010);
   writel(0x0804a240, WEIM_BASE_ADDR + 0x010); 
}

/*!
 * This test tries to read the manufacturer and device ID of the NOR flash.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
int weim_nor_flash_test(void)
{
    int rc = 0;

    if (!weim_nor_flash_test_enable) {
        return TEST_NOT_PRESENT;
    }
    PROMPT_RUN_TEST("WEIM NOR FLASH", NULL);

    /* init the weim interface for the NOR flash */
    weim_iomux_config();
#if defined(BOARD_SABRE_AI) && !defined(BOARD_REV_A)  // for I2C3 steering
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DISP0_DAT8, ALT5);
    gpio_set_direction(GPIO_PORT4, 29, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT4, 29, GPIO_HIGH_LEVEL);

    /* Select ALT5 mode of EIM_A24 for GPIO5_4 - EIMD18_I2C3_STEER(EIM_A24) */
    /* low output to select WEIM NOR option */
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_A24);
    gpio_set_direction(GPIO_PORT5, 4, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT5, 4, GPIO_LOW_LEVEL);
#endif

    weim_nor_flash_cs_setup();

    rc |= nor_flash_auto_manu_id();
    rc |= nor_flash_auto_dev_id();

    if (rc == 0) {
        return TEST_PASSED;
    } else {
        return TEST_FAILED;
    }
}

//RUN_TEST("WEIM NOR FLASH", weim_nor_flash_test)
