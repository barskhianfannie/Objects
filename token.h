#ifndef TOKEN_H
#define TOKEN_H

//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Token
{
public:

    Token();
    Token(string str, int type);


    friend ostream& operator <<(ostream& outs, const Token& t)
    {
        switch(t._type)
        {
            case 1 ... 9: outs <<setw(1)<<"ALPHA"<<setw(10)<< "|"<<t._token<<"|"<<endl;
                break;
            case 10 ... 12: outs<<setw(1)<<"DIGIT"<<setw(10)<< "|"<<t._token<<"|"<<endl;
                break;
            case 20 ... 29: outs<<setw(1)<<"SPACE"<<setw(10)<< "|"<<t._token<<"|"<<endl;
                break;
            case 30 ... 39: outs<<setw(1)<<"PUNC "<<setw(10)<< "|"<<t._token<<"|"<<endl;
                break;
            case 40 ... 50: outs<<setw(1)<<"UNKNOWN"<<setw(8)<< "|"<<t._token<<"|"<<endl;
                break;
            case 0: outs<<setw(1)<<"UNKNOWN"<<setw(8)<< "|"<<t._token<<"|"<<endl;
                break;
            case 13: outs<<setw(1)<<"PERCENT"<<setw(8)<< "|"<<t._token<<"|"<<endl;
                break;
        }
        return outs;


    }
    int type();
    string type_string();
    string token_str();


private:
    string _token;
    int _type;
};

#endif // TOKEN_H
