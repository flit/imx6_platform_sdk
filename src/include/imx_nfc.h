/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_NFC_H__
#define __IMX_NFC_H__

//#include "hardware.h"

#define FLASH_Read_ID                   (0x90)

#define NAND_MAIN_BUF0                  (NFC_BASE + 0x000)
#define NAND_MAIN_BUF1                  (NFC_BASE + 0x200)
#define NAND_MAIN_BUF2                  (NFC_BASE + 0x400)
#define NAND_MAIN_BUF3                  (NFC_BASE + 0x600)
#define NAND_MAIN_BUF4                  (NFC_BASE + 0x800)
#define NAND_MAIN_BUF5                  (NFC_BASE + 0xA00)
#define NAND_MAIN_BUF6                  (NFC_BASE + 0xC00)
#define NAND_MAIN_BUF7                  (NFC_BASE + 0xE00)
#define NAND_SPAR_BUF0                  (NFC_BASE + 0x1000)
#define NAND_SPAR_BUF1                  (NFC_BASE + 0x1040)
#define NAND_SPAR_BUF2                  (NFC_BASE + 0x1080)
#define NAND_SPAR_BUF3                  (NFC_BASE + 0x10C0)
#define NAND_SPAR_BUF4                  (NFC_BASE + 0x1100)
#define NAND_SPAR_BUF5                  (NFC_BASE + 0x1140)
#define NAND_SPAR_BUF6                  (NFC_BASE + 0x1180)
#define NAND_SPAR_BUF7                  (NFC_BASE + 0x11C0)
#define NAND_REG_BASE                    (NFC_BASE + 0x1E00)

#define NFC_WR_PROT_REG                (NFC_IP_BASE + 0x00)
#define UNLOCK_BLK_ADD0_REG         (NFC_IP_BASE + 0x04)
#define UNLOCK_BLK_ADD1_REG         (NFC_IP_BASE + 0x08)
#define UNLOCK_BLK_ADD2_REG         (NFC_IP_BASE + 0x0C)
#define UNLOCK_BLK_ADD3_REG         (NFC_IP_BASE + 0x10)
#define UNLOCK_BLK_ADD4_REG         (NFC_IP_BASE + 0x14)
#define UNLOCK_BLK_ADD5_REG         (NFC_IP_BASE + 0x18)
#define UNLOCK_BLK_ADD6_REG         (NFC_IP_BASE + 0x1C)
#define UNLOCK_BLK_ADD7_REG         (NFC_IP_BASE + 0x20)

#define NFC_FLASH_CONFIG2_REG     (NFC_IP_BASE + 0x24)
#define NFC_FLASH_CONFIG2_ECC_EN     (1 << 3)

#define NFC_FLASH_CONFIG3_REG     (NFC_IP_BASE + 0x28)

#define NFC_IPC_REG                          (NFC_IP_BASE + 0x2C)
#define NFC_IPC_INT                           (1 << 31)
#define NFC_IPC_AUTO_DONE             (1 << 30)
#define NFC_IPC_LPS                           (1 << 29)
#define NFC_IPC_RB_B                         (1 << 28)
#define NFC_IPC_CACK                         (1 << 1)
#define NFC_IPC_CREQ                         (1 << 0)
#define NFC_AXI_ERR_ADD_REG          (NFC_IP_BASE + 0x30)

#define NAND_CMD_REG                       (NAND_REG_BASE + 0x00)
#define NAND_ADD0_REG                     (NAND_REG_BASE + 0x04)

#define NAND_CONFIGURATION1_REG      (NAND_REG_BASE + 0x34)

#define NAND_CONFIGURATION1_NFC_RST   (1 << 2)
#define NAND_CONFIGURATION1_NF_CE       (1 << 1)
#define NAND_CONFIGURATION1_SP_EN       (1 << 0)

#define NAND_ECC_STATUS_RESULT_REG     (NAND_REG_BASE + 0x38)

#define NAND_STATUS_SUM_REG             (NAND_REG_BASE + 0x3C)

#define NAND_LAUNCH_REG                     (NAND_REG_BASE + 0x40)
#define NAND_LAUNCH_FCMD                        (1 << 0)
#define NAND_LAUNCH_FADD                        (1 << 1)
#define NAND_LAUNCH_FDI                           (1 << 2)
#define NAND_LAUNCH_AUTO_PROG              (1 << 6)
#define NAND_LAUNCH_AUTO_READ              (1 << 7)
#define NAND_LAUNCH_AUTO_READ_CONT   (1 << 8)
#define NAND_LAUNCH_AUTO_ERASE            (1 << 9)
#define NAND_LAUNCH_COPY_BACK0            (1 << 10)
#define NAND_LAUNCH_COPY_BACK1            (1 << 11)
#define NAND_LAUNCH_AUTO_STAT              (1 << 12)

enum nfc_output_mode {
    FDO_PAGE_SPARE = 0x0008,
    FDO_SPARE_ONLY = 0x1008,    // LSB has to be 0x08
    FDO_FLASH_ID = 0x0010,
    FDO_FLASH_STATUS = 0x0020,
};

enum nfc_internal_buf {
    RAM_BUF_0 = 0x0 << 4,
    RAM_BUF_1 = 0x1 << 4,
    RAM_BUF_2 = 0x2 << 4,
    RAM_BUF_3 = 0x3 << 4,
    RAM_BUF_4 = 0x4 << 4,
    RAM_BUF_5 = 0x5 << 4,
    RAM_BUF_6 = 0x6 << 4,
    RAM_BUF_7 = 0x7 << 4,
};

#endif
