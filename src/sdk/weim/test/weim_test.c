/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"
#include "cfi_flash.h"
#include "../inc/weim_ifc.h"

#define WEIM_BUFFER_SZ 0x1000
static uint32_t weim_test_buffer[WEIM_BUFFER_SZ];

static void weim_hw_prepare(void)
{
    /* Init WEIM */
    weim_init(WEIM_CS0, DSZ_16_HIGH, FALSE, FALSE);
#if 1
    /* Nor flash */
    weim_cfg_set(WEIM_CS0, GCR1_CREP, TRUE);

    /* Address hold time */
    weim_cfg_set(WEIM_CS0, GCR2_ADH, 1);

    /* Bypass grant(only for Muxed 16) */
    weim_cfg_set(WEIM_CS0, GCR2_MUX16_BYP_GRANT, FALSE);

    /* ADV navigation */
    weim_cfg_set(WEIM_CS0, RCR1_RADVN, 2);

    /* OE assertion */
    weim_cfg_set(WEIM_CS0, RCR1_OEA, 0);

    /* Read wait state control */
    weim_cfg_set(WEIM_CS0, RCR1_RWSC, 28);

    /* WE negation */
    weim_cfg_set(WEIM_CS0, WCR1_WEN, 1);

    /* WE assertion */
    weim_cfg_set(WEIM_CS0, WCR1_WEA, 1);

    /* BE negation */
    weim_cfg_set(WEIM_CS0, WCR1_WBEN, 2);

    /* BE assertion */
    weim_cfg_set(WEIM_CS0, WCR1_WBEA, 1);

    /* ADV Negation */
    weim_cfg_set(WEIM_CS0, WCR1_WADVN, 1);

    /* Write wait state control */
    weim_cfg_set(WEIM_CS0, WCR1_WWSC, 8);
#else
    reg32_write(0x21B8090, 0x00000120);
    reg32_write(0x21B8000, 0x00620081);
    reg32_write(0x21B8004, 0x00000001);
    reg32_write(0x21B8008, 0x1C020000);
    reg32_write(0x21B800C, 0x00000000);
    reg32_write(0x21B8010, 0x0804A240);
#endif
}

static int weim_nor_test(void)
{
    uint32_t idx, retv, size, start, end, *data;
    int32_t count, first[CFG_MAX_FLASH_BANKS], last[CFG_MAX_FLASH_BANKS];
    flash_info_t *info;

    /* Prepare buffer */
    for (idx = 0; idx < WEIM_BUFFER_SZ; idx++) {
        weim_test_buffer[idx] = idx + 0x5A5A0000;
    }

    /* HW init */
    weim_hw_prepare();

    /* Reset flash to read mode */
    flash_reset(WEIM_CS_BASE_ADDR);

    /* Initialize flash */
    size = flash_init(WEIM_CS_BASE_ADDR);
    if ((size == 0) || (info->flash_id == FLASH_UNKNOWN)) {
        printf("Error: Missing or Unknown FLASH type.\n");
        return FALSE;
    } else {
        printf("Flash size: 0x%8x\n", size);
    }

    start = WEIM_CS_BASE_ADDR;
    end = start + size - 1;

    /* Obtain sector info */
    retv = flash_fill_sect_ranges(start, end, first, last, &count);
    if (retv == OK) {
        /* Unprotect */
        retv = flash_sects_protect(0, first, last);
        if (retv == OK) {
            /* Erase sectors */
            printf("Flash erase...\n");
            retv = flash_sects_erase(first, first);
            if (retv == OK) {
                if (*(uint16_t *) start != 0xFFFF) {
                    retv = ERR;
                    printf("Error: erased data not 0xFFFF.");
                } else {
                    /* Program data */
                    printf("\nFlash program...\n");
                    retv = flash_write((uint8_t *) weim_test_buffer,
                                       start, WEIM_BUFFER_SZ * sizeof(uint32_t));
                }
            }
        }

        /* Protect */
        if (retv == OK) {
            retv = flash_sects_protect(1, first, last);
        }
    }

    /* Compare data */
    if (retv == OK) {
        printf("Data compare...\n");
        for (idx = 0, data = (uint32_t *) start; idx < WEIM_BUFFER_SZ; idx++) {
            if (weim_test_buffer[idx] != data[idx]) {
                printf("[%d] Data mismatch: 0x%8x, 0x%8x\n", idx, weim_test_buffer[idx], data[idx]);
                retv = ERR;
                break;
            }
        }
    }

    return retv;
}

int weim_test(void)
{
    uint8_t sel, retv;

    printf("WEIM test start: \n");

    do {
        printf("  s - to start WEIM NOR flash test.\n");
        printf("  x - to exit.\n");

        do {
            sel = getchar();
        } while (sel == NONE_CHAR);

        if (sel == 'x') {
            printf("Test exit.\n");
            break;
        }

        if (sel == 's') {
            retv = weim_nor_test();
            if (retv == OK) {
                printf("Test passed.\n");
            } else {
                printf("Test failed.\n");
            }
        }
    } while (1);

    return 0;
}
