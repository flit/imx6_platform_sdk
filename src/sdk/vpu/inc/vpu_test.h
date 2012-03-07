/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VPU_TEST_H_
#define _VPU_TEST_H_
#include "hardware.h"
#include "vpu_lib.h"
#include "vpu_io.h"
#include "fat_driver.h"
#include "vpu_util.h"
#include "../../ipu/inc/ipu_common.h"
#include "../../usdhc/inc/usdhc_ifc.h"
#include "../../vdoa/inc/vdoa.h"

#define MAX_FIFO_SIZE 		32
#define NUM_FRAME_BUFS	64
#define FB_INDEX_MASK		(NUM_FRAME_BUFS - 1)

#if defined(MX6DQ_SMART_DEVICE) || defined(MX6SDL_SMART_DEVICE)
#define SD_PORT_BASE_ADDR	USDHC3_BASE_ADDR
#else
#define SD_PORT_BASE_ADDR	USDHC4_BASE_ADDR
#endif
#define SZ_4K			4 * 1024

#define STREAM_BUF_SIZE		0x200000
#define STREAM_FILL_SIZE	0x40000
#define STREAM_READ_SIZE	(512 * 8)
#define STREAM_END_SIZE		0
#define PS_SAVE_SIZE		0x080000
#define VP8_MB_SAVE_SIZE	0x080000
#define MPEG4_SCRATCH_SIZE	0x080000

#define ENCODER_OUTPUT_SIZE	0x2000000

#define STREAM_ENC_PIC_RESET 	1

#define PATH_V4L2	0
#define PATH_FILE	1
#define PATH_NET	2
#define PATH_IPU	3
#define PATH_MEM	4

/* Test operations */
#define ENCODE		1
#define DECODE		2
#define LOOPBACK	3

#define DEFAULT_PORT		5555
#define DEFAULT_PKT_SIZE	0x28000

#define SIZE_USER_BUF            0x1000
#define USER_DATA_INFO_OFFSET    8*17

#define VDOA_DIS            (0)
#define VDOA_EN             (1)

#define EPIT_EPITCR_OFFSET	0x00    //  32bit timer 3 control reg
#define EPIT_EPITSR_OFFSET	0x04    //  32bit timer 3 prescaler reg
#define EPIT_EPITLR_OFFSET	0x08    //  32bit timer 3 compare reg
#define EPIT_EPITCMPR_OFFSET	0x0C    //  32bit timer 3 capture reg
#define EPIT_EPITCNR_OFFSET	0x10    //  32bit timer 3 counter reg

enum {
    MODE420 = 0,
    MODE422 = 1,
    MODE224 = 2,
    MODE444 = 3,
    MODE400 = 4
};

struct frame_buf {
    int addrY;
    int addrCb;
    int addrCr;
    int strideY;
    int strideC;
    int mvColBuf;
    vpu_mem_desc desc;
};

struct v4l_buf {
    void *start;
    off_t offset;
    size_t length;
};

#define MAX_BUF_NUM	32
#define QUEUE_SIZE	(MAX_BUF_NUM + 1)
struct ipu_queue {
    int list[MAX_BUF_NUM + 1];
    int head;
    int tail;
};

struct ipu_buf {
    int ipu_paddr;
    void *ipu_vaddr;
    int field;
};

struct capture_testbuffer {
    size_t offset;
    unsigned int length;
};

struct rot {
    int rot_en;
    int ipu_rot_en;
    int rot_angle;
};

#define MAX_PATH	256
struct cmd_line {
    tFile *input;               /* Input file name */
    uint32_t input_mem_addr;    /*active if the input is stored in memory */
    tFile *output;              /* Output file name */
    uint32_t output_mem_addr;
    int src_scheme;
    int dst_scheme;
    int src_fd;
    int dst_fd;
    int width;
    int height;
    int enc_width;
    int enc_height;
    int loff;
    int toff;
    int format;
    int deblock_en;
    int dering_en;
    int rot_en;
    int ipu_rot_en;
    int rot_angle;
    int mirror;
    int chromaInterleave;
    int bitrate;
    int gop;
    int save_enc_hdr;
    int count;
    int prescan;
    int bs_mode;
    char *nbuf;                 /* network buffer */
    int nlen;                   /* remaining data in network buffer */
    int noffset;                /* offset into network buffer */
    int seq_no;                 /* seq numbering to detect skipped frames */
    uint16_t port;              /* udp port number */
    uint16_t complete;          /* wait for the requested buf to be filled completely */
    int iframe;
    int mp4_h264Class;
    char vdi_motion;            /* VDI motion algorithm */
    int fps;
    int mapType;
    int read_mode;
};

typedef struct {
    const char *name;
    int (*test) (void *arg);
} vpu_test_t;

struct decode {
    DecHandle handle;
    PhysicalAddress phy_bsbuf_addr;
    PhysicalAddress phy_ps_buf;
    PhysicalAddress phy_slice_buf;
    PhysicalAddress phy_vp8_mbparam_buf;
    int phy_slicebuf_size;
    int phy_vp8_mbparam_size;
    uint32_t virt_bsbuf_addr;
    int picwidth;
    int picheight;
    int stride;
    int mjpg_fmt;
    int regfbcount;
    int minfbcount;
    int rot_buf_count;
    int extrafb;
    FrameBuffer *fb;
    struct frame_buf **pfbpool;
    struct vpu_display *disp;
    vpu_mem_desc *mvcol_memdesc;
    Rect picCropRect;
    int reorderEnable;
    int tiled2LinearEnable;
    int totalFrameDecoded;
    DecReportInfo mbInfo;
    DecReportInfo mvInfo;
    DecReportInfo frameBufStat;
    DecReportInfo userData;

    struct cmd_line *cmdl;
};

struct encode {
    EncHandle handle;           /* Encoder handle */
    PhysicalAddress phy_bsbuf_addr; /* Physical bitstream buffer */
    uint32_t virt_bsbuf_addr;   /* Virtual bitstream buffer */
    int enc_picwidth;           /* Encoded Picture width */
    int enc_picheight;          /* Encoded Picture height */
    int src_picwidth;           /* Source Picture width */
    int src_picheight;          /* Source Picture height */
    int totalfb;                /* Total number of framebuffers allocated */
    int src_fbid;               /* Index of frame buffer that contains YUV image */
    FrameBuffer *fb;            /* frame buffer base given to encoder */
    struct frame_buf **pfbpool; /* allocated fb pointers are stored here */
    ExtBufCfg scratchBuf;
    int mp4_dataPartitionEnable;
    int ringBufferEnable;
    int mjpg_fmt;
    int mvc_paraset_refresh_en;
    int mvc_extension;
    int linear2TiledEnable;
    int minFrameBufferCount;

    EncReportInfo mbInfo;
    EncReportInfo mvInfo;
    EncReportInfo sliceInfo;

    struct cmd_line *cmdl;      /* command line */
    uint8_t *huffTable;
    uint8_t *qMatTable;
};

typedef struct {
    struct frame_buf *frames[MAX_FIFO_SIZE];
    uint32_t id[MAX_FIFO_SIZE];
    int wrptr;
    int rdptr;
    int size;
    int full;
    uint32_t popCnt;
} vdec_frame_buffer_t;

typedef struct {
    uint32_t bs_start;
    uint32_t bs_offset;
    uint32_t bs_end;
} bs_mem_t;

typedef struct {
    uint32_t timer_start;
    uint32_t timer_elapsed_ms;
} vpu_frame_timer_t;

extern uint32_t usdhc_busy;
extern tFile files[10];
extern tVolume *V;
extern struct decode *gDecInstance[];
extern struct encode *gEncInstance[];
extern vdec_frame_buffer_t gDecFifo[];
extern uint32_t gBsBuffer[];
extern int gCurrentActiveInstance;
extern int gTotalActiveInstance;
extern vpu_resource_t *vpu_hw_map;
extern struct hw_module hw_vpu;
extern struct hw_module hw_epit2;
extern int disp_clr_index[];
extern int multi_instance;
extern bs_mem_t bsmem;
extern int ipu_initialized[];

void framebuf_init(void);
int vpu_stream_read(struct cmd_line *cmd, char *buf, int n);
int vpu_stream_write(struct cmd_line *cmd, char *buf, int n);
void get_arg(char *buf, int *argc, char *argv[]);
int open_files(struct cmd_line *cmd);
void close_files(struct cmd_line *cmd);
int check_params(struct cmd_line *cmd, int op);
char *skip_unwanted(char *ptr);
int parse_options(char *buf, struct cmd_line *cmd, int *mode);
int card_xfer_result(int base_address, int *result);
struct frame_buf *framebuf_alloc(int stdMode, int format, int strideY, int height, int mvCol);
struct frame_buf *tiled_framebuf_alloc(int stdMode, int format, int strideY, int height, int mvCol,
                                       int mapType);
void framebuf_free(struct frame_buf *fb);
int encoder_open(struct encode *enc);
void encoder_close(struct encode *enc);
int encoder_configure(struct encode *enc);
int encoder_allocate_framebuffer(struct encode *enc);
void encoder_free_framebuffer(struct encode *enc);

int decoder_open(struct decode *dec);
void decoder_close(struct decode *dec);
int decoder_parse(struct decode *dec);
int decoder_allocate_framebuffer(struct decode *dec);
void decoder_free_framebuffer(struct decode *dec);
int video_data_cmp(unsigned char *src, unsigned char *dst, int size);
int decoder_setup(void *arg);
int encoder_setup(void *arg);
int ipu_refresh(int ipu_index, uint32_t buffer);
void config_system_parameters(void);
int fat_read_from_usdhc(uint32_t sd_addr, uint32_t sd_size, void *buffer, int fast_flag);
void init_fat32_device(void *blkreq_func);
int fat_search_files(char *ext, int num);
void dec_fifo_init(vdec_frame_buffer_t * fifo, int size);
int dec_fifo_push(vdec_frame_buffer_t * fifo, struct frame_buf **frame, uint32_t id);
int dec_fifo_pop(vdec_frame_buffer_t * fifo, struct frame_buf **frame, uint32_t * id);
int dec_fifo_is_empty(vdec_frame_buffer_t * fifo);
int dec_fifo_is_full(vdec_frame_buffer_t * fifo);
void epit2_config(void);
void epit_isr(void);
int get_timer_stamp(int periodic);
void decoder_frame_display(void);
int decode_test(void *arg);
int encode_test(void *arg);
int dec_fill_bsbuffer(DecHandle handle, struct cmd_line *cmd,
                      uint32_t bs_va_startaddr, uint32_t bs_va_endaddr,
                      uint32_t bs_pa_startaddr, int defaultsize);
extern int config_hdmi_si9022(int ipu_index, int ipu_di);
extern void hdmi_1080P60_video_output(int ipu_index, int ipu_di);
extern int ips_hdmi_1080P60_stream(int ipu_index);
extern void hdmi_720P60_video_output(int ipu_index, int ipu_di);
extern void enable_L1_cache(void);
extern int ips_hannstar_xga_yuv_stream(int ipu_index);
extern void ipu_dma_update_buffer(uint32_t ipu_index, uint32_t channel, uint32_t buffer_index,
                                  uint32_t buffer_addr);
extern void ipu_channel_buf_ready(int ipu_index, int channel, int buf);

static inline int is_mx6q_mjpg(int fmt)
{
    if (cpu_is_mx6q() && (fmt == STD_MJPG))
        return true;
    else
        return false;
}

#endif
