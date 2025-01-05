# MIT License

# Copyright (c) 2025 QIU YIXIANG

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Don't edit this file, change configuration in config/config.mk

-include config/config.mk

# Directory Definition
INCLUDE_PATH		:=		./include
SRC_PATH			:=		./src
CONFIG_PATH			:=		./config
TEST_PATH			:=		./test
BUILD_PATH			:=		$(BUILD_DIR)
OBJ_PATH			:=		$(BUILD_PATH)/obj

# C Compiler Flags
CC_FLAGS			:=	
CC_FLAGS			+=		-std=$(CC_STD)
CC_FLAGS			+=		-Wall -Wextra -Wshadow -Werror
CC_FLAGS			+=		-Wno-unused-parameter -Wno-unused-but-set-variable
CC_FLAGS			+=		-isystem $(INCLUDE_PATH)

ifeq ($(DEBUGGER), 0)
# Disable Debugger Mode
CC_FLAGS			+=		-O3
else
# Enable Debugger Mode
CC_FLAGS			+=		-O0
CC_FLAGS			+=		-g -ggdb3 
endif

SRC_LISTS			:=		$(sort $(shell find $(SRC_PATH) -type f -name "*.c"))
SRC_LISTS			:=		$(notdir $(SRC_LISTS))

OBJ_LISTS			:=		$(patsubst %.c, %.o, $(SRC_LISTS))
OBJ_LISTS			:=		$(addprefix $(OBJ_PATH)/, $(OBJ_LISTS))

.DEFAULT_GOAL		:=		all

.PHONY: all clean lib check_dir test

all: lib 

lib: check_dir $(OBJ_LISTS)
ifeq ($(BUILD_MODE), static)
# Build For Static Library
	$(AR) rcs $(BUILD_PATH)/lib$(LIB_NAME).a $(OBJ_LISTS)
else

endif

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

# Phony Target Defined Here
check_dir:
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(BUILD_PATH)
	@rm -rf $(TEST_PATH)/build
	@rm -rf ./main.out

test: lib
	$(MAKE) -C test 