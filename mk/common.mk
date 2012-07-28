
#-------------------------------------------------------------------------------
# Root paths
#-------------------------------------------------------------------------------

# At this point, the path to this makefile was just appended to MAKEFILE_LIST. We make
# use of this to get the root directory of the SDK. This variable is exported to child
# instances of make.
SDK_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../)
export SDK_ROOT

# Build root directory paths.
SDK_LIB_ROOT = $(SDK_ROOT)/sdk
APPS_ROOT = $(SDK_ROOT)/apps

# Build output directory paths.
#
# Libraries are not board-specific, but apps are.
#
# ./output
# 		mx6dq/
#			lib/
#				libsdk.a
#				libfoobar.a
#				obj/
#					*.o
#			unittest/
#				evb_rev_a/
#					app1.elf
#					obj/
#						*.o
#			obds/
#
OUTPUT_ROOT = $(SDK_ROOT)/output/$(TARGET)

LIBS_ROOT = $(OUTPUT_ROOT)/lib
LIB_OBJS_ROOT = $(LIBS_ROOT)/obj

# Put app build products in their own dir.
APP_OUTPUT_ROOT = $(OUTPUT_ROOT)/$(APP)/$(BOARD)_rev_$(BOARD_REVISION)
APP_OBJS_ROOT = $(APP_OUTPUT_ROOT)/obj

#-------------------------------------------------------------------------------
# Target and board configuration
#-------------------------------------------------------------------------------

# Target
ifeq "$(TARGET)" "mx6dq"
C_DEFINES += -DCHIP_MX6DQ
CPU	= cortex-a9
else ifeq "$(TARGET)" "mx6sdl"
C_DEFINES += -DCHIP_MX6SDL
CPU	= cortex-a9
else ifeq "$(TARGET)" "mx6sl"
C_DEFINES += -DCHIP_MX6SL
CPU	= cortex-a9
else
$(error Unknown target $(TARGET))
endif

# Board
ifeq "$(BOARD)" "evb"
C_DEFINES += -DBOARD_EVB
else ifeq "$(BOARD)" "sabre_ai"
C_DEFINES += -DBOARD_SABRE_AI
else ifeq "$(BOARD)" "sabre_lite"
C_DEFINES += -DBOARD_SABRE_LITE
else ifeq "$(BOARD)" "smart_device"
C_DEFINES += -DBOARD_SMART_DEVICE
else
$(error Unknown board $(BOARD))
endif

# Board revision
ifeq "$(BOARD_REVISION)" "b"
C_DEFINES +=-DBOARD_VERSION2
else ifeq "$(BOARD_REVISION)" "a"
C_DEFINES +=-DBOARD_VERSION1
else
$(error Unknown board revision $(BOARD_REVISION))
endif

BOARD_DIR = $(shell echo $(BOARD)_rev_$(BOARD_REVISION) | tr [:upper:] [:lower:])

# Set this to define if we want to build thumb binaries or 0 for ARM.
USE_THUMB ?= 1

#-------------------------------------------------------------------------------
# Compiler and tools
#-------------------------------------------------------------------------------

CC_VERSION ?= 4.6.3
CROSS_COMPILE ?= arm-none-eabi-

# Strip off the trailing '-', resulting in arm-none-eabi
CROSS_COMPILE_STRIP := $(patsubst %-,%,$(CROSS_COMPILE))

# For this to work, must use the codesourcery 4.6.3 release of GCC.
CC_INCLUDE = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include
CC_INCLUDE_FIXED = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include-fixed
CC_LIB = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/$(CC_LIB_POST)

# CFLAGS += -DIMPRESARIO_PLATFORM_MQX
# enable/disable MUM for tracking system memory usage
#CFLAGS += -DMEMUSAGE_DEBUG

# CONFIG_INC = $(INFRA_ROOT)/config/include
# PROFILE_INC = $(INFRA_ROOT)/config/profiles
# ifeq (x$(CONFIG_STRING), x)
# 	BOARD_INC = $(INFRA_ROOT)/config/boards/$(BOARD)
# endif

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
OBJCOPY = $(CROSS_COMPILE)objcopy


#CC_PREFIX ?= /opt/arm-eabi
CC_PREFIX ?= $(dir $(shell which $(CC)))..

# CodeSourcery ARM EABI compiler already includes newlib libc.  Use this.
LIBC_LDPATH = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/lib/$(CC_LIB_POST)
LIBC_CFLAGS = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/include

# first:
# 	@echo $(SDK_ROOT)
# 	@echo $(SDK_LIB_ROOT)
# 	@echo $(CC_PREFIX)
# 	@echo $(CC_LIB)
# 	@echo $(CC_INCLUDE)
# 	@echo $(CC_INCLUDE_FIXED)
# 	@echo $(C_DEFINES)

#-------------------------------------------------------------------------------
# Compiler flags
#-------------------------------------------------------------------------------

# Generate debug information.
# Add '-O0' at the end of this line to turn off optimizations.  This can make
# debugging (especially asm) much easier but it greatly increases the size of
# the code and reduces performance.
CDEBUG = -g -O0
#CDEBUG = -g

# Multi-core build
#CFLAGS += -j4

# Turns on all -O2 except size increasers.
# Any CDEBUG settings will come after this and can be used to override.
CFLAGS += -Os
CFLAGS += -mno-unaligned-access


# enables all warnings and treat them as errors except those preceded with -Wno-
C_FLAGS_WARNINGS = -Wall -Werror -Wno-unused-function -fdiagnostics-show-option
C_FLAGS_WARNINGS += -Wno-unused-but-set-variable -Wno-format

# Basic compiler flags. Enable debugging.
# Disable placing globals into the common section.
# COMMON_C_FLAGS = -g -fno-common
# 
# # Optimization flags.
# # No optimization, but turn on dead code elimination.
# OPTIMIZATION_FLAGS = -O0 -fdce

# ARM flags.
# Set the CPU, enable APCS, and enable ARM/thumb interworking.
# Turn on NEON FPU.
ARM_FLAGS = -march=armv7-a -mcpu=$(CPU) -mtune=$(CPU) -mapcs -mthumb-interwork
# ARM_FLAGS += -mfpu=neon -mfloat-abi=softfp

# C flags.
# Set the C standard to C99 with GNU extensions.
# Use traditional GNU inline function semantics.
# C_FLAGS = $(C_FLAGS_WARNINGS) $(ARM_FLAGS) $(COMMON_C_FLAGS) $(OPTIMIZATION_FLAGS)
# C_FLAGS += -std=gnu99 -fgnu89-inline
# 
# # C++ flags. Disable exceptions and RTTI.
# CXX_FLAGS = $(C_FLAGS_WARNINGS) $(ARM_FLAGS) $(COMMON_C_FLAGS) $(OPTIMIZATION_FLAGS)
# CXX_FLAGS += -fno-exceptions -fno-rtti



# Turn on all warnings.
#CFLAGS += -Wall
CFLAGS += $(C_FLAGS_WARNINGS)

# Don't use common symbols.  This is usually done in kernels.  Makes
# code size slightly larger and increases performance.
CFLAGS += -fno-common

# Use a freestanding build environment.  Standard for kernels, implies
# std library may not exist.
CFLAGS += -ffreestanding -fno-builtin

# Don't ever link anything against shared libs.
CFLAGS += -static

# Don't link against the system std library or compiler libraries.
# Everything we link against MUST be specified with -I/-L explicitly.
CFLAGS += -nostdinc -nostdlib

# Set the C standard to C99 with GNU extensions.
# Use traditional GNU inline function semantics.
CFLAGS += -std=gnu99 -fgnu89-inline

# XXX: remove this later after rebuild mp3 decoder and other pre-built
# binaries.
#CFLAGS += -fshort-enums

# Generate code specifically for ARMv7-A, cortex-a8/a5 chip.
#CFLAGS += -march=armv7-a

#CFLAGS += -mtune=cortex-a9

# Always use the aapcs-linux ABI.  This will work for EABI and GNU/Linux.
#CFLAGS += -mabi=aapcs-linux

CFLAGS += $(ARM_FLAGS)

ifeq ($(USE_THUMB), 1)
# Generate thumb2 instructions (mixed 16/32-bit).
	CFLAGS += -mthumb
# Allow mixed ARM and thumb code.  All C code will generate thumb instructions
# but there is hand-written asm that requires ARM.
	CFLAGS += -mthumb-interwork
# Indicate to MQX PSP that we're using thumb.
	CFLAGS += -DUSE_THUMB
	CC_LIB_POST = thumb2
else
# Generate ARM-only code.
	CFLAGS += -marm
	CC_LIB_POST =
endif

# Use NEON SIMD instructions for floating point.  Alternatively can specify
# VFP which gives IEEE 754-compliance (unlike NEON which can have errors).
CFLAGS += -mfpu=neon
# Specify these options with NEON.
CFLAGS += -ftree-vectorize
CFLAGS += -fno-math-errno
CFLAGS += -funsafe-math-optimizations
CFLAGS += -fno-signed-zeros
# Use soft floating point api with HW instructions.
CFLAGS += -mfloat-abi=softfp

# Build with debug symbols enabled by default.  Uncomment to remove.
# This comes last to allow overriding earlier optimization options.
CFLAGS += $(CDEBUG)

CFLAGS += $(C_DEFINES)


# C++ flags.
CXXFLAGS += $(CFLAGS) $(C_DEFINES)

# Disable exceptions and RTTI.
CXXFLAGS += -fno-exceptions -fno-rtti



# define every configuration option using -D flag
# ifneq (x$(CONFIG_STRING), x)
# CFLAGS += $(foreach i,$(CONFIG_STRING),-D$(i))
# endif
# 
# ifneq (x$(BOARD), x)
# CFLAGS += -DBOARD=$(BOARD)
# endif

#CFLAGS += -DBSP_BOARD_TYPE=$(BSP_BOARD_TYPE)

#-------------------------------------------------------------------------------
# Include paths
#-------------------------------------------------------------------------------


# include OSA for Linux and MQX
# INC +=  -I$(OSA_ROOT) \
#         -I$(LIBCOMMON_ROOT)

# ifeq ($(PLATFORM), mqx)
# 	# Indicate gcc and newlib std includes as -isystem so gcc tags and
# 	# treats them as system directories.
# 	SYSTEM_INC = -isystem $(CC_INCLUDE) \
# 		     -isystem $(CC_INCLUDE_FIXED) \
# 		     -isystem $(LIBC_CFLAGS)
# 
# 	ifeq (x$(CONFIG_STRING), x)
# 		SYSTEM_INC += -I$(PROFILE_INC) \
# 			          -I$(BOARD_INC) \
# 			          -I$(CONFIG_INC)
# 	else
# 		SYSTEM_INC += -I$(PROFILE_INC) \
# 			          -I$(CONFIG_INC)
# 	endif
# 
# 	# Global $(INC) variable can be used to include everything.
# 	INC += $(SYSTEM_INC) \
# 
# 	# Link against libc and libgcc.  Specify paths to libc in newlib build
# 	# directory.  Need to specify libgcc since our linker does not link
# 	# against anything, even compiler libs because of -nostdlib.
# 	# XXX: libc and libcs3unhosted have symbols that each rely on the other.
# 	# Need to do this strange double-include to fix that.  Address later.
# 	LDINC += -lc -lcs3unhosted -lc -lcs3 -lcs3arm -lgcc
# 	LDADD += -L$(CC_LIB) -L$(LIBC_LDPATH)
# 
# else
# 	INC += -I$(LINUX_FAKEROOT)/usr/include
# 	# XXX: we only need asound when using Maestro.
# 	LDINC += -lpthread -lrt -lasound
# 	LDADD += -L. -L$(LINUX_FAKEROOT)/usr/lib
# 
# 	ifeq (x$(CONFIG_STRING), x)
# 		INC += -I$(PROFILE_INC) \
# 		       -I$(BOARD_INC) \
# 		       -I$(CONFIG_INC)
# 	else
# 		INC += -I$(PROFILE_INC) \
# 		       -I$(CONFIG_INC)
# 	endif
# 
# 
# endif


LD_FLAGS = $(DEBUG_FLAGS) $(THUMB_FLAGS) -nostartfiles
LD_FLAGS += -lm -lstdc++ -lc -lgcc
LD_FLAGS += -Wl,-Map,$(MAP_FILE)
LD_FLAGS += -T $(LD_FILE)


SYSTEM_INC = -isystem $(CC_INCLUDE) \
		 -isystem $(CC_INCLUDE_FIXED) \
		 -isystem $(LIBC_CFLAGS)

C_INCLUDES = \
    -I$(SDK_ROOT)/sdk/include  \
    -I$(SDK_ROOT)/sdk \
    -I$(SDK_ROOT)/sdk/drivers \
    -I$(SDK_ROOT)/sdk/include/$(TARGET) \
    -I$(SDK_ROOT)/sdk/$(TARGET)/$(BOARD)_rev_$(BOARD_REVISION) \
    -I. \
    -I../inc \
    -I$(SDK_ROOT)/sdk/common/ \
    -I$(SDK_ROOT)/sdk/common/filesystem/ \
    -I$(SDK_ROOT)/sdk/common/filesystem/include \
    -I$(SDK_ROOT)/sdk/common/filesystem/fat/include \
    -I$(SDK_ROOT)/sdk/core \
    -I$(SDK_ROOT)/sdk/utility

A_FLAGS 		=
A_INCLUDES += \
    -I$(SDK_ROOT)/sdk/include \
    -I$(SDK_ROOT)/sdk/include/$(TARGET)/ \
    -I.
A_DEFINES 	=
