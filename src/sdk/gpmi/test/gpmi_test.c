/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "nand_devices.h"
#include "../drv/gpmi.h"

//static const flash_dev_info_t *flash_dev_info;
static const flash_dev_info_t supported_devices[] = {
#include "supported_nand_parts.inl"
};



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
        return TEST_PASSED;
	}
}
