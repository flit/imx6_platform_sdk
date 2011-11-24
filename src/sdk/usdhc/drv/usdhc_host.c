/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * usdhc_host.c
 *
 * uSDHC driver for controller
 *
 */
#include "usdhc.h"
#include "hardware.h"
#include "usdhc_host.h"

extern int SDHC_ADMA_mode;
extern int SDHC_INTR_mode;

/*---------------------------------------------- Static Fcuntion ------------------------------------------------*/

static void usdhc_set_data_transfer_width(int base_address, int data_width)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    esdhc_base->protocol_control &= ~ESDHC_BUS_WIDTH_MASK;
    esdhc_base->protocol_control |= data_width & ESDHC_BUS_WIDTH_MASK;
}

static void usdhc_set_endianness(int base_address, int endian_mode)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    esdhc_base->protocol_control &= ~ESDHC_ENDIAN_MODE_MASK;
    esdhc_base->protocol_control |= endian_mode;
}

static int usdhc_wait_cmd_data_lines(int base_address, int data_present)
{
    int count = ZERO;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Wait for release of CMD line */
    while (esdhc_base->present_state & ESDHC_PRESENT_STATE_CIHB) {
        if (count == ESDHC_CIHB_CHK_COUNT) {
            return FAIL;
        }

        count++;
        hal_delay_us(ESDHC_STATUS_CHK_TIMEOUT);
    }

    /* If data present with command, wait for release of DATA lines */
    if (data_present == DATA_PRESENT) {
        count = ZERO;

        while (esdhc_base->present_state & ESDHC_PRESENT_STATE_CDIHB) {
            if (count == ESDHC_CDIHB_CHK_COUNT) {
                return FAIL;
            }

            count++;
            hal_delay_us(ESDHC_STATUS_CHK_TIMEOUT);
        }
    }

    return SUCCESS;
}

static void usdhc_cmd_cfg(int base_address, command_t * cmd)
{
    unsigned int consist_status;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Write Command Argument in Command Argument Register */
    esdhc_base->command_argument = cmd->arg;

    /* Clear the DMAS field */
    esdhc_base->protocol_control &= ~ESDHC_PRTCTL_DMAS_MASK;

    /* If ADMA mode enabled and command with DMA, enable ADMA2 */
    if ((cmd->dma_enable == ENABLE) && (SDHC_ADMA_mode == ENABLE)) {
        esdhc_base->protocol_control |= ESDHC_PRTCTL_ADMA2_VAL;
    }

    /* Keep bit fields other than command setting intact */
    consist_status = esdhc_base->mixer_control & ESDHC_MIXER_CTRL_CMD_MASK;

    esdhc_base->mixer_control = (consist_status |
                                 ((cmd->dma_enable) << ESDHC_DMAEN_SHIFT) |
                                 ((cmd->
                                   block_count_enable_check) << ESDHC_BLOCK_COUNT_ENABLE_SHIFT) |
                                 ((cmd->acmd12_enable) << ESDHC_AC12EN_SHIFT) | ((cmd->
                                                                                  ddren) <<
                                                                                 ESDHC_DDREN_SHIFT)
                                 | ((cmd->data_transfer) << ESDHC_DATA_TRANSFER_SHIFT) |
                                 ((cmd->
                                   multi_single_block) << ESDHC_MULTI_SINGLE_BLOCK_SELECT_SHIFT));

    esdhc_base->command_transfer_type = (((cmd->response_format) << ESDHC_RESPONSE_FORMAT_SHIFT) |
                                         ((cmd->crc_check) << ESDHC_CRC_CHECK_SHIFT) |
                                         ((cmd->cmdindex_check) << ESDHC_CMD_INDEX_CHECK_SHIFT) |
                                         ((cmd->data_present) << ESDHC_DATA_PRESENT_SHIFT) |
                                         ((cmd->command) << ESDHC_CMD_INDEX_SHIFT));
}

static void usdhc_wait_end_cmd_resp_dma_intr(int base_address)
{
    int count = ZERO;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    while (!(esdhc_base->interrupt_status & ESDHC_STATUS_END_CMD_RESP_TC_TIME_MSK)) {
        if (count == ESDHC_DMA_TIMEOUT_COUNT) {
            usdhc_printf("Data transfer timeout.\n");
            break;
        }

        count++;
        hal_delay_us(ESDHC_STATUS_CHK_TIMEOUT);
    }
}

static void usdhc_wait_end_cmd_resp_intr(int base_address)
{
    int count = ZERO;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    while (!(esdhc_base->interrupt_status & ESDHC_STATUS_END_CMD_RESP_TIME_MSK)) {
        if (count == ESDHC_OPER_TIMEOUT_COUNT) {
            usdhc_printf("Command timeout.\n");
            break;
        }

        count++;
        hal_delay_us(ESDHC_STATUS_CHK_TIMEOUT);
    }
}

static int usdhc_check_response(int base_address)
{
    int status = FAIL;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    if (((esdhc_base->interrupt_status & ESDHC_STATUS_END_CMD_RESP_MSK) ||
         (esdhc_base->mmc_boot_register & ESDHC_MMC_BOOT_REG_BOOT_EN)) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_TIME_OUT_RESP_MSK) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_RESP_CRC_ERR_MSK) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_RESP_CMD_INDEX_ERR_MSK) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_RESP_CMD_END_BIT_ERR_MSK)) {
        status = SUCCESS;
    } else {
        usdhc_printf("Error status: 0x%x\n", esdhc_base->interrupt_status);

        /* Clear CIHB and CDIHB status */
        if ((esdhc_base->present_state & ESDHC_PRESENT_STATE_CIHB) ||
            (esdhc_base->present_state & ESDHC_PRESENT_STATE_CDIHB)) {
            esdhc_base->system_control |= ESDHC_SOFTWARE_RESET;
        }
    }

    return status;
}

static int usdhc_check_transfer(int base_address)
{
    int status = FAIL;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    if ((esdhc_base->interrupt_status & ESDHC_STATUS_TRANSFER_COMPLETE_MSK) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_TIME_OUT_READ_MSK) &&
        !(esdhc_base->interrupt_status & ESDHC_STATUS_READ_CRC_ERR_MSK)) {
        status = SUCCESS;
    } else {
        usdhc_printf("Error transfer status: 0x%x\n", esdhc_base->interrupt_status);
    }

    return status;
}

static void usdhc_handle_isr(int idx)
{
    host_register_ptr esdhc_base = (host_register_ptr) usdhc_device[idx].reg_base;

    /* Set interrupt flag */
    if (esdhc_base->interrupt_status & ESDHC_STATUS_END_DATA_RSP_TC_MASK) {
        usdhc_device[idx].status = INTR_TC;
    } else {
        usdhc_device[idx].status = INTR_ERROR;

        /* Clear CIHB or CDIHB */
        if ((esdhc_base->present_state & ESDHC_PRESENT_STATE_CIHB) ||
            (esdhc_base->present_state & ESDHC_PRESENT_STATE_CDIHB)) {
            esdhc_base->system_control |= ESDHC_SOFTWARE_RESET;
        }
    }

    /* Clear interrupt */
    esdhc_base->interrupt_status = ESDHC_CLEAR_INTERRUPT;

    /* Clear interrupt enable */
    esdhc_base->interrupt_signal_enable = 0;
}

/*---------------------------------------------- Global Function ------------------------------------------------*/

void usdhc1_isr(void)
{
    usdhc_handle_isr(USDHC_PORT1);
}

void usdhc2_isr(void)
{
    usdhc_handle_isr(USDHC_PORT2);
}

void usdhc3_isr(void)
{
    usdhc_handle_isr(USDHC_PORT3);
}

void usdhc4_isr(void)
{
    usdhc_handle_isr(USDHC_PORT4);
}

void host_init(int base_address)
{
    /* Enable Clock Gating */

    /* IOMUX Configuration */
    usdhc_iomux_config((unsigned int)base_address);
}

void host_init_active(int base_address)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Send 80 clock ticks for card to power up */
    esdhc_base->system_control |= ESDHC_SYSCTL_INITA;

    /* Wait until INITA field cleared */
    while (esdhc_base->system_control & ESDHC_SYSCTL_INITA) {
        ;
    }
}

int host_send_cmd(int base_address, command_t * cmd)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Clear Interrupt status register */
    esdhc_base->interrupt_status = ESDHC_CLEAR_INTERRUPT;

    /* Enable Interrupt */
    esdhc_base->interrupt_status_enable |= ESDHC_INTERRUPT_ENABLE;

    /* Wait for CMD/DATA lines to be free */
    if (usdhc_wait_cmd_data_lines(base_address, cmd->data_present) == FAIL) {
        printf("Data/Command lines busy.\n");
        return FAIL;
    }

    /* Clear interrupt status */
    esdhc_base->interrupt_status |= ESDHC_STATUS_END_CMD_RESP_TIME_MSK;

    /* Enable interrupt when sending DMA commands */
    if ((SDHC_INTR_mode == ENABLE) && (cmd->dma_enable == TRUE)) {
        int idx = card_get_port(base_address);

        /* Set interrupt flag to busy */
        usdhc_device[idx].status = INTR_BUSY;

        /* Enable uSDHC interrupt */
        esdhc_base->interrupt_signal_enable = ESDHC_STATUS_END_DATA_RSP_TC_MASK;
    }

    /* Configure Command */
    usdhc_cmd_cfg(base_address, cmd);

    /* If DMA Enabled */
    if (cmd->dma_enable == TRUE) {
        /* Return in interrupt mode */
        if (SDHC_INTR_mode == ENABLE) {
            return SUCCESS;
        }

        usdhc_wait_end_cmd_resp_dma_intr(base_address);
    }

    /* Other command */
    else {
        usdhc_wait_end_cmd_resp_intr(base_address);
    }

    /* Mask all interrupts */
    esdhc_base->interrupt_signal_enable = ZERO;

    /* Check if an error occured */
    return usdhc_check_response(base_address);
}

void host_cfg_clock(int base_address, int frequency)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Clear SDCLKEN bit */
    esdhc_base->system_control &= ~ESDHC_SYSCTL_SDCLKEN_MASK;

    /* Wait until clock stable */
    while (!(esdhc_base->present_state & ESDHC_PRSSTAT_SDSTB_BIT)) {
        ;
    }

    /* Clear DTOCV, SDCLKFS, DVFS bits */
    esdhc_base->system_control &= ~ESDHC_SYSCTL_FREQ_MASK;

    /* Clear PEREN, HCKEN, IPGEN bits */
    esdhc_base->system_control &= ~ESDHC_SYSCTL_INPUT_CLOCK_MASK;

    /* Wait until clock stable */
    while (!(esdhc_base->present_state & ESDHC_PRSSTAT_SDSTB_BIT)) {
        ;
    }

    /* Set frequency dividers */
    if (frequency == IDENTIFICATION_FREQ) {
        esdhc_base->system_control |= ESDHC_IDENT_FREQ;
    } else if (frequency == OPERATING_FREQ) {
        esdhc_base->system_control |= ESDHC_OPERT_FREQ;
    } else {
        esdhc_base->system_control |= ESDHC_HS_FREQ;
    }

    /* Wait until clock stable */
    while (!(esdhc_base->present_state & ESDHC_PRSSTAT_SDSTB_BIT)) {
        ;
    }

    /* Set SDCLKEN bit */
    esdhc_base->system_control |= ESDHC_SYSCTL_SDCLKEN_MASK;

    /* Clear DTOESEN bit */
    esdhc_base->system_control &= ~ESDHC_IRQSTATEN_DTOESEN;

    /* Set DTOCV bit */
    esdhc_base->system_control |= ESDHC_SYSCTL_DTOCV_VAL;

    /* Set DTOESEN bit */
    esdhc_base->system_control |= ESDHC_IRQSTATEN_DTOESEN;
}

void host_set_bus_width(int base_address, int bus_width)
{
    int width = bus_width >> ONE;

    usdhc_set_data_transfer_width(base_address, width);
}

void host_reset(int base_address, int bus_width, int endian_mode)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Reset the eSDHC by writing 1 to RSTA bit of SYSCTRL Register */
    esdhc_base->system_control |= ESDHC_SOFTWARE_RESET;

    /* Wait until RSTA field cleared */
    while (esdhc_base->system_control & ESDHC_SOFTWARE_RESET) {
        ;
    }

    /* Set default bus width to eSDHC */
    host_set_bus_width(base_address, bus_width);

    /* Set Endianness of eSDHC */
    usdhc_set_endianness(base_address, endian_mode);
}

void host_read_response(int base_address, command_response_t * response)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Read response from registers */
    response->cmd_rsp0 = esdhc_base->command_response0;
    response->cmd_rsp1 = esdhc_base->command_response1;
    response->cmd_rsp2 = esdhc_base->command_response2;
    response->cmd_rsp3 = esdhc_base->command_response3;
}

void host_cfg_block(int base_address, int blk_len, int nob, int wml)
{
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Number of blocks and block length */
    esdhc_base->block_attributes = ((nob << ESDHC_BLKATTR_NOB_SHIFT) |
                                    (blk_len & ESDHC_BLKATTR_BLKLEN_MASK));
    /* Watermark level - for DMA transfer */
    esdhc_base->watermark_level = wml;
}

void host_clear_fifo(int base_address)
{
    unsigned int val, idx;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* If data present in Rx FIFO */
    if (esdhc_base->interrupt_status & ESDHC_INTSTAT_BRR) {
        /* Read from FIFO until empty */
        for (idx = 0; idx < ESDHC_FIFO_LENGTH; idx++) {
            val = esdhc_base->data_buffer_access;
        }
    }

    /* Maybe not necessary */
    esdhc_base->interrupt_status = ESDHC_INTSTAT_BRR;
}

void host_setup_adma(int base_address, int *ptr, int length)
{
    unsigned int dst_ptr = (unsigned int)ptr;
    unsigned int port, bd_id = 0;
    adma_bd_t *bd_addr;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Get uSDHC port according to base address */
    port = card_get_port(base_address);

    /* Get BD pointer */
    bd_addr = (adma_bd_t *) usdhc_device[port].adma_ptr;

    /* Setup BD chain */
    while (length > 0) {
        bd_addr[bd_id].address = dst_ptr;
        if (length > ESDHC_ADMA_BD_MAX_LEN) {
            bd_addr[bd_id].length = ESDHC_ADMA_BD_MAX_LEN;
            bd_addr[bd_id].attribute = ESDHC_ADMA_BD_ACT | ESDHC_ADMA_BD_VALID;
            length -= ESDHC_ADMA_BD_MAX_LEN;
            dst_ptr += ESDHC_ADMA_BD_MAX_LEN;
        } else {
            bd_addr[bd_id].length = length;
            bd_addr[bd_id].attribute = ESDHC_ADMA_BD_ACT | ESDHC_ADMA_BD_VALID | ESDHC_ADMA_BD_END;
            length = 0;
        }

        bd_id++;
    }

    /* Setup BD pointer */
    esdhc_base->adma_system_address = (unsigned int)bd_addr;

    /* Clear interrupt status */
    esdhc_base->interrupt_status = ESDHC_CLEAR_INTERRUPT;
}

int host_data_read(int base_address, int *dst_ptr, int length, int wml)
{
    int idx, itr, loop;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Enable Interrupt */
    esdhc_base->interrupt_status_enable |= ESDHC_INTERRUPT_ENABLE;

    /* Read data to dst_ptr */
    loop = length / (4 * wml);
    for (idx = 0; idx < loop; idx++) {
        /* Wait until buffer ready */
        while (!(esdhc_base->present_state & ESDHC_PRSTAT_BREN)) {
            ;
        }

        /* Read from FIFO watermark words */
        for (itr = 0; itr < wml; itr++) {
            *dst_ptr = esdhc_base->data_buffer_access;
            dst_ptr++;
        }
    }

    /* Read left data that not WML aligned */
    loop = (length % (4 * wml)) / 4;
    if (loop != 0) {
        /* Wait until buffer ready */
        while (!(esdhc_base->present_state & ESDHC_PRSTAT_BREN)) {
            ;
        }

        /* Read the left to destination buffer */
        for (itr = 0; itr < loop; itr++) {
            *dst_ptr = esdhc_base->data_buffer_access;
            dst_ptr++;
        }

        /* Clear FIFO */
        for (; itr < wml; itr++) {
            idx = esdhc_base->data_buffer_access;
        }
    }

    /* Wait until transfer complete */
    while (!(esdhc_base->interrupt_status & ESDHC_STATUS_END_DATA_RSP_TC_MASK)) ;

    /* Check if error happened */
    return usdhc_check_transfer(base_address);
}

int host_data_write(int base_address, int *src_ptr, int length, int wml)
{
    int idx, itr, loop;
    host_register_ptr esdhc_base = (host_register_ptr) base_address;

    /* Enable Interrupt */
    esdhc_base->interrupt_status_enable |= ESDHC_INTERRUPT_ENABLE;

    /* Write data from src_ptr */
    loop = length / (4 * wml);
    for (idx = 0; idx < loop; idx++) {
        /* Wait until write available */
        while (!(esdhc_base->present_state & ESDHC_PRSTAT_BWEN)) {
            ;
        }

        /* Write to FIFO watermark words */
        for (itr = 0; itr < wml; itr++) {
            esdhc_base->data_buffer_access = *src_ptr;
            src_ptr++;
        }
    }

    /* Write left data that not watermark aligned */
    loop = (length % (4 * wml)) / 4;
    if (loop != 0) {
        /* Wait until buffer ready */
        while (!(esdhc_base->present_state & ESDHC_PRSTAT_BWEN)) {
            ;
        }

        /* Write the left from source buffer */
        for (itr = 0; itr < loop; itr++) {
            esdhc_base->data_buffer_access = *src_ptr;
            src_ptr++;
        }

        /* Fill FIFO */
        for (; itr < wml; itr++) {
            esdhc_base->data_buffer_access = idx;
        }
    }

    /* Wait for transfer complete */
    while (!(esdhc_base->interrupt_status & ESDHC_STATUS_END_DATA_RSP_TC_MASK)) ;

    /* Check if error happened */
    return usdhc_check_transfer(base_address);
}
