#include "./../cclib-common/inc/base/common_define.h"
#include <iostream>

cc_size_t foo() {
    cc_size_t cc = 111;
    std::cout << "cc_size_t: " << sizeof(cc_size_t) << std::endl;
    return cc;
}

int main(int argc, char const *argv[])
{
    /* code */
    cc_size_t a = foo();
    std::cout << "a: " << a << std::endl;
    return 0;
}
