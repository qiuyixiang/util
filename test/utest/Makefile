# Simple Makefile for utest
# This makefile is fully independent to the main Makefile
MODULE_NAME		:=		utest

BUILD_DIR		:=		.
ROOT_DIR		:=		../..
UTEST_DIR		:=		$(ROOT_DIR)/modules/$(MODULE_NAME)
LIB_DIR			:=		$(ROOT_DIR)/build/lib
CONFIG_DIR		:=		$(ROOT_DIR)/config
INCLUDE_DIR		:=		$(UTEST_DIR)/include

DEPS			:=		$(shell find $(INCLUDE_DIR) -name "*.h")

include $(CONFIG_DIR)/config.mk

CC				:=		gcc
CC_FLAGS		:=
CC_FLAGS		+=		-Wall -Wextra -Wshadow 
CC_FLAGS		+=		-O3 -std=c11
CC_FLAGS		+=		-isystem $(INCLUDE_DIR)

.DEFAULT_GOAL	:=		test
.PHONY:					test, clean

test: main.out
main.out: main.o $(LIB_DIR)/lib$(LIB_NAME).a
	@$(CC) $<  -L$(LIB_DIR) -l$(LIB_NAME) -o $@

%.o: %.c $(DEPS)
	@$(CC) $(CC_FLAGS) -c $< -o $@ 

clean:
	@rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.out