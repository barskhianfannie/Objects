#ifndef STOKENIZER_H
#define STOKENIZER_H

//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures

#include "../STokenizer/constants.h"
#include "../STokenizer/token.h"
#include "../STokenizer/machine.h"
#include <iostream>
using namespace std;


class STokenizer
{
public:

    STokenizer();
    STokenizer(char str[]);


    bool done();            //true: there are no more tokens
    bool more();            //true: there are more tokens


    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t)
    {
        string str;
        int state = s.get_token(str);
        t = Token(str,state);
        cout << t;

        return s;
    }

    //set a new string as the input string
    void set_string(char str[]);

private:

    //PRIVATE FUNCTIONS
    //Creating a Table - Unique Machine with SUCCESS/ FAIL States
    void make_table(int _table[][MAX_COLUMNS]);

    //extract the longest string that matches one of the acceptable token types.
    int get_token(string& token);


     //PRIVATE MEMBER VARIABLES

    char _buffer[MAX_BUFFER + 1];       //input string
    int _pos;                       //current position in the string
    static int _table[MAX_ROWS][MAX_COLUMNS];
};

#endif // STOKENIZER_H
