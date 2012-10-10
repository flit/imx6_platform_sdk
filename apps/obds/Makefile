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
# Power test application
#

include $(SDK_ROOT)/mk/common.mk

# Determine if the target is either the MX6DQ or MX6SDL.
ifeq "$(TARGET)" "mx6dq"
is_dq_or_sdl = 1
endif
ifeq "$(TARGET)" "mx6sdl"
is_dq_or_sdl = 1
endif

# Set up to link application.
APP_NAME = obds
LINK_APP = 1

# Local source files.
#    $(wildcard src/tests/*)
#    src/tests/audio_esai_test.c
#    src/tests/ipu_test.c
#    src/tests/sdio_card_test.c
#    src/tests/usb_tests_obds.c
#   src/tests/weim_nor_flash_test.c
define SOURCES
    $(APPS_ROOT)/common/platform_init.c
    $(APPS_ROOT)/common/print_clock_info.c
    $(SDK_LIB_ROOT)/drivers/spi/test/spi_nor_numonyx.c
    $(SDK_LIB_ROOT)/drivers/spi/test/imx_spi_nor_atmel.c
    $(SDK_LIB_ROOT)/drivers/usdhc/test/usdhc_test.c
    src/obds.c
    src/obds_utils.c
    src/tests/ddr_test.c
    src/tests/flexcan_test.c
    src/tests/gps_test.c
    src/tests/i2c_dev_tests.c
    src/tests/i2c_check_light_sensor_isl29023.c
    src/tests/i2c_device_barometer_ppl3115.c
    src/tests/i2c_device_digital_compass_mag3110.c
    src/tests/i2c_device_digital_compass_mag3112.c
    src/tests/i2c_device_id_check_mma8450.c
    src/tests/i2c_device_id_check_mma8451.c
    src/tests/i2c_device_pmic_pf0100.c
    src/tests/i2c_device_temp_sensor_emc1046.c
    src/tests/i2c_device_zigbee_mc1323.c
    src/tests/i2c_eeprom_at24cxx_test.c
    src/tests/imx_spi_nor_test.c
    src/tests/mmcsd_test.c
    src/tests/pmic_da9053.c
    src/tests/pmic_lt3589.c
    src/tests/pmic_max17135.c
    src/tests/pmic_mc13892.c
    src/tests/program_board_id.c
    src/tests/program_mac_address.c
    src/tests/snvs_srtc_test.c
    src/tests/touch_button_test.c
    src/tests/touch_screen.c
    src/tests/touch_screen_max11801.c
    src/tests/uart_test.c
endef

# Add drivers that are only available of mx6dq or mx6sdl.
ifdef is_dq_or_sdl
SOURCES += \
    src/tests/audio_ssi_test.c \
    src/tests/android_buttons_test.c \
    src/tests/deserializer_ds90ur124.c \
    src/tests/enet_mx6dldq_test.c \
    src/tests/fm_tuner_si476x_test.c \
    src/tests/i2c_device_id_check_p1003_tsc.c \
    src/tests/mlb_os81050.c \
    src/tests/video_dec_adv7180.c \
    src/tests/video_dec_ARD_MB_reset_button.c \
    src/tests/video_dec_ARD_MBrst_from_cpu_expander.c
endif

# Need to include the SDK library!
LIBRARIES = \
    $(LIBSDK) \
    $(LIBBOARD)

# Specify our linker script.
LD_FILE = $(APPS_ROOT)/obds/src/obds_sdk_app.ld

# Add common to include paths.
INCLUDES += -I$(APPS_ROOT)/common -I$(APPS_ROOT)/obds/src


include $(SDK_ROOT)/mk/targets.mk
