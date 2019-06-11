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
#ifndef CCLIB_ADT_STACK_H
#define CCLIB_ADT_STACK_H

#include "./../../cclib-common/inc/base/common_define.h"
#include "vector.h"
#include <iostream>

using namespace cclib;
using namespace cclib::adt;

namespace cclib {
    namespace adt {
        template<typename T>
        class Stack {
            public:
                Stack():_M_vector(new Vector<T>()) {}
                ~Stack() {
                    delete _M_vector;
                    _M_vector = CC_NULL;
                }

            public:
                bool push(const T& data) {
                    return _M_vector->push_back(data);
                }

                bool pop() {
                    return _M_vector->pop_back();
                }

                T& top() {
                    typename Vector<T>::Iterator itr = _M_vector->end();
                    return *(--itr);
                }

            private:
                Vector<T>* _M_vector;
        };
    } //namespace adt
} //namespace cclib

#endif //CCLIB_ADT_STACK_H