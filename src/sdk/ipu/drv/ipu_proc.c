/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_dc.c
 * @brief display controller configuration of IPU.
 * @ingroup diag_ipu
 */
#include <stdio.h>
#include <string.h>
#include "ipu_common.h"
#include "hardware.h"

extern inline int need_csc(int i, int o);

/*!
 * DC submodule configuration.
 * DC submodule is to control the data, and tranfer them to display.
 * @param	ipu_index:	ipu index
 * @param	conf:		ipu configuration data structure
 */
void ipu_dc_config(int ipu_index, ips_hw_conf_struct_t * conf)
{
    dc_microcode_t microcode = { 0 };
    uint32_t de_pointer = 1;

    microcode.addr = 1;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;
    microcode.waveform = de_pointer + 1;
    microcode.gluelogic = 0;
    microcode.sync = 5;
    ipu_dc_microcode_config(ipu_index, microcode);
    ipu_dc_microcode_event(ipu_index, 5, NEW_DATA, 1, 1);

    ipu_dc_microcode_event(ipu_index, 5, NL, 3, 2);
    ipu_dc_microcode_event(ipu_index, 5, EOL, 2, 3);

    /*new line event */
    microcode.addr = 2;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;
    microcode.waveform = de_pointer + 1;
    microcode.gluelogic = 8;
    microcode.sync = 5;
    ipu_dc_microcode_config(ipu_index, microcode);

    /*end of line event */
    microcode.addr = 3;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;
    microcode.waveform = de_pointer + 1;
    microcode.gluelogic = 4;
    microcode.sync = 5;
    ipu_dc_microcode_config(ipu_index, microcode);

    //WRITE_CHAN configuration
    ipu_dc_write_channel_config(ipu_index, 23, 2, conf->output.disp.di, 0);

    //DISP_CONF configuration
    ipu_dc_display_config(ipu_index, 2, 2 /*paralell */ , 0, conf->output.disp.width - 1);

    //DC_MAP configuration
    ipu_dc_map(ipu_index, 1, conf->output.disp.colorimetry);

}

/*
* config the write channel for display.
* different channels linked to different display port
*/
int ipu_dc_write_channel_config(int ipu_index, int dma_channel, int disp_port, int link_di_index,
                                int field_mode_enable)
{
    switch (dma_channel) {
    case 23:
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_START_TIME_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__CHAN_MASK_DEFAULT_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_CHAN_TYP_5, 4);    //Normal mode without anti-tearing
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DISP_ID_5, disp_port);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, link_di_index);

        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__W_SIZE_5, 2);   //Component size access to DC set to 24bit
        ipu_write_field(ipu_index, IPU_DC_WR_CH_ADDR_5__ST_ADDR_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__FIELD_MODE_5, field_mode_enable);

        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_1, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_5, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_1_6, 2);    //Channel 1 of the DC handless sync flow
        ipu_write_field(ipu_index, IPU_DC_GEN__MASK_EN, 0); // mask channel is disabled
        ipu_write_field(ipu_index, IPU_DC_GEN__DC_CH5_TYPE, 0); // alternate sync or asyn flow
        break;
    case 28:
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_START_TIME_1, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__CHAN_MASK_DEFAULT_1, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_CHAN_TYP_1, 4);    //Normal mode without anti-tearing
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_DISP_ID_1, disp_port);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_DI_ID_1, link_di_index);

        /* if CH28 is connected to DI0, CH23 must connect to DI1 even if it is not used. */
        if (link_di_index == 0)
            ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, 1);

        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__W_SIZE_1, 2);   //Component size access to DC set to 24bit
        ipu_write_field(ipu_index, IPU_DC_WR_CH_ADDR_1__ST_ADDR_1, 0);  //START ADDRESS OF CHANNEL
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__FIELD_MODE_1, field_mode_enable);

        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_1, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_1_6, 2);    //Channel 1 of the DC handless sync flow
        break;
    default:
        printf("Display channel wrong!\n");
        return -1;
    }

    return 0;
}

/*
*  config the display port in the DC
*/
int ipu_dc_display_config(int ipu_index, int display_port, int type, int increment, int strideline)
{
    switch (display_port) {
    case 0:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_0__DISP_TYP_0, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_0__ADDR_INCREMENT_0, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_0__SL_0, strideline);  //stride line
        break;
    case 1:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_1__DISP_TYP_1, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_1__ADDR_INCREMENT_1, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_1__SL_1, strideline);  //stride line
        break;
    case 2:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_2__DISP_TYP_2, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_2__ADDR_INCREMENT_2, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_2__SL_2, strideline);  //stride line
        break;
    case 3:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__DISP_TYP_3, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__ADDR_INCREMENT_3, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_3__SL_3, strideline);  //stride line
        break;
    default:
        printf("Display port wrong!\n");
        return false;
    }
    return true;
}

int ipu_dc_map(int ipu_index, int map, int format)
{
    int offset[3], mask[3];

    switch (format) {
    case DCMAP_RGB565:
        offset[0] = 15;
        mask[0] = 0xF8;
        offset[1] = 10;
        mask[1] = 0xFC;
        offset[2] = 4;
        mask[2] = 0xF8;
        break;
    case DCMAP_RGB666:
        offset[0] = 17;
        mask[0] = 0xFC;
        offset[1] = 11;
        mask[1] = 0xFC;
        offset[2] = 5;
        mask[2] = 0xFC;
        break;
    case DCMAP_RGB666H:
        offset[0] = 21;
        mask[0] = 0xFC;
        offset[1] = 13;
        mask[1] = 0xFC;
        offset[2] = 5;
        mask[2] = 0xFC;
        break;
    case DCMAP_RGB888:
    case DCMAP_YUV888:
        offset[0] = 23;
        mask[0] = 0xFF;
        offset[1] = 15;
        mask[1] = 0xFF;
        offset[2] = 7;
        mask[2] = 0xFF;
        break;
    case DCMAP_GBR888:
    case DCMAP_UVY888:
        offset[0] = 15;
        mask[0] = 0xFF;
        offset[1] = 7;
        mask[1] = 0xFF;
        offset[2] = 23;
        mask[2] = 0xFF;
        break;
    case DCMAP_BRG888:
    case DCMAP_VYU888:
        offset[0] = 7;
        mask[0] = 0xFF;
        offset[1] = 23;
        mask[1] = 0xFF;
        offset[2] = 15;
        mask[2] = 0xFF;
        break;
    default:
        printf("Unkown data type!!\n");
        return -1;
    }

    switch (map) {
    case 0:
        //DC_MAP, should be RGB666 mode
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_OFFSET_2, offset[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_MASK_2, mask[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_1, offset[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_1, mask[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_0, offset[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_0, mask[2]);

        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_0, 2);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_0, 1);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_0, 0);
        break;

    case 1:
        //DC_MAP
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_18__MD_OFFSET_6, offset[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_18__MD_MASK_6, mask[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_OFFSET_5, offset[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_MASK_5, mask[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_OFFSET_4, offset[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_MASK_4, mask[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_1, 6);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_1, 5);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_1, 4);
        break;

    default:
        printf("Map pointer not support yet!\n");
        return -1;
    }

    return 0;
}

/*
* microcode configuration, refer to ipuv3 spec
*/
void ipu_dc_microcode_config(int ipu_index, dc_microcode_t microcode)
{
    unsigned int LowWord = 0;
    unsigned int HighWord = 0;
    unsigned int opcode_fixed;
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    switch (microcode.opcode) {
    case HLG:
        LowWord = LowWord | (microcode.operand << 5);

        HighWord = HighWord | (microcode.operand >> 27);
        opcode_fixed = 0x0;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROD:
        /*write data to display */
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x18 | (microcode.lf << 1);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOAR:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8E | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROAR:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xCE | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLODR:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8C;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRODR:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xCC;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRBC:
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        opcode_fixed = 0x19B;
        HighWord = HighWord | (opcode_fixed << 0);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WCLK:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.mapping = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xC9;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSIII:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8B;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSII:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8A;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSI:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x89;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOA:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x14 | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROA:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x1C | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOD:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x10;
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRG:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.operand << 15);

        HighWord = HighWord | (microcode.operand >> 17);
        opcode_fixed = 1;
        HighWord = HighWord | (opcode_fixed << 7);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case RD:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x88;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WACK:
        microcode.mapping = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        opcode_fixed = 0x11A;
        HighWord = HighWord | (opcode_fixed << 0);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HMA:
        LowWord = LowWord | (microcode.operand << 5);
        opcode_fixed = 0x2;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case BMA:
        opcode_fixed = 0x3;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case MSK:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.operand << 15);

        HighWord = HighWord | (microcode.operand >> 17);
        opcode_fixed = 0xC8;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    default:
        printf("Wrong opcode type of DC!!\n");
        return;
    }

    writel(LowWord, ipu_base_addr + IPU_MEM_DC_MICROCODE_BASE_ADDR + microcode.addr * 8);
    writel(HighWord, ipu_base_addr + IPU_MEM_DC_MICROCODE_BASE_ADDR + microcode.addr * 8 + 4);
}

/*
* microcode event configuration, to handle different event
*/
void ipu_dc_microcode_event(int ipu_index, int channel, int event, int priority, int address)
{
    int channel_offset = (channel >= 5) ? (0x5C + (channel - 5) * 0x1C) : channel * 0x1C;

    switch (event) {
    case NL:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NL_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NL_PRIORITY_CHAN_0,
                        priority);
        break;

    case NF:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NF_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NF_PRIORITY_CHAN_0,
                        priority);
        break;

    case NFIELD:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_NFIELD_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_NFIELD_PRIORITY_CHAN_0,
                        priority);
        break;

    case DCEOF:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_EOF_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_EOF_PRIORITY_CHAN_0,
                        priority);
        break;

    case EOFIELD:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOFIELD_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOFIELD_PRIORITY_CHAN_0,
                        priority);
        break;

    case EOL:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOL_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOL_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_CHAN:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_CHAN_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_CHAN_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_ADDR:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_ADDR_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_ADDR_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_DATA:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL4_CH_0__COD_NEW_DATA_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL4_CH_0__COD_NEW_DATA_PRIORITY_CHAN_0,
                        priority);
        break;

    default:
        printf("Wrong DC microcode event!!\n");
        return;
    }

    return;
}

/*!
* this function is used to config the color space conversion task in the DP
* @param ipu_index: ipu index, 1 or 2
* @param dp: dp params index
* @param dp_csc_params: csc conversion matrix
*/
void ipu_dp_csc_config(int ipu_index, int dp, dp_csc_param_t dp_csc_params)
{
    int (*coeff)[3];
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_YUV_SAT_MODE_SYNC, 0);  //SAT mode is zero
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_GAMUT_SAT_EN_SYNC, 0);  //GAMUT en (RGB...)

    if (dp_csc_params.mode >= 0) {
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_DEF_SYNC, dp_csc_params.mode);  //disable CSC
    }

    coeff = (void *)dp_csc_params.coeff;

    if (coeff) {
        writel(GET_LSB(10, coeff[0][0]) | (GET_LSB(10, coeff[0][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[0][2]) | (GET_LSB(10, coeff[1][0]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_1__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[1][1]) | (GET_LSB(10, coeff[1][2]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_2__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[2][0]) | (GET_LSB(10, coeff[2][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_3__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[2][2]) | (GET_LSB(14, coeff[3][0]) << 16) |
               (coeff[4][0] << 30), ipu_base_addr + SRM_DP_CSC_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(14, coeff[3][1]) | (coeff[4][1] << 14) |
               (GET_LSB(14, coeff[3][2]) << 16) | (coeff[4][2] << 30),
               ipu_base_addr + SRM_DP_CSC_SYNC_1__ADDR + dp * 4);
    }

    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_S_SRM_MODE, 3);
    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_SRM_PRI, 0x0);
}

/*!
* this function is used to config the foreground plane for combination in the DP
* @param ipu_index: ipu index
* @param foreground_params: params for the foreground, including offset and size
*/
void ipu_dp_fg_config(int ipu_index, dp_fg_param_t foreground_params)
{
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_EN_SYNC, 0);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_YUV_EN_SYNC, 0);

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_COC_SYNC, foreground_params.cursorEnable);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWCKE_SYNC, foreground_params.colorKeyEnable);  //color key
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWAM_SYNC, foreground_params.alphaMode);    //1=global alpha,0=local alpha
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWSEL_SYNC, foreground_params.graphicSelect);   //1=graphic is FG,0=graphic is BG
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_FG_EN_SYNC, foreground_params.fgEnable);    //1=FG channel enabled,0=FG channel disabled
    ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGXP_SYNC, foreground_params.offsetHoriz);
    ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGYP_SYNC, foreground_params.offsetVert);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, foreground_params.opaque);    // set the FG opaque
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKR_SYNC, 0xFF);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKG_SYNC, 0xFF);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKB_SYNC, 0xFF);
}

/*!
 * config the DP module, mainly to perform blending, CSC and gamma correction
 * @param	ipu_index:	ipu index
 * @param	conf:		ipu configuration data structure
 */
void ipu_dp_config(int ipu_index, ips_hw_conf_struct_t * conf)
{
    dp_fg_param_t dpFGParam = { 0 };
    dp_csc_param_t dpCSCParam = { 0 };

    /*  Y = R *  .299 + G *  .587 + B *  .114;
       U = R * -.169 + G * -.332 + B *  .500 + 128.;
       V = R *  .500 + G * -.419 + B * -.0813 + 128.; */
    int rgb2ycbcr_coeff[5][3] = {
        {0x04D, 0x096, 0x01D},
        {0x3D5, 0x3AB, 0x080},
        {0x080, 0x395, 0x3EB},
        {0x0000, 0x0200, 0x0200},
        {0x2, 0x2, 0x2},
    };

    /* R = (1.164 * (Y - 16)) + (1.596 * (Cr - 128));
       G = (1.164 * (Y - 16)) - (0.392 * (Cb - 128)) - (0.813 * (Cr - 128));
       B = (1.164 * (Y - 16)) + (2.017 * (Cb - 128); */
    int ycbcr2rgb_coeff[5][3] = {
        {0x4A, 0x0, 0x66},
        {0x4A, 0x3E7, 0x3CC},
        {0x4A, 0x81, 0x0},
        {0x3F22, 0x85, 0x3EEB}, // A0, A1, A2
        {0x0, 0x0, 0x0},        /*S0,S1,S2 */
    };

    dpFGParam.fgEnable = 0;
    dpFGParam.cursorEnable = 0;
    dpFGParam.colorKeyEnable = 0;
    dpFGParam.offsetHoriz = 0;
    dpFGParam.offsetVert = 0;
    dpFGParam.alphaMode = 1;    // 1-  global alpha
    dpFGParam.graphicSelect = 0;    // graphic is forground
    dpFGParam.opaque = 0x30;    //show background

    ipu_dp_fg_config(ipu_index, dpFGParam);

    /********************************************
    00	CSC disable
    01	CSC enable after combining
    10	CSC enable before combining on BG channel
    11	CSC enable before combining on FG channel
    *******************************************/
    if (need_csc(conf->input.layer[0].colorimetry, conf->output.disp.colorimetry)) {
        dpCSCParam.mode = 2;
        if (conf->input.layer[0].colorimetry == INTERLEAVED_RGB)
            dpCSCParam.coeff = (int **)rgb2ycbcr_coeff;
        else
            dpCSCParam.coeff = (int **)ycbcr2rgb_coeff;
    } else {
        dpCSCParam.mode = 0;
    }

    ipu_dp_csc_config(ipu_index, 0, dpCSCParam);
}

/*!
 * enable IC submodule
 *
 * @param	ipu_index:	ipu index
 * @param	ic_enable:	enable IC
 * @param	ic_enable:	enable IRT
 */
void ipu_ic_enable(int ipu_index, int ic_enable, int irt_enable)
{
    ipu_write_field(ipu_index, IPU_IPU_CONF__IC_EN, ic_enable);
    ipu_write_field(ipu_index, IPU_IPU_CONF__IRT_EN, irt_enable);
}

/*
* this function is used to config the rotation/resizing task perform by the Image Converter
*/
void ipu_ic_task_config(int ipu_index, ipu_task_params_t task_params)
{
    int resCoff = 0, downsCoff = 0;

    switch (task_params.taskType) {
    case PrP_ENC_TASK:
        ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_EN, 0);
        ipu_write_field(ipu_index, IPU_IC_CONF__RWS_EN, 1);
        ipu_write_field(ipu_index, IPU_IC_CONF__CSI_MEM_WR_EN, 0);
        ipu_write_field(ipu_index, IPU_IPU_FS_PROC_FLOW1__ENC_IN_VALID, 1);

        if (task_params.resInfo.inWidth % 16 == 0) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB0_BURST_16, 1);    // set to 16bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB6_BURST_16, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB0_BURST_16, 0);    // set to 8bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB6_BURST_16, 0);
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_ROT_EN, task_params.rotEnable);

        /* set rotation task */
        if (task_params.rotEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T1_FLIP_LR, task_params.rotInfo.HorizFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T1_FLIP_UD, task_params.rotInfo.VertFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T1_ROT, task_params.rotInfo.rotation);
        }

        /* set resizing task */
        if (task_params.resEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_2__T1_FR_HEIGHT,
                            task_params.resInfo.outHeight - 1);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_3__T1_FR_WIDTH,
                            task_params.resInfo.outWidth - 1);

            ipu_ic_calc_resize_coeffs(task_params.resInfo.inWidth, task_params.resInfo.outWidth,
                                      &resCoff, &downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_ENC_RSC__PRPENC_DS_R_H, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_ENC_RSC__PRPENC_RS_R_H, resCoff);
            ipu_ic_calc_resize_coeffs(task_params.resInfo.inHeight, task_params.resInfo.outHeight,
                                      &resCoff, &downsCoff);

            ipu_write_field(ipu_index, IPU_IC_PRP_ENC_RSC__PRPENC_DS_R_V, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_ENC_RSC__PRPENC_RS_R_V, resCoff);
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_EN, 1);
        break;

    case PrP_VF_TASK:
        ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_EN, 0);
        ipu_write_field(ipu_index, IPU_IC_CONF__RWS_EN, 1);
        ipu_write_field(ipu_index, IPU_IC_CONF__CSI_MEM_WR_EN, 0);
        ipu_write_field(ipu_index, IPU_IPU_FS_PROC_FLOW1__VF_IN_VALID, 1);

        if (task_params.resInfo.inWidth % 16 == 0) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB1_BURST_16, 1);    // set to 16bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB6_BURST_16, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB1_BURST_16, 0);    // set to 8bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB6_BURST_16, 0);
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_ROT_EN, task_params.rotEnable);

        // set rotation
        if (task_params.rotEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T2_FLIP_LR, task_params.rotInfo.HorizFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T2_FLIP_UD, task_params.rotInfo.VertFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T2_ROT, task_params.rotInfo.rotation);
        }
        // set resizing
        if (task_params.resEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_2__T2_FR_HEIGHT,
                            task_params.resInfo.outHeight - 1);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_3__T2_FR_WIDTH,
                            task_params.resInfo.outWidth - 1);
            ipu_ic_calc_resize_coeffs(task_params.resInfo.inWidth, task_params.resInfo.outWidth,
                                      &resCoff, &downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_VF_RSC__PRPVF_DS_R_H, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_VF_RSC__PRPVF_RS_R_H, resCoff);
            ipu_ic_calc_resize_coeffs(task_params.resInfo.inHeight, task_params.resInfo.outHeight,
                                      &resCoff, &downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_VF_RSC__PRPVF_DS_R_V, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PRP_VF_RSC__PRPVF_RS_R_V, resCoff);
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_EN, 1);
        break;

    case PP_TASK:
        ipu_write_field(ipu_index, IPU_IC_CONF__PP_EN, 0);

        if (task_params.resInfo.inWidth % 16 == 0) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB2_BURST_16, 1);    // set to 16bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB5_BURST_16, 1);
        } else {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB2_BURST_16, 0);    // set to 8bps
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB5_BURST_16, 0);
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PP_EN, 1);
        ipu_write_field(ipu_index, IPU_IC_CONF__PP_ROT_EN, task_params.rotEnable);

        // set rotation
        if (task_params.rotEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T3_FLIP_LR, task_params.rotInfo.HorizFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T3_FLIP_UD, task_params.rotInfo.VertFlip);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_1__T3_ROT, task_params.rotInfo.rotation);
        }
        // set resizing
        if (task_params.resEnable) {
            ipu_write_field(ipu_index, IPU_IC_IDMAC_2__T3_FR_HEIGHT,
                            task_params.resInfo.outHeight - 1);
            ipu_write_field(ipu_index, IPU_IC_IDMAC_3__T3_FR_WIDTH,
                            task_params.resInfo.outWidth - 1);

            ipu_ic_calc_resize_coeffs(task_params.resInfo.inWidth, task_params.resInfo.outWidth,
                                      &resCoff, &downsCoff);

            ipu_write_field(ipu_index, IPU_IC_PP_RSC__PP_DS_R_H, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PP_RSC__PP_RS_R_H, resCoff);
            ipu_ic_calc_resize_coeffs(task_params.resInfo.inHeight, task_params.resInfo.outHeight,
                                      &resCoff, &downsCoff);

            ipu_write_field(ipu_index, IPU_IC_PP_RSC__PP_DS_R_V, downsCoff);
            ipu_write_field(ipu_index, IPU_IC_PP_RSC__PP_RS_R_V, resCoff);  // FROM (1536/2 -1)->479 *8192 = 13117
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PP_EN, 1);
        break;
    default:
        printf("Task type is wrong, IC task configuration failed\n");
        return;
    }
}

/*
* this function is used to calculate the params for resizing
*/
int ipu_ic_calc_resize_coeffs(int in_size, int out_size, int *resize_coeff, int *downsize_coeff)
{
    int tempSize;
    int tempDownsize;

    /* Cannot downsize more than 8:1 */
    if ((out_size << 3) < in_size)
        return -1;

    /* compute downsizing coefficient */
    tempDownsize = 0;
    tempSize = in_size;

    while (((tempSize >= out_size * 2) || (tempSize > 1024))
           && (tempDownsize < 2)) {
        tempSize >>= 1;
        tempDownsize++;
    }

    *downsize_coeff = tempDownsize;

    /* compute resizing coefficient using the following equation:
       resizeCoeff = M*(SI -1)/(SO - 1)
       where M = 2^13, SI - input size, SO - output size    */
    *resize_coeff = (8192L * (tempSize - 1)) / (out_size - 1);

    if (*resize_coeff >= 16384L) {
        printf("Overflow on resize coeff %d.\n", *resize_coeff);
        *resize_coeff = 0x3FFF;
    }

    return 0;
}

/*
* this function is used to set the resizing parameters
*/
int ipu_ic_config_resize_rate(int ipu_index, char *task_type, unsigned int res_vert,
                              unsigned int down_vert, unsigned int res_horiz,
                              unsigned int down_horiz)
{
    unsigned int val;
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    val = (down_vert << 30) | (res_vert << 16) | (down_horiz << 14) | (res_horiz);

    if (!strcmp(task_type, "PPTASK")) {
        writel(val, ipu_base_addr + IPU_IC_PP_RSC__ADDR);
    } else if (!strcmp(task_type, "VFTASK")) {
        writel(val, ipu_base_addr + IPU_IC_PRP_VF_RSC__ADDR);
    } else if (!strcmp(task_type, "PrPTASK")) {
        writel(val, ipu_base_addr + IPU_IC_PRP_ENC_RSC__ADDR);
    } else {
        printf("Task type is not defined!\n");
        return -1;
    }

    return 0;
}

/*
* this function is used to calculate the output size for IC resizing task
*/
void ipu_ic_calc_vout_size(int ipu_index, ipu_res_info_t * info, ips_hw_conf_struct_t * conf,
                           int rotation, int full_screen_enable)
{
    float coffHeight, coffWidth;

    /*if rotation is enabled, swap the width and height */
    if (rotation) {
        coffWidth = (float)(conf->output.disp.height) / info->inWidth;
        coffHeight = (float)(conf->output.disp.width) / info->inHeight;
    } else {
        coffWidth = (float)(conf->output.disp.width) / info->inWidth;
        coffHeight = (float)(conf->output.disp.height) / info->inHeight;
    }

    /* the resizing ratio should be the same in both width and height */
    if (coffWidth >= coffHeight) {
        info->outWidth = info->inWidth * coffHeight;
        info->outHeight = info->inHeight * coffHeight;
    } else {
        info->outWidth = info->inWidth * coffWidth;
        info->outHeight = info->inHeight * coffWidth;
    }

    if (full_screen_enable) {
        if (rotation) {
            info->outWidth = conf->output.disp.height;
            info->outHeight = conf->output.disp.width;
        } else {
            info->outWidth = conf->output.disp.width;
            info->outHeight = conf->output.disp.height;
        }
    }

    /* the output of IPU resizing is up to 1024*1024 */
    info->xSplitParts = (info->outWidth - 1) / 1024 + 1;
    info->ySplitParts = (info->outHeight - 1) / 1024 + 1;

    /* the image in block mode, which is 16*16 size */
    info->outWidth -=
        (16 * info->xSplitParts - 1) - (info->outWidth - 1) % (16 * info->xSplitParts);

}

/*
* this function is used to config the combination task in the IC
* local alpha with per-pixel or from separate buffer can be used
* global alpha can be used also.
*/
int ipu_ic_combine_config(int ipu_index, ic_comb_params_t comb_params)
{
    switch (comb_params.taskType) {
    case PrP_VF_TASK:
        ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB3_BURST_16, 1);    // set to 16bps

        if (comb_params.alpha > 0 && comb_params.alpha < 0x100) {
            ipu_write_field(ipu_index, IPU_IC_CONF__IC_GLB_LOC_A, 1);   // global alpha enabled
            ipu_write_field(ipu_index, IPU_IC_CMBP_1__IC_PRPVF_ALPHA_V, comb_params.alpha); // global alpha value
        } else {
            ipu_write_field(ipu_index, IPU_IC_CONF__IC_GLB_LOC_A, 0);   // local alpha from separate buffer
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CMB, (comb_params.alpha == 0) ? 0 : 1);
        ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_EN, 1);
        break;
    case PP_TASK:
        ipu_write_field(ipu_index, IPU_IC_IDMAC_1__CB4_BURST_16, 1);    // set to 16bps

        if (comb_params.alpha > 0 && comb_params.alpha < 0x100) {
            ipu_write_field(ipu_index, IPU_IC_CONF__IC_GLB_LOC_A, 1);   // global alpha enabled
            ipu_write_field(ipu_index, IPU_IC_CMBP_1__IC_PP_ALPHA_V, comb_params.alpha);    // global alpha
        } else {
            ipu_write_field(ipu_index, IPU_IC_CONF__IC_GLB_LOC_A, 0);   // local alpha in sepatate buffer
        }

        ipu_write_field(ipu_index, IPU_IC_CONF__PP_CMB, (comb_params.alpha == 0) ? 0 : 1);
        ipu_write_field(ipu_index, IPU_IC_CONF__PP_EN, 1);
        break;
    default:
        printf("Task Type is wrong!!\n");
        return -1;
    }

    return 0;
}

/*
* this function is used to config the color space conversion task in the IC
*/
int ipu_ic_csc_config(int ipu_index, int csc_set_index, ic_csc_params_t csc_params)
{
    unsigned int param;
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    unsigned int tpmBaseAddr = ipu_base_addr + TPM_BASE_OFFSET;
    unsigned int *base = NULL;

    if (csc_set_index != 1 && csc_set_index != 2) {
        printf("Wrong index input for IC CSC!!\n");
        return -1;
    }

    /*Y = R *  .299 + G *  .587 + B *  .114;
       U = R * -.169 + G * -.332 + B *  .500 + 128.;
       V = R *  .500 + G * -.419 + B * -.0813 + 128.; */
    unsigned int rgb2ycbcr_coeff[4][3] = {
        {0x004D, 0x0096, 0x001D},
        {0x01D5, 0x01AB, 0x0080},
        {0x0080, 0x0195, 0x01EB},
        {0x0000, 0x0200, 0x0200},   /* A0, A1, A2 */
    };

    /* transparent RGB->RGB matrix for combining
     */
    unsigned int rgb2rgb_coeff[4][3] = {
        {0x0080, 0x0000, 0x0000},
        {0x0000, 0x0080, 0x0000},
        {0x0000, 0x0000, 0x0080},
        {0x0000, 0x0000, 0x0000},   /* A0, A1, A2 */
    };

    /*
       R = (1.164 * (Y - 16)) + (1.596 * (Cr - 128));
       G = (1.164 * (Y - 16)) - (0.392 * (Cb - 128)) - (0.813 * (Cr - 128));
       B = (1.164 * (Y - 16)) + (2.017 * (Cb - 128);
     */
    unsigned int ycbcr2rgb_coeff[4][3] = {
        {0x95, 0x0, 0xCC},
        {0x95, 0x1CE, 0x198},
        {0x95, 0xFF, 0x0},
        {0x1E42, 0x10A, 0x1DD6},    // A0, A1, A2
    };

    /*
       R = (1.164 * alpha *  (Y - 16)) + (1.596 * (Cr - 128));
       G = (1.164 * alpha * (Y - 16)) - (0.392 * (Cb - 128)) - (0.813 * (Cr - 128));
       B = (1.164 * alpha * (Y - 16)) + (2.017 * (Cb - 128);
     */
    if (csc_set_index == 1) {
        if (csc_params.taskType == PrP_ENC_TASK) {
            base = (void *)(tpmBaseAddr + 0x2008);
        } else if (csc_params.taskType == PrP_VF_TASK) {
            base = (void *)(tpmBaseAddr + 0x4028);
        } else if (csc_params.taskType == PP_TASK) {
            base = (void *)(tpmBaseAddr + 0x6060);
        } else {
            printf("Wrong task type for IC CSC1 input!!\n");
            return -1;
        }
    } else {
        if (csc_params.taskType == PrP_VF_TASK) {
            base = (void *)(tpmBaseAddr + 0x4040);
        } else if (csc_params.taskType == PP_TASK) {
            base = (void *)(tpmBaseAddr + 0x6078);
        } else {
            printf("Wrong task type for IC CSC2 input!!\n");
            return -1;
        }
    }

    if ((csc_params.inFormat == YUV) && (csc_params.outFormat == RGB)) {
        /* Init CSC (YCbCr->RGB) */
        param = (ycbcr2rgb_coeff[3][0] << 27) |
            (ycbcr2rgb_coeff[0][0] << 18) | (ycbcr2rgb_coeff[1][1] << 9) | ycbcr2rgb_coeff[2][2];
        writel(param, base++);
        /* scale = 2, sat = 0 */
        param = (ycbcr2rgb_coeff[3][0] >> 5) | (2 << (40 - 32));
        writel(param, base++);

        param = (ycbcr2rgb_coeff[3][1] << 27) |
            (ycbcr2rgb_coeff[0][1] << 18) | (ycbcr2rgb_coeff[1][0] << 9) | ycbcr2rgb_coeff[2][0];
        writel(param, base++);
        param = (ycbcr2rgb_coeff[3][1] >> 5);
        writel(param, base++);

        param = (ycbcr2rgb_coeff[3][2] << 27) |
            (ycbcr2rgb_coeff[0][2] << 18) | (ycbcr2rgb_coeff[1][2] << 9) | ycbcr2rgb_coeff[2][1];
        writel(param, base++);
        param = (ycbcr2rgb_coeff[3][2] >> 5);
        writel(param, base++);
    } else if ((csc_params.inFormat == RGB) && (csc_params.outFormat == YUV)) {
        /* Init CSC1 (RGB->YCbCr) */
        param = (rgb2ycbcr_coeff[3][0] << 27) |
            (rgb2ycbcr_coeff[0][0] << 18) | (rgb2ycbcr_coeff[1][1] << 9) | rgb2ycbcr_coeff[2][2];
        writel(param, base++);
        /* scale = 1, sat = 0 */
        param = (rgb2ycbcr_coeff[3][0] >> 5) | (1UL << 8);
        writel(param, base++);

        param = (rgb2ycbcr_coeff[3][1] << 27) |
            (rgb2ycbcr_coeff[0][1] << 18) | (rgb2ycbcr_coeff[1][0] << 9) | rgb2ycbcr_coeff[2][0];
        writel(param, base++);
        param = (rgb2ycbcr_coeff[3][1] >> 5);
        writel(param, base++);

        param = (rgb2ycbcr_coeff[3][2] << 27) |
            (rgb2ycbcr_coeff[0][2] << 18) | (rgb2ycbcr_coeff[1][2] << 9) | rgb2ycbcr_coeff[2][1];
        writel(param, base++);
        param = (rgb2ycbcr_coeff[3][2] >> 5);
        writel(param, base++);
    } else if (((csc_params.inFormat == RGB) && (csc_params.outFormat == RGB))
               || ((csc_params.inFormat == YUV) && (csc_params.outFormat == YUV))) {
        /* Init CSC1 */
        param =
            (rgb2rgb_coeff[3][0] << 27) | (rgb2rgb_coeff[0][0] << 18) |
            (rgb2rgb_coeff[1][1] << 9) | rgb2rgb_coeff[2][2];
        writel(param, base++);
        /* scale = 2, sat = 0 */
        param = (rgb2rgb_coeff[3][0] >> 5) | (2UL << 8);
        writel(param, base++);

        param =
            (rgb2rgb_coeff[3][1] << 27) | (rgb2rgb_coeff[0][1] << 18) |
            (rgb2rgb_coeff[1][0] << 9) | rgb2rgb_coeff[2][0];
        writel(param, base++);
        param = (rgb2rgb_coeff[3][1] >> 5);
        writel(param, base++);

        param =
            (rgb2rgb_coeff[3][2] << 27) | (rgb2rgb_coeff[0][2] << 18) |
            (rgb2rgb_coeff[1][2] << 9) | rgb2rgb_coeff[2][1];
        writel(param, base++);
        param = (rgb2rgb_coeff[3][2] >> 5);
        writel(param, base++);
    } else {
        printf("Unkown color space conversion!!\n");
        return -1;
    }

    if (csc_set_index == 1) {
        if (csc_params.taskType == PrP_ENC_TASK) {
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_CSC1, 1);
        } else if (csc_params.taskType == PrP_VF_TASK) {
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CSC1, 1);
        } else if (csc_params.taskType == PP_TASK) {
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_CSC1, 1);
        } else {
            printf("Wrong Task input!!\n");
            return -1;
        }
    } else {
        if (csc_params.taskType == PrP_VF_TASK) {
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CSC2, 1);
        } else if (csc_params.taskType == PP_TASK) {
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_CSC2, 1);
        } else {
            printf("Wrong Task input!!\n");
            return -1;
        }
    }

    return 0;
}

/*
* enable ipu tasks, such as preprocessing/post-processing task
*/
int ipu_ic_task_enable(int ipu_index, int task_type, int task, int enable)
{
    switch (task_type) {
    case PrP_ENC_TASK:

        if (task == IC_CSC1)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_CSC1, enable);
        else if (IC_PRPENC)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPENC_EN, enable);
        else
            printf("Task Type is wrong!!\n");

        break;
    case PrP_VF_TASK:

        if (task == IC_CMB)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CMB, enable);
        else if (task == IC_CSC1)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CSC1, enable);
        else if (task == IC_CSC2)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_CSC2, enable);
        else if (task == IC_PRPVF)
            ipu_write_field(ipu_index, IPU_IC_CONF__PRPVF_EN, enable);
        else
            printf("Task Type is wrong!!\n");

        break;
    case PP_TASK:

        if (task == IC_CMB)
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_CMB, enable);
        else if (task == IC_CSC1)
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_CSC1, enable);
        else if (task == IC_CSC2)
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_CSC2, enable);
        else if (task == IC_PP)
            ipu_write_field(ipu_index, IPU_IC_CONF__PP_EN, enable);
        else
            printf("Task Type is wrong!!\n");

        break;
    default:
        printf("Task Type is wrong!!\n");
        return -1;
    }

    return 0;
}
