#include <iostream>
using namespace std;
struct Node {

    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class myQueue {
    private:
        Node* head;
        Node* tail;
    public:
        myQueue(): head(nullptr), tail(nullptr) {}

        void enqueue(int data) {
            Node* n = new Node(data);
            if(this->head == nullptr) {
                head = tail = n;
            }
            else {
                tail->next = n;
                tail = n;
            }
        }
        void dequeue() {
            // removes the node after the head
            if(this->head == nullptr) {
                return;
            }
            this->head = this->head->next;
        }

        void print() {
            Node* curr = this->head;
            while(curr != nullptr) {
                cout << curr->data << endl;
                curr = curr->next;
            }
        }
};

int main() {
    myQueue q = myQueue();
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    cout << endl << endl;
    q.dequeue();
    q.print();

}