#
# Top-level Makefile.
#
# This file is responsible for building all libraries and applications.
#

include mk/common.mk

# Library subdirectories that the apps depend upon.
SUBDIRS = sdk

# List of all applications to build.
ALL_APPS = sdk_unit_test power_modes_test

.PHONY: all
all: $(ALL_APPS)
# 	@echo
# 	@echo "Build all passed for $(TARGET) $(BOARD) rev $(BOARD_REVISION)!"
# 	@echo

$(ALL_APPS): $(SUBDIRS)
	@$(MAKE) -s -r -C apps/$@
	@echo
	@echo "Build of $@ passed for $(TARGET) $(BOARD) rev $(BOARD_REVISION)!"
	@echo

.PHONY: clean
clean::
	@echo "Deleting output directory..."
	@rm -rf output
	@echo "done."


include mk/targets.mk
