/*
Author
----------------------
-name:string
-gender: char
----------------------
+getName(): string
+setName(string):void

+getGender(): char
+setGender(const char *):void
*/

#ifndef AUTHOR_INCLUDED
#define AUTHOR_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Author
{
private:
    string name;
    char gender;

public:
    Author();
    Author(string, const char *);
    Author(string, char);

    string getName();
    char getGender();

    void setName(string);
    void setGender(const char *);
    void setGender(char);

    friend ostream &operator<<(ostream &os, const Author &author);
    
};

#endif