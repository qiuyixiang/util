#include <utest.h>

// demo program using utest module
// this file may include other test case headers
TEST_CASE(simple){
    EXPECT_TRUE(1);
    EXPECT_FALSE(0);
    EXPECT_EQ(10, 10);
    EXPECT_NE(10, 20);
}

SUB_TEST_CASE(string){
    EXPECT_STR_EQ("Hello", "Hello");
    EXPECT_STR_NE("Hello", "World");
}
SUB_TEST_CASE(judge){
    EXPECT_EQ(1, 1);
    ASSERT_FALSE(0);
    ASSERT_TRUE(1);
    ASSERT_EQ(sizeof(int), 4);
}

TEST_CASE(multiple){
    RUN_SUB_TEST_CASE(string);
    RUN_SUB_TEST_CASE(judge);
}
SUB_TEST_CASE(a){ }
SUB_TEST_CASE(dump) { }
SUB_TEST_CASE(cc){ }
SUB_TEST_CASE(sys) { }
SUB_TEST_CASE(long_align_string) { }

// Test for string format
TEST_CASE(format){
    RUN_SUB_TEST_CASE(a);
    RUN_SUB_TEST_CASE(dump);
    RUN_SUB_TEST_CASE(cc);
    RUN_SUB_TEST_CASE(sys);
    RUN_SUB_TEST_CASE(long_align_string);
}

SUB_TEST_CASE(greater){
    EXPECT_GE(3, 3);
    EXPECT_GT(4, 2);
}
SUB_TEST_CASE(less){
    EXPECT_LE(3, 4);
    EXPECT_LT(3, 5);
}
TEST_CASE(new_feature){
    RUN_SUB_TEST_CASE(greater);
    RUN_SUB_TEST_CASE(less);
}
int main(int argc, char * argv[]){
    // turn off -Wunused-parameter
    (void)argc, (void)argv;
    // SET_OUTPUT_FORMAT(FORMAT_TIGHT);

    RUN_TEST_CASE(simple);
    RUN_TEST_CASE(multiple);
    RUN_TEST_CASE(format);
    RUN_TEST_CASE(new_feature);
}