#ifndef TESTS_H
#define TESTS_H

// Author : Fannie Barskhian
// Class : Data Structures
// Project : Stack and Queue

#include "../Linked_List_Functions/lnkd_lst_fnc.h"
#include "../Linked_Lists/Includes/Stack_Queue/queue_class.h"
#include "../Linked_Lists/Includes/Stack_Queue/stack_class.h"
using namespace std;
#include <iostream>




//======================================================================
//                                                   TEST DECLARATIONS
//======================================================================

void test_insert_head();
void test_init_head();
void test_delete_all();
void test_empty();
void test_copy_list();
void test_delete_head();


//======================================================================
//======================================================================

void test_insert_head()
{
    node<int>* head = nullptr;
    int n = 100;
    cout << endl;
    cout << "Creating a Linked List Using The Insert Head Function from 0 to 100 in increments of 10 " << endl;
        for (int i=0; i<n; i+=10)
        {
            insert_head(head, i);
        }
        print_list(head);
        cout << endl;
        cout << "//====================================================================== " << endl;

}

void test_init_head()
{
    node<int>* head = nullptr;
    int n = 30;
    cout << endl;
    cout << "Creating a short Linked List for INIT_HEAD Testing Purposes " << endl;
        for (int i=0; i<n; i+=10)
        {
            insert_head(head, i);
        }
   print_list(head);
    cout << "Initializing Head of List to Null and Attempting to Print " << endl;
    init_head(head);
    print_list(head);
    cout << "//====================================================================== " << endl;
}

void test_delete_all()
{
    node<int>* head = nullptr;
    int n = 5;
    cout << " Creating a short Linked List  for DELETE ALL Testing Purposes" << endl;
        for (int i=0; i<n; i+=1)
        {
            insert_head(head, i);
        }
        print_list(head);
     cout << "Running Delete All Function   " << endl;
     delete_all(head);
      cout << "Attempting to Print Now  "<< endl;
     print_list(head);
     cout << endl;
     cout << "//====================================================================== " << endl;

}


void test_empty()
{
    node<int>* head = nullptr;
    int n = 2;
    cout << " Creating a shorter Linked List for EMPTY Testing Purposes" << endl;
    for (int i=0; i<n; i+=1)
    {
        insert_head(head, i);
    }
    cout << "Testing if this is empty -> " ;
    print_list(head);
    if(_empty(head))
    {
        cout << "ERROR" << endl;
    }else{
        cout << "PASSED" << endl;
    }
    cout << endl;
    cout << "//====================================================================== " << endl;

}

void test_copy_list()
{
    node<int>* head = nullptr;
    node<int>* head2 = nullptr;
   int  n = 50;
    for (int i=0; i<n; i+=10)
    {
        insert_head(head, i);
    }
    cout << "Testing Copy Function: " << endl;
    cout << "List # 1 " ;
    print_list(head);
    cout << endl;
    for (int i=0; i<n; i+=4)
    {
        insert_head(head2, i);
    }
    cout << "List # 2 " ;
    print_list(head2);
    cout << "Making List 2 = List 1 using the copy function" << endl;
    copy_list(head,head2);
    cout << "List # 2 " ;
    print_list(head2);

    cout << endl;
    cout << "//====================================================================== " << endl;
}


#endif // TESTS_H
