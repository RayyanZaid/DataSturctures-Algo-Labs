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

    // Keep track of parent and children
    Node* parent = nullptr;
    Node* current = this->root;

    // iterate until end of the tree
    while(current != nullptr) {
        // check to see if node == key or not
        if(current->getString() == key) {
            // remove it

            // 1) If node is leaf (including root)

            // check if it is the leaf
            if(current->getRight() == nullptr && current->getLeft() == nullptr) {
                // if it's the root
                if(parent == nullptr) {
                    if(this->root->getNum() == 1) {
                        this->root = nullptr;
                        return;
                    }
                    this->root->decrement();
                    
                }
                else if(parent->getLeft() == current) {
                    if(parent->getLeft()->getNum() == 1) {
                        parent->setLeft(nullptr);
                        return;
                    }
                    parent->getLeft()->decrement();
                    
                }
                else {
                    if(parent->getRight()->getNum() == 1) {
                        parent->setRight(nullptr);
                        return;
                    }
                    parent->getRight()->decrement();
                }

                
            }

            // 2) If node has only one child

            // if the right is the one that's null (so the only child is left)
            else if(current->getRight() == nullptr) {   
                if(parent == nullptr) { // if it is the root node with a left child
                    if(this->root->getNum() == 1) {
                        this->root = current->getLeft();
                        return;
                        }
                    this->root->decrement();  
                }

                // skipping over the current node  (look at ipad drawing for visualization)
                else if(parent->getLeft() == current) {
                    if(parent->getLeft()->getNum() == 1) {
                        parent->setLeft(current->getLeft());
                        return;
                    }
                    parent->getLeft()->decrement();
                }

                else {
                    if(parent->getRight()->getNum() == 1) {
                        parent->setRight(current->getLeft());
                        return;
                    }
                    parent->getRight()->decrement(); 
                
                }

            }
            // if left is null (so only child is right)
            else if(current->getLeft() == nullptr) {
                if(parent == nullptr) { // if it is the root node with a right child
                    if(this->root->getNum() == 1) {
                        this->root = current->getRight();
                        return;
                        }
                    this->root->decrement();  
                }
                else if(parent->getLeft() == current) {
                    if(parent->getLeft()->getNum() == 1) {
                        parent->setLeft(current->getRight());
                        return;
                    }
                    parent->getLeft()->decrement();
                }

                else {
                    if(parent->getRight()->getNum() == 1) {
                        parent->setRight(current->getRight());
                        return;
                    }
                    parent->getRight()->decrement(); 
                
                }
            }


            // 3) If node has 2 children
            else {


                if(current->getNum() <= 1) {
                
                // find leftmost elemnt of the node to remove's right subtree
                // this will be the successor
                Node* successor = current->getRight();
                while(successor->getLeft() != nullptr) {
                    successor = successor->getLeft();
                }
                // copy data of successor before removing 
                string successorString = successor->getString();
                int successorNum = successor->getNum();
                //remove the successor since we want to put its data in place of the node we removed
                remove(successor->getString());
                // replace current's data with the successor's
                current->setData(successorString, successorNum);
                return;
                }

                current->decrement();
            }

            return; // if this runs, the node was found and removed
        }

        // if not found

        // if current string is less than key, search left
        else if(current->getString() < key) {
            parent = current;
            current = current->getRight();
        }

        else {
            parent = current;
            current = current->getLeft();
        }
    }
    return; // this will run if node not found
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

