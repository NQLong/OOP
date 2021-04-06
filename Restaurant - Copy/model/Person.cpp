#include <bits/stdc++.h>

#include "Person.h"

using namespace std;

void Person::setName(string _name)
{
    name = _name;
}

void Person::setAddress(string _address)
{
    address = _address;
}

string Person::getName()
{
    return name;
}

string Person::getAddress()
{
    return address;
}

Person::Person(string _name, string _address)
{
    name = _name;
    address = _address;
}

Person::Person() {}

Person::Person(const Person &_person)
{
    this->name = _person.name;
    this->address = _person.address;
}

Person &Person::operator=(const Person &_person)
{
    this->name = _person.name;
    this->address = _person.address;
    return *this;
}

string Person::toString()
{
    return "Person(name =" + name + ", address = " + address + ")";
}