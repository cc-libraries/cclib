#include "./../inc/adt/list_stl.h"

#include <iostream>

void foo() {
    list<int> cc;
    cc.push_back(1);
    cc.push_back(2);
    cc.push_back(3);

    list<int>::iterator itr = cc.end();
    std::cout << "*itr: " << *itr << std::endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    foo();
    return 0;
}

