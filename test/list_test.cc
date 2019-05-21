//COMPILE: g++ list_test.cc -std=c++11
#include <iostream>
#include "./../inc/adt/list.h"
#include "./../cclib-common/inc/util/util.h"
#include <list>

using namespace std;
using namespace cclib;
using namespace cclib::adt;

void listTest() {
    List<int> cc;
    cc.push_back(1);
    // cc.push_back(2);
    // cc.push_back(3);
    // cclib::common::util::printListValue(cc);

    List<int>::iterator itr = cc.end();
    cout << "hello itr: " << *itr << endl;
    while(itr != cc.begin()) {
        cout << "itr: " << *itr << endl;
        --itr;
    }


    // cc.pop_back();
    // cc.pop_back();
    // cc.pop_back();
    cclib::common::util::printListValue(cc);

}

int main(int argc, char const *argv[])
{
    /* code */
    listTest();
    return 0;
}
