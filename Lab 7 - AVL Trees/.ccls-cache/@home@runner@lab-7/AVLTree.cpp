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
                currentNode = nullptr;
            }
        }

        // added
        Node* insertedNodeDuplicate = insertedNode;

        // this is to update the heights
        while(insertedNode!=nullptr) {
            Rebalance(insertedNode);
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
      /*cout << endl << endl << node->getString() << "'s left child is " << node->getLeft()->getString() << endl;*/
        
    }
    else {
    //  cout << endl << endl << node->getString() << "'s left child is null" << endl;
    }
    int rightHeight = -1;
    if(node->getRight() != nullptr) {
      rightHeight = node->getRight()->getHeight();
    //  cout << endl << endl << node->getString() << "'s right child is " << node->getRight()->getString() << endl;
    }
    else {
     // cout << endl << endl << node->getString() << "'s right child is null" << endl;
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

/*void AVLTree::rotate(){
  Node* root = this->root;
  if ((balanceFactor(root) == 2) && (balanceFactor(root->getLeft()) == 1)){
    rotateRight(root);
  }
  else if ((balanceFactor(root) == -2) && (balanceFactor(root->getLeft()) == -1)){
    rotateLeft(root);
  }
  else if ((balanceFactor(root) == 2) && (balanceFactor(root->getLeft()) == -1)){
    rotateLeft(root->getLeft());
    rotateRight(root);

  }
  else if ((balanceFactor(root) == -2) && (balanceFactor(root->getLeft()) == -1)){
    rotateRight(root->getRight());
    rotateLeft(root);
  }
}*/

Node* AVLTree::rotateLeft(Node* node){
  Node* rightLeftchild = node->getRight()->getLeft();
  if (node->getParent() != nullptr)
      ReplaceChild(node->getParent(), node, node->getRight());
   else { // node is root
      this->root = node->getRight();
      this->root->setParent(nullptr);
   }
   setChild(node->getRight(), "left", node);
   setChild(node, "right", rightLeftchild);  
  return node->getRight();
}

Node* AVLTree::rotateRight(Node* node){
  
  Node* leftRightChild = node->getLeft()->getRight();
  if (node->getParent() != nullptr)
      ReplaceChild(node->getParent(), node, node->getLeft());
   else { // node is root
      this->root = node->getLeft();
      this->root->setParent(nullptr);
   }
   setChild(node->getLeft(), "right", node);
   setChild(node, "left", leftRightChild);
    return node->getLeft();

  }
 
bool AVLTree::setChild(Node* parent, string whichChild, Node* child){
  if (whichChild != "left" && whichChild != "right")
      return false;

   if (whichChild == "left")
      parent->setLeft(child);
   else
      parent->setRight(child);
   if (child != nullptr)
      child->setParent(parent);

   UpdateHeight(parent);
   return true;
}

bool AVLTree::ReplaceChild(Node* parent, Node* currentChild, Node* newChild){
  if (parent->getLeft() == currentChild)
      return setChild(parent, "left", newChild);
   else if (parent->getRight() == currentChild)
      return setChild(parent, "right", newChild);
   return false;
}

Node* AVLTree::Rebalance(Node * node){
  UpdateHeight(node);       
   if (balanceFactor(node) == -2) {
      if (balanceFactor(node->getRight()) == 1) {
         // Double rotation case.
        rotateRight(node->getRight());
      }
      return rotateLeft(node);
   }
   else if (balanceFactor(node) == 2) {
      if (balanceFactor(node->getLeft()) == -1) {
         // Double rotation case.
         rotateLeft(node->getLeft());
      }
      return rotateRight(node);
   }        
   return node;
}

