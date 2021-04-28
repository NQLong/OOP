#ifndef AUTHOR_H_INCLUDED
#define AUTHOR_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class Author
{
private:
    string name;
    string email;
    char gender;

public:
    string getName();

    void setName(string name);

    string getEmail();

    void setEmail(string email);

    char getGender();

    void setGender(char gender);

    Author();

    Author(string, string, char);

    string toString();
    
};
#endif