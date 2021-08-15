#include "RB.h"

//RB constructor
template <class TYPE>
RB<TYPE>::RB() {
    root = NULL;
}

//RB destructor
template <class TYPE>
RB<TYPE>::~RB() {
    //dtor
}

template <class TYPE>
TYPE RB<TYPE>::getRoot() {
    if(root != NULL)
        return root->getKey();
    else {
        cout << "Empty tree!" << endl;
        exit(1);
    }
}

//Auxiliary to BST search
template <class TYPE>
bool RB<TYPE>::auxSearch(NodeRB<TYPE>* n, TYPE val) {
    if(n == NULL)
        return false;
    else if(val == n->getKey())
        return true;
    else if(val < n->getKey())
        return auxSearch(n->getLeft(), val);
    else
        return auxSearch(n->getLeft(), val);
}

//BST search
template <class TYPE>
bool RB<TYPE>::searchBST(TYPE val) {
    return auxSearch(root, val);
}

//Auxiliary to printing
template <class TYPE>
void RB<TYPE>::auxPrint(string prefix, NodeRB<TYPE>* n, bool left) {
    if(n != NULL) {
        cout << prefix;
        cout << (left ? "├──" : "└──");
        cout << n->getKey() << endl;
        auxPrint(prefix + (left ? "│   " : "    "), n->getLeft(), true);
        auxPrint(prefix + (left ? "│   " : "    "), n->getRight(), false);
    }
}

//Printing
template <class TYPE>
void RB<TYPE>::print(){
    auxPrint("", root, false);
}

//Here is the explicit instantiation of the
//template types I'll want and need
template class RB<int>;