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
                return this->_parent->_leftChild == this ? this->_parent->_rightChild | this->_parent->_leftChild;
            }
        };

        template<typename Comparable>
        class RedBlackTree {
            public:
            RedBlackTree(): _size(0), _M_node(CC_NULL), _M_Nil(new RedBlackNode<Comparable>()) {}
            // RedBlackTree(const Comparable& data) {}
            // RedBlackTree(const RedBlackTree& instance) {}
            ~RedBlackTree() {
                if(_M_header) {
                    remove(_M_header);
                }
            }

            // const RedBlackTree& operator=(const RedBlackTree& instance) {}
            bool contains(const Comparable& data) const {}
            bool empty() const {}
            cc_size_t size() {}
            bool clear() {}

            bool insert(const Comparable& data) {
                if(CC_NULL == _M_header) {
                    _M_header = new RedBlackNode<Comparable>(data, EN_Black, CC_NULL, CC_NULL, CC_NULL);
                } else {
                    insert(_M_header, data);
                }
            }
            bool remove(const Comparable& data) {
                remove(_M_header, data);
            }

            Comparable find(const Comparable& data) {

            }

            private:
                bool remove(RedBlackNode<Comparable>* node, Comparable& data) {
                    if(node->_data > data) {
                        if(node->_leftChild == _M_Nil) {
                            return false;
                        }
                        return remove(node->_leftChild, data);
                    } else if(node->_data < data) {
                        if(node->_rightChild == _M_Nil) {
                            return false;
                        }
                        return remove(node->_rightChild, data);
                    } else {    //node->_data == data
                        if(node->_rightChild == _M_Nil) {
                            removeChild(node);
                            return ture;
                        }
                        RedBlackNode<Comparable>* minNode = findMin(node->_rightChild);
                        std::swap(node->_data, minNode->_data);
                        removeChild(minNode);
                        return true;
                    }
                }

                RedBlackNode<Comparable>* findMin(RedBlackNode<Comparable>* node) {
                    if(node->_leftChild == _M_Nil) {
                        return node;
                    }

                    return findMin(node->_leftChild);
                }

                void removeChild(RedBlackNode<Comparable>* node) {
                    RedBlackNode<Comparable>* child = node->_leftChild == _M_Nil ? node->_rightChild : node->_leftChild;
                    if(node->_parent == CC_NULL && node->_leftChild == _M_Nil && node->_rightChild == _M_Nil) {
                        node = CC_NULL;
                        _M_header = node;
                        return;
                    }

                    if(CC_NULL == node->_parent) {
                        delete node;
                        child->_parent = CC_NULL;
                        _M_header = child;
                        _M_header->_color = EN_Black;
                        return;
                    }

                    if(node->_parent->_leftChild == node) {
                        node->_parent->_leftChild = child;
                    } else {
                        node->_parent->_rightChild = child;
                    }
                    child->_parent = node->_parent;

                    if(EN_Black == node->_color) {
                        if(EN_Red == child->_color) {
                            child->_color = EN_Black;
                        } else {
                            remove(child);
                        }
                    }
                }

                void remove(RedBlackNode<Comparable>* node) {
                    if(CC_NULL == node->_parent) {
                        node->_color = EN_Black;
                        return;
                    }

                    if(EN_Red == node->sibling()->_color) {
                        node->_parent->_color = EN_Red;
                        node->sibling()->_color = EN_Black;
                        if(node == node->_parent->_leftChild) {
                            rotateLeft(node->_parent);
                        } else {
                            rotateRight(node->_parent);
                        }
                    }

                    if( (EN_Black == node->_parent->_color) && (EN_Black == node->sibling()->_color) &&
                    (EN_Black == node->sibling()->_leftChild->_color) && (EN_Black == node->sibling()->_rightChild->_color)) {
                        node->sibling()->_color = EN_Red;
                        remove(node->_parent);
                    } else if((EN_Red == node->_parent->_color) && (EN_Black == node->sibling()->_color) &&
                    (EN_Black == node->sibling()->_leftChild->_color) && (EN_Black == node->sibling()->_rightChild->_color)) {
                        node->sibling()->_color = EN_Red;
                        node->_parent->_color = EN_Black;
                    } else {
                        if(EN_Black == node->sibling()->_color) {
                            if((node == node->_parent->_leftChild) && (EN_Red == node->sibling()->_leftChild->_color) &&
                            (EN_Black == node->sibling()->_rightChild->_color)) {
                                node->sibling()->_color = EN_Red;
                                node->sibling()->_leftChild->_color = EN_Black;
                                rotateRight(node->sibling()->_leftChild);
                            } else if((node == node->_parent->_rightChild) && (EN_Black == node->sibling()->_leftChild->_color) &&
                            (EN_Red == node->sibling()->_rightChild->_color)) {
                                node->sibling()->_color = EN_Red;
                                node->sibling()->_rightChild->_color = EN_Black;
                                rotateLeft(node->sibling()->_rightChild);
                            }
                        }
                        node->sibling()->_color = node->_parent->_color;
                        node->_parent->_color = EN_Black;
                        if(node == node->_parent->_leftChild) {
                            node->sibling()->_rightChild->_color = EN_Black;
                            rotateLeft(node->sibling());
                        } else {
                            node->sibling()->_leftChild->_color = EN_Black;
                            rotateRight(node->sibling());
                        }
                    }
                }

                bool insert(RedBlackNode<Comparable>*& node, const Comparable& data) {
                    if(node->_data >= data) {
                        if(node->_leftChild != _M_Nil) {
                            insert(node->_leftChild, data);
                        } else {
                            RedBlackNode<Comparable>* temp =
                            new RedBlackNode<Comparable>(data, EN_Red, node, _M_Nil, _M_Nil);
                            node->_leftChild = temp;
                            insertHandle(node);
                        }
                    } else {
                        if(node->_rightChild != _M_Nil) {
                            insert(node->_rightChild, data);
                        } else {
                            RedBlackNode<Comparable>* temp =
                             new RedBlackNode<Comparable>(data, EN_Red, node, _M_Nil, _M_Nil);
                             node->_rightChild = temp;
                             insertHandle(node);
                        }
                    }
                }

                bool insertHandle(RedBlackNode<Comparable>*& node) {
                    if(node->_parent == CC_NULL) {
                        _M_header = node;
                        _M_header->_color = EN_Black;
                        return true;
                    }

                    if(EN_Red == node->_parent->_color) {
                        if(EN_Red == node->uncle()->_color) {
                            node->_parent->_color = node->uncle()->_color = EN_Black;
                            node->grandParent()->_color = EN_Red;
                            insertHandle(node->grandParent());
                        } else {
                            if(node->_parent->_rightChild == node && node->grandParent()->_leftChild == node->_parent) {
                                rotateLeft(node);
                                rotateRight(node);
                                node->_color = EN_Black;
                                node->_leftChild->_color = node->_rightChild->_color = EN_Red;
                            } else if(node->_parent->_leftChild == node && node->grandParent()->_rightChild == node->_parent) {
                                rotateRight(node);
                                rotateLeft(node);
                                node->_color = EN_Black;
                                node->_leftChild->_color = node->_rightChild->_color = EN_Red;
                            } else if(node->_parent->_leftChild == node && node->grandParent()->_leftChild == node->_parent) {
                                node->_parent->_color = EN_Black;
                                node->grandParent()->_color = EN_Red;
                                rotateRight(node->_parent);
                            } else {    //node->_parent->_rightChild == node && node->grandParent()->_rightChild == node->_parent
                                node->_parent->_color = EN_Black;
                                node->grandParent()->_color = EN_Red;
                                rotateLeft(node->_parent);
                            }
                        }
                    }
                }

                void rotateRight(RedBlackNode<Comparable>* node) {
                    RedBlackNode<Comparable>* grandParent = node->grandParent();
                    RedBlackNode<Comparable>* parent = node->_parent;
                    RedBlackNode<Comparable>* rightChild = node->_rightChild;

                    parent->_leftChild = rightChild;

                    if(rightChild != _M_Nil) {
                        rightChild->_parent = parent;
                    }

                    node->_rightChild = parent;
                    parent->_parent = node;

                    if(_M_header == parent) {
                        _M_header = node;
                    }
                    node->_parent = grandParent;

                    if(CC_NULL != grandParent) {
                        if(grandParent->_leftChild == parent) {
                            grandParent->_leftChild = node;
                        } else {
                            grandParent->_rightChild = node;
                        }
                    }
                }

                void rotateLeft(RedBlackNode<Comparable>* node) {
                    if(node->_parent == CC_NULL) {
                        _M_header = node;
                        return;
                    }

                    RedBlackNode<Comparable>* grandParent = node->grandParent();
                    RedBlackNode<Comparable>* parent = node->_parent;
                    RedBlackNode<Comparable>* leftChild = node->_leftChild;
                    parent->_rightChild = leftChild;

                    node->_rightChild = parent;
                    if(leftChild != _M_Nil) {
                        leftChild->_parent = parent;
                    }
                    node->_leftChild = parent;
                    parent->_parent = node;

                    if(_M_header == parent) {
                        _M_header = node;
                    }
                    node->_parent = grandParent;

                    if(CC_NULL != grandParent) {
                        if(grandParent->_leftChild == parent) {
                            grandParent->_leftChild = node;
                        } else {
                            grandParent->_rightChild = node;
                        }
                    }
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
                        root = (root->_leftChild != CC_NULL) ? root->_leftChild : root->_rightChild;
                        delete temp;    //NOTICE: delete?
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