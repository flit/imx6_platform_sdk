/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "fat_driver.h"
#include "hardware.h"
#include "video.h"
#include "buffers.h"
#include "../../usdhc/inc/usdhc_ifc.h"
#ifdef MMDC_PROFILING
#include "mmdc.h"
#endif

extern void enable_L1_cache(void);

//#define MMDC_PROFILING
#ifdef MMDC_PROFILING
extern void start_mmdc_profiling(mmdc_p mmdc);
extern void stop_mmdc_profiling(mmdc_p mmdc);
extern mmdc_p mmdc_p0;
extern mmdc_p mmdc_p1;
#endif

tFile files[10];
tVolume *V;
int video_disp[2] = { 2, 1 };   //video 1 is show on IPU2, video 2 is shown in IPU1
int second_video_en = 0;

int fat_read_from_usdhc(uint32_t sd_addr, uint32_t sd_size, void *buffer, int fast_flag)
{
    card_data_read(SD_PORT_BASE_ADDR, buffer, sd_size, sd_addr);
    return 1;
}

void init_fat32_device(void *blkreq_func)
{
    int fnum;

    V = (tVolume *) FAT_DRIVER_BUFFER;

    V->blkreq = blkreq_func;
    V->buffer = (char *)(FAT_DRIVER_BUFFER + 0x00100000);

    fat_mount(V);

    fnum = fat_scan_root(V, files, 10, 1, "264");

    printf("File 0 is %s\n", files[0].fname);
    fat_open_file(V, &(files[0]));
    files[0].file_size &= 0xfff80000;

    printf("File 1 is %s\n", files[1].fname);
    fat_open_file(V, &(files[1]));
    files[1].file_size &= 0xfff80000;
}

int vpu_buffer_fill(uint32_t inst, uint32_t addr, uint32_t size)
{
    int res, i;

    /* if SD is currently busy, it means that the other video instance has requested a buffer fill, */
    /* return without doing anything, the video driver will request a buffer fill again next frame */
    int usdhc_status = 0;
    card_xfer_result(SD_PORT_BASE_ADDR, &usdhc_status);
    if (usdhc_status != 1)
        return 0;
    res = fat_read_file(V, &files[inst], (char *)addr, size);

    if (res < size) {
        for (i = 0; i < (size - res); i++)
            reg8_write(addr + res + i, 0x0);
    }

    return 1;
}

extern int ipu_idmac_chan_cur_buff(uint32_t ipu_index, uint32_t channel);
extern void ipu_dma_update_buffer(uint32_t ipu_index, uint32_t channel, uint32_t buffer_index,
                                  uint32_t buffer_addr);
extern void ipu_channel_buf_ready(int ipu_index, int channel, int buf);
extern inline void ipu_cpmem_mod_field(uint32_t base, int w, int bit, int size, uint32_t v);
int ipu_refresh(uint32_t * buffer)
{
    ipu_dma_update_buffer(video_disp[0], 23, 0, buffer[0]);
    ipu_channel_buf_ready(video_disp[0], 23, 0);
    if (second_video_en) {
        ipu_dma_update_buffer(video_disp[1], 23, 0, buffer[1]);
        ipu_channel_buf_ready(video_disp[1], 23, 0);
    }
    return 0;
}

void config_system_parameters(void)
{
    /* set AxCACHE bits for IPU/VPU/VDOA */
    reg32_write(IOMUXC_GPR4, reg32_read(IOMUXC_GPR4) | 0xFF0000CF);

    /* increase QoS for IPUs, id 0 */
    reg32_write(IOMUXC_GPR6, 0x22272227);
    reg32_write(IOMUXC_GPR7, 0x22272227);
}

extern int config_hdmi_si9022(int ipu_index, int ipu_di);
extern void hdmi_1080P60_video_output(int ipu_index, int ipu_di);
extern int ips_hdmi_1080P60_stream(int ipu_index);

int vdec_test(void)
{
    video_params params[2];

    /*instance attached to display interface */
    config_system_parameters();

    /* initialize SD card and FAT driver */
    enable_L1_cache();

    card_init(SD_PORT_BASE_ADDR, 4);    //SD card must work in 4-bit mode

    /*uSDHC working in POLLING mode */
    init_fat32_device((void *)fat_read_from_usdhc);

    /*now enable the INTERRUPT mode of usdhc */
    SDHC_INTR_mode = 1;
    SDHC_ADMA_mode = 1;

    /* initialize VPU */
    VPU_Init(VPU_WORK_BUFFERS);

    /* initialize video streams and configure IPUs */
    video_setup(0, VDOA_DIS, VIDEO_0_BUFFERS, &params[0]);
    hdmi_1080P60_video_output(video_disp[0], 0);
    ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[0], 23), NON_INTERLEAVED_UBO,
                        params[0].u_offset / 8);
    ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[0], 23), NON_INTERLEAVED_VBO,
                        params[0].v_offset / 8);
    ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[0], 23), NON_INTERLEAVED_SLY,
                        params[0].y_strideline - 1);
    ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[0], 23), NON_INTERLEAVED_SLUV,
                        params[0].uv_strideline - 1);
    printf("The first HDMI display is configured!!\n");

    /* initialize video streams and configure IPUs for second instance */
    if (!config_hdmi_si9022(video_disp[1], 0)) {
        video_setup(1, VDOA_DIS, VIDEO_1_BUFFERS, &params[1]);
        config_hdmi_si9022(video_disp[1], 0);
        ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[1], 23), NON_INTERLEAVED_UBO,
                            params[1].u_offset / 8);
        ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[1], 23), NON_INTERLEAVED_VBO,
                            params[1].v_offset / 8);
        ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[1], 23), NON_INTERLEAVED_SLY,
                            params[1].y_strideline - 1);
        ipu_cpmem_mod_field(ipu_cpmem_addr(video_disp[1], 23), NON_INTERLEAVED_SLUV,
                            params[1].uv_strideline - 1);
        second_video_en = 1;
        printf("The second HDMI display is configured!!\n");
    } else {
        printf("The second HDMI display is not detected!!\n");
        second_video_en = 0;
    }

    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x10000);
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITLR_OFFSET, 0x444);   //30fps
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000e);
    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITCR_OFFSET, 0x0302000f);

#ifdef MMDC_PROFILING
    mmdc_profile_res_t prof_results;
    start_mmdc_profiling(mmdc_p0);
    hal_delay_us(1000000);
    stop_mmdc_profiling(mmdc_p0);
    if (!get_mmdc_profiling_results(mmdc_p0, &prof_results))
        printf("MMDC Profiler counters overflow!\n");
    else
        print_mmdc_profiling_results(&prof_results, RES_FULL);
#endif

    while (1) ;
}
