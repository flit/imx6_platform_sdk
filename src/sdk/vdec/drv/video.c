/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "video.h"
#include "interrupt.h"
#include "io.h"
#include "../../usdhc/inc/usdhc_ifc.h"

#define BITSTREAM_BUF_SIZE      (0x800000)
#define VPU_BUFFERS_NUM         (32)
#define BUFFER_QUEUE_MIN_SIZE   (4)

/*********** Global Variables ************/

DecHandle pDec[MAX_INSTANCES];
DecParam param;
VPUframesFifo fifo[MAX_INSTANCES];
uint32_t bitstream_buffer[MAX_INSTANCES];
uint32_t ipu_eba[MAX_INSTANCES][2];
FrameBuffer buffers[MAX_INSTANCES][VPU_BUFFERS_NUM];
int curInst, switchInst, currentlyDecoding, vdoa_buf;
int activeInstances[MAX_INSTANCES];

/*****************************************/

int vpu_buffer_fill(uint32_t inst, uint32_t addr, uint32_t size);   /* this function should be implemented in the calling code */
int ipu_refresh(uint32_t *);

void fifoInit(VPUframesFifo * fifo, int size)
{
    fifo->size = size;
    fifo->wrptr = 0;
    fifo->rdptr = 0;
    fifo->full = 0;
    fifo->popCnt = 0;
}

int fifoFull(VPUframesFifo * fifo)
{
    return (fifo->full);
}

int fifoEmpty(VPUframesFifo * fifo)
{
    return ((fifo->rdptr == fifo->wrptr) && !(fifo->full));
}

/*one frame is in-queued*/
int fifoPush(VPUframesFifo * fifo, uint32_t frame, uint32_t ts)
{
    if (fifo->full)
        return -1;

    fifo->frames[fifo->wrptr] = frame;
    fifo->timeStamp[fifo->wrptr] = ts;

    if (++fifo->wrptr == fifo->size)
        fifo->wrptr = 0;

    if (fifo->wrptr == fifo->rdptr)
        fifo->full = 1;

    return 0;
}

/*one frame is dequeued*/
int fifoPop(VPUframesFifo * fifo, uint32_t * frame, uint32_t * ts, uint32_t * id)
{
    if ((fifo->rdptr == fifo->wrptr) && !(fifo->full))
        return -1;

    *frame = fifo->frames[fifo->rdptr];
    *ts = fifo->timeStamp[fifo->rdptr];
    *id = fifo->popCnt++;

    if (++fifo->rdptr == fifo->size)
        fifo->rdptr = 0;

    if (fifo->full)
        fifo->full = 0;

    return 0;
}

/*PIC_RUN interrupt occured*/
void vpu_decode_isr(void)
{
    PhysicalAddress rptr, wptr;
    uint32_t size;
    uint32_t fill_size, fill_addr;
    DecOutputInfo decout;
    VPU_ClearInterrupt();
    VPU_DecGetOutputInfo(pDec[curInst], &decout);

    if (decout.indexFrameDisplay >= 0)
        fifoPush(&fifo[curInst], buffers[curInst][decout.indexFrameDisplay].bufY & 0xfffff000, 0);

    VPU_DecGetBitstreamBuffer(pDec[curInst], &rptr, &wptr, &size);

    if (size > (BITSTREAM_BUF_SIZE >> 2)) {
        size = BITSTREAM_BUF_SIZE >> 2;
        if ((wptr == (bitstream_buffer[curInst] + BITSTREAM_BUF_SIZE))) {
            fill_addr = bitstream_buffer[curInst];
            fill_size = size & 0xfffff000;
        } else {
            fill_addr = wptr;
            if (((size & 0xfffff000) + wptr) > (bitstream_buffer[curInst] + BITSTREAM_BUF_SIZE))
                fill_size = bitstream_buffer[curInst] + BITSTREAM_BUF_SIZE - wptr;
            else
                fill_size = size & 0xfffff000;
        }
        if (vpu_buffer_fill(curInst, fill_addr, fill_size))
            VPU_DecUpdateBitstreamBuffer(pDec[curInst], fill_size);
    }

    /* Find the next instance to decode. If there's only one - will loop back to it.
       All the instance will be actived in RR mode. */
    if (switchInst) {
        while (!(activeInstances[++curInst]))
            if (curInst == (MAX_INSTANCES - 1)) {
                curInst = 0;
                if (activeInstances[curInst])
                    break;
            }
    }

    if (fifoFull(&fifo[curInst])) {
        //the fifo is full, vpu should wait for its clearing.
        currentlyDecoding = 0;
    } else {
        VPU_DecStartOneFrame(pDec[curInst], &param);
    }
}

void epit_vpu_isr(void)
{
    uint32_t ts, id;
    uint32_t buffer[MAX_INSTANCES];
    int i;

    reg32_write(EPIT2_BASE_ADDR + EPIT_EPITSR_OFFSET, 0x1);

    for (i = 0; i < MAX_INSTANCES; ++i) {
        if (activeInstances[i]) {
            if (fifoPop(&fifo[i], &buffer[i], &ts, &id) == -1)
                printf("VPU instance %d fifo underrun...\n", i);
        }
    }

    ipu_refresh(buffer);

    /*Now FIFO is non-full, active the VPU for decoding */
    if (!currentlyDecoding) {
        VPU_DecStartOneFrame(pDec[curInst], &param);
        currentlyDecoding = 1;
    }
}

struct hw_module vpu_mod = {
    "VPU for enc/dec",
    VPU_BASE_ADDR,
    200000000,
    IMX_INT_VPU_IPI,
    &vpu_decode_isr,
};

struct hw_module epit2 = {
    "EPIT for video control",
    EPIT2_BASE_ADDR,
    32768,
    IMX_INT_EPIT2,
    &epit_vpu_isr,
};

extern volatile unsigned int usdhc_busy;
void video_setup(int inst, int use_vdoa, uint32_t buffers_base, video_params * vpu_params)
{
    DecInitialInfo decInfo;
    DecOpenParam openParams;
    SecAxiUse secAxi;
    int i, fifo_size;

    if (inst == 0)
        for (i = 0; i < MAX_INSTANCES; activeInstances[i++] = 0) ;

    //capture_interrupt(IMX_INT_VPU_IPI, vpu_decode_isr, CPU_0);
    register_interrupt_routine(vpu_mod.irq_id, vpu_mod.irq_subroutine);
    enable_interrupt(vpu_mod.irq_id, CPU_0, 0);

    switchInst = 0;
    curInst = inst;

    /* initialize bitstream */
    bitstream_buffer[inst] = buffers_base;
    openParams.bitstreamFormat = STD_H264;
    openParams.bitstreamBuffer = bitstream_buffer[inst];
    openParams.bitstreamBufferSize = BITSTREAM_BUF_SIZE;
    openParams.mp4DeblkEnable = 0;
    openParams.reorderEnable = 1;
    openParams.filePlayEnable = 0;
    openParams.dynamicBuffAllocEnable = 0;
    openParams.picWidth = 0;
    openParams.picHeight = 0;
    openParams.streamStartByteOffset = 0;
    openParams.mjpg_thumbNailDecEnable = 0;
    openParams.psSaveBuffer = 0;
    openParams.psSaveBufferSize = 0;
    openParams.mp4Class = 0;
    openParams.vc1AnnexL3MetaDisable = 0;
    openParams.mapType = use_vdoa;  /* mapType should be 1 if vdoa is used (tiled format) */
    openParams.tiled2LinearEnable = 0;

    vpu_buffer_fill(inst, bitstream_buffer[inst], BITSTREAM_BUF_SIZE);

    /*wait untill the buffer is filled */
    int usdhc_status = 0;
    while (1) {
        card_xfer_result(SD_PORT_BASE_ADDR, &usdhc_status);
        if (usdhc_status == 1)  //transfer complete
            break;
    }

    VPU_DecOpen(&pDec[inst], &openParams);
    VPU_DecGetInitialInfo(pDec[inst], &decInfo);

    /* set up secondary AXI bus */
    secAxi.useBitEnable = 1;
    secAxi.useIpEnable = 1;
    secAxi.useOvlEnable = 1;
    secAxi.useDbkYEnable = 1;
    secAxi.useDbkCEnable = 1;
    secAxi.useBtpEnable = 1;
    secAxi.useHostBitEnable = 1;
    secAxi.useHostIpEnable = 1;
    secAxi.useHostOvlEnable = 1;
    secAxi.useHostDbkYEnable = 1;
    secAxi.useHostDbkCEnable = 1;
    secAxi.useHostBtpEnable = 1;
    secAxi.bufBitUse = OFFSET_AXI_BIT;
    secAxi.bufIpAcDcUse = OFFSET_AXI_IP;
    secAxi.bufDbkYUse = OFFSET_AXI_DBKY;
    secAxi.bufDbkCUse = OFFSET_AXI_DBKC;
    secAxi.bufOvlUse = OFFSET_AXI_OVL;
    secAxi.bufBtpUse = OFFSET_AXI_BTP;
    VPU_DecGiveCommand(pDec[inst], SET_SEC_AXI, (void *)&secAxi);

    /* setup buffers, here we are using maximum buffers.
       the actual buffer number can be got from the initial information */
    buffers[inst][0].bufY = buffers_base + BITSTREAM_BUF_SIZE;
    VPU_DecRegisterFrameBuffer(pDec[inst], buffers[inst], VPU_BUFFERS_NUM, FRAME_MAX_WIDTH, NULL);

    fifo_size = VPU_BUFFERS_NUM - (decInfo.minFrameBufferCount /*+ decInfo.frameBufDelay */  + 4);
    if (fifo_size < BUFFER_QUEUE_MIN_SIZE) {
        printf("Buffer for output is not enough, total %d buffers!!", fifo_size);
        return;
    }
    fifoInit(&fifo[inst], fifo_size);

    VPU_EnableInterrupt(PIC_RUN_COMPLETE);

    /* fill fifo with decoded frames */
    param.prescanEnable = 0;
    param.prescanMode = 0;
    param.dispReorderbuf = 0;
    param.iframeSearchEnable = 0;
    param.skipframeMode = 0;
    param.skipframeNum = 0;
    param.picStreamBufferAddr = 0;
    param.picStartByteOffset = 0;
    param.chunkSize = 0;
    VPU_DecStartOneFrame(pDec[inst], &param);
    while (!(fifoFull(&fifo[inst]))) ;

    if (use_vdoa) {
        //TBD
    } else {
        vpu_params->u_offset = buffers[inst][0].bufCb - buffers[inst][0].bufY;
        vpu_params->v_offset = buffers[inst][0].bufCb - buffers[inst][0].bufY;
        register_interrupt_routine(epit2.irq_id, epit2.irq_subroutine);
        enable_interrupt(epit2.irq_id, CPU_0, 0);
    }

    /* Add by Ray: assume partially interleaved format,
       set the strideline to MAX to support non 1080p video playback without
       resizing the image */
    vpu_params->y_strideline = FRAME_MAX_WIDTH; //decInfo.picWidth;    
    vpu_params->uv_strideline = FRAME_MAX_WIDTH;    //decInfo.picWidth;
    vpu_params->frame_width = decInfo.picWidth;
    vpu_params->frame_height = decInfo.picHeight;

    activeInstances[inst] = 1;
    switchInst = 1;
    curInst = 0;
}
