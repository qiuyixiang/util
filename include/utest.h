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

#ifndef UTIL_UTEST_H
#define UTIL_UTEST_H

/**
 * This sub-library is just for simple unit test
 * Designed using only C, and this file is part of util library
 * Usage: 
 *  REGISTER_TEST(TEST_NAME)      
 *      Register a test which will be executed by call RUN_ALL_TEST
 *  RUN_ALL_TEST()
 *      A macro which will run all test suites automatically
 */

/* Declaration Interface of Simple C Unit Test */
#define REGISTER_TEST(TEST_NAME)
#define RUN_ALL_TEST

#define EXPECT_EQ(COND1, COND2)
#define EXPECT_NE(COND1, COND2)
#define EXPECT_LT(COND1, COND2)
#define EXPECT_GT(COND1, COND2)
#define EXPECT_TRUE(COND)
#define EXPECT_FALSE(COND)
#define EXPECT_RANGE_EQ(BUFFER, TYPE, SIZE, VALUE)

// Backward Compatible With Later Test Frame
#define USING_IMPL_ASSERT

#include <utest/_utest.h>
#endif