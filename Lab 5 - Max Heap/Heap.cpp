#include "Heap.h"
#include "PrintJob.h"

#include <iostream>

using namespace std;

Heap::Heap() {
    this->numItems = 0;
}

void Heap::enqueue(PrintJob* jobToInsert) {

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
    // Algorithm: 
    // 1) Swap root data with the last data

    PrintJob* temp = this->arr[0];
    this->arr[0] = this->arr[this->numItems];
    this->arr[this->numItems] = temp;

    // 2) Decrement num
    numItems--;
    // 3) Move the new root down to where its supposed to be

}






void Heap::print() {

    for(int i = 0; i<4; i++) {
    cout << "Priority: " << arr[i]->getPriority()
        << ", Job Number: " << arr[i]->getJobNumber()
        << ", Number of Pages: " << arr[i]->getPages()
        << endl;
    }
}