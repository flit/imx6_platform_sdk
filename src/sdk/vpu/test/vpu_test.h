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
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef _DEC_H
#define _DEC_H

#include "vpu_lib.h"
#include "vpu_io.h"

#define STREAM_BUF_SIZE		0x200000
#define STREAM_FILL_SIZE	0x40000
#define STREAM_READ_SIZE	(512 * 8)
#define STREAM_END_SIZE		0
#define PS_SAVE_SIZE		0x080000
#define VP8_MB_SAVE_SIZE	0x080000
#define MPEG4_SCRATCH_SIZE	0x080000

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
    char input[MAX_PATH];       /* Input file name */
    char output[MAX_PATH];      /* Output file name */
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
};

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
    int fbcount;
    int minFrameBufferCount;
    int rot_buf_count;
    int extrafb;
    FrameBuffer *fb;
    struct frame_buf **pfbpool;
    struct vpu_display *disp;
    vpu_mem_desc *mvcol_memdesc;
    Rect picCropRect;
    int reorderEnable;
    int tiled2LinearEnable;

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
    int fbcount;                /* Total number of framebuffers allocated */
    int src_fbid;               /* Index of frame buffer that contains YUV image */
    FrameBuffer *fb;            /* frame buffer base given to encoder */
    struct frame_buf **pfbpool; /* allocated fb pointers are stored here */

    EncReportInfo mbInfo;
    EncReportInfo mvInfo;
    EncReportInfo sliceInfo;

    struct cmd_line *cmdl;      /* command line */
    uint8_t *huffTable;
    uint8_t *qMatTable;
};

void framebuf_init(void);
int fwriten(int fd, void *vptr, size_t n);
int freadn(int fd, void *vptr, size_t n);
int vpu_read(struct cmd_line *cmd, char *buf, int n);
int vpu_write(struct cmd_line *cmd, char *buf, int n);
void get_arg(char *buf, int *argc, char *argv[]);
int open_files(struct cmd_line *cmd);
void close_files(struct cmd_line *cmd);
int check_params(struct cmd_line *cmd, int op);
char *skip_unwanted(char *ptr);
int parse_options(char *buf, struct cmd_line *cmd, int *mode);

struct vpu_display *v4l_display_open(struct decode *dec, int nframes,
                                     struct rot rotation, Rect rotCrop);
struct frame_buf *framebuf_alloc(int stdMode, int format, int strideY, int height);
struct frame_buf *tiled_framebuf_alloc(int stdMode, int format, int strideY, int height);
void framebuf_free(struct frame_buf *fb);

struct vpu_display *ipu_display_open(struct decode *dec, int nframes, struct rot rotation,
                                     Rect cropRect);
void ipu_display_close(struct vpu_display *disp);
int ipu_put_data(struct vpu_display *disp, int index, int field, int fps);

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

void SaveQpReport(uint32_t * qpReportAddr, int picWidth, int picHeight, int frameIdx,
                  char *fileName);
int video_data_cmp(unsigned char *src, unsigned char *dst, int size);
#endif
