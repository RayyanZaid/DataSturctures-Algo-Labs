#include "Heap.h"
#include "PrintJob.h"

#include <iostream>

using namespace std;

Heap::Heap() {
    this->numItems = 0;
}

void Heap::enqueue(PrintJob* jobToInsert) {

    if(this->numItems >= MAX_HEAP_SIZE) {
        return;
    }
    // insert in the last available spot
    this->arr[numItems] = jobToInsert;


    // implement the percolate up algorithm
    int nodeIndex = numItems;

    while(nodeIndex > 0) {
        int parentIndex = (nodeIndex - 1) / 2;
        if(arr[nodeIndex]->getPriority() > arr[parentIndex]->getPriority()) {
            //swap data
            PrintJob* temp = arr[nodeIndex];    
            arr[nodeIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            // swap indices
            nodeIndex = parentIndex; 
        }
        else {
        return;
        }
    }

    numItems++;
}


void Heap::dequeue() {

    if(this->numItems == 0) {
        return;
    }
    // Algorithm: 
    // 1) Swap root data with the last data
    this->numItems--;
    PrintJob* temp = this->arr[0];
    this->arr[0] = this->arr[this->numItems];
    this->arr[this->numItems] = temp;

    // 2) Move the new root down to where its supposed to be
    trickleDown(0);

    
    
}


PrintJob* Heap::highest() {
    if(this->numItems == 0) {
        return nullptr;
    }
    return this->arr[0];
}



void Heap::print() {

    if(this->numItems == 0) {
        return;
    }
    cout << "Priority: " << arr[0]->getPriority()
        << ", Job Number: " << arr[0]->getJobNumber()
        << ", Number of Pages: " << arr[0]->getPages() 
        << endl;
    
}