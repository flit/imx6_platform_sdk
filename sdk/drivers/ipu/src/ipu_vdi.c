/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * @file  ipu_vdi.c
 * @brief IPU Software Firmware, VDI is used for video de-interlacer. 
 * @ingroup diag_ipu
 */

#include "ipu/ipu_common.h"

int ipu_deinterlace_3_fields(int ipu_index)
{
    uint32_t reg;

    reg = ipu_read(ipu_index, IPU_VDI_C__ADDR);
    if (reg & VDI_C_MOT_SEL_FULL)
        return 0;
    else
        return 1;
}

/* selet the top field */
void ipu_vdi_set_top_field_man(int ipu_index, bool top_field_0)
{
    uint32_t reg;

    reg = ipu_read(ipu_index, IPU_VDI_C__ADDR);
    if (top_field_0)
        reg &= ~VDI_C_TOP_FIELD_MAN_1;
    else
        reg |= VDI_C_TOP_FIELD_MAN_1;
    ipu_write(ipu_index, IPU_VDI_C__ADDR, reg);
}

/*select the motion mode*/
void ipu_vdi_set_motion(int ipu_index, ips_motion_sel_e motion_sel)
{
    uint32_t reg;

    reg = ipu_read(ipu_index, IPU_VDI_C__ADDR);
    reg &= ~(VDI_C_MOT_SEL_FULL | VDI_C_MOT_SEL_MED | VDI_C_MOT_SEL_LOW);
    if (motion_sel == VDI_HIGH_MOTION)
        reg |= VDI_C_MOT_SEL_FULL;
    else if (motion_sel == VDI_MED_MOTION)
        reg |= VDI_C_MOT_SEL_MED;
    else
        reg |= VDI_C_MOT_SEL_LOW;

    ipu_write(ipu_index, IPU_VDI_C__ADDR, reg);
}

static void ipu_enable_vdi(int ipu_index)
{
    ipu_write_field(ipu_index, IPU_IPU_CONF__IC_INPUT, 1);
    ipu_write_field(ipu_index, IPU_IPU_CONF__VDI_EN, 1);
}

static void ipu_disable_vdi(int ipu_index)
{
    ipu_write_field(ipu_index, IPU_IPU_CONF__VDI_EN, 0);
}

/*!
 * ipu_vdi_init
 *
 * @param	ipu		ipu handler
 * @param	channel      IDMAC channel
 * @param	params	    vdi input parameters
 *
 * @return	Returns 0 on success or negative error code on fail
 */
void ipu_vdi_init(int ipu_index, int fmt, int field_mode, int width, int height,
                  ips_motion_sel_e motion_sel)
{
    uint32_t reg;
    uint32_t pixel_fmt;

    reg = ((height - 1) << 16) | (width - 1);
    ipu_write(ipu_index, IPU_VDI_FSIZE__ADDR, reg);

    /* Full motion, only vertical filter is used
       Burst size is 4 accesses */
    if (fmt == NON_INTERLEAVED_YUV420 || fmt == PARTIAL_INTERLEAVED_YUV420)
        pixel_fmt = VDI_C_CH_420;
    else
        pixel_fmt = VDI_C_CH_422;

    reg = ipu_read(ipu_index, IPU_VDI_C__ADDR);
    reg |= pixel_fmt;
    reg |= VDI_C_BURST_SIZE2_4;
    reg |= VDI_C_BURST_SIZE1_4 | VDI_C_VWM1_SET_1 | VDI_C_VWM1_CLR_2;
    reg |= VDI_C_BURST_SIZE3_4 | VDI_C_VWM3_SET_1 | VDI_C_VWM3_CLR_2;
    ipu_write(ipu_index, IPU_VDI_C__ADDR, reg);

    if (field_mode == IPS_FIELD_INTERLACED_TB)
        ipu_vdi_set_top_field_man(ipu_index, false);
    else if (field_mode == IPS_FIELD_INTERLACED_BT)
        ipu_vdi_set_top_field_man(ipu_index, true);

    ipu_vdi_set_motion(ipu_index, motion_sel);

    ipu_write_field(ipu_index, IPU_IC_CONF__RWS_EN, 0);

    ipu_enable_vdi(ipu_index);
}

void ipu_vdi_uninit(int ipu_index)
{
    ipu_write(ipu_index, IPU_VDI_FSIZE__ADDR, 0);
    ipu_write(ipu_index, IPU_VDI_C__ADDR, 0);

    ipu_disable_vdi(ipu_index);
}
