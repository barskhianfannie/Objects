#ifndef QUEUE_TESTS_H
#define QUEUE_TESTS_H

// Author : Fannie Barskhian
// Class : Data Structures
// Project : Stack and Queue

#include "../Linked_Lists/Includes/Stack_Queue/queue_class.h"

//======================================================================
//                                                   TEST DECLARATIONS
//======================================================================

void test_queue_funcs();
void test_big_three();


//======================================================================
//======================================================================

void test_queue_funcs()
{
    cout << endl;
    cout << "TESTING QUEUE FUNCTIONS " << endl;
    Queue<int> queue;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
       queue.push(i);
        cout << "Push: {"<< i << "} " << queue ;
    }
    cout << "Front of the Queue = " << queue.front() <<endl;
    cout << "Is the Queue Empty? " ;
    if(queue.empty())
    {
            cout << "ERROR" << endl;
    }else{
        cout << "No. Test PASSED. " << endl;
    }
    cout << endl;
    for (int i=0; i<n; i+=5)
    {
        queue.pop();
        cout << "Pop : {"<<  i << "} " << queue;
    }

    cout << "Is the Queue Empty? " ;
    if(!queue.empty())
    {
            cout << "ERROR" << endl;
    }else{
        cout << "Yes. Test PASSED. " << endl;
    }
    cout << endl;
}

void test_queue_big_three()
{
    Queue<int> queue;
    Queue<int> queue2;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
        queue.push(i);
    }
    for (int i=0; i<n; i+=7)
    {
        queue2.push(i);
    }
    cout << "Queue # 1 : " << queue ;
    cout << "Queue # 2 :" << queue2;
    cout << "Testing Assignment Operator Queue 2 = Queue 1: " ;
    queue2 = queue ;
    cout << queue2;
    cout << "Popping Queue 1 then Printing Queue 1 and 2 to see if Assignment Operator is legit " << endl;
    for (int i=0; i<n; i+=8)
    {
        queue.pop();
    }
    cout << "Queue # 1 : " << queue ;
    cout << "Queue # 2 :" << queue2;
    cout << "Testing Copy Constructor ----- Queue<int> queue3 = queue; " << endl;
    cout << queue << endl;
    Queue<int> queue3 = queue;
    cout << "Queue # 1 : " << queue ;
    cout << "Queue # 3 :" << queue3;
    cout << "Popping Queue 1 then Printing Queue1 and 3 to see if Copy Constructor is legit " << endl;
    queue.pop();
    cout << "Queue # 1 : " << queue ;
    cout << "Queue # 3 :" << queue3;

}

void test_queue_Iterators()
{
    Queue<int> queue;
    int n = 44;
    for (int i=0; i<n; i+=5)
    {
        queue.push(i);
    }
    Queue<int>::Iterator it;
    it = queue.Begin();
    cout << "Testing Queue Iterator and Moving it Through the Queue using it++ " << endl;
    cout << queue;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << *it << endl;
    ++it;
    cout << "Testing Queue Iterator Last Node Function " << endl;
    it = queue.LastNode();
      cout << *it << endl;
}



#endif // QUEUE_TESTS_H
