/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file gpmi_test.c
 * @brief Unit test for the GPMI controller.
 *
 * @ingroup diag_nand
 */

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "nand_devices.h"
#include "gpmi/src/gpmi.h"

static const flash_dev_info_t *flash_dev_info;
static const flash_dev_info_t supported_devices[] = {
#include "supported_nand_parts.inl"
};

static unsigned int rd_buf[8300];
static unsigned int wr_buf[8300];
#define NUM_DEVICES (sizeof(supported_devices) / sizeof(flash_dev_info_t))
#define COL_CYCLE             flash_dev_info->col_cycle
#define ROW_CYCLE             flash_dev_info->row_cycle
#define NF_PG_SZ              (flash_dev_info->page_size) 
#define NF_SP_SZ              (flash_dev_info->spare_size) 

extern int GpmiNandReadPage(unsigned int, unsigned int *,unsigned int,unsigned int);

extern int GpmiNandWritePage(unsigned int, unsigned int *,unsigned int,unsigned int);
extern void read_nflash_id(void *id);
extern int GpmiNandEraseBlock(unsigned int);
int gpmi_test(void)
{
    unsigned short nand_id[4];
    int i ,rtCode = 0;
    read_nflash_id(nand_id);

    flash_dev_info = supported_devices;

    for (i = 0; i < NUM_DEVICES; i++) {
        if ((flash_dev_info->device_id == nand_id[0]) &&
            (flash_dev_info->device_id2 == 0xFFFF || flash_dev_info->device_id2 == nand_id[1])) {
            break;
        }
        flash_dev_info++;
    }

    if (i == NUM_DEVICES) {
        printf("**NAND device unrecognized!\n");
        printf("NAND ID: 0x%04x, 0x%04x, 0x%04x, 0x%04x\n",
               nand_id[0], nand_id[1], nand_id[2], nand_id[3]);
        printf("Does the NAND ID match what is expected per the datasheet?Y(yes) or N(no)\n");
        if (!is_input_char('y'))
            return TEST_FAILED;
    } else {
        printf("%s found\n", flash_dev_info->vendor_info);
        printf("NAND ID: 0x%04x, 0x%04x, 0x%04x, 0x%04x\n",
               nand_id[0], nand_id[1], nand_id[2], nand_id[3]);
    }

    printf("NAND ID successfully read\n");
	rtCode = GpmiNandEraseBlock(0);

	if (rtCode != SUCCESS){
	    printf("NAND block 0 erase failed\n");	 
        return TEST_FAILED;
		}
	else{
		printf("NAND block 0 erase sueccess\n");
        //return TEST_PASSED;
	}
	    wr_buf[0] = 0x80010810;
		wr_buf[1] = 0x01801008;
		for(i=2;i<NF_PG_SZ/4;i++)
		{
			wr_buf[i] = wr_buf[i-1] + wr_buf[i-2];
		}
	    

        rtCode = GpmiNandWritePage(0,wr_buf, NF_PG_SZ, NF_SP_SZ);
	
	if(rtCode == SUCCESS)
		rtCode = GpmiNandReadPage(0,rd_buf, NF_PG_SZ, NF_SP_SZ);

    
	for(i=0;i<(NF_PG_SZ+NF_SP_SZ)/4;i++)
			  {
          	
				if(rd_buf[i]!=wr_buf[i])
				{
					printf("data verify error\n");
					printf("wr: %x |",wr_buf[i]);
					printf("rd: %x\n",rd_buf[i]);
						
					rtCode=FAILURE;
					break;
				}
                
				
		}
	     printf("data verify success\n");
	   
    return rtCode;	
}
