//COMPILE: g++ vector_test.cc -std=c++11
#include <iostream>
#include "./../inc/adt/vector.h"
#include "./../cclib-common/inc/util/util.h"
#include "./../inc/algorithm/binary/binary.h"

using namespace std;

using namespace cclib;
using namespace cclib::adt;

void vectorTest() {
    Vector<int> cc;

    bool res = cc.push_back(4);
    cc.push_back(1);
    cc.push_back(2);
    cc.push_back(3);

    cc.insert(2, 5);
    cclib::common::util::printVectorValue(cc);

    cc.earse(2);
    cclib::common::util::printVectorValue(cc);

    cc.clear();
    cclib::common::util::printVectorValue(cc);

    cc.push_back(1);
    cc.push_back(2);
    cc.push_back(4);
    cclib::common::util::printVectorValue(cc);

    Vector<int>::Iterator aa = cc.begin();
    while(aa != cc.end()) {
        cout << "aa: " << *(aa++) << endl;
    }

    cc.pop_back();
    cclib::common::util::printVectorValue(cc);

    Vector<int>::Iterator dd = cc.begin();
    for(int i = 0; i < cc.size() + 1; i++) {
        cout << "aa: " << *(dd++) << endl;
    }

    // cc.pop_back();
    // cclib::common::util::printVectorValue(cc);
    // cout << "hello: " << cc.empty() << endl;

    // cc.pop_back();
    // cclib::common::util::printVectorValue(cc);
    // cout << "hello1:" << cc.empty() << endl;

    // cc.push_back(1);

    Vector<int> bb = cc;
    bb.push_back(3);
}

void foo() {
    cclib::algorithm::Binary aa;
    aa.increase();
    aa.increase();
    aa.increase();
}

int main(int argc, char const *argv[])
{
    /* code */
    foo();
    return 0;
}
