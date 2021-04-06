#include "Waiter.h"

#include <bits/stdc++.h>

using namespace std;

void Waiter::setId(int _id)
{
    id = _id;
}

Waiter::Waiter(int id, string name, string address, string pN) : Person(name, address)
{
    this->id = id;
    phoneNumber = pN;
}

void Waiter::setPhoneNumber(string pN)
{
    phoneNumber = pN;
}

int Waiter::getId()
{
    return id;
}

string Waiter::getPhoneNumber()
{
    return phoneNumber;
}

string Waiter::toString()
{
    return "Waiter(id = " + to_string(id)+"," +Person::toString()+", phone number = "+phoneNumber;
}

Waiter::Waiter(){}