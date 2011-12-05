/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs.c
 * @brief  SNVS driver source file.
 *
 */

#include <snvs.h>

/* Driver API */

/*!
 * Enable or disable non-secured real time counter
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   state - 1 to enable the counter and any other value to disable it.
 */
void snvs_rtc_counter(struct hw_module *port, uint8_t state)
{
    volatile struct mx_snvs *psnvs = 
        (volatile struct mx_snvs *)port->base;

    if( state == ENABLE )
    {
        /* Set RTC_EN bit in hpcr register */
        psnvs->hpcr |= HPCR_RTC_EN;

        /* Wait until the bit is set */
        while((psnvs->hpcr & HPCR_RTC_EN) == 0);
    }
    else
    {
        /* Clear RTC_EN bit in hpcr register */
        psnvs->hpcr &= ~HPCR_RTC_EN;

        /* Wait until the bit is cleared */
        while(psnvs->hpcr & HPCR_RTC_EN);
    }
}

/*!
 * Enable or disable non-secured time alarm
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   state - 1 to enable the alarm and any other value to disable it.
 */
void snvs_rtc_alarm(struct hw_module *port, uint8_t state)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    if( state == ENABLE )
    {
        /* Set HPTA_EN bit of hpcr register */
        psnvs->hpcr |= HPCR_HPTA_EN;

        /* Wait until the bit is set */
        while((psnvs->hpcr & HPCR_HPTA_EN) == 0);
    }
    else
    {
        /* Clear HPTA_EN bit of hpcr register */
        psnvs->hpcr &= ~HPCR_HPTA_EN;

        /* Wait until the bit is cleared */
        while(psnvs->hpcr & HPCR_HPTA_EN);
    }
}

/*!
 * Enable or disable non-secured periodic interrupt
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   freq - frequence for periodic interrupt, valid values 0 to 15, 
 *          a value greater than 15 will be regarded as 15.
 *
 * @param   state - 1 to enable the alarm and any other value to disable it.
 */
void snvs_rtc_periodic_interrupt(struct hw_module *port, uint8_t freq, uint8_t state)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    if( state == ENABLE )
    {
        if( freq > 15 )
            freq = 15;

        /* First clear the periodic interrupt frequency bits */
        psnvs->hpcr &= ~HPCR_PI_FREQ_MASK;

        /* Set freq, SNVS interrupts the CPU whenever the 
         * frequency value (0-15) bit of RTC counter toggles.
         * The counter is incremented by the slow 32KHz clock. 
         */
        psnvs->hpcr |= ((freq << HPCR_PI_FREQ_SHIFT) & HPCR_PI_FREQ_MASK);
        psnvs->hpcr |= HPCR_PI_EN;
        while((psnvs->hpcr & HPCR_PI_EN) == 0);
    }
    else
    {
        /* Clear freq and periodic interrupt bit to disable periodic interrupt */
        psnvs->hpcr &= ~HPCR_PI_FREQ_MASK;
        psnvs->hpcr &= ~HPCR_PI_EN;
        while(psnvs->hpcr & HPCR_PI_EN);
    }
}

/*!
 * Programs non-secured real time counter
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   count - 64-bit integer to program into 47-bit RTC counter register;
 *          only 47-bit LSB will be used
 */
void snvs_rtc_set_counter(struct hw_module *port, uint64_t count)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    /* Disable RTC */
    snvs_rtc_counter(port, DISABLE);

    /* Program the counter */ 
    psnvs->hprtclr = (uint32_t)count;
    psnvs->hprtcmr = (uint32_t)(count >> 32);

    /* Reenable RTC */
    snvs_rtc_counter(port, ENABLE);
}

/*!
 * Sets non-secured RTC time alarm register
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   timeout - 64-bit integer to program into 47-bit time alarm register;
 *          only 47-bit LSB will be used
 */
void snvs_rtc_set_alarm_timeout(struct hw_module *port, uint64_t timeout)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    /* Disable alarm */
    snvs_rtc_alarm(port, DISABLE);

    /* Program time alarm registers */
    psnvs->hptalr = (uint32_t)timeout;
    psnvs->hptamr = (uint32_t)(timeout >> 32);

    /* Reenable alarm */
    snvs_rtc_alarm(port, ENABLE);
}

/*!
 * Enable or disable secure real time counter
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   state - 1 to enable the counter and any other value to disable it.
 */
void snvs_srtc_counter(struct hw_module *port, uint8_t state)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;


    if(state == ENABLE)
    {
        psnvs->lpcr |= LPCR_RTC_EN;
        while((psnvs->lpcr & LPCR_RTC_EN) == 0);
    }
    else
    {
        psnvs->lpcr &= ~LPCR_RTC_EN;
        while(psnvs->lpcr & LPCR_RTC_EN);
    }
}

/*!
 * Enable or disable secure time alarm
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   state - 1 to enable the alarm and any other value to disable it.
 */
void snvs_srtc_alarm(struct hw_module *port, uint8_t state)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    if(state == ENABLE)
    {
        psnvs->lpcr |= LPCR_LPTA_EN;
        while((psnvs->lpcr & LPCR_LPTA_EN) == 0);
    }    
    else
    {
        psnvs->lpcr &= ~LPCR_LPTA_EN;
        while(psnvs->lpcr & LPCR_LPTA_EN);
    }
}

/*!
 * Programs secure real time counter
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   count - 64-bit integer to program into 47-bit SRTC counter register;
 *          only 47-bit LSB will be used
 */
void snvs_srtc_set_counter(struct hw_module *port, uint64_t count)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    /* Disable RTC */
    snvs_srtc_counter(port, DISABLE);

    /* Program the counter */ 
    psnvs->lpsrtclr = (uint32_t)count;
    psnvs->lpsrtcmr = (uint32_t)(count >> 32);

    /* Reenable RTC */
    snvs_srtc_counter(port, ENABLE);
}

/*!
 * Set secured RTC time alarm register
 *
 * @param   port - pointer to the SNVS module structure.
 *
 * @param   timeout - 32-bit integer to program into 32-bit time alarm register;
 */
void snvs_srtc_set_alarm_timeout(struct hw_module *port, uint32_t timeout)
{
    volatile struct mx_snvs *psnvs = (volatile struct mx_snvs *)port->base;

    /* Disable alarm */
    snvs_srtc_alarm(port, DISABLE);

    /* Program time alarm register */
    psnvs->lptar = timeout;

    /* Reenable alarm */
    snvs_srtc_alarm(port, ENABLE);
}

/*!
 * Presently nothing to do as part of snvs initialization
 *
 * @param   port - pointer to the SNVS module structure.
 */
void snvs_init(struct hw_module *port)
{
}

/*!
 * Presently nothing to do as part of snvs deinit
 *
 * @param   port - pointer to the SNVS module structure.
 */
void snvs_deinit(struct hw_module *port)
{
}
