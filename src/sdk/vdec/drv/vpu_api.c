/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*
 *   VPU API implementation for i.MX-6q (Arik)
 *   
 *   Based on Chips & Media CODE960 API Reference Manual
 */

/******************************** Includes ************************************/
#include "vpu_api.h"
#include "vpu_fw.h"
#include "video.h"

/****************************** Local Defines *********************************/

#define INSTANCES_NUM           (4)
#define WORK_BUF_SIZE           (160*1024 + (INSTANCES_NUM * 41*1024))
#define CODE_BUF_SIZE           (204*1024)

#define	 FW_H264			    0
#define	 FW_VC1					1
#define	 FW_MPEG2				2
#define	 FW_MPEG4_DIVX3			3
#define	 FW_RV					4
#define	 FW_AVS					5
#define	 FW_JPEG				6
#define	 FW_VPX					7

/* vpu_read and vpu_write macros */
#define vpu_write(offset, val)    *((PhysicalAddress *)(VPU_BASE_ADDR + offset)) = (val)
#define vpu_read(offset)            *((PhysicalAddress *)(VPU_BASE_ADDR + offset))

/*************************** Local Type Definitions ***************************/

typedef enum {
    NOP = 0,
    SEQ_INIT,
    SEQ_END,
    PICTURE_RUN,
    SET_FRAME_BUF,
    ENCODE_HEADER,
    ENC_PARA_SET,
    DEC_PARA_SET,
    DEC_BUF_FLUSH,
    ENC_PARA_CHANGE,
    SLEEP,
    WAKE,
    CMD12,
    CMD13,
    CMD14,
    GET_FW_VERSION
} vpuCmd;

/************************ Local Structure Definitions *************************/

typedef struct {
    PhysicalAddress codeBuffer;
    PhysicalAddress workBuffer;
    PhysicalAddress paraBuffer;
    int useCache;
    int CbCrInterleaved;
} vpuParams;

/***************************** Global Variables *******************************/

/* VPU parameters structure */
vpuParams vpu;

/* Decoder Instances */
DecInst DecInstances[INSTANCES_NUM];

/****************************** Local Functions *******************************/

void vpu_run_command(int idx, CodStd std, vpuCmd command)
{
    int codec[] =
        { FW_H264, FW_VC1, FW_MPEG2, FW_MPEG4_DIVX3, FW_MPEG4_DIVX3, FW_MPEG4_DIVX3, FW_RV, FW_AVS,
        FW_JPEG, FW_VPX, FW_VPX, FW_VPX
    };
    int codec_aux[] = { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2 };

    vpu_write(BIT_RUN_INDEX, idx);
    vpu_write(BIT_RUN_COD_STD, codec[std]);
    vpu_write(BIT_RUN_AUX_STD, codec_aux[std]);
    vpu_write(BIT_RUN_COMMAND, command);
}

/*void GDI_setPicInfo(int map_type, int index)
{
    uint32_t addr, data;

    vpu_write(GDI_CONTROL, 1);
    while (!(vpu_read(GDI_STATUS) & 0x1));

    addr = GDI_INFO_CONTROL  + ((index * 5) << 2);
    
    data =  (map_type * 3) << 20;
    data |= color_mode << 17;
    data |= cbcr_interleaved;
    data |= stride;
    vpu_write(addr, data);
 
    vpu_write(addr + 0x4, (picWidth << 16) | picHeight);
    vpu_write(addr + 0x8, y_addr);
    vpu_write(addr + 0xc, cb_addr);
    vpu_write(addr + 0x10, cr_addr);

    vpu_write(GDI_CONTROL, 0);
}*/

void GDI_setMapping(int map_type)
{
    /* Two map types are supported:
     * 0 - linear map.
     * 1 - Tiled MB raster frame map.   */

    if (map_type) {
        vpu_write(GDI_XY2_CAS_0, 0x1010);
        vpu_write(GDI_XY2_CAS_1, 0x1111);
        vpu_write(GDI_XY2_CAS_2, 0x1212);
        vpu_write(GDI_XY2_CAS_3, 0x1303);
        vpu_write(GDI_XY2_CAS_4, 0x0340);

        vpu_write(GDI_XY2_RBC_CONFIG, 0x837070);

        vpu_write(GDI_RBC2_AXI_0, 0xc30);
        vpu_write(GDI_RBC2_AXI_1, 0xc30);
        vpu_write(GDI_RBC2_AXI_2, 0xc30);
        vpu_write(GDI_RBC2_AXI_3, 0x000);
        vpu_write(GDI_RBC2_AXI_4, 0x041);
        vpu_write(GDI_RBC2_AXI_5, 0x082);
        vpu_write(GDI_RBC2_AXI_6, 0x0c3);
        vpu_write(GDI_RBC2_AXI_7, 0x108);
        vpu_write(GDI_RBC2_AXI_8, 0x209);
        vpu_write(GDI_RBC2_AXI_9, 0x24a);
        vpu_write(GDI_RBC2_AXI_A, 0x28b);
        vpu_write(GDI_RBC2_AXI_B, 0x2cc);
        vpu_write(GDI_RBC2_AXI_C, 0x30d);
        vpu_write(GDI_RBC2_AXI_D, 0x34e);
        vpu_write(GDI_RBC2_AXI_E, 0x38f);
        vpu_write(GDI_RBC2_AXI_F, 0x3e0);
        vpu_write(GDI_RBC2_AXI_10, 0x821);
        vpu_write(GDI_RBC2_AXI_11, 0x862);
        vpu_write(GDI_RBC2_AXI_12, 0x8a3);
        vpu_write(GDI_RBC2_AXI_13, 0x8e4);
        vpu_write(GDI_RBC2_AXI_14, 0x925);
        vpu_write(GDI_RBC2_AXI_15, 0x966);
        vpu_write(GDI_RBC2_AXI_16, 0x9a7);
        vpu_write(GDI_RBC2_AXI_17, 0x9e8);
        vpu_write(GDI_RBC2_AXI_18, 0xa29);
        vpu_write(GDI_RBC2_AXI_19, 0xa6a);
        vpu_write(GDI_RBC2_AXI_1A, 0xaab);
        vpu_write(GDI_RBC2_AXI_1B, 0xaec);
        vpu_write(GDI_RBC2_AXI_1C, 0xb2d);
        vpu_write(GDI_RBC2_AXI_1D, 0xb6e);
        vpu_write(GDI_RBC2_AXI_1E, 0xbaf);
        vpu_write(GDI_RBC2_AXI_1F, 0xbf0);

    } else {
        vpu_write(GDI_XY2_CAS_0, 0x4040);
        vpu_write(GDI_XY2_CAS_1, 0x4040);
        vpu_write(GDI_XY2_CAS_2, 0x4040);
        vpu_write(GDI_XY2_CAS_3, 0x4040);
        vpu_write(GDI_XY2_CAS_4, 0x4040);

        vpu_write(GDI_XY2_RBC_CONFIG, 0x800000);

        vpu_write(GDI_RBC2_AXI_0, 0xc30);
        vpu_write(GDI_RBC2_AXI_1, 0xc30);
        vpu_write(GDI_RBC2_AXI_2, 0xc30);
        vpu_write(GDI_RBC2_AXI_3, 0x000);
        vpu_write(GDI_RBC2_AXI_4, 0x041);
        vpu_write(GDI_RBC2_AXI_5, 0x082);
        vpu_write(GDI_RBC2_AXI_6, 0x0c3);
        vpu_write(GDI_RBC2_AXI_7, 0x104);
        vpu_write(GDI_RBC2_AXI_8, 0x145);
        vpu_write(GDI_RBC2_AXI_9, 0x186);
        vpu_write(GDI_RBC2_AXI_A, 0x1c7);
        vpu_write(GDI_RBC2_AXI_B, 0x208);
        vpu_write(GDI_RBC2_AXI_C, 0x410);
        vpu_write(GDI_RBC2_AXI_D, 0x451);
        vpu_write(GDI_RBC2_AXI_E, 0x820);
        vpu_write(GDI_RBC2_AXI_F, 0x861);
        vpu_write(GDI_RBC2_AXI_10, 0x8a2);
        vpu_write(GDI_RBC2_AXI_11, 0x8e3);
        vpu_write(GDI_RBC2_AXI_12, 0x924);
        vpu_write(GDI_RBC2_AXI_13, 0x965);
        vpu_write(GDI_RBC2_AXI_14, 0x9a6);
        vpu_write(GDI_RBC2_AXI_15, 0x9e7);
        vpu_write(GDI_RBC2_AXI_16, 0xa28);
        vpu_write(GDI_RBC2_AXI_17, 0xa69);
        vpu_write(GDI_RBC2_AXI_18, 0xaaa);
        vpu_write(GDI_RBC2_AXI_19, 0xaeb);
        vpu_write(GDI_RBC2_AXI_1A, 0xb2c);
        vpu_write(GDI_RBC2_AXI_1B, 0xb6d);
        vpu_write(GDI_RBC2_AXI_1C, 0xbae);
        vpu_write(GDI_RBC2_AXI_1D, 0xbef);
        vpu_write(GDI_RBC2_AXI_1E, 0xc30);
        vpu_write(GDI_RBC2_AXI_1F, 0xc30);
    }

    vpu_write(GDI_XY2_CAS_5, 0x4040);
    vpu_write(GDI_XY2_CAS_6, 0x4040);
    vpu_write(GDI_XY2_CAS_7, 0x4040);
    vpu_write(GDI_XY2_CAS_8, 0x4040);
    vpu_write(GDI_XY2_CAS_9, 0x4040);
    vpu_write(GDI_XY2_CAS_A, 0x4040);
    vpu_write(GDI_XY2_CAS_B, 0x4040);
    vpu_write(GDI_XY2_CAS_C, 0x4040);
    vpu_write(GDI_XY2_CAS_D, 0x4040);
    vpu_write(GDI_XY2_CAS_E, 0x4040);
    vpu_write(GDI_XY2_CAS_F, 0x4040);
    vpu_write(GDI_XY2_BA_0, 0x4040);
    vpu_write(GDI_XY2_BA_1, 0x4040);
    vpu_write(GDI_XY2_BA_2, 0x4040);
    vpu_write(GDI_XY2_BA_3, 0x4040);
    vpu_write(GDI_XY2_RAS_0, 0x4040);
    vpu_write(GDI_XY2_RAS_1, 0x4040);
    vpu_write(GDI_XY2_RAS_2, 0x4040);
    vpu_write(GDI_XY2_RAS_3, 0x4040);
    vpu_write(GDI_XY2_RAS_4, 0x4040);
    vpu_write(GDI_XY2_RAS_5, 0x4040);
    vpu_write(GDI_XY2_RAS_6, 0x4040);
    vpu_write(GDI_XY2_RAS_7, 0x4040);
    vpu_write(GDI_XY2_RAS_8, 0x4040);
    vpu_write(GDI_XY2_RAS_9, 0x4040);
    vpu_write(GDI_XY2_RAS_A, 0x4040);
    vpu_write(GDI_XY2_RAS_B, 0x4040);
    vpu_write(GDI_XY2_RAS_C, 0x4040);
    vpu_write(GDI_XY2_RAS_D, 0x4040);
    vpu_write(GDI_XY2_RAS_E, 0x4040);
    vpu_write(GDI_XY2_RAS_F, 0x4040);
}

inline void VPU_CleanFrameBuffer(PhysicalAddress * buf, uint8_t val, uint32_t size)
{
    memset((void *)buf, val, size);
}

/*******************************************************************************
* getFrameBuffersAddr()
*
* This function sets the frame buffers addresses 
* pBuffer - array of frame buffers descriptors
* picHeight, stride - used to calculate frame size 
* addr - frame buffers base address
* mapType - linear map (0) or tiled map (1)
* framesNum - number of frames to allocate 
*
*******************************************************************************/
void getFrameBuffersAddr(FrameBuffer * pBuffer, uint32_t picHeight, uint32_t stride, uint32_t addr,
                         int mapType, int framesNum)
{
    uint32_t sizeLuma, sizeChroma, sizeAll, sizeMvCol = 0;
    uint32_t lum_top_base, lum_bot_base, chr_top_base, chr_bot_base;
    int i;

//    sizeLuma = ((picHeight + 31) & 0xffe0) * stride;
    sizeLuma = FRAME_MAX_WIDTH * FRAME_MAX_HEIGHT;
    sizeChroma = sizeLuma >> 2;

    if (mapType) {
        sizeLuma = (sizeLuma + 0x3fff) & 0xffffc000;
        sizeChroma = (sizeChroma + 0x3fff) & 0xffffc000;
        sizeAll = sizeLuma + 2 * sizeChroma;
        sizeMvCol = (sizeMvCol + 0x3fff) & 0xffffc000;

        for (i = 0; i < framesNum; ++i) {
            lum_top_base = addr;
            lum_bot_base = lum_top_base + sizeLuma / 2;
            chr_top_base = lum_top_base + sizeLuma;
            chr_bot_base = chr_top_base + sizeChroma;

            pBuffer[i].bufY = (lum_top_base & 0xfffff000) + (chr_top_base >> 20);
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufY, 0x10, sizeLuma);
            pBuffer[i].bufCb =
                ((chr_top_base & 0x000ff000) << 12) + ((lum_bot_base & 0xfffff000) >> 8) +
                (chr_bot_base >> 28);
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufCb, 0x80, sizeChroma);
            pBuffer[i].bufCr = (chr_bot_base & 0x0ffff000) << 4;
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufCr, 0x80, sizeChroma);

            addr += sizeAll;
        }
    } else {
        sizeAll = sizeLuma + 2 * sizeChroma;
        sizeMvCol = (sizeAll + 3) / 5;
        sizeMvCol = (sizeMvCol + 7) & 0xfffffff8;

        for (i = 0; i < framesNum; ++i) {
            pBuffer[i].bufY = addr;
            pBuffer[i].bufCb = addr + sizeLuma;
            pBuffer[i].bufCr = addr + sizeLuma + sizeChroma;
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufY, 0x10, sizeLuma);
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufCb, 0x80, sizeChroma);
            VPU_CleanFrameBuffer((PhysicalAddress *) pBuffer[i].bufCr, 0x80, sizeChroma);
            addr += sizeAll;
        }
    }

    for (i = 0; i < framesNum; ++i) {
        pBuffer[i].bufMvCol = addr;
        addr += sizeMvCol;
        pBuffer[i].myIndex = i;
        pBuffer[i].stride = stride;
    }

}

/* Function VPU_initDecoder()
 * This function sets the DEC_INIT command after setting the proper registers */
void VPU_initDecoder(DecHandle pHandle)
{
    uint32_t data;

    vpu_write(BIT_RD_PTR_0 + (pHandle->instId) * 8, pHandle->bitstreamBuffer);
    vpu_write(BIT_WR_PTR_0 + (pHandle->instId) * 8,
              pHandle->bitstreamBuffer + pHandle->bitstreamBufferSize);

    vpu_write(CMD_DEC_SEQ_BB_START, pHandle->bitstreamBuffer);
    vpu_write(CMD_DEC_SEQ_BB_SIZE, pHandle->bitstreamBufferSize >> 10);

    data = pHandle->mp4DeblkEnable;
    data |= pHandle->reorderEnable << 1;
    data |= pHandle->filePlayEnable << 2;
    data |= pHandle->dynamicBuffAllocEnable << 3;
    vpu_write(CMD_DEC_SEQ_OPTION, data);

    vpu_write(CMD_DEC_SEQ_START_BYTE, pHandle->streamStartByteOffset);
    vpu_write(CMD_DEC_SEQ_PS_BB_START, pHandle->psSaveBuffer);
    vpu_write(CMD_DEC_SEQ_PS_BB_SIZE, pHandle->psSaveBufferSize);

    vpu_write(CMD_DEC_SEQ_USER_DATA_OPTION, 0x0);
    vpu_write(CMD_DEC_SEQ_THM_EN, 0x0);

    vpu_run_command(pHandle->instId, pHandle->format, SEQ_INIT);

    while (VPU_IsBusy()) ;
}

/***************************** Global Functions *******************************/

RetCode VPU_GetVersionInfo(uint32_t * versionInfo)
{
    vpu_run_command(0, 0, GET_FW_VERSION);
    while (VPU_IsBusy()) ;

    *versionInfo = vpu_read(RET_FW_VER_NUM);
    return RETCODE_SUCCESS;
}

int VPU_IsBusy(void)
{
    return vpu_read(BIT_BUSY_FLAG);
}

RetCode VPU_Init(PhysicalAddress workBuf)
{
    int i;
    uint32_t data;
    unsigned short *fw_buffer;

    vpu.codeBuffer = workBuf;
    vpu.workBuffer = vpu.codeBuffer + CODE_BUF_SIZE;
    vpu.paraBuffer = vpu.workBuffer + WORK_BUF_SIZE;

    vpu.useCache = 0;
    vpu.CbCrInterleaved = 1;

    DecInstances[1].instStatus = VPU_INSTANCE_IDLE;
    DecInstances[2].instStatus = VPU_INSTANCE_IDLE;
    DecInstances[3].instStatus = VPU_INSTANCE_IDLE;
    DecInstances[4].instStatus = VPU_INSTANCE_IDLE;

    for (i = 0; i < 0x100; i += 4)
        vpu_write(0x100 + i, 0x0);

    /* download code */
    vpu_write(BIT_CODE_RUN, 0x0);

    fw_buffer = (unsigned short *)(vpu.codeBuffer);
    for (i = 0; i < bit_code_length; i += 4) {
        fw_buffer[i + 3] = bit_code[i];
        fw_buffer[i + 2] = bit_code[i + 1];
        fw_buffer[i + 1] = bit_code[i + 2];
        fw_buffer[i + 0] = bit_code[i + 3];
    }

    for (i = 0; i < 512; ++i)
        vpu_write(BIT_CODE_DOWN, (i << 16) | bit_code[i]);

    vpu_write(BIT_CODE_BUF_ADDR, vpu.codeBuffer);
    vpu_write(BIT_WORK_BUF_ADDR, vpu.workBuffer);
    vpu_write(BIT_PARA_BUF_ADDR, vpu.paraBuffer);

    vpu_write(BIT_BIT_STREAM_CTRL, VPU_ENDIAN_FORMAT);
    data = VPU_ENDIAN_FORMAT;
    data |= 0x3c * vpu.CbCrInterleaved;
    /* data |= vpu.mapType << 10;
       data |= vpu.mapType << 9; */
    vpu_write(BIT_FRAME_MEM_CTRL, data);

    vpu_write(BIT_BIT_STREAM_PARA, 0x0);
    vpu_write(BIT_INT_ENABLE, 0x0);

    vpu_write(BIT_AXI_SRAM_USE, 0x0);

    //GDI_setMapping(vpu.mapType);

    vpu_write(BIT_CODE_RUN, 0x1);

    return RETCODE_SUCCESS;
}

RetCode VPU_DecOpen(DecHandle * pHandle, DecOpenParam * pOpenParam)
{
    int i;

    /* search for a free decoder instance */
    for (i = 0; i < INSTANCES_NUM; ++i) {
        if (DecInstances[i].instStatus == VPU_INSTANCE_IDLE) {
            (*pHandle) = &(DecInstances[i]);
            (*pHandle)->instStatus = VPU_INSTANCE_PARAMS_SET;
            (*pHandle)->instId = i;
            break;
        }
    }

    if (i == INSTANCES_NUM)
        return RETCODE_FAILURE; /* no free decoder instances */

    /* copy parameters from pOpenParam */
    (*pHandle)->format = pOpenParam->bitstreamFormat;
    (*pHandle)->bitstreamBuffer = pOpenParam->bitstreamBuffer;
    (*pHandle)->bitstreamBufferSize = pOpenParam->bitstreamBufferSize;
    (*pHandle)->mp4DeblkEnable = pOpenParam->mp4DeblkEnable;
    (*pHandle)->reorderEnable = pOpenParam->reorderEnable;
    (*pHandle)->filePlayEnable = pOpenParam->filePlayEnable;
    (*pHandle)->dynamicBuffAllocEnable = pOpenParam->dynamicBuffAllocEnable;
    (*pHandle)->streamStartByteOffset = pOpenParam->streamStartByteOffset;
    (*pHandle)->mjpg_thumbNailDecEnable = pOpenParam->mjpg_thumbNailDecEnable;
    (*pHandle)->psSaveBuffer = pOpenParam->psSaveBuffer;
    (*pHandle)->psSaveBufferSize = pOpenParam->psSaveBufferSize;
    (*pHandle)->mp4Class = pOpenParam->mp4Class;
    (*pHandle)->vc1AnnexL3MetaDisable = pOpenParam->vc1AnnexL3MetaDisable;
    (*pHandle)->mapType = pOpenParam->mapType;
    (*pHandle)->tiled2LinearEnable = pOpenParam->tiled2LinearEnable;
    (*pHandle)->rotEnable = 0;  /* rotation disabled by default */
    (*pHandle)->rotMode = 0;
    (*pHandle)->deringEnable = 0;

    if (pOpenParam->mapType) {
        vpu_write(BIT_FRAME_MEM_CTRL, vpu_read(BIT_FRAME_MEM_CTRL) | 0x600);
        GDI_setMapping(pOpenParam->mapType);
    }

    return RETCODE_SUCCESS;

}

RetCode VPU_DecGetInitialInfo(DecHandle pHandle, DecInitialInfo * pInfo)
{
    uint32_t data;

    VPU_initDecoder(pHandle);

    if (!vpu_read(RET_DEC_SEQ_SUCCESS))
        return RETCODE_FAILURE;

    data = vpu_read(RET_DEC_SEQ_SRC_SIZE);
    pInfo->picWidth = (data & 0x0fff0000) >> 16;
    pInfo->picHeight = data & 0x00000fff;

    pInfo->minFrameBufferCount = vpu_read(RET_DEC_SEQ_FRAME_NEED);
    pInfo->frameBufDelay = vpu_read(RET_DEC_SEQ_FRAME_DELAY);

    /* frame rate numerator & denominator */
    pInfo->frameRateRes = vpu_read(RET_DEC_SEQ_FRATE_NR);
    pInfo->frameRateDiv = vpu_read(RET_DEC_SEQ_FRATE_DR);

    pInfo->aspectRateInfo = vpu_read(RET_DEC_SEQ_ASPECT);
    pInfo->bitRate = vpu_read(RET_DEC_SEQ_BIT_RATE);

    pInfo->mp4_dataPartitionEnable = vpu_read(RET_DEC_SEQ_INFO) & 0x1;

    pInfo->picCropRect.right = vpu_read(RET_DEC_SEQ_CROP_LEFT_RIGHT) & 0xffff;
    pInfo->picCropRect.left = vpu_read(RET_DEC_SEQ_CROP_LEFT_RIGHT) >> 16;
    pInfo->picCropRect.bottom = vpu_read(RET_DEC_SEQ_CROP_TOP_BOTTOM) & 0xffff;
    pInfo->picCropRect.top = vpu_read(RET_DEC_SEQ_CROP_TOP_BOTTOM) >> 16;

    data = vpu_read(RET_DEC_SEQ_HEADER_REPORT);
    pInfo->profile = data & 0xff;
    pInfo->level = (data & 0xff00) >> 8;
    pInfo->interlace = (data & 0x10000) >> 16;
    pInfo->direct8x8Flag = (data & 0x20000) >> 17;
    pInfo->vc1_psf = (data & 0x40000) >> 18;
    pInfo->constraint_set_flag[0] = (data & 0x080000) >> 19;
    pInfo->constraint_set_flag[1] = (data & 0x100000) >> 20;
    pInfo->constraint_set_flag[2] = (data & 0x200000) >> 21;
    pInfo->constraint_set_flag[3] = (data & 0x400000) >> 22;

    pHandle->info = (*pInfo);

    pHandle->instStatus = VPU_INSTANCE_READY_TO_DECODE;

    return RETCODE_SUCCESS;
}

RetCode VPU_DecStartOneFrame(DecHandle pHandle, DecParam * pParam)
{
    uint32_t data;

    if (pHandle->instStatus == VPU_INSTANCE_DECODING)
        return RETCODE_FRAME_NOT_COMPLETE;

    if (pHandle->instStatus != VPU_INSTANCE_READY_TO_DECODE)
        return RETCODE_WRONG_CALL_SEQUENCE;

    vpu_write(BIT_FRM_DIS_FLG_0 + pHandle->instId * 4, 0x0);

    data = 0;
    data |= pHandle->rotMode;
    data |= pHandle->rotEnable;
    data |= pHandle->deringEnable;
    vpu_write(CMD_DEC_PIC_ROT_MODE, data);

    if (pHandle->rotEnable) {
        vpu_write(CMD_DEC_PIC_ROT_INDEX, pHandle->rotBuffer.myIndex);
        vpu_write(CMD_DEC_PIC_ROT_ADDR_Y, pHandle->rotBuffer.bufY);
        vpu_write(CMD_DEC_PIC_ROT_ADDR_CB, pHandle->rotBuffer.bufCb);
        vpu_write(CMD_DEC_PIC_ROT_ADDR_CR, pHandle->rotBuffer.bufCr);
        vpu_write(CMD_DEC_PIC_ROT_STRIDE, pHandle->rotBuffer.stride);
    }

    data = pParam->prescanEnable;
    data |= pParam->prescanMode << 1;
    data |= pParam->iframeSearchEnable << 2;
    data |= pParam->skipframeMode << 3;

    vpu_write(CMD_DEC_PIC_OPTION, data);
    vpu_write(CMD_DEC_PIC_SKIP_NUM, pParam->skipframeNum);

    if (pHandle->filePlayEnable) {
        vpu_write(CMD_DEC_PIC_CHUNK_SIZE, pParam->chunkSize);
        vpu_write(CMD_DEC_PIC_BB_START, pParam->picStreamBufferAddr);
        vpu_write(CMD_DEC_PIC_START_BYTE, pParam->picStartByteOffset);
    }

    vpu_run_command(pHandle->instId, pHandle->format, PICTURE_RUN);

    return RETCODE_SUCCESS;
}

RetCode VPU_DecGetOutputInfo(DecHandle pHandle, DecOutputInfo * pInfo)
{
    uint32_t data;

    data = vpu_read(RET_DEC_PIC_SUCCESS);
    pInfo->decodingSuccess = data & 0x1;
    pInfo->notSufficientSliceBuffer = (data & 0x4) >> 2;
    pInfo->notSufficientPsBuffer = (data & 0x8) >> 3;
    pInfo->mp4PackedPBframe = (data & 0x10000) >> 16;

    pInfo->indexFrameDisplay = vpu_read(RET_DEC_PIC_IDX);
    pInfo->indexFrameDecoded = vpu_read(RET_DEC_PIC_CUR_IDX);

    pInfo->numOfErrMBs = vpu_read(RET_DEC_PIC_ERR_MB);

    data = vpu_read(RET_DEC_PIC_TYPE);
    pInfo->picType = data & 0x3;
    pInfo->interlacedFrame = (data & 0x40000) >> 18;
    pInfo->pictureStructure = (data & 0x180000) >> 19;
    pInfo->topFieldFirst = (data & 0x200000) >> 21;
    pInfo->repeatFirstField = (data & 0x400000) >> 22;
    pInfo->progressiveFrame = (data & 0x1800000) >> 23;
    pInfo->fieldSequence = (data & 0xe000000) >> 25;

    pInfo->prescanResult = vpu_read(RET_DEC_PIC_OPTION);

    pInfo->decPicCrop.right = vpu_read(RET_DEC_PIC_CROP_LEFT_RIGHT) & 0xffff;
    pInfo->decPicCrop.left = vpu_read(RET_DEC_PIC_CROP_LEFT_RIGHT) >> 16;
    pInfo->decPicCrop.bottom = vpu_read(RET_DEC_PIC_CROP_TOP_BOTTOM) & 0xffff;
    pInfo->decPicCrop.top = vpu_read(RET_DEC_PIC_CROP_TOP_BOTTOM) >> 16;

    pInfo->aspectRateInfo = vpu_read(RET_DEC_PIC_ASPECT);

    pInfo->frameRateRes = vpu_read(RET_DEC_PIC_FRATE_NR);
    pInfo->frameRateDiv = vpu_read(RET_DEC_PIC_FRATE_DR);

    data = vpu_read(RET_DEC_PIC_VP8_PIC_REPORT);
    pInfo->vp8PicInfo.showFrame = data & 0x1;
    pInfo->vp8PicInfo.versionNumber = (data & 0x6) >> 1;
    pInfo->vp8PicInfo.refIdxLast = (data & 0xff00) >> 8;
    pInfo->vp8PicInfo.refIdxAltr = (data & 0x00ff0000) >> 16;
    pInfo->vp8PicInfo.refIdxGold = data >> 24;

    data = vpu_read(RET_DEC_PIC_VP8_SCALE_INFO);
    pInfo->vp8ScaleInfo.hScaleFactor = data >> 30;
    pInfo->vp8ScaleInfo.vScaleFactor = (data & 0x30000000) >> 28;
    pInfo->vp8ScaleInfo.picWidth = (data & 0x0fffc000) >> 14;
    pInfo->vp8ScaleInfo.picHeight = data & 0x3fff;

    data = vpu_read(RET_DEC_PIC_POST);
    pInfo->hScaleFlag = (data & 0x2) >> 1;
    pInfo->vScaleFlag = (data & 0x4) >> 2;

    data = vpu_read(RET_DEC_PIC_SIZE);
    pInfo->decPicHeight = data & 0xffff;
    pInfo->decPicWidth = data >> 16;

    pInfo->packedMode = 0;

    /* pInfo->outputExpData is not supported */

    return RETCODE_SUCCESS;
}

RetCode VPU_DecGetBitstreamBuffer(DecHandle pHandle, PhysicalAddress * pRdptr,
                                  PhysicalAddress * pWrptr, uint32_t * size)
{
    *pRdptr = vpu_read(BIT_RD_PTR_0 + pHandle->instId * 8);
    *pWrptr = vpu_read(BIT_WR_PTR_0 + pHandle->instId * 8);

    if (*pWrptr >= *pRdptr)
        /* size = (rd - buf) + (buf + bufSize - wr) = rd - wr + bufsize */
        *size = *pRdptr - *pWrptr + pHandle->bitstreamBufferSize;
    else
        *size = *pRdptr - *pWrptr;

    return RETCODE_SUCCESS;
}

RetCode VPU_DecUpdateBitstreamBuffer(DecHandle pHandle, uint32_t size)
{
    uint32_t wrptr;

    wrptr = vpu_read(BIT_WR_PTR_0 + pHandle->instId * 8);

    if ((wrptr + size) > (pHandle->bitstreamBuffer + pHandle->bitstreamBufferSize))
        vpu_write(BIT_WR_PTR_0 + pHandle->instId * 8, wrptr + size - pHandle->bitstreamBufferSize);
    else
        vpu_write(BIT_WR_PTR_0 + pHandle->instId * 8, wrptr + size);

    return RETCODE_SUCCESS;
}

RetCode VPU_DecRegisterFrameBuffer(DecHandle pHandle, FrameBuffer * pBuffer, int num, int stride,
                                   DecBufInfo * pBufInfo)
{
    int i;

    pHandle->pBuffer = pBuffer;

//    getFrameBuffersAddr(pBuffer, pHandle->info.picHeight, stride, pBuffer[0].bufY, pHandle->mapType,                      num);
    /*Add by Ray: to support video other than 1080P for display with no resizing */
    getFrameBuffersAddr(pBuffer, FRAME_MAX_HEIGHT, stride, pBuffer[0].bufY, pHandle->mapType, num);

    for (i = 0; i < num; i += 2) {
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12)) = pBuffer[i].bufCb;
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12 + 0x04)) = pBuffer[i].bufY;
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12 + 0x08)) = pBuffer[i + 1].bufY;
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12 + 0x0c)) = pBuffer[i].bufCr;
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12 + 0x14)) = pBuffer[i + 1].bufCr;
        *((PhysicalAddress *) (vpu.paraBuffer + i * 12 + 0x14)) = pBuffer[i + 1].bufCb;
        *((PhysicalAddress *) (vpu.paraBuffer + 384 + i * 4)) = pBuffer[i].bufMvCol;
        *((PhysicalAddress *) (vpu.paraBuffer + 388 + i * 4)) = pBuffer[i + 1].bufMvCol;
    }

    vpu_write(CMD_SET_FRAME_BUF_NUM, num);
    vpu_write(CMD_SET_FRAME_BUF_STRIDE, stride);

    vpu_write(CMD_SET_FRAME_AXI_BIT_ADDR, pHandle->SecAxi.bufBitUse);
    vpu_write(CMD_SET_FRAME_AXI_IP_ADDR, pHandle->SecAxi.bufIpAcDcUse);
    vpu_write(CMD_SET_FRAME_AXI_DBKY_ADDR, pHandle->SecAxi.bufDbkYUse);
    vpu_write(CMD_SET_FRAME_AXI_DBKC_ADDR, pHandle->SecAxi.bufDbkCUse);
    vpu_write(CMD_SET_FRAME_AXI_OVL_ADDR, pHandle->SecAxi.bufOvlUse);
    vpu_write(CMD_SET_FRAME_AXI_BTP_ADDR, pHandle->SecAxi.bufBtpUse);

    if (pHandle->mapType) {
        vpu_write(CMD_SET_FRAME_CACHE_SIZE, VPU_CACHE_PARAMETERS);
        vpu_write(CMD_SET_FRAME_CACHE_CONFIG, VPU_CACHE_CONFIG);
    } else {
        vpu_write(CMD_SET_FRAME_CACHE_SIZE, 0x0);
        vpu_write(CMD_SET_FRAME_CACHE_CONFIG, 0x10000000);
    }

    vpu_write(CMD_SET_FRAME_MB_BUF_BASE, 0x0);

    vpu_run_command(pHandle->instId, pHandle->format, SET_FRAME_BUF);

    while (VPU_IsBusy()) ;

    return RETCODE_SUCCESS;
}

RetCode VPU_DecGiveCommand(DecHandle pHandle, CodecCommand cmd, void *pParam)
{
    uint32_t data;

    switch (cmd) {
    case ENABLE_ROTATION:
        pHandle->rotEnable = 1;
        break;

    case DISABLE_ROTATION:
        pHandle->rotEnable = 0;
        break;

    case SET_ROTATION_ANGLE:
        pHandle->rotMode |= (pHandle->rotMode & 0xfffffffc) | *(int *)pParam;
        break;

    case ENABLE_DERING:
        pHandle->deringEnable = 1;
        break;

    case DISABLE_DERING:
        pHandle->deringEnable = 0;
        break;

    case SET_MIRROR_DIRECTION:
        pHandle->rotMode &= 0xfffffff3;
        pHandle->rotMode |= *(MirrorDirection *) pParam;
        break;

    case SET_ROTATOR_OUTPUT:
        pHandle->rotBuffer = *(FrameBuffer *) pParam;
        break;

    case SET_ROTATOR_STRIDE:
        pHandle->rotBuffer.stride = *(int *)pParam;
        break;

    case SET_SEC_AXI:
        pHandle->SecAxi = *(SecAxiUse *) pParam;
        data = pHandle->SecAxi.useBitEnable |
            pHandle->SecAxi.useIpEnable << 1 |
            pHandle->SecAxi.useDbkYEnable << 2 |
            pHandle->SecAxi.useDbkCEnable << 3 |
            pHandle->SecAxi.useOvlEnable << 4 |
            pHandle->SecAxi.useBtpEnable << 5 |
            pHandle->SecAxi.useHostBitEnable << 8 |
            pHandle->SecAxi.useHostIpEnable << 9 |
            pHandle->SecAxi.useHostDbkYEnable << 10 |
            pHandle->SecAxi.useHostDbkCEnable << 11 |
            pHandle->SecAxi.useHostOvlEnable << 12 | pHandle->SecAxi.useHostBtpEnable << 13;
        vpu_write(BIT_AXI_SRAM_USE, data);
        break;

    default:
        return RETCODE_INVALID_COMMAND;
    };

    return RETCODE_SUCCESS;
}

RetCode VPU_EnableInterrupt(IntSelect intSel)
{
    vpu_write(BIT_INT_ENABLE, 1 << intSel);

    return RETCODE_SUCCESS;
}

RetCode VPU_ClearInterrupt()
{
    vpu_write(BIT_INT_CLEAR, 1);

    return RETCODE_SUCCESS;
}
