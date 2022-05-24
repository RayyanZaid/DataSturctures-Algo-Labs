#include <iostream>
#include <time.h> 

using namespace std;

const int NUMBERS_SIZE = 50000;


int Partition(int numbers[], int lowIndex, int highIndex);


int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);


    int midpoint = Partition(arr1, 0,NUMBERS_SIZE);
    cout << midpoint;
    // const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    // clock_t Start = clock();

    

    

    // clock_t End = clock();


    // int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    // cout << elapsedTime;
}


void QuickSort_midpoint(int numbers[], int lowIndex, int highIndex) {
    if(lowIndex >= highIndex) {
        return;
    }

    int splitIndex = Partition(numbers, lowIndex, highIndex);
    QuickSort_midpoint(numbers, lowIndex, splitIndex);
    QuickSort_midpoint(numbers, splitIndex+1, highIndex);
    
}

int Partition(int numbers[], int lowIndex, int highIndex) {
    int midpoint = (lowIndex + highIndex) / 2;
    int pivot = numbers[midpoint];
    cout << midpoint << endl;
    return midpoint;
}