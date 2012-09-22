/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

//#include "imx_i2c.h"
#include "obds.h"
#include "hardware.h"

int p1003_show_touch(unsigned int i2c_base_addr);

unsigned char p1003_version_reg_read(unsigned int i2c_base_addr, unsigned char reg_addr,
                                     unsigned char *ret_val)
{
    struct imx_i2c_request rq;

    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = P1003_TSC_I2C_ID; // 4
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 10;
    rq.buffer = ret_val;

    if (i2c_xfer(&rq, I2C_READ) != 0) {
//    if (i2c_xfer(i2c_base_addr, &rq, I2C_READ) != 0) {
        printf("%s() error. return\n", __FUNCTION__);
        return -1;
    }

    return 0;
}

unsigned char p1003_version_reg_write(unsigned int i2c_base_addr, unsigned char reg_addr,
                                     unsigned char *buffer)
{
	struct imx_i2c_request rq;
    rq.ctl_addr = i2c_base_addr;
    rq.dev_addr = P1003_TSC_I2C_ID; // 4
    rq.reg_addr = reg_addr;
    rq.reg_addr_sz = 1;
    rq.buffer_sz = 2 + buffer[1];
    rq.buffer = buffer;

    if (i2c_xfer(&rq, I2C_WRITE) != 0) {
//    if (i2c_xfer(i2c_base_addr, &rq, I2C_WRITE) != 0) {
        printf("%s() error. return\n", __FUNCTION__);
        return -1;
    }

    return 0;
}

int i2c_device_id_check_p1003(unsigned int i2c_base_addr)
{
    printf("\nTest HannStar P1003_TSC Device ID\n\n");
    i2c_init(i2c_base_addr, 100000);

	unsigned char ret_buf1[10] = {0};
//	unsigned char ret_buf2[10] = {0};

	// route interrupt signal
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE, 0x1A080);
 	gpio_set_direction(GPIO_PORT6, 8, GPIO_GDIR_INPUT);

    // set to idle
//	unsigned char buf0[] = {0x03, 0x06, 0x0A, 0x04, 0x36, 0x3F, 0x01, 0x00, 0, 0};
//	if (p1003_version_reg_write(i2c_base_addr, 0, buf0) != 0) {
//        printf("failed to send set_to_idle command.\n");
//        return 1;
//    }
//    // check active
//	unsigned char buf3[] = {0x03, 0x03, 0x0A, 0x01, 'A', 0, 0, 0, 0, 0};
//	if (p1003_version_reg_write(i2c_base_addr, 0, buf3) != 0) {
//        printf("failed to send set_to_idle command.\n");
//        return 1;
//    } else
//    {
//    	// wait for INT line to go low
////    	while (gpio_get_level(GPIO_PORT6, 8) == GPIO_HIGH_LEVEL)
////    		printf(".");
//
//		if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf1) != 0) {
//			printf("failed to read 1st HannStar firmware version packet\n");
//			return 1;
//		}
//		printf("HannStar TSC check active: 0x%02X\n", ret_buf1[0]);
////		printf("\t0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",   ret_buf1[0], ret_buf1[1], ret_buf1[2], ret_buf1[3], ret_buf1[4], ret_buf1[5], ret_buf1[6], ret_buf1[7], ret_buf1[8], ret_buf1[9]);
//    }

	// read firmware version
	unsigned char buf[] = {0x03, 0x03, 0x0A, 0x01, 'D', 0, 0, 0, 0, 0};
    if (p1003_version_reg_write(i2c_base_addr, 0, buf) != 0) {
        printf("failed to send get_hanstar_firmware_version command.\n");
        return 1;
    } else
    {
    	// wait for INT line to go low
//    	while (gpio_get_level(GPIO_PORT6, 8) == GPIO_HIGH_LEVEL)
//    		printf(".");

		if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf1) != 0) {
			printf("failed to read 1st HannStar firmware version packet\n");
			return 1;
		}
		printf("HannStar firmware version: 0x%02X\n", ret_buf1[5]);
    }
//		  else if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf2) != 0) {
//			printf("failed to read 2nd HannStar firmware version packet\n");
//			return 1;
//		} else {
//			printf("HannStar TSC firmware version:\n");
//			printf("\t0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",   ret_buf1[0], ret_buf1[1], ret_buf1[2], ret_buf1[3], ret_buf1[4], ret_buf1[5], ret_buf1[6], ret_buf1[7], ret_buf1[8], ret_buf1[9]);
//			printf("\t0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n\n", ret_buf2[0], ret_buf2[1], ret_buf2[2], ret_buf2[3], ret_buf2[4], ret_buf2[5], ret_buf2[6], ret_buf2[7], ret_buf2[8], ret_buf2[9]);
//		}
//    }
//
//    buf[4] = 'E';
//    if (p1003_version_reg_write(i2c_base_addr, 0, buf) != 0) {
//        printf("failed to send get_hanstar_controller_name command.\n");
//        return 1;
//    } else
//    {
//    	// wait for INT line to go low
//    	while (gpio_get_level(GPIO_PORT6, 8) == GPIO_HIGH_LEVEL)
//    		printf(".");
//
//    	if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf1) != 0) {
//			printf("failed to read 1st HannStar controller name packet\n");
//			return 1;
//		} else if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf2) != 0) {
//			printf("failed to read 2nd HannStar controller name packet\n");
//			return 1;
//		} else {
//			printf("HannStar TSC controller name:\n");
//			printf("\t0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",   ret_buf1[0], ret_buf1[1], ret_buf1[2], ret_buf1[3], ret_buf1[4], ret_buf1[5], ret_buf1[6], ret_buf1[7], ret_buf1[8], ret_buf1[9]);
//			printf("\t0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n\n", ret_buf2[0], ret_buf2[1], ret_buf2[2], ret_buf2[3], ret_buf2[4], ret_buf2[5], ret_buf2[6], ret_buf2[7], ret_buf2[8], ret_buf2[9]);
//		}
//    }

	printf("    Read HannStar firmware version passed.\n\n");
    p1003_show_touch(i2c_base_addr);
    return 0;
}

typedef struct {
    short accel_x;
    short accel_y;
    short accel_z;
} Accel, *pAccel;

#define REPORTID_MTOUCH 0x04

int p1003_get_touch(unsigned int i2c_base_addr, Accel * acc)
{

	unsigned char ret_buf[10] = {0};
	char status = 0;
	char untouched_count = 0;

	do {
		if (p1003_version_reg_read(i2c_base_addr, 0, ret_buf) != 0) {
			printf("failed to read HannStar position packet\n");
			return 1;
		}

		status = ret_buf[1] & 0x01;
		if ( status )
			untouched_count = 0;
		else
			++untouched_count;

	} while ((ret_buf[0] != REPORTID_MTOUCH) && (untouched_count < 10));

	char contactID = (ret_buf[1] & 0x7C) >> 2;
	static short x0 = 0, y0 = 0, x1 = 0, y1 = 0;
	if ( contactID == 0)
	{
		if ( status )
		{
			x0 = (((short)(ret_buf[3])<<8) + (short)ret_buf[2]) >> 4;
			y0 = (((short)(ret_buf[5])<<8) + (short)ret_buf[4]) >> 4;
		}
		else
		{
			x0 = y0 = 0;
		}
	}
	else
	{
		if ( status )
		{
			x1 = (((short)(ret_buf[3])<<8) + (short)ret_buf[2]) >> 4;
			y1 = (((short)(ret_buf[5])<<8) + (short)ret_buf[4]) >> 4;
		}
		else
		{
			x1 = y1 = 0;
		}

	}
	printf("\r    The touch data is: contact 0: X = %d, Y = %d contact 1: X = %d, Y = %d          ", x0, y0, x1, y1);
//	  printf("0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",   ret_buf[0], ret_buf[1], ret_buf[2], ret_buf[3], ret_buf[4], ret_buf[5], ret_buf[6], ret_buf[7], ret_buf[8], ret_buf[9]);

    return 0;
}

int p1003_show_touch(unsigned int i2c_base_addr)
{
    unsigned char uc = NONE_CHAR;
    Accel acc;

    printf("    Do you want to check the touch screen?(y/n)\n\n");

    do {
        uc = getchar();
//        uc = receive_char();
    } while (uc == NONE_CHAR);

    if (uc == 'y' || uc == 'Y')
    {
        printf("    Start show touch screen. Type 'x' to exit.\n\n");
        while (1) {
            p1003_get_touch(i2c_base_addr, &acc);
            uc = getchar();
//            uc = receive_char();
            if (uc == 'x' || uc == 'X') {
                printf("\n\n");
                break;
            }
        }
    } else {
        return 1;
    }
    return 0;
}
