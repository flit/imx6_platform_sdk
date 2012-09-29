/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file snvs.c
 * @brief  SNVS driver source file.
 *
 */

#include "snvs/snvs.h"
#include "registers/regssnvs.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void snvs_rtc_counter(struct hw_module *port, uint8_t state)
{
    if (state)
    {
        // Set RTC_EN bit in hpcr register 
        HW_SNVS_HPCR_SET(BM_SNVS_HPCR_RTC_EN);

        // Wait until the bit is set 
        while (!HW_SNVS_HPCR.B.RTC_EN);
    }
    else
    {
        // Clear RTC_EN bit in hpcr register 
        HW_SNVS_HPCR_CLR(BM_SNVS_HPCR_RTC_EN);

        // Wait until the bit is cleared 
        while (HW_SNVS_HPCR.B.RTC_EN);
    }
}

void snvs_rtc_alarm(struct hw_module *port, uint8_t state)
{
    if (state)
    {
        // Set HPTA_EN bit of hpcr register 
        HW_SNVS_HPCR_SET(BM_SNVS_HPCR_HPTA_EN);

        // Wait until the bit is set 
        while (!HW_SNVS_HPCR.B.HPTA_EN);
    }
    else
    {
        // Clear HPTA_EN bit of hpcr register 
        HW_SNVS_HPCR_CLR(BM_SNVS_HPCR_HPTA_EN);

        // Wait until the bit is cleared 
        while (HW_SNVS_HPCR.B.HPTA_EN);
    }
}

void snvs_rtc_periodic_interrupt(struct hw_module *port, uint8_t freq, uint8_t state)
{
    if (state)
    {
        if (freq > 15)
        {
            freq = 15;
        }

        // Set freq, SNVS interrupts the CPU whenever the
        // frequency value (0-15) bit of RTC counter toggles.
        // The counter is incremented by the slow 32KHz clock.
        HW_SNVS_HPCR.B.PI_FREQ = freq;
        HW_SNVS_HPCR_SET(BM_SNVS_HPCR_PI_EN);
        while (!HW_SNVS_HPCR.B.PI_EN);
    }
    else
    {
        // Clear freq and periodic interrupt bit to disable periodic interrupt 
        HW_SNVS_HPCR_CLR(BM_SNVS_HPCR_PI_EN);

        while (HW_SNVS_HPCR.B.PI_EN);
    }
}

void snvs_rtc_set_counter(struct hw_module *port, uint64_t count)
{
    // Disable RTC
    snvs_rtc_counter(port, false);

    // Program the counter  
    HW_SNVS_HPRTCLR_WR(count & 0xffffffff);
    HW_SNVS_HPRTCMR_WR(count >> 32);

    // Reenable RTC 
    snvs_rtc_counter(port, true);
}

void snvs_rtc_set_alarm_timeout(struct hw_module *port, uint64_t timeout)
{
    // Disable alarm
    snvs_rtc_alarm(port, false);

    // Program time alarm registers 
    HW_SNVS_HPTALR_WR(timeout & 0xffffffff);
    HW_SNVS_HPTAMR_WR(timeout >> 32);

    // Reenable alarm 
    snvs_rtc_alarm(port, true);
}

void snvs_srtc_counter(struct hw_module *port, uint8_t state)
{
    if (state)
    {
        HW_SNVS_LPCR_SET(BM_SNVS_LPCR_SRTC_ENV);
        while (!HW_SNVS_LPCR.B.SRTC_ENV);
    }
    else
    {
        HW_SNVS_LPCR_CLR(BM_SNVS_LPCR_SRTC_ENV);
        while (HW_SNVS_LPCR.B.SRTC_ENV);
    }
}

void snvs_srtc_alarm(struct hw_module *port, uint8_t state)
{
    if (state)
    {
        HW_SNVS_LPCR_SET(BM_SNVS_LPCR_LPTA_EN);
        while (!HW_SNVS_LPCR.B.LPTA_EN);
    }    
    else
    {
        HW_SNVS_LPCR_CLR(BM_SNVS_LPCR_LPTA_EN);
        while (HW_SNVS_LPCR.B.LPTA_EN);
    }
}

void snvs_srtc_set_counter(struct hw_module *port, uint64_t count)
{
    // Disable RTC
    snvs_srtc_counter(port, false);

    // Program the counter  
    HW_SNVS_LPSRTCLR_WR(count & 0xffffffff);
    HW_SNVS_LPSRTCMR_WR(count >> 32);

    // Reenable RTC 
    snvs_srtc_counter(port, true);
}

void snvs_srtc_set_alarm_timeout(struct hw_module *port, uint32_t timeout)
{
    // Disable alarm
    snvs_srtc_alarm(port, false);

    // Program time alarm register 
    HW_SNVS_LPTAR_WR(timeout);

    // Reenable alarm 
    snvs_srtc_alarm(port, true);
}

void snvs_init(struct hw_module *port)
{
    // Nothing to do here.
}

void snvs_deinit(struct hw_module *port)
{
    // Nothing to do here.
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
