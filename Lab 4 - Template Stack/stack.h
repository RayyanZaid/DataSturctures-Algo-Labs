#ifndef stack_h

#define stack_h

#include<stdexcept>

using namespace std;

const int MAX_SIZE=20;

template<class T>

class stack{

              //private fields

              T data[MAX_SIZE];

              int size;

public:

stack() {
    size = 0;
}


void push(T val) {
    if(size == MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
    }
    data[size] = val;
    size++;
}

void pop() {
    if(size == 0) {
        throw out_of_range("Called pop on empty stack.");
    }
    size--; // if list is not empty, reduce the size (aka pop the top)
}

void pop_two(){
  if (size < 2){
      if(size == 0) {
          throw out_of_range("Called pop_two on empty stack.");
      }
      throw out_of_range("Called pop_two on a stack of size 1.");
  }
  pop();    // if size is at least 2, pop 2
  pop();
}

T top() {
    if(size == 0) {
        throw underflow_error("Called top on empty stack.");
    }
    return data[size-1]; // size - 1 because when you push, you increment the size at the end
}            

             
bool empty() {
    return size==0;
}

};

#endif


             

 