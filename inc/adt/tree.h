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

        template<typename Comparable>
        class BinarySearchTreeIterator {

        };

        template<typename Comparable>
        class BinarySearchTree {
            typedef BinarySearchTreeIterator<Comparable> iterator;

            public:
                BinarySearchTree() {}
                BinarySearchTree(const BinarySearchTree& instance) {}
                ~BinarySearchTree() {}

            public:
                bool contains(const Comparable& data) const {
                    return preOrderTraversalHandle(data, this->_M_node);
                }

                bool insert(const Comparable& data) {
                    insert(data, this->_M_node);
                }

                bool remove(const Comparable& data) {}

                bool empty() const {}

                bool clear() {}

            private:
                bool preOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(data == root->_data)
                        return true;
                    if(NULL != root->_leftChild)
                        preOrderTraversalHandle(data, root->_leftChild);
                    if(NULL != root->_rightChild)
                        preOrderTraversalHandle(data, root->_rightChild);

                    return false;
                }

                bool inOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(NULL != root->_leftChild)
                        inOrderTraversalHandle(data, root->_leftChild);
                    if(data == root->_data)
                        return true;
                    if(NULL != root->_rightChild)
                        inOrderTraversalHandle(data, root->_rightChild);

                    return false;
                }

                bool postOrderTraversalHandle(const Comparable& data, const BinaryNode<Comparable>* root) {
                    IS_POINT_NULL_POINT(root);

                    if(NULL != root->_leftChild)
                        postOrderTraversalHandle(data, root->_leftChild);
                    if(NULL != root->_rightChild)
                        postOrderTraversalHandle(data, root->_rightChild);
                    if(data == root->_data)
                        return true;

                    return false;
                }

                bool insert(const Comparable& data, const BinaryNode<Comparable>* root) {
                    bool result = true;

                    if(NULL == root)
                        root = new BinaryNode<Comparable>(data, NULL, NULL);
                    else if(data < root->_data)
                        insert(data, root->_rightChild);
                    else if(data > root->_data)
                        insert(data, root->_leftChild);
                    else    //NOTICE: duplicate data, do nothing
                        result = false;

                    return result;
                }

            private:
                size_t _size;
                BinaryNode<Comparable>* _M_node;
        };
    } // namespace adt
} // namespace cclib


#endif //CCLIB_ADT_TREE_H