#include <iostream>

#include "RB.h"

using namespace std;

int main() {
  /*const string red("\033[0;31;47m");
  const string black("\033[0;30;47m");
  const string reset("\033[0m");
  cout << black << "text" << reset << endl;
  cout << "normal?" << endl;*/
  RB<int> flamengo;
  //flamengo.insertRB(10);
  flamengo.insertRB(1);
  flamengo.insertRB(2);
  flamengo.insertRB(3);
  flamengo.insertRB(4);
  flamengo.insertRB(5);
  flamengo.insertRB(6);
  flamengo.insertRB(7);
  //flamengo.insertRB(8);
  //flamengo.insertRB(9);
  
  flamengo.print();
}