/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "ipu_reg_def.h"
#include "ips.h"

enum {
    IDMAC_SINGLE_BUFFER = 0x0,
    IDMAC_DOUBLE_BUFFER = 0x1,
};

typedef struct {
    uint32_t channel;
    uint32_t xv;
    uint32_t yv;
    uint32_t xb;
    uint32_t yb;
    uint32_t nsb_b;
    uint32_t cf;
    uint32_t sx;
    uint32_t sy;
    uint32_t ns;
    uint32_t sdx;
    uint32_t sm;
    uint32_t scc;
    uint32_t sce;
    uint32_t sdy;
    uint32_t sdrx;
    uint32_t sdry;
    uint32_t bpp;
    uint32_t dec_sel;
    uint32_t dim;
    uint32_t so;
    uint32_t bndm;
    uint32_t bm;
    uint32_t rot;
    uint32_t hf;
    uint32_t vf;
    uint32_t the;
    uint32_t cap;
    uint32_t cae;
    uint32_t fw;
    uint32_t fh;
    uint32_t eba0;
    uint32_t eba1;
    uint32_t ilo;
    uint32_t npb;
    uint32_t pfs;
    uint32_t alu;
    uint32_t albm;
    uint32_t id;
    uint32_t th;
    uint32_t sl;
    uint32_t wid0;
    uint32_t wid1;
    uint32_t wid2;
    uint32_t wid3;
    uint32_t ofs0;
    uint32_t ofs1;
    uint32_t ofs2;
    uint32_t ofs3;
    uint32_t ubo;
    uint32_t vbo;
    uint32_t sly;
    uint32_t sluv;
} ipu_channel_parameter_t;

void ipu_write_field(int ipu_index, unsigned int ID_addr, unsigned int ID_mask, unsigned int data);
void di_up_down_config(int ipu_index, int di, int pointer, int set, int up, int down);
void di_pointer_config(int ipu_index, int di, int pointer, int access, int component, int cst,
                       int pt0, int pt1, int pt2, int pt3, int pt4, int pt5, int pt6);
void di_sync_config(int ipu_index, int di, int pointer, int run_value_m1, int run_resolution,
                    int offset_value, int offset_resolution, int cnt_auto_reload, int step_repeat,
                    int cnt_clr_sel, int cnt_polarity_gen_en, int cnt_polarity_trigger_sel,
                    int cnt_polarity_clr_sel, int cnt_up, int cnt_down);
void microcode_event(int ipu_index, char channel[1], char event[8], int priority, int address);
void microcode_config(int ipu_index, int word, int stop, char opcode[10], int lf, int af,
                      int operand, int mapping, int waveform, int gluelogic, int sync);
void init_idmac_parameters(void);
void idmac_config(int ipu_index, int dataFormat);
void dmfc_config(int ipu_index);
void dp_config(int ipu_index, int cscEn);
void dc_config(int ipu_index);
void dc_channel_config(int ipu_index);
void dc_event_routines(int ipu_index);
void di_config(int ipu_index);
void ipu_enable_display(int ipu_index);
void ipu_disable_display(int ipu_index);
void ipu_channel_buf_ready(int ipu_index, int channel, int buf);
void ipu_channel_buf_not_ready(int ipu_index, int channel, int buf);
void ipu_csi_config(int ipu_index, int width, int height);
void capture_display_idmac_config(int ipu_index, int dataFormat);
int ipu_smfc_fifo_allocate(int ipu_index, int channel, int map, int burst_size);
int ipu_idmac_channel_busy(int ipu_index, int channel);
void ipu_capture_channel_link(int ipu_index);
