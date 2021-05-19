#include "../../Header/Actor/Person.h"

Person::~Person()
{
}

void Person::input_person()
{
    cout << "full name: ";
    getline(cin, this->name);
    cout << "email: ";
    getline(cin, this->email);
    cout << "phone: ";
    getline(cin, this->phone);
    return;
}

string Person::getName()
{
    return this->name;
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getEmail()
{
    return this->email;
}

void Person::setEmail(string email)
{
    this->email = email;
}

string Person::getPhone()
{
    return this->phone;
}

void Person::setPhone(string phone)
{
    this->phone = phone;
}

ostream &operator<<(ostream &os, const Person &e)
{
    os
        << "name: " << e.name << endl
        << "email: " << e.email << endl
        << "phone: " << e.phone;
    return os;
}
