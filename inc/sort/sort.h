/*********************************************************************
 * cclib-algorithm
 *
 * Copyright (c) 2019 cc-algorithm contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/cc-libraries/cclib-algorithm/blob/master/LICENSE>
 * See https://github.com/cc-libraries/cclib-algorithm for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_ALGORITHM_SORT_H
#define CCLIB_ALGORITHM_SORT_H
#include <vector>
#include <iterator>
#include <iostream>
#include <limits>

#include "./../../cclib-common/inc/util/util.h"

using namespace std;

namespace cclib {
    namespace algorithm {
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

                void mergeSort(vector<Comparable>& sortValue) {
                    mergeSort(sortValue, 0, sortValue.size() - 1);
                }

                void heapSort(vector<Comparable>& sortValue) {
                    for(int i = sortValue.size() / 2; i >= 0; i--) {
                        percDown(sortValue, i, sortValue.size());
                    }
                    for(int j = sortValue.size() - 1; j > 0; j--) {
                        swap(sortValue[0], sortValue[j]);
                        percDown(sortValue, 0, j - 1);
                        // percDown(sortValue, 0, j); //NOTICE: method 2
                    }
                }

            private:
                void merge(vector<int> &sortValue, int left, int center, int right) {
                    vector<int> leftSubArray(sortValue.begin() + left, sortValue.begin() + center + 1);
                    vector<int> rightSubArray(sortValue.begin() + center + 1, sortValue.begin() + right + 1);
                    int idxLeft = 0, idxRight = 0;
                    leftSubArray.insert(leftSubArray.end(), numeric_limits<Comparable>::max());
                    rightSubArray.insert(rightSubArray.end(), numeric_limits<Comparable>::max());

                    for (int i = left; i <= right; i++) {
                        sortValue[i] = leftSubArray[idxLeft] < rightSubArray[idxRight]
                         ? leftSubArray[idxLeft++] : rightSubArray[idxRight++];
                    }
                }

                void mergeSort(vector<Comparable>& sortValue, int left, int right) {
                    if(left < right) {
                        int center = (left + right) / 2;
                        mergeSort(sortValue, left, center);
                        mergeSort(sortValue, center + 1, right);
                        merge(sortValue, left, center, right);
                    }
                }

                inline int leftChild(int dad) {
                    return 2 * dad + 1; //NOTICE: left child in array or vector
                }
                inline void percDown(vector<Comparable>& sortValue, int start, int end) {
                    int leftChildNode, parentNode;
                    parentNode = start;
                    leftChildNode = leftChild(parentNode);
                    while(leftChildNode <= end) {
                        //COMMENT: get max node between left to right
                        if(leftChildNode + 1 <= end && sortValue[leftChildNode] < sortValue[leftChildNode + 1]) {
                            leftChildNode++;
                        }
                        if(sortValue[parentNode] > sortValue[leftChildNode]) {
                            return;
                        } else {
                            swap(sortValue[parentNode], sortValue[leftChildNode]);
                            parentNode = leftChildNode;
                            leftChildNode = leftChild(parentNode);
                        }
                    }

                    //NOTICE: method 2 not clearly than method 1
                    // Comparable tmp;
                    // for(tmp = sortValue[parentNode]; leftChild(parentNode) < end; parentNode = leftChildNode) {
                    //     leftChildNode = leftChild(parentNode);
                    //     if(leftChildNode != end - 1 && sortValue[leftChildNode] < sortValue[leftChildNode + 1]) {
                    //         leftChildNode++;
                    //     }
                    //     if(tmp < sortValue[leftChildNode]) {
                    //         sortValue[parentNode] = sortValue[leftChildNode];
                    //     } else {
                    //         break;
                    //     }
                    // }
                    // sortValue[parentNode] = tmp;
                }
        };
    }
}

#endif   //CCLIB_ALGORITHM_SORT_H