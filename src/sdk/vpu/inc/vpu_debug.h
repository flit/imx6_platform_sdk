/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file vpu_debug.h
 *
 * @brief VPU debug definition
 *
 * @ingroup VPU
 */

#ifndef __VPU_DEBUG_H
#define __VPU_DEBUG_H

#define	DEBUG_LEVEL	0

#define dprintf(level, fmt, arg...)     if (DEBUG_LEVEL >= level) \
        printf("[DEBUG]\t%s:%d " fmt, __FILE__, __LINE__, ## arg)

#define err_msg(fmt, arg...) do { if (DEBUG_LEVEL >= 1)		\
	printf("[ERR]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[ERR]\t" fmt, ## arg);	\
	} while (0)
#define info_msg(fmt, arg...) do { if (DEBUG_LEVEL >= 1)		\
	printf("[INFO]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[INFO]\t" fmt, ## arg);	\
	} while (0)
#define warn_msg(fmt, arg...) do { if (DEBUG_LEVEL >= 1)		\
	printf("[WARN]\t%s:%d " fmt,  __FILE__, __LINE__, ## arg); else \
	printf("[WARN]\t" fmt, ## arg);	\
	} while (0)

#define ENTER_FUNC() dprintf(4, "enter %s()\n", __func__)
#define EXIT_FUNC() dprintf(4, "exit %s()\n", __func__)

#endif
