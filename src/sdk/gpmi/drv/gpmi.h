/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file stmp_nand.h
 * @brief The header file that contains the general definitions for NAND
 *
 * @ingroup diag_nand
 */

#ifndef __GPMI_H__
#define __GPMI_H__
//extern static flash_dev_info_t *flash_dev_info;





#define GPMI_NAND0_APBHDMA_CHANNEL_RESET() (*(unsigned int *)HW_APBH_CHANNEL_CTRL |= (0x10<<16))

// generic defines
#define RETRIES                       100000
#define XFER8                         15
#define XFER16                        24

#define SUCCESS                       0
#define FAILURE                       !SUCCESS
#define NOT_BUSY                      0x10
#define BUSY_TIMEOUT                  0x11
#define INVALID_BITS                  0x12
//#define TRUE                          0x13
//#define FALSE                         0x14
#define GPMI_TIMEOUT                  0x15

#define DMA_NO_XFER                   0x00
#define DMA_WRITE                     0x01
#define DMA_READ                      0x02
#define DMA_SENSE                    0x03

#define DMA_NO_CHAIN                  0
#define DMA_CHAIN                     1
#define DMA_NO_DECR_SEMA              0
#define DMA_DECR_SEMA                 1
#define DMA_NO_IRQ_FINISH             0
#define DMA_IRQ_FINISH                1
#define DMA_NO_WAIT4END               0
#define DMA_WAIT4END                  1
#define DMA_NO_WAIT4RDY               0
#define DMA_WAIT4RDY                  1
#define DMA_HALT_ON_TERMINAL          1
#define DMA_NO_HALT_ON_TERMINAL       0

#define NAND_CS_NO_LOCK               0
#define NAND_CS_LOCK                  1

#define GPMI_CTRL0_NAND_DATA_BYTES    0x00
#define GPMI_CTRL0_NAND_CMD_BYTES     0x01
#define GPMI_CTRL0_NAND_ADDR_BYTES    0x02

#define GPMI_CTRL0_NO_ADDR_INCR       0
#define GPMI_CTRL0_ADDR_INCR          1

#define GPMI_CTRL0_NO_UDMA_MODE       0
#define GPMI_CTRL0_UDMA_MODE          1

#define GPMI_NO_DEV_IRQ               0
#define GPMI_DEV_IRQ                  1
#define GPMI_NO_TO_IRQ                0
#define GPMI_TO_IRQ                   1

#define GPMI_CTRL0_CMD_WRITE               0x00
#define GPMI_CTRL0_CMD_READ                0x01
#define GPMI_CTRL0_CMD_READ_COMPARE        0x02
#define GPMI_CTRL0_CMD_WAIT_READY          0x03

#define CHAN0                         0x0
#define CHAN1                         0x1
#define CHAN2                         0x2
#define CHAN3                         0x3
#define CHAN4                         0x4
#define CHAN5                         0x5

#define FLASH_BUSY_TIMEOUT              1000000 //100msec

typedef struct _dma_cmd {
    unsigned command:2;
    unsigned chain:1;
    unsigned irq_finish:1;
    unsigned nandlock:1;
    unsigned wait4rdy:1;
    unsigned decr_sema:1;
    unsigned wait4endcmd:1;
    unsigned haltonterminal:1;
    unsigned unused0:3;
    unsigned num_pio_wds:4;
    unsigned num_bytes:16;
} DMA_CMD;

typedef struct _dma_buff {
    struct _dma_buff
    *next_buff;
    DMA_CMD cmd;
    void *buff_ptr;
    unsigned int pio_wrds[6];
} DMA_BUFF;

typedef union _gpmi_ctrl0 {
    struct {
        unsigned xfer_cnt:16;
        unsigned addr_incr:1;
        unsigned addr:3;        // consists of addr:3, and cs:2
        unsigned cs:3;
        unsigned word_len:1;
        unsigned cmd_mode:2;
        unsigned rsv0:1;
        unsigned lock_cs:1;
        unsigned rsv1:1;
        unsigned run:1;
        unsigned clkgate:1;
        unsigned sft_reset:1;
    } gpmi_cmd;

    unsigned int gpmi_u32;

} GPMI_CMD;


#endif //__GPMI_H__
