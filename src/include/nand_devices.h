/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __NAND_DEVICES_H
#define __NAND_DEVICES_H

/*Generic NAND Commands Code*/
#define NAND_CMD_READ_SETUP         0x00
#define NAND_CMD_READ_NEXT          0x30
#define NAND_CMD_PROGRAM_SETUP      0x80
#define NAND_CMD_PROGRAM_CONFIRM    0x10
#define NAND_CMD_ERASE_SETUP        0x60
#define NAND_CMD_ERASE_CONFIRM      0xD0
#define NAND_CMD_READ_STATUS        0x70
#define NAND_CMD_READ_ID             0x90
#define NAND_CMD_RESET               0xFF

enum nfc_page_area {
    NFC_SPARE_ONLY,
    NFC_MAIN_ONLY,
};

enum {
    MXC_NAND_8_BIT = 8,
    MXC_NAND_16_BIT = 16,
};

enum {
    NAND_SLC = 0,
    NAND_MLC = 1,
};

/* Search good / bad pattern on the first page only */
#define NAND_BBT_SCAN1STPAGE    0x00000001
/* Search good / bad pattern on the first and the second page */
#define NAND_BBT_SCAN2NDPAGE    0x00000002
/* Search good / bad pattern on the last page only */
#define NAND_BBT_SCANLSTPAGE    0x00000004
// todo: move to top
#define ECC_FORCE_ON    1
#define ECC_FORCE_OFF   2

enum blk_bad_type {
    BLK_BAD_FACTORY = 0,
    BLK_BAD_RUNTIME = 1,
};

typedef struct flash_dev_info {
    unsigned short device_id;
    unsigned short device_id2;
    unsigned short device_id3;
    unsigned short device_id4;
    unsigned int col_cycle;     // number of column address cycles
    unsigned int row_cycle;     // number of row address cycles
    unsigned short page_size;
    unsigned short spare_size;
    unsigned int pages_per_block;
    unsigned int block_size;
    unsigned int block_count;
    unsigned int device_size;
    unsigned int port_size;     // x8 or x16 IO
    unsigned int type;          // SLC vs MLC
    unsigned int options;
    unsigned int fis_start_addr;
    unsigned int bi_off;
    unsigned int bbt_blk_max_nr;
    char vendor_info[96];

} flash_dev_info_t;

#endif //__NAND_DEVICES_H
