#include <iostream>
#include <vector>
#include <time.h>
#include <stdexcept>

using namespace std;

vector<char> createVector();
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

template<typename T>
void selection_sort(vector<T> &vals);


int main() {

    // TEST BENCH

    // vector<char> vec = createVector();
    

    // cout << "Should be 4: " << min_index(vec,4) << endl;


    // cout << "Should be sorted: ";
    // selection_sort(vec);
    // for(int i = 0; i<vec.size(); i++) {
    //     cout << vec.at(i) << " ";
    // }


    // cout << endl << endl;


    // vector<int> integerVector = {1,4,2,46,32,1};
    // cout << "Unsorted: ";
    // for(int i = 0; i<integerVector.size(); i++) {
    //     cout << integerVector.at(i) << " ";
    // }

    // cout << endl << "Sorted:   ";

    // selection_sort(integerVector);
    // for(int i = 0; i<integerVector.size(); i++) {
    //     cout << integerVector.at(i) << " ";
    // }


    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;

}


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}


template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {

    T minValue = vals.at(index);
    unsigned minValueIndex = index;
    for(int i = index+1; i<vals.size(); i++) {
        if(vals.at(i) < minValue) {
            minValue = vals.at(i);
            minValueIndex = i;
        }
    }

    return minValueIndex;
} 

// Algorithm for Selection Sort
// 1. Get the index of the minimum value from the first element in the array to the end.
// 2. Swap the data at the minIndex with the data from the start 
// 3. Repeat this process with an incremented starting index

template<typename T>
void selection_sort(vector<T> &vals) {
    for(int i = 0; i<vals.size(); i++) {
        unsigned minIndex = min_index(vals,i);
        T tempStart = vals.at(i);   // temp variable to store start element
        vals.at(i) = vals.at(minIndex); // switch
        vals.at(minIndex) = tempStart;
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {

}