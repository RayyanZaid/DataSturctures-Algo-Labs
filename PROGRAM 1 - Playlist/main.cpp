#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string payload;
    Node* next;
};

Node* newNode(string payload) {
   Node* currentNode = new Node;
    currentNode->payload = payload;
    currentNode->next = nullptr;
    return currentNode;
}

Node* loadGame(int n, vector<string> names) {
    Node* head = nullptr;
    Node* prev = nullptr;
    string name;

    for (int i = 0; i < n; ++i) {
        name = names.at(i);
        if (head == nullptr) {
            head = newNode(name); // initialize head specially
            prev = head;    // set previous node to head
        } else {
            prev->next = newNode(name); // connecting the previous node to the next node
            prev = prev->next; // moving the previous pointer to the next node for the next iteration
            
        }
    }

    if (prev != nullptr) {
        prev->next = head;  // once done with the linked list, make it a circle by pointing last element back to the head

    }
    return head;
}

void print(Node* start) { // prints list
    Node* curr = start;
    while (curr != nullptr) {
        cout << curr->payload << endl;
        curr = curr->next;
        if (curr == start) {
            break; // exit circular list
        }
    }
}

Node* runGame(Node* start, int k) { // josephus w circular list, k = num skips
    Node* curr = start;
    Node* prev = curr;
    while (curr->next != curr) { // exit condition, last person standing 
        for (int i = 0; i < k; ++i) { // find kth node
          Node* currTemp = curr;    // move the previous and current pointers down the list. need prev pointer
          // to skip over the current node (the line that says "delete kth node")
          curr = curr->next; // incrementing curr
          prev = currTemp; // setting previous equal to what curr used to be
        }

        prev->next = curr->next; // delete kth node (skipping the person who died)
        delete curr;    // deleting them so there's no dangling pointers
       curr = prev->next; // setting current to what current's next would have been (2 lines earlier)
    }

    return curr; // last person standing
}

/* Driver program to test above functions */
int main() {
    int n=1, k=1, max; // n = num names; k = num skips (minus 1)
    string name;
    vector<string> names;

    // get inputs
    cin >> n >> k;
    while (cin >> name && name != ".") { names.push_back(name); } // EOF or . ends input

    // initialize and run game
    Node* startPerson = loadGame(n, names);
    Node* lastPerson = runGame(startPerson, k);

    if (lastPerson != nullptr) {
        cout << lastPerson->payload << " wins!" << endl;
    } else {
        cout << "error: null game" << endl;
    }

    return 0;
}

