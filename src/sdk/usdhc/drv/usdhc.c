/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * usdhc.c
 *
 * uSDHC driver for SD/MMC card on MX6x above platform
 *
 */

#include "usdhc.h"
#include "hardware.h"
#include "interrupt.h"
#include "usdhc_host.h"

/* Global Variables */

usdhc_inst_t usdhc_device[USDHC_NUMBER_PORTS] = {
    {
     USDHC1_BASE_ADDR,          //register base
     USDHC_ADMA_BUFFER1,        //ADMA base
     usdhc1_isr,                //ISR
     0,                         //RCA
     0,                         //addressing mode
     IMX_INT_USDHC1,            //interrupt ID
     0,                         //status
     }
    ,

    {
     USDHC2_BASE_ADDR,          //register base
     USDHC_ADMA_BUFFER2,        //ADMA base
     usdhc2_isr,                //ISR
     0,                         //RCA
     0,                         //addressing mode
     IMX_INT_USDHC2,            //interrupt ID
     0,                         //status
     }
    ,

    {
     USDHC3_BASE_ADDR,          //register base
     USDHC_ADMA_BUFFER3,        //ADMA base
     usdhc3_isr,                //ISR
     0,                         //RCA
     0,                         //addressing mode
     IMX_INT_USDHC3,            //interrupt ID
     0,                         //status
     }
    ,

    {
     USDHC4_BASE_ADDR,          //register base
     USDHC_ADMA_BUFFER4,        //ADMA base
     usdhc4_isr,                //ISR
     0,                         //RCA
     0,                         //addressing mode
     IMX_INT_USDHC4,            //interrupt ID
     0,                         //status
     }
    ,
};

/* Whether to enable ADMA */
int SDHC_ADMA_mode = DISABLE;

/* Whether to enable Interrupt */
int SDHC_INTR_mode = DISABLE;

/********************************************* Static Function ******************************************/
static int card_software_reset(int base_address)
{
    command_t cmd;
    int response = FAIL;

    /* Configure CMD0 */
    card_cmd_config(&cmd, CMD0, NO_ARG, READ, RESPONSE_NONE, DATA_PRESENT_NONE, DISABLE, DISABLE);

    usdhc_printf("Send CMD0.\n");

    /* Issue CMD0 to Card */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        response = SUCCESS;
    }

    return response;
}

static int card_init_interrupt(int base_address)
{
    int idx = card_get_port(base_address);

    if (idx == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return FAIL;
    }

    /* Disable interrupt */
    disable_interrupt(usdhc_device[idx].intr_id, CPU_0);

    if (SDHC_INTR_mode == ENABLE) {
        /* Register interrupt */
        register_interrupt_routine(usdhc_device[idx].intr_id, usdhc_device[idx].isr);

        /* Enable interrupt */
        enable_interrupt(usdhc_device[idx].intr_id, CPU_0, 0);
    }

    return SUCCESS;
}

/********************************************* Global Function ******************************************/
int card_init(int base_address, int bus_width)
{
    int init_status = FAIL;

    /* Initialize uSDHC Controller */
    host_init(base_address);

    /* Software Reset to Interface Controller */
    host_reset(base_address, ESDHC_ONE_BIT_SUPPORT, ESDHC_LITTLE_ENDIAN_MODE);

    /* Initialize interrupt */
    if (card_init_interrupt(base_address) == FAIL) {
        printf("Interrupt initialize failed.\n");
        return FAIL;
    }

    /* Enable Identification Frequency */
    host_cfg_clock(base_address, IDENTIFICATION_FREQ);

    /* Send Init 80 Clock */
    host_init_active(base_address);

    usdhc_printf("Reset card.\n");

    /* Issue Software Reset to card */
    if (card_software_reset(base_address) == FAIL) {
        return FAIL;
    }

    /* SD Voltage Validation */
    if (sd_voltage_validation(base_address) == SUCCESS) {
        usdhc_printf("SD voltage validation passed.\n");

        /* SD Initialization */
        init_status = sd_init(base_address, bus_width);
    }

    /* MMC Voltage Validation */
    else if (mmc_voltage_validation(base_address) == SUCCESS) {
        usdhc_printf("MMC voltage validation passed.\n");

        /* MMC Initialization */
        init_status = mmc_init(base_address, bus_width);
    }

    return init_status;
}

#if 0
int card_get_csd(int base_address)
{

    command_t cmd;
    command_response_t response;
    int status = FAIL;
    int card_address = (card_rca << RCA_SHIFT);

    /* Configure CMD9 for MMC/SD card */
    mxcmci_cmd_config(&cmd, CMD9, card_address, READ, RESPONSE_136,
                      DATA_PRESENT_NONE, ENABLE, DISABLE);

    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        response.format = RESPONSE_136;
        host_read_response(base_address, &response);

        csd.csd0 = response.cmd_rsp0;
        csd.csd1 = response.cmd_rsp1;
        csd.csd2 = response.cmd_rsp2;
        csd.csd3 = response.cmd_rsp3;

        status = SUCCESS;
    }

    return status;
}
#endif

void card_cmd_config(command_t * cmd, int index, int argument, xfer_type_t transfer,
                     response_format_t format, data_present_select data,
                     crc_check_enable crc, cmdindex_check_enable cmdindex)
{
    cmd->command = index;
    cmd->arg = argument;
    cmd->data_transfer = transfer;
    cmd->response_format = format;
    cmd->data_present = data;
    cmd->crc_check = crc;
    cmd->cmdindex_check = cmdindex;
    cmd->dma_enable = FALSE;
    cmd->block_count_enable_check = DISABLE;
    cmd->multi_single_block = SINGLE;
    cmd->acmd12_enable = DISABLE;
    cmd->ddren = DISABLE;

    /* Multi Block R/W Setting */
    if ((CMD18 == index) || (CMD25 == index)) {
        if (SDHC_ADMA_mode == ENABLE) {
            cmd->dma_enable = TRUE;
        }

        cmd->block_count_enable_check = ENABLE;
        cmd->multi_single_block = MULTIPLE;
        cmd->acmd12_enable = ENABLE;
    }
}

int card_get_cid(int base_address)
{
    command_t cmd;
    int status = FAIL;
    command_response_t response;

    /* Configure CMD2 */
    card_cmd_config(&cmd, CMD2, NO_ARG, READ, RESPONSE_136, DATA_PRESENT_NONE, ENABLE, DISABLE);

    usdhc_printf("Send CMD2.\n");

    /* Send CMD2 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        response.format = RESPONSE_136;
        host_read_response(base_address, &response);

        /* No Need to Save CID */

        status = SUCCESS;
    }

    return status;
}

int card_enter_trans(int base_address)
{
    command_t cmd;
    int card_address, port, status = FAIL;

    /* Get port from base address */
    port = card_get_port(base_address);

    /* Get RCA */
    card_address = usdhc_device[port].rca << RCA_SHIFT;

    /* Configure CMD7 */
    card_cmd_config(&cmd, CMD7, card_address, READ, RESPONSE_48_CHECK_BUSY,
                    DATA_PRESENT_NONE, ENABLE, ENABLE);

    usdhc_printf("Send CMD7.\n");

    /* Send CMD7 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        /* Check if the card in TRAN state */
        if (card_trans_status(base_address) == SUCCESS) {
            status = SUCCESS;
        }
    }

    return status;
}

int card_trans_status(int base_address)
{
    command_t cmd;
    command_response_t response;
    int card_state, card_address, port, status = FAIL;

    /* Get Port */
    port = card_get_port(base_address);

    /* Get RCA */
    card_address = usdhc_device[port].rca << RCA_SHIFT;

    /* Configure CMD13 */
    card_cmd_config(&cmd, CMD13, card_address, READ, RESPONSE_48,
                    DATA_PRESENT_NONE, ENABLE, ENABLE);

    usdhc_printf("Send CMD13.\n");

    /* Send CMD13 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        /* Get Response */
        response.format = RESPONSE_48;
        host_read_response(base_address, &response);

        /* Read card state from response */
        card_state = CURR_CARD_STATE(response.cmd_rsp0);
        if (card_state == TRAN) {
            status = SUCCESS;
        }
    }

    return status;
}

int card_get_port(int base_address)
{
    int idx;

    for (idx = 0; idx < USDHC_NUMBER_PORTS; idx++) {
        if (usdhc_device[idx].reg_base == base_address) {
            break;
        }
    }

    return idx;
}

int card_set_blklen(int base_address, int len)
{
    command_t cmd;
    int status = FAIL;

    /* Configure CMD16 */
    card_cmd_config(&cmd, CMD16, len, READ, RESPONSE_48, DATA_PRESENT_NONE, ENABLE, ENABLE);

    usdhc_printf("Send CMD16.\n");

    /* Send CMD16 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        status = SUCCESS;
    }

    return status;
}

int card_data_read(int base_address, int *dst_ptr, int length, int offset)
{
    int port, sector;
    command_t cmd;

    /* Get uSDHC port according to base address */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return FAIL;
    }

    usdhc_printf("card_data_read: Read 0x%x bytes from SD%d offset 0x%x to 0x%x.\n",
                 length, port + 1, offset, (int)dst_ptr);

    /* Get sector number */
    if (SDHC_ADMA_mode == ENABLE) {
        /* For DMA mode, length should be sector aligned */
        if ((length % BLK_LEN) != 0) {
            length = length + BLK_LEN - (length % BLK_LEN);
        }

        sector = length / BLK_LEN;
    } else {
        /* For PIO mode, not neccesary */
        sector = length / BLK_LEN;

        if ((length % BLK_LEN) != 0) {
            sector++;
        }
    }

    /* Offset should be sectors */
    if (usdhc_device[port].addr_mode == SECT_MODE) {
        offset = offset / BLK_LEN;
    }

    /* Set block length to card */
    if (card_set_blklen(base_address, BLK_LEN) == FAIL) {
        printf("Fail to set block length to card.\n");
        return FAIL;
    }

    /* Clear Rx FIFO */
    host_clear_fifo(base_address);

    /* Configure block length/number and watermark */
    host_cfg_block(base_address, BLK_LEN, sector, ESDHC_BLKATTR_WML_BLOCK);

    /* If DMA mode enabled, configure BD chain */
    if (SDHC_ADMA_mode == ENABLE) {
        host_setup_adma(base_address, dst_ptr, length);
    }

    /* Use CMD18 for multi-block read */
    card_cmd_config(&cmd, CMD18, offset, READ, RESPONSE_48, DATA_PRESENT, ENABLE, ENABLE);

    usdhc_printf("card_data_read: Send CMD18.\n");

    /* Send CMD18 */
    if (host_send_cmd(base_address, &cmd) == FAIL) {
        printf("Fail to send CMD18.\n");
        return FAIL;
    } else {
        /* In polling IO mode, manually read data from Rx FIFO */
        if (SDHC_ADMA_mode == DISABLE) {
            usdhc_printf("Non-DMA mode, read data from FIFO.\n");

            if (host_data_read(base_address, dst_ptr, length, ESDHC_BLKATTR_WML_BLOCK) == FAIL) {
                printf("Fail to read data from card.\n");
                return FAIL;
            }
        }
    }

    usdhc_printf("card_data_read: Data read successful.\n");

    return SUCCESS;
}

int card_data_write(int base_address, int *src_ptr, int length, int offset)
{
    int port, sector;
    command_t cmd;

    /* Get uSDHC port according to base address */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return FAIL;
    }

    usdhc_printf("card_data_write: write 0x%x bytes to SD%d offset 0x%x from 0x%x.\n",
                 length, port + 1, offset, (int)src_ptr);

    /* Get sector number */
    if (SDHC_ADMA_mode == ENABLE) {
        /* For DMA mode, length should be sector aligned */
        if ((length % BLK_LEN) != 0) {
            length = length + BLK_LEN - (length % BLK_LEN);
        }

        sector = length / BLK_LEN;
    } else {
        /* For PIO mode, not neccesary */
        sector = length / BLK_LEN;

        if ((length % BLK_LEN) != 0) {
            sector++;
        }
    }

    /* Offset should be sectors */
    if (usdhc_device[port].addr_mode == SECT_MODE) {
        offset = offset / BLK_LEN;
    }

    /* Set block length to card */
    if (card_set_blklen(base_address, BLK_LEN) == FAIL) {
        printf("Fail to set block length to card.\n");
        return FAIL;
    }

    /* Configure block length/number and watermark */
    host_cfg_block(base_address, BLK_LEN, sector, ESDHC_BLKATTR_WML_BLOCK << ESDHC_WML_WRITE_SHIFT);

    /* If DMA mode enabled, configure BD chain */
    if (SDHC_ADMA_mode == ENABLE) {
        host_setup_adma(base_address, src_ptr, length);
    }

    /* Use CMD25 for multi-block write */
    card_cmd_config(&cmd, CMD25, offset, WRITE, RESPONSE_48, DATA_PRESENT, ENABLE, ENABLE);

    usdhc_printf("card_data_write: Send CMD25.\n");

    /* Send CMD25 */
    if (host_send_cmd(base_address, &cmd) == FAIL) {
        printf("Fail to send CMD25.\n");
        return FAIL;
    } else {
        if (SDHC_ADMA_mode == DISABLE) {
            usdhc_printf("Non-DMA mode, write to FIFO.\n");

            if (host_data_write(base_address, src_ptr, length, ESDHC_BLKATTR_WML_BLOCK) == FAIL) {
                printf("Fail to write data to card.\n");
                return FAIL;
            }
        }

        usdhc_printf("card_data_write: Data written successful.\n");
    }

    return SUCCESS;
}

int card_xfer_result(int base_address, int *result)
{
    int idx = card_get_port(base_address);

    if (idx == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return FAIL;
    }

    *result = usdhc_device[idx].status;

    return SUCCESS;
}
