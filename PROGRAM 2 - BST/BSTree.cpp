#include "Node.h"
#include "BSTree.h"


void BSTree::insert(const string & str) {
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

void BSTree::remove(const string &key) {
    // Algorithm 

    Node* node = searchReturnsNode(key);
    Node* parent = GetParent(node);
    RemoveNode(parent,node);
    
    
}

bool BSTree::search(const string &key) const {
   Node* result = search(this->root,key);

    if(result) {
        return true;
    }
    return false;
    
}


string BSTree::largest() const {
    if(this->root == nullptr) {
        return "";
    }
    Node* current = this->root;
    while(current->getRight() != nullptr) {
        current = current->getRight();
    }
    return current->getString();
}

string BSTree::smallest() const {
    if(this->root == nullptr) {
        return "";
    }
    Node* current = this->root;
    while(current->getLeft() != nullptr) {
        current = current->getLeft();
    }
    return current->getString();
}

int BSTree::height(const string& key) const {
    Node* node = search(this->root,key);
    if(node != nullptr) {
        return height(node);
    }
    else {
        return -1;
    }
}


void BSTree::preOrder( ) const { 
    preOrder(this->root);
    cout << endl;
}
void BSTree::postOrder( ) const { 
    postOrder(this->root);
    cout << endl;
}
void BSTree::inOrder( ) const { 
    inOrder(this->root);
    cout << endl;
}

