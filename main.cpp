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
  flamengo.insertRB(30);
  flamengo.insertRB(70);
  flamengo.insertRB(88);
  flamengo.print();
}