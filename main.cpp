#include <iostream>

#include "BST.h"

using namespace std;

//TODO min & max
//TODO other ways to print the tree 

int main() {
  cout << "Binary Search Tree\n" << "Provide the keys you want to insert or -1 to leave insertion:\n";
  BST<int> bst;
  int key;
  cin >> key;
  while(key != -1) {
    bst.insertBST(key);
    cin >> key;
  }
  bst.print();
  cout << "Provide the keys you want to delete or -1 to leave deletion:\n";
  cin >> key;
  while(key != -1) {
    bst.deleteBST(key);
    //bst.print();
    cin >> key;
  }
  /*BST<int> bst;
  bst.insertBST(20);
  bst.insertBST(10);
  bst.insertBST(30);
  bst.insertBST(8);
  bst.insertBST(15);
  bst.insertBST(25);
  bst.insertBST(33);
  bst.insertBST(6);
  bst.insertBST(9);
  bst.insertBST(14);
  //bst.insertBST(18);
  bst.print();
  bst.deleteBST(15);
  //bst.print();*/
}