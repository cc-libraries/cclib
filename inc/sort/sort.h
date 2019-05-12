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
        };
    }
}

#endif   //CCLIB_CCALGORITHM_SORT_H