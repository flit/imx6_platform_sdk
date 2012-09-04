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
ALL_APPS = \
	sdk_unit_test \
	power_modes_test

# Default target.
.PHONY: all
all: $(ALL_APPS) ;

# App targets. All apps depend on the listed subdirectories.
.PHONY: ALL_APPS
$(ALL_APPS): $(SUBDIRS)
	@echo $$'\n'"Building $@..."
	@$(MAKE) $(silent_make) -r -C apps/$@
	@echo $$'\n'"Build of $@ passed for $(TARGET) $(BOARD) rev $(BOARD_REVISION)!"$$'\n'

$(SUBDIRS)::
	@echo $$'\n'"Building $@..."

# Target to clean everything.
.PHONY: clean
clean:
	@echo "Deleting output directory..."
	@rm -rf output
	@echo "done."

# Target to clean just the sdk. Actually, it cleans any libraries for the target, so the
# board libraries will be cleaned, too.
.PHONY: clean_sdk
clean_sdk:
ifdef TARGET
	rm -rf $(OUTPUT_ROOT)/lib
else
	rm -rf $(SDK_ROOT)/output/*/lib
endif

# Target to clean the board library and objects.
.PHONY: clean_board
clean_board:
	rm -rf $(LIBBOARD) $(OUTPUT_ROOT)/lib/obj/board/$(TARGET)/$(BOARD_WITH_REV)

# Set up targets to clean each of the applications. For an app "foo", the target to clean
# just that app is "clean_foo". If no TARGET is passed to make, the app is cleaned
# for all targets.
ALL_APP_CLEAN_TARGETS := $(addprefix clean_,$(ALL_APPS))
.PHONY: $(ALL_APP_CLEAN_TARGETS)
$(ALL_APP_CLEAN_TARGETS):
ifdef TARGET
ifdef BOARD
ifdef BOARD_REVISION
ifdef BOARD_REVISION_IS_DEFAULT
# Clean all revs of the board.
	rm -rf $(OUTPUT_ROOT)/$(patsubst clean_%,%,$@)/$(BOARD)_rev_*
else
# Specific rev specified so clean just that one rev.
	rm -rf $(OUTPUT_ROOT)/$(patsubst clean_%,%,$@)/$(BOARD_WITH_REV)
endif
else
# Clean all revs of the board.
	rm -rf $(OUTPUT_ROOT)/$(patsubst clean_%,%,$@)/$(BOARD)_rev_*
endif
else
# Clean all boards of the app.
	rm -rf $(OUTPUT_ROOT)/$(patsubst clean_%,%,$@)
endif
else
# Clean all boards and targets of the app.
	rm -rf $(SDK_ROOT)/output/*/$(patsubst clean_%,%,$@)
endif

include mk/targets.mk
