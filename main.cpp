#include <iostream>

#include "RB.h"

using namespace std;

int main() {
  RB<int> flamengo;
  int vec[28] = {45,  1, 22, 37, 30, 
                  3,  4,  2,  6, 16,
                 36, 20, 44, 34,  5,
                 35, 33, 25, 10, 14, 
                  7, 20, 27, 11, 19, 
                  9, 21, 43};

  for(int i = 0; i < 28 ; i++)
    flamengo.insertRB(vec[i]);
  flamengo.print();
}