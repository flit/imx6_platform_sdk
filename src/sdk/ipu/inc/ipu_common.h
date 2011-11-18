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
#include "hardware.h"
#include "ipu_reg_def.h"
#include "buffers.h"
#include "../../ldb/inc/ldb_def.h"

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

enum {
    NO_CSC,
    RGB_YUV,
    YUV_RGB,
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
#define NON_INTERLEAVED_SLUV 	1, 128,14
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

/*common definition for interleaved and non-interleaved channel descriptor.*/
#define CPMEM_XV 		NON_INTERLEAVED_XV
#define CPMEM_YV 		NON_INTERLEAVED_YV
#define CPMEM_XB 		NON_INTERLEAVED_XB
#define CPMEM_YB 		NON_INTERLEAVED_YB
#define CPMEM_NSBB 		NON_INTERLEAVED_NSBB
#define CPMEM_CF 		NON_INTERLEAVED_CF
#define CPMEM_SO 		NON_INTERLEAVED_SO
#define CPMEM_BNDM  	NON_INTERLEAVED_BNDM
#define CPMEM_BM 		NON_INTERLEAVED_BM
#define CPMEM_ROT 		NON_INTERLEAVED_ROT
#define CPMEM_HF 		NON_INTERLEAVED_HF
#define CPMEM_VF 		NON_INTERLEAVED_VF
#define CPMEM_THE 		NON_INTERLEAVED_THE
#define CPMEM_CAP 		NON_INTERLEAVED_CAP
#define CPMEM_CAE 		NON_INTERLEAVED_CAE
#define CPMEM_FW 		NON_INTERLEAVED_FW
#define CPMEM_FH 		NON_INTERLEAVED_FH
#define CPMEM_EBA0 		NON_INTERLEAVED_EBA0
#define CPMEM_EBA1 		NON_INTERLEAVED_EBA1
#define CPMEM_ILO 		NON_INTERLEAVED_ILO
#define CPMEM_NPB 		NON_INTERLEAVED_NPB
#define CPMEM_PFS 		NON_INTERLEAVED_PFS
#define CPMEM_ALU 		NON_INTERLEAVED_ALU
#define CPMEM_ALBM 		NON_INTERLEAVED_ALBM
#define CPMEM_ID 		NON_INTERLEAVED_ID
#define CPMEM_TH 		NON_INTERLEAVED_TH
#define CPMEM_CRE 		NON_INTERLEAVED_CRE

enum disp_port {
    IPU1_DI0,
    IPU1_DI1,
    IPU2_DI0,
    IPU2_DI1,
};

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
    IC_PP_RES_TO_MEM_CH22 = 22,
    MEM_TO_DP_BG_CH23 = 23,
    MEM_TO_DP_FG_CH27 = 27,
    MEM_TO_DC_CH28 = 28,
    MEM_TO_IC_PRPENC_ROT_CH45 = 45,
    MEM_TO_IC_PRPVF_ROT_CH46 = 46,
    MEM_TO_IC_PP_ROT_CH47 = 47,
    IC_PRPENC_ROT_TO_MEM_CH48 = 48,
    IC_PRPVF_ROT_TO_MEM_CH49 = 49,
    IC_PP_ROT_TO_MEM_CH50 = 50,
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
    IC_ROT,
};

typedef enum {
    NON_INTERLEAVED_YUV444 = 0x0,
    NON_INTERLEAVED_YUV422 = 0x1,
    NON_INTERLEAVED_YUV420 = 0x2,
    PARTIAL_INTERLEAVED_YUV422 = 0x3,
    PARTIAL_INTERLEAVED_YUV420 = 0x4,
    INTERLEAVED_LUT = 0x5,
    INTERLEAVED_GENERIC = 0x6,
    INTERLEAVED_RGB = 0x7,
    INTERLEAVED_Y1U1Y2V1 = 0x8,
    INTERLEAVED_Y2U1Y1V1 = 0x9,
    INTERLEAVED_U1Y1V1Y2 = 0xA,
    INTERLEAVED_U1Y2V1Y1 = 0xB,
} ips_dma_colorimetry_e;

typedef enum {
    DCMAP_RGB565,
    DCMAP_RGB666,
    DCMAP_RGB666H,
    DCMAP_RGB666L,
    DCMAP_RGB888,
    DCMAP_GBR888,
    DCMAP_BRG888,
    DCMAP_YUV888,
    DCMAP_UVY888,
    DCMAP_VYU888,
    DCMAP_RGBA8888,
    DCMAP_YUVA8888,
} ips_dcmap_colorimetry_e;

enum disp_dev_flag {
    EPSON_VGA,
    CLAA_WVGA,
    SEIKO_WVGA_7INCH,
    SEIKO_WVGA_4_3INCH,
    AUO_XGA_LVDS,
    HannStar_XGA_LVDS,
    CHIMEI_HD1080_LVDS,
    VGAOUT_XGA,
    DVI_SVGA,
    DVI_XGA,
    DVI_SXGA,
    TV_NTSC,
    TV_PAL,
    TV_720P60,
    TV_1080P30,
    TV_1080P25,
    TV_1080P24,
    TV_1080I60,
    HDMI_480P60,
    HDMI_720P60,
    HDMI_1080P24,
    HDMI_1080P25,
    HDMI_1080P30,
    HDMI_1080P60,
};

typedef struct {
    char panel_name[32];
    uint32_t panel_id;
    uint32_t colorimetry;
    uint32_t refresh_rate;
    uint32_t width;
    uint32_t height;
    uint32_t pixel_clock;
    uint32_t hsync_start_width;
    uint32_t hsync_width;
    uint32_t hsync_end_width;
    uint32_t vsync_start_width;
    uint32_t vsync_width;
    uint32_t vsync_end_width;
    uint32_t delay_h2v;
    uint32_t interlaced;
    uint32_t clk_sel;
    uint32_t clk_pol;
    uint32_t hsync_pol;
    uint32_t vsync_pol;
    uint32_t drdy_pol;
    uint32_t data_pol;
    int (*panel_init) (void);
    int (*panel_deinit) (void);
} ips_dev_panel_t;

typedef struct ipu_res_info {
    uint32_t addr0_in;
    uint32_t addr1_in;
    uint32_t addr0_out;
    uint32_t addr1_out;
    uint32_t width_in;
    uint32_t height_in;
    uint32_t width_out;
    uint32_t height_out;
    uint32_t strideline_in;     //sl for interleaved mode, sly for non-interleaved mode
    uint32_t strideline_out;
    uint32_t u_offset_in;
    uint32_t u_offset_out;
    uint32_t pixel_format_in;
    uint32_t pixel_format_out;
} ipu_res_info_t;

typedef struct ipu_rot_info {
    uint32_t addr0_in;
    uint32_t addr1_in;
    uint32_t addr0_out;
    uint32_t addr1_out;
    uint32_t width_in;
    uint32_t height_in;
    uint32_t width_out;
    uint32_t height_out;
    uint32_t strideline_in;
    uint32_t strideline_out;
    uint32_t ubo_in;
    uint32_t ubo_out;
    uint32_t pixel_format_in;
    uint32_t pixel_format_out;
    uint32_t rot;
    uint32_t hf;
    uint32_t vf;
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

int ipu_sw_reset(int ipu_index, int timeout);
void ipu_disable_display(int ipu_index);
void ipu_display_setup(uint32_t ipu_index, ips_dev_panel_t * panel, uint32_t mem_colorimetry,
                       uint32_t csc_typ);
void ipu_dual_display_setup(uint32_t ipu_index, ips_dev_panel_t * panel, uint32_t mem_colorimetry,
                            uint32_t fg_width, uint32_t fg_height);
void ipu_enable_display(int ipu_index);

void ipu_disp_bg_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                              uint32_t pixel_format);
void ipu_disp_fg_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                              uint32_t pixel_format);
void ipu_dualdisp_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                               uint32_t pixel_format);
void ipu_singledisp_idmac_config(uint32_t ipu_index, uint32_t width, uint32_t height,
                                 uint32_t pixel_format);

void ipu_rotate_idmac_config(uint32_t ipu_index, uint32_t channel_in, uint32_t channel_out,
                             ipu_rot_info_t rot_info);
void ipu_resize_idmac_config(uint32_t ipu_index, uint32_t channel_in, uint32_t channel_out,
                             ipu_res_info_t res_info);
void ipu_idma_pixel_format_config(uint32_t ipu_index, uint32_t channel, uint32_t pixel_format,
                                  uint32_t sl, uint32_t ubo);
int ipu_idmac_channel_busy(int ipu_index, int channel);
void ipu_idmac_channel_enable(int ipu_index, int channel, int enable);
void ipu_channel_buf_ready(int ipu_index, int channel, int buf);

void ipu_dmfc_config(uint32_t ipu_index, uint32_t channel);

void ipu_dc_config(uint32_t ipu_index, uint32_t channel, uint32_t di, uint32_t width,
                   uint32_t colorimetry);
void ipu_dc_microcode_config(int ipu_index, dc_microcode_t microcode);
void ipu_dc_microcode_event(int ipu_index, int channel, int event, int priority, int address);
int ipu_dc_write_channel_config(int ipu_index, int dma_channel, int disp_port, int link_di_index,
                                int field_mode_enable);
int ipu_dc_display_config(int ipu_index, int display_port, int type, int increment, int strideline);
int ipu_dc_map(int ipu_index, int map, int format);
void microcode_event(int ipu_index, char channel[1], char event[8], int priority, int address);

void ipu_dp_fg_config(uint32_t ipu_index, uint32_t dual_disp, uint32_t fg_xp, uint32_t fg_yp,
                      uint32_t alpha);
void ipu_dp_csc_config(uint32_t ipu_index, uint32_t dp, uint32_t csc_type);
void ipu_dp_config(uint32_t ipu_index, uint32_t csc_type, uint32_t dual_disp, uint32_t fg_xp,
                   uint32_t fg_yp, uint32_t alpha);

void ipu_di_config(uint32_t ipu_index, uint32_t di, ips_dev_panel_t * panel);
void ipu_di_waveform_config(int ipu_index, int di, int pointer, int set, int up, int down);
int ipu_di_screen_set(int ipu_index, int di, int screen_height);
void ipu_di_pointer_config(int ipu_index, int di, int pointer, int access, int component, int cst,
                           int *pt);
int ipu_di_bsclk_gen(int ipu_index, int di, int division, int up, int down);
void ipu_di_sync_config(int ipu_index, int di, int pointer, di_sync_wave_gen_t sync_waveform_gen);
void ipu_di_interface_set(uint32_t ipu_index, uint32_t di, ips_dev_panel_t * panel,
                          uint32_t line_prediction, uint32_t vsync_sel, uint32_t hsync_sel);

void ipu_ic_rotation_config(int ipu_index, int taskType, int rot, int hf, int vf);
void ipu_ic_resize_config(int ipu_index, int taskType, ipu_res_info_t res_info);
void ipu_ic_enable(int ipu_index, int ic_enable, int irt_enable);
int ipu_ic_calc_resize_coeffs(int in_size, int out_size, int *resize_coeff, int *downsize_coeff);
int ipu_ic_config_resize_rate(int ipu_index, char *task_type, unsigned int res_vert,
                              unsigned int down_vert, unsigned int res_horiz,
                              unsigned int down_horiz);
int ipu_ic_combine_config(int ipu_index, ic_comb_params_t comb_params);
int ipu_ic_csc_config(int ipu_index, int csc_set_index, ic_csc_params_t csc_params);
int ipu_ic_task_enable(int ipu_index, int task_type, int task, int enable);

void ipu_write_field(int ipu_index, unsigned int ID_addr, unsigned int ID_mask, unsigned int data);

ips_dev_panel_t *search_panel(char *panel_name);
void load_centralized_image(uint32_t addr, ips_dev_panel_t * panel);
void load_foreground_image(uint32_t addr, uint32_t width, uint32_t height);
void set_background_margin(ips_dev_panel_t * panel, uint32_t width, uint32_t height);

void load_horiz_image(uint32_t addr, uint32_t width, uint32_t height);

extern ips_dev_panel_t disp_dev_list[];
extern uint32_t num_of_panels;

#endif
