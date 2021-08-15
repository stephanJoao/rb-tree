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
        
        bool searchBST(TYPE val);

        void print();

    private:
        bool auxSearch(NodeRB<TYPE> *n, TYPE val);

        void auxPrint(string prefix, NodeRB<TYPE>* n, bool left);

    //Variables
    public:

    private:
        NodeRB<TYPE> *root;

};

#endif // RB_H