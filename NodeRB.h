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

        void setLeft(NodeRB<TYPE>* n) { left = n; };
        void setRight(NodeRB<TYPE>* n) { right = n; };
        void setParent(NodeRB<TYPE>* n) { parent = n; };
        void setKey(TYPE k) { key = k; };
        void reColour(char c) { colour = c; };

        NodeRB<TYPE>* getLeft() { return left; };
        NodeRB<TYPE>* getRight() { return right; };
        NodeRB<TYPE>* getParent() { return parent; };
        TYPE getKey() { return key; };
        char getColour() { return colour; };

    private:

    //Variables
    public:

    private:
        NodeRB<TYPE>* left;
        NodeRB<TYPE>* right;
        NodeRB<TYPE>* parent;
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
    delete parent;
}

#endif // NodeRB_H