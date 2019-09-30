#ifndef LNKD_LST_FNC_H
#define LNKD_LST_FNC_H

using namespace std;
#include <stdio.h>
#include <iostream>
#include <cassert>


template <typename T>
struct node{

    node(): _next(nullptr), _prev(nullptr)
    {
        //nullptr constructor

    }



        node(T item=T(), node<T>* next = nullptr, node<T>* prev= nullptr):_item(item), _next(next), _prev(prev)
        {
            //node constructor with passed in values

        }


    friend ostream& operator <<(ostream& outs, const node<T>& print_me)
    {

            if(print_me._next == nullptr)
            {
                outs << "[ " << print_me._item <<" ] -> " << "|||" << endl;
            }else{
                outs<<"[ "<<print_me._item<<" ]-> ";
            }

            return outs;
    }

    T _item;
    node<T>* _next;
    node<T>* _prev;

};

//          FUNCTION DECLARATIONS
//======================================================================

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head);

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head);

//true if head is NULL, false otherwise.
template <class T>
bool _empty(const node<T>* head);

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy);


template<typename T>
node<T>* insert_head(node<T>* &head_ptr, const T& item);


//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item);


template <typename T>
T delete_head(node<T>* &head);//insert or add if a dup


template <typename T>
void print_list(node<T>* head_ptr, ostream& outs=cout);

template <typename T>
node<T>* last_node(node<T>* head);

//======================================================================


//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head)
{
    head = NULL;
    return head;
}

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head)
{
        node<T>* walker;
        while(head  != nullptr)
        {
            if(head->_next == nullptr)
            {
                walker = head;
                head = nullptr;
                delete walker;
            }else{
                walker = head;
                head = walker->_next;
                if(head->_next == nullptr)
                {
                    head = nullptr;
                }else{
                    delete walker;
                }
            }
        }
}

//true if head is NULL, false otherwise.
template <class T>
bool _empty(const node<T>* head)
{
    if(head ==  NULL)
    {
        return true;
    }else{
        return false;
    }
}


//makes a copy of the list, returns a pointer to the last node:

template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    cpy = nullptr;
    const node<T>* walker = head;
    node<T>* temp = cpy;
    while(walker != nullptr){
           temp = insert_after (cpy, temp, walker->_item);
           walker = walker->_next;
       }


       return last_node(cpy) ;
}

//Inserting new Head by creating a new Node
template <typename T>
node<T>* insert_head(node<T>* &head_ptr, const T& item)
{

    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;
    head_ptr->_prev = temp;
    temp->_prev = nullptr;



    return temp;

}

//insert_after: if after is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item)
{
    node<T>* temp = new node<T>(item);

          if(head == nullptr)
              head = temp;
          else if(after == nullptr)
          {
              temp->_next = head->_next;
              temp->_prev = head->_prev;
              head->_next = temp;
          }
          else
          {
              temp->_next = after->_next;
              temp->_prev = after->_prev;
             after->_next = temp;
          }

          return temp;

}

template <typename T>
T delete_head(node<T>* &head)
{
    assert(head != nullptr);
    if(head->_next == nullptr)
    {
        T item = head->_item;
        head = nullptr;
        return item;
    }else{
        node<T>* temp = NULL;
        temp = head;
        head = head->_next;
        head->_prev = temp->_prev;
        T itm = temp->_item;
        delete temp;

        return itm;
    }


}


template <typename T>
void print_list(node<T>* head_ptr, ostream& outs)
{

    node<T>* walker = head_ptr;
    if(walker == NULL)
    {
        cout << "You Are Attempting to Print an Empty List " << endl;
    }
    while (walker!=NULL)
    {

        outs<<*walker;
        walker = walker->_next;
    }
    outs<<endl;
}


template <typename T>
node<T>* last_node(node<T>* head)
{
    node<T>* marker = head;

    while(marker->_next != nullptr)
    {
        marker = marker -> _next;

    }

    if(marker->_next == nullptr)
    {
        return marker;
    }
}













#endif // LNKD_LST_FNC_H
