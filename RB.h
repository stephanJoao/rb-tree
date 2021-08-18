#ifndef RB_H
#define RB_H

#include <iostream>

#include "NodeRB.h"

using namespace std;

//Red-Black Tree
template <class TYPE>
class RB {

    //Functions
    public:
        RB();
        ~RB();

        TYPE getRoot();
        bool empty() { return (root == NULL); };
        
        NodeRB<TYPE>* searchBST(TYPE val);
        void insertRB(TYPE val);

        void print();

    private:
        void deleteTree(NodeRB<TYPE>* current);
        
        void leftRotation(NodeRB<TYPE> *n);
        void rightRotation(NodeRB<TYPE> *n);
        void doubleLeftRotation(NodeRB<TYPE> *n);
        void doubleRightRotation(NodeRB<TYPE> *n);

        NodeRB<TYPE>* fixInsertRB(NodeRB<TYPE>* parent, TYPE val);
        NodeRB<TYPE>* insertBST(TYPE val, bool* added);

        void auxPrint(string prefix, NodeRB<TYPE>* n, bool left);

    //Variables
    public:

    private:
        NodeRB<TYPE> *root;

};

#endif // RB_H