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
            T* _data;
            Node* _prev;
            Node* _next;

            Node(): _data(NULL), _prev(NULL), _next(NULL) {}
            Node(T* data): _data(data) {}

            bool operator==(const Node* instance) const {
                return (instance->_data == this->_data) && (instance->_prev == this->_prev) && (instance->_next == this->_next);
            }

            bool operator!=(const Node* instance) const {
                return (instance->_data != this->_data) && (instance->_prev != this->_prev) && (instance->_next != this->_next);
            }

            void operator delete(void* node) {
                delete ((Node<T>*)node)->_data;
                ((Node<T>*)node)->_prev = ((Node<T>*)node)->_next = NULL;
            }
        };

        template<typename T>
        class ListIterator {
            public:
                typedef ListIterator<T> _Self;

            public:
                ListIterator() {}

                ListIterator(Node<T>* nodeData) {
                    _M_node = nodeData;
                }

                ListIterator(const _Self& itr) : _M_node(itr._M_node) {}

                ~ListIterator() {}

                T operator*() { return *(_M_node->_data); }

                _Self operator++() {
                    _M_node = NULL == _M_node ? NULL : _M_node->_next;
                    return *this;
                }

                _Self operator++(int) {
                    _Self _temp = *this;
                    _M_node = NULL == _M_node ? NULL : _M_node->_next;
                    return *this;
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
                explicit List() : _size(0), _M_node(NULL) {
                    _M_node = new Node<T>();
                    _M_node->_next = _M_node;
                    _M_node->_prev = _M_node;
                }

                List( const List& instance): _size(instance._size) {
                    *this = instance;
                }

                ~List() {
                    clear();

                    // if(NULL != _M_node) {
                        // delete _M_node;
                        // _M_node = NULL;
                    // }
                }

                const List& operator=(const List& instance) {
                    if( this != &instance ) {
                        for(iterator itr = instance.begin(); itr != instance.end(); ++itr) {
                            push_back(*itr);
                        }
                    }

                    return *this;
                }

                ListIterator<T> begin() {
                    return ListIterator<T>((Node<T>*)_M_node->_next);
                }

                iterator end() {
                    return iterator(_M_node);
                }

                size_t size() const {
                    return _size;
                }

                bool empty() const {
                    return _M_node->_next == _M_node;
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
                    iterator temp = end();
                    erase(--temp);  //TODO:
                }

                iterator insert(iterator itr, const T& data) {
                    Node<T>* temp = new Node<T>(new T(data));
                    temp->_next = itr._M_node;
                    temp->_prev = itr._M_node->_prev;
                    std::cout << "hello_chenchen: " << std::endl;
                    itr._M_node->_prev->_next = temp;
                    itr._M_node->_prev = temp;
                    _size++;

                    return iterator(temp);
                }

                ListIterator<T> erase(ListIterator<T> itr) {
                    Node<T>* nextNode = itr._M_node->_next;
                    itr._M_node->_prev->_next = itr._M_node->_next;
                    itr._M_node->_next->_prev = itr._M_node->_prev;

                    // delete itr._M_node->_data;
                    // itr._M_node->_data = NULL;
                    delete itr._M_node;
                    itr._M_node = NULL;

                    return iterator(nextNode);
                }

            private:
                size_t _size;
                Node<T>* _M_node;
        };
    }
}

#endif  //CCLIB_ADT_LIST_H