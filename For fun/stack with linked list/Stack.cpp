#include <iostream>
using namespace std;

class Node {
    private:
    int data;
    Node* nextPointer;

    public:

    Node(int data) {
        this->data = data;
        this->nextPointer = nullptr;
    }
    Node* getNext() {
        return nextPointer;
    }

    void setNext(Node* next) {
        this->nextPointer = next;
    }

    void printData() {
        cout << this->data << endl;
    }

};

class Stack {
    private:
    Node* head;
    Node* tail;
    
    public: 

    Stack() {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data) {
        Node* nodeToBePushed = new Node(data);
        Node* tmp = head->getNext();
        head->setNext(nodeToBePushed);
        nodeToBePushed->setNext(tmp);
    }

    void printStack() {
        Node* curr = this->head;
        while(curr!=nullptr) {
            curr->printData();
            curr = curr->getNext();
        }
    }
};

int main() {
    Stack s = Stack();
    s.push(5);
    s.printStack();

}


