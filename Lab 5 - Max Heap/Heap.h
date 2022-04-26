#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  //current number of items in heap

public:
  /*Initializes an empty heap.*/
  Heap();

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue ( PrintJob* );

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void dequeue ( );

  /*Returns the node with highest priority.*/
  PrintJob* highest ( );

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void print ( );

private:
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void trickleDown(int nodeIndex) {
    int childIndex = nodeIndex*2 + 1;
    int valueOfPriority = this->arr[nodeIndex]->getPriority();

    while(childIndex < this->numItems) {  // as long as the parent has a child
      // find max value among the parent node and its children
      int maxValue = valueOfPriority;
      int maxIndex = -1;

      for(int i = 0; i<2 && i+childIndex < this->numItems; i++) { // going to check the children
          int valueOfCurrentChild = this->arr[i+childIndex]->getPriority();
          if(valueOfCurrentChild > maxValue) {
            maxValue = valueOfCurrentChild;
            maxIndex = i+childIndex;
          }
      }
      // if the parent is the biggest value
      if(maxValue == valueOfPriority) {
        return;
      }
      else {
          PrintJob* temp = this->arr[nodeIndex];      // swap the parent and child
          this->arr[nodeIndex] = this->arr[maxIndex];
          this->arr[maxIndex] = temp;

          nodeIndex = maxIndex;         // make the nodeIndex the new parent for the next iteration
          childIndex = 2*nodeIndex + 1;   // get the new child index
      }
    }
  }

  //You can include additional private helper functions here
};
#endif
