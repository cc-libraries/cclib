/*********************************************************************
 * cclib
 *
 * Copyright (c) 2019 cclib contributors:
 *   - hello_chenchen <https://github.com/hello-chenchen>
 *
 * MIT License <https://github.com/cc-libraries/cclib/blob/master/LICENSE>
 * See https://github.com/cc-libraries/cclib for the latest update to this file
 *
 * author: hello_chenchen <https://github.com/hello-chenchen>
 **********************************************************************************/
#ifndef CCLIB_ALGORITHM_SORT_H
#define CCLIB_ALGORITHM_SORT_H

#include "./../../../cclib-common/inc/util/util.h"
#include "./../../adt/vector.h"
#include <algorithm>

using namespace cclib;
using namespace cclib::adt;
using namespace cclib::common::util;

namespace cclib {
    namespace algorithm {
        template<typename Comparable>
        class Sort {
            public:
                void bubbleSort(Vector<Comparable>& sortValue) {
                    for(int i = 0; i < sortValue.size(); i++) {
                        for(int n = 0; n < sortValue.size() - i - 1; n++) {
                            if(sortValue[n] > sortValue[n+1]) {
                                swap(&sortValue[n], &sortValue[n+1]);
                            }
                        }
                    }
                }

                void selectSort(Vector<Comparable>& sortValue) {
                    for(int i = 0; i < sortValue.size(); i++) {
                        cc_size_t minValue = i;
                        for(int n = i; n < sortValue.size() - 1; n++) {
                            if(sortValue[minValue] > sortValue[n+1]) {
                                minValue = n + 1;
                            }
                        }

                        if(i == minValue) continue;
                        swap(sortValue[i], sortValue[minValue]);
                    }
                }

                void insertSort(Vector<Comparable>& sortValue) {
                    for(int i = 1; i < sortValue.size(); i++) {
                        for(int n = i; n > 0; n--) {
                            if(sortValue[n] < sortValue[n-1]) {
                                swap(sortValue[n], sortValue[n-1]);
                            } else {    //NOTICE: reduce unnecessary steps
                                break;
                            }
                        }
                    }
                }

                void insertionSort(Vector<Comparable>& sortValue) {
                    int j;
                    for(int p = 1; p < sortValue.size(); p++) {
                        Comparable tmp = sortValue[p];
                        for( j = p; j > 0 && tmp < sortValue[j - 1]; j--) {
                            sortValue[j] = sortValue[j-1];
                            sortValue[j-1] = tmp;
                        }
                    }
                }

                void shellSort(Vector<Comparable>& sortValue) {
                    for(int gap = sortValue.size() / 2; gap > 0; gap /= 2) {
                        for(int i = gap; i < sortValue.size(); i++) {
                            for(int j = i; j >= gap; j -= gap) {
                                if(sortValue[j] < sortValue[j - gap]) {
                                    swap(sortValue[j], sortValue[j - gap]);
                                }
                            }
                        }
                    }
                }

                void mergeSort(std::vector<Comparable>& sortValue) {
                    mergeSort(sortValue, 0, sortValue.size() - 1);
                }

                void mergeSort(Vector<Comparable>& sortValue) {
                    mergeSort(sortValue, 0, sortValue.size() - 1);
                }

                void heapSort(Vector<Comparable>& sortValue) {
                    for(int i = sortValue.size() / 2; i >= 0; i--) {
                        percDown(sortValue, i, sortValue.size());
                    }
                    for(int j = sortValue.size() - 1; j > 0; j--) {
                        swap(sortValue[0], sortValue[j]);
                        percDown(sortValue, 0, j - 1);
                    }
                }

                void quickSort(Vector<Comparable>& sortValue) {
                    quickSort(sortValue, 0, sortValue.size() - 1);
                }

                //DEPRECATED:
                void countSort(Vector<int>& sortValue) {
                    for(int i = 0; i < sortValue.size() - 1; i++) {
                        if(sortValue[i] > sortValue[i+1]) {
                            swap(sortValue[i], sortValue[i+1]);
                        }
                    }
                    int maxValue = sortValue[sortValue.size()-1];

                    int* array = new int[maxValue+1]();

                    for(int i = 0; i < sortValue.size(); i++) {
                        array[sortValue[i]]++;
                    }

                    sortValue.clear();  //FIXME: array is better
                    for(int i = 0; i < maxValue + 1; i++) {
                        while(0 != array[i]) {
                            sortValue.push_back(i);
                            array[i]--;
                        }
                    }
                }

                //DEPRECATED:
                void radixSort(Vector<int>& sortValue) {
                    Vector<Vector<int>> array;   //FIXME: array is better
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());
                    array.push_back(new Vector<int>());

                    for(int i = 0; i < sortValue.size() - 1; i++) {
                        if(sortValue[i] > sortValue[i+1]) {
                            swap(sortValue[i], sortValue[i+1]);
                        }
                    }
                    int maxValue = sortValue[sortValue.size()-1];

                    int flag = 0;
                    while(maxValue != 0) {
                        maxValue /= 10;
                        flag++;
                    }

                    for(int i = 1; i <= flag; i++) {
                        for(int n = 0; n < 10; n++) {
                            array[n].clear();
                        }

                        for(int n = 0; n < sortValue.size(); n++) {
                            int remainder = spliteIntDigit(sortValue[n], i);

                            array[remainder].push_back(sortValue[n]);
                        }

                        sortValue.clear();  //FIXME: array is better
                        for(int j = 0; j < 10; j++) {
                            for(int n = 0; n < array[j].size(); n++) {
                                sortValue.push_back(array[j][n]);
                            }
                        }
                    }
                }

            private:
                void quickSort(Vector<Comparable>& sortValue, int start, int end) {
                    if(start >= end) return;

                    int left = start, right = end - 1;
                    Comparable endValue = sortValue[end];

                    for(int i = 0; i <= right; i++) {
                        if(sortValue[i] <= endValue) {
                            swap(sortValue[left++], sortValue[i]);
                        }
                    }
                    swap(sortValue[left], sortValue[end]);

                    quickSort(sortValue, start, left-1);
                    quickSort(sortValue, left+1, end);
                }

                void mergeSort(Vector<Comparable>& sortValue, int left, int right) {
                    if(left < right) {
                        int center = (left + right) / 2;
                        mergeSort(sortValue, left, center);
                        mergeSort(sortValue, center + 1, right);
                        merge(sortValue, left, center, right);
                    }
                }

                void merge(Vector<Comparable>& sortValue, int left, int center, int right) {
                    Vector<Comparable> leftSubArray(sortValue.begin() + left, sortValue.begin() + center + 1);
                    Vector<Comparable> rightSubArray(sortValue.begin() + center + 1, sortValue.begin() + right + 1);
                    int idxLeft = 0, idxRight = 0;
                    //COMMENT: push max value to end to compare when the left or right array is none
                    leftSubArray.push_back(std::numeric_limits<Comparable>::max());
                    rightSubArray.push_back(std::numeric_limits<Comparable>::max());

                    for (int i = left; i <= right; i++) {
                        sortValue[i] = leftSubArray[idxLeft] < rightSubArray[idxRight]
                         ? leftSubArray[idxLeft++] : rightSubArray[idxRight++];
                    }
                }

                inline int leftChild(int dad) {
                    return 2 * dad + 1; //NOTICE: left child in array or vector
                }
                inline void percDown(Vector<Comparable>& sortValue, int start, int end) {
                    int leftChildNode, parentNode;
                    parentNode = start;
                    leftChildNode = leftChild(parentNode);
                    while(leftChildNode <= end) {
                        //COMMENT: find max node between left to right
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
                }
        };
    }
}

#endif   //CCLIB_ALGORITHM_SORT_H