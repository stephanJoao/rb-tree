#ifndef NODEBST_H
#define NODEBST_H

#include <iostream>

using namespace std;

//Node for a Binary Search Tree
template <class TYPE>
class NodeBST {

    //Functions
    public:
        NodeBST();
        NodeBST(TYPE val);
        ~NodeBST();

        void setLeft(NodeBST *n) { left = n; };
        void setRight(NodeBST *n) { right = n; };
        void setKey(TYPE k) { key = k; };

        NodeBST* getLeft() { return left; };
        NodeBST* getRight() { return right; };
        TYPE getKey() { return key; };

    private:

    //Variables
    public:

    private:
        NodeBST *left;
        NodeBST *right;
        TYPE key;

};

template <class TYPE>
NodeBST<TYPE>::NodeBST() {
    left = NULL;
    right = NULL;
}

template <class TYPE>
NodeBST<TYPE>::NodeBST(TYPE val) {
    key = val;
    left = NULL;
    right = NULL;
}

template <class TYPE>
NodeBST<TYPE>::~NodeBST() {
    delete left;
    delete right;
}

#endif // NodeBST_H