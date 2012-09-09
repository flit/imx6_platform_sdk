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
# OS
#-------------------------------------------------------------------------------

# Get the OS name. Known values are "Linux", "CYGWIN_NT-5.1", and "Darwin".
os_name := $(shell uname -s)

# Set to 1 if running on cygwin.
is_cygwin := $(and $(findstring CYGWIN,$(os_name)),1)

# Set to 1 if running on redhat.
is_redhat := $(shell if [ -f /etc/redhat-release ]; then echo 1 ; fi)

#-------------------------------------------------------------------------------
# Logging options
#-------------------------------------------------------------------------------

# Enable color output by default.
BUILD_SDK_COLOR ?= 1

# Normally, commands in recipes are prefixed with '@' so the command itself
# is not echoed by make. But if VERBOSE is defined (set to anything non-empty),
# then the '@' is removed from recipes. The 'at' variable is used to control
# this. Similarly, 'silent_make' is used to pass the -s option to child make
# invocations when not in VERBOSE mode.
ifeq "$(VERBOSE)" "1"
at :=
silent_make :=
else
at := @
silent_make := -s
endif

# These colors must be printed with the printf command. echo won't handle the
# escape sequences.
color_default = \033[00m
color_bold = \033[01m
color_red = \033[31m
color_green = \033[32m
color_yellow = \033[33m
color_blue = \033[34m
color_magenta = \033[35m
color_cyan = \033[36m

ifeq "$(BUILD_SDK_COLOR)" "1"
color_build := $(color_bold)$(color_blue)
color_c := $(color_green)
color_cpp := $(color_green)
color_asm := $(color_magenta)
color_ar := $(color_yellow)
color_link := $(color_cyan)
endif

#-------------------------------------------------------------------------------
# Root paths
#-------------------------------------------------------------------------------

# At this point, the path to this makefile was just appended to MAKEFILE_LIST. We make
# use of this to get the root directory of the SDK. This variable is exported to child
# instances of make.
this_makefile := $(firstword $(MAKEFILE_LIST))
export SDK_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../)

# Build root directory paths.
SDK_LIB_ROOT = $(SDK_ROOT)/sdk
APPS_ROOT = $(SDK_ROOT)/apps
BOARD_ROOT = $(SDK_ROOT)/board/$(TARGET)/$(BOARD)

# Build output directory paths.
#
# All output goes under the top-level 'output' directory. Libraries are not board-specific,
# but apps are. Everything is chip-specific. Objects for both libs and apps are placed in
# an 'obj' directory under either the app or lib output directory.
#
# Libs:     output/<chip>/lib/lib<foo>.a
# Lib objs: output/<chip>/lib/obj/<foo>/...
#
# Apps:     output/<chip>/<app>/<board>/<app>.elf
# App objs: output/<chip>/<app>/<board>/obj/...
#
OUTPUT_ROOT = $(SDK_ROOT)/output/$(TARGET)

LIBS_ROOT = $(OUTPUT_ROOT)/lib
LIB_OBJS_ROOT = $(LIBS_ROOT)/obj/$(TARGET_LIB_NAME)

# Put app build products in their own dir.
APP_OUTPUT_ROOT = $(OUTPUT_ROOT)/$(APP_NAME)/$(BOARD_WITH_REV)
APP_OBJS_ROOT = $(APP_OUTPUT_ROOT)/obj

#-------------------------------------------------------------------------------
# Standard library paths
#-------------------------------------------------------------------------------

LIBSDK = $(LIBS_ROOT)/libsdk.a
LIBBOARD = $(LIBS_ROOT)/libboard_$(BOARD_WITH_REV).a

#-------------------------------------------------------------------------------
# Target and board configuration
#-------------------------------------------------------------------------------

# Handle lower-case versions of the config variables. These are really meant to ease
# manual invocation of make via the command line.
ifdef target
TARGET = $(target)
endif
ifdef board
BOARD = $(board)
endif
ifdef boardrev
BOARD_REVISION = $(boardrev)
endif

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
else ifeq "$(BOARD)" "evk"
DEFINES += -DBOARD_EVK
else ifeq "$(BOARD)" "sabre_ai"
DEFINES += -DBOARD_SABRE_AI
else ifeq "$(BOARD)" "sabre_lite"
DEFINES += -DBOARD_SABRE_LITE
else ifeq "$(BOARD)" "smart_device"
DEFINES += -DBOARD_SMART_DEVICE
else ifdef BOARD
$(error Unknown board $(BOARD))
endif

# Board revision, defaults to a if not specified.
ifndef BOARD_REVISION
BOARD_REVISION = a
BOARD_REVISION_IS_DEFAULT = yes
endif
ifeq "$(BOARD_REVISION)" "b"
DEFINES +=-DBOARD_VERSION2
else ifeq "$(BOARD_REVISION)" "a"
DEFINES +=-DBOARD_VERSION1
else ifdef BOARD_REVISION
$(error Unknown board revision $(BOARD_REVISION))
endif

# Only define this variable if a board is specified.
ifdef BOARD
BOARD_WITH_REV := $(BOARD)_rev_$(BOARD_REVISION)
endif

# Set this define to 1 if we want to build thumb binaries, or 0 for ARM.
USE_THUMB ?= 0

#-------------------------------------------------------------------------------
# Compiler and tools
#-------------------------------------------------------------------------------

# For all the paths built below, we assume that the Mentor CodeSourcery release of gcc is
# being used. Other distributions of gcc may work, but have not been tested.

# Set compiler version defaults.
CROSS_COMPILE = arm-none-eabi-

# Strip off the trailing '-', resulting in arm-none-eabi
CROSS_COMPILE_STRIP := $(CROSS_COMPILE:%-=%)

# Build tool names.
CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
AR = $(CROSS_COMPILE)ar
OBJCOPY = $(CROSS_COMPILE)objcopy

# Ask the gcc front-end to tell us where libgcc and libc libraries are located. These
# variables must be recursively defined variables since they depend on CFLAGS.
libgcc_default = $(shell $(CC) -print-file-name=libgcc.a)
LIBGCC = $(shell $(CC) $(CFLAGS) -print-file-name=libgcc.a)
LIBC = $(shell $(CC) $(CFLAGS) -print-file-name=libc.a)

# Standard library include paths.
LIBGCC_LDPATH = $(abspath $(dir $(LIBGCC)))
LIBC_LDPATH = $(abspath $(dir $(LIBC)))

# System header file include paths.
LIBC_INCLUDE = $(abspath $(dir $(LIBC))/../include)
CC_INCLUDE = $(abspath $(dir $(libgcc_default))/include)
CC_INCLUDE_FIXED = $(abspath $(dir $(libgcc_default))/include-fixed)

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

ifeq "$(USE_THUMB)" "1"
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
# Use float-abi=softfp for soft floating point api with HW instructions.
# Alternatively, float-abi=hard for hw float instructions and pass float args in float regs.
ARM_FLAGS += -mfloat-abi=softfp

# Build common flags shared by C and C++.
COMMON_FLAGS += $(ARM_FLAGS) $(CDEBUG)

# C flags. Set C99 mode.
CFLAGS += $(COMMON_FLAGS)
CFLAGS += $(C99_FLAGS)

# C++ flags. Disable exceptions and RTTI.
CXXFLAGS += $(COMMON_FLAGS)
CXXFLAGS += -fno-exceptions -fno-rtti

#-------------------------------------------------------------------------------
# Include paths
#-------------------------------------------------------------------------------

# Link against libc and libgcc. Specify paths to libc in newlib build
# directory.  Need to specify libgcc since our linker does not link
# against anything, even compiler libs because of -nostdlib.
LDADD += -lm -lstdc++ -lc -lgcc

# These include paths have to be quoted because they may contain spaces,
# particularly under cygwin.
LDINC += -L '$(LIBGCC_LDPATH)' -L '$(LIBC_LDPATH)'

# Indicate gcc and newlib std includes as -isystem so gcc tags and
# treats them as system directories.
SYSTEM_INC = \
    -isystem $(CC_INCLUDE) \
    -isystem $(CC_INCLUDE_FIXED) \
    -isystem $(LIBC_INCLUDE)

INCLUDES += \
    -I$(SDK_ROOT)/sdk \
    -I$(SDK_ROOT)/sdk/include  \
    -I$(SDK_ROOT)/sdk/include/$(TARGET) \
    -I$(SDK_ROOT)/sdk/drivers \
    -I$(SDK_ROOT)/sdk/common \
    -I$(SDK_ROOT)/sdk/core \
    -I$(SDK_ROOT)/sdk/utility \
    -I$(BOARD_ROOT)

