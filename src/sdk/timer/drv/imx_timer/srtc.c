/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file srtc.c
 * @brief  SRTC driver source file.
 *
 * @ingroup diag_timer
 */

#include <snvs.h>
#include <srtc.h>
#include <soc_memory_map.h>
#include <interrupt.h>

/*!
 * SRTC strucures used by the driver.
 */
typedef struct snvs_srtc_module_ {
    struct hw_module *port;
    funct_t onetime_timer_callback;
} snvs_srtc_module_t;

/* Local functions declaration */

void snvs_srtc_setup_interrupt(struct hw_module *port, uint8_t state);
void snvs_srtc_interrupt_handler(void);

static struct hw_module port = {
        "SNVS SRTC Driver",                 /* Driver Name */
        SNVS_BASE_ADDR,                     /* Block base address in memory map */
        0,                                  /* Frequency */
        IMX_INT_SNVS,                   /* Interrupt ID*/
        &snvs_srtc_interrupt_handler        /* Irq handler*/ 
};

static struct snvs_srtc_module_ snvs_srtc_module = {
    &port,
    NULL
};

/* Local Functions */

/*!
 * Setup SNVS interrupt. It enables or disables the related HW module
 * interrupt, and attached the related sub-routine into the vector table.
 *
 * @param   port - pointer to the SNVS module structure.
 * @param   state - ENABLE or DISABLE the interrupt.
 */
void snvs_srtc_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == ENABLE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    }
    else
    {
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
    }
}

/*!
 * SNVS SRTC interrupt handler.
 */
void snvs_srtc_interrupt_handler(void)
{
    volatile struct mx_snvs *psnvs = 
        (volatile struct mx_snvs *)snvs_srtc_module.port->base;

    snvs_srtc_setup_interrupt(snvs_srtc_module.port, DISABLE);

    if(psnvs->lpsr & LPSR_LPTA && snvs_srtc_module.onetime_timer_callback != NULL)
    {
        psnvs->lpsr &= ~LPSR_LPTA;
        snvs_srtc_module.onetime_timer_callback();
        snvs_srtc_module.onetime_timer_callback = NULL;
        snvs_srtc_alarm(snvs_srtc_module.port, DISABLE);
    }   
    else
    {
        snvs_srtc_setup_interrupt(snvs_srtc_module.port, ENABLE);
    }
}

/* Driver API */
/*!
 * Initializes SRTC by enabling secure real time counter and
 * disables time alarm. It also calls internal API snvs_rtc_setup_interrupt 
 * to register interrupt service handler
 */
void srtc_init(void)
{
    /* Initialize SNVS driver */
    snvs_init(snvs_srtc_module.port);

    /* Start SRTC counter */
    snvs_srtc_counter(snvs_srtc_module.port, ENABLE);

    /* Keep time alarm disabled */
    snvs_srtc_alarm(snvs_srtc_module.port, DISABLE);
}

/*!
 * Disables interrupt, counter and time alarm 
 */
void srtc_deinit(void)
{
    /* Disable the interrupt */
    snvs_srtc_setup_interrupt(snvs_srtc_module.port, DISABLE);

    /* Disable the counter */
    snvs_srtc_counter(snvs_srtc_module.port, DISABLE);
    snvs_srtc_alarm(snvs_srtc_module.port, DISABLE);

    /* Deinitialize SNVS */
    snvs_deinit(snvs_srtc_module.port);
}

/*!
 * Calls in appropriate low level API to setup SRTC one-time timer
 *
 * @param   timeout - set SRTC alarm timeout.
 * @param   callback - callback function to be called from isr.
 */
void srtc_setup_onetime_timer(uint32_t timeout, funct_t callback)
{
    /* Disables the interrupt */
    snvs_srtc_setup_interrupt(snvs_srtc_module.port, DISABLE);

    /* Clear the SRTC counter */
    snvs_srtc_set_counter(snvs_srtc_module.port, 0);

    /* Program the timeout value */
    snvs_srtc_set_alarm_timeout(snvs_srtc_module.port, timeout);

    /* Set the callback function */
    snvs_srtc_module.onetime_timer_callback = callback;

    /* Reanable the interrupt */
    snvs_srtc_setup_interrupt(snvs_srtc_module.port, ENABLE);
}
