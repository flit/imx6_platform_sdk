/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * Module Name:  usdhc.h
 */
#ifndef __USDHC_H__
#define __USDHC_H__

//#define USDHC_DEBUG

#ifdef USDHC_DEBUG
#define usdhc_printf(args...) printf(args)
#else
#define usdhc_printf(args...)
#endif

/*------------------------------------------- Macros --------------------------------------------*/

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define SUCCESS 0
#define FAIL 1

#define ZERO 0
#define ONE 1
#define FOUR 4
#define EIGHT 8

#define NO_ARG 0
#define RCA_SHIFT 16
#define CURR_CARD_STATE(r) ((int) ((r) & 0x1E00) >> 9)

#define BYTE_MODE 0
#define SECT_MODE 1

#define BLK_LEN 512

#define CARD_BUSY_BIT 0x80000000

/* MMC Defines */
#define MMC_SWITCH_SETBW_ARG(bus_width) (unsigned int)(0x03b70001 | ((bus_width >> 2) << 8))
#define MMC_HV_HC_OCR_VALUE 0x40FF8000
#define MMC_OCR_HC_RESP_VAL 0x40000000
#define MMC_OCR_HC_BIT_MASK 0x60000000

#define MMC_VOLT_VALID_COUNT 3000
#define MMC_VOLT_VALID_DELAY 300

/* SD Defines */
#define SD_VOLT_VALID_COUNT 3000
#define SD_VOLT_VALID_DELAY 300

#define SD_R1_STATUS_APP_CMD_MSK 0x20

#define SD_OCR_VALUE_HV_LC 0x00ff8000
#define SD_OCR_VALUE_HV_HC 0x40ff8000
#define SD_OCR_VALUE_LV_HC 0x40000080
#define SD_OCR_HC_RES      0x40000000
#define SD_IF_HV_COND_ARG  0x000001AA
#define SD_IF_LV_COND_ARG  0x000002AA

#define SD_OCR_VALUE_COUNT  3
#define SD_IF_CMD_ARG_COUNT 2

/*------------------------------------------- Enumerations --------------------------------------------*/
enum card_type_e {
    CARD_SD = 0,
    CARD_MMC = 1,
    CARD_ESD = 2,
    CARD_EMMC = 3
};

enum commands {
    CMD0 = 0,
    CMD1 = 1,
    CMD2 = 2,
    CMD3 = 3,
    CMD5 = 5,
    CMD6 = 6,
    ACMD6 = 6,
    CMD7 = 7,
    CMD8 = 8,
    CMD9 = 9,
    CMD12 = 12,
    CMD13 = 13,
    CMD16 = 16,
    CMD17 = 17,
    CMD18 = 18,
    CMD24 = 24,
    CMD25 = 25,
    CMD26 = 26,
    CMD32 = 32,
    CMD33 = 33,
    CMD35 = 35,
    CMD36 = 36,
    CMD37 = 37,
    CMD38 = 38,
    CMD39 = 39,
    ACMD41 = 41,
    CMD43 = 43,
    ACMD51 = 51,
    CMD55 = 55,
    CMD60 = 60,
    CMD61 = 61,
    CMD62 = 62,
};

enum states {
    IDLE,
    READY,
    IDENT,
    STBY,
    TRAN,
    DATA,
    RCV,
    PRG,
    DIS
};

enum usdhc_port_e {
    USDHC_PORT1 = 0,
    USDHC_PORT2 = 1,
    USDHC_PORT3 = 2,
    USDHC_PORT4 = 3,
    USDHC_NUMBER_PORTS = 4
};

typedef enum {
    WRITE = 0,
    READ = 1,
    SD_COMMAND = 2
} xfer_type_t;

typedef enum {
    RESPONSE_NONE,
    RESPONSE_136,
    RESPONSE_48,
    RESPONSE_48_CHECK_BUSY
} response_format_t;

typedef enum {
    DATA_PRESENT_NONE = 0,
    DATA_PRESENT = 1
} data_present_select;

typedef enum {
    DISABLE = 0,
    ENABLE = 1
} crc_check_enable, cmdindex_check_enable, block_count_enable, ddren_enable;

typedef enum {
    SINGLE = 0,
    MULTIPLE = 1
} multi_single_block_select;

enum intr_status {
    INTR_BUSY = 0,
    INTR_TC = 1,
    INTR_ERROR = 2
};

typedef struct {
    unsigned int command;
    unsigned int arg;
    xfer_type_t data_transfer;
    response_format_t response_format;
    data_present_select data_present;
    crc_check_enable crc_check;
    cmdindex_check_enable cmdindex_check;
    block_count_enable block_count_enable_check;
    multi_single_block_select multi_single_block;
    unsigned int dma_enable;
    unsigned int acmd12_enable;
    ddren_enable ddren;
} command_t;

typedef struct {
    response_format_t format;
    unsigned int cmd_rsp0;
    unsigned int cmd_rsp1;
    unsigned int cmd_rsp2;
    unsigned int cmd_rsp3;
} command_response_t;

typedef struct {
    unsigned int reg_base;      //register base address
    unsigned int adma_ptr;      //ADMA buffer address
    void (*isr) (void);         //interrupt service routine

    unsigned short rca;         //relative card address
    unsigned char addr_mode;    //addressing mode
    unsigned char intr_id;      //interrupt ID
    unsigned char status;       //interrupt status
} usdhc_inst_t;

/* uSDHC device table */
extern usdhc_inst_t usdhc_device[];

/*------------------------------------------- Function Defines --------------------------------------------*/

//extern int  card_get_csd(void);
extern void card_cmd_config(command_t *, int, int, xfer_type_t, response_format_t,
                            data_present_select, crc_check_enable, cmdindex_check_enable);
extern int card_get_cid(int);
extern int card_enter_trans(int);
extern int card_trans_status(int);
extern int card_get_port(int);

extern int mmc_init(int, int);
extern int mmc_voltage_validation(int);

extern int sd_init(int, int);
extern int sd_voltage_validation(int);

#endif
