include $(SDK_ROOT)/mk/common.mk


ifneq "$(TARGET)" "mx6sl"
define SOURCES
	adv7180_capture.c
	camera_test.c
	sensor_capture.c
endef
endif

ifeq "$(TARGET)" "mx6sl"
define SOURCES
	camera_test.c
	csi_sensor_capture.c
endef
endif

include $(SDK_ROOT)/mk/targets.mk
