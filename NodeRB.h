#ifndef NODERB_H
#define NODERB_H

#include <iostream>

using namespace std;

//Node for a Red-Black Tree
template <class TYPE>
class NodeRB {

    //Functions
    public:
        NodeRB();
        NodeRB(TYPE val);
        ~NodeRB();

        void setLeft(NodeRB *n) { left = n; };
        void setRight(NodeRB *n) { right = n; };
        void setParent(NodeRB *n) { parent = n; };
        void setKey(TYPE k) { key = k; };
        void setColour(char c) { colour = c; };

        NodeRB* getLeft() { return left; };
        NodeRB* getRight() { return right; };
        NodeRB* getParent() { return parent; };
        TYPE getKey() { return key; };
        char getColour() { return colour; };

    private:

    //Variables
    public:

    private:
        NodeRB *left;
        NodeRB *right;
        NodeRB *parent;
        TYPE key;
        char colour;

};

template <class TYPE>
NodeRB<TYPE>::NodeRB() {
    left = NULL;
    right = NULL;
    parent = NULL;
    colour = 'r';
}

template <class TYPE>
NodeRB<TYPE>::NodeRB(TYPE val) {
    left = NULL;
    right = NULL;
    parent = NULL;
    key = val;
    colour = 'r';
}

template <class TYPE>
NodeRB<TYPE>::~NodeRB() {
    delete left;
    delete right;
}

#endif // NodeRB_H