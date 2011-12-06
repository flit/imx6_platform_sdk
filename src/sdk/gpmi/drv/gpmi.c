/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdlib.h>
#include <stdio.h>
#include "hardware.h"
#include "nand_devices.h"
#include "gpmi.h"
#include "regsapbh.h"
#include "regsgpmi.h"
//extern static const flash_dev_info_t *flash_dev_info;

DMA_BUFF gdma0, gdma1, gdma2, gdma3, gdma4, gdma5, gdma6, gdma7, gdma8, gdma9;
DMA_BUFF dma_buff0, dma_buff1, dma_buff2, dma_buff3, dma_buff4, dma_buff5, dma_buff6, dma_buff7,
    dma_buff8;
DMA_BUFF dma_buff9, dma_buff10, dma_buff11, dma_buff12, dma_buff13, dma_buff14, dma_buff15, dummy;

/*!
 * Build the dma chain
 *
 * @param   chain           indicate the dma command is chained or not
 * @param   cmd             dma command type
 * @param   decr_sema       indicate whether the channel will decrement its semaphore at the completion of the current command structure
 * @param   irq_finish      indicates whether the channel will cause the interrupt status bit to be set upon completion of the current command
 * @param   nand_lock       indicates that the NAND DMA channel will remain "locked" in the arbiter at the expense of other NAND DMA channels
 * @param   num_bytes       number of bytes to transfer to or from the appropriate PIO register in the GPMI0 device
 * @param   num_pio         number of command words to send to the GPMI0, starting with the base PIO address of the GPMI0 control register
 * @param   wait4end        indicates whether the channel will wait for the end of command signal to be sent from the APBH device to the DMA before starting the next DMA command
 * @param   wait4rdy        indicates whether the NAND DMA channel will wait until the NAND device reports 'ready' before executing the command
 * @param   haltonterm      indicates whether the channel will immeditately terminate the current descriptor and halt the DMA channel if a terminate signal is set
 * @return  a dma structure
 */
DMA_CMD BuildDMACmd(int chain, int cmd, int decr_sema, int irq_finish, int nand_lock,
                    int num_bytes, int num_pio, int wait4end, int wait4rdy, int haltonterm)
{

    DMA_CMD dma_cmd;

    dma_cmd.chain = chain;
    dma_cmd.command = cmd;
    dma_cmd.decr_sema = decr_sema;
    dma_cmd.irq_finish = irq_finish;
    dma_cmd.nandlock = nand_lock;
    dma_cmd.num_bytes = num_bytes;
    dma_cmd.num_pio_wds = num_pio;
    dma_cmd.haltonterminal = haltonterm;
    dma_cmd.unused0 = 0x0;
    dma_cmd.wait4endcmd = wait4end;
    dma_cmd.wait4rdy = wait4rdy;
    return (dma_cmd);

}

/*!
 * Configuration of the GPMI Control Register 0
 *
 * @param   cnt        Number of words (8 or 16 bit wide) to transfer for this command
 * @param   size       indicates whether the word length is 8 bit or 16 bit
 * @param   addr       The address for read and write data bytes/write command bytes/write address bytes
 * @param   cmd_mode   00= Write mode/01= Read Mode/10= Read and Compare Mode (setting sense flop)/11= Wait for Ready
 * @param   incr       indicates whether the address will increment once, after the first cycle
 * @param   udma       indicates whether using ATA-Ultra DMA mode on the external bus
 * @param   dev_irq_en When set to '1' and ATA_IRQ pin is asserted, the GPMI_IRQ output will assert.
 * @param   to_irq_en  enable timeout IRQ for transfers in ATA mode only
 * @param   lock       0= Deassert chip select (CS) after RUN is complete. 1= Continue to assert chip select (CS) after RUN is complete.
 * @return  return the gpmi ctrl0 register value
 */
unsigned int BuildGPMICmd(int cnt, int size, unsigned addr, int cmd_mode, int incr, int udma,
                          int dev_irq_en, int to_irq_en, int lock)
{

    GPMI_CMD gcmd;

    gcmd.gpmi_u32 = 0x0;

    // Setup a ommand to specified cs/address.
    gcmd.gpmi_cmd.xfer_cnt = cnt & 0xffff;
    gcmd.gpmi_cmd.addr_incr = incr;
    gcmd.gpmi_cmd.run = 0;
    gcmd.gpmi_cmd.clkgate = 0;
    gcmd.gpmi_cmd.sft_reset = 0;
    gcmd.gpmi_cmd.lock_cs = lock;
    gcmd.gpmi_cmd.cmd_mode = cmd_mode;

    gcmd.gpmi_cmd.addr = addr & 0x7;
    gcmd.gpmi_cmd.cs = 0;
    gcmd.gpmi_cmd.word_len = 1;

    return (gcmd.gpmi_u32);
}

/*!
 * DMA Operation
 *
 * @param   dma        pointer to the dma structure
 * @param   chan       channel number
 * @return  Indicate the dma status, if successful, return 0
 */
int DoDMA(DMA_BUFF * dma, int chan)
{

    int rtCode = SUCCESS;
    int loop_count = FLASH_BUSY_TIMEOUT / 1000;
    unsigned int iComplete = 0;

    BW_APBH_CHANNEL_CTRL_RESET_CHANNEL(1 << chan);

    // clear interrupt
    HW_APBH_CTRL1_CLR(0x1 << chan);

    // Pointer to next command structure for channel 4.
    HW_APBH_CHn_NXTCMDAR_WR(chan, (unsigned int)dma);

    /* Essentially, this starts the DMA channel */
    HW_APBH_CHn_SEMA_WR(chan, 1);

    while ((loop_count != 0) && (iComplete == 0)) {
        hal_delay_us(10000);
        loop_count--;
        iComplete = (HW_APBH_CTRL1_RD() & (0x1 << chan));
    }

    if (iComplete == 0) {
        // abort dma by resetting channel
        BW_APBH_CHANNEL_CTRL_RESET_CHANNEL(0x1 << chan);
        printf(" dma error!!/n");
        rtCode = BUSY_TIMEOUT;
    }

    return (rtCode);

}

void GpmiNandSetSafeTiming(void)
{
    HW_GPMI_TIMING0_WR((3 << 16) | (3 << 8) | (3 << 0));
    HW_GPMI_TIMING1_WR((unsigned int)0xFFFF << 16); //old is 0x132
}



/*Page Address: in block0, page addr is from 0~127, in block 1, page addres is from 128~255*/

int GpmiNandReadPage(unsigned int pageaddr, unsigned int * buf, unsigned int NF_PG_SZ, unsigned int NF_SP_SZ)
{
	int rtCode = SUCCESS;
	u8 data[8];
	//int i;
	printf("NAND Read Page %d\n",pageaddr);
	
	memset((u8 *)buf,0x0,(NF_PG_SZ+NF_SP_SZ)/4);
	
	data[0] = NAND_CMD_READ_SETUP;
	data[1] = 0x00;
	data[2] = 0x00;
	data[3] = pageaddr & 0xFF;
	data[4] = (pageaddr >> 0x8 ) & 0xFF;
	data[5] = (pageaddr >> 0x16) & 0xFF;
	
	data[6] = NAND_CMD_READ_NEXT;
	data[7] = NAND_CMD_READ_STATUS;
	
	/*Fill CMD0 and address cycles - 5 cycles */
	gdma0.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 6, 3, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma0.pio_wrds[0] =
            BuildGPMICmd(6, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
    
	gdma0.pio_wrds[1] = 0x00000000; //fill into HW_GPMI_COMPARE
	gdma0.pio_wrds[2] = 0x0;//HW_GPMI_ECCCTRL_ECC_DISABLE;//BW_GPMI_ECCCTRL_ENABLE_ECC(BV_GPMI_ECCCTRL_ENABLE_ECC__DISABLE); //file into HW_GPMI_ECCCTRL
	
	gdma0.next_buff = &gdma1;
    gdma0.buff_ptr = &data[0];
    
    /*Fill read next command 0x30*/
    gdma1.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 1, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma1.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
		
	gdma1.next_buff = &gdma2;
    gdma1.buff_ptr = &data[6];
    
    /*Check NAND Status start*/
    gdma2.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_NO_XFER, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 1, DMA_WAIT4END,
                    DMA_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma2.pio_wrds[0] =
            BuildGPMICmd(0, XFER8, GPMI_CTRL0_NAND_DATA_BYTES, GPMI_CTRL0_CMD_WAIT_READY, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_NO_LOCK);
	
	gdma2.next_buff = &gdma3;
    gdma2.buff_ptr = (void *)NULL;
    
    //sense dma 
    gdma3.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_SENSE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);                  
	
	gdma3.next_buff = &gdma4;  //if ready, transfer data from NAND to DMA buffer
    gdma3.buff_ptr = &gdma8;//&gdma8; //if timeout, go to timeout handler dma
    
    /*Read out data*/
    //*(volatile unsigned int *)HW_GPMI_PAYLOAD_ADDR = (unsigned int)buf & 0xFFFFFFFC;
    //*(volatile unsigned int *)HW_GPMI_AUXILIARY_ADDR = ((unsigned int)buf + NAND_PAGE_DATA_SIZE/4) & 0xFFFFFFFC;
    gdma4.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_WRITE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, (NF_PG_SZ+NF_SP_SZ), 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma4.pio_wrds[0] =
            BuildGPMICmd((NF_PG_SZ+NF_SP_SZ), XFER8, GPMI_CTRL0_NAND_DATA_BYTES , GPMI_CTRL0_CMD_READ, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_TO_IRQ, NAND_CS_NO_LOCK);
    gdma4.pio_wrds[1] = 0x00;
    gdma4.pio_wrds[2] = 0x0;//(0x0<<13)|(0x1<<12)|0x1FF;//(~(1<<12));//0x00;
    gdma4.pio_wrds[3] = 0x0;//NAND_PAGE_SIZE;
    gdma4.pio_wrds[4] = (unsigned int)buf&0xFFFFFFFC;
	HW_GPMI_PAYLOAD_WR((unsigned int)buf&0xFFFFFFFC);
	HW_GPMI_AUXILIARY_WR((unsigned int)(buf+NF_PG_SZ/4)&0xFFFFFFFC);
   // gdma4.pio_wrds[5] = (unsigned int)(buf+NAND_PAGE_DATA_SIZE/4)&0xFFFFFFFC;
    
    gdma4.next_buff = &gdma5;
    gdma4.buff_ptr = (void*)((unsigned int)buf&0xFFFFFFFC); //read the status of GPMI to determine if there is timeout occuring
    
    /*wait_for_done*/
    gdma5.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_NO_XFER, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 0, 3, DMA_WAIT4END,
                    DMA_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma5.pio_wrds[0] =
            BuildGPMICmd(0, XFER8, GPMI_CTRL0_NAND_DATA_BYTES , GPMI_CTRL0_CMD_WAIT_READY, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_TO_IRQ, NAND_CS_NO_LOCK);
    gdma5.pio_wrds[1] = 0x0;
    gdma5.pio_wrds[2] = 0x0;//0x0;
    gdma5.next_buff = &gdma7;  
    gdma5.buff_ptr = (void*)0;  
    //success handler
    gdma7.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma7.next_buff = NULL;  
    gdma7.buff_ptr = (void *)SUCCESS;   
    
    //failure handler
    gdma8.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma8.next_buff = NULL;  
    gdma8.buff_ptr = (void *)FAILURE;   
    
    rtCode = DoDMA(&gdma0, CHAN0);
    
    if (rtCode == BUSY_TIMEOUT) {
            printf("    **TIMEOUT: No response from the NAND!!\n");
        } else if (rtCode == SUCCESS) {
         
			printf("data read success\n");
     }

	return rtCode;
}

int GpmiNandWritePage(unsigned int pageaddr, unsigned int * buf, unsigned int NF_PG_SZ, unsigned int NF_SP_SZ)
{
	int rtCode = SUCCESS;
	u8 data[8];
	//int i;
	u16 nandStatus = 0;
	printf("NAND Write Page %d\n",pageaddr);
	
	
	data[0] = NAND_CMD_PROGRAM_SETUP;
	data[1] = 0x00;
	data[2] = 0x00;
	data[3] = pageaddr & 0xFF;
	data[4] = (pageaddr >> 8 ) & 0xFF;
	data[5] = (pageaddr >> 16) & 0xFF;
	data[6] = NAND_CMD_PROGRAM_CONFIRM;
	data[7] = NAND_CMD_READ_STATUS;
	
	/*Fill CMD0 and address cycles - 5 cycles */
	gdma0.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 6, 3, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma0.pio_wrds[0] =
            BuildGPMICmd(6, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
    
	gdma0.pio_wrds[1] = 0x0; //fill into HW_GPMI_COMPARE
	gdma0.pio_wrds[2] = 0x0; //HW_GPMI_ECCCTRL_ECC_DISABLE;
	
	gdma0.next_buff = &gdma1;
    gdma0.buff_ptr = &data[0];
    
    /*Transfer data into NAND*/
    //*(volatile unsigned int *)HW_GPMI_PAYLOAD_ADDR = (unsigned int)buf & 0xFFFFFFFC;
    //*(volatile unsigned int *)HW_GPMI_AUXILIARY_ADDR = ((unsigned int)buf + NAND_PAGE_DATA_SIZE/4) & 0xFFFFFFFC;
    gdma1.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, (NF_PG_SZ+NF_SP_SZ), 4, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY, DMA_NO_HALT_ON_TERMINAL );
                    
    gdma1.pio_wrds[0] =
            BuildGPMICmd((NF_PG_SZ+NF_SP_SZ), XFER8, GPMI_CTRL0_NAND_DATA_BYTES , GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
    gdma1.pio_wrds[1] = 0x0; //fill into HW_GPMI_COMPARE
	gdma1.pio_wrds[2] = 0x0;//HW_GPMI_ECCCTRL_ECC_DISABLE;
    gdma1.pio_wrds[3] = 0;//ECC_COUNT
    gdma1.pio_wrds[4] = (unsigned int)buf&0xFFFFFFFC;
    gdma1.pio_wrds[5] = (unsigned int)(buf+NF_PG_SZ/4)&0xFFFFFFFC;
	HW_GPMI_PAYLOAD_WR((unsigned int)buf&0xFFFFFFFC);
	HW_GPMI_AUXILIARY_WR((unsigned int)(buf+NF_PG_SZ/4)&0xFFFFFFFC);
    gdma1.next_buff = &gdma2;
    gdma1.buff_ptr = (void *)((unsigned int)buf&0xFFFFFFFC); //read the status of GPMI to determine if there is timeout occuring
    
    /*Send Program Confirm 0x10 command*/
    gdma2.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 1, 3, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma2.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES , GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
    gdma2.pio_wrds[1] = 0x0; //fill into HW_GPMI_COMPARE
	gdma2.pio_wrds[2] = 0x0;//HW_GPMI_ECCCTRL_ECC_DISABLE;
	
    gdma2.next_buff = &gdma3;
    gdma2.buff_ptr = &data[6]; 
    
    /*wait dma*/
    gdma3.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_NO_XFER, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 1, DMA_WAIT4END,
                    DMA_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma3.pio_wrds[0] =
            BuildGPMICmd(0, XFER8, GPMI_CTRL0_NAND_DATA_BYTES, GPMI_CTRL0_CMD_WAIT_READY, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_NO_LOCK);
	
	gdma3.next_buff = &gdma4;
    gdma3.buff_ptr = (void *)NULL;
    
    /*sense dma*/
    gdma4.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_SENSE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);                  
	
	gdma4.next_buff = &gdma5;  //if ready, check program status
    gdma4.buff_ptr = &gdma9; //if timeout, go to timeout handler dma
    
    /*send read status command*/
    gdma5.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 1, 3, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma5.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
    gdma5.pio_wrds[1] = 0x0;
    gdma5.pio_wrds[2] = 0x0;
                    
    gdma5.next_buff = &gdma6;  //if ready, 
    gdma5.buff_ptr = &data[6]; //if failed, go to timeout handler dma
    
    //read status value
    gdma6.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_WRITE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 1, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma6.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_DATA_BYTES, GPMI_CTRL0_CMD_READ, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_NO_LOCK);
                         
    gdma6.next_buff = &gdma7;  //if ready, 
    gdma6.buff_ptr = &nandStatus; //if failed, go to timeout handler dma
    
	/*sense dma*/
    gdma7.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_SENSE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);                  
	
	gdma7.next_buff = &gdma8;  //if ready, check program status
    gdma7.buff_ptr = &gdma9; //if timeout, go to timeout handler dma
   
    //success handler
    gdma8.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma8.next_buff = NULL;  
    gdma8.buff_ptr = (void *)SUCCESS;   
    
    //failure handler
    gdma9.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma9.next_buff = NULL;  
    gdma9.buff_ptr = (void *)FAILURE;   
    
    rtCode = DoDMA(&gdma0, CHAN0);
    if (rtCode == BUSY_TIMEOUT) {
        printf("    **TIMEOUT: No response from the NAND!!\n");
        printf("    **NAND Program may failed!!\n");
    }
    
  //  printf("Nand Status 0x%x\n",nandStatus);
    return rtCode;
}


int GpmiNandEraseBlock(unsigned int blockaddr)
{
	int rtCode = SUCCESS;
	u8 data[8];
	unsigned int rowAddr;	
	u16 nandStatus = 0;
	printf("NAND Erase Block %d\n",blockaddr);
	rowAddr = blockaddr; 
	
	data[0] = NAND_CMD_ERASE_SETUP;
	data[1] = rowAddr & 0xFF;
	data[2] = (rowAddr >> 8) & 0xFF;
	data[3] = (rowAddr >> 16) & 0xFF;
	data[4] = (rowAddr >> 24) & 0xFF;
	data[5] = NAND_CMD_ERASE_CONFIRM;
	data[6] = NAND_CMD_READ_STATUS;
	/*Send ERASE setup command and 3 row address cycles*/
	gdma0.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 4, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma0.pio_wrds[0] =
            BuildGPMICmd(4, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
	//gdma0.pio_wrds[1] = 0x00000000;
	//gdma0.pio_wrds[2] = 0x0;//HW_GPMI_ECCCTRL_ECC_DISABLE;
	
 	gdma0.next_buff = &gdma1;
    gdma0.buff_ptr = &data[0];
    
    /*Fill ERASE confirm command*/
    gdma1.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 1, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma1.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
	
	gdma1.next_buff = &gdma2;
    gdma1.buff_ptr = &data[5];
    
    /*Check NAND Status start*/
    gdma2.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_NO_XFER, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 1, DMA_WAIT4END,
                    DMA_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma2.pio_wrds[0] =
            BuildGPMICmd(0, XFER8, GPMI_CTRL0_NAND_DATA_BYTES, GPMI_CTRL0_CMD_WAIT_READY, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_NO_LOCK);
	
	gdma2.next_buff = &gdma3;
    gdma2.buff_ptr = (void *)NULL;
    
    //check status conditional branch
    gdma3.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_SENSE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);                  
	
	gdma3.next_buff = &gdma4;  //if ready, go to read nand status
    gdma3.buff_ptr = &gdma8; //if timeout, go to timeout handler dma
    
    //send read status command - 0x70
    gdma4.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 1, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma4.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_LOCK);
                         
    gdma4.next_buff = &gdma5;  //if ready, 
    gdma4.buff_ptr = &data[6]; //if failed, go to timeout handler dma
    
    //read status value
    gdma5.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_WRITE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 1, 1, DMA_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL);
                    
    gdma5.pio_wrds[0] =
            BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_DATA_BYTES, GPMI_CTRL0_CMD_READ, GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE,
                         GPMI_NO_DEV_IRQ, GPMI_NO_TO_IRQ, NAND_CS_NO_LOCK);
    gdma5.pio_wrds[1] = 0x40;                 
    gdma5.next_buff = &gdma7;  //if success 
    gdma5.buff_ptr = &nandStatus; //if failed, go to timeout handler dma
    
    /*status pass
    gdma6.cmd = 
		BuildDMACmd(DMA_CHAIN, DMA_SENSE, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma6.next_buff = &gdma7;  // success handler
    gdma6.buff_ptr = &gdma8;   // failure handler
    */
    //success handler
    gdma7.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma7.next_buff = NULL;  
    gdma7.buff_ptr = (void *)SUCCESS;   
    
    //failure handler
    gdma8.cmd = 
		BuildDMACmd(DMA_NO_CHAIN, DMA_NO_XFER, DMA_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK, 0, 0, DMA_NO_WAIT4END,
                    DMA_NO_WAIT4RDY,DMA_NO_HALT_ON_TERMINAL); 
    
    gdma8.next_buff = NULL;  
    gdma8.buff_ptr = (void *)FAILURE;   
    
    rtCode = DoDMA(&gdma0, NAND_CHANNEL);
    if (rtCode == BUSY_TIMEOUT) {
        printf("    **TIMEOUT: No response from the NAND!!\n");
        printf("    **NAND Erase may failed!!\n");
    }
    
    printf("Nand Status 0x%x\n",nandStatus);
    return rtCode;
    
}



/*!
 * Read the id of nand flash
 *
 * @param   id  Return back the NAND ID
 * @return  a number shows whether the read action is successful or not
 */
int GpmiNandReadId(unsigned short *id)
{

    int rtCode = SUCCESS;
    unsigned char data[8];
//    unsigned short id1, id2;
    int i = NAND_CHANNEL;

    data[0] = 0x90;
    data[1] = 0x00;
    data[2] = 0x00;
    data[3] = 0x00;
    data[4] = 0x00;
    data[5] = 0x00;
    data[6] = 0x00;
    data[7] = 0x00;

    gdma0.cmd =
        BuildDMACmd(DMA_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_NO_IRQ_FINISH, NAND_CS_LOCK, 2,
                    3, DMA_WAIT4END, DMA_NO_WAIT4RDY, DMA_NO_HALT_ON_TERMINAL);

    gdma0.pio_wrds[0] =
        BuildGPMICmd(2, XFER8, (GPMI_CTRL0_NAND_CMD_BYTES | (i << 3)), GPMI_CTRL0_CMD_WRITE,
                     GPMI_CTRL0_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE, GPMI_NO_DEV_IRQ,
                     GPMI_NO_TO_IRQ, NAND_CS_LOCK);

    gdma0.next_buff = &gdma1;
    gdma0.buff_ptr = &data[0];

    gdma1.cmd =
        BuildDMACmd(DMA_NO_CHAIN, DMA_WRITE, DMA_NO_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_NO_LOCK,
                    6, 1, DMA_WAIT4END, DMA_NO_WAIT4RDY, DMA_NO_HALT_ON_TERMINAL);

    gdma1.pio_wrds[0] =
        BuildGPMICmd(6, XFER8, (GPMI_CTRL0_NAND_DATA_BYTES | (i << 3)), GPMI_CTRL0_CMD_READ,
                     GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE, GPMI_NO_DEV_IRQ,
                     GPMI_TO_IRQ, NAND_CS_NO_LOCK);

    gdma1.next_buff = NULL;
    gdma1.buff_ptr = &data[2];

    rtCode = DoDMA(&gdma0, NAND_CHANNEL);

    if (rtCode == BUSY_TIMEOUT) {
        printf("**TIMEOUT: No response from the NAND!!\n");
    } else if (rtCode == SUCCESS) {
        //  printf("finished reading the NAND ID!!\n");
        //printf("------------------------\n");
        *id++ = data[3] << 8 | data[2];
        *id++ = data[5] << 8 | data[4];
        //printf("id data, 0x%04x,0x%04x,0x%04x,0x%04x\n", data[2], data[3], data[4], data[5]);
    }

    return rtCode;
}

/*!
 * Reset nand flash
 *
 */
void GpmiNandReset(void)
{
    int rtCode = SUCCESS;
    unsigned char data;

    data = 0xFF;

    printf("Reset NAND\n");

    gdma0.cmd =
        BuildDMACmd(DMA_NO_CHAIN, DMA_READ, DMA_NO_DECR_SEMA, DMA_IRQ_FINISH, NAND_CS_LOCK, 1, 1,
                    DMA_WAIT4END, DMA_NO_WAIT4RDY, DMA_NO_HALT_ON_TERMINAL);

    gdma0.pio_wrds[0] =
        BuildGPMICmd(1, XFER8, GPMI_CTRL0_NAND_CMD_BYTES, GPMI_CTRL0_CMD_WRITE,
                     GPMI_CTRL0_NO_ADDR_INCR, GPMI_CTRL0_NO_UDMA_MODE, GPMI_NO_DEV_IRQ, GPMI_TO_IRQ,
                     NAND_CS_NO_LOCK);
    gdma0.next_buff = &gdma0;
    gdma0.buff_ptr = &data;

    rtCode = DoDMA(&gdma0, NAND_CHANNEL);

    if (rtCode == BUSY_TIMEOUT) {
        printf("    **TIMEOUT: No response from the NAND!!\n");
        printf("    **Please check NAND flash connection!!\n");
    }
}

/*!
 * Nand test main function
 * @param id returns the NAND ID read from the NAND device
 */

void read_nflash_id(unsigned short *id)
{
    /* set up the clocks for the GPMI NAND interface */
    gpmi_nand_clk_setup();

    HW_GPMI_CTRL0_WR(0xC0000000);   // ensure clock gated and reset set (will be cleared later)

    // preparing soft reset and clock gate.
    HW_GPMI_CTRL0_CLR(0x40000000);  // first, ungate clock
    HW_GPMI_CTRL0_CLR(0x80000000);  // now bring out of reset

    // Only soft reset if GPMI hasn't been enabled.
    HW_GPMI_CTRL0_SET(BM_GPMI_CTRL0_SFTRST);

    while (!HW_GPMI_CTRL0.B.CLKGATE) {
        // busy wait
    }

    // Now bring out of reset and disable Clk gate.
    HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_SFTRST | BM_GPMI_CTRL0_CLKGATE);
    /* Disable BCH at GPMI accessing NAND */
    HW_GPMI_ECCCTRL_CLR(1 << 12);   //disable ECC

    GpmiNandSetSafeTiming();

    /* Set up pin muxing for NAND flash */
    gpmi_nand_pinmux_config();

    // Put GPMI in NAND mode, keep DEVICE reset enabled, and make certain
    // polarity is active high
    HW_GPMI_CTRL1_WR(BF_GPMI_CTRL1_DEV_RESET(BV_GPMI_CTRL1_DEV_RESET__DISABLED) |
                     BF_GPMI_CTRL1_ATA_IRQRDY_POLARITY
                     (BV_GPMI_CTRL1_ATA_IRQRDY_POLARITY__ACTIVEHIGH) |
                     BW_GPMI_CTRL1_GPMI_MODE(BV_GPMI_CTRL1_GPMI_MODE__NAND));

    // Take the APBH out of reset.
    // APBH - disable reset, enable clock.
    HW_APBH_CTRL0_CLR(0xC0000000);

    BW_APBH_CHANNEL_CTRL_RESET_CHANNEL(0x1 << (CHAN0));
    HW_APBH_CTRL1_CLR(0x1 << (CHAN0));
    /* send RESET command to the NAND flash */
    GpmiNandReset();

    /* call function for reading NAND device ID, pass in how many devices are populated */
    GpmiNandReadId(id);
}
