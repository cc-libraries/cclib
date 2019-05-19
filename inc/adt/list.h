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

namespace cclib {
    namespace adt {
        template<typename T>
        struct Node {
            T _data;
            Node* prev;
            Node* next;

            Node(): _data = T(), prev(NULL), next(NULL) {}

            bool operator==(const Node* instance) const {
                return (instance->_data == this->_data) && (instance->prev == this->prev) && (instance->next == this->next);
            }

            bool operator!=(const Node* instance) const {
                return (instance->_data != this->_data) && (instance->prev != this->prev) && (instance->next != this->next);
            }
        };

        template<typename T>
        class ListIterator {
            public:
                typedef ListIterator<T> _Self;

            public:
                ListIterator() {}
                ListIterator(Node* nodeData) : _M_node(nodeData) {}
                ListIterator(_Self& itr) : _M_node(itr._M_node) {}
                ~ListIterator() {}
                T operator*() { return _M_node->_data; }
                _Self operator++() {
                    _M_node = NULL == _M_Node ? NULL : _M_node->next;
                    return *this;
                }
                _Self operator++(int) {
                    _Self _temp = *this;
                    _M_node = NULL == _M_Node ? NULL : _M_node->next;
                    return *this;
                }

                bool operator== (const iterator& instance) const {
                    return _M_node == instance._M_node;
                }

                bool operator!= (const iterator& instance) const {
                    return _M_node != instance._M_node;
                }

            private:
                Node* _M_node;
        };

        template <typename T>
        class List {
            public:
                typedef ListIterator<T> iterator;

            public:
                List() : _size(0), _M_node(NULL) {}
                List( const List& instance) {
                    *this = instance;
                }
                ~List() {
                    clear();
                    delete _M_node;
                    _M_node = NULL;
                }

                const List& operator=(const List& instance) {
                    if( this != &instance ) {
                        _M_node
                    }

                }

                iterator begin() {}
                iterator end() {}

                size_t size() const {}
                bool empty() const {}
                bool clear() {}

                bool push_front(const T& data) {}
                bool push_back(const T& data) {}
                bool pop_front(const T& data) {}
                bool pop_back(const T& data) {}

                iterator insert(iterator itr, const T& data) {}
                iterator erase(iterator itr) {}
                iterator erase(size_t index) {}

            private:
                size_t _size;
                Node* _M_node;
        };
    }
}

#endif  //CCLIB_ADT_LIST_H