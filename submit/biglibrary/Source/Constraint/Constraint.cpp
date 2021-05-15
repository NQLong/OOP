#include "../../Header/Constraint/Constraint.h"
#include <algorithm>
#include <cctype>

void clear()
{
    system("cls");
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

FullName::~FullName() {}

FullName::FullName() {}

FullName FullName::input()
{
    FullName temp;
    cout << "First name: ";
    getline(cin, temp.first_name);
    cout << "last name: ";
    getline(cin, temp.last_name);
    return temp;
}

ostream &operator<<(ostream &os, const FullName &f)
{
    if (f.first_name != "")
        os << f.first_name << " ";
    os << f.last_name;
    return os;
}

void FullName::modify()
{
    cout << "First name: ";
    getline(cin, this->first_name);
    cout << "last name: ";
    getline(cin, this->last_name);
}

bool is_valid_date(time_t t)
{
    return (t < time(0) || (t - time(0)) / 3600 / 24 < 7);
}

time_t input_time()
{
    int day, month, year;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    cout << "Day : ";
    cin >> ltm.tm_mday;
    cout << "Month : ";
    cin >> month;
    ltm.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    ltm.tm_year = year - 1900;
    cout << "Hour: ";
    cin >> ltm.tm_hour;
    cout << "Min : ";
    cin >> ltm.tm_min;
    cout << "Seccond: ";
    cin >> ltm.tm_sec;
    cin.ignore();
    return mktime(&ltm);
}

time_t input_date()
{
    int day, month, year;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    cout << "Day : ";
    cin >> ltm.tm_mday;
    cout << "Month : ";
    cin >> month;
    ltm.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    ltm.tm_year = year - 1900;
    ltm.tm_hour = 0;
    ltm.tm_sec = 0;
    ltm.tm_min = 0;
    cin.ignore();
    return mktime(&ltm);
}

bool is_consist(list<int> lst, int i)
{
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (*it == i)
            return true;
    }
    return false;
}

Address Address::inputAddress()
{
    Address temp;
    cout << "Street: ";
    getline(cin, temp.street);
    cout << "State: ";
    getline(cin, temp.city);
    cout << "State: ";
    getline(cin, temp.state);
    cout << "zip-code: ";
    getline(cin, temp.zip_code);
    cout << "Country: ";
    getline(cin, temp.country);
    return temp;
}

Address::Address() {}
Address::~Address() {}

void wait()
{
    string str;
    getline(cin, str);
}

ostream &operator<<(ostream &os, const time_t &T)
{
    return (os << (char *)ctime(&T));
}

ostream &operator<<(ostream &os, const AccountState &a)
{
    switch (a)
    {
    case ACTIVE:
        return os << "Active";
    case FROZEN:
        return os << "Frozen";
    case CLOSED:
        return os << "Closed";
    }
    return os;
}

AccountState select_account_state()
{
    cout << "Select account state" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (AccountState)i << endl;
    }
    cout << endl
         << "Seclect state: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 3 || state < 1)
    {
        cout << "invalid state option, try again";
        wait();
        clear();
        return select_account_state();
    }
    return (AccountState)(state - 1);
}

ostream &operator<<(ostream &os, const Format &f)
{

    switch (f)
    {
    case PAPERBACK:
        return os << "Paperback";
    case HARDCOVER:
        return os << "Hardcover";
    case AUDIOBOOK:
        return os << "Audiobook";
    case AUDIO_CD:
        return os << "Audio cd";
    case MP3_CD:
        return os << "Mp3 cd";
    case PDF:
        return os << "PDF";
    }
    return os;
}

Format select_format()
{
    cout << "Select format" << endl
         << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (Format)i << endl;
    }
    cout << endl
         << "Seclect format: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 6 || state < 1)
    {
        cout << "invalid format option, try again";
        wait();
        clear();
        return select_format();
    }
    return (Format)(state - 1);
}

ostream &operator<<(ostream &os, const Language &l)
{
    // ENGLISH,
    //     FRENCH,
    //     GERMAN,
    //     SPANISH,
    //     ITALIAN
    switch (l)
    {
    case ENGLISH:
        return os << "English";
    case FRENCH:
        return os << "French";
    case GERMAN:
        return os << "German";
    case SPANISH:
        return os << "Spanish";
    case ITALIAN:
        return os << "Italian";
    }
    return os;
}

Language select_language()
{
    cout << "Select language" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (Language)i << endl;
    }
    cout << endl
         << "Choose language: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 6 || state < 1)
    {
        cout << "invalid language option, try again";
        wait();
        clear();
        return select_language();
    }
    return (Language)(state - 1);
}

ostream &operator<<(ostream &os, const UserType &u)
{
    switch (u)
    {
    case LIBRARIAN:
        return os << "Librarian";
    case PATRON:
        return os << "Patron";
    }
    return os;
}
UserType select_user_type()
{
    cout << "Select User Type" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (UserType)i << endl;
    }
    cout << endl
         << "Choose Type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 2 || state < 1)
    {
        cout << "invalid type option, try again";
        wait();
        clear();
        return select_user_type();
    }
    return (UserType)(state - 1);
}

string lower_string(string in)
{
    string data = in;
    transform(data.begin(), data.end(), data.begin(),
              [](unsigned char c) { return tolower(c); });
    return data;
}