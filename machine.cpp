//  Author : Fannie Barskhian
//  Project : STokenizer
//  Class   : CS8 Data Structures

#include "../STokenizer/machine.h"
#include "../STokenizer/constants.h"
#include <iostream>

using namespace  std;



//Fill all cells of the array with -1
void init_table(int _table[][MAX_COLUMNS])
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLUMNS; j++ )
            _table[i][j] = -1;
    }
}


//Mark this state (row) with a 1 (success)
void mark_success(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 1;
}


////Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 0;
}

//Mark this row and column
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state)
{
    _table[row][column] = state;
}



//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    for(int j = 0; j < strlen(columns); j++) // ASCII a-z
    {
        _table[row][columns[j]] = state;
    }
}


////true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state)
{
    return _table[state][0];
}

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS])
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLUMNS; j++)
        {
            cout << _table[i][j];
        }
    }
}


