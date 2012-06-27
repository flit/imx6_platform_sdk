/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _VPU_TEST_H_
#define _VPU_TEST_H_
#include <filesystem/fsapi.h>
#include "hardware.h"
#include "vpu_lib.h"
#include "vpu_io.h"
#include "vpu_util.h"
#include "ipu/inc/ipu_common.h"
#include "vdoa/inc/vdoa.h"
#include "usdhc/inc/usdhc_ifc.h"

#define MAX_FIFO_SIZE 		32
#define NUM_FRAME_BUFS	64
#define FB_INDEX_MASK		(NUM_FRAME_BUFS - 1)

#if defined(BOARD_SMART_DEVICE)
#define SD_PORT_BASE_ADDR	USDHC3_BASE_ADDR
#else
#define SD_PORT_BASE_ADDR	USDHC3_BASE_ADDR
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

enum {
    MODE420 = 0,
    MODE422 = 1,
    MODE224 = 2,
    MODE444 = 3,
    MODE400 = 4
};

enum {
    VPLAY_FREE_RUN = 0,
    VPLAY_25FPS = 25,
    VPLAY_30FPS = 30,
};

struct frame_buf {
    int32_t addrY;
    int32_t addrCb;
    int32_t addrCr;
    int32_t strideY;
    int32_t strideC;
    int32_t mvColBuf;
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
    int32_t list[MAX_BUF_NUM + 1];
    int32_t head;
    int32_t tail;
};

struct ipu_buf {
    int32_t ipu_paddr;
    void *ipu_vaddr;
    int32_t field;
};

struct capture_testbuffer {
    size_t offset;
    uint32_t length;
};

struct rot {
    int32_t rot_en;
    int32_t ipu_rot_en;
    int32_t rot_angle;
};

#define MAX_PATH	256
struct cmd_line {
    int32_t input;              /* Input file name */
    uint32_t input_mem_addr;    /*active if the input is stored in memory */
    int32_t output;             /* Output file name */
    uint32_t output_mem_addr;
    int32_t src_scheme;
    int32_t dst_scheme;
    int32_t src_fd;
    int32_t dst_fd;
    int32_t width;
    int32_t height;
    int32_t enc_width;
    int32_t enc_height;
    int32_t loff;
    int32_t toff;
    int32_t format;
    int32_t deblock_en;
    int32_t dering_en;
    int32_t rot_en;
    int32_t ipu_rot_en;
    int32_t rot_angle;
    int32_t mirror;
    int32_t chromaInterleave;
    int32_t bitrate;
    int32_t gop;
    int32_t save_enc_hdr;
    int32_t count;
    int32_t prescan;
    int32_t bs_mode;
    char *nbuf;                 /* network buffer */
    int32_t nlen;                   /* remaining data in network buffer */
    int32_t noffset;                /* offset into network buffer */
    int32_t seq_no;                 /* seq numbering to detect skipped frames */
    uint16_t port;              /* udp port number */
    uint16_t complete;          /* wait for the requested buf to be filled completely */
    int32_t iframe;
    int32_t mp4_h264Class;
    char vdi_motion;            /* VDI motion algorithm */
    int32_t fps;
    int32_t mapType;
    int32_t read_mode;
};

typedef struct {
    const char *name;
    int32_t (*test) (void *arg);
} vpu_test_t;

struct decode {
    DecHandle handle;
    PhysicalAddress phy_bsbuf_addr;
    PhysicalAddress phy_ps_buf;
    PhysicalAddress phy_slice_buf;
    PhysicalAddress phy_vp8_mbparam_buf;
    int32_t phy_slicebuf_size;
    int32_t phy_vp8_mbparam_size;
    uint32_t virt_bsbuf_addr;
    int32_t picwidth;
    int32_t picheight;
    int32_t stride;
    int32_t mjpg_fmt;
    int32_t regfbcount;
    int32_t minfbcount;
    int32_t rot_buf_count;
    int32_t extrafb;
    FrameBuffer *fb;
    struct frame_buf **pfbpool;
    struct vpu_display *disp;
    vpu_mem_desc *mvcol_memdesc;
    Rect picCropRect;
    int32_t reorderEnable;
    int32_t tiled2LinearEnable;
    int32_t totalFrameDecoded;
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
    int32_t enc_picwidth;           /* Encoded Picture width */
    int32_t enc_picheight;          /* Encoded Picture height */
    int32_t src_picwidth;           /* Source Picture width */
    int32_t src_picheight;          /* Source Picture height */
    int32_t totalfb;                /* Total number of framebuffers allocated */
    int32_t src_fbid;               /* Index of frame buffer that contains YUV image */
    FrameBuffer *fb;            /* frame buffer base given to encoder */
    struct frame_buf **pfbpool; /* allocated fb pointers are stored here */
    ExtBufCfg scratchBuf;
    int32_t mp4_dataPartitionEnable;
    int32_t ringBufferEnable;
    int32_t mjpg_fmt;
    int32_t mvc_paraset_refresh_en;
    int32_t mvc_extension;
    int32_t linear2TiledEnable;
    int32_t minFrameBufferCount;

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
    int32_t wrptr;
    int32_t rdptr;
    int32_t size;
    int32_t full;
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
extern struct decode *gDecInstance[];
extern struct encode *gEncInstance[];
extern vdec_frame_buffer_t gDecFifo[];
extern uint32_t gBsBuffer[];
extern int32_t gCurrentActiveInstance;
extern int32_t gTotalActiveInstance;
extern vpu_resource_t *vpu_hw_map;
extern hw_module_t hw_vpu;
extern hw_module_t hw_epit2;
extern int32_t disp_clr_index[];
extern int32_t multi_instance;
extern bs_mem_t bsmem;
extern int32_t ipu_initialized[];

void framebuf_init(void);
int32_t vpu_stream_read(struct cmd_line *cmd, char *buf, int32_t n);
int32_t vpu_stream_write(struct cmd_line *cmd, char *buf, int32_t n);
void get_arg(char *buf, int32_t *argc, char *argv[]);
int32_t open_files(struct cmd_line *cmd);
void close_files(struct cmd_line *cmd);
int32_t check_params(struct cmd_line *cmd, int32_t op);
char *skip_unwanted(char *ptr);
int32_t parse_options(char *buf, struct cmd_line *cmd, int32_t *mode);
struct frame_buf *framebuf_alloc(int32_t stdMode, int32_t format, int32_t strideY, int32_t height, int32_t mvCol);
struct frame_buf *tiled_framebuf_alloc(int32_t stdMode, int32_t format, int32_t strideY, int32_t height, int32_t mvCol,
                                       int32_t mapType);
void framebuf_free(struct frame_buf *fb);
int32_t encoder_open(struct encode *enc);
void encoder_close(struct encode *enc);
int32_t encoder_configure(struct encode *enc);
int32_t encoder_allocate_framebuffer(struct encode *enc);
void encoder_free_framebuffer(struct encode *enc);

int32_t decoder_open(struct decode *dec);
void decoder_close(struct decode *dec);
int32_t decoder_parse(struct decode *dec);
int32_t decoder_allocate_framebuffer(struct decode *dec);
void decoder_free_framebuffer(struct decode *dec);
int32_t video_data_cmp(unsigned char *src, unsigned char *dst, int32_t size);
int32_t decoder_setup(void *arg);
int32_t encoder_setup(void *arg);
int32_t ipu_refresh(uint32_t ipu_index, uint32_t buffer);
void config_system_parameters(void);
void dec_fifo_init(vdec_frame_buffer_t * fifo, int32_t size);
int32_t dec_fifo_push(vdec_frame_buffer_t * fifo, struct frame_buf **frame, uint32_t id);
int32_t dec_fifo_pop(vdec_frame_buffer_t * fifo, struct frame_buf **frame, uint32_t * id);
int32_t dec_fifo_is_empty(vdec_frame_buffer_t * fifo);
int32_t dec_fifo_is_full(vdec_frame_buffer_t * fifo);
void decoder_frame_display(void);
int32_t decode_test(void *arg);
int32_t encode_test(void *arg);
int32_t dec_fill_bsbuffer(DecHandle handle, struct cmd_line *cmd,
                      uint32_t bs_va_startaddr, uint32_t bs_va_endaddr,
                      uint32_t bs_pa_startaddr, int32_t defaultsize);
extern int32_t config_hdmi_si9022(int32_t ipu_index, int32_t ipu_di);
extern void hdmi_1080P60_video_output(int32_t ipu_index, int32_t ipu_di);
extern int32_t ips_hdmi_1080P60_stream(int32_t ipu_index);
extern void hdmi_720P60_video_output(int32_t ipu_index, int32_t ipu_di);
extern void enable_L1_cache(void);
extern int32_t ips_hannstar_xga_yuv_stream(int32_t ipu_index);
extern void ipu_dma_update_buffer(uint32_t ipu_index, uint32_t channel, uint32_t buffer_index,
                                  uint32_t buffer_addr);
extern int32_t ipu_idmac_chan_cur_buff(uint32_t ipu_index, uint32_t channel);
extern void ipu_channel_buf_ready(int32_t ipu_index, int32_t channel, int32_t buf);

static inline int32_t is_mx6q_mjpg(int32_t fmt)
{
    if (cpu_is_mx6q() && (fmt == STD_MJPG))
        return true;
    else
        return false;
}

#endif
