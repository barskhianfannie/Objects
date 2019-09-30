#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

// Author : Fannie Barskhian
// Class : Data Structures
// Project : Stack and Queue

#include <iostream>
#include "../Linked_List_Functions/lnkd_lst_fnc.h"
using namespace std;


template <class T>
class Queue{

public:
        class Iterator{
        friend class Queue;
        public:
        Iterator():_ptr(nullptr){}


        Iterator(node<T>* p): _ptr(p) {}                     //Point Iterator to where p is pointing to


        Iterator next()
        {
            assert(_ptr);
            return _ptr->_next;
        }

        T& operator *()                      //dereference operator // item  RETURN _PTR->_ITEM;
        {
            return _ptr->_item;
        }

        T* operator ->()                        //member access operator // address
        {
            return &_ptr->_item;
        }

        bool is_null()                                //true if _ptr is NULL
        {
            if(_ptr == nullptr)
                return true;
            else
                return false;
        }


        friend bool operator !=(const Iterator& left, const Iterator& right) //true if left != right
        {
            if(left._ptr != right._ptr)
                return true;
            else
                return false;
        }

        friend bool operator ==(const Iterator& left, const Iterator& right) //true if left == right
        {
            if(left._ptr->_next == right._ptr)
                return true;
            else
                return false;
        }

        Iterator& operator++()                       //member operator: ++it; or ++it = new_value
        {
            _ptr = _ptr ->_next;
            return *this;
        }

        friend Iterator operator++(Iterator& it, int unused)    //friend operator: it++
        {
            assert(it._ptr);
            Iterator temp = it;
            it = it.next();
            return temp;
        }

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Queue():_head(NULL), _tail(NULL),size(0){}

    ~Queue();
    Queue(const Queue<T>& other);


    Queue<T> &operator =(const Queue& rhs)
    {
        if(rhs._head == nullptr)
        {
            delete_all(_head);
        }else if(this != &rhs){
             delete_all(_head);
              copy_list(rhs._head, _head);
               _tail = last_node(_head);
         }

     return *this;
     }

    void push(T item);
    T pop();
    bool empty();
    T front();
    int get_size();
    Iterator Begin() const;                                     //Iterator to the head node //DONE
    Iterator End() const;                                       //Iterator to NULL          //DONE
    Iterator LastNode() const;


    friend ostream& operator <<(ostream& outs, const Queue& q)
    {
        print_list(q._head, outs);
        return outs;
    }


private:

    node<T>* _head;
    node<T>* _tail;
    int size;


};


//======================================================================
//                                          BIG THREE FUNCTIONS DEFINED
//======================================================================


template <class T>
 Queue<T>::~Queue()
 {
     delete_all(_head);
 }

 template <class T>
 Queue<T>:: Queue(const Queue<T>& other)
 {
     _tail = copy_list(other._head, _head);
 }

 //======================================================================
 //======================================================================



template <class T>
void Queue<T>:: push(T item)
{
    _tail = insert_after(_head,_tail,item);
    size++;
}

template <class T>
T Queue<T>:: pop()
{
    assert(_head != nullptr);
    size--;
    return delete_head(_head);
}

template <class T>
bool Queue <T>::empty()
{
    return (_head == nullptr);
}

template <class T>
T Queue <T>:: front()
{
    return _head->_item;
}

template <class T>
int Queue<T>:: get_size()
{
    return size;
}

template <class T>
typename Queue<T>:: Iterator Queue<T>:: Begin() const
{
    return _head;
}

template <class T>
typename Queue<T>:: Iterator Queue<T>:: LastNode() const
{
    return  _tail;
}

template <class T>
typename Queue<T>:: Iterator Queue<T>:: End() const
{
    return nullptr;
}




#endif // QUEUE_CLASS_H
