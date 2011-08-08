/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_dc.c
 * @brief display controller configuration of IPU.
 * @ingroup diag_ipu
 */
#include <stdio.h>
#include <string.h>
#include "ipu_common.h"
#include "hardware.h"
/*!
 * DC submodule configuration.
 * DC submodule is to control the data, and tranfer them to display.
 * So DC channel #5 is selected to link DMFC(from IDMAC channel #23) and DI0 display port #3.
 */
void dc_config(int ipu_index)
{
    dc_channel_config(ipu_index);
    dc_event_routines(ipu_index);
}

/*!
 * this function is to config the DC channel to link IDMAC channel #23 
 * and DI display port. Here we choose display #3.
 */
void dc_event_routines(int ipu_index)
{
    microcode_config(ipu_index, 6,  //word address
                     1,         //stop
                     "WROD", 0, //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //select map conf 0
                     1,         //waveform generated by DI0_DW_GEN0
                     0,         //GLUELOGIC
                     5);        //sync with unit #5
    /*link events to routines */
    microcode_event(ipu_index, "5", "NEW_DATA", 1, 6);

    /*config DC map for data, RGB 666 mode */

    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_OFFSET_2, 17);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_MASK_2, 0xFC);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_1, 11);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_1, 0xFC);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_0, 5);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_0, 0xFC);

    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_0, 2);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_0, 1);
    ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_0, 0);

}

/*!
 * config the DC channel properties.
 */
void dc_channel_config(int ipu_index)
{
    /*configure DC channel #5 for channel 23, sync type and link to display port 3 */
    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_START_TIME_5, 0);  //ANTITEARING START TIME
    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__CHAN_MASK_DEFAULT_5, 0);    //just higher priority event will be served
    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_CHAN_TYP_5, 4);    //Normal mode without anti-tearing
    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DISP_ID_5, 3); //select display 3

    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, 0);   //channel associated to DI1

    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__W_SIZE_5, 2);   //Component size access to DC set to 24bit
    ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__FIELD_MODE_5, 0);   //field mode enable

    ipu_write_field(ipu_index, IPU_DC_WR_CH_ADDR_5__ST_ADDR_5, 0);  //START ADDRESS OF CHANNEL

    ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_5, 1); //sets the priority of channel #5 to high.
    ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_1, 1); //sets the priority of channel #1 to high.
    ipu_write_field(ipu_index, IPU_DC_GEN__MASK_EN, 0); // mask channel is disabled.(mask channel can associated with different IDMAC channels)
    ipu_write_field(ipu_index, IPU_DC_GEN__DC_CH5_TYPE, 0); // alternate sync or asyn flow
    ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_1_6, 2);    //DC channel #1 handles sync flow

    /*Display port Configuration for DI0 */
    ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__ADDR_INCREMENT_3, 0);   //automatical address increase by 1
    ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__DISP_TYP_3, 2); //paralell display without byte enable
    ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_3__SL_3, 1024 - 1);    //stride line
}

void microcode_config(int ipu_index, int word, int stop, char opcode[10],
                      int lf, int af, int operand, int mapping, int waveform, int gluelogic,
                      int sync)
{

    unsigned int LowWord = 0;
    unsigned int HighWord = 0;
    unsigned int opcode_fixed;

    /*HLG - HOLD WORD GENERIC:  hold operand in register for next operating,
       without display access */
    if (!strcmp(opcode, "HLG")) {
        LowWord = LowWord | (operand << 5); //[31:5]
        HighWord = HighWord | (operand >> 27);  //[36:32]
        opcode_fixed = 0x0;     //0-0
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WRITE DATA to display */
    else if (!strcmp(opcode, "WROD")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*Generic data, this data is attached with OR to 16 MSB of
           mapped address   */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        opcode_fixed = 0x18 | (lf << 1);    //1-1-0-lf-0
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*ATTACH AND HOLD ADDRESS in REGISTER, Adding Mapped Address
       to held data and hold in register */
    else if (!strcmp(opcode, "HLOAR")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        // 1 0 0 0 1 1 1 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x8E | (af << 0);    //1-0-0-0-1-1-1-AF
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*ATTACH AND WRITE ADDRESS to DISPLAY, Adding Mapped Address
       to held data and write to display */
    else if (!strcmp(opcode, "WROAR")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        // 1 1 0 0 1 1 1 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0xCE | (af << 0);    //1-1-0-0-1-1-1-AF
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*ATTACH AND HOLD DATA in REGISTER, Adding Mapped Address
       to held data and hold in register */
    else if (!strcmp(opcode, "HLODR")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8C;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WRODR -  WRITE_DATA_OPCODE - ATTACH AND WRITE DATA to DISPLAY,
       Adding Mapped Data to hold data in internal register and write to display */
    else if (!strcmp(opcode, "WRODR")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0xCC;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WRITE BIT CHANNEL. merging 1bit mask from IDMAC mask channel
       with data and write to display */
    else if (!strcmp(opcode, "WRBC")) {
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        opcode_fixed = 0x19B;   //
        HighWord = HighWord | (opcode_fixed << 0);  //[40:32]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WAIT CLOCK - Waiting N clocks */
    else if (!strcmp(opcode, "WCLK")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        mapping = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0xC9;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WAIT STATUS - 3 microcodes command loop for  checking display status
       by POLLING READ. THE WSTS_II has to be used immediately after WSTS _III */
    else if (!strcmp(opcode, "WSTS_III")) {
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8B;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WAIT STATUS - second command in  3 microcode commands loop or first
       command in 2 microcode commands loop for  checking display status by
       POLLING READ. THE WSTS_I has to be used immediately after WSTS_II */
    else if (!strcmp(opcode, "WSTS_II")) {
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8A;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WAIT STATUS - third command in  3 microcode commands loop or second command
       in 2 microcode commands loop or first command in one command loop for  checking
       display status by POLLING READ. */
    else if (!strcmp(opcode, "WSTS_I")) {
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x89;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*HOLD ADDRESS in REGISTER: display's address which is calculated by IPU, is stored in register */
    else if (!strcmp(opcode, "HLOA")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*Generic data, this data is attached with OR to 16 MSB of mapped address */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        // 1 0 1 0 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x14 | (af << 0);    //1-0-1-0-AF
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*HOLD ADDRESS in REGISTER: display's address which is calculated by IPU,
       is stored in register */
    else if (!strcmp(opcode, "WROA")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*Generic data, this data is attached with OR to 16 MSB of mapped address */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        // 1 0 1 0 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x1C | (af << 0);    //1-1-1-0-AF
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*HOLD DATA in REGISTER */
    else if (!strcmp(opcode, "HLOD")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*Generic data, this data is attached with OR to 16 MSB of mapped address */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        opcode_fixed = 0x10;    //1-0-0-0-0
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*WRG - Write 24bit word to DI and Hold the word in register
       WRITE WORD GENERIC
       This opcode is used for sending "a user's code", which is stored in microcode memory
       to  a display,NO MAPPING */
    else if (!strcmp(opcode, "WRG")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (operand << 15);    //[31:15]

        HighWord = HighWord | (operand >> 17);  //[38:32]
        opcode_fixed = 1;       //0-1
        HighWord = HighWord | (opcode_fixed << 7);  //[40:39]
        HighWord = HighWord | (stop << 9);  //[41]
    }
    /*RD - Read command parameters: */
    else if (!strcmp(opcode, "RD")) {
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        LowWord = LowWord | (mapping << 15);    //[19:15]
        /*operand - means delay value in DI_CLK for display's data latching by DI,
           defined by user. number of IPU's clock to latch data from DI. after WSTS cycle start */
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x88;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]

    }
    /*WAIT FOR ACKNOWLEDGE */
    else if (!strcmp(opcode, "WACK")) {
        mapping = 0;            //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //operand - means delay value in DI_CLK for display's data latching by DI, defined by user
        //number of IPU's clock to latch data from DI. after WSTS cycle start
        LowWord = LowWord | (operand << 20);    //[31:20]

        opcode_fixed = 0x11A;   //
        HighWord = HighWord | (opcode_fixed << 0);  //[40:32]
        HighWord = HighWord | (stop << 9);  //[41]

    }
    /*HMA  - HOLD_MICROCODE_ADDRESS - hold operand in special Microcode address register */
    else if (!strcmp(opcode, "HMA")) {
        //[4:0]
        //Microcode address defined by user
        LowWord = LowWord | (operand << 5); //[12:5]
        opcode_fixed = 0x2;     //
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]

    }
    /*BMA  - BRANCH_MICROCODE_ADDRESS jump to Microcode address which is stored at
       special Microcode address register */
    else if (!strcmp(opcode, "BMA")) {
        opcode_fixed = 0x3;     //
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]

    }
    /*Additional information for event masking */
    else if (!strcmp(opcode, "MSK")) {
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        stop = 0;               //fixed
        //(no mapping)
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        //[32-28] - 0
        //[27] e0m- event 0 mask, defined by user
        //[26] e1m - event 1 mask, defined by user
        //[25] e2m - event 2 mask, defined by user
        //[24] e3m - event 3 mask, defined by user
        //[23] nfm- new frame mask , defined by user
        //[22] nlm- new line mask , defined by user
        //[21] nfldm- new field mask , defined by user
        //[20] eofm- end of frame mask, defined by user
        //[19] eolm- end of line mask, defined by user
        //[18] eofldm-  end of field mask, defined by user
        //[17] nadm- new address mask, defined by user
        //[16] ncm- new channel mask, defined by user
        //[15] dm - data mask, defined by user
        LowWord = LowWord | (operand << 15);    //[19:15]
        HighWord = HighWord | (operand >> 17);  //[32]
        opcode_fixed = 0xC8;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]

    }

    if (ipu_index == 1) {
        reg32_write(IPU1_CTRL_BASE_ADDR + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8, LowWord);
        reg32_write(IPU1_CTRL_BASE_ADDR + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8 + 4, HighWord);
    } else if (ipu_index == 2) {
        reg32_write(IPU2_CTRL_BASE_ADDR + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8, LowWord);
        reg32_write(IPU2_CTRL_BASE_ADDR + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8 + 4, HighWord);
    } else {
        printf("wrong ipu index %d\n", ipu_index);
    }
}

void microcode_event(int ipu_index, char channel[1], char event[8], int priority, int address)
{
    if (!strcmp(channel, "0")) {
        if (!strcmp(event, "NL")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_0__COD_NL_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_0__COD_NL_PRIORITY_CHAN_0, priority);
        }                       //NL
        else if (!strcmp(event, "NF")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_0__COD_NF_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_0__COD_NF_PRIORITY_CHAN_0, priority);
        }                       //NF
        else if (!strcmp(event, "NFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_0__COD_NFIELD_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_0__COD_NFIELD_PRIORITY_CHAN_0, priority);
        }                       //NFIELD
        else if (!strcmp(event, "EOF")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_0__COD_EOF_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_0__COD_EOF_PRIORITY_CHAN_0, priority);
        }                       //EOF
        else if (!strcmp(event, "EOFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_0__COD_EOFIELD_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_0__COD_EOFIELD_PRIORITY_CHAN_0, priority);
        }                       //EOFIELD
        else if (!strcmp(event, "EOL")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_0__COD_EOL_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_0__COD_EOL_PRIORITY_CHAN_0, priority);
        }                       //EOL
        else if (!strcmp(event, "NEW_CHAN")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_0__COD_NEW_CHAN_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_0__COD_NEW_CHAN_PRIORITY_CHAN_0, priority);
        }                       //NEW_CHAN
        else if (!strcmp(event, "NEW_ADDR")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_0__COD_NEW_ADDR_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_0__COD_NEW_ADDR_PRIORITY_CHAN_0, priority);
        }                       //NEW_ADDR
        else if (!strcmp(event, "NEW_DATA")) {
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_0__COD_NEW_DATA_START_CHAN_0, address);
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_0__COD_NEW_DATA_PRIORITY_CHAN_0, priority);
        }                       //NEW_DATA
    } else if (!strcmp(channel, "1")) {
        if (!strcmp(event, "NL")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_1__COD_NL_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_1__COD_NL_PRIORITY_CHAN_1, priority);
        }                       //NL
        else if (!strcmp(event, "NF")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_1__COD_NF_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_1__COD_NF_PRIORITY_CHAN_1, priority);
        }                       //NF
        else if (!strcmp(event, "NFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_1__COD_NFIELD_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_1__COD_NFIELD_PRIORITY_CHAN_1, priority);
        }                       //NFIELD
        else if (!strcmp(event, "EOF")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_1__COD_EOF_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_1__COD_EOF_PRIORITY_CHAN_1, priority);
        }                       //EOF
        else if (!strcmp(event, "EOFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_1__COD_EOFIELD_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_1__COD_EOFIELD_PRIORITY_CHAN_1, priority);
        }                       //EOFIELD
        else if (!strcmp(event, "EOL")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_1__COD_EOL_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_1__COD_EOL_PRIORITY_CHAN_1, priority);
        }                       //EOL
        else if (!strcmp(event, "NEW_CHAN")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_1__COD_NEW_CHAN_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_1__COD_NEW_CHAN_PRIORITY_CHAN_1, priority);
        }                       //NEW_CHAN
        else if (!strcmp(event, "NEW_ADDR")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_1__COD_NEW_ADDR_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_1__COD_NEW_ADDR_PRIORITY_CHAN_1, priority);
        }                       //NEW_ADDR
        else if (!strcmp(event, "NEW_DATA")) {
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_1__COD_NEW_DATA_START_CHAN_1, address);
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_1__COD_NEW_DATA_PRIORITY_CHAN_1, priority);
        }                       //NEW_DATA
    } else if (!strcmp(channel, "2")) {
        if (!strcmp(event, "NL")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_2__COD_NL_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_2__COD_NL_PRIORITY_CHAN_2, priority);
        }                       //NL
        else if (!strcmp(event, "NF")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_2__COD_NF_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_2__COD_NF_PRIORITY_CHAN_2, priority);
        }                       //NF
        else if (!strcmp(event, "NFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_2__COD_NFIELD_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_2__COD_NFIELD_PRIORITY_CHAN_2, priority);
        }                       //NFIELD
        else if (!strcmp(event, "EOF")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_2__COD_EOF_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_2__COD_EOF_PRIORITY_CHAN_2, priority);
        }                       //EOF
        else if (!strcmp(event, "EOFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_2__COD_EOFIELD_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_2__COD_EOFIELD_PRIORITY_CHAN_2, priority);
        }                       //EOFIELD
        else if (!strcmp(event, "EOL")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_2__COD_EOL_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_2__COD_EOL_PRIORITY_CHAN_2, priority);
        }                       //EOL
        else if (!strcmp(event, "NEW_CHAN")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_2__COD_NEW_CHAN_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_2__COD_NEW_CHAN_PRIORITY_CHAN_2, priority);
        }                       //NEW_CHAN
        else if (!strcmp(event, "NEW_ADDR")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_2__COD_NEW_ADDR_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_2__COD_NEW_ADDR_PRIORITY_CHAN_2, priority);
        }                       //NEW_ADDR
        else if (!strcmp(event, "NEW_DATA")) {
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_2__COD_NEW_DATA_START_CHAN_2, address);
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_2__COD_NEW_DATA_PRIORITY_CHAN_2, priority);
        }                       //NEW_DATA
    } else if (!strcmp(channel, "5")) {
        if (!strcmp(event, "NL")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_5__COD_NL_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_5__COD_NL_PRIORITY_CHAN_5, priority);
        }                       //NL
        else if (!strcmp(event, "NF")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_5__COD_NF_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_5__COD_NF_PRIORITY_CHAN_5, priority);
        }                       //NF
        else if (!strcmp(event, "NFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_5__COD_NFIELD_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_5__COD_NFIELD_PRIORITY_CHAN_5, priority);
        }                       //NFIELD
        else if (!strcmp(event, "EOF")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_5__COD_EOF_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_5__COD_EOF_PRIORITY_CHAN_5, priority);
        }                       //EOF
        else if (!strcmp(event, "EOFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_5__COD_EOFIELD_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_5__COD_EOFIELD_PRIORITY_CHAN_5, priority);
        }                       //EOFIELD
        else if (!strcmp(event, "EOL")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_5__COD_EOL_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_5__COD_EOL_PRIORITY_CHAN_5, priority);
        }                       //EOL
        else if (!strcmp(event, "NEW_CHAN")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_5__COD_NEW_CHAN_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_5__COD_NEW_CHAN_PRIORITY_CHAN_5, priority);
        }                       //NEW_CHAN
        else if (!strcmp(event, "NEW_ADDR")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_5__COD_NEW_ADDR_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_5__COD_NEW_ADDR_PRIORITY_CHAN_5, priority);
        }                       //NEW_ADDR
        else if (!strcmp(event, "NEW_DATA")) {
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_5__COD_NEW_DATA_START_CHAN_5, address);
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_5__COD_NEW_DATA_PRIORITY_CHAN_5, priority);
        }                       //NEW_DATA
    } else if (!strcmp(channel, "6")) {

        if (!strcmp(event, "NL")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_6__COD_NL_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_6__COD_NL_PRIORITY_CHAN_6, priority);
        }                       //NL
        else if (!strcmp(event, "NF")) {
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_6__COD_NF_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL0_CH_6__COD_NF_PRIORITY_CHAN_6, priority);
        }                       //NF
        else if (!strcmp(event, "NFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_6__COD_NFIELD_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_6__COD_NFIELD_PRIORITY_CHAN_6, priority);
        }                       //NFIELD
        else if (!strcmp(event, "EOF")) {
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_6__COD_EOF_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL1_CH_6__COD_EOF_PRIORITY_CHAN_6, priority);
        }                       //EOF
        else if (!strcmp(event, "EOFIELD")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_6__COD_EOFIELD_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_6__COD_EOFIELD_PRIORITY_CHAN_6, priority);
        }                       //EOFIELD
        else if (!strcmp(event, "EOL")) {
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_6__COD_EOL_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL2_CH_6__COD_EOL_PRIORITY_CHAN_6, priority);
        }                       //EOL
        else if (!strcmp(event, "NEW_CHAN")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_6__COD_NEW_CHAN_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_6__COD_NEW_CHAN_PRIORITY_CHAN_6, priority);
        }                       //NEW_CHAN
        else if (!strcmp(event, "NEW_ADDR")) {
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_6__COD_NEW_ADDR_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL3_CH_6__COD_NEW_ADDR_PRIORITY_CHAN_6, priority);
        }                       //NEW_ADDR
        else if (!strcmp(event, "NEW_DATA")) {
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_6__COD_NEW_DATA_START_CHAN_6, address);
            ipu_write_field(ipu_index, IPU_DC_RL4_CH_6__COD_NEW_DATA_PRIORITY_CHAN_6, priority);
        }                       //NEW_DATA
    }                           //channel 6
}                               //microcode_event

/*!
* this function is used to config the color space conversion task in the DP
* @param ipu_index: ipu index, 1 or 2
* @param dp: dp params index
* @param dp_csc_params: csc conversion matrix
*/
void ipu_dp_csc_config(int ipu_index, int dp, dp_csc_param_t dp_csc_params)
{
    int (*coeff)[3];
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_YUV_SAT_MODE_SYNC, 0);  //SAT mode is zero
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_GAMUT_SAT_EN_SYNC, 0);  //GAMUT en (RGB...)

    if (dp_csc_params.mode >= 0) {
        ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_CSC_DEF_SYNC, dp_csc_params.mode);  //disable CSC
    }

    coeff = (void *)dp_csc_params.coeff;

    if (coeff) {
        writel(GET_LSB(10, coeff[0][0]) | (GET_LSB(10, coeff[0][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[0][2]) | (GET_LSB(10, coeff[1][0]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_1__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[1][1]) | (GET_LSB(10, coeff[1][2]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_2__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[2][0]) | (GET_LSB(10, coeff[2][1]) << 16),
               ipu_base_addr + SRM_DP_CSCA_SYNC_3__ADDR + dp * 4);
        writel(GET_LSB(10, coeff[2][2]) | (GET_LSB(14, coeff[3][0]) << 16) |
               (coeff[4][0] << 30), ipu_base_addr + SRM_DP_CSC_SYNC_0__ADDR + dp * 4);
        writel(GET_LSB(14, coeff[3][1]) | (coeff[4][1] << 14) |
               (GET_LSB(14, coeff[3][2]) << 16) | (coeff[4][2] << 30),
               ipu_base_addr + SRM_DP_CSC_SYNC_1__ADDR + dp * 4);
    }

    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_S_SRM_MODE, 3);
    ipu_write_field(ipu_index, IPU_IPU_SRM_PRI2__DP_SRM_PRI, 0x0);
}

/*!
* this function is used to config the foreground plane for combination in the DP
* @param ipu_index: ipu index
* @param foreground_params: params for the foreground, including offset and size
*/
void ipu_dp_fg_config(int ipu_index, dp_fg_param_t foreground_params)
{
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_EN_SYNC, 0);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GAMMA_YUV_EN_SYNC, 0);

    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_COC_SYNC, foreground_params.cursorEnable);
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWCKE_SYNC, foreground_params.colorKeyEnable);  //color key
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWAM_SYNC, foreground_params.alphaMode);    //1=global alpha,0=local alpha
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_GWSEL_SYNC, foreground_params.graphicSelect);   //1=graphic is FG,0=graphic is BG
    ipu_write_field(ipu_index, SRM_DP_COM_CONF_SYNC__DP_FG_EN_SYNC, foreground_params.fgEnable);    //1=FG channel enabled,0=FG channel disabled
    ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGXP_SYNC, foreground_params.offsetHoriz);
    ipu_write_field(ipu_index, SRM_DP_FG_POS_SYNC__DP_FGYP_SYNC, foreground_params.offsetVert);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, foreground_params.opaque);    // set the FG opaque
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKR_SYNC, 0xFF);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKG_SYNC, 0xFF);
    ipu_write_field(ipu_index, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWCKB_SYNC, 0xFF);
}

/*!
 * config the DP module, mainly to perform blending, CSC and gamma correction
 *
 * @param	ipu_index: ipu index
 * @param 	cscEn: 	enable or disable the CSC module
 */
void dp_config(int ipu_index, int cscen, int cscmode)
{
    dp_fg_param_t dpFGParam = { 0 };
    dp_csc_param_t dpCSCParam = { 0 };

    /*  Y = R *  .299 + G *  .587 + B *  .114;
       U = R * -.169 + G * -.332 + B *  .500 + 128.;
       V = R *  .500 + G * -.419 + B * -.0813 + 128.; */
    int rgb2ycbcr_coeff[5][3] = {
        {0x04D, 0x096, 0x01D},
        {0x3D5, 0x3AB, 0x080},
        {0x080, 0x395, 0x3EB},
        {0x0000, 0x0200, 0x0200},
        {0x2, 0x2, 0x2},
    };

    /* R = (1.164 * (Y - 16)) + (1.596 * (Cr - 128));
       G = (1.164 * (Y - 16)) - (0.392 * (Cb - 128)) - (0.813 * (Cr - 128));
       B = (1.164 * (Y - 16)) + (2.017 * (Cb - 128); */
    int ycbcr2rgb_coeff[5][3] = {
        {0x4A, 0x0, 0x66},
        {0x4A, 0x3E7, 0x3CC},
        {0x4A, 0x81, 0x0},
        {0x3F22, 0x85, 0x3EEB}, // A0, A1, A2
        {0x0, 0x0, 0x0},        /*S0,S1,S2 */
    };

    dpFGParam.fgEnable = 0;
    dpFGParam.cursorEnable = 0;
    dpFGParam.colorKeyEnable = 0;
    dpFGParam.offsetHoriz = 0;
    dpFGParam.offsetVert = 0;
    dpFGParam.alphaMode = 1;    // 1-  global alpha
    dpFGParam.graphicSelect = 0;    // graphic is forground
    dpFGParam.opaque = 0x30;    //show background

    ipu_dp_fg_config(ipu_index, dpFGParam);

    /********************************************
    00	CSC disable
    01	CSC enable after combining
    10	CSC enable before combining on BG channel
    11	CSC enable before combining on FG channel
    *******************************************/
    dpCSCParam.mode = cscen;

    if (cscmode = RGB2YUV) {
        dpCSCParam.coeff = rgb2ycbcr_coeff;
    } else if (cscmode = YUV2RGB) {
        dpCSCParam.coeff = ycbcr2rgb_coeff;
    }

    ipu_dp_csc_config(ipu_index, 0, dpCSCParam);
}
