#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
#include "WordLadder.h"
using namespace std;

WordLadder::WordLadder(){}


WordLadder::WordLadder(const string& dictionaryFile){

    ifstream inFS;
    inFS.open(dictionaryFile);
    if(!inFS.is_open()){
        cout << "Could not open file." << endl;
        exit(1);
    }

    string word;

    while(inFS >> word){
        dict.push_back(word);
    }
    inFS.close();
}

WordLadder::~WordLadder(){}

void WordLadder::outputLadder(const string& start, const string& end){
    stack<string> wordStack;
    wordStack.push(start);

    // make a queue of string stacks
    queue<stack <string> > theQueue;

    // push the stack into our queue
    theQueue.push(wordStack);
    
    //if you erase you dont check the one after the one that is erased
    while(!theQueue.empty()){
        list<string>::iterator dictionaryIterator;
        for(dictionaryIterator = dict.begin(); dictionaryIterator != dict.end(); ++dictionaryIterator){
            string topOfFrontQueue = theQueue.front().top();

            // if the word is off by one from the last word
            if(offByOne(*dictionaryIterator, topOfFrontQueue)){
                if(*dictionaryIterator == end){
                    theQueue.front().push(end);
                    outputLadder(theQueue.front(), start);
                    return;
                }
                else{
                    stack<string> newStack = theQueue.front();
                    newStack.push(*dictionaryIterator);
                    theQueue.push(newStack);
                    dictionaryIterator = dict.erase(dictionaryIterator); //what node does it point to
                    --dictionaryIterator;
                }
            }
        }
        theQueue.pop();
    }
    cout << "No Ladder found!" << endl;
}

void WordLadder::outputLadder(stack<string>& s, const string& end){
    ofstream outFS;
    outFS.open("out1.txt");

    string stackWord = s.top();
    while(stackWord != end) {
        outFS << stackWord << endl;
        s.pop();
        stackWord = s.top();
    }
    outFS << stackWord;
    
}



bool WordLadder::offByOne(const string& s1, const string& s2){

    int offByOne = 0;
    for(int i  = 0; i<5; i++) {
        if(s1[i] != s2[i]) {
            offByOne++;
        }
    }

    if(offByOne == 1) {
        return true;
    }
    
    return false;
}
