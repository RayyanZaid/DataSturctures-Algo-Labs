#include <iostream>
#include "PrintJob.h"
#include "Heap.h"
using namespace std;

int main() {
    PrintJob* job2 = new PrintJob(2,2,2);
    PrintJob* job1 = new PrintJob(1,1,1);
    PrintJob* job4 = new PrintJob(4,4,4);
    PrintJob* job3 = new PrintJob(3,3,3);
    Heap heap = Heap();
    heap.enqueue(job1);
    heap.enqueue(job2);
    heap.enqueue(job3);
    heap.enqueue(job4);
    heap.print();
    heap.dequeue();
    cout << "AFTER: " << endl << endl;
    heap.print();

    heap.dequeue();
    cout << "AFTER: " << endl << endl;
    heap.print();
    heap.dequeue();
    cout << "AFTER: " << endl << endl;
    heap.print();
    heap.dequeue();
}