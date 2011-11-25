/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*   
 *   Based on Chips & Media CODE960 API Reference Manual
 */

#ifndef VPU_API_H_
#define VPU_API_H_

#include "io.h"
#include "buffers.h"
/**************************** Macro Definitions *******************************/
//------------------------------------------------------------------------------
// HARDWARE REGISTER
//------------------------------------------------------------------------------
#define BIT_CODE_RUN                0x000
#define BIT_CODE_DOWN               0x004
#define BIT_INT_REQ                 0x008
#define BIT_INT_CLEAR               0x00C
#define BIT_CUR_PC                  0x018

#define BIT_SW_RESET                0x024
#define BIT_CYCLE_INT_CNT	    0x028
#define BIT_CYCLE_EN		    0x02C
#define BIT_RESET_REQ_STS_DATA	    0x030
#define BIT_RESET_STATUS	    0x034
//------------------------------------------------------------------------------
// GLOBAL REGISTER
//------------------------------------------------------------------------------
#define BIT_CODE_BUF_ADDR           0x100
#define BIT_WORK_BUF_ADDR           0x104
#define BIT_PARA_BUF_ADDR           0x108
#define BIT_BIT_STREAM_CTRL         0x10C
#define BIT_FRAME_MEM_CTRL          0x110
#define BIT_BIT_STREAM_PARA         0x114

#define BIT_RD_PTR_0                0x120
#define BIT_WR_PTR_0                0x124
#define BIT_RD_PTR_1                0x128
#define BIT_WR_PTR_1                0x12C
#define BIT_RD_PTR_2                0x130
#define BIT_WR_PTR_2                0x134
#define BIT_RD_PTR_3                0x138
#define BIT_WR_PTR_3                0x13C

#define BIT_AXI_SRAM_USE	    0x140
#define BIT_SEARCH_BASE		    0x144
#define BIT_SEARCH_SIZE 	    0x148
#define BIT_FRAME_CYCLE             0x14C

#define BIT_FRM_DIS_FLG_0           0x150
#define BIT_FRM_DIS_FLG_1           0x154
#define BIT_FRM_DIS_FLG_2           0x158
#define BIT_FRM_DIS_FLG_3           0x15C

#define BIT_BUSY_FLAG               0x160
#define BIT_RUN_COMMAND             0x164
#define BIT_RUN_INDEX               0x168
#define BIT_RUN_COD_STD             0x16C
#define BIT_INT_ENABLE              0x170
#define BIT_INT_REASON              0x174
#define BIT_RUN_AUX_STD             0x178

#define BIT_CMD_0                   0x1E0
#define BIT_CMD_1                   0x1E4

#define BIT_MSG_0                   0x1F0
#define BIT_MSG_1                   0x1F4
#define BIT_MSG_2                   0x1F8
#define BIT_MSG_3                   0x1FC

//------------------------------------------------------------------------------
// SUB-BLOCK REGISTER
//------------------------------------------------------------------------------
// ME
#define ME_DONE                 0x060
#define ME_SRC_PIC_X            0x080
#define ME_SRC_PIC_Y            0x084
#define ME_SRC_ADDR_CB          0x090
#define ME_SRC_ADDR_CR          0x094
#define ME_SRC_ROT_MODE         0x098

#define RET_FW_VER_NUM          0x1C0
#define RET_FW_CODE_REV         0x1C4

//------------------------------------------------------------------------------
// [DEC SEQ INIT] COMMAND
//------------------------------------------------------------------------------
#define CMD_DEC_SEQ_BB_START        0x180
#define CMD_DEC_SEQ_BB_SIZE         0x184
#define CMD_DEC_SEQ_OPTION          0x188
#define CMD_DEC_SEQ_SRC_SIZE        0x18C
#define CMD_DEC_SEQ_START_BYTE      0x190
#define CMD_DEC_SEQ_PS_BB_START     0x194
#define CMD_DEC_SEQ_PS_BB_SIZE      0x198
#define CMD_DEC_SEQ_THM_EN          0x19C
#define CMD_DEC_SEQ_CLIP_MODE	    0x1A0
#define CMD_DEC_SEQ_CLIP_FROM	    0x1A4
#define CMD_DEC_SEQ_CLIP_TO	    0x1A8
#define CMD_DEC_SEQ_CLIP_CNT	    0x1B8
#define CMD_DEC_SEQ_SAM_XY	    0x198

#define CMD_DEC_SEQ_USER_DATA_OPTION    0x194
#define CMD_DEC_SEQ_USER_DATA_BASE_ADDR 0x1AC
#define CMD_DEC_SEQ_USER_DATA_BUF_SIZE  0x1B0

#define RET_DEC_SEQ_BIT_RATE        0x1B4

#define RET_DEC_SEQ_SUCCESS         0x1C0
#define RET_DEC_SEQ_SRC_FMT         0x1C4
#define RET_DEC_SEQ_SRC_SIZE        0x1C4
#define RET_DEC_SEQ_ASPECT          0x1C8
#define RET_DEC_SEQ_FRAME_NEED      0x1CC
#define RET_DEC_SEQ_FRAME_DELAY     0x1D0
#define RET_DEC_SEQ_INFO            0x1D4
#define RET_DEC_SEQ_VP8_SCALING_INFO    0x1D4
#define RET_DEC_SEQ_CROP_LEFT_RIGHT 0x1D8
#define RET_DEC_SEQ_CROP_TOP_BOTTOM 0x1DC
#define RET_DEC_SEQ_NEXT_FRAME_NUM  0x1E0
#define RET_DEC_SEQ_FRAME_FORMAT    0x1E4
#define RET_DEC_SEQ_THM_IND         0x1E8
#define RET_DEC_SEQ_HEADER_REPORT   0x1EC

#define RET_DEC_SEQ_FRATE_NR        0x1E4
#define RET_DEC_SEQ_FRATE_DR        0x1E8

//------------------------------------------------------------------------------
// [ENC SEQ INIT] COMMAND
//------------------------------------------------------------------------------
#define CMD_ENC_SEQ_BB_START        0x180
#define CMD_ENC_SEQ_BB_SIZE         0x184

#define CMD_ENC_SEQ_OPTION          0x188   // AUD, SLICE, MB BIT
#define CMD_ENC_SEQ_COD_STD         0x18C
#define CMD_ENC_SEQ_SRC_SIZE        0x190
#define CMD_ENC_SEQ_SRC_F_RATE      0x194
#define CMD_ENC_SEQ_MP4_PARA        0x198
#define CMD_ENC_SEQ_263_PARA        0x19C
#define CMD_ENC_SEQ_264_PARA        0x1A0
#define CMD_ENC_SEQ_SLICE_MODE      0x1A4
#define CMD_ENC_SEQ_GOP_NUM         0x1A8
#define CMD_ENC_SEQ_RC_PARA         0x1AC
#define CMD_ENC_SEQ_RC_BUF_SIZE     0x1B0
#define CMD_ENC_SEQ_INTRA_REFRESH   0x1B4
#define CMD_ENC_SEQ_SPP_CHUNK_SIZE  0x1B8
#define CMD_ENC_SEQ_SRCH_RAM_BASE   0x1B8
#define CMD_ENC_SEQ_SRCH_RAM_SIZE   0x1BC
#define CMD_ENC_SEQ_INTRA_QP        0x1C4
#define CMD_ENC_SEQ_RC_QP_MAX       0x1C8
#define CMD_ENC_SEQ_RC_GAMMA        0x1CC
#define CMD_ENC_SEQ_RC_MODE         0x1D0
#define CMD_ENC_SEQ_INTRA_WEIGHT    0x1D4
#define CMD_ENC_SEQ_ME_OPTION       0x1D8

#define CMD_ENC_SEQ_JPG_PARA        0x198
#define CMD_ENC_SEQ_RST_INT	    0x19C
#define CMD_ENC_SEQ_THM_EN	    0x1A0
#define CMD_ENC_SEQ_THM_SIZE	    0x1A4
#define CMD_ENC_SEQ_THM_BASE	    0x1A8

#define RET_ENC_SEQ_SUCCESS         0x1C0

//------------------------------------------------------------------------------
// [DEC PIC RUN] COMMAND
//------------------------------------------------------------------------------
#define CMD_DEC_PIC_ROT_MODE        	0x180
#define CMD_DEC_PIC_ROT_INDEX       	0x184
#define CMD_DEC_PIC_ROT_ADDR_Y      	0x188
#define CMD_DEC_PIC_ROT_ADDR_CB     	0x18C
#define CMD_DEC_PIC_ROT_ADDR_CR     	0x190
#define CMD_DEC_PIC_OPTION          	0x194
#define CMD_DEC_PIC_SKIP_NUM     	    0x198

#define CMD_DEC_PIC_CLIP_ADDR_Y		0x1A0
#define CMD_DEC_PIC_CLIP_ADDR_CB	0x1A4
#define CMD_DEC_PIC_CLIP_ADDR_CR	0x1A8
#define CMD_DEC_PIC_CHUNK_SIZE      	0x19C
#define CMD_DEC_PIC_BB_START        	0x1A0
#define CMD_DEC_PIC_START_BYTE      	0x1A4
#define CMD_DEC_PIC_PARA_BASE		0x1A8
#define CMD_DEC_PIC_USERD_BASE		0x1AC
#define CMD_DEC_PIC_USERD_SIZE		0x1B0
#define CMD_DEC_PIC_FILT_PARA		0x1B4
#define CMD_DEC_PIC_ROT_STRIDE      	0x1B8

#define RET_DEC_PIC_SIZE		    0x1BC
#define RET_DEC_PIC_FRAME_NUM       0x1C0
#define RET_DEC_PIC_IDX        	    0x1C4
#define RET_DEC_PIC_ERR_MB          0x1C8
#define RET_DEC_PIC_TYPE            0x1CC
#define RET_DEC_PIC_POST            0x1D0
#define RET_DEC_PIC_OPTION		    0x1D4
#define RET_DEC_PIC_SUCCESS		    0x1D8
#define RET_DEC_PIC_CUR_IDX		    0x1DC
#define RET_DEC_PIC_NEXT_IDX		0x1E0
#define RET_DEC_PIC_HEADER_REPORT	0x1E4
#define RET_DEC_PIC_CROP_LEFT_RIGHT 0x1E0
#define RET_DEC_PIC_CROP_TOP_BOTTOM 0x1E4
#define RET_DEC_PIC_VP8_SCALE_INFO  0x1F0
#define RET_DEC_PIC_ASPECT          0x1F0
#define RET_DEC_PIC_FRATE_NR        0x1F4
#define RET_DEC_PIC_FRATE_DR        0x1F8

#define RET_DEC_PIC_VP8_PIC_REPORT      0x1E8

//------------------------------------------------------------------------------
// [ENC PIC RUN] COMMAND
//------------------------------------------------------------------------------
#define CMD_ENC_PIC_SRC_INDEX       	0x180
#define CMD_ENC_PIC_SRC_STRIDE      	0x184
#define CMD_ENC_PIC_QS              	0x18C
#define CMD_ENC_PIC_ROT_MODE        	0x190
#define CMD_ENC_PIC_OPTION          	0x194
#define	CMD_ENC_PIC_BB_START        	0x198
#define	CMD_ENC_PIC_BB_SIZE         	0x19C

#define CMD_ENC_PIC_SRC_ADDR_Y      	0x1A8
#define CMD_ENC_PIC_SRC_ADDR_CB     	0x1AC
#define CMD_ENC_PIC_SRC_ADDR_CR     	0x1B0

//added in the 2nd early release on Aug 8th, v1.6.0 pkg
//Helen
#define CMD_ENC_PIC_SRC_BASE_INDEX  	0x1A4   /// Sub Frame Sync.

#define RET_ENC_PIC_FRAME_NUM       	0x1C0
#define RET_ENC_PIC_TYPE            	0x1C4
#define RET_ENC_PIC_FRAME_IDX       	0x1C8
#define RET_ENC_PIC_SLICE_NUM       	0x1CC
#define RET_ENC_PIC_FLAG            	0x1D0

//------------------------------------------------------------------------------
// [SET FRAME BUF] COMMAND
//------------------------------------------------------------------------------
#define CMD_SET_FRAME_BUF_NUM               0x180
#define CMD_SET_FRAME_BUF_STRIDE            0x184
#define CMD_SET_FRAME_SLICE_BB_START        0x188
#define CMD_SET_FRAME_SLICE_BB_SIZE         0x18C
#define	CMD_SET_FRAME_AXI_BIT_ADDR          0x190
#define	CMD_SET_FRAME_AXI_IP_ADDR           0x194
#define	CMD_SET_FRAME_AXI_DBKY_ADDR         0x198
#define	CMD_SET_FRAME_AXI_DBKC_ADDR         0x19C
#define	CMD_SET_FRAME_AXI_OVL_ADDR          0x1A0
#define	CMD_SET_FRAME_AXI_BTP_ADDR          0x1A4
#define	CMD_SET_FRAME_CACHE_SIZE	    0x1A8
#define	CMD_SET_FRAME_CACHE_CONFIG	    0x1AC
#define CMD_SET_FRAME_MB_BUF_BASE           0x1B0
// ENC only
#define CMD_SET_FRAME_SUBSAMP_BASE_A        0x188
#define CMD_SET_FRAME_SUBSAMP_BASE_B        0x18C

//------------------------------------------------------------------------------
// [ENC HEADER] COMMAND
//------------------------------------------------------------------------------
#define CMD_ENC_HEADER_CODE                 0x180
#define CMD_ENC_HEADER_BB_START             0x184
#define CMD_ENC_HEADER_BB_SIZE              0x188
// AVC ENC only
#define CMD_ENC_HEADER_FRAME_CROP_H         0x18C   // {FrameCropLeftSample[15:0], FrameCropRightSample[15:0]}
#define CMD_ENC_HEADER_FRAME_CROP_V         0x190   // {FrameCropTopSample[15:0], FrameCropBottomSample[15:0]}

//------------------------------------------------------------------------------
// GDMA Register definition
//------------------------------------------------------------------------------

#define GDI_CONTROL                 0x1034
#define GDI_PIC_INIT_HOST           0x1038
#define GDI_PINFO_REQ               0x1060
#define GDI_PINFO_ACK               0x1064
#define GDI_PINFO_ADDR              0x1068
#define GDI_PINFO_DATA              0x106c
#define GDI_BWB_ENABLE              0x1070
#define GDI_BWB_SIZE                0x1074
#define GDI_BWB_STD_STRUCT          0x1078
#define GDI_BWB_STATUS              0x107c
#define GDI_STATUS                  0x1080
#define GDI_WPROT_ERR_CLEAR         0x10a0
#define GDI_WPROT_ERR_RSN           0x10a4
#define GDI_WPROT_ERR_ADR           0x10a8
#define GDI_WPROT_RGN_EN            0x10ac
#define GDI_WPROT_RGN0_STA          0x10b0
#define GDI_WPROT_RGN0_END          0x10b4
#define GDI_WPROT_RGN1_STA          0x10b8
#define GDI_WPROT_RGN1_END          0x10bc
#define GDI_WPROT_RGN2_STA          0x10c0
#define GDI_WPROT_RGN2_END          0x10c4
#define GDI_WPROT_RGN3_STA          0x10c8
#define GDI_WPROT_RGN3_END          0x10cc
#define GDI_WPROT_RGN4_STA          0x10d0
#define GDI_WPROT_RGN4_END          0x10d4
#define GDI_WPROT_RGN5_STA          0x10d8
#define GDI_WPROT_RGN5_END          0x10dc
#define GDI_DCU_CTRL                0x10f0
#define GDI_DCU_STATUS              0x10f4
#define GDI_DCU_PIC_SIZE            0x10f8
#define GDI_INFO_CONTROL            0x1400
#define GDI_INFO_PIC_SIZE           0x1404
#define GDI_INFO_BASE_Y             0x1408
#define GDI_INFO_BASE_CB            0x140C
#define GDI_INFO_BASE_CR            0x1410

#define GDI_XY2_CAS_0               0x1800
#define GDI_XY2_CAS_1               0x1804
#define GDI_XY2_CAS_2               0x1808
#define GDI_XY2_CAS_3               0x180C
#define GDI_XY2_CAS_4               0x1810
#define GDI_XY2_CAS_5               0x1814
#define GDI_XY2_CAS_6               0x1818
#define GDI_XY2_CAS_7               0x181C
#define GDI_XY2_CAS_8               0x1820
#define GDI_XY2_CAS_9               0x1824
#define GDI_XY2_CAS_A               0x1828
#define GDI_XY2_CAS_B               0x182C
#define GDI_XY2_CAS_C               0x1830
#define GDI_XY2_CAS_D               0x1834
#define GDI_XY2_CAS_E               0x1838
#define GDI_XY2_CAS_F               0x183C

#define GDI_XY2_BA_0                0x1840
#define GDI_XY2_BA_1                0x1844
#define GDI_XY2_BA_2                0x1848
#define GDI_XY2_BA_3                0x184C

#define GDI_XY2_RAS_0               0x1850
#define GDI_XY2_RAS_1               0x1854
#define GDI_XY2_RAS_2               0x1858
#define GDI_XY2_RAS_3               0x185C
#define GDI_XY2_RAS_4               0x1860
#define GDI_XY2_RAS_5               0x1864
#define GDI_XY2_RAS_6               0x1868
#define GDI_XY2_RAS_7               0x186C
#define GDI_XY2_RAS_8               0x1870
#define GDI_XY2_RAS_9               0x1874
#define GDI_XY2_RAS_A               0x1878
#define GDI_XY2_RAS_B               0x187C
#define GDI_XY2_RAS_C               0x1880
#define GDI_XY2_RAS_D               0x1884
#define GDI_XY2_RAS_E               0x1888
#define GDI_XY2_RAS_F               0x188C

#define GDI_XY2_RBC_CONFIG          0x1890

#define GDI_RBC2_AXI_0              0x18A0
#define GDI_RBC2_AXI_1              0x18A4
#define GDI_RBC2_AXI_2              0x18A8
#define GDI_RBC2_AXI_3              0x18AC
#define GDI_RBC2_AXI_4              0x18B0
#define GDI_RBC2_AXI_5              0x18B4
#define GDI_RBC2_AXI_6              0x18B8
#define GDI_RBC2_AXI_7              0x18BC
#define GDI_RBC2_AXI_8              0x18C0
#define GDI_RBC2_AXI_9              0x18C4
#define GDI_RBC2_AXI_A              0x18C8
#define GDI_RBC2_AXI_B              0x18CC
#define GDI_RBC2_AXI_C              0x18D0
#define GDI_RBC2_AXI_D              0x18D4
#define GDI_RBC2_AXI_E              0x18D8
#define GDI_RBC2_AXI_F              0x18DC
#define GDI_RBC2_AXI_10             0x18E0
#define GDI_RBC2_AXI_11             0x18E4
#define GDI_RBC2_AXI_12             0x18E8
#define GDI_RBC2_AXI_13             0x18EC
#define GDI_RBC2_AXI_14             0x18F0
#define GDI_RBC2_AXI_15             0x18F4
#define GDI_RBC2_AXI_16             0x18F8
#define GDI_RBC2_AXI_17             0x18FC
#define GDI_RBC2_AXI_18             0x1900
#define GDI_RBC2_AXI_19             0x1904
#define GDI_RBC2_AXI_1A             0x1908
#define GDI_RBC2_AXI_1B             0x190C
#define GDI_RBC2_AXI_1C             0x1910
#define GDI_RBC2_AXI_1D             0x1914
#define GDI_RBC2_AXI_1E             0x1918
#define GDI_RBC2_AXI_1F             0x191C

//------------------------------------------------------------------------------
// MD5
//------------------------------------------------------------------------------
#define MD5_RUN                     0x000
#define MD5_STATUS                  0x004
#define MD5_PARAM                   0x008
#define MD5_PIC_SIZE                0x00C
#define MD5_Y_BASE                  0x010
#define MD5_CB_BASE                 0x014
#define MD5_CR_BASE                 0x018
#define MD5_Y_STRIDE                0x01C
#define MD5_C_STRIDE                0x020
#define MD5_YSIZE                   0x024
#define MD5_CSIZE                   0x028
#define MD5_Y_KEY0                  0x030
#define MD5_Y_KEY1                  0x034
#define MD5_Y_KEY2                  0x038
#define MD5_Y_KEY3                  0x03C
#define MD5_C_KEY0                  0x040
#define MD5_C_KEY1                  0x044
#define MD5_C_KEY2                  0x048
#define MD5_C_KEY3                  0x04C

// INTERRUPT ID
#define BIT_INIT_INTRPT			0x1
#define SEQ_INIT_INTRPT			0x2
#define SEQ_END_INTRPT			0x4
#define PIC_RUN_INTRPT			0x8
#define DECBUF_EMPTY_INTRPT		0x10
#define ENCBUF_FULL_INTRPT		0x20

#define VPU_CACHE_PARAMETERS    0x03330322
#define VPU_CACHE_CONFIG        0x04200808

#define VPU_ENDIAN_FORMAT		0x0

#define OFFSET_AXI_DBKY           (VPU_SEC_AXI_START + 0x0000)
#define OFFSET_AXI_DBKC           (VPU_SEC_AXI_START + 0x8000)
#define OFFSET_AXI_BIT            (VPU_SEC_AXI_START + 0x10000)
#define OFFSET_AXI_IP             (VPU_SEC_AXI_START + 0x14000)
#define OFFSET_AXI_OVL            (VPU_SEC_AXI_START + 0x18000)
#define OFFSET_AXI_BTP            (VPU_SEC_AXI_START + 0x1D000)

/***************************** Type Definitions *******************************/

typedef uint32_t PhysicalAddress;

typedef struct {
    int left;
    int top;
    int right;
    int bottom;
} Rect;

typedef enum {
    STD_H264,
    STD_VC1,
    STD_MPEG2,
    STD_MPEG4,
    STD_H263,
    STD_DIV3,
    STD_RV,
    STD_AVS,
    STD_MJPG,
    STD_THO,
    STD_VP6,
    STD_VP8
} CodStd;

typedef enum {
    RETCODE_SUCCESS,
    RETCODE_FAILURE,
    RETCODE_INVALID_HANDLE,
    RETCODE_INVALID_PARAM,
    RETCODE_INVALID_COMMAND,
    RETCODE_INVALID_OUTPUT_NOT_SET,
    RETCODE_INVALID_STRIDE_NOT_SET,
    RETCODE_FRAME_NOT_COMPLETE,
    RETCODE_INVALID_FRAME_BUFFER,
    RETCODE_INSUFFICIENT_FRAME_BUFFERS,
    RETCODE_INVALID_STRIDE,
    RETCODE_WRONG_CALL_SEQUENCE,
    RETCODE_CALLED_BEFORE,
    RETCODE_NOT_INITIALIZED,
    RETCODE_USERDATA_BUF_NOT_SET
} RetCode;

typedef enum {
    ENABLE_ROTATION,
    DISABLE_ROTATION,
    ENABLE_MIRRORING,
    DISABLE_MIRRORING,
    SET_MIRROR_DIRECTION,
    SET_ROTATION_ANGLE,
    SET_ROTATOR_OUTPUT,
    SET_ROTATOR_STRIDE,
    DEC_SET_SPS_RBSP,
    DEC_SET_PPS_RBSP,
    ENABLE_DERING,
    DISABLE_DERING,
    SET_SEC_AXI,
    ENABLE_REP_BUFSTAT,
    DISABLE_REP_BUFSTAT,
    ENABLE_REP_MBPARAM,
    DISABLE_REP_MBPARAM,
    ENABLE_REP_MV,
    DISABLE_REP_MV,
    ENABLE_REP_USERDATA,
    DISABLE_REP_USERDATA,
    SET_ADDR_REP_PICPARAM,
    SET_ADDR_REP_USERDATA,
    SET_SIZE_REP_USERDATA,
    SET_USERDATA_REPORT_MODE,
    SET_ADDR_REP_BUF_STATE,
    SET_ADDR_REP_MB_PARAM,
    SET_ADDR_REP_MV_DATA,
    SET_MC_CACHE_CONFIG,
    ENABLE_MC_CACHE,
    DISABLE_MC_CACHE,
    DEC_CMD_END
} CodecCommand;

typedef enum {
    ENC_GET_SPS_RBSP = DEC_CMD_END,
    ENC_GET_PPS_RBSP,
    ENC_PUT_MP4_HEADER,
    ENC_PUT_AVC_HEADER,
    ENC_GET_VOS_HEADER,
    ENC_GET_VO_HEADER,
    ENC_GET_VOL_HEADER,
    ENC_SET_INTRA_MB_REFRESH_NUMBER,
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
    ENC_SET_PIC_PARA_ADDR
} CodecCommandExt;

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

typedef enum {
    VPU_INSTANCE_IDLE = 0,
    VPU_INSTANCE_PARAMS_SET,
    VPU_INSTANCE_DECODER_INITIALIZED,
    VPU_INSTANCE_READY_TO_DECODE,
    VPU_INSTANCE_DECODING
} DecInstStatus;

typedef enum {
    INT_BIT0 = 0,
    SEQ_INIT_COMPLETE,
    SEQ_END_COMPLETE,
    PIC_RUN_COMPLETE,
    SET_FRAME_BUF_COMPLETE,
    ENC_HEADER_SET_COMPLETE,
    ENC_PARA_SET_COMPLETE,
    DEC_PARA_SET_COMPLETE,
    DEC_BUF_FLUSH_COMPLETE,
    BIT9,
    BIT10,
    BIT11,
    BIT12,
    WR_ACCESS_VIOL,
    DEC_BUFF_EMPTY,
    ENC_BUFF_FULL
} IntSelect;                    /* IntSelect is not part of Chips & Media API */

/**************************** Structure Definitions ****************************/

typedef struct {
    PhysicalAddress bufY;
    PhysicalAddress bufCb;
    PhysicalAddress bufCr;
    PhysicalAddress bufMvCol;
    /* Note: All of the 3 pixel component addresses must be 8-byte aligned. */
    int myIndex;
    int stride;
} FrameBuffer;

typedef struct {
    int frameBufDataSize;       /* Frame Buffer Status */
    PhysicalAddress frameBufStatDataAddr;
    int mbParamDataSize;        /* Mb Param for Error Concealment */
    PhysicalAddress mbParamDataAddr;
    int mvDataSize;             /* Motion vector */
    int mvNumPerMb;
    PhysicalAddress mvDataAddr;
    int userDataNum;            /* User Data */
    int userDataSize;
    int userDataBufFull;
} DecOutputExtData;

typedef struct {
    int useBitEnable;
    int useIpEnable;
    int useOvlEnable;
    int useDbkYEnable;
    int useDbkCEnable;
    int useBtpEnable;
    int useHostBitEnable;
    int useHostIpEnable;
    int useHostOvlEnable;
    int useHostDbkYEnable;
    int useHostDbkCEnable;
    int useHostBtpEnable;
    PhysicalAddress bufBitUse;
    PhysicalAddress bufIpAcDcUse;
    PhysicalAddress bufDbkYUse;
    PhysicalAddress bufDbkCUse;
    PhysicalAddress bufOvlUse;
    PhysicalAddress bufBtpUse;
} SecAxiUse;

typedef struct {
    unsigned hScaleFactor;
    unsigned vScaleFactor;
    unsigned picWidth;
    unsigned picHeight;
} Vp8ScaleInfo;

typedef struct {
    unsigned showFrame;
    unsigned versionNumber;
    unsigned refIdxLast;
    unsigned refIdxAltr;
    unsigned refIdxGold;
} Vp8PicInfo;

typedef struct {
    CodStd bitstreamFormat;
    PhysicalAddress bitstreamBuffer;
    int bitstreamBufferSize;
    int mp4DeblkEnable;
    int reorderEnable;
    int filePlayEnable;
    int dynamicBuffAllocEnable;
    int picWidth;
    int picHeight;
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
    int picWidth;
    int picHeight;
    uint32_t frameRateRes;
    uint32_t frameRateDiv;
    Rect picCropRect;
    uint32_t frameRateInfo;
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
    int profile;
    int level;
    int interlace;
    int constraint_set_flag[4];
    int direct8x8Flag;
    int vc1_psf;
    int aspectRateInfo;
    int bitRate;
    Vp8ScaleInfo vp8ScaleInfo;
    int userDataNum;
    int userDataSize;
    int userDataBufFull;
} DecInitialInfo;

typedef struct {
    PhysicalAddress bufferBase;
    int bufferSize;
} ExtBufCfg;

typedef struct {
    PhysicalAddress sliceSaveBuffer;
    int sliceSaveBufferSize;
} DecAvcSliceBufInfo;

typedef struct {
    DecAvcSliceBufInfo avcSliceBufInfo;
    ExtBufCfg vp8MbDataBufInfo;
} DecBufInfo;

typedef struct {
    int prescanEnable;
    int prescanMode;
    int dispReorderbuf;
    int iframeSearchEnable;
    int skipframeMode;
    int skipframeNum;
    PhysicalAddress picStreamBufferAddr;
    int picStartByteOffset;
    int chunkSize;
} DecParam;

typedef struct {
    int indexFrameDisplay;
    int indexFrameDecoded;
    int picType;
    int numOfErrMBs;
    int hScaleFlag;
    int vScaleFlag;
    int prescanResult;
    int notSufficientPsBuffer;
    int notSufficientSliceBuffer;
    int decodingSuccess;
    int interlacedFrame;
    int mp4PackedPBframe;
    int aspectRateInfo;
    uint32_t frameRateRes;
    uint32_t frameRateDiv;
    Vp8ScaleInfo vp8ScaleInfo;
    Vp8PicInfo vp8PicInfo;
    int pictureStructure;
    int topFieldFirst;
    int repeatFirstField;
    int progressiveFrame;
    int fieldSequence;
    DecOutputExtData outputExtData;
    int packedMode;
    int decPicHeight;
    int decPicWidth;
    Rect decPicCrop;
} DecOutputInfo;

typedef struct {
    int instId;
    DecInstStatus instStatus;   /* current status of decoder instance */
    CodStd format;
    PhysicalAddress bitstreamBuffer;
    int bitstreamBufferSize;
    SecAxiUse SecAxi;
    int mp4DeblkEnable;
    int reorderEnable;
    int filePlayEnable;
    int dynamicBuffAllocEnable;
    int streamStartByteOffset;
    int mjpg_thumbNailDecEnable;
    PhysicalAddress psSaveBuffer;
    int psSaveBufferSize;
    int mp4Class;
    int vc1AnnexL3MetaDisable;
    int mapType;
    int tiled2LinearEnable;
    DecInitialInfo info;
    FrameBuffer *pBuffer;
    int rotMode;                /* rotation mode */
    int rotEnable;              /* enable rotation filter */
    int deringEnable;           /* enable dering filter for rotation */
    FrameBuffer rotBuffer;
} DecInst;

typedef DecInst *DecHandle;

/*************************** Function Declarations ****************************/

/*
 *  This function initializes VPU hardware and proper data structures/resources. 
 *  Application must call this function only once before using the VPU.
 *
 * */

RetCode VPU_Init(PhysicalAddress workBuf);

/*
 *
 *
 * */

int VPU_IsBusy(void);

/*
 *  versionInfo:[output] The 16 MSB means product ID and the 16 LSB means firmware version ID. 
 * */

RetCode VPU_GetVersionInfo(uint32_t * versionInfo);

/*
 *
 * pHandle: [Output] A pointer to a DecHandle type variable which will specify each instance for application. 
 * pOpenParam: [Input] A pointer to a DecOpenParam type structure which describes required parameters for creating a new decoder instance.
 *
 * */

RetCode VPU_DecOpen(DecHandle * pHandle, DecOpenParam * pOpenParam);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * pInfo: [Output] Pointer to DecInitialInfo data structure.
 *
 * */

RetCode VPU_DecGetInitialInfo(DecHandle pHandle, DecInitialInfo * pInfo);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * escape: [Input] A flag to enable or disable forced escape from SEQ_INIT.
 * */

RetCode VPU_DecSetEscSeqInit(DecHandle pHandle, int escape);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * pRdptr: [Output] Stream buffer read pointer for the current decoder instance
 * pWrptr: [Output] Stream buffer write pointer for the current decoder instance
 * size: [Output] A variable specifying the available space in bitstream buffer for the current decoder instance.
 *
 * */

RetCode VPU_DecGetBitstreamBuffer(DecHandle pHandle, PhysicalAddress * pRdptr,
                                  PhysicalAddress * pWrptr, uint32_t * size);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * size: [Input] A variable specifying the amount of bits transferred into bitstream buffer for the current decoder instance.
 *
 **/

RetCode VPU_DecUpdateBitstreamBuffer(DecHandle pHandle, uint32_t size);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * pBuffer: [Input] ] A pointer to a FrameBuffer type structure which describes frame buffer pointer parameters for the current decoder instance.
 * num: [Input] A number of frame buffers.
 * stride: [Input] A stride value of the given frame buffers.
 * pBufInfo: [Input] A pointer to a DecBufInfo type structure which describes information on the additional work buffers. 
 * Currently sliceSaveBuffer is only declared by this structure.
 * 
 * */

RetCode VPU_DecRegisterFrameBuffer(DecHandle pHandle, FrameBuffer * pBuffer, int num, int stride,
                                   DecBufInfo * pBufInfo);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * pParam: [Input] A pointer to a DecParam type structure which describes picture decoding parameters for the given decoder instance.
 *
 * */

RetCode VPU_DecStartOneFrame(DecHandle pHandle, DecParam * pParam);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * pInfo: [Output] A pointer to a DecOutputInfo type structure which describes picture decoding results for the current decoder instance.
 *
 * */

RetCode VPU_DecGetOutputInfo(DecHandle pHandle, DecOutputInfo * pInfo);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 *
 * */

RetCode VPU_DecClose(DecHandle pHandle);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 *
 * */

RetCode VPU_DecBitBufferFlush(DecHandle pHandle);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * index: [Input] A frame buffer index to be cleared.
 *
 **/

RetCode VPU_DecClrDispFlag(DecHandle pHandle, int index);

/*
 *
 *
 * */

RetCode VPU_SleepWake(DecHandle pHandle, int index);

/*
 * pHandle: [Input] A decoder handle obtained from VPU_DecOpen().
 * cmd: [Intput] A variable specifying the given command of CodecComand type.
 * pParam: [Intput/Output] A pointer to a command-specific data structure which describes picture I/O parameters for the current decoder instance.
 *
 * */

RetCode VPU_DecGiveCommand(DecHandle pHandle, CodecCommand cmd, void *pParam);

/* The functions below are not part of Chips & Media API */
RetCode VPU_EnableInterrupt(IntSelect intSel);
RetCode VPU_ClearInterrupt(void);

#endif
