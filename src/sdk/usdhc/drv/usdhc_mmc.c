/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 *
 * usdhc_mmc.c
 *
 * MMC card specific driver
 *
 */

#include "usdhc.h"
#include "hardware.h"
#include "usdhc_host.h"

extern int card_rca[];
extern int card_address_mode[];

/********************************************* Static Function ******************************************/
static int mmc_set_rca(int base_address)
{
    command_t cmd;
    int port, card_state, status = FAIL;
    command_response_t response;

    /* Check uSDHC Port */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return status;
    }

    /* Set RCA to ONE */
    card_rca[port] = ONE;

    /* Configure CMD3 */
    card_cmd_config(&cmd, CMD3, (card_rca[port] << RCA_SHIFT), READ, RESPONSE_48, DATA_PRESENT_NONE,
                    ENABLE, ENABLE);

    usdhc_printf("Send CMD3.\n");

    /* Send CMD3 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        response.format = RESPONSE_48;
        host_read_response(base_address, &response);

        /* Check the IDENT card state */
        card_state = CURR_CARD_STATE(response.cmd_rsp0);

        if (card_state == IDENT) {
            status = SUCCESS;
        }
    }

    return status;
}

static int mmc_set_bus_width(int base_address, int bus_width)
{
    command_t cmd;
    int status = FAIL;

    /* Check Bus Width */
    if ((bus_width != ONE) && (bus_width != FOUR) && (bus_width != EIGHT)) {
        printf("Invalid bus_width: %d\n", bus_width);
        return status;
    }

    /* Configure MMC Switch Command */
    card_cmd_config(&cmd, CMD6, MMC_SWITCH_SETBW_ARG(bus_width), READ,
                    RESPONSE_48, DATA_PRESENT_NONE, ENABLE, ENABLE);

    usdhc_printf("Send CMD6.\n");

    /* Send CMD6 */
    if (host_send_cmd(base_address, &cmd) == SUCCESS) {
        status = SUCCESS;
    }

    return status;
}

/********************************************* Global Function ******************************************/
int mmc_init(int base_address, int bus_width)
{
    int status = FAIL;

    usdhc_printf("Get CID.\n");

    /* Get CID */
    if (card_get_cid(base_address) == SUCCESS) {
        usdhc_printf("Set RCA.\n");

        /* Set RCA */
        if (mmc_set_rca(base_address) == SUCCESS) {
            /* Check Card Type here */
            usdhc_printf("Set operating frequency.\n");

            /* Switch to Operating Frequency */
            host_cfg_clock(base_address, OPERATING_FREQ);

            usdhc_printf("Enter transfer state.\n");

            /* Enter Transfer State */
            if (card_enter_trans(base_address) == SUCCESS) {
                usdhc_printf("Set bus width.\n");

                /* Set Card Bus Width */
                if (mmc_set_bus_width(base_address, bus_width) == SUCCESS) {
                    /* Set Host Bus Width */
                    host_set_bus_width(base_address, bus_width);

                    /* Set High Speed Here */
                    {
                        status = SUCCESS;
                    }
                }
            }
        }
    }

    return status;
}

int mmc_voltage_validation(int base_address)
{
    command_t cmd;
    command_response_t response;
    int port, count = ZERO, status = FAIL;
    unsigned int ocr_val = MMC_HV_HC_OCR_VALUE;

    /* Check uSDHC Port from Base Address */
    port = card_get_port(base_address);
    if (port == USDHC_NUMBER_PORTS) {
        printf("Base address: 0x%x not in address table.\n", base_address);
        return status;
    }

    while ((count < MMC_VOLT_VALID_COUNT) && (status == FAIL)) {
        /* Configure CMD1 */
        card_cmd_config(&cmd, CMD1, ocr_val, READ, RESPONSE_48, DATA_PRESENT_NONE, DISABLE,
                        DISABLE);

        /* Send CMD1 */
        if (host_send_cmd(base_address, &cmd) == FAIL) {
            printf("Send CMD1 failed.\n");
            break;
        } else {
            /* Check Response */
            response.format = RESPONSE_48;
            host_read_response(base_address, &response);

            /* Check Busy Bit Cleared or NOT */
            if (response.cmd_rsp0 & CARD_BUSY_BIT) {
                /* Check Address Mode */
                if ((response.cmd_rsp0 & MMC_OCR_HC_BIT_MASK) == MMC_OCR_HC_RESP_VAL) {
                    card_address_mode[port] = SECT_MODE;
                } else {
                    card_address_mode[port] = BYTE_MODE;
                }

                status = SUCCESS;
            } else {
                count++;
                hal_delay_us(MMC_VOLT_VALID_DELAY);
            }
        }
    }

    return status;
}
