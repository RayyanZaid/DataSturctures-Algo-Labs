#include <iostream>
#include <fstream>
#include <vector>
#include "WordFrequency.h"
#include "HashEncoder.h"
using namespace std;




int main() {
    ifstream inFS;
    inFS.open("data.txt");


    string temp;

    vector<WordFrequency> existingWords;

    while(inFS >> temp) {
        
        bool isInList = false;
        
        for(int i = 0; i < existingWords.size(); i++) {
            if(existingWords.at(i).getWord() == temp) {
                existingWords.at(i).incrementCount();
                isInList = true;
            }
        }

        if(!isInList) {
            WordFrequency newWord = WordFrequency(temp);
            existingWords.push_back(newWord);
        }
    }

    sort(existingWords.begin(), existingWords.end());
    reverse(existingWords.begin(), existingWords.end());
    
    for(int i = 0; i < 20; i++) {
        existingWords[i].setCode(i+1);
    }

    for(int i = 0; i < 20; i++) {
        cout << existingWords[i].getCode() << endl;
    }

    // Create a hashtable that stores each word to a corresponding index

    HashEncoder(20);
    

    
    

 
}