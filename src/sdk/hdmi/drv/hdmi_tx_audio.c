
/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file hdmi_tx_audio.c
 * @brief hdmi tx audio configuration.
 * @ingroup diag_hdmi
 */

#include <stdio.h>
#include "hardware.h"
#include "hdmi_tx.h"

#define ValidityBit 1
#define UserBit 0

//extern unsigned i;

//extern hdmi_data_info_s hdmi_instance;
//extern hdmi_audioparam_s hdmi_audioparam_instance;

/*! ------------------------------------------------------------
 * HDMI TX Audio
 *  ------------------------------------------------------------
 */
uint32_t hdmi_audio_mute(uint32_t en)
{
    writebf((en == TRUE) ? 0xF : 0, HDMI_FC_AUDSCONF, 4, 4);
    return TRUE;
}

void audio_PacketLayout(uint8_t bit)
{
    writebf(bit, HDMI_FC_AUDSCONF, 0, 1);
}

void audio_ValidityRight(uint8_t bit, unsigned int channel)
{
    writebf(bit, HDMI_FC_AUDSV, 4 + channel, 1);

}

void audio_ValidityLeft(uint8_t bit, unsigned int channel)
{
    writebf(bit, HDMI_FC_AUDSV, channel, 1);
}

void audio_UserRight(uint8_t bit, unsigned int channel)
{
    writebf(bit, HDMI_FC_AUDSU, 4 + channel, 1);
}

void audio_UserLeft(uint8_t bit, unsigned int channel)
{
    writebf(bit, HDMI_FC_AUDSU, channel, 1);
}

void audio_IecCgmsA(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS0, 4, 2);
}

void audio_IecCopyright(uint8_t bit)
{
    writebf(bit, HDMI_FC_AUDSCHNLS0, 0, 1);
}

void audio_IecCategoryCode(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS1, 0, 8);
}

void audio_IecPcmMode(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS2, 4, 3);
}

void audio_IecSource(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS2, 0, 4);
}

int audio_IecChannelRight(uint8_t value, unsigned int channel)
{
    if (channel == 0) {
        writebf(value, HDMI_FC_AUDSCHNLS3, 0, 4);
    } else if (channel == 1) {
        writebf(value, HDMI_FC_AUDSCHNLS3, 4, 4);
    } else if (channel == 2) {
        writebf(value, HDMI_FC_AUDSCHNLS4, 0, 4);
    } else if (channel == 3) {
        writebf(value, HDMI_FC_AUDSCHNLS4, 4, 4);
    } else {
        return FALSE;
    }
    return TRUE;
}

int audio_IecChannelLeft(uint8_t value, unsigned int channel)
{
    if (channel == 0) {
        writebf(value, HDMI_FC_AUDSCHNLS5, 0, 4);
    } else if (channel == 1) {
        writebf(value, HDMI_FC_AUDSCHNLS5, 4, 4);
    } else if (channel == 2) {
        writebf(value, HDMI_FC_AUDSCHNLS6, 0, 4);
    } else if (channel == 3) {
        writebf(value, HDMI_FC_AUDSCHNLS6, 4, 4);
    } else {
        return FALSE;
    }
    return TRUE;
}

void audio_IecClockAccuracy(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS7, 4, 2);
}

void audio_IecSamplingFreq(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS7, 0, 4);
}

void audio_IecOriginalSamplingFreq(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS8, 4, 4);
}

void audio_IecWordLength(uint8_t value)
{
    writebf(value, HDMI_FC_AUDSCHNLS8, 0, 4);
}

void audio_DMA_InterruptMask(uint8_t value)
{
    writeb(value, HDMI_AHB_DMA_MASK);
}

void audio_DMA_InterruptPolarity(uint8_t value)
{
    writeb(value, HDMI_AHB_DMA_POL);
}

void audio_DMA_ResetFIFO()
{
    writebf(1, HDMI_AHB_DMA_CONF0, 7, 1);
}

void audio_clk_N(uint32_t value)
{
    writeb((uint8_t) (value >> 0), HDMI_AUD_N1);
    writeb((uint8_t) (value >> 8), HDMI_AUD_N2);
    writeb((uint8_t) (value >> 16), HDMI_AUD_N3);
}

void audio_clk_CTS(uint32_t value)
{
    writeb((uint8_t) (value >> 0), HDMI_AUD_CTS1);
    writeb((uint8_t) (value >> 8), HDMI_AUD_CTS2);
    writebf((uint8_t) (value >> 16), HDMI_AUD_CTS3, 0, 4);
    writebf((value != 0) ? 1 : 0, HDMI_AUD_CTS3, 4, 1);
}

void audio_clk_F(uint8_t value)
{
    writebf(value, HDMI_AUD_INPUTCLKFS, 0, 3);
}

unsigned audio_ComputeN(uint32_t freq, uint16_t pixelClk, unsigned ratioClk)
{
    uint32_t n = (128 * freq) / 1000;

    switch (freq) {
    case 32000:
        if (pixelClk == 2517) {
            n = (ratioClk == 150) ? 9152 : 4576;
        } else if (pixelClk == 2702) {
            n = (ratioClk == 150) ? 8192 : 4096;
        } else if (pixelClk == 7417 || pixelClk == 14835) {
            n = 11648;
        } else {
            n = 4096;
        }
        break;
    case 44100:
        if (pixelClk == 2517) {
            n = 7007;
        } else if (pixelClk == 7417) {
            n = 17836;
        } else if (pixelClk == 14835) {
            n = (ratioClk == 150) ? 17836 : 8918;
        } else {
            n = 6272;
        }
        break;
    case 48000:
        if (pixelClk == 2517) {
            n = (ratioClk == 150) ? 9152 : 6864;
        } else if (pixelClk == 2702) {
            n = (ratioClk == 150) ? 8192 : 6144;
        } else if (pixelClk == 7417) {
            n = 11648;
        } else if (pixelClk == 14835) {
            n = (ratioClk == 150) ? 11648 : 5824;
        } else {
            n = 6144;
        }
        break;
    case 88200:
        n = audio_ComputeN(44100, pixelClk, ratioClk) * 2;
        break;
    case 96000:
        n = audio_ComputeN(48000, pixelClk, ratioClk) * 2;
        break;
    case 176400:
        n = audio_ComputeN(44100, pixelClk, ratioClk) * 4;
        break;
    case 192000:
        n = audio_ComputeN(48000, pixelClk, ratioClk) * 4;
        break;
    default:
        break;
    }
    return n;
}

unsigned audio_ComputeCTS(uint32_t freq, uint16_t pixelClk, unsigned ratioClk)
{
    uint32_t cts = 0;
    switch (freq) {
    case 32000:
        if (pixelClk == 29700) {
            cts = 222750;
            break;
        }
    case 48000:
    case 96000:
    case 192000:
        switch (pixelClk) {
        case 2520:
        case 2700:
        case 5400:
        case 7425:
        case 14850:
            cts = pixelClk * 10;
            break;
        case 29700:
            cts = 247500;
            break;
        default:
//                   All other TMDS clocks are not supported by DWC_hdmi_tx
//                   the TMDS clocks divided or multiplied by 1,001
//                   coefficients are not supported.

            break;
        }
        break;
    case 44100:
    case 88200:
    case 176400:
        switch (pixelClk) {
        case 2520:
            cts = 28000;
            break;
        case 2700:
            cts = 30000;
            break;
        case 5400:
            cts = 60000;
            break;
        case 7425:
            cts = 82500;
            break;
        case 14850:
            cts = 165000;
            break;
        case 29700:
            cts = 247500;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return (cts * ratioClk) / 100;
}

//*/

void audio_DMA_StartAddr(uint32_t value)
{
    writeb((uint8_t) (value >> 0), HDMI_AHB_DMA_STRADDR0);
    writeb((uint8_t) (value >> 8), HDMI_AHB_DMA_STRADDR1);
    writeb((uint8_t) (value >> 16), HDMI_AHB_DMA_STRADDR2);
    writeb((uint8_t) (value >> 24), HDMI_AHB_DMA_STRADDR3);
}

void audio_DMA_StopAddr(uint32_t value)
{
    writeb((uint8_t) (value >> 0), HDMI_AHB_DMA_STPADDR0);
    writeb((uint8_t) (value >> 8), HDMI_AHB_DMA_STPADDR1);
    writeb((uint8_t) (value >> 16), HDMI_AHB_DMA_STPADDR2);
    writeb((uint8_t) (value >> 24), HDMI_AHB_DMA_STPADDR3);
}

void audio_DMA_LockEnable(uint8_t bit)
{
    writebf(bit, HDMI_AHB_DMA_CONF0, 3, 1);
}

void audio_DMA_BurstMode(uint8_t bit)
{
    writebf(bit, HDMI_AHB_DMA_CONF0, 0, 1);
}

void audio_DMA_IncrType(uint8_t value)
{
    writebf(value, HDMI_AHB_DMA_CONF0, 1, 2);
}

void audio_DMA_Threshold(uint8_t value)
{
    writeb(value, HDMI_AHB_DMA_THRSLD);
}

void audio_DMA_SetCONF1(uint8_t value)
{
    writeb(value, HDMI_AHB_DMA_CONF1);
}

void audio_DMA_Start()
{
    writebf(1, HDMI_AHB_DMA_START, 0, 1);
}

int audio_Configure(hdmi_audioparam_s hdmi_audioparam_instance, uint16_t pixelClk,
                    unsigned ratioClk)
{
//  hdmi_audioparam_s hdmi_audioparam_instance;
    //unsigned i;
    audio_PacketLayout((Audio_ChannelCount(hdmi_audioparam_instance.ChannelAllocation) >
                        2) ? 1 : 0);

    audio_DMA_InterruptMask(0x7f);
    audio_DMA_InterruptPolarity(0xFF);
    audio_DMA_ResetFIFO();

    audio_clk_N(audio_ComputeN(hdmi_audioparam_instance.SamplingFrequency, pixelClk, ratioClk));
    audio_clk_CTS(audio_ComputeCTS(hdmi_audioparam_instance.SamplingFrequency, pixelClk, ratioClk));    // automatic mode
//  audio_clk_F( 0);
    audio_info_config();
    return hdmi_audio_mute(FALSE);
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
uint8_t Audio_ChannelCount(uint8_t mChannelAllocation)
{
    switch (mChannelAllocation) {
    case 0x00:
        return 1;
    case 0x01:
    case 0x02:
    case 0x04:
        return 2;
    case 0x03:
    case 0x05:
    case 0x06:
    case 0x08:
    case 0x14:
        return 3;
    case 0x07:
    case 0x09:
    case 0x0A:
    case 0x0C:
    case 0x15:
    case 0x16:
    case 0x18:
        return 4;
    case 0x0B:
    case 0x0D:
    case 0x0E:
    case 0x10:
    case 0x17:
    case 0x19:
    case 0x1A:
    case 0x1C:
        return 5;
    case 0x0F:
    case 0x11:
    case 0x12:
    case 0x1B:
    case 0x1D:
    case 0x1E:
        return 6;
    case 0x13:
    case 0x1F:
        return 7;
    default:
        return 0;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
uint8_t Audio_IecOriginalSamplingFrequency(uint32_t mOriginalSamplingFrequency)
{
    // SPEC values are LSB to MSB
    switch (mOriginalSamplingFrequency) {
    case 44100:
        return 0xF;
    case 88200:
        return 0x7;
    case 22050:
        return 0xB;
    case 176400:
        return 0x3;
    case 48000:
        return 0xD;
    case 96000:
        return 0x5;
    case 24000:
        return 0x9;
    case 192000:
        return 0x1;
    case 8000:
        return 0x6;
    case 11025:
        return 0xA;
    case 12000:
        return 0x2;
    case 32000:
        return 0xC;
    case 16000:
        return 0x8;
    default:
        return 0x0;             // not indicated
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
uint8_t Audio_IecSamplingFrequency(uint32_t mSamplingFrequency)
{
    // SPEC values are LSB to MSB
    switch (mSamplingFrequency) {
    case 22050:
        return 0x4;
    case 44100:
        return 0x0;
    case 88200:
        return 0x8;
    case 176400:
        return 0xC;
    case 24000:
        return 0x6;
    case 48000:
        return 0x2;
    case 96000:
        return 0xA;
    case 192000:
        return 0xE;
    case 32000:
        return 0x3;
    case 768000:
        return 0x9;
    default:
        return 0x1;             // not indicated
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
uint8_t Audio_IecWordLength(uint8_t mSampleSize)
{
    // SPEC values are LSB to MSB
    switch (mSampleSize) {
    case 20:
        return 0x3;             // or 0xA;
    case 22:
        return 0x5;
    case 23:
        return 0x9;
    case 24:
        return 0xB;
    case 21:
        return 0xD;
    case 16:
        return 0x2;
    case 18:
        return 0x4;
    case 19:
        return 0x8;
    case 17:
        return 0xC;
    default:
        return 0x0;             // not indicated
    }
}

void audio_Configure_DMA(uint32_t startAddr, uint32_t stopAddr, uint8_t hlockEn, uint8_t incrType,
                         uint8_t threshold, uint32_t audioChnl, uint8_t intMask)
{
    audio_DMA_StartAddr(startAddr);
    audio_DMA_StopAddr(stopAddr);
    audio_DMA_LockEnable(hlockEn);

    switch (incrType) {
    case 1:
        audio_DMA_BurstMode(0);
        audio_DMA_IncrType(0);
        break;
    case 4:
        audio_DMA_BurstMode(1);
        audio_DMA_IncrType(0);
        break;
    case 8:
        audio_DMA_BurstMode(1);
        audio_DMA_IncrType(1);
        break;
    case 16:
        audio_DMA_BurstMode(1);
        audio_DMA_IncrType(2);
        break;
    default:
        printf("invalid incrType: 0x%x\n", incrType);
        break;
    }
    audio_DMA_Threshold(threshold);
    audio_DMA_InterruptMask(intMask);
    audio_DMA_InterruptPolarity(0xFF);

    switch (audioChnl) {
    case 2:
        audio_DMA_SetCONF1(0x3);
        break;
    case 4:
        audio_DMA_SetCONF1(0xF);
        break;
    case 6:
        audio_DMA_SetCONF1(0x3F);
        break;
    case 8:
        audio_DMA_SetCONF1(0xFF);
        break;
    default:
        printf("invalid auduo channel number: 0x%x\n", audioChnl);
        break;
    }

    audio_DMA_Start();
}

void audio_info_config()
{
    writeb(0x10, HDMI_FC_AUDICONF0);
    writeb(0x00, HDMI_FC_AUDICONF1);
    writeb(0x0, HDMI_FC_AUDICONF2);
}
