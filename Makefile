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

ROOT_DIR			:=		.
BUILD_DIR			:=		$(ROOT_DIR)/build
MODULE_DIR			:=		$(ROOT_DIR)/modules
INCLUDE_DIR			:=		$(ROOT_DIR)/include
OBJ_DIR				:=		$(BUILD_DIR)/obj

# options for GNU GCC flags
CC_FLAGS		:=
# GCC warning flags
CC_WARNING		:=		-Wall -Werror -Wextra -Wshadow
# GCC std version flags
CC_STD			:=		-std=c11

CC_FLAGS		+= 		$(CC_WARNING) $(CC_STD)


MODULE_LIST			:=		$(MODULES)
MODULE_SRCS			:=		$(foreach module, $(MODULE_LIST), $(wildcard $(MODULE_DIR)/$(module)/src/*.c))
# Module objects format as : ./build/MODULE/%.c
MODULE_OBJS			:=		$(foreach module, $(MODULE_LIST), 		\
							$(addprefix $(OBJ_DIR)/$(module)/, 		\
							$(patsubst %.c, %.o, 					\
							$(notdir 								\
							$(wildcard $(MODULE_DIR)/$(module)/src/*.c)))))
OBJS				:=		$(MODULE_OBJS)

# this file used to generate compile rule for modules
# @argument: module name
define compile_rule
$(OBJ_DIR)/$(1)/%.o: $(MODULE_DIR)/$(1)/src/%.c
	@mkdir -p $(OBJ_DIR)/$(1)
	@$(CC) $(CC_FLAGS) -c $$< -o $$@
endef


$(foreach mod, $(MODULE_LIST), $(eval $(call compile_rule,$(mod))))


.PHONY: 		main, clean
.DEFAULT_GOAL		:=		main

clean:
	@rm -rf $(BUILD_DIR)

main: $(OBJS)




