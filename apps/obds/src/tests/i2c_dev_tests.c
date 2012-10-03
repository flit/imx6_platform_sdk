/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "obds.h"
#include "hardware.h"

extern int i2c_device_id_check_MMA8451(unsigned int i2c_base_addr);
extern int i2c_device_id_check_isl29023(unsigned int i2c_base_addr);
extern int i2c_device_id_check_mag3112(unsigned int i2c_base_addr);
extern int i2c_device_id_check_mag3110(unsigned int i2c_base_addr);
extern int i2c_device_check_max11801(unsigned int i2c_base_addr);
extern int i2c_device_check_cs42888(void);
extern int i2c_device_id_check_p1003(unsigned int i2c_base_addr);
extern int i2c_device_id_check_emc1046(unsigned int i2c_base_addr);

extern int i2c_device_id_check_MMA8450(unsigned int i2c_base_addr);
extern int i2c_device_id_check_ppl3115(unsigned int i2c_base_addr);
extern int i2c_device_id_check_mc1323(unsigned int i2c_base_addr);

int i2c_device_id_check_mag3112_test_enable = 1;
int i2c_device_id_check_mag3110_test_enable = 1;
int i2c_device_id_check_isl29023_test_enable = 1;
int i2c_device_id_check_mma8451_test_enable = 1;
int i2c_device_id_check_p1003_test_enable = 1;
int i2c_device_id_check_cs42888_test_enable = 1;

static const char * const i2c_device_test_name = "I2C Device ID Test";

/*!
 * This test performs i2c device id check 
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
menu_action_t i2c_device_id_check(const menu_context_t* const context, void* const param) 
{
	int rc = 0;
    int test_count = 0;
    const char* indent = menu_get_indent(context);

    if ( prompt_run_test(i2c_device_test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }  
    
#if defined(BOARD_TYPE_SMART_DEVICE)
        //  USB_OTG_PWR_EN (EIM_D22)
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB3);
        gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);

        //rc |= i2c_device_id_check_mc1323(I2C2_BASE_ADDR);
        if (i2c_device_id_check_mma8451_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_MMA8451(I2C1_BASE_ADDR);  // accelerometer
        }
        if (i2c_device_id_check_isl29023_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_isl29023(I2C3_BASE_ADDR); // light sensor
        }
        if (i2c_device_id_check_mag3110_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_mag3110(I2C3_BASE_ADDR);  // eCompass mag3110
        }
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
#elif defined(BOARD_TYPE_SABRE_LITE)
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
#elif defined(BOARD_TYPE_SABRE_AI) 
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
        if (i2c_device_id_check_cs42888_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_check_cs42888();   // audio codec on main board
        }
        if (i2c_device_id_check_isl29023_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_isl29023(I2C3_BASE_ADDR); // light sensor on main board
        }
        if (i2c_device_id_check_mag3112_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_mag3112(I2C3_BASE_ADDR);  // eCompass on main board
        }
        if (i2c_device_id_check_mma8451_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_MMA8451(I2C3_BASE_ADDR);  // accelerometer on main board
        }       
#endif    

    if (test_count == 0) 
    {
        printf("%sNo I2C Device tests performed.\n", indent);
        print_test_failed(i2c_device_test_name, indent);

        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;        
        
    }
    if (rc == 0) 
    {
        printf("\n%sI2C Device test failed.\n", indent);
        print_test_failed(i2c_device_test_name, indent);

        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;        
    }
    else
    {
    	printf("\n%sI2C Device test passed.\n", indent);
        print_test_passed(i2c_device_test_name, indent);

        *(test_return_t*)param = TEST_FAILED;
        return MENU_CONTINUE;      
    }

    return MENU_CONTINUE;          
}

#if 0
int i2c_device_id_check(void)
{
    int rc = 0;
    int test_count = 0;

    PROMPT_RUN_TEST("I2C Device ID", NULL);

    if ((BOARD_TYPE_ID == BOARD_TYPE_DEFAULT) || (BOARD_TYPE_ID == BOARD_TYPE_EVB)) 
    {

    } 
    else if (BOARD_TYPE_ID == BOARD_TYPE_SMART_DEVICE) 
    {
        //  USB_OTG_PWR_EN (EIM_D22)
        writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB3);
        gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);

        //rc |= i2c_device_id_check_mc1323(I2C2_BASE_ADDR);
        if (i2c_device_id_check_mma8451_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_MMA8451(I2C1_BASE_ADDR);  // accelerometer
        }
        if (i2c_device_id_check_isl29023_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_isl29023(I2C3_BASE_ADDR); // light sensor
        }
        if (i2c_device_id_check_mag3110_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_mag3110(I2C3_BASE_ADDR);  // eCompass mag3110
        }
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
        //rc |= i2c_device_id_check_emc1046(I2C3_BASE_ADDR);
    } 
    else if (BOARD_TYPE_ID == BOARD_TYPE_SABRE_LITE) 
    {
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
    } 
    else if (BOARD_TYPE_ID == BOARD_TYPE_SABRE_AI) 
    {
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(P1003_TSC_I2C_BASE);    // hannstar display TSC via lvds
        }
        if (i2c_device_id_check_cs42888_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_check_cs42888();   // audio codec on main board
        }
        if (i2c_device_id_check_isl29023_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_isl29023(I2C3_BASE_ADDR); // light sensor on main board
        }
        if (i2c_device_id_check_mag3112_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_mag3112(I2C3_BASE_ADDR);  // eCompass on main board
        }
        if (i2c_device_id_check_mma8451_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_MMA8451(I2C3_BASE_ADDR);  // accelerometer on main board
        }
    }

    if (test_count == 0) {
        printf("No I2C Device tests performed.\n");
        return 0;
    }
    printf("I2C Device test %s.\n", (rc == 0) ? "passed" : "failed");
    return rc;
}
#endif

