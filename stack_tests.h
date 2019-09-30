#ifndef STACK_TESTS_H
#define STACK_TESTS_H

// Author : Fannie Barskhian
// Class : Data Structures
// Project : Stack and Queue

#include "../Linked_Lists/Includes/Stack_Queue/stack_class.h"


//======================================================================
//                                                   TEST DECLARATIONS
//======================================================================

void test_stack_funcs();
void test_big_three();
void test_stack_Iterators();

//======================================================================
//======================================================================

void test_stack_funcs()
{
    cout << endl;
    cout << "TESTING STACK FUNCTIONS " << endl;
    Stack<int> stack;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
        stack.push(i);
        cout << "Push: {"<< i << "} " << stack ;
    }
    cout << "Top of the Stack = " << stack.top() <<endl;
    cout << "Is the List Empty? " ;
    if(stack.empty())
    {
            cout << "ERROR" << endl;
    }else{
        cout << "No. Test PASSED. " << endl;
    }
    cout << endl;
    for (int i=0; i<n; i+=5)
    {
        stack.pop();
        cout << "Pop : {"<< 40- i << "} " << stack ;
    }

    cout << "Is the List Empty? " ;
    if(!stack.empty())
    {
            cout << "ERROR" << endl;
    }else{
        cout << "Yes. Test PASSED. " << endl;
    }
    cout << endl;
}

void test_stack_big_three()
{
    Stack<int> stack;
    Stack<int> stack2;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
        stack.push(i);
    }
    for (int i=0; i<n; i+=7)
    {
        stack2.push(i);
    }
    cout << "Stack # 1 : " << stack ;
    cout << "Stack # 2 :" << stack2;
    cout << "Testing Assignment Operator Stack 2 = Stack 1: " ;
    stack2 = stack ;
    cout << stack2;
    cout << "Popping Stack 1 then Printing Stack 1 and 2 to see if Assignment Operator is legit " << endl;
    for (int i=0; i<n; i+=8)
    {
        stack.pop();
    }
    cout << "Stack # 1 : " << stack ;
    cout << "Stack # 2 :" << stack2;
    cout << "Testing Copy Constructor ----- Stack<int> stack3 = stack; " ;
    Stack<int> stack3 = stack;
    cout << "Stack # 1 : " << stack ;
    cout << "Stack # 3 :" << stack3;
    cout << "Popping Stack 1 then Printing Stack 1 and 3 to see if Copy Constructor is legit " << endl;
    stack.pop();
    cout << "Stack # 1 : " << stack ;
    cout << "Stack # 3 :" << stack3;

}

void test_stack_Iterators()
{
    Stack<int> stack;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
        stack.push(i);
    }
    Stack<int>::Iterator it;
    it = stack.Begin();
    cout << "Testing Stack Iterator and Moving it Through the Stack using it++ " << endl;
    cout << stack;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << "Testing Stack Iterator Last Node Function " << endl;
    it = stack.LastNode();
      cout << *it << endl;
}

#endif // STACK_TESTS_H
