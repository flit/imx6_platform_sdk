#-------------------------------------------------------------------------------
# Copyright (C) 2012 Freescale Semiconductor, Inc. All Rights Reserved.
#
# THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
# SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
# OF SUCH DAMAGE.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Utility
#-------------------------------------------------------------------------------

# Kludge to create a variable equal to a single space.
empty :=
space := $(empty) $(empty)

#-------------------------------------------------------------------------------
# Root paths
#-------------------------------------------------------------------------------

# At this point, the path to this makefile was just appended to MAKEFILE_LIST. We make
# use of this to get the root directory of the SDK. This variable is exported to child
# instances of make.
export SDK_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../)

# Build root directory paths.
SDK_LIB_ROOT = $(SDK_ROOT)/sdk
APPS_ROOT = $(SDK_ROOT)/apps
BOARD_ROOT = $(SDK_ROOT)/board/$(TARGET)/$(BOARD)

# Build output directory paths.
#
# All output goes under the top-level 'output' directory. Libraries are not board-specific,
# but apps are. Everything is chip-specific.
#
# Libs: output/<chip>/lib/lib<foo>.a
# Apps: output/<chip>/<app>/<board>/<app>.elf
#
# Objects for both libs and apps are placed in an 'obj' directory under either the app
# or lib output directory.
#
OUTPUT_ROOT = $(SDK_ROOT)/output/$(TARGET)

LIBS_ROOT = $(OUTPUT_ROOT)/lib
LIB_OBJS_ROOT = $(LIBS_ROOT)/obj

# Put app build products in their own dir.
APP_OUTPUT_ROOT = $(OUTPUT_ROOT)/$(APP_NAME)/$(BOARD_WITH_REV)
APP_OBJS_ROOT = $(APP_OUTPUT_ROOT)/obj

#-------------------------------------------------------------------------------
# Target and board configuration
#-------------------------------------------------------------------------------

# Target
ifeq "$(TARGET)" "mx6dq"
DEFINES += -DCHIP_MX6DQ
CPU	= cortex-a9
else ifeq "$(TARGET)" "mx6sdl"
DEFINES += -DCHIP_MX6SDL
CPU	= cortex-a9
else ifeq "$(TARGET)" "mx6sl"
DEFINES += -DCHIP_MX6SL
CPU	= cortex-a9
else ifdef TARGET
$(error Unknown target $(TARGET))
endif

# Board
ifeq "$(BOARD)" "evb"
DEFINES += -DBOARD_EVB
else ifeq "$(BOARD)" "sabre_ai"
DEFINES += -DBOARD_SABRE_AI
else ifeq "$(BOARD)" "sabre_lite"
DEFINES += -DBOARD_SABRE_LITE
else ifeq "$(BOARD)" "smart_device"
DEFINES += -DBOARD_SMART_DEVICE
else ifdef BOARD
$(error Unknown board $(BOARD))
endif

# Board revision
ifeq "$(BOARD_REVISION)" "b"
DEFINES +=-DBOARD_VERSION2
else ifeq "$(BOARD_REVISION)" "a"
DEFINES +=-DBOARD_VERSION1
else ifdef BOARD_REVISION
$(error Unknown board revision $(BOARD_REVISION))
endif

BOARD_WITH_REV := $(BOARD)_rev_$(BOARD_REVISION)

# Set this to define if we want to build thumb binaries or 0 for ARM.
USE_THUMB ?= 0

#-------------------------------------------------------------------------------
# Compiler and tools
#-------------------------------------------------------------------------------

# Set compiler version defaults.
CC_VERSION ?= 4.6.3
CROSS_COMPILE ?= arm-none-eabi-

# Strip off the trailing '-', resulting in arm-none-eabi
CROSS_COMPILE_STRIP := $(patsubst %-,%,$(CROSS_COMPILE))

# For this to work, must use the codesourcery release of GCC.
CC_INCLUDE = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include
CC_INCLUDE_FIXED = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include-fixed
CC_LIB = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/$(CC_LIB_POST)

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
OBJCOPY = $(CROSS_COMPILE)objcopy

# Get the compiler directory.
CC_PREFIX ?= $(dir $(shell which $(CC)))..

# CodeSourcery ARM EABI compiler already includes newlib libc.  Use this.
LIBC_LDPATH = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/lib/$(CC_LIB_POST)
LIBC_CFLAGS = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/include

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
COMMON_FLAGS += -Os
COMMON_FLAGS += -mno-unaligned-access

# Turn on dead code elimination.
COMMON_FLAGS += -fdce

# Enables all warnings and treat them as errors except those preceded with -Wno-
C_FLAGS_WARNINGS = -Wall -Werror -Wno-unused-function -fdiagnostics-show-option
C_FLAGS_WARNINGS += -Wno-unused-but-set-variable -Wno-format

# Turn on all warnings.
COMMON_FLAGS += $(C_FLAGS_WARNINGS)

# Don't use common symbols.  This is usually done in kernels.  Makes
# code size slightly larger and increases performance.
COMMON_FLAGS += -fno-common

# Use a freestanding build environment.  Standard for kernels, implies
# std library may not exist.
COMMON_FLAGS += -ffreestanding -fno-builtin

# Don't ever link anything against shared libs.
COMMON_FLAGS += -static

# Don't link against the system std library or compiler libraries.
# Everything we link against MUST be specified with -I/-L explicitly.
#COMMON_FLAGS += -nostdinc -nostdlib

# Set the C standard to C99 with GNU extensions.
# Use traditional GNU inline function semantics.
C99_FLAGS = -std=gnu99 -fgnu89-inline

# Generate code specifically for ARMv7-A, cortex-ax CPU.
# Use the ARM Procedure Call Standard.
ARM_FLAGS = -march=armv7-a -mcpu=$(CPU) -mtune=$(CPU) -mapcs

ifeq ($(USE_THUMB), 1)
# Generate thumb2 instructions (mixed 16/32-bit).
	ARM_FLAGS += -mthumb
# Allow mixed ARM and thumb code.  All C code will generate thumb instructions
# but there is hand-written asm that requires ARM.
	ARM_FLAGS += -mthumb-interwork
# Indicate to MQX PSP that we're using thumb.
	ARM_FLAGS += -DUSE_THUMB
	CC_LIB_POST = thumb2
else
# Generate ARM-only code.
	ARM_FLAGS += -marm
	CC_LIB_POST =
endif

# Use NEON SIMD instructions for floating point.  Alternatively can specify
# VFP which gives IEEE 754-compliance (unlike NEON which can have errors).
ARM_FLAGS += -mfpu=neon
# Specify these options with NEON.
ARM_FLAGS += -ftree-vectorize
ARM_FLAGS += -fno-math-errno
ARM_FLAGS += -funsafe-math-optimizations
ARM_FLAGS += -fno-signed-zeros
# Use hw float instructions and pass float args in regs.
# Alternatively, float-abi=softfp for soft floating point api with HW instructions.
ARM_FLAGS += -mfloat-abi=softfp
#hard

# Build common flags shared by C and C++.
COMMON_FLAGS += $(ARM_FLAGS) $(CDEBUG)

# C flags. Set C99 mode.
CFLAGS = $(COMMON_FLAGS)
CFLAGS += $(C99_FLAGS)

# C++ flags. Disable exceptions and RTTI.
CXXFLAGS = $(COMMON_FLAGS)
CXXFLAGS += -fno-exceptions -fno-rtti

#-------------------------------------------------------------------------------
# Include paths
#-------------------------------------------------------------------------------

# Link against libc and libgcc. Specify paths to libc in newlib build
# directory.  Need to specify libgcc since our linker does not link
# against anything, even compiler libs because of -nostdlib.
LDADD += -lm -lstdc++ -lc -lgcc
LDINC += -L$(CC_LIB) -L$(LIBC_LDPATH)

# Indicate gcc and newlib std includes as -isystem so gcc tags and
# treats them as system directories.
# SYSTEM_INC = -isystem $(CC_INCLUDE) \
# 		 -isystem $(CC_INCLUDE_FIXED) \
# 		 -isystem $(LIBC_CFLAGS)

INCLUDES += \
    -I$(SDK_ROOT)/sdk \
    -I$(SDK_ROOT)/sdk/include  \
    -I$(SDK_ROOT)/sdk/include/$(TARGET) \
    -I$(SDK_ROOT)/sdk/drivers \
    -I$(SDK_ROOT)/sdk/common \
    -I$(SDK_ROOT)/sdk/core \
    -I$(SDK_ROOT)/sdk/utility \
    -I$(BOARD_ROOT)


