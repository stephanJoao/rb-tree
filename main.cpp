#include <iostream>

#include "RB.h"

using namespace std;

int main() {
  RB<int> flamengo;
  for (int i = 0; i < 20 ; i++)
    flamengo.insertRB(rand()%98 + 1);
  
  flamengo.print();
}