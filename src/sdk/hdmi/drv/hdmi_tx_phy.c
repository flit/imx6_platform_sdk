/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_tx_phy.c
 * @brief common functions defination of hdmi phy.
 *
 * @ingroup diag_hdmi
 */

#include <stdio.h>
#include "hardware.h"
#include "hdmi_tx.h"

/*!
 * configure the interrupt mask of source PHY.
 */
void hdmi_phy_int_mask(int mask)
{
    writeb(mask, HDMI_PHY_MASK0);
}

/*!
 * set the DE polarity
 * @param	pol: high or low for DE active
 */
void hdmi_phy_de_pol(int pol)
{
    writebf(pol, HDMI_PHY_CONF0, 1, 1);
}

/*!
 * select the interface control??
 * @param  seldipif: interface selection
 */
void hdmi_phy_if_sel(int seldipif)
{
    writebf(seldipif, HDMI_PHY_CONF0, 0, 1);
}

/*!
 * enable TMDS output
 * @param	en: enable or disable the TMDS output
 */
void hdmi_phy_tmds(int en)
{
    writebf(en, HDMI_PHY_CONF0, 6, 1);
}

/*!
 * PHY power down enable
 * @param 	en: enable or disable PHY
 * 1 - power down disable
 * 0 - power down enable
 */
void hdmi_phy_pdown(int en)
{
    writebf(en, HDMI_PHY_CONF0, 7, 1);
}

/*!
 * PHY reset
 * @param 	bit: reset PHY
 * 1 - reset PHY
 * 0 - turn PHY to normal
 */
void hdmi_phy_reset(uint8_t bit)
{
    writebf(bit ? 0 : 1, HDMI_MC_PHYRSTZ, 0, 1);
}

static inline void hdmi_phy_test_clear(uint8_t bit)
{
    writebf(bit, HDMI_PHY_TST0, 5, 1);
}

static inline void hdmi_phy_test_enable(uint8_t bit)
{
    writebf(bit, HDMI_PHY_TST0, 4, 1);
}

static inline void hdmi_phy_test_clock(uint8_t bit)
{
    writebf(bit, HDMI_PHY_TST0, 0, 1);
}

static inline void hdmi_phy_test_din(uint8_t bit)
{
    writeb(bit, HDMI_PHY_TST1);
}

static inline void hdmi_phy_test_dout(uint8_t bit)
{
    writeb(bit, HDMI_PHY_TST2);
}

static int hdmi_phy_test_control(uint8_t value)
{
    hdmi_phy_test_din(value);
    hdmi_phy_test_enable(1);
    hdmi_phy_test_clock(1);
    hdmi_phy_test_clock(0);
    hdmi_phy_test_enable(0);

    return TRUE;
}

static int hdmi_phy_test_data(uint8_t value)
{
    hdmi_phy_test_din(value);
    hdmi_phy_test_enable(0);
    hdmi_phy_test_clock(1);
    hdmi_phy_test_clock(0);

    return TRUE;
}

static void hdmi_phy_gen2_tx_pon(uint8_t bit)
{
    writebf(bit, HDMI_PHY_CONF0, 3, 1); //gen2 tx power on
}

static void hdmi_phy_gen2_pddq(uint8_t bit)
{
    writebf(bit, HDMI_PHY_CONF0, 4, 1); //gen2 pddq
}

static void hdmi_heacphy_reset(uint8_t bit)
{
    writebf(bit, HDMI_MC_HEACPHY_RST, 0, 1);    //gen2 pddq
}

/*!
 * polling the i2c operation status bit to check if the i2c r/w
 * is done before the time run out.
 *
 * @param 	msec:	time out value, using epit as the timer
 */
int hdmi_phy_wait_i2c_done(int msec)
{
    unsigned char val = 0;
    val = readb(HDMI_IH_I2CMPHY_STAT0) & 0x3;
    while (val == 0) {
        hal_delay_us(1000);
        if (msec-- == 0) {
            printf("HDMI PHY i2c operation time out!!\n");
            return FALSE;
        }
        val = readb(HDMI_IH_I2CMPHY_STAT0) & 0x3;
    }
    return TRUE;
}

/*!
 * HDMI phy registers access through internal I2C bus
 *
 * @param	data: 	value to be send
 * @param	addr:	sub-address of registers
 *
 * @retval	TRUE:	I2C write succeed
 * @retval	FALSE:	I2C write failed/timeout  
 */
int hdmi_phy_i2c_write(uint16_t data, uint8_t addr)
{
    writeb(0xFF, HDMI_IH_I2CMPHY_STAT0);
    writeb(addr, HDMI_PHY_I2CM_ADDRESS_ADDR);
    writeb((uint8_t) (data >> 8), HDMI_PHY_I2CM_DATAO_1_ADDR);
    writeb((uint8_t) (data >> 0), HDMI_PHY_I2CM_DATAO_0_ADDR);
    writebf(1, HDMI_PHY_I2CM_OPERATION_ADDR, 4, 1);
    return hdmi_phy_wait_i2c_done(1000);
}

/*!
 * HDMI phy registers read through internal I2C bus
 *
 * @param	addr:	sub-address of register
 *
 * @return	value read back
 */
uint16_t hdmi_phy_i2c_read(uint8_t addr)
{
    uint16_t data;
    uint8_t msb = 0, lsb = 0;
    writeb(0xFF, HDMI_IH_I2CMPHY_STAT0);
    writeb(addr, HDMI_PHY_I2CM_ADDRESS_ADDR);
    writebf(1, HDMI_PHY_I2CM_OPERATION_ADDR, 0, 1);
    hdmi_phy_wait_i2c_done(1000);
    msb = readb(HDMI_PHY_I2CM_DATAI_1_ADDR);
    lsb = readb(HDMI_PHY_I2CM_DATAI_0_ADDR);
    data = (msb << 8) | lsb;
    return data;
}

/*!
 * HDMI phy registers access and verificate through internal I2C bus
 *
 * @param	data: 	value to be send
 * @param	addr:	sub-address of registers
 *
 * @retval	TRUE:	I2C write succeed
 * @retval	FALSE:	I2C write failed, the value read back not equal to the input  
 */
int hdmi_phy_i2c_write_verify(uint16_t data, uint8_t addr)
{
    unsigned short val = 0;
    //int repeat = 5;
    hdmi_phy_i2c_write(data, addr);
    val = hdmi_phy_i2c_read(addr);
    if (val != data) {
        printf("I2C data verification failed at REG 0x%02x : 0x%04x vs 0x%04x\n", addr, data, val);
        return FALSE;
    }
    return TRUE;
}

#define PHY_GEN2
/*!
 * HDMI phy configuration
 *
 * @param	pClk: 	pixel clock input
 * @param	pRep:	repetition setting
 * @param	cRes: 	color resolution per component
 * @param	cscOn:	csc on/off switch
 * @param	audioOn:	audio on/off switch
 * @param	cecOn:	cec on/off switch
 * @param	hdcpOn: hdcp on/off switch
 *
 * @retval	FALSE	configuration failed
 * @retval	TRUE	configuration succeed
 */
int hdmi_phy_configure(uint16_t pClk, uint8_t pRep, uint8_t cRes, int cscOn,
                       int audioOn, int cecOn, int hdcpOn)
{
    uint16_t clk = 0, rep = 0;
    // colour resolution 0 is 8 bit colour depth
    if (cRes == 0) {
        cRes = 8;
    }
    if (pRep != 0) {
        printf("pixel repetition not supported %d", pRep);
        return FALSE;
    } else if (cRes != 8 && cRes != 12) {
        printf("color resolution not supported %d", cRes);
        return FALSE;
    }

    switch (pClk) {
    case 2520:
        clk = 0x93C1;
        rep = (cRes == 8) ? 0x6A4A : 0x6653;
        break;
    case 2700:
        clk = 0x96C1;
        rep = (cRes == 8) ? 0x6A4A : 0x6653;
        break;
    case 5400:
        clk = 0x8CC3;
        rep = (cRes == 8) ? 0x6A4A : 0x6653;
        break;
    case 7200:
        clk = 0x90C4;
        rep = (cRes == 8) ? 0x6A4A : 0x6654;
        break;
    case 7425:
        clk = 0x95C8;
        rep = (cRes == 8) ? 0x6A4A : 0x6654;
        break;
    case 10800:
        clk = 0x98C6;
        rep = (cRes == 8) ? 0x6A4A : 0x6653;
        break;
    case 14850:
        clk = 0x89C9;
        rep = (cRes == 8) ? 0x6A4A : 0x6654;
        break;
    default:
        printf("pixel clock not supported %d", pClk);
        return FALSE;
    }
    writebf((cscOn == TRUE) ? 1 : 0, HDMI_MC_FLOWCTRL, 0, 1);
    // clock gate == 0 => turn on modules
    writebf(0, HDMI_MC_CLKDIS, 0, 1);
    writebf(0, HDMI_MC_CLKDIS, 1, 1);
    writebf((pRep > 0) ? 1 : 0, HDMI_MC_CLKDIS, 2, 1);
    writebf((audioOn == TRUE) ? 1 : 0, HDMI_MC_CLKDIS, 3, 1);
    writebf((cscOn == TRUE) ? 1 : 0, HDMI_MC_CLKDIS, 4, 1);
    writebf((cecOn == TRUE) ? 1 : 0, HDMI_MC_CLKDIS, 5, 1);
    writebf((hdcpOn == TRUE) ? 1 : 0, HDMI_MC_CLKDIS, 6, 1);

#ifdef PHY_GEN2
    hdmi_phy_gen2_tx_pon(0);
    hdmi_phy_gen2_pddq(1);
    hdmi_phy_reset(0);
    hdmi_phy_reset(1);
    hdmi_heacphy_reset(1);
    hdmi_phy_test_clear(1);
    writebf(0x69, HDMI_PHY_I2CM_SLAVE_ADDR, 0, 7);
    hdmi_phy_test_clear(0);

    switch (pClk) {
    case 2520:
        switch (cRes) {
        case 8:
            // PLL/MPLL Cfg
            hdmi_phy_i2c_write(0x01e0, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);   // CURRCTRL
            hdmi_phy_i2c_write(0x0000, 0x15);   // GMPCTRL
            hdmi_phy_i2c_write(0x0000, 0x13);   // PLLPHBYCTRL
            hdmi_phy_i2c_write(0x0006, 0x17);
            // RESISTANCE TERM 133Ohm Cfg
            hdmi_phy_i2c_write(0x0005, 0x19);   // TXTERM
            // PREEMP Cgf 0.00
            hdmi_phy_i2c_write(0x8009, 0x09);   // CKSYMTXCTRL
            // TX/CK LVL 10
            hdmi_phy_i2c_write(0x0210, 0x0E);   // VLEVCTRL
            // REMOVE CLK TERM
            hdmi_phy_i2c_write(0x8000, 0x05);   // CKCALCTRL
            break;
        case 10:
            hdmi_phy_i2c_write(0x21e1, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x0000, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x41e2, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0000, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 2700:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x01e0, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x0000, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x21e1, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x0000, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x41e2, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0000, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 5400:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x0140, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x2141, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x4142, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 7200:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x0140, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x2141, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x40a2, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 7425:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x0140, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x0005, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x20a1, 0x06);
            hdmi_phy_i2c_write(0x0b5c, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x40a2, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 10800:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x00a0, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x20a1, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x40a2, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    case 14850:
        switch (cRes) {
        case 8:
            hdmi_phy_i2c_write(0x00a0, 0x06);
            hdmi_phy_i2c_write(0x06dc, 0x10);
            hdmi_phy_i2c_write(0x000a, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 10:
            hdmi_phy_i2c_write(0x2001, 0x06);
            hdmi_phy_i2c_write(0x0b5c, 0x10);
            hdmi_phy_i2c_write(0x000f, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x8009, 0x09);
            hdmi_phy_i2c_write(0x0210, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        case 12:
            hdmi_phy_i2c_write(0x4002, 0x06);
            hdmi_phy_i2c_write(0x091c, 0x10);
            hdmi_phy_i2c_write(0x000f, 0x15);
            hdmi_phy_i2c_write(0x0000, 0x13);
            hdmi_phy_i2c_write(0x0006, 0x17);
            hdmi_phy_i2c_write(0x0005, 0x19);
            hdmi_phy_i2c_write(0x800b, 0x09);
            hdmi_phy_i2c_write(0x0129, 0x0E);
            hdmi_phy_i2c_write(0x8000, 0x05);
            break;
        default:
            printf("color depth not supported %d", pClk);
            return FALSE;
        }
        break;
    default:
        printf("pixel clock not supported %d", pClk);
        return FALSE;
    }
    hdmi_phy_gen2_tx_pon(1);
    hdmi_phy_gen2_pddq(0);
    hal_delay_us(1000);
#else //this is for test mode
    hdmi_phy_test_clear(0);
    hdmi_phy_test_clear(1);
    hdmi_phy_test_clear(0);
#define PHY_TNP
#ifdef PHY_TNP
    printf("TNP build\n");
#else
    printf("CNP build\n");
#endif
#ifndef PHY_TNP
    hdmi_phy_test_clock(0);
    hdmi_phy_test_enable(0);
    if (hdmi_phy_test_control(0x1B) == FALSE) {
        return FALSE;
    }
    hdmi_phy_test_data((unsigned char)(clk >> 8));
    hdmi_phy_test_data((unsigned char)(clk >> 0));
    if (hdmi_phy_test_control(0x1A) == FALSE) {
        return FALSE;
    }
    hdmi_phy_test_data((unsigned char)(rep >> 8));
    hdmi_phy_test_data((unsigned char)(rep >> 0));
#endif
    if (pClk == 14850 && cRes == 12) {
        printf("Applying Pre-Emphase");
        if (hdmi_phy_test_control(0x24) == FALSE) {
            return FALSE;
        }
        hdmi_phy_test_data(0x80);
        hdmi_phy_test_data(0x90);
        hdmi_phy_test_data(0xa0);
#ifndef PHY_TNP
        hdmi_phy_test_data(0xb0);
        if (hdmi_phy_test_control(0x20) == FALSE) { // +11.1ma 3.3 pe
            return FALSE;
        }
        hdmi_phy_test_data(0x04);
        if (hdmi_phy_test_control(0x21) == FALSE) { // +11.1 +2ma 3.3 pe
            return FALSE;
        }
        hdmi_phy_test_data(0x2a);
        // TODO verify
        if (hdmi_phy_test_control(0x11) == FALSE) {
            return FALSE;
        }
        hdmi_phy_test_data(0xf3);
        hdmi_phy_test_data(0x93);
#else
        if (hdmi_phy_test_control(0x20) == FALSE) {
            return FALSE;
        }
        hdmi_phy_test_data(0x00);
        if (hdmi_phy_test_control(0x21) == FALSE) {
            return FALSE;
        }
        hdmi_phy_test_data(0x00);
#endif
    }
    if (hdmi_phy_test_control(0x00) == FALSE) {
        return FALSE;
    }
    hdmi_phy_test_din(0x00);
    hdmi_phy_reset(1);          // reset PHY
    hdmi_phy_reset(0);          // for phy gen2 shoud be 0 => 1
    hdmi_phy_tmds(0);           // toggle TMDS
    hdmi_phy_tmds(1);
#endif
    if ((readb(HDMI_PHY_STAT0) & 0x01) == 0) {
        //printf("PHY PLL not locked");
        return FALSE;
    }
    return TRUE;
}

/*!
 * HDMI phy initialization
 *
 * @param	de:		data enable polarity, 1 for positive and 0 for negative
 * @param	pclk:	pixel clock
 */
void hdmi_phy_init(uint8_t de, uint16_t pclk)
{
    hdmi_phy_int_mask(0xFF);
    hdmi_phy_de_pol((de == TRUE) ? 1 : 0);
    hdmi_phy_if_sel(0);
    hdmi_phy_tmds(1);
    hdmi_phy_pdown(1);          //enable PHY

    hdmi_phy_configure(pclk, 0, 8, FALSE, FALSE, FALSE, FALSE);
}
