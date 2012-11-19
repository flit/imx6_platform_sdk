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

#include "obds.h"

extern menu_action_t i2c_device_isl29023_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_mag3110_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_mag3112_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_ppl3115_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_MMA8450_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_MMA8451_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_emc1046_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_P1003_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_max11801_test(const menu_context_t* context, void* param);
extern menu_action_t i2c_device_mc1323_test(const menu_context_t* context, void* param);

//extern int i2c_device_check_cs42888(void);
//int i2c_device_id_check_cs42888_test_enable = 1;

static const char * const i2c_device_test_name = "I2C Device ID Test";

/*!
 * This test performs i2c device id check 
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
menu_action_t i2c_device_id_check(const menu_context_t* const context, void* const param) 
{
    int test_count = 0;

    if ( prompt_run_test(i2c_device_test_name, NULL) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }  
    
#if defined(CHIP_MX6DQ)   
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB3);
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);
#if defined(BOARD_SMART_DEVICE) 
    test_count = 4;
    i2c_device_MMA8451_test(context, param);
    i2c_device_isl29023_test(context, param);
    i2c_device_mag3110_test(context, param);
    i2c_device_P1003_test(context, param);
    //rc |= i2c_device_id_check_mc1323(I2C2_BASE_ADDR);
    
#elif defined(BOARD_SABRE_LITE) 
    test_count = 1;
    i2c_device_P1003_test(context, param);
#elif defined(BOARD_SABRE_AI)      
    test_count = 5;   
    i2c_device_P1003_test(context, param);
    i2c_device_isl29023_test(context, param);
    i2c_device_mag3110_test(context, param);
    i2c_device_mag3112_test(context, param);
    i2c_device_MMA8451_test(context, param);
    
/*        if (i2c_device_id_check_cs42888_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_check_cs42888();   // audio codec on main board
        } */
#endif    

#endif //Chip MX6DQ 

#if defined(CHIP_MX6SDL)
    writel(ALT5, IOMUXC_SW_MUX_CTL_PAD_EIM_EB3);
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
    hal_delay_us(1000);
    gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);

#if defined(BOARD_SMART_DEVICE) 
    test_count = 4;
    i2c_device_MMA8451_test(context, param);
    i2c_device_isl29023_test(context, param);
    i2c_device_mag3110_test(context, param);
    i2c_device_P1003_test(context, param);
#elif defined(BOARD_SABRE_LITE)
    test_count = 1;
    i2c_device_P1003_test(context, param);    
#elif defined(BOARD_SABRE_AI)
    test_count = 5;
    i2c_device_P1003_test(context, param);
    i2c_device_isl29023_test(context, param);
    i2c_device_mag3110_test(context, param);
    i2c_device_mag3112_test(context, param);
    i2c_device_MMA8451_test(context, param);
/*        if (i2c_device_id_check_cs42888_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_check_cs42888();   // audio codec on main board
        } */
#endif

#endif //Chip MX6SDL

#if defined(CHIP_MX6SL)
    test_count = 2;
    i2c_device_MMA8450_test(context, param);
    i2c_device_isl29023_test(context, param);
#endif //Chip MX6SL

    if (test_count == 0) 
    {
        printf("No I2C Device tests performed.\n");
        print_test_failed(i2c_device_test_name, NULL);

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
            rc |= i2c_device_id_check_p1003(g_p1003_tsc_i2c_device.port);    // hannstar display TSC via lvds
        }
        //rc |= i2c_device_id_check_emc1046(I2C3_BASE_ADDR);
    } 
    else if (BOARD_TYPE_ID == BOARD_TYPE_SABRE_AI) 
    {
        if (i2c_device_id_check_p1003_test_enable == 1) {
            ++test_count;
            rc |= i2c_device_id_check_p1003(g_p1003_tsc_i2c_device.port);    // hannstar display TSC via lvds
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

