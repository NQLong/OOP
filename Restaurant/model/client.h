#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <bits/stdc++.h>
#include "person.h"

using namespace std;

class Client : public Person
{
private:
    string taxId;

public:
    Client();
    Client(string, string, string);
    Client(const Client &);

    Client& operator=(const Client &);

    void setTaxId(string);
    string getTaxID();
    string toString();
};

#endif