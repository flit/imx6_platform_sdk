/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef CHIP_MX6SL

#include <stdio.h>
#include "io.h"
#include "hardware.h"
#include "soc_memory_map.h"

extern audio_pcm_t pcm_music;
extern audio_pcm_para_t pcm_para;
extern audio_pcm_t pcm_record;
extern audio_card_p snd_card_esai;

extern audio_card_p snd_card;

int esai_test_enable;

int esai_test(void)
{
    int nRet1 = TEST_FAILED, nRet2 = TEST_FAILED, nRet3 = TEST_FAILED;
    uint8_t recvCh = 0;
    audio_dev_para_t dev_para;
    uint32_t bytes_written = 0;

    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;
    dev_para.trans_dir = AUDIO_TRANS_DIR_TX;
    dev_para.sample_rate = (pcm_music.para)->sample_rate;
    dev_para.word_length = (pcm_music.para)->word_length;
    dev_para.channel_number = (pcm_music.para)->channel_number;

    if (!esai_test_enable) {
        return TEST_NOTPRESENT;
    }

    PROMPT_RUN_TEST("ESAI");
#if defined(BOARD_SABRE_AI)
    printf
        ("Please make sure the SABRE AI board was mounted on the main board and headphone was plugged. Type 'y' to confirm.\n");
#else
    printf
        ("Please make sure the \"Automative Port card \" was mounted and headphone was plugged. Type 'y' to confirm.\n");
#endif
    do {
        recvCh = getchar();
    } while (0xFF == recvCh);
    if ((recvCh != 'y') && (recvCh != 'Y')) {
        return TEST_BYPASSED;
    }
    
    snd_card = snd_card_esai;
 
    if (0 != snd_card->ops->init(snd_card)) {
        nRet1 = TEST_FAILED;
        goto CleanUP2;
    }
#if defined(BOARD_SABRE_AI)
    dev_para.bus_mode = AUDIO_BUS_MODE_SLAVE;
    snd_card->ops->config(snd_card, &dev_para);
//    esai_config(0, TX_CH_SEL_CH0 | TX_CH_SEL_CH1 | TX_CH_SEL_CH2 | TX_CH_SEL_CH3, RX_CH_SEL_CH0);   //Config as slave
#else
    dev_para.bus_mode = AUDIO_BUS_MODE_MASTER;
    snd_card->ops->config(snd_card, &dev_para);
//    esai_config(1, TX_CH_SEL_CH0 | TX_CH_SEL_CH1 | TX_CH_SEL_CH2 | TX_CH_SEL_CH3, RX_CH_SEL_CH0);   //Config as master
#endif

    while (1) {
        if (0 != snd_card->ops->write(snd_card, pcm_music.buf, pcm_music.size, &bytes_written)) {
            printf("esai_output_data timeout.\n");
            nRet1 = TEST_FAILED;
            goto CleanUP2;
        }

        printf("Do you need to replay it? Type 'y' or 'n'.\n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);
        if ((recvCh == 'y') || (recvCh == 'Y'))
            continue;
        else
            break;
    }

    printf("Do you hear audio? Type 'y' or 'n'.\n");
    do {
        recvCh = getchar();
    } while (0xFF == recvCh);
    if ((recvCh == 'y') || (recvCh == 'Y')) {
        printf(" ESAI playback test passed.\n");
        nRet1 = TEST_PASSED;
    } else {
        printf(" ESAI playback test failed.\n");
        nRet1 = TEST_FAILED;
        goto CleanUP1;
    }

    /***************************LINI-IN recording test*******************/
#if !defined(BOARD_SABRE_AI)          // per Babin 5/9/12

//    audio_pcm_t pcm_record;

    printf("Do you wanna run the LINE-IN recording test? Type 'y' or 'n'.\n");
    do {
        recvCh = getchar();
    } while (0xFF == recvCh);
    if ((recvCh != 'y') && (recvCh != 'Y')) {
        printf("ESAI recording test bypassed.\n");
        nRet2 = TEST_BYPASSED;
    }
    if (nRet2 != TEST_BYPASSED) {
#if (!defined(CHIP_MX6SL) && defined(BOARD_EVB))
        printf("For MX6DQ/MX6SDL EVB board, only Rev X3 supported, and R394 should be mounted.\n");
#endif
        printf("Please connect LINE_OUT signal in your PC ");
#if defined(SABRE_AI)
        printf("to \"LINE-IN\" on the main board.");
#else
        printf(" to AIN1 and AIN2 on \"Automative Port card \".");
#endif

        printf("Type 'y' or 'Y' to confirm.\n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);
        if ((recvCh != 'y') && (recvCh != 'Y')) {
            printf("ESAI recording test bypassed.\n");
            nRet2 = TEST_BYPASSED;
            goto CleanUP1;
        }

        printf("Recording...\n");
        if (snd_card->ops->read(snd_card, pcm_record.buf, pcm_record.size, &bytes_written) <= 0) {
//        if (0 != esai_input_data(audio_record_buf, AUDIO_RECORD_BUF_LEN)) {
            printf("esai_input_data timeout.\n");
            nRet2 = TEST_FAILED;
            goto CleanUP1;
        }

        printf("Press anykey to hear the audio recorded? \n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);

        printf("Playback the music recorded...\n");

        memcpy(&pcm_record, &pcm_music, sizeof(audio_pcm_t));

        while (1) {
            snd_card->ops->write(snd_card, pcm_record.buf, pcm_record.size, &bytes_written);
//            esai_output_data((audio_pcm_p) & pcm_record);

            printf("Do you need to replay it? Type 'y' or 'n'.\n");
            do {
                recvCh = getchar();
            } while (0xFF == recvCh);
            if ((recvCh == 'y') || (recvCh == 'Y'))
                continue;
            else
                break;
        }

        printf("Do you hear audio? Type 'y' or 'n'.\n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);
        if ((recvCh == 'y') || (recvCh == 'Y')) {
            printf(" ESAI record test passed.\n");
            nRet2 = TEST_PASSED;
        } else {
            nRet2 = TEST_FAILED;;
            printf(" ESAI record test failed.\n");
            goto CleanUP1;
        }
    }
#endif // !defined(SABRE_AI) - per Babin 5/8/12

    /***************************** MIC-IN recording test ***********************************/
#if !defined(BOARD_SABRE_AI)          // per Babin 5/8/12
    printf("Do you wanna run the MIC-IN recording test? Type 'y' or 'n'.\n");
    do {
        recvCh = getchar();
    } while (0xFF == recvCh);
    if ((recvCh != 'y') && (recvCh != 'Y')) {
        printf("ESAI recording test bypassed.\n");
        nRet3 = TEST_BYPASSED;
    }
    if (nRet3 != TEST_BYPASSED) {
        printf("Please connect headphone");
        printf("to \"MICS1+2\" on the main board.");

        printf("Type 'y' or 'Y' to confirm.\n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);
        if ((recvCh != 'y') && (recvCh != 'Y')) {
            printf("ESAI MIC-IN recording test bypassed.\n");
            nRet3 = TEST_BYPASSED;
            goto CleanUP1;
        }

        printf("Recording...\n");
        
        if (0 != snd_card->ops->read(snd_card, pcm_record.buf, pcm_record.size, &bytes_written)) {
//        if (0 != esai_input_data(audio_record_buf, AUDIO_RECORD_BUF_LEN)) {
            printf("esai_input_data timeout.\n");
            nRet3 = TEST_FAILED;
            goto CleanUP1;
        }

        printf("Press anykey to hear the audio recorded? \n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);

        printf("Playback the music recorded...\n");

        memcpy(&pcm_record, &pcm_music, sizeof(audio_pcm_t));

        while (1) {
            snd_card->ops->write(snd_card, pcm_record.buf, pcm_record.size, &bytes_written);
//            esai_output_data((audio_pcm_p) & pcm_record);

            printf("Do you need to replay it? Type 'y' or 'n'.\n");
            do {
                recvCh = getchar();
            } while (0xFF == recvCh);
            if ((recvCh == 'y') || (recvCh == 'Y'))
                continue;
            else
                break;
        }

        printf("Do you hear audio? Type 'y' or 'n'.\n");
        do {
            recvCh = getchar();
        } while (0xFF == recvCh);
        if ((recvCh == 'y') || (recvCh == 'Y')) {
            printf(" ESAI record test passed.\n");
            nRet3 = TEST_PASSED;
        } else {
            nRet3 = TEST_FAILED;;
            printf(" ESAI record test failed.\n");
            goto CleanUP1;
            printf("Do you wanna run the LINE-IN recording test? Type 'y' or 'n'.\n");
            do {
                recvCh = getchar();
            } while (0xFF == recvCh);
            if ((recvCh != 'y') && (recvCh != 'Y')) {
                printf("ESAI recording test bypassed.\n");
                nRet3 = TEST_BYPASSED;
                goto CleanUP1;
            }
        }
    }
#endif // !defined(SABRE_AI) - per Babin 5/8/12

  CleanUP1:
    snd_card->ops->deinit(snd_card);
//   esai_deinit();

  CleanUP2:
    if ((nRet1 == TEST_FAILED) || (nRet2 == TEST_FAILED) || (nRet3 == TEST_FAILED))
        return TEST_FAILED;
    else
        return TEST_PASSED;
}

//RUN_TEST_INTERACTIVE("ESAI", esai_test)
#endif //MX6SL
