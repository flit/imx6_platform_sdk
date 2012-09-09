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


# FAT32 and FS steering API source files.
define SOURCES
steering/fs_steering_read.c 
steering/fs_steering_utility.c 
steering/fs_steering.c
fat/base.c
fat/filegetattrib.c
fat/cache_wrappers.c
fat/fsinit.c
fat/readdevicerecord.c
fat/fatapi.c
fat/handle.c
fat/chdir.c
fat/deletetree.c
fat/findfirst.c
fat/fopen.c
fat/longfilename.c
fat/standardapi.c
fat/fsunicode.c
fat/string_utilities.c
fat/directories.c
fat/findnextsector.c
fat/reentrant_section.c
fat/fs_fat_memory.c
endef

# Extra include paths needed to build the filesystem.
INCLUDES += \
	-I$(SDK_ROOT)/sdk/common/filesystem/ \
    -I$(SDK_ROOT)/sdk/common/filesystem/include \
    -I$(SDK_ROOT)/sdk/common/filesystem/fat/


include $(SDK_ROOT)/mk/targets.mk
