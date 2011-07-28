/*
 * Copyright (C) 2008-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file io.h
 * @brief       Basic defines
 *
 * @ingroup init
 */
#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imx_spi.h"

#ifndef NULL
#define NULL				0
#endif

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef signed long long int64_t;
typedef signed int int32_t;
typedef signed short int16_t;
typedef signed char int8_t;

typedef int bool;
#define true                1
#define false               0

#define NONE_CHAR           0xFF

#define REG8_VAL(a)          ((unsigned char)(a))
#define REG16_VAL(a)         ((unsigned short)(a))
#define REG32_VAL(a)         ((unsigned int)(a))

#define REG8_PTR(a)          ((volatile unsigned char *)(a))
#define REG16_PTR(a)         ((volatile unsigned short *)(a))
#define REG32_PTR(a)         ((volatile unsigned int *)(a))

#define REG8(a)             (*(volatile unsigned char *)(a))
#define REG16(a)            (*(volatile unsigned short *)(a))
#define REG32(a)            (*(volatile unsigned int *)(a))
#define SET_REG8(v, a)      (*(volatile unsigned char *)(a) = (v))
#define SET_REG16(v, a)     (*(volatile unsigned short *)(a) = (v))
#define SET_REG32(v, a)     (*(volatile unsigned int *)(a) = (v))
#define readb(a)            REG8(a)
#define readw(a)            REG16(a)
#define readl(a)            REG32(a)
#define writeb(v, a)        SET_REG8(v, a)
#define writew(v, a)        SET_REG16(v, a)
#define writel(v, a)        SET_REG32(v, a)

/*
 * This macro is used to get certain bit field from a number
 */
#define MXC_GET_FIELD(val, len, sh)          ((val >> sh) & ((1 << len) - 1))

//TODO:
#define MOD_REG8()
#define MOD_REG16()
#define MOD_REG32()

/*
 * This macro is used to get certain bit field from a number
 */
#define GET_FIELD(val, len, sh)          ((val >> sh) & ((1 << len) - 1))

/*
 * This macro is used to set certain bit field inside a number
 */
#define SET_FIELD(val, len, sh, nval)    ((val & ~(((1 << len) - 1) << sh)) | (nval << sh))

struct hw_module {
    char *name;
    uint32_t base;
    uint32_t freq;
};

#ifdef SDK_DEBUG
#define printf1    printf
#else
#define printf1(fmt,args...)
#endif

/*!
 * maximum number of tests currently supported
 */
#define MAX_TEST_NR             200
/*!
 * maximum test name length in byte
 */
#define MAX_TEST_NAME_LEN       30
/*!
 * maximum number of retries for a certain test
 */
#define MAX_TEST_RETRY          10

struct test_module {
    char name[MAX_TEST_NAME_LEN];
    int32_t result;
};

void record_test_result(char *name, int result);

typedef int (*sdk_test_t) (void);
typedef unsigned int (*pmic_mc13892_reg_t) (unsigned int reg, unsigned int val, unsigned int write);

void fuse_blow_row(int bank, int row, unsigned int value);
unsigned int sense_fuse(int bank, int row);
void hal_delay_us(uint32_t usecs);
uint32_t get_freq(uint32_t module_base);
char receive_char(void);
int is_input_char(uint8_t c);
void _sys_exit(int return_code);
void platform_init(void);
int gpio_dir_config(int port, int pin, int dir);
int gpio_read_data(int port, int pin);
int gpio_write_data(int port, int pin, unsigned int attr);

#define RUN_TEST_COMMON(name, func)                         \
    static int sdk_##func (void)                           \
    {                                                       \
        sdk_test_t test_func = (sdk_test_t) func;         \
        record_test_result(name, test_func());              \
        return 0;                                           \
    }

#define RUN_TEST(name, func)            \
    RUN_TEST_COMMON(name, func)         \
    static sdk_test_t __sdk_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch"))) = sdk_##func;

#define RUN_TEST_EARLY(name, func)      \
    RUN_TEST_COMMON(name, func)         \
    static sdk_test_t __sdk_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_early"))) = sdk_##func;

#define RUN_TEST_LATE(name, func)       \
    RUN_TEST_COMMON(name, func)         \
    static sdk_test_t __sdk_test_##func __attribute__ ((used)) __attribute__ ((section(".test_launch_late"))) = sdk_##func;

#define RUN_TEST_INTERACTIVE(name, func)        RUN_TEST_LATE(name, func)

#define PROMPT_RUN_TEST(name)           \
    do {                                \
        printf("\n---- Running < %s > test\n", name);       \
        if (!auto_run_enable) {                             \
            if (!is_input_char('y'))                        \
                return TEST_BYPASSED;                       \
        }                                                   \
    } while (0)

#define TEST_PASSED     0
#define TEST_FAILED     -1
#define TEST_BYPASSED   2
#define TEST_NOTPRESENT 3

extern int auto_run_enable;     // global flag to indicate auto-run feature enabled or not
extern uint32_t spi_nor_flash_type; // Flag decides the SPI-NOR device
/* SPI-NOR defines */
#define AT45DB321D          1
#define M25P32               2

#endif // __IO_H__
