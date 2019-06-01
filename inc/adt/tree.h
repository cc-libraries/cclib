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
/************************
 * NOTICE: Red Black tree
 * Every node has a color either red or black.
 * Root of tree is always black.
 * There are no two adjacent red nodes (A red node cannot have a red parent or red child).
 * Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes.
************************/
#ifndef CCLIB_ADT_TREE_H
#define CCLIB_ADT_TREE_H
#include "./../../cclib-common/inc/base/common_define.h"

namespace cclib
{
    namespace adt
    {
        enum RedBlackColor {EN_Red, EN_Black};
        enum RedBlackDirection{EN_Left, EN_Right};

        template<typename Comparable>
        struct RedBlackNode {
            Comparable _data;
            RedBlackColor _color;
            RedBlackNode* _parent;
            RedBlackNode* _leftChild;
            RedBlackNode* _rightChild;

            RedBlackNode(): _data(Comparable()), _parent(CC_NULL), _leftChild(CC_NULL), _rightChild(CC_NULL), _color(EN_Black) {}
            RedBlackNode(const Comparable& data, RedBlackColor color, RedBlackNode* parent, RedBlackNode* leftChild, RedBlackNode* rightChild):
             _data(data), _color(color), _parent(parent), _leftChild(leftChild), _rightChild(rightChild) {}

            RedBlackNode* grandParent() {
                if(CC_NULL == this->_parent) {
                    return CC_NULL;
                }

                return this->_parent->_parent;
            }

            RedBlackNode* uncle() {
                if(CC_NULL == grandParent()) {
                    return CC_NULL;
                }

                return this->_parent == grandParent()->_rightChild ? grandParent()->_leftChild : grandParent()->_rightChild;
            }

            RedBlackNode* sibling() {
                return this->_parent->_leftChild == this ? this->_parent->_rightChild : this->_parent->_leftChild;
            }

            RedBlackNode* self() {
                return this->_parent->_leftChild == this ? this->_parent->_leftChild : this->_parent->_rightChild;
            }

            RedBlackDirection direction() {
                return this->_parent->_leftChild == this ? EN_Left : EN_Right;
            }

            // bool operator==(RedBlackNode<Comparable>*& node) const {
            //     return (this->_color == node->_color) && (this->_parent == node->_parent) && (this->_data == node->_data)
            //     && (this->_leftChild == node->_leftChild) && (this->_rightChild == node->_rightChild);
            // }

            // bool operator!=(RedBlackNode<Comparable>*& node) const {
            //     return (this->_color != node->_color) || (this->_parent != node->_parent) || (this->_data != node->_data)
            //     || (this->_leftChild != node->_leftChild) || (this->_rightChild != node->_rightChild);
            // }
        };

        template<typename Comparable>
        class RedBlackTree {
            public:
            RedBlackTree(): _size(0), _M_header(CC_NULL), _M_Nil(new RedBlackNode<Comparable>()) {
                _M_header = _M_Nil;
                _M_header->_leftChild = _M_Nil;
                _M_header->_rightChild = _M_Nil;
            }
            // RedBlackTree(const Comparable& data) {}
            // RedBlackTree(const RedBlackTree& instance) {}
            ~RedBlackTree() {
                if(_M_header) {
                    remove(_M_header);
                }
            }

            // const RedBlackTree& operator=(const RedBlackTree& instance) {}
            bool contains(const Comparable& data) const {}
            bool empty() const {
                return 0 == _size ? true : false;
            }
            cc_size_t size() {
                return _size;
            }
            bool clear() {}

            bool remove(const RedBlackNode<Comparable>*& node) {
                RedBlackNode<Comparable>*& fixNode = remove(node->_data, this->_M_header);
                removeFixUp(fixNode);
            }

            bool insert(const Comparable& data) {
                RedBlackNode<Comparable>*& node = new RedBlackNode<Comparable>(data, EN_Black, CC_NULL, _M_Nil, _M_Nil);
                bool result = true;
                if(_M_Nil == _M_header) {
                    _M_header = node;
                } else {
                    result = insert(node, _M_header);
                }

                if(result) {
                    insertFixUp(node);
                }
            }
            private:
                RedBlackNode<Comparable>* findMin(RedBlackNode<Comparable>*& root) const {
                    if(_M_Nil == root) {
                        return _M_Nil;
                    }

                    while(root->_leftChild != _M_Nil) {
                        root = root->_leftChild;
                    }

                    return root;
                }

                void deleteNode(RedBlackNode<Comparable>*& node) {
                    node->_data.~Comparable();  //TODO: destruct?
                    delete node;
                    node = _M_Nil;
                }

                void removeFixUp(RedBlackNode<Comparable>*& node) {
                    //NOTICE:_M_Nil == node->_leftChild
                    if(EN_Red == node->_color) {
                        // deleteNode(node);
                        node->_data.~Comparable();  //TODO: destruct?
                        node->_parent->_leftChild = _M_Nil;
                        return;
                    }

                    //EN_Black == node->_color
                    if(_M_Nil == node->_rightChild) {
                        rotateLeft(node->_parent);
                        node->_data.~Comparable();  //TODO: destruct?
                        node->_parent->_leftChild = _M_Nil;
                        // deleteNode(node);
                    } else {    //EN_Red == node->_rightChild->_color
                        node->_data = node->_rightChild->_data;
                        node->_rightChild->_data.~Comparable();  //TODO: destruct?
                        node->_rightChild = _M_Nil;
                    }
                }

                RedBlackNode<Comparable>*& remove(const Comparable& data, RedBlackNode<Comparable>*& root) {
                    if(_M_Nil == root) {   //not found
                        return _M_Nil;
                    }

                    if(data < root->_data) {
                        return remove(data, root->_leftChild);
                    } else if(data > root->_data) {
                        return remove(data, root->_rightChild);
                    } else if(data = root->_data){
                        root->_data.~Comparable();  //TODO: destruct?
                         RedBlackNode<Comparable>*& result = findMin(root->_rightChild);
                        root->_data = result->_data;    //NOTICE: not delete root->_rightChild
                        return result;
                    } else {
                        return _M_Nil;
                    }
                }

                void insertFixUp(const RedBlackNode<Comparable>*& node) {
                    if(EN_Red == node->_parent->_color) {
                        RedBlackNode<Comparable>* uncle = node->uncle();
                        if(_M_Nil != uncle) {   //uncle->_color == EN_Red
                            node->_parent->_color = EN_Black;
                            uncle->_color = EN_Black;
                            node->grandParent()->_color = EN_Red;
                            insertFixUp(node->grandParent());
                        } else {
                             if(EN_Right == node->direction() && EN_Left == node->_parent->direction()) {
                                 rotateLeft(node->_parent);
                             } else if(EN_Left == node->direction() && EN_Right == node->_parent->direction()) {
                                 rotateRight(node->_parent);
                             }

                             if(node == node->_parent->_leftChild && node->_parent == node->grandParent()->_leftChild) {
                                 rotateRight(node->grandParent());
                             } else {
                                 rotateLeft(node->grandParent());
                             }
                        }
                    }
                }

                bool insert(const RedBlackNode<Comparable>*& node, RedBlackNode<Comparable>*& root) {
                    bool result = true;

                    if(_M_Nil == root) {
                        node->_color = EN_Red;
                        node->_parent = root->_parent;
                        root = node;
                        ++_size;
                    }
                    else if(node->_data < root->_data)
                        insert(node->_data, root->_leftChild);
                    else if(node->_data > root->_data)
                        insert(node->_data, root->_rightChild);
                    else    //NOTICE: duplicate data, do nothing
                        result = false;

                    return result;
                }

                void rotateRight(RedBlackNode<Comparable>*& y) {
                    RedBlackNode<Comparable>* x = y->_leftChild;
                    y->_leftChild = x->_rightChild; //1. rotate x child

                    if(_M_Nil != x->_rightChild) { //2. rotate child parent
                        x->_rightChild->_parent = y;
                    }

                    x->_parent = y->_parent;    //3. rotate x parent

                    //rotate y parent child
                    if(_M_Nil == y->_parent) {
                        _M_header = x;
                    } else if(y->_parent->_leftChild = y) {
                        y->_parent->_leftChild = x;
                    } else {
                        y->_parent->_rightChild = x;
                    }

                    //5. rotate two node
                    x->_rightChild = y;
                    y->_parent = x;
                }

                void rotateLeft(RedBlackNode<Comparable>*& x) {
                    RedBlackNode<Comparable>* y = x->_leftChild;
                    x->_rightChild = y->_leftChild; //1. rotate y child

                    if(_M_Nil != y->_leftChild) {
                        y->_leftChild->_parent = x->_parent;    //2. rotate child parent
                    }

                    y->_parent = x->_parent;    //3. rotate y parent

                    if(_M_Nil == x->_parent) { //4. rotate x parent child
                        _M_header = y;
                    } else if(x == x->_parent->_leftChild) {
                        x->_parent->_leftChild = y;
                    } else {
                        x->_parent->_rightChild = y;
                    }

                    //5. rotate two node
                    y->_leftChild = x;  //y child
                    x->_parent = y; //x parent
                }

            private:
                cc_size_t _size;
                RedBlackNode<Comparable>* _M_header, _M_Nil;
        };

        template<typename Comparable>
        struct BinaryNode {
            Comparable _data;
            BinaryNode* _leftChild;
            BinaryNode* _rightChild;
            BinaryNode(const Comparable& data, BinaryNode* leftChild, BinaryNode* rightChild)
            : _data(data), _leftChild(leftChild), _rightChild(rightChild) {}
        };

        template<typename Comparable>
        class BinarySearchTree {
            public:
                BinarySearchTree(): _size(0), _M_node(CC_NULL) {}
                // BinarySearchTree(const BinarySearchTree& instance) {}
                ~BinarySearchTree() {
                    clear();
                }

            public:
                bool contains(const Comparable& data) {
                    return preOrderTraversalHandle(data, this->_M_node);
                }

                BinaryNode<Comparable>* begin() {
                    return this->_M_node;
                }

                bool insert(const Comparable& data) {
                    bool result = insert(data, this->_M_node);
                    return result;
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
                    if(CC_NULL == root) {   //not found
                        return false;
                    }

                    if(data < root->_data) {
                        remove(data, root->_leftChild);
                    } else if(data > root->_data) {
                        remove(data, root->_rightChild);
                    } else if(data == root->_data && root->_leftChild != CC_NULL && root->_rightChild != CC_NULL) {
                        root->_data.~Comparable();  //NOTICE: destruct?
                        root->_data = findMin(root->_rightChild)->_data;
                        remove(root->_data, root->_rightChild);
                    } else {    //data == root->_data && (root->_leftChild != CC_NULL || root->_rightChild != CC_NULL)
                        BinaryNode<Comparable>* temp = root;
                        if(root->_leftChild != CC_NULL) {
                            root = root->_leftChild;
                            // root->_leftChild->_data.~Comparable();
                            // delete root->_leftChild;
                            // root->_leftChild = CC_NULL;
                        } else {
                            root = root->_rightChild;
                            // root->_rightChild->_data.~Comparable();
                            // delete root->_rightChild;
                            // root->_rightChild = CC_NULL;
                        }
                        delete temp;    //NOTICE: delete?
                        --_size;
                        return true;
                    }
                }

                BinaryNode<Comparable>* findMin(BinaryNode<Comparable>*& root) const {
                    IS_POINT_NULL_POINT(root);

                    while(root->_leftChild != CC_NULL) {
                        root = root->_leftChild;
                    }

                    return root;
                }

                BinaryNode<Comparable>* findMax(BinaryNode<Comparable>*& root) const {
                    IS_POINT_NULL_POINT(root);

                    while(root->_rightChild != CC_NULL) {
                        root = root->_rightChild;
                    }

                    return root;
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
                    else if(data < root->_data) {
                        insert(data, root->_leftChild);
                    }
                    else if(data > root->_data) {
                        insert(data, root->_rightChild);
                    }
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