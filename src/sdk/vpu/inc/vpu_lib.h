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
 * @file vpu_lib.h
 *
 * @brief header file for codec API funcitons for VPU
 *
 * @ingroup VPU
 */

#ifndef __VPU__LIB__H
#define __VPU__LIB__H

#include "io.h"

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
    RETCODE_MEMORY_ACCESS_VIOLATION = -18
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

    SET_MC_CACHE_CONFIG,
    ENABLE_MC_CACHE,
    DISABLE_MC_CACHE,
    SET_WRITE_MEM_PROTECT,
    SET_JPG_HEADER_BUFFER,

    ENC_SET_SUB_FRAME_SYNC,
    ENC_ENABLE_SUB_FRAME_SYNC,
    ENC_DISABLE_SUB_FRAME_SYNC
} CodecCommand;

typedef struct {
    uint32_t strideY;
    uint32_t strideC;
    int myIndex;
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
    CHROMA_FORMAT_420,
    CHROMA_FORMAT_422,
    CHROMA_FORMAT_224,
    CHROMA_FORMAT_444,
    CHROMA_FORMAT_400
} ChromaFormat;

typedef struct {
    int DbkOffsetA;
    int DbkOffsetB;
    int DbkOffsetEnable;
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
    int bitstreamBufferSize;
    int qpReport;
    int mp4DeblkEnable;
    int reorderEnable;
    int chromaInterleave;
    int filePlayEnable;
    int picWidth;
    int picHeight;
    int dynamicAllocEnable;
    int streamStartByteOffset;
    int mjpg_thumbNailDecEnable;
    PhysicalAddress psSaveBuffer;
    int psSaveBufferSize;
    int mp4Class;

    int vc1AnnexL3MetaDisable;
    int mapType;
    int tiled2LinearEnable;
} DecOpenParam;

typedef struct {
    int frameBufStatBufSize;    /* Size of buffer to save Frame Buffer Status */
    int mbInfoBufSize;          /* Size of buffer to save Mb information for Error Concealment  */
    int mvInfoBufSize;          /* Size of buffer to save Motion vector information */
} DecReportBufSize;

typedef struct {
    uint8_t *pHeader;
    int headerSize;
} JpegHeaderBufInfo;

typedef struct {
    int picWidth;               // {(PicX+15)/16} * 16
    int picHeight;              // {(PicY+15)/16} * 16
    uint32_t frameRateInfo;
    uint32_t frameRateRes;
    uint32_t frameRateDiv;

    Rect picCropRect;

    int mp4_dataPartitionEnable;
    int mp4_reversibleVlcEnable;
    int mp4_shortVideoHeader;
    int h263_annexJEnable;

    int minFrameBufferCount;
    int frameBufDelay;
    int nextDecodedIdxNum;
    int normalSliceSize;
    int worstSliceSize;
    int mjpg_thumbNailEnable;
    int mjpg_sourceFormat;

    int streamInfoObtained;
    int profile;
    int level;
    int interlace;
    int constraint_set_flag[4];
    int direct8x8Flag;
    int vc1_psf;
    int aspectRateInfo;
    uint32_t errorcode;

    int bitRate;
    Vp8ScaleInfo vp8ScaleInfo;
    int mjpg_ecsPtr;

    DecReportBufSize reportBufSize;
} DecInitialInfo;

typedef struct {
    PhysicalAddress bufferBase;
    int bufferSize;
} ExtBufCfg;

typedef struct {
    int sliceMode;
    int sliceSizeMode;
    int sliceSize;
} EncSliceMode;

typedef struct {
    PhysicalAddress sliceSaveBuffer;
    int sliceSaveBufferSize;
} DecAvcSliceBufInfo;

typedef struct {
    int maxMbX;
    int maxMbY;
    int maxMbNum;
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
    int prescanEnable;
    int prescanMode;
    int dispReorderBuf;
    int iframeSearchEnable;
    int skipframeMode;
    int skipframeNum;
    int chunkSize;
    int picStartByteOffset;
    PhysicalAddress picStreamBufferAddr;
} DecParam;

typedef struct {
    int enable;
    int size;
    union {
        int mvNumPerMb;
        int userDataNum;
    };
    union {
        int reserved;
        int userDataBufFull;
    };
    uint8_t *addr;
} DecReportInfo;

typedef struct {
    unsigned showFrame:1;
    unsigned versionNumber:3;
    unsigned refIdxLast:8;
    unsigned refIdxAltr:8;
    unsigned refIdxGold:8;
} Vp8PicInfo;

typedef struct {
    int indexFrameDisplay;
    int indexFrameDecoded;
    int NumDecFrameBuf;
    int picType;
    int numOfErrMBs;
    uint32_t *qpInfo;
    int hScaleFlag;
    int vScaleFlag;
    int indexFrameRangemap;
    int prescanresult;
    int notSufficientPsBuffer;
    int notSufficientSliceBuffer;
    int decodingSuccess;
    int interlacedFrame;
    int mp4PackedPBframe;
    int h264Npf;

    int pictureStructure;
    int topFieldFirst;
    int repeatFirstField;
    union {
        int progressiveFrame;
        int vc1_repeatFrame;
    };
    int fieldSequence;

    int decPicHeight;
    int decPicWidth;
    Rect decPicCrop;

    int aspectRateInfo;
    uint32_t frameRateRes;
    uint32_t frameRateDiv;
    Vp8ScaleInfo vp8ScaleInfo;
    Vp8PicInfo vp8PicInfo;
    int mjpg_consumedByte;

    DecReportInfo mbInfo;
    DecReportInfo mvInfo;
    DecReportInfo frameBufStat;
    DecReportInfo userData;
} DecOutputInfo;

/* encode struct and definition */
typedef struct CodecInst EncInst;
typedef EncInst *EncHandle;

typedef struct {
    int mp4_dataPartitionEnable;
    int mp4_reversibleVlcEnable;
    int mp4_intraDcVlcThr;
    int mp4_hecEnable;
    int mp4_verid;
} EncMp4Param;

typedef struct {
    int h263_annexIEnable;
    int h263_annexJEnable;
    int h263_annexKEnable;
    int h263_annexTEnable;
} EncH263Param;

typedef struct {
    int avc_constrainedIntraPredFlag;
    int avc_disableDeblk;
    int avc_deblkFilterOffsetAlpha;
    int avc_deblkFilterOffsetBeta;
    int avc_chromaQpOffset;
    int avc_audEnable;
    int avc_fmoEnable;
    int avc_fmoSliceNum;
    int avc_fmoType;
    int avc_fmoSliceSaveBufSize;
    int avc_frameCroppingFlag;
    int avc_frameCropLeft;
    int avc_frameCropRight;
    int avc_frameCropTop;
    int avc_frameCropBottom;
} EncAvcParam;

typedef struct {
    int mjpg_sourceFormat;
    int mjpg_restartInterval;
    int mjpg_thumbNailEnable;
    int mjpg_thumbNailWidth;
    int mjpg_thumbNailHeight;
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

    int picWidth;
    int picHeight;
    uint32_t frameRateInfo;
    int bitRate;
    int initialDelay;
    int vbvBufferSize;
    int enableAutoSkip;
    int gopSize;

    EncSliceMode slicemode;
    int intraRefresh;

    int sliceReport;
    int mbReport;
    int mbQpReport;

    int rcIntraQp;
    int chromaInterleave;
    int dynamicAllocEnable;
    int ringBufferEnable;

    union {
        EncMp4Param mp4Param;
        EncH263Param h263Param;
        EncAvcParam avcParam;
        EncMjpgParam mjpgParam;
    } EncStdParam;

    int userQpMin;
    int userQpMax;
    int userQpMinEnable;
    int userQpMaxEnable;

    uint32_t userGamma;
    int RcIntervalMode;         /* 0:normal, 1:frame_level, 2:slice_level, 3: user defined Mb_level */
    int MbInterval;             /* use when RcintervalMode is 3 */
    int avcIntra16x16OnlyModeEnable;
    int MESearchRange;          // 3: 16x16, 2:32x16, 1:64x32, 0:128x64, H.263(Short Header : always 3)
    int MEUseZeroPmv;           // 0: PMV_ENABLE, 1: PMV_DISABLE
    int IntraCostWeight;        // Additional weight of Intra Cost for mode decision to reduce Intra MB density
} EncOpenParam;

typedef struct {
    int sliceInfoBufSize;       /* Slice Info */
    int mbInfoBufSize;          /* Mb Param for Error Concealment */
    int mvInfoBufSize;          /* Motion vector */
} EncReportBufSize;

typedef struct {
    int minFrameBufferCount;
    EncReportBufSize reportBufSize;
} EncInitialInfo;

typedef struct {
    FrameBuffer *sourceFrame;
    int encTopOffset;
    int encLeftOffset;
    int forceIPicture;
    int skipPicture;
    int quantParam;
    PhysicalAddress picStreamBufferAddr;
    int picStreamBufferSize;
    int enableAutoSkip;
} EncParam;

typedef struct {
    int enable;
    int type;
    int size;
    uint8_t *addr;
} EncReportInfo;

typedef struct {
    PhysicalAddress bitstreamBuffer;
    uint32_t bitstreamSize;
    int bitstreamWrapAround;
    int skipEncoded;
    int picType;
    int numOfSlices;
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
    int size;
} EncParamSet;

typedef struct {
    PhysicalAddress searchRamAddr;
    int SearchRamSize;
} SearchRamParam;

typedef struct {
    PhysicalAddress buf;
    int size;
    int headerType;
    int userProfileLevelEnable;
    int userProfileLevelIndication;
} EncHeaderParam;

typedef enum {
    VOL_HEADER,                 /* video object layer header */
    VOS_HEADER,                 /* visual object sequence header */
    VIS_HEADER                  /* video object header */
} Mp4HeaderType;

typedef enum {
    SPS_RBSP,
    PPS_RBSP
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
 * lib_major increases when a new platform support is added
 * lib_minor increases when one firmware is upgraded
 * lib_release increases when bug fixes, excluding the above cases
 */
typedef struct vpu_versioninfo {
    int fw_major;               /* firmware major version */
    int fw_minor;               /* firmware minor version */
    int fw_release;             /* firmware release version */
    int lib_major;              /* library major version */
    int lib_minor;              /* library minor version */
    int lib_release;            /* library release version */
} vpu_versioninfo;

#define VPU_FW_VERSION(major, minor, release)	 \
	(((major) << 12) + ((minor) << 8) + (release))

#define VPU_LIB_VERSION(major, minor, release)	 \
	(((major) << 12) + ((minor) << 8) + (release))

#define VPU_LIB_VERSION_CODE	VPU_LIB_VERSION(5, 1, 4)

extern unsigned int system_rev;

#define CHIP_REV_1_0            	0x10
#define CHIP_REV_2_0			0x20
#define CHIP_REV_2_1            	0x21

#define mxc_cpu()               (system_rev >> 12)
#define mxc_is_cpu(part)        ((mxc_cpu() == part) ? 1 : 0)
#define mxc_cpu_rev()           (system_rev & 0xFF)
#define mxc_cpu_is_rev(rev)     \
        ((mxc_cpu_rev() == rev) ? 1 : ((mxc_cpu_rev() < rev) ? -1 : 2))
#define MXC_REV(type)                           \
static inline int type## _rev (int rev)         \
{                                               \
        return (type() ? mxc_cpu_is_rev(rev) : 0);      \
}

#define cpu_is_mx27()		mxc_is_cpu(0x27)
#define cpu_is_mx32()		mxc_is_cpu(0x32)
#define cpu_is_mx37()		mxc_is_cpu(0x37)
#define cpu_is_mx51()		mxc_is_cpu(0x51)
#define cpu_is_mx53()		mxc_is_cpu(0x53)
#define cpu_is_mx5x()		(mxc_is_cpu(0x51) || mxc_is_cpu(0x53))
#define cpu_is_mx6q()		mxc_is_cpu(0x61)

MXC_REV(cpu_is_mx27);
MXC_REV(cpu_is_mx32);
MXC_REV(cpu_is_mx37);
MXC_REV(cpu_is_mx51);

RetCode vpu_Init(void *);
void vpu_UnInit(void);
RetCode vpu_GetVersionInfo(vpu_versioninfo * verinfo);

RetCode vpu_EncOpen(EncHandle *, EncOpenParam *);
RetCode vpu_EncClose(EncHandle);
RetCode vpu_EncGetInitialInfo(EncHandle, EncInitialInfo *);
RetCode vpu_EncRegisterFrameBuffer(EncHandle handle, FrameBuffer * bufArray,
                                   int num, int frameBufStride, int sourceBufStride,
                                   PhysicalAddress subSampBaseA, PhysicalAddress subSampBaseB);
RetCode vpu_EncGetBitstreamBuffer(EncHandle handle, PhysicalAddress * prdPrt,
                                  PhysicalAddress * pwrPtr, uint32_t * size);
RetCode vpu_EncUpdateBitstreamBuffer(EncHandle handle, uint32_t size);
RetCode vpu_EncStartOneFrame(EncHandle handle, EncParam * param);
RetCode vpu_EncGetOutputInfo(EncHandle handle, EncOutputInfo * info);
RetCode vpu_EncGiveCommand(EncHandle handle, CodecCommand cmd, void *parameter);

RetCode vpu_DecOpen(DecHandle *, DecOpenParam *);
RetCode vpu_DecClose(DecHandle);
RetCode vpu_DecSetEscSeqInit(DecHandle handle, int escape);
RetCode vpu_DecGetInitialInfo(DecHandle handle, DecInitialInfo * info);
RetCode vpu_DecRegisterFrameBuffer(DecHandle handle,
                                   FrameBuffer * bufArray, int num, int stride,
                                   DecBufInfo * pBufInfo);
RetCode vpu_DecGetBitstreamBuffer(DecHandle handle, PhysicalAddress * paRdPtr,
                                  PhysicalAddress * paWrPtr, uint32_t * size);
RetCode vpu_DecUpdateBitstreamBuffer(DecHandle handle, uint32_t size);
RetCode vpu_DecStartOneFrame(DecHandle handle, DecParam * param);
RetCode vpu_DecGetOutputInfo(DecHandle handle, DecOutputInfo * info);
RetCode vpu_DecBitBufferFlush(DecHandle handle);
RetCode vpu_DecClrDispFlag(DecHandle handle, int index);
RetCode vpu_DecGiveCommand(DecHandle handle, CodecCommand cmd, void *parameter);

int vpu_IsBusy(void);
int vpu_WaitForInt(int timeout_in_ms);
RetCode vpu_SWReset(DecHandle handle, int index);
int vpu_GetXY2AXIAddr(int ycbcr, int posY, int posX, int stride,
                      unsigned int addrY, unsigned int addrCb, unsigned int addrCr);

void SaveGetEncodeHeader(EncHandle handle, int encHeaderType, char *filename);

#endif
