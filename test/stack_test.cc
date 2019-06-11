#include "./../inc/adt/stack.h"
#include <iostream>

using namespace std;
using namespace cclib::adt;

void stack_test() {
    Stack<int> aa;
    aa.push(11);
    aa.push(12);
    aa.push(13);

    for(int i = 0; i < 3; i++) {
        cout << "aa[" << i << "]: " << aa.top() << endl;
        aa.pop();
    }
}

int main(int argc, char const *argv[])
{
    stack_test();
    return 0;
}
