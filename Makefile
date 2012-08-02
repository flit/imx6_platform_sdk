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
PROGS = 
TESTS = 

.PHONY: all
all: $(SUBDIRS) $(PROGS)
	@echo
	@echo "Build succeeded!"
	@echo

.PHONY: test
test: $(SUBDIRS) $(TESTS)
	@echo
	@echo "Tests built successfully!"
	@echo

$(PROGS):
	$(MAKE) -C apps/$@

$(TESTS):
	$(MAKE) -C test/apps/$@

.PHONY: clean
clean::
	rm -rf output

# 	@for _dir in $(PROGS); do \
# 		$(MAKE) -C apps/$$_dir clean; \
# 	done
# 	@for _dir in $(TESTS); do \
# 		$(MAKE) -C test/apps/$$_dir clean; \
# 	done

include mk/targets.mk
