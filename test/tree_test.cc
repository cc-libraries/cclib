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
    cclib::common::util::printBinarySearchTreeValue(cc);

    int a = cc.find(12);
    cout << "a: " << a << endl;

    cout << cc.contains(14) << endl;
    cout << cc.contains(11) << endl;

    cc.remove(12);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printBinarySearchTreeValue(cc);

    cc.clear();
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printBinarySearchTreeValue(cc);
}

void binarySearchTreeTest1() {
    BinarySearchTree<cclib::adt::Pair<int, int>> cc;
    cc.insert(Pair<int, int>(12, 22));
    cc.insert(Pair<int, int>(11, 21));
    cc.insert(Pair<int, int>(13, 23));
    // cc.insert(Pair<int, int>(15, 25));
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printBinarySearchTreeValue(cc);

    Pair<int, int> a = cc.find(12);
    cout << "a1: " << cclib::adt::Pair<int,int>::to_string(a) << endl;

    cout << cc.contains(14) << endl;
    cout << cc.contains(11) << endl;

    cc.remove(12);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printBinarySearchTreeValue(cc);

    cout << "clear " <<endl;
    cc.clear();
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printBinarySearchTreeValue(cc);
    cout << "end" << endl;
}

void redBlackTreeTest() {
    RedBlackTree<int> cc;
    cc.insert(11);
    cc.insert(12);
    cc.insert(13);
    cc.insert(14);
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);
    // cc.printHeader();
    cc.remove(14);
    // cc.printHeader();
    cout << "size1: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    cc.remove(12);
    cout << "size2: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    RedBlackNode<int>* a = cc.find(11);
    cout << "a->_data: " << a->_data << endl;
    cclib::common::util::printTreeValue(cc);

    cc.clear();
    cout << "size3: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);
}

void redBlackTreePairTest() {
    RedBlackTree<cclib::adt::Pair<int, int>> cc;
    cc.insert(Pair<int, int>(11, 21));
    cc.insert(Pair<int, int>(12, 22));
    cc.insert(Pair<int, int>(13, 23));
    cc.insert(Pair<int, int>(14, 24));
    cout << "size: " << cc.size() << endl;
    cclib::common::util::printTreeValue(cc);

    // cc.remove(14);
    // cout << "size: " << cc.size() << endl;

    // cc.remove(12);
    // cout << "size: " << cc.size() << endl;

    // cout << "cc: " << &cc <<endl;
    // RedBlackTree<int> aa = cc;
    // cout << "aa.size: " << aa.size() << endl;
    // cout << "aa: " << &aa << endl;

    // cc.clear();
    // cout << "size1: " << cc.size() << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    // binarySearchTreeTest();
    redBlackTreePairTest();
    return 0;
}
