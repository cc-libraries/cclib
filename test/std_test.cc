#include <list>
#include <iostream>
#include <string>

using namespace std;

void foo() {
    list<int> cc;
    cc.push_back(122);
    cc.push_back(11);
    cc.push_back(31);

    list<int>::iterator itr = cc.end();
    cout  << " *itr: " << *(--itr) << endl;

    list<int> aa = cc;
    list<int>::iterator itr1 = aa.begin();
    cout << "itr1: " << *itr1 << endl;
    itr1++;
    cout << "itr2: " << *itr1 << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    foo();
    return 0;
}
