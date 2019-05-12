/*********************************************************************
 * cc-algorithm
 *
 * Copyright (c) 2019 cc-clipboard contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/hello-chenchen/cc-algorithm/blob/master/LICENSE>
 * See https://github.com/hello-chenchen/cc-algorithm for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_CCALGORITHM_SORT_H
#define CCLIB_CCALGORITHM_SORT_H
#include <vector>
#include <iterator>
#include <iostream>
// #include <algorithm>

using namespace std;

namespace cclib {
    namespace ccalgorithm {
        template<typename Comparable>
        class Sort {
            public:
                void insertionSort(vector<Comparable>& sortValue) {
                    int j;
                    for(int p = 1; p < sortValue.size(); p++) {
                        Comparable tmp = sortValue[p];
                        for( j = p; j > 0 && tmp < sortValue[j - 1]; j--) {
                            sortValue[j] = sortValue[j-1];
                            sortValue[j-1] = tmp;
                        }
                    }
                }

                void shellSort(vector<Comparable>& sortValue) {
                    for(int gap = sortValue.size() / 2; gap > 0; gap /= 2) {
                        for(int i = gap; i < sortValue.size(); i++) {
                            Comparable tmp = sortValue[i];
                            for(int j = i; j >= gap && tmp < sortValue[j - gap]; j -= gap) {
                                sortValue[j] = sortValue[j - gap];
                                sortValue[j-gap] = tmp;
                            }
                        }
                    }
                }


                inline int leftChild(int i) {
                    return 2 * i + 1;
                }
                inline void percDown(vector<Comparable>& sortValue, int i, int n) {
                    int child;
                    Comparable tmp;
                    for(tmp = sortValue[i]; leftChild(i) < n; i = child) {
                        child = leftChild(i);
                        if(child != n - 1 && sortValue[child] < sortValue[child + 1]) {
                            child++;
                        }
                        if(tmp < sortValue[child]) {
                            sortValue[i] = sortValue[child];
                        } else {
                            break;
                        }
                    }

                    sortValue[i] = tmp;
                }
                void heapSort(vector<Comparable>& sortValue) {
                    for(int i = sortValue.size() / 2; i >= 0; i--) {
                        percDown(sortValue, i, sortValue.size());
                    }
                    for(int j = sortValue.size() - 1; j > 0; j--) {
                        swap(sortValue[0], sortValue[j]);
                        percDown(sortValue, 0, j);
                    }
                }
        };
    }
}

#endif   //CCLIB_CCALGORITHM_SORT_H