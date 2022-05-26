#include <string>
#include <list>
#include <iostream>
#include "WordFrequency.h"

using namespace std;

class HashEncoder {

 private:
	list<WordFrequency> *hashTable;
	int size;

 public:
	HashEncoder(int size) {
        this->size = size;
        this->hashTable = new list<WordFrequency>[size];
    }
	bool contains(const string &);
	double getAverage(const string &);
	void put(const string &, int);
	
 private:
	int computeHash(const string &);
};