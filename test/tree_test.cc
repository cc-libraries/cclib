#include "./../cclib-common/inc/base/precompile_define.h"
#include "./../cclib-common/inc/base/common_define.h"
#include "./../cclib-common/inc/util/util.h"
#include "./../inc/adt/tree.h"
#include "./../inc/adt/pair.h"
#include <iostream>

using namespace std;
using namespace cclib::adt;

void binarySearchTreeTest() {
    BinarySearchTree<int> cc;
    cc.insert(11);
    cc.insert(12);
    cc.insert(13);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    int a = cc.find(12);
    cout << "a: " << a << endl;

    cout << cc.contains(14) << endl;
    cout << cc.contains(11) << endl;

    cc.remove(12);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    cc.clear();
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);
}

void binarySearchTreeTest1() {
    BinarySearchTree<cclib::adt::Pair<int, int>> cc;
    cc.insert(Pair<int, int>(11, 21));
    cc.insert(Pair<int, int>(12, 22));
    cc.insert(Pair<int, int>(13, 23));
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    Pair<int, int> a = cc.find(12);
    cout << "a: " << cclib::adt::Pair<int,int>::to_string(a) << endl;

    cout << cc.contains(14) << endl;
    cout << cc.contains(11) << endl;

    cc.remove(12);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    cc.clear();
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);
}

int main(int argc, char const *argv[])
{
    /* code */
    binarySearchTreeTest();
    binarySearchTreeTest1();
    return 0;
}
