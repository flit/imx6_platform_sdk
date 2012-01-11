/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file keypad_port.c
 * @brief Keypad port driver source file.
 *
 * @ingroup diag_keypad
 */

#include "hardware.h"

static uint8_t g_col_inuse;
static uint8_t g_row_inuse;
static uint8_t g_init_done = 0;
static uint8_t g_wait_for_irq;
static uint16_t g_status_reg;

/*!
 * Keypad port function to return the read key.
 */
uint8_t kpp_get_key(uint16_t *rd_keys, uint8_t kpp_col, uint8_t kpp_row)
{
    uint16_t port_state[8];
    uint8_t tested_col;
    uint16_t col_mask;

    /* Initialize global variables to store the board's keypad usage */
    g_col_inuse = kpp_col;
    g_row_inuse = kpp_row;

    /* Initialize the keypad port */
    kpp_init();

    /* enter WFI now - TO DO */
    /* might be a problem when in debug mode with JTAG !!!! */

    g_wait_for_irq = 1;
    enable_irq(KDIE);
    while(g_wait_for_irq);

    /* check what to do with status register !!! */
    /*     TOOOO DOOOO */

    /* start the scanning routine */
    /* set a high level on each columns */
    writew(0xFF00, KPP_KPDR);

    /* For quick discharging of keypad capacitance */
    /* configure the column in totem pole and keep the active row */
    writew(COL_IN_TTPOLE | g_row_inuse, KPP_KPCR);
    /* re-configure the column to open-drain and keep the active row */
    writew(COL_IN_ODRAIN | g_row_inuse, KPP_KPCR);

    /* Clear consecutively each active column and
     * sample the row state for each.
     */
    for(tested_col=0 ; tested_col < 8 ; tested_col++)
    {
        col_mask = g_col_inuse & (1 << tested_col);
        if(col_mask)
        {
            writew((~col_mask << 8),KPP_KPDR);
            hal_delay_us(100);
            port_state[tested_col] = readw(KPP_KPDR);
        }
        else
            port_state[tested_col] = 0xFFFF;
    }

    memcpy(rd_keys, port_state, sizeof(port_state));

    /* set a low level on each columns */
    writew(0, KPP_KPDR);

    /* clear status flags and synchronizer chain */
    writew(0x7, KPP_KPSR);
    /* set KRSS to detect a release key event */
    /* TO DO */

    /* enable the interrupts */
    enable_irq(KDIE);

    return 0;
}

/*!
 * Keypad port interrupt routine.
 */
void kpp_interrupt_routine(void)
{
    disable_irq(KDIE);

    g_status_reg = readw(KPP_KPSR);

    g_wait_for_irq = 0;
}

/*!
 * Setup keypad interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   state - ENABLE or DISABLE the interrupt.
 */
void kpp_setup_interrupt(uint8_t state)
{
    if (state == ENABLE) {    
        /* clear status flags and synchronizer chain */
        writew(0x7, KPP_KPSR);
        /* register the IRQ sub-routine */
        register_interrupt_routine(IMX_INT_KPP, &kpp_interrupt_routine);
        /* enable the IRQ */
        enable_interrupt(IMX_INT_KPP, CPU_0, 0);
    }
    else {
        /* disable the IRQ */
        disable_interrupt(IMX_INT_KPP, CPU_0);
        /* clear status flags and synchronizer chain */
        writew(0x7, KPP_KPSR);
    }
}

/*!
 * Initialize the keypad controller.
 *
 */
void kpp_init(void)
{
	/* there's no clock to enable for the keypad port */

    /* configure the IOMUX if not already done */
    if(!g_init_done)
        kpp_iomux_config();

    /* configure the columns in open-drain and Set the active row */
    writew(COL_IN_ODRAIN | g_row_inuse, KPP_KPCR);
    /* configure columns as output, and row as input */
    writew(0xFF00, KPP_KDDR);
    /* set a low level on each columns */
    writew(0, KPP_KPDR);
    /* clear status flags and synchronizer chain */
    writew(0x7, KPP_KPSR);

    /* enable IRQ if not already done */
    if(!g_init_done)
    {
        kpp_setup_interrupt(ENABLE);
        g_init_done = 0;
    }
}
