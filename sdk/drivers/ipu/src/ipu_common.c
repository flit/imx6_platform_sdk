/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
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

inline int32_t need_csc(int32_t i, int32_t o)
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
void ipu_write_field(int32_t ipu_index, uint32_t ID_addr, uint32_t ID_mask, uint32_t data)
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
void ipu_enable_display(int32_t ipu_index)
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
void ipu_disable_display(int32_t ipu_index)
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
int32_t ipu_sw_reset(int32_t ipu_index, int32_t timeout)
{
    uint32_t tmpVal;
    int32_t ipuOffset = 0x3;

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
void ipu_display_setup(uint32_t ipu_index, uint32_t mem_addr0, uint32_t mem_addr1,
                       uint32_t mem_colorimetry, ips_dev_panel_t * panel)
{
    uint32_t channel = MEM_TO_DP_BG_CH23;
    uint32_t di = 0;
    uint32_t in_type, out_type, csc_type = NO_CSC;

    /*step1: determine CSC type according input colorimetry and output colorimetry */
    in_type = (mem_colorimetry == INTERLEAVED_RGB) ? RGB : YUV;
    switch (panel->colorimetry) {
    case DCMAP_YUV888:
    case DCMAP_UVY888:
    case DCMAP_VYU888:
    case DCMAP_YUVA8888:
        out_type = YUV;
        break;
    default:
        out_type = RGB;
        break;
    }

    if (in_type == RGB && out_type == YUV)
        csc_type = RGB_YUV;
    else if (in_type == YUV && out_type == RGB)
        csc_type = YUV_RGB;
    else
        csc_type = NO_CSC;

    /*step2: setup idma channel for background only */
    ipu_disp_bg_idmac_config(ipu_index, mem_addr0, mem_addr1, panel->width, panel->height,
                             mem_colorimetry);
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
    //config foreground idma
    ipu_disp_fg_idmac_config(ipu_index, CH27_EBA0, 0, fg_width, fg_height, mem_colorimetry);
    //config background idma
    ipu_disp_bg_idmac_config(ipu_index, CH23_EBA0, 0, panel->width, panel->height, mem_colorimetry);

    ipu_dmfc_config(ipu_index, fg_channel);
    ipu_dmfc_config(ipu_index, bg_channel);

    ipu_dc_config(ipu_index, bg_channel, di, panel->width, panel->colorimetry);
    //set the foreground position: in the middle of the screen and at the bottom of the screen.
    ipu_dp_config(ipu_index, NO_CSC, 1, fg_xp, fg_yp, alpha);
    ipu_di_config(ipu_index, di, panel);
}

void ipu_capture_setup(uint32_t ipu_index, uint32_t csi_interface, uint32_t raw_width, uint32_t raw_height, uint32_t act_width, uint32_t act_height, ips_dev_panel_t * panel)
{
    uint32_t csi_in_channel = CSI_TO_MEM_CH0, disp_channel = MEM_TO_DP_BG_CH23;
    ipu_idmac_info_t idmac_info;
    uint32_t csi_mem0 = CH23_EBA0, csi_mem1 = CH23_EBA1;
    uint32_t csi_pixel_format = NON_INTERLEAVED_YUV420;

    /*step1: config the csi: idma channel (csi -- mem), smfc, csi */
    memset(&idmac_info, 0, sizeof(ipu_idmac_info_t));
    idmac_info.channel = CSI_TO_MEM_CH0;
    idmac_info.addr0 = csi_mem0;
    idmac_info.addr1 = csi_mem1;
    idmac_info.width = act_width;
    idmac_info.height = act_height;
    idmac_info.pixel_format = csi_pixel_format;
	if (csi_interface == CSI_BT656_NTSC_INTERLACED || csi_interface == CSI_BT656_PAL_INTERLACED)
    	idmac_info.so = 1;
	else 
		idmac_info.so = 0;
    if (csi_pixel_format >= INTERLEAVED_RGB) {
        idmac_info.sl = panel->width * 2;
        idmac_info.u_offset = 0;
    } else {
        idmac_info.sl = panel->width;
        idmac_info.u_offset = panel->width * panel->height;
    }
    idmac_info.npb = 15;
    ipu_general_idmac_config(ipu_index, &idmac_info);

    /*step2: allocate smfc fifo for CSI input channel */
    ipu_smfc_fifo_allocate(ipu_index, 0, 0, 3);

    /*step3: config csi for IPU */
    ipu_csi_config(ipu_index, csi_interface, raw_width, raw_height, act_width, act_height);

    /*step4: config display channel: idma, dmfc, dc, dp, di */
    ipu_display_setup(ipu_index, csi_mem0, csi_mem1, csi_pixel_format, panel);

    /*step5: link csi and display */
    ipu_capture_disp_link(ipu_index, 0);

    /*step6: paint the other display area to white. */
    memset((void *)CH23_EBA0, 0xFF, panel->width * panel->height);
    memset((void *)(CH23_EBA0 + panel->width * panel->height), 0x80,
           panel->width * panel->height / 2);

    memset((void *)CH23_EBA1, 0xFF, panel->width * panel->height);
    memset((void *)(CH23_EBA1 + panel->width * panel->height), 0x80,
           panel->width * panel->height / 2);

    ipu_channel_buf_ready(ipu_index, csi_in_channel, 0);
    ipu_channel_buf_ready(ipu_index, csi_in_channel, 1);

    ipu_channel_buf_ready(ipu_index, disp_channel, 0);
    ipu_channel_buf_ready(ipu_index, disp_channel, 1);
}

void ipu_mipi_csi2_setup(uint32_t ipu_index, uint32_t csi_width, uint32_t csi_height,
                         ips_dev_panel_t * panel)
{
    uint32_t csi_in_channel = CSI_TO_MEM_CH0;
    ipu_idmac_info_t idmac_info;

    /*step1: config the csi: idma channel (csi -- mem), smfc, csi */

    /*setup idma background channel from MEM to display
       channel: 23
     */
    memset(&idmac_info, 0, sizeof(ipu_idmac_info_t));
    idmac_info.channel = csi_in_channel;
    idmac_info.addr0 = CH23_EBA0;
    idmac_info.addr1 = CH23_EBA1;
    idmac_info.width = csi_width;
    idmac_info.height = csi_height;
    idmac_info.pixel_format = PARTIAL_INTERLEAVED_YUV420;
    idmac_info.sl = panel->width;
    idmac_info.u_offset = panel->width * panel->height;
    idmac_info.npb = 15;
    ipu_general_idmac_config(ipu_index, &idmac_info);

    /*step2: allocate smfc fifo for CSI input channel */
    ipu_smfc_fifo_allocate(ipu_index, 0, 0, 3);

    /*step3: config csi for IPU */
    ipu_csi_config(ipu_index, CSI_MIPI, csi_width, csi_height, csi_width, csi_height);

    /*step4: config display channel: idma, dmfc, dc, dp, di */
    ipu_display_setup(ipu_index, CH23_EBA0, CH23_EBA1, PARTIAL_INTERLEAVED_YUV420, panel);

    /*step5: link csi and display */
    ipu_capture_disp_link(ipu_index, 0);


    /*step6: paint the other display area to white. */
    memset((void *)CH23_EBA0, 0xFF, 2 * panel->width * panel->height);
    memset((void *)(CH23_EBA0 + panel->width * panel->height), 0x80,
           panel->width * panel->height / 2);
    memset((void *)CH23_EBA1, 0xFF, 2 * panel->width * panel->height);
    memset((void *)(CH23_EBA1 + panel->width * panel->height), 0x80,
           panel->width * panel->height / 2);
}

/*! Set display parameters in IPU configuration structure according to your display panel name. There are only some displays are supported by this function. And you can set the display manually all by your self if the hardware is supported by IPU.
 *
 * @param panel_name:		panel name of your display
 */
ips_dev_panel_t *search_panel(char *panel_name)
{
    ips_dev_panel_t *panel = &disp_dev_list[0];
    int32_t index = 0;

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
