#include "../../Header/Constraint/constraint.h"

ostream &operator<<(ostream &os, EmployeeType &Typ)
{
    switch (Typ)
    {
    case MANAGER:
        os << "Manager";
        break;
    case WAITER:
        os << "Waiter";
        break;
    case CHEF:
        os << "Chef";
        break;
    case RECEPTIONIST:
        os << "Receptionist";
        break;
    case ADMIN:
        os << "Admin";
        break;
    }
    return os;
}

ostream &operator<<(ostream &os, const SeatType &T)
{
    switch (T)
    {
    case S_REGULAR:
        os << "Regular";
        break;
    case S_KID:
        os << "Kid";
        break;
    case S_ACCESSIBLE:
        os << "Accessible";
        break;
    case S_OTHER:
        os << "Other";
        break;
    }
    return os;
}

ostream &operator<<(ostream &os, const OrderStatus &T)
{
    switch (T)
    {
    case O_CANCELED:
        os << "Canceled";
        break;
    case O_COMPLETED:
        os << "Completed";
        break;
    case O_NONE:
        os << "None";
        break;
    case O_PREPARING:
        os << "Preparing";
        break;
    case O_RECEIVED:
        os << "Received";
        break;
    }
    return os;
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

Address::Address()
{
}

void wait()
{
    string str;
    getline(cin, str);
}

ostream &operator<<(ostream &os, const time_t &T)
{
    return (os << (char *)ctime(&T));
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

void clear(){
    system("cls");
}