/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "flexcan/flexcan.h"
#include "registers/regsflexcan.h"


//! possible time segment settings for propseg, pseg1, pseg2
static struct time_segment time_segments[18] = {
    {1, 2, 1},  /* 0: total 8 timequanta */
    {1, 2, 2},  /* 1: total 9 timequanta */
    {2, 2, 2},  /* 2: total 10 timequanta */
    {2, 2, 3},  /* 3: total 11 timequanta */
    {2, 3, 3},  /* 4: total 12 timequanta */
    {3, 3, 3},  /* 5: total 13 timequanta */
    {3, 3, 4},  /* 6: total 14 timequanta */
    {3, 4, 4}, /* 7: total 15 timequanta */
    {4, 4, 4}, /* 8: total 16 timequanta */
    {4, 4, 5}, /* 9: total 17 timequanta */
    {4, 5, 5}, /* 10: total 18 timequanta */
    {5, 5, 5}, /* 11: total 19 timequanta */
    {5, 5, 6}, /* 12: total 20 timequanta */
    {5, 6, 6}, /* 13: total 21 timequanta */
    {6, 6, 6}, /* 14: total 22 timequanta */
    {6, 6, 7}, /* 15: total 23 timequanta */
    {6, 7, 7}, /* 16: total 24 timequanta */
    {7, 7, 7} /* 17: total 25 timequanta */
};

void can_init(struct hw_module *port, uint32_t max_mb)
{
    uint32_t instance = port->instance;
    uint32_t ctl;
    int i;

    /* configure the I/O for the port */
    hw_can_iomux_config(instance);

    can_sw_reset(port);         //software reset

    ctl = HW_FLEXCAN_MCR_RD(instance);
    ctl &= ~BM_FLEXCAN_MCR_MAXMB;    	//clear MAXMB field
    ctl |= BF_FLEXCAN_MCR_MAXMB(max_mb);     	// set MAXMB field (0-63)
    HW_FLEXCAN_MCR_WR(instance, ctl);
    ctl &= ~BM_FLEXCAN_MCR_MDIS;
    HW_FLEXCAN_MCR_WR(instance, ctl);

    // Programming the bit timing segments"
    HW_FLEXCAN_CTRL_WR(instance, (CAN_TIMING_PARAMETERS << 16));

    // initialize MBs to zero
    for (i = 0; i < CAN_NUMBER_OF_BUFFERS; i++) {
        set_can_mb(port, i, 0, 0, 0, 0);
    }

    // disable all MB interrupts
    HW_FLEXCAN_IMASK1_WR(instance, 0);
    HW_FLEXCAN_IMASK2_WR(instance, 0);
}

void can_set_can_attributes(struct imx_flexcan *can_module, uint32_t bitrate, struct hw_module *hw_port)
{
    can_module->bitrate = bitrate;
    can_module->port = hw_port;
}

void can_update_bitrate(struct imx_flexcan *can_module)
{
    uint32_t instance = can_module->port->instance;
    unsigned int can_PE_CLK = can_module->port->freq;  //can protocol engine clock, input from CCM
    unsigned int temp;
    
    if (can_PE_CLK == 30000000){
        switch (can_module->bitrate){
            case MBPS_1: // 
                can_module->presdiv = 1; // sets sclk ftq to 15MHz = PEclk/2
                can_module->ts = time_segments[7]; // 15 time quanta (15-8=7 for array ID)
                break;
            case KBPS_800:
                can_module->presdiv = 1; // sets sclk ftq to 15MHz = PEclk/2
                can_module->ts = time_segments[11]; // 19 time quanta (19-8=11 for array ID)
                break;
            case KBPS_500:
                can_module->presdiv = 2; // sets sclk ftq to 10MHz = PEclk/3
                can_module->ts = time_segments[12]; // 20 time quanta (20-8=12 for array ID) 
                break;   
            case KBPS_250:
                can_module->presdiv = 4; // sets sclk ftq to 6MHz = PEclk/5
                can_module->ts = time_segments[16]; // 24 time quanta (24-8=16 for array ID) 
                break;
            case KBPS_125:
                can_module->presdiv = 9; // sets sclk ftq to 3MHz = PEclk/10
                can_module->ts = time_segments[16]; // 24 time quanta (24-8=16 for array ID)
                break;
            case KBPS_62:  //62.5kps 
                can_module->presdiv = 19; // sets sclk ftq to 1.5MHz = PEclk/20
                can_module->ts = time_segments[16]; // 24 time quanta (24-8=16 for array ID)
                break;
            case KBPS_20:
                can_module->presdiv = 59; // sets sclk ftq to 500KHz = PEclk/60
                can_module->ts = time_segments[17]; // 25 time quanta (25-8=17 for array ID)
                break;
            case KBPS_10:
                can_module->presdiv = 119; // sets sclk ftq to 500KHz = PEclk/60
                can_module->ts = time_segments[17]; // 25 time quanta (25-8=17 for array ID)
                break;
            default:
                printf("CAN bitrate not supported\n");
                break;       
        }
    }
    else { printf("CAN PE_CLK input to CAN module speed not supported\n");}
    
    // Update the the bit timing segments
    temp = HW_FLEXCAN_CTRL_RD(instance) & CAN_TIMING_MASK;
    temp += (can_module->presdiv <<24) + (can_module->ts.pseg1 <<19) + (can_module->ts.pseg2 <<16) + (can_module->ts.propseg); 
    HW_FLEXCAN_CTRL_WR(instance, temp);
}

void can_sw_reset(struct hw_module *port)
{
    uint32_t instance = port->instance, val;

    val = HW_FLEXCAN_MCR_RD(instance);
    val |= BF_FLEXCAN_MCR_SOFT_RST(1);
    HW_FLEXCAN_MCR_WR(instance, val);
    while (HW_FLEXCAN_MCR_RD(instance) & BF_FLEXCAN_MCR_SOFT_RST(1)) ;  // poll until complete
}

void set_can_mb(struct hw_module *port, uint32_t mbID, uint32_t cs, uint32_t id, uint32_t data0,
                uint32_t data1)
{
    volatile struct can_message_buffers *can_mb =
        (volatile struct can_message_buffers *)(port->base + CAN_MB_OFFSET);

    can_mb->MB[mbID].cs = cs;
    can_mb->MB[mbID].id = id;
    can_mb->MB[mbID].data0 = data0;
    can_mb->MB[mbID].data1 = data1;
}
void print_can_mb(struct hw_module *port, uint32_t mbID)
{
    volatile struct can_message_buffers *can_mb =
        (volatile struct can_message_buffers *)(port->base + CAN_MB_OFFSET);
    printf("\tMB[%d].cs    = 0x%x\n", mbID, can_mb->MB[mbID].cs);
    printf("\tMB[%d].id    = 0x%x\n", mbID, can_mb->MB[mbID].id);
    printf("\tMB[%d].data0 = 0x%x\n", mbID, can_mb->MB[mbID].data0);
    printf("\tMB[%d].data1 = 0x%x\n\n", mbID, can_mb->MB[mbID].data1);
}

void can_enable_mb_interrupt(struct hw_module *port, uint32_t mbID)
{
    uint32_t instance = port->instance, val;

    if (mbID < 32) {
	val = HW_FLEXCAN_IMASK1_RD(instance);
 	val |= (1 << mbID);
	HW_FLEXCAN_IMASK1_WR(instance, val);
    } else if (mbID < 64) {
	val = HW_FLEXCAN_IMASK2_RD(instance);
 	val |= (1 << (mbID - 32));
	HW_FLEXCAN_IMASK1_WR(instance, val);
    }
}

void can_disable_mb_interrupt(struct hw_module *port, uint32_t mbID)
{
    uint32_t instance = port->instance, val;

    if (mbID < 32) {
	val = HW_FLEXCAN_IMASK1_RD(instance);
 	val &= ~(1 << mbID);
	HW_FLEXCAN_IMASK1_WR(instance, val);
    } else if (mbID < 64) {
	val = HW_FLEXCAN_IMASK2_RD(instance);
 	val &= ~(1 << (mbID - 32));
	HW_FLEXCAN_IMASK1_WR(instance, val);
    }
}

void can_exit_freeze(struct hw_module *port)
{
    uint32_t instance = port->instance, val;

    val = HW_FLEXCAN_MCR_RD(instance);
    val &= ~BM_FLEXCAN_MCR_FRZ;
    HW_FLEXCAN_MCR_WR(instance, val);
}

void can_freeze(struct hw_module *port)
{
    uint32_t instance = port->instance, val;

    val = HW_FLEXCAN_MCR_RD(instance);
    val |= BM_FLEXCAN_MCR_FRZ;
    HW_FLEXCAN_MCR_WR(instance, val);
}

uint64_t can_mb_int_flag(struct hw_module *port)
{
    uint32_t instance = port->instance;
    uint64_t val;

    val = (uint64_t)HW_FLEXCAN_IFLAG2_RD(instance);
    val <<= 32;
    val |=(uint64_t)HW_FLEXCAN_IFLAG1_RD(instance);	

    return val;
}

void can_mb_int_ack(struct hw_module *port, uint32_t mbID)
{
    uint32_t instance = port->instance;
    uint32_t val;

    if(mbID < 32){
    	val = HW_FLEXCAN_IFLAG1_RD(instance);
    	val |= (0x01 << mbID);
	HW_FLEXCAN_IFLAG1_WR(instance, val);
    }else{
    	val = HW_FLEXCAN_IFLAG2_RD(instance);	
    	val |= (0x01 << (mbID - 32));
	HW_FLEXCAN_IFLAG2_WR(instance, val);
    }
}
