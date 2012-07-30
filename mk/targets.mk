# Select our object root depending on whether we're building an app or lib.
ifneq "$(APP)" ""
OBJS_ROOT = $(APP_OBJS_ROOT)
else
OBJS_ROOT = $(LIB_OBJS_ROOT)
endif

# Kludge to create a variable equal to a single space.
empty :=
space := $(empty) $(empty)

# Strip sources.
SOURCES := $(strip $(SOURCES))

# Convert sources list to absolute paths and relative paths.
SOURCES_ABS := $(foreach s,$(SOURCES),$(abspath $(s)))
SOURCES_REL := $(subst $(SDK_ROOT)/,,$(SOURCES_ABS))

# Get a list of directories containing the source files.
SOURCE_DIRS_ABS := $(sort $(foreach f,$(SOURCES_ABS),$(dir $(f))))
SOURCE_DIRS_REL := $(subst $(SDK_ROOT)/,,$(SOURCE_DIRS_ABS))

OBJECTS_DIRS := $(addprefix $(OBJS_ROOT)/,$(SOURCE_DIRS_REL))

# Filter source files list into separate source types.
C_SOURCES = $(filter %.c,$(SOURCES_REL))
CXX_SOURCES = $(filter %.cpp,$(SOURCES_REL))
ASM_s_SOURCES = $(filter %.s,$(SOURCES_REL))
ASM_S_SOURCES = $(filter %.S,$(SOURCES_REL))

# Convert sources to objects.
OBJECTS_C := $(addprefix $(OBJS_ROOT)/,$(C_SOURCES:.c=.o))
OBJECTS_CXX := $(addprefix $(OBJS_ROOT)/,$(CXX_SOURCES:.c=.o))
OBJECTS_ASM := $(addprefix $(OBJS_ROOT)/,$(ASM_s_SOURCES:.s=.o))
OBJECTS_ASM_S := $(addprefix $(OBJS_ROOT)/,$(ASM_S_SOURCES:.S=.o))

# Complete list of all object files.
OBJECTS_ALL := $(OBJECTS_LDS) $(OBJECTS_C) $(OBJECTS_CXX) $(OBJECTS_ASM) $(OBJECTS_ASM_S)

# Build the target lib path from the lib name.
ifneq "$(TARGET_LIB_NAME)" ""
TARGET_LIB ?= $(LIBS_ROOT)/$(TARGET_LIB_NAME)
endif

# --> Default recipe!
#
# Note that prerequisite order is important here. The subdirectories must be built first, or you
# may end up with files in the current directory not getting added to libraries. This would happen
# if subdirs modified the library file after local files were compiled but before they were added
# to the library.
.PHONY: all
all : echovars $(SUBDIRS) $(OBJS_ROOT) $(OBJECTS_DIRS) $(OBJECTS_ALL) $(LIBS) $(APP) $(TARGET_LIB)

.PHONY: echovars
echovars:
# 	@echo SOURCES = $(SOURCES)
# 	@echo SOURCES_ABS = $(SOURCES_ABS)
# 	@echo SOURCES_REL = $(SOURCES_REL)
# 	@echo SOURCE_DIRS_PATH = $(SOURCE_DIRS_PATH)
# 	@echo OBJECTS_DIRS = $(OBJECTS_DIRS)
# 	@echo C_SOURCES = $(C_SOURCES)
# 	@echo OBJECTS_C = $(OBJECTS_C)

# Recipe to create the output directory.
$(OBJS_ROOT) $(OBJECTS_DIRS) :
	@mkdir -p $@

# Pattern rules for compilation.

$(OBJS_ROOT)/%.o: $(SDK_ROOT)/%.c
#%.o: %.c
# Generate make dependencies and compile. The -MP option creates empty targets
# for each header file so that a rebuild will be forced if the file goes missing, but
# no error will occur.
	@echo Compiling $(subst $(SDK_ROOT)/,,$<)
	@$(CC) $(CFLAGS) $(SYSTEM_INC) $(C_INCLUDES) $(C_DEFINES) -MMD -MF $(basename $@).d -MP -o $@ -c $<

$(OBJS_ROOT)/%.o: $(SDK_ROOT)/%.cpp
# Generate make dependencies and compile. The -MP option creates empty targets
# for each header file so that a rebuild will be forced if the file goes missing, but
# no error will occur.
	@echo Compiling $(subst $(SDK_ROOT)/,,$<)
	@$(CXX) $(CXXFLAGS) $(SYSTEM_INC) $(C_INCLUDES) $(C_DEFINES) -MMD -MF $(basename $@).d -MP -o $@ -c $<

# For .S assembly files, first run through the C preprocessor then assemble.
$(OBJS_ROOT)/%.o: $(SDK_ROOT)/%.S
	@echo Compiling $(subst $(SDK_ROOT)/,,$<)
	@$(CPP) -D__LANGUAGE_ASM__ $(C_INCLUDES) $(C_DEFINES) -o $(basename $@).s $<
	@$(AS) $(A_FLAGS) $(C_INCLUDES) $(A_DEFINES) -MD $(OBJS_ROOT)/$*.d -o $@ $(basename $@).s

$(OBJS_ROOT)/%.o: $(SDK_ROOT)/%.s
	@echo Compiling $(subst $(SDK_ROOT)/,,$<)
	@$(AS) $(A_FLAGS) $(C_INCLUDES) $(A_DEFINES) -MD $(basename $@).d -o $@ $<


# $(OBJECTS): %.o: %.c
# 	$(CC) -c $(CFLAGS) $(INC) $< -o $@
# 	$(CC) -MM $(CFLAGS) $(INC) $*.c > $*.d
# 
# $(OBJECTS_ASM): %.o: %.S
# 	$(CC) -c $(CFLAGS) -D__ASM__ $(INC) $< -o $@
# 	$(CC) -MM $(CFLAGS) -D__ASM__ $(INC) $*.S > $*.d
# 
# $(OBJECTS_LDS): $(OBJECTS_LDS).S $(FILES_RELA_LDS)
# 	$(CC) -s $(OBJECTS_LDS).S $(CFLAGS) -E -P -D__ASM__ $(INC) -o $(OBJECTS_LDS)


# $(OBJS_ROOT)/%.o: %.c
# # Generate make dependencies and compile. The -MP option creates empty targets
# # for each header file so that a rebuild will be forced if the file goes missing, but
# # no error will occur.
# #	@echo Compiling $(addprefix $(MODULE_REL_DIR)$(MODULE)/,$<)
# 	@echo Compiling $<
# 	@$(CC) $(CFLAGS) $(SYSTEM_INC) $(C_INCLUDES) $(C_DEFINES) -MMD -MF $(OBJS_ROOT)/$(basename $@).d -MP -o $@ -c $<
# 
# $(OBJS_ROOT)/%.o: %.cpp
# # Generate make dependencies and compile. The -MP option creates empty targets
# # for each header file so that a rebuild will be forced if the file goes missing, but
# # no error will occur.
# 	@echo Compiling $<
# 	@$(CXX) $(CXXFLAGS) $(SYSTEM_INC) $(C_INCLUDES) $(C_DEFINES) -MMD -MF $(OBJS_ROOT)/$*.d -MP -o $@ -c $<
# 
# # For .S assembly files, first run through the C preprocessor then assemble.
# $(OBJS_ROOT)/%.o: %.S
# 	@echo Assembling $<
# 	@$(CPP) -D__LANGUAGE_ASM__ $(C_INCLUDES) $(C_DEFINES) -o $(basename $@).s $<
# 	@$(AS) $(A_FLAGS) $(C_INCLUDES) $(A_DEFINES) -MD $(OBJS_ROOT)/$*.d -o $@ $(basename $@).s
# 
# $(OBJS_ROOT)/%.o: %.s
# 	@echo Assembling $<
# 	@$(AS) $(A_FLAGS) $(C_INCLUDES) $(A_DEFINES) -MD $(OBJS_ROOT)/$*.d -o $@ $<


# Add objects to the target library.
$(TARGET_LIB): $(OBJECTS_ALL)
	@echo Archiving $(notdir $?)
	@$(AR) -roucs $(TARGET_LIB) $?

# Recursively execute make in the subdirectories.
.PHONY: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -r -C $@

# Link the application.
$(APP): $(OBJECTS) $(OBJECTS_ASM) $(LIBRARIES) $(APP_LIBS)
# Wrap the link objects in start/end group so that ld re-checks each
# file for dependencies.  Otherwise linking static libs can be a pain
# since order matters.
# XXX: specify the .text segment to start in SRAM.  Change this later.
#      also ugly hack for multiple defition of _start_mqx.  not sure
#      why this is happening.
	@echo Linking $(APP)
# 	$(LD) -Bstatic \
# 	      -T $(MQX_LD_SCRIPT) \
# 	      $(MQX_ROOT)/lib/start.o \
# 	      --start-group \
# 	      	$(OBJECTS) \
# 	      	$(OBJECTS_CXX) \
# 		$(OBJECTS_ASM) \
# 		$(LIBRARIES) \
# 		$(APP_LIBS) \
# 	      --end-group \
# 	      $(LDADD) $(LDINC) -o $@ \
# 	      -Map $@.map
# 	$(OBJCOPY) -O binary $@ $@.bin
	$(CC) -o $(OUTPUT_ELF) $(CFLAGS) $(C_INCLUDES) -Wl,--whole-archive $(TARGET_LIB) -Wl,--no-whole-archive $(LD_FLAGS)
	arm-none-eabi-objcopy -O binary $(OUTPUT_ELF) $(OUTPUT_BIN)

# $(OUTPUT_ELF): $(TARGET_LIB) $(LD_FILE)
# 	@echo Linking $(OUTPUT_ELF)
# 	@$(CC) -o $(OUTPUT_ELF) $(C_FLAGS) $(C_INCLUDES) $(C_DEFINES) -Wl,--whole-archive $(TARGET_LIB) -Wl,--no-whole-archive $(LD_FLAGS)
# 
# $(OUTPUT_BIN): $(OUTPUT_ELF)
# 	@echo Generating $(OUTPUT_BIN)
# 	@arm-none-eabi-objcopy -O binary $(OUTPUT_ELF) $(OUTPUT_BIN)

# Set clean as a phony target and it can be appended to.  This is the default
# behavior.
.PHONY: clean
clean::
	rm -f *.o *.d *.a *.map *.bin $(OBJECTS_LDS)
	@for _dir in $(SUBDIRS); do \
		$(MAKE) -C $$_dir clean; \
	done

# Include dependency files.
-include $(OBJECTS_ALL:.o=.d)
#-include $(OBJECTS_CXX:.o=.d)
#-include $(OBJECTS_ASM:.o=.d)

