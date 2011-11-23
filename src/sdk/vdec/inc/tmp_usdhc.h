/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef USDHC_H_
#define USDHC_H_

#include "io.h"

typedef struct {
    uint32_t ds_addr;           /* 0x00 */
    uint32_t blk_att;           /* 0x04 */
    uint32_t cmd_arg;           /* 0x08 */
    uint32_t cmd_xfr_type;      /* 0x0c */
    uint32_t cmd_rsp0;          /* 0x10 */
    uint32_t cmd_rsp1;          /* 0x14 */
    uint32_t cmd_rsp2;          /* 0x18 */
    uint32_t cmd_rsp3;          /* 0x1c */
    uint32_t data_buff_acc_port;    /* 0x20 */
    uint32_t press_state;       /* 0x24 */
    uint32_t prot_ctrl;         /* 0x28 */
    uint32_t sys_ctrl;          /* 0x2c */
    uint32_t int_status;        /* 0x30 */
    uint32_t int_status_en;     /* 0x34 */
    uint32_t int_signal_en;     /* 0x38 */
    uint32_t autocmd12_err_status;  /* 0x3c */
    uint32_t host_ctrl_cap;     /* 0x40 */
    uint32_t wtmk_lvl;          /* 0x44 */
    uint32_t mix_ctrl;          /* 0x48 */
    uint32_t rsvd1;             /* 0x4c */
    uint32_t force_event;       /* 0x50 */
    uint32_t adma_err_status;   /* 0x54 */
    uint32_t adma_sys_addr;     /* 0x58 */
    uint32_t rsvd2;             /* 0x5c */
    uint32_t dll_ctrl;          /* 0x60 */
    uint32_t dll_status;        /* 0x64 */
    uint32_t clk_tune_ctrl_status;  /* 0x68 */
    uint32_t rsvd3[21];         /* 0x6c - 0xbc */
    uint32_t vend_spec;         /* 0xc0 */
    uint32_t mmc_boot;          /* 0xc4 */
    uint32_t rsvd4[13];         /* 0xc8 - 0xf8 */
    uint32_t host_ctrl_ver;     /* 0xfc */
} uSDHCRegs_t;

typedef uSDHCRegs_t *uSDHCRegs;

typedef enum {
    SD_CARD,
    MMC
} CardType;

typedef enum {
    BUS_1BIT = 0,
    BUS_4BIT,
    BUS_8BIT
} BusWidth;

/* Responses */
#define NO_RESP             (0x00000000)    /* CRC disabled, CMD index disabled */
#define R1_RESP             (0x001a0000)    /* CRC enabled, CMD index enabled */
#define R1b_RESP            (0x001b0000)    /* CRC enabled, CMD index enabled */
#define R2_RESP             (0x00110000)    /* CRC enabled, CMD index disabled */
#define R3_RESP             (0x00020000)    /* CRC disabled, CMD index disabled */
#define R4_RESP             (0x001a0000)    /* CRC enabled, CMD index enabled */
#define R5_RESP             (0x001a0000)    /* CRC enabled, CMD index enabled */
#define R5b_RESP            (0x001b0000)    /* CRC enabled, CMD index enabled */
#define R6_RESP             (0x001a0000)    /* CRC enabled, CMD index enabled */
#define R7_RESP             (0x001a0000)    /* CRC enabled, CMD index enabled */

/* Command Types */
#define NORMAL_CMD          (0)
#define SUSPEND_CMD         (1)
#define RESUME_CMD          (2)
#define ABORT_CMD           (3)

/* Data Present bits */
#define DATA_PRESENT        (0x00200000)
#define NO_DATA             (0x0)
#define DATA_WRITE          (0x0)
#define DATA_READ           (0x10)
#define MULTIPLE_BLOCKS     (0x22)
#define AUTO_CMD12          (0x4)

/* uSDHC Error Status Bits */
#define ERROR_BITS          (0x157f0000)

#define MAX_BLOCK_CNT       (32768)
#define BLK_SIZE            (0x200)
#define BLK_SIZE_SHIFT      (9)

typedef enum {
    CMD0 = 0,
    CMD1,
    CMD2,
    CMD3,
    CMD4,
    CMD5,
    CMD6,
    CMD7,
    CMD8,
    CMD9,
    CMD10,
    CMD11,
    CMD12,
    CMD13,
    CMD14,
    CMD15,
    CMD16,
    CMD17,
    CMD18,
    CMD19,
    CMD20,
    CMD21,
    CMD22,
    CMD23,
    CMD24,
    CMD25,
    CMD26,
    CMD27,
    CMD28,
    CMD29,
    CMD30,
    CMD31,
    CMD32,
    CMD33,
    CMD34,
    CMD35,
    CMD36,
    CMD37,
    CMD38,
    CMD39,
    CMD40,
    CMD41,
    CMD42,
    CMD43,
    CMD44,
    CMD45,
    CMD46,
    CMD47,
    CMD48,
    CMD49,
    CMD50,
    CMD51,
    CMD52,
    CMD53,
    CMD54,
    CMD55,
    CMD56,
    CMD57,
    CMD58,
    CMD59,
    CMD60,
    CMD61,
    CMD62,
    CMD63,
    ACMD0,
    ACMD1,
    ACMD2,
    ACMD3,
    ACMD4,
    ACMD5,
    ACMD6,
    ACMD7,
    ACMD8,
    ACMD9,
    ACMD10,
    ACMD11,
    ACMD12,
    ACMD13,
    ACMD14,
    ACMD15,
    ACMD16,
    ACMD17,
    ACMD18,
    ACMD19,
    ACMD20,
    ACMD21,
    ACMD22,
    ACMD23,
    ACMD24,
    ACMD25,
    ACMD26,
    ACMD27,
    ACMD28,
    ACMD29,
    ACMD30,
    ACMD31,
    ACMD32,
    ACMD33,
    ACMD34,
    ACMD35,
    ACMD36,
    ACMD37,
    ACMD38,
    ACMD39,
    ACMD40,
    ACMD41,
    ACMD42,
    ACMD43,
    ACMD44,
    ACMD45,
    ACMD46,
    ACMD47,
    ACMD48,
    ACMD49,
    ACMD50,
    ACMD51,
    ACMD52,
    ACMD53,
    ACMD54,
    ACMD55,
    ACMD56,
    ACMD57,
    ACMD58,
    ACMD59,
    ACMD60,
    ACMD61,
    ACMD62,
    ACMD63
} CommandId;

typedef struct {
    uSDHCRegs uSDHC;
    CardType type;
    BusWidth busWidth;
    uint32_t rca;
    uint32_t highCapacity;
    int polling;
} uSDHC_Card;

void uSDHC_SendCmd(uSDHCRegs uSDHC, CommandId cmdidx, uint32_t arg);
void uSDHC_InitSD(uSDHC_Card * card);
void uSDHC_Read(uSDHC_Card * card, uint32_t sd_addr, uint32_t size, uint32_t * data);
void uSDHC_Write(uSDHC_Card * card, uint32_t sd_addr, uint32_t size, uint32_t * data);
void uSDHC_EnableInt(uSDHC_Card * card);
void uSDHC_ClearInterrupts(uSDHC_Card * card);

#endif
