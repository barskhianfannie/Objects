#ifndef FTOKENIZER_TESTS_H
#define FTOKENIZER_TESTS_H

//  Author : Fannie Barskhian
//  Project : FTokenizer
//  Class   : CS8 Data Structures
//  Author : Fannie Barskhian
//  Project : FTokenizer
//  Class   : CS8 Data Structures

#include <iostream>
#include "../STokenizer/stokenizer.h"
#include "../STokenizer/ftokenizer.h"
#include "../STokenizer/stokenizer_tests.h"

using namespace std;

void test_FTokenizer();


void test_FTokenizer()
{
    char file_name[] = "solitude.txt";
     Token t;
     FTokenizer ftk(file_name);
     ftk>>t;
     int token_count = 0;
     while (ftk.more()){
         if (t.type_string()=="ALPHA" ){
             token_count++;
         }
         ftk>>t;
     }
     cout<<"Tokens Found: "<<token_count<<endl;
     cout<<"=========="<<endl;
}

#endif // FTOKENIZER_TESTS_H
