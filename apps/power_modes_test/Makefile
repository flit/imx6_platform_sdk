#
# SDK unit test application
#

include $(SDK_ROOT)/mk/common.mk


# Set up to link application. Subdirectories will archive objects into sdk_unit_test.a
# but not try to link the application executable since LINK_APP is not set.
export APP_NAME = power_modes_test
export APP_LIB_NAME = power_modes_test.a

# Set this to enable linking of the application executable.
LINK_APP = true

# Subdirectories included in the build.
define SUBDIRS
	$(BOARD_ROOT)
endef

# Local source files.
define SOURCES
	$(APPS_ROOT)/common/platform_init.c
	src/power_modes_test.c
endef

# Need to include the SDK library!
LIBRARIES = $(LIBS_ROOT)/libsdk.a

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/common/basic_sdk_app.ld

INCLUDES += -I$(APPS_ROOT)/common


include $(SDK_ROOT)/mk/targets.mk
