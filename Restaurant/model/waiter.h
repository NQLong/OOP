#ifndef WAITER_H_INCLUDED
#define WAITER_H_INCLUDED
#include <bits/stdc++.h>
#include "person.h"
using namespace std;

class Waiter : public Person
{
private:
    int id;
    string phoneNumber;
public:
    Waiter();
    Waiter(int,string,string,string);
    void setId (int _id );
    void setPhoneNumber(string);
    int getId();
    string getPhoneNumber();
    string toString();
};
#endif