//COMPILE: g++ list_test.cc -std=c++11
#include <iostream>
#include "./../inc/adt/list.h"
#include "./../cclib-common/inc/util/util.h"

using namespace std;
using namespace cclib;
using namespace cclib::adt;

void listTest() {
    List<int> cc;
    cc.push_back(1);
    cc.push_back(2);
    cclib::common::util::printListValue(cc);
}

int main(int argc, char const *argv[])
{
    /* code */
    listTest();
    return 0;
}
