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
        << "Name: " << e.name << endl
        << "Email: " << e.email << endl
        << "Phone: " << e.phone;
    return os;
}

bool operator==(const Person &lhs, const Person &rhs)
{
    return (
        (rhs.name == lhs.name) &&
        (rhs.email == lhs.email) &&
        (rhs.phone == lhs.phone) &&
        true);
}
void Person::render_person_title()
{
    cout
        << setw(20) << left << "        Name " << '|'
        << setw(20) << left << "        Eamil" << '|'
        << setw(13) << left << "    Phone" << '|'

        ;
}
void Person::render_person(Person p)
{
    cout
        << setw(20) << left << p.name << '|'
        << setw(20) << left << p.email << '|'
        << setw(13) << left << p.phone << '|';
}
