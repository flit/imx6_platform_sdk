/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IPU_COMMON_H__
#define __IPU_COMMON_H__

#include "gpu_test_common.h"
#include "ipu_reg_def.h"

// IDMAC defines
#define INTERLEAVED_MODE 0
#define NON_INTERLEAVED_MODE 1

#define SHIFT_DISABLE 0
#define SHIFT_ENABLE  1

#define NL 1
#define NF 2
#define NFIELD 3
#define EOF_ 4
#define EOFIELD 5
#define EOL 6
#define NEW_CHAN 7
#define NEW_ADDR 8
#define NEW_DATA 9

#define HLG 1
#define WROD 2
#define HLOAR 3
#define WROAR 4
#define HLODR 5
#define WRODR 6
#define WRBC 7
#define WCLK 8
#define WSTS_III 9
#define WSTS_II 10
#define WSTS_I 11
#define HLOA 12
#define WROA 13
#define HLOD 14
#define WRG 15
#define RD 16
#define WACK 17
#define HMA 18
#define BMA 19
#define MSK 20

void sdk_ipu_write_field(WORD IPU, WORD ID_addr, WORD ID_mask, WORD data);
void ipu_setup_xga(WORD ch23_eba, WORD overlay, WORD ch27_fw, WORD ch27_fh, WORD ch27_eba0,
                   WORD ch27_eba1, WORD ch27_x, WORD ch27_y, WORD global_alpha);

#endif
