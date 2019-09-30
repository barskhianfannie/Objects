#ifndef FTOKENIZER_H
#define FTOKENIZER_H
#include "../STokenizer/constants.h"
#include "../STokenizer/stokenizer.h"
#include "../STokenizer/token.h"
#include <iostream>
#include <fstream>
using namespace std;


class FTokenizer
{
public:

    const int MAX_BLOCK = MAX_BUFFER;
    FTokenizer(char* fname);
    ~FTokenizer();
    Token next_token();
    bool more();        //returns the current value of _more
    int pos();          //returns the value of _pos
    int block_pos();     //returns the value of _blockPos
    friend FTokenizer& operator >> (FTokenizer& f, Token& t)
    {
        t = f.next_token();
       return f;
    }

private:

    bool get_new_block(); //gets the new block from the file
    ifstream _f;           //file being tokenized
    STokenizer _stk;     //The STokenizer object to tokenize current block
    bool _more;         //false if last token of the last block
                        //  has been processed and now we are at
                        //  the end of the last block.
};

#endif // FTOKENIZER_H
