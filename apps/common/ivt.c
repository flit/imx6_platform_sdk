/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hab.h"
#include "hab_types.h"
#include "hab_cmd.h"

extern unsigned * _start_image_add;
extern unsigned * __start_boot_data;
extern unsigned * __hab_data;
extern unsigned * _image_size;

extern uint8_t input_dcd_hdr[];

extern void startup(void);

struct hab_ivt input_ivt __attribute__ ((section (".ivt"))) ={
    /** @ref hdr word with tag #HAB_TAG_IVT, length and HAB version fields
     *  (see @ref data)
     */
    IVT_HDR(sizeof(struct hab_ivt), HAB_VER(4, 0)),
    /** Absolute address of the first instruction to execute from the
     *  image
     */
    (hab_image_entry_f)startup,

    /** Reserved in this version of HAB: should be NULL. */
    NULL,
    /** Absolute address of the image DCD: may be NULL. */
    &input_dcd_hdr,
    /** Absolute address of the Boot Data: may be NULL, but not interpreted
     *  any further by HAB
     */
    &__start_boot_data,
    /** Absolute address of the IVT.*/
    (const void*) (&input_ivt),
    /** Absolute address of the image CSF.*/
    (const void*) &__hab_data,
    /** Reserved in this version of HAB: should be zero. */
    0
};

typedef struct {
    uint32_t start;            /**< Start address of the image */
    uint32_t size;             /**< Size of the image */
    uint32_t plugin;           /**< Plugin flag */
} boot_data_t;

boot_data_t bd __attribute__ ((section (".boot_data"))) ={
    (uint32_t) &_start_image_add,
    (uint32_t) &_image_size,
    0,
};

