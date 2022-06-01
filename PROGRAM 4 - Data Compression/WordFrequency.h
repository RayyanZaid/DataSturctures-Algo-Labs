#include <iostream>
using namespace std;

#ifndef WORDFREQUENCY_H
#define WORDFREQUENCY_H

class WordFrequency {
    private:
        string word;
        int count;
        int code;

    public:

    WordFrequency(string word) {
        this->word = word;
        count = 1;
    }

    string getWord() {
        return this->word;
    }
    
    int getCount() {
        return this->count;
    }
    
    void incrementCount() {
        this->count++;
    }

    bool operator<(const WordFrequency &c) const {
        return count < c.count;
    }

    bool operator>(const WordFrequency &c) const {
        return count > c.count;
    }

    void setCode(int code) {
        this->code = code;
    }

    int getCode() {
        return this->code;
    }

    
};

#endif