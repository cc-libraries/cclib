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
#ifndef CCLIB_ADT_VECTOR_H
#define CCLIB_ADT_VECTOR_H

#include "iterator.h"

namespace cclib {
    namespace adt {
        template<typename T>
        class vector {
            public:
                // typedef iterator<T>    iterator;

            public:
                explicit vector(size_t num) : _size(num) {
                    //TODO:
                    _M_first = new T[num];
                 }
                vector(vector<T>& instance) {
                    //TODO:
                    operator=(instance);
                }
                ~vector() {
                    //TODO:
                    delete[] _M_first;
                }

                vector& operator=(const vector<T>& instance) {
                    //TODO:
                    return nullptr;
                }

                T& operator[] (size_t index) {
                    //TODO:
                    return *(_M_first + index);
                }

                size_t size() const {
                    //TODO:
                    return 0;
                }

                bool empty() const {
                    //TODO:
                    return true;
                }

                bool push_back(const T& data) {
                    //TODO:
                    return true;
                }

                bool pop_back() {
                    //TODO:
                    return true;
                }

                iterator getIterator() {
                    //TODO:
                    return new vectorIterator();
                }

            private:
                size_t _size;
                T*  _M_first;
                class vectorIterator : public iterator {
                    public:
                        T operator*() {
                            //TODO:
                        }
                        auto operator++() {
                            //TODO:
                        }
                        auto operator++(int) {
                            //TODO:
                        }

                        auto begin() {
                            //TODO:
                        }
                        auto end() {
                            //TODO:
                        }
                        auto next() {
                            //TODO:
                        }
                }
        };
    }
}

#endif  //CCLIB_ADT_VECTOR_H