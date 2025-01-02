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

# C Compiler Flags
CC_FLAGS			:=	
CC_FLAGS			+=		-std=$(CC_STD)
CC_FLAGS			+=		-Wall -Wextra -Wshadow -Werror
CC_FLAGS			+=		-Wno-unused-parameter -Wno-unused-but-set-variable
CC_FLAGS			+=		-isystem=$(INCLUDE_PATH)

ifeq ($(DEBUGGER), 0)
# Disable Debugger Mode
CC_FLAGS			+=		-O3
else
# Enable Debugger Mode
CC_FLAGS			+=		-O0
CC_FLAGS			+=		-g -ggdb3 
endif