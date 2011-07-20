/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 * Copyright (c) 2006, Chips & Media.  All rights reserved.
 */
/*
 * The code contained herein is licensed under the GNU Lesser General
 * Public License.  You may obtain a copy of the GNU Lesser General
 * Public License Version 2.1 or later at the following locations:
 *
 * http://www.opensource.org/licenses/lgpl-license.html
 * http://www.gnu.org/copyleft/lgpl.html
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

#include "vpu_reg.h"
#include "vpu_lib.h"
#include "vpu_util.h"
#include "vpu_io.h"
#include "vpu_debug.h"

#if defined(IMX37_3STACK)
#define IMAGE_ENDIAN			1
#define STREAM_ENDIAN			1
#else
#define IMAGE_ENDIAN			0
#define STREAM_ENDIAN			0
#endif

unsigned int system_rev = 0x53 << 12;
extern const unsigned short bit_code[];
static PhysicalAddress rdPtrRegAddr[] = {
    BIT_RD_PTR_0,
    BIT_RD_PTR_1,
    BIT_RD_PTR_2,
    BIT_RD_PTR_3
};

static PhysicalAddress wrPtrRegAddr[] = {
    BIT_WR_PTR_0,
    BIT_WR_PTR_1,
    BIT_WR_PTR_2,
    BIT_WR_PTR_3
};

static PhysicalAddress disFlagRegAddr[] = {
    BIT_FRM_DIS_FLG_0,
    BIT_FRM_DIS_FLG_1,
    BIT_FRM_DIS_FLG_2,
    BIT_FRM_DIS_FLG_3
};

/* If a frame is started, pendingInst is set to the proper instance. */
static CodecInst **ppendingInst;

Uint32 virt_codeBuf;
unsigned long *virt_paraBuf;
unsigned long *virt_paraBuf2;

extern vpu_mem_desc bit_work_addr;
extern semaphore_t *vpu_semap;

static int decoded_pictype[32];

/*!
 * @brief
 * This functure indicate whether processing(encoding/decoding) a frame
 * is completed or not yet.
 *
 * @return
 * @li 0: VPU hardware is idle.
 * @li Non-zero value: VPU hardware is busy processing a frame.
 */
int vpu_IsBusy()
{
    int vpu_busy;

    ENTER_FUNC();

    vpu_busy = VpuReadReg(BIT_BUSY_FLAG);

    return vpu_busy != 0;
}

int vpu_WaitForInt(int timeout_in_ms)
{
    ENTER_FUNC();

    hal_delay_us(timeout_in_ms * 10);

    return 0;
}

/*!
 * @brief VPU initialization.
 * This function initializes VPU hardware and proper data structures/resources.
 * The user must call this function only once before using VPU codec.
 *
 * @param  cb  callback function if needed
 *
 * @return  This function always returns RETCODE_SUCCESS.
 */
RetCode vpu_Init(void *cb)
{
    int i, err;
    volatile Uint32 data;
    PhysicalAddress workBuffer, codeBuffer, paraBuffer;

    ENTER_FUNC();

    err = IOSystemInit(cb);
    if (err) {
        err_msg("IOSystemInit() failure.\n");
        return RETCODE_FAILURE;
    }

    if (!LockVpu(vpu_semap)) {
        err = IOSystemShutdown();
        return RETCODE_FAILURE_TIMEOUT;
    }
    codeBuffer = bit_work_addr.phy_addr;
    workBuffer = codeBuffer + CODE_BUF_SIZE;
    paraBuffer = workBuffer + WORK_BUF_SIZE + PARA_BUF2_SIZE;

    virt_codeBuf = (Uint32) (bit_work_addr.virt_uaddr);
    virt_paraBuf = (unsigned long *)(virt_codeBuf + CODE_BUF_SIZE + WORK_BUF_SIZE + PARA_BUF2_SIZE);
    virt_paraBuf2 = (unsigned long *)(virt_codeBuf + CODE_BUF_SIZE + WORK_BUF_SIZE);

    ppendingInst = (CodecInst **) (&vpu_semap->pendingInst);

    if (!isVpuInitialized()) {
        if (DownloadBitCodeTable((unsigned long *)virt_codeBuf) != RETCODE_SUCCESS) {
            return RETCODE_FAILURE;
        }

        VpuWriteReg(BIT_WORK_BUF_ADDR, workBuffer);
        VpuWriteReg(BIT_PARA_BUF_ADDR, paraBuffer);
        VpuWriteReg(BIT_CODE_BUF_ADDR, codeBuffer);

        if (!cpu_is_mx5x())
            VpuWriteReg(BIT_RESET_CTRL, 0);

        VpuWriteReg(BIT_BIT_STREAM_PARAM, 0);

        VpuWriteReg(BIT_CODE_RUN, 0);

        /* Download BIT Microcode to Program Memory */
        for (i = 0; i < 2048; ++i) {
            data = bit_code[i];
            VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data);
        }

        data = STREAM_ENDIAN | STREAM_FULL_EMPTY_CHECK_DISABLE << BIT_BUF_CHECK_DIS;
        data |= BUF_PIC_FLUSH << BIT_BUF_PIC_FLUSH | BUF_PIC_RESET << BIT_BUF_PIC_RESET;
        VpuWriteReg(BIT_BIT_STREAM_CTRL, data);
        VpuWriteReg(BIT_FRAME_MEM_CTRL, IMAGE_ENDIAN);
        VpuWriteReg(BIT_INT_ENABLE, 8); /* PIC_RUN irq enable */

        if (cpu_is_mx5x())
            VpuWriteReg(BIT_AXI_SRAM_USE, 0);   /* init to not use SRAM */

        VpuWriteReg(BIT_BUSY_FLAG, 1);
        VpuWriteReg(BIT_CODE_RUN, 1);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    EXIT_FUNC();
    return RETCODE_SUCCESS;
}

void vpu_UnInit(void)
{
    IOSystemShutdown();
}

/*
 * This function resets the VPU instance specified by handle or index that
 * exists in the current thread. If handle is not NULL, the index will be
 * ignored and the instance of handle will be reset; otherwise, vpu will only
 * clean the instance record per index, not do real vpu reset.
 */
RetCode vpu_SWReset(DecHandle handle, int index)
{
    static unsigned int regBk[64];
    int i = 0;
    CodecInst *pCodecInst;
    RetCode ret;

    ENTER_FUNC();

    info_msg("vpu_SWReset");
    if (handle == NULL) {
        if (index < 0 || index >= MAX_NUM_INSTANCE)
            return RETCODE_FAILURE;

        /* Free instance info per index */
        pCodecInst = (CodecInst *) (&vpu_semap->codecInstPool[index]);
        if (pCodecInst == NULL)
            warn_msg("The instance is freed\n");
        else {
            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;
            FreeCodecInstance(pCodecInst);
            UnlockVpu(vpu_semap);
        }
        return RETCODE_SUCCESS;
    }

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS) {
        ret = CheckEncInstanceValidity(handle);
        if (ret != RETCODE_SUCCESS)
            return ret;
    }

    pCodecInst = handle;

    if (*ppendingInst && (pCodecInst != *ppendingInst))
        return RETCODE_FAILURE;
    else {
        /* Need to unlock VPU since mutex is locked when StartOneFrame */
        UnlockVpu(vpu_semap);
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    for (i = 0; i < 64; i++)
        regBk[i] = VpuReadReg(BIT_CODE_BUF_ADDR + (i * 4));
    //IOSysSWReset();//removed by Ray
    for (i = 0; i < 64; i++)
        VpuWriteReg(BIT_CODE_BUF_ADDR + (i * 4), regBk[i]);
    VpuWriteReg(BIT_CODE_RUN, 0);

    Uint32 *p = (Uint32 *) virt_codeBuf;
    Uint32 data;
    Uint16 data_hi;
    Uint16 data_lo;
    if (cpu_is_mx5x()) {
        for (i = 0; i < 2048; i += 4) {
            data = p[(i / 2) + 1];
            data_hi = (data >> 16) & 0xFFFF;
            data_lo = data & 0xFFFF;
            VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data_hi);
            VpuWriteReg(BIT_CODE_DOWN, ((i + 1) << 16) | data_lo);

            data = p[i / 2];
            data_hi = (data >> 16) & 0xFFFF;
            data_lo = data & 0xFFFF;
            VpuWriteReg(BIT_CODE_DOWN, ((i + 2) << 16) | data_hi);
            VpuWriteReg(BIT_CODE_DOWN, ((i + 3) << 16) | data_lo);
        }
    } else {
        for (i = 0; i < 2048; i += 2) {
            if (cpu_is_mx37())
                data = swab32(p[i / 2]);
            else
                data = p[i / 2];
            data_hi = (data >> 16) & 0xFFFF;
            data_lo = data & 0xFFFF;

            VpuWriteReg(BIT_CODE_DOWN, (i << 16) | data_hi);
            VpuWriteReg(BIT_CODE_DOWN, ((i + 1) << 16) | data_lo);
        }
    }

    VpuWriteReg(BIT_BUSY_FLAG, 1);
    VpuWriteReg(BIT_CODE_RUN, 1);
    while (vpu_IsBusy()) ;

    BitIssueCommand(0, 0, VPU_WAKE);
    while (vpu_IsBusy()) ;

    /* The handle cannot be used after restore */
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get VPU Firmware Version.
 */
RetCode vpu_GetVersionInfo(vpu_versioninfo * verinfo)
{
    Uint32 ver;
    Uint16 pn, version;
    RetCode ret = RETCODE_SUCCESS;
    char productstr[18] = { 0 };

    ENTER_FUNC();

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    VpuWriteReg(RET_VER_NUM, 0);

    BitIssueCommand(0, 0, FIRMWARE_GET);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    ver = VpuReadReg(RET_VER_NUM);
    UnlockVpu(vpu_semap);

    if (ver == 0)
        return RETCODE_FAILURE;

    pn = (Uint16) (ver >> 16);
    version = (Uint16) ver;

    switch (pn) {
    case PRJ_TRISTAN:
    case PRJ_TRISTAN_REV:
        strcpy(productstr, "i.MX27");
        break;
    case PRJ_PRISM_CX:
    case PRJ_PRISM_EX:
    case PRJ_BODA_CX_4:
    case PRJ_BODA_DX_4V:
        strcpy(productstr, "i.MX32");
        break;
    case PRJ_BODADX7X:
        strcpy(productstr, "i.MX37");
        break;
    case PRJ_CODAHX_14:
        strcpy(productstr, "i.MX51");
        break;
    case PRJ_CODA7541:
        strcpy(productstr, "i.MX53");
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

        verinfo->lib_major = (VPU_LIB_VERSION_CODE >> (12)) & 0x0f;
        verinfo->lib_minor = (VPU_LIB_VERSION_CODE >> (8)) & 0x0f;
        verinfo->lib_release = (VPU_LIB_VERSION_CODE) & 0xff;
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
RetCode vpu_EncOpen(EncHandle * pHandle, EncOpenParam * pop)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    int instIdx;
    RetCode ret;
    Uint32 val;

    ENTER_FUNC();

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    ret = CheckEncOpenParam(pop);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    ret = GetCodecInstance(&pCodecInst);
    if (ret == RETCODE_FAILURE) {
        *pHandle = 0;
        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }
    UnlockVpu(vpu_semap);

    *pHandle = pCodecInst;
    instIdx = pCodecInst->instIndex;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    pEncInfo->openParam = *pop;

    if ((pop->bitstreamFormat == STD_MPEG4) || (pop->bitstreamFormat == STD_H263))
        pCodecInst->codecMode = MP4_ENC;
    else if (pop->bitstreamFormat == STD_AVC)
        pCodecInst->codecMode = AVC_ENC;
    else if (pop->bitstreamFormat == STD_MJPG)
        pCodecInst->codecMode = MJPG_ENC;

    pEncInfo->streamRdPtr = pop->bitstreamBuffer;
    pEncInfo->streamRdPtrRegAddr = rdPtrRegAddr[instIdx];
    pEncInfo->streamWrPtrRegAddr = wrPtrRegAddr[instIdx];
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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    VpuWriteReg(pEncInfo->streamRdPtrRegAddr, pEncInfo->streamRdPtr);
    VpuWriteReg(pEncInfo->streamWrPtrRegAddr, pEncInfo->streamBufStartAddr);

    val = VpuReadReg(BIT_BIT_STREAM_CTRL);
    val &= ~BITS_STREAMCTRL_MASK;
    val |= (STREAM_ENDIAN | STREAM_FULL_EMPTY_CHECK_DISABLE << BIT_BUF_CHECK_DIS);
    if (pEncInfo->ringBufferEnable == 0) {
        val |= (pEncInfo->dynamicAllocEnable << BIT_ENC_DYN_BUFALLOC_EN);
        val |= 1 << BIT_BUF_PIC_RESET;
    } else {
        val |= 1 << BIT_BUF_PIC_FLUSH;
    }

    VpuWriteReg(BIT_BIT_STREAM_CTRL, val);

    val = VpuReadReg(BIT_FRAME_MEM_CTRL) & ~(1 << (instIdx + 2));
    VpuWriteReg(BIT_FRAME_MEM_CTRL, val | (pEncInfo->openParam.chromaInterleave << (instIdx + 2)));
    UnlockVpu(vpu_semap);

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
RetCode vpu_EncClose(EncHandle handle)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;

    if (*ppendingInst == pCodecInst) {
        return RETCODE_FRAME_NOT_COMPLETE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (pEncInfo->initialInfoObtained) {
        BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SEQ_END);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    /* Free memory allocated for data report functions */
    IOFreeMem(&pEncInfo->picParaBaseMem);

    /* Free searchRam if searchRam doesn't use IRAM */
    if ((pEncInfo->secAxiUse.useHostMeEnable == 0) && (pEncInfo->secAxiUse.searchRamAddr))
        IOFreeMem(&pEncInfo->searchRamMem);

    FreeCodecInstance(pCodecInst);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief user could allocate frame buffers
 * according to the information obtained from this function.
 * @param handle [Input] The handle obtained from vpu_EncOpen().
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
RetCode vpu_EncGetInitialInfo(EncHandle handle, EncInitialInfo * info)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    EncOpenParam *pEncOP;
    int picWidth;
    int picHeight;
    Uint32 data, *tableBuf;
    int i;
    SetIramParam iramParam;
    RetCode ret;

    ENTER_FUNC();

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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    data = (picWidth << BIT_PIC_WIDTH_OFFSET) | picHeight;
    VpuWriteReg(CMD_ENC_SEQ_SRC_SIZE, data);
    VpuWriteReg(CMD_ENC_SEQ_SRC_F_RATE, pEncOP->frameRateInfo);

    if (pEncOP->bitstreamFormat == STD_MPEG4) {
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
        if (cpu_is_mx5x())
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 8);
        else
            VpuWriteReg(CMD_ENC_SEQ_COD_STD, 1);
        data = pEncOP->EncStdParam.h263Param.h263_annexJEnable << 2 |
            pEncOP->EncStdParam.h263Param.h263_annexKEnable << 1 |
            pEncOP->EncStdParam.h263Param.h263_annexTEnable;
        VpuWriteReg(CMD_ENC_SEQ_263_PARA, data);
    } else if (pEncOP->bitstreamFormat == STD_AVC) {
        VpuWriteReg(CMD_ENC_SEQ_COD_STD, 2);
        data = (pEncOP->EncStdParam.avcParam.avc_deblkFilterOffsetBeta &
                15) << 12 |
            (pEncOP->EncStdParam.avcParam.avc_deblkFilterOffsetAlpha
             & 15) << 8 |
            pEncOP->EncStdParam.avcParam.avc_disableDeblk << 6 |
            pEncOP->EncStdParam.avcParam.avc_constrainedIntraPredFlag
            << 5 | (pEncOP->EncStdParam.avcParam.avc_chromaQpOffset & 31);
        VpuWriteReg(CMD_ENC_SEQ_264_PARA, data);
    } else if (pEncOP->bitstreamFormat == STD_MJPG) {
        VpuWriteReg(CMD_ENC_SEQ_JPG_PARA,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_sourceFormat);
        VpuWriteReg(CMD_ENC_SEQ_JPG_RST_INTERVAL,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_restartInterval);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_EN,
                    pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_thumbNailEnable);
        data =
            (pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_thumbNailWidth) << 16 | (pEncInfo->
                                                                                     openParam.
                                                                                     EncStdParam.
                                                                                     mjpgParam.
                                                                                     mjpg_thumbNailHeight);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_SIZE, data);
        VpuWriteReg(CMD_ENC_SEQ_JPG_THUMB_OFFSET, 0);

        tableBuf = (Uint32 *) pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_hufTable;
        for (i = 0; i < 108; i += 2) {
            virt_paraBuf[i + 1] = *tableBuf;
            virt_paraBuf[i] = *(tableBuf + 1);
            tableBuf += 2;
        }
        tableBuf = (Uint32 *) pEncInfo->openParam.EncStdParam.mjpgParam.mjpg_qMatTable;
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
        VpuWriteReg(CMD_ENC_SEQ_RC_PARA, data);
    } else {
        VpuWriteReg(CMD_ENC_SEQ_RC_PARA, 0);
    }

    VpuWriteReg(CMD_ENC_SEQ_RC_BUF_SIZE, pEncOP->vbvBufferSize);
    VpuWriteReg(CMD_ENC_SEQ_INTRA_REFRESH, pEncOP->intraRefresh);

    VpuWriteReg(CMD_ENC_SEQ_BB_START, pEncInfo->streamBufStartAddr);
    VpuWriteReg(CMD_ENC_SEQ_BB_SIZE, pEncInfo->streamBufSize / 1024);

    data = 0;
    if (cpu_is_mx27()) {
        data |= (pEncOP->sliceReport << 1) | pEncOP->mbReport;
        data |= (pEncOP->mbQpReport << 3);
    }
    if (pEncOP->rcIntraQp >= 0) {
        data |= (1 << 5);
        VpuWriteReg(CMD_ENC_SEQ_INTRA_QP, pEncOP->rcIntraQp);
    }
    if (pCodecInst->codecMode == AVC_ENC) {
        data |= (pEncOP->EncStdParam.avcParam.avc_audEnable << 2);
        data |= (pEncOP->EncStdParam.avcParam.avc_fmoEnable << 4);
    }
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
    if (pCodecInst->codecMode == AVC_ENC) {
        if (pEncOP->avcIntra16x16OnlyModeEnable)
            data |= (1 << 9);
    }

    VpuWriteReg(CMD_ENC_SEQ_OPTION, data);

    VpuWriteReg(CMD_ENC_SEQ_RC_INTERVAL_MODE,
                (pEncInfo->openParam.MbInterval << 2) | pEncInfo->openParam.RcIntervalMode);

    if (cpu_is_mx27() && (pCodecInst->codecMode == AVC_ENC)) {
        data = (pEncOP->EncStdParam.avcParam.avc_fmoType << 4) |
            (pEncOP->EncStdParam.avcParam.avc_fmoSliceNum & 0x0f);
        data |= (FMO_SLICE_SAVE_BUF_SIZE << 7);
        VpuWriteReg(CMD_ENC_SEQ_FMO, data);
    }

    /* Set secondAXI IRAM */
    iramParam.width = pEncOP->picWidth;
    SetEncSecondAXIIRAM(&pEncInfo->secAxiUse, &iramParam);
    /* Use external memory if IRAM is disabled for searchMe */
    if (pEncInfo->secAxiUse.useHostMeEnable == 0) {
        pEncInfo->searchRamMem.size = pEncInfo->secAxiUse.searchRamSize;
        IOGetMem(&pEncInfo->searchRamMem);
        pEncInfo->secAxiUse.searchRamAddr = pEncInfo->searchRamMem.phy_addr;
    }

    VpuWriteReg(CMD_ENC_SEARCH_BASE, pEncInfo->secAxiUse.searchRamAddr);
    VpuWriteReg(CMD_ENC_SEARCH_SIZE, pEncInfo->secAxiUse.searchRamSize);

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SEQ_INIT);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (VpuReadReg(RET_ENC_SEQ_SUCCESS) == 0) {
        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }
    UnlockVpu(vpu_semap);

    if (pCodecInst->codecMode == MJPG_ENC)
        info->minFrameBufferCount = 0;
    else
        info->minFrameBufferCount = 2;  /* reconstructed frame + reference frame */

    info->reportBufSize.sliceInfoBufSize = SIZE_SLICE_INFO;
    info->reportBufSize.mbInfoBufSize = SIZE_MB_DATA;
    info->reportBufSize.mvInfoBufSize = SIZE_MV_DATA;

    pEncInfo->initialInfo = *info;
    pEncInfo->initialInfoObtained = 1;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Registers frame buffers
 * @param handle [Input] The handle obtained from vpu_EncOpen().
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
RetCode vpu_EncRegisterFrameBuffer(EncHandle handle, FrameBuffer * bufArray,
                                   int num, int frameBufStride, int sourceBufStride)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    int i;
    RetCode ret;

    ENTER_FUNC();

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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (cpu_is_mx5x()) {
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
    } else {
        /* Let the codec know the addresses of the frame buffers. */
        for (i = 0; i < num; ++i) {
            virt_paraBuf[i * 3] = bufArray[i].bufY;
            virt_paraBuf[i * 3 + 1] = bufArray[i].bufCb;
            virt_paraBuf[i * 3 + 2] = bufArray[i].bufCr;
        }
    }

    /* Tell the codec how much frame buffers were allocated. */
    VpuWriteReg(CMD_SET_FRAME_BUF_NUM, num);
    VpuWriteReg(CMD_SET_FRAME_BUF_STRIDE, frameBufStride);
    VpuWriteReg(CMD_SET_FRAME_SOURCE_BUF_STRIDE, sourceBufStride);

    if (cpu_is_mx5x()) {
        VpuWriteReg(CMD_SET_FRAME_AXI_BIT_ADDR, pEncInfo->secAxiUse.bufBitUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_IPACDC_ADDR, pEncInfo->secAxiUse.bufIpAcDcUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_DBKY_ADDR, pEncInfo->secAxiUse.bufDbkYUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_DBKC_ADDR, pEncInfo->secAxiUse.bufDbkCUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_OVL_ADDR, pEncInfo->secAxiUse.bufOvlUse);
    }

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SET_FRAME_BUF);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

RetCode vpu_EncGetBitstreamBuffer(EncHandle handle,
                                  PhysicalAddress * prdPrt, PhysicalAddress * pwrPtr, Uint32 * size)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    Uint32 room;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (prdPrt == 0 || pwrPtr == 0 || size == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;
    rdPtr = pEncInfo->streamRdPtr;
    wrPtr = VpuReadReg(pEncInfo->streamWrPtrRegAddr);

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

RetCode vpu_EncUpdateBitstreamBuffer(EncHandle handle, Uint32 size)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    PhysicalAddress wrPtr;
    PhysicalAddress rdPtr;
    RetCode ret;
    int room = 0;

    ENTER_FUNC();

    ret = CheckEncInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pEncInfo = &pCodecInst->CodecInfo.encInfo;
    rdPtr = pEncInfo->streamRdPtr;

    wrPtr = VpuReadReg(pEncInfo->streamWrPtrRegAddr);
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

    VpuWriteReg(pEncInfo->streamRdPtrRegAddr, rdPtr);
    return RETCODE_SUCCESS;
}

/*!
 * @brief Starts encoding one frame.
 *
 * @param handle [Input] The handle obtained from vpu_EncOpen().
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
RetCode vpu_EncStartOneFrame(EncHandle handle, EncParam * param)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    FrameBuffer *pSrcFrame;
    Uint32 rotMirEnable;
    Uint32 rotMirMode;
    Uint32 val;
    RetCode ret;

    ENTER_FUNC();

    /* When doing pre-rotation, mirroring is applied first and rotation
     * later, vice versa when doing post-rotation.
     * For consistency, pre-rotation is converted to post-rotation
     * orientation.
     */
    static Uint32 rotatorModeConversion[] = {
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
    rotMirEnable = 0;
    rotMirMode = 0;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (pEncInfo->rotationEnable) {
        rotMirEnable = 0x10;    /* Enable rotator */
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
        rotMirEnable = 0x10;    /* Enable mirror */
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
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_Y, pSrcFrame->bufY +
                    param->encTopOffset * pSrcFrame->strideY + param->encLeftOffset);
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_CB, pSrcFrame->bufCb +
                    param->encTopOffset / 2 * pSrcFrame->strideC + param->encLeftOffset / 2);
        VpuWriteReg(CMD_ENC_PIC_SRC_ADDR_CR, pSrcFrame->bufCr +
                    param->encTopOffset / 2 * pSrcFrame->strideC + param->encLeftOffset / 2);

        VpuWriteReg(CMD_ENC_PIC_OPTION,
                    (pEncInfo->encReportSliceInfo.enable << 5) |
                    (pEncInfo->encReportMVInfo.enable << 4) |
                    (pEncInfo->encReportMBInfo.enable << 3) |
                    ((!param->enableAutoSkip) << 2) | (param->forceIPicture << 1 & 0x2));
    }

    if (pEncInfo->dynamicAllocEnable == 1) {
        VpuWriteReg(CMD_ENC_PIC_BB_START, param->picStreamBufferAddr);
        VpuWriteReg(CMD_ENC_PIC_BB_SIZE, param->picStreamBufferSize / 1024);
    }

    if (pEncInfo->encReportMBInfo.enable || pEncInfo->encReportMVInfo.enable ||
        pEncInfo->encReportSliceInfo.enable) {
        Uint32 *virt_addr, phy_addr;

        if (!pEncInfo->picParaBaseMem.phy_addr) {
            pEncInfo->picParaBaseMem.size = ENC_ADDR_END_OF_RPT_BUF;
            ret = IOGetMem(&pEncInfo->picParaBaseMem);
            if (ret) {
                err_msg("Unable to obtain physical mem\n");
                return RETCODE_FAILURE;
            }
        }

        VpuWriteReg(CMD_ENC_PIC_PARA_BASE_ADDR, pEncInfo->picParaBaseMem.phy_addr);

        virt_addr = (Uint32 *) pEncInfo->picParaBaseMem.virt_uaddr;
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

    val = (pEncInfo->secAxiUse.useBitEnable | pEncInfo->secAxiUse.useIpEnable << 1 |
           pEncInfo->secAxiUse.useDbkEnable << 2 | pEncInfo->secAxiUse.useOvlEnable << 3 |
           pEncInfo->secAxiUse.useMeEnable << 4 | pEncInfo->secAxiUse.useHostBitEnable << 7 |
           pEncInfo->secAxiUse.useHostIpEnable << 8 | pEncInfo->secAxiUse.useHostDbkEnable << 9 |
           pEncInfo->secAxiUse.useHostOvlEnable << 10 | pEncInfo->secAxiUse.useHostMeEnable << 11);
    VpuWriteReg(BIT_AXI_SRAM_USE, val);

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, PIC_RUN);

    *ppendingInst = pCodecInst;

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get information of the output of encoding.
 *
 * @param encHandle [Input] The handle obtained from vpu_EncOpen().
 * @param info [Output] Pointer to EncOutputInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM info is a null pointer.
 */
RetCode vpu_EncGetOutputInfo(EncHandle handle, EncOutputInfo * info)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    Uint32 val;

    ENTER_FUNC();

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

    val = VpuReadReg(RET_ENC_PIC_TYPE);
    info->skipEncoded = (val >> 2) & 0x01;
    info->picType = val & 0x03;

    if (pEncInfo->ringBufferEnable == 0) {
        if (pEncInfo->dynamicAllocEnable == 1) {
            rdPtr = VpuReadReg(CMD_ENC_PIC_BB_START);
        } else {
            rdPtr = pEncInfo->streamBufStartAddr;
        }

        wrPtr = VpuReadReg(pEncInfo->streamWrPtrRegAddr);
        info->bitstreamBuffer = rdPtr;
        info->bitstreamSize = wrPtr - rdPtr;
    }

    info->numOfSlices = VpuReadReg(RET_ENC_PIC_SLICE_NUM);
    info->bitstreamWrapAround = VpuReadReg(RET_ENC_PIC_FLAG);

    if (cpu_is_mx27()) {
        info->pSliceInfo = (Uint32 *) ((Uint32) virt_paraBuf + 0x1200);
        info->pMBInfo = virt_paraBuf;
        if (pCodecInst->codecMode == MP4_ENC && pEncInfo->openParam.mbQpReport == 1) {
            int widthInMB, heightInMB, readPnt, writePnt;
            Uint32 *virt_mbQpAddr;
            int i, j;
            Uint32 val1, val2;

            virt_mbQpAddr = (Uint32 *) ((Uint32) virt_paraBuf + 0x1300);
            widthInMB = pEncInfo->openParam.picWidth / 16;
            heightInMB = pEncInfo->openParam.picHeight / 16;
            writePnt = 0;
            for (i = 0; i < heightInMB; ++i) {
                readPnt = i * 32;
                for (j = 0; j < widthInMB; j += 4) {
                    val1 = virt_mbQpAddr[readPnt];
                    readPnt++;
                    val2 = virt_mbQpAddr[readPnt];
                    readPnt++;
                    val = (val1 << 8 & 0xff000000) | (val1 << 16) |
                        (val2 >> 8) | (val2 & 0x000000ff);
                    virt_paraBuf2[writePnt] = val;
                    writePnt++;
                }
            }
            info->pMBQpInfo = virt_paraBuf2;
        }
    }

    if (pEncInfo->encReportMBInfo.enable) {
        int size = 0;
        Uint32 tempBuf[2], address = 0;
        Uint8 *dst_addr = NULL, *src_addr = NULL;
        Uint32 virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr, 8);
        address = *tempBuf;
        val = *(tempBuf + 1);
        info->mbInfo.size = val & 0xFFFF;
        info->mbInfo.enable = (val >> 24) & 0xFF;
        info->mbInfo.addr = pEncInfo->encReportMBInfo.addr;
        if (info->mbInfo.addr && info->mbInfo.size) {
            size = (info->mbInfo.size + 7) / 8 * 8;
            dst_addr = (Uint8 *) info->mbInfo.addr;
            src_addr = (Uint8 *) (virt_addr + ADDR_MB_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    if (pEncInfo->encReportMVInfo.enable) {
        int size = 0;
        Uint32 tempBuf[2], address = 0;
        Uint8 *dst_addr = NULL, *src_addr = NULL;
        Uint32 virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr + 8, 8);
        address = *tempBuf;
        val = *(tempBuf + 1);
        info->mvInfo.size = val & 0xFFFF;
        info->mvInfo.enable = (val >> 24) & 0xFF;
        info->mvInfo.type = (val >> 16) & 0xFF;
        info->mvInfo.addr = pEncInfo->encReportMVInfo.addr;
        if (info->mvInfo.addr && info->mvInfo.size) {
            size = (info->mvInfo.size + 7) / 8 * 8;
            dst_addr = (Uint8 *) info->mvInfo.addr;
            src_addr = (Uint8 *) (virt_addr + ADDR_MB_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    if (pEncInfo->encReportSliceInfo.enable) {
        int size = 0;
        Uint32 tempBuf[2], address = 0;
        Uint8 *dst_addr = NULL, *src_addr = NULL;
        Uint32 virt_addr = pEncInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr + 16, 8);
        address = *tempBuf;
        val = *(tempBuf + 1);

        info->sliceInfo.size = val & 0xFFFF;
        info->sliceInfo.enable = (val >> 24) & 0xFF;
        info->sliceInfo.type = (val >> 16) & 0xFF;
        info->sliceInfo.addr = pEncInfo->encReportSliceInfo.addr;
        if (info->sliceInfo.addr && info->sliceInfo.size) {
            size = (info->sliceInfo.size + 7) / 8 * 8;
            dst_addr = (Uint8 *) info->sliceInfo.addr;
            src_addr = (Uint8 *) (virt_addr + ADDR_SLICE_BASE_OFFSET);
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    *ppendingInst = 0;
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief This function gives a command to the encoder.
 *
 * @param encHandle [Input] The handle obtained from vpu_EncOpen().
 * @param cmd [Intput] user command.
 * @param param [Intput/Output] param  for cmd.
 *
 * @return
 * @li RETCODE_INVALID_COMMAND cmd is not one of 8 values above.
 * @li RETCODE_INVALID_HANDLE encHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished
 */
RetCode vpu_EncGiveCommand(EncHandle handle, CodecCommand cmd, void *param)
{
    CodecInst *pCodecInst;
    EncInfo *pEncInfo;
    RetCode ret;

    ENTER_FUNC();

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
            int angle;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            angle = *(int *)param;
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            GetParaSet(handle, 0, param);
            UnlockVpu(vpu_semap);
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            GetParaSet(handle, 1, param);
            UnlockVpu(vpu_semap);
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            EncodeHeader(handle, encHeaderParam);
            UnlockVpu(vpu_semap);
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            EncodeHeader(handle, encHeaderParam);
            UnlockVpu(vpu_semap);
            break;
        }

    case ENC_SET_SEARCHRAM_PARAM:
        {
            /* dummy this command for i.MX51 platform */
            if (cpu_is_mx5x())
                break;

            SearchRamParam *scRamParam = NULL;
            int EncPicX;
            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }

            EncPicX = pCodecInst->CodecInfo.encInfo.openParam.picWidth;

            scRamParam = (SearchRamParam *) param;

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            VpuWriteReg(BIT_SEARCH_RAM_BASE_ADDR, scRamParam->searchRamAddr);
            UnlockVpu(vpu_semap);

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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            GetParaSet(handle, 1, param);
            UnlockVpu(vpu_semap);

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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            GetParaSet(handle, 2, param);
            UnlockVpu(vpu_semap);

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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            GetParaSet(handle, 0, param);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_SET_GOP_NUMBER:
        {
            int *pGopNumber = (int *)param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pGopNumber < 0 || *pGopNumber > 32767) {
                return RETCODE_INVALID_PARAM;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetGopNumber(handle, (Uint32 *) pGopNumber);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_SET_INTRA_QP:
        {
            int *pIntraQp = (int *)param;
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetIntraQp(handle, (Uint32 *) pIntraQp);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_SET_BITRATE:
        {
            int *pBitrate = (int *)param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pBitrate < 0 || *pBitrate > 32767) {
                return RETCODE_INVALID_PARAM;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetBitrate(handle, (Uint32 *) pBitrate);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_SET_FRAME_RATE:
        {
            int *pFramerate = (int *)param;
            if (pCodecInst->codecMode != MP4_ENC && pCodecInst->codecMode != AVC_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (*pFramerate <= 0) {
                return RETCODE_INVALID_PARAM;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetFramerate(handle, (Uint32 *) pFramerate);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_SET_INTRA_MB_REFRESH_NUMBER:
        {
            int *pIntraRefreshNum = (int *)param;

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetIntraRefreshNum(handle, (Uint32 *) pIntraRefreshNum);
            UnlockVpu(vpu_semap);

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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetSliceMode(handle, (EncSliceMode *) pSliceMode);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_ENABLE_HEC:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetHecMode(handle, 1);
            UnlockVpu(vpu_semap);

            break;
        }

    case ENC_DISABLE_HEC:
        {
            if (pCodecInst->codecMode != MP4_ENC) {
                return RETCODE_INVALID_COMMAND;
            }

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetHecMode(handle, 0);
            UnlockVpu(vpu_semap);

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
RetCode vpu_DecOpen(DecHandle * pHandle, DecOpenParam * pop)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int instIdx, bit_offset = 0;
    Uint32 val;
    RetCode ret;

    ENTER_FUNC();

    if (!isVpuInitialized()) {
        return RETCODE_NOT_INITIALIZED;
    }

    ret = CheckDecOpenParam(pop);
    if (ret != RETCODE_SUCCESS) {
        return ret;
    }

    ret = GetCodecInstance(&pCodecInst);
    if (ret == RETCODE_FAILURE) {
        *pHandle = 0;
        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }

    *pHandle = pCodecInst;
    instIdx = pCodecInst->instIndex;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    pDecInfo->openParam = *pop;

    if (cpu_is_mx27()) {
        pCodecInst->codecMode = pop->bitstreamFormat == STD_AVC ? AVC_DEC : MP4_DEC;
    } else {
        if (pop->bitstreamFormat == STD_MPEG4) {
            pCodecInst->codecMode = MP4_DEC;
        } else if (pop->bitstreamFormat == STD_AVC) {
            pCodecInst->codecMode = AVC_DEC;
        } else if (pop->bitstreamFormat == STD_VC1) {
            pCodecInst->codecMode = VC1_DEC;
        } else if (pop->bitstreamFormat == STD_MPEG2) {
            pCodecInst->codecMode = MP2_DEC;
        } else if (pop->bitstreamFormat == STD_DIV3) {
            pCodecInst->codecMode = DV3_DEC;
        } else if (pop->bitstreamFormat == STD_RV) {
            pCodecInst->codecMode = RV_DEC;
        } else if (pop->bitstreamFormat == STD_MJPG) {
            pCodecInst->codecMode = MJPG_DEC;
        }
    }

    pDecInfo->streamWrPtr = pop->bitstreamBuffer;
    pDecInfo->streamRdPtrRegAddr = rdPtrRegAddr[instIdx];
    pDecInfo->streamWrPtrRegAddr = wrPtrRegAddr[instIdx];
    pDecInfo->frameDisplayFlagRegAddr = disFlagRegAddr[instIdx];
    pDecInfo->streamBufStartAddr = pop->bitstreamBuffer;
    pDecInfo->streamBufSize = pop->bitstreamBufferSize;
    pDecInfo->streamBufEndAddr = pop->bitstreamBuffer + pop->bitstreamBufferSize;
    pDecInfo->frameBufPool = 0;

    pDecInfo->rotationEnable = 0;
    pDecInfo->mirrorEnable = 0;
    pDecInfo->mirrorDirection = MIRDIR_NONE;
    pDecInfo->rotationAngle = 0;
    pDecInfo->rotatorOutputValid = 0;
    pDecInfo->rotatorStride = 0;
    pDecInfo->deringEnable = 0;

    if (cpu_is_mx37()) {
        pDecInfo->dbkOffset.DbkOffsetEnable = 0;
        pDecInfo->dbkOffset.DbkOffsetA = 0;
        pDecInfo->dbkOffset.DbkOffsetB = 0;
    }

    pDecInfo->filePlayEnable = pop->filePlayEnable;
    if (pop->filePlayEnable == 1) {
        pDecInfo->picSrcSize = (pop->picWidth << BIT_PIC_WIDTH_OFFSET) | pop->picHeight;
    }
    pDecInfo->dynamicAllocEnable = pop->dynamicAllocEnable;

    pDecInfo->initialInfoObtained = 0;
    pDecInfo->vc1BframeDisplayValid = 0;

    pDecInfo->decReportFrameBufStat.enable = 0;
    pDecInfo->decReportMBInfo.enable = 0;
    pDecInfo->decReportMVInfo.enable = 0;
    pDecInfo->decReportUserData.enable = 0;
    pDecInfo->decReportUserData.size = 0;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    VpuWriteReg(pDecInfo->streamRdPtrRegAddr, pDecInfo->streamBufStartAddr);
    VpuWriteReg(pDecInfo->streamWrPtrRegAddr, pDecInfo->streamWrPtr);
    VpuWriteReg(pDecInfo->frameDisplayFlagRegAddr, 0);

    /* Clear stream end flag */
    VpuWriteReg(BIT_BIT_STREAM_PARAM, VpuReadReg(BIT_BIT_STREAM_PARAM) & ~(1 << (instIdx + 2)));

    bit_offset = cpu_is_mx37()? (instIdx + 1) : (instIdx + 2);
    val = VpuReadReg(BIT_FRAME_MEM_CTRL) & ~(1 << bit_offset);
    VpuWriteReg(BIT_FRAME_MEM_CTRL, val | (pDecInfo->openParam.chromaInterleave << bit_offset));

    return RETCODE_SUCCESS;
}

/*!
 * @brief Decoder close function
 *
 * @param  handle [Input] The handle obtained from vpu_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful closing.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode vpu_DecClose(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (*ppendingInst == pCodecInst) {
        return RETCODE_FRAME_NOT_COMPLETE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (pDecInfo->initialInfoObtained) {
        if (cpu_is_mx5x()) {
            if (pDecInfo->openParam.bitstreamFormat == STD_DIV3)
                VpuWriteReg(BIT_RUN_AUX_STD, 1);
            else
                VpuWriteReg(BIT_RUN_AUX_STD, 0);
        }
        BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SEQ_END);
        while (VpuReadReg(BIT_BUSY_FLAG)) ;
    }

    /* Free memory allocated for data report functions */
    IOFreeMem(&pDecInfo->picParaBaseMem);
    IOFreeMem(&pDecInfo->userDataBufMem);

    FreeCodecInstance(pCodecInst);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecSetEscSeqInit(DecHandle handle, int escape)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (escape == 0)
        VpuWriteReg(CMD_DEC_SEQ_INIT_ESCAPE, VpuReadReg(CMD_DEC_SEQ_INIT_ESCAPE) & ~0x01);
    else
        VpuWriteReg(CMD_DEC_SEQ_INIT_ESCAPE, VpuReadReg(CMD_DEC_SEQ_INIT_ESCAPE) | 0x01);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get header information of bitstream.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
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
RetCode vpu_DecGetInitialInfo(DecHandle handle, DecInitialInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    Uint32 val, val2;
    SetIramParam iramParam;
    RetCode ret;

    ENTER_FUNC();

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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (DecBitstreamBufEmpty(pDecInfo)) {
        UnlockVpu(vpu_semap);
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    VpuWriteReg(CMD_DEC_SEQ_BB_START, pDecInfo->streamBufStartAddr);
    VpuWriteReg(CMD_DEC_SEQ_BB_SIZE, pDecInfo->streamBufSize / 1024);

    if (pDecInfo->filePlayEnable == 1) {
        VpuWriteReg(CMD_DEC_SEQ_START_BYTE, pDecInfo->openParam.streamStartByteOffset);
    }

    val = ((pDecInfo->dynamicAllocEnable << 3) & 0x8) |
        ((pDecInfo->filePlayEnable << 2) & 0x4) | ((pDecInfo->openParam.reorderEnable << 1) & 0x2);

    if (pCodecInst->codecMode == MJPG_DEC) {
        val |= 1 << 10;         /* force not interrupt mode */
        val |= pDecInfo->decReportUserData.enable << 5;
    }

    if (pDecInfo->decReportUserData.enable && !pDecInfo->userDataBufMem.phy_addr) {
        pDecInfo->userDataBufMem.size = pDecInfo->decReportUserData.size;
        ret = IOGetMem(&pDecInfo->userDataBufMem);
        if (ret) {
            err_msg("Unable to obtain physical mem\n");
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }
        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BASE_ADDR, pDecInfo->userDataBufMem.phy_addr);
        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BUF_SIZE, pDecInfo->decReportUserData.size);
    }

    if (cpu_is_mx27()) {
        val |= (pDecInfo->openParam.qpReport & 0x1);
    } else {
        val |= (pDecInfo->openParam.mp4DeblkEnable & 0x1);
    }

    VpuWriteReg(CMD_DEC_SEQ_OPTION, val);

    if (pCodecInst->codecMode == VC1_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_VC1_STREAM_FMT, 0);
    }

    if (pCodecInst->codecMode == MP4_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_MP4_ASP_CLASS, pDecInfo->openParam.mp4Class);
    }

    if (pCodecInst->codecMode == AVC_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_PS_BB_START, pDecInfo->openParam.psSaveBuffer);
        VpuWriteReg(CMD_DEC_SEQ_PS_BB_SIZE, (pDecInfo->openParam.psSaveBufferSize / 1024));
    }

    if (pCodecInst->codecMode == MJPG_DEC) {
        VpuWriteReg(CMD_DEC_SEQ_JPG_THUMB_EN, pDecInfo->openParam.mjpg_thumbNailDecEnable);
    }

    VpuWriteReg(CMD_DEC_SEQ_SRC_SIZE, pDecInfo->picSrcSize);

    if (cpu_is_mx5x()) {
        if (pDecInfo->openParam.bitstreamFormat == STD_DIV3)
            VpuWriteReg(BIT_RUN_AUX_STD, 1);
        else
            VpuWriteReg(BIT_RUN_AUX_STD, 0);
    }

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SEQ_INIT);
    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    if (VpuReadReg(RET_DEC_SEQ_SUCCESS) == 0) {
        val = VpuReadReg(RET_DEC_SEQ_ERR_REASON);
        info->errorcode = val;

        UnlockVpu(vpu_semap);
        return RETCODE_FAILURE;
    }

    val = VpuReadReg(RET_DEC_SEQ_SRC_SIZE);
    if (cpu_is_mx37() || cpu_is_mx5x()) {
        info->picWidth = ((val >> 16) & 0xffff);
        info->picHeight = (val & 0xffff);
    } else {
        info->picWidth = ((val >> 10) & 0x3ff);
        info->picHeight = (val & 0x3ff);
    }

    if (pCodecInst->codecMode == MJPG_DEC) {
        if (info->picWidth < 16 || info->picHeight < 16) {
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }
    } else {
        if (info->picWidth < 64 || info->picHeight < 64) {
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }
    }

    val = VpuReadReg(RET_DEC_SEQ_SRC_F_RATE);
    info->frameRateInfo = val;

    if (pCodecInst->codecMode == MP4_DEC) {
        val = VpuReadReg(RET_DEC_SEQ_INFO);
        info->mp4_shortVideoHeader = (val >> 2) & 1;
        info->mp4_dataPartitionEnable = val & 1;
        info->mp4_reversibleVlcEnable = info->mp4_dataPartitionEnable ? ((val >> 1) & 1) : 0;
        info->h263_annexJEnable = (val >> 3) & 1;
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
            if (cpu_is_mx5x()) {
                info->picCropRect.left = ((val >> 16) & 0xFFFF);
                info->picCropRect.right = info->picWidth - ((val & 0xFFFF));
                info->picCropRect.top = ((val2 >> 16) & 0xFFFF);
                info->picCropRect.bottom = info->picHeight - ((val2 & 0xFFFF));

            } else {
                info->picCropRect.left = ((val >> 10) & 0x3FF) * 2;
                info->picCropRect.right = info->picWidth - ((val & 0x3FF) * 2);
                info->picCropRect.top = ((val2 >> 10) & 0x3FF) * 2;
                info->picCropRect.bottom = info->picHeight - ((val2 & 0x3FF) * 2);
            }
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

    if (pCodecInst->codecMode == MJPG_DEC) {
        info->mjpg_thumbNailEnable = (VpuReadReg(RET_DEC_SEQ_JPG_THUMB_IND) & 0x01);
        info->mjpg_sourceFormat = (VpuReadReg(RET_DEC_SEQ_JPG_PARA) & 0x07);
        if (pDecInfo->openParam.mjpg_thumbNailDecEnable == 1)
            if (info->mjpg_thumbNailEnable == 0) {
                UnlockVpu(vpu_semap);
                return RETCODE_FAILURE;
            }
    }

    if (cpu_is_mx37()) {
        val = VpuReadReg(RET_DEC_SEQ_INFO);
        info->profile = (val >> 4) & 0xFF;
        info->level = (val >> 12) & 0xFF;
        info->interlace = (val >> 20) & 0x0001;
        info->vc1_psf = (val >> 22) & 0x0001;
    } else if (cpu_is_mx5x()) {
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
    }

    val = VpuReadReg(RET_DEC_SEQ_ASPECT);
    info->aspectRateInfo = val;

    info->reportBufSize.frameBufStatBufSize = SIZE_FRAME_BUF_STAT;
    info->reportBufSize.mbInfoBufSize = SIZE_MB_DATA;
    info->reportBufSize.mvInfoBufSize = SIZE_MV_DATA;

    if (cpu_is_mx37() || cpu_is_mx5x())
        info->streamInfoObtained = 1;
    else
        info->streamInfoObtained = 0;

    UnlockVpu(vpu_semap);

    pDecInfo->initialInfo = *info;
    pDecInfo->initialInfoObtained = 1;

    /* Set secondAXI IRAM */
    if (!cpu_is_mx37()) {
        iramParam.width = (info->picWidth + 15) & ~15;
        iramParam.profile = info->profile;
        iramParam.codecMode = pCodecInst->codecMode;
        SetDecSecondAXIIRAM(&pDecInfo->secAxiUse, &iramParam);
    }

    return RETCODE_SUCCESS;
}

/*!
 * @brief Register decoder frame buffers.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
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
 * the value requested by vpu_DecGetInitialInfo().
 * @li RETCODE_INVALID_STRIDE stride is less than the picture width.
 */
RetCode vpu_DecRegisterFrameBuffer(DecHandle handle,
                                   FrameBuffer * bufArray, int num, int stride,
                                   DecBufInfo * pBufInfo)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    int i;
    RetCode ret;

    ENTER_FUNC();

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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (!cpu_is_mx5x()) {
        /* Let the codec know the addresses of the frame buffers. */
        for (i = 0; i < num; ++i) {
            if (cpu_is_mx37()) {
                virt_paraBuf[i * 3] = swab32(bufArray[i].bufY);
                virt_paraBuf[i * 3 + 1] = swab32(bufArray[i].bufCb);
                virt_paraBuf[i * 3 + 2] = swab32(bufArray[i].bufCr);
                if (pDecInfo->openParam.bitstreamFormat == STD_AVC) {
                    virt_paraBuf[i + 96] = swab32(bufArray[i].bufMvCol);
                }
            } else {
                virt_paraBuf[i * 3] = bufArray[i].bufY;
                virt_paraBuf[i * 3 + 1] = bufArray[i].bufCb;
                virt_paraBuf[i * 3 + 2] = bufArray[i].bufCr;
            }
        }
    } else {
        /* mx51 case need to swap word */
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
            pDecInfo->openParam.bitstreamFormat == STD_RV)
            virt_paraBuf[97] = bufArray[0].bufMvCol;
    }
    if (cpu_is_mx37()) {
        if (pDecInfo->openParam.bitstreamFormat == STD_VC1 ||
            pDecInfo->openParam.bitstreamFormat == STD_MPEG4) {
            virt_paraBuf[96] = swab32(bufArray[0].bufMvCol);
        }
    }

    /* Tell the decoder how much frame buffers were allocated. */
    VpuWriteReg(CMD_SET_FRAME_BUF_NUM, num);
    VpuWriteReg(CMD_SET_FRAME_BUF_STRIDE, stride);

    if (cpu_is_mx5x()) {
        VpuWriteReg(CMD_SET_FRAME_AXI_BIT_ADDR, pDecInfo->secAxiUse.bufBitUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_IPACDC_ADDR, pDecInfo->secAxiUse.bufIpAcDcUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_DBKY_ADDR, pDecInfo->secAxiUse.bufDbkYUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_DBKC_ADDR, pDecInfo->secAxiUse.bufDbkCUse);
        VpuWriteReg(CMD_SET_FRAME_AXI_OVL_ADDR, pDecInfo->secAxiUse.bufOvlUse);
    } else
        VpuWriteReg(BIT_AXI_SRAM_USE, 0);   /* not use SRAM */

    if (pCodecInst->codecMode == AVC_DEC) {
        VpuWriteReg(CMD_SET_FRAME_SLICE_BB_START, pBufInfo->avcSliceBufInfo.sliceSaveBuffer);
        VpuWriteReg(CMD_SET_FRAME_SLICE_BB_SIZE,
                    (pBufInfo->avcSliceBufInfo.sliceSaveBufferSize / 1024));
    }

    VpuWriteReg(CMD_SET_FRAME_MAX_DEC_SIZE,
                (pBufInfo->maxDecFrmInfo.maxMbNum << 16 |
                 pBufInfo->maxDecFrmInfo.maxMbX << 8 | pBufInfo->maxDecFrmInfo.maxMbY));

    if (cpu_is_mx5x()) {
        if (pDecInfo->openParam.bitstreamFormat == STD_DIV3)
            VpuWriteReg(BIT_RUN_AUX_STD, 1);
        else
            VpuWriteReg(BIT_RUN_AUX_STD, 0);
    }
    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, SET_FRAME_BUF);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Get bitstream for decoder.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param bufAddr [Output] Bitstream buffer physical address.
 * @param size [Output] Bitstream size.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM buf or size is invalid.
 */
RetCode vpu_DecGetBitstreamBuffer(DecHandle handle,
                                  PhysicalAddress * paRdPtr,
                                  PhysicalAddress * paWrPtr, Uint32 * size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress rdPtr;
    PhysicalAddress wrPtr;
    Uint32 room;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (paRdPtr == 0 || paWrPtr == 0 || size == 0) {
        return RETCODE_INVALID_PARAM;
    }

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    rdPtr = VpuReadReg(pDecInfo->streamRdPtrRegAddr);
    wrPtr = pDecInfo->streamWrPtr;

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
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param size [Input] Size of bit stream you put.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_INVALID_PARAM Invalid input parameters.
 */
RetCode vpu_DecUpdateBitstreamBuffer(DecHandle handle, Uint32 size)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    PhysicalAddress wrPtr;
    PhysicalAddress rdPtr;
    RetCode ret;
    int room = 0, val = 0;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;
    wrPtr = pDecInfo->streamWrPtr;

    LockVpuReg(vpu_semap);
    if (size == 0) {
        /* Set stream end flag */
        val = VpuReadReg(BIT_BIT_STREAM_PARAM);
        VpuWriteReg(BIT_BIT_STREAM_PARAM, val |= 1 << (pCodecInst->instIndex + 2));
        UnlockVpuReg(vpu_semap);
        return RETCODE_SUCCESS;
    } else {
        /* Clear stream end flag */
        val = VpuReadReg(BIT_BIT_STREAM_PARAM);
        VpuWriteReg(BIT_BIT_STREAM_PARAM, val & ~(1 << (pCodecInst->instIndex + 2)));
        UnlockVpuReg(vpu_semap);
    }

    rdPtr = VpuReadReg(pDecInfo->streamRdPtrRegAddr);
    if (wrPtr < rdPtr) {
        if (rdPtr <= wrPtr + size) {
            return RETCODE_INVALID_PARAM;
        }
    }

    wrPtr += size;

    if (pDecInfo->filePlayEnable != 1) {
        if (wrPtr > pDecInfo->streamBufEndAddr) {
            room = wrPtr - pDecInfo->streamBufEndAddr;
            wrPtr = pDecInfo->streamBufStartAddr;
            wrPtr += room;
        }

        if (wrPtr == pDecInfo->streamBufEndAddr) {
            wrPtr = pDecInfo->streamBufStartAddr;
        }
    }

    pDecInfo->streamWrPtr = wrPtr;
    VpuWriteReg(pDecInfo->streamWrPtrRegAddr, wrPtr);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Start decoding one frame.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 */
RetCode vpu_DecStartOneFrame(DecHandle handle, DecParam * param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    DecParam *pDecParam;
    Uint32 rotMir;
    Uint32 val = 0;
    RetCode ret;

    ENTER_FUNC();

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

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if ((cpu_is_mx37() || cpu_is_mx5x()) && pDecInfo->deringEnable) {
        rotMir |= 0x20;         /* Enable Dering Filter */
    }

    if ((rotMir & 0x30) ||      /* rotator or dering enabled */
        (pCodecInst->codecMode == MJPG_DEC)) {
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_Y, pDecInfo->rotatorOutput.bufY);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CB, pDecInfo->rotatorOutput.bufCb);
        VpuWriteReg(CMD_DEC_PIC_ROT_ADDR_CR, pDecInfo->rotatorOutput.bufCr);
        VpuWriteReg(CMD_DEC_PIC_ROT_STRIDE, pDecInfo->rotatorStride);
    }

    VpuWriteReg(CMD_DEC_PIC_ROT_MODE, rotMir);

    if (cpu_is_mx32()) {
        if (pCodecInst->codecMode == MP4_DEC && pDecInfo->openParam.mp4DeblkEnable == 1) {
            if (pDecInfo->deBlockingFilterOutputValid) {
                VpuWriteReg(CMD_DEC_PIC_DBK_ADDR_Y, pDecInfo->deBlockingFilterOutput.bufY);
                VpuWriteReg(CMD_DEC_PIC_DBK_ADDR_CB, pDecInfo->deBlockingFilterOutput.bufCb);
                VpuWriteReg(CMD_DEC_PIC_DBK_ADDR_CR, pDecInfo->deBlockingFilterOutput.bufCr);
            } else {
                UnlockVpu(vpu_semap);
                return RETCODE_DEBLOCKING_OUTPUT_NOT_SET;
            }
        }
    }

    if (pDecInfo->decReportMBInfo.enable || pDecInfo->decReportMVInfo.enable ||
        pDecInfo->decReportFrameBufStat.enable) {
        if (!pDecInfo->picParaBaseMem.phy_addr) {
            pDecInfo->picParaBaseMem.size = DEC_ADDR_END_OF_RPT_BUF;
            ret = IOGetMem(&pDecInfo->picParaBaseMem);
            if (ret) {
                err_msg("Unable to obtain physical mem\n");
                UnlockVpu(vpu_semap);
                return RETCODE_FAILURE;
            }
        }

        VpuWriteReg(CMD_DEC_PIC_PARA_BASE_ADDR, pDecInfo->picParaBaseMem.phy_addr);

        if (cpu_is_mx5x()) {
            Uint32 *virt_addr, phy_addr;

            virt_addr = (Uint32 *) pDecInfo->picParaBaseMem.virt_uaddr;
            phy_addr = pDecInfo->picParaBaseMem.phy_addr;
            /* Set frameStat buffer address */
            if (pDecInfo->decReportFrameBufStat.enable) {
                *virt_addr = phy_addr + ADDR_FRAME_BUF_STAT_BASE_OFFSET;
            }
            /* Set mbParam buffer address */
            if (pDecInfo->decReportMBInfo.enable) {
                *(virt_addr + 2) = phy_addr + ADDR_MB_BASE_OFFSET;
            }
            /* Set mvParam buffer address */
            if (pDecInfo->decReportMVInfo.enable) {
                *(virt_addr + 4) = phy_addr + ADDR_MV_BASE_OFFSET;
            }
        }
        if (cpu_is_mx37()) {
            Uint32 *virt_addr, phy_addr;

            virt_addr = (Uint32 *) pDecInfo->picParaBaseMem.virt_uaddr;
            phy_addr = pDecInfo->picParaBaseMem.phy_addr;
            /* Set frameStat buffer address */
            if (pDecInfo->decReportFrameBufStat.enable) {
                *(virt_addr + 1) = swab32(phy_addr + ADDR_FRAME_BUF_STAT_BASE_OFFSET);
            }
            /* Set mbParam buffer address */
            if (pDecInfo->decReportMBInfo.enable) {
                *(virt_addr + 3) = swab32(phy_addr + ADDR_MB_BASE_OFFSET);
            }
            /* Set mvParam buffer address */
            if (pDecInfo->decReportMVInfo.enable) {
                *(virt_addr + 5) = swab32(phy_addr + ADDR_MV_BASE_OFFSET);
            }
        }
    }

    if (pDecInfo->decReportUserData.enable && !pDecInfo->userDataBufMem.phy_addr) {
        pDecInfo->userDataBufMem.size = pDecInfo->decReportUserData.size;
        ret = IOGetMem(&pDecInfo->userDataBufMem);
        if (ret) {
            err_msg("Unable to obtain physical mem\n");
            UnlockVpu(vpu_semap);
            return RETCODE_FAILURE;
        }

        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BASE_ADDR, pDecInfo->userDataBufMem.phy_addr);
        VpuWriteReg(CMD_DEC_PIC_USER_DATA_BUF_SIZE, pDecInfo->decReportUserData.size);
    }

    val = 0;
    if (cpu_is_mx37())
        val |= (pDecInfo->dbkOffset.DbkOffsetEnable << 9);

    if (cpu_is_mx37() || cpu_is_mx5x()) {
        if (cpu_is_mx37())
            val |= (param->skipframeNum << 16);

        val |= (1 << 10);       /* hardcode to use interrupt disable mode  */
        val |= (pDecInfo->decReportFrameBufStat.enable << 8);
        val |= (pDecInfo->decReportMBInfo.enable << 7);
        val |= (pDecInfo->decReportMVInfo.enable << 6);

        /* if iframeSearch is Enable, other bit is ignored. */
        if (param->iframeSearchEnable == 1) {
            val |= ((param->iframeSearchEnable & 0x1) << 2);
            pDecInfo->vc1BframeDisplayValid = 0;
        } else if (param->skipframeMode) {
            val |= (param->skipframeMode << 3);
            val |= (param->prescanMode << 1);
            val |= (param->prescanEnable);
        } else {
            val |= (pDecInfo->decReportUserData.enable << 5);
            val |= (param->prescanMode << 1);
            val |= (param->prescanEnable);
        }
    } else {
        if (param->iframeSearchEnable == 1) {
            val = (param->iframeSearchEnable << 2) & 0x4;
        } else {
            val = (param->skipframeMode << 3) |
                (param->iframeSearchEnable << 2) | (param->prescanMode << 1) | param->prescanEnable;
        }
    }
    VpuWriteReg(CMD_DEC_PIC_OPTION, val);

    if (cpu_is_mx37()) {
        VpuWriteReg(CMD_DEC_PIC_DBK_OFFSET,
                    ((pDecInfo->dbkOffset.DbkOffsetA & 31) << 5) |
                    (pDecInfo->dbkOffset.DbkOffsetB & 31));
    }

    /* TODO may be removed after next mx51 release be aligned with mx37 */
    if (cpu_is_mx5x())
        VpuWriteReg(CMD_DEC_PIC_SKIP_NUM, param->skipframeNum);

    if (!cpu_is_mx5x()) {
        /* clear dispReorderBuf flag firstly */
        val = VpuReadReg(CMD_DEC_DISPLAY_REORDER) & 0xFFFFFFFD;
        val |= (param->dispReorderBuf & 0x1) << 1;
        if (((pCodecInst->codecMode == AVC_DEC) && (pDecInfo->openParam.reorderEnable == 1)) ||
            (pCodecInst->codecMode == VC1_DEC) ||
            (pCodecInst->codecMode == MP2_DEC) ||
            (pCodecInst->codecMode == MP4_DEC) || (pCodecInst->codecMode == RV_DEC)) {
            if (pDecInfo->filePlayEnable == 1)
                VpuWriteReg(CMD_DEC_DISPLAY_REORDER, val);
        }
    }

    if (pDecInfo->filePlayEnable == 1) {
        VpuWriteReg(CMD_DEC_PIC_CHUNK_SIZE, param->chunkSize);
        if (pDecInfo->dynamicAllocEnable == 1) {
            VpuWriteReg(CMD_DEC_PIC_BB_START, param->picStreamBufferAddr);
        }

        VpuWriteReg(CMD_DEC_PIC_START_BYTE, param->picStartByteOffset);
    }

    if (cpu_is_mx5x()) {
        if (pDecInfo->openParam.bitstreamFormat == STD_DIV3)
            VpuWriteReg(BIT_RUN_AUX_STD, 1);
        else
            VpuWriteReg(BIT_RUN_AUX_STD, 0);
    }

    val = (pDecInfo->secAxiUse.useBitEnable | pDecInfo->secAxiUse.useIpEnable << 1 |
           pDecInfo->secAxiUse.useDbkEnable << 2 | pDecInfo->secAxiUse.useOvlEnable << 3 |
           pDecInfo->secAxiUse.useHostBitEnable << 7 | pDecInfo->secAxiUse.useHostIpEnable << 8 |
           pDecInfo->secAxiUse.useHostDbkEnable << 9 | pDecInfo->secAxiUse.useHostOvlEnable << 10);
    VpuWriteReg(BIT_AXI_SRAM_USE, val);

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, PIC_RUN);

    *ppendingInst = pCodecInst;
    return RETCODE_SUCCESS;
}

/*!
 * @brief Get the information of output of decoding.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param info [Output] Pointer to DecOutputInfo data structure.
 *
 * @return
 * @li RETCODE_SUCCESS Successful operation.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_WRONG_CALL_SEQUENCE Wrong calling sequence.
 * @li RETCODE_INVALID_PARAM Info is an invalid pointer.
 */
RetCode vpu_DecGetOutputInfo(DecHandle handle, DecOutputInfo * info)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;
    Uint32 val = 0;
    Uint32 val2 = 0;
    PhysicalAddress paraBuffer;

    ENTER_FUNC();

    paraBuffer = bit_work_addr.phy_addr + CODE_BUF_SIZE + WORK_BUF_SIZE + PARA_BUF2_SIZE;

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

    val = VpuReadReg(RET_DEC_PIC_SUCCESS);
    info->decodingSuccess = (val & 0x01);
    if (pCodecInst->codecMode == AVC_DEC) {
        info->notSufficientPsBuffer = (val >> 3) & 0x1;
        info->notSufficientSliceBuffer = (val >> 2) & 0x1;
    } else if (pCodecInst->codecMode == MP4_DEC) {
        info->mp4PackedPBframe = ((val >> 16) & 0x01);
    }

    val = VpuReadReg(RET_DEC_PIC_SIZE); /* decoding picture size */
    info->decPicHeight = val & 0xFFFF;
    info->decPicWidth = (val >> 16) & 0xFFFF;

    /* frame crop information */
    if (pCodecInst->codecMode == AVC_DEC) {
        val = VpuReadReg(RET_DEC_PIC_CROP_LEFT_RIGHT);
        val2 = VpuReadReg(RET_DEC_PIC_CROP_TOP_BOTTOM);
        if (val == 0 && val2 == 0) {
            info->decPicCrop.left = 0;
            info->decPicCrop.right = 0;
            info->decPicCrop.top = 0;
            info->decPicCrop.bottom = 0;
        } else {
            if (cpu_is_mx5x()) {
                info->decPicCrop.left = ((val >> 16) & 0xFFFF);
                info->decPicCrop.right = info->decPicWidth - ((val & 0xFFFF));
                info->decPicCrop.top = ((val2 >> 16) & 0xFFFF);
                info->decPicCrop.bottom = info->decPicHeight - ((val2 & 0xFFFF));
            } else if (cpu_is_mx37()) {
                info->decPicCrop.left = ((val >> 10) & 0x3FF) * 2;
                info->decPicCrop.right = info->decPicWidth - ((val & 0x3FF) * 2);
                info->decPicCrop.top = ((val2 >> 10) & 0x3FF) * 2;
                info->decPicCrop.bottom = info->decPicHeight - ((val2 & 0x3FF) * 2);
            }
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

    info->interlacedFrame = (val >> 16) & 0x1;

    if (cpu_is_mx37() || cpu_is_mx5x()) {
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
    }

    if (pDecInfo->decReportFrameBufStat.enable) {
        int size = 0, paraInfo = 0, address = 0;
        Uint32 tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;
        memcpy((char *)tempBuf, (void *)virt_addr, 8);
        if (cpu_is_mx37()) {
            val = swab32(*tempBuf);
            address = swab32(*(tempBuf + 1));
        } else {
            val = *(tempBuf + 1);
            address = *tempBuf;
        }

        paraInfo = (val >> 24) & 0xFF;
        size = (val >> 0) & 0xFFFFFF;

        info->frameBufStat.enable = 1;
        if (paraInfo == PARA_TYPE_FRM_BUF_STATUS) {
            info->frameBufStat.size = size;
            info->frameBufStat.addr = pDecInfo->decReportFrameBufStat.addr;
            size = (size + 7) / 8 * 8;
            if (info->frameBufStat.size && info->frameBufStat.addr) {
                Uint8 *dst_addr, *src_addr;
                dst_addr = (Uint8 *) info->frameBufStat.addr;
                src_addr = (Uint8 *) (virt_addr + ADDR_FRAME_BUF_STAT_BASE_OFFSET);
                CopyBufferData(dst_addr, src_addr, size);
            }
        }
    }

    /* Mb Param */
    if (pDecInfo->decReportMBInfo.enable) {
        int size = 0, paraInfo = 0, address = 0;
        Uint32 tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)(virt_addr + 8), 8);
        if (cpu_is_mx37()) {
            val = swab32(*tempBuf);
            address = swab32(*(tempBuf + 1));
        } else {
            val = *(tempBuf + 1);
            address = *tempBuf;
        }

        paraInfo = (val >> 24) & 0xFF;
        size = (val >> 0) & 0x00FFFF;

        info->mbInfo.enable = 1;
        if (paraInfo == PARA_TYPE_MB_PARA) {
            info->mbInfo.size = size;
            info->mbInfo.addr = pDecInfo->decReportMBInfo.addr;
            size = (size + 7) / 8 * 8;
            if (info->mbInfo.size && info->mbInfo.addr) {
                Uint8 *dst_addr, *src_addr;
                dst_addr = (Uint8 *) info->mbInfo.addr;
                src_addr = (Uint8 *) (virt_addr + ADDR_MB_BASE_OFFSET);
                CopyBufferData(dst_addr, src_addr, size);
            }
        } else {
            /* VPU does not write data */
            info->mbInfo.size = 0;
            info->mbInfo.addr = 0;
        }

    }

    /* Motion Vector */
    if (pDecInfo->decReportMVInfo.enable) {
        int size = 0, paraInfo = 0, address = 0, mvNumPerMb = 0;
        Uint32 tempBuf[2], virt_addr;

        virt_addr = pDecInfo->picParaBaseMem.virt_uaddr;
        memcpy((char *)tempBuf, (void *)(virt_addr + 16), 8);
        if (cpu_is_mx37()) {
            val = swab32(*tempBuf);
            address = swab32(*(tempBuf + 1));
        } else {
            val = *(tempBuf + 1);
            address = *tempBuf;
        }

        paraInfo = (val >> 24) & 0xFF;
        mvNumPerMb = (val >> 16) & 0xFF;
        size = (val >> 0) & 0xFFFF;
        info->mvInfo.enable = 1;
        if (paraInfo == PARA_TYPE_MV) {

            info->mvInfo.size = size;
            info->mvInfo.mvNumPerMb = mvNumPerMb;
            info->mvInfo.addr = pDecInfo->decReportMVInfo.addr;
            if (info->mvInfo.size && info->mvInfo.addr) {
                Uint8 *dst_addr, *src_addr;
                dst_addr = (Uint8 *) info->mvInfo.addr;
                src_addr = (Uint8 *) (virt_addr + ADDR_MV_BASE_OFFSET);
                size = (size + 7) / 8 * 8 * mvNumPerMb * 4;
                CopyBufferData(dst_addr, src_addr, size);
            }

        } else {
            /* VPU does not write data */
            info->mvInfo.mvNumPerMb = 0;
            info->mvInfo.addr = 0;
        }
    }

    /* User Data */
    if (pDecInfo->decReportUserData.enable) {
        int userDataNum = 0, userDataSize = 0;
        Uint32 tempBuf[2], virt_addr;

        virt_addr = pDecInfo->userDataBufMem.virt_uaddr;

        memcpy((char *)tempBuf, (void *)virt_addr, 8);

        val = cpu_is_mx37()? swab32(*tempBuf) : *(tempBuf + 1);
        userDataNum = (val >> 16) & 0xFFFF;
        userDataSize = (val >> 0) & 0xFFFF;
        if (userDataNum == 0)
            userDataSize = 0;

        info->userData.userDataNum = userDataNum;
        info->userData.size = userDataSize;

        val = cpu_is_mx37()? swab32(*(tempBuf + 1)) : *tempBuf;
        if (userDataNum == 0)
            info->userData.userDataBufFull = 0;
        else
            info->userData.userDataBufFull = (val >> 16) & 0xFFFF;

        info->userData.enable = 1;
        if (userDataSize && pDecInfo->decReportUserData.addr) {
            int size = (userDataSize + 7) / 8 * 8 + USER_DATA_INFO_OFFSET;
            Uint8 *dst_addr, *src_addr;
            dst_addr = (Uint8 *) pDecInfo->decReportUserData.addr;
            src_addr = (Uint8 *) virt_addr;
            CopyBufferData(dst_addr, src_addr, size);
        }
    }

    info->numOfErrMBs = VpuReadReg(RET_DEC_PIC_ERR_MB);
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
                val &= VpuReadReg(pDecInfo->frameDisplayFlagRegAddr);
                VpuWriteReg(pDecInfo->frameDisplayFlagRegAddr, val);
                info->indexFrameDisplay = -3;
            } else {
                pDecInfo->vc1BframeDisplayValid = 1;
            }
        }
    }

    if (cpu_is_mx27()) {
        if (pCodecInst->codecMode == MP4_DEC && pDecInfo->openParam.qpReport == 1) {
            int widthInMB;
            int heightInMB;
            int readPnt;
            int writePnt;
            int i;
            int j;
            Uint32 val, val1, val2;

            widthInMB = pDecInfo->initialInfo.picWidth / 16;
            heightInMB = pDecInfo->initialInfo.picHeight / 16;
            writePnt = 0;
            for (i = 0; i < heightInMB; ++i) {
                readPnt = i * 32;
                for (j = 0; j < widthInMB; j += 4) {
                    val1 = virt_paraBuf[readPnt];
                    readPnt++;
                    val2 = virt_paraBuf[readPnt];
                    readPnt++;
                    val = (val1 << 8 & 0xff000000) |
                        (val1 << 16) | (val2 >> 8) | (val2 & 0x000000ff);
                    virt_paraBuf2[writePnt] = val;
                    writePnt++;
                }
            }

            info->qpInfo = virt_paraBuf2;
        }
    }

    if (cpu_is_mx37() || cpu_is_mx5x()) {
        if (pCodecInst->codecMode == VC1_DEC) {
            val = VpuReadReg(RET_DEC_PIC_POST);
            info->hScaleFlag = (val >> 1) & 1;
            info->vScaleFlag = (val >> 2) & 1;
            info->indexFrameRangemap = -1;
            if (val & 1)
                info->indexFrameRangemap = (val >> 3) & 31;

        }
    }

    *ppendingInst = 0;
    UnlockVpu(vpu_semap);

    /* Workaround for multi-instances competition */
    hal_delay_us(10);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecBitBufferFlush(DecHandle handle)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    pCodecInst = handle;
    pDecInfo = &pCodecInst->CodecInfo.decInfo;

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    if (cpu_is_mx5x()) {
        if (pDecInfo->openParam.bitstreamFormat == STD_DIV3)
            VpuWriteReg(BIT_RUN_AUX_STD, 1);
        else
            VpuWriteReg(BIT_RUN_AUX_STD, 0);
    }

    BitIssueCommand(pCodecInst->instIndex, pCodecInst->codecMode, DEC_BUF_FLUSH);

    while (VpuReadReg(BIT_BUSY_FLAG)) ;

    pDecInfo->streamWrPtr = pDecInfo->streamBufStartAddr;
    VpuWriteReg(pDecInfo->streamWrPtrRegAddr, pDecInfo->streamBufStartAddr);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

RetCode vpu_DecClrDispFlag(DecHandle handle, int index)
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

    /* This means frame buffers have not been registered. */
    if (pDecInfo->frameBufPool == 0) {
        return RETCODE_WRONG_CALL_SEQUENCE;
    }

    if ((index < 0) || (index > (pDecInfo->numFrameBuffers - 1)))
        return RETCODE_INVALID_PARAM;

    if (!LockVpu(vpu_semap))
        return RETCODE_FAILURE_TIMEOUT;

    val = (~(1 << index) & VpuReadReg(pDecInfo->frameDisplayFlagRegAddr));
    VpuWriteReg(pDecInfo->frameDisplayFlagRegAddr, val);
    UnlockVpu(vpu_semap);

    return RETCODE_SUCCESS;
}

/*!
 * @brief Give command to the decoder.
 *
 * @param handle [Input] The handle obtained from vpu_DecOpen().
 * @param cmd [Intput] Command.
 * @param param [Intput/Output] param  for cmd.
 *
 * @return
 * @li RETCODE_INVALID_COMMANDcmd is not valid.
 * @li RETCODE_INVALID_HANDLE decHandle is invalid.
 * @li RETCODE_FRAME_NOT_COMPLETE A frame has not been finished.
 */
RetCode vpu_DecGiveCommand(DecHandle handle, CodecCommand cmd, void *param)
{
    CodecInst *pCodecInst;
    DecInfo *pDecInfo;
    RetCode ret;

    ENTER_FUNC();

    ret = CheckDecInstanceValidity(handle);
    if (ret != RETCODE_SUCCESS)
        return ret;

    if (cpu_is_mx27() && (cmd == DEC_SET_DEBLOCK_OUTPUT)) {
        return RETCODE_NOT_SUPPORTED;
    }

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
            int angle;
            int height, width;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            angle = *(int *)param;
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
            int stride;

            if (param == 0) {
                return RETCODE_INVALID_PARAM;
            }
            stride = *(int *)param;
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

            if (!LockVpu(vpu_semap))
                return RETCODE_FAILURE_TIMEOUT;

            SetParaSet(handle, 0, param);
            UnlockVpu(vpu_semap);
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
            if (!cpu_is_mx5x()) {
                FrameBuffer *frame;
                if (param == 0) {
                    return RETCODE_INVALID_PARAM;
                }
                frame = (FrameBuffer *) param;
                pDecInfo->deBlockingFilterOutput = *frame;
                pDecInfo->deBlockingFilterOutputValid = 1;
            }
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

void SaveGetEncodeHeader(EncHandle handle, int encHeaderType, char *filename)
{
    FILE *fp = NULL;
    Uint8 *pHeader = NULL;
    EncParamSet encHeaderParam = { 0 };
    int i;
    Uint32 dword1, dword2;
    Uint32 *pBuf;
    Uint32 byteSize;

    ENTER_FUNC();

    if (filename == NULL)
        return;

    vpu_EncGiveCommand(handle, encHeaderType, &encHeaderParam);
    byteSize = ((encHeaderParam.size + 3) & ~3);
    pHeader = (Uint8 *) malloc(sizeof(Uint8) * byteSize);
    if (pHeader) {
        memcpy(pHeader, encHeaderParam.paraSet, byteSize);

        /* ParaBuffer is big endian */
        pBuf = (Uint32 *) pHeader;
        for (i = 0; i < byteSize / 4; i++) {
            dword1 = pBuf[i];
            dword2 = (dword1 >> 24) & 0xFF;
            dword2 |= ((dword1 >> 16) & 0xFF) << 8;
            dword2 |= ((dword1 >> 8) & 0xFF) << 16;
            dword2 |= ((dword1 >> 0) & 0xFF) << 24;
            pBuf[i] = dword2;
        }

        if (encHeaderParam.size > 0) {
#if 0
            fp = fopen(filename, "wb");
            if (fp) {
                fwrite(pHeader, sizeof(Uint8), encHeaderParam.size, fp);
                fclose(fp);
            }
#endif
        }

        free(pHeader);
    }
}
