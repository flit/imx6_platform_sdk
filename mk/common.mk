#-------------------------------------------------------------------------------
# Copyright (c) 2012 Freescale Semiconductor, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# o Redistributions of source code must retain the above copyright notice, this list
#   of conditions and the following disclaimer.
#
# o Redistributions in binary form must reproduce the above copyright notice, this
#   list of conditions and the following disclaimer in the documentation and/or
#   other materials provided with the distribution.
#
# o Neither the name of Freescale Semiconductor, Inc. nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
# Root paths
#-------------------------------------------------------------------------------

# At this point, the path to this makefile was just appended to MAKEFILE_LIST. We make
# use of this to get the root directory of the SDK. This variable is exported to child
# instances of make.
this_makefile := $(firstword $(MAKEFILE_LIST))
export SDK_ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))../)

# The rest of the paths are defined in a separate makefile for easy access.
include $(SDK_ROOT)/mk/paths.mk

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

# Ask the compiler for its version
CC_VERSION := $(shell $(CC) -dumpversion)

# Get the compiler directory. We have to go through this sillyness in order to support
# paths with spaces in their names, such as under Cygwin where the CodeSourcery compiler
# is normally installed under C:\Program Files\.
CC_PREFIX := $(shell dirname "`which $(CC)`")/..

# Standard library include paths.
LIBGCC_LDPATH = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/$(CC_LIB_POST)
LIBC_LDPATH = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/lib/$(CC_LIB_POST)

# System header file include paths.
CC_INCLUDE = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include
CC_INCLUDE_FIXED = $(CC_PREFIX)/lib/gcc/$(CROSS_COMPILE_STRIP)/$(CC_VERSION)/include-fixed
LIBC_INCLUDE = $(CC_PREFIX)/$(CROSS_COMPILE_STRIP)/include

#-------------------------------------------------------------------------------
# Target and board configuration
#-------------------------------------------------------------------------------

include $(SDK_ROOT)/mk/config.mk

#-------------------------------------------------------------------------------
# Compiler flags
#-------------------------------------------------------------------------------

include $(SDK_ROOT)/mk/flags.mk

