#include "./../cclib-common/inc/base/precompile_define.h"
#include "./../cclib-common/inc/base/common_define.h"
#include "./../cclib-common/inc/util/util.h"
#include "./../inc/adt/tree.h"
#include <iostream>

using namespace cclib::adt;

void binarySearchTreeTest() {
    BinarySearchTree<int> cc;
    cc.insert(11);
    cc.insert(12);
    cc.insert(13);
    std::cout << "size: " << cc.size() << std::endl;
    cclib::common::util::printTreeValue(cc);

    int a = cc.find(12);
    std::cout << "a: " << a << std::endl;

    cc.remove(12);
    std::cout << "size: " << cc.size() << std::endl;
    cclib::common::util::printTreeValue(cc);
}

int main(int argc, char const *argv[])
{
    /* code */
    binarySearchTreeTest();
    return 0;
}
