#ifndef BST_TESTS_H
#define BST_TESTS_H

// AUTHOR : FANNIE BARSKHIAN
// CLASS : DATA STRUCTURES
// PROJECT : BINARY SEARCH TREES


#include "../BSTrees/bst_functions.h"
#include "../BSTrees/bst_class.h"
#include <iostream>

void test_insert();
tree_node<int>* make_tree();
void test_sorted_list();
void BST_Menu();
void test_tree_copy();
void test_tree_search();
void test_tree_erase();
void run_lower_tests();
void big_three_tests();



char menu;
int num;
bool run = true;

void big_three_tests()
{
    cout << "===============================================================" << endl;
    cout << "           TESTING BST CLASS BIG THREE FUNCTIONS               " << endl;
    cout << "===============================================================" << endl;
    BSTree<int> tree;
    int numbers[] = {5,4,7,12, 9,10,15,17,50,25,75,35,65,85};
    for(int i = 0; i < 14; i++)
    {
        tree.insert(numbers[i]);
    }

    cout << "Made Tree # 1 : " << endl <<  tree << endl;
    cout << "Testing Copy CTOR [ BSTree<int> tree_2 = tree_1 ] " << endl;
    BSTree<int> tree_copy = tree;
    cout << tree_copy << endl;

    tree_copy.clear();
    int numbers_1[] = {5,4,7,12};
    for(int i = 0; i < 4; i++)
    {
        tree_copy.insert(numbers_1[i]);
    }
    cout << "Setting Tree # 2 to : " << endl << endl;
    cout << tree_copy;
    cout << "Testing Assignment Operator [ tree_2 = tree_1 ] " << endl << endl;
    tree_copy = tree;
    cout << tree_copy;
    cout << "Clearing Tree # 1 then running Assignment Operator [ tree_2 = tree_1 ] again " << endl;
    cout << "Nothing should be printing here " << endl;
}

void BST_Menu()
{
    BSTree<int> tree;
    tree.clear();

    while(run)
    {
        cout << "[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: " ;
        cin >> menu;
        menu = toupper(menu);
        switch(menu)
        {
            case 'R':
            {
                num = rand() % 100;
                cout << "-- INSERTING: " << num << endl;// num in the range 0 to 99
                cout << endl << endl;
                tree.insert(num);
                cout << tree << endl << endl;
                cout << "==============================================" << endl << endl;
                break;
            }
            case 'I' :
            {
                cout << "Please input number you would like to add to the tree : " ;
                cin >> num;
                cout << "-- INSERTING: " << num << endl;
                tree.insert(num);
                cout << endl << endl;
                cout << tree << endl << endl;
                cout << "==============================================" << endl << endl;
                break;

            }
            case 'C' :
            {
                cout << "Clearing Tree" << endl;
                tree.clear();
                cout << endl << endl;
                cout << tree << endl << endl;
                cout << "==============================================" << endl << endl;
                break;
            }
            case 'S':
            {
                cout << "Please input a number to see if it exists in the tree: " ;
                cin >> num;
                cout << "Searching for:  " << num << endl;
                tree_node<int>* root = new tree_node<int>();
                if(tree.search(num,root))
                {
                    cout << "Found : " << num << endl;
                    cout << endl << endl;
                    cout << tree << endl << endl;
                    cout << "==============================================" << endl << endl;
                }else{
                    cout << num << " does not exist in this tree." << endl;
                    cout << endl << endl;
                    cout << tree << endl << endl;
                    cout << "==============================================" << endl << endl;
                }
                break;
            }
            case 'X' :
            {
                run = false;
                break;
            }
            default :
            {
                cout << "Invalid Input" << endl;
            }
        }
    }
}


tree_node<int>* make_tree()
{
    int numbers[] = {5,4,7,12, 9,10,15,17,50,25,75,35,65,85};
    tree_node<int>* root = new tree_node<int>();
    tree_clear(root); // erase 0 as the root

    for(int i = 0; i < 11; i++)
    {
        tree_insert(root, numbers[i]);
    }
    return root;

}
void test_insert()
{
    cout << "==============================================" << endl;
    cout << "TESTING INSERT FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
    tree_node<int>* root = make_tree();
    tree_print(root);
}

void test_sorted_list()
{
    cout << "==============================================" << endl;
    cout << "TESTING SORTED LIST FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
    int sorted[] ={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(sorted)/ sizeof (sorted[0]);
    tree_node<int>* sort = new tree_node<int>();
    sort = tree_from_sorted_list(sorted, size); // works
    tree_print(sort);
    cout << endl;
    cout << "==============================================" << endl;
    cout << "TESTING DEBUG PRINT H/BF FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
    tree_print_debug(sort);
}

void test_tree_copy()
{
    cout << "==============================================" << endl;
    cout << "TESTING COPY FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
    tree_node<int>* root = make_tree();
    cout << "Making Tree # 1 " << endl;
    cout << "==================================" << endl;
    tree_print(root);
    cout << "Making Copy of Tree # 1 into Tree # 2 then printing Tree # 2 " << endl;
    cout << "==================================" << endl;
    tree_node<int>* root_copy;
    root_copy = tree_copy(root);
    tree_print(root_copy);
}



void test_tree_search()
{
    cout << "==============================================" << endl;
    cout << "TESTING SEARCH FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
    tree_node<int>* root = make_tree();
    cout << "This is Your Tree " << endl;
    cout << "==================================" << endl;
    tree_print(root);
    cout << "Please input a number to see if it exists in the tree: " ;
    cin >> num;
    cout << "Searching for:  " << num << endl;
    tree_node<int>* found_ptr = new tree_node<int>();
    if(tree_search(root, num, found_ptr))
    {
        cout << "Found : " << num << endl;
        cout << endl << endl;
        cout << "==============================================" << endl << endl;
    }else{
        cout << num << " does not exist in this tree." << endl;
        cout << endl << endl;
        cout << "==============================================" << endl << endl;
    }

}

void test_tree_erase()
{
    cout << "==============================================" << endl ;
    cout << "TESTING ERASE FUNCTION" << endl;
    cout << "==============================================" << endl << endl;
        tree_node<int>* root = make_tree();
        cout << "This is Your Tree " << endl;
        tree_print(root);
        cout << endl << endl;
        cout << "==================================" << endl;
        cout << "Please input a number you would like to erase from the tree " ;
        cin >> num;
        run = tree_erase(root, num);
        if(!run)
        {
            cout << "Found & Erasing : " << num << endl;
            cout << endl << endl;
            tree_print(root);
            cout << "==============================================" << endl << endl;
        }else{
            cout << num << " does not exist in this tree." << endl;
            tree_print(root);
            cout << endl << endl;
            cout << "==============================================" << endl << endl;
        }
}

void run_lower_tests()
{
    test_insert();
    cout << endl << endl;
    test_sorted_list();
    cout << endl << endl;
    test_tree_copy();
    cout << endl << endl;
    test_tree_erase();
    cout << endl << endl;
    test_tree_search();
    cout << endl << endl;
}

#endif // BST_TESTS_H
