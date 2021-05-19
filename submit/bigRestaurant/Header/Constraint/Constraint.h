#ifndef B7E5AD63_D675_4BF5_ADCA_80920130FD08
#define B7E5AD63_D675_4BF5_ADCA_80920130FD08
// from enum import Enum
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "Address.h"
#include "Enum.h"
#include "MyTime.h"
#include "Storage.h"





template <class T>
bool is_consist(list<T> lst, T item)
{
    for (typename list< T>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        if (*it == item)
            return true;
    }
    return false;
}

template <class T>
T my_input_c(string stm)
{
    T inp;
    cout << stm;
    cin >> inp;
    cin.ignore();
    return inp;
}

bool is_valid_date(time_t);

void wait();

void clear();

bool select_statement(string false_stmt, string true_stmt);

string lower_string(string in);

string select_statements(list<string>);

string input_str(string stm);

string string_of_time(time_t);

string string_of_list(list<int>);
void print_option(list<string>);

#endif /* B7E5AD63_D675_4BF5_ADCA_80920130FD08 */
