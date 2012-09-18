/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"

#define SPI_NOR_XFER_SZ     512

#define SPI_INIT_PARAM ((uint32_t)0x00000084)

extern int spi_nor_query_atmel(uint32_t * data);
extern int spi_nor_write_atmel(uint32_t addr, uint8_t * data, uint32_t length);
extern int spi_nor_read_atmel(void *src, void *dest, int len);
extern int spi_nor_erase_atmel(uint32_t addr, uint32_t length);
extern int spi_nor_query_numonyx(uint32_t * data);
extern int spi_nor_write_numonyx(uint32_t addr, uint8_t* data, uint32_t length);
extern int spi_nor_read_numonyx(void *src, void *dest, int len);
extern int spi_nor_erase_numonyx(uint32_t addr, uint32_t length);

uint32_t spi_nor_flash_type;
extern dev_ecspi_e dev_spi_nor;

uint8_t __attribute__ ((aligned(4))) spi_nor_tx_buf[SPI_NOR_XFER_SZ];
uint8_t __attribute__ ((aligned(4))) spi_nor_rx_buf[SPI_NOR_XFER_SZ];

struct chip_id {
    char id0;
    char id1;
    char id2;
};

struct chip_id AT45DB321D_id = {
    .id0 = 0x01,                // Atmel AT45DB321D
    .id1 = 0x27,
    .id2 = 0x1f
};

struct chip_id M25P32_id = {
    .id0 = 0x16,
    .id1 = 0x20,
    .id2 = 0x20
};

int spi_nor_query(uint32_t * data, uint32_t spi_nor_flash_type)
{
    /* query id */
    if (spi_nor_flash_type == AT45DB321D)
        return spi_nor_query_atmel(data);
    else if (spi_nor_flash_type == M25P32)
        return spi_nor_query_numonyx(data);

    return 0;
}

/* spi nor write */
int spi_nor_write(uint32_t addr, uint8_t * data, uint32_t length, uint32_t spi_nor_flash_type)
{
    if (spi_nor_flash_type == AT45DB321D)
        return spi_nor_write_atmel(addr, data, length);
    else if (spi_nor_flash_type == M25P32)
        return spi_nor_write_numonyx(addr, data, length);

    return 0;
}

int spi_nor_read(void *src, void *dest, int len, uint32_t spi_nor_flash_type)
{
    if (spi_nor_flash_type == AT45DB321D)
        return spi_nor_read_atmel(src, dest, len);
    else if (spi_nor_flash_type == M25P32)
        return spi_nor_read_numonyx(src, dest, len);

    return 0;
}

int spi_nor_erase(uint32_t addr, uint32_t length, uint32_t spi_nor_flash_type)
{
    if (spi_nor_flash_type == AT45DB321D)
        return spi_nor_erase_atmel(addr, length);
    else if (spi_nor_flash_type == M25P32)
        return spi_nor_erase_numonyx(addr, length);

    return 0;
}

int spi_nor_test_enable;
int spi_nor_test(void)
{
    uint32_t src[128];
    uint32_t dst[128];
    uint32_t i;
    uint8_t id[4];

    if (!spi_nor_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("SPI NOR FLASH");

#if defined(BOARD_SABRE_AI)
    printf("\nConfigure J3 to 2-3 position when running the test.\n");
    printf("and when test is over configure J3 to 1-2 position.\n");
    printf("Has jumper J3 been properly configured?\n");
    if (!is_input_char('y')) {
        printf("  skipping SPI NOR FLASH test \n");
        return TEST_BYPASSED;
    }
#endif

//    spi_init_flash(&imx_spi_nor);
    dev_spi_nor = DEV_ECSPI1;
    //init eCSPI
    ecspi_open(dev_spi_nor, (param_ecspi_t)SPI_INIT_PARAM);

    // Look through table for device data
    spi_nor_query((uint32_t *) id, spi_nor_flash_type);

    // Do we find the device? If not, return error.
    printf("Get chip id: 0x%x, 0x%x, 0x%x, 0x%x\n", id[0], id[1], id[2], id[3]);

    if (spi_nor_flash_type == AT45DB321D) {
        if ((id[0] == AT45DB321D_id.id0) && (id[1] == AT45DB321D_id.id1)
            && (id[2] == AT45DB321D_id.id2)) {
            printf("SPI nor flash chip AT45DBxx found.\n");
            printf("chip id checking PASS.\n");

        } else {
            printf("chip id checking FAIL.\n");
            return TEST_FAILED;
        }
    } else if (spi_nor_flash_type == M25P32) {
        if ((id[0] == M25P32_id.id0) && (id[1] == M25P32_id.id1)
            && (id[2] == M25P32_id.id2)) {
            printf("SPI nor flash chip M25P32xx found.\n");
            printf("chip id checking PASS.\n");

        } else {
            printf("chip id checking FAIL.\n");
            return TEST_FAILED;
        }
    }

    src[0] = 0x12345678;
    src[1] = 0x22222222;

    for (i = 2; i < 128; i++) {
        src[i] = src[i - 1] + src[i - 2];
    }

    printf("Erase spi-nor flash...\n");
    spi_nor_erase(0, 64 * 1024, spi_nor_flash_type);

    printf("Program spi-nor flash... \n");
    if (spi_nor_write(0, (void *)src, 512, spi_nor_flash_type) == 1) {
        /* Not tested as we need a power cycle */
        printf(" SPI NOR test has been bypassed \n");
        return TEST_FAILED;
    }
    printf("Read back data from spi-nor flash \n");
    memset((void *)dst, 0x0, 512);
    spi_nor_read(0, (void *)dst, 512, spi_nor_flash_type);
    printf("Compare data...\n");

    // compare data...
    for (i = 0; i < 128; i++) {
        if (dst[i] != src[i]) {
            printf("SPI NOR verify failed. \n");
            printf("[0x%x] src: 0x%x, dst: 0x%x\n", i, src[i], dst[i]);
            return TEST_FAILED;
        }
    }
    printf("spi-nor test PASS \n");
    return TEST_PASSED;
}

//RUN_TEST("SPI NOR FLASH", spi_nor_test)
