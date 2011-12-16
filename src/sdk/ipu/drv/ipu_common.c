/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file ipu_common.c
 * @brief common functions defination of IPU.
 * @ingroup diag_ipu
 */

#include <string.h>
#include "ipu_common.h"

inline int need_csc(int i, int o)
{
    if ((i == INTERLEAVED_RGB && o > DCMAP_BRG888) || (i != INTERLEAVED_RGB && o <= DCMAP_BRG888))
        return 1;
    else
        return 0;
}

/*!
 * write field of ipu registers, without affecting other bits.
 *
 * @param	ipu_index:	ipu index
 * @param	ID_addr:    register address
 * @param	ID_mask:    fields position
 * @param	data:	    the value of input
 */
void ipu_write_field(int ipu_index, uint32_t ID_addr, uint32_t ID_mask, uint32_t data)
{
    uint32_t rdata;

    if (ipu_index == 1)
        ID_addr += IPU1_CTRL_BASE_ADDR;
    else if (ipu_index == 2)
        ID_addr += IPU2_CTRL_BASE_ADDR;
    else {
        printf("wrong ipu index %d\n", ipu_index);
        return;
    }

    rdata = reg32_read(ID_addr);
    rdata &= ~ID_mask;
    rdata |= (data * (ID_mask & -ID_mask)) & ID_mask;
    reg32_write(ID_addr, rdata);
}

/*!
 * enable submodules of IPU to establish the data path.
 *
 * @param	ipu_index:	ipu index
 */
void ipu_enable_display(int ipu_index)
{
    /*enable all the related submodules. */
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI0_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DP_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DC_EN, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DMFC_EN, 1);
}

/*!
 * disable submodules of IPU to establish the data path.
 *
 * @param	ipu_index:	ipu index
 */
void ipu_disable_display(int ipu_index)
{
    /*enable all the related submodules. */
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI0_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DI1_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DP_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DC_EN, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__DMFC_EN, 0);
}

/*!
 * reset ipu by SRC(system reset controller)
 *
 * @param	ipu_index:	ipu index
 * @param	timeout:    time out setting for ipu reset
 *
 * @return	true for success, others for time out.
 */
int ipu_sw_reset(int ipu_index, int timeout)
{
    uint32_t tmpVal;
    int ipuOffset = 0x3;

    if (ipu_index == 1)
        ipuOffset = 0x3;
    else
        ipuOffset = 0xC;
    tmpVal = readl(SRC_BASE_ADDR);
    writel(tmpVal | (0x1 << ipuOffset), SRC_BASE_ADDR);

    while (timeout > 0) {
        tmpVal = readl(SRC_BASE_ADDR) & (0x1 << ipuOffset);
        timeout--;

        if (tmpVal == 0)
            return true;
    }

    printf("Error: ipu software reset time out!!\n");
    return false;
}

/*!
 * display function HW configuration for IPU.
 *
 * @param   ipu_index:  ipu index
 * @param   panel:      ipu panel configuration data structure
 * @param   mem_colorimetry: colorimetry configuration
 * @param   csc_type: color space conversion type
 */
void ipu_display_setup(uint32_t ipu_index, ips_dev_panel_t * panel, uint32_t mem_colorimetry,
                       uint32_t csc_type)
{
    uint32_t channel = MEM_TO_DP_BG_CH23;
    uint32_t di = 0;
    //single image display
    //only config background idma
    ipu_disp_bg_idmac_config(ipu_index, panel->width, panel->height, mem_colorimetry);
    ipu_dmfc_config(ipu_index, channel);
    ipu_dc_config(ipu_index, channel, di, panel->width, panel->colorimetry);
    ipu_dp_config(ipu_index, csc_type, 0, 0, 0, 0);
    ipu_di_config(ipu_index, di, panel);
}

/*!
 * display function HW configuration for IPU.
 *
 * @param	ipu_index:	ipu index
 * @param	panel:		ipu panel configuration data structure
 * @param   mem_colorimetry: colorimetry configuration
 * @param   fg_width: foreground width
 * @param   fg_height: foreground height
 * @param   fg_xp: foreground x position
 * @param   fg_yp: foreground y position
 * @param   alpha: alpha value
 */
void ipu_dual_display_setup(uint32_t ipu_index, ips_dev_panel_t * panel, uint32_t mem_colorimetry,
                            uint32_t fg_width, uint32_t fg_height, uint32_t fg_xp, uint32_t fg_yp,
                            uint32_t alpha)
{
    uint32_t bg_channel = MEM_TO_DP_BG_CH23;
    uint32_t fg_channel = MEM_TO_DP_FG_CH27;
    uint32_t di = 0;

    //dual display: partial plane display
    //config both foreground and backgournd idma
    ipu_disp_fg_idmac_config(ipu_index, fg_width, fg_height, mem_colorimetry);
    ipu_disp_bg_idmac_config(ipu_index, panel->width, panel->height, mem_colorimetry);

    ipu_dmfc_config(ipu_index, fg_channel);
    ipu_dmfc_config(ipu_index, bg_channel);

    ipu_dc_config(ipu_index, bg_channel, di, panel->width, panel->colorimetry);
    //set the foreground position: in the middle of the screen and at the bottom of the screen.
    ipu_dp_config(ipu_index, NO_CSC, 1, fg_xp, fg_yp, alpha);
    ipu_di_config(ipu_index, di, panel);
}

/*! Set display parameters in IPU configuration structure according to your display panel name. There are only some displays are supported by this function. And you can set the display manually all by your self if the hardware is supported by IPU.
 *
 * @param panel_name:		panel name of your display
 */
ips_dev_panel_t *search_panel(char *panel_name)
{
    ips_dev_panel_t *panel = &disp_dev_list[0];
    int index = 0;

    while (index < num_of_panels) {
        if (!strcmp(panel->panel_name, panel_name))
            break;
        else {
            panel++;
            index++;
        }
    }

    if (index == num_of_panels) {
        printf("The display panel %s is not supported!\n", panel_name);
        return NULL;
    }

    return panel;
}
