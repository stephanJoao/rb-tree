#include "BST.h"

//BST constructor
template <class TYPE>
BST<TYPE>::BST() {
    root = NULL;
}

//BST destructor
template <class TYPE>
BST<TYPE>::~BST() {
    //dtor
}

template <class TYPE>
TYPE BST<TYPE>::getRoot() {
    if(root != NULL)
        return root->getKey();
    else {
        cout << "Empty tree!" << endl;
        exit(1);
    }
}

//Auxiliary to BST search
template <class TYPE>
bool BST<TYPE>::auxSearch(NodeBST<TYPE>* n, TYPE val) {
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
bool BST<TYPE>::searchBST(TYPE val) {
    return auxSearch(root, val);
}

//Auxiliary to BST insertion
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::auxInsert(NodeBST<TYPE>* n, TYPE val) {
    if(n == NULL) {
        n = new NodeBST<TYPE>(val);
    }
    else if(val < n->getKey())
        n->setLeft(auxInsert(n->getLeft(), val));
    else if(val > n->getKey())
        n->setRight(auxInsert(n->getRight(), val));
    else {
        cout << "The value is already in the tree!" << endl;
    }
    return n;
}

//BST insertion
template <class TYPE>
void BST<TYPE>::insertBST(TYPE val) {
    root = auxInsert(root, val);
}

//Leaf deletion
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::deleteLeaf(NodeBST<TYPE>* n) {
    delete n;
    return NULL;
}

//Node with one child deletion
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::deleteNode1Child(NodeBST<TYPE>* n) {
    NodeBST<TYPE>* aux;
    if(n->getLeft() == NULL) {
        aux = n->getRight();
        //delete n->getRight();
    }
    else {
        aux = n->getLeft();
        //delete n->getLeft();
    }
    delete n;
    //cout << n->getKey();
    return aux;
}

//Minor value
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::min(NodeBST<TYPE>* n) {
    while (n->getLeft() != NULL)
        n = n->getLeft();
    return n;
}

//Auxiliary to delete
template <class TYPE>
NodeBST<TYPE>* BST<TYPE>::auxDelete(NodeBST<TYPE>* n, TYPE val) {
    if(n == NULL) {
        cout << "Value does not exist!" << endl;
        return NULL;
    }
    else if(val < n->getKey()) //delete in the left subtree
        n->setLeft(auxDelete(n->getLeft(), val));
    else if(val > n->getKey()) //delete in the right subtree
        n->setRight(auxDelete(n->getRight(), val));
    else //found the node
    {
        if((n->getLeft() == NULL) && (n->getRight() == NULL))
            n = deleteLeaf(n);
        else if((n->getLeft() == NULL) || (n->getRight() == NULL)) {
            NodeBST<TYPE>* aux;
            if(n->getLeft() == NULL) {
                cout << "É pra deletar da direita!" << endl;
                aux = n->getRight();
                //delete n->getRight();
            }
            else {
                cout << "É pra deletar da esquerda!" << endl;
                aux = n->getLeft();
                //delete n->getLeft();
            }
            cout << "Deleta o nó" << endl;
            delete n;
            cout << "N recebe auxiliar" << endl;
            n = aux;
            //TODO The deletion is incorrect! 
            //TODO The second time doesn't even enter the condition!!!
            //n = deleteNode1Child(n);
        }
        else {
            NodeBST<TYPE>* aux = min(n->getRight());

            TYPE auxKey = aux->getKey();
            n->setKey(auxKey);
            aux->setKey(val);

            n->setRight(auxDelete(n->getRight(),val));
        }
    }
    return n;
}

//BST node removal
template <class TYPE>
void BST<TYPE>::deleteBST(TYPE val) {
    root = auxDelete(root, val);
}

//Auxiliary to printing
template <class TYPE>
void BST<TYPE>::auxPrint(string prefix, NodeBST<TYPE>* n, bool left) {
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
void BST<TYPE>::print(){
    auxPrint("", root, false);
}

//Here is the explicit instantiation of the
//template types I'll want and need
template class BST<int>;