/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
/*!
 * @defgroup diag_spdif SPDIF Test
 */

/*!
 * @file spdif.c
 * @brief Simple poll-driven on-chip spdif driver to playback some audio
 *
 * @ingroup diag_spdif
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "hardware.h"
//#include "soc_types.h"
#include "spdif/regsspdif.h"
#include "spdif/spdif_wav_data.h"

//=============================================================================
// Channel Status for Consumer use according to IEC60959-3
//=============================================================================
#define IEC958_CON_CTRL_CONS        (0x0 << 0)  //Consumer use of channel status block
#define IEC958_CON_AUDIO_PCM        (0x0 << 0)
#define IEC958_CON_AUDIO_COMPRESSED (0x1 << 0)
#define IEC958_CON_COPYRIGHT_NONE   (0x0 << 0)
#define IEC958_CON_COPYRIGHT_WITH   (0x1 << 0)
#define IEC958_CON_EMPHASIS_NONE    (0x0 << 0)
#define IEC958_CON_EMPHASIS_5015    (0x1 << 0)
#define IEC958_CON_EMPHASIS_RESV    (0x2 << 0)
#define IEC958_CON_CHANNEL_MODE0    (0x0 << 0)

#define IEC958_CON_SOURCE_NUMBER_0  (0x0 << 0)
#define IEC958_CON_SOURCE_NUMBER_1  (0x1 << 0)
#define IEC958_CON_SOURCE_NUMBER_2  (0x2 << 0)
#define IEC958_CON_SOURCE_NUMBER_3  (0x3 << 0)
#define IEC958_CON_SOURCE_NUMBER_4  (0x4 << 0)
#define IEC958_CON_SOURCE_NUMBER_5  (0x5 << 0)
#define IEC958_CON_SOURCE_NUMBER_6  (0x6 << 0)
#define IEC958_CON_SOURCE_NUMBER_7  (0x7 << 0)
#define IEC958_CON_SOURCE_NUMBER_8  (0x8 << 0)
#define IEC958_CON_SOURCE_NUMBER_9  (0x9 << 0)
#define IEC958_CON_SOURCE_NUMBER_10 (0x10 << 0)
#define IEC958_CON_SOURCE_NUMBER_11 (0x11 << 0)
#define IEC958_CON_SOURCE_NUMBER_12 (0x12 << 0)
#define IEC958_CON_SOURCE_NUMBER_13 (0x13 << 0)
#define IEC958_CON_SOURCE_NUMBER_14 (0x14 << 0)
#define IEC958_CON_SOURCE_NUMBER_15 (0x15 << 0)

#define IEC958_CON_SAMPLE_FREQ_44100 (0x0 << 0)
#define IEC958_CON_SAMPLE_FREQ_48000 (0x1 << 0)
#define IEC958_CON_SAMPLE_FREQ_32000 (0x3 << 0)

#define IEC958_CON_CLOCK_ACCURACY_LEVEL2 (0x0 << 0)
#define IEC958_CON_CLOCK_ACCURACY_LEVEL1 (0x1 << 0)
#define IEC958_CON_CLOCK_ACCURACY_LEVEL3 (0x2 << 0)
#define IEC958_CON_CLOCK_ACCURACY_RSV    (0x3 << 0)

#define IEC958_CON_MAX_LENGTH_20         (0x0 << 0)
#define IEC958_CON_MAX_LENGTH_24         (0x1 << 0)

#define IEC958_CON_SAMPLE_LENGTH_NODEFINED  (0x1 << 0)
#define IEC958_CON_SAMPLE_LENGTH_20_16   (0x1 << 0)
#define IEC958_CON_SAMPLE_LENGTH_22_18   (0x2 << 0)
#define IEC958_CON_SAMPLE_LENGTH_23_19   (0x4 << 0)
#define IEC958_CON_SAMPLE_LENGTH_24_20   (0x5 << 0)
#define IEC958_CON_SAMPLE_LENGTH_21_17   (0x6 << 0)

//=============================================================================
// Channel infomation structure based on IEC-60958
//=============================================================================
typedef struct {
    union {
        unsigned int Data;
        struct {
            unsigned int ChannelStatus:1;
            unsigned int AudioFormat:1;
            unsigned int Copyright:1;
            unsigned int AddInfo:3;
            unsigned int ChannelMode:2;
            unsigned int CategoryCode:8;
            unsigned int SourceNumber:4;
            unsigned int ChannelNumber:4;
            unsigned int Dummy:8;
        } Ctrl;
    } H;                        //bits [47:24] of C Channel
    union {
        unsigned int Data;
        struct {
            unsigned int SampleFreq:4;
            unsigned int ClockAccuracy:2;
            unsigned int Dummy1:2;
            unsigned int MaxLenth:1;
            unsigned int Samplenth:3;
            unsigned int Dummy2:20;
        } Ctrl;
    } L;                        //bits [23:0] of C Channel

} CCHANNEL, *P_CCHANNEL;

//=============================================================================
// Enumeration of audio format.
//=============================================================================
typedef enum FormatTag {
    WAVE_FORMAT_PCM = 0,
    FORMAT_COMPRESSED = 1
} FormatTag_t;

extern char receive_char(void);

/*!
 * Configure spdif pins
 *
 */
void SPDIFPinMux(void)
{
    *(volatile unsigned int *)(0x80018000 + 0x08) = 0xC0000000;

    //spdif tx muxsel 7, gpio3_27
    *(volatile unsigned int *)(0x80018000 + 0x178) = 0x3 << 22;

    *(volatile unsigned int *)(0x80018000 + 0x3f8) = 0x3 << 12;
    *(volatile unsigned int *)(0x80018000 + 0x3f4) = 0x2 << 12;

}

/*!
 * Enable clk_spdif
 *
 */
void SPDIFClkCtrl(void)
{
    //pll 480MHz-> DIV/4 fixed -> clk_spdif
    //power up pll0
    *(volatile unsigned int *)(0x80040000 + 0x4) = 1 << 17;

    //spdif clk gate
    *(volatile unsigned int *)(0x80040000 + 0xE0) = 0x0;
}

/*!
 * Initialize spdif registers
 *
 */
void SPDIFOUTInit(void)
{
    CCHANNEL channel;
    unsigned int SampleRate = 48000;
    unsigned int FormatTag = WAVE_FORMAT_PCM;

    HW_SPDIF_CTRL_CLR(BM_SPDIF_CTRL_CLKGATE | BM_SPDIF_CTRL_SFTRST);

    HW_SPDIF_CTRL_CLR(BM_SPDIF_CTRL_WAIT_END_XFER);

    HW_SPDIF_CTRL_SET(BM_SPDIF_CTRL_WORD_LENGTH);

    HW_SPDIF_CTRL_SET(BM_SPDIF_CTRL_FIFO_OVERFLOW_IRQ | BM_SPDIF_CTRL_FIFO_UNDERFLOW_IRQ);

    // write channel data (consumer mode)
    memset(&channel, 0, sizeof(channel));
    channel.H.Ctrl.ChannelStatus = IEC958_CON_CTRL_CONS;    //Consumer use of channel status block
    if (FormatTag == WAVE_FORMAT_PCM)
        channel.H.Ctrl.AudioFormat = IEC958_CON_AUDIO_PCM;
    else                        //SPDIF_AUDIO_TYPE_COMPRESSED
        channel.H.Ctrl.AudioFormat = IEC958_CON_AUDIO_COMPRESSED;
    channel.H.Ctrl.Copyright = IEC958_CON_COPYRIGHT_NONE;
    channel.H.Ctrl.AddInfo = IEC958_CON_EMPHASIS_5015;
    channel.H.Ctrl.ChannelMode = IEC958_CON_CHANNEL_MODE0;
    channel.H.Ctrl.SourceNumber = IEC958_CON_SOURCE_NUMBER_2;

    channel.L.Ctrl.ClockAccuracy = IEC958_CON_CLOCK_ACCURACY_LEVEL2;

    if (SampleRate == 44100)
        channel.L.Ctrl.SampleFreq = IEC958_CON_SAMPLE_FREQ_44100;
    else if (SampleRate == 32000)
        channel.L.Ctrl.SampleFreq = IEC958_CON_SAMPLE_FREQ_32000;
    else                        //48K
        channel.L.Ctrl.SampleFreq = IEC958_CON_SAMPLE_FREQ_48000;

    if (SampleRate == 16) {
        channel.L.Ctrl.MaxLenth = IEC958_CON_MAX_LENGTH_20;
        channel.L.Ctrl.Samplenth = IEC958_CON_SAMPLE_LENGTH_20_16;  //IEC958_CON_SAMPLE_LENGTH_20_16;
    } else                      //wBitsPerSample ==  24. 32
    {
        channel.L.Ctrl.MaxLenth = IEC958_CON_MAX_LENGTH_24;
        channel.L.Ctrl.Samplenth = IEC958_CON_SAMPLE_LENGTH_24_20;  //IEC958_CON_SAMPLE_LENGTH_24_20;
    }

    HW_SPDIF_FRAMECTRL_SET(BF_SPDIF_FRAMECTRL_PRO(channel.H.Ctrl.ChannelStatus) |
                           BF_SPDIF_FRAMECTRL_AUDIO(channel.H.Ctrl.AudioFormat) |
                           BF_SPDIF_FRAMECTRL_COPY(channel.H.Ctrl.Copyright) |
                           BF_SPDIF_FRAMECTRL_PRE(channel.H.Ctrl.AddInfo) |
                           BF_SPDIF_FRAMECTRL_CC(channel.H.Ctrl.CategoryCode));

    //Config samplerate
    if (SampleRate == 44100) {
        HW_SPDIF_SRR_WR(BF_SPDIF_SRR_BASEMULT(1) | 0x0AC44);
    } else if (SampleRate == 32000) {
        HW_SPDIF_SRR_WR(BF_SPDIF_SRR_BASEMULT(1) | 0x07D00);
    } else                      // 48K
    {
        HW_SPDIF_SRR_WR(BF_SPDIF_SRR_BASEMULT(1) | 0x0BB80);
    }

    //SPDIF CONTROL Register
    HW_SPDIF_CTRL_CLR(BF_SPDIF_CTRL_RUN(1));

}

/*!
 * Initialize the on-chip spdif module
 *
 */
void SPDIFInit(void)
{
    //Pin mux
    SPDIFPinMux();

    //Clk init
    SPDIFClkCtrl();

    //output initialization
    SPDIFOUTInit();
}

/*!
 * Test the spdif feature through playing some audio
 *
 * @return      TEST_PASSED or TEST_FAILED
 */
static int spdif_test(void)
{
    int i, result;
    unsigned char recvCh;

    PROMPT_RUN_TEST("SPDIF", NULL);

    SPDIFInit();

    printf("Start spdif TX...\n");

    HW_SPDIF_CTRL_SET(BF_SPDIF_CTRL_RUN(1));

    i = 0;
    while (1) {
        if (HW_SPDIF_DEBUG_RD() & (1 << 0)) {
            HW_SPDIF_DATA_WR(*((unsigned int *)wav_data1 + i));
            i++;
            if (i >= 40314 /*32-bit word count of wav_data array */ ) {
                i = 0;
                printf
                    (" Do you need to re-play it? Type 'R' or 'r'. Type 'N' or 'n' to break test\n");
                do {
                    recvCh = receive_char();
                } while (recvCh == 0xFF);
                if ((recvCh == 'R') || (recvCh == 'r'))
                    continue;   /* hear again */
                else
                    break;      /* by pass */

            }
        }
    }

    printf(" Do you hear audio through SPDIF? Type 'y' or 'Y'\n");
    do {
        recvCh = getchar();
    } while (recvCh == 0xFF);
    if ((recvCh == 'y') || (recvCh == 'Y'))
        result = 0;             /* If user types 'Y' or 'y' test passed */
    else
        result = -1;            /* Else test failed */

    HW_SPDIF_CTRL_CLR(BF_SPDIF_CTRL_RUN(1));

    return result;

}

//RUN_TEST_INTERACTIVE("SPDIF", spdif_test)
