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
#ifndef CCLIB_ADT_LIST_H
#define CCLIB_ADT_LIST_H

#include "./../../cclib-common/inc/base/common_define.h"

namespace cclib {
    namespace adt {
        template<typename T>
        struct Node {
            T _data;
            Node* _prev;
            Node* _next;

            Node():_data(T()), _prev(CC_NULL), _next(CC_NULL) {}
            Node(const T& data): _data(data) {}
            Node(const T& data, Node* prev, Node* next): _data(T()), _prev(prev), _next(next) {}
            // Node(const T& data): _data(new T(data)) {}

            bool operator==(const Node* instance) const {
                return (instance->_data == this->_data) && (instance->_prev == this->_prev) && (instance->_next == this->_next);
            }

            bool operator!=(const Node* instance) const {
                return (instance->_data != this->_data) && (instance->_prev != this->_prev) && (instance->_next != this->_next);
            }

            void operator delete(void* node) {
                ((Node<T>*)node)->_data.~T();
                ((Node<T>*)node)->_prev = ((Node<T>*)node)->_next = CC_NULL;
            }
        };

        template<typename T>
        class ListIterator {
            public:
                typedef ListIterator<T> _Self;

            public:
                ListIterator(): _M_node(CC_NULL) {}

                ListIterator(Node<T>* nodeData) {
                    _M_node = nodeData;
                }

                ListIterator(const _Self& itr) : _M_node(itr._M_node) {}

                ~ListIterator() {}

                T operator*() {
                    return CC_NULL == _M_node ? CC_NULL : _M_node->_data;
                }

                _Self operator++() {
                    _M_node = CC_NULL == _M_node ? CC_NULL : _M_node->_next;
                    return *this;
                }

                _Self operator++(int) {
                    _Self _temp = *this;
                    _M_node = CC_NULL == _M_node ? CC_NULL : _M_node->_next;
                    return _temp;
                }

                _Self operator--() {
                    _M_node = CC_NULL == _M_node ? CC_NULL : _M_node->_prev;
                    return *this;
                }

                _Self operator--(int) {
                    _Self _temp = *this;
                    _M_node = CC_NULL == _M_node ? CC_NULL : _M_node->_prev;
                    return _temp;
                }

                bool operator== (const _Self& instance) const {
                    return _M_node == instance._M_node;
                }

                bool operator!= (const _Self& instance) const {
                    return _M_node != instance._M_node;
                }

            // friend class List;

            public:
                Node<T>* _M_node;
        };

        template <typename T>
        class List {
            public:
                typedef ListIterator<T> iterator;

            public:
                explicit List() : _size(0), _M_node(new Node<T>()) {
                    _M_node->_next = _M_node;
                    _M_node->_prev = _M_node;
                }

                List(List& instance): _size(0), _M_node(new Node<T>()) {
                    this->_M_node->_next = this->_M_node;
                    this->_M_node->_prev = this->_M_node;
                    operator=(instance);
                }

                ~List() {
                    clear();

                    if(CC_NULL != _M_node) {
                        delete _M_node;
                        _M_node = CC_NULL;
                    }
                }

                const List& operator=(List& instance) {
                    if( this != &instance ) {
                        for(iterator itr = instance.begin(); itr != instance.end(); ++itr) {
                            push_back(*itr);
                        }
                    }

                    return *this;
                }

                iterator begin() {
                    return iterator((Node<T>*)_M_node->_next);
                }

                iterator end() {
                    return iterator(_M_node);
                }

                cc_size_t size() const {
                    return _size;
                }

                bool empty() const {
                    return 0 == _size;
                }

                bool clear() {
                    while(!empty()) {
                        pop_front();
                    }
                    return true;
                }

                bool push_front(const T& data) {
                    insert(begin(), data);
                    return true;
                }

                bool push_back(const T& data) {
                    insert(end(), data);
                    return true;
                }

                bool pop_front() {
                    erase(begin());
                    return true;
                }

                bool pop_back() {
                    erase(--end());
                    return true;
                }

                iterator insert(iterator itr, const T& data) {
                    Node<T>* temp = new Node<T>(data);
                    temp->_next = itr._M_node;
                    temp->_prev = itr._M_node->_prev;
                    itr._M_node->_prev->_next = temp;
                    itr._M_node->_prev = temp;
                    _size++;

                    return temp;
                }

                iterator erase(iterator itr) {
                    Node<T>* nextNode = itr._M_node->_next;
                    itr._M_node->_prev->_next = itr._M_node->_next;
                    itr._M_node->_next->_prev = itr._M_node->_prev;

                    delete itr._M_node;
                    itr._M_node = CC_NULL;
                    _size--;

                    return iterator(nextNode);
                }

            private:
                cc_size_t _size;
                Node<T>* _M_node;
        };
    } // namespace adt
} // namespace cclib

#endif  //CCLIB_ADT_LIST_H
