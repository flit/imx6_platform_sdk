#
# Top-level Makefile.
#
# This file is responsible for building all libraries and applications.
#

include mk/common.mk

SUBDIRS = sdk

# Programs contains the directory of programs.  For now there will be a
# top-level Makefile inside that knows how to build them.  This just recurses
# into it.
ALL_APPS = sdk_unit_test

.PHONY: all
all: $(SUBDIRS) $(ALL_APPS)
	@echo
	@echo "Build succeeded!"
	@echo

$(ALL_APPS):
	@$(MAKE) -s -r -C apps/$@

.PHONY: clean
clean::
	@echo "Deleting output directory..."
	@rm -rf output


include mk/targets.mk
