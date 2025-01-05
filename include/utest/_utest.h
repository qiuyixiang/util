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

#undef TEST_UNIT
#undef RUN_ALL_TEST
#undef EXPECT_EQ
#undef EXPECT_NE
#undef EXPECT_LT
#undef EXPECT_LT
#undef EXPECT_GT
#undef EXPECT_RANGE_EQ

#define _UTEST_COLOR_BLACK          "\033[30m"
#define _UTEST_COLOR_RED            "\033[31m"
#define _UTEST_COLOR_GREEN          "\033[32m"
#define _UTEST_COLOR_YELLOW         "\033[33m"
#define _UTEST_COLOR_BLUE           "\033[34m"
#define _UTEST_COLOR_PURPLE         "\033[35m"
#define _UTEST_COLOR_CYAN           "\033[36m"
#define _UTEST_COLOR_WHITE          "\033[37m"
#define _UTEST_COLOR_RESET          "\033[0m"

#define _UTEST_RESET_COLOR          fprintf(stdout, _UTEST_COLOR_RESET)
#define _UTEST_SET_COLOR(COLOR)     fprintf(stdout, COLOR)

#define _UTEST_ERROR_MSG(CASE)                                                       \
             _UTEST_SET_COLOR(_UTEST_COLOR_RED);  \
             fprintf(stdout, "%s failed at line : %d file : %s\n",  \
                 CASE, __LINE__, __FILE__);  \
             _UTEST_RESET_COLOR


#if (!defined(__UTIL_UTEST_IMPL__)) 
extern void utest_run_all_test();
#endif

#define TEST_UNIT(TESTUNIT)                 void TESTUNIT()
#define RUN_ALL_TEST                        utest_run_all_test

#define EXPECT_EQ(COND1, COND2)                                                        
#define EXPECT_NE(COND1, COND2)
#define EXPECT_LT(COND1, COND2)
#define EXPECT_GT(COND1, COND2)
#define EXPECT_RANGE_EQ(BUFFER, TYPE, VALUE)

#endif