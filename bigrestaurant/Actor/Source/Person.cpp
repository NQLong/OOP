#include "../Header/Person.h"

Person::~Person()
{
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

ostream& operator << (ostream& os,const Person& e){
    os 
    <<e.name<<endl
    <<e.email<<endl
    <<e.phone    
    ;
    return os;
}
