#include "IntList.h"
#include <iostream>
using namespace std;
IntList::IntList() {
    
    this->dummyHead = nullptr;
    this->dummyTail = nullptr;
    this->head = dummyHead;
    this->tail= dummyTail;
    
}

IntList::~IntList() {
    while(head!=nullptr) {
        IntNode* next = head->next;
        delete dummyHead;
        head = next;
    }
}

void IntList::push_front(int data){
   IntNode* newNode = new IntNode(data);

    newNode->next = dummyHead;
   if (dummyHead == nullptr) {
       dummyTail = newNode;
       newNode->prev = nullptr;
   } 
   else {
       newNode->prev = dummyHead->prev;
       dummyHead->prev = newNode;  
   }
   dummyHead = newNode;

}

void IntList::push_back(int data) {
    IntNode* newNode = new IntNode(data);

    newNode->prev = dummyTail;
    if(empty()) {
        dummyHead = newNode;
        dummyTail = newNode;
        newNode->prev = nullptr;
    }
    else {
        dummyTail -> next = newNode;
        dummyTail = newNode;
    }
}

void IntList::pop_front(){
   if(empty()) {
       
       return;
   } 

       IntNode* temp = dummyHead;
       if (dummyHead == dummyTail){
           dummyHead = nullptr;
           dummyTail = nullptr;
       } 
       else {
           dummyHead = dummyHead->next;
           dummyHead->prev = nullptr;
       }
       delete temp;
}

void IntList::pop_back() {
    if(empty()) {
        return;
    }

    IntNode* temp = dummyTail;
    if(dummyHead == dummyTail) {
        dummyHead = dummyTail = nullptr;
    }
    else {
        dummyTail = dummyTail->prev;
        dummyTail->next = nullptr;
    }
    delete temp;
    
}





ostream& operator<<(ostream& os, const IntList& list) {
    for(IntNode* currentNode = list.dummyHead; currentNode!=nullptr; currentNode = currentNode->next) {
        if(currentNode->next == nullptr) {  // if we are at the last element
            os << currentNode->data;
        }
        else {
            os << currentNode->data << " ";
        }
    }
    return os;
}

bool IntList::empty() const {
    if(dummyHead == nullptr && dummyTail == nullptr) {
        return true;
    }
    return false;
}

void IntList::printReverse() const {
    IntNode* currentNode = this->dummyTail;
    while(currentNode!=nullptr) {
        if(currentNode->prev == nullptr) {
            cout << currentNode->data;
        }
        else {
            cout << currentNode ->data << " ";
        }
        currentNode = currentNode->prev;
    }
}