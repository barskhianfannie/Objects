//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures

#include "token.h"
#include "../STokenizer/constants.h"



Token::Token()
{
    _type = UNKNOWN;

}

Token:: Token(string str, int type)
{
    _token = str;
    _type = type;
}


int Token::type()
{
    return _type;

}

string Token:: type_string()
{
    string type;
    switch(_type)
    {
        case ALPHA:
            type = "ALPHA";
            break;
        case DIGIT:
            type = "DIGIT";
            break;
        case SPACE :
            type = "SPACES";
            break;
        case UNKNOWN :
            type = "UNKNOWN";
            break;
        case PUNC:
            type = "PUNC";
            break;
        default:
            type = "ERROR";
            break;
    }
    return type;

}


string Token:: token_str()
{
    return _token;

}


