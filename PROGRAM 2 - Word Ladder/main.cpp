#include "WordLadder.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
   
   WordLadder test = WordLadder("dictionary.txt");
   test.outputLadder("abaca", "adept","g");


   return 0;
}
