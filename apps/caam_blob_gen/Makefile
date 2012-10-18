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
# CAAM blob generator for encrypted boot
#

include $(SDK_ROOT)/mk/common.mk

# Set up to link application.
APP_NAME = caam_blob_gen
LINK_APP = 1

# Local source files.
define SOURCES
    $(APPS_ROOT)/common/platform_init.c
    $(APPS_ROOT)/common/ivt.c
    src/caam_blob_gen.c
endef

# Need to include the SDK library!
LIBRARIES = \
    $(LIBSDK) \
    $(LIBBOARD)

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/common/basic_sdk_app.ld.S

# Add common to include paths.
INCLUDES += -I$(APPS_ROOT)/common


include $(SDK_ROOT)/mk/targets.mk
