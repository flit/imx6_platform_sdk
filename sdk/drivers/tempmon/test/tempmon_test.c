/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "tempmon/tempmon.h"
#include "system_util.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////////////
// Code
//////////////////////////////////////////////////////////////////////////////////////////

void over_temp_callback(float theTemp)
{
    printf("\n* Temp alarm triggered! Temperature = %4.1f *\n", theTemp);
}

void print_current_temp(void)
{
    float temp = tempmon_get_temp();
    printf("Current temperature = %d degrees C\n\n", (int)temp);
}

//! @brief Test the tempmon driver.
//!
void tempmon_test(void)
{
    int status;
    
    printf("\n--- tempmon test ---\n\n");
    
    // Init the driver.
    status = tempmon_init();
    if (status)
    {
        printf("tempmon init failed: err=%d\n", status);
        return;
    }
    
    // Read the current temperature
    print_current_temp();
    
    do {
        // Print the prompt.
        printf("\n\
Choose an option:\n\
    p - Print current temperature\n\
    a - Set temperature alarm\n\
    d - Disable the alarm\n\
    x - Exit test\n\
\n\
> ");
    
        // Wait for the user to type a valid character.
        char c;
        while (true)
        {
            c = getchar();
            if (c == 'x' || c == 'p' || c == 'a' || c == 'd')
            {
                break;
            }
        }
        
        // Echo the typed char.
        printf("%c\n\n", c);
        
        switch (c)
        {
            case 'x':
                printf("Test exited.\n");
                return;

            case 'p':
                // Read the current temperature
                print_current_temp();
                break;
            
            case 'a':
            {
                printf("Enter the measurement period in milliseconds:\n");
                int period = read_int();
                
                printf("Enter alarm temperature in integer degrees C:\n");
                int alarmTemp = read_int();
                
                // Set the alarm.
                tempmon_set_alarm(period, alarmTemp, over_temp_callback);
                break;
            }
            
            case 'd':
                tempmon_disable_alarm();
                
                printf("Alarm disabled!\n");
                break;
        }
    } while (true);
}

//////////////////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////////////////
