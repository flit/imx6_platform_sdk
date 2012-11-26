/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file m29w256gl.c
 * @brief Driver to get the device and manufacturer ID of the Numonyx M29W256GL NOR flash.
 *
 * @ingroup diag_weim_nor
 */

#include "io.h"
#include "sdk.h"

/* General programmer's note: when writing to the flash, we are left shifting the address by 1 to align
     with 16-bit addressing.  For example, if we are writing to flash address of 0x555, the 
     internal AHB address needs to be 0xAAA or "0x555<<1"  */

// CS_BASE informs the program of the base system address of the Flash
#define CS_BASE  0x08000000 // WEIM_CS_BASE_ADDR

//reset & unlock writes
#define reset() writew(0x00F0, CS_BASE)

#define unlock() writew(0x00AA, CS_BASE+(0x555<<1)); writew(0x0055, CS_BASE+(0x2AA<<1))

//manufacturer and device ID values
#define MANU_ID 0x0020
#define MANU_ID_AD readw(CS_BASE)
#define DEV_ID_1 0x227E
#define DEV_ID_AD_1 (CS_BASE + (0x1<<1))
#define DEV_ID_2 0x2222
#define DEV_ID_AD_2 (CS_BASE + (0xE<<1))
#define DEV_ID_3 0x2201
#define DEV_ID_AD_3 (CS_BASE + (0xF<<1))

/*!
 * This function reads and checks the manufacturer ID of the Numonyx M29W256GL NOR flash.
 * 
 * @return 0 on success; non-zero otherwise
 */
int m29w256gl_auto_manu_id(void)
{
    short temp;

    reset();
    unlock();
    writew(0x0090, CS_BASE + (0x555 << 1));
    temp = MANU_ID_AD;

    printf("MANU_ID = 0x%x\n", temp);   // uncomment for debug purposes

    reset();
    if (temp == MANU_ID) {
        printf("  WEIM NOR flash Manufacturer ID correct \n");
        return 0;
    } else {
        printf("  **Manufacturer ID is not correct, it read back as 0x%x\n", temp);
        printf("  **But it should be: 0x%x\n", MANU_ID);
        return 1;
    }
}

/*!
 * This function reads and checks the device ID of the Numonyx M29W256GL NOR flash.
 * 
 * @return 0 on success; non-zero otherwise
 */
int m29w256gl_auto_dev_id(void)
{
    short temp[3];

    reset();
    unlock();
    writew(0x0090, CS_BASE + (0x555 << 1));

    temp[0] = readw(DEV_ID_AD_1);
    temp[1] = readw(DEV_ID_AD_2);
    temp[2] = readw(DEV_ID_AD_3);

    reset();
    printf("DEV_ID = 0x%x, 0x%x, 0x%x\n", temp[0], temp[1], temp[2]);   // uncomment for debug purposes

    if ((temp[0] == DEV_ID_1) && (temp[1] == DEV_ID_2) && (temp[2] == DEV_ID_3)) {
        printf("  WEIM NOR flash Device ID correct \n");
        return 0;
    } else {
        printf("  **Device ID is not correct, it reads back as: 0x%x, 0x%x, 0x%x\n", temp[0],
               temp[1], temp[2]);
        printf("  **But it should be: 0x%x, 0x%x, 0x%x\n", DEV_ID_1, DEV_ID_2, DEV_ID_3);
        return 1;
    }
}
