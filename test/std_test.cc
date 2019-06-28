#include <list>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Demo{
    int a;
    int b;
    Demo(int aa, int bb):a(aa), b(bb) {}
    ~Demo() {
        std::cout << "~Demo()" << std::endl;
    }
};

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
    std::map<int,int> example = {std::pair<int,int>(14, 24)};
    // std::map<int, char> example;
    // Demo* a1 = new Demo(31, 32);
    cout << "map size: " <<example.size() << endl;
    example.insert(std::pair<int,int>(11, 21));
    example.insert(std::pair<int,int>(12, 22));
    example.insert(std::pair<int,int>(13, 23));
    cout << "map size1: " <<example.size() << endl;
    auto search = example.find(13);
    if(search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
        // search->second;
        // Demo b1 = (Demo)search->second;
        // std::cout << "Demo: " << b1.a << " " << b1.b << endl;
    }
    else {
        std::cout << "Not found\n";
    }

    auto search1 = example.find(12);
    if(search1 != example.end()) {
        std::cout << "Found1 " << search1->first << " " << search1->second << '\n';
    }
    else {
        std::cout << "Not found\n";
    }

    example.erase(11);

    cout << "map size2: " <<example.size() << endl;
}

void foo2() {
    vector<int> aa;
    aa.push_back(11);
    aa.push_back(12);
    aa.push_back(13);

    vector<int>::iterator itr = aa.begin();
    while(itr != aa.end()) {
        std::cout << "itr: " << *(itr++) << std::endl;
    }
}

void foo3() {
    char aa[10] = {0};
    int a = &aa[5] - &aa[1];
    cout << a << endl;
}

void foo4() {
    list<int> aa;
    list<int>::iterator itr = aa.begin();
    list<int>::iterator itr1 = aa.end();

    if(itr == ++itr1) {
        cout << "1 " << endl;
    } else {
        cout << "0 " << endl;
    }
}

void foo5() {
    if(0.0f == float()) {
        cout << "float" << endl;
    }

    if(0 == float()) {
        cout << "float1" << endl;
    }
}

int pow(int x, unsigned int n) {
    if(0 == n) {
        if(int() == x) {
            return -1;
        }

        return 1;
    }

    for(int i = 1; i < n; i++) {
        x *= x;
    }

    return x;
}

int spliteIntDigit(int value, int index) {
    int divValue = value / pow(10, index-1);
    return 0 == divValue ? -1 : divValue % 10;
}

void foo6() {
    cout << "foo6" << endl;
    int a = spliteIntDigit(3, 2);
    cout << "a: " << a << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    foo6();
    return 0;
}
