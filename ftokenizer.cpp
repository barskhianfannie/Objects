//  Author : Fannie Barskhian
//  Project : FTokenizer
//  Class   : CS8 Data Structures

#include "ftokenizer.h"
#include <iostream>
using namespace std;

FTokenizer::FTokenizer(char* fname)
{
      _f.open(fname);
      _more = true;
      get_new_block();
}


FTokenizer::~FTokenizer()
{
    cout << "Closing File" << endl;
    _f.close();
}


Token FTokenizer:: next_token()
{
    Token t;
    if(_stk.done())
    {
        get_new_block();
    }
    _stk >> t;
    return t;

}

bool FTokenizer::more()
{

    return _more;
}


bool FTokenizer:: get_new_block()
{
    char s[MAX_BLOCK + 1];
    _f.read(s, MAX_BLOCK);
    int bytes_read = _f.gcount();
    if(bytes_read == 0)
    {
        _more = false;
        return false;
    }
    s[bytes_read] = '\0';
    _stk.set_string(s);
    return true;

}
