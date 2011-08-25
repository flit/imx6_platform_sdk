/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_common.h
 * @brief common macro and data structre defination of IPU.
 * @ingroup diag_ipu
 */

#ifndef __IPU_COMMON_H__
#define __IPU_COMMON_H__
#include "ipu_reg_def.h"
#include "ips.h"
#include "ipu_def.h"

#define CPMEM_WORD0_OFFSET	0x0
#define CPMEM_WORD1_OFFSET	0x20

enum {
    IDMAC_SINGLE_BUFFER = 0x0,
    IDMAC_DOUBLE_BUFFER = 0x1,
};

enum {
    RGB,
    YUV,
};

// DI counter definitions
#define DI_COUNTER_BASECLK 	 	0
#define DI_COUNTER_IHSYNC   	1
#define DI_COUNTER_OHSYNC   	2
#define DI_COUNTER_OVSYNC   	3
#define DI_COUNTER_ALINE    	4
#define DI_COUNTER_ACLOCK   	5

// IDMAC defines
#define INTERLEAVED_MODE 		0
#define NON_INTERLEAVED_MODE 	1

#define SHIFT_DISABLE 			0
#define SHIFT_ENABLE  			1

#define CSC_ENABLE				1
#define CSC_DISABLE				0

struct ipu_cpmem_word {
    uint32_t data[5];
    uint32_t res[3];
};

typedef struct ipu_cpmem {
    struct ipu_cpmem_word word[2];
} ipu_cpmem_t;

#define ipu_cpmem_addr(ipu, ch) ({ \
	uint32_t temp; \
	if(ipu==1) { \
		temp = (uint32_t)(((struct ipu_cpmem *)(IPU1_CTRL_BASE_ADDR+IPU_MEMORY_OFFSET)) + (ch)); \
		}else{ \
		temp = (uint32_t)(((struct ipu_cpmem *)(IPU2_CTRL_BASE_ADDR+IPU_MEMORY_OFFSET)) + (ch)); \
		}\
		temp;\
})

#define _param_word(base, w) \
	(((struct ipu_cpmem *)(base))->word[(w)].data)

/*define non-interleaved channel descriptor.
	p1 - word 0 or 1
	p2 - offset
	p3 - width
*/
#define NON_INTERLEAVED_XV 		0, 0, 10
#define NON_INTERLEAVED_YV 		0, 10, 9
#define NON_INTERLEAVED_XB 		0, 19,13
#define NON_INTERLEAVED_YB 		0, 32,12
#define NON_INTERLEAVED_NSBB 	0, 44, 1
#define NON_INTERLEAVED_CF 		0, 45, 1
#define NON_INTERLEAVED_UBO 	0, 46,22
#define NON_INTERLEAVED_VBO 	0, 68,22
#define NON_INTERLEAVED_IOX 	0, 90, 4
#define NON_INTERLEAVED_RDRW 	0, 94, 1
#define NON_INTERLEAVED_SO 		0, 113,1
#define NON_INTERLEAVED_BNDM  	0, 114,3
#define NON_INTERLEAVED_BM 		0, 117,2
#define NON_INTERLEAVED_ROT 	0, 119,1
#define NON_INTERLEAVED_HF 		0, 120,1
#define NON_INTERLEAVED_VF 		0, 121,1
#define NON_INTERLEAVED_THE 	0, 122,1
#define NON_INTERLEAVED_CAP 	0, 123,1
#define NON_INTERLEAVED_CAE 	0, 124,1
#define NON_INTERLEAVED_FW 		0, 125,13
#define NON_INTERLEAVED_FH 		0, 138,12
#define NON_INTERLEAVED_EBA0 	1, 0, 29
#define NON_INTERLEAVED_EBA1 	1, 29,29
#define NON_INTERLEAVED_ILO 	1, 58,20
#define NON_INTERLEAVED_NPB 	1, 78, 7
#define NON_INTERLEAVED_PFS 	1, 85, 4
#define NON_INTERLEAVED_ALU 	1, 89, 1
#define NON_INTERLEAVED_ALBM 	1, 90, 2
#define NON_INTERLEAVED_ID 		1, 93, 2
#define NON_INTERLEAVED_TH 		1, 95, 7
#define NON_INTERLEAVED_SLY 	1, 102,14
#define NON_INTERLEAVED_WID3 	1, 125,3
#define NON_INTERLEAVED_SLUY 	1, 128,14
#define NON_INTERLEAVED_CRE 	1, 149,1

/*define interleaved channel descriptor.
	p1 - word 0 or 1
	p2 - offset
	p3 - width
*/
#define INTERLEAVED_XV 		0, 0, 10
#define INTERLEAVED_YV 		0, 10, 9
#define INTERLEAVED_XB 		0, 19,13
#define INTERLEAVED_YB 		0, 32,12
#define INTERLEAVED_NSBB 	0, 44, 1
#define INTERLEAVED_CF 		0, 45, 1
#define INTERLEAVED_SX 		0, 46,12
#define INTERLEAVED_SY 		0, 58,11
#define INTERLEAVED_NS 		0, 69,10
#define INTERLEAVED_SDX 	0, 79, 7
#define INTERLEAVED_SM 		0, 86,10
#define INTERLEAVED_SCC 	0, 96, 1
#define INTERLEAVED_SCE 	0, 97, 1
#define INTERLEAVED_SDY 	0, 98, 7
#define INTERLEAVED_SDRX 	0, 105,1
#define INTERLEAVED_SDRY 	0, 106,1
#define INTERLEAVED_BPP 	0, 107,3
#define INTERLEAVED_DECSEL 	0, 110,2
#define INTERLEAVED_DIM 	0, 112,1
#define INTERLEAVED_SO 		0, 113,1
#define INTERLEAVED_BNDM  	0, 114,3
#define INTERLEAVED_BM 		0, 117,2
#define INTERLEAVED_ROT 	0, 119,1
#define INTERLEAVED_HF 		0, 120,1
#define INTERLEAVED_VF 		0, 121,1
#define INTERLEAVED_THE 	0, 122,1
#define INTERLEAVED_CAP 	0, 123,1
#define INTERLEAVED_CAE 	0, 124,1
#define INTERLEAVED_FW 		0, 125,13
#define INTERLEAVED_FH 		0, 138,12
#define INTERLEAVED_EBA0 	1, 0, 29
#define INTERLEAVED_EBA1 	1, 29,29
#define INTERLEAVED_ILO 	1, 58,20
#define INTERLEAVED_NPB 	1, 78, 7
#define INTERLEAVED_PFS 	1, 85, 4
#define INTERLEAVED_ALU 	1, 89, 1
#define INTERLEAVED_ALBM 	1, 90, 3
#define INTERLEAVED_ID 		1, 93, 2
#define INTERLEAVED_TH 		1, 95, 7
#define INTERLEAVED_SL 		1, 102,14
#define INTERLEAVED_WID0 	1, 116,3
#define INTERLEAVED_WID1 	1, 119,3
#define INTERLEAVED_WID2 	1, 122,3
#define INTERLEAVED_WID3 	1, 125,3
#define INTERLEAVED_OFF0 	1, 128,5
#define INTERLEAVED_OFF1 	1, 133,5
#define INTERLEAVED_OFF2 	1, 138,5
#define INTERLEAVED_OFF3 	1, 143,5
#define INTERLEAVED_SXYS 	1, 148,1
#define INTERLEAVED_CRE 	1, 149,1
#define INTERLEAVED_DECSEL2	1, 150,1

typedef struct dc_microcode {
    int addr;
    int stop;
    int opcode;
    int lf;
    int af;
    int operand;
    int mapping;
    int waveform;
    int gluelogic;
    int sync;
} dc_microcode_t;

enum dc_event {
    NL,
    NF,
    NFIELD,
    DCEOF,
    EOFIELD,
    EOL,
    NEW_CHAN,
    NEW_ADDR,
    NEW_DATA,
};

enum dc_opcode {
    HLG,
    WRG,
    HLOA,
    WROA,
    HLOD,
    WROD,
    HLOAR,
    WROAR,
    HLODR,
    WRODR,
    WRBC,
    WCLK,
    WSTSI,
    WSTSII,
    WSTSIII,
    RD,
    WACK,
    MSK,
    HMA,
    HMA1,
    BMA,
};

enum {
    CSI_TO_MEM_CH0 = 0,
    CSI_TO_MEM_CH1 = 1,
    CSI_TO_MEM_CH2 = 2,
    CSI_TO_MEM_CH3 = 3,
    MEM_TO_VDI_CH8 = 8,
    MEM_TO_VDI_CH9 = 9,
    MEM_TO_VDI_CH10 = 10,
    MEM_TO_IC_PP_RES_CH11 = 11,
    MEM_TO_IC_PRP_RES_CH12 = 12,
    VDI_TO_MEM_CH13 = 13,
    MEM_TO_IC_PPR_GPLANE_CH14 = 14,
    MEM_TO_IC_PP_GPLANE_CH15 = 15,
    MEM_TO_IC_PRP_ALPHA_CH17 = 17,
    MEM_TO_IC_PRP_ALPHA_CH18 = 18,
    IC_PRPENC_RES_TO_MEM_CH20 = 20,
    IC_PRPVF_RES_TO_MEM_CH21 = 21,
    IC_PP_RES_TO_MEM_CH21 = 22,
    MEM_TO_DP_BG_CH23 = 23,
    MEM_TO_DP_FG_CH27 = 27,
    MEM_TO_DC_CH28 = 28,
    MEM_TO_IC_PRPENC_ROT_CH45 = 45,
    MEM_TO_IC_PRPVF_ROT_CH46 = 46,
    MEM_TO_IC_PP_ROT_CH47 = 47,
    IC_PRPENC_ROT_TO_MEM_CH48 = 48,
    IC_PRPVF_ROT_TO_MEM_CH49 = 49,
    IC_PP_ROT_TO_MEM_CH48 = 50,
};

enum ic_task_type {
    PrP_ENC_TASK = 0,
    PrP_VF_TASK,
    PP_TASK,
    IC_CMB,
    IC_CSC1,
    IC_CSC2,
    IC_PP,
    IC_PRPENC,
    IC_PRPVF,
};

typedef struct ipu_res_info {
    int taskType;
    unsigned int inAddr0;
    unsigned int inAddr1;
    unsigned int outAddr0;
    unsigned int outAddr1;
    int inWidth;
    int inHeight;
    int outWidth;
    int outHeight;
    int xSplitParts;
    int ySplitParts;
    int stridelineIn;
    int stridelineOut;
    int uOffsetIn;
    int uOffsetOut;
    int vOffsetIn;
    int vOffsetOut;
    int inDataFormat;
    int outDataFormat;
} ipu_res_info_t;

typedef struct ipu_rot_info {
    int taskType;
    unsigned int inAddr0;
    unsigned int inAddr1;
    unsigned int outAddr0;
    unsigned int outAddr1;
    int inWidth;
    int inHeight;
    int outWidth;
    int outHeight;
    int stridelineIn;
    int stridelineOut;
    int uOffsetIn;
    int uOffsetOut;
    int inDataFormat;
    int outDataFormat;
    int HorizFlip;
    int VertFlip;
    int rotation;
} ipu_rot_info_t;
typedef struct alpha_chan_params {
    uint32_t alphaChanBaseAddr;
    int alphaWidth;
    int alphaHeight;
    int alphaStrideline;
} alpha_chan_params_t;

typedef struct ic_comb_params {
    int taskType;
    uint32_t baseAddr;
    int width;
    int height;
    int alpha;
    int inDataformat;
    alpha_chan_params_t alphaChan;
} ic_comb_params_t;

typedef struct ic_csc_params {
    int taskType;
    int inFormat;
    int outFormat;
} ic_csc_params_t;

typedef struct ipu_task_params {
    int taskType;
    int resEnable;
    int rotEnable;
    ipu_res_info_t resInfo;
    ipu_rot_info_t rotInfo;
} ipu_task_params_t;

typedef struct dp_fg_param {
    int fgEnable;
    int opaque;
    int offsetVert;
    int offsetHoriz;
    int cursorEnable;
    int colorKeyEnable;
    int graphicSelect;
    int alphaMode;
} dp_fg_param_t;

typedef struct di_sync_wave_gen {
    int runValue;
    int runResolution;
    int offsetValue;
    int offsetResolution;
    int cntAutoReload;
    int stepRepeat;
    int cntClrSel;
    int cntPolarityGenEn;
    int cntPolarityTrigSel;
    int cntPolarityClrSel;
    int cntUp;
    int cntDown;
} di_sync_wave_gen_t;

typedef struct di_cntl_signal {
    int vsync_sel;
    int vsync_pol;
    int hsync_sel;
    int hsync_pol;
    int clk_sel;
    int clk_pol;
    int drdy_pol;
} di_cntl_signal_t;

#define GET_LSB(bit, val)  (((uint32_t)(val)) & ((0x1<<(bit)) - 1))

typedef struct dp_csc_param {
    int mode;
    int **coeff;
} dp_csc_param_t;

typedef struct ipu_hw_ic {
    int pp_task;
    int prp_enc_task;
    int prp_vf_task;
} ipu_hw_ic_t;

typedef struct ipu_hw_di {
    int dp_path_di0;
    int dp_path_di1;
    int dc_path_di0;
    int dc_path_di1;
} ipu_hw_di_t;

typedef struct ipu_hw_resource {
    ipu_hw_ic_t ic;
    ipu_hw_di_t di;
} ipu_hw_resource_t;

void ipu_di_waveform_config(int ipu_index, int di, int pointer, int set, int up, int down);
int ipu_di_screen_set(int ipu_index, int di, int screen_height);
void ipu_di_pointer_config(int ipu_index, int di, int pointer, int access, int component, int cst,
                           int *pt);
int ipu_di_bsclk_gen(int ipu_index, int di, int division, int up, int down);
void ipu_di_sync_config(int ipu_index, int di, int pointer, di_sync_wave_gen_t sync_waveform_gen);
void ipu_di_interface_set(int ipu_index, int di, int line_prediction, ips_hw_conf_struct_t * conf);

void dc_channel_config(int ipu_index, ips_hw_conf_struct_t * conf);
void dc_event_routines(int ipu_index, ips_hw_conf_struct_t * conf);
void ipu_dc_microcode_config(int ipu_index, dc_microcode_t microcode);
void ipu_dc_microcode_event(int ipu_index, int channel, int event, int priority, int address);
int ipu_dc_write_channel_config(int ipu_index, int dma_channel, int disp_port, int link_di_index,
                                int field_mode_enable);
int ipu_dc_display_config(int ipu_index, int display_port, int type, int increment, int strideline);
int ipu_dc_map(int ipu_index, int map, int format);
void microcode_event(int ipu_index, char channel[1], char event[8], int priority, int address);
void ipu_write_field(int ipu_index, unsigned int ID_addr, unsigned int ID_mask, unsigned int data);
void ipu_idmac_config(int ipu_index, ips_hw_conf_struct_t * conf);
void ipu_dc_config(int ipu_index, ips_hw_conf_struct_t * conf);
void ipu_dp_config(int ipu_index, ips_hw_conf_struct_t * conf);
void ipu_di_config(int ipu_index, ips_hw_conf_struct_t * conf);
void load_centralized_image(ips_flow_t * flow);
void ipu_ic_enable(int ipu_index, int ic_enable, int irt_enable);
void ipu_ic_task_config(int ipu_index, ipu_task_params_t task_params);
int ipu_ic_calc_resize_coeffs(int in_size, int out_size, int *resize_coeff, int *downsize_coeff);
int ipu_ic_config_resize_rate(int ipu_index, char *task_type, unsigned int res_vert,
                              unsigned int down_vert, unsigned int res_horiz,
                              unsigned int down_horiz);
void ipu_ic_calc_vout_size(int ipu_index, ipu_res_info_t * info, ips_hw_conf_struct_t * conf,
                           int rotation, int full_screen_enable);
int ipu_ic_combine_config(int ipu_index, ic_comb_params_t comb_params);
int ipu_ic_csc_config(int ipu_index, int csc_set_index, ic_csc_params_t csc_params);
int ipu_ic_task_enable(int ipu_index, int task_type, int task, int enable);
void ipu_enable_display(int ipu_index);

#endif
