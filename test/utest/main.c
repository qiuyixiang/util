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
TEST_CASE(multiple){
    RUN_SUB_TEST_CASE(string);
}

int main(int argc, char * argv[]){
    // turn off -Wunused-parameter
    (void)argc, (void)argv;
    INIT_TEST();
    RUN_TEST_CASE(simple);
}