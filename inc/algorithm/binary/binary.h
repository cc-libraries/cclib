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
#ifndef CCLIB_ALGORITHM_BINARY_H
#define CCLIB_ALGORITHM_BINARY_H

#include "./../../adt/vector.h"
#include "./../../../cclib-common/inc/base/common_define.h"
#include "./../../../cclib-common/inc/util/util.h"

using namespace cclib;
using namespace cclib::adt;

namespace cclib {
    namespace algorithm {
        class Binary {
            public:
                Vector<int> increase() {
                    if(0 == value.size()) {
                        value.push_back(0);
                        return value;
                    }
                    Vector<int>::Iterator itr = value.end();
                    Vector<int> va = increaseFixUP(value, itr);
                    cclib::common::util::printVectorValue(value);
                }

            private:
                Vector<int> increaseFixUP(Vector<int>& val, Vector<int>::Iterator& itr) {
                    if(0 == *itr) {
                        *itr = 1;
                    } else {
                        if(itr == val.begin()) {
                            val.push_back(0);
                        } else {
                            *itr-- = 0;
                            increaseFixUP(val, itr);
                        }
                    }

                    return val;
                }

                Vector<int> value;
        };
    }
}

#endif //CCLIB_ALGORITHM_BINARY_H