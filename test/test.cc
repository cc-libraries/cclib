//COMPILE: g++ test.cc
#include <vector>
#include <iostream>

#include "./../inc/sort/sort.h"

using namespace std;

using namespace cclib;
using namespace ccalgorithm;

void insertionSortTest() {
    vector<int>* cc = new vector<int>();
    cc->push_back(4);
    cc->push_back(12);
    cc->push_back(3);
    cc->push_back(115);

    Sort<int>* aa = new Sort<int>();
    aa->insertionSort(*cc);

    cout << "cc[0]: " << cc->at(0) << " cc[1]: " << cc->at(1)
    << " cc[2]: " << cc->at(2) << " cc[3]: " << cc->at(3) << endl;
    delete cc;
    delete aa;
}

int main(int argc, char const *argv[])
{
    /* code */
    insertionSortTest();
    return 0;
}
