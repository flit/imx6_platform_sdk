/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file ipu_csi.c
 * @brief camera interface configuration of IPU.
 * @ingroup diag_ipu
 */

#include <string.h>
#include "ipu/ipu_common.h"

/*
 * set the CSI module to handle data from camera
 * @param width: frame width of camera input
 * @param height: frame height of camera input
 */
void ipu_csi_config(uint32_t ipu_index, uint32_t source, uint32_t width, uint32_t height,
                    uint32_t data_format, uint32_t gate_mode)
{
    uint32_t csiVSC = 0, csiHSC = 0;
    uint32_t csiBottomSkip = 0, csiRightSkip = 0;
    uint32_t csiFrameHeight = height, csiFrameWidth = width;

    /* setting CSI data source, default is from parallel interface */
    if (source == CSI_PARALLEL) {
        ipu_write_field(ipu_index, IPU_IPU_CONF__CSI1_DATA_SOURCE, 0);  //csi1 data source is parallel
        ipu_write_field(ipu_index, IPU_IPU_CONF__CSI0_DATA_SOURCE, 0);  //csi0 data souce is parallel
    } else if (source == CSI_MIPI) {
        ipu_write_field(ipu_index, IPU_IPU_CONF__CSI1_DATA_SOURCE, 1);  //csi1 data source is mipi
        ipu_write_field(ipu_index, IPU_IPU_CONF__CSI0_DATA_SOURCE, 1);  //csi0 data souce is mipi
    }

    ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_DATA_DEST, 4);  //destination is IDMAC
    ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_SENS_PRTCL, gate_mode); // Gated clock mode
    ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_DIV_RATIO, 0);  //division ratio of HSP_CLK into SENSOR_MCLK
    ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_DATA_WIDTH, 1); //8bits per color
    ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_PACK_TIGHT, 0); //only when data format is RGB/YUV, and data_width > 8

    /* data format setting */
    if (source == CSI_PARALLEL) {
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_SENS_DATA_FORMAT, data_format); // YUV422
    } else if (source == CSI_MIPI) {
        switch (data_format) {
        case CSI_UYVY:
            ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI0, 0x1E);   //(UYVY)MIPI_YUV422 8bit
            break;
        case CSI_RGB565:
            ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI0, 0x22);   //MIPI_RGB565
            break;
        case CSI_RGB555:
            ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI0, 0x21);   //MIPI_RGB555
            break;
        case CSI_RGB444:
            ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI0, 0x20);   //MIPI_RGB565
            break;
        default:
            printf("\nThispixel format is not supported by MIPI_CSI2!\n");
            return;
        }
        /*using CSI0_MIPI_DI0 by default, DI1~3 unused */
        ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI1, 0);
        ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI2, 0);
        ipu_write_field(ipu_index, IPU_CSI0_DI__CSI0_MIPI_DI3, 0);
    } else {
        printf("\nWrong interface! Only Parallel and MIPI is supported!\n");
        return;
    }

    /* set parallel interface information */
    if (source == CSI_PARALLEL) {
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_DATA_EN_POL, 0);
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_EXT_VSYNC, 1);
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_SENS_PIX_CLK_POL, 0);   // pos edge
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_DATA_POL, 0);
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_HSYNC_POL, 0);
        ipu_write_field(ipu_index, IPU_CSI0_SENS_CONF__CSI0_VSYNC_POL, 0);
    }

    /*CSI0 common sensor configuration for PApa */
    /*set sensor frame size */
    ipu_write_field(ipu_index, IPU_CSI0_SENS_FRM_SIZE__CSI0_SENS_FRM_HEIGHT, csiFrameHeight - 1);
    ipu_write_field(ipu_index, IPU_CSI0_SENS_FRM_SIZE__CSI0_SENS_FRM_WIDTH, csiFrameWidth - 1);

    /*CSI_ACT_FRM_SIZE */
    ipu_write_field(ipu_index, IPU_CSI0_ACT_FRM_SIZE__CSI0_ACT_FRM_HEIGHT,
                    (csiFrameHeight - 1 - csiVSC - csiBottomSkip));
    ipu_write_field(ipu_index, IPU_CSI0_ACT_FRM_SIZE__CSI0_ACT_FRM_WIDTH,
                    (csiFrameWidth - 1 - csiHSC - csiRightSkip));

    /*CSI_OUT_FRM_CTRL */
    ipu_write_field(ipu_index, IPU_CSI0_OUT_FRM_CTRL__CSI0_HORZ_DWNS, 0);
    ipu_write_field(ipu_index, IPU_CSI0_OUT_FRM_CTRL__CSI0_VERT_DWNS, 0);
    ipu_write_field(ipu_index, IPU_CSI0_OUT_FRM_CTRL__CSI0_HSC, csiHSC);
    ipu_write_field(ipu_index, IPU_CSI0_OUT_FRM_CTRL__CSI0_VSC, csiVSC);

    ipu_write_field(ipu_index, IPU_IPU_CONF__CSI_SEL, 0);
    ipu_write_field(ipu_index, IPU_IPU_CONF__CSI0_EN, 1);

    //???? mipi has IPU_CSI0_CPD_CTRL__ADDR
    ipu_write_field(ipu_index, IPU_CSI0_CPD_CTRL__CSI0_CPD, 0);
}

/*!
 * set the SMFC(fifo for camera input) property
 *
 * @param	ipu_index: ipu index
 * @param 	channel: select the channel number out of 0~3
 * @param 	map: choose the map between channel and fifo
 * @param 	burst_size: set the burst size of fifo input.
 *
 * @return -1 means channel not found, 0 means configuration is ok.
 */
uint32_t ipu_smfc_fifo_allocate(uint32_t ipu_index, uint32_t channel, uint32_t map,
                                uint32_t burst_size)
{
    switch (channel) {
    case 0:
        ipu_write_field(ipu_index, IPU_SMFC_MAP__MAP_CH0, map);
        ipu_write_field(ipu_index, IPU_SMFC_BS__BURST0_SIZE, burst_size);
        break;

    case 1:
        ipu_write_field(ipu_index, IPU_SMFC_MAP__MAP_CH1, map);
        ipu_write_field(ipu_index, IPU_SMFC_BS__BURST1_SIZE, burst_size);
        break;

    case 2:
        ipu_write_field(ipu_index, IPU_SMFC_MAP__MAP_CH2, map);
        ipu_write_field(ipu_index, IPU_SMFC_BS__BURST2_SIZE, burst_size);
        break;

    case 3:
        ipu_write_field(ipu_index, IPU_SMFC_MAP__MAP_CH3, map);
        ipu_write_field(ipu_index, IPU_SMFC_BS__BURST3_SIZE, burst_size);
        break;

    default:
        printf("Wrong channel selected!!\n");
        return -1;
    }

    ipu_write_field(ipu_index, IPU_IPU_CONF__SMFC_EN, 1);
    return 0;
}

/*!
 * link CSI channel smfc with display 
 *
 * @param	ipu_index: ipu index
 * @param 	smfc: select the smfc number out of 0/2
 *
 * @return -1 means channel not found, 0 means configuration is ok.
 */
void ipu_capture_disp_link(uint32_t ipu_index, uint32_t smfc)
{
    switch (smfc) {
    case 0:
        ipu_write_field(ipu_index, IPU_IPU_FS_PROC_FLOW3__SMFC0_DEST_SEL, 0x9); // smfc0 -> chan23
        ipu_write_field(ipu_index, IPU_IPU_FS_DISP_FLOW1__DP_SYNC0_SRC_SEL, 0x1);   // MG source from capture 0
        break;
    case 2:
        ipu_write_field(ipu_index, IPU_IPU_FS_PROC_FLOW3__SMFC2_DEST_SEL, 0x9); // smfc2 -> chan23
        ipu_write_field(ipu_index, IPU_IPU_FS_DISP_FLOW1__DP_SYNC0_SRC_SEL, 0x2);   // MG source from capture 2
        break;
    default:
        printf("Wrong smfc selected!!\n");
        break;
    }
}
