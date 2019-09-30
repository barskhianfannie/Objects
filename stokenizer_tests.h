#ifndef STOKENIZER_TESTS_H
#define STOKENIZER_TESTS_H

//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures


#include <iostream>
#include "../STokenizer/stokenizer.h"
#include "../STokenizer/ftokenizer.h"

using namespace std;


string token;



void test_STokenizer(char pass[])
{
    token = string(pass);
    size_t str_len = strlen(pass);
    cout << "The String is: " << endl << endl << token << endl << endl;
    STokenizer stk(pass);
    Token t;
    while(!stk.done())
    {
        stk >> t;
        t = Token();
        stk>>t;

    }
}


#endif // STOKENIZER_TESTS_H
