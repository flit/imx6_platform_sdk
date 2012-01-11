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

#define reg8_read(addr)       *((volatile uint8_t *)(addr))
#define reg16_read(addr)      *((volatile uint16_t *)(addr))
#define reg32_read(addr)      *((volatile uint32_t *)(addr))

#define reg8_write(addr,val)  *((volatile uint8_t *)(addr)) = (val)
#define reg16_write(addr,val) *((volatile uint16_t *)(addr)) = (val)
#define reg32_write(addr,val) *((volatile uint32_t *)(addr)) = (val)

#define mem8_read(addr)       *((volatile uint8_t *)(addr))
#define mem16_read(addr)      *((volatile uint16_t *)(addr))
#define mem32_read(addr)      *((volatile uint32_t *)(addr))

#define mem8_write(addr,val)  *((volatile uint8_t *)(addr)) = (val)
#define mem16_write(addr,val) *((volatile uint16_t *)(addr)) = (val)
#define mem32_write(addr,val) *((volatile uint32_t *)(addr)) = (val)

#define readb(a)        reg8_read(a)
#define readw(a)        reg16_read(a)
#define readl(a)        reg32_read(a)

/* prefered method to access registers */
#define writeb(v, a)    reg8_write(a, v)
#define writew(v, a)    reg16_write(a, v)
#define writel(v, a)    reg32_write(a, v)

#define  reg8setbit(addr,bitpos) \
         reg8_write((addr),(reg8_read((addr)) | (1<<(bitpos))))

#define  reg16setbit(addr,bitpos) \
         reg16_write((addr),(reg16_read((addr)) | (1<<(bitpos))))

#define  reg32setbit(addr,bitpos) \
         reg32_write((addr),(reg32_read((addr)) | (1<<(bitpos))))

#define  reg8clrbit(addr,bitpos) \
         reg8_write((addr),(reg8_read((addr)) & (0xFF ^ (1<<(bitpos)))))

#define  reg16clrbit(addr,bitpos) \
         reg16_write((addr),(reg16_read((addr)) & (0xFFFF ^ (1<<(bitpos)))))

#define  reg32clrbit(addr,bitpos) \
         reg32_write((addr),(reg32_read((addr)) & (0xFFFFFFFF ^ (1<<(bitpos)))))

#define reg8_write_mask(addr, data, mask) \
        reg8_write((addr),((reg8_read(addr) & (~mask)) | (mask & data)))

#define reg16_write_mask(addr, data, mask) \
        reg16_write((addr),((reg16_read(addr) & (~mask)) | (mask & data)))

#define reg32_write_mask(addr, data, mask) \
        reg32_write((addr),((reg32_read(addr) & (~mask)) | (mask & data)))

#define gen_msk32(start, end)	((0xFFFFFFFF << (start)) ^ (0xFFFFFFFF << ((end + 1))))
#define reg32_set_field(addr, start, end, val) \
		reg32_write_mask(addr, (val) << (start), gen_msk32((start, end)))

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
