#include <utest.h>

REGISTER_TEST(test1){
    fprintf(stdout, "Hello World !\n");
}
int main(){
    RUN_ALL_TEST();
}