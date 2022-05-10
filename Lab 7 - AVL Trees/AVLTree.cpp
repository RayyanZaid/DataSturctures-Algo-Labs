#include "Node.h"
#include "AVLTree.h"

using namespace std;
#include <iostream>

void AVLTree::insert(const string & str) {
    Node* nodeToInsert = new Node(str);

    if(this->root == nullptr) {
        this->root = nodeToInsert;
    }
    else {
        Node* currentNode = this->root;
        while(currentNode != nullptr) {
            if(nodeToInsert->getString() < currentNode->getString()) {
                if(currentNode->getLeft() == nullptr) {
                    currentNode->setLeft(nodeToInsert);
                    currentNode = nullptr; // setting it to nullptr so that the loop doesn't go on
                }
                else {
                    currentNode = currentNode->getLeft();
                }
            }

            else if(nodeToInsert->getString() > currentNode->getString()) {
                if(currentNode->getRight() == nullptr) {    // if current's right is null, we set its right to the node
                    currentNode->setRight(nodeToInsert);
                    currentNode = nullptr;
                }
                else {  // else we keep traversing the tree
                    currentNode = currentNode->getRight();
                }
            }
            else { // they are the same, increment the count of the current element
                currentNode->addOne();
                currentNode = nullptr;
            }
        }
    }

}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(this->root);
}