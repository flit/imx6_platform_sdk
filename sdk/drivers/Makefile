include $(SDK_ROOT)/mk/common.mk


# Determine if the target is either the MX6DQ or MX6SDL.
ifeq "$(TARGET)" "mx6dq"
is_dq_or_sdl = 1
endif
ifeq "$(TARGET)" "mx6sdl"
is_dq_or_sdl = 1
endif

define SOURCES
audio/src/cs42888.c
audio/src/imx_esai.c
audio/src/imx_spdif.c
audio/src/imx-audmux.c
audio/src/imx-ssi.c
audio/src/sgtl5000.c
audio/src/snd_card.c
camera/src/camera_profile.c
camera/src/smd_sensor.c
cpu_utility/src/cpu_get_cores.c
eim/src/eim.c
gic/src/gic.c
gpio/src/gpio.c
i2c/src/imx_i2c_slave.c
i2c/src/imx_i2c.c
keypad/src/keypad_port.c
ocotp/src/ocotp.c
pmu/src/pmu_driver.cpp
pwm/src/pwm.c
rtc/src/rtc.c
rtc/src/srtc.c
sdma/src/sdma_script_info.c
sdma/src/sdma.c
snvs/src/snvs.c
spi/src/ecspi.c
tempmon/src/tempmon.c
timer/src/epit.c
timer/src/gpt.c
timer/src/timer.c
uart/src/imx_uart.c
usb/src/mx6x_usb.c
usb/src/usb_common.c
usb/src/usbd_drv.c
usb/src/usbh_drv.c
usdhc/src/usdhc_host.c
usdhc/src/usdhc_mmc.c
usdhc/src/usdhc_sd.c
usdhc/src/usdhc.c
endef

# Only the MX6DQ has SATA.
ifeq "$(TARGET)" "mx6dq"
SOURCES += sata/src/sata.c
endif

# Add drivers that are only available of mx6dq or mx6sdl.
ifdef is_dq_or_sdl
SOURCES += \
	enet/src/enet_drv.c \
	flexcan/src/can.c \
	gpu/src/rotate_texture.c \
	gpu/src/sdk_gpu_utilities.c \
	gpu/src/sdk_ipu_common.c \
	gpu/src/texture.c \
	gpmi/src/bch_ecc.c \
	gpmi/src/gpmi_dma_components.cpp \
	gpmi/src/gpmi_dma_isr.cpp \
	gpmi/src/gpmi_dma_sequences.cpp \
	gpmi/src/gpmi_nand_operations.cpp \
	gpmi/src/gpmi.cpp \
	hdmi/src/hdmi_common.c \
	hdmi/src/hdmi_tx_audio.c \
	hdmi/src/hdmi_tx_phy.c \
	hdmi/src/hdmi_tx.c \
	ipu/src/ips_disp_panel.c \
	ipu/src/ipu_common.c \
	ipu/src/ipu_csi.c \
	ipu/src/ipu_dc.c \
	ipu/src/ipu_di.c \
	ipu/src/ipu_dmfc.c \
	ipu/src/ipu_dp.c \
	ipu/src/ipu_ic.c \
	ipu/src/ipu_idmac.c \
	ldb/src/ldb.c \
	mipi/src/mipi_csi2_common.c \
	mipi/src/mipi_dsi_common.c \
	mipi/src/ov5640_mipi_fm.c \
	pcie/src/pcie_phy.c \
	pcie/src/pcie_prot.c \
	pcie/src/pcie.c \
	vdoa/src/vdoa.c \
	video/src/adv7180.c \
	vpu/src/vpu_gdi.c \
	vpu/src/vpu_io.c \
	vpu/src/vpu_lib.c \
	vpu/src/vpu_util.c
endif


include $(SDK_ROOT)/mk/targets.mk
