/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * Module Name: usdhc_host.h
 */

#ifndef __USDHC_HOST_H__
#define __USDHC_HOST_H__

/*---------------------------------------- Macro -------------------------------------------*/

#define ESDHC_SYSCTL_INITA            ((unsigned int)0x08000000)
#define ESDHC_SOFTWARE_RESET          ((unsigned int)0x01000000)

#define ESDHC_BUS_WIDTH_MASK          ((unsigned int)0x00000006)
#define ESDHC_ENDIAN_MODE_MASK        ((unsigned int)0x00000030)

#define ESDHC_LITTLE_ENDIAN_MODE      ((unsigned int)0x00000020)
#define ESDHC_HW_BIG_ENDIAN_MODE      ((unsigned int)0x00000010)

#define ESDHC_SYSCTL_SDCLKEN_MASK     ((unsigned int)0x00000008)
#define ESDHC_PRSSTAT_SDSTB_BIT       ((unsigned int)0x00000008)
#define ESDHC_SYSCTL_FREQ_MASK        ((unsigned int)0x000FFFF0)
#define ESDHC_SYSCTL_INPUT_CLOCK_MASK ((unsigned int)0x00000007)
#define ESDHC_IRQSTATEN_DTOESEN       ((unsigned int)0x00100000)
#define ESDHC_SYSCTL_DTOCV_VAL        ((unsigned int)0x000E0000)

#define ESDHC_CLEAR_INTERRUPT         ((unsigned int)0x117F01FF)
#define ESDHC_INTERRUPT_ENABLE        ((unsigned int)0x007F013F)
#define ESDHC_PRESENT_STATE_CIHB      ((unsigned int)0x00000001)
#define ESDHC_PRESENT_STATE_CDIHB     ((unsigned int)0x00000002)

#define ESDHC_ONE_BIT_SUPPORT         0x0000000
#define ESDHC_ADMA_BD_BLOCK_NUM       2000

#define ESDHC_STATUS_CHK_TIMEOUT      1000  /*  1ms */

#define ESDHC_CIHB_CHK_COUNT          10    /* 10ms */
#define ESDHC_CDIHB_CHK_COUNT         100   /* 0.1s */
#define ESDHC_OPER_TIMEOUT_COUNT      10    /* 10ms */
#define ESDHC_DMA_TIMEOUT_COUNT       10000 /* 10s  */

#define ESDHC_STATUS_END_CMD_RESP_MSK         ((unsigned int)0x00000001)
#define ESDHC_STATUS_TRANSFER_COMPLETE_MSK    ((unsigned int)0x00000002)
#define ESDHC_MMC_BOOT_REG_BOOT_EN            ((unsigned int)0x00000040)
#define ESDHC_STATUS_TIME_OUT_RESP_MSK        ((unsigned int)0x00010000)
#define ESDHC_STATUS_RESP_CRC_ERR_MSK         ((unsigned int)0x00020000)
#define ESDHC_STATUS_RESP_CMD_END_BIT_ERR_MSK ((unsigned int)0x00040000)
#define ESDHC_STATUS_RESP_CMD_INDEX_ERR_MSK   ((unsigned int)0x00080000)
#define ESDHC_STATUS_TIME_OUT_READ_MSK        ((unsigned int)0x00100000)
#define ESDHC_STATUS_READ_CRC_ERR_MSK         ((unsigned int)0x00200000)
#define ESDHC_STATUS_END_CMD_RESP_TIME_MSK    ((unsigned int)0x100F0001)
#define ESDHC_STATUS_END_CMD_RESP_TC_TIME_MSK ((unsigned int)0x100F0002)
#define ESDHC_STATUS_END_DATA_RSP_TC_MASK     ((unsigned int)0x00700002)

#define ESDHC_PRTCTL_DMAS_MASK        ((unsigned int)0x00000300)
#define ESDHC_PRTCTL_ADMA2_VAL        ((unsigned int)0x00000200)
#define ESDHC_MIXER_CTRL_CMD_MASK     ((unsigned int)0xFFFFFFC0)

#define ESDHC_ADMA_BD_ACT             ((unsigned char)0x20)
#define ESDHC_ADMA_BD_END             ((unsigned char)0x02)
#define ESDHC_ADMA_BD_VALID           ((unsigned char)0x01)
#define ESDHC_ADMA_BD_MAX_LEN         ((unsigned short)(64*1024-512))

#define ESDHC_INTSTAT_BRR             (0x00000020)
#define ESDHC_INTSTAT_BWR             (0x00000010)
#define ESDHC_PRSTAT_BREN             (0x00000800)
#define ESDHC_PRSTAT_BWEN             (0x00000400)
#define ESDHC_FIFO_LENGTH             (0x80)
#define ESDHC_BLKATTR_WML_BLOCK       (0x80)
#define ESDHC_BLKATTR_WML_SWITCH      (0x10)
#define ESDHC_WML_WRITE_SHIFT         (16)

#define ESDHC_DMAEN_SHIFT                       (0)
#define ESDHC_BLOCK_COUNT_ENABLE_SHIFT          (1)
#define ESDHC_AC12EN_SHIFT                      (2)
#define ESDHC_DDREN_SHIFT                       (3)
#define ESDHC_DATA_TRANSFER_SHIFT               (4)
#define ESDHC_MULTI_SINGLE_BLOCK_SELECT_SHIFT   (5)

#define ESDHC_RESPONSE_FORMAT_SHIFT             (16)
#define ESDHC_CRC_CHECK_SHIFT                   (19)
#define ESDHC_CMD_INDEX_CHECK_SHIFT             (20)
#define ESDHC_DATA_PRESENT_SHIFT                (21)
#define ESDHC_CMD_INDEX_SHIFT                   (24)

#define ESDHC_BLKATTR_NOB_SHIFT                 (16)
#define ESDHC_BLKATTR_BLKLEN_MASK               (0xFFFF)

/*------------------------------------- Enumeration ----------------------------------------*/
typedef enum {
    OPERATING_FREQ,
    IDENTIFICATION_FREQ,
    HS_FREQ
} sdhc_freq_t;

/*-------------------------------------- Structure -----------------------------------------*/

/* ADMA Buffer Descriptor */
typedef struct {
    unsigned char attribute;
    unsigned char reserved;
    unsigned short int length;
    unsigned int address;
} adma_bd_t;

/* uSDHC Register Map */
typedef struct {
    volatile unsigned int dma_system_address;
    volatile unsigned int block_attributes;
    volatile unsigned int command_argument;
    volatile unsigned int command_transfer_type;
    volatile unsigned int command_response0;
    volatile unsigned int command_response1;
    volatile unsigned int command_response2;
    volatile unsigned int command_response3;
    volatile unsigned int data_buffer_access;
    volatile unsigned int present_state;
    volatile unsigned int protocol_control;
    volatile unsigned int system_control;
    volatile unsigned int interrupt_status;
    volatile unsigned int interrupt_status_enable;
    volatile unsigned int interrupt_signal_enable;
    volatile unsigned int autocmd12_status;
    volatile unsigned int host_controller_capabilities;
    volatile unsigned int watermark_level;
    volatile unsigned int mixer_control;
    unsigned int reserved1[1];
    volatile unsigned int force_event;
    volatile unsigned int adma_error_status_register;
    volatile unsigned int adma_system_address;
    unsigned int reserved2[1];
    volatile unsigned int dll_control_register;
    volatile unsigned int dll_status_register;
    volatile unsigned int clk_tuning_control;
    unsigned int reserved3[21];
    volatile unsigned int vendor_specific_register;
    volatile unsigned int mmc_boot_register;
    unsigned int reserved4[13];
    volatile unsigned int host_controller_version;
} host_register, *host_register_ptr;

/*---------------------------------------- Function Define ----------------------------------------*/
extern void host_init(int);
extern void host_init_active(int);
extern int host_send_cmd(int, command_t *);
extern void host_set_bus_width(int, int);
extern void host_reset(int, int, int);
extern void host_read_response(int, command_response_t *);
extern void host_cfg_clock(int, int);
extern void host_cfg_block(int, int, int, int);
extern void host_clear_fifo(int);
extern void host_setup_adma(int, int *, int);
extern int host_data_read(int, int *, int, int);
extern int host_data_write(int, int *, int, int);

#endif
