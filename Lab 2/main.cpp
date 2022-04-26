#include <iostream>
using namespace std;
#include "IntList.h"

int main() {
    // UNIT TESTING

    // Constructor
    IntList* list = new IntList();
    IntList* list2 = new IntList();
    // PUSH and POP Front
    list->push_front(2);
    list->push_front(1);
    cout << "Should be 1 2: " << *list << endl;
    list->pop_front();
    cout << "Should be 2: " << *list << endl;

    // PUSH AND POP BACK
    list2->push_back(1);
    cout << "Should be 1: " << *list2 << endl;
    list2->pop_back();
    cout << "Should be nothing: " << *list2 << endl;


    //EMPTY
    cout << "Should be 1 (True): " << list2->empty() << endl;

    // PRINT REVERSE
    list->push_front(1);
    list->push_back(3);

    cout << "Should be 3 2 1: ";
    list->printReverse();


    //Destructor
    delete list;
    
}