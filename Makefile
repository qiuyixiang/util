# MIT License
#
# Copyright (c) 2025 QIU YIXIANG
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Makefile for util project
include config/config.mk

CC					:=		gcc
AR					:=		ar
LD					:=		ld

ROOT_DIR			:=		.
FULL_DIR			:=		$(CURDIR)
BUILD_DIR			:=		$(ROOT_DIR)/build
MODULE_DIR			:=		$(ROOT_DIR)/modules
INCLUDE_DIR			:=		$(ROOT_DIR)/include
OBJ_DIR				:=		$(BUILD_DIR)/obj
LIB_DIR				:=		$(BUILD_DIR)/lib
CONFIG_DIR			:=		$(ROOT_DIR)/config

# options for GNU GCC flags
CC_FLAGS		:=

# GCC warning flags
CC_WARNING		:=		-Wall -Werror -Wextra -Wshadow
CC_WARNING		+=		-Wno-unused-variable
# GCC debugger flags
CC_DEBUGGER		:=	
# GCC optimizer flags
CC_OPTIMIZER	:=		
# GCC std version flags
CC_STD			:=		-std=c11

ifeq ($(DEBUGGER), true)
CC_DEBUGGER		+=		-ggdb -g2
CC_OPTIMIZER	+=		-O0
else 
CC_OPTIMIZER	+=		-O3
endif

CC_FLAGS		+=		$(CC_STD)
CC_FLAGS		+= 		$(CC_WARNING)
CC_FLAGS		+=		$(CC_DEBUGGER)
CC_FLAGS		+=		$(CC_OPTIMIZER)

# define variable MODULES which will include all module names
ifdef MODULES
MODULE_LIST		:=		$(MODULES)
else
MODULE_LIST		:=		$(patsubst $(MODULE_DIR)/%/, %, $(wildcard $(MODULE_DIR)/*/))
endif

# Automatic generate variable MODULE_OBJS_XXX in form of ./build/obj/MODULE/%.o
$(foreach module, $(MODULE_LIST), $(eval 	\
MODULE_OBJS_$(module) := 					\
$(addprefix $(OBJ_DIR)/$(module)/, 			\
$(patsubst %.c, %.o, 						\
$(notdir 									\
$(wildcard $(MODULE_DIR)/$(module)/src/*.c))))))

MODULE_OBJS		:=		$(foreach module, $(MODULE_LIST), $(MODULE_OBJS_$(module)))
# generate compile rule for module object file
# @argument: module name
define compile_rule_module_obj
$(OBJ_DIR)/$(1)/%.o: $(MODULE_DIR)/$(1)/src/%.c
	@$(CC) $(CC_FLAGS) -c $$< -o $$@
	@echo "+ CC\t$(1)/$$(notdir $$<)"
endef

# Generate compiler rules for all objects in module
$(foreach module, $(MODULE_LIST), $(eval $(call compile_rule_module_obj,$(module))))

# check module and show info
# @argument : module name
define compile_module_rule_check
.PHONY:		check_$(1)
check_$(1): 
	@mkdir -p $(OBJ_DIR)/$(1)
	@echo "[$(1)] \tModule Build"
endef

$(foreach module, $(MODULE_LIST), $(eval $(call compile_module_rule_check,$(module))))

# generate module target 
# @argument: module name
define compile_module
$(1): check_$(1) $(MODULE_OBJS_$(1))
	@echo "Module $(1) Build Success\n"
endef

$(foreach module, $(MODULE_LIST), $(eval $(call compile_module,$(module))))

.DEFAULT_GOAL		:=		main
.PHONY: 					main, clean, lib, mkdir_lib, header, help
# Main target
main: lib

# help info
help:
	@echo "Makefile for util library"
	@echo "Copyright (C) QIU YIXIANG"
	@echo "You can change any configure in $(CONFIG_DIR)/config.mk"
	@echo "Usage: "
	@echo "\tmake lib\tbuild library"
	@echo "\tmake clean\tclean build target"
	@echo "\tmake header\tinstall header files"
	@echo ""

header:
	@mkdir -p $(INCLUDE_DIR)
	@for module in $(MODULE_LIST); do							\
		cp -r $(MODULE_DIR)/$$module/include/* $(INCLUDE_DIR);	\
	done
	@echo "Successfully install headers in $(INCLUDE_DIR)/ !"

mkdir_lib:
	@mkdir -p $(LIB_DIR)

# lib target
lib: mkdir_lib $(MODULE_LIST)
# build static library
ifeq ($(METHOD), static)
	@$(AR) rcs $(LIB_DIR)/lib$(LIB_NAME).a $(MODULE_OBJS)
else
# build dynamic (shared) library
endif
	@echo "+ AR\tlib$(LIB_NAME).a"
	@echo "Build $(METHOD) library $(LIB_NAME) in $(LIB_DIR)/ successfully!"

clean:
	@rm -rf $(BUILD_DIR) $(INCLUDE_DIR)


