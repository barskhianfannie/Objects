#ifndef BST_CLASS_H
#define BST_CLASS_H

// AUTHOR : FANNIE BARSKHIAN
// CLASS : DATA STRUCTURES
// PROJECT : BINARY SEARCH TREES

#include <iostream>
using namespace std;
#include "../BSTrees/bst_functions.h"

template <typename T>
class BSTree
{
    public:

         BSTree();
         BSTree(const T* sorted_list, int size=-1);

         //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

         BSTree(const BSTree<T>& copy_me);
         BSTree<T>& operator =(const BSTree<T>& rhs)
         {
             if(rhs.root == nullptr)
             {
                 *this = NULL;
             }else
             {
                 root = tree_copy(rhs.root);
             }

             return *this;
         }
         ~BSTree();

         //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

         void insert(const T& insert_me);
         void erase(const T& target);
         bool search(const T& target, tree_node<T>* & found_ptr );
         void clear();

         friend ostream& operator <<(ostream& outs, const BSTree<T>& tree)
         {
             tree_print(tree.root);
             return outs;
         }


         BSTree<T>& operator +=(const BSTree<T>& rhs); // dont worry according to professor

    private:

        tree_node<T>* root;
};

template <typename T>
BSTree<T>::BSTree()
{
   root = new tree_node<T>();
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T>& copy_me)
{
    cout << "COPY CTOR FIRED" << endl;
    root = tree_copy(copy_me.root);
}

template <typename T>
BSTree<T>::~BSTree()
{
    cout << "DESTRUCTOR FIRED, DESTROYING YOUR TREE " << endl;
    tree_clear(root);
    root = NULL;
}

template <typename T>
BSTree<T>::BSTree(const T* sorted_list, int size)
{
    root = tree_from_sorted_list(sorted_list, size);
}


template <typename T>
void BSTree<T>::insert(const T& insert_me)
{
    tree_insert(root, insert_me);
}

template <typename T>
void BSTree<T>:: erase(const T& target)
{
    tree_erase(root, target);
}


template <typename T>
bool BSTree<T>:: search(const T& target, tree_node<T>* & found_ptr)
{
   return tree_search(root, target, found_ptr);
}

template <typename T>
void BSTree<T> :: clear()
{
    tree_clear(root);
}



#endif // BST_CLASS_H
