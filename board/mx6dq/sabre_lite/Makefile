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

include $(SDK_ROOT)/mk/common.mk


TARGET_LIB_NAME := board_$(BOARD_WITH_REV)

SOURCES := \
	$(SDK_ROOT)/board/common/hardware_modules.c \
	$(SDK_ROOT)/board/common/board_io_expanders.c \
	$(SDK_ROOT)/board/common/board_i2c.c \
	$(SDK_ROOT)/board/common/board_audio.c \
	$(SDK_ROOT)/board/common/board_buttons.c \
	$(SDK_ROOT)/board/common/board_camera.c \
	$(SDK_ROOT)/board/common/board_can.c \
	$(SDK_ROOT)/board/common/board_display.c \
	$(SDK_ROOT)/board/common/board_hdmi.c \
	$(SDK_ROOT)/board/common/board_mipi.c \
	$(SDK_ROOT)/board/common/board_nand.c \
	$(SDK_ROOT)/board/common/board_network.c \
	$(SDK_ROOT)/board/common/board_pcie.c \
	$(SDK_ROOT)/board/common/board_sata.c \
	$(SDK_ROOT)/board/common/board_usb.c \
    $(SDK_ROOT)/board/$(TARGET)/$(BOARD)/dcd.c \
	$(wildcard iomux/*.c)


include $(SDK_ROOT)/mk/targets.mk
