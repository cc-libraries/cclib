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
/************************
 * NOTICE: Binary search tree
 * it is a binary tree;
 * each node contains a value;
 * a total order is defined on these values (every two values can be compared with each other);
 * left subtree of a node contains only values lesser, than the node's value;
 * right subtree of a node contains only values greater, than the node's value.
*************************/
#ifndef CCLIB_ADT_TREE_H
#define CCLIB_ADT_TREE_H
#include "./../../cclib-common/inc/base/common_define.h"
#include <iostream>
#include <string>

namespace cclib
{
    namespace adt
    {
        template<typename Comparable>
        struct BinaryNode {
            Comparable _data;
            BinaryNode* _leftChild;
            BinaryNode* _rightChild;
            BinaryNode(const Comparable& data, BinaryNode* leftChild, BinaryNode* rightChild)
            : _data(data), _leftChild(leftChild), _rightChild(rightChild) {}
        };

        template<typename _Key, typename _Value>
        struct Pair {
            _Key _key;
            _Value _value;

            Pair() {}
            Pair(const _Key& key, const _Value& value): _key(key), _value(value) {}
            Pair(const _Key& key): _key(key), _value(CC_NULL) {}

            Pair& operator=(const Pair& instance) {
                this->_key = instance._key;
                this->_value = instance._value;
            }

            bool operator==(const Pair& instance) const {
                return this->_key == instance._key;
            }

            bool operator!=(const Pair& instance) const {
                return this->_key != instance._key;
            }

            bool operator<(const Pair& instance) const {
                return this->_value < instance._value;
            }

            bool operator>(const Pair& instance) const {
                return this->_value > instance._value;
            }

            static std::string to_string(Pair& instance) {
                return std::to_string(instance._key) + " " + std::to_string(instance._value);
            }
        };

        template<typename Comparable>
        class BinarySearchTree {
            public:
                BinarySearchTree(): _size(0), _M_node(CC_NULL) {}
                BinarySearchTree(const BinarySearchTree& instance) {}
                ~BinarySearchTree() {
                    // clear();
                }

            public:
                bool contains(const Comparable& data) {
                    return preOrderTraversalHandle(data, this->_M_node);
                }

                BinaryNode<Comparable>* begin() {
                    return this->_M_node;
                }

                bool insert(const Comparable& data) {
                    insert(data, this->_M_node);
                }

                bool remove(const Comparable& data) {
                    remove(data, this->_M_node);
                }

                Comparable find(const Comparable& key) {  //TODO: change to callback
                    return find(key, this->_M_node);
                }

                cc_size_t size() {
                    return _size;
                }

                bool empty() const {
                    return CC_INIT == _size;
                }

                bool clear() {
                    clear(this->_M_node);
                }

            private:
                bool clear(BinaryNode<Comparable>*& root) {
                    if(CC_NULL == root) {
                        return true;
                    }

                    remove(root->_data, root);
                    return clear(root);
                }

                bool remove(const Comparable& data, BinaryNode<Comparable>*& root) {
                    // std::cout << "root: " << root << " data:" << data << std::endl;
                    if(CC_NULL == root) {   //not found
                        return false;
                    }

                    // std::cout << "root->_data: " << root->_data << " root->_leftChild: " << root->_leftChild << " root->_rightChild: " << root->_rightChild << std::endl;
                    if(data < root->_data) {
                        // std::cout << "root->_data1: " << root->_data << std::endl;
                        remove(data, root->_leftChild);
                    } else if(data > root->_data) {
                        // std::cout << "root->_data2: " << root->_data << " root->_rightChild: " << root->_rightChild << std::endl;
                        remove(data, root->_rightChild);
                    } else if(data == root->_data && root->_leftChild != CC_NULL && root->_rightChild != CC_NULL) {
                        // std::cout << "root->_data3: " << root->_data << std::endl;
                        //TODO: root->_data.~Comparable();
                        root->_data = findMin(root->_rightChild)->_data;
                        remove(root->_data, root->_rightChild);
                    } else {    //data == root->_data && (root->_leftChild != CC_NULL || root->_rightChild != CC_NULL)
                        //TODO: delete root->data?
                        // std::cout << "root->_data4: " << root->_data << std::endl;
                        root = (root->_leftChild != CC_NULL) ? root->_leftChild : root->_rightChild;
                        --_size;
                        return true;
                    }
                }

                BinaryNode<Comparable>* findMin(BinaryNode<Comparable>*& root) const {
                    IS_POINT_NULL_POINT(root);

                    if(CC_NULL == root->_leftChild) {
                        return root;
                    }

                    return findMin(root->_leftChild);
                }

                BinaryNode<Comparable>* findMax(BinaryNode<Comparable>*& root) const {
                    IS_POINT_NULL_POINT(root);

                    if(CC_NULL == root->_rightChild) {
                        return root;
                    }

                    return findMax(root->_rightChild);
                }

                Comparable find(const Comparable& key, BinaryNode<Comparable>*& root) {
                    IS_POINT_NULL_POINT(root);

                    if(key == root->_data) {
                        return root->_data;
                    }
                    if(CC_NULL != root->_leftChild) {
                        return find(key, root->_leftChild);
                    }
                    if(CC_NULL != root->_rightChild) {
                        return find(key, root->_rightChild);
                    }

                    std::cout << "result: " <<std::endl;
                    return CC_NULL;
                }

                bool preOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(data == root->_data)
                        return true;
                    if(CC_NULL != root->_leftChild)
                        return preOrderTraversalHandle(data, root->_leftChild);
                    if(CC_NULL != root->_rightChild)
                        return preOrderTraversalHandle(data, root->_rightChild);

                    return false;
                }

                bool inOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(CC_NULL != root->_leftChild)
                        return inOrderTraversalHandle(data, root->_leftChild);
                    if(data == root->_data)
                        return true;
                    if(CC_NULL != root->_rightChild)
                        return inOrderTraversalHandle(data, root->_rightChild);

                    return false;
                }

                bool postOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(CC_NULL != root->_leftChild)
                        return postOrderTraversalHandle(data, root->_leftChild);
                    if(CC_NULL != root->_rightChild)
                        return postOrderTraversalHandle(data, root->_rightChild);
                    if(data == root->_data)
                        return true;

                    return false;
                }

                bool insert(const Comparable& data, BinaryNode<Comparable>*& root) {
                    bool result = true;

                    if(CC_NULL == root) {
                        root = new BinaryNode<Comparable>(data, CC_NULL, CC_NULL);
                        ++_size;
                    }
                    else if(data < root->_data)
                        insert(data, root->_leftChild);
                    else if(data > root->_data)
                        insert(data, root->_rightChild);
                    else    //NOTICE: duplicate data, do nothing
                        result = false;

                    return result;
                }

            private:
                cc_size_t _size;
                BinaryNode<Comparable>* _M_node;
        };
    } // namespace adt
} // namespace cclib


#endif //CCLIB_ADT_TREE_H