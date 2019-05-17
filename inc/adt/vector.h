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

// #include "iterator.h"
#include <stddef.h>
#include <iostream>

namespace cclib {
    namespace adt {
        const size_t _default_storage = 1;

        // template<typename T>
        // class vectorIterator {
        //     public:
        //         typedef vectorIterator<T> _Self;

        //     public:
        //         T operator*() {}
        //         _Self operator++() {}
        //         _Self operator++(int) {}

        //         _Self begin() {}
        //         _Self next() {}
        // };

        template<typename T>
        class Vector {
            public:
                typedef T*    Iterator;

            public:
                explicit Vector(size_t num = 0) : _size(0 == num ? _default_storage : num), _storage_count(0), _M_first(NULL) {
                    _M_first = new T[_size];
                 }

                Vector(const Vector<T>& instance) : _size(instance._size), _storage_count(instance._storage_count) {
                    operator=(instance);
                }

                Vector(Iterator begin, Iterator end) : _size(begin - end), _storage_count(_size) {
                    _M_first = new T[_size];
                    for(int i = 0; i < _size; i++) {
                        _M_first[i] = *(begin + i);
                    }
                }

                ~Vector() {
                    delete[] _M_first;
                    _M_first = NULL;
                }

                Vector<T>& operator=(const Vector<T>& instance) {
                    _M_first = new T[_size];
                    for(int i = 0; i < _storage_count; i++) {
                        _M_first[i] = instance._M_first[i];
                    }

                    return *this;
                }

                T& operator[] (size_t index) {
                    return *(_M_first + index);
                }

                Iterator begin() {
                    return _M_first;
                }

                Iterator end() {
                    return _M_first + _storage_count;
                }

                bool clear() {
                    delete[] _M_first;
                    _M_first = NULL;
                    _size = _storage_count = 0;

                    return true;
                }

                size_t size() const {
                    return _storage_count;
                }

                bool empty() const {
                    return 0 == _storage_count ? true : false;
                }

                bool push_back(const T& data) {
                    if(_size == _storage_count) {
                        doubleExpansion();
                    }

                    _M_first[_storage_count++] = data;
                    return true;
                }

                bool pop_back() {
                    _M_first[--_storage_count] = T(0);
                    return true;
                }

                bool insert(Iterator position, const T& data) {
                    int pos = position - _M_first;
                    return insert(pos, data);
                }

                bool insert(int index, const T& data) {
                    if(index > _storage_count) return false;

                    if(_size == _storage_count) {
                        doubleExpansion();
                    }

                    T* temp = new T[_size];
                    for(int i = 0; i < index; i++) {
                        temp[i] = _M_first[i];
                    }

                    temp[index] = data;

                    for(int i = index; i < _storage_count; i++) {
                        temp[i + 1] = _M_first[i];
                    }
                    ++_storage_count;

                    delete[] _M_first;
                    _M_first = temp;

                    return true;
                }

                bool earse(Iterator position) {
                    size_t pos = position - _M_first;
                    return earse(pos);
                }

                bool earse(size_t index) {
                    if(index > _storage_count) return false;

                    for(int i = index; i < _size - 1; i++) {
                        _M_first[i] = _M_first[i + 1];
                    }

                    _M_first[_storage_count - 1] = T(0);
                    --_storage_count;
                    return true;
                }

            private:
                void doubleExpansion() {
                    _size = 2 * _size + 1;
                    T* temp = new T[_size];
                    for(int i = 0; i < _storage_count; i++) {    //NOTICE: memcpy is the same time complexity O(n)
                        temp[i] = _M_first[i];
                    }
                    delete[] _M_first;
                    _M_first = temp;
                }
                size_t _size;
                size_t _storage_count;
                T*  _M_first;
        };
    }
}

#endif  //CCLIB_ADT_VECTOR_H