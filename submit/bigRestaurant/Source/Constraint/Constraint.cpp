#include "../../Header/Constraint/constraint.h"

void *Storage::Restaurant;
void *Storage::cheves;
void *Storage::waiters;
void *Storage::recetionists;
void *Storage::managers;
void *Storage::customers;
void *Storage::reservations;
void *Storage::orders;
void *Storage::menus;
void *Storage::checks;
void *Storage::tables;

bool is_valid_date(time_t t)
{
    return (t < time(0) || (t - time(0)) / 3600 / 24 < 7);
}

void wait()
{
    string str;
    getline(cin, str);
}

bool is_linux()
{

#ifdef _WIN32
    return false;
#elif _WIN64
    return false;
#elif __APPLE__ || __MACH__
    return false;
#elif __linux__
    return true;
#elif __FreeBSD__
    return false;
#elif __unix || __unix__
    return true;
#else
    return true;
#endif
}

void clear()
{
    if (!is_linux)
        system("cls");
    else
        system("clear");
}

bool select_statement(string stm1, string stm2)
{
    cout << "1. " + stm1 << endl;
    cout << "2. " + stm2 << endl
         << endl;
    cout << "Select: ";
    int option;
    cin >> option;
    cin.ignore();
    if (option > 2 || option < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_statement(stm1, stm2);
    }
    return option - 1;
}

string select_statements(list<string> stmts)
{
    int count = 1;
    for (auto it = stmts.begin(); it != stmts.end(); it++)
    {
        cout << setw(3) << to_string(count++) + "." << *it << endl;
    }
    int option;
    cout << endl;
    while (true)
    {
        cout << "Enter number: ";
        cin >> option;
        cin.ignore();
        if (option < 1 && option > stmts.size())
        {
            cout << "Invalid number, try again";
            wait();
            clear();
            continue;
        }
        break;
    }
    auto it = stmts.begin();
    for (int i = 0; i < option - 1; i++)
    {
        it++;
    }
    return *it;
}

string lower_string(string in)
{
    string data = in;
    transform(data.begin(), data.end(), data.begin(),
              [](unsigned char c) { return tolower(c); });
    return data;
}

string input_str(string stm)
{
    string inp;
    cout << stm;
    getline(cin, inp);
    return inp;
}

string string_of_time(time_t t)
{
    stringstream ss;
    ss << (char *)ctime(&t);
    string temp;
    getline(ss, temp);
    return temp;
}

void print_option(list<string> stmts)
{
    int count = 1;
    clear();
    for (auto stm = stmts.begin(); stm != stmts.end(); stm++)
    {
        cout
            << setw(3) << left << to_string(count++) + "."
            << *stm << "." << endl;
    }

    cout << endl
         << setw(3) << left << "0."
         << "Back." << endl;

    cout << endl
         << "Enter your choice: ";
}