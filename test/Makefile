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

# Makefile For Test

CC					:=		gcc-14


BUILD_PATH			:=		./build
LIB_PATH			:=		../build
INCLUDE_PATH		:=		../include

LIB_NAME			:=		util
OUTPUT_FILE_NAME	:=		main.out

CC_FLAGS			+=		-Wall -Wextra -Wshadow -Werror
CC_FLAGS			+=		-Wno-unused-parameter -Wno-unused-but-set-variable
CC_FLAGS			+=		-O3
CC_FLAGS			+=		-isystem $(INCLUDE_PATH)

# Change This Test case for different test target
TEST_CASE			:=		utest

.DEFAULT_TARGET		:=		all 
.PHONY: clean all check_dir

all: check_dir $(TEST_CASE)

# Define Self-Custom Test Case Here
######################################################

# Test For Sub-library Utest 
UTEST_PATH			:=		./utest

utest: $(BUILD_PATH)/utest.o
	$(CC) $(CC_FLAGS) $< -L $(LIB_PATH) -l$(LIB_NAME) -o ../$(OUTPUT_FILE_NAME)

$(BUILD_PATH)/utest.o: $(UTEST_PATH)/utest.c
	$(CC) $(CC_FLAGS) -c $< -o $@


######################################################


check_dir:
	@mkdir -p $(BUILD_PATH)

clean:
	rm -rf $(BUILD_PATH)