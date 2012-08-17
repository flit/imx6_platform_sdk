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
# Top-level Makefile.
#
# This file is responsible for building all libraries and applications.
#

include mk/common.mk

# Library subdirectories that the apps depend upon. Handled automatically by targets.mk.
SUBDIRS = sdk

# List of all applications to build. Applications must reside in the apps directory.
ALL_APPS = sdk_unit_test power_modes_test

# Default target.
.PHONY: all
all: $(ALL_APPS)

$(ALL_APPS): $(SUBDIRS)
	@echo $$'\n'"Building $@..."
	@$(MAKE) -s -r -C apps/$@
	@echo $$'\n'"Build of $@ passed for $(TARGET) $(BOARD) rev $(BOARD_REVISION)!"$$'\n'

.PHONY: clean
clean::
	@echo "Deleting output directory..."
	@rm -rf output
	@echo "done."


include mk/targets.mk
