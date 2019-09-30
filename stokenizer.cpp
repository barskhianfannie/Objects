//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures

#include "stokenizer.h"
#include <ctype.h>
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer()
{
    make_table(_table);
    _pos = 0;
}

STokenizer::STokenizer(char str[])
{
    make_table(_table);
    _pos = 0;
    set_string(str);
}



bool STokenizer:: done()
{
    return (_buffer[_pos] == '\0');
}

bool STokenizer:: more()
{
    return (_pos != MAX_BUFFER+1);
}

void STokenizer::set_string(char str[])
{
    strcpy(_buffer,str);
    _pos = 0;
}


void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    //INITAIALIZE THE TABLE
    init_table(_table);

    //Mark Success States
    mark_success(_table,1); // ALPHA
    mark_success(_table,10); // DIGIT
    mark_success(_table,12); // DECIMALS
    mark_success(_table,14); // Percents
    mark_success(_table,20); // PUNCS
    mark_success(_table,30); // SPACEs
    mark_success(_table, 32); //TAB
    mark_success(_table, 40); // UNKNOWN


    mark_fail(_table,0);
    mark_fail(_table, 11); // Decimals
//    mark_fail(_table, 13); // Percentages
    mark_fail(_table, 31); // Tab

    //ALPHAS
    mark_cells(0, _table, ALPHAS, 1);
    mark_cells(1, _table, ALPHAS, 1);
    mark_cells(33, _table, ALPHAS, 34);
    mark_cells(34, _table, ALPHAS, 34);
    //Handling Apostrophe's after words like example: wasn't
    mark_cell(1, _table, 39, 33);

    //DIGITS
    mark_cells(0,_table, DIGITS, 10);
    mark_cells(10, _table, DIGITS, 10);
    mark_cells(11, _table, DIGITS, 12); // Handling Decimals
    mark_cells(12, _table, DIGITS, 12); // Allowing Numbers after Decimals
    // Handling Percentages
    mark_cell(10,_table, 37, 13);
    mark_cell(12, _table, 37, 13);

    //PUNCS
    mark_cells(0, _table, PUNCS, 30);
    mark_cells(30, _table, PUNCS, 30);

    //UNKNOWNS
    mark_cells(0,_table, UNKNOWNS, 40);
    mark_cells(40,_table, UNKNOWNS, 40);

    //SPACE
    mark_cell(0, _table, 32, 20);
    //SPACES
    mark_cell(20, _table, 32, 20);

    //Number followed by . (decimals)
    mark_cell(10, _table, 46, 11); // 46 ASCII == .

    // tab
    mark_cell(30,_table, 92, 31); // 92 ASCII == '\'
    mark_cell(31,_table, 116,  32); //84 ASCII == t


}

int STokenizer:: get_token(string& token)
{
        int state = 0;
        int last_success = -1;
        int begin = _pos;

        // If not ASCII, return Unknown
        if(!isascii(_buffer[_pos]))
        {
            _pos++;
            token = string(&_buffer[begin], &_buffer[_pos]);
            return state;
        }

            while(_table[state][_buffer[_pos]] != -1 && _buffer[_pos] != '\0')
            {
                state = _table[state][_buffer[_pos]];
                if(is_success(_table, state))
                {
                    last_success = _pos;
                }
                _pos++;
            }

        if(state != 0)
        {
            token = string(&_buffer[begin], &_buffer[last_success + 1]);
            return state;
        }else{
            _pos++;
            token = string(&_buffer[begin], &_buffer[_pos]);
            return state;
        }


}
