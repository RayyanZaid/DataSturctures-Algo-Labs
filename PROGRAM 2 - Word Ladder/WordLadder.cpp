#include <string>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iostream>
using namespace std;

#include "WordLadder.h"


/* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
   
    WordLadder::WordLadder(const string &nameOfFile) {
        ifstream inFS;
        inFS.open(nameOfFile);

        if(!inFS.is_open()) {
            cout << "Could not open file " << nameOfFile << endl;
        }

        string eachWord;

        while(inFS >> eachWord) {
            if(eachWord.size() != 5) {
                cout << "At least one word is not size 5" << endl;
                return;
            }
            else {
                dict.push_back(eachWord);
            }
        }
    }

    // to test constructor

    void WordLadder::printList() {
        for(int i = 0; i<10; i++) {
            cout << dict.front() << endl;
            dict.pop_front();
        }
    }





    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
    void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {

        bool startWordInList = false;
        bool endWordInList = false;

        for(list<string>::iterator iter = dict.begin(); iter!=dict.end(); iter++) {
            if(*iter == start) {
                startWordInList = true;
            }

            if(*iter == end) {
                endWordInList = true;
            }
        }

        if(!startWordInList || !endWordInList) {
            cout << "Start or end word does not exist" << endl;
            return;
        }


        /*  Algorithm for finding a word ladder

            1. Create a stack with the first word

            2. Enqueue stack on to a Queue of Stacks

            3. Create a while loop to ensure the Queue is not empty

            4. Get the top word in the front stack (need this to search for words one off)

            5. Compare each word in dictionary to the top word

        */

       // 1

       stack<string> stackOfWords;
       stackOfWords.push(start);

       // 2

       queue<stack<string>> queue;
       queue.push(stackOfWords);

       // 3

       while(!queue.empty()) {

           // 4
           string topWordInFrontStack = queue.front().top();

           // 5

           int nonMatchCounter = 0;
           for(string eachWord : dict) {

               for(int i = 0; i<5; i++) {
                   if(topWordInFrontStack[i] != eachWord[i]) {
                       nonMatchCounter++;
                   }
               }
               
               if(nonMatchCounter == 1) {

                   stack<string> newStack = queue.front();
                   newStack.push(eachWord);

                   if(eachWord== end) {
                       cout << "Hello" << endl;
                       
                   }
                   else {
                   queue.push(newStack);
                   dict.remove(newStack.top());
                   queue.pop();
                   }
               }
            
            
           }
           

           
        
       }

       cout << "Word Ladder does not exist for these two words" << endl;
    }