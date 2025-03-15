/**
 *  MIT License
 *
 *  Copyright (c) 2025 QIU YIXIANG
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <utest.h>
#include <stdlib.h>

uint32_t __global_test_counter;
uint32_t __global_subtest_counter;
uint32_t __global_ot_format;

#define SPACE_ALIGN_MAX     30
#define BUFFER_SIZE         64

__attribute__((constructor)) void _init_utest(void){
    __global_test_counter = 0;
    __global_subtest_counter = 0;
    __global_ot_format = FORMAT_DEFAULT;
    fprintf(stdout, "Utest A simple C Unit Test Framework.\n");
}
__attribute__((destructor)) void _fini_utest(void){
    fprintf(stdout, "\nUtest Summary:\n");
    fprintf(stdout, " -Test Cases Passed : %u \n -Sub-Test Cases Passed : %u \n", \
            __global_test_counter, __global_subtest_counter);
}
// print message with case information in format [CASE_NAME] 
// and the string is left-aligned
static void _print_align(const char * __msg, uint32_t __align){
    size_t __len = strlen(__msg);
    if (__len <= __align){
        fprintf(stdout, "%s", __msg);
        fprintf(stdout, "%*s", (int)(__align - __len), " ");
    }else{
        fprintf(stderr, "Case name too long !\n");
        exit(-1);
    }
}
// run test case with proper info display
void _run_test(void(*__case_handler)(), const char * __case, uint32_t __flag){
    char __buffer[BUFFER_SIZE];
    if (__flag & FLAG_TEST_CASE){
        if (__flag == FLAG_HAS_SUB_CASE){
            
        }else{
            if (__global_ot_format != FORMAT_TIGHT){
                sprintf(__buffer, "[%s]", __case);
                _print_align(__buffer, SPACE_ALIGN_MAX - strlen(_COLOR_GREEN) - strlen(_COLOR_RESET));
                fprintf(stdout, "Running Test Case\n");
            }

            (*__case_handler)();

            sprintf(__buffer, "[%s%s%s]", _COLOR_GREEN, __case, _COLOR_RESET);
            _print_align(__buffer, SPACE_ALIGN_MAX);
            fprintf(stdout, "Test Case Passed\n");
        }
        __global_test_counter++;
    }else if (__flag & FLAG_SUB_TEST_CASE){
        (*__case_handler)();
        // String format process
        sprintf(__buffer, " |-[%s%s%s]", _COLOR_GREEN, __case, _COLOR_RESET);
        _print_align(__buffer, SPACE_ALIGN_MAX + 3);
        fprintf(stdout, "Sub-test Case Passed!\n");

        __global_subtest_counter++;
    }
    
}