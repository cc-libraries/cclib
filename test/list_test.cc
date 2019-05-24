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
    cc.push_back(12);
    cc.push_back(22);
    cc.push_front(32);
    cclib::common::util::printListValue(cc);

    List<int>::iterator itr = cc.begin();
    cout << "hello itr: " << *itr << endl;

    // List<int> aa = cc;
    // List<int>::iterator itr1 = aa.begin();
    // cout << "itr1: " << *itr1 << endl;
    // itr1++;
    // cout << "itr2: " << *itr1 << endl;

    // cc.pop_back();
    // cc.pop_back();
    // cc.pop_back();
    // cclib::common::util::printListValue(cc);

}

int main(int argc, char const *argv[])
{
    /* code */
    listTest();
    cout << "aaa" << endl;
    return 0;
}
