/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "tmp_usdhc.h"

const uint32_t CommandTable[] = {
    /* CMD0 */ NO_RESP | NO_DATA,
    /* CMD1 */ R3_RESP | NO_DATA,
    /* CMD2 */ R2_RESP | NO_DATA,
    /* CMD3 */ R1_RESP | NO_DATA,
    /* CMD4 */ NO_RESP | NO_DATA,
    /* CMD5 */ R3_RESP | NO_DATA,
    /* CMD6 */ R1_RESP | NO_DATA,
    /* CMD7 */ R1b_RESP | NO_DATA,
    /* CMD8 */ R1_RESP | NO_DATA,
    /* CMD9 */ R2_RESP | NO_DATA,
    /* CMD10 */ R2_RESP | NO_DATA,
    /* CMD11 */ R1_RESP | NO_DATA,
    /* CMD12 */ R1b_RESP | NO_DATA | ABORT_CMD,
    /* CMD13 */ R1_RESP | NO_DATA,
    /* CMD14 */ R1_RESP | NO_DATA,
    /* CMD15 */ R1_RESP | NO_DATA,
    /* CMD16 */ R1_RESP | NO_DATA,
    /* CMD17 */ R1_RESP | DATA_PRESENT | DATA_READ,
    /* CMD18 */ R1_RESP | DATA_PRESENT | DATA_READ | MULTIPLE_BLOCKS | AUTO_CMD12,
    /* CMD19 */ R1_RESP | DATA_PRESENT | DATA_READ,
    /*NEEDS CHECK */
    /* CMD20 */ R1_RESP | DATA_PRESENT | DATA_WRITE,
    /*NEEDS CHECK */
    /* CMD21 */ R1_RESP | NO_DATA,
    /* CMD22 */ R1_RESP | NO_DATA,
    /* CMD23 */ R1_RESP | NO_DATA,
    /* CMD24 */ R1_RESP | DATA_PRESENT | DATA_WRITE,
    /* CMD25 */ R1_RESP | DATA_PRESENT | DATA_WRITE | MULTIPLE_BLOCKS | AUTO_CMD12,
    /* CMD26 */ R1_RESP | NO_DATA,
    /* CMD27 */ R1_RESP | NO_DATA,
    /* CMD28 */ R1b_RESP | NO_DATA,
    /* CMD29 */ R1b_RESP | NO_DATA,
    /* CMD30 */ R1_RESP | NO_DATA,
    /* CMD31 */ R1_RESP | NO_DATA,
    /* CMD32 */ R1_RESP | NO_DATA,
    /* CMD33 */ R1_RESP | NO_DATA,
    /* CMD34 */ R1_RESP | NO_DATA,
    /* CMD35 */ R1_RESP | NO_DATA,
    /* CMD36 */ R1_RESP | NO_DATA,
    /* CMD37 */ R1_RESP | NO_DATA,
    /* CMD38 */ R1b_RESP | NO_DATA,
    /* CMD39 */ R3_RESP | DATA_PRESENT | DATA_WRITE /*NEEDS CHECK */ ,
    /* CMD40 */ R1_RESP | NO_DATA,
    /* CMD41 */ R1_RESP | NO_DATA,
    /* CMD42 */ R1b_RESP | NO_DATA,
    /* CMD43 */ R1_RESP | NO_DATA,
    /* CMD44 */ R1_RESP | NO_DATA,
    /* CMD45 */ R1_RESP | NO_DATA,
    /* CMD46 */ R1_RESP | NO_DATA,
    /* CMD47 */ R1_RESP | NO_DATA,
    /* CMD48 */ R1_RESP | NO_DATA,
    /* CMD49 */ R1_RESP | NO_DATA,
    /* CMD50 */ R1_RESP | NO_DATA,
    /* CMD51 */ R1_RESP | NO_DATA,
    /* CMD52 */ R1_RESP | NO_DATA,
    /* CMD53 */ R1_RESP | DATA_PRESENT | DATA_WRITE,
    /* CMD54 */ R1_RESP | NO_DATA,
    /* CMD55 */ R1_RESP | NO_DATA,
    /* CMD56 */ R1b_RESP | DATA_PRESENT | DATA_WRITE,
    /* CMD57 */ R1_RESP | NO_DATA,
    /* CMD58 */ R1_RESP | NO_DATA,
    /* CMD59 */ R1_RESP | NO_DATA,
    /* CMD60 */ R1_RESP | NO_DATA,
    /* CMD61 */ R1_RESP | NO_DATA,
    /* CMD62 */ R1_RESP | NO_DATA,
    /* CMD63 */ R1_RESP | NO_DATA,
    /* ACMD0 */ R1_RESP | NO_DATA,
    /* ACMD1 */ R1_RESP | NO_DATA,
    /* ACMD2 */ R1_RESP | NO_DATA,
    /* ACMD3 */ R1_RESP | NO_DATA,
    /* ACMD4 */ R1_RESP | NO_DATA,
    /* ACMD5 */ R1_RESP | NO_DATA,
    /* ACMD6 */ R1_RESP | NO_DATA,
    /* ACMD7 */ R1_RESP | NO_DATA,
    /* ACMD8 */ R1_RESP | NO_DATA,
    /* ACMD9 */ R1_RESP | NO_DATA,
    /* ACMD10 */ R1_RESP | NO_DATA,
    /* ACMD11 */ R1_RESP | NO_DATA,
    /* ACMD12 */ R1_RESP | NO_DATA,
    /* ACMD13 */ R1_RESP | NO_DATA,
    /* ACMD14 */ R1_RESP | NO_DATA,
    /* ACMD15 */ R1_RESP | NO_DATA,
    /* ACMD16 */ R1_RESP | NO_DATA,
    /* ACMD17 */ R1_RESP | NO_DATA,
    /* ACMD18 */ R1_RESP | NO_DATA,
    /* ACMD19 */ R1_RESP | NO_DATA,
    /* ACMD20 */ R1_RESP | NO_DATA,
    /* ACMD21 */ R1_RESP | NO_DATA,
    /* ACMD22 */ R1_RESP | NO_DATA,
    /* ACMD23 */ R1_RESP | NO_DATA,
    /* ACMD24 */ R1_RESP | NO_DATA,
    /* ACMD25 */ R1_RESP | NO_DATA,
    /* ACMD26 */ R1_RESP | NO_DATA,
    /* ACMD27 */ R1_RESP | NO_DATA,
    /* ACMD28 */ R1_RESP | NO_DATA,
    /* ACMD29 */ R1_RESP | NO_DATA,
    /* ACMD30 */ R1_RESP | NO_DATA,
    /* ACMD31 */ R1_RESP | NO_DATA,
    /* ACMD32 */ R1_RESP | NO_DATA,
    /* ACMD33 */ R1_RESP | NO_DATA,
    /* ACMD34 */ R1_RESP | NO_DATA,
    /* ACMD35 */ R1_RESP | NO_DATA,
    /* ACMD36 */ R1_RESP | NO_DATA,
    /* ACMD37 */ R1_RESP | NO_DATA,
    /* ACMD38 */ R1_RESP | NO_DATA,
    /* ACMD39 */ R1_RESP | NO_DATA,
    /* ACMD40 */ R1_RESP | NO_DATA,
    /* ACMD41 */ R3_RESP | NO_DATA,
    /* ACMD42 */ R1_RESP | NO_DATA,
    /* ACMD43 */ R1_RESP | NO_DATA,
    /* ACMD44 */ R1_RESP | NO_DATA,
    /* ACMD45 */ R1_RESP | NO_DATA,
    /* ACMD46 */ R1_RESP | NO_DATA,
    /* ACMD47 */ R1_RESP | NO_DATA,
    /* ACMD48 */ R1_RESP | NO_DATA,
    /* ACMD49 */ R1_RESP | NO_DATA,
    /* ACMD50 */ R1_RESP | NO_DATA,
    /* ACMD51 */ R1_RESP | NO_DATA,
    /* ACMD52 */ R1_RESP | NO_DATA,
    /* ACMD53 */ R1_RESP | NO_DATA,
    /* ACMD54 */ R1_RESP | NO_DATA,
    /* ACMD55 */ R1_RESP | NO_DATA,
    /* ACMD56 */ R1_RESP | NO_DATA,
    /* ACMD57 */ R1_RESP | NO_DATA,
    /* ACMD58 */ R1_RESP | NO_DATA,
    /* ACMD59 */ R1_RESP | NO_DATA,
    /* ACMD60 */ R1_RESP | NO_DATA,
    /* ACMD61 */ R1_RESP | NO_DATA,
    /* ACMD62 */ R1_RESP | NO_DATA,
    /* ACMD63 */ R1_RESP | NO_DATA
};

void uSDHC_SendCmd(uSDHCRegs uSDHC, CommandId cmdidx, uint32_t arg)
{
    uint32_t data;

    /* wait until CIHB is cleared */
    while (uSDHC->press_state & 0x1) ;

    data = CommandTable[cmdidx];

    /* if data is present, wait until CDIHB is cleared */
    if (data & 0x00200000)
        while (uSDHC->press_state & 0x2) ;

    uSDHC->cmd_arg = arg;

    /* always enable dma */
    uSDHC->mix_ctrl = (data & 0xffff) | 0x1;

    /* start command */
    uSDHC->cmd_xfr_type = (cmdidx << 24) | (data & 0xffff0000);

    while (!(uSDHC->int_status & 0x00010001)) ;
    uSDHC->int_status = 0xfffffffd;

}

void uSDHC_InitSD(uSDHC_Card * card)
{
    int i;
    uint32_t ocr_val;
    uSDHCRegs uSDHC = card->uSDHC;

    /* reset controller */
    uSDHC->sys_ctrl |= 0x01000000;
    while (uSDHC->sys_ctrl & 0x01000000) ;

    /* send 80 clocks to card for initialization */
    uSDHC->sys_ctrl |= 0x08000000;
    for (i = 0; i < 400; ++i) ;
    /* wait 2ms */
    //GPT()

    uSDHC_SendCmd(uSDHC, CMD0, 0x0);    /* reset command */
    uSDHC_SendCmd(uSDHC, CMD8, 0x1AA);

    ocr_val = 0x40ff8000;
    while (!(ocr_val & 0x80000000)) {
        uSDHC_SendCmd(uSDHC, CMD55, 0x0);
        uSDHC_SendCmd(uSDHC, ACMD41, ocr_val);
        ocr_val = uSDHC->cmd_rsp0;
    }
    card->highCapacity = (ocr_val & 0x40000000) >> 30;

    uSDHC_SendCmd(uSDHC, CMD2, 0x0);
    uSDHC_SendCmd(uSDHC, CMD3, 0x0);
    card->rca = uSDHC->cmd_rsp0 & 0xffff0000;

    uSDHC_SendCmd(uSDHC, CMD13, card->rca);

    /* select card, switch to 'transfer' mode */
    uSDHC_SendCmd(uSDHC, CMD7, card->rca);

    uSDHC_SendCmd(uSDHC, CMD13, card->rca);

    /* set bus width */
    uSDHC_SendCmd(uSDHC, CMD55, card->rca);
    uSDHC_SendCmd(uSDHC, ACMD6, (card->busWidth == BUS_4BIT) ? 0x2 : 0x0);

    uSDHC_SendCmd(uSDHC, CMD13, card->rca);

    /* set block size to 512 bytes */
    uSDHC_SendCmd(uSDHC, CMD16, 0x200);

    uSDHC->prot_ctrl |= card->busWidth << 1;
    uSDHC->prot_ctrl &= 0xfffffcff; /* Simple DMA */
    uSDHC->wtmk_lvl = 0x00080008;
    uSDHC->sys_ctrl = 0x008e0400;
}

void uSDHC_Write(uSDHC_Card * card, uint32_t sd_addr, uint32_t size, uint32_t * data)
{
    uint32_t blk_cnt, i;
    uSDHCRegs uSDHC = card->uSDHC;

    blk_cnt = size >> BLK_SIZE_SHIFT;

    if (card->highCapacity)
        sd_addr >>= BLK_SIZE_SHIFT;

    if (blk_cnt == 1) {
        uSDHC->ds_addr = (uint32_t) data;
        uSDHC_SendCmd(uSDHC, CMD24, sd_addr);
        while (!(uSDHC->int_status & 0x2)) ;
        uSDHC->int_status = 0xffffffff;
        return;
    }

    i = 0;
    while (blk_cnt > 0) {
        uSDHC->ds_addr = (uint32_t) data + ((MAX_BLOCK_CNT << BLK_SIZE_SHIFT) * i);
        uSDHC->blk_att = (((blk_cnt > MAX_BLOCK_CNT) ? MAX_BLOCK_CNT : blk_cnt) << 16) | BLK_SIZE;
        uSDHC_SendCmd(uSDHC, CMD25, sd_addr + ((MAX_BLOCK_CNT) * i++));
        while (!(uSDHC->int_status & 0x2)) ;
        uSDHC->int_status = 0xffffffff;
        blk_cnt -= (blk_cnt > MAX_BLOCK_CNT) ? MAX_BLOCK_CNT : blk_cnt;
    }
}

void uSDHC_Read(uSDHC_Card * card, uint32_t sd_addr, uint32_t size, uint32_t * data)
{
    uint32_t blk_cnt, i;
    uSDHCRegs uSDHC = card->uSDHC;

    blk_cnt = size >> BLK_SIZE_SHIFT;

    if (card->highCapacity)
        sd_addr >>= BLK_SIZE_SHIFT;

    i = 0;
    while (blk_cnt > 0) {
        uSDHC->ds_addr = (uint32_t) data + ((MAX_BLOCK_CNT << BLK_SIZE_SHIFT) * i);
        uSDHC->blk_att = (((blk_cnt > MAX_BLOCK_CNT) ? MAX_BLOCK_CNT : blk_cnt) << 16) | BLK_SIZE;
        if (card->polling)
            uSDHC->int_status = 0xffffffff;
        uSDHC_SendCmd(uSDHC, CMD18, sd_addr + ((MAX_BLOCK_CNT) * i++));
        if (!(card->polling)) {
            while (!(uSDHC->int_status & 0x2)) ;
            uSDHC->int_status = 0xffffffff;
        }
        blk_cnt -= (blk_cnt > MAX_BLOCK_CNT) ? MAX_BLOCK_CNT : blk_cnt;
    }

}

void uSDHC_EnableInt(uSDHC_Card * card)
{
    //clear interrupt status first
    card->uSDHC->int_signal_en = 0x117f0002;
}

void uSDHC_ClearInterrupts(uSDHC_Card * card)
{
    card->uSDHC->int_status = 0xffffffff;
}
