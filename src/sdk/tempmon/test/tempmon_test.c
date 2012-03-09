/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "tempmon/tempmon.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

//! @brief Test the tempmon driver.
//!
void tempmon_test(void)
{
    int status;
    
    // Init the driver.
    status = tempmon_init();
    if (status)
    {
        printf("tempmon init failed: err=%d\n", status);
        return;
    }
    
    do {
        // Print the prompt.
        printf("\
tempmon test\n\
\n\
Choose an option:\n\
    p - Print current temperature\n\
    x - Exit test\n\n");
    
        // Wait for the user to type a character.
        char c;
        while ((c = getchar()) == NONE_CHAR);

        switch (c)
        {
            case 'x':
            {
                printf("\nTest exit.\n");
                return;
            }

            case 'p':
            {
                // Read the current temperature
                int temp = tempmon_get_temp();
                printf("Current temperature = %d °C\n\n", temp);
                break;
            }
        }
    } while (true);
}

//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
