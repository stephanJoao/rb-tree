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

//BST iterative search that returns the node
template <class TYPE>
NodeRB<TYPE>* RB<TYPE>::searchBST(TYPE val) {
    NodeRB<TYPE>* n = root;
    while(n != NULL) {
        if(val > n->getKey())
            n = n->getRight();
        else if(val < n->getKey())
            n = n->getLeft();
        else
            return n;
    }
    return NULL;
}

//AVL left rotation with parent changing
template <class TYPE>
void RB<TYPE>::leftRotation(NodeRB<TYPE>* n) {
    NodeRB<TYPE>* aux = n->getRight();
    aux->setParent(n->getParent());
    n->setRight(aux->getLeft());
    if(aux->getLeft() != NULL)
        aux->getLeft()->setParent(n);  
    aux->setLeft(n);
    n->setParent(aux);
    if(root == n)
        root = aux;
    else {
        if(aux->getParent()->getLeft() == n)
            aux->getParent()->setLeft(aux);
        else
            aux->getParent()->setRight(aux);
    }
}

//AVL right rotation with parent changing
template <class TYPE>
void RB<TYPE>::rightRotation(NodeRB<TYPE>* n) {
    NodeRB<TYPE>* aux = n->getLeft();
    if(n->getParent() != NULL) {
        aux->setParent(n->getParent());
    }  
    n->setLeft(aux->getRight());
    if(aux->getRight() != NULL) {
        aux->getRight()->setParent(n);
    }  
    aux->setRight(n);
    n->setParent(aux);
}

//AVL double left rotation with parent changing
template <class TYPE>
void RB<TYPE>::doubleLeftRotation(NodeRB<TYPE>* n) {
    NodeRB<TYPE>* aux = n->getRight();
    NodeRB<TYPE>* aux2 = aux->getLeft();
    if(n->getParent() != NULL) {
        aux2->setParent(n->getParent());
    }
    n->setRight(aux2->getLeft());
    if(n->getRight() != NULL) {
        n->getRight()->setParent(n);
    }
    aux->setLeft(aux2->getRight());
    if(aux->getLeft() != NULL) {
        aux->getLeft()->setParent(aux);
    }
    aux2->setLeft(n);
    n->setParent(aux2);
    aux2->setRight(aux);
    aux->setParent(aux2);
}

//AVL double right rotation with parent changing
template <class TYPE>
void RB<TYPE>::doubleRightRotation(NodeRB<TYPE>* n) {
    NodeRB<TYPE>* aux = n->getLeft();
    NodeRB<TYPE>* aux2 = aux->getRight();
    if(n->getParent() != NULL) {
        aux2->setParent(n->getParent());
    }
    n->setLeft(aux2->getRight());
    if(n->getLeft() != NULL) {
        n->getLeft()->setParent(n);
    }
    aux->setRight(aux2->getLeft());
    if(aux->getRight() != NULL) {
        aux->getRight()->setParent(aux);
    }
    aux2->setRight(n);
    n->setParent(aux2);
    aux2->setLeft(aux);
    aux->setParent(aux2);
}

//BST iterative insertion with parent setting that returns the parent pointer 
//and has a pointer to a boolean that indicates if a value has been added
template <class TYPE>
NodeRB<TYPE>* RB<TYPE>::insertBST(TYPE val, bool* added) {
    NodeRB<TYPE>* n = root;
    NodeRB<TYPE>* past = NULL;
    NodeRB<TYPE>* newNode = new NodeRB<TYPE>(val);
    
    if(n == NULL) {
        root = newNode;
        *added = true;
        return NULL;
    }

    while(n != NULL) {
        past = n;
        if(val > n->getKey())
            n = n->getRight();
        else if(val < n->getKey())
            n = n->getLeft();
        else {
            *added = false;
            return NULL;
        }
    }

    if(val > past->getKey())
        past->setRight(newNode);
    else
        past->setLeft(newNode);
    newNode->setParent(past);
    *added = true;
    return past;
}

//RB insertion using iterative BST insertion //with colour and balance fixing
template <class TYPE>
void RB<TYPE>::insertRB(TYPE val) {
    bool added;
    NodeRB<TYPE>* parent = insertBST(val, &added); 
    if(parent != NULL)
        cout << "Pai do " << val << " é " << parent->getKey() << endl;
    
    if(val == 88) {
        NodeRB<TYPE>* child = parent->getRight();
        NodeRB<TYPE>* grandParent = parent->getParent();
        cout << grandParent->getKey() << endl;
        leftRotation(grandParent);
    }
}

//Auxiliary to printing
template <class TYPE>
void RB<TYPE>::auxPrint(string prefix, NodeRB<TYPE>* n, bool left) {
    const string red("\033[0;31;47m");
    const string black("\033[0;30;47m");
    const string reset("\033[0m");
    
    if(n != NULL) {
        cout << prefix;
        cout << (left ? "├──" : "└──");
        if(n->getColour() == 'r')
            cout << red << n->getKey() << reset << endl;
        else
            cout << black << n->getKey() << reset << endl;
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