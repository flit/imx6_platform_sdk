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

#
# SDK unit test application
#

include $(SDK_ROOT)/mk/common.mk

# Set up to link application.
export APP_NAME = gpu_demo
export ARCHIVE_APP_OBJECTS = 0

LINK_APP = 1

# Local source files.
define SOURCES
    src/rotate_texture.c
    src/sdk_gpu_utilities.c
	src/texture.c
	src/gpu_test.c
    $(APPS_ROOT)/common/platform_init.c
    $(APPS_ROOT)/common/print_clock_info.c
    $(APPS_ROOT)/common/print_version.c
    $(APPS_ROOT)/common/ivt.c
endef

# Need to include the SDK library!
LIBRARIES = \
    $(LIBSDK) \
    $(LIBBOARD)

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/common/basic_sdk_app.ld

# Add common to include paths.
INCLUDES += -I$(APPS_ROOT)/common -I$(APPS_ROOT)/$(APP_NAME)

# Standard targets.
include $(SDK_ROOT)/mk/targets.mk


