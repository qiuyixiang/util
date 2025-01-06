/* This File Show How to use utest */
#include <utest.h>

REGISTER_TEST(test_number){
    EXPECT_EQ(10, 10);
    EXPECT_EQ(20, 20);
}

REGISTER_TEST(test_gt){
    EXPECT_GT(20, 10);
    EXPECT_GT(100.2439, 93.24);
}
#define BUFFER_SIZE 5
REGISTER_TEST(test_range){
    int INT_group[BUFFER_SIZE] = {10, 10, 10, 10, 10};
    EXPECT_RANGE_EQ(INT_group, int, BUFFER_SIZE, 10);
    char CHAR_group[BUFFER_SIZE] = "AAAAA";
    EXPECT_RANGE_EQ(CHAR_group, char, BUFFER_SIZE, 'A');
}
int main(){
    RUN_ALL_TEST();
}