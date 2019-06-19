#include "./../cclib-common/inc/base/common_define.h"
#include <iostream>

cc_size_t foo() {
    cc_size_t cc = 111;
    std::cout << "cc_size_t: " << sizeof(cc_size_t) << std::endl;
    return cc;
}

void foo1() {
    int a = 4;
    int b = 7;
    int c = MAX_VALUE(a, b);
    std::cout << "max value: " << c << std::endl;

    int d = MIN_VALUE(a, b);
    std::cout << "min value: " << d << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    foo1();
    return 0;
}
