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

#ifndef NULL
#define NULL				0
#endif

typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef long long int64_t;
typedef int int32_t;
typedef short int16_t;
typedef char int8_t;

typedef int bool;

/* defines a pointer to a function */
typedef void (*funct_t) (void);

#define TRUE        1
#define FALSE       0
#define true        1
#define false       0
#define ENABLE      1          
#define DISABLE     0

#define NONE_CHAR   0xFF

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
    int8_t *name;       /* name of the module */
    uint32_t base;      /* module base address */
    uint32_t freq;      /* input clock frequency */
    uint32_t irq_id;    /* ID of its interrupt */
    void (*irq_subroutine)(void);   /* module interrupt sub-routine address */
    void (*iomux_config) (void);   /* module I/O mux configuration function */
};

#ifdef SDK_DEBUG
#define printf1    printf
#else
#define printf1(fmt,args...)
#endif

typedef int32_t (*sdk_test_t) (void);

#define TEST_PASSED     0
#define TEST_FAILED     -1
#define TEST_BYPASSED   2
#define TEST_NOTPRESENT 3

#endif // __IO_H__
