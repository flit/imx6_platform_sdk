/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef SDMA_SCRIPT_CODE_H
#define SDMA_SCRIPT_CODE_H

/*!
* SDMA ROM scripts start addresses and sizes
*/

#define start_ADDR   0
#define start_SIZE   22

#define core_ADDR   80
#define core_SIZE   232

#define common_ADDR   312
#define common_SIZE   330

#define ap_2_ap_ADDR   642
#define ap_2_ap_SIZE   41

#define app_2_mcu_ADDR   683
#define app_2_mcu_SIZE   64

#define mcu_2_app_ADDR   747
#define mcu_2_app_SIZE   70

#define uart_2_mcu_ADDR   817
#define uart_2_mcu_SIZE   74

#define shp_2_mcu_ADDR   891
#define shp_2_mcu_SIZE   69

#define mcu_2_shp_ADDR   960
#define mcu_2_shp_SIZE   72

#define uartsh_2_mcu_ADDR   1032
#define uartsh_2_mcu_SIZE   68

#define spdif_2_mcu_ADDR   1100
#define spdif_2_mcu_SIZE   34

#define mcu_2_spdif_ADDR   1134
#define mcu_2_spdif_SIZE   59

#define firi_2_mcu_ADDR   1193
#define firi_2_mcu_SIZE   97

#define mcu_2_firi_ADDR   1290
#define mcu_2_firi_SIZE   79

#define loop_DMAs_routines_ADDR   1369
#define loop_DMAs_routines_SIZE   227

#define test_ADDR   1596
#define test_SIZE   63

#define signature_ADDR   1023
#define signature_SIZE   1

/*!
* SDMA RAM scripts start addresses and sizes
*/

#define mcu_2_ssiapp_ADDR   6144
#define mcu_2_ssiapp_SIZE   98

#define mcu_2_ssish_ADDR   6242
#define mcu_2_ssish_SIZE   89

#define p_2_p_ADDR   6331
#define p_2_p_SIZE   254

#define ssiapp_2_mcu_ADDR   6585
#define ssiapp_2_mcu_SIZE   94

#define ssish_2_mcu_ADDR   6679
#define ssish_2_mcu_SIZE   84

/*!
* SDMA RAM image start address and size
*/

#define RAM_CODE_START_ADDR     6144
#define RAM_CODE_SIZE           619

/*!
* Buffer that holds the SDMA RAM image
*/

static const uint16_t sdma_code[] = {
    0xc1e3, 0x57db, 0x5fe3, 0x57e3, 0x52f3, 0x6a01, 0x008f, 0x00d5,
    0x7d01, 0x008d, 0x05a0, 0x5deb, 0x0478, 0x7d03, 0x0479, 0x7d2c,
    0x7c36, 0x0479, 0x7c1f, 0x56ee, 0x0f00, 0x0660, 0x7d05, 0x6509,
    0x7e43, 0x620a, 0x7e41, 0x9820, 0x620a, 0x7e3e, 0x6509, 0x7e3c,
    0x0512, 0x0512, 0x02ad, 0x0760, 0x7d03, 0x55fb, 0x6dd3, 0x982b,
    0x55fb, 0x1d04, 0x6dd3, 0x6ac8, 0x7f2f, 0x1f01, 0x2003, 0x4800,
    0x7ce4, 0x9853, 0x55fb, 0x6dd7, 0x0015, 0x7805, 0x6209, 0x6ac8,
    0x6209, 0x6ac8, 0x6dd7, 0x9852, 0x55fb, 0x6dd7, 0x0015, 0x0015,
    0x7805, 0x620a, 0x6ac8, 0x620a, 0x6ac8, 0x6dd7, 0x9852, 0x55fb,
    0x6dd7, 0x0015, 0x0015, 0x0015, 0x7805, 0x620b, 0x6ac8, 0x620b,
    0x6ac8, 0x6dd7, 0x7c09, 0x6ddf, 0x7f07, 0x0000, 0x55eb, 0x4d00,
    0x7d07, 0xc1fa, 0x57e3, 0x9806, 0x0007, 0x68cc, 0x680c, 0xc213,
    0xc20a, 0x9803, 0xc1d9, 0xc1e3, 0x57db, 0x5fe3, 0x57e3, 0x52f3,
    0x6a21, 0x008f, 0x00d5, 0x7d01, 0x008d, 0x05a0, 0x5deb, 0x56fb,
    0x0478, 0x7d03, 0x0479, 0x7d2a, 0x7c31, 0x0479, 0x7c20, 0x0b70,
    0x0311, 0x53eb, 0x0f00, 0x0360, 0x7d05, 0x6509, 0x7e37, 0x620a,
    0x7e35, 0x9886, 0x620a, 0x7e32, 0x6509, 0x7e30, 0x0512, 0x0512,
    0x02ad, 0x0760, 0x7c02, 0x5a06, 0x988e, 0x5a26, 0x7f27, 0x1f01,
    0x2003, 0x4800, 0x7ce8, 0x0b70, 0x0311, 0x5313, 0x98af, 0x0015,
    0x7804, 0x6209, 0x5a06, 0x6209, 0x5a26, 0x98ae, 0x0015, 0x0015,
    0x7804, 0x620a, 0x5a06, 0x620a, 0x5a26, 0x98ae, 0x0015, 0x0015,
    0x0015, 0x7804, 0x620b, 0x5a06, 0x620b, 0x5a26, 0x7c07, 0x0000,
    0x55eb, 0x4d00, 0x7d06, 0xc1fa, 0x57e3, 0x9869, 0x0007, 0x680c,
    0xc213, 0xc20a, 0x9866, 0x0b70, 0x0311, 0x5313, 0x076c, 0x7c01,
    0xc1d9, 0x5efb, 0x068a, 0x076b, 0x7c01, 0xc1d9, 0x5ef3, 0x59db,
    0x58d3, 0x018f, 0x0110, 0x390f, 0x008b, 0xc13c, 0x7d2b, 0x5ac0,
    0x5bc8, 0xc14e, 0x7c27, 0x0388, 0x0689, 0x5ce3, 0x0dff, 0x0511,
    0x1dff, 0x05bc, 0x073e, 0x4d00, 0x7d18, 0x0870, 0x0011, 0x077e,
    0x7d09, 0x077d, 0x7d02, 0x5228, 0x98e6, 0x52f8, 0x54db, 0x02bc,
    0x02cc, 0x7c09, 0x077c, 0x7d02, 0x5228, 0x98ef, 0x52f8, 0x54d3,
    0x02bc, 0x02cc, 0x7d09, 0x0400, 0x98dd, 0x008b, 0x52c0, 0x53c8,
    0xc159, 0x7dd6, 0x0200, 0x98cd, 0x08ff, 0x00bf, 0x077f, 0x7d15,
    0x0488, 0x00d5, 0x7d01, 0x008d, 0x05a0, 0x5deb, 0x028f, 0x0212,
    0x0212, 0x3aff, 0x05da, 0x7c02, 0x073e, 0x9918, 0x02a4, 0x02dd,
    0x7d02, 0x073e, 0x9918, 0x075e, 0x9918, 0x55eb, 0x0598, 0x5deb,
    0x52f3, 0x54fb, 0x076a, 0x7d26, 0x076c, 0x7d01, 0x9955, 0x076b,
    0x7c57, 0x0769, 0x7d04, 0x0768, 0x7d02, 0x0e01, 0x992f, 0x5893,
    0x00d6, 0x7d01, 0x008e, 0x5593, 0x05a0, 0x5d93, 0x06a0, 0x7802,
    0x5502, 0x5d04, 0x7c1d, 0x4e00, 0x7c08, 0x0769, 0x7d03, 0x5502,
    0x7e17, 0x993c, 0x5d04, 0x7f14, 0x0689, 0x5093, 0x4800, 0x7d01,
    0x9927, 0x99a0, 0x0015, 0x7806, 0x5502, 0x5d04, 0x074f, 0x5502,
    0x5d24, 0x072f, 0x7c01, 0x99a0, 0x0017, 0x076f, 0x7c01, 0x2001,
    0x5593, 0x009d, 0x0007, 0xd9a7, 0x98f5, 0x6cd3, 0x0769, 0x7d04,
    0x0768, 0x7d02, 0x0e01, 0x9964, 0x5893, 0x00d6, 0x7d01, 0x008e,
    0x5593, 0x05a0, 0x5d93, 0x06a0, 0x7802, 0x5502, 0x6dc8, 0x7c0f,
    0x4e00, 0x7c08, 0x0769, 0x7d03, 0x5502, 0x7e09, 0x9971, 0x6dc8,
    0x7f06, 0x0689, 0x5093, 0x4800, 0x7d01, 0x995c, 0x99a0, 0x999a,
    0x6ac3, 0x0769, 0x7d04, 0x0768, 0x7d02, 0x0e01, 0x9987, 0x5893,
    0x00d6, 0x7d01, 0x008e, 0x5593, 0x05a0, 0x5d93, 0x06a0, 0x7802,
    0x65c8, 0x5d04, 0x7c0f, 0x4e00, 0x7c08, 0x0769, 0x7d03, 0x65c8,
    0x7e09, 0x9994, 0x5d04, 0x7f06, 0x0689, 0x5093, 0x4800, 0x7d01,
    0x997f, 0x99a0, 0x5593, 0x009d, 0x0007, 0x6cff, 0xd9a7, 0x98f5,
    0x0000, 0x54e3, 0x55eb, 0x4d00, 0x7c01, 0x98f5, 0x98dd, 0x54e3,
    0x55eb, 0x0aff, 0x0211, 0x1aff, 0x077f, 0x7c02, 0x05a0, 0x99b4,
    0x009d, 0x058c, 0x05ba, 0x05a0, 0x0210, 0x04ba, 0x04ad, 0x0454,
    0x0006, 0xc1e3, 0x57db, 0x52fb, 0x6ac3, 0x52f3, 0x6a05, 0x008f,
    0x00d5, 0x7d01, 0x008d, 0x05a0, 0x5deb, 0x0478, 0x7d03, 0x0479,
    0x7d2b, 0x7c1e, 0x0479, 0x7c33, 0x56ee, 0x0f00, 0x55fb, 0x0760,
    0x7d02, 0x6dc3, 0x99d5, 0x1d04, 0x6dc3, 0x62c8, 0x7e3c, 0x0660,
    0x7d02, 0x0210, 0x0212, 0x6a09, 0x7f36, 0x0212, 0x6a09, 0x7f33,
    0x0212, 0x6a09, 0x7f30, 0x1f01, 0x2003, 0x4800, 0x7ce7, 0x9a09,
    0x55fb, 0x6dc7, 0x0015, 0x0015, 0x0015, 0x7805, 0x62c8, 0x6a0b,
    0x62c8, 0x6a0b, 0x6dc7, 0x9a08, 0x55fb, 0x6dc7, 0x0015, 0x0015,
    0x7805, 0x62c8, 0x6a0a, 0x62c8, 0x6a0a, 0x6dc7, 0x9a08, 0x55fb,
    0x6dc7, 0x0015, 0x7805, 0x62c8, 0x6a09, 0x62c8, 0x6a09, 0x6dc7,
    0x7c0a, 0x6a28, 0x57db, 0x7f07, 0x0000, 0x55eb, 0x4d00, 0x7d05,
    0xc1fa, 0x57db, 0x99bf, 0xc277, 0x0454, 0xc20a, 0x99ba, 0xc1d9,
    0xc1e3, 0x57db, 0x52f3, 0x6a05, 0x008f, 0x00d5, 0x7d01, 0x008d,
    0x05a0, 0x56fb, 0x0478, 0x7d03, 0x0479, 0x7d29, 0x7c1f, 0x0479,
    0x7c2e, 0x5de3, 0x0d70, 0x0511, 0x55ed, 0x0f00, 0x0760, 0x7d02,
    0x5206, 0x9a33, 0x5226, 0x7e33, 0x0560, 0x7d02, 0x0210, 0x0212,
    0x6a09, 0x7f2d, 0x0212, 0x6a09, 0x7f2a, 0x0212, 0x6a09, 0x7f27,
    0x1f01, 0x2003, 0x4800, 0x7cea, 0x55e3, 0x9a5e, 0x0015, 0x0015,
    0x0015, 0x7804, 0x5206, 0x6a0b, 0x5226, 0x6a0b, 0x9a5d, 0x0015,
    0x0015, 0x7804, 0x5206, 0x6a0a, 0x5226, 0x6a0a, 0x9a5d, 0x0015,
    0x7804, 0x5206, 0x6a09, 0x5226, 0x6a09, 0x7c09, 0x6a28, 0x7f07,
    0x0000, 0x57db, 0x4d00, 0x7d05, 0xc1fa, 0x57db, 0x9a1c, 0xc277,
    0x0454, 0xc20a, 0x9a19
};
#endif
