#ifndef _OS_ERRORDEFS_H
#define _OS_ERRORDEFS_H

#include "errordefs.h"
#include "os_subgroups.h"
//commented out codes are ones that are not being used at all right now.

#define ERROR_OS_KERNEL_GROUP           (ERROR_MASK|OS_KERNEL_GROUP)
#define ERROR_OS_MEMORY_MANAGER_GROUP   (ERROR_MASK|OS_MEMORY_MANAGER_GROUP)
#define ERROR_OS_POWER_MANAGER_GROUP    (ERROR_MASK|OS_POWER_MANAGER_GROUP)
#define ERROR_OS_FILESYSTEM_GROUP       (ERROR_MASK|OS_FILESYSTEM_GROUP)
#define ERROR_OS_EOI_GROUP              (ERROR_MASK|OS_EOI_GROUP)
#define ERROR_OS_VMI_GROUP              (ERROR_MASK|OS_VMI_GROUP)
#define ERROR_OS_SYSMGR_GROUP           (ERROR_MASK|OS_SYSMGR_GROUP)

#endif//_OS_ERRORDEFS_H 

