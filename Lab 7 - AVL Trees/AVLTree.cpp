#include "Node.h"
#include "AVLTree.h"

using namespace std;
#include <iostream>

void AVLTree::insert(const string & str) {
    Node* nodeToInsert = new Node(str);
    Node* insertedNode;
    if(this->root == nullptr) {
        this->root = nodeToInsert;
        this->root->setHeight(0);

    }
    else {
        Node* currentNode = this->root;
        while(currentNode != nullptr) {
            if(nodeToInsert->getString() < currentNode->getString()) {
                if(currentNode->getLeft() == nullptr) {
                    currentNode->setLeft(nodeToInsert);

                    // new code for this lab

                    // setting the parent
                    currentNode->getLeft()->setParent(currentNode);
                    insertedNode = currentNode;
                    currentNode = nullptr; // setting it to nullptr so that the loop doesn't go on
                }
                else {
                    currentNode = currentNode->getLeft();
                }
            }

            else if(nodeToInsert->getString() > currentNode->getString()) {
                if(currentNode->getRight() == nullptr) {    // if current's right is null, we set its right to the node
                    currentNode->setRight(nodeToInsert);
                    currentNode->getRight()->setParent(currentNode);
                    insertedNode = currentNode;
                    currentNode = nullptr;
                }
                else {  // else we keep traversing the tree
                    currentNode = currentNode->getRight();
                }
            }
            else { // they are the same, increment the count of the current element
                currentNode->addOne();
                insertedNode = currentNode;
                currentNode = nullptr;
            }
        }

        // added
        Node* insertedNodeDuplicate = insertedNode;

        // this is to update the heights
        while(insertedNode!=nullptr) {
            UpdateHeight(insertedNode);
            insertedNode= insertedNode->getParent();    
        }

        // this is to find the closest unbalanced node to the inserted one

        
        Node* closest = findUnbalancedNode(insertedNodeDuplicate);
        if(closest != nullptr) {
            cout << closest->getString() << endl;
        }
        
        
        
    }
    
}

int AVLTree::balanceFactor(Node* node) const {

    int leftHeight = -1;
    if(node->getLeft() != nullptr) {
        leftHeight = node->getLeft()->getHeight();
        
    }

    int rightHeight = -1;
    if(node->getRight() != nullptr) {
        rightHeight = node->getRight()->getHeight();
        
    }
    int balanceFactor = leftHeight - rightHeight;
    
    return balanceFactor;
}


// public function that is accessed by main
void AVLTree::printBalanceFactors() {
    printBalanceFactors(this->root);
    cout << endl;
}

Node* AVLTree::findUnbalancedNode(Node* nodeAtInsertedPosition) {
    bool keepTraversing = true;
    while(keepTraversing == true) {

        if(balanceFactor(nodeAtInsertedPosition) == 2 || balanceFactor(nodeAtInsertedPosition) == -2) {
        
            return nodeAtInsertedPosition;
        }

        nodeAtInsertedPosition = nodeAtInsertedPosition->getParent();

        if(nodeAtInsertedPosition == nullptr) {
            keepTraversing = false;
        }
    }
    return nullptr;
}