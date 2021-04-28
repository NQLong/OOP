#include "constraint.h"

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


ostream &operator<<(ostream &os, const time_t &T){
    return (os << (char*)ctime(&T));
}