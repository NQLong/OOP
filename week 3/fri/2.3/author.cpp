#include "author.h"

Author::Author()
{
    cout << "something";
}

Author::Author(string name, string email, const char *gender)
{
    
    this->gender = gender[0];
    // cout<<this->gender;
    // memcpy(&(this->gender),gender,1);
    this->name = name;
    this->email = email;
}

string Author::getName()
{
    return this->name;
}

void Author::setName(string name)
{
    this->name = name;
}

string Author::getEmail()
{
    return this->email;
}

void Author::setEmail(string email)
{
    this->email = email;
}

char Author::getGender()
{
    return this->gender;
}

void Author::setGender(char gender)
{
    this->gender = gender;
}

string Author::toString()
{
    return "Author[name=" + this->name + ",email=" + this->email + ",gender=" + this->gender + "]";
}

ostream &operator<<(ostream &os, const Author &author)
{
    // cout<<author.gender;
    return (os << "Author[name=" << author.name << ",email=" << author.email << ",gender=" << author.gender << "]");
}