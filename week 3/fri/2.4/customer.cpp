#include "customer.h"

Customer::Customer()
{
}

Customer::Customer(int id, string name, int discount)
{
    this->id = id;
    this->name = name;
    this->discount = discount;
}

ostream &operator<<(ostream &, const Customer &)
{
}

int Customer::getId()
{
    return this->id;
}

void Customer::setId(int id)
{
    this->id = id;
}

string Customer::getName()
{
    return this->name;
}

void Customer::setName(string name)
{
    this->name = name;
}

int Customer::getDiscount()
{
    return this->discount;
}

void Customer::setDiscount(int discount)
{
    this->discount = discount;
}