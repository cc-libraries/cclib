#include <list>
#include <iostream>
#include <string>
#include <map>

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

void foo1() {
    std::map<int,char> example = {{1,'a'},{2,'b'}};

    auto search = example.find(2);
    if(search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    foo();
    return 0;
}
