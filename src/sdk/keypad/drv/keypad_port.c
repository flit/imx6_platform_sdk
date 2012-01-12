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
static uint8_t g_wait_for_irq;

/*!
 * Keypad port function to scan the keypad matrix and return the read key(s).
 * The scan sequence is described into the reference manual into "Key press
 * interrupt scanning sequence".
 * To debounce, this sequence is at least executed 3 times, and if the result
 * of the 3 scans is the same, it exists.
 * Likely if a key was detected active 3 times, it's because it is pressed.
 * This is an implementation of the "Keypad matrix Scanning" section presented
 * in the reference manual.
 *
 * @param   keypad_state - variable that returns the keypad read state.
 */
void kpp_scan_matrix(uint16_t *keypad_state)
{
    uint16_t port_state_1[8];
    uint16_t port_state_2[8];
    uint16_t port_state_3[8];
    uint16_t *port_state;
    uint8_t tested_col, i, loop;
    uint16_t col_mask;

    memset(port_state_1, 0x0000, sizeof(port_state_1));
    memset(port_state_2, 0x0000, sizeof(port_state_2));
    memset(port_state_3, 0x0000, sizeof(port_state_3));

    loop = 1;
    while(loop != 0)
    {
        if(loop == 1)
            port_state = port_state_1;
        else if(loop == 2)
            port_state = port_state_2;
        else if(loop == 3)
        {
            port_state = port_state_3;
            loop = 0;
        }
        loop++;

        /* Execute the scan sequence on the whole keypad.
         * it clears consecutively each active column and
         * sample the row state each time.
         */
        for(tested_col=0 ; tested_col < 8 ; tested_col++)
        {
            col_mask = g_col_inuse & (1 << tested_col);
            if(col_mask)
            {
                writew((~col_mask << 8),KPP_KPDR);
                hal_delay_us(1);
                port_state[tested_col] = ~readw(KPP_KPDR);
            }
            else
                port_state[tested_col] = 0x0;
        }

        /* For key pressed detection:
         * exit from here when 3 consecutive scans of the full
         * keypad matrix give the same result.
         * The read of the KPP_KPDR is inverted, so that the software
         * looks for a value different from 0
         *  => at least one key is pressed.
         */
        for(i=0 ; i < 8 ; i++)
        {
            if((port_state_1[i] & port_state_2[i] &
               port_state_3[i] & 0xFF) != 0x00)
                loop = 0;
        }
    }

    /* copy the result into the global keypad state variable */
    memcpy(keypad_state, port_state_1, sizeof(port_state_1));
}

/*!
 * Keypad port function to return the read key.
 *
 * @param   rd_keys - active columns in the keypad.
 * @param   condition - keypad state is read immediately (IMMEDIATE)
 *                      or it waits for key pressed interrupt (WF_INTERRUPT).
 */
void kpp_get_keypad_state(uint16_t *rd_keys, uint8_t condition)
{
    uint16_t keypad_state[8];

    /* enter WFI now - TO DO */
    /* might be a problem when in debug mode with JTAG !!!! */

    g_wait_for_irq = 1;

    /* Clear status flags and synchronizer chains */
    writew(0xF, KPP_KPSR);

    /* Either the application waits for a pressed key event
     * or it needs immediately the state of the keypad.
     */
    if(condition == WF_INTERRUPT)
    {
        enable_irq(KDIE);
        while(g_wait_for_irq);
    }

    /* Start the scanning routine */
    /* Set a high level on each columns */
    writew(0xFF00, KPP_KPDR);

    /* For quick discharging of keypad capacitance */
    /* configure the column in totem pole */
    writew(COL_IN_TTPOLE | g_row_inuse, KPP_KPCR);

    /* re-configure the column to open-drain */
    writew(COL_IN_ODRAIN | g_row_inuse, KPP_KPCR);

    /* Scan sequence function */
    kpp_scan_matrix(keypad_state);

    /* copy the result to the application */
    memcpy(rd_keys, keypad_state, sizeof(keypad_state));

    /* Set a low level on each columns */
    writew(0, KPP_KPDR);
}

/*!
 * Keypad port function to wait for all keys to release.
 */
void kpp_wait_for_release_state(void)
{
    /* enter WFI now - TO DO */
    /* might be a problem when in debug mode with JTAG !!!! */

    g_wait_for_irq = 1;

    /* Clear status flags and synchronizer chains */
    writew(0xF, KPP_KPSR);

    /* There's nothing to return. This event only occurs
     * when all key are released.
     */
    enable_irq(KRIE);
    while(g_wait_for_irq);
}

/*!
 * Keypad port interrupt routine.
 */
void kpp_interrupt_routine(void)
{
    disable_irq(KDIE | KRIE);
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
        /* clear status flags and synchronizer chains */
        writew(0xF, KPP_KPSR);
        /* register the IRQ sub-routine */
        register_interrupt_routine(IMX_INT_KPP, &kpp_interrupt_routine);
        /* enable the IRQ */
        enable_interrupt(IMX_INT_KPP, CPU_0, 0);
    }
    else {
        /* disable the IRQ */
        disable_interrupt(IMX_INT_KPP, CPU_0);
        /* clear status flags and synchronizer chains */
        writew(0xF, KPP_KPSR);
    }
}

/*!
 * Initialize the keypad controller.
 *
 * @param   kpp_col - active columns in the keypad.
 * @param   kpp_row - active rows in the keypad.
 */
void kpp_init(uint8_t kpp_col, uint8_t kpp_row)
{
    /* Initialize global variables to store the board's keypad usage */
    g_col_inuse = kpp_col;
    g_row_inuse = kpp_row;

    /* there's no clock to enable for the keypad port */

    /* configure the IOMUX */
    kpp_iomux_config();

    /* configure the columns in open-drain & set the active rows */
    writew(COL_IN_ODRAIN | g_row_inuse, KPP_KPCR);
    /* configure columns as outputs and rows as inputs */
    writew(0xFF00, KPP_KDDR);
    /* set a low level on each columns */
    writew(0, KPP_KPDR);
    /* clear status flags and synchronizer chains */
    writew(0xF, KPP_KPSR);

    /* set up the interrupt */
    kpp_setup_interrupt(ENABLE);
}
