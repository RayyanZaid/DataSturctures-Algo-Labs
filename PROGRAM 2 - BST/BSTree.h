#include "Node.h"

#include <iostream>
using namespace std;

#ifndef BSTREE_H
#define BSTREE_H

class BSTree {

    private:



    Node* root;



    bool RemoveNode(Node* parent, Node* node) {
        if(node == nullptr) {
            return false;
        }

        // internal node with 2 children

        if(node->getLeft() != nullptr && node->getRight() != nullptr) {
            Node* succNode = node->getRight();
            Node* successorParent = node;

            while(succNode->getLeft() != nullptr) {
                successorParent = succNode;
                succNode = succNode->getLeft();
            }
            node->setData(succNode->getString(), succNode->getNum());
            RemoveNode(successorParent,succNode);
        }

        else if(node == this->root) {
            if(node->getLeft() !=nullptr) {
                this->root = node->getLeft();
            }
            else {
                this->root = node->getRight();
            }
        }

        else if(node->getLeft() != nullptr) {
            if(parent->getLeft() == node) {
                parent->setLeft(node->getLeft());
            }
            else {
                parent->setRight(node->getLeft());
            }
        }

        else {
            if(parent->getLeft() == node) {
                parent->setLeft(node->getRight());
            }
            else {
                parent->setRight(node->getRight());
            }
        }

    return true;



    }

    void preOrder(Node* root) const {
        if(root != nullptr) {
            cout << root->getString() << "(" << root->getNum() << "), ";

            preOrder(root->getLeft());

            preOrder(root->getRight());
        }
    }
    void postOrder(Node* root) const {
        if(root != nullptr) {

            postOrder(root->getLeft());

            postOrder(root->getRight());

            cout << root->getString() << "(" << root->getNum() << "), ";
        }
    }

    void inOrder(Node* root) const {
        if(root != nullptr) {

            inOrder(root->getLeft());
            cout << root->getString() << "(" << root->getNum() << "), ";
            inOrder(root->getRight());
            
        }
    }

    Node* search(Node* node, const string &key) const {
        if(node == nullptr) {
            return nullptr;
        }
        else if(node->getString() == key) {
            return node;
        }
        else if(key > node->getString()) {
            return search((node->getRight()),key);
        }
        else {
            return search((node->getLeft()),key);
        }
    }

    int height(Node* node) const {
        if(node == nullptr) {
            return -1;
        }
        else {
            int leftHeight = height(node->getLeft());
            int rightHeight = height(node->getRight());
            if(leftHeight > rightHeight) {
                return 1 + leftHeight;
            }
            else {
                return 1 + rightHeight;
            }
        }
    }

    

    public: 
    BSTree() {
        this->root = nullptr;
    }

    // added

    Node* GetParent(Node* searchNode) {
        return GetParentRecursive(this->root,searchNode);
    }

    Node* GetParentRecursive(Node* root, Node* node) {
        if(root == nullptr) {
            return nullptr;
        }

        if(root->getLeft() == node || root->getRight() == node) {
            return root;
        }

        if(node->getString() < root->getString()) {
            return GetParentRecursive(root->getLeft(), node);
        }
        return GetParentRecursive(root->getRight(), node);
    }

    Node* searchReturnsNode(string key) {
        Node* nodeToRemove = this->root;

        while(nodeToRemove != nullptr) {
            if(key == nodeToRemove->getString()) {
                return nodeToRemove; 
            }
            else if(key < nodeToRemove->getString()) {
                nodeToRemove = nodeToRemove->getLeft();
            }
            else {
                nodeToRemove = nodeToRemove->getRight();
            }
            
    }
    return nullptr;
    }
    
    
    /* Mutators */
        /* Insert an item into the binary search tree. 
           Be sure to keep BST properties. 
           When an item is first inserted into the tree the count should be set to 1. 
           When adding a duplicate string (case sensitive), rather than adding another node, 
           the count variable should be incremented 
         */
        void insert(const string &newString);
        /* Remove a specified string from the tree. 
           Be sure to maintain all bianry search tree properties. 
           If removing a node with a count greater than 1, just decrement the count, otherwise, 
           if the count is simply 1, remove the node. 
            You MUST follow the remove algorithm shown in the slides and discussed in class or else 
            your program will not pass the test functions. 
            When removing, 
                if removing a leaf node, simply remove the leaf. Otherwise, 
                if the node to remove has a left child, replace the node to remove with the largest 
                string value that is smaller than the current string to remove 
                (i.e. find the largest value in the left subtree of the node to remove). 
                If the node has no left child, replace the node to remove with the smallest value 
                larger than the current string to remove 
                (i.e. find the smallest value in the right subtree of the node to remove. 
         */
        void remove(const string &key);

        /* Accessors */
        /* Search for a string in the binary search tree. 
           It should return true if the string is in the tree, and false otherwise. 
         */
        bool search(const string &key) const;
        /* Find and return the largest value in the tree. Return an empty string if the tree is empty */
        string largest() const;
        /* Find and return the smallest value in the tree. Return an emtpy string if the tree is empty */
        string smallest() const;
        /* Compute and return the height of a particular string in the tree. 
           The height of a leaf node is 0 (count the number of edges on the longest path). 
           Return -1 if the string does not exist. 
         */
        int height(const string&) const;

        /* Printing */
        /* For all printing orders, each node should be displayed as follows:
           <string> (<count>)
           e.g. goodbye(1), Hello World(3)
           */
        void preOrder() const;
        void postOrder() const;
        void inOrder() const;

        

        Node* getRoot() {
            return this->root;
        }
};

#endif