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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vpu_test.h"
#include "vpu_debug.h"
#include "vpu_lib.h"

extern int quitflag;
extern int golden_data[];

static FILE *fpFrmStatusLogfile = NULL;
static FILE *fpErrMapLogfile = NULL;
static FILE *fpQpLogfile = NULL;
static FILE *fpSliceBndLogfile = NULL;
static FILE *fpMvLogfile = NULL;
static FILE *fpUserDataLogfile = NULL;

static int isInterlacedMPEG4 = 0;

/* record the offset of bitstream */
int bsoffset = 0;
int rawoffset = 0;

#define FN_FRAME_BUFFER_STATUS "dec_frame_buf_status.log"
#define FN_ERR_MAP_DATA "dec_error_map.log"
#define FN_QP_DATA "dec_qp.log"
#define FN_SB_DATA "dec_slice_bnd.log"
#define FN_MV_DATA "dec_mv.log"
#define FN_USER_DATA "dec_user_data.log"

#define JPG_HEADER_SIZE	     0x200
#ifdef COMBINED_VIDEO_SUPPORT
#define MAX_FRAME_WIDTH 720
#define MAX_FRAME_HEIGHT 576
#endif

void SaveFrameBufStat(uint8_t * frmStatusBuf, int size, int DecNum)
{

    int i;

    if (fpFrmStatusLogfile == NULL) {
        fpFrmStatusLogfile = fopen(FN_FRAME_BUFFER_STATUS, "w+");
    }

    fprintf(fpFrmStatusLogfile, "FRAME [%1d]\n", DecNum);

    for (i = 0; i < size; i++) {
        fprintf(fpFrmStatusLogfile, "[%d] %d ", i * 2, ((frmStatusBuf[i] >> 4) & 0x0F));
        fprintf(fpFrmStatusLogfile, "[%d] %d ", (i * 2) + 1, (frmStatusBuf[i] & 0x0F));
    }
    fprintf(fpFrmStatusLogfile, "\n");
    fflush(fpFrmStatusLogfile);
}

void SaveMB_Para(uint8_t * mbParaBuf, int size, int DecNum)
{

    int i;

    if (DecNum == 1)
        DecNum = DecNum;

    if (fpErrMapLogfile == NULL)
        fpErrMapLogfile = fopen(FN_ERR_MAP_DATA, "w+");
    if (fpQpLogfile == NULL)
        fpQpLogfile = fopen(FN_QP_DATA, "w+");
    if (fpSliceBndLogfile == NULL)
        fpSliceBndLogfile = fopen(FN_SB_DATA, "w+");

    fprintf(fpQpLogfile, "FRAME [%1d]\n", DecNum);
    fprintf(fpSliceBndLogfile, "FRAME [%1d]\n", DecNum);
    fprintf(fpErrMapLogfile, "FRAME [%1d]\n", DecNum);

    for (i = 0; i < size; i++) {
        fprintf(fpQpLogfile, "MbAddr[%4d]: MbQs[%2d]\n", i, mbParaBuf[i] & 0x3F);
        fprintf(fpSliceBndLogfile, "MbAddr[%4d]: Slice Boundary Flag[%1d]\n", i,
                (mbParaBuf[i] >> 6) & 1);
        fprintf(fpErrMapLogfile, "MbAddr[%4d]: ErrMap[%1d]\n", i, (mbParaBuf[i] >> 7) & 1);
    }

    fflush(fpQpLogfile);
    fflush(fpSliceBndLogfile);
    fflush(fpErrMapLogfile);
}

void SaveMvPara(uint8_t * mvParaBuf, int size, int mvNumPerMb, int mbNumX, int DecNum)
{

    int i, j;
    short mvX, mvY;
    uint8_t *mvDatabuf;

    if (fpMvLogfile == 0) {
        fpMvLogfile = fopen(FN_MV_DATA, "w+");
    }

    fprintf(fpMvLogfile, "FRAME [%1d]\n", DecNum);

    for (i = 0; i < size; i++) {
        for (j = 0; j < mvNumPerMb; j++) {
            mvDatabuf = (mvParaBuf + (i * mvNumPerMb + j) * 4);
            mvX = (short)((mvDatabuf[0] << 8) | (mvDatabuf[1] << 0));
            mvY = (short)((mvDatabuf[2] << 8) | (mvDatabuf[3] << 0));

            if (!(mvX & 0x8000)) {
                /* Intra MB */
                mvX = 0;
                mvY = 0;

                if (j == 0)
                    fprintf(fpMvLogfile, "MbAddr[%4d:For ]: Avail[0] Mv[%5d:%5d]\n", i, mvX, mvY);
                if (j == 1)
                    fprintf(fpMvLogfile, "MbAddr[%4d:Back]: Avail[0] Mv[%5d:%5d]\n", i, mvX, mvY);

            } else {

                if (mvX & 0x2000) { /* Signed extension */
                    mvX = mvX | 0xC000;
                } else {
                    mvX = mvX & 0x1FFF;
                }

                if (mvY & 0x2000) {
                    mvY = mvY | 0xC000;
                } else {
                    mvY = mvY & 0x1FFF;
                }

                if (j == 0)
                    fprintf(fpMvLogfile, "MbAddr[%4d:For ]: Avail[1] Mv[%5d:%5d]\n", i, mvX, mvY);
                if (j == 1)
                    fprintf(fpMvLogfile, "MbAddr[%4d:Back]: Avail[1] Mv[%5d:%5d]\n", i, mvX, mvY);
            }
        }
    }
    fflush(fpMvLogfile);
}

void SaveUserData(uint8_t * userDataBuf)
{
    int i, UserDataType, UserDataSize, userDataNum, TotalSize;
    uint8_t *tmpBuf;

    if (fpUserDataLogfile == 0) {
        fpUserDataLogfile = fopen(FN_USER_DATA, "w+");
    }

    tmpBuf = userDataBuf;
    userDataNum = (short)((tmpBuf[0] << 8) | (tmpBuf[1] << 0));
    TotalSize = (short)((tmpBuf[2] << 8) | (tmpBuf[3] << 0));

    tmpBuf = userDataBuf + 8;

    for (i = 0; i < userDataNum; i++) {
        UserDataType = (short)((tmpBuf[0] << 8) | (tmpBuf[1] << 0));
        UserDataSize = (short)((tmpBuf[2] << 8) | (tmpBuf[3] << 0));
        fprintf(fpUserDataLogfile, "\n[Idx Type Size] : [%4d %4d %4d]", i, UserDataType,
                UserDataSize);

        tmpBuf += 8;
    }
    fprintf(fpUserDataLogfile, "\n");

    tmpBuf = userDataBuf + USER_DATA_INFO_OFFSET;
    for (i = 0; i < TotalSize; i++) {
        fprintf(fpUserDataLogfile, "%02x", tmpBuf[i]);
        if ((i & 7) == 7)
            fprintf(fpUserDataLogfile, "\n");
    }
    fprintf(fpUserDataLogfile, "\n");
    fflush(fpUserDataLogfile);

}

/*
 * Fill the bitstream to vpu ring buffer
 */
int dec_fill_bsbuffer(DecHandle handle, struct cmd_line *cmd,
                      uint32_t bs_va_startaddr, uint32_t bs_va_endaddr,
                      uint32_t bs_pa_startaddr, int defaultsize, int *eos, int *fill_end_bs)
{
    RetCode ret;
    PhysicalAddress pa_read_ptr, pa_write_ptr;
    uint32_t target_addr, space;
    int size;
    int nread, room;
    *eos = 0;

    ret = vpu_DecGetBitstreamBuffer(handle, &pa_read_ptr, &pa_write_ptr, &space);
    if (ret != RETCODE_SUCCESS) {
        err_msg("vpu_DecGetBitstreamBuffer failed\n");
        return -1;
    }

    /* Decoder bitstream buffer is empty */
    if (space <= 0)
        return 0;

    if (defaultsize > 0) {
        if (space < defaultsize)
            return 0;

        size = defaultsize;
    } else {
        size = ((space >> 9) << 9);
    }

    if (size == 0)
        return 0;

    /* Fill the bitstream buffer */
    target_addr = bs_va_startaddr + (pa_write_ptr - bs_pa_startaddr);
    if ((target_addr + size) > bs_va_endaddr) {
        room = bs_va_endaddr - target_addr;
        nread = vpu_read(cmd, (void *)target_addr, room);
        if (nread <= 0) {
            /* EOF or error */
            if (nread < 0) {
                return -1;
            }

            *eos = 1;
        } else {
            /* unable to fill the requested size, so back off! */
            if (nread != room)
                goto update;

            /* read the remaining */
            space = nread;
            nread = vpu_read(cmd, (void *)bs_va_startaddr, (size - room));
            if (nread <= 0) {
                /* EOF or error */
                if (nread < 0) {
                    return -1;
                }

                *eos = 1;
            }

            nread += space;
        }
    } else {
        nread = vpu_read(cmd, (void *)target_addr, size);
        if (nread <= 0) {
            /* EOF or error */
            if (nread < 0) {
                return -1;
            }

            *eos = 1;
        }
    }

  update:
    if (*eos == 0) {
        ret = vpu_DecUpdateBitstreamBuffer(handle, nread);
        if (ret != RETCODE_SUCCESS) {
            err_msg("vpu_DecUpdateBitstreamBuffer failed\n");
            return -1;
        }
        *fill_end_bs = 0;
    } else {
        if (!*fill_end_bs) {
            ret = vpu_DecUpdateBitstreamBuffer(handle, STREAM_END_SIZE);
            if (ret != RETCODE_SUCCESS) {
                err_msg("vpu_DecUpdateBitstreamBuffer failed" "\n");
                return -1;
            }
            *fill_end_bs = 1;
        }

    }

    return nread;
}

/*
 * This function is to convert framebuffer from interleaved Cb/Cr mode
 * to non-interleaved Cb/Cr mode.
 *
 * Note: This function does _NOT_ really store this framebuffer into file.
 */
static void saveNV12ImageHelper(uint8_t * pYuv, struct decode *dec, uint8_t * buf)
{
    int Y, Cb;
    uint8_t *Y1, *Cb1, *Cr1;
    int img_size;
    int y, x;
    uint8_t *tmp;
    int height = dec->picheight;
    int stride = dec->stride;

    if (!pYuv || !buf) {
        err_msg("pYuv or buf should not be NULL.\n");
        return;
    }

    img_size = stride * height;

    Y = (int)buf;
    Cb = Y + img_size;

    Y1 = pYuv;
    Cb1 = Y1 + img_size;
    Cr1 = Cb1 + (img_size >> 2);

    memcpy(Y1, (uint8_t *) Y, img_size);

    for (y = 0; y < (dec->picheight / 2); y++) {
        tmp = (uint8_t *) (Cb + dec->picwidth * y);
        for (x = 0; x < dec->picwidth; x += 2) {
            *Cb1++ = tmp[x];
            *Cr1++ = tmp[x + 1];
        }
    }
}

int decoder_start(struct decode *dec)
{
    DecHandle handle = dec->handle;
    DecOutputInfo outinfo = { 0 };
    DecParam decparam = { 0 };
    int rot_en = dec->cmdl->rot_en, rot_stride, fwidth, fheight;
    int rot_angle = dec->cmdl->rot_angle;
    int deblock_en = dec->cmdl->deblock_en;
    int dering_en = dec->cmdl->dering_en;
    FrameBuffer *deblock_fb = NULL;
    FrameBuffer *fb = dec->fb;
    struct frame_buf **pfbpool = dec->pfbpool;
    struct frame_buf *pfb = NULL;
    int err, eos = 0, fill_end_bs = 0, decodefinish = 0;
    RetCode ret;
    int loop_id;
    uint32_t yuv_addr, img_size;
    double frame_id = 0;
    int decIndex = 0;
    int rotid = 0, dblkid = 0, mirror;
    int count = dec->cmdl->count;
    int totalNumofErrMbs = 0;
    int disp_clr_index = -1, actual_display_index = -1, field = 0;
    int is_waited_int = 0;
    int tiled2LinearEnable = dec->tiled2LinearEnable;

    /* deblock_en is zero on mx37 and mx51 since it is cleared in decode_open() function. */
    if (rot_en || dering_en) {
        rotid = dec->fbcount;
        if (deblock_en) {
            dblkid = dec->fbcount + dec->rot_buf_count;
        }
    } else if (deblock_en) {
        dblkid = dec->fbcount;
    }
    if (dec->cmdl->format == STD_MJPG)
        rotid = 0;

    decparam.dispReorderBuf = 0;

    decparam.prescanEnable = dec->cmdl->prescan;
    decparam.prescanMode = 0;

    decparam.skipframeMode = 0;
    decparam.skipframeNum = 0;
    /*
     * once iframeSearchEnable is enabled, prescanEnable, prescanMode
     * and skipframeMode options are ignored.
     */
    decparam.iframeSearchEnable = 0;

    fwidth = ((dec->picwidth + 15) & ~15);
    fheight = ((dec->picheight + 15) & ~15);

    if (rot_en || dering_en || tiled2LinearEnable || (dec->cmdl->format == STD_MJPG)) {
        /*
         * VPU is setting the rotation angle by counter-clockwise.
         * We convert it to clockwise, which is consistent with V4L2
         * rotation angle strategy.
         */
        if (rot_en) {
            if (rot_angle == 90 || rot_angle == 270)
                rot_angle = 360 - rot_angle;
        } else
            rot_angle = 0;
        vpu_DecGiveCommand(handle, SET_ROTATION_ANGLE, &rot_angle);

        mirror = dec->cmdl->mirror;
        vpu_DecGiveCommand(handle, SET_MIRROR_DIRECTION, &mirror);

        if (rot_en || dering_en) {
            rot_stride = (rot_angle == 90 || rot_angle == 270) ? fheight : fwidth;
        } else
            rot_stride = fwidth;
        vpu_DecGiveCommand(handle, SET_ROTATOR_STRIDE, &rot_stride);
    }

    if (deblock_en) {
        deblock_fb = &fb[dblkid];
    }

    if (dec->cmdl->dst_scheme == PATH_IPU) {
        img_size = dec->stride * dec->picheight;
    } else {
        img_size = dec->picwidth * dec->picheight * 3 / 2;
        if (deblock_en) {
            pfb = pfbpool[dblkid];
            deblock_fb->bufY = pfb->addrY;
            deblock_fb->bufCb = pfb->addrCb;
            deblock_fb->bufCr = pfb->addrCr;
        }
    }

    while (1) {

        if (rot_en || dering_en || tiled2LinearEnable || (dec->cmdl->format == STD_MJPG)) {
            vpu_DecGiveCommand(handle, SET_ROTATOR_OUTPUT, (void *)&fb[rotid]);
            if (frame_id == 0) {
                if (rot_en) {
                    vpu_DecGiveCommand(handle, ENABLE_ROTATION, 0);
                    vpu_DecGiveCommand(handle, ENABLE_MIRRORING, 0);
                }
                if (dering_en) {
                    vpu_DecGiveCommand(handle, ENABLE_DERING, 0);
                }
            }
        }

        if (deblock_en) {
            ret = vpu_DecGiveCommand(handle, DEC_SET_DEBLOCK_OUTPUT, (void *)deblock_fb);
            if (ret != RETCODE_SUCCESS) {
                err_msg("Failed to set deblocking output\n");
                return -1;
            }
        }

        if (dec->mbInfo.enable == 1) {
            ret = vpu_DecGiveCommand(handle, DEC_SET_REPORT_MBINFO, &dec->mbInfo);
            if (ret != RETCODE_SUCCESS) {
                err_msg("Failed to set MbInfo report, ret %d\n", ret);
                return -1;
            }
        }
        if (dec->mvInfo.enable == 1) {
            ret = vpu_DecGiveCommand(handle, DEC_SET_REPORT_MVINFO, &dec->mvInfo);
            if (ret != RETCODE_SUCCESS) {
                err_msg("Failed to set MvInfo report, ret %d\n", ret);
                return -1;
            }
        }
        if (dec->frameBufStat.enable == 1) {
            ret = vpu_DecGiveCommand(handle, DEC_SET_REPORT_BUFSTAT, &dec->frameBufStat);
            if (ret != RETCODE_SUCCESS) {
                err_msg("Failed to set frame status report, ret %d\n", ret);
                return -1;
            }
        }
        if (dec->userData.enable == 1) {
            ret = vpu_DecGiveCommand(handle, DEC_SET_REPORT_USERDATA, &dec->userData);
            if (ret != RETCODE_SUCCESS) {
                err_msg("Failed to set user data report, ret %d\n", ret);
                return -1;
            }
        }

        ret = vpu_DecStartOneFrame(handle, &decparam);
        if (ret != RETCODE_SUCCESS) {
            err_msg("DecStartOneFrame failed\n");
            return -1;
        }

        is_waited_int = 0;
        loop_id = 0;
        while (vpu_IsBusy()) {
            err = dec_fill_bsbuffer(handle, dec->cmdl,
                                    dec->virt_bsbuf_addr,
                                    (dec->virt_bsbuf_addr + STREAM_BUF_SIZE),
                                    dec->phy_bsbuf_addr, STREAM_FILL_SIZE, &eos, &fill_end_bs);

            if (err < 0) {
                err_msg("dec_fill_bsbuffer failed\n");
                return -1;
            }

            /*
             * Suppose vpu is hang if one frame cannot be decoded in 5s,
             * then do vpu software reset.
             * Please take care of this for network case since vpu
             * interrupt also cannot be received if no enough data.
             */
            if (loop_id == 10) {
                err = vpu_SWReset(handle, 0);
                return -1;
            }

            if (!err) {
                vpu_WaitForInt(500);
                is_waited_int = 1;
                loop_id++;
            }
        }

        if (!is_waited_int)
            vpu_WaitForInt(500);

        ret = vpu_DecGetOutputInfo(handle, &outinfo);

        if ((dec->cmdl->format == STD_MJPG) && (outinfo.indexFrameDisplay == 0)) {
            outinfo.indexFrameDisplay = rotid;
        }

        info_msg("frame_id = %d\n", (int)frame_id);
        if (ret != RETCODE_SUCCESS) {
            err_msg("vpu_DecGetOutputInfo failed Err code is %d\n"
                    "\tframe_id = %d\n", ret, (int)frame_id);
            return -1;
        }

        if (outinfo.decodingSuccess == 0) {
            warn_msg("Incomplete finish of decoding process.\n" "\tframe_id = %d\n", (int)frame_id);
            if (quitflag)
                break;
            else
                continue;
        }

        if (cpu_is_mx6q() && (outinfo.decodingSuccess & 0x10)) {
            warn_msg("vpu needs more bitstream in rollback mode\n"
                     "\tframe_id = %d\n", (int)frame_id);
            if (quitflag)
                break;
            else
                continue;
        }

        if (outinfo.notSufficientPsBuffer) {
            err_msg("PS Buffer overflow\n");
            return -1;
        }

        if (outinfo.notSufficientSliceBuffer) {
            err_msg("Slice Buffer overflow\n");
            return -1;
        }

        /* Frame Buffer Status */
        if (outinfo.indexFrameDecoded >= 0 &&
            outinfo.frameBufStat.enable && outinfo.frameBufStat.size) {
            SaveFrameBufStat(outinfo.frameBufStat.addr, outinfo.frameBufStat.size, decIndex);
        }

        /* Mb Param */
        if (outinfo.indexFrameDecoded >= 0 && outinfo.mbInfo.enable && outinfo.mbInfo.size) {
            /* skip picture */
            if (!(dec->cmdl->format == STD_VC1 && (outinfo.picType >> 3 == 4)))
                SaveMB_Para(outinfo.mbInfo.addr, outinfo.mbInfo.size, decIndex);
        }

        /* Motion Vector */
        if (outinfo.indexFrameDecoded >= 0 && outinfo.mvInfo.enable && outinfo.mvInfo.size) {
            int mbNumX = dec->picwidth / 16;
            SaveMvPara(outinfo.mvInfo.addr, outinfo.mvInfo.size,
                       outinfo.mvInfo.mvNumPerMb, mbNumX, decIndex);
        }

        /* User Data */
        if (outinfo.indexFrameDecoded >= 0 && outinfo.userData.enable && outinfo.userData.size) {
            if (outinfo.userData.userDataBufFull)
                warn_msg("User Data Buffer is Full\n");
            SaveUserData(dec->userData.addr);
        }

        if (outinfo.indexFrameDecoded >= 0) {
            if (dec->cmdl->format == STD_VC1) {
                if (outinfo.pictureStructure == 2)
                    info_msg("dec_idx %d : FRAME_INTERLACE\n", decIndex);
                else if (outinfo.pictureStructure == 3) {
                    if (outinfo.topFieldFirst)
                        field = 0;
                    else
                        field = 1;
                }
                if (outinfo.vc1_repeatFrame)
                    info_msg("dec_idx %d : VC1 RPTFRM [%1d]\n", decIndex, outinfo.vc1_repeatFrame);
            } else if ((dec->cmdl->format == STD_AVC) || (dec->cmdl->format == STD_MPEG4)) {
                if ((outinfo.interlacedFrame) ||
                    ((dec->cmdl->format == STD_MPEG4) && isInterlacedMPEG4)) {
                    if (outinfo.topFieldFirst)
                        field = 2;
                    else
                        field = 3;
                    dprintf(3, "Top Field First flag: %d, dec_idx %d\n",
                            outinfo.topFieldFirst, decIndex);
                }
            } else if ((dec->cmdl->format != STD_MPEG4) &&
                       (dec->cmdl->format != STD_H263) && (dec->cmdl->format != STD_RV)) {
                if (outinfo.interlacedFrame) {
                    if (outinfo.pictureStructure == 1)
                        field = 0;
                    else if (outinfo.pictureStructure == 2)
                        field = 1;
                    else if (outinfo.pictureStructure == 3) {
                        if (outinfo.topFieldFirst)
                            field = 2;  //top-bottom
                        else
                            field = 3;  //bottom-top
                    }
                }
                if (outinfo.repeatFirstField)
                    info_msg("frame_idx %d : Repeat First Field\n", decIndex);
            }
        }

        if (outinfo.indexFrameDecoded >= 0)
            decIndex++;

        if (outinfo.indexFrameDisplay == -1)
            decodefinish = 1;
        else if ((outinfo.indexFrameDisplay > dec->fbcount) &&
                 (outinfo.prescanresult != 0) && !cpu_is_mx6q())
            decodefinish = 1;

        if (decodefinish)
            break;

        if ((outinfo.prescanresult == 0) && (decparam.prescanEnable == 1)) {
            if (eos) {
                break;
            } else {
                int fillsize = 0;

                if (dec->cmdl->src_scheme == PATH_NET)
                    fillsize = 1000;
                else
                    warn_msg("Prescan: not enough bs data" "\n");

                dec->cmdl->complete = 1;
                err = dec_fill_bsbuffer(handle,
                                        dec->cmdl,
                                        dec->virt_bsbuf_addr,
                                        (dec->virt_bsbuf_addr +
                                         STREAM_BUF_SIZE),
                                        dec->phy_bsbuf_addr, fillsize, &eos, &fill_end_bs);
                dec->cmdl->complete = 0;
                if (err < 0) {
                    err_msg("dec_fill_bsbuffer failed\n");
                    return -1;
                }

                if (eos)
                    break;
                else
                    continue;
            }
        }

        if (quitflag)
            break;

        /* BIT don't have picture to be displayed */
        if ((outinfo.indexFrameDisplay == -3) || (outinfo.indexFrameDisplay == -2)) {
            dprintf(3, "VPU doesn't have picture to be displayed.\n"
                    "\toutinfo.indexFrameDisplay = %d\n", outinfo.indexFrameDisplay);

            if (dec->cmdl->dst_scheme != PATH_IPU) {
                if (dec->cmdl->format != STD_MJPG && disp_clr_index >= 0) {
                    err = vpu_DecClrDispFlag(handle, disp_clr_index);
                    if (err)
                        err_msg("vpu_DecClrDispFlag failed Error code" " %d\n", err);
                }
                disp_clr_index = outinfo.indexFrameDisplay;
            }
            continue;
        }

        if (rot_en || dering_en || (dec->cmdl->format == STD_MJPG))
            actual_display_index = rotid;
        else
            actual_display_index = outinfo.indexFrameDisplay;

        /*compare the output with golden data */
        if (golden_data != NULL) {
            int size = 0;
            pfb = pfbpool[actual_display_index];

            yuv_addr = pfb->addrY + pfb->desc.virt_uaddr - pfb->desc.phy_addr;
            size = fwidth * fheight * 3 / 2;
            info_msg("VPU output addr is 0x%08x, size is %d * %d\n", yuv_addr, fwidth, fheight);
            ret =
                video_data_cmp((unsigned char *)yuv_addr, (unsigned char *)&golden_data[rawoffset],
                               size);
            if (ret != 0) {
                err_msg("VPU decoder output does not match the golden data!!\n");
            }
            rawoffset += size;

            if (dec->cmdl->format != STD_MJPG && disp_clr_index >= 0) {
                err = vpu_DecClrDispFlag(handle, disp_clr_index);
                if (err)
                    err_msg("vpu_DecClrDispFlag failed Error code" " %d\n", err);
            }
            disp_clr_index = outinfo.indexFrameDisplay;
        }

        if (outinfo.numOfErrMBs) {
            totalNumofErrMbs += outinfo.numOfErrMBs;
            info_msg("Num of Error Mbs : %d, in Frame : %d \n", outinfo.numOfErrMBs, (int)frame_id);
        }

        frame_id++;
        if ((count != 0) && (frame_id >= count))
            break;

        if (dec->cmdl->src_scheme == PATH_NET) {
            err = dec_fill_bsbuffer(handle, dec->cmdl,
                                    dec->virt_bsbuf_addr,
                                    (dec->virt_bsbuf_addr + STREAM_BUF_SIZE),
                                    dec->phy_bsbuf_addr, STREAM_FILL_SIZE, &eos, &fill_end_bs);
            if (err < 0) {
                err_msg("dec_fill_bsbuffer failed\n");
                return -1;
            }
        }
    }

    if (totalNumofErrMbs) {
        info_msg("Total Num of Error MBs : %d\n", totalNumofErrMbs);
    }

    return 0;
}

void decoder_free_framebuffer(struct decode *dec)
{
    int i, totalfb;
//    vpu_mem_desc *mvcol_md = dec->mvcol_memdesc;
//    int deblock_en = dec->cmdl->deblock_en;

    totalfb = dec->fbcount + dec->extrafb;

    /* deblock_en is zero on mx37 and mx51 since it is cleared in decode_open() function. */
    if (dec->cmdl->dst_scheme != PATH_IPU) {
        for (i = 0; i < totalfb; i++) {
            framebuf_free(dec->pfbpool[i]);
        }
    }

    if (fpFrmStatusLogfile) {
        fclose(fpFrmStatusLogfile);
        fpFrmStatusLogfile = NULL;
    }
    if (fpErrMapLogfile) {
        fclose(fpErrMapLogfile);
        fpErrMapLogfile = NULL;
    }
    if (fpQpLogfile) {
        fclose(fpQpLogfile);
        fpQpLogfile = NULL;
    }
    if (fpSliceBndLogfile) {
        fclose(fpSliceBndLogfile);
        fpSliceBndLogfile = NULL;
    }
    if (fpMvLogfile) {
        fclose(fpMvLogfile);
        fpMvLogfile = NULL;
    }
    if (fpUserDataLogfile) {
        fclose(fpUserDataLogfile);
        fpUserDataLogfile = NULL;
    }

    if (dec->fb) {
        free(dec->fb);
        dec->fb = NULL;
    }
    if (dec->pfbpool) {
        free(dec->pfbpool);
        dec->pfbpool = NULL;
    }

    if (dec->frameBufStat.addr) {
        free(dec->frameBufStat.addr);
    }

    if (dec->mbInfo.addr) {
        free(dec->mbInfo.addr);
    }

    if (dec->mvInfo.addr) {
        free(dec->mvInfo.addr);
    }

    if (dec->userData.addr) {
        free(dec->userData.addr);
    }

    return;
}

int decoder_allocate_framebuffer(struct decode *dec)
{
    DecBufInfo bufinfo;
    int i, fbcount = dec->fbcount, totalfb;
    int dst_scheme = dec->cmdl->dst_scheme, rot_en = dec->cmdl->rot_en;
    int deblock_en = dec->cmdl->deblock_en;
    int dering_en = dec->cmdl->dering_en;
    RetCode ret;
    DecHandle handle = dec->handle;
    FrameBuffer *fb;
    struct frame_buf **pfbpool;
    int stride;

    if (rot_en || dering_en) {
        /*
         * At least 1 extra fb for rotation(or dering) is needed, two extrafb
         * are allocated for rotation if path is V4L,then we can delay 1 frame
         * de-queue from v4l queue to improve performance.
         */
        dec->rot_buf_count = (dec->cmdl->dst_scheme == PATH_IPU) ? 2 : 1;
        dec->extrafb += dec->rot_buf_count;
    }

    /*
     * 1 extra fb for deblocking on MX32, no need extrafb for blocking on MX37 and MX51
     * dec->cmdl->deblock_en has been cleared to zero after set it to oparam.mp4DeblkEnable
     * in decoder_open() function on MX37 and MX51.
     */
    if (deblock_en) {
        dec->extrafb++;
    }

    totalfb = fbcount + dec->extrafb;

    fb = dec->fb = calloc(totalfb, sizeof(FrameBuffer));
    if (fb == NULL) {
        err_msg("Failed to allocate fb\n");
        return -1;
    }

    pfbpool = dec->pfbpool = calloc(totalfb, sizeof(struct frame_buf *));
    if (pfbpool == NULL) {
        err_msg("Failed to allocate pfbpool\n");
        free(dec->fb);
        dec->fb = NULL;
        return -1;
    }

    if ((dst_scheme != PATH_IPU) || ((dst_scheme == PATH_IPU) && deblock_en)) {

        for (i = 0; i < totalfb; i++) {
            /*
             * Tiled framebuffer allocation is needed for decoding
             * buffers for none linear frame map type on mx6q platform.
             */
            if (cpu_is_mx6q() && (i < fbcount) && (dec->cmdl->mapType != LINEAR_FRAME_MAP))
                pfbpool[i] = tiled_framebuf_alloc(dec->cmdl->format, dec->mjpg_fmt,
                                                  dec->stride, dec->picheight);
            else
                pfbpool[i] = framebuf_alloc(dec->cmdl->format, dec->mjpg_fmt,
                                            dec->stride, dec->picheight);
            if (pfbpool[i] == NULL) {
                totalfb = i;
                goto err;
            }

            fb[i].bufY = pfbpool[i]->addrY;
            fb[i].bufCb = pfbpool[i]->addrCb;
            fb[i].bufCr = pfbpool[i]->addrCr;
            fb[i].bufMvCol = pfbpool[i]->mvColBuf;
        }
    }

    stride = ((dec->stride + 15) & ~15);
    if (dec->cmdl->format == STD_AVC) {
        bufinfo.avcSliceBufInfo.bufferBase = dec->phy_slice_buf;
        bufinfo.avcSliceBufInfo.bufferSize = dec->phy_slicebuf_size;
    } else if (dec->cmdl->format == STD_VP8) {
        bufinfo.vp8MbDataBufInfo.bufferBase = dec->phy_vp8_mbparam_buf;
        bufinfo.vp8MbDataBufInfo.bufferSize = dec->phy_vp8_mbparam_size;
    }

    /* User needs to fill max suported macro block value of frame as following */
    bufinfo.maxDecFrmInfo.maxMbX = dec->stride / 16;
    bufinfo.maxDecFrmInfo.maxMbY = dec->picheight / 16;
    bufinfo.maxDecFrmInfo.maxMbNum = dec->stride * dec->picheight / 256;
    ret = vpu_DecRegisterFrameBuffer(handle, fb, fbcount, stride, &bufinfo);
    if (ret != RETCODE_SUCCESS) {
        err_msg("Register frame buffer failed, ret=%d\n", ret);
        goto err;
    }

    return 0;

  err:
    if (dst_scheme != PATH_IPU) {
        for (i = 0; i < totalfb; i++) {
            framebuf_free(pfbpool[i]);
        }
    }

    if (fpFrmStatusLogfile) {
        fclose(fpFrmStatusLogfile);
        fpFrmStatusLogfile = NULL;
    }
    if (fpErrMapLogfile) {
        fclose(fpErrMapLogfile);
        fpErrMapLogfile = NULL;
    }
    if (fpQpLogfile) {
        fclose(fpQpLogfile);
        fpQpLogfile = NULL;
    }
    if (fpSliceBndLogfile) {
        fclose(fpSliceBndLogfile);
        fpSliceBndLogfile = NULL;
    }
    if (fpMvLogfile) {
        fclose(fpMvLogfile);
        fpMvLogfile = NULL;
    }
    if (fpUserDataLogfile) {
        fclose(fpUserDataLogfile);
        fpUserDataLogfile = NULL;
    }

    free(dec->fb);
    free(dec->pfbpool);
    dec->fb = NULL;
    dec->pfbpool = NULL;
    return -1;
}

int decoder_parse(struct decode *dec)
{
    DecInitialInfo initinfo = { 0 };
    DecHandle handle = dec->handle;
    int align, profile, level, extended_fbcount;
    RetCode ret;
    char *count;

    /*
     * If userData report is enabled, buffer and comamnd need to be set
     * before DecGetInitialInfo for MJPG.
     */
    if (dec->userData.enable) {
        dec->userData.size = SIZE_USER_BUF;
        dec->userData.addr = malloc(SIZE_USER_BUF);
        if (!dec->userData.addr)
            err_msg("malloc_error\n");
    }

    if (dec->cmdl->format == STD_MJPG) {
        ret = vpu_DecGiveCommand(handle, DEC_SET_REPORT_USERDATA, &dec->userData);
        if (ret != RETCODE_SUCCESS) {
            err_msg("Failed to set user data report, ret %d\n", ret);
            return -1;
        }
    }

    /* Parse bitstream and get width/height/framerate etc */
    vpu_DecSetEscSeqInit(handle, 1);
    ret = vpu_DecGetInitialInfo(handle, &initinfo);
    vpu_DecSetEscSeqInit(handle, 0);
    if (ret != RETCODE_SUCCESS) {
        err_msg("vpu_DecGetInitialInfo failed, ret:%d, errorcode:%d\n", ret, initinfo.errorcode);
        return -1;
    }

    if (initinfo.streamInfoObtained) {
        switch (dec->cmdl->format) {
        case STD_AVC:
            info_msg("H.264 Profile: %d Level: %d Interlace: %d\n",
                     initinfo.profile, initinfo.level, initinfo.interlace);

            if (initinfo.aspectRateInfo) {
                int aspect_ratio_idc;
                int sar_width, sar_height;

                if ((initinfo.aspectRateInfo >> 16) == 0) {
                    aspect_ratio_idc = (initinfo.aspectRateInfo & 0xFF);
                    info_msg("aspect_ratio_idc: %d\n", aspect_ratio_idc);
                } else {
                    sar_width = (initinfo.aspectRateInfo >> 16);
                    sar_height = (initinfo.aspectRateInfo & 0xFFFF);
                    info_msg("sar_width: %d\nsar_height: %d", sar_width, sar_height);
                }
            } else {
                info_msg("Aspect Ratio is not present.\n");
            }

            break;
        case STD_VC1:
            if (initinfo.profile == 0)
                info_msg("VC1 Profile: Simple\n");
            else if (initinfo.profile == 1)
                info_msg("VC1 Profile: Main\n");
            else if (initinfo.profile == 2)
                info_msg("VC1 Profile: Advanced\n");

            info_msg("Level: %d Interlace: %d Progressive Segmented Frame: %d\n",
                     initinfo.level, initinfo.interlace, initinfo.vc1_psf);

            if (initinfo.aspectRateInfo)
                info_msg("Aspect Ratio [X, Y]:[%3d, %3d]\n",
                         (initinfo.aspectRateInfo >> 8) & 0xff, (initinfo.aspectRateInfo) & 0xff);
            else
                info_msg("Aspect Ratio is not present.\n");

            break;
        case STD_MPEG2:
            info_msg("Mpeg2 Profile: %d Level: %d Progressive Sequence Flag: %d\n",
                     initinfo.profile, initinfo.level, initinfo.interlace);
            /*
             * Profile: 3'b101: Simple, 3'b100: Main, 3'b011: SNR Scalable,
             * 3'b10: Spatially Scalable, 3'b001: High
             * Level: 4'b1010: Low, 4'b1000: Main, 4'b0110: High 1440, 4'b0100: High
             */
            if (initinfo.aspectRateInfo)
                info_msg("Aspect Ratio Table index: %d\n", initinfo.aspectRateInfo);
            else
                info_msg("Aspect Ratio is not present.\n");
            break;

        case STD_MPEG4:
            if (initinfo.level & 0x80) {    /* VOS Header */
                initinfo.level &= 0x7F;
                if (initinfo.level == 8 && initinfo.profile == 0) {
                    level = 0;
                    profile = 0;    /* Simple, Level_L0 */
                } else {
                    switch (initinfo.profile) {
                    case 0xB:
                        profile = 1;    /* advanced coding efficiency object */
                        break;
                    case 0xF:
                        if ((initinfo.level & 8) == 0)
                            profile = 2;    /* advanced simple object */
                        else
                            profile = 5;    /* reserved */
                        break;
                    case 0x0:
                        profile = 0;
                        break;  /* Simple Profile */
                    default:
                        profile = 5;
                        break;
                    }
                    level = initinfo.level;
                }
            } else {            /* VOL Header only */
                level = 7;      /* reserved */
                switch (initinfo.profile) {
                case 0x1:
                    profile = 0;    /* simple object */
                    break;
                case 0xC:
                    profile = 1;    /* advanced coding efficiency object */
                    break;
                case 0x11:
                    profile = 2;    /* advanced simple object */
                    break;
                default:
                    profile = 5;    /* reserved */
                    break;
                }
            }
            isInterlacedMPEG4 = initinfo.interlace;

            info_msg("Mpeg4 Profile: %d Level: %d Interlaced: %d\n",
                     profile, level, initinfo.interlace);
            /*
             * Profile: 8'b00000000: SP, 8'b00010001: ASP
             * Level: 4'b0000: L0, 4'b0001: L1, 4'b0010: L2, 4'b0011: L3, ...
             * SP: 1/2/3/4a/5/6, ASP: 0/1/2/3/4/5
             */
            if (initinfo.aspectRateInfo)
                info_msg("Aspect Ratio Table index: %d\n", initinfo.aspectRateInfo);
            else
                info_msg("Aspect Ratio is not present.\n");

            break;

        case STD_RV:
            info_msg("RV Profile: %d Level: %d\n", initinfo.profile, initinfo.level);
            break;

        case STD_H263:
            info_msg("H263 Profile: %d Level: %d\n", initinfo.profile, initinfo.level);
            break;

        case STD_DIV3:
            info_msg("DIV3 Profile: %d Level: %d\n", initinfo.profile, initinfo.level);
            break;

        case STD_MJPG:
            dec->mjpg_fmt = initinfo.mjpg_sourceFormat;
            info_msg("MJPG SourceFormat: %d\n", initinfo.mjpg_sourceFormat);
            break;

        default:
            break;
        }
    }

    info_msg("Decoder: width = %d, height = %d, fps = %u, count = %u\n",
             initinfo.picWidth, initinfo.picHeight,
             initinfo.frameRateInfo, initinfo.minFrameBufferCount);

#ifdef COMBINED_VIDEO_SUPPORT
    /* Following lines are sample code to support minFrameBuffer counter
       changed in combined video stream. */
    if (dec->cmdl->format == STD_AVC)
        initinfo.minFrameBufferCount = 19;
#endif
    /*
     * We suggest to add two more buffers than minFrameBufferCount:
     *
     * vpu_DecClrDispFlag is used to control framebuffer whether can be
     * used for decoder again. One framebuffer dequeue from IPU is delayed
     * for performance improvement and one framebuffer is delayed for
     * display flag clear.
     *
     * Performance is better when more buffers are used if IPU performance
     * is bottleneck.
     *
     * Two more buffers may be needed for interlace stream from IPU DVI view
     */
    dec->minFrameBufferCount = initinfo.minFrameBufferCount;
    count = getenv("VPU_EXTENDED_BUFFER_COUNT");
    if (count)
        extended_fbcount = atoi(count);
    else
        extended_fbcount = 2;

    if (initinfo.interlace)
        dec->fbcount = initinfo.minFrameBufferCount + extended_fbcount + 2;
    else
        dec->fbcount = initinfo.minFrameBufferCount + extended_fbcount;

    dec->picwidth = ((initinfo.picWidth + 15) & ~15);

    align = 16;
    if ((dec->cmdl->format == STD_MPEG2 ||
         dec->cmdl->format == STD_VC1 || dec->cmdl->format == STD_AVC) && initinfo.interlace == 1)
        align = 32;

    dec->picheight = ((initinfo.picHeight + align - 1) & ~(align - 1));

#ifdef COMBINED_VIDEO_SUPPORT
    /* Following lines are sample code to support resolution change
       from small to large in combined video stream. MAX_FRAME_WIDTH
       and MAX_FRAME_HEIGHT must be defined per user requirement. */
    if (dec->picwidth < MAX_FRAME_WIDTH)
        dec->picwidth = MAX_FRAME_WIDTH;
    if (dec->picheight < MAX_FRAME_HEIGHT)
        dec->picheight = MAX_FRAME_HEIGHT;
#endif

    if ((dec->picwidth == 0) || (dec->picheight == 0))
        return -1;

    /*
     * Information about H.264 decoder picture cropping rectangle which
     * presents the offset of top-left point and bottom-right point from
     * the origin of frame buffer.
     *
     * By using these four offset values, host application can easily
     * detect the position of target output window. When display cropping
     * is off, the cropping window size will be 0.
     *
     * This structure for cropping rectangles is only valid for H.264
     * decoder case.
     */

    /* Add non-h264 crop support, assume left=top=0 */
    if ((dec->picwidth > initinfo.picWidth ||
         dec->picheight > initinfo.picHeight) &&
        (!initinfo.picCropRect.left &&
         !initinfo.picCropRect.top &&
         !initinfo.picCropRect.right && !initinfo.picCropRect.bottom)) {
        initinfo.picCropRect.left = 0;
        initinfo.picCropRect.top = 0;
        initinfo.picCropRect.right = initinfo.picWidth;
        initinfo.picCropRect.bottom = initinfo.picHeight;
    }

    info_msg("CROP left/top/right/bottom %u %u %u %u\n",
             initinfo.picCropRect.left,
             initinfo.picCropRect.top, initinfo.picCropRect.right, initinfo.picCropRect.bottom);

    memcpy(&(dec->picCropRect), &(initinfo.picCropRect), sizeof(initinfo.picCropRect));

    /* worstSliceSize is in kilo-byte unit */
    dec->phy_slicebuf_size = initinfo.worstSliceSize * 1024;
    dec->stride = dec->picwidth;

    /* Allocate memory for frame status, Mb and Mv report */
    if (dec->frameBufStat.enable) {
        dec->frameBufStat.addr = malloc(initinfo.reportBufSize.frameBufStatBufSize);
        if (!dec->frameBufStat.addr)
            err_msg("malloc_error\n");
    }
    if (dec->mbInfo.enable) {
        dec->mbInfo.addr = malloc(initinfo.reportBufSize.mbInfoBufSize);
        if (!dec->mbInfo.addr)
            err_msg("malloc_error\n");
    }
    if (dec->mvInfo.enable) {
        dec->mvInfo.addr = malloc(initinfo.reportBufSize.mvInfoBufSize);
        if (!dec->mvInfo.addr)
            err_msg("malloc_error\n");
    }

    info_msg("Display fps will be %d\n", dec->cmdl->fps);

    return 0;
}

int decoder_open(struct decode *dec)
{
    RetCode ret;
    DecHandle handle = { 0 };
    DecOpenParam oparam = { 0 };
    if (dec->cmdl->mapType == LINEAR_FRAME_MAP)
        dec->tiled2LinearEnable = 0;
    else
        /* CbCr interleave must be enabled for tiled map */
        dec->cmdl->chromaInterleave = 1;

    oparam.bitstreamFormat = dec->cmdl->format;
    oparam.bitstreamBuffer = dec->phy_bsbuf_addr;
    oparam.bitstreamBufferSize = STREAM_BUF_SIZE;
    oparam.reorderEnable = dec->reorderEnable;
    oparam.mp4DeblkEnable = dec->cmdl->deblock_en;
    oparam.chromaInterleave = dec->cmdl->chromaInterleave;
    oparam.mjpg_thumbNailDecEnable = 0;
    oparam.mapType = dec->cmdl->mapType;
    oparam.tiled2LinearEnable = dec->tiled2LinearEnable;

    /*
     * mp4 deblocking filtering is optional out-loop filtering for image
     * quality. In other words, mpeg4 deblocking is post processing.
     * So, host application need to allocate new frame buffer.
     * - On MX27, VPU doesn't support mpeg4 out loop deblocking filtering.
     * - On MX37 and MX51, VPU control the buffer internally and return one
     *   more buffer after vpu_DecGetInitialInfo().
     * - On MX32, host application need to set frame buffer externally via
     *   the command DEC_SET_DEBLOCK_OUTPUT.
     */
    if (oparam.mp4DeblkEnable == 1) {
        dec->cmdl->deblock_en = 0;
    }

    oparam.psSaveBuffer = dec->phy_ps_buf;
    oparam.psSaveBufferSize = PS_SAVE_SIZE;

    ret = vpu_DecOpen(&handle, &oparam);
    if (ret != RETCODE_SUCCESS) {
        err_msg("vpu_DecOpen failed %d\n", ret);
        return -1;
    }

    dec->handle = handle;
    return 0;
}

void decoder_close(struct decode *dec)
{
    DecOutputInfo outinfo = { 0 };
    RetCode ret;

    ret = vpu_DecClose(dec->handle);
    if (ret == RETCODE_FRAME_NOT_COMPLETE) {
        vpu_DecGetOutputInfo(dec->handle, &outinfo);
        ret = vpu_DecClose(dec->handle);
        if (ret != RETCODE_SUCCESS)
            err_msg("vpu_DecClose failed\n");
    }
}

int decode_test(void *arg)
{
    struct cmd_line *cmdl;
    vpu_mem_desc mem_desc = { 0 };
    vpu_mem_desc ps_mem_desc = { 0 };
    vpu_mem_desc slice_mem_desc = { 0 };
    struct decode *dec;
    int ret, eos = 0, fill_end_bs = 0, fillsize = 0;
    bsoffset = 0;
    rawoffset = 0;

    dec = (struct decode *)calloc(1, sizeof(struct decode));
    if (dec == NULL) {
        err_msg("Failed to allocate decode structure\n");
        return -1;
    }

    cmdl = (struct cmd_line *)calloc(1, sizeof(struct cmd_line));
    if (cmdl == NULL) {
        err_msg("Failed to allocate command structure\n");
        return -1;
    }

    mem_desc.size = STREAM_BUF_SIZE;
    ret = IOGetMem(&mem_desc);
    if (ret) {
        err_msg("Unable to obtain physical mem\n");
        return -1;
    }

    dec->phy_bsbuf_addr = mem_desc.phy_addr;
    dec->virt_bsbuf_addr = mem_desc.virt_uaddr;

    dec->reorderEnable = 1;

    dec->userData.enable = 0;
    dec->mbInfo.enable = 0;
    dec->mvInfo.enable = 0;
    dec->frameBufStat.enable = 0;

    /*set the decoder command args */
    strcpy(cmdl->input, "input.avc");   /* Input file name */
    strcpy(cmdl->output, "output.yuv"); /* Output file name */
    cmdl->format = STD_VC1;
    cmdl->src_scheme = PATH_MEM;
    cmdl->dst_scheme = PATH_MEM;
    cmdl->dering_en = 0;
    cmdl->deblock_en = 0;
    cmdl->chromaInterleave = 0;
    cmdl->fps = 30;

    dec->cmdl = cmdl;

    if (cmdl->format == STD_RV)
        dec->userData.enable = 0;   /* RV has no user data */

    if (cmdl->format == STD_AVC) {
        ps_mem_desc.size = PS_SAVE_SIZE;
        ret = IOGetMem(&ps_mem_desc);
        if (ret) {
            err_msg("Unable to obtain physical ps save mem\n");
            goto err;
        }
        dec->phy_ps_buf = ps_mem_desc.phy_addr;
    }

    /* open decoder */
    ret = decoder_open(dec);
    if (ret)
        goto err;

    cmdl->complete = 1;
    if (dec->cmdl->src_scheme == PATH_NET)
        fillsize = 1024;
    ret = dec_fill_bsbuffer(dec->handle, cmdl,
                            dec->virt_bsbuf_addr,
                            (dec->virt_bsbuf_addr + STREAM_BUF_SIZE),
                            dec->phy_bsbuf_addr, fillsize, &eos, &fill_end_bs);
    cmdl->complete = 0;
    if (ret < 0) {
        err_msg("dec_fill_bsbuffer failed\n");
        goto err1;
    }

    /* parse the bitstream */
    ret = decoder_parse(dec);
    if (ret) {
        err_msg("decoder parse failed\n");
        goto err1;
    }

    /* allocate slice buf */
    if (cmdl->format == STD_AVC) {
        slice_mem_desc.size = dec->phy_slicebuf_size;
        ret = IOGetMem(&slice_mem_desc);
        if (ret) {
            err_msg("Unable to obtain physical slice save mem\n");
            goto err1;
        }

        dec->phy_slice_buf = slice_mem_desc.phy_addr;
    }

    /* allocate frame buffers */
    ret = decoder_allocate_framebuffer(dec);
    if (ret)
        goto err1;

    /* Not set fps when doing performance test default */
    if ((dec->cmdl->fps == 0))
        dec->cmdl->fps = 30;

    /* start decoding */
    ret = decoder_start(dec);
  err1:
    decoder_close(dec);

    /* free the frame buffers */
    decoder_free_framebuffer(dec);
  err:
    if (cmdl->format == STD_AVC) {
        IOFreeMem(&slice_mem_desc);
        IOFreeMem(&ps_mem_desc);
    }

    IOFreeMem(&mem_desc);
    free(dec);
    return ret;
}
