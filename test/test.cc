//COMPILE: g++ test.cc
#include <vector>
#include <iostream>
#include <time.h>

#include "./../inc/sort/sort.h"

using namespace std;

using namespace cclib;
using namespace ccalgorithm;

void insertionSortTest(vector<int>* sortValue, Sort<int>* sortClass) {
    sortClass->insertionSort(*sortValue);
}

void shellSortTest(vector<int>* sortValue, Sort<int>* sortClass) {
    sortClass->shellSort(*sortValue);
}

int timeComplexityCalculate(clock_t startTime, clock_t endTime) {
    return endTime - startTime;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int>* cc = new vector<int>();
    cc->push_back(4);
    cc->push_back(12);
    cc->push_back(3);
    cc->push_back(115);
    cc->push_back(15);
    cc->push_back(11);
    cc->push_back(2);
    Sort<int>* aa = new Sort<int>();
    clock_t start,end;
    start = clock();
    insertionSortTest(cc, aa);
    end = clock();
    cout << "timeComplexityCalculate: " << timeComplexityCalculate(start, end) << endl;
    start = clock();
    shellSortTest(cc, aa);
    end = clock();
    cout << "timeComplexityCalculate: " << timeComplexityCalculate(start, end) << endl;
    cout << "cc[0]: " << cc->at(0) << " cc[1]: " << cc->at(1)
    << " cc[2]: " << cc->at(2) << " cc[3]: " << cc->at(3) <<
    " cc[4]: " << cc->at(4) << " cc[5]: " << cc->at(5) <<
    " cc[6]: " << cc->at(6) << endl;
    delete cc;
    cc = NULL;
    delete aa;
    aa = NULL;
    return 0;
}
