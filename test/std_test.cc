#include <list>
#include <iostream>

using namespace std;

void foo() {
    list<int> cc;
    cc.push_back(1);
    cc.push_back(2);
    cc.push_back(3);

    list<int>::iterator itr = cc.end();
    
}