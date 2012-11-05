/*
 * Copyright (c) 2011-2012, Freescale Semiconductor, Inc.
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

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */

/*!
 * @file vpu_lib.c
 *
 * @brief This file implements codec API funcitons for VPU
 *
 * @ingroup VPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vpu/vpu_reg.h"
#include "vpu/vpu_lib.h"
#include "vpu/vpu_util.h"
#include "vpu/vpu_io.h"
#include "vpu/vpu_debug.h"
#include "vpu/vpu_gdi.h"
#include "timer/timer.h"

#define IMAGE_ENDIAN			0
#define STREAM_ENDIAN			0

uint32_t system_rev = 0x61 << 12;
extern const unsigned short bit_code[];

/* If a frame is started, pendingInst is set to the proper instance. */
static CodecInst **ppendingInst;

uint32_t virt_codeBuf;
uint32_t *virt_paraBuf;
uint32_t *virt_paraBuf2;

extern vpu_mem_desc bit_work_addr;
extern vpu_resource_t *vpu_hw_map;

static int32_t decoded_pictype[32];

/*!
 * @brief
 * This functure indicate whether processing(encoding/decoding) a frame
 * is completed or not yet.
 *
 * @return
 * @li 0: VPU hardware is idle.
 * @li Non-zero value: VPU hardware is busy processing a frame.
 */
int32_t VPU_IsBusy()
{
    int32_t vpu_busy;

    vpu_busy = VpuReadReg(BIT_BUSY_FLAG);

    return vpu_busy != 0;
}

int32_t VPU_WaitForInt(int32_t timeout_in_ms)
{
    hal_delay_us(timeout_in_ms * 10);

    return 0;
}

/*!
 * @brief VPU initialization.
 * This function initializes VPU hardware and proper data structures/resources.
 * The user must call this function only once before using VPU codec.
 *
 * @return  This function always returns RETCODE_SUCCESS.
 */
RetCode VPU_Init(void)
{
    int32_t i, err;
    volatile uint32_t data;
    PhysicalAddress tempBuffer, codeBuffer, paraBuffer;

    err = IOSystemInit();
    if (err) {
        err_msg("IOSystemInit() failure.\n");
        return RETCODE_FAILURE;
    }

    for (i = 0x100; i < 0x200; i += 4) {
        VpuWriteReg(i, 0x0);
    }

    codeBuffer = bit_work_addr.phy_addr;
    tempBuffer = codeBuffer + CODE_BUF_SIZE;
    paraBuffer = tempBuffer + TEMP_BUF_SIZE + PARA_BUF2_SIZE;

    virt_codeBuf = (uint32_t) (bit_work_addr.virt_uaddr);
    virt_paraBuf = (uint32_t *) (virt_codeBuf + CODE_BUF_SIZE + TEMP_BUF_SIZE + PARA_BUF2_SIZE);
    virt_paraBuf2 = (uint32_t *) (virt_codeBuf + CODE_BUF_SIZE + TEMP_BUF_SIZE);

    ppendingInst = (CodecInst **) (&(vpu_hw_map->pendingInst));

    if (!isVpuInitialized()) {
        if (DownloadBitCodeTable((uint32_t *) virt_codeBuf) != RETCODE_SUCCESS) {
            return RETCODE_FAILURE;
        }

        for (i = 0; i < 64; i++)
            VpuWriteReg(BIT_CODE_BUF_ADDR + (i * 4), 0);

        VpuWriteReg(BIT_PARA_BUF_ADDR, paraBuffer);
        VpuWriteReg(BIT_CODE_BUF_ADDR, codeBuffer);
        VpuWriteReg(BIT_TEMP_BUF_ADDR, tempBuffer);

        VpuWriteReg(BIT_BIT_STREAM_PARAM, 0);

        if (VpuReadReg(BIT_CUR_PC) != 0) {
            /* IRQ is disabled during shutdown */
            VpuWriteReg(BIT_INT_ENABLE, 1 << INT_BIT_PIC_RUN);
            return RETCODE_SUCCESS;
        }
        VpuWriteReg(BIT_CODE_RUN, 0);

        /* Download BIT Microcode to Program Memory */
        for (i = 0; i < 2048; ++i) {
            data = bit_code[i];
            VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data);
        }

        data = STREAM_ENDIAN | STREAM_FULL_EMPTY_CHECK_DISABLE << BIT_BUF_CHECK_DIS;
        data |= BUF_PIC_FLUSH << BIT_BUF_PIC_FLUSH | BUF_PIC_RESET << BIT_BUF_PIC_RESET;
        VpuWriteReg(BIT_BIT_STREAM_CTRL, data);
        VpuWriteReg(BIT_FRAME_MEM_CTRL, IMAGE_ENDIAN | 1 << 12);

        VpuWriteReg(BIT_INT_ENABLE, 1 << INT_BIT_PIC_RUN);
        VpuWriteReg(BIT_AXI_SRAM_USE, 0);   /* init to not use SRAM */

        VpuWriteReg(BIT_BUSY_FLAG, 1);
        VpuWriteReg(BIT_CODE_RUN, 1);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    return RETCODE_SUCCESS;
}

void VPU_UnInit(void)
{
    IOSystemShutdown();
}

RetCode VPU_SWReset(int32_t forcedReset)
{
    volatile int32_t i;
    uint32_t cmd;

    if (forcedReset == 0) {
        VpuWriteReg(GDI_BUS_CTRL, 0x11);
        while (VpuReadReg(GDI_BUS_STATUS) != 0x77) ;
        VpuWriteReg(GDI_BUS_CTRL, 0x00);
    }

    cmd = VPU_SW_RESET_BPU_CORE | VPU_SW_RESET_BPU_BUS;
    cmd |= VPU_SW_RESET_VCE_CORE | VPU_SW_RESET_VCE_BUS;
    VpuWriteReg(BIT_SW_RESET, cmd);
    for (i = 0; i < 50; i++) ;
    while (VpuReadReg(BIT_SW_RESET_STATUS) != 0) ;

    VpuWriteReg(BIT_SW_RESET, 0);
    return RETCODE_SUCCESS;
}

/*!
 * @brief Get VPU Firmware Version.
 */
RetCode VPU_GetVersionInfo(vpu_versioninfo * verinfo)
{
    uint32_t ver, fw_code = 0;
    uint16_t pn, version;
    RetCode ret = RETCODE_SUCCESS;
    char productstr[18] = { 0 };

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    VpuWriteReg(RET_VER_NUM, 0);

    BitIssueCommand(NULL, FIRMWARE_GET);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    ver = VpuReadReg(RET_VER_NUM);
    if (cpu_is_mx6q())
        fw_code = VpuReadReg(RET_FW_CODE_REV);

    if (ver == 0)
        return RETCODE_FAILURE;

    pn = (uint16_t) (ver >> 16);
    version = (uint16_t) ver;

    switch (pn) {
    case PRJ_CODAHX_14:
        strcpy(productstr, "i.MX51");
        break;
    case PRJ_CODA7541:
        strcpy(productstr, "i.MX53");
        break;
    case PRJ_CODA_960:
        strcpy(productstr, "i.MX6Q");
        break;
    default:
        err_msg("Unknown VPU\n");
        ret = RETCODE_FAILURE;
        break;
    }

    if (verinfo != NULL) {
        verinfo->fw_major = (version >> 12) & 0x0f;
        verinfo->fw_minor = (version >> 8) & 0x0f;
        verinfo->fw_release = version & 0xff;
        verinfo->fw_code = fw_code;
        info_msg("Product Info: %s\n", productstr);
    }

    return ret;
}

/*!
 * @brief VPU encoder initialization
 *
 * @param pHandle [Output] Pointer to EncHandle type
    where a handle will be written by which you can refer
    to an encoder instance. If no instance is available,
    null handle is returned via pHandle.
 *
 * @param pop  [Input] Pointer to EncOpenParam type
 * which describes parameters necessary for encoding.
 *
 * @return
 * @li RETCODE_SUCCESS: Success in acquisition of an encoder instance.
 * @li RETCODE_FAILURE: Failed in acquisition of an encoder instance.
 * @li RETCODE_INVALID_PARAM: pop is a null pointer, or some parameter
 * passed does not satisfy conditions described in the paragraph for
 * EncOpenParam type.
 */
RetCode VPU_EncOpen(EncHandle * pHandle, EncOpenParam * pop)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    int32_t instIdx;
    RetCode ret;
    uint32_t val;

    ret = CheckEncOpenParam(pop);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    ret = GetCodecInstance(&pCodecInst);
    if (ret == RETCODE_FAILURE) {
        *pHandle = 0;
        return RETCODE_FAILURE;
    }

    *pHandle = pCodecInst;
    instIdx = pCodecInst->instIndex;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    pCodecInst->contextBufMem.size = SIZE_CONTEXT_BUF;
    ret = IOGetMem(&pCodecInst->contextBufMem);
    if (ret) {
        err_msg("Unable to obtain physical mem\n");
        return RETCODE_FAILURE;
    }
    pEncInfo->openParam = *pop;

    pCodecInst->codecModeAux = 0;
    if ((pop->bitstreamFormat == STD_MPEG4) || (pop->bitstreamFormat == STD_H263))
        pCodecInst->codecMode = MP4_ENC;
    else if (pop->bitstreamFormat == STD_AVC)
        pCodecInst->codecMode = AVC_ENC;
    if (cpu_is_mx6q())
        pCodecInst->codecModeAux = pop->EncStdParam.avcParam.mvc_extension;
    else if (pop->bitstreamFormat == STD_MJPG)
        pCodecInst->codecMode = MJPG_ENC;

    pEncInfo->streamRdPtr = pop->bitstreamBuffer;
    pEncInfo->streamBufStartAddr = pop->bitstreamBuffer;
    pEncInfo->streamBufSize = pop->bitstreamBufferSize;
    pEncInfo->streamBufEndAddr = pop->bitstreamBuffer + pop->bitstreamBufferSize;
    pEncInfo->frameBufPool = 0;

    pEncInfo->rotationEnable = 0;
    pEncInfo->mirrorEnable = 0;
    pEncInfo->mirrorDirection = MIRDIR_NONE;
    pEncInfo->rotationAngle = 0;

    pEncInfo->initialInfoObtained = 0;
    pEncInfo->dynamicAllocEnable = pop->dynamicAllocEnable;
    pEncInfo->ringBufferEnable = pop->ringBufferEnable;
    pEncInfo->cacheConfig.Bypass = 1;   /* By default, turn off MC cache */
    pEncInfo->subFrameSyncConfig.subFrameSyncOn = 0;    /* By default, turn off SubFrameSync */
    pEncInfo->linear2TiledEnable = pop->linear2TiledEnable;
    pEncInfo->mapType = pop->mapType;

    /* MB Aligned source resolution */
    pEncInfo->srcFrameWidth = (pop->picWidth + 15) & ~15;
    pEncInfo->srcFrameHeight = (pop->picHeight + 15) & ~15;

    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = pEncInfo->streamRdPtr;
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = pEncInfo->streamBufStartAddr;

    if (instIdx == VpuReadReg(BIT_RUN_INDEX)) {

        VpuWriteReg(BIT_RD_PTR, pEncInfo->streamRdPtr);
        VpuWriteReg(BIT_WR_PTR, pEncInfo->streamBufStartAddr);
    }

    val = VpuReadReg(BIT_BIT_STREAM_CTRL);
    val &= ~BITS_STREAMCTRL_MASK;
    val |= (STREAM_ENDIAN | STREAM_FULL_EMPTY_CHECK_DISABLE << BIT_BUF_CHECK_DIS);
    if (pEncInfo->ringBufferEnable == 0) {
        if (!cpu_is_mx6q())
            val |= (pEncInfo->dynamicAllocEnable << BIT_ENC_DYN_BUFALLOC_EN);
        val |= 1 << BIT_BUF_PIC_RESET;
    } else
        val |= 1 << BIT_BUF_PIC_FLUSH;

    VpuWriteReg(BIT_BIT_STREAM_CTRL, val);

    val = VpuReadReg(BIT_FRAME_MEM_CTRL);
    val &= ~(1 << 2 | 0x7 << 9);    /* clear the bit firstly */
    if (pEncInfo->mapType)
        val |= pEncInfo->linear2TiledEnable << 11 | 0x03 << 9;

    pCodecInst->ctxRegs[CTX_BIT_FRAME_MEM_CTRL] = val | (pEncInfo->openParam.chromaInterleave << 2);

    if (cpu_is_mx6q())
        VpuWriteReg(GDI_WPROT_RGN_EN, 0);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Encoder system close.
 *
 * @param encHandle [Input] The handle obtained from vpu_EncOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful closing.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode VPU_EncClose(EncHandle handle)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    if (*ppendingInst == pCodecInst) {
        return RETCODE_FRAME_NOT_COMPLETE;
    }

    if (pEncInfo->initialInfoObtained) {
        BitIssueCommand(pCodecInst, SEQ_END);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    FreeCodecInstance(pCodecInst);

    return RETCODE_SUCCESS;
}

/*!
 * @brief user could allocate frame buffers
 * according to the information obtained from this function.
 * @param handle [Input] The handle obtained from VPU_EncOpen().
 * @param info [Output] The information required before starting
 * encoding will be put to the data structure pointed to by initialInfo.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_FAILURE There was an error in getting information and
 *                                    configuring the encoder.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished
 * @li RETCODE_INVALID_PARAM initialInfo is a null pointer.
 */
RetCode VPU_EncGetInitialInfo(EncHandle handle, EncInitialInfo * info)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    EncOpenParam *pEncOP;
    int32_t picWidth;
    int32_t picHeight;
    uint32_t data, *tableBuf;
    int32_t i;
    SetIramParam iramParam;
    RetCode ret;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;
    pEncOP = &pEncInfo->openParam;

    if (pEncInfo->initialInfoObtained) {
        return RETCODE_CALLED_BEFORE;
    }

    picWidth = pEncOP->picWidth;
    picHeight = pEncOP->picHeight;

    data = (picWidth << BIT_PIC_WIDTH_OFFSET) | picHeight;
    VpuWriteReg(CMD_ENC_SEQ_SRC_SIZE, data);
    VpuWriteReg(CMD_ENC_SEQ_SRC_F_RATE, pEncOP->frameRateInfo);

    if (pEncOP->bitstreamFormat == STD_MPEG4) {
        pEncInfo->mp4_dataPartitionEnable = pEncOP->EncStdParam.mp4Param.mp4_dataPartitionEnable;
        if (cpu_is_mx6q())
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 3);
        else
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 0);
        data = pEncOP->EncStdParam.mp4Param.mp4_intraDcVlcThr << 2 |
            pEncOP->EncStdParam.mp4Param.mp4_reversibleVlcEnable << 1 |
            pEncOP->EncStdParam.mp4Param.mp4_dataPartitionEnable;
        data |= ((pEncOP->EncStdParam.mp4Param.mp4_hecEnable > 0)
                 ? 1 : 0) << 5;
        data |= ((pEncOP->EncStdParam.mp4Param.mp4_verid == 2)
                 ? 0 : 1) << 6;
        VpuWriteReg(CMD_ENC_SEQ_MP4_PARA, data);
    } else if (pEncOP->bitstreamFormat == STD_H263) {
        if (cpu_is_mx6q())
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 11);
        data = pEncOP->EncStdParam.h263Param.h263_annexIEnable << 3 |
            pEncOP->EncStdParam.h263Param.h263_annexJEnable << 2 |
            pEncOP->EncStdParam.h263Param.h263_annexKEnable << 1 |
            pEncOP->EncStdParam.h263Param.h263_annexTEnable;
        VpuWriteReg(CMD_ENC_SEQ_263_PARA, data);
    } else if (pEncOP->bitstreamFormat == STD_AVC) {
        if (cpu_is_mx6q())
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 0);
        else
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 2);
        data = (pEncOP->EncStdParam.avcParam.avc_deblkFilterOffsetBeta &
                15) << 12 |
            (pEncOP->EncStdParam.avcParam.avc_deblkFilterOffsetAlpha
             & 15) << 8 |
            pEncOP->EncStdParam.avcParam.avc_disableDeblk << 6 |
            pEncOP->EncStdParam.avcParam.avc_constrainedIntraPredFlag
            << 5 | (pEncOP->EncStdParam.avcParam.avc_chromaQpOffset & 31);
        VpuWriteReg(CMD_ENC_SEQ_264_PARA, data);
    } else if ((!cpu_is_mx6q()) && pEncOP->bitstreamFormat == STD_MJPG) {
        VpuWriteReg(CMD_ENC_SEQ_JPG_PARA,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_sourceFormat);
        VpuWriteReg(CMD_ENC_SEQ_JPG_RST_INTERVAL,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_restartInterval);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_EN,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_thumbNailEnable);
        data =
            (pEncInfo->openParam.EncStdParam.mjpgParam.
             mjpg_thumbNailWidth) << 16 | (pEncInfo->openParam.
                                           EncStdParam.mjpgParam.mjpg_thumbNailHeight);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_SIZE, data);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_OFFSET, 0);

        tableBuf = (uint32_t *) pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_hufTable;
        for (i = 0; i < 108; i += 2) {
            virt_paraBuf[i + 1] = *tableBuf;
            virt_paraBuf[i] = *(tableBuf + 1);
            tableBuf += 2;
        }
        tableBuf = (uint32_t *) pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_qMatTable;
        for (i = 0; i < 48; i += 2) {
            virt_paraBuf[i + 129] = *tableBuf;
            virt_paraBuf[i + 128] = *(tableBuf + 1);
            tableBuf += 2;
        }
    }

    if (pEncOP->bitstreamFormat != STD_MJPG) {
        data = pEncOP->slicemode.sliceSize << 2 |
            pEncOP->slicemode.sliceSizeMode << 1 | pEncOP->slicemode.sliceMode;

        VpuWriteReg(CMD_ENC_SEQ_SLICE_MODE, data);
        VpuWriteReg(CMD_ENC_SEQ_GOP_NUM, pEncOP->gopSize);
    }

    if (pEncOP->bitRate) {      /* rate control enabled */
        data = pEncOP->initialDelay << 16 | pEncOP->bitRate << 1 | 1;
        if (cpu_is_mx6q())
            data |= (!pEncInfo->openParam.enableAutoSkip) << 31;
        VpuWriteReg(CMD_ENC_SEQ_RC_PARA, data);
    } else {
        VpuWriteReg(CMD_ENC_SEQ_RC_PARA, 0);
    }

    VpuWriteReg(CMD_ENC_SEQ_RC_BUF_SIZE, pEncOP->vbvBufferSize);
    VpuWriteReg(CMD_ENC_SEQ_INTRA_REFRESH, pEncOP->intraRefresh);

    VpuWriteReg(CMD_ENC_SEQ_BB_START, pEncInfo->streamBufStartAddr);
    VpuWriteReg(CMD_ENC_SEQ_BB_SIZE, pEncInfo->streamBufSize / 1024);

    data = 0;

    if (pEncOP->rcIntraQp >= 0)
        data |= (1 << 5);
    VpuWriteReg(CMD_ENC_SEQ_INTRA_QP, pEncOP->rcIntraQp);

    if (pCodecInst->codecMode == AVC_ENC) {
        data |= (pEncOP->EncStdParam.avcParam.avc_audEnable << 2);
        if (!cpu_is_mx6q())
            data |= (pEncOP->EncStdParam.avcParam.avc_fmoEnable << 4);
        else if (pCodecInst->codecModeAux == AVC_AUX_MVC) {
            data |= (pEncInfo->openParam.EncStdParam.avcParam.interview_en << 4);
            data |= (pEncInfo->openParam.EncStdParam.avcParam.paraset_refresh_en << 8);
            data |= (pEncInfo->openParam.EncStdParam.avcParam.prefix_nal_en << 9);
        }
    }

    if (cpu_is_mx6q()) {
        if (pEncInfo->openParam.userQpMax) {
            data |= (1 << 6);
            VpuWriteReg(CMD_ENC_SEQ_RC_QP_MIN_MAX, pEncInfo->openParam.userQpMax);
        }
        if (pEncOP->userGamma) {
            data |= (1 << 7);
            VpuWriteReg(CMD_ENC_SEQ_RC_GAMMA, pEncOP->userGamma);
        }
    } else {
        if (pEncOP->userQpMinEnable) {
            data |= (1 << 6);
            VpuWriteReg(CMD_ENC_SEQ_RC_QP_MIN_MAX,
                        (pEncOP->userQpMin << 8) | (pEncOP->userQpMax & 0xFF));
        }
        if (pEncOP->userQpMaxEnable) {
            data |= (1 << 7);
            VpuWriteReg(CMD_ENC_SEQ_RC_QP_MIN_MAX,
                        (pEncOP->userQpMin << 8) | (pEncOP->userQpMax & 0xFF));
        }

        if (pEncOP->userGamma) {
            data |= (1 << 8);
            VpuWriteReg(CMD_ENC_SEQ_RC_GAMMA, pEncOP->userGamma);
        }
    }

    if ((!cpu_is_mx6q()) && pCodecInst->codecMode == AVC_ENC) {
        if (pEncOP->avcIntra16x16OnlyModeEnable)
            data |= (1 << 9);
    }

    VpuWriteReg(CMD_ENC_SEQ_OPTION, data);

    VpuWriteReg(CMD_ENC_SEQ_RC_INTERVAL_MODE,
                (pEncInfo->openParam.MbInterval << 2) | pEncInfo->openParam.RcIntervalMode);

    /* Set secondAXI IRAM */
    iramParam.width = pEncOP->picWidth;
    SetEncSecondAXIIRAM(&pEncInfo->secAxiUse, &iramParam);

    if (!cpu_is_mx6q()) {
        /* Use external memory if IRAM is disabled for searchMe */
        if (pEncInfo->secAxiUse.useHostMeEnable == 0) {
            pEncInfo->searchRamMem.size = pEncInfo->secAxiUse.searchRamSize;
            IOGetMem(&pEncInfo->searchRamMem);
            pEncInfo->secAxiUse.searchRamAddr = pEncInfo->searchRamMem.phy_addr;
        }

        VpuWriteReg(CMD_ENC_SEARCH_BASE, pEncInfo->secAxiUse.searchRamAddr);
        VpuWriteReg(CMD_ENC_SEARCH_SIZE, pEncInfo->secAxiUse.searchRamSize);
    } else {
        VpuWriteReg(CMD_ENC_SEQ_ME_OPTION, pEncInfo->openParam.MEUseZeroPmv << 2 |
                    pEncInfo->openParam.MESearchRange);
        VpuWriteReg(CMD_ENC_SEQ_INTRA_WEIGHT, pEncInfo->openParam.IntraCostWeight);
    }

    BitIssueCommand(pCodecInst, SEQ_INIT);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (cpu_is_mx6q() && VpuReadReg(RET_ENC_SEQ_ENC_SUCCESS) & (1 << 31)) {
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    if (VpuReadReg(RET_ENC_SEQ_ENC_SUCCESS) == 0) {
        return RETCODE_FAILURE;
    }

    /* Backup wr pointer to ctx */
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = VpuReadReg(BIT_WR_PTR);

    if (pCodecInst->codecMode == MJPG_ENC)
        info->minFrameBufferCount = 0;
    else {
        if (pCodecInst->codecMode == AVC_ENC && pCodecInst->codecModeAux == AVC_AUX_MVC)
            info->minFrameBufferCount = 3;  /* reconstructed frame + 2 reference frame */
        else
            info->minFrameBufferCount = 2;  /* reconstructed frame + reference frame */
    }

    info->reportBufSize.sliceInfoBufSize = SIZE_SLICE_INFO;
    info->reportBufSize.mbInfoBufSize = SIZE_MB_DATA;
    info->reportBufSize.mvInfoBufSize = SIZE_MV_DATA;

    pEncInfo->initialInfo = *info;
    pEncInfo->initialInfoObtained = 1;

    if (cpu_is_mx6q()) {
        SetTiledMapTypeInfo(pEncInfo->mapType, &pEncInfo->sTiledInfo);
        /* Enable 2-D cache */
        SetMaverickCache(&pEncInfo->cacheConfig, 0, pEncInfo->openParam.chromaInterleave);
    }

    return RETCODE_SUCCESS;
}

/*!
 * @brief Registers frame buffers
 * @param handle [Input] The handle obtained from VPU_EncOpen().
 * @param bufArray [Input] Pointer to the first element of an array
 *			of FrameBuffer data structures.
 * @param num [Input] Number of elements of the array.
 * @param stride [Input] Stride value of frame buffers being registered.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished
 * @li RETCODE_WRONG_CALL_SEQUENCE Function call in wrong sequence.
 * @li RETCODE_INVALID_FRAME_BUFFER pBuffer is a null pointer.
 * @li RETCODE_INSUFFICIENT_FRAME_BUFFERS num is smaller than requested.
 * @li RETCODE_INVALID_STRIDE stride is smaller than the picture width.
 */
RetCode VPU_EncRegisterFrameBuffer(EncHandle handle, FrameBuffer * bufArray,
                                   int32_t num, int32_t frameBufStride, int32_t sourceBufStride,
                                   PhysicalAddress subSampBaseA, PhysicalAddress subSampBaseB,
                                   EncExtBufInfo * pBufInfo)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    int32_t i;
    uint32_t val;
    RetCode ret;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    if (pEncInfo->frameBufPool) {
        return RETCODE_CALLED_BEFORE;
    }

    if (!pEncInfo->initialInfoObtained) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (bufArray == 0) {
        return RETCODE_INVALID_FRAME_BUFFER;
    }

    if (num < pEncInfo->initialInfo.minFrameBufferCount) {
        return RETCODE_INSUFFICIENT_FRAME_BUFFERS;
    }

    if (frameBufStride % 8 != 0 || frameBufStride == 0) {
        return RETCODE_INVALID_STRIDE;
    }

    pEncInfo->frameBufPool = bufArray;
    pEncInfo->numFrameBuffers = num;
    pEncInfo->stride = frameBufStride;

    if (pCodecInst->codecMode != MJPG_ENC) {
        /* Need to swap word between Dword(64bit) */
        for (i = 0; i < num; i += 2) {
            virt_paraBuf[i * 3] = bufArray[i].bufCb;
            virt_paraBuf[i * 3 + 1] = bufArray[i].bufY;
            virt_paraBuf[i * 3 + 3] = bufArray[i].bufCr;
            if (i + 1 < num) {
                virt_paraBuf[i * 3 + 2] = bufArray[i + 1].bufY;
                virt_paraBuf[i * 3 + 4] = bufArray[i + 1].bufCr;
                virt_paraBuf[i * 3 + 5] = bufArray[i + 1].bufCb;
            }
        }
    }

    /* Tell the codec how much frame buffers were allocated. */
    VpuWriteReg(CMD_SET_FRAME_BUF_NUM, num);
    VpuWriteReg(CMD_SET_FRAME_BUF_STRIDE, frameBufStride);

    if (!cpu_is_mx6q())
        VpuWriteReg(CMD_SET_FRAME_SOURCE_BUF_STRIDE, sourceBufStride);

    if (cpu_is_mx6q()) {
        /* Maverick Cache Configuration */
        val = (pEncInfo->cacheConfig.luma.cfg.PageSizeX << 28) |
            (pEncInfo->cacheConfig.luma.cfg.PageSizeY << 24) |
            (pEncInfo->cacheConfig.luma.cfg.CacheSizeX << 20) |
            (pEncInfo->cacheConfig.luma.cfg.CacheSizeY << 16) |
            (pEncInfo->cacheConfig.chroma.cfg.PageSizeX << 12) |
            (pEncInfo->cacheConfig.chroma.cfg.PageSizeY << 8) |
            (pEncInfo->cacheConfig.chroma.cfg.CacheSizeX << 4) |
            (pEncInfo->cacheConfig.chroma.cfg.CacheSizeY << 0);
        VpuWriteReg(CMD_SET_FRAME_CACHE_SIZE, val);

        val = (pEncInfo->cacheConfig.Bypass << 4) |
            (pEncInfo->cacheConfig.DualConf << 2) | (pEncInfo->cacheConfig.PageMerge << 0);
        val = val << 24;
        val |= (pEncInfo->cacheConfig.LumaBufferSize << 16) |
            (pEncInfo->cacheConfig.CbBufferSize << 8) | (pEncInfo->cacheConfig.CrBufferSize);
        VpuWriteReg(CMD_SET_FRAME_CACHE_CONFIG, val);
    }

    VpuWriteReg(CMD_SET_FRAME_AXI_BIT_ADDR, pEncInfo->secAxiUse.bufBitUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_IPACDC_ADDR, pEncInfo->secAxiUse.bufIpAcDcUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKY_ADDR, pEncInfo->secAxiUse.bufDbkYUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKC_ADDR, pEncInfo->secAxiUse.bufDbkCUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_OVL_ADDR, pEncInfo->secAxiUse.bufOvlUse);

    if (cpu_is_mx6q()) {
        VpuWriteReg(CMD_SET_FRAME_AXI_BTP_ADDR, pEncInfo->secAxiUse.bufBtpUse);

        /*
         * Magellan Encoder specific : Subsampling ping-pong Buffer
         * Set Sub-Sampling buffer for ME-Reference and DBK-Reconstruction
         * BPU will swap below two buffer internally every pic by pic
         */
        VpuWriteReg(CMD_SET_FRAME_SUBSAMP_A, subSampBaseA);
        VpuWriteReg(CMD_SET_FRAME_SUBSAMP_B, subSampBaseB);

        if (pCodecInst->codecMode == AVC_ENC && pCodecInst->codecModeAux == AVC_AUX_MVC) {
            if (pBufInfo == NULL || !pBufInfo->subSampBaseAMvc || !pBufInfo->subSampBaseBMvc) {
                return RETCODE_INVALID_PARAM;
            }
            VpuWriteReg(CMD_SET_FRAME_SUBSAMP_A_MVC, pBufInfo->subSampBaseAMvc);
            VpuWriteReg(CMD_SET_FRAME_SUBSAMP_B_MVC, pBufInfo->subSampBaseBMvc);
        }

        if (pCodecInst->codecMode == MP4_ENC) {
            if (pEncInfo->mp4_dataPartitionEnable) {
                if (pBufInfo == NULL) {
                    return RETCODE_INVALID_PARAM;
                }
                /* MPEG4 Encoder Data-Partitioned bitstream temporal buffer */
                VpuWriteReg(CMD_SET_FRAME_DP_BUF_BASE, pBufInfo->scratchBuf.bufferBase);
                VpuWriteReg(CMD_SET_FRAME_DP_BUF_SIZE, pBufInfo->scratchBuf.bufferSize);
            } else {
                VpuWriteReg(CMD_SET_FRAME_DP_BUF_BASE, 0);
                VpuWriteReg(CMD_SET_FRAME_DP_BUF_SIZE, 0);
            }
        }
    }

    BitIssueCommand(pCodecInst, SET_FRAME_BUF);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (cpu_is_mx6q() && VpuReadReg(RET_SET_FRAME_SUCCESS) & (1 << 31)) {
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    return RETCODE_SUCCESS;
}

RetCode VPU_EncGetBitstreamBuffer(EncHandle handle,
                                  PhysicalAddress * prdPrt,
                                  PhysicalAddress * pwrPtr, uint32_t * size)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    int32_t instIndex;
    uint32_t room;
    RetCode ret;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (prdPrt == 0 || pwrPtr == 0 || size == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    rdPtr = pEncInfo->streamRdPtr;

    /* Check current instance is in running or not, if not
       Get the pointer from back context regs */
    instIndex = VpuReadReg(BIT_RUN_INDEX);
    wrPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_WR_PTR) : pCodecInst->ctxRegs[CTX_BIT_WR_PTR];

    if (pEncInfo->ringBufferEnable == 1) {
        if (wrPtr >= rdPtr) {
            room = wrPtr - rdPtr;
        } else {
            room = (pEncInfo->streamBufEndAddr - rdPtr) + (wrPtr - pEncInfo->streamBufStartAddr);
        }
    } else {
        if (rdPtr == pEncInfo->streamBufStartAddr && wrPtr >= rdPtr)
            room = wrPtr - rdPtr;
        else
            return RETCODE_INVALID_PARAM;
    }

    *prdPrt = rdPtr;
    *pwrPtr = wrPtr;
    *size = room;

    return RETCODE_SUCCESS;
}

RetCode VPU_EncUpdateBitstreamBuffer(EncHandle handle, uint32_t size)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    PhysicalAddress wrPtr;
    PhysicalAddress rdPtr;
    RetCode ret;
    int32_t room = 0, instIndex;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    rdPtr = pEncInfo->streamRdPtr;

    instIndex = VpuReadReg(BIT_RUN_INDEX);
    wrPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_WR_PTR) : pCodecInst->ctxRegs[CTX_BIT_WR_PTR];

    if (rdPtr < wrPtr) {
        if (rdPtr + size > wrPtr)
            return RETCODE_INVALID_PARAM;
    }

    if (pEncInfo->ringBufferEnable == 1) {
        rdPtr += size;
        if (rdPtr > pEncInfo->streamBufEndAddr) {
            room = rdPtr - pEncInfo->streamBufEndAddr;
            rdPtr = pEncInfo->streamBufStartAddr;
            rdPtr += room;
        }
        if (rdPtr == pEncInfo->streamBufEndAddr) {
            rdPtr = pEncInfo->streamBufStartAddr;
        }
    } else {
        rdPtr = pEncInfo->streamBufStartAddr;
    }

    pEncInfo->streamRdPtr = rdPtr;

    instIndex = VpuReadReg(BIT_RUN_INDEX);
    if (pCodecInst->instIndex == instIndex)
        VpuWriteReg(BIT_RD_PTR, wrPtr);
    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = rdPtr;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Starts encoding one frame.
 *
 * @param handle [Input] The handle obtained from VPU_EncOpen().
 * @param pParam [Input] Pointer to EncParam data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM pParam is invalid.
 * @li RETCODE_INVALID_FRAME_BUFFER skipPicture in EncParam is 0
 * and sourceFrame in EncParam is a null pointer.
 */
RetCode VPU_EncStartOneFrame(EncHandle handle, EncParam * param)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    FrameBuffer *pSrcFrame;
    uint32_t rotMirEnable = 0;
    uint32_t rotMirMode = 0;
    uint32_t val;
    RetCode ret;

    /* When doing pre-rotation, mirroring is applied first and rotation
     * later, vice versa when doing post-rotation.
     * For consistency, pre-rotation is converted to post-rotation
     * orientation.
     */
    static uint32_t rotatorModeConversion[] = {
        0, 1, 2, 3, 4, 7, 6, 5,
        6, 5, 4, 7, 2, 3, 0, 1
    };

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    /* This means frame buffers have not been registered. */
    if (pEncInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    ret = CheckEncParam(pCodecInst, param);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    pSrcFrame = param->sourceFrame;

    if (pEncInfo->rotationEnable) {
        switch (pEncInfo->rotationAngle) {
        case 0:
            rotMirMode |= 0x0;
            break;

        case 90:
            rotMirMode |= 0x1;
            break;

        case 180:
            rotMirMode |= 0x2;
            break;

        case 270:
            rotMirMode |= 0x3;
            break;
        }
    }
    if (pEncInfo->mirrorEnable) {
        switch (pEncInfo->mirrorDirection) {
        case MIRDIR_NONE:
            rotMirMode |= 0x0;
            break;

        case MIRDIR_VER:
            rotMirMode |= 0x4;
            break;

        case MIRDIR_HOR:
            rotMirMode |= 0x8;
            break;

        case MIRDIR_HOR_VER:
            rotMirMode |= 0xc;
            break;

        }
    }

    /* Set GDI related registers per tiled map info for mx6q */
    if (cpu_is_mx6q())
        SetGDIRegs(&pEncInfo->sTiledInfo);
    if (!cpu_is_mx6q())
        rotMirMode = rotatorModeConversion[rotMirMode];
    rotMirMode |= rotMirEnable;
    VpuWriteReg(CMD_ENC_PIC_ROT_MODE, rotMirMode);

    VpuWriteReg(CMD_ENC_PIC_QS, param->quantParam);

    if (param->skipPicture) {
        VpuWriteReg(CMD_ENC_PIC_OPTION,
                    (pEncInfo->encReportSliceInfo.enable << 5) |
                    (pEncInfo->encReportMVInfo.enable << 4) |
                    (pEncInfo->encReportMBInfo.enable << 3) | 1);
    } else {
        if (cpu_is_mx6q()) {
            VpuWriteReg(CMD_ENC_PIC_SRC_INDEX, pSrcFrame->myIndex);
            VpuWriteReg(CMD_ENC_PIC_SRC_STRIDE, pSrcFrame->strideY);
        }
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_Y, pSrcFrame->bufY +
                    param->encTopOffset * pSrcFrame->strideY + param->encLeftOffset);
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_CB, pSrcFrame->bufCb +
                    param->encTopOffset / 2 * pSrcFrame->strideC + param->encLeftOffset / 2);
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_CR, pSrcFrame->bufCr +
                    param->encTopOffset / 2 * pSrcFrame->strideC + param->encLeftOffset / 2);

        val = (pEncInfo->encReportSliceInfo.enable << 5) |
            (pEncInfo->encReportMVInfo.enable << 4) |
            (pEncInfo->encReportMBInfo.enable << 3) | (param->forceIPicture << 1 & 0x2);
        if (!cpu_is_mx6q())
            val |= (!param->enableAutoSkip) << 2;
        VpuWriteReg(CMD_ENC_PIC_OPTION, val);
    }

    if (pEncInfo->dynamicAllocEnable == 1) {
        VpuWriteReg(CMD_ENC_PIC_BB_START, param->picStreamBufferAddr);
        VpuWriteReg(CMD_ENC_PIC_BB_SIZE, param->picStreamBufferSize / 1024);
    }

    if (pEncInfo->encReportMBInfo.enable || pEncInfo->encReportMVInfo.enable ||
        pEncInfo->encReportSliceInfo.enable) {
        uint32_t *virt_addr, phy_addr;

        if (!pEncInfo->picParaBaseMem.phy_addr) {
            pEncInfo->picParaBaseMem.size = ENC_ADDR_END_OF_RPT_BUF;
            ret = IOGetMem(&pEncInfo->picParaBaseMem);
            if (ret) {
                err_msg("Unable to obtain physical mem\n");
                return RETCODE_FAILURE;
            }
            if (IOGetMem(&pEncInfo->picParaBaseMem) <= 0) {
                pEncInfo->picParaBaseMem.phy_addr = 0;
                err_msg("Unable to obtain virtual mem\n");
                return RETCODE_FAILURE;
            }
        }

        VpuWriteReg(CMD_ENC_PIC_PARA_BASE_ADDR, pEncInfo->picParaBaseMem.phy_addr);

        virt_addr = (uint32_t *) pEncInfo->picParaBaseMem.virt_uaddr;
        phy_addr = pEncInfo->picParaBaseMem.phy_addr;
        /* Set mbParam buffer address */
        if (pEncInfo->encReportMBInfo.enable) {
            *virt_addr = phy_addr + ADDR_MB_BASE_OFFSET;
        }
        /* Set mvParam buffer address */
        if (pEncInfo->encReportMVInfo.enable) {
            *(virt_addr + 2) = phy_addr + ADDR_MV_BASE_OFFSET;
        }
        /* Set slice info address */
        if (pEncInfo->encReportSliceInfo.enable) {
            *(virt_addr + 4) = phy_addr + ADDR_SLICE_BASE_OFFSET;
        }
    }

    if (cpu_is_mx6q()) {
        val = (pEncInfo->secAxiUse.useBitEnable |
               pEncInfo->secAxiUse.useIpEnable << 1 |
               pEncInfo->secAxiUse.useDbkEnable << 2 |
               pEncInfo->secAxiUse.useDbkEnable << 3 |
               pEncInfo->secAxiUse.useOvlEnable << 4 |
               pEncInfo->secAxiUse.useBtpEnable << 5 |
               pEncInfo->secAxiUse.useHostBitEnable << 8 |
               pEncInfo->secAxiUse.useHostIpEnable << 9 |
               pEncInfo->secAxiUse.useHostDbkEnable << 10 |
               pEncInfo->secAxiUse.useHostDbkEnable << 11 |
               pEncInfo->secAxiUse.useHostOvlEnable << 12 |
               pEncInfo->secAxiUse.useHostBtpEnable << 13);
    } else {
        val = (pEncInfo->secAxiUse.useBitEnable |
               pEncInfo->secAxiUse.useIpEnable << 1 |
               pEncInfo->secAxiUse.useDbkEnable << 2 |
               pEncInfo->secAxiUse.useOvlEnable << 3 |
               pEncInfo->secAxiUse.useMeEnable << 4 |
               pEncInfo->secAxiUse.useHostBitEnable << 7 |
               pEncInfo->secAxiUse.useHostIpEnable << 8 |
               pEncInfo->secAxiUse.useHostDbkEnable << 9 |
               pEncInfo->secAxiUse.useHostOvlEnable << 10 |
               pEncInfo->secAxiUse.useHostMeEnable << 11);
    }
    VpuWriteReg(BIT_AXI_SRAM_USE, val);

    if (cpu_is_mx6q()) {
        val = (pEncInfo->subFrameSyncConfig.subFrameSyncOn << 15 |
               pEncInfo->subFrameSyncConfig.sourceBufNumber << 8 |
               pEncInfo->subFrameSyncConfig.sourceBufIndexBase << 0);
        VpuWriteReg(CMD_ENC_PIC_SUB_FRAME_SYNC, val);
    }

    BitIssueCommand(pCodecInst, PIC_RUN);

    *ppendingInst = pCodecInst;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get information of the output of encoding.
 *
 * @param encHandle [Input] The handle obtained from VPU_EncOpen().
 * @param info [Output] Pointer to EncOutputInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM info is a null pointer.
 */
RetCode VPU_EncGetOutputInfo(EncHandle handle, EncOutputInfo * info)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    uint32_t val;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    if (*ppendingInst == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (pCodecInst != *ppendingInst) {
        return RETCODE_INVALID_HANDLE;
    }

    /* Clock is gated off when received interrupt in driver, so need to gate on here. */

    if (cpu_is_mx6q() && VpuReadReg(RET_ENC_PIC_SUCCESS) & (1 << 31)) {
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    val = VpuReadReg(RET_ENC_PIC_TYPE);
    info->skipEncoded = (val >> 2) & 0x01;
    info->picType = val & 0x03;

    if (pEncInfo->ringBufferEnable == 0) {
        if (pEncInfo->dynamicAllocEnable == 1)
            rdPtr = VpuReadReg(CMD_ENC_PIC_BB_START);
        else
            rdPtr = pEncInfo->streamBufStartAddr;

        wrPtr = VpuReadReg(BIT_WR_PTR);
        info->bitstreamBuffer = rdPtr;
        info->bitstreamSize = wrPtr - rdPtr;
    }

    info->numOfSlices = VpuReadReg(RET_ENC_PIC_SLICE_NUM);
    info->bitstreamWrapAround = VpuReadReg(RET_ENC_PIC_FLAG);
    info->reconFrameIndex = VpuReadReg(RET_ENC_PIC_FRAME_IDX);

    if (pEncInfo->encReportMBInfo.enable) {
        int32_t size = 0;
        uint32_t tempBuf[2];
        uint8_t *dst_addr = NULL, *src_addr = NULL;
        uint32_t virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr, 8);
        val = *(tempBuf + 1);
        info->mbInfo.size = val & 0xFFFF;
        info->mbInfo.enable = (val >> 24) & 0xFF;
        info->mbInfo.addr = pEncInfo->encReportMBInfo.addr;
        if (info->mbInfo.addr && info->mbInfo.size) {
            size = (info->mbInfo.size + 7) / 8 * 8;
            dst_addr = (uint8_t *) info->mbInfo.addr;
            src_addr = (uint8_t *) (virt_addr + ADDR_MB_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    if (pEncInfo->encReportMVInfo.enable) {
        int32_t size = 0;
        uint32_t tempBuf[2];
        uint8_t *dst_addr = NULL, *src_addr = NULL;
        uint32_t virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr + 8, 8);
        val = *(tempBuf + 1);
        info->mvInfo.size = val & 0xFFFF;
        info->mvInfo.enable = (val >> 24) & 0xFF;
        info->mvInfo.type = (val >> 16) & 0xFF;
        info->mvInfo.addr = pEncInfo->encReportMVInfo.addr;
        if (info->mvInfo.addr && info->mvInfo.size) {
            size = (info->mvInfo.size + 7) / 8 * 8;
            dst_addr = (uint8_t *) info->mvInfo.addr;
            src_addr = (uint8_t *) (virt_addr + ADDR_MB_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    if (pEncInfo->encReportSliceInfo.enable) {
        int32_t size = 0;
        uint32_t tempBuf[2];
        uint8_t *dst_addr = NULL, *src_addr = NULL;
        uint32_t virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr + 16, 8);
        val = *(tempBuf + 1);

        info->sliceInfo.size = val & 0xFFFF;
        info->sliceInfo.enable = (val >> 24) & 0xFF;
        info->sliceInfo.type = (val >> 16) & 0xFF;
        info->sliceInfo.addr = pEncInfo->encReportSliceInfo.addr;
        if (info->sliceInfo.addr && info->sliceInfo.size) {
            size = (info->sliceInfo.size + 7) / 8 * 8;
            dst_addr = (uint8_t *) info->sliceInfo.addr;
            src_addr = (uint8_t *) (virt_addr + ADDR_SLICE_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    /* Backup context regs */
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = VpuReadReg(BIT_WR_PTR);
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = VpuReadReg(BIT_BIT_STREAM_PARAM);
    *ppendingInst = 0;

    return RETCODE_SUCCESS;
}

/*!
 * @brief This function gives a command to the encoder.
 *
 * @param encHandle [Input] The handle obtained from VPU_EncOpen().
 * @param cmd [Intput] user command.
 * @param param [Intput/Output] param  for cmd.
 *
 * @return
 * @li RETCODE_INVALID_COMMAND cmd is not one of 8 values above.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished
 */
RetCode VPU_EncGiveCommand(EncHandle handle, CodecCommand cmd, void *param)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    switch (cmd) {
    case ENABLE_ROTATION:
        {
            pEncInfo->rotationEnable = 1;
            break;
        }

    case DISABLE_ROTATION:
        {
            pEncInfo->rotationEnable = 0;
            break;
        }

    case ENABLE_MIRRORING:
        {
            pEncInfo->mirrorEnable = 1;
            break;
        }

    case DISABLE_MIRRORING:
        {
            pEncInfo->mirrorEnable = 0;
            break;
        }

    case SET_MIRROR_DIRECTION:
        {
            MirrorDirection mirDir;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            mirDir = *(MirrorDirection *) param;
            if (mirDir < MIRDIR_NONE || mirDir > MIRDIR_HOR_VER) {
                return RETCODE_INVALID_PARAM;
            }

            pEncInfo->mirrorDirection = mirDir;
            break;
        }

    case SET_ROTATION_ANGLE:
        {
            int32_t angle;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            angle = *(int32_t *) param;
            if (angle != 0 && angle != 90 && angle != 180 && angle != 270) {
                return RETCODE_INVALID_PARAM;
            }

            if (pEncInfo->initialInfoObtained && (angle == 90 || angle == 270)) {
                return RETCODE_INVALID_PARAM;
            }

            pEncInfo->rotationAngle = angle;
            break;
        }

    case ENC_GET_SPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            GetParaSet(handle, 0, param);
            break;
        }

    case ENC_GET_PPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            GetParaSet(handle, 1, param);
            break;
        }

    case ENC_PUT_MP4_HEADER:
        {
            EncHeaderParam *encHeaderParam;

            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            encHeaderParam = (EncHeaderParam *) param;
            if (!(VOL_HEADER <= encHeaderParam->headerType &&
                  encHeaderParam->headerType <= VIS_HEADER)) {
                return RETCODE_INVALID_PARAM;
            }

            EncodeHeader(handle, encHeaderParam);
            break;
        }

    case ENC_PUT_AVC_HEADER:
        {
            EncHeaderParam *encHeaderParam;

            if (pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            encHeaderParam = (EncHeaderParam *) param;
            if (!(SPS_RBSP <= encHeaderParam->headerType && encHeaderParam->headerType <= PPS_RBSP)) {
                return RETCODE_INVALID_PARAM;
            }

            EncodeHeader(handle, encHeaderParam);
            break;
        }

    case ENC_SET_SEARCHRAM_PARAM:
        {
            /* dummy this command for none mx27 platform */
            break;

        }

    case ENC_GET_VOS_HEADER:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            GetParaSet(handle, 1, param);

            break;
        }

    case ENC_GET_VO_HEADER:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            GetParaSet(handle, 2, param);

            break;
        }

    case ENC_GET_VOL_HEADER:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            GetParaSet(handle, 0, param);

            break;
        }

    case ENC_SET_GOP_NUMBER:
        {
            int32_t *pGopNumber = (int32_t *) param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pGopNumber < 0 || *pGopNumber > 32767) {
                return RETCODE_INVALID_PARAM;
            }

            SetGopNumber(handle, (uint32_t *) pGopNumber);

            break;
        }

    case ENC_SET_INTRA_QP:
        {
            int32_t *pIntraQp = (int32_t *) param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (pCodecInst->codecMode == MP4_ENC) {
                if (*pIntraQp < 1 || *pIntraQp > 31)
                    return RETCODE_INVALID_PARAM;
            }

            if (pCodecInst->codecMode == AVC_ENC) {
                if (*pIntraQp < 0 || *pIntraQp > 51)
                    return RETCODE_INVALID_PARAM;
            }

            SetIntraQp(handle, (uint32_t *) pIntraQp);

            break;
        }

    case ENC_SET_BITRATE:
        {
            int32_t *pBitrate = (int32_t *) param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pBitrate < 0 || *pBitrate > 32767) {
                return RETCODE_INVALID_PARAM;
            }

            SetBitrate(handle, (uint32_t *) pBitrate);

            break;
        }

    case ENC_SET_FRAME_RATE:
        {
            int32_t *pFramerate = (int32_t *) param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pFramerate <= 0) {
                return RETCODE_INVALID_PARAM;
            }

            SetFramerate(handle, (uint32_t *) pFramerate);

            break;
        }

    case ENC_SET_INTRA_MB_REFRESH_NUMBER:
        {
            int32_t *pIntraRefreshNum = (int32_t *) param;

            SetIntraRefreshNum(handle, (uint32_t *) pIntraRefreshNum);

            break;
        }

    case ENC_SET_SLICE_INFO:
        {
            EncSliceMode *pSliceMode = (EncSliceMode *) param;
            if (pSliceMode->sliceMode < 0 || pSliceMode->sliceMode > 1) {
                return RETCODE_INVALID_PARAM;
            }

            if (pSliceMode->sliceSizeMode < 0 || pSliceMode->sliceSizeMode > 1) {
                return RETCODE_INVALID_PARAM;
            }

            SetSliceMode(handle, (EncSliceMode *) pSliceMode);

            break;
        }

    case ENC_ENABLE_HEC:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            SetHecMode(handle, 1);

            break;
        }

    case ENC_DISABLE_HEC:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            SetHecMode(handle, 0);

            break;
        }

    case ENC_SET_REPORT_MBINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pEncInfo->encReportMBInfo = *(EncReportInfo *) param;

            if (pEncInfo->encReportMBInfo.enable && !pEncInfo->encReportMBInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case ENC_SET_REPORT_MVINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pEncInfo->encReportMVInfo = *(EncReportInfo *) param;

            if (pEncInfo->encReportMVInfo.enable && !pEncInfo->encReportMVInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case ENC_SET_REPORT_SLICEINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pEncInfo->encReportSliceInfo = *(EncReportInfo *) param;

            if (pEncInfo->encReportSliceInfo.enable && !pEncInfo->encReportSliceInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case ENC_SET_SUB_FRAME_SYNC:
        {
            EncSubFrameSyncConfig *subFrameSyncConfig;

            if (param == 0)
                return RETCODE_INVALID_PARAM;

            subFrameSyncConfig = (EncSubFrameSyncConfig *) param;
            pEncInfo->subFrameSyncConfig.subFrameSyncOn = subFrameSyncConfig->subFrameSyncOn;
            pEncInfo->subFrameSyncConfig.sourceBufNumber = subFrameSyncConfig->sourceBufNumber;
            pEncInfo->subFrameSyncConfig.sourceBufIndexBase =
                subFrameSyncConfig->sourceBufIndexBase;
            break;
        }

    case ENC_ENABLE_SUB_FRAME_SYNC:
        {
            pEncInfo->subFrameSyncConfig.subFrameSyncOn = 1;
            break;
        }

    case ENC_DISABLE_SUB_FRAME_SYNC:
        {
            pEncInfo->subFrameSyncConfig.subFrameSyncOn = 0;
            break;
        }

    default:
        err_msg("Invalid encoder command\n");
        return RETCODE_INVALID_COMMAND;
    }

    return RETCODE_SUCCESS;
}

/*!
 * @brief Decoder initialization
 *
 * @param pHandle [Output] Pointer to DecHandle type
 * @param pop [Input] Pointer to DecOpenParam type.
 *
 * @return
 * @li RETCODE_SUCCESS Success in acquisition of a decoder instance.
 * @li RETCODE_FAILURE Failed in acquisition of a decoder instance.
 * @li RETCODE_INVALID_PARAM pop is a null pointer or invalid.
 */
RetCode VPU_DecOpen(DecHandle * pHandle, DecOpenParam * pop)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int32_t instIdx, i;
    uint32_t val;
    RetCode ret;

    if (!isVpuInitialized())
        return RETCODE_NOT_INITIALIZED;

    ret = CheckDecOpenParam(pop);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    ret = GetCodecInstance(&pCodecInst);
    if (ret == RETCODE_FAILURE) {
        *pHandle = 0;
        return RETCODE_FAILURE;
    }

    *pHandle = pCodecInst;
    instIdx = pCodecInst->instIndex;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* Allocate context buffer */
    pCodecInst->contextBufMem.size = SIZE_CONTEXT_BUF;
    ret = IOGetMem(&pCodecInst->contextBufMem);
    if (ret) {
        err_msg("Unable to obtain physical mem\n");
        return RETCODE_FAILURE;
    }

    pDecInfo->openParam = *pop;

    switch (pop->bitstreamFormat) {
    case STD_MPEG4:
        pCodecInst->codecMode = MP4_DEC;
        pCodecInst->codecModeAux = MP4_AUX_MPEG4;
        break;
    case STD_AVC:
        pCodecInst->codecMode = AVC_DEC;
        pCodecInst->codecModeAux = pop->avcExtension;
        break;
    case STD_VC1:
        pCodecInst->codecMode = VC1_DEC;
        break;
    case STD_MPEG2:
        pCodecInst->codecMode = MP2_DEC;
        break;
    case STD_DIV3:
        pCodecInst->codecMode = DV3_DEC;
        pCodecInst->codecModeAux = MP4_AUX_DIVX3;
        break;
    case STD_RV:
        pCodecInst->codecMode = RV_DEC;
        break;
    case STD_AVS:
        pCodecInst->codecMode = AVS_DEC;
        break;
    case STD_VP8:
        pCodecInst->codecMode = VPX_DEC;
        pCodecInst->codecModeAux = VPX_AUX_VP8;
        break;
    case STD_MJPG:
        pCodecInst->codecMode = MJPG_DEC;
        break;
    default:
        break;
    }

    pDecInfo->streamWrPtr = pop->bitstreamBuffer;
    pDecInfo->streamBufStartAddr = pop->bitstreamBuffer;
    pDecInfo->streamBufSize = pop->bitstreamBufferSize;
    pDecInfo->streamBufEndAddr = pop->bitstreamBuffer + pop->bitstreamBufferSize;
    pDecInfo->jpgInfo.pVirtBitStream = pop->pBitStream;
    pDecInfo->jpgInfo.frameOffset = 0;
    pDecInfo->jpgInfo.lineBufferMode = pop->jpgLineBufferMode;

    pDecInfo->frameBufPool = 0;

    pDecInfo->rotationEnable = 0;
    pDecInfo->mirrorEnable = 0;
    pDecInfo->mirrorDirection = MIRDIR_NONE;
    pDecInfo->rotationAngle = 0;
    pDecInfo->rotatorOutputValid = 0;
    pDecInfo->rotatorStride = 0;
    pDecInfo->deringEnable = 0;

    if (pCodecInst->codecMode == VPX_DEC)
        pDecInfo->picSrcSize = (pop->picWidth << 16) | pop->picHeight;

    pDecInfo->initialInfoObtained = 0;
    pDecInfo->vc1BframeDisplayValid = 0;

    pDecInfo->decReportFrameBufStat.enable = 0;
    pDecInfo->decReportMBInfo.enable = 0;
    pDecInfo->decReportMVInfo.enable = 0;
    pDecInfo->decReportUserData.enable = 0;
    pDecInfo->decReportUserData.size = 0;

    pDecInfo->mapType = pop->mapType;
    pDecInfo->tiledLinearEnable = pop->tiled2LinearEnable;
    pDecInfo->cacheConfig.Bypass = 1;
    for (i = 0; i < 6; i++)
        pDecInfo->writeMemProtectCfg.region[i].enable = 0;

    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = pDecInfo->streamBufStartAddr;
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = pDecInfo->streamWrPtr;
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = 0;
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = 0;

    VpuWriteReg(GDI_WPROT_RGN_EN, 0);

    if (instIdx == VpuReadReg(BIT_RUN_INDEX)) {
        VpuWriteReg(BIT_RD_PTR, pDecInfo->streamBufStartAddr);
        VpuWriteReg(BIT_WR_PTR, pDecInfo->streamWrPtr);
        VpuWriteReg(BIT_FRM_DIS_FLG, 0);
    }

    val = VpuReadReg(BIT_FRAME_MEM_CTRL);
    val &= ~(1 << 2 | 1 << 3);  /* clear the bit firstly */
    val &= 0x3f;
    if (pDecInfo->openParam.bitstreamMode)
        pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] |= 1 << 3;

    if (pDecInfo->mapType)
        val |= (pDecInfo->tiledLinearEnable << 11 | 0x03 << 9);
    val |= 1 << 12;
    pCodecInst->ctxRegs[CTX_BIT_FRAME_MEM_CTRL] =
        val | (pDecInfo->openParam.chromaInterleave * 0xF << 2);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Decoder close function
 *
 * @param  handle [Input] The handle obtained from VPU_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful closing.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode VPU_DecClose(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (*ppendingInst == pCodecInst) {
        return RETCODE_FRAME_NOT_COMPLETE;
    }

    if (pDecInfo->initialInfoObtained) {
        BitIssueCommand(pCodecInst, SEQ_END);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    FreeCodecInstance(pCodecInst);

    return RETCODE_SUCCESS;
}

RetCode VPU_DecSetEscSeqInit(DecHandle handle, int32_t escape)
{
    CodecInst *pCodecInst;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;

    if (escape == 0)
        pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] &= ~0x01;
    else
        pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] |= 0x01;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get header information of bitstream.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param info [Output] Pointer to DecInitialInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_FAILURE There was an error in getting initial information.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM info is an invalid pointer.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 */
RetCode VPU_DecGetInitialInfo(DecHandle handle, DecInitialInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    uint32_t val, val2;
    SetIramParam iramParam;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (pDecInfo->initialInfoObtained) {
        return RETCODE_CALLED_BEFORE;
    }

    if (DecBitstreamBufEmpty(handle)) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    VpuWriteReg(CMD_DEC_SEQ_BB_START, pDecInfo->streamBufStartAddr);
    VpuWriteReg(CMD_DEC_SEQ_BB_SIZE, pDecInfo->streamBufSize / 1024);

    if (pCodecInst->codecMode == VPX_DEC)
        VpuWriteReg(CMD_DEC_SEQ_START_BYTE, 0);

    val = 0;
    val |= ((pDecInfo->openParam.reorderEnable << 1) & 0x2);
    if (pCodecInst->codecMode == MJPG_DEC) {
        val |= 1 << 10;         /* force not interrupt mode */
        val |= pDecInfo->decReportUserData.enable << 5;
    }

    val |= (pDecInfo->openParam.mp4DeblkEnable & 0x1);

    VpuWriteReg(CMD_DEC_SEQ_OPTION, val);

    if (pCodecInst->codecMode == VC1_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_VC1_STREAM_FMT, 0);
    }

    if (pCodecInst->codecMode == MP4_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_MP4_ASP_CLASS, pDecInfo->openParam.mp4Class);
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_X264_MV_EN, 1);

    }

    if (pCodecInst->codecMode == MJPG_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_JPG_THUMB_EN, pDecInfo->openParam.mjpg_thumbNailDecEnable);
    }

    if (pCodecInst->codecMode == VPX_DEC)
        VpuWriteReg(CMD_DEC_SEQ_SRC_SIZE, pDecInfo->picSrcSize);
    else if (pCodecInst->codecMode == AVC_DEC)
        VpuWriteReg(CMD_DEC_SEQ_SPP_CHUNK_SIZE, 512);

    BitIssueCommand(pCodecInst, SEQ_INIT);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    val = VpuReadReg(RET_DEC_SEQ_SUCCESS);

    if (val & (1 << 31)) {
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }
    if (pDecInfo->openParam.bitstreamMode && (val & (1 << 4))) {
        return RETCODE_FAILURE;
    }

    if (val == 0) {
        val = VpuReadReg(RET_DEC_SEQ_ERR_REASON);
        info->errorcode = val;

        return RETCODE_FAILURE;
    }

    val = VpuReadReg(RET_DEC_SEQ_SRC_SIZE);
    info->picWidth = ((val >> 16) & 0xffff);
    info->picHeight = (val & 0xffff);

    if (pCodecInst->codecMode == MJPG_DEC) {
        if (info->picWidth < 16 || info->picHeight < 16) {
            return RETCODE_FAILURE;
        }
    } else {
        if (info->picWidth < 64 || info->picHeight < 64) {
            return RETCODE_FAILURE;
        }
    }

    info->frameRateRes = VpuReadReg(RET_DEC_SEQ_FRATE_NR);
    info->frameRateDiv = VpuReadReg(RET_DEC_SEQ_FRATE_DR);
    info->bitRate = VpuReadReg(RET_DEC_SEQ_BIT_RATE);

    if (pCodecInst->codecMode == MP4_DEC) {
        val = VpuReadReg(RET_DEC_SEQ_INFO);
        info->mp4_shortVideoHeader = (val >> 2) & 1;
        info->mp4_dataPartitionEnable = val & 1;
        info->mp4_reversibleVlcEnable = info->mp4_dataPartitionEnable ? ((val >> 1) & 1) : 0;
        info->h263_annexJEnable = (val >> 3) & 1;
    } else if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        /* h_scale[31:30] v_scale[29:28] pic_width[27:14] pic_height[13:0] */
        val = VpuReadReg(RET_DEC_SEQ_VP8_SCALE_INFO);
        info->vp8ScaleInfo.hScaleFactor = (val >> 30) & 0x03;
        info->vp8ScaleInfo.vScaleFactor = (val >> 28) & 0x03;
        info->vp8ScaleInfo.picWidth = (val >> 14) & 0x3FFF;
        info->vp8ScaleInfo.picHeight = (val >> 0) & 0x3FFF;
    }

    info->minFrameBufferCount = VpuReadReg(RET_DEC_SEQ_FRAME_NEED);
    info->frameBufDelay = VpuReadReg(RET_DEC_SEQ_FRAME_DELAY);

    if (pCodecInst->codecMode == AVC_DEC) {
        val = VpuReadReg(RET_DEC_SEQ_CROP_LEFT_RIGHT);
        val2 = VpuReadReg(RET_DEC_SEQ_CROP_TOP_BOTTOM);
        if (val == 0 && val2 == 0) {
            info->picCropRect.left = 0;
            info->picCropRect.right = 0;
            info->picCropRect.top = 0;
            info->picCropRect.bottom = 0;
        } else {
            info->picCropRect.left = ((val >> 16) & 0xFFFF);
            info->picCropRect.right = info->picWidth - ((val & 0xFFFF));
            info->picCropRect.top = ((val2 >> 16) & 0xFFFF);
            info->picCropRect.bottom = info->picHeight - ((val2 & 0xFFFF));
        }

        val = info->picWidth * info->picHeight;
        info->normalSliceSize = (val * 3 / 2) / 1024 / 4;
        info->worstSliceSize = ((val / 256) * 3200 / 8 + 512) / 1024;
    } else {
        info->picCropRect.left = 0;
        info->picCropRect.right = 0;
        info->picCropRect.top = 0;
        info->picCropRect.bottom = 0;
    }

    val = VpuReadReg(RET_DEC_SEQ_HEADER_REPORT);
    info->profile = (val >> 0) & 0xFF;
    info->level = (val >> 8) & 0xFF;
    info->interlace = (val >> 16) & 0x01;
    info->direct8x8Flag = (val >> 17) & 0x01;
    info->vc1_psf = (val >> 18) & 0x01;
    info->constraint_set_flag[0] = (val >> 19) & 0x01;
    info->constraint_set_flag[1] = (val >> 20) & 0x01;
    info->constraint_set_flag[2] = (val >> 21) & 0x01;
    info->constraint_set_flag[3] = (val >> 22) & 0x01;

    val = VpuReadReg(RET_DEC_SEQ_ASPECT);
    info->aspectRateInfo = val;

    info->reportBufSize.frameBufStatBufSize = SIZE_FRAME_BUF_STAT;
    info->reportBufSize.mbInfoBufSize = SIZE_MB_DATA;
    info->reportBufSize.mvInfoBufSize = SIZE_MV_DATA;

    info->streamInfoObtained = 1;

    /* Backup rd pointer to ctx */
    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = VpuReadReg(BIT_RD_PTR);
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = VpuReadReg(BIT_BIT_STREAM_PARAM);

    pDecInfo->initialInfo = *info;
    pDecInfo->initialInfoObtained = 1;

    /* Set secondAXI IRAM */
    iramParam.width = (info->picWidth + 15) & ~15;
    iramParam.height = (info->picHeight + 15) & ~15;
    iramParam.profile = info->profile;
    iramParam.codecMode = pCodecInst->codecMode;
    SetDecSecondAXIIRAM(&pDecInfo->secAxiUse, &iramParam);

    SetTiledMapTypeInfo(pDecInfo->mapType, &pDecInfo->sTiledInfo);
#if 0
    /* Enable 2-D cache */
    SetMaverickCache(&pDecInfo->cacheConfig, pDecInfo->mapType,
                     pDecInfo->openParam.chromaInterleave);
#endif
    return RETCODE_SUCCESS;
}

/*!
 * @brief Register decoder frame buffers.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param bufArray [Input] Pointer to the first element of an array of FrameBuffer.
 * @param num [Input] Number of elements of the array.
 * @param stride [Input] Stride value of frame buffers being registered.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_FRAME_BUFFER Buffer is an invalid pointer.
 * @li RETCODE_INSUFFICIENT_FRAME_BUFFERS num is less than
 * the value requested by VPU_DecGetInitialInfo().
 * @li RETCODE_INVALID_STRIDE stride is less than the picture width.
 */
RetCode VPU_DecRegisterFrameBuffer(DecHandle handle,
                                   FrameBuffer * bufArray, int32_t num, int32_t stride,
                                   DecBufInfo * pBufInfo)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int32_t i;
    RetCode ret;
    uint32_t val;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (pDecInfo->frameBufPool) {
        return RETCODE_CALLED_BEFORE;
    }

    if (!pDecInfo->initialInfoObtained) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (bufArray == 0) {
        return RETCODE_INVALID_FRAME_BUFFER;
    }

    if (num < pDecInfo->initialInfo.minFrameBufferCount) {
        return RETCODE_INSUFFICIENT_FRAME_BUFFERS;
    }

    if (stride < pDecInfo->initialInfo.picWidth || stride % 8 != 0) {
        return RETCODE_INVALID_STRIDE;
    }

    pDecInfo->frameBufPool = bufArray;
    pDecInfo->numFrameBuffers = num;
    pDecInfo->stride = stride;

    if (pDecInfo->openParam.bitstreamFormat == STD_MJPG)
        return RETCODE_SUCCESS;

    /* none mx27 platform case need to swap word */
    for (i = 0; i < num; i += 2) {
        virt_paraBuf[i * 3] = bufArray[i].bufCb;
        virt_paraBuf[i * 3 + 1] = bufArray[i].bufY;
        virt_paraBuf[i * 3 + 3] = bufArray[i].bufCr;
        if (pDecInfo->openParam.bitstreamFormat == STD_AVC)
            virt_paraBuf[96 + i + 1] = bufArray[i].bufMvCol;
        if (i + 1 < num) {
            virt_paraBuf[i * 3 + 2] = bufArray[i + 1].bufY;
            virt_paraBuf[i * 3 + 4] = bufArray[i + 1].bufCr;
            virt_paraBuf[i * 3 + 5] = bufArray[i + 1].bufCb;
            if (pDecInfo->openParam.bitstreamFormat == STD_AVC)
                virt_paraBuf[96 + i] = bufArray[i + 1].bufMvCol;
        }
    }
    if (pDecInfo->openParam.bitstreamFormat == STD_VC1 ||
        pDecInfo->openParam.bitstreamFormat == STD_MPEG4 ||
        pDecInfo->openParam.bitstreamFormat == STD_AVS ||
        pDecInfo->openParam.bitstreamFormat == STD_RV)
        virt_paraBuf[97] = bufArray[0].bufMvCol;

    /* Tell the decoder how much frame buffers were allocated. */
    VpuWriteReg(CMD_SET_FRAME_BUF_NUM, num);
    VpuWriteReg(CMD_SET_FRAME_BUF_STRIDE, stride);

    VpuWriteReg(CMD_SET_FRAME_AXI_BIT_ADDR, pDecInfo->secAxiUse.bufBitUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_IPACDC_ADDR, pDecInfo->secAxiUse.bufIpAcDcUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKY_ADDR, pDecInfo->secAxiUse.bufDbkYUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_DBKC_ADDR, pDecInfo->secAxiUse.bufDbkCUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_OVL_ADDR, pDecInfo->secAxiUse.bufOvlUse);
    VpuWriteReg(CMD_SET_FRAME_AXI_BTP_ADDR, pDecInfo->secAxiUse.bufBtpUse);

    /* Maverick Cache Configuration */
    val = (pDecInfo->cacheConfig.luma.cfg.PageSizeX << 28) |
        (pDecInfo->cacheConfig.luma.cfg.PageSizeY << 24) |
        (pDecInfo->cacheConfig.luma.cfg.CacheSizeX << 20) |
        (pDecInfo->cacheConfig.luma.cfg.CacheSizeY << 16) |
        (pDecInfo->cacheConfig.chroma.cfg.PageSizeX << 12) |
        (pDecInfo->cacheConfig.chroma.cfg.PageSizeY << 8) |
        (pDecInfo->cacheConfig.chroma.cfg.CacheSizeX << 4) |
        (pDecInfo->cacheConfig.chroma.cfg.CacheSizeY << 0);
    VpuWriteReg(CMD_SET_FRAME_CACHE_SIZE, val);

    val = (pDecInfo->cacheConfig.Bypass << 4) |
        (pDecInfo->cacheConfig.DualConf << 2) | (pDecInfo->cacheConfig.PageMerge << 0);
    val = val << 24;
    val |= (pDecInfo->cacheConfig.LumaBufferSize << 16) |
        (pDecInfo->cacheConfig.CbBufferSize << 8) | (pDecInfo->cacheConfig.CrBufferSize);
    VpuWriteReg(CMD_SET_FRAME_CACHE_CONFIG, val);
    if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        VpuWriteReg(CMD_SET_FRAME_MB_BUF_BASE, pBufInfo->vp8MbDataBufInfo.bufferBase);
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        VpuWriteReg(CMD_SET_FRAME_SLICE_BB_START, pBufInfo->avcSliceBufInfo.bufferBase);
        VpuWriteReg(CMD_SET_FRAME_SLICE_BB_SIZE, (pBufInfo->avcSliceBufInfo.bufferSize / 1024));
    }

    BitIssueCommand(pCodecInst, SET_FRAME_BUF);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (cpu_is_mx6q() && VpuReadReg(RET_SET_FRAME_SUCCESS) & (1 << 31)) {
        return RETCODE_MEMORY_ACCESS_VIOLATION;
    }

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get bitstream for decoder.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param bufAddr [Output] Bitstream buffer physical address.
 * @param size [Output] Bitstream size.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM buf or size is invalid.
 */
RetCode VPU_DecGetBitstreamBuffer(DecHandle handle,
                                  PhysicalAddress * paRdPtr,
                                  PhysicalAddress * paWrPtr, uint32_t * size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    int32_t instIndex;
    uint32_t room;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (paRdPtr == 0 || paWrPtr == 0 || size == 0)
        return RETCODE_INVALID_PARAM;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    wrPtr = pDecInfo->streamWrPtr;

    /* Check current instance is in running or not, if not
       Get the pointer from back context regs */
    instIndex = VpuReadReg(BIT_RUN_INDEX);
    rdPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_RD_PTR) : pCodecInst->ctxRegs[CTX_BIT_RD_PTR];

    if (wrPtr < rdPtr) {
        room = rdPtr - wrPtr - 1;
    } else {
        room = (pDecInfo->streamBufEndAddr - wrPtr) + (rdPtr - pDecInfo->streamBufStartAddr) - 1;
    }

    *paRdPtr = rdPtr;
    *paWrPtr = wrPtr;
    *size = room;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Update the current bit stream position.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param size [Input] Size of bit stream you put.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM Invalid input parameters.
 */
RetCode VPU_DecUpdateBitstreamBuffer(DecHandle handle, uint32_t size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress wrPtr;
    PhysicalAddress rdPtr;
    RetCode ret;
    int32_t room = 0, instIndex;
    uint32_t val = 0;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    wrPtr = pDecInfo->streamWrPtr;

    instIndex = VpuReadReg(BIT_RUN_INDEX);

    val = pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM];
    /* Set stream end flag if size == 0; otherwise, clear the flag */
    val = (size == 0) ? (val | 1 << 2) : (val & ~(1 << 2));
    /* Backup to context reg */
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = val;

    if (pCodecInst->instIndex == instIndex)
        VpuWriteReg(BIT_BIT_STREAM_PARAM, val); /* Write to VPU hardware */

    if (size == 0) {
        return RETCODE_SUCCESS;
    }

    rdPtr = (pCodecInst->instIndex == instIndex) ?
        VpuReadReg(BIT_RD_PTR) : pCodecInst->ctxRegs[CTX_BIT_RD_PTR];

    if ((!cpu_is_mx6q() && pDecInfo->filePlayEnable != 1) || cpu_is_mx6q()) {
        if (wrPtr < rdPtr) {
            if (rdPtr <= wrPtr + size) {
                return RETCODE_INVALID_PARAM;
            }
        }
    }

    wrPtr += size;

    if (wrPtr > pDecInfo->streamBufEndAddr) {
        room = wrPtr - pDecInfo->streamBufEndAddr;
        wrPtr = pDecInfo->streamBufStartAddr;
        wrPtr += room;
    }

    if (wrPtr == pDecInfo->streamBufEndAddr) {
        wrPtr = pDecInfo->streamBufStartAddr;
    }

    pDecInfo->streamWrPtr = wrPtr;

    if (pCodecInst->instIndex == instIndex)
        VpuWriteReg(BIT_WR_PTR, wrPtr);
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = wrPtr;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Start decoding one frame.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 */
RetCode VPU_DecStartOneFrame(DecHandle handle, DecParam * param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    DecParam *pDecParam;
    uint32_t rotMir;
    uint32_t val = 0;
    RetCode ret;

    if (!handle->initDone)
        return RETCODE_CODEC_NOT_ISSUED;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    pDecParam = &pCodecInst->CodecParam.decParam;
    memcpy(pDecParam, param, sizeof(*pDecParam));

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    rotMir = 0;
    if (pDecInfo->rotationEnable) {
        rotMir |= 0x10;         /* Enable rotator */
        switch (pDecInfo->rotationAngle) {
        case 0:
            rotMir |= 0x0;
            break;

        case 90:
            rotMir |= 0x1;
            break;

        case 180:
            rotMir |= 0x2;
            break;

        case 270:
            rotMir |= 0x3;
            break;
        }
    }

    if (pDecInfo->mirrorEnable) {
        rotMir |= 0x10;         /* Enable mirror */
        switch (pDecInfo->mirrorDirection) {
        case MIRDIR_NONE:
            rotMir |= 0x0;
            break;

        case MIRDIR_VER:
            rotMir |= 0x4;
            break;

        case MIRDIR_HOR:
            rotMir |= 0x8;
            break;

        case MIRDIR_HOR_VER:
            rotMir |= 0xc;
            break;

        }
    }

    /* Set GDI related registers per tiled map info for mx6q */
    SetGDIRegs(&pDecInfo->sTiledInfo);
    if (pDecInfo->tiledLinearEnable) {
        rotMir |= 0x10;
    }

    if (pDecInfo->deringEnable) {
        rotMir |= 0x20;         /* Enable Dering Filter */
    }

    if (rotMir & 0x30) {
        VpuWriteReg(CMD_DEC_PIC_ROT_INDEX, pDecInfo->rotatorOutput.myIndex);

        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_Y, pDecInfo->rotatorOutput.bufY);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CB, pDecInfo->rotatorOutput.bufCb);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CR, pDecInfo->rotatorOutput.bufCr);
        VpuWriteReg(CMD_DEC_PIC_ROT_STRIDE, pDecInfo->rotatorStride);
    }

    VpuWriteReg(CMD_DEC_PIC_ROT_MODE, rotMir);

    val = 0;
    val |= (1 << 10);           /* hardcode to use interrupt disable mode  */

    /* if iframeSearch is Enable, other bit is ignored. */
    if (param->iframeSearchEnable == 1) {
        val |= ((param->iframeSearchEnable & 0x1) << 2);
        pDecInfo->vc1BframeDisplayValid = 0;
    } else {
        if (param->skipframeMode)
            val |= (param->skipframeMode << 3);
        if (!cpu_is_mx6q()) {
            val |= (param->prescanMode << 1);
            val |= (param->prescanEnable);
        }
    }
    VpuWriteReg(CMD_DEC_PIC_OPTION, val);

    VpuWriteReg(CMD_DEC_PIC_SKIP_NUM, param->skipframeNum);

    val = (pDecInfo->secAxiUse.useBitEnable |
           pDecInfo->secAxiUse.useIpEnable << 1 |
           pDecInfo->secAxiUse.useDbkEnable << 2 |
           pDecInfo->secAxiUse.useDbkEnable << 3 |
           pDecInfo->secAxiUse.useOvlEnable << 4 |
           pDecInfo->secAxiUse.useBtpEnable << 5 |
           pDecInfo->secAxiUse.useHostBitEnable << 8 |
           pDecInfo->secAxiUse.useHostIpEnable << 9 |
           pDecInfo->secAxiUse.useHostDbkEnable << 10 |
           pDecInfo->secAxiUse.useHostDbkEnable << 11 |
           pDecInfo->secAxiUse.useHostOvlEnable << 12 | pDecInfo->secAxiUse.useHostBtpEnable << 13);
    VpuWriteReg(BIT_AXI_SRAM_USE, val);

    BitIssueCommand(pCodecInst, PIC_RUN);

    *ppendingInst = pCodecInst;
    return RETCODE_SUCCESS;
}

/*!
 * @brief Get the information of output of decoding.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param info [Output] Pointer to DecOutputInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM Info is an invalid pointer.
 */
RetCode VPU_DecGetOutputInfo(DecHandle handle, DecOutputInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    uint32_t val = 0;
    uint32_t val2 = 0;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (info == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (*ppendingInst == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (pCodecInst != *ppendingInst) {
        return RETCODE_INVALID_HANDLE;
    }

    memset(info, 0, sizeof(DecOutputInfo));

    /* Clock is gated off when received interrupt in driver, so need to gate on here. */

    val = VpuReadReg(RET_DEC_PIC_SUCCESS);
    info->decodingSuccess = (val & 0x01);

    if (cpu_is_mx6q()) {
        if (val & (1 << 31)) {
            *ppendingInst = 0;
            return RETCODE_MEMORY_ACCESS_VIOLATION;
        }
        if (pDecInfo->openParam.bitstreamMode && (val & (1 << 4)))
            info->decodingSuccess |= 0x10;
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        info->notSufficientPsBuffer = (val >> 3) & 0x1;
        info->notSufficientSliceBuffer = (val >> 2) & 0x1;
    } else if (pCodecInst->codecMode == MP4_DEC) {
        info->mp4PackedPBframe = ((val >> 16) & 0x01);
        /* Need to backup WR_PTR for mp4PackedPBframe */
        if (info->mp4PackedPBframe)
            pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = VpuReadReg(BIT_WR_PTR);
    }

    val = VpuReadReg(RET_DEC_PIC_SIZE); /* decoding picture size */
    info->decPicHeight = val & 0xFFFF;
    info->decPicWidth = (val >> 16) & 0xFFFF;

    if (cpu_is_mx6q()) {
        info->frameStartPos = VpuReadReg(BIT_BYTE_POS_FRAME_START);
        info->frameEndPos = VpuReadReg(BIT_BYTE_POS_FRAME_END);
        if (info->frameEndPos > (int32_t) pDecInfo->streamBufEndAddr) {
            info->consumedByte = pDecInfo->streamBufEndAddr - info->frameStartPos;
            info->consumedByte += info->frameEndPos - pDecInfo->streamBufStartAddr;
        } else
            info->consumedByte = info->frameEndPos - info->frameStartPos;
    }

    if (cpu_is_mx6q() && pCodecInst->codecMode == VC1_DEC) {
        val = VpuReadReg(RET_DEC_PIC_POST);
        info->hScaleFlag = val >> 1 & 1;
        info->vScaleFlag = val >> 2 & 1;

        if (info->hScaleFlag)
            info->decPicWidth = pDecInfo->initialInfo.picWidth / 2;
        if (info->vScaleFlag)
            info->decPicHeight = pDecInfo->initialInfo.picHeight / 2;
    }

    if (pCodecInst->codecMode == VPX_DEC && pCodecInst->codecModeAux == VPX_AUX_VP8) {
        /* VP8 specific header information */
        /* h_scale[31:30] v_scale[29:28] pic_width[27:14] pic_height[13:0] */
        val = VpuReadReg(RET_DEC_PIC_VP8_SCALE_INFO);
        info->vp8ScaleInfo.hScaleFactor = (val >> 30) & 0x03;
        info->vp8ScaleInfo.vScaleFactor = (val >> 28) & 0x03;
        info->vp8ScaleInfo.picWidth = (val >> 14) & 0x3FFF;
        info->vp8ScaleInfo.picHeight = (val >> 0) & 0x3FFF;
        /* ref_idx_gold[31:24], ref_idx_altr[23:16], ref_idx_last[15: 8], */
        /* version_number[3:1], show_frame[0] */
        val = VpuReadReg(RET_DEC_PIC_VP8_PIC_REPORT);
        info->vp8PicInfo.refIdxGold = (val >> 24) & 0x0FF;
        info->vp8PicInfo.refIdxAltr = (val >> 16) & 0x0FF;
        info->vp8PicInfo.refIdxLast = (val >> 8) & 0x0FF;
        info->vp8PicInfo.versionNumber = (val >> 1) & 0x07;
        info->vp8PicInfo.showFrame = (val >> 0) & 0x01;
    }

    /* frame crop information */
    if (pCodecInst->codecMode == AVC_DEC) {
        val = VpuReadReg(RET_DEC_PIC_CROP_LEFT_RIGHT);
        val2 = VpuReadReg(RET_DEC_PIC_CROP_TOP_BOTTOM);
        if (val == 0xFFFFFFFF && val2 == 0xFFFFFFFF) {
            /* Keep current crop information */
        } else if (val == 0 && val2 == 0) {
            info->decPicCrop.left = 0;
            info->decPicCrop.right = 0;
            info->decPicCrop.top = 0;
            info->decPicCrop.bottom = 0;
        } else {
            info->decPicCrop.left = ((val >> 16) & 0xFFFF);
            info->decPicCrop.right = info->decPicWidth - ((val & 0xFFFF));
            info->decPicCrop.top = ((val2 >> 16) & 0xFFFF);
            info->decPicCrop.bottom = info->decPicHeight - ((val2 & 0xFFFF));
        }
    } else {
        info->decPicCrop.left = 0;
        info->decPicCrop.right = 0;
        info->decPicCrop.top = 0;
        info->decPicCrop.bottom = 0;
    }

    val = VpuReadReg(RET_DEC_PIC_TYPE);

    if (pCodecInst->codecMode == VC1_DEC && pDecInfo->initialInfo.profile == 2) /* VC1 AP propile */
        info->picType = val & 0x3f;
    else
        info->picType = val & 0x7;
    if (cpu_is_mx6q()) {
        info->picTypeFirst = (val & 0x38) >> 3;
        info->idrFlg = (val & 0xC0) >> 6;
    }
    info->interlacedFrame = (val >> 16) & 0x1;

    info->h264Npf = (val >> 16) & 0x3;
    info->interlacedFrame = (val >> 18) & 0x1;
    info->pictureStructure = (val >> 19) & 0x0003;  /* MbAffFlag[17], FieldPicFlag[16] */
    info->topFieldFirst = (val >> 21) & 0x0001; /* TopFieldFirst[18] */
    info->repeatFirstField = (val >> 22) & 0x0001;
    if (pCodecInst->codecMode == VC1_DEC)
        info->vc1_repeatFrame = (val >> 23) & 0x0003;
    else
        info->progressiveFrame = (val >> 23) & 0x0003;
    info->fieldSequence = (val >> 25) & 0x0007;

    if (cpu_is_mx6q()) {
        info->frameRateRes = VpuReadReg(RET_DEC_PIC_FRATE_NR);
        info->frameRateDiv = VpuReadReg(RET_DEC_PIC_FRATE_DR);
        if (pCodecInst->codecMode == AVC_DEC && info->frameRateDiv)
            info->frameRateDiv *= 2;
        if (pCodecInst->codecMode == VPX_DEC)
            info->aspectRateInfo = 0;
        else
            info->aspectRateInfo = VpuReadReg(RET_DEC_PIC_ASPECT);
    }

    info->numOfErrMBs = VpuReadReg(RET_DEC_PIC_ERR_MB);
    if (!cpu_is_mx6q())
        info->prescanresult = VpuReadReg(RET_DEC_PIC_OPTION);

    info->indexFrameDisplay = VpuReadReg(RET_DEC_PIC_FRAME_IDX);
    info->indexFrameDecoded = VpuReadReg(RET_DEC_PIC_CUR_IDX);
    info->NumDecFrameBuf = VpuReadReg(RET_DEC_PIC_FRAME_NEED);

    /* save decoded picType to this array */
    if (info->indexFrameDecoded >= 0)
        decoded_pictype[info->indexFrameDecoded] = info->picType;

    if (pCodecInst->codecMode == VC1_DEC && info->indexFrameDisplay != -3) {
        if (pDecInfo->vc1BframeDisplayValid == 0) {
            /* Check the pictype of displayed frame */
            if ((decoded_pictype[info->indexFrameDisplay] == 3
                 && pDecInfo->initialInfo.profile != 2)
                || ((decoded_pictype[info->indexFrameDisplay] >> 3) == 3
                    && pDecInfo->initialInfo.profile == 2)) {
                /* clear buffer for not displayed B frame */
                val = ~(1 << info->indexFrameDisplay);
                val &= VpuReadReg(BIT_FRM_DIS_FLG);
                VpuWriteReg(BIT_FRM_DIS_FLG, val);
                info->indexFrameDisplay = -3;
            } else {
                pDecInfo->vc1BframeDisplayValid = 1;
            }
        }
    }

    if (pCodecInst->codecMode == AVC_DEC && pCodecInst->codecModeAux == AVC_AUX_MVC) {
        val = VpuReadReg(RET_DEC_PIC_MVC_REPORT);
        info->mvcPicInfo.viewIdxDisplay = val & 1;
        info->mvcPicInfo.viewIdxDecoded = (val >> 1) & 1;
    }

    if (cpu_is_mx6q() && (pCodecInst->codecMode == AVC_DEC)) {
        val = VpuReadReg(RET_DEC_PIC_AVC_FPA_SEI0);

        if (val < 0)
            info->avcFpaSei.exist = 0;
        else {
            info->avcFpaSei.exist = 1;
            info->avcFpaSei.frame_packing_arrangement_id = val & 0x7FFFFFFF;

            val = VpuReadReg(RET_DEC_PIC_AVC_FPA_SEI1);
            info->avcFpaSei.content_interpretation_type = val & 0x3F;
            info->avcFpaSei.frame_packing_arrangement_type = (val >> 6) & 0x7F;
            info->avcFpaSei.frame_packing_arrangement_ext_flag = (val >> 13) & 0x01;
            info->avcFpaSei.frame1_self_contained_flag = (val >> 14) & 0x01;
            info->avcFpaSei.frame0_self_contained_flag = (val >> 15) & 0x01;
            info->avcFpaSei.current_frame_is_frame0_flag = (val >> 16) & 0x01;
            info->avcFpaSei.field_views_flag = (val >> 17) & 0x01;
            info->avcFpaSei.frame0_flipped_flag = (val >> 18) & 0x01;
            info->avcFpaSei.spatial_flipping_flag = (val >> 19) & 0x01;
            info->avcFpaSei.quincunx_sampling_flag = (val >> 20) & 0x01;
            info->avcFpaSei.frame_packing_arrangement_cancel_flag = (val >> 21) & 0x01;

            val = VpuReadReg(RET_DEC_PIC_AVC_FPA_SEI2);
            info->avcFpaSei.frame_packing_arrangement_repetition_period = val & 0x7FFF;
            info->avcFpaSei.frame1_grid_position_y = (val >> 16) & 0x0F;
            info->avcFpaSei.frame1_grid_position_x = (val >> 20) & 0x0F;
            info->avcFpaSei.frame0_grid_position_y = (val >> 24) & 0x0F;
            info->avcFpaSei.frame0_grid_position_x = (val >> 28) & 0x0F;
        }
    }

    /* Backup context regs, no need to save BIT_WR_PTR
       and BIT_FRAME_MEM_CTRL since f/w doesn't update the registers */
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = VpuReadReg(BIT_FRM_DIS_FLG);
    pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = VpuReadReg(BIT_RD_PTR);
    pCodecInst->ctxRegs[CTX_BIT_STREAM_PARAM] = VpuReadReg(BIT_BIT_STREAM_PARAM);

    if (pCodecInst->codecMode == VC1_DEC) {
        val = VpuReadReg(RET_DEC_PIC_POST);
        info->hScaleFlag = (val >> 1) & 1;
        info->vScaleFlag = (val >> 2) & 1;
        info->indexFrameRangemap = -1;
        if (val & 1)
            info->indexFrameRangemap = (val >> 3) & 31;
    }

    *ppendingInst = 0;

    /* Workaround for multi-instances competition */
    //hal_delay_us(10000);

    return RETCODE_SUCCESS;
}

RetCode VPU_DecBitBufferFlush(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (cpu_is_mx6q())
        pCodecInst->ctxRegs[CTX_BIT_RD_PTR] = pDecInfo->streamBufStartAddr;

    BitIssueCommand(pCodecInst, DEC_BUF_FLUSH);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    pDecInfo->streamWrPtr = pDecInfo->streamBufStartAddr;

    VpuWriteReg(BIT_WR_PTR, pDecInfo->streamBufStartAddr);
    /* Backup context reg */
    pCodecInst->ctxRegs[CTX_BIT_WR_PTR] = pDecInfo->streamBufStartAddr;

    return RETCODE_SUCCESS;
}

RetCode VPU_DecClrDispFlag(DecHandle handle, int32_t index)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    int32_t val;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if ((index < 0) || (index > (pDecInfo->numFrameBuffers - 1)))
        return RETCODE_INVALID_PARAM;

    val = (~(1 << index) & pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG]);
    pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG] = val;

    return RETCODE_SUCCESS;
}

static int BitCount(uint32_t u32)
{
    uint32_t tmp = u32 - ((u32 >> 1) & 033333333333) - ((u32 >> 2) & 011111111111);
    tmp = ((tmp + (tmp >> 3)) & 030707070707);
    tmp = (tmp + (tmp >> 6));
    tmp = (tmp + (tmp >> 12) + (tmp >> 24)) & 077;

    return ((int)tmp);
}

/*!
 * check the VPU decoder buffer status. if there is avaible buffer for output,
 * VPU can start to decode the next frame, or else, skip this loop and wait 
 * untill available.
 */
RetCode VPU_DecBufferCheck(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    int val;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /*Note: the maximum buffer number is less than 32. */
    val = ((1 << pDecInfo->numFrameBuffers) - 1) & (~pCodecInst->ctxRegs[CTX_BIT_FRM_DIS_FLG]);
    val = BitCount(val);
    if (val <= 2)
        return RETCODE_FAILURE;
    else
        return RETCODE_SUCCESS;

}

/*!
 * @brief Give command to the decoder.
 *
 * @param handle [Input] The handle obtained from VPU_DecOpen().
 * @param cmd [Intput] Command.
 * @param param [Intput/Output] param  for cmd.
 *
 * @return
 * @li RETCODE_INVALID_COMMANDcmd is not valid.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode VPU_DecGiveCommand(DecHandle handle, CodecCommand cmd, void *param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    switch (cmd) {
    case ENABLE_ROTATION:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->rotationEnable = 1;
            break;
        }

    case DISABLE_ROTATION:
        {
            pDecInfo->rotationEnable = 0;
            break;
        }

    case ENABLE_MIRRORING:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->mirrorEnable = 1;
            break;
        }

    case DISABLE_MIRRORING:
        {
            pDecInfo->mirrorEnable = 0;
            break;
        }

    case SET_MIRROR_DIRECTION:
        {
            MirrorDirection mirDir;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            mirDir = *(MirrorDirection *) param;
            if (mirDir < MIRDIR_NONE || mirDir > MIRDIR_HOR_VER) {
                return RETCODE_INVALID_PARAM;
            }
            pDecInfo->mirrorDirection = mirDir;
            break;
        }

    case SET_ROTATION_ANGLE:
        {
            int32_t angle;
            int32_t height, width;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            angle = *(int32_t *) param;
            if (angle != 0 && angle != 90 && angle != 180 && angle != 270) {
                return RETCODE_INVALID_PARAM;
            }
            if (pDecInfo->rotatorStride != 0) {
                height = pDecInfo->initialInfo.picHeight;
                width = pDecInfo->initialInfo.picWidth;

                if (angle == 90 || angle == 270) {
                    if (height > pDecInfo->rotatorStride) {
                        return RETCODE_INVALID_PARAM;
                    }
                } else {
                    if (width > pDecInfo->rotatorStride) {
                        return RETCODE_INVALID_PARAM;
                    }
                }
            }

            pDecInfo->rotationAngle = angle;
            break;
        }

    case SET_ROTATOR_OUTPUT:
        {
            FrameBuffer *frame;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            frame = (FrameBuffer *) param;
            pDecInfo->rotatorOutput = *frame;
            pDecInfo->rotatorOutputValid = 1;
            break;
        }

    case SET_ROTATOR_STRIDE:
        {
            int32_t stride;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            stride = *(int32_t *) param;
            if (stride % 8 != 0 || stride == 0) {
                return RETCODE_INVALID_STRIDE;
            }
            if (pDecInfo->rotationAngle == 90 || pDecInfo->rotationAngle == 270) {
                if (pDecInfo->initialInfo.picHeight > stride) {
                    return RETCODE_INVALID_STRIDE;
                }
            } else {
                if (pDecInfo->initialInfo.picWidth > stride) {
                    return RETCODE_INVALID_STRIDE;
                }
            }

            pDecInfo->rotatorStride = stride;
            break;
        }

    case DEC_SET_SPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_DEC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            SetParaSet(handle, 0, param);
            break;
        }

    case DEC_SET_PPS_RBSP:
        {
            if (pCodecInst->codecMode != AVC_DEC) {
                return RETCODE_INVALID_COMMAND;
            }
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            SetParaSet(handle, 1, param);
            break;
        }

    case DEC_SET_DEBLOCK_OUTPUT:
        {
            break;
        }
    case ENABLE_DERING:
        {
            if (!pDecInfo->rotatorOutputValid) {
                return RETCODE_ROTATOR_OUTPUT_NOT_SET;
            }
            if (pDecInfo->rotatorStride == 0) {
                return RETCODE_ROTATOR_STRIDE_NOT_SET;
            }
            pDecInfo->deringEnable = 1;
            break;
        }

    case DISABLE_DERING:
        {
            pDecInfo->deringEnable = 0;
            break;
        }

    case SET_DBK_OFFSET:
        {
            DbkOffset dbkOffset;
            dbkOffset = *(DbkOffset *) param;

            pDecInfo->dbkOffset.DbkOffsetA = dbkOffset.DbkOffsetA;
            pDecInfo->dbkOffset.DbkOffsetB = dbkOffset.DbkOffsetB;

            pDecInfo->dbkOffset.DbkOffsetEnable =
                ((pDecInfo->dbkOffset.DbkOffsetA != 0) && (pDecInfo->dbkOffset.DbkOffsetB != 0));
            break;
        }

    case DEC_SET_REPORT_BUFSTAT:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportFrameBufStat = *(DecReportInfo *) param;

            if (pDecInfo->decReportFrameBufStat.enable && !pDecInfo->decReportFrameBufStat.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_MBINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportMBInfo = *(DecReportInfo *) param;

            if (pDecInfo->decReportMBInfo.enable && !pDecInfo->decReportMBInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_MVINFO:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportMVInfo = *(DecReportInfo *) param;
            if (pDecInfo->decReportMVInfo.enable && !pDecInfo->decReportMVInfo.addr)
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    case DEC_SET_REPORT_USERDATA:
        {
            if (param == 0)
                return RETCODE_INVALID_PARAM;
            pDecInfo->decReportUserData = *(DecReportInfo *) param;
            if ((pDecInfo->decReportUserData.enable) && (!pDecInfo->decReportUserData.addr))
                return RETCODE_REPORT_BUF_NOT_SET;
            break;
        }

    default:
        return RETCODE_INVALID_COMMAND;
    }

    return RETCODE_SUCCESS;
}

RetCode VPU_EnableInterrupt(int32_t sel)
{
    VpuWriteReg(BIT_INT_ENABLE, 1 << sel);

    return RETCODE_SUCCESS;
}

RetCode VPU_ClearInterrupt(void)
{
    VpuWriteReg(BIT_INT_CLEAR, 1);

    return RETCODE_SUCCESS;
}
