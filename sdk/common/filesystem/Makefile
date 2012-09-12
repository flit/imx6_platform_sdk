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
fat/base.c
fat/cache_wrappers.c
fat/chdir.c
fat/deletetree.c
fat/directories.c
fat/fatapi.c
fat/filegetattrib.c
fat/findfirst.c
fat/findnextsector.c
fat/fopen.c
fat/fs_fat_memory.c
fat/fs_steering.c
fat/fsinit.c
fat/fsunicode.c
fat/handle.c
fat/longfilename.c
fat/readdevicerecord.c
fat/reentrant_section.c
fat/standardapi.c
fat/string_utilities.c
endef

# Extra include paths needed to build the filesystem.
INCLUDES += \
	-I$(SDK_ROOT)/sdk/common/filesystem/ \
    -I$(SDK_ROOT)/sdk/common/filesystem/include \
    -I$(SDK_ROOT)/sdk/common/filesystem/fat/


include $(SDK_ROOT)/mk/targets.mk
