#ifndef personIncluded
#define personIncluded
#include <bits/stdc++.h>

using namespace std;

class Person
{
private:
    string name;
    string address;

public:
    void setName(string _name);
    void setAddress(string _address);
    string getName();
    string getAddress();

    Person(string _name, string _address);
    Person();
    Person(const Person &);
    Person& operator=(const Person&);
    string toString();
};
#endif