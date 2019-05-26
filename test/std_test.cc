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
    cout << "map size: " <<example.size() << endl;
    example.insert(std::pair<int,char>(1, 'c'));
    cout << "map size1: " <<example.size() << endl;
    auto search = example.find(2);
    if(search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

    auto search1 = example.find('a');
    if(search1 != example.end()) {
        std::cout << "Found1 " << search1->first << " " << search1->second << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    foo1();
    return 0;
}
