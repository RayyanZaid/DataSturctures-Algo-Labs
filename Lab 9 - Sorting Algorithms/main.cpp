#include <iostream>
#include <time.h> 

using namespace std;

const int NUMBERS_SIZE = 50000;


int Partition(int numbers[], int lowIndex, int highIndex);
void QuickSort_midpoint(int numbers[], int lowIndex, int highIndex);
void InsertionSort(int numbers[], int numbersSize);

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; i++){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {

    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1,arr2,arr3);
    
    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();

    
    InsertionSort(arr1,NUMBERS_SIZE);
    QuickSort_midpoint(arr2,0,NUMBERS_SIZE-1);
    

    clock_t End = clock();
    
    for(int i = 0; i<5; i++) {
        cout << arr1[i] << endl;
    }
    int elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << endl << endl;
    cout << elapsedTime << endl;
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


    bool done = false;
    while(!done) {
        
        while(numbers[lowIndex] < pivot) {
            lowIndex++;
        }

        while(numbers[highIndex] > pivot) {
            highIndex--;
        }

        if(lowIndex >= highIndex) {
            done = true;
        }
        else {
            int temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;

            lowIndex++;
            highIndex--;    
        }
    }

    return highIndex;
}

void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;

    int temp = 0;

    for(int i = 1; i<numbersSize; ++i) {
        j = i;

        while(j>0 && numbers[j] < numbers[j-1]) {
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            --j;
        }
    }
}