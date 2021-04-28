#include "../Header/Author.h"

Author::Author() {}

Author::Author(string name, const char *gender)
{
    this->name = name;
    this->gender = *gender;
}

string Author::getName()
{
    return this->name;
}

void Author::setName(string name)
{
    this->name = name;
}

char Author::getGender()
{
    return this->gender;
}

void Author::setGender(char gender)
{
    this->gender = gender;
}

ostream &operator<<(ostream &os, const Author &author)
{
    return os
           << "Name   :" << author.name << endl
           << "Gender :" << (author.gender == 'm' ? "male" : "female") << endl;
}