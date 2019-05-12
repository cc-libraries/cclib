//COMPILE: g++ test.cc
#include <vector>
#include <iostream>
#include <time.h>

#include "./../inc/sort/sort.h"

using namespace std;

using namespace cclib;
using namespace ccalgorithm;

inline vector<int> getStackVectorValue() {
    vector<int> vectorValue;
    vectorValue.push_back(4);
    vectorValue.push_back(12);
    vectorValue.push_back(3);
    vectorValue.push_back(115);
    vectorValue.push_back(15);
    vectorValue.push_back(11);
    vectorValue.push_back(2);
    return vectorValue;
}
inline void coutVectorValue(vector<int> value) {
    cout << "vector ";
    for(int i = 0; i < value.size(); i++) {
        cout << " value[" << i << "]: " << value[i];
    }
    cout << endl;
}
void insertionSortTest(Sort<int>* sortClass) {
    vector<int> sortValue = getStackVectorValue();
    sortClass->insertionSort(sortValue);
    coutVectorValue(sortValue);
}

void shellSortTest(Sort<int>* sortClass) {
    vector<int> sortValue = getStackVectorValue();
    sortClass->shellSort(sortValue);
    coutVectorValue(sortValue);
}

void heapSortTest(Sort<int>* sortClass) {
    vector<int> sortValue = getStackVectorValue();
    sortClass->heapSort(sortValue);
    coutVectorValue(sortValue);
}

int timeComplexityCalculate(clock_t startTime, clock_t endTime) {
    return endTime - startTime;
}

int main(int argc, char const *argv[])
{
    /* code */
    Sort<int>* sortClass = new Sort<int>();
    clock_t start,end;
    start = clock();
    insertionSortTest(sortClass);
    end = clock();
    cout << "insertion sort time spend: " << timeComplexityCalculate(start, end) << endl;
    start = clock();
    shellSortTest(sortClass);
    end = clock();
    cout << "shell sort time spend: " << timeComplexityCalculate(start, end) << endl;
    delete sortClass;
    sortClass = NULL;
    return 0;
}
