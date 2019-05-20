#include <iostream>
#include "./../inc/adt/vector.h"
#include "./../cclib-common/inc/util/util.h"

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

    cc.pop_back();
    cclib::common::util::printVectorValue(cc);
    cout << "hello: " << cc.empty() << endl;

    cc.pop_back();
    cclib::common::util::printVectorValue(cc);
    cout << "hello1:" << cc.empty() << endl;

    cc.push_back(1);

    Vector<int> bb;
    Vector<int> dd;
    bb = cc;
    dd = bb;
}

int main(int argc, char const *argv[])
{
    /* code */
    vectorTest();
    return 0;
}
