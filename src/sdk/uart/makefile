include $(PROJ_DIR)/make.def

MODULE := $(shell basename $(shell pwd))
MODULE_PREFIX := $(subst /,_,$(MODULE))
MODULE_OUT := $(PROJ_OUT)/obj/$(MODULE)

MODULE_C_FLAGS 	:=
MODULE_C_INCLUDES :=
MODULE_C_DEFINES 	:=

MODULE_A_FLAGS 		:=
MODULE_A_INCLUDES 	:=
MODULE_A_DEFINES 	:=

S_SRCS := $(wildcard *.S)
C_SRCS := $(wildcard *.c)
C_OBJS := $(patsubst %c,%o,$(C_SRCS))
S_OBJS := $(patsubst %S,%o,$(S_SRCS))
A_OBJS :=
MODULE_OBJS := $(A_OBJS) $(C_OBJS) $(S_OBJS)
MODULE_OBJS := $(addprefix $(MODULE_OUT)/, $(MODULE_OBJS))

SUB_DIRS := imx_uart

.PHONY: dir $(SUB_DIRS) all

dir:$(SUB_DIRS) all

$(SUB_DIRS):
	make -S -C $@ dir

include $(PROJ_DIR)/make.rules
