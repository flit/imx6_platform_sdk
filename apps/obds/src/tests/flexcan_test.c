/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file can_common.c
 * @brief CAN driver's common operation functions
 *
 * @ingroup diag_can
 */

#include "hardware.h"
#include "obds.h"
//#include "functions.h"
//#include "can_common.h"
//extern int can_tx0rx1(void);
//extern int can_tx1rx0(void);

static const char * const test_name = "FLEXCAN1/2 LOOPBACK Test";

/*!
 * Test can0 and can1 tx/rx.
 *
 * @return      TEST_PASSED or TEST_FAILED
 */
menu_action_t flexcan_test(const menu_context_t* const context, void* const param)
{
	const char* indent = menu_get_indent(context);

    if ( prompt_run_test(test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }
    test_return_t result1 = TEST_NOT_IMPLEMENTED, result2 = TEST_NOT_IMPLEMENTED;

#if defined(SABRE_AI)
    printf("%s(Please note that in order to run the test, you need to first\n", indent);
    printf("%s(on SABRE AI main board): connect J35.6 to J34.7 and connect J35.7 to J34.2\n\n", indent);
    printf("%sWould you like to run the FLEXCAN1/FLEXCAN2 loopback tests?\n", indent);
    if (!is_input_char('y'))
    {
        print_test_skipped(test_name, indent);

        *(test_return_t*)param = TEST_BYPASSED;
        return MENU_CONTINUE;
    }
/* TODO: Call new functions
    can_io_cfg(CAN0_BASE_ADDR);
    can_io_cfg(CAN1_BASE_ADDR);
*/
#endif

    printf("%sFLEXCAN test1: FLEXCAN2-TX and FLEXCAN1-RX\n", indent);
/* TODO: Implemnent CAN2 TX -> CAN1 RX
    result1 = can_tx2rx1();

    // Disable the module
    reg32setbit(CAN1_BASE_ADDR + CAN_MCR, 31);
    reg32setbit(CAN0_BASE_ADDR + CAN_MCR, 31);
    //reset can0 and can1
    reg32setbit(CAN0_BASE_ADDR + CAN_MCR, 25);
    reg32setbit(CAN1_BASE_ADDR + CAN_MCR, 25);
    hal_delay_us(5000);
*/
    printf("%sFLEXCAN test2: FLEXCAN1-TX and FLEXCAN2-RX\n", indent);
/* TODO: Implemnent CAN1 TX -> CAN2 RX
    result2 = can_tx0rx1();
*/
    print_test_not_implemented(test_name, indent);

    *(test_return_t*)param = result1 = result2;
    return MENU_CONTINUE;

/* TODO: Reinstate this code and remove the above code
 * after implementing testsImplemnent CAN1 TX -> CAN2 RX

    if (result1 == TEST_PASSED && result2 == TEST_PASSED)
    {
        print_test_passed(test_name, indent);

        *(test_return_t*)param = TEST_PASSED;
        return MENU_CONTINUE;
    }

    print_test_failed(test_name, indent);

    *(test_return_t*)param = TEST_FAILED;
    return MENU_CONTINUE;
*/
}
