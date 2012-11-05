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
 * @file vpu_lib.h
 *
 * @brief header file for codec API funcitons for VPU
 *
 * @ingroup VPU
 */

#ifndef __VPU__LIB__H
#define __VPU__LIB__H

#include "sdk.h"

typedef uint32_t PhysicalAddress;
typedef uint32_t VirtualAddress;

#define STREAM_FULL_EMPTY_CHECK_DISABLE 0
#define BUF_PIC_FLUSH			1
#define BUF_PIC_RESET			0

#define BIT_REG_MARGIN			0x4000

#define PRJ_TRISTAN     		0xF000
#define PRJ_TRISTAN_REV			0xF001
#define PRJ_PRISM_CX			0xF002
#define PRJ_SHIVA       		0xF003
#define PRJ_PRISM_EX			0xF004
#define PRJ_BODA_CX_4			0xF005
#define PRJ_CODA_DX_6M			0xF100
#define PRJ_CODA_DX_8			0xF306
#define PRJ_BODA_DX_4V			0xF405
#define PRJ_BODADX7X			0xF009
#define	PRJ_CODAHX_14			0xF00A
#define PRJ_CODA7541			0xF012
#define PRJ_CODA_960			0xF020

#define MAX_NUM_INSTANCE		8

#define DC_TABLE_INDEX0		    0
#define AC_TABLE_INDEX0		    1
#define DC_TABLE_INDEX1		    2
#define AC_TABLE_INDEX1		    3

typedef enum {
    STD_MPEG4 = 0,
    STD_H263 = 1,
    STD_AVC = 2,
    STD_VC1 = 3,
    STD_MPEG2 = 4,
    STD_DIV3 = 5,
    STD_RV = 6,
    STD_MJPG = 7,
    STD_AVS = 8,
    STD_VP8 = 9
} CodStd;

typedef enum {
    RETCODE_SUCCESS = 0,
    RETCODE_FAILURE = -1,
    RETCODE_INVALID_HANDLE = -2,
    RETCODE_INVALID_PARAM = -3,
    RETCODE_INVALID_COMMAND = -4,
    RETCODE_ROTATOR_OUTPUT_NOT_SET = -5,
    RETCODE_ROTATOR_STRIDE_NOT_SET = -11,
    RETCODE_FRAME_NOT_COMPLETE = -6,
    RETCODE_INVALID_FRAME_BUFFER = -7,
    RETCODE_INSUFFICIENT_FRAME_BUFFERS = -8,
    RETCODE_INVALID_STRIDE = -9,
    RETCODE_WRONG_CALL_SEQUENCE = -10,
    RETCODE_CALLED_BEFORE = -12,
    RETCODE_NOT_INITIALIZED = -13,
    RETCODE_DEBLOCKING_OUTPUT_NOT_SET = -14,
    RETCODE_NOT_SUPPORTED = -15,
    RETCODE_REPORT_BUF_NOT_SET = -16,
    RETCODE_FAILURE_TIMEOUT = -17,
    RETCODE_MEMORY_ACCESS_VIOLATION = -18,
    RETCODE_JPEG_EOS = -19,
    RETCODE_JPEG_BIT_EMPTY = -20,
    RETCODE_CODEC_NOT_ISSUED = -21,
} RetCode;

typedef enum {
    LINEAR_FRAME_MAP = 0,
    TILED_FRAME_MB_RASTER_MAP = 1,
    TILED_FIELD_MB_RASTER_MAP = 2,
    TILED_MAP_TYPE_MAX
} GDI_TILED_MAP_TYPE;

typedef enum {
    ENABLE_ROTATION,
    DISABLE_ROTATION,
    ENABLE_MIRRORING,
    DISABLE_MIRRORING,
    ENABLE_DERING,
    DISABLE_DERING,
    SET_MIRROR_DIRECTION,
    SET_ROTATION_ANGLE,
    SET_ROTATOR_OUTPUT,
    SET_ROTATOR_STRIDE,
    ENC_GET_SPS_RBSP,
    ENC_GET_PPS_RBSP,
    DEC_SET_SPS_RBSP,
    DEC_SET_PPS_RBSP,
    ENC_PUT_MP4_HEADER,
    ENC_PUT_AVC_HEADER,
    ENC_SET_SEARCHRAM_PARAM,
    ENC_GET_VOS_HEADER,
    ENC_GET_VO_HEADER,
    ENC_GET_VOL_HEADER,
    ENC_GET_JPEG_HEADER,
    ENC_SET_INTRA_MB_REFRESH_NUMBER,
    DEC_SET_DEBLOCK_OUTPUT,
    ENC_ENABLE_HEC,
    ENC_DISABLE_HEC,
    ENC_SET_SLICE_INFO,
    ENC_SET_GOP_NUMBER,
    ENC_SET_INTRA_QP,
    ENC_SET_BITRATE,
    ENC_SET_FRAME_RATE,
    ENC_SET_REPORT_MBINFO,
    ENC_SET_REPORT_MVINFO,
    ENC_SET_REPORT_SLICEINFO,
    DEC_SET_REPORT_BUFSTAT,
    DEC_SET_REPORT_MBINFO,
    DEC_SET_REPORT_MVINFO,
    DEC_SET_REPORT_USERDATA,
    SET_DBK_OFFSET,
    SET_WRITE_MEM_PROTECT,

    ENC_SET_SUB_FRAME_SYNC,
    ENC_ENABLE_SUB_FRAME_SYNC,
    ENC_DISABLE_SUB_FRAME_SYNC
} CodecCommand;

typedef struct {
    uint32_t strideY;
    uint32_t strideC;
    int32_t myIndex;
    PhysicalAddress bufY;
    PhysicalAddress bufCb;
    PhysicalAddress bufCr;
    PhysicalAddress bufMvCol;
} FrameBuffer;

typedef struct {
    uint32_t left;
    uint32_t top;
    uint32_t right;
    uint32_t bottom;
} Rect;

typedef enum {
    MIRDIR_NONE,
    MIRDIR_VER,
    MIRDIR_HOR,
    MIRDIR_HOR_VER
} MirrorDirection;

typedef enum {
    FORMAT_420,
    FORMAT_422,
    FORMAT_224,
    FORMAT_444,
    FORMAT_400
} ChromaFormat;

typedef struct {
    int32_t DbkOffsetA;
    int32_t DbkOffsetB;
    int32_t DbkOffsetEnable;
} DbkOffset;

/* VP8 specific display information */
typedef struct {
    unsigned hScaleFactor:2;
    unsigned vScaleFactor:2;
    unsigned picWidth:14;
    unsigned picHeight:14;
} Vp8ScaleInfo;

/* Decode struct and definition */
typedef struct CodecInst DecInst;
typedef DecInst *DecHandle;

typedef struct {
    CodStd bitstreamFormat;
    PhysicalAddress bitstreamBuffer;
    uint8_t *pBitStream;
    int32_t bitstreamBufferSize;
    int32_t qpReport;
    int32_t mp4DeblkEnable;
    int32_t reorderEnable;
    int32_t chromaInterleave;
    int32_t filePlayEnable;     /* Not used on mx6 */
    int32_t picWidth;
    int32_t picHeight;
    int32_t avcExtension;       /* Not used on none mx6 */
    int32_t dynamicAllocEnable; /* Not used on mx6 */
    int32_t streamStartByteOffset;
    int32_t mjpg_thumbNailDecEnable;    /* Not used on mx6 */
    PhysicalAddress psSaveBuffer;
    int32_t psSaveBufferSize;
    int32_t mp4Class;

    int32_t mapType;
    int32_t tiled2LinearEnable;
    int32_t bitstreamMode;
    int32_t jpgLineBufferMode;  /* mx6 */

} DecOpenParam;

typedef struct {
    int32_t frameBufStatBufSize;    /* Size of buffer to save Frame Buffer Status */
    int32_t mbInfoBufSize;      /* Size of buffer to save Mb information for Error Concealment  */
    int32_t mvInfoBufSize;      /* Size of buffer to save Motion vector information */
} DecReportBufSize;

typedef struct {
    uint8_t *pHeader;
    int32_t headerSize;
} JpegHeaderBufInfo;

typedef struct {
    int32_t picWidth;
    int32_t picHeight;
    uint32_t frameRateInfo;     /* Not used on mx6 */
    uint32_t frameRateRes;      /* Not used on none mx6 */
    uint32_t frameRateDiv;      /* Not used on none mx6 */

    Rect picCropRect;

    int32_t mp4_dataPartitionEnable;
    int32_t mp4_reversibleVlcEnable;
    int32_t mp4_shortVideoHeader;
    int32_t h263_annexJEnable;

    int32_t minFrameBufferCount;
    int32_t frameBufDelay;
    int32_t nextDecodedIdxNum;
    int32_t normalSliceSize;
    int32_t worstSliceSize;
    int32_t mjpg_thumbNailEnable;
    int32_t mjpg_sourceFormat;

    int32_t streamInfoObtained;
    int32_t profile;
    int32_t level;
    int32_t interlace;
    int32_t constraint_set_flag[4];
    int32_t direct8x8Flag;
    int32_t vc1_psf;
    int32_t aspectRateInfo;
    uint32_t errorcode;

    int32_t bitRate;
    Vp8ScaleInfo vp8ScaleInfo;
    int32_t mjpg_ecsPtr;

    DecReportBufSize reportBufSize;
} DecInitialInfo;

typedef struct {
    PhysicalAddress bufferBase;
    int32_t bufferSize;
} ExtBufCfg;

typedef struct {
    int32_t sliceMode;
    int32_t sliceSizeMode;
    int32_t sliceSize;
} EncSliceMode;
typedef struct {
    PhysicalAddress subSampBaseAMvc;
    PhysicalAddress subSampBaseBMvc;
    ExtBufCfg scratchBuf;
} EncExtBufInfo;

typedef struct {
    PhysicalAddress sliceSaveBuffer;
    int32_t sliceSaveBufferSize;
} DecAvcSliceBufInfo;

typedef struct {
    int32_t maxMbX;
    int32_t maxMbY;
    int32_t maxMbNum;
} DecMaxFrmInfo;

typedef struct {
    ExtBufCfg avcSliceBufInfo;
    ExtBufCfg vp8MbDataBufInfo;
    DecMaxFrmInfo maxDecFrmInfo;
} DecBufInfo;

typedef enum {
    PARA_TYPE_FRM_BUF_STATUS = 1,
    PARA_TYPE_MB_PARA = 2,
    PARA_TYPE_MV = 4,
} ExtParaType;

typedef struct {
    int32_t prescanEnable;      /* Not used on mx6 */
    int32_t prescanMode;        /* Not used on mx6 */
    int32_t dispReorderBuf;
    int32_t iframeSearchEnable;
    int32_t skipframeMode;
    int32_t skipframeNum;
    int32_t chunkSize;          /* Not used on mx6 */
    int32_t picStartByteOffset; /* Not used on mx6 */
    PhysicalAddress picStreamBufferAddr;    /* Not used on mx6 */
    int32_t mjpegScaleDownRatioWidth;   /* mx6 */
    int32_t mjpegScaleDownRatioHeight;  /* mx6 */

    PhysicalAddress phyJpgChunkBase;
    unsigned char *virtJpgChunkBase;

} DecParam;

typedef struct {
    int32_t enable;
    int32_t size;
    union {
        int32_t mvNumPerMb;
        int32_t userDataNum;
    };
    union {
        int32_t reserved;
        int32_t userDataBufFull;
    };
    uint8_t *addr;
} DecReportInfo;

/* VP8 specific header information */
typedef struct {
    unsigned showFrame:1;
    unsigned versionNumber:3;
    unsigned refIdxLast:8;
    unsigned refIdxAltr:8;
    unsigned refIdxGold:8;
} Vp8PicInfo;

/* MVC specific picture information */
typedef struct {
    int32_t viewIdxDisplay;
    int32_t viewIdxDecoded;
} MvcPicInfo;

/* AVC specific SEI information (frame packing arrangement SEI) */
typedef struct {
    unsigned exist;
    unsigned frame_packing_arrangement_id;
    unsigned frame_packing_arrangement_cancel_flag;
    unsigned quincunx_sampling_flag;
    unsigned spatial_flipping_flag;
    unsigned frame0_flipped_flag;
    unsigned field_views_flag;
    unsigned current_frame_is_frame0_flag;
    unsigned frame0_self_contained_flag;
    unsigned frame1_self_contained_flag;
    unsigned frame_packing_arrangement_ext_flag;
    unsigned frame_packing_arrangement_type;
    unsigned content_interpretation_type;
    unsigned frame0_grid_position_x;
    unsigned frame0_grid_position_y;
    unsigned frame1_grid_position_x;
    unsigned frame1_grid_position_y;
    unsigned frame_packing_arrangement_repetition_period;
} AvcFpaSei;

typedef struct {
    int32_t indexFrameDisplay;
    int32_t indexFrameDecoded;
    int32_t NumDecFrameBuf;
    int32_t picType;
    int32_t picTypeFirst;       /* Not used on none mx6 */
    int32_t idrFlg;             /* Not used on none mx6 */
    int32_t numOfErrMBs;
    uint32_t *qpInfo;           /* Not used on mx5 and mx6 */
    int32_t hScaleFlag;
    int32_t vScaleFlag;
    int32_t indexFrameRangemap;
    int32_t prescanresult;      /* Not used on mx6 */
    int32_t notSufficientPsBuffer;
    int32_t notSufficientSliceBuffer;
    int32_t decodingSuccess;
    int32_t interlacedFrame;
    int32_t mp4PackedPBframe;
    int32_t h264Npf;

    int32_t pictureStructure;
    int32_t topFieldFirst;
    int32_t repeatFirstField;
    union {
        int32_t progressiveFrame;
        int32_t vc1_repeatFrame;
    };
    int32_t fieldSequence;

    int32_t decPicHeight;
    int32_t decPicWidth;
    Rect decPicCrop;

    int32_t aspectRateInfo;
    uint32_t frameRateRes;      /* Not used on none mx6 */
    uint32_t frameRateDiv;      /* Not used on none mx6 */
    Vp8ScaleInfo vp8ScaleInfo;
    Vp8PicInfo vp8PicInfo;
    MvcPicInfo mvcPicInfo;      /* Not used on none mx6 */
    AvcFpaSei avcFpaSei;

    int32_t frameStartPos;      /* Not used on none mx6 */
    int32_t frameEndPos;        /* Not used on none mx6 */
    int32_t consumedByte;       /* Not used on none mx6 */

    DecReportInfo mbInfo;       /* Not used on mx6 */
    DecReportInfo mvInfo;       /* Not used on mx6 */
    DecReportInfo frameBufStat; /* Not used on mx6 */
    DecReportInfo userData;
} DecOutputInfo;

/* encode struct and definition */
typedef struct CodecInst EncInst;
typedef EncInst *EncHandle;

typedef struct {
    int32_t mp4_dataPartitionEnable;
    int32_t mp4_reversibleVlcEnable;
    int32_t mp4_intraDcVlcThr;
    int32_t mp4_hecEnable;
    int32_t mp4_verid;
} EncMp4Param;

typedef struct {
    int32_t h263_annexIEnable;
    int32_t h263_annexJEnable;
    int32_t h263_annexKEnable;
    int32_t h263_annexTEnable;
} EncH263Param;

typedef struct {
    int32_t avc_constrainedIntraPredFlag;
    int32_t avc_disableDeblk;
    int32_t avc_deblkFilterOffsetAlpha;
    int32_t avc_deblkFilterOffsetBeta;
    int32_t avc_chromaQpOffset;
    int32_t avc_audEnable;
    int32_t avc_fmoEnable;
    int32_t avc_fmoSliceNum;
    int32_t avc_fmoType;
    int32_t avc_fmoSliceSaveBufSize;
    int32_t avc_frameCroppingFlag;
    int32_t avc_frameCropLeft;
    int32_t avc_frameCropRight;
    int32_t avc_frameCropTop;
    int32_t avc_frameCropBottom;
    int32_t mvc_extension;
    int32_t interview_en;
    int32_t paraset_refresh_en;
    int32_t prefix_nal_en;
} EncAvcParam;

typedef struct {
    int32_t mjpg_sourceFormat;
    int32_t mjpg_restartInterval;
    int32_t mjpg_thumbNailEnable;
    int32_t mjpg_thumbNailWidth;
    int32_t mjpg_thumbNailHeight;
    uint8_t *mjpg_hufTable;
    uint8_t *mjpg_qMatTable;

    uint8_t huffVal[4][162];
    uint8_t huffBits[4][256];
    uint8_t qMatTab[4][64];
    uint8_t cInfoTab[4][6];

} EncMjpgParam;

typedef struct {
    PhysicalAddress bitstreamBuffer;
    uint32_t bitstreamBufferSize;
    CodStd bitstreamFormat;

    int32_t picWidth;
    int32_t picHeight;
    uint32_t frameRateInfo;
    int32_t bitRate;
    int32_t initialDelay;
    int32_t vbvBufferSize;
    int32_t enableAutoSkip;
    int32_t gopSize;
    int32_t linear2TiledEnable;
    int32_t mapType;

    EncSliceMode slicemode;
    int32_t intraRefresh;

    int32_t sliceReport;
    int32_t mbReport;
    int32_t mbQpReport;

    int32_t rcIntraQp;
    int32_t chromaInterleave;
    int32_t dynamicAllocEnable; /* Not used for mx6 */
    int32_t ringBufferEnable;

    union {
        EncMp4Param mp4Param;
        EncH263Param h263Param;
        EncAvcParam avcParam;
        EncMjpgParam mjpgParam;
    } EncStdParam;

    int32_t userQpMin;
    int32_t userQpMax;
    int32_t userQpMinEnable;
    int32_t userQpMaxEnable;

    uint32_t userGamma;
    int32_t RcIntervalMode;     /* 0:normal, 1:frame_level, 2:slice_level, 3: user defined Mb_level */
    int32_t MbInterval;         /* use when RcintervalMode is 3 */
    int32_t avcIntra16x16OnlyModeEnable;

    int32_t MESearchRange;      // 3: 16x16, 2:32x16, 1:64x32, 0:128x64, H.263(Short Header : always 3)
    int32_t MEUseZeroPmv;       // 0: PMV_ENABLE, 1: PMV_DISABLE
    int32_t IntraCostWeight;    // Additional weight of Intra Cost for mode decision to reduce Intra MB density
} EncOpenParam;

typedef struct {
    int32_t sliceInfoBufSize;   /* Slice Info */
    int32_t mbInfoBufSize;      /* Mb Param for Error Concealment */
    int32_t mvInfoBufSize;      /* Motion vector */
} EncReportBufSize;

typedef struct {
    int32_t minFrameBufferCount;
    EncReportBufSize reportBufSize;
} EncInitialInfo;

typedef struct {
    FrameBuffer *sourceFrame;
    int32_t encTopOffset;
    int32_t encLeftOffset;
    int32_t forceIPicture;
    int32_t skipPicture;
    int32_t quantParam;
    PhysicalAddress picStreamBufferAddr;
    int32_t picStreamBufferSize;
    int32_t enableAutoSkip;
} EncParam;

typedef struct {
    int32_t enable;
    int32_t type;
    int32_t size;
    uint8_t *addr;
} EncReportInfo;

typedef struct {
    PhysicalAddress bitstreamBuffer;
    uint32_t bitstreamSize;
    int32_t bitstreamWrapAround;
    int32_t skipEncoded;
    int32_t picType;
    int32_t numOfSlices;
    int32_t reconFrameIndex;

    uint32_t *pSliceInfo;
    uint32_t *pMBInfo;
    uint32_t *pMBQpInfo;

    EncReportInfo mbInfo;
    EncReportInfo mvInfo;
    EncReportInfo sliceInfo;
} EncOutputInfo;

typedef struct {
    uint32_t *paraSet;
    uint8_t *pParaSet;
    int32_t size;
} EncParamSet;

typedef struct {
    PhysicalAddress searchRamAddr;
    int32_t SearchRamSize;
} SearchRamParam;

typedef struct {
    PhysicalAddress buf;
    int32_t size;
    int32_t headerType;
    int32_t userProfileLevelEnable;
    int32_t userProfileLevelIndication;
} EncHeaderParam;

typedef enum {
    VOL_HEADER,                 /* video object layer header */
    VOS_HEADER,                 /* visual object sequence header */
    VIS_HEADER                  /* video object header */
} Mp4HeaderType;

typedef enum {
    SPS_RBSP,
    PPS_RBSP,
    END_SEQ_RBSP,
    END_STREAM_RBSP,
    SPS_RBSP_MVC,
    PPS_RBSP_MVC
} AvcHeaderType;

typedef struct {
    uint32_t gopNumber;
    uint32_t intraQp;
    uint32_t bitrate;
    uint32_t framerate;
} stChangeRcPara;

/*
 * The firmware version is retrieved from bitcode table.
 *
 * The library version convention:
 */
typedef struct vpu_versioninfo {
    int32_t fw_major;           /* firmware major version */
    int32_t fw_minor;           /* firmware minor version */
    int32_t fw_release;         /* firmware release version */
    int32_t fw_code;            /* firmware checkin code number */
} vpu_versioninfo;

#define VPU_FW_VERSION(major, minor, release)	 \
	(((major) << 12) + ((minor) << 8) + (release))

#define VPU_LIB_VERSION(major, minor, release)	 \
	(((major) << 12) + ((minor) << 8) + (release))

extern uint32_t system_rev;

#define CHIP_REV_1_0            	0x10
#define CHIP_REV_2_0			0x20
#define CHIP_REV_2_1            	0x21

#define mxc_cpu()               (system_rev >> 12)
#define mxc_is_cpu(part)        ((mxc_cpu() == part) ? 1 : 0)
#define mxc_cpu_rev()           (system_rev & 0xFF)
#define mxc_cpu_is_rev(rev)     \
        ((mxc_cpu_rev() == rev) ? 1 : ((mxc_cpu_rev() < rev) ? -1 : 2))
#define MXC_REV(type)                           \
static inline int32_t type## _rev (int32_t rev)         \
{                                               \
        return (type() ? mxc_cpu_is_rev(rev) : 0);      \
}

#define cpu_is_mx5x()		(mxc_is_cpu(0x51) || mxc_is_cpu(0x53))
#define cpu_is_mx6q()		(mxc_is_cpu(0x61) || mxc_is_cpu(0x63))

RetCode VPU_Init(void);
void VPU_UnInit(void);
RetCode VPU_GetVersionInfo(vpu_versioninfo * verinfo);

RetCode VPU_EncOpen(EncHandle *, EncOpenParam *);
RetCode VPU_EncClose(EncHandle);
RetCode VPU_EncGetInitialInfo(EncHandle, EncInitialInfo *);
RetCode VPU_EncRegisterFrameBuffer(EncHandle handle, FrameBuffer * bufArray,
                                   int32_t num, int32_t frameBufStride, int32_t sourceBufStride,
                                   PhysicalAddress subSampBaseA, PhysicalAddress subSampBaseB,
                                   EncExtBufInfo * pBufInfo);
RetCode VPU_EncGetBitstreamBuffer(EncHandle handle, PhysicalAddress * prdPrt,
                                  PhysicalAddress * pwrPtr, uint32_t * size);
RetCode VPU_EncUpdateBitstreamBuffer(EncHandle handle, uint32_t size);
RetCode VPU_EncStartOneFrame(EncHandle handle, EncParam * param);
RetCode VPU_EncGetOutputInfo(EncHandle handle, EncOutputInfo * info);
RetCode VPU_EncGiveCommand(EncHandle handle, CodecCommand cmd, void *parameter);

RetCode VPU_DecOpen(DecHandle *, DecOpenParam *);
RetCode VPU_DecClose(DecHandle);
RetCode VPU_DecSetEscSeqInit(DecHandle handle, int32_t escape);
RetCode VPU_DecGetInitialInfo(DecHandle handle, DecInitialInfo * info);
RetCode VPU_DecRegisterFrameBuffer(DecHandle handle,
                                   FrameBuffer * bufArray, int32_t num, int32_t stride,
                                   DecBufInfo * pBufInfo);
RetCode VPU_DecGetBitstreamBuffer(DecHandle handle, PhysicalAddress * paRdPtr,
                                  PhysicalAddress * paWrPtr, uint32_t * size);
RetCode VPU_DecUpdateBitstreamBuffer(DecHandle handle, uint32_t size);
RetCode VPU_DecStartOneFrame(DecHandle handle, DecParam * param);
RetCode VPU_DecGetOutputInfo(DecHandle handle, DecOutputInfo * info);
RetCode VPU_DecBitBufferFlush(DecHandle handle);
RetCode VPU_DecClrDispFlag(DecHandle handle, int32_t index);
RetCode VPU_DecBufferCheck(DecHandle handle);
RetCode VPU_DecGiveCommand(DecHandle handle, CodecCommand cmd, void *parameter);
RetCode VPU_EnableInterrupt(int32_t sel);
RetCode VPU_ClearInterrupt(void);
int32_t VPU_IsBusy(void);
int32_t jpu_IsBusy(void);
int32_t VPU_WaitForInt(int32_t timeout_in_ms);
RetCode VPU_SWReset(int32_t forcedReset);
int VPU_GetXY2AXIAddr(DecHandle handle, int ycbcr, int posY, int posX, int stride,
                      unsigned int addrY, unsigned int addrCb, unsigned int addrCr);

#endif
