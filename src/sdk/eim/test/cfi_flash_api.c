/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "cfi_flash.h"

extern flash_info_t flash_info[];
extern int flash_real_protect(flash_info_t *, int, int);
extern int write_buff(flash_info_t *, uint8_t *, uint32_t, uint32_t);

static flash_info_t *addr2info(uint32_t addr)
{
    flash_info_t *info;
    int i;

    for (i = 0, info = &flash_info[0]; i < CFG_MAX_FLASH_BANKS; ++i, ++info) {
        if (info->flash_id != FLASH_UNKNOWN && addr >= info->start[0] &&
            addr <= info->start[0] + info->size - 1) {
            return (info);
        }
    }

    return (0);
}

void flash_protect(int flag, uint32_t from, uint32_t to, flash_info_t * info)
{
    uint32_t b_end = info->start[0] + info->size - 1;
    short s_end = info->sector_count - 1;
    int i;

    flash_print("flash_protect %s: from 0x%8x to 0x%8x\n",
                (flag & FLAG_PROTECT_SET) ? "ON" :
                (flag & FLAG_PROTECT_CLEAR) ? "OFF" : "???", from, to);

    if (info->sector_count == 0 || info->size == 0 || to < from) {
        return;
    }

    if (info->flash_id == FLASH_UNKNOWN || to < info->start[0] || from > b_end) {
        return;
    }

    for (i = 0; i < info->sector_count; ++i) {
        uint32_t end;           /* last address in current sect */

        end = (i == s_end) ? b_end : info->start[i + 1] - 1;

        if (from <= end && to >= info->start[i]) {
            if (flag & FLAG_PROTECT_CLEAR) {
#if defined(CFG_FLASH_PROTECTION)
                flash_real_protect(info, i, 0);
#else
                info->protect[i] = 0;
#endif /* CFG_FLASH_PROTECTION */
                flash_print("protect off %d\n", i);
            } else if (flag & FLAG_PROTECT_SET) {
#if defined(CFG_FLASH_PROTECTION)
                flash_real_protect(info, i, 1);
#else
                info->protect[i] = 1;
#endif /* CFG_FLASH_PROTECTION */
                flash_print("protect on %d\n", i);
            }
        }
    }
}

int flash_write(uint8_t * src, uint32_t addr, uint32_t cnt)
{
    int i;
    uint32_t end = addr + cnt - 1;
    flash_info_t *info_first = addr2info(addr);
    flash_info_t *info_last = addr2info(end);
    flash_info_t *info;

    if (cnt == 0) {
        return (ERR_OK);
    }

    if (!info_first || !info_last) {
        return (ERR_INVAL);
    }

    for (info = info_first; info <= info_last; ++info) {
        uint32_t b_end = info->start[0] + info->size;
        short s_end = info->sector_count - 1;
        for (i = 0; i < info->sector_count; ++i) {
            uint32_t e_addr = (i == s_end) ? b_end : info->start[i + 1];

            if ((end >= info->start[i]) && (addr < e_addr) && (info->protect[i] != 0)) {
                return (ERR_PROTECTED);
            }
        }
    }

    /* finally write data to flash */
    for (info = info_first; info <= info_last && cnt > 0; ++info) {
        uint32_t len;

        len = info->start[0] + info->size - addr;
        if (len > cnt)
            len = cnt;
        if ((i = write_buff(info, src, addr, len)) != 0) {
            return (i);
        }
        cnt -= len;
        addr += len;
        src += len;
    }
    return (ERR_OK);
}

void flash_perror(int err)
{
    switch (err) {
    case ERR_OK:
        break;
    case ERR_TIMOUT:
        flash_print("Timeout writing to Flash\n");
        break;
    case ERR_NOT_ERASED:
        flash_print("Flash not Erased\n");
        break;
    case ERR_PROTECTED:
        flash_print("Can't write to protected Flash sectors\n");
        break;
    case ERR_INVAL:
        flash_print("Outside available Flash\n");
        break;
    case ERR_ALIGN:
        flash_print("Start and/or end address not on sector boundary\n");
        break;
    case ERR_UNKNOWN_FLASH_VENDOR:
        flash_print("Unknown Vendor of Flash\n");
        break;
    case ERR_UNKNOWN_FLASH_TYPE:
        flash_print("Unknown Type of Flash\n");
        break;
    case ERR_PROG_ERROR:
        flash_print("General Flash Programming Error\n");
        break;
    default:
        flash_print("%s[%d] FIXME: rc=%d\n", __FILE__, __LINE__, err);
        break;
    }
}

int flash_fill_sect_ranges(uint32_t addr_first, uint32_t addr_last, int *s_first, int *s_last,
                           int *s_count)
{
    flash_info_t *info;
    uint32_t bank;
    int rcode = 0;

    *s_count = 0;

    for (bank = 0; bank < CFG_MAX_FLASH_BANKS; ++bank) {
        s_first[bank] = -1;     /* first sector to erase    */
        s_last[bank] = -1;      /* last  sector to erase    */
    }

    for (bank = 0, info = &flash_info[0];
         (bank < CFG_MAX_FLASH_BANKS) && (addr_first <= addr_last); ++bank, ++info) {
        uint32_t b_end;
        int sect;
        short s_end;

        if (info->flash_id == FLASH_UNKNOWN) {
            continue;
        }

        b_end = info->start[0] + info->size - 1;
        s_end = info->sector_count - 1;

        for (sect = 0; sect < info->sector_count; ++sect) {
            uint32_t end;       /* last address in current sect */

            end = (sect == s_end) ? b_end : info->start[sect + 1] - 1;

            if (addr_first > end)
                continue;

            if (addr_first >= info->start[sect]) {
                s_first[bank] = sect;
            }
            if (addr_last - 1 <= end) {
                s_last[bank] = sect;
                break;
            }
        }
        if (s_first[bank] >= 0) {
            if (s_last[bank] < 0) {
                if (addr_last > b_end) {
                    s_last[bank] = s_end;
                } else {
                    puts("Error: end address" " not on sector boundary\n");
                    rcode = 1;
                    break;
                }
            }
            if (s_last[bank] < s_first[bank]) {
                puts("Error: end sector" " precedes start sector\n");
                rcode = 1;
                break;
            }
            sect = s_last[bank];
            addr_first = (sect == s_end) ? b_end + 1 : info->start[sect + 1];
            (*s_count) += s_last[bank] - s_first[bank] + 1;
        } else if (addr_first >= info->start[0] && addr_first < b_end) {
            puts("Error: start address not on sector boundary\n");
            rcode = 1;
            break;
        } else if (s_last[bank] >= 0) {
            puts("Error: cannot span across banks when they are" " mapped in reverse order\n");
            rcode = 1;
            break;
        }
    }

    return rcode;
}

int flash_sects_protect(int p, int *s_first, int *s_last)
{
    flash_info_t *info;
    uint32_t bank;
    int protected, i;
    int rcode = OK;

    protected = 0;

    for (bank = 0, info = &flash_info[0]; bank < CFG_MAX_FLASH_BANKS; ++bank, ++info) {
        if (info->flash_id == FLASH_UNKNOWN)
            continue;

        if (s_first[bank] >= 0 && s_first[bank] <= s_last[bank]) {
            protected += s_last[bank] - s_first[bank] + 1;
            for (i = s_first[bank]; i <= s_last[bank]; ++i) {
#if defined(CFG_FLASH_PROTECTION)
                if (flash_real_protect(info, i, p))
                    rcode = ERR;
#else
                info->protect[i] = p;
#endif /* CFG_FLASH_PROTECTION */
            }
        }
    }

    return rcode;
}

int flash_sects_erase(int *s_first, int *s_last)
{
    flash_info_t *info;
    uint32_t bank;
    int erased = 0;
    int rcode = 0;

    for (bank = 0, info = &flash_info[0];
         (bank < CFG_MAX_FLASH_BANKS) && (rcode == 0); ++bank, ++info) {
        if (s_first[bank] >= 0) {
            erased += s_last[bank] - s_first[bank] + 1;
            rcode = flash_erase(info, s_first[bank], s_last[bank]);
        }
    }

    return rcode;
}
