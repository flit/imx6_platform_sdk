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


# Provide default value of TEST if not set.
TEST ?= ALL

# Test selection configuration.
ifeq "$(TEST)" "ALL"
DEFINES +=-DALL_TEST_ENABLE
endif

# Pass the selected test name to the unit test app.
DEFINES +=-DSTANDALONE -DSDK_TEST=$(TEST)_test

# Set up to link application. Subdirectories will archive objects into sdk_unit_test.a
# but not try to link the application executable since LINK_APP is not set.
export APP_NAME = sdk_unit_test
export APP_LIB_NAME = sdk_unit_test.a

# Set this to enable linking of the application executable.
LINK_APP = true

# Subdirectories included in the build.
define SUBDIRS
	$(BOARD_ROOT)
	$(SDK_LIB_ROOT)/drivers/audio/test
	$(SDK_LIB_ROOT)/drivers/cpu_utility/test
	$(SDK_LIB_ROOT)/drivers/gic/test
	$(SDK_LIB_ROOT)/drivers/hdmi/test
	$(SDK_LIB_ROOT)/drivers/i2c/test
	$(SDK_LIB_ROOT)/drivers/ipu/test
	$(SDK_LIB_ROOT)/drivers/ocotp/test
	$(SDK_LIB_ROOT)/drivers/pmu/test
	$(SDK_LIB_ROOT)/drivers/rtc/test
	$(SDK_LIB_ROOT)/drivers/sdma/test
	$(SDK_LIB_ROOT)/drivers/tempmon/test
	$(SDK_LIB_ROOT)/drivers/timer/test
	$(SDK_LIB_ROOT)/drivers/uart/test
	$(SDK_LIB_ROOT)/drivers/usdhc/test
	$(SDK_LIB_ROOT)/drivers/vdoa/test
	$(SDK_LIB_ROOT)/drivers/vpu/test
endef

# Tests that are only available on the evb.
ifeq "$(BOARD)" "evb"
	SUBDIRS += \
		$(SDK_LIB_ROOT)/drivers/enet/test \
		$(SDK_LIB_ROOT)/drivers/gpmi/test \
		$(SDK_LIB_ROOT)/drivers/gpu/test \
		$(SDK_LIB_ROOT)/drivers/keypad/test \
		$(SDK_LIB_ROOT)/drivers/pcie/test \
		$(SDK_LIB_ROOT)/drivers/spi/test \
		$(SDK_LIB_ROOT)/drivers/wdog/test
endif

# Tests that apply to either evb or sabre_ai.
ifneq "$(filter evb sabre_ai,$(BOARD))" ""
	SUBDIRS += \
		$(SDK_LIB_ROOT)/drivers/mipi/test \
		$(SDK_LIB_ROOT)/drivers/usb/test
endif

# Tests that are only available on the sabre_ai board.
ifeq "$(BOARD)" "sabre_ai"
	SUBDIRS += \
		$(SDK_LIB_ROOT)/drivers/flexcan/test \
		$(SDK_LIB_ROOT)/drivers/eim/test
endif

# Camera is only available on the smart_device board.
ifeq "$(BOARD)" "smart_device"
	SUBDIRS += \
		$(SDK_LIB_ROOT)/drivers/camera/test \
		$(SDK_LIB_ROOT)/drivers/keypad/test
endif

# PWM is available on all but sabre_lite.
ifneq "$(BOARD)" "sabre_lite"
	SUBDIRS += $(SDK_LIB_ROOT)/drivers/pwm/test
endif

# SATA is only available on the mx6dq.
ifeq "$(TARGET)" "mx6dq"
	SUBDIRS += $(SDK_LIB_ROOT)/drivers/sata/test
endif

# Local source files.
define SOURCES
	$(APPS_ROOT)/common/platform_init.c
	src/unit_test_main.c
	src/all_test.c
endef

# Need to include the SDK library!
LIBRARIES := \
	$(LIBSDK) \
	$(LIBBOARD)

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/common/basic_sdk_app.ld

# Add common to include paths.
INCLUDES += -I$(APPS_ROOT)/common


include $(SDK_ROOT)/mk/targets.mk
