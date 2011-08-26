/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit.c
 * @brief EPIT driver.
 *
 */

#include "hardware.h"


void epit_enable(struct hw_module *port)
{
    volatile struct mx_epit *pepit = (volatile struct mx_epit *)port->base;

    pepit->epitcr |= EPITCR_EN;
}

/*! 
 * Setup EPIT interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the EPIT module structure
 */
void epit_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_1, 0);
    }
    else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_1);
}

void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode)
{
    volatile struct mx_epit *pepit = (volatile struct mx_epit *)port->base;
    uint32_t control_reg_tmp = 0;

    /* start with a known state by disabling and reseting the module */
    pepit->epitcr = EPITCR_SWR;
    /* wait for the reset to complete */
    while ((pepit->epitcr & EPITCR_SWR) != 0) ;

    /* set the source clock for the timer */
    control_reg_tmp |= clock_src;

    /* set the counter prescaler value */
    control_reg_tmp |= EPITCR_PRESCALAR(prescaler);

    /* set the reload mode */
    control_reg_tmp |= reload_mode;

    /* set behavior for low power mode */
    control_reg_tmp |= low_power_mode;

    /* make the counter start from a known value when enabled, this is loaded from
       EPITLR register if RLD=reload_mode=1 or 0xFFFFFFFF if RLD=reload_mode=0 */
    control_reg_tmp |= EPITCR_IOVW | EPITCR_ENMOD;

    /* finally write the control register */
    pepit->epitcr = control_reg_tmp;

    /* initialize the load register if RLD=reload_mode=1 */
    if(reload_mode == EPITCR_RLD)
        pepit->epitlr = load_val;
}






/************************************************************************/
/************************************************************************/
#ifdef OLD_TROUKS
static volatile int clock_counter;

/* Return the current clock value */
/* In order to obtain a high precision, whilst keeping the performance  */
/* penalty low, IRQs are only occuring at a rate of 100 per second, but */
/* the current timer value is factored in.  */
unsigned int ref_clock(void)
{
    return 0xFFFFFFFF - readl(EPIT_BASE_ADDR + EPITCNR);
}

//
// Delay for some number of micro-seconds
//
void hal_delay_us(unsigned int usecs)
{
    /*
     * This causes overflow.
     * unsigned int delayCount = (usecs * 32768) / 1000000;
     * So use the following one instead
     */
    unsigned int delayCount = (usecs * 512) / 15625;

    if (delayCount == 0) {
        return;
    }

    writel(0x01, EPIT_BASE_ADDR + EPITSR);  // clear the compare status bit

    writel(delayCount, EPIT_BASE_ADDR + EPITLR);

    while ((0x1 & readl(EPIT_BASE_ADDR + EPITSR)) == 0) ;   // return until compare bit is set
}

void epit2_isr(void)
{
    writel(0x1, EPIT2_BASE_ADDR + EPITSR);  // to clear interrupt source
    printf("epit timer interrupt!!\n");
}

void epit2_periodic_interrupt(unsigned int interval)
{
    unsigned int epitCr, val;
    epitCr = readl(EPIT2_BASE_ADDR + EPITCR);
    val = (epitCr & 0x03000000) >> 24;

    if (val == 3) {
        writel(interval, EPIT2_BASE_ADDR + EPITLR);
    } else {
        printf("undefine the clock you select\n");
    }

    val = readl(EPIT2_BASE_ADDR + EPITCR);
    enable_interrupt(IMX_INT_EPIT2, CPU_1, 0);
    register_interrupt_routine(IMX_INT_EPIT2, epit2_isr);
    writel(val | 0x1, EPIT2_BASE_ADDR + EPITCR);
}


#endif











