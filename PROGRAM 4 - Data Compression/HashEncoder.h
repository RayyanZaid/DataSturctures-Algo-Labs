#include <string>
#include <list>
#include <iostream>
#include "WordFrequency.h"
#include <iterator>
#include <vector>
#ifndef HASHENCODER_H
#define HASHENCODER_H
using namespace std;

class HashEncoder {

 private:
	int size;
	string *words = new string[20];

 public:
	HashEncoder(int size) {
        this->size = size;
    }
	
	void print() {
		for(int i = 0; i<20; i++) {
			cout << words[i] << endl;
		}
	}
	void put(WordFrequency &wordObject) {
		int hash = computeHash(wordObject);
		words[hash] = wordObject.getWord();
	}
	
 private:
	int computeHash(WordFrequency wordObject) {
		int hash = wordObject.getCode() - 1;
		return hash;
	}
};

#endif