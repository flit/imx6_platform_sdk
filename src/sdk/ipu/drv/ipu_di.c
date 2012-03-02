/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_di.c
 * @brief display interface configuration of IPU.
 * @ingroup diag_ipu
 */

#include <stdio.h>
#include <string.h>
#include "ipu_common.h"
#include "io.h"
#include "hardware.h"

/*!
 * IPU display interface configuration, generating the timing for display devices.
 *
 * @param   ipu_index:  ipu index
 * @param   di:         used display interface
 * @param	panel:      ipu panel configuration data structure
 */
void ipu_di_config(uint32_t ipu_index, uint32_t di, ips_dev_panel_t * panel)
{
    /*********************************************************************
    *	DI0 configuration:
    *	hsync   	------	 DI0 pin 2
    *	vsync   	------	 DI0 pin 3
    *	data_en 	------	 DI0 pin 15
    *	clk     	------	 DI0 disp clk
    *	COUNTER 2  	------	 VSYNC
    *	COUNTER 3  	------	 HSYNC
    **********************************************************************/
    uint32_t hsync_sel = 1;
    uint32_t vsync_sel = 2;
    uint32_t clk_src = panel->clk_sel;
    int clkUp, clkDown;
    int ipuClk, typPixClk, div;
    int hDisp, hSyncStartWidth, hSyncWidth, hSyncEndWidth;
    int delayH2V;
    int vDisp, vSyncStartWidth, vSyncWidth, vSyncEndWidth;
    int hTotal, vTotal;
    int dw_set;                 // data waveform set
    int de_pointer = 0;
    int pt[7];
    di_sync_wave_gen_t syncWaveformGen = {
        0
    };

    /**********************************************************************
    *	these reference values are all got from panel spec.Typical
    * values are selected. BE CAREFUL to config the waveform generators!
    ***********************************************************************/

    hSyncStartWidth = panel->hsync_start_width;
    hSyncWidth = panel->hsync_width;
    hSyncEndWidth = panel->hsync_end_width;
    delayH2V = panel->delay_h2v;
    vSyncStartWidth = panel->vsync_start_width;
    vSyncWidth = panel->vsync_width;
    vSyncEndWidth = panel->vsync_end_width;
    typPixClk = panel->pixel_clock;
    hDisp = panel->width;
    vDisp = panel->height;
    hTotal = hSyncStartWidth + hSyncEndWidth + hDisp;
    vTotal = vSyncStartWidth + vSyncEndWidth + vDisp;

    /*use display panel clock */
    if (clk_src == 1)
        ipuClk = panel->pixel_clock;
    else
        ipuClk = IPU_DEFAULT_WORK_CLOCK;    // for imx6dqel->pixel_clock;

    div = (int)((float)ipuClk / (float)typPixClk + 0.5);    // get the nearest value of typical pixel clock
    ipu_di_screen_set(ipu_index, di, vTotal - 1);

    /* config PIN_15(DRDY signal)
       set DI_PIN15 to be waveform according to DI data wave set 2 pointer 0 */
    dw_set = 2;
    memset(pt, 0, sizeof(pt));
    pt[4] = dw_set;
    ipu_di_pointer_config(ipu_index, di, de_pointer, div - 1, div - 1, 0, pt);

    /*set the up & down of data wave set 2. */
    ipu_di_waveform_config(ipu_index, di, de_pointer, dw_set, 0, div * 2);  // one bit for fraction part

    /* set clk for DI0, generate the base clock of DI0 */
    clkUp = div;                // l-shift 1

    if (clkUp == 1)
        clkDown = clkUp * 2;
    else
        clkDown = clkUp * 2 - 1;

    ipu_di_bsclk_gen(ipu_index, di, div << 4, clkUp, clkDown);

    /*internal HSYNC */
    syncWaveformGen.runValue = hTotal - 1;
    syncWaveformGen.runResolution = DI_COUNTER_BASECLK + 1;
    syncWaveformGen.offsetValue = 0;
    syncWaveformGen.offsetResolution = 0;
    syncWaveformGen.cntAutoReload = 1;
    syncWaveformGen.stepRepeat = 0;
    syncWaveformGen.cntClrSel = 0;
    syncWaveformGen.cntPolarityGenEn = 0;
    syncWaveformGen.cntPolarityTrigSel = 0;
    syncWaveformGen.cntPolarityClrSel = 0;
    syncWaveformGen.cntUp = 0;
    syncWaveformGen.cntDown = 2;
    ipu_di_sync_config(ipu_index, di, DI_COUNTER_IHSYNC, syncWaveformGen);

    /*OUTPUT HSYNC */
    syncWaveformGen.runValue = hTotal - 1;
    syncWaveformGen.runResolution = DI_COUNTER_BASECLK + 1;
    syncWaveformGen.offsetValue = delayH2V;
    syncWaveformGen.offsetResolution = DI_COUNTER_BASECLK + 1;
    syncWaveformGen.cntAutoReload = 1;
    syncWaveformGen.stepRepeat = 0;
    syncWaveformGen.cntClrSel = 0;
    syncWaveformGen.cntPolarityGenEn = 0;
    syncWaveformGen.cntPolarityTrigSel = 0;
    syncWaveformGen.cntPolarityClrSel = 0;
    syncWaveformGen.cntUp = 0;
    syncWaveformGen.cntDown = div * hSyncWidth << 1;
    ipu_di_sync_config(ipu_index, di, DI_COUNTER_OHSYNC, syncWaveformGen);

    /*Output Vsync */
    syncWaveformGen.runValue = vTotal - 1;
    syncWaveformGen.runResolution = DI_COUNTER_IHSYNC + 1;
    syncWaveformGen.offsetValue = 0;
    syncWaveformGen.offsetResolution = 0;
    syncWaveformGen.cntAutoReload = 1;
    syncWaveformGen.stepRepeat = 0;
    syncWaveformGen.cntClrSel = 0;
    syncWaveformGen.cntPolarityGenEn = 1;
    syncWaveformGen.cntPolarityTrigSel = 2;
    syncWaveformGen.cntPolarityClrSel = 0;
    syncWaveformGen.cntUp = 0;
    syncWaveformGen.cntDown = vSyncWidth << 1;
    ipu_di_sync_config(ipu_index, di, DI_COUNTER_OVSYNC, syncWaveformGen);

    /*Active Lines start points */
    syncWaveformGen.runValue = 0;
    syncWaveformGen.runResolution = DI_COUNTER_OHSYNC + 1;
    syncWaveformGen.offsetValue = vSyncStartWidth;
    syncWaveformGen.offsetResolution = DI_COUNTER_OHSYNC + 1;
    syncWaveformGen.cntAutoReload = 0;
    syncWaveformGen.stepRepeat = vDisp;
    syncWaveformGen.cntClrSel = DI_COUNTER_OVSYNC + 1;
    syncWaveformGen.cntPolarityGenEn = 0;
    syncWaveformGen.cntPolarityTrigSel = 0;
    syncWaveformGen.cntPolarityClrSel = 0;
    syncWaveformGen.cntUp = 0;
    syncWaveformGen.cntDown = 0;
    ipu_di_sync_config(ipu_index, di, DI_COUNTER_ALINE, syncWaveformGen);

    /*Active clock start points */
    syncWaveformGen.runValue = 0;
    syncWaveformGen.runResolution = DI_COUNTER_BASECLK + 1;
    syncWaveformGen.offsetValue = hSyncStartWidth;
    syncWaveformGen.offsetResolution = DI_COUNTER_BASECLK + 1;
    syncWaveformGen.cntAutoReload = 0;
    syncWaveformGen.stepRepeat = hDisp;
    syncWaveformGen.cntClrSel = DI_COUNTER_ALINE + 1;
    syncWaveformGen.cntPolarityGenEn = 0;
    syncWaveformGen.cntPolarityTrigSel = 0;
    syncWaveformGen.cntPolarityClrSel = 0;
    syncWaveformGen.cntUp = 0;
    syncWaveformGen.cntDown = 0;
    ipu_di_sync_config(ipu_index, di, DI_COUNTER_ACLOCK, syncWaveformGen);

    ipu_di_interface_set(ipu_index, di, panel, 2, vsync_sel, hsync_sel);
}

/*!
 * set di waveform up/down attributes.
 *
 * @param   ipu_index:	ipu index
 * @param   di:			display interface selection
 * @param   pointer:    waveform pointer
 * @param   set:        waveform set
 * @param   up:         raising edge
 * @param   down:       falling edge
 */
void ipu_di_waveform_config(int ipu_index, int di, int pointer, int set, int up, int down)
{
    ipu_write_field(ipu_index, DI_WAVESET_UP(di, pointer, set), up);
    ipu_write_field(ipu_index, DI_WAVESET_DOWN(di, pointer, set), down);
    return;
}

/*!
 * set di waveform up/down attributes.
 *
 * @param   ipu_index:	ipu index
 * @param   di:         display interface selection
 * @param   screen_height: height of the screen
 */
int ipu_di_screen_set(int ipu_index, int di, int screen_height)
{
    switch (di) {
    case 0:
        ipu_write_field(ipu_index, IPU_DI0_SCR_CONF__DI0_SCREEN_HEIGHT, screen_height);
        break;

    case 1:
        ipu_write_field(ipu_index, IPU_DI1_SCR_CONF__DI1_SCREEN_HEIGHT, screen_height);
        break;

    default:
        printf("Wrong di pointer %d!!\n", di);
        return -1;
    }

    return 0;
}

/*!
 * set di pointer configuration
 *
 * @param   ipu_index:  ipu index
 * @param   di:         display interface selection
 * @param   pointer:    waveform pointer
 * @param   access:     access period, it define a clock period for display
 * @param   component:  component period
 * @param   cst:        chip select pointer
 * @param   pt:         pointer to the waveform
 */
void ipu_di_pointer_config(int ipu_index, int di, int pointer, int access, int component,
                           int cst, int *pt)
{
    unsigned int regVal = 0;
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    regVal =
        (access << 24) | (component << 16) | (cst << 14) | (pt[6] << 12) | (pt[5] << 10) | (pt[4] <<
                                                                                            8) |
        (pt[3] << 6) | (pt[2] << 4) | (pt[1] << 2) | pt[0];

    if (di == 0) {
        writel(regVal, ipu_base_addr + IPU_DI0_DW_GEN_0__ADDR + pointer * 4);
    } else {
        writel(regVal, ipu_base_addr + IPU_DI1_DW_GEN_0__ADDR + pointer * 4);
    }

    return;
}

/*!
 * set di waveform up/down attributes.
 *
 * @param   ipu_index:  ipu index
 * @param   di:         display interface selection
 * @param   division:   clock divider
 * @param   up:         raising edge
 * @param   down:       falling edge
 *
 * @return 	true for success and false for failure
 */
int ipu_di_bsclk_gen(int ipu_index, int di, int division, int up, int down)
{
    switch (di) {
    case 0:
        ipu_write_field(ipu_index, IPU_DI0_BS_CLKGEN0__DI0_DISP_CLK_OFFSET, 0);
        ipu_write_field(ipu_index, IPU_DI0_BS_CLKGEN0__DI0_DISP_CLK_PERIOD, division);
        ipu_write_field(ipu_index, IPU_DI0_BS_CLKGEN1__DI0_DISP_CLK_DOWN, down);
        ipu_write_field(ipu_index, IPU_DI0_BS_CLKGEN1__DI0_DISP_CLK_UP, up);
        break;

    case 1:
        ipu_write_field(ipu_index, IPU_DI1_BS_CLKGEN0__DI1_DISP_CLK_OFFSET, 0);
        ipu_write_field(ipu_index, IPU_DI1_BS_CLKGEN0__DI1_DISP_CLK_PERIOD, division);
        ipu_write_field(ipu_index, IPU_DI1_BS_CLKGEN1__DI1_DISP_CLK_DOWN, down);
        ipu_write_field(ipu_index, IPU_DI1_BS_CLKGEN1__DI1_DISP_CLK_UP, up);
        break;

    default:
        printf("Wrong di pointer %d!!\n", di);
        return false;
    }

    return true;
}

/*!
 * This function is used to config the waveform generator in the DI
 *
 * @param	ipu_index:	ipu index
 * @param	di:			display interface selection
 * @param	pointer:		waveform pointer
 * @param	sync_waveform_gen:		waveform information
 */
void ipu_di_sync_config(int ipu_index, int di, int pointer, di_sync_wave_gen_t sync_waveform_gen)
{
    ipu_write_field(ipu_index, DI_SWGEN0_RUN_VALUE_M1(di, pointer), sync_waveform_gen.runValue);
    ipu_write_field(ipu_index, DI_SWGEN0_RUN_RESOL(di, pointer), sync_waveform_gen.runResolution);
    ipu_write_field(ipu_index, DI_SWGEN0_OFFSET_VALUE(di, pointer), sync_waveform_gen.offsetValue);
    ipu_write_field(ipu_index, DI_SWGEN0_OFFSET_RESOL(di, pointer),
                    sync_waveform_gen.offsetResolution);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_POL_GEN_EN(di, pointer),
                    sync_waveform_gen.cntPolarityGenEn);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_AUTOLOAD(di, pointer),
                    sync_waveform_gen.cntAutoReload);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_CLR_SEL(di, pointer), sync_waveform_gen.cntClrSel);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_DOW(di, pointer), sync_waveform_gen.cntDown);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_POL_TRIG_SEL(di, pointer),
                    sync_waveform_gen.cntPolarityTrigSel);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_POL_CLR_SEL(di, pointer),
                    sync_waveform_gen.cntPolarityClrSel);
    ipu_write_field(ipu_index, DI_SWGEN1_CNT_CNT_UP(di, pointer), sync_waveform_gen.cntUp);
    ipu_write_field(ipu_index, DI_STEP_RPT(di, pointer), sync_waveform_gen.stepRepeat);

    return;
}

/*!
 * set the display interface attributes.
 *
 * @param   ipu_index:  ipu index
 * @param   di:         display interface selection
 * @param   panel:      ipu panel configuration data structure
 * @param   line_prediction:    prediction of lines
 * @param   vsync_sel:  vsynch selection
 * @param   hsync_sel:  hsynch selection
 */
void ipu_di_interface_set(uint32_t ipu_index, uint32_t di, ips_dev_panel_t * panel,
                          uint32_t line_prediction, uint32_t vsync_sel, uint32_t hsync_sel)
{
    switch (di) {
    case 0:
        ipu_write_field(ipu_index, IPU_DI0_SYNC_AS_GEN__DI0_SYNC_START, line_prediction);
        ipu_write_field(ipu_index, IPU_DI0_SYNC_AS_GEN__DI0_VSYNC_SEL, vsync_sel);
        ipu_write_field(ipu_index, IPU_DI0_GENERAL__DI0_DISP_Y_SEL, hsync_sel);
        ipu_write_field(ipu_index, IPU_DI0_GENERAL__DI0_CLK_EXT, panel->clk_sel);

        ipu_write_field(ipu_index, IPU_DI0_GENERAL__DI0_POLARITY_DISP_CLK, 0);
        ipu_write_field(ipu_index, IPU_DI0_GENERAL__ADDR, 1 << vsync_sel, panel->vsync_pol);    //VSYNC POLARITY
        ipu_write_field(ipu_index, IPU_DI0_GENERAL__ADDR, 1 << hsync_sel, panel->hsync_pol);    //HSYNC POLARITY
        ipu_write_field(ipu_index, IPU_DI0_POL__DI0_DRDY_POLARITY_15, panel->drdy_pol);

        ipu_write_field(ipu_index, IPU_DI0_POL__DI0_DRDY_DATA_POLARITY, panel->data_pol);
        /*release ipu DI0 counter */
        ipu_write_field(ipu_index, IPU_IPU_DISP_GEN__DI0_COUNTER_RELEASE, 1);
        break;

    case 1:
        ipu_write_field(ipu_index, IPU_DI1_SYNC_AS_GEN__DI1_SYNC_START, line_prediction);
        ipu_write_field(ipu_index, IPU_DI1_SYNC_AS_GEN__DI1_VSYNC_SEL, vsync_sel);
        ipu_write_field(ipu_index, IPU_DI1_GENERAL__DI1_DISP_Y_SEL, hsync_sel);
        ipu_write_field(ipu_index, IPU_DI1_GENERAL__DI1_CLK_EXT, panel->clk_sel);

        ipu_write_field(ipu_index, IPU_DI1_GENERAL__DI1_POLARITY_DISP_CLK, panel->clk_pol);
        ipu_write_field(ipu_index, IPU_DI1_GENERAL__ADDR, 1 << vsync_sel, panel->vsync_pol);    //VSYNC POLARITY
        ipu_write_field(ipu_index, IPU_DI1_GENERAL__ADDR, 1 << hsync_sel, panel->hsync_pol);    //HSYNC POLARITY
        ipu_write_field(ipu_index, IPU_DI1_POL__DI1_DRDY_POLARITY_15, panel->drdy_pol);
        ipu_write_field(ipu_index, IPU_DI1_POL__DI1_DRDY_DATA_POLARITY, panel->data_pol);

        /*release ipu DI1 counter */
        ipu_write_field(ipu_index, IPU_IPU_DISP_GEN__DI1_COUNTER_RELEASE, 1);
        break;

    default:
        printf("Wrong di pointer %d!!\n", di);
    }
}
