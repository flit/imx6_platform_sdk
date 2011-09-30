/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include <string.h>

#include "hardware.h"
#include "usdhc_test.h"
#include "../inc/usdhc_ifc.h"

static int usdhc_test_pio(void);
static int usdhc_test_adma(void);
static int usdhc_test_adma_intr(void);
static int mmc_test(unsigned int, unsigned int);

static usdhc_test_t usdhc_tests[] = {
    {"usdhc polling IO", usdhc_test_pio},
    {"usdhc ADMA polling", usdhc_test_adma},
    {"usdhc ADMA interrupt", usdhc_test_adma_intr},
};

/* Buffer Definition */
static int mmc_test_src[MMC_TEST_BUF_SIZE + MMC_CARD_SECTOR_BUFFER];
static int mmc_test_dst[MMC_TEST_BUF_SIZE + MMC_CARD_SECTOR_BUFFER];
static int mmc_test_tmp[MMC_TEST_BUF_SIZE + MMC_CARD_SECTOR_BUFFER];

/********************************************* Global Function ******************************************/

int usdhc_test(void)
{
    int retv, idx;
    char sel;

    printf("\n---- Running uSDHC test, type 'x' to exit.\n");

    do {
#if ((defined MX61_ARD) || (defined MX61_SMD) || (defined MX61_QSB) || (defined MX61_EVB))
        printf("Make sure to insert an MMC/SD card into SD slot #3\n");
#endif

        printf("Please select test:\n");
        for (idx = 0; idx < (sizeof(usdhc_tests) / sizeof(usdhc_test_t)); idx++) {
            printf("\t%d - %s\n", idx, usdhc_tests[idx].name);
        }
        printf("\tx - to exit.\n");

        do {
            sel = getchar();
        } while (sel == (char)0xFF);

        if (sel == 'x') {
            printf("\nTest exit.\n");
            break;
        }

        idx = sel - '0';

        if ((idx >= 0) && (idx < (sizeof(usdhc_tests) / sizeof(usdhc_test_t)))) {
            printf("\n");
            retv = usdhc_tests[idx].test();
            if (retv == TRUE) {
                printf("\n%s test PASSED.\n\n", usdhc_tests[idx].name);
            } else {
                printf("\n%s test FAILED.\n\n", usdhc_tests[idx].name);
            }
        }
    } while (TRUE);

    return retv;
}

/********************************************* Static Function ******************************************/

static int usdhc_test_pio(void)
{
    int retv = TRUE;

#if ((defined MX61_ARD) || (defined MX61_SMD) || (defined MX61_QSB) || (defined MX61_EVB))
    /* MMC - 8 bit, SD - 4 bit  */
    retv = mmc_test(8, USDHC3_BASE_ADDR);
#endif

    return retv;
}

static int usdhc_test_adma(void)
{
    int retv = TRUE;

    SDHC_ADMA_mode = TRUE;

#if ((defined MX61_ARD) || (defined MX61_SMD) || (defined MX61_QSB) || (defined MX61_EVB))
    /* MMC - 8 bit, SD - 4 bit  */
    retv = mmc_test(8, USDHC3_BASE_ADDR);
#endif

    SDHC_ADMA_mode = FALSE;

    return retv;
}

static int usdhc_test_adma_intr(void)
{
    int retv;

    SDHC_INTR_mode = SDHC_ADMA_mode = TRUE;

#if ((defined MX61_ARD) || (defined MX61_SMD) || (defined MX61_QSB) || (defined MX61_EVB))
    /* MMC - 8 bit, SD - 4 bit  */
    retv = mmc_test(8, USDHC3_BASE_ADDR);
#endif

    SDHC_INTR_mode = SDHC_ADMA_mode = FALSE;

    return retv;
}

static int mmc_test(unsigned int bus_width, unsigned int base_address)
{
    int status, idx;

    printf("1. Init card.\n");

    /* Initialize card */
    status = card_init(base_address, bus_width);

    if (status == FAIL) {
        printf("SD/MMC initialize failed.\n");
        return FALSE;
    }

    printf("2. Card -> TMP.\n");

    /* Initialize buffer */
    memset(mmc_test_src, 0x5A, MMC_TEST_BUF_SIZE);
    memset(mmc_test_dst, 0xA5, MMC_TEST_BUF_SIZE);

    /* Store card data to temporary buffer */
    status =
        card_data_read(base_address, mmc_test_tmp, MMC_TEST_BUF_SIZE * sizeof(int),
                       MMC_TEST_OFFSET);
    if (status == FAIL) {
        printf("%d: SD/MMC data read failed.\n", __LINE__);
        return FALSE;
    }

    printf("3. SRC -> Card.\n");

    /* Copy from source to Card */
    status =
        card_data_write(base_address, mmc_test_src, MMC_TEST_BUF_SIZE * sizeof(int),
                        MMC_TEST_OFFSET);
    if (status == FAIL) {
        printf("%d: SD/MMC data write failed.\n", __LINE__);
        return FALSE;
    }

    printf("4. Card -> DST.\n");

    /* Copy from card to destination */
    status =
        card_data_read(base_address, mmc_test_dst, MMC_TEST_BUF_SIZE * sizeof(int),
                       MMC_TEST_OFFSET);
    if (status == FAIL) {
        printf("%d: SD/MMC data read failed.\n", __LINE__);
        return FALSE;
    }

    printf("5. TMP -> Card.\n");

    /* Restore from temporary buffer to card */
    status =
        card_data_write(base_address, mmc_test_tmp, MMC_TEST_BUF_SIZE * sizeof(int),
                        MMC_TEST_OFFSET);
    if (status == FAIL) {
        printf("%d: SD/MMC data write failed.\n", __LINE__);
        return FALSE;
    }

    printf("6. Compare SRC & DST.\n");

    /* Compare loopback data */
    for (idx = 0; idx < MMC_TEST_BUF_SIZE; idx++) {
        if (mmc_test_src[idx] != mmc_test_dst[idx]) {
            printf("Word %d mismatch: source - 0x%x, destination - 0x%x\n", idx + 1,
                   mmc_test_src[idx], mmc_test_dst[idx]);
            return FALSE;
        }
    }

    return TRUE;
}
