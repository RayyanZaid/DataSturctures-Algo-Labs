#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"

using namespace std;
#include <iostream>
class AVLTree {
    private:
        Node* root;

    // helpers

        Node* findUnbalancedNode(Node* nodeAtInsertedPosition);
    // Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
    
        void rotate(); 
    // Implement four possible imbalance cases and update the parent of the given node.

        Node* rotateLeft();
    // Rotate the subtree to left at the given node and returns the new subroot.

        Node* rotateRight();
    // Rotate the subtree to right at the given node and returns the new subroot.

        void printBalanceFactors(Node* root) const {
        if(root != nullptr) {

            printBalanceFactors(root->getLeft());
            cout << root->getString() << "(" << balanceFactor(root) << "), ";
            printBalanceFactors(root->getRight());
            
        }
    }

        void UpdateHeight(Node* node) {
            int leftHeight = -1;

    // get heights of left and right subtrees

            if(node->getLeft() != nullptr) {
                leftHeight = node->getLeft()->getHeight();
            }

            int rightHeight = -1;

            if(node->getRight() != nullptr) {
                rightHeight = node->getRight()->getHeight();
            }
    // whichever is more + 1 will be the height of the node passed into the function

            if(leftHeight >= rightHeight) {
                node->setHeight(leftHeight+1);
            }
            else {
                node->setHeight(rightHeight+1);
            }
            

        }




        void visualizeTree(ofstream &, Node *);
    


    public: 

    AVLTree() {
        this->root = nullptr;
    }
    void insert(const string &);   // insert and then rotate if necessary

    int balanceFactor(Node* n) const; // return balance factor of a given node
    
    void printBalanceFactors(); // print all balance factors in inorder

    void visualizeTree(const string &); 
};

#endif