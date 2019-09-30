#ifndef STACK_CLASS_H
#define STACK_CLASS_H

// Author : Fannie Barskhian
// Class : Data Structures
// Project : Stack and Queue


#include <iostream>
using namespace std;
#include  "../Linked_List_Functions/lnkd_lst_fnc.h"


template <class T>
class Stack
{
    public:
    class Iterator{
    public:
            friend class Stack;
            Iterator():_ptr(nullptr){}


            Iterator(node<T>* p): _ptr(p) {}


            Iterator next()
            {
                assert(_ptr);
                return _ptr->_next;
            }

            T& operator *()
            {
                return _ptr->_item;
            }

            T* operator ->()
            {
                return &_ptr->_item;
            }

            bool is_null()
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


    Stack():_top(nullptr){}

    ~Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator =(const Stack<T>& rhs)
    {
        if(rhs._top == nullptr)
        {
            delete_all(_top);
        }else if(this != &rhs) {
            delete_all(_top);
             copy_list(rhs._top, _top);
        }
         return *this;
    }

    void push(T item);
    T pop();
    T top();
    bool empty();

    Iterator Begin() const;                                     //Iterator to the head node //DONE
    Iterator End() const;                                       //Iterator to NULL          //DONE
    Iterator LastNode() const;


    friend ostream& operator << (ostream& outs, const Stack& s)
    {
       print_list(s._top);
       return outs;
    }


private:

    node<T>* _top;
};

//======================================================================
//                                          BIG THREE FUNCTIONS DEFINED
//======================================================================


template <class T>
Stack<T>::~Stack()
 {
     delete_all(_top);
 }

 template <class T>
Stack<T>:: Stack(const Stack<T>& other)
 {
    _top = nullptr;
     copy_list(other._top, _top);

 }

 //======================================================================
 //======================================================================


template <class T>
void Stack<T>::push(T item)
{
    _top = insert_head(_top, item);
}

template <class T>
T Stack <T>:: pop()
{

    return delete_head(_top);
}

template <class T>
T Stack <T>:: top()
{
    return _top->_item;
}

template <class T>
bool  Stack <T>:: empty()
{
    return  _empty(_top);
}


//======================================================================
//
//======================================================================

template <class T>
typename Stack<T>:: Iterator Stack<T>:: Begin() const
{
    return _top;
}

template <class T>
typename Stack<T>:: Iterator Stack<T>:: LastNode() const
{
    return last_node(_top);
}

template <class T>
typename Stack<T>:: Iterator Stack<T>:: End() const
{
    return nullptr;
}





#endif // STACK_CLASS_H
