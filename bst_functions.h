#ifndef BST_FUNCTIONS_H
#define BST_FUNCTIONS_H

// AUTHOR : FANNIE BARSKHIAN
// CLASS : DATA STRUCTURES
// PROJECT : BINARY SEARCH TREES


#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

template <typename T>
struct tree_node
{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor()
    {
        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        int left_h = _left ? _left->_height : -1;
        int right_h = _right ? _right->_height : -1;
        int bal  = (right_h - left_h);

        return bal;
    }

    int height()
    {
        // if _left is null, left_h = -1, else it equals _left->_height
        int left_h = _left ? _left->_height : -1;
        //same with right
        int right_h = _right ? _right->_height : -1;

        _height = 1 + max(left_h, right_h);
        return _height;
    }


    int update_height()
    {
        _height = height();
        return _height;
        //set the _height member variable (call height();)
    }

    tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)
    {
        _height = -1;
        //don't forget to set the _height.
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
};





template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me);

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);

template<typename T>
void tree_print(tree_node<T>* root, int level=0,
                                    ostream& outs=cout);

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout);

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root);

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target);

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value);

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root);

//template <typename T>       //Add tree src to dest
//void tree_add(tree_node<T>* & dest, const tree_node<T>* src);


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size);

template <typename T>       // sorted array -> tree   get middles and break it up.......
tree_node<T>* tree_from_sorted_list_helper(const T* a, int start, int end);




template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me)
{
   if(!root)
   {
       root = new tree_node<T>(insert_me);
   }else if(insert_me  < root->_item)
   {
       tree_insert(root->_left, insert_me);
   }else{
       tree_insert(root->_right, insert_me);
   }

   root->update_height();
}

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target)
{
    bool dbg = false;
    if(dbg) cout << "Entering tree search with root address " << root << " target: " <<target <<  endl;
    if(root == nullptr)
    {
        return root;
    }

    if(root->_item == target)
    {
        return root;
    }

    if(root->_item > target)
    {
        return tree_search(root->_left, target);
    }

    if(root->_item < target)
    {
        return tree_search(root->_right, target);
    }

}

template<typename T>
void tree_print(tree_node<T>* root, int level, ostream& outs)
{
    if(root)
    {
        tree_print(root->_right, level + 1);
        outs << setw(4*level) << ""<< "[" << root->_item << "]" << endl;
        tree_print(root->_left, level + 1);
    }
}

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root)
{
    if(root)
    {
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root = nullptr;
    }
}


template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value)
{
    if(root->_right)
    {
        tree_remove_max(root->_right, max_value);
    }else{
        if(root->_left)
        {
            max_value = root->_item;
            tree_node<T>* temp = root;
            root = root->_left;
            delete temp;
            temp = nullptr;
        }else{
            max_value = root->_item;
            delete root;
            root = nullptr;
        }
    }
    if(root) root->update_height();
}

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target)
{

    bool dbg = false;
    if(dbg) cout << "Entering Tree Erase with target:   " << target << endl;

    bool erased;
    if(root == NULL)
    {
        cout << "hitting" << endl;
        erased = false;
    }else if( target < root->_item)
    {
        tree_erase(root->_left, target);
    }else if(target > root->_item)
    {
        tree_erase(root->_right, target);
    }else{

        if(root->_left != nullptr) //left child(may have both childs)
        {
            tree_remove_max(root->_left, root->_item);
            erased = true;
        }else if(root->_right != nullptr)
        { //Right Child Only
            tree_node<T>* temp = root;
            root = root->_right;
            delete temp;
            temp = NULL;
            erased= true;
        }else{ //Dealing with Leafs
            delete root;
            root = NULL;
            erased =true;
        }
    }
    if(root) root->update_height();
    return erased;
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target, tree_node<T>* &found_ptr)
{
    bool dbg = false;
    if(dbg)cout << "Entering tree search with root address " << root << " target: "
                <<target << " and found_ptr address: " << found_ptr << endl;
    found_ptr = tree_search(root,target);

    if(found_ptr == nullptr)
    {
        return false;
    }else{
        return true;
    }
}

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root)
{
    if(root)
    {
       tree_node<T>* rootcopy = new tree_node<T>(root->_item, tree_copy(root->_left), tree_copy(root->_right));
       return rootcopy;
    }

}

template <typename T>       // sorted array -> tree   get middles and break it up.......
tree_node<T>* tree_from_sorted_list(const T* a, int size)
{
    bool dbg = false;
    if(dbg) cout << "In original tree_from_sorted_list " << endl;

   tree_node<T>* root =  tree_from_sorted_list_helper(a, 0 , size - 1);
   return root;

}

template <typename T>       // sorted array -> tree   get middles and break it up.......
tree_node<T>* tree_from_sorted_list_helper(const T* a, int start, int end)
{
    bool dbg = false;
    if(dbg) cout << "In tree_from_sorted_list helper" << endl;

    if(start > end) return NULL;
    int midpoint = (start + end) / 2;
    tree_node<T>* root = new tree_node<T>(a[midpoint]);
    root->_left = tree_from_sorted_list_helper(a, start, midpoint - 1);
    root->_right = tree_from_sorted_list_helper(a, midpoint + 1, end);
    if(root) root->update_height();
    return root;
}

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level, ostream& outs)
{
    if(root)
    {
        tree_print_debug(root->_right, level + 1);
        outs << setw(4*level) << ""<< "[" << root->_item << "]" <<"-------------------------------------H: " <<  root->_height
             <<"  BF: " <<   root->balance_factor() <<  endl;
        tree_print_debug(root->_left, level + 1);
    }
}




#endif // BST_FUNCTIONS_H
