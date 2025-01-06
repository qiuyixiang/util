/**
 * MIT License
 *
 * Copyright (c) 2025 QIU YIXIANG
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef __UTIL_UTEST_H__
#define __UTIL_UTEST_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef USING_IMPL_ASSERT
#include <assert.h>
#endif

#undef REGISTER_TEST
#undef RUN_ALL_TEST
#undef EXPECT_EQ
#undef EXPECT_NE
#undef EXPECT_LT
#undef EXPECT_LT
#undef EXPECT_GT
#undef EXPECT_RANGE_EQ
#undef EXPECT_TRUE                      
#undef EXPECT_FALSE

#define _UTEST_COLOR_BLACK          "\033[30m"
#define _UTEST_COLOR_RED            "\033[31m"
#define _UTEST_COLOR_GREEN          "\033[32m"
#define _UTEST_COLOR_YELLOW         "\033[33m"
#define _UTEST_COLOR_BLUE           "\033[34m"
#define _UTEST_COLOR_PURPLE         "\033[35m"
#define _UTEST_COLOR_CYAN           "\033[36m"
#define _UTEST_COLOR_WHITE          "\033[37m"
#define _UTEST_COLOR_RESET          "\033[0m"

// Internal Utility Macros
#define _UTEST_MACRO_COMBINE(NAME1, NAME2)      NAME1##NAME2
#define _UTEST_MACRO_STR(MACRO)                 #MACRO
#define _GNU_CONSTRUCTOR_FUNC                   __attribute__((constructor))
#define _UTEST_RESET_COLOR(_)                   fprintf(stdout, _UTEST_COLOR_RESET)
#define _UTEST_SET_COLOR(COLOR)                 fprintf(stdout, COLOR)   

#define _UTEST_SHOW_RESULT(STATUS, COLOR)       \
        fputc('[', stdout);                     \
        _UTEST_SET_COLOR(COLOR);                \
        fputs(STATUS, stdout);                  \
        _UTEST_RESET_COLOR();                   \
        fputc(']', stdout);                     \

#ifdef USING_IMPL_ASSERT
// A Simple Implementation Which Just Using Assert
#define EXPECT_EQ(COND1, COND2)                 assert((COND1) == (COND2))
#define EXPECT_NE(COND1, COND2)                 assert((COND1) != (COND2))
#define EXPECT_LT(COND1, COND2)                 assert((COND1) < (COND2))
#define EXPECT_GT(COND1, COND2)                 assert((COND1) > (COND2))
#define EXPECT_TRUE(COND)                       assert((COND))
#define EXPECT_FALSE(COND)                      assert(!(COND))
#define EXPECT_RANGE_EQ(BUFFER, TYPE, SIZE, VALUE)                      \
        for (uint64_t __index = 0; __index != SIZE; ++__index)          \
                assert((*((TYPE *)BUFFER + __index) == (TYPE)VALUE))

#define REGISTER_TEST(TEST_NAME)                                    \
        void TEST_NAME();                                           \
        _GNU_CONSTRUCTOR_FUNC void                                  \
        _UTEST_MACRO_COMBINE(REGISTER_, TEST_NAME)(){               \
            TEST_NAME();                                            \
            _UTEST_SHOW_RESULT("PASSED", _UTEST_COLOR_GREEN);       \
            fprintf(stdout, " " _UTEST_MACRO_STR(TEST_NAME) "\n");  \
        }                                                           \
        void TEST_NAME()

#endif

#define RUN_ALL_TEST(_)

#endif