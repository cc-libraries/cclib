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
            Node* _prev;
            Node* _next;

            Node():_data(T()), _prev(NULL), _next(NULL) {}
            Node(const T& data): _data(data) {}
            Node(const T& data, Node* prev, Node* next): _data(T()), _prev(NULL), _next(NULL) {}
            // Node(const T& data): _data(new T(data)) {}

            bool operator==(const Node* instance) const {
                return (instance->_data == this->_data) && (instance->_prev == this->_prev) && (instance->_next == this->_next);
            }

            bool operator!=(const Node* instance) const {
                return (instance->_data != this->_data) && (instance->_prev != this->_prev) && (instance->_next != this->_next);
            }

            // void operator delete(void* node) {
            //     delete ((Node<T>*)node)->_data;
            //     ((Node<T>*)node)->_prev = ((Node<T>*)node)->_next = NULL;
            // }
        };

        template<typename T>
        class ListIterator {
            public:
                typedef ListIterator<T> _Self;

            public:
                ListIterator(): _M_node(NULL) {}

                ListIterator(Node<T>* nodeData) {
                    _M_node = nodeData;
                }

                ListIterator(const _Self& itr) : _M_node(itr._M_node) {}

                ~ListIterator() {}

                T& operator*() {
                    // return NULL == _M_node ? NULL : *(_M_node->_data);
                    // std::cout << "_M_node: " << _M_node->_data << std::endl;
                    return _M_node->_data;
                }

                _Self operator++() {
                    _M_node = NULL == _M_node ? NULL : _M_node->_next;
                    return *this;
                }

                _Self operator++(int) {
                    _Self _temp = *this;
                    _M_node = NULL == _M_node ? NULL : _M_node->_next;
                    return _temp;
                }

                _Self operator--() {
                    _M_node = NULL == _M_node ? NULL : _M_node->_prev;
                    return *this;
                }

                _Self operator--(int) {
                    _Self _temp = *this;
                    _M_node = NULL == _M_node ? NULL : _M_node->_prev;
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
                explicit List() : _size(0), _head(NULL), _tail(NULL) {
                    _head = new Node<T>();
                    _tail = new Node<T>();
                    _head->_next = _tail;
                    _tail->_prev = _head;
                }

                List( const List& instance): _size(instance._size) {
                    _size = 0;
                    _head = new Node<T>();
                    _tail = new Node<T>();
                    _head->_next = _tail;
                    _tail->_prev = _head;
                    *this = instance;
                }

                ~List() {
                    clear();

                    delete _head;
                    delete _tail;
                }

                const List& operator=(const List& instance) {
                    if( this != &instance ) {
                        for(iterator itr = instance.begin(); itr != instance.end(); ++itr) {
                            push_back(*itr);
                        }
                    }

                    return *this;
                }

                iterator begin() {
                    iterator iterator(_head->_next);
                }

                iterator end() {
                    return iterator(_tail);
                }

                size_t size() const {
                    return _size;
                }

                bool empty() const {
                    return _size == 0;
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
                    erase(-- end());  //TODO:
                    return true;
                }

                iterator insert(iterator itr, const T& data) {
                    Node<T>* temp = itr._M_node;
                    _size++;

                    return iterator(temp->_prev = temp->_prev->_next = new Node<T>(data, temp->_prev, temp));
                }

                iterator erase(iterator itr) {
                    Node<T>* nextNode = itr._M_node;
                    iterator retVal(nextNode->_next);
                    itr._M_node->_prev->_next = itr._M_node->_next;
                    itr._M_node->_next->_prev = itr._M_node->_prev;

                    // delete itr._M_node->_data;
                    // itr._M_node->_data = NULL;
                    delete itr._M_node;
                    itr._M_node = NULL;
                    _size--;

                    return retVal;
                }

            private:
                size_t _size;
                Node<T>* _head;
                Node<T>* _tail;
        };
    }
}

#endif  //CCLIB_ADT_LIST_H